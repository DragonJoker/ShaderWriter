/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslAdaptStatements.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>
#include <GlslCommon/GlslFillConfig.hpp>

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/PreprocessShader.hpp>
#include <ShaderAST/Visitors/SelectEntryPoint.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>

#include <algorithm>

namespace glsl
{
	std::string compilePreprocessedGlsl( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::PreprocessResult & preprocessResult
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config )
	{
		auto & typesCache = shader.getTypesCache();
		config.shaderStage = stage;
		auto intrinsics = glsl::fillConfig( stage
			, *preprocessResult.statements );
		glsl::checkConfig( config, intrinsics );
		glsl::AdaptationData adaptationData{ stage
			, config
			, intrinsics
			, preprocessResult.ssaData.nextVarId };
		auto statements = adaptStatements( *preprocessResult.stmtCache
			, *preprocessResult.exprCache
			, typesCache
			, *preprocessResult.statements
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::simplify( *preprocessResult.stmtCache
			, *preprocessResult.exprCache
			, typesCache
			, *statements );
		statements = ast::specialiseStatements( *preprocessResult.stmtCache
			, *preprocessResult.exprCache
			, typesCache
			, *statements
			, specialisation );
		return glsl::generateGlslStatements( config, intrinsics, *statements ).source;
	}

	std::string compileGlsl( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const * stmt
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config )
	{
		auto preprocessResult = ast::preprocessShader( allocator, shader, *stmt );
		return compilePreprocessedGlsl( allocator, shader, preprocessResult, stage, specialisation, config );
	}
	
	std::string compileGlsl( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config )
	{
		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
		auto entryPoints = ast::listEntryPoints( *shader.getStatements() );
		auto it = std::find_if( entryPoints.begin()
			, entryPoints.end()
			, [&shader]( ast::EntryPointConfig const & lookup )
			{
				return lookup.stage == shader.getType();
			} );
		if ( it == entryPoints.end() )
		{
			return {};
		}

		auto statements = ast::selectEntryPoint( compileStmtCache
			, compileExprCache
			, *it
			, *shader.getStatements() );
		return compileGlsl( allocator
			, shader
			, statements.get()
			, shader.getType()
			, specialisation
			, config );
	}
}
