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

		uint32_t getNaiveSize( Type const & type )
		{
			auto arraySize = getArraySize( type );
			return ( arraySize == NotArray
				? getNaiveSize( type.getKind() )
				: arraySize * getNaiveSize( getNonArrayType( type ) ) );
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

			if ( kind == Kind::eStruct )
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
				return ( size + alignment - 1 ) & ~( alignment - 1 );
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
			uint32_t padAlignment = 1;

			for ( auto & member : type )
			{
				uint32_t packedAlignment = getPackedAlignment( *member.type, layout );
				uint32_t alignment = std::max( packedAlignment, padAlignment );
				auto kind = getNonArrayKindRec( *member.type );

				// The next member following a struct member is aligned to the base alignment of the struct that came before.
				// GL 4.5 spec, 7.6.2.2.
				if ( kind == Kind::eStruct )
				{
					padAlignment = packedAlignment;
				}
				else
				{
					padAlignment = 1;
				}

				result = ( result + alignment - 1 ) & ~( alignment - 1 );
				result += getPackedSize( *member.type, layout );
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

			if ( kind == Kind::eStruct )
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

		uint32_t getAligned( uint32_t value, uint32_t align )
		{
			return ( value + align - 1 ) & ~( align - 1 );
		}
	}

	//*************************************************************************

	Struct::Struct( TypesCache & cache
		, Struct const & rhs )
		: Type{ cache, Kind::eStruct }
		, m_name{ rhs.getName() }
		, m_layout{ rhs.m_layout }
	{
		for ( auto & member : rhs )
		{
			if ( member.type->getKind() == Kind::eArray )
			{
				declMember( member.name
					, std::static_pointer_cast< Array >( member.type ) );
			}
			else if ( member.type->getKind() == Kind::eStruct )
			{
				declMember( member.name
					, std::static_pointer_cast< Struct >( member.type ) );
			}
			else
			{
				declMember( member.name
					, member.type );
			}
		}
	}

	Struct::Struct( TypesCache & cache
		, Struct * parent
		, uint32_t index
		, Struct const & copy )
		: Type{ cache, parent, index, copy }
		, m_name{ copy.getName() }
		, m_layout{ copy.m_layout }
	{
		for ( auto & member : copy )
		{
			if ( member.type->getKind() == Kind::eArray )
			{
				declMember( member.name
					, std::static_pointer_cast< Array >( member.type ) );
			}
			else if ( member.type->getKind() == Kind::eStruct )
			{
				declMember( member.name
					, std::static_pointer_cast< Struct >( member.type ) );
			}
			else
			{
				declMember( member.name
					, member.type );
			}
		}
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
		, std::string name )
		: Type{ cache, Kind::eStruct }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
	{
	}

	Struct::Member Struct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize )
	{
		TypePtr mbrType;
		auto type = getCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
				, *this
				, uint32_t( m_members.size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( type
				, *this
				, uint32_t( m_members.size() ) );
		}

		return doAddMember( mbrType, name );
	}

	Struct::Member Struct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize
		, uint32_t location
		, var::Flag input )
	{
		TypePtr mbrType;
		auto type = getCache().getBasicType( kind );

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
				, *this
				, uint32_t( m_members.size() ) );
		}
		else
		{
			mbrType = getCache().getMemberType( type
				, *this
				, uint32_t( m_members.size() ) );
		}

		return doAddIOMember( mbrType, name, location, input );
	}

	Struct::Member Struct::declMember( std::string name
		, TypePtr type )
	{
		return declMember( name
			, getNonArrayKind( type )
			, getArraySize( type ) );
	}

	Struct::Member Struct::declMember( std::string name
		, ArrayPtr type
		, uint32_t arraySize )
	{
		auto mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
			, *this
			, uint32_t( m_members.size() ) );
		return doAddMember( mbrType, name );
	}

	Struct::Member Struct::declMember( std::string name
		, ArrayPtr type
		, uint32_t arraySize
		, uint32_t location
		, var::Flag input )
	{
		auto mbrType = getCache().getMemberType( getCache().getArray( type, arraySize )
			, *this
			, uint32_t( m_members.size() ) );
		return doAddIOMember( mbrType, name, location, input );
	}

	Struct::Member Struct::declMember( std::string name
		, ArrayPtr type )
	{
		Struct::Member result;
		auto kind = getNonArrayKind( type );

		if ( kind == Kind::eStruct )
		{
			result = declMember( name
				, std::static_pointer_cast< Struct >( type->getType() )
				, type->getArraySize() );
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

	Struct::Member Struct::declMember( std::string name
		, StructPtr type
		, uint32_t arraySize )
	{
		TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = getCache().getStruct( type->getMemoryLayout(), type->getName() );
			mbrType = getCache().getMemberType( getCache().getArray( mbrType, arraySize )
				, *this
				, uint32_t( m_members.size() ) );
		}
		else
		{
			mbrType = getCache().getStruct( type->getMemoryLayout(), type->getName() );
			mbrType = getCache().getMemberType( mbrType
				, *this
				, uint32_t( m_members.size() ) );
		}

		return doAddMember( mbrType, name );
	}

	Struct::Member Struct::declMember( std::string name
		, StructPtr type )
	{
		return declMember( name
			, type
			, NotArray );
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

	uint32_t Struct::findMember( std::string const & name )
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

	Struct::Member Struct::doAddMember( TypePtr type
		, std::string const & name )
	{
		auto [size, offset] = doLookupMember( name, type );
		auto stride = type->getKind() == Kind::eArray
			? getArrayStride( type, m_layout )
			: 0u;
		m_members.push_back( { std::move( type )
			, std::string( name )
			, offset
			, size
			, stride } );
		doUpdateOffsets();
		return m_members.back();
	}

	Struct::Member Struct::doAddIOMember( TypePtr type
		, std::string const & name
		, uint32_t location
		, var::Flag input )
	{
		auto [size, offset] = doLookupMember( name, type );
		m_members.push_back( { std::move( type )
			, std::string( name )
			, offset
			, size
			, location
			, input } );
		return m_members.back();
	}

	void Struct::doUpdateOffsets()
	{
		uint32_t offset = 0u;

		for ( auto & member : m_members )
		{
			uint32_t alignment = getAlignment( *member.type, m_layout );
			member.offset = getAligned( offset, alignment );
			offset = member.offset + getAligned( member.size, alignment );
		}
	}

	//*************************************************************************

	size_t getHash( MemoryLayout layout, std::string const & name )
	{
		size_t result = std::hash< std::string >{}( name );
		result = hashCombine( result, layout );
		return result;
	}

	bool operator==( Struct const & lhs, Struct const & rhs )
	{
		auto result = static_cast< Type const & >( lhs ) == static_cast< Type const & >( rhs )
			&& lhs.size() == rhs.size();
		auto itl = lhs.begin();
		auto itr = rhs.begin();

		while ( result && itl != lhs.end() )
		{
			result = itl->type->getKind() == itr->type->getKind()
				&& getArraySize( itl->type ) == getArraySize( itr->type );

			if ( result )
			{
				if ( itl->type->getKind() == Kind::eStruct )
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

	//*************************************************************************
}
