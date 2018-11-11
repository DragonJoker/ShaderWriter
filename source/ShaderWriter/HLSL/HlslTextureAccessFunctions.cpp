/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp"

#include <ASTGenerator/Expr/EnumIntrinsic.hpp>
#include <ASTGenerator/Expr/ExprBitAnd.hpp>
#include <ASTGenerator/Expr/ExprBitOr.hpp>
#include <ASTGenerator/Expr/ExprCast.hpp>
#include <ASTGenerator/Expr/ExprDivide.hpp>
#include <ASTGenerator/Expr/ExprEqual.hpp>
#include <ASTGenerator/Expr/ExprInit.hpp>
#include <ASTGenerator/Expr/ExprIntrinsicCall.hpp>
#include <ASTGenerator/expr/ExprLiteral.hpp>
#include <ASTGenerator/expr/ExprLShift.hpp>
#include <ASTGenerator/expr/ExprLShiftAssign.hpp>
#include <ASTGenerator/expr/ExprMbrSelect.hpp>
#include <ASTGenerator/expr/ExprOrAssign.hpp>
#include <ASTGenerator/expr/ExprRShift.hpp>
#include <ASTGenerator/expr/ExprRShiftAssign.hpp>
#include <ASTGenerator/expr/ExprTimes.hpp>

#include <ASTGenerator/Stmt/StmtFunctionDecl.hpp>
#include <ASTGenerator/Stmt/StmtReturn.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>
#include <ASTGenerator/Stmt/StmtVariableDecl.hpp>

#include <string>

namespace sdw::hlsl
{
	namespace details
	{
		using namespace ast;

