/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/Type.hpp"

#include "ASTGenerator/Type/ImageConfiguration.hpp"
#include "ASTGenerator/Type/TypeCache.hpp"
#include "ASTGenerator/Type/TypeImage.hpp"
#include "ASTGenerator/Type/TypeSampledImage.hpp"

namespace ast::type
{
	//*************************************************************************

	Type::Type( Struct * parent
		, uint32_t index
		, Kind kind
		, uint32_t arraySize )
		: m_kind{ kind }
		, m_arraySize{ arraySize }
		, m_parent{ parent }
		, m_index{ index }
	{
	}

	Type::Type( Kind kind
		, uint32_t arraySize )
		: Type{ nullptr, ~( 0u ), kind, arraySize }
	{
	}

	Type::~Type()
	{
	}

	//*************************************************************************

	TypePtr getUndefined( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eUndefined };
		return cache.getType( arraySize );
	}

	TypePtr getVoid( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVoid };
		return cache.getType( arraySize );
	}

	TypePtr getFunction( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eFunction };
		return cache.getType( arraySize );
	}

	TypePtr getBool( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eBoolean };
		return cache.getType( arraySize );
	}

	TypePtr getInt( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eInt };
		return cache.getType( arraySize );
	}

	TypePtr getUInt( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eUInt };
		return cache.getType( arraySize );
	}

	TypePtr getFloat( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eFloat };
		return cache.getType( arraySize );
	}

	TypePtr getDouble( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eDouble };
		return cache.getType( arraySize );
	}

	TypePtr getVec2Type( Kind kind, uint32_t arraySize )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec2B( arraySize );
		case Kind::eInt:
			return getVec2I( arraySize );
		case Kind::eUInt:
			return getVec2U( arraySize );
		case Kind::eFloat:
			return getVec2F( arraySize );
		case Kind::eDouble:
			return getVec2D( arraySize );
		default:
			assert( false && "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr getVec3Type( Kind kind, uint32_t arraySize )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec3B( arraySize );
		case Kind::eInt:
			return getVec3I( arraySize );
		case Kind::eUInt:
			return getVec3U( arraySize );
		case Kind::eFloat:
			return getVec3F( arraySize );
		case Kind::eDouble:
			return getVec3D( arraySize );
		default:
			assert( false && "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr getVec4Type( Kind kind, uint32_t arraySize )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec4B( arraySize );
		case Kind::eInt:
			return getVec4I( arraySize );
		case Kind::eUInt:
			return getVec4U( arraySize );
		case Kind::eFloat:
			return getVec4F( arraySize );
		case Kind::eDouble:
			return getVec4D( arraySize );
		default:
			assert( false && "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr getVec2B( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec2B };
		return cache.getType( arraySize );
	}

	TypePtr getVec3B( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec3B };
		return cache.getType( arraySize );
	}

	TypePtr getVec4B( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec4B };
		return cache.getType( arraySize );
	}

	TypePtr getVec2I( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec2I };
		return cache.getType( arraySize );
	}

	TypePtr getVec3I( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec3I };
		return cache.getType( arraySize );
	}

	TypePtr getVec4I( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec4I };
		return cache.getType( arraySize );
	}

	TypePtr getVec2U( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec2U };
		return cache.getType( arraySize );
	}

	TypePtr getVec3U( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec3U };
		return cache.getType( arraySize );
	}

	TypePtr getVec4U( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec4U };
		return cache.getType( arraySize );
	}

	TypePtr getVec2F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec2F };
		return cache.getType( arraySize );
	}

	TypePtr getVec3F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec3F };
		return cache.getType( arraySize );
	}

	TypePtr getVec4F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec4F };
		return cache.getType( arraySize );
	}

	TypePtr getVec2D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec2D };
		return cache.getType( arraySize );
	}

	TypePtr getVec3D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec3D };
		return cache.getType( arraySize );
	}

	TypePtr getVec4D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eVec4D };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x2F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat2x2F };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x3F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat2x3F };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x4F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat2x4F };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x2F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat3x2F };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x3F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat3x3F };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x4F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat3x4F };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x2F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat4x2F };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x3F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat4x3F };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x4F( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat4x4F };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x2D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat2x2D };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x3D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat2x3D };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x4D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat2x4D };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x2D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat3x2D };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x3D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat3x3D };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x4D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat3x4D };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x2D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat4x2D };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x3D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat4x3D };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x4D( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eMat4x4D };
		return cache.getType( arraySize );
	}

	TypePtr getConstantsBuffer( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eConstantsBuffer };
		return cache.getType( arraySize );
	}

	TypePtr getShaderBuffer( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eShaderBuffer };
		return cache.getType( arraySize );
	}

	TypePtr getSampler( uint32_t arraySize )
	{
		static TypeCache<> cache{ Kind::eSampler };
		return cache.getType( arraySize );
	}

	TypePtr getImage( ImageConfiguration config
		, uint32_t arraySize )
	{
		static auto cache{ makeTypeCache< Image >( makeImageType ) };
		return cache.getType( arraySize, config );
	}

	TypePtr getSampledImage( ImageConfiguration config
		, uint32_t arraySize )
	{
		static auto cache{ makeTypeCache< SampledImage >( makeSampledImageType ) };
		return cache.getType( arraySize, config );
	}

	//*************************************************************************

	TypePtr makeType( Kind kind, uint32_t arraySize )
	{
		assert( kind != Kind::eImage
			&& kind != Kind::eSampledImage );

		switch ( kind )
		{
		case Kind::eUndefined:
			return getUndefined( arraySize );
		case Kind::eVoid:
			return getVoid( arraySize );
		case Kind::eFunction:
			return getFunction( arraySize );
		case Kind::eBoolean:
			return getBool( arraySize );
		case Kind::eInt:
			return getInt( arraySize );
		case Kind::eUInt:
			return getUInt( arraySize );
		case Kind::eFloat:
			return getFloat( arraySize );
		case Kind::eDouble:
			return getDouble( arraySize );
		case Kind::eVec2B:
			return getVec2B( arraySize );
		case Kind::eVec3B:
			return getVec3B( arraySize );
		case Kind::eVec4B:
			return getVec4B( arraySize );
		case Kind::eVec2I:
			return getVec2I( arraySize );
		case Kind::eVec3I:
			return getVec3I( arraySize );
		case Kind::eVec4I:
			return getVec4I( arraySize );
		case Kind::eVec2U:
			return getVec2U( arraySize );
		case Kind::eVec3U:
			return getVec3U( arraySize );
		case Kind::eVec4U:
			return getVec4U( arraySize );
		case Kind::eVec2F:
			return getVec2F( arraySize );
		case Kind::eVec3F:
			return getVec3F( arraySize );
		case Kind::eVec4F:
			return getVec4F( arraySize );
		case Kind::eVec2D:
			return getVec2D( arraySize );
		case Kind::eVec3D:
			return getVec3D( arraySize );
		case Kind::eVec4D:
			return getVec4D( arraySize );
		case Kind::eMat2x2F:
			return getMat2x2F( arraySize );
		case Kind::eMat2x3F:
			return getMat2x3F( arraySize );
		case Kind::eMat2x4F:
			return getMat2x4F( arraySize );
		case Kind::eMat3x2F:
			return getMat3x2F( arraySize );
		case Kind::eMat3x3F:
			return getMat3x3F( arraySize );
		case Kind::eMat3x4F:
			return getMat3x4F( arraySize );
		case Kind::eMat4x2F:
			return getMat4x2F( arraySize );
		case Kind::eMat4x3F:
			return getMat4x3F( arraySize );
		case Kind::eMat4x4F:
			return getMat4x4F( arraySize );
		case Kind::eMat2x2D:
			return getMat2x2D( arraySize );
		case Kind::eMat2x3D:
			return getMat2x3D( arraySize );
		case Kind::eMat2x4D:
			return getMat2x4D( arraySize );
		case Kind::eMat3x2D:
			return getMat3x2D( arraySize );
		case Kind::eMat3x3D:
			return getMat3x3D( arraySize );
		case Kind::eMat3x4D:
			return getMat3x4D( arraySize );
		case Kind::eMat4x2D:
			return getMat4x2D( arraySize );
		case Kind::eMat4x3D:
			return getMat4x3D( arraySize );
		case Kind::eMat4x4D:
			return getMat4x4D( arraySize );
		case Kind::eConstantsBuffer:
			return getConstantsBuffer( arraySize );
		case Kind::eShaderBuffer:
			return getShaderBuffer( arraySize );
		case Kind::eSampler:
			return getSampler( arraySize );
		default:
			assert( false && "Unexpected Kind" );
			return nullptr;
		}
	}

	//*************************************************************************

	bool isScalarType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
		case Kind::eInt:
		case Kind::eUInt:
		case Kind::eFloat:
		case Kind::eDouble:
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
		assert( isMatrixType( kind )
			|| isVectorType( kind ) );

		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
			return Kind::eBoolean;

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

		default:
			assert( "Unsupported type::Kind" );
			return Kind::eUndefined;
		}
	}

	//*************************************************************************
}
