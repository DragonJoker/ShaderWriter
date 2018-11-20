/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/TypeStruct.hpp"

#include <algorithm>

namespace ast::type
{
	//*************************************************************************

	namespace
	{
		uint32_t getAlignedSize( uint32_t size, uint32_t align )
		{
			uint32_t result = 0u;

			while ( size > align )
			{
				size -= align;
				result += align;
			}

			return result + align;
		}

		uint32_t getScalarSize( Kind kind )
		{
			assert( isScalarType( kind ) );
			uint32_t result;

			switch ( kind )
			{
			case Kind::eBoolean:
				result = 1u;
				break;
			case Kind::eHalf:
				result = 2u;
				break;
			case Kind::eInt:
			case Kind::eUInt:
			case Kind::eFloat:
				result = 4u;
				break;
			case Kind::eDouble:
				result = 8u;
				break;
			}

			return result;
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

		uint32_t getPackedBaseSize( Kind kind )
		{
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
				assert( false && "Unsupported type::Kind" );
				return 0u;
			}
		}

		uint32_t getPackedAlignment( Type const & type
			, MemoryLayout layout );

		uint32_t getPackedAlignment( Struct const & type
			, MemoryLayout layout )
		{
			// Rule 9. Structs alignments are maximum alignment of its members.
			uint32_t alignment = 0;

			for ( auto & member : type )
			{
				alignment = std::max( alignment, getPackedAlignment( *member.type, layout ) );
			}

			//// In std140, struct alignment is rounded up to 16.
			//if ( isVec4Padded( layout ) )
			//{
			//	alignment = std::max( alignment, 16u );
			//}

			return alignment;
		}

		uint32_t getPackedAlignment( Kind kind
			, MemoryLayout layout )
		{
			uint32_t const baseAlignment = getPackedBaseSize( getScalarType( kind ) );
			uint32_t result;
			// From 7.6.2.2 in GL 4.5 core spec
			// (https://www.khronos.org/registry/OpenGL/specs/gl/glspec45.core.pdf).

			if ( isScalarType( kind ) )
			{
				// Rule 1
				result = baseAlignment;
			}
			else
			{
				auto componentCount = getComponentCount( kind );

				if ( isVectorType( kind )
					&& ( componentCount == 2u || componentCount == 4u ) )
				{
					// Rule 2
					result = componentCount * baseAlignment;
				}
				else if ( isVectorType( kind )
						&& componentCount == 3u )
				{
					// Rule 3
					result = 4u * baseAlignment;
				}
				else
				{
					// Rule 4 is about arrays.

					/* Not scalar, not vector => Matrix type */
					componentCount = getComponentCount( getComponentType( kind ) );

					// Rule 5: Column-major matrices are stored as arrays of
					// vectors.
					if ( isVec4Padded( layout ) )
					{
						result = 4u * baseAlignment;
					}
					else if ( componentCount == 3u )
					{
						result = 4u * baseAlignment;
					}
					else
					{
						result = componentCount * baseAlignment;
					}
					// Rule 6 is about arrays.

					// Rule 7 is about column matrices, that are not supported. TODO ?.

					// Rule 8 is about arrays.

					// Rule 9 is about structures.
				}
			}

			return result;
		}

		uint32_t getPackedAlignment( Type const & type
			, MemoryLayout layout )
		{
			uint32_t result = 0u;

			if ( getArraySize( type ) != NotArray )
			{
				uint32_t const minimumAlignment = isVec4Padded( layout )
					? 16u
					: 1u;
				// Get the alignment of the base type, then maybe round up.
				result = std::max( minimumAlignment
					, getPackedAlignment( *static_cast< Array const & >( type ).getType()
						, layout ) );
			}
			else if ( type.getKind() == Kind::eStruct )
			{
				result = getPackedAlignment( static_cast< Struct const & >( type )
					, layout );
			}
			else
			{
				result = getPackedAlignment( getNonArrayKind( type )
					, layout );
			}

			return result;
		}

		uint32_t getSize140( Kind kind
			, bool isArray );

