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

			Kind kind = type.getKind();

			switch ( kind )
			{
			case Kind::eUndefined:
			case Kind::eVoid:
			case Kind::eFunction:
				result = 0;
				break;
			case Kind::eStruct:
				result = getSize( static_cast< Struct const & >( type )
					, layout );
				break;
			case Kind::eBoolean:
				result = 1;
				break;
			case Kind::eInt:
			case Kind::eUInt:
			case Kind::eFloat:
				result = 4;
				break;
			case Kind::eDouble:
				result = 8;
				break;
			case Kind::eVec2B:
				result = 2;
				break;
			case Kind::eVec3B:
				result = 3;
				break;
			case Kind::eVec4B:
				result = 4;
				break;
			case Kind::eVec2I:
			case Kind::eVec2U:
			case Kind::eVec2F:
				result = 8;
				break;
			case Kind::eVec3I:
			case Kind::eVec3U:
			case Kind::eVec3F:
				result = 12;
				break;
			case Kind::eVec4I:
			case Kind::eVec4U:
			case Kind::eVec4F:
			case Kind::eVec2D:
			case Kind::eMat2x2F:
				result = 16;
				break;
			case Kind::eVec3D:
			case Kind::eMat2x3F:
			case Kind::eMat3x2F:
				result = 24;
				break;
			case Kind::eVec4D:
			case Kind::eMat2x4F:
			case Kind::eMat4x2F:
			case Kind::eMat2x2D:
				result = 32;
				break;
			case Kind::eMat3x3F:
				result = 36;
				break;
			case Kind::eMat3x4F:
			case Kind::eMat4x3F:
			case Kind::eMat2x3D:
			case Kind::eMat3x2D:
				result = 48;
				break;
			case Kind::eMat4x4F:
			case Kind::eMat2x4D:
			case Kind::eMat4x2D:
				result = 64;
				break;
			case Kind::eMat3x3D:
				result = 72;
				break;
			case Kind::eMat3x4D:
			case Kind::eMat4x3D:
				result = 96;
				break;
			case Kind::eMat4x4D:
				result = 128;
				break;
			case Kind::eConstantsBuffer:
			case Kind::eShaderBuffer:
			case Kind::eImage:
			case Kind::eSampler:
			case Kind::eSampledImage:
				result = 1u;
				break;
			default:
				assert( false && "Unsizeable Kind" );
				result = 0u;
				break;
			}

			if ( layout == MemoryLayout::eStd140 )
			{
				result = getAlignedSize( result, 16u );
			}

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
			~( 0u ),
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
