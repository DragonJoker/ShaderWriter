/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GLSLHelpers_H___
#define ___SDW_GLSLHelpers_H___
#pragma once

#include "compileGlsl.hpp"

#include <ShaderAST/ShaderASTPrerequisites.hpp>
#include <ShaderAST/Stmt/StmtInputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtOutputGeometryLayout.hpp>

#include <ShaderAST/Stmt/PreprocExtension.hpp>

namespace glsl
{
	static uint32_t constexpr InvalidIndex = ~( 0u );

	std::string getTypeName( ast::type::Kind kind );
	std::string getTypeName( ast::type::TypePtr type );
	std::string getTypeArraySize( ast::type::TypePtr type );
	std::string getInterpolationQualifier( ast::var::Variable const & var );
	std::string getLocationName( ast::var::Variable const & var );
	std::string getAccessQualifierName( ast::type::ImageConfiguration const & config );
	std::string getDirectionName( ast::var::Variable const & var );
	std::string getStatusName( ast::stmt::PreprocExtension::ExtStatus status );
	std::string getOperatorName( ast::expr::Kind kind );
	std::string getLayoutName( ast::type::InputLayout layout );
	std::string getLayoutName( ast::type::OutputLayout layout );
	std::string getLayoutName( ast::type::PatchDomain value );
	std::string getLayoutName( ast::type::PrimitiveOrdering value );
	std::string getLayoutName( ast::type::Partitioning value );
	std::string getCtorName( ast::expr::CompositeType composite
		, ast::type::Kind component );
	bool isUnaryPre( ast::expr::Kind kind );

	struct IntrinsicsConfig
	{
		bool requiresFma1F{ false };
		bool requiresFma2F{ false };
		bool requiresFma3F{ false };
		bool requiresFma4F{ false };
		bool requiresFma1D{ false };
		bool requiresFma2D{ false };
		bool requiresFma3D{ false };
		bool requiresFma4D{ false };
		bool requiresRayDescDecl{ false };

		GlslExtensionSet requiredExtensions{};
	};
	void checkType( ast::type::Type const & type
		, IntrinsicsConfig & config );
}

#endif
