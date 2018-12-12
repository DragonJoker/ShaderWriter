/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/Type.hpp"

#include "ShaderAST/Type/ImageConfiguration.hpp"
#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

#include <algorithm>

namespace ast::type
{
	//*************************************************************************

	Type::Type( Kind kind )
		: Type{ nullptr, NotMember, kind }
	{
	}

	Type::Type( Struct * parent
		, uint32_t index
		, Kind kind )
		: m_kind{ kind }
		, m_parent{ parent }
		, m_index{ index }
	{
	}

	Type::Type( Struct & parent
		, uint32_t index
		, Kind kind )
		: Type{ &parent, index, kind }
	{
	}

	Type::~Type()
	{
	}

	TypePtr Type::getMemberType( Struct & parent, uint32_t index )const
	{
		return std::make_shared< Type >( parent, index, getKind() );
	}

	//*************************************************************************

	bool operator==( Type const & lhs, Type const & rhs )
	{
		auto result = lhs.getKind() == rhs.getKind()
			&& getArraySize( lhs ) == getArraySize( rhs );

		if ( result )
		{
			result = getSize( lhs, MemoryLayout::eStd430 ) == getSize( rhs, MemoryLayout::eStd430 );
		}

		return result;
	}

	//*************************************************************************

	bool isBoolType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBool:
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
			return true;

