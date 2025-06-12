/*
See LICENSE file in root folder
*/
#ifndef ___SDW_PreprocessShader_H___
#define ___SDW_PreprocessShader_H___
#pragma once

#include "ShaderAST/Expr/ExprCache.hpp"
#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/TransformSSA.hpp"

#include <utility>

namespace ast
{
	struct PreprocessResult
	{
		PreprocessResult( PreprocessResult const & ) = delete;
		PreprocessResult & operator=( PreprocessResult const & ) = delete;

		SDAST_API PreprocessResult( PreprocessResult && )noexcept = default;
		SDAST_API PreprocessResult & operator=( PreprocessResult && )noexcept = default;
		SDAST_API PreprocessResult( ShaderAllocatorBlock & allocator
			, Shader const & shader );

		ast::SSAData ssaData;
		std::unique_ptr< ast::stmt::StmtCache > stmtCache;
		std::unique_ptr< ast::expr::ExprCache > exprCache;
		ast::stmt::ContainerPtr statements;
	};

	SDAST_API PreprocessResult preprocessShader( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const & stmt );
}

#endif