		uint32_t getSize140NotArray( Kind kind
			, bool isVec4Padded )
		{
			// From 7.6.2.2 in GL 4.5 core spec
			// (https://www.khronos.org/registry/OpenGL/specs/gl/glspec45.core.pdf).

			// Rule 1
			if ( isScalarType( kind ) )
			{
				return getScalarSize( kind );
			}

			auto componentCount = getComponentCount( kind );

			// Rule 2
			if ( isVectorType( kind )
				&& ( componentCount == 2u || componentCount == 4u ) )
			{
				return componentCount * getScalarSize( getComponentType( kind ) );
			}

			// Rule 3
			if ( isVectorType( kind )
				&& componentCount == 3u )
			{
				return 4u * getScalarSize( getComponentType( kind ) );
			}

			// Rule 4 is about arrays.

			/* Not scalar, not vector => Matrix type */

			// Rule 5: Column-major matrices are stored as arrays of
			// vectors.
			if ( isVec4Padded )
			{
				return componentCount * 4u * getScalarSize( getComponentType( getComponentType( kind ) ) );
			}
			else
			{
				return componentCount * getSize140( getComponentType( kind ), true );
			}

			// Rule 6 is about arrays.

			// Rule 7 is about column matrices, that are not supported. TODO ?.

			// Rule 8 is about arrays.

			// Rule 9 is about structures.
		}

		uint32_t getSize140( Kind kind
			, bool isArray )
		{
			if ( !isArray )
			{
				return getSize140NotArray( kind, false );
			}

			return std::max( 16u, getSize140NotArray( kind, true ) );
		}

		uint32_t getSize430( Kind kind
			, bool isArray );

		uint32_t getSize430NotArray( Kind kind )
		{
			// From 7.6.2.2 in GL 4.5 core spec
			// (https://www.khronos.org/registry/OpenGL/specs/gl/glspec45.core.pdf).

			// Rule 1
			if ( isScalarType( kind ) )
			{
				return getScalarSize( kind );
			}

			auto componentCount = getComponentCount( kind );

			// Rule 2
			if ( isVectorType( kind )
				&& ( componentCount == 2u || componentCount == 4u ) )
			{
				return componentCount * getScalarSize( getComponentType( kind ) );
			}

			// Rule 3
			if ( isVectorType( kind )
				&& componentCount == 3u )
			{
				return 4u * getScalarSize( getComponentType( kind ) );
			}

			// Rule 4 is about arrays.

			/* Not scalar, not vector => Matrix type */

			// Rule 5: Column-major matrices are stored as arrays of
			// vectors.
			return componentCount * getSize430( getComponentType( kind ), true );

			// Rule 6 is about arrays.

			// Rule 7 is about column matrices, that are not supported. TODO ?.

			// Rule 8 is about arrays.

			// Rule 9 is about structures.
		}

		uint32_t getSize430( Kind kind
			, bool isArray )
		{
			return getSize430NotArray( kind );
		}

		uint32_t getSize( Kind kind
			, bool isArray
			, MemoryLayout layout )
		{
			assert( isScalarType( kind )
				|| isVectorType( kind )
				|| isMatrixType( kind ) );

			uint32_t result;

			if ( layout == MemoryLayout::eStd430 )
			{
				result = getSize430( kind, isArray );
			}
			else
			{
				result = getSize140( kind, isArray );
			}

			return result;
		}

		uint32_t getSize( Struct const & type
			, MemoryLayout layout )
		{
			uint32_t result{ 0u };

			if ( !type.empty() )
			{
				auto & member = type.back();
				result = member.offset + member.size;
			}

			return result;
		}

		uint32_t getSize( Type const & type
			, MemoryLayout layout )
		{
			uint32_t result;
			auto arraySize = getArraySize( type );

			if ( type.getKind() == Kind::eStruct )
			{
				result = getSize( static_cast< Struct const & >( type )
					, layout );
			}
			else if ( type.getKind() == Kind::eArray )
			{
				result = getSize( *static_cast< Array const & >( type ).getType()
					, layout );
			}
			else
			{
				result = getSize( getNonArrayKind( type )
					, false
					, layout );
			}

			return ( arraySize != type::NotArray && arraySize != type::UnknownArraySize )
				? result * arraySize
				: result;
		}

		uint32_t getAlignment140( Kind kind
			, bool isArray );

