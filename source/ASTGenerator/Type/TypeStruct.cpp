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
			uint32_t result = type.getKind() == Kind::eStruct
				? getSize( static_cast< Struct const & >( type ), layout )
				: getSize( type.getKind(), type.getArraySize() != type::NotArray, layout );
			return ( type.getArraySize() != type::NotArray && type.getArraySize() != type::UnknownArraySize )
				? result * type.getArraySize()
				: result;
		}
	}

	Struct::Struct( Struct * parent
		, uint32_t index
		, Struct const & copy
		, uint32_t arraySize )
		: Type{ parent, index, Kind::eStruct, arraySize }
		, m_name{ copy.getName() }
		, m_layout{ copy.m_layout }
	{
		for ( auto & member : copy )
		{
			if ( member.type->getKind() == Kind::eStruct )
			{
				declMember( member.name
					, std::static_pointer_cast< Struct >( member.type )
					, member.type->getArraySize() );
			}
			else
			{
				declMember( member.name
					, member.type->getKind()
					, member.type->getArraySize() );
			}
		}
	}

	Struct::Struct( MemoryLayout layout
		, std::string name
		, uint32_t arraySize )
		: Type{ Kind::eStruct, arraySize }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
	{
	}

	Struct::Member Struct::declMember( std::string name
		, TypePtr type )
	{
		return declMember( name
			, type->getKind()
			, type->getArraySize() );
	}

	Struct::Member Struct::declMember( std::string name
		, Kind kind
		, uint32_t arraySize )
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

		auto type = std::shared_ptr< Type >( new Type
			{
				this,
				uint32_t( m_members.size() ),
				kind,
				arraySize,
			} );
		auto size = type::getSize( type, m_layout );
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
		return m_members.back();
	}

	Struct::Member Struct::declMember( std::string name
		, StructPtr type )
	{
		return declMember( name
			, type
			, type->getArraySize() );
	}

	Struct::Member Struct::declMember( std::string name
		, StructPtr type
		, uint32_t arraySize )
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

		type = std::shared_ptr< Struct >( new Struct
			{
				this,
				uint32_t( m_members.size() ),
				*type,
				arraySize
			} );
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
		return m_members.back();
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
		return StructPtr{ new Struct
		{
			nullptr,
			NotMember,
			*this,
			getArraySize(),
		} };
	}

	uint32_t getSize( TypePtr type
		, MemoryLayout layout )
	{
		return getSize( *type, layout );
	}

	bool operator==( Type const & lhs, Type const & rhs )
	{
		auto result = lhs.getKind() == rhs.getKind()
			&& lhs.getArraySize() == lhs.getArraySize();

		if ( result )
		{
			result = getSize( lhs, MemoryLayout::eStd430 ) == getSize( rhs, MemoryLayout::eStd430 );
		}

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
				&& itl->type->getArraySize() == itr->type->getArraySize();

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
