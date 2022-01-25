/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeStruct.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

#include <algorithm>
#include <stdexcept>

namespace ast::type
{
	//*************************************************************************

	namespace
	{
		uint32_t getAligned( uint32_t value, uint32_t align )
		{
			auto rem = value % align;
			return ( rem
				? value + ( align - rem )
				: value );
		}

		bool isVec4Padded( MemoryLayout layout )
		{
			switch ( layout )
			{
			case MemoryLayout::eStd140:
				return true;

			default:
				return false;
			}
		}

		uint32_t getNaiveSize( Kind kind )
		{
			uint32_t mult = 1u;

			while ( !isScalarType( kind ) )
			{
				mult *= getComponentCount( kind );
				kind = getComponentType( kind );
			}

			switch ( kind )
			{
			case Kind::eDouble:
			case Kind::eUInt64:
				return mult * 8u;
			case Kind::eFloat:
			case Kind::eInt:
			case Kind::eUInt:
				return mult * 4u;
			case Kind::eHalf:
				return mult * 2u;
			case Kind::eBoolean:
				return mult * 1u;
			default:
				AST_Failure( "Unsupported type::Kind" );
				return 0u;
			}
		}

		uint32_t getNonArrayNaiveSize( Type const & type )
		{
			if ( isStructType( type ) )
			{
				auto mbr = getStructType( type )->back();
				return mbr.offset + mbr.size;
			}

			if ( isArrayType( type.getKind() ) )
			{
				auto mbr = getStructType( type )->back();
				return mbr.offset + mbr.size;
			}

			return getNaiveSize( type.getKind() );
		}

		uint32_t getLargestScalarElementSize( Struct const & type )
		{
			uint32_t result = 0u;

			for ( auto & mbr : type )
			{
				auto t = getNonArrayTypeRec( mbr.type );

				if ( isStructType( t ) )
				{
					result = std::max( result, mbr.size );
				}
				else
				{
					auto kind = t->getKind();

					while ( !isScalarType( kind ) )
					{
						kind = getComponentType( kind );
					}

					result = std::max( result, getNaiveSize( kind ) );
				}
			}

			return result;
		}

		uint32_t getNaiveSize( Type const & type )
		{
			if ( type.getKind() == ast::type::Kind::eArray )
			{
				auto arraySize = getArraySize( type );

				if ( arraySize == ast::type::UnknownArraySize )
				{
					arraySize = 1u;
				}

				return arraySize * getNaiveSize( getNonArrayType( type ) );
			}

			return getNonArrayNaiveSize( type );
		}

		uint32_t getPackedBaseSize( Kind kind )
		{
			while ( !isScalarType( kind ) )
			{
				kind = getComponentType( kind );
			}

			switch ( kind )
			{
			case Kind::eDouble:
			case Kind::eUInt64:
				return 8u;
			case Kind::eFloat:
			case Kind::eInt:
			case Kind::eUInt:
				return 4u;
			case Kind::eHalf:
				return 2u;
			case Kind::eBoolean:
				return 1u;

			default:
				AST_Failure( "Unsupported type::Kind" );
				return 0u;
			}
		}

		uint32_t getPackedAlignment( Type const & type
			, MemoryLayout layout );

		uint32_t getPackedAlignment( Array const & type
			, MemoryLayout layout )
		{
			uint32_t minimumAlignment = 1;

			if ( isVec4Padded( layout ) )
			{
				minimumAlignment = 16;
			}

			auto * tmp = type.getType().get();

			while ( getArraySize( *tmp ) != NotArray )
			{
				tmp = static_cast< Array const & >( *tmp ).getType().get();
			}

			// Get the alignment of the base type, then maybe round up.
			return std::max( minimumAlignment
				, getPackedAlignment( *tmp, layout ) );
		}

		uint32_t getPackedAlignment( Struct const & type
			, MemoryLayout layout )
		{
			// Rule 9. Structs alignments are maximum alignment of its members.
			uint32_t alignment = 0;

			for ( auto & member : type )
			{
				alignment = std::max( alignment
					, getPackedAlignment( *member.type, layout ) );
			}

			// In std140, struct alignment is rounded up to 16.
			if ( isVec4Padded( layout ) )
			{
				alignment = std::max( alignment, 16u );
			}

			return alignment;
		}