		inline void writeTextureSizeBuffer( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_textureSize(" + type + " texImage)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dim;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(dim);" ) );
			cont->addStmt( stmt::makeComment( "	return int(dim);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureSize1D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_textureSize(" + type + " texImage, int lod)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dim;" ) );
			cont->addStmt( stmt::makeComment( "	uint dump;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(lod, dim, dump);" ) );
			cont->addStmt( stmt::makeComment( "	return int(dim);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureSize2D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int2 SDW_textureSize(" + type + " texImage, int lod)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dump;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(lod, dimX, dimY, dump);" ) );
			cont->addStmt( stmt::makeComment( "	return int2(dimX, dimY);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureSize2DRect( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int2 SDW_textureSize(" + type + " texImage)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dump;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(0, dimX, dimY, dump);" ) );
			cont->addStmt( stmt::makeComment( "	return int2(dimX, dimY);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureSize3D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int3 SDW_textureSize(" + type + " texImage, int lod)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimZ;" ) );
			cont->addStmt( stmt::makeComment( "	uint dump;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(lod, dimX, dimY, dimZ, dump);" ) );
			cont->addStmt( stmt::makeComment( "	return int3(dimX, dimY, dimZ);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureQueryLod1D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_textureQueryLod(" + type + " texImage, SamplerState texSampler, float P)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return float2(texImage.CalculateLevelOfDetail(texSampler, P), 0.0);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureQueryLod2D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_textureQueryLod(" + type + " texImage, SamplerState texSampler, float2 P)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return float2(texImage.CalculateLevelOfDetail(texSampler, P), 0.0);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureQueryLod3D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_textureQueryLod(" + type + " texImage, SamplerState texSampler, float3 P)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return float2(texImage.CalculateLevelOfDetail(texSampler, P), 0.0);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureQueryLevels1D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_textureQueryLevels(" + type + " texImage)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dim;" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(0, dim, res);" ) );
			cont->addStmt( stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureQueryLevels2D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_textureQueryLevels(" + type + " texImage)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(0, dimX, dimY, res);" ) );
			cont->addStmt( stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureQueryLevels3D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_textureQueryLevels(" + type + " texImage)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimZ;" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	texImage.GetDimensions(0, dimX, dimY, dimZ, res);" ) );
			cont->addStmt( stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_projectTexCoords2(float2 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.x / texCoords.y;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords3( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_projectTexCoords3(float3 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.xy / texCoords.z;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords4To1( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_projectTexCoords4to1(float4 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.x / texCoords.w;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords4To2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_projectTexCoords4To2(float4 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.xy / texCoords.w;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords4( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float3 SDW_projectTexCoords4(float4 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.xyz / texCoords.w;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
	}

	void writeHlslTextureAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
		if ( config.requiresTextureSizeBufferF )
		{
			details::writeTextureSizeBuffer( container, "Buffer<float4>" );
		}
		if ( config.requiresTextureSizeBufferI )
		{
			details::writeTextureSizeBuffer( container, "Buffer<int4>" );
		}
		if ( config.requiresTextureSizeBufferU )
		{
			details::writeTextureSizeBuffer( container, "Buffer<uint4>" );
		}
		if ( config.requiresTextureSize1DF )
		{
			details::writeTextureSize1D( container, "Texture1D<float4>" );
		}
		if ( config.requiresTextureSize1DShadowF )
		{
			details::writeTextureSize1D( container, "Texture1D<float4>" );
		}
		if ( config.requiresTextureSize1DI )
		{
			details::writeTextureSize1D( container, "Texture1D<int4>" );
		}
		if ( config.requiresTextureSize1DU )
		{
			details::writeTextureSize1D( container, "Texture1D<uint4>" );
		}
		if ( config.requiresTextureSize1DArrayF )
		{
			details::writeTextureSize2D( container, "Texture1DArray<float4>" );
		}
		if ( config.requiresTextureSize1DArrayShadowF )
		{
			details::writeTextureSize2D( container, "Texture1DArray<float4>" );
		}
		if ( config.requiresTextureSize1DArrayI )
		{
			details::writeTextureSize2D( container, "Texture1DArray<int4>" );
		}
		if ( config.requiresTextureSize1DArrayU )
		{
			details::writeTextureSize2D( container, "Texture1DArray<uint4>" );
		}
		if ( config.requiresTextureSize2DF )
		{
			details::writeTextureSize2D( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureSize2DRectF )
		{
			details::writeTextureSize2DRect( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureSize2DShadowF )
		{
			details::writeTextureSize2D( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureSize2DRectShadowF )
		{
			details::writeTextureSize2DRect( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureSize2DI )
		{
			details::writeTextureSize2D( container, "Texture2D<int4>" );
		}
		if ( config.requiresTextureSize2DRectI )
		{
			details::writeTextureSize2DRect( container, "Texture2D<int4>" );
		}
		if ( config.requiresTextureSize2DU )
		{
			details::writeTextureSize2D( container, "Texture2D<uint4>" );
		}
		if ( config.requiresTextureSize2DRectU )
		{
			details::writeTextureSize2DRect( container, "Texture2D<uint4>" );
		}
		if ( config.requiresTextureSize2DArrayF )
		{
			details::writeTextureSize3D( container, "Texture2DArray<float4>" );
		}
		if ( config.requiresTextureSize2DArrayShadowF )
		{
			details::writeTextureSize3D( container, "Texture2DArray<float4>" );
		}
		if ( config.requiresTextureSize2DArrayI )
		{
			details::writeTextureSize3D( container, "Texture2DArray<int4>" );
		}
		if ( config.requiresTextureSize2DArrayU )
		{
			details::writeTextureSize3D( container, "Texture2DArray<uint4>" );
		}
		if ( config.requiresTextureSize3DF )
		{
			details::writeTextureSize3D( container, "Texture3D<float4>" );
		}
		if ( config.requiresTextureSize3DI )
		{
			details::writeTextureSize3D( container, "Texture3D<int4>" );
		}
		if ( config.requiresTextureSize3DU )
		{
			details::writeTextureSize3D( container, "Texture3D<uint4>" );
		}
		if ( config.requiresTextureSizeCubeF )
		{
			details::writeTextureSize2D( container, "TextureCube<float4>" );
		}
		if ( config.requiresTextureSizeCubeShadowF )
		{
			details::writeTextureSize2D( container, "TextureCube<float4>" );
		}
		if ( config.requiresTextureSizeCubeI )
		{
			details::writeTextureSize2D( container, "TextureCube<int4>" );
		}
		if ( config.requiresTextureSizeCubeU )
		{
			details::writeTextureSize2D( container, "TextureCube<uint4>" );
		}
		if ( config.requiresTextureSizeCubeArrayF )
		{
			details::writeTextureSize3D( container, "TextureCubeArray<float4>" );
		}
		if ( config.requiresTextureSizeCubeArrayShadowF )
		{
			details::writeTextureSize3D( container, "TextureCubeArray<float4>" );
		}
		if ( config.requiresTextureSizeCubeArrayI )
		{
			details::writeTextureSize3D( container, "TextureCubeArray<int4>" );
		}
		if ( config.requiresTextureSizeCubeArrayU )
		{
			details::writeTextureSize3D( container, "TextureCubeArray<uint4>" );
		}
		if ( config.requiresTextureQueryLod1DF )
		{
			details::writeTextureQueryLod1D( container, "Texture1D<float4>" );
		}
		if ( config.requiresTextureQueryLod1DShadowF )
		{
			details::writeTextureQueryLod1D( container, "Texture1D<float4>" );
		}
		if ( config.requiresTextureQueryLod1DI )
		{
			details::writeTextureQueryLod1D( container, "Texture1D<int4>" );
		}
		if ( config.requiresTextureQueryLod1DU )
		{
			details::writeTextureQueryLod1D( container, "Texture1D<uint4>" );
		}
		if ( config.requiresTextureQueryLod1DArrayF )
		{
			details::writeTextureQueryLod1D( container, "Texture1DArray<float4>" );
		}
		if ( config.requiresTextureQueryLod1DArrayShadowF )
		{
			details::writeTextureQueryLod1D( container, "Texture1DArray<float4>" );
		}
		if ( config.requiresTextureQueryLod1DArrayI )
		{
			details::writeTextureQueryLod1D( container, "Texture1DArray<int4>" );
		}
		if ( config.requiresTextureQueryLod1DArrayU )
		{
			details::writeTextureQueryLod1D( container, "Texture1DArray<uint4>" );
		}
		if ( config.requiresTextureQueryLod2DF )
		{
			details::writeTextureQueryLod2D( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureQueryLod2DShadowF )
		{
			details::writeTextureQueryLod2D( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureQueryLod2DI )
		{
			details::writeTextureQueryLod2D( container, "Texture2D<int4>" );
		}
		if ( config.requiresTextureQueryLod2DU )
		{
			details::writeTextureQueryLod2D( container, "Texture2D<uint4>" );
		}
		if ( config.requiresTextureQueryLod2DArrayF )
		{
			details::writeTextureQueryLod2D( container, "Texture2DArray<float4>" );
		}
		if ( config.requiresTextureQueryLod2DArrayShadowF )
		{
			details::writeTextureQueryLod2D( container, "Texture2DArray<float4>" );
		}
		if ( config.requiresTextureQueryLod2DArrayI )
		{
			details::writeTextureQueryLod2D( container, "Texture2DArray<int4>" );
		}
		if ( config.requiresTextureQueryLod2DArrayU )
		{
			details::writeTextureQueryLod2D( container, "Texture2DArray<uint4>" );
		}
		if ( config.requiresTextureQueryLod3DF )
		{
			details::writeTextureQueryLod3D( container, "Texture3D<float4>" );
		}
		if ( config.requiresTextureQueryLod3DI )
		{
			details::writeTextureQueryLod3D( container, "Texture3D<int4>" );
		}
		if ( config.requiresTextureQueryLod3DU )
		{
			details::writeTextureQueryLod3D( container, "Texture3D<uint4>" );
		}
		if ( config.requiresTextureQueryLodCubeF )
		{
			details::writeTextureQueryLod3D( container, "TextureCube<float4>" );
		}
		if ( config.requiresTextureQueryLodCubeShadowF )
		{
			details::writeTextureQueryLod3D( container, "TextureCube<float4>" );
		}
		if ( config.requiresTextureQueryLodCubeI )
		{
			details::writeTextureQueryLod3D( container, "TextureCube<int4>" );
		}
		if ( config.requiresTextureQueryLodCubeU )
		{
			details::writeTextureQueryLod3D( container, "TextureCube<uint4>" );
		}
		if ( config.requiresTextureQueryLodCubeArrayF )
		{
			details::writeTextureQueryLod3D( container, "TextureCubeArray<float4>" );
		}
		if ( config.requiresTextureQueryLodCubeArrayShadowF )
		{
			details::writeTextureQueryLod3D( container, "TextureCubeArray<float4>" );
		}
		if ( config.requiresTextureQueryLodCubeArrayI )
		{
			details::writeTextureQueryLod3D( container, "TextureCubeArray<int4>" );
		}
		if ( config.requiresTextureQueryLodCubeArrayU )
		{
			details::writeTextureQueryLod3D( container, "TextureCubeArray<uint4>" );
		}
		if ( config.requiresTextureQueryLevels1DF )
		{
			details::writeTextureQueryLevels1D( container, "Texture1D<float4>" );
		}
		if ( config.requiresTextureQueryLevels1DShadowF )
		{
			details::writeTextureQueryLevels1D( container, "Texture1D<float4>" );
		}
		if ( config.requiresTextureQueryLevels1DI )
		{
			details::writeTextureQueryLevels1D( container, "Texture1D<int4>" );
		}
		if ( config.requiresTextureQueryLevels1DU )
		{
			details::writeTextureQueryLevels1D( container, "Texture1D<uint4>" );
		}
		if ( config.requiresTextureQueryLevels1DArrayF )
		{
			details::writeTextureQueryLevels2D( container, "Texture1DArray<float4>" );
		}
		if ( config.requiresTextureQueryLevels1DArrayShadowF )
		{
			details::writeTextureQueryLevels2D( container, "Texture1DArray<float4>" );
		}
		if ( config.requiresTextureQueryLevels1DArrayI )
		{
			details::writeTextureQueryLevels2D( container, "Texture1DArray<int4>" );
		}
		if ( config.requiresTextureQueryLevels1DArrayU )
		{
			details::writeTextureQueryLevels2D( container, "Texture1DArray<uint4>" );
		}
		if ( config.requiresTextureQueryLevels2DF )
		{
			details::writeTextureQueryLevels2D( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureQueryLevels2DShadowF )
		{
			details::writeTextureQueryLevels2D( container, "Texture2D<float4>" );
		}
		if ( config.requiresTextureQueryLevels2DI )
		{
			details::writeTextureQueryLevels2D( container, "Texture2D<int4>" );
		}
		if ( config.requiresTextureQueryLevels2DU )
		{
			details::writeTextureQueryLevels2D( container, "Texture2D<uint4>" );
		}
		if ( config.requiresTextureQueryLevels2DArrayF )
		{
			details::writeTextureQueryLevels3D( container, "Texture2DArray<float4>" );
		}
		if ( config.requiresTextureQueryLevels2DArrayShadowF )
		{
			details::writeTextureQueryLevels3D( container, "Texture2DArray<float4>" );
		}
		if ( config.requiresTextureQueryLevels2DArrayI )
		{
			details::writeTextureQueryLevels3D( container, "Texture2DArray<int4>" );
		}
		if ( config.requiresTextureQueryLevels2DArrayU )
		{
			details::writeTextureQueryLevels3D( container, "Texture2DArray<uint4>" );
		}
		if ( config.requiresTextureQueryLevels3DF )
		{
			details::writeTextureQueryLevels3D( container, "Texture3D<float4>" );
		}
		if ( config.requiresTextureQueryLevels3DI )
		{
			details::writeTextureQueryLevels3D( container, "Texture3D<int4>" );
		}
		if ( config.requiresTextureQueryLevels3DU )
		{
			details::writeTextureQueryLevels3D( container, "Texture3D<uint4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeF )
		{
			details::writeTextureQueryLevels2D( container, "TextureCube<float4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeShadowF )
		{
			details::writeTextureQueryLevels2D( container, "TextureCube<float4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeI )
		{
			details::writeTextureQueryLevels2D( container, "TextureCube<int4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeU )
		{
			details::writeTextureQueryLevels2D( container, "TextureCube<uint4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeArrayF )
		{
			details::writeTextureQueryLevels3D( container, "TextureCubeArray<float4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeArrayShadowF )
		{
			details::writeTextureQueryLevels3D( container, "TextureCubeArray<float4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeArrayI )
		{
			details::writeTextureQueryLevels3D( container, "TextureCubeArray<int4>" );
		}
		if ( config.requiresTextureQueryLevelsCubeArrayU )
		{
			details::writeTextureQueryLevels3D( container, "TextureCubeArray<uint4>" );
		}
		if ( config.requiresProjectTexCoords2 )
		{
			details::writeProjectTexCoords2( container );
		}
		if ( config.requiresProjectTexCoords3 )
		{
			details::writeProjectTexCoords3( container );
		}
		if ( config.requiresProjectTexCoords4To1 )
		{
			details::writeProjectTexCoords4To1( container );
		}
		if ( config.requiresProjectTexCoords4To2 )
		{
			details::writeProjectTexCoords4To2( container );
		}
		if ( config.requiresProjectTexCoords4 )
		{
			details::writeProjectTexCoords4( container );
		}
	}
}