		default:
			return false;
		}
	}

	bool isUnsignedIntType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eUInt:
		case Kind::eVec2U:
		case Kind::eVec3U:
		case Kind::eVec4U:
			return true;

		default:
			return false;
		}
	}

	bool isSignedIntType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eInt:
		case Kind::eVec2I:
		case Kind::eVec3I:
		case Kind::eVec4I:
			return true;

		default:
			return false;
		}
	}

	bool isHalfType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eHalf:
		case Kind::eVec2H:
		case Kind::eVec3H:
		case Kind::eVec4H:
			return true;

		default:
			return false;
		}
	}

	bool isFloatType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eFloat:
		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
		case Kind::eMat2x2F:
		case Kind::eMat2x3F:
		case Kind::eMat2x4F:
		case Kind::eMat3x2F:
		case Kind::eMat3x3F:
		case Kind::eMat3x4F:
		case Kind::eMat4x2F:
		case Kind::eMat4x3F:
		case Kind::eMat4x4F:
			return true;

		default:
			return false;
		}
	}

	bool isDoubleType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eDouble:
		case Kind::eVec2D:
		case Kind::eVec3D:
		case Kind::eVec4D:
		case Kind::eMat2x2D:
		case Kind::eMat2x3D:
		case Kind::eMat2x4D:
		case Kind::eMat3x2D:
		case Kind::eMat3x3D:
		case Kind::eMat3x4D:
		case Kind::eMat4x2D:
		case Kind::eMat4x3D:
		case Kind::eMat4x4D:
			return true;

		default:
			return false;
		}
	}

	bool isScalarType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBool:
		case Kind::eInt:
		case Kind::eUInt:
		case Kind::eFloat:
		case Kind::eDouble:
		case Kind::eHalf:
			return true;

		default:
			return false;
		}
	}

	bool isVectorType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
		case Kind::eVec2I:
		case Kind::eVec3I:
		case Kind::eVec4I:
		case Kind::eVec2U:
		case Kind::eVec3U:
		case Kind::eVec4U:
		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
		case Kind::eVec2D:
		case Kind::eVec3D:
		case Kind::eVec4D:
		case Kind::eVec2H:
		case Kind::eVec3H:
		case Kind::eVec4H:
			return true;

		default:
			return false;
		}
	}

	bool isMatrixType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eMat2x2F:
		case Kind::eMat2x3F:
		case Kind::eMat2x4F:
		case Kind::eMat3x2F:
		case Kind::eMat3x3F:
		case Kind::eMat3x4F:
		case Kind::eMat4x2F:
		case Kind::eMat4x3F:
		case Kind::eMat4x4F:
		case Kind::eMat2x2D:
		case Kind::eMat2x3D:
		case Kind::eMat2x4D:
		case Kind::eMat3x2D:
		case Kind::eMat3x3D:
		case Kind::eMat3x4D:
		case Kind::eMat4x2D:
		case Kind::eMat4x3D:
		case Kind::eMat4x4D:
			return true;

		default:
			return false;
		}
	}

	bool isArrayType( Kind kind )
	{
		return kind == Kind::eArray;
	}

	bool isStructType( Kind kind )
	{
		return kind == Kind::eStruct;
	}

	bool isSamplerType( Kind kind )
	{
		return kind == Kind::eSampler;
	}

	bool isImageType( Kind kind )
	{
		return kind == Kind::eImage;
	}

	bool isSampledImageType( Kind kind )
	{
		return kind == Kind::eSampledImage;
	}

	uint32_t getComponentCount( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec2I:
		case Kind::eVec2U:
		case Kind::eVec2F:
		case Kind::eVec2D:
		case Kind::eVec2H:
		case Kind::eMat2x2F:
		case Kind::eMat2x3F:
		case Kind::eMat2x4F:
		case Kind::eMat2x2D:
		case Kind::eMat2x3D:
		case Kind::eMat2x4D:
			return 2u;

		case Kind::eVec3B:
		case Kind::eVec3I:
		case Kind::eVec3U:
		case Kind::eVec3F:
		case Kind::eVec3D:
		case Kind::eVec3H:
		case Kind::eMat3x2F:
		case Kind::eMat3x3F:
		case Kind::eMat3x4F:
		case Kind::eMat3x2D:
		case Kind::eMat3x3D:
		case Kind::eMat3x4D:
			return 3u;

		case Kind::eVec4B:
		case Kind::eVec4I:
		case Kind::eVec4U:
		case Kind::eVec4F:
		case Kind::eVec4D:
		case Kind::eVec4H:
		case Kind::eMat4x2F:
		case Kind::eMat4x3F:
		case Kind::eMat4x4F:
		case Kind::eMat4x2D:
		case Kind::eMat4x3D:
		case Kind::eMat4x4D:
			return 4u;

		default:
			return 1u;
		}
	}

	Kind getComponentType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
			return Kind::eBool;

		case Kind::eVec2I:
		case Kind::eVec3I:
		case Kind::eVec4I:
			return Kind::eInt;

		case Kind::eVec2U:
		case Kind::eVec3U:
		case Kind::eVec4U:
			return Kind::eUInt;

		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
			return Kind::eFloat;

		case Kind::eMat2x2F:
		case Kind::eMat3x2F:
		case Kind::eMat4x2F:
			return Kind::eVec2F;

		case Kind::eMat2x3F:
		case Kind::eMat3x3F:
		case Kind::eMat4x3F:
			return Kind::eVec3F;

		case Kind::eMat2x4F:
		case Kind::eMat3x4F:
		case Kind::eMat4x4F:
			return Kind::eVec4F;

		case Kind::eVec2D:
		case Kind::eVec3D:
		case Kind::eVec4D:
			return Kind::eDouble;

		case Kind::eMat2x2D:
		case Kind::eMat3x2D:
		case Kind::eMat4x2D:
			return Kind::eVec2D;

		case Kind::eMat2x3D:
		case Kind::eMat3x3D:
		case Kind::eMat4x3D:
			return Kind::eVec3D;

		case Kind::eMat2x4D:
		case Kind::eMat3x4D:
		case Kind::eMat4x4D:
			return Kind::eVec4D;

		case Kind::eVec2H:
		case Kind::eVec3H:
		case Kind::eVec4H:
			return Kind::eHalf;

		default:
			return kind;
		}
	}

	Kind getScalarType( Kind kind )
	{
		if ( isScalarType( kind ) )
		{
			return kind;
		}

		auto parent = getComponentType( kind );

		if ( isVectorType( kind ) )
		{
			return parent;
		}

		return getComponentType( parent );
	}

	expr::CompositeType getCompositeType( Kind kind )
	{
		assert( isVectorType( kind )
			|| isMatrixType( kind ) );

		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec2I:
		case Kind::eVec2U:
		case Kind::eVec2F:
		case Kind::eVec2D:
		case Kind::eVec2H:
			return expr::CompositeType::eVec2;

		case Kind::eVec3B:
		case Kind::eVec3I:
		case Kind::eVec3U:
		case Kind::eVec3F:
		case Kind::eVec3D:
		case Kind::eVec3H:
			return expr::CompositeType::eVec3;

		case Kind::eVec4B:
		case Kind::eVec4I:
		case Kind::eVec4U:
		case Kind::eVec4F:
		case Kind::eVec4D:
		case Kind::eVec4H:
			return expr::CompositeType::eVec4;

		case Kind::eMat2x2F:
		case Kind::eMat2x2D:
			return expr::CompositeType::eMat2x2;

		case Kind::eMat2x3F:
		case Kind::eMat2x3D:
			return expr::CompositeType::eMat2x3;

		case Kind::eMat2x4F:
		case Kind::eMat2x4D:
			return expr::CompositeType::eMat2x4;

		case Kind::eMat3x2F:
		case Kind::eMat3x2D:
			return expr::CompositeType::eMat3x2;

		case Kind::eMat3x3F:
		case Kind::eMat3x3D:
			return expr::CompositeType::eMat3x3;

		case Kind::eMat3x4F:
		case Kind::eMat3x4D:
			return expr::CompositeType::eMat3x4;

		case Kind::eMat4x2F:
		case Kind::eMat4x2D:
			return expr::CompositeType::eMat4x2;

		case Kind::eMat4x3F:
		case Kind::eMat4x3D:
			return expr::CompositeType::eMat4x3;

		case Kind::eMat4x4F:
		case Kind::eMat4x4D:
			return expr::CompositeType::eMat4x4;

		default:
			assert( "Unsupported type::Kind" );
			return expr::CompositeType::eVec4;
		}
	}

	Kind getNonArrayKindRec( Type const & type )
	{
		auto result = type.getKind();
		auto * tmp = &type;

		while ( tmp->getKind() == type::Kind::eArray )
		{
			tmp = static_cast< Array const & >( *tmp ).getType().get();
		}

		return tmp->getKind();
	}

	Kind getNonArrayKindRec( TypePtr type )
	{
		return getNonArrayKindRec( *type );
	}

	Kind getNonArrayKind( Type const & type )
	{
		return type.getKind() == type::Kind::eArray
			? static_cast< Array const & >( type ).getType()->getKind()
			: type.getKind();
	}

	Kind getNonArrayKind( TypePtr type )
	{
		return getNonArrayKind( *type );
	}

	uint32_t getArraySize( Type const & type )
	{
		return type.getKind() == type::Kind::eArray
			? static_cast< type::Array const & >( type ).getArraySize()
			: NotArray;
	}

	uint32_t getArraySize( TypePtr type )
	{
		return getArraySize( *type );
	}

	//*************************************************************************
}
