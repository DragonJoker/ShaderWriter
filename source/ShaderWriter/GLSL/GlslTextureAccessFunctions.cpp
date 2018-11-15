/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslTextureAccessFunctions.hpp"

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

namespace sdw::glsl
{
	namespace details
	{
		using namespace ast;

		inline void writeTextureShadow( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_texture(" + sampler + " image, " + astArgType + " P, float refZ)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texture(image, " + glslArgType + "(P, refZ));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureShadowBias( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_texture(" + sampler + " image, " + astArgType + " P, float refZ, float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texture(image, " + glslArgType + "(P, refZ), bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTexture1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_texture(sampler1DShadow image, float P, float refZ)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texture(image, vec3(P, refZ, refZ));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTexture1DShadowBias( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_texture(sampler1DShadow image, float P, float refZ, float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texture(image, vec3(P, refZ, refZ), bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTexture2DShadow( stmt::Container * container )
		{
			writeTextureShadow( container, "sampler2DShadow", "vec2", "vec3" );
		}

		inline void writeTexture2DShadowBias( stmt::Container * container )
		{
			writeTextureShadowBias( container, "sampler2DShadow", "vec2", "vec3" );
		}

		inline void writeTextureCubeShadow( stmt::Container * container )
		{
			writeTextureShadow( container, "samplerCubeShadow", "vec3", "vec4" );
		}

		inline void writeTextureCubeShadowBias( stmt::Container * container )
		{
			writeTextureShadowBias( container, "samplerCubeShadow", "vec3", "vec4" );
		}

		inline void writeTexture1DArrayShadow( stmt::Container * container )
		{
			writeTextureShadow( container, "sampler1DArrayShadow", "vec2", "vec3" );
		}

		inline void writeTexture1DArrayShadowBias( stmt::Container * container )
		{
			writeTextureShadowBias( container, "sampler1DArrayShadow", "vec2", "vec3" );
		}

		inline void writeTexture2DArrayShadow( stmt::Container * container )
		{
			writeTextureShadow( container, "sampler2DArrayShadow", "vec3", "vec4" );
		}

		inline void writeTexture2DArrayShadowBias( stmt::Container * container )
		{
			writeTextureShadowBias( container, "sampler2DArrayShadow", "vec3", "vec4" );
		}

		inline void writeTexture2DRectShadow( stmt::Container * container )
		{
			writeTextureShadow( container, "sampler2DRectShadow", "vec2", "vec3" );
		}

		inline void writeTextureProjShadow( stmt::Container * container
			, std::string const & sampler )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProj(" + sampler + " image, vec3 P, float refZ)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProj(image, vec4(P.xy, refZ, P.z));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProj1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProj(sampler1DShadow image, vec2 P, float refZ)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProj(image, vec4(P.x, refZ, refZ, P.y));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProj1DShadowBias( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProj(sampler1DShadow image, vec2 P, float refZ, float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProj(image, vec4(P.x, refZ, refZ, P.y), bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjShadowBias( stmt::Container * container
			, std::string const & sampler )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProj(" + sampler + " image, vec3 P, float refZ, float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProj(image, vec4(P.xy, refZ, P.z), bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProj2DShadow( stmt::Container * container )
		{
			writeTextureProjShadow( container, "sampler2DShadow" );
		}

		inline void writeTextureProj2DShadowBias( stmt::Container * container )
		{
			writeTextureProjShadowBias( container, "sampler2DShadow" );
		}

		inline void writeTextureProj2DRectShadow( stmt::Container * container )
		{
			writeTextureProjShadow( container, "sampler2DRectShadow" );
		}

		inline void writeTextureLodShadow( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureLod(" + sampler + " image, " + astArgType + " P, float refZ, float lod)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureLod(image, " + glslArgType + "(P, refZ), lod);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureLod1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureLod(sampler1DShadow image, float P, float refZ, float lod)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureLod(image, vec3(P, refZ, refZ), lod);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureLod2DShadow( stmt::Container * container )
		{
			writeTextureLodShadow( container, "sampler2DShadow", "vec2", "vec3" );
		}

		inline void writeTextureLod1DArrayShadow( stmt::Container * container )
		{
			writeTextureLodShadow( container, "sampler1DArrayShadow", "vec2", "vec3" );
		}

		inline void writeTextureOffsetShadow( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType
			, std::string const & offsetType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureOffset(" + sampler + " image, " + astArgType + " P, float refZ, " + offsetType + " offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureOffset(image, " + glslArgType + "(P, refZ), offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureOffsetShadowBias( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType
			, std::string const & offsetType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureOffset(" + sampler + " image, " + astArgType + " P, float refZ, " + offsetType + " offset, float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureOffset(image, " + glslArgType + "(P, refZ), offset, bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureOffset1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureOffset(sampler1DShadow image, float P, float refZ, float offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureOffset(image, vec3(P, refZ, refZ), offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureOffset1DShadowBias( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureOffset(sampler1DShadow image, float P, float refZ, float offset, float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureOffset(image, vec3(P, refZ, refZ), offset, bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureOffset2DRectShadow( stmt::Container * container )
		{
			writeTextureOffsetShadow( container, "sampler2DRectShadow", "vec2", "vec3", "ivec2" );
		}

		inline void writeTextureOffset2DShadow( stmt::Container * container )
		{
			writeTextureOffsetShadow( container, "sampler2DShadow", "vec2", "vec3", "ivec2" );
		}

		inline void writeTextureOffset2DShadowBias( stmt::Container * container )
		{
			writeTextureOffsetShadow( container, "sampler2DShadow", "vec2", "vec3", "ivec2" );
		}

		inline void writeTextureOffset1DArrayShadow( stmt::Container * container )
		{
			writeTextureOffsetShadow( container, "sampler1DArrayShadow", "vec2", "vec3", "int" );
		}

		inline void writeTextureOffset2DArrayShadow( stmt::Container * container )
		{
			writeTextureOffsetShadow( container, "sampler2DArrayShadow", "vec3", "vec4", "ivec2" );
		}

		inline void writeTextureProjOffsetShadow( stmt::Container * container
			, std::string const & sampler
			, std::string const & offsetType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjOffset(" + sampler + " image, vec3 P, float refZ, " + offsetType + " offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjOffset(image, vec4(P.xy, refZ, P.z), offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjOffsetShadowBias( stmt::Container * container
			, std::string const & sampler
			, std::string const & offsetType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjOffset(" + sampler + " image, vec3 P, float refZ, float " + offsetType + ", float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjOffset(image, vec4(P.xy, refZ, P.z), offset, bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjOffset1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjOffset(sampler1DShadow image, vec2 P, float refZ, float offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjOffset(image, vec4(P.x, refZ, refZ, P.y), offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjOffset1DShadowBias( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjOffset(sampler1DShadow image, vec2 P, float refZ, float offset, float bias)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjOffset(image, vec4(P.x, refZ, refZ, P.y), offset, bias);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjOffset2DShadow( stmt::Container * container )
		{
			writeTextureProjOffsetShadow( container, "sampler2DShadow", "ivec2" );
		}

		inline void writeTextureProjOffset2DShadowBias( stmt::Container * container )
		{
			writeTextureProjOffsetShadowBias( container, "sampler2DShadow", "ivec2" );
		}

		inline void writeTextureProjOffset2DRectShadow( stmt::Container * container )
		{
			writeTextureProjOffsetShadow( container, "sampler2DRectShadow", "ivec2" );
		}

		inline void writeTextureLodOffsetShadow( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType
			, std::string const & offsetType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureLodOffset(" + sampler + " image, " + astArgType + " P, float refZ, float lod, " + offsetType + " offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureLodOffset(image, " + glslArgType + "(P, refZ), lod, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureLodOffset1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureLodOffset(sampler1DShadow image, float P, float refZ, float lod, int offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureLodOffset(image, vec3(P, refZ, refZ), lod, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureLodOffset2DShadow( stmt::Container * container )
		{
			writeTextureLodOffsetShadow( container, "sampler2DShadow", "vec2", "vec3", "ivec2" );
		}

		inline void writeTextureLodOffset1DArrayShadow( stmt::Container * container )
		{
			writeTextureLodOffsetShadow( container, "sampler1DArrayShadow", "vec2", "vec3", "int" );
		}

		inline void writeTextureProjLod1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjLod(sampler1DShadow image, vec2 P, float refZ, float lod)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjLod(image, vec4(P.x, refZ, refZ, P.y), lod);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjLod2DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjLod(sampler2DShadow image, vec3 P, float refZ, float lod)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjLod(image, vec4(P.xy, refZ, P.z), lod);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjLodOffset1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjLodOffset(sampler1DShadow image, vec2 P, float refZ, float lod, int offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjLodOffset(image, vec3(P.x, refZ, refZ, P.y), lod, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjLodOffset2DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjLodOffset(sampler2DShadow image, vec3 P, float refZ, float lod, ivec2 offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjLodOffset(image, vec4(P.xy, refZ, p.z), lod, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureGradShadow( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType
			, std::string const & dPdType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureGrad(" + sampler + " image, " + astArgType + " P, float refZ, " + dPdType + " dPdx, " + dPdType + " dPdy)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureGrad(image, " + glslArgType + "(P, refZ), dPdx, dPdy);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureGrad1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureGrad(sampler1DShadow image, float P, float refZ, float dPdx, float dPdy)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureGrad(image, vec3(P, refZ, refZ), dPdx, dPdy);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureGrad2DRectShadow( stmt::Container * container )
		{
			writeTextureGradShadow( container, "sampler2DRectShadow", "vec2", "vec3", "vec2" );
		}

		inline void writeTextureGrad2DShadow( stmt::Container * container )
		{
			writeTextureGradShadow( container, "sampler2DShadow", "vec2", "vec3", "vec2" );
		}

		inline void writeTextureGrad1DArrayShadow( stmt::Container * container )
		{
			writeTextureGradShadow( container, "sampler1DArrayShadow", "vec2", "vec3", "float" );
		}

		inline void writeTextureGradOffsetShadow( stmt::Container * container
			, std::string const & sampler
			, std::string const & astArgType
			, std::string const & glslArgType
			, std::string const & dPdType
			, std::string const & offsetType )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureGradOffset(" + sampler + " image, " + astArgType + " P, float refZ, " + dPdType + " dPdx, " + dPdType + " dPdy, " + offsetType + " offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureGradOffset(image, " + glslArgType + "(P, refZ), dPdx, dPdy, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureGradOffset1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureGradOffset(sampler1DShadow image, float P, float refZ, float dPdx, float dPdy, int offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureGradOffset(image, vec3(P, refZ, refZ), dPdx, dPdy, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureGradOffset2DRectShadow( stmt::Container * container )
		{
			writeTextureGradOffsetShadow( container, "sampler2DRectShadow", "vec2", "vec3", "vec2", "ivec2" );
		}

		inline void writeTextureGradOffset2DShadow( stmt::Container * container )
		{
			writeTextureGradOffsetShadow( container, "sampler2DShadow", "vec2", "vec3", "vec2", "ivec2" );
		}

		inline void writeTextureGradOffset1DArrayShadow( stmt::Container * container )
		{
			writeTextureGradOffsetShadow( container, "sampler1DArrayShadow", "vec2", "vec3", "float", "int" );
		}

		inline void writeTextureGradOffset2DArrayShadow( stmt::Container * container )
		{
			writeTextureGradOffsetShadow( container, "sampler2DArrayShadow", "vec3", "vec4", "vec2", "ivec2" );
		}

		inline void writeTextureProjGradShadow( stmt::Container * container
			, std::string const & sampler )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjGrad(" + sampler + " image, vec3 P, float refZ, vec2 dPdx, vec2 dPdy)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjGrad(image, vec4(P.xy, refZ, p.z), dPdx, dPdy);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjGrad1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjGrad(sampler1DShadow image, vec2 P, float refZ, float dPdx, float dPdy)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjGrad(image, vec4(P.x, refZ, refZ, P.y), dPdx, dPdy);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjGrad2DRectShadow( stmt::Container * container )
		{
			writeTextureProjGradShadow( container, "sampler2DRectShadow" );
		}

		inline void writeTextureProjGrad2DShadow( stmt::Container * container )
		{
			writeTextureProjGradShadow( container, "sampler2DShadow" );
		}

		inline void writeTextureProjGradOffsetShadow( stmt::Container * container
			, std::string const & sampler )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjGradOffset(" + sampler + " image, vec3 P, float refZ, vec2 dPdx, vec2 dPdy, ivec2 offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjGradOffset(image, vec4(P.xy, refZ, p.z), dPdx, dPdy, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjGradOffset1DShadow( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_textureProjGradOffset(sampler1DShadow image, vec2 P, float refZ, float dPdx, float dPdy, int offset)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return textureProjGradOffset(image, vec4(P.x, refZ, refZ, P.y), dPdx, dPdy, offset);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeTextureProjGradOffset2DRectShadow( stmt::Container * container )
		{
			writeTextureProjGradOffsetShadow( container, "sampler2DRectShadow" );
		}

		inline void writeTextureProjGradOffset2DShadow( stmt::Container * container )
		{
			writeTextureProjGradOffsetShadow( container, "sampler2DShadow" );
		}
	}

	void compileGlslTextureAccessFunctions( ast::stmt::Container * cont
		, IntrinsicsConfig const & config )
	{
		//if ( config.requiresTexture1DShadowF )
		//{
		//	details::writeTexture1DShadow( cont );
		//}

		//if ( config.requiresTexture1DShadowFBias )
		//{
		//	details::writeTexture1DShadowBias( cont );
		//}

		//if ( config.requiresTexture2DShadowF )
		//{
		//	details::writeTexture2DShadow( cont );
		//}

		//if ( config.requiresTexture2DShadowFBias )
		//{
		//	details::writeTexture2DShadowBias( cont );
		//}

		//if ( config.requiresTextureCubeShadowF )
		//{
		//	details::writeTextureCubeShadow( cont );
		//}

		//if ( config.requiresTextureCubeShadowFBias )
		//{
		//	details::writeTextureCubeShadowBias( cont );
		//}

		//if ( config.requiresTexture1DArrayShadowF )
		//{
		//	details::writeTexture1DArrayShadow( cont );
		//}

		//if ( config.requiresTexture1DArrayShadowFBias )
		//{
		//	details::writeTexture1DArrayShadowBias( cont );
		//}

		//if ( config.requiresTexture2DArrayShadowF )
		//{
		//	details::writeTexture2DArrayShadow( cont );
		//}

		//if ( config.requiresTexture2DArrayShadowFBias )
		//{
		//	details::writeTexture2DArrayShadowBias( cont );
		//}

		//if ( config.requiresTexture2DRectShadowF )
		//{
		//	details::writeTexture2DRectShadow( cont );
		//}

		//if ( config.requiresTextureProj1DShadowF )
		//{
		//	details::writeTextureProj1DShadow( cont );
		//}

		//if ( config.requiresTextureProj1DShadowFBias )
		//{
		//	details::writeTextureProj1DShadowBias( cont );
		//}

		//if ( config.requiresTextureProj2DShadowF )
		//{
		//	details::writeTextureProj2DShadow( cont );
		//}

		//if ( config.requiresTextureProj2DShadowFBias )
		//{
		//	details::writeTextureProj2DShadowBias( cont );
		//}

		//if ( config.requiresTextureProj2DRectShadowF )
		//{
		//	details::writeTextureProj2DRectShadow( cont );
		//}

		//if ( config.requiresTextureLod1DShadowF )
		//{
		//	details::writeTextureLod1DShadow( cont );
		//}

		//if ( config.requiresTextureLod2DShadowF )
		//{
		//	details::writeTextureLod2DShadow( cont );
		//}

		//if ( config.requiresTextureLod1DArrayShadowF )
		//{
		//	details::writeTextureLod1DArrayShadow( cont );
		//}

		//if ( config.requiresTextureOffset2DRectShadowF )
		//{
		//	details::writeTextureOffset2DRectShadow( cont );
		//}

		//if ( config.requiresTextureOffset1DShadowF )
		//{
		//	details::writeTextureOffset1DShadow( cont );
		//}

		//if ( config.requiresTextureOffset1DShadowFBias )
		//{
		//	details::writeTextureOffset1DShadowBias( cont );
		//}

		//if ( config.requiresTextureOffset2DShadowF )
		//{
		//	details::writeTextureOffset2DShadow( cont );
		//}

		//if ( config.requiresTextureOffset2DShadowFBias )
		//{
		//	details::writeTextureOffset2DShadowBias( cont );
		//}

		//if ( config.requiresTextureOffset1DArrayShadowF )
		//{
		//	details::writeTextureOffset1DArrayShadow( cont );
		//}

		//if ( config.requiresTextureOffset2DArrayShadowF )
		//{
		//	details::writeTextureOffset2DArrayShadow( cont );
		//}

		//if ( config.requiresTextureProjOffset1DShadowF )
		//{
		//	details::writeTextureProjOffset1DShadow( cont );
		//}

		//if ( config.requiresTextureProjOffset1DShadowFBias )
		//{
		//	details::writeTextureProjOffset1DShadowBias( cont );
		//}

		//if ( config.requiresTextureProjOffset2DShadowF )
		//{
		//	details::writeTextureProjOffset2DShadow( cont );
		//}

		//if ( config.requiresTextureProjOffset2DShadowFBias )
		//{
		//	details::writeTextureProjOffset2DShadowBias( cont );
		//}

		//if ( config.requiresTextureProjOffset2DRectShadowF )
		//{
		//	details::writeTextureProjOffset2DRectShadow( cont );
		//}

		//if ( config.requiresTextureLodOffset1DShadowF )
		//{
		//	details::writeTextureLodOffset1DShadow( cont );
		//}

		//if ( config.requiresTextureLodOffset2DShadowF )
		//{
		//	details::writeTextureLodOffset2DShadow( cont );
		//}

		//if ( config.requiresTextureLodOffset1DArrayShadowF )
		//{
		//	details::writeTextureLodOffset1DArrayShadow( cont );
		//}

		//if ( config.requiresTextureProjLod1DShadowF )
		//{
		//	details::writeTextureProjLod1DShadow( cont );
		//}

		//if ( config.requiresTextureProjLod2DShadowF )
		//{
		//	details::writeTextureProjLod2DShadow( cont );
		//}

		//if ( config.requiresTextureProjLodOffset1DShadowF )
		//{
		//	details::writeTextureProjLodOffset1DShadow( cont );
		//}

		//if ( config.requiresTextureProjLodOffset2DShadowF )
		//{
		//	details::writeTextureProjLodOffset2DShadow( cont );
		//}

		//if ( config.requiresTextureGrad2DRectShadowF )
		//{
		//	details::writeTextureGrad2DRectShadow( cont );
		//}

		//if ( config.requiresTextureGrad1DShadowF )
		//{
		//	details::writeTextureGrad1DShadow( cont );
		//}

		//if ( config.requiresTextureGrad2DShadowF )
		//{
		//	details::writeTextureGrad2DShadow( cont );
		//}

		//if ( config.requiresTextureGrad1DArrayShadowF )
		//{
		//	details::writeTextureGrad1DArrayShadow( cont );
		//}

		//if ( config.requiresTextureGradOffset2DRectShadowF )
		//{
		//	details::writeTextureGradOffset2DRectShadow( cont );
		//}

		//if ( config.requiresTextureGradOffset1DShadowF )
		//{
		//	details::writeTextureGradOffset1DShadow( cont );
		//}

		//if ( config.requiresTextureGradOffset2DShadowF )
		//{
		//	details::writeTextureGradOffset2DShadow( cont );
		//}

		//if ( config.requiresTextureGradOffset1DArrayShadowF )
		//{
		//	details::writeTextureGradOffset1DArrayShadow( cont );
		//}

		//if ( config.requiresTextureGradOffset2DArrayShadowF )
		//{
		//	details::writeTextureGradOffset2DArrayShadow( cont );
		//}

		//if ( config.requiresTextureProjGrad1DShadowF )
		//{
		//	details::writeTextureProjGrad1DShadow( cont );
		//}

		//if ( config.requiresTextureProjGrad2DShadowF )
		//{
		//	details::writeTextureProjGrad2DShadow( cont );
		//}

		//if ( config.requiresTextureProjGrad2DRectShadowF )
		//{
		//	details::writeTextureProjGrad2DRectShadow( cont );
		//}

		//if ( config.requiresTextureProjGradOffset1DShadowF )
		//{
		//	details::writeTextureProjGradOffset1DShadow( cont );
		//}

		//if ( config.requiresTextureProjGradOffset2DShadowF )
		//{
		//	details::writeTextureProjGradOffset2DShadow( cont );
		//}

		//if ( config.requiresTextureProjGradOffset2DRectShadowF )
		//{
		//	details::writeTextureProjGradOffset2DRectShadow( cont );
		//}
	}
}