		uint32_t getPackedAlignment( Kind kind
			, MemoryLayout layout )
		{
			const uint32_t baseAlignment = getPackedBaseSize( kind );

			// From GL_EXT_scalar_block_layout spec
			// (https://github.com/KhronosGroup/GLSL/blob/master/extensions/ext/GL_EXT_scalar_block_layout.txt#L74)
			// 1. If the member is a scalar consuming N basic machine units, the base alignment is N.
			// 2. If the member is a vector, the base alignment is equal to that of its components.
			// 3. If the member is a matrix, the base alignment is equal to that of its components.
			// 4. If the member is an array, the base alignment is equal to that of its elements.
			if ( layout == MemoryLayout::eScalar )
			{
				return baseAlignment;
			}

			auto componentCount = getComponentCount( kind );
			// From 7.6.2.2 in GL 4.5 core spec
			// (https://www.khronos.org/registry/OpenGL/specs/gl/glspec45.core.pdf).

			// Rule 1
			if ( isScalarType( kind ) )
			{
				return baseAlignment;
			}

			// Rule 2
			if ( isVectorType( kind )
				&& ( componentCount == 2u || componentCount == 4u ) )
			{
				return componentCount * baseAlignment;
			}

			// Rule 3
			if ( isVectorType( kind )
				&& componentCount == 3u )
			{
				return 4u * baseAlignment;
			}

			// Rule 4 implied. Alignment does not change in std430.

			/* Not scalar, not vector => Matrix type */
			componentCount = getComponentCount( getComponentType( kind ) );

			// Rule 5. Column-major matrices are stored as arrays of
			// vectors.
			if ( isVec4Padded( layout ) )
			{
				return 4u * baseAlignment;
			}
			else if ( componentCount == 3u )
			{
				return 4u * baseAlignment;
			}
			else
			{
				return componentCount * baseAlignment;
			}

			// Rule 6 implied.

			// Rule 7 is about column matrices, that are not supported. TODO ?.

			// Rule 8 implied.

			// Rule 9 is about structures.
		}

		uint32_t getPackedAlignment( Type const & type
			, MemoryLayout layout )
		{
			auto arraySize = getArraySize( type );

			if ( arraySize != NotArray )
			{
				return getPackedAlignment( static_cast< Array const & >( type )
					, layout );
			}

			auto kind = getNonArrayKindRec( type );

			if ( kind == Kind::eStruct
				|| kind == Kind::eRayDesc )
			{
				return getPackedAlignment( static_cast< Struct const & >( type )
					, layout );
			}

			return getPackedAlignment( type.getKind()
				, layout );
		}

		uint32_t getPackedSize( Type const & type
			, MemoryLayout layout );

		uint32_t getPackedArrayStride( const Array & type
			, MemoryLayout layout )
		{
			// Array stride is equal to aligned size of the underlying type.
			auto arrayed = type.getType();
			uint32_t size = getPackedSize( *arrayed, layout );
			auto arraySize = getArraySize( *arrayed );

			if ( arraySize == NotArray )
			{
				uint32_t alignment = getPackedAlignment( type, layout );
				return getAligned( size, alignment );
			}
			else
			{
				// For multidimensional arrays, array stride always matches size of subtype.
				// The alignment cannot change because multidimensional arrays are basically N * M array elements.
				return size;
			}
		}

		uint32_t getPackedSize( Array const & type
			, MemoryLayout layout )
		{
			auto arraySize = type.getArraySize() == UnknownArraySize
				? 1u
				: type.getArraySize();
			return arraySize * getPackedArrayStride( type
				, layout );
		}

