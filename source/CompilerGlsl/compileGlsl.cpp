/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslAdaptStatements.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>
#include <GlslCommon/GlslFillConfig.hpp>

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace glsl
{
	std::string compileGlsl( ast::Shader const & shader
		, ast::stmt::Container const * stmt
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config )
	{
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto & typesCache = shader.getTypesCache();
		config.shaderStage = stage;
		auto intrinsics = glsl::fillConfig( stage
			, *stmt );
		glsl::checkConfig( config, intrinsics );

		auto ownAllocator = config.allocator ? nullptr : std::make_unique< ast::ShaderAllocator >();
		auto allocator = config.allocator ? config.allocator->getBlock() : ownAllocator->getBlock();
		ast::stmt::StmtCache compileStmtCache{ *allocator };
		ast::expr::ExprCache compileExprCache{ *allocator };
		auto statements = ast::transformSSA( compileStmtCache
			, compileExprCache
			, typesCache
			, *stmt
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
		glsl::AdaptationData adaptationData{ stage
			, config
			, intrinsics
			, ssaData.nextVarId };
		statements = adaptStatements( compileStmtCache
			, compileExprCache
			, typesCache
			, *statements
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, typesCache
			, *statements );
		statements = ast::specialiseStatements( compileStmtCache
			, compileExprCache
			, typesCache
			, *statements
			, specialisation );
		return glsl::generateGlslStatements( config, intrinsics, *statements ).source;
	}
	
	std::string compileGlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config )
	{
		return compileGlsl( shader
			, shader.getStatements()
			, shader.getType()
			, specialisation
			, config );
	}
}
