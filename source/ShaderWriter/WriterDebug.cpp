/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterDebug.hpp"

#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Shader.hpp>

namespace sdw
{
	std::string writeDebug( Shader const & shader )
	{
		return debug::displayStatements( *shader.getStatements() );
	}

	std::string writeDebug( stmt::Container const & stmt )
	{
		return debug::displayStatements( stmt );
	}

	std::string writeDebugPreprocessed( Shader const & shader
		, stmt::Container const & stmt )
	{
		auto & typesCache = shader.getTypesCache();
		auto ownAllocator = std::make_unique< ast::ShaderAllocator >();
		auto allocator = ownAllocator->getBlock();
		ast::stmt::StmtCache compileStmtCache{ *allocator };
		ast::expr::ExprCache compileExprCache{ *allocator };
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto statements = ast::transformSSA( compileStmtCache
			, compileExprCache
			, typesCache
			, stmt
			, ssaData
			, true );
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, typesCache
			, *statements );
		statements = ast::resolveConstants( compileStmtCache
			, compileExprCache
			, typesCache
			, *statements );
		return debug::displayStatements( *statements );
	}

	std::string writeDebugPreprocessed( Shader const & shader )
	{
		return writeDebugPreprocessed( shader
			, *shader.getStatements() );
	}
}