		uint32_t getAlignment140NotArray( Kind kind
			, bool isVec4Padded )
		{
			// From 7.6.2.2 in GL 4.5 core spec
			// (https://www.khronos.org/registry/OpenGL/specs/gl/glspec45.core.pdf).

			// Rule 1
			if ( isScalarType( kind ) )
			{
				return 1u;
			}

			auto componentCount = getComponentCount( kind );

			// Rule 2
			if ( isVectorType( kind )
				&& ( componentCount == 2u || componentCount == 4u ) )
			{
				return componentCount * getScalarSize( getComponentType( kind ) );
			}

			// Rule 3
			if ( isVectorType( kind )
				&& componentCount == 3u )
			{
				return 4u * getScalarSize( getComponentType( kind ) );
			}

			// Rule 4 is about arrays.

			/* Not scalar, not vector => Matrix type */

			// Rule 5: Column-major matrices are stored as arrays of
			// vectors.
			if ( isVec4Padded )
			{
				return componentCount * 4u * getScalarSize( getComponentType( getComponentType( kind ) ) );
			}
			else
			{
				return componentCount * getAlignment140( getComponentType( kind ), true );
			}

			// Rule 6 is about arrays.

			// Rule 7 is about column matrices, that are not supported. TODO ?.

			// Rule 8 is about arrays.

			// Rule 9 is about structures.
		}

		uint32_t getAlignment140( Kind kind
			, bool isArray )
		{
			if ( !isArray )
			{
				return getAlignment140NotArray( kind, false );
			}

			return std::max( 16u, getAlignment140NotArray( kind, true ) );
		}

		uint32_t getAlignment430( Kind kind
			, bool isArray );

		uint32_t getAlignment430NotArray( Kind kind )
		{
			// From 7.6.2.2 in GL 4.5 core spec
			// (https://www.khronos.org/registry/OpenGL/specs/gl/glspec45.core.pdf).

			// Rule 1
			if ( isScalarType( kind ) )
			{
				return 1u;
			}

			auto componentCount = getComponentCount( kind );

			// Rule 2
			if ( isVectorType( kind )
				&& ( componentCount == 2u || componentCount == 4u ) )
			{
				return componentCount * getScalarSize( getComponentType( kind ) );
			}

			// Rule 3
			if ( isVectorType( kind )
				&& componentCount == 3u )
			{
				return 4u * getScalarSize( getComponentType( kind ) );
			}

			// Rule 4 is about arrays.

			/* Not scalar, not vector => Matrix type */

			// Rule 5: Column-major matrices are stored as arrays of
			// vectors.
			return componentCount * getAlignment430( getComponentType( kind ), true );

			// Rule 6 is about arrays.

			// Rule 7 is about column matrices, that are not supported. TODO ?.

			// Rule 8 is about arrays.

			// Rule 9 is about structures.
		}

		uint32_t getAlignment430( Kind kind
			, bool isArray )
		{
			return getAlignment430NotArray( kind );
		}

		uint32_t getAlignment( Kind kind
			, bool isArray
			, MemoryLayout layout )
		{
			assert( isScalarType( kind )
				|| isVectorType( kind )
				|| isMatrixType( kind ) );

			uint32_t result;

			if ( layout == MemoryLayout::eStd430 )
			{
				result = getAlignment430( kind, isArray );
			}
			else
			{
				result = getAlignment140( kind, isArray );
			}

			return result;
		}

		uint32_t getAlignment( Struct const & type
			, MemoryLayout layout )
		{
			// Rule 9. Structs alignments are maximum alignment of its members.
			uint32_t result = 0u;

			for ( auto & member : type )
			{
				result = std::max( result, getAlignment( member.type, layout ) );
			}

			// In std140, struct alignment is rounded up to 16.
			if ( layout == MemoryLayout::eStd140 )
			{
				result = std::max( result, 16u );
			}

			return result;
		}

		uint32_t getAlignment( Type const & type
			, MemoryLayout layout )
		{
			uint32_t result = type.getKind() == Kind::eStruct
				? getAlignment( static_cast< Struct const & >( type ), layout )
				: getAlignment( type.getKind(), getArraySize( type ) != type::NotArray, layout );
			return ( getArraySize( type ) != type::NotArray && getArraySize( type ) != type::UnknownArraySize )
				? result * getArraySize( type )
				: result;
		}
	}

