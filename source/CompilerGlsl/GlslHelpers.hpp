/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GLSLHelpers_H___
#define ___SDW_GLSLHelpers_H___
#pragma once

#include "compileGlsl.hpp"

#include <ShaderAST/ShaderASTPrerequisites.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Stmt/StmtInputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtOutputGeometryLayout.hpp>

#include <ShaderAST/Stmt/PreprocExtension.hpp>

#pragma warning( push )
#pragma warning( disable:5262 )
#include <sstream>
#include <locale>
#pragma warning( pop )

namespace glsl
{
	static uint32_t constexpr InvalidIndex = ~( 0u );

	struct IntrinsicsConfig
	{
		ast::ShaderStage stage;

		bool requiresFma1F{ false };
		bool requiresFma2F{ false };
		bool requiresFma3F{ false };
		bool requiresFma4F{ false };
		bool requiresFma1D{ false };
		bool requiresFma2D{ false };
		bool requiresFma3D{ false };
		bool requiresFma4D{ false };
		bool requiresRayDescDecl{ false };
		bool requiresBlendIndex{ false };
		bool requiresSeparateSamplers{ false };
		bool requiresInt8{ false };
		bool requiresInt16{ false };
		bool requiresInt64{ false };

		GlslExtensionSet requiredExtensions{};
	};
	void checkType( ast::type::TypePtr type
		, IntrinsicsConfig & config );
}

#endif
