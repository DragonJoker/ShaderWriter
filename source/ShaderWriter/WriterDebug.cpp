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
		return debug::displayStatements( shader.getStatements() );
	}

	std::string writeDebug( stmt::Container * stmt )
	{
		return debug::displayStatements( stmt );
	}

	std::string writeDebugPreprocessed( Shader const & shader )
	{
		auto ownAllocator = std::make_unique< ast::ShaderAllocator >();
		auto allocator = ownAllocator->getBlock();
		ast::stmt::StmtCache compileStmtCache{ *allocator };
		ast::expr::ExprCache compileExprCache{ *allocator };
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto statements = ast::transformSSA( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, shader.getStatements()
			, ssaData
			, true );
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get() );
		statements = ast::resolveConstants( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get() );
		return debug::displayStatements( statements.get() );
	}
}