		uint32_t getPackedSize( Struct const & type
			, MemoryLayout layout )
		{
			uint32_t result{ 0u };

			if ( type.getMemoryLayout() != layout )
			{
				uint32_t padAlignment = 1;

				for ( auto & member : type )
				{
					uint32_t packedAlignment = getPackedAlignment( *member.type, layout );
					uint32_t alignment = std::max( packedAlignment, padAlignment );
					auto kind = getNonArrayKindRec( *member.type );

					// The next member following a struct member is aligned to the base alignment of the struct that came before.
					// GL 4.5 spec, 7.6.2.2.
					if ( kind == Kind::eStruct
						|| kind == Kind::eRayDesc )
					{
						padAlignment = packedAlignment;
					}
					else
					{
						padAlignment = 1;
					}

					result = getAligned( result, alignment );
					result += getPackedSize( *member.type, layout );
				}
			}
			else if ( !type.empty() )
			{
				auto member = type.back();
				uint32_t packedAlignment = getPackedAlignment( *member.type, layout );
				result = member.offset + member.size;
				result = getAligned( result, packedAlignment );
			}

			return result;
		}

		uint32_t getPackedSize( Type const & type
			, MemoryLayout layout )
		{
			auto arraySize = getArraySize( type );

			if ( arraySize != NotArray )
			{
				return getPackedSize( static_cast< Array const & >( type )
					, layout );
			}

			auto kind = getNonArrayKindRec( type );

			if ( kind == Kind::eStruct
				|| kind == Kind::eRayDesc )
			{
				return getPackedSize( static_cast< Struct const & >( type )
					, layout );
			}

			const uint32_t baseAlignment = getPackedBaseSize( kind );

			if ( isScalarType( kind ) )
			{
				return baseAlignment;
			}

			if ( isVectorType( kind ) )
			{
				return getComponentCount( kind ) * baseAlignment;
			}

			// Not scalar, not vector => Matrix.
			auto columns = getComponentCount( kind );

			if ( isVec4Padded( layout ) )
			{
				return columns * 4 * baseAlignment;
			}

			auto rows = getComponentCount( getComponentType( kind ) );

			if ( rows == 3 )
			{
				return columns * 4 * baseAlignment;
			}

			return columns * rows * baseAlignment;
		}
	}

	//*************************************************************************

	std::string getRealName( Builtin builtin
		, uint32_t index )
	{
		auto result = getName( builtin );

		if ( index != Struct::InvalidLocation )
		{
			result += std::to_string( index );
		}

		return result;
	}

	//*************************************************************************

	Struct::Struct( TypesCache & cache
		, Struct const & rhs )
		: Type{ cache, Kind::eStruct }
		, m_name{ rhs.getName() }
		, m_layout{ rhs.m_layout }
		, m_flag{ rhs.m_flag }
	{
		doCopyMembers( rhs );
	}

	Struct::Struct( TypesCache & cache
		, Struct * parent
		, uint32_t index
		, Struct const & copy )
		: Type{ cache, parent, index, copy }
		, m_name{ copy.getName() }
		, m_layout{ copy.m_layout }
		, m_flag{ copy.m_flag }
	{
		doCopyMembers( copy );
	}


	Struct::Struct( TypesCache & cache
		, Struct & parent
		, uint32_t index
		, Struct const & copy )
		: Struct{ cache, &parent, index, copy }
	{
	}

	Struct::Struct( TypesCache & cache
		, MemoryLayout layout
		, std::string name
		, var::Flag flag
		, Kind kind )
		: Type{ cache, kind }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
		, m_flag{ flag }
	{
	}

	Struct::Member Struct::getMember( uint32_t index )
	{
		return m_members[index];
	}

