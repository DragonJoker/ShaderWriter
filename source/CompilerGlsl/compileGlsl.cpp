/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslAdaptStatements.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>
#include <GlslCommon/GlslFillConfig.hpp>

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SelectEntryPoint.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace glsl
{
	std::string compileGlsl( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const * stmt
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config )
	{
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getVarId();
		auto & typesCache = shader.getTypesCache();
		config.shaderStage = stage;
		auto intrinsics = glsl::fillConfig( stage
			, *stmt );
		glsl::checkConfig( config, intrinsics );

		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
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
