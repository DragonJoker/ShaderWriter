/*
See LICENSE file in root folder
*/
#include "CompilerHlsl/compileHlsl.hpp"

#include "HlslFillConfig.hpp"
#include "HlslGenerateStatements.hpp"
#include "HlslAdaptStatements.hpp"

#include <ShaderAST/Visitors/PreprocessShader.hpp>
#include <ShaderAST/Visitors/SelectEntryPoint.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>

#include <algorithm>

namespace hlsl
{
	namespace
	{
		void checkConfig( HlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig )
		{
			if ( isRayTraceStage( writerConfig.shaderStage ) && writerConfig.shaderModel < hlsl::v6_3 )
			{
				throw UnsupportedExtensionException{ "Unsupported Ray Tracing stage for this shader model" };
			}

			if ( isMeshStage( writerConfig.shaderStage ) && writerConfig.shaderModel < hlsl::v6_5 )
			{
				throw UnsupportedExtensionException{ "Unsupported Mesh/Amplification stage for this shader model" };
			}

			if ( intrinsicsConfig.requiresWaveOps && writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported Wave ops for this shader model" };
			}

			if ( intrinsicsConfig.requiresControlBarrier
				&& writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
				&& writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported control barrier for this shader model" };
			}

			if ( writerConfig.shaderModel < hlsl::v5_0
				&& ( writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
					|| writerConfig.shaderStage == ast::ShaderStage::eTessellationEvaluation ) )
			{
				throw UnsupportedExtensionException{ "Unsupported Tessellation stage for this shader model" };
			}

			if ( intrinsicsConfig.requiresDouble && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw UnsupportedExtensionException{ "Unsupported double type for this shader model" };
			}

			if ( intrinsicsConfig.requiresInt8 )
			{
				throw UnsupportedExtensionException{ "Unsupported byte type for this shader model" };
			}

			if ( intrinsicsConfig.requiresAtomicAddFloat )
			{
				throw UnsupportedExtensionException{ "Unsupported atomic add with floating point" };
			}

			if ( intrinsicsConfig.requiresInt16 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported short type for this shader model" };
			}

			if ( intrinsicsConfig.requiresSInt64 )
			{
				throw UnsupportedExtensionException{ "Unsupported int64_t type" };
			}

			if ( intrinsicsConfig.requiresUInt64 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported uint64_t type for this shader model" };
			}

			if ( intrinsicsConfig.requiresUAV && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw UnsupportedExtensionException{ "Unsupported UAV for this shader model" };
			}

			if ( intrinsicsConfig.requiresInterpolate && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported interpolate for this shader model" };
			}

			if ( intrinsicsConfig.requiresShadowOnTiled && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported sample shadow for tiled resource, for this shader model" };
			}

			if ( intrinsicsConfig.requiresGather && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported gather, for this shader model" };
			}

			if ( intrinsicsConfig.requiresSampledIndex && writerConfig.shaderModel < hlsl::v4_1 )
			{
				throw UnsupportedExtensionException{ "Unsupported SV_SampleIndex for this shader model" };
			}
		}
	}

	std::string compilePreprocessedHlsl( ast::Shader const & shader
		, ast::PreprocessResult & preprocessResult
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig )
	{
		auto & typesCache = shader.getTypesCache();
		auto config = writerConfig;
		config.shaderStage = stage;
		HlslShader hlslShader{ shader, stage };
		AdaptationData adaptationData{ *preprocessResult.exprCache
			, hlslShader };
		adaptationData.aliasId = preprocessResult.ssaData.aliasId;
		adaptationData.nextVarId = preprocessResult.ssaData.nextVarId;
		auto intrinsicsConfig = hlsl::fillConfig( hlslShader
			, adaptationData
			, *preprocessResult.statements );
		checkConfig( config, intrinsicsConfig );

		auto statements = hlsl::adaptStatements( *preprocessResult.stmtCache
			, *preprocessResult.exprCache
			, hlslShader
			, *preprocessResult.statements
			, intrinsicsConfig
			, config
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
		std::map< ast::var::VariablePtr, ast::expr::Expr const * > aliases;
		return hlsl::generateStatements( config, adaptationData.getRoutines(), aliases, *statements );
	}

	std::string compileHlsl( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const * stmt
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig )
	{
		auto preprocessResult = ast::preprocessShader( allocator, shader, *stmt );
		return compilePreprocessedHlsl( shader, preprocessResult, stage, specialisation, writerConfig );
	}

	std::string compileHlsl( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig )
	{
		ast::stmt::StmtCache compileStmtCache{ shader.getAllocator() };
		ast::expr::ExprCache compileExprCache{ shader.getAllocator() };
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
		return compileHlsl( allocator
			, shader
			, statements.get()
			, shader.getType()
			, specialisation
			, writerConfig );
	}
}
