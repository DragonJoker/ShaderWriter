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

#include <sstream>
#include <locale>

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
	std::string getLayoutName( ast::type::OutputTopology value );
	std::string getCtorName( ast::expr::CompositeType composite
		, ast::type::Kind component );
	std::string getCtorName( ast::expr::Expr const & image
		, ast::expr::Expr const & sampler );
	bool isUnaryPre( ast::expr::Kind kind );
	std::string getQualifiedName( ast::type::Kind kind
		, ast::type::ImageConfiguration const & config );
	std::string getQualifiedName( ast::type::Kind kind
		, ast::type::ImageConfiguration const & config
		, bool isComparison );
	std::string getQualifiedName( ast::type::Kind kind
		, ast::type::ImageConfiguration const & config
		, ast::type::Trinary comparison );

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

	template< typename ValueT >
	std::string writeValue( ValueT const & v )
	{
		std::stringstream stream;
		stream.imbue( std::locale{ "C" } );
		stream << v;
		return stream.str();
	}
}

#endif
