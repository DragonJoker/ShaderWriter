/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeStruct.hpp"

#include "ShaderAST/Shader.hpp"
#include "ShaderAST/Type/TypeCache.hpp"

#include <algorithm>
#include <string_view>

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
			case Kind::eInt64:
			case Kind::eUInt64:
				return mult * 8u;
			case Kind::eFloat:
			case Kind::eInt32:
			case Kind::eUInt32:
				return mult * 4u;
			case Kind::eInt16:
			case Kind::eUInt16:
			case Kind::eHalf:
				return mult * 2u;
			case Kind::eBoolean:
			case Kind::eInt8:
			case Kind::eUInt8:
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
			case Kind::eInt64:
			case Kind::eUInt64:
				return 8u;
			case Kind::eFloat:
			case Kind::eInt32:
			case Kind::eUInt32:
				return 4u;
			case Kind::eInt16:
			case Kind::eUInt16:
			case Kind::eHalf:
				return 2u;
			case Kind::eBoolean:
			case Kind::eInt8:
			case Kind::eUInt8:
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

			auto const * tmp = type.getType().get();

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
			if ( auto arraySize = getArraySize( type );
				arraySize != NotArray )
			{
				return getPackedAlignment( static_cast< Array const & >( type )
					, layout );
			}

			if ( auto kind = getNonArrayKindRec( type );
				kind == Kind::eStruct || kind == Kind::eRayDesc )
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

					// The next member following a struct member is aligned to the base alignment of the struct that came before.
					// GL 4.5 spec, 7.6.2.2.
					if ( auto kind = getNonArrayKindRec( *member.type );
						kind == Kind::eStruct || kind == Kind::eRayDesc )
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
			if ( auto arraySize = getArraySize( type );
				arraySize != NotArray )
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

			if ( kind == Kind::eVoid )
			{
				return 0u;
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

	Struct::Struct( TypesCache & typesCache
		, Struct const & rhs )
		: Type{ typesCache, Kind::eStruct }
		, m_name{ rhs.getName() }
		, m_layout{ rhs.m_layout }
		, m_flag{ rhs.m_flag }
		, m_entryPoint{ rhs.m_entryPoint }
	{
		doCopyMembers( rhs );
	}

	Struct::Struct( TypesCache & typesCache
		, Struct * parent
		, uint32_t index
		, Struct const & copy )
		: Type{ typesCache, parent, index, copy }
		, m_name{ copy.getName() }
		, m_layout{ copy.m_layout }
		, m_flag{ copy.m_flag }
		, m_entryPoint{ copy.m_entryPoint }
	{
		doCopyMembers( copy );
	}


	Struct::Struct( TypesCache & typesCache
		, Struct & parent
		, uint32_t index
		, Struct const & copy )
		: Struct{ typesCache, &parent, index, copy }
	{
	}

	Struct::Struct( TypesCache & typesCache
		, MemoryLayout layout
		, std::string name
		, var::Flag flag
		, Kind kind
		, EntryPoint entryPoint )
		: Type{ typesCache, kind }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
		, m_flag{ flag }
		, m_entryPoint{ entryPoint }
	{
	}

	Struct::Member Struct::getMember( uint32_t index )const
	{
		return m_members[index];
	}

	Struct::Member Struct::getMember( std::string_view name )const
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Member const & lookup )
			{
				return lookup.name == name;
			} );

		if ( it == m_members.end() )
		{
			throw Exception{ "Struct member [" + std::string( name ) + "] was not found." };
		}

		return *it;
	}

	uint32_t Struct::findMember( std::string_view name )const
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
		, uint32_t index )const
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
			throw Exception{ "Struct member [" + getRealName( builtin, index ) + "] was not found." };
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
		return std::shared_ptr< Struct >( new Struct{ getTypesCache()
			, parent
			, index
			, *this } );
	}

	std::tuple< uint32_t, uint32_t, bool > Struct::doLookupMember( std::string_view name
		, TypePtr type )
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Struct::Member const & lookup )
			{
				return lookup.name == name;
			} );
		uint32_t offset{};

		if ( it != m_members.end() )
		{
			offset = it->offset;
		}
		else
		{
			offset = ( m_members.empty()
				? 0u
				: m_members.back().offset + m_members.back().size );
		}

		return std::make_tuple( getSize( *type, m_layout )
			, offset
			, it != m_members.end() );
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
				: ( prvIsStruct ? prvAlignment : getAlignment( *member.type, m_layout ) ) );
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

	BaseStruct::BaseStruct( TypesCache & typesCache
		, MemoryLayout layout
		, std::string name
		, Kind kind )
		: Struct{ typesCache, layout, std::move( name ), {}, kind }
	{
	}

	BaseStruct::BaseStruct( TypesCache & typesCache
		, MemoryLayout layout
		, std::string name )
		: BaseStruct{ typesCache, layout, std::move( name ), Kind::eStruct }
	{
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( Builtin builtin
		, Kind kind
		, uint32_t arraySize
		, uint32_t index
		, bool enabled )
	{
		if ( !enabled )
		{
			return { Struct::Member{}, false };
		}

		TypePtr mbrType;
		auto type = getTypesCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, builtin, index );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize
		, bool enabled )
	{
		if ( !enabled )
		{
			return { Struct::Member{}, false };
		}

		TypePtr mbrType;
		auto type = getTypesCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, std::move( name ) );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, TypePtr type
		, uint32_t arraySize
		, bool enabled )
	{
		if ( !enabled )
		{
			return { Struct::Member{}, false };
		}

		if ( type->getKind() == Kind::eArray )
		{
			return declMember( std::move( name )
				, std::static_pointer_cast< Array >( type )
				, arraySize );
		}

		if ( type->getKind() == Kind::eStruct )
		{
			auto structType = getStructType( type );

			if ( structType->getFlag() == 0u )
			{
				return declMember( std::move( name )
					, std::static_pointer_cast< BaseStruct >( structType )
					, arraySize );
			}

			return declMember( std::move( name )
				, std::static_pointer_cast< IOStruct >( structType )
				, arraySize );
		}

		if ( arraySize == NotArray )
		{
			return declMember( std::move( name )
				, getNonArrayKind( type )
				, getArraySize( type ) );
		}

		return declMember( std::move( name )
			, type->getKind()
			, arraySize );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, ArrayPtr type
		, uint32_t arraySize
		, bool enabled )
	{
		if ( !enabled )
		{
			return { Struct::Member{}, false };
		}

		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, std::move( name ) );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, ArrayPtr type
		, bool enabled )
	{
		if ( !enabled )
		{
			return { Struct::Member{}, false };
		}

		auto kind = getNonArrayKind( type );

		if ( kind == Kind::eStruct
			|| kind == Kind::eRayDesc )
		{
			auto structType = std::static_pointer_cast< Struct >( type->getType() );

			if ( structType->getFlag() )
			{
				return declMember( std::move( name )
					, std::static_pointer_cast< IOStruct >( structType )
					, type->getArraySize() );
			}

			return declMember( std::move( name )
				, std::static_pointer_cast< BaseStruct >( structType )
				, type->getArraySize() );
		}

		if ( kind == Kind::eArray )
		{
			return declMember( std::move( name )
				, std::static_pointer_cast< Array >( type->getType() )
				, type->getArraySize() );
		}

		return declMember( std::move( name )
			, kind
			, type->getArraySize() );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, BaseStructPtr type
		, uint32_t arraySize
		, bool enabled )
	{
		if ( !enabled )
		{
			return { Struct::Member{}, false };
		}

		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getStruct( type->getMemoryLayout(), type->getName() );
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( mbrType, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getStruct( type->getMemoryLayout(), type->getName() );
			mbrType = getTypesCache().getMemberType( mbrType
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, std::move( name ) );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, BaseStructPtr type
		, bool enabled )
	{
		return declMember( std::move( name )
			, type
			, NotArray
			, enabled );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, IOStructPtr type
		, uint32_t arraySize
		, bool enabled )
	{
		if ( !enabled )
		{
			return { Struct::Member{}, false };
		}

		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, std::move( name ) );
	}

	std::pair< Struct::Member, bool > BaseStruct::declMember( std::string name
		, IOStructPtr type
		, bool enabled )
	{
		return declMember( std::move( name )
			, type
			, NotArray
			, enabled );
	}

	std::pair< Struct::Member, bool > BaseStruct::doCreateMember( TypePtr type
		, std::string name )
	{
		auto [size, offset, exists] = doLookupMember( name, type );
		auto stride = type->getKind() == Kind::eArray
			? getArrayStride( type, getMemoryLayout() )
			: 0u;

		if ( exists )
		{
			return { getMember( name ), false };
		}

		Member result{ std::move( type )
			, std::move( name )
			, offset
			, size
			, stride };
		doAddMember( result );
		return { result, true };
	}

	std::pair< Struct::Member, bool > BaseStruct::doCreateMember( TypePtr type
		, Builtin builtin
		, uint32_t index )
	{
		auto [size, offset, exists] = doLookupMember( getRealName( builtin, index ), type );

		if ( exists )
		{
			return { getMember( builtin ), false };
		}

		Member result{ std::move( type )
			, builtin
			, index };
		doAddMember( result );
		return { result, true };
	}

	//*************************************************************************

	IOStruct::IOStruct( TypesCache & typesCache
		, MemoryLayout layout
		, std::string name
		, EntryPoint entryPoint
		, var::Flag flag )
		: Struct{ typesCache, layout, std::move( name ), flag, type::Kind::eStruct, entryPoint }
	{
	}

	bool IOStruct::declMember( Builtin builtin
		, Kind kind
		, uint32_t arraySize
		, uint32_t index )
	{
		TypePtr mbrType;
		auto type = getTypesCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, builtin, index ).second;
	}

	bool IOStruct::declMember( Builtin builtin
		, ArrayPtr type
		, uint32_t arraySize
		, uint32_t index )
	{
		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, builtin, index ).second;
	}

	bool IOStruct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize
		, uint32_t location
		, bool enabled )
	{
		if ( !enabled )
		{
			return false;
		}

		TypePtr mbrType;
		auto type = getTypesCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( type
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType, std::move( name ), location ).second;
	}

	bool IOStruct::declMember( std::string name
		, TypePtr type
		, uint32_t location
		, bool enabled )
	{
		return declMember( std::move( name )
			, getNonArrayKind( type )
			, getArraySize( type )
			, location
			, enabled );
	}

	bool IOStruct::declMember( std::string name
		, TypePtr type
		, uint32_t arraySize
		, uint32_t location
		, bool enabled )
	{
		auto internalArraySize = getArraySize( type );
		return declMember( std::move( name )
			, getNonArrayKind( type )
			, ( arraySize == NotArray
				? internalArraySize
				: ( internalArraySize == NotArray ? arraySize : internalArraySize * arraySize ) )
			, location
			, enabled );
	}

	bool IOStruct::declMember( std::string name
		, ArrayPtr type
		, uint32_t arraySize
		, uint32_t location
		, bool enabled )
	{
		if ( !enabled )
		{
			return false;
		}

		auto mbrType = getTypesCache().getMemberType( getTypesCache().getArray( type, arraySize )
			, *this
			, uint32_t( size() ) );
		return doCreateMember( mbrType, std::move( name ), location ).second;
	}

	bool IOStruct::declMember( std::string name
		, ArrayPtr type
		, uint32_t location
		, bool enabled )
	{
		if ( !enabled )
		{
			return false;
		}

		auto kind = getNonArrayKind( type );

		if ( kind == Kind::eStruct
			|| kind == Kind::eRayDesc )
		{
			return declMember( std::move( name )
				, std::static_pointer_cast< Struct >( type->getType() )
				, type->getArraySize() );
		}

		if ( kind == Kind::eArray )
		{
			return declMember( std::move( name )
				, type->getType()->getKind()
				, type->getArraySize()
				, location );
		}

		return declMember( std::move( name )
			, kind
			, type->getArraySize()
			, location );
	}

	bool IOStruct::declMember( std::string name
		, StructPtr type
		, uint32_t arraySize
		, bool enabled )
	{
		if ( !enabled )
		{
			return false;
		}

		TypePtr mbrType = type;

		if ( arraySize != NotArray )
		{
			mbrType = getTypesCache().getMemberType( getTypesCache().getArray( mbrType, arraySize )
				, *this
				, uint32_t( size() ) );
		}
		else
		{
			mbrType = getTypesCache().getMemberType( mbrType
				, *this
				, uint32_t( size() ) );
		}

		return doCreateMember( mbrType
			, std::move( name )
			, InvalidLocation ).second;
	}

	bool IOStruct::declMember( std::string name
		, StructPtr type
		, bool enabled )
	{
		return declMember( std::move( name )
			, type
			, NotArray
			, enabled );
	}

	std::pair< Struct::Member, bool > IOStruct::doCreateMember( TypePtr type
		, std::string name
		, uint32_t location )
	{
		auto [size, offset, exists] = doLookupMember( name, type );

		if ( exists )
		{
			return { getMember( name ), false };
		}

		Member result{ std::move( type )
			, std::move( name )
			, offset
			, size
			, 0u
			, location };
		doAddMember( result );
		return { result, true };
	}

	std::pair< Struct::Member, bool > IOStruct::doCreateMember( TypePtr type
		, Builtin builtin
		, uint32_t index )
	{
		auto [size, offset, exists] = doLookupMember( getRealName( builtin, index ), type );

		if ( exists )
		{
			return { getMember( builtin ), false };
		}

		Member result{ std::move( type )
			, builtin
			, index };
		doAddMember( result );
		return { result, true };
	}

	//*************************************************************************

	RayDesc::RayDesc( TypesCache & typesCache )
		: BaseStruct{ typesCache, MemoryLayout::eC, "RayDesc", Kind::eRayDesc }
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
		, EntryPoint entryPoint
		, var::Flag flag )
	{
		size_t result = std::hash< std::string >{}( name );
		result = hashCombine( result, layout );
		result = hashCombine( result, entryPoint );
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
			else if ( type->getRawKind() == type::Kind::eTaskPayloadNV )
			{
				type = static_cast< type::TaskPayloadNV const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayload )
			{
				type = static_cast< type::TaskPayload const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadInNV )
			{
				type = static_cast< type::TaskPayloadInNV const & >( *type ).getType().get();
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
			else if ( type->getRawKind() == type::Kind::eTaskPayloadNV )
			{
				type = static_cast< type::TaskPayloadNV const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayload )
			{
				type = static_cast< type::TaskPayload const & >( *type ).getType();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadInNV )
			{
				type = static_cast< type::TaskPayloadInNV const & >( *type ).getType();
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
