/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/Type.hpp"

namespace ast::type
{
	//*************************************************************************

	class TypeCache
	{
	public:
		TypeCache( Kind kind )
			: m_kind{ kind }
		{
		}

		TypePtr getType( uint32_t arraySize )
		{
			auto it = m_cache.find( arraySize );

			if ( it == m_cache.end() )
			{
				it = m_cache.emplace( arraySize, std::shared_ptr< Type >( new Type{ m_kind, arraySize } ) ).first;
			}

			return it->second;
		}

	private:
		Kind m_kind;
		std::map< uint32_t, TypePtr > m_cache;
	};

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
		static TypeCache cache{ Kind::eUndefined };
		return cache.getType( arraySize );
	}

	TypePtr getVoid( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVoid };
		return cache.getType( arraySize );
	}

	TypePtr getFunction( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eFunction };
		return cache.getType( arraySize );
	}

	TypePtr getBool( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eBoolean };
		return cache.getType( arraySize );
	}

	TypePtr getInt( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eInt };
		return cache.getType( arraySize );
	}

	TypePtr getUInt( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eUInt };
		return cache.getType( arraySize );
	}

	TypePtr getFloat( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eFloat };
		return cache.getType( arraySize );
	}

	TypePtr getDouble( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eDouble };
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
		static TypeCache cache{ Kind::eVec2B };
		return cache.getType( arraySize );
	}

	TypePtr getVec3B( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec3B };
		return cache.getType( arraySize );
	}

	TypePtr getVec4B( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec4B };
		return cache.getType( arraySize );
	}

	TypePtr getVec2I( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec2I };
		return cache.getType( arraySize );
	}

	TypePtr getVec3I( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec3I };
		return cache.getType( arraySize );
	}

	TypePtr getVec4I( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec4I };
		return cache.getType( arraySize );
	}

	TypePtr getVec2U( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec2U };
		return cache.getType( arraySize );
	}

	TypePtr getVec3U( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec3U };
		return cache.getType( arraySize );
	}

	TypePtr getVec4U( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec4U };
		return cache.getType( arraySize );
	}

	TypePtr getVec2F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec2F };
		return cache.getType( arraySize );
	}

	TypePtr getVec3F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec3F };
		return cache.getType( arraySize );
	}

	TypePtr getVec4F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec4F };
		return cache.getType( arraySize );
	}

	TypePtr getVec2D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec2D };
		return cache.getType( arraySize );
	}

	TypePtr getVec3D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec3D };
		return cache.getType( arraySize );
	}

	TypePtr getVec4D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eVec4D };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x2F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat2x2F };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x3F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat2x3F };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x4F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat2x4F };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x2F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat3x2F };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x3F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat3x3F };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x4F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat3x4F };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x2F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat4x2F };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x3F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat4x3F };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x4F( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat4x4F };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x2D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat2x2D };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x3D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat2x3D };
		return cache.getType( arraySize );
	}

	TypePtr getMat2x4D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat2x4D };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x2D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat3x2D };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x3D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat3x3D };
		return cache.getType( arraySize );
	}

	TypePtr getMat3x4D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat3x4D };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x2D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat4x2D };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x3D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat4x3D };
		return cache.getType( arraySize );
	}

	TypePtr getMat4x4D( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eMat4x4D };
		return cache.getType( arraySize );
	}

	TypePtr getConstantsBuffer( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eConstantsBuffer };
		return cache.getType( arraySize );
	}

	TypePtr getShaderBuffer( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eShaderBuffer };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerBufferF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerBufferF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler3DF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler3DF };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DRectF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DRectF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DArrayF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DArrayF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DArrayF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DArrayF };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeArrayF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeArrayF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DShadowF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DShadowF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DShadowF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DShadowF };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeShadowF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeShadowF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DRectShadowF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DRectShadowF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DArrayShadowF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DArrayShadowF };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DArrayShadowF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DArrayShadowF };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeArrayShadowF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeArrayShadowF };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerBufferI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerBufferI };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DI };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DI };
		return cache.getType( arraySize );
	}

	TypePtr getSampler3DI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler3DI };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeI };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DRectI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DRectI };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DArrayI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DArrayI };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DArrayI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DArrayI };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeArrayI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeArrayI };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerBufferU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerBufferU };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DU };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DU };
		return cache.getType( arraySize );
	}

	TypePtr getSampler3DU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler3DU };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeU };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DRectU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DRectU };
		return cache.getType( arraySize );
	}

	TypePtr getSampler1DArrayU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler1DArrayU };
		return cache.getType( arraySize );
	}

	TypePtr getSampler2DArrayU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSampler2DArrayU };
		return cache.getType( arraySize );
	}

	TypePtr getSamplerCubeArrayU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eSamplerCubeArrayU };
		return cache.getType( arraySize );
	}

	TypePtr getImageBufferF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageBufferF };
		return cache.getType( arraySize );
	}

	TypePtr getImage1DF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage1DF };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DF };
		return cache.getType( arraySize );
	}

	TypePtr getImage3DF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage3DF };
		return cache.getType( arraySize );
	}

	TypePtr getImageCubeF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageCubeF };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DRectF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DRectF };
		return cache.getType( arraySize );
	}

	TypePtr getImage1DArrayF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage1DArrayF };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DArrayF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DArrayF };
		return cache.getType( arraySize );
	}

	TypePtr getImageCubeArrayF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageCubeArrayF };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DMSF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DMSF };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DMSArrayF( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DMSArrayF };
		return cache.getType( arraySize );
	}

	TypePtr getImageBufferI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageBufferI };
		return cache.getType( arraySize );
	}

	TypePtr getImage1DI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage1DI };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DI };
		return cache.getType( arraySize );
	}

	TypePtr getImage3DI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage3DI };
		return cache.getType( arraySize );
	}

	TypePtr getImageCubeI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageCubeI };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DRectI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DRectI };
		return cache.getType( arraySize );
	}

	TypePtr getImage1DArrayI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage1DArrayI };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DArrayI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DArrayI };
		return cache.getType( arraySize );
	}

	TypePtr getImageCubeArrayI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageCubeArrayI };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DMSI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DMSI };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DMSArrayI( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DMSArrayI };
		return cache.getType( arraySize );
	}

	TypePtr getImageBufferU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageBufferU };
		return cache.getType( arraySize );
	}

	TypePtr getImage1DU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage1DU };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DU };
		return cache.getType( arraySize );
	}

	TypePtr getImage3DU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage3DU };
		return cache.getType( arraySize );
	}

	TypePtr getImageCubeU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageCubeU };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DRectU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DRectU };
		return cache.getType( arraySize );
	}

	TypePtr getImage1DArrayU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage1DArrayU };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DArrayU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DArrayU };
		return cache.getType( arraySize );
	}

	TypePtr getImageCubeArrayU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImageCubeArrayU };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DMSU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DMSU };
		return cache.getType( arraySize );
	}

	TypePtr getImage2DMSArrayU( uint32_t arraySize )
	{
		static TypeCache cache{ Kind::eImage2DMSArrayU };
		return cache.getType( arraySize );
	}

	//*************************************************************************

	TypePtr makeType( Kind kind, uint32_t arraySize )
	{
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
		case Kind::eSamplerBufferF:
			return getSamplerBufferF( arraySize );
		case Kind::eSampler1DF:
			return getSampler1DF( arraySize );
		case Kind::eSampler2DF:
			return getSampler2DF( arraySize );
		case Kind::eSampler3DF:
			return getSampler3DF( arraySize );
		case Kind::eSamplerCubeF:
			return getSamplerCubeF( arraySize );
		case Kind::eSampler2DRectF:
			return getSampler2DRectF( arraySize );
		case Kind::eSampler1DArrayF:
			return getSampler1DArrayF( arraySize );
		case Kind::eSampler2DArrayF:
			return getSampler2DArrayF( arraySize );
		case Kind::eSamplerCubeArrayF:
			return getSamplerCubeArrayF( arraySize );
		case Kind::eSampler1DShadowF:
			return getSampler1DShadowF( arraySize );
		case Kind::eSampler2DShadowF:
			return getSampler2DShadowF( arraySize );
		case Kind::eSamplerCubeShadowF:
			return getSamplerCubeShadowF( arraySize );
		case Kind::eSampler2DRectShadowF:
			return getSampler2DRectShadowF( arraySize );
		case Kind::eSampler1DArrayShadowF:
			return getSampler1DArrayShadowF( arraySize );
		case Kind::eSampler2DArrayShadowF:
			return getSampler2DArrayShadowF( arraySize );
		case Kind::eSamplerCubeArrayShadowF:
			return getSamplerCubeArrayShadowF( arraySize );
		case Kind::eSamplerBufferI:
			return getSamplerBufferI( arraySize );
		case Kind::eSampler1DI:
			return getSampler1DI( arraySize );
		case Kind::eSampler2DI:
			return getSampler2DI( arraySize );
		case Kind::eSampler3DI:
			return getSampler3DI( arraySize );
		case Kind::eSamplerCubeI:
			return getSamplerCubeI( arraySize );
		case Kind::eSampler2DRectI:
			return getSampler2DRectI( arraySize );
		case Kind::eSampler1DArrayI:
			return getSampler1DArrayI( arraySize );
		case Kind::eSampler2DArrayI:
			return getSampler2DArrayI( arraySize );
		case Kind::eSamplerCubeArrayI:
			return getSamplerCubeArrayI( arraySize );
		case Kind::eSamplerBufferU:
			return getSamplerBufferU( arraySize );
		case Kind::eSampler1DU:
			return getSampler1DU( arraySize );
		case Kind::eSampler2DU:
			return getSampler2DU( arraySize );
		case Kind::eSampler3DU:
			return getSampler3DU( arraySize );
		case Kind::eSamplerCubeU:
			return getSamplerCubeU( arraySize );
		case Kind::eSampler2DRectU:
			return getSampler2DRectU( arraySize );
		case Kind::eSampler1DArrayU:
			return getSampler1DArrayU( arraySize );
		case Kind::eSampler2DArrayU:
			return getSampler2DArrayU( arraySize );
		case Kind::eSamplerCubeArrayU:
			return getSamplerCubeArrayU( arraySize );
		case Kind::eImageBufferF:
			return getImageBufferF( arraySize );
		case Kind::eImage1DF:
			return getImage1DF( arraySize );
		case Kind::eImage2DF:
			return getImage2DF( arraySize );
		case Kind::eImage3DF:
			return getImage3DF( arraySize );
		case Kind::eImageCubeF:
			return getImageCubeF( arraySize );
		case Kind::eImage2DRectF:
			return getImage2DRectF( arraySize );
		case Kind::eImage1DArrayF:
			return getImage1DArrayF( arraySize );
		case Kind::eImage2DArrayF:
			return getImage2DArrayF( arraySize );
		case Kind::eImageCubeArrayF:
			return getImageCubeArrayF( arraySize );
		case Kind::eImage2DMSF:
			return getImage2DMSF( arraySize );
		case Kind::eImage2DMSArrayF:
			return getImage2DMSArrayF( arraySize );
		case Kind::eImageBufferI:
			return getImageBufferI( arraySize );
		case Kind::eImage1DI:
			return getImage1DI( arraySize );
		case Kind::eImage2DI:
			return getImage2DI( arraySize );
		case Kind::eImage3DI:
			return getImage3DI( arraySize );
		case Kind::eImageCubeI:
			return getImageCubeI( arraySize );
		case Kind::eImage2DRectI:
			return getImage2DRectI( arraySize );
		case Kind::eImage1DArrayI:
			return getImage1DArrayI( arraySize );
		case Kind::eImage2DArrayI:
			return getImage2DArrayI( arraySize );
		case Kind::eImageCubeArrayI:
			return getImageCubeArrayI( arraySize );
		case Kind::eImage2DMSI:
			return getImage2DMSI( arraySize );
		case Kind::eImage2DMSArrayI:
			return getImage2DMSArrayI( arraySize );
		case Kind::eImageBufferU:
			return getImageBufferU( arraySize );
		case Kind::eImage1DU:
			return getImage1DU( arraySize );
		case Kind::eImage2DU:
			return getImage2DU( arraySize );
		case Kind::eImage3DU:
			return getImage3DU( arraySize );
		case Kind::eImageCubeU:
			return getImageCubeU( arraySize );
		case Kind::eImage2DRectU:
			return getImage2DRectU( arraySize );
		case Kind::eImage1DArrayU:
			return getImage1DArrayU( arraySize );
		case Kind::eImage2DArrayU:
			return getImage2DArrayU( arraySize );
		case Kind::eImageCubeArrayU:
			return getImageCubeArrayU( arraySize );
		case Kind::eImage2DMSU:
			return getImage2DMSU( arraySize );
		case Kind::eImage2DMSArrayU:
			return getImage2DMSArrayU( arraySize );
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
		switch ( kind )
		{
		case Kind::eSamplerBufferF:
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
		case Kind::eSamplerBufferI:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler2DRectI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eSamplerBufferU:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler2DRectU:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
		case Kind::eCount:
			return true;

		default:
			return false;
		}
	}

	bool isImageType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
		case Kind::eCount:
			return true;

		default:
			return false;
		}
	}

	ImageDim getDimension( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eSampler1DF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler1DShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler1DI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler1DU:
		case Kind::eSampler1DArrayU:
		case Kind::eImage1DF:
		case Kind::eImage1DArrayF:
		case Kind::eImage1DI:
		case Kind::eImage1DArrayI:
		case Kind::eImage1DU:
		case Kind::eImage1DArrayU:
			return ImageDim::e1D;

		case Kind::eSampler2DF:
		case Kind::eSampler2DArrayF:
		case Kind::eSampler2DShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSampler2DI:
		case Kind::eSampler2DArrayI:
		case Kind::eSampler2DU:
		case Kind::eSampler2DArrayU:
		case Kind::eImage2DF:
		case Kind::eImage2DArrayF:
		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
		case Kind::eImage2DI:
		case Kind::eImage2DArrayI:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
		case Kind::eImage2DU:
		case Kind::eImage2DArrayU:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
			return ImageDim::e2D;

		case Kind::eSamplerCubeF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSamplerCubeArrayShadowF:
		case Kind::eSamplerCubeI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eSamplerCubeU:
		case Kind::eSamplerCubeArrayU:
		case Kind::eImageCubeF:
		case Kind::eImageCubeArrayF:
		case Kind::eImageCubeI:
		case Kind::eImageCubeArrayI:
		case Kind::eImageCubeU:
		case Kind::eImageCubeArrayU:
			return ImageDim::eCube;

		case Kind::eSampler2DRectF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSampler2DRectI:
		case Kind::eSampler2DRectU:
		case Kind::eImage2DRectF:
		case Kind::eImage2DRectI:
		case Kind::eImage2DRectU:
			return ImageDim::eRect;

		case Kind::eSampler3DF:
		case Kind::eSampler3DI:
		case Kind::eSampler3DU:
		case Kind::eImage3DF:
		case Kind::eImage3DI:
		case Kind::eImage3DU:
			return ImageDim::e3D;

		case Kind::eSamplerBufferF:
		case Kind::eSamplerBufferI:
		case Kind::eSamplerBufferU:
			return ImageDim::eBuffer;

		default:
			assert( "Unsupported type::Kind" );
			return ImageDim::e2D;
		}
	}

	Ternary getDepth( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eSamplerBufferF:
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSamplerBufferI:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler2DRectI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eSamplerBufferU:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler2DRectU:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
			return Ternary::eFalse;

		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
			return Ternary::eTrue;

		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
			return Ternary::eDontCare;

		default:
			assert( "Unsupported type::Kind" );
			return Ternary::eDontCare;
		}
	}

	Ternary getSampled( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
			return Ternary::eTrue;

		case Kind::eSamplerBufferF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSamplerBufferI:
		case Kind::eSampler2DRectI:
		case Kind::eSamplerBufferU:
		case Kind::eSampler2DRectU:
		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
			return Ternary::eFalse;

		default:
			assert( "Unsupported type::Kind" );
			return Ternary::eDontCare;
		}
	}

	bool getArrayed( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage2DMSArrayF:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage2DMSArrayI:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
		case Kind::eImage2DMSArrayU:
			return true;

		case Kind::eSamplerBufferF:
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSamplerBufferI:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler2DRectI:
		case Kind::eSamplerBufferU:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler2DRectU:
		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage2DMSF:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage2DMSI:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage2DMSU:
		case Kind::eCount:
			return false;

		default:
			assert( "Unsupported type::Kind" );
			return false;
		}
	}

	bool getMS( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eSamplerBufferF:
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
		case Kind::eSamplerBufferI:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler2DRectI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eSamplerBufferU:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler2DRectU:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
			return false;

		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
			return true;

		default:
			assert( "Unsupported type::Kind" );
			return false;
		}
	}

	Kind getVectorType( Kind kind )
	{
		assert( isSamplerType( kind )
			|| isImageType( kind ) );

		switch ( kind )
		{
		case Kind::eSamplerBufferF:
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
			return Kind::eVec4F;

		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
			return Kind::eFloat;

		case Kind::eSamplerBufferI:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler2DRectI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
			return Kind::eVec4I;

		case Kind::eSamplerBufferU:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler2DRectU:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
			return Kind::eVec4U;

		default:
			assert( "Unsupported type::Kind" );
			return Kind::eVec4F;
		}
	}

	AccessKind getAccessType( Kind kind )
	{
		assert( isSamplerType( kind )
			|| isImageType( kind ) );

		switch ( kind )
		{
		case Kind::eSamplerBufferF:
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
		case Kind::eSamplerBufferI:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler2DRectI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eSamplerBufferU:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler2DRectU:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
			return AccessKind::eRead;

		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
			return AccessKind::eReadWrite;

		default:
			assert( "Unsupported type::Kind" );
			return AccessKind::eRead;
		}
	}

	ImageConfig getImageConfig( Kind kind )
	{
		auto type = getVectorType( kind );
		return
		{
			getDimension( kind ),
			getDepth( kind ),
			getSampled( kind ),
			getArrayed( kind ),
			getMS( kind ),
			( isVectorType( type )
				? getComponentCount( type )
				: 1u ),
			( isVectorType( type )
				? getComponentType( type )
				: type ),
			getAccessType( kind ),
		};
	}

	uint32_t getComponentCount( Kind kind )
	{
		assert( isMatrixType( kind )
			|| isVectorType( kind ) );

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
			|| isVectorType( kind )
			|| isSamplerType( kind )
			|| isImageType( kind ) );

		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
			return Kind::eBoolean;

		case Kind::eVec2I:
		case Kind::eVec3I:
		case Kind::eVec4I:
		case Kind::eSamplerBufferI:
		case Kind::eSampler1DI:
		case Kind::eSampler2DI:
		case Kind::eSampler3DI:
		case Kind::eSamplerCubeI:
		case Kind::eSampler2DRectI:
		case Kind::eSampler1DArrayI:
		case Kind::eSampler2DArrayI:
		case Kind::eSamplerCubeArrayI:
		case Kind::eImage1DI:
		case Kind::eImage2DI:
		case Kind::eImage3DI:
		case Kind::eImageCubeI:
		case Kind::eImage2DRectI:
		case Kind::eImage1DArrayI:
		case Kind::eImage2DArrayI:
		case Kind::eImageCubeArrayI:
		case Kind::eImage2DMSI:
		case Kind::eImage2DMSArrayI:
			return Kind::eInt;

		case Kind::eVec2U:
		case Kind::eVec3U:
		case Kind::eVec4U:
		case Kind::eSamplerBufferU:
		case Kind::eSampler1DU:
		case Kind::eSampler2DU:
		case Kind::eSampler3DU:
		case Kind::eSamplerCubeU:
		case Kind::eSampler2DRectU:
		case Kind::eSampler1DArrayU:
		case Kind::eSampler2DArrayU:
		case Kind::eSamplerCubeArrayU:
		case Kind::eImage1DU:
		case Kind::eImage2DU:
		case Kind::eImage3DU:
		case Kind::eImageCubeU:
		case Kind::eImage2DRectU:
		case Kind::eImage1DArrayU:
		case Kind::eImage2DArrayU:
		case Kind::eImageCubeArrayU:
		case Kind::eImage2DMSU:
		case Kind::eImage2DMSArrayU:
			return Kind::eUInt;

		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
		case Kind::eSamplerBufferF:
		case Kind::eSampler1DF:
		case Kind::eSampler2DF:
		case Kind::eSampler3DF:
		case Kind::eSamplerCubeF:
		case Kind::eSampler2DRectF:
		case Kind::eSampler1DArrayF:
		case Kind::eSampler2DArrayF:
		case Kind::eSamplerCubeArrayF:
		case Kind::eSampler1DShadowF:
		case Kind::eSampler2DShadowF:
		case Kind::eSamplerCubeShadowF:
		case Kind::eSampler2DRectShadowF:
		case Kind::eSampler1DArrayShadowF:
		case Kind::eSampler2DArrayShadowF:
		case Kind::eSamplerCubeArrayShadowF:
		case Kind::eImage1DF:
		case Kind::eImage2DF:
		case Kind::eImage3DF:
		case Kind::eImageCubeF:
		case Kind::eImage2DRectF:
		case Kind::eImage1DArrayF:
		case Kind::eImage2DArrayF:
		case Kind::eImageCubeArrayF:
		case Kind::eImage2DMSF:
		case Kind::eImage2DMSArrayF:
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