	Struct::Struct( Struct const & rhs )
		: Type{ Kind::eStruct }
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

	Struct::Struct( Struct * parent
		, uint32_t index
		, Struct const & copy )
		: Type{ parent, index, Kind::eStruct }
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

	Struct::Struct( MemoryLayout layout
		, std::string name )
		: Type{ Kind::eStruct }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
	{
	}

	Struct::Member Struct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize )
	{
		type::TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = std::make_shared< Array >( this
				, uint32_t( m_members.size() )
				, makeType( kind )
				, arraySize );
		}
		else
		{
			mbrType = std::shared_ptr< Type >( new Type
				{
					this,
					uint32_t( m_members.size() ),
					kind,
				} );
		}

		return doAddMember( mbrType, name );
	}

	Struct::Member Struct::declMember( std::string name
		, StructPtr type
		, uint32_t arraySize )
	{
		type::TypePtr mbrType;

		if ( arraySize != NotArray )
		{
			mbrType = std::shared_ptr< Struct >( new Struct{ *type } );
			mbrType = std::make_shared< Array >( this
				, uint32_t( m_members.size() )
				, std::move( mbrType )
				, arraySize );
		}
		else
		{
			mbrType = std::shared_ptr< Struct >( new Struct
				{
					this,
					uint32_t( m_members.size() ),
					*type,
				} );
		}

		return doAddMember( mbrType, name );
	}

	Struct::Member Struct::declMember( std::string name
		, TypePtr type )
	{
		return declMember( name
			, getNonArrayKind( type )
			, getArraySize( type ) );
	}

	Struct::Member Struct::declMember( std::string name
		, StructPtr type )
	{
		return declMember( name
			, type
			, getArraySize( type ) );
	}

	Struct::Member Struct::declMember( std::string name
		, ArrayPtr type )
	{
		Struct::Member result;
		auto kind = getNonArrayKind( type );

		if ( kind == type::Kind::eStruct )
		{
			result = declMember( name
				, std::static_pointer_cast< Struct >( type->getType() )
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

	StructPtr Struct::getUnqualifiedType()const
	{
		return StructPtr( new Struct
			{
				nullptr,
				NotMember,
				*this,
			} );
	}

	Struct::Member Struct::doAddMember( type::TypePtr type
		, std::string const & name )
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Member const & lookup )
			{
				return lookup.name == name;
			} );

		if ( it != m_members.end() )
		{
			throw std::runtime_error{ "Struct member [" + name + "] already exists." };
		}

		auto size = getSize( type, m_layout );
		auto offset = m_members.empty()
			? 0u
			: m_members.back().offset + m_members.back().size;

		m_members.push_back(
			{
				std::move( type ),
				std::string( name ),
				offset,
				size,
			} );
		doUpdateOffsets();
		return m_members.back();
	}

	void Struct::doUpdateOffsets()
	{
		uint32_t alignment = getPackedAlignment( *this, getMemoryLayout() );
		uint32_t offset = 0u;

		for ( auto & member : m_members )
		{
			member.offset = offset;
			offset += ( member.size + alignment - 1 ) & ~( alignment - 1 );
		}
	}

	uint32_t getSize( TypePtr type
		, MemoryLayout layout )
	{
		return getSize( *type, layout );
	}

	uint32_t getAlignment( TypePtr type
		, MemoryLayout layout )
	{
		return getAlignment( *type, layout );
	}

	bool operator==( Type const & lhs, Type const & rhs )
	{
		auto result = lhs.getKind() == rhs.getKind()
			&& getArraySize( lhs ) == getArraySize( lhs );

		if ( result )
		{
			result = getSize( lhs, MemoryLayout::eStd430 ) == getSize( rhs, MemoryLayout::eStd430 );
		}

		return result;
	}

	bool operator==( Array const & lhs, Array const & rhs )
	{
		return *lhs.getType() == *rhs.getType()
			&& lhs.getArraySize() == rhs.getArraySize();
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
}
