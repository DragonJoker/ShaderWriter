/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslAdaptStatements.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>
#include <GlslCommon/GlslFillConfig.hpp>

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace glsl
{
	std::string compileGlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config )
	{
		config.shaderStage = shader.getType();
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto intrinsics = glsl::fillConfig( shader.getType()
			, shader.getStatements() );
		glsl::checkConfig( config, intrinsics );

		auto ownAllocator = config.allocator ? nullptr : std::make_unique< ast::ShaderAllocator >();
		auto allocator = config.allocator ? config.allocator->getBlock() : ownAllocator->getBlock();
		ast::stmt::StmtCache compileStmtCache{ *allocator };
		ast::expr::ExprCache compileExprCache{ *allocator };
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
		glsl::AdaptationData adaptationData{ shader.getType()
			, config
			, std::move( intrinsics )
			, ssaData.nextVarId };
		statements = adaptStatements( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get()
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get() );
		statements = ast::specialiseStatements( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get()
			, specialisation );
		return glsl::generateGlslStatements( config, intrinsics, statements.get() ).source;
	}
}
