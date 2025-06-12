/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/PreprocessShader.hpp"

#include "ShaderAST/Shader.hpp"
#include "ShaderAST/Visitors/ResolveConstants.hpp"
#include "ShaderAST/Visitors/SimplifyStatements.hpp"

namespace ast
{
	PreprocessResult::PreprocessResult( ShaderAllocatorBlock & allocator
		, Shader const & shader )
		: stmtCache{ std::make_unique< stmt::StmtCache >( allocator ) }
		, exprCache{ std::make_unique< expr::ExprCache >( allocator ) }
	{
		ssaData.nextVarId = shader.getVarId();
	}

	PreprocessResult preprocessShader( ShaderAllocatorBlock & allocator
		, Shader const & shader
		, stmt::Container const & stmt )
	{
		PreprocessResult result{ allocator, shader };
		auto & typesCache = shader.getTypesCache();
		auto statements = transformSSA( *result.stmtCache
			, *result.exprCache
			, typesCache
			, stmt
			, result.ssaData
			, true );
		statements = simplify( *result.stmtCache
			, *result.exprCache
			, typesCache
			, *statements );
		result.statements = resolveConstants( *result.stmtCache
			, *result.exprCache
			, *statements );
		return result;
	}
}