	Struct::Member Struct::getMember( std::string const & name )
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Member const & lookup )
			{
				return lookup.name == name;
			} );

		if ( it == m_members.end() )
		{
			throw std::runtime_error{ "Struct member [" + name + "] was not found." };
		}

		return *it;
	}

	uint32_t Struct::findMember( std::string const & name )const
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Member const & lookup )
			{
				return lookup.name == name;
			} );
		return m_members.end() == it
			? NotFound
			: uint32_t( std::distance( m_members.begin(), it ) );
	}

	Struct::Member Struct::getMember( Builtin builtin
		, uint32_t index )
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&builtin, &index]( Member const & lookup )
			{
				return lookup.builtin == builtin
					&& lookup.builtinIndex == index;
			} );

		if ( it == m_members.end() )
		{
			throw std::runtime_error{ "Struct member [" + getRealName( builtin, index ) + "] was not found." };
		}

		return *it;
	}

	uint32_t Struct::findMember( Builtin builtin
		, uint32_t index )const
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&builtin, &index]( Member const & lookup )
			{
				return lookup.builtin == builtin
					&& lookup.builtinIndex == index;
			} );
		return m_members.end() == it
			? NotFound
			: uint32_t( std::distance( m_members.begin(), it ) );
	}

	TypePtr Struct::getMemberType( Struct & parent, uint32_t index )const
	{
		return std::shared_ptr< Struct >( new Struct
			{
				getCache(),
				parent,
				index,
				*this,
			} );
	}

	std::pair< uint32_t, uint32_t > Struct::doLookupMember( std::string const & name
		, TypePtr type )
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Struct::Member const & lookup )
			{
				return lookup.name == name;
			} );

		if ( it != m_members.end() )
		{
			throw std::runtime_error{ "Struct member [" + name + "] already exists." };
		}

		return std::make_pair( getSize( *type, m_layout )
			, ( m_members.empty()
				? 0u
				: m_members.back().offset + m_members.back().size ) );
	}

	void Struct::doAddMember( Struct::Member const & member )
	{
		m_members.push_back( member );
		doUpdateOffsets();
	}

	void Struct::doUpdateOffsets()
	{
		uint32_t offset = 0u;
		auto minAlign = 1u;
		auto prvAlignment = 1u;
		bool prvIsStruct = false;

		if ( m_layout == MemoryLayout::eScalar )
		{
			minAlign = getLargestScalarElementSize( *this );
		}

		for ( auto & member : m_members )
		{
			uint32_t alignment = ( m_layout == MemoryLayout::eScalar
				? minAlign
				: ( prvIsStruct
					? prvAlignment
					: getAlignment( *member.type, m_layout ) ) );
			member.offset = getAligned( offset, alignment );
			offset = member.offset + member.size;
			prvAlignment = alignment;
			prvIsStruct = isStructType( member.type );
		}
	}

	void Struct::doCopyMembers( Struct const & rhs )
	{
		for ( auto & member : rhs )
		{
			m_members.push_back( member );
		}

		doUpdateOffsets();
	}

	//*************************************************************************

	BaseStruct::BaseStruct( TypesCache & cache
		, MemoryLayout layout
		, std::string name
		, Kind kind )
		: Struct{ cache, layout, name, {}, kind }
	{
	}

	BaseStruct::BaseStruct( TypesCache & cache
		, MemoryLayout layout
		, std::string name )
		: BaseStruct{ cache, layout, name, Kind::eStruct }
	{
	}

	Struct::Member BaseStruct::declMember( Builtin builtin
		, Kind kind
		, uint32_t arraySize
		, uint32_t index )
	{
		TypePtr mbrType;
		auto type = getCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, builtin, index );
	}

	Struct::Member BaseStruct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize )
	{
		TypePtr mbrType;
		auto type = getCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, name );
	}

	Struct::Member BaseStruct::declMember( std::string name
		, TypePtr type )
	{
		return declMember( name
			, getNonArrayKind( type )
			, getArraySize( type ) );
	}

	Struct::Member BaseStruct::declMember( std::string name
		, ArrayPtr type
		, uint32_t arraySize )
	{
		auto mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
			, *this
			, uint32_t( size() ) );
		return doCreateMember( mbrType, name );
	}

	Struct::Member BaseStruct::declMember( std::string name
		, ArrayPtr type )
	{
		Struct::Member result;
		auto kind = getNonArrayKind( type );

		if ( kind == Kind::eStruct
			|| kind == Kind::eRayDesc )
		{
			auto structType = std::static_pointer_cast< Struct >( type->getType() );

			if ( structType->getFlag() )
			{
				result = declMember( name
					, std::static_pointer_cast< IOStruct >( structType )
					, type->getArraySize() );
			}
			else
			{
				result = declMember( name
					, std::static_pointer_cast< BaseStruct >( structType )
					, type->getArraySize() );
			}
		}
		else if ( kind == Kind::eArray )
		{
			result = declMember( name
				, std::static_pointer_cast< Array >( type->getType() )
				, type->getArraySize() );
		}
		else
		{
			result = declMember( name
				, kind
				, type->getArraySize() );
		}

		return result;
	}

	Struct::Member BaseStruct::declMember( std::string name
		, BaseStructPtr type
		, uint32_t arraySize )
	{
		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getStruct( type->getMemoryLayout(), type->getName() );
			mbrType = getCache().getMemberType( getCache().getArray( mbrType, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getStruct( type->getMemoryLayout(), type->getName() );
			mbrType = getCache().getMemberType( mbrType
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, name );
	}

	Struct::Member BaseStruct::declMember( std::string name
		, BaseStructPtr type )
	{
		return declMember( name
			, type
			, NotArray );
	}

	Struct::Member BaseStruct::declMember( std::string name
		, IOStructPtr type
		, uint32_t arraySize )
	{
		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getIOStruct( type->getMemoryLayout()
				, type->getName()
				, ast::var::Flag( type->getFlag() ) );
			mbrType = getCache().getMemberType( getCache().getArray( mbrType, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getIOStruct( type->getMemoryLayout()
				, type->getName()
				, ast::var::Flag( type->getFlag() ) );
			mbrType = getCache().getMemberType( mbrType
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, name );
	}

	Struct::Member BaseStruct::declMember( std::string name
		, IOStructPtr type )
	{
		return declMember( name
			, type
			, NotArray );
	}

	Struct::Member BaseStruct::doCreateMember( TypePtr type
		, std::string const & name )
	{
		auto [size, offset] = doLookupMember( name, type );
		auto stride = type->getKind() == Kind::eArray
			? getArrayStride( type, getMemoryLayout() )
			: 0u;
		Member result{ std::move( type )
			, std::string( name )
			, offset
			, size
			, stride };
		doAddMember( result );
		return result;
	}

	Struct::Member BaseStruct::doCreateMember( TypePtr type
		, Builtin builtin
		, uint32_t index )
	{
		doLookupMember( getRealName( builtin, index ), type );
		Member result{ std::move( type )
			, builtin
			, index };
		doAddMember( result );
		return result;
	}

	//*************************************************************************

	IOStruct::IOStruct( TypesCache & cache
		, MemoryLayout layout
		, std::string name
		, var::Flag flag )
		: Struct{ cache, layout, name, flag }
	{
	}

	void IOStruct::declMember( Builtin builtin
		, Kind kind
		, uint32_t arraySize
		, uint32_t index )
	{
		TypePtr mbrType;
		auto type = getCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		doCreateMember( mbrType, builtin, index );
	}

	void IOStruct::declMember( Builtin builtin
		, ArrayPtr type
		, uint32_t arraySize
		, uint32_t index )
	{
		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		doCreateMember( mbrType, builtin, index );
	}

	void IOStruct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize
		, uint32_t location
		, bool enabled )
	{
		if ( !enabled )
		{
			return;
		}

		TypePtr mbrType;
		auto type = getCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		doCreateMember( mbrType, name, location );
	}

	void IOStruct::declMember( std::string name
		, TypePtr type
		, uint32_t location
		, bool enabled )
	{
		declMember( name
			, getNonArrayKind( type )
			, getArraySize( type )
			, location );
	}

	void IOStruct::declMember( std::string name
		, ArrayPtr type
		, uint32_t arraySize
		, uint32_t location
		, bool enabled )
	{
		if ( !enabled )
		{
			return;
		}

		auto mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
			, *this
			, uint32_t( size() ) );
		doCreateMember( mbrType, name, location );
	}

	void IOStruct::declMember( std::string name
		, ArrayPtr type
		, uint32_t location
		, bool enabled )
	{
		if ( !enabled )
		{
			return;
		}

		auto kind = getNonArrayKind( type );

		if ( kind == Kind::eStruct
			|| kind == Kind::eRayDesc )
		{
			declMember( name
				, std::static_pointer_cast< Struct >( type->getType() )
				, type->getArraySize() );
		}
		else if ( kind == Kind::eArray )
		{
			declMember( name
				, type->getType()->getKind()
				, type->getArraySize()
				, location );
		}
		else 
		{
			declMember( name
				, kind
				, type->getArraySize()
				, location );
		}
	}

	void IOStruct::declMember( std::string name
		, StructPtr type
		, uint32_t arraySize
		, bool enabled )
	{
		if ( !enabled )
		{
			return;
		}

		TypePtr mbrType = type;

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( mbrType, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( mbrType
				, *this
				, uint32_t( size() ) );
		}

		doCreateMember( mbrType
			, name
			, InvalidLocation );
	}

	void IOStruct::declMember( std::string name
		, StructPtr type
		, bool enabled )
	{
		declMember( name
			, type
			, NotArray );
	}

	Struct::Member IOStruct::doCreateMember( TypePtr type
		, std::string const & name
		, uint32_t location )
	{
		auto [size, offset] = doLookupMember( name, type );
		Member result{ std::move( type )
			, std::string( name )
			, offset
			, size
			, 0u
			, location };
		doAddMember( result );
		return result;
	}

	Struct::Member IOStruct::doCreateMember( TypePtr type
		, Builtin builtin
		, uint32_t index )
	{
		doLookupMember( getRealName( builtin, index ), type );
		Member result{ std::move( type )
			, builtin
			, index };
		doAddMember( result );
		return result;
	}

	//*************************************************************************

	RayDesc::RayDesc( TypesCache & cache )
		: BaseStruct{ cache, MemoryLayout::eC, "RayDesc", Kind::eRayDesc }
	{
		declMember( "Origin", Kind::eVec3F );
		declMember( "TMin", Kind::eFloat );
		declMember( "Direction", Kind::eVec3F );
		declMember( "TMax", Kind::eFloat );
	}

	//*************************************************************************

	size_t getHash( MemoryLayout layout
		, std::string const & name )
	{
		size_t result = std::hash< std::string >{}( name );
		result = hashCombine( result, layout );
		return result;
	}

	size_t getHash( MemoryLayout layout
		, std::string const & name
		, var::Flag flag )
	{
		size_t result = std::hash< std::string >{}( name );
		result = hashCombine( result, layout );
		result = hashCombine( result, flag );
		return result;
	}

	bool operator==( Struct const & lhs, Struct const & rhs )
	{
		auto result = static_cast< Type const & >( lhs ) == static_cast< Type const & >( rhs )
			&& lhs.getFlag() == rhs.getFlag()
			&& lhs.size() == rhs.size();
		auto itl = lhs.begin();
		auto itr = rhs.begin();

		while ( result && itl != lhs.end() )
		{
			result = itl->type->getKind() == itr->type->getKind()
				&& getArraySize( itl->type ) == getArraySize( itr->type );

			if ( result )
			{
				if ( itl->type->getKind() == Kind::eStruct
					|| itl->type->getKind() == Kind::eRayDesc )
				{
					result = static_cast< Struct const & >( *itl->type ) == static_cast< Struct const & >( *itr->type );
				}
				else
				{
					result = *itl->type == *itr->type;
				}
			}

			++itl;
			++itr;
		}

		return result;
	}

	//*************************************************************************

	bool isStructType( type::Type const & ptype )
	{
		auto type = &ptype;

		while ( type->getRawKind() != type::Kind::eStruct
			&& type->getRawKind() != type::Kind::eRayDesc )
		{
			if ( type->getRawKind() == type::Kind::ePointer )
			{
				type = static_cast< type::Pointer const & >( *type ).getPointerType().get();
			}
			else if ( type->getRawKind() == type::Kind::eRayPayload )
			{
				type = static_cast< type::RayPayload const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eCallableData )
			{
				type = static_cast< type::CallableData const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eHitAttribute )
			{
				type = static_cast< type::HitAttribute const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eFragmentInput )
			{
				type = static_cast< type::FragmentInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eGeometryInput )
			{
				type = static_cast< type::GeometryInput const & >( *type ).getType().get();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return isStructType( static_cast< type::Array const & >( *type ).getType() );
				}
			}
			else if ( type->getRawKind() == type::Kind::eGeometryOutput )
			{
				type = static_cast< type::GeometryOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eComputeInput )
			{
				type = static_cast< type::ComputeInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationInputPatch )
			{
				type = static_cast< type::TessellationInputPatch const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationOutputPatch )
			{
				type = static_cast< type::TessellationOutputPatch const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlInput )
			{
				type = static_cast< type::TessellationControlInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlOutput )
			{
				type = static_cast< type::TessellationControlOutput const & >( *type ).getType().get();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return isStructType( static_cast< type::Array const & >( *type ).getType() );
				}
			}
			else if ( type->getRawKind() == type::Kind::eTessellationEvaluationInput )
			{
				type = static_cast< type::TessellationEvaluationInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eMeshVertexOutput )
			{
				type = static_cast< type::MeshVertexOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eMeshPrimitiveOutput )
			{
				type = static_cast< type::MeshPrimitiveOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayload )
			{
				type = static_cast< type::TaskPayload const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadIn )
			{
				type = static_cast< type::TaskPayloadIn const & >( *type ).getType().get();
			}
			else
			{
				break;
			}
		}

		if ( type->getRawKind() == type::Kind::eStruct
			|| type->getRawKind() == type::Kind::eRayDesc )
		{
			return true;
		}

		return false;
	}

	bool isStructType( type::TypePtr type )
	{
		return isStructType( *type );
	}

	type::Struct const * getStructType( type::Type const & ptype )
	{
		auto type = &ptype;

		while ( type->getRawKind() != type::Kind::eStruct
			&& type->getRawKind() != type::Kind::eRayDesc )
		{
			if ( type->getRawKind() == type::Kind::ePointer )
			{
				type = static_cast< type::Pointer const & >( *type ).getPointerType().get();
			}
			else if ( type->getRawKind() == type::Kind::eRayPayload )
			{
				type = static_cast< type::RayPayload const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eCallableData )
			{
				type = static_cast< type::CallableData const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eHitAttribute )
			{
				type = static_cast< type::HitAttribute const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eFragmentInput )
			{
				type = static_cast< type::FragmentInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eGeometryInput )
			{
				type = static_cast< type::GeometryInput const & >( *type ).getType().get();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return getStructType( *static_cast< type::Array const & >( *type ).getType().get() );
				}
			}
			else if ( type->getRawKind() == type::Kind::eGeometryOutput )
			{
				type = static_cast< type::GeometryOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eComputeInput )
			{
				type = static_cast< type::ComputeInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationInputPatch )
			{
				type = static_cast< type::TessellationInputPatch const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationOutputPatch )
			{
				type = static_cast< type::TessellationOutputPatch const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlInput )
			{
				type = static_cast< type::TessellationControlInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlOutput )
			{
				type = static_cast< type::TessellationControlOutput const & >( *type ).getType().get();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return getStructType( *static_cast< type::Array const & >( *type ).getType().get() );
				}

				return nullptr;
			}
			else if ( type->getRawKind() == type::Kind::eTessellationEvaluationInput )
			{
				type = static_cast< type::TessellationEvaluationInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eMeshVertexOutput )
			{
				type = static_cast< type::MeshVertexOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eMeshPrimitiveOutput )
			{
				type = static_cast< type::MeshPrimitiveOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayload )
			{
				type = static_cast< type::TaskPayload const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadIn )
			{
				type = static_cast< type::TaskPayloadIn const & >( *type ).getType().get();
			}
			else
			{
				break;
			}
		}

		if ( type->getRawKind() == type::Kind::eStruct
			|| type->getRawKind() == type::Kind::eRayDesc )
		{
			return static_cast< type::Struct const * >( type );
		}

		return nullptr;
	}

	type::StructPtr getStructType( type::TypePtr type )
	{
		while ( type->getRawKind() != type::Kind::eStruct
			&& type->getRawKind() != type::Kind::eRayDesc )
		{
			if ( type->getRawKind() == type::Kind::ePointer )
			{
				type = static_cast< type::Pointer const & >( *type ).getPointerType();
			}
			else if ( type->getRawKind() == type::Kind::eRayPayload )
			{
				type = static_cast< type::RayPayload const & >( *type ).getDataType();
			}
			else if ( type->getRawKind() == type::Kind::eCallableData )
			{
				type = static_cast< type::CallableData const & >( *type ).getDataType();
			}
			else if ( type->getRawKind() == type::Kind::eHitAttribute )
			{
				type = static_cast< type::HitAttribute const & >( *type ).getDataType();
			}
			else if ( type->getRawKind() == type::Kind::eFragmentInput )
			{
				type = static_cast< type::FragmentInput const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eGeometryInput )
			{
				type = static_cast< type::GeometryInput const & >( *type ).getType();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return getStructType( static_cast< type::Array const & >( *type ).getType() );
				}
			}
			else if ( type->getRawKind() == type::Kind::eGeometryOutput )
			{
				type = static_cast< type::GeometryOutput const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eComputeInput )
			{
				type = static_cast< type::ComputeInput const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationInputPatch )
			{
				type = static_cast< type::TessellationInputPatch const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationOutputPatch )
			{
				type = static_cast< type::TessellationOutputPatch const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlInput )
			{
				type = static_cast< type::TessellationControlInput const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlOutput )
			{
				type = static_cast< type::TessellationControlOutput const & >( *type ).getType();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return getStructType( static_cast< type::Array const & >( *type ).getType() );
				}
			}
			else if ( type->getRawKind() == type::Kind::eTessellationEvaluationInput )
			{
				type = static_cast< type::TessellationControlInput const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eMeshVertexOutput )
			{
				type = static_cast< type::MeshVertexOutput const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eMeshPrimitiveOutput )
			{
				type = static_cast< type::MeshPrimitiveOutput const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayload )
			{
				type = static_cast< type::TaskPayload const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadIn )
			{
				type = static_cast< type::TaskPayloadIn const & >( *type ).getType();
			}
			else
			{
				break;
			}
		}

		if ( type->getRawKind() == type::Kind::eStruct
			|| type->getRawKind() == type::Kind::eRayDesc )
		{
			return std::static_pointer_cast< type::Struct >( type );
		}

		return nullptr;
	}

	uint32_t getSize( Type const & type
		, MemoryLayout layout )
	{
		if ( layout == MemoryLayout::eC )
		{
			return getNaiveSize( type );
		}

		return getPackedSize( type, layout );
	}

	uint32_t getSize( TypePtr type
		, MemoryLayout layout )
	{
		return getSize( *type, layout );
	}

	uint32_t getAlignment( Type const & type
		, MemoryLayout layout )
	{
		if ( layout == MemoryLayout::eC )
		{
			return 1u;
		}

		return getPackedAlignment( type, layout );
	}

	uint32_t getAlignment( TypePtr type
		, MemoryLayout layout )
	{
		return getAlignment( *type, layout );
	}

	uint32_t getArrayStride( Array const & type
		, MemoryLayout layout )
	{
		if ( layout == MemoryLayout::eC )
		{
			return getNaiveSize( *type.getType() );
		}

		return getPackedArrayStride( type, layout );
	}

	uint32_t getArrayStride( ArrayPtr type
		, MemoryLayout layout )
	{
		return getArrayStride( *type, layout );
	}

	uint32_t getArrayStride( Type const & type
		, MemoryLayout layout )
	{
		return type.getKind() == Kind::eArray
			? getArrayStride( static_cast< Array const & >( type ), layout )
			: 1u;
	}

	uint32_t getArrayStride( TypePtr type
		, MemoryLayout layout )
	{
		return getArrayStride( *type, layout );
	}

	bool hasRuntimeArray( TypePtr type )
	{
		if ( type->getKind() != Kind::eStruct )
		{
			return false;
		}

		return getArraySize( getStructType( type )->back().type ) == UnknownArraySize;
	}

	//*************************************************************************
}
