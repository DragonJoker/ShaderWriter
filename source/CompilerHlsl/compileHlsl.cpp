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
		std::string printRaytracingTier( uint32_t tier )
		{
			auto major = tier / 10u;
			auto minor = tier % 10u;
			return std::to_string( major ) + "_" + std::to_string( minor );
		}

		std::string printShaderModel( uint32_t shaderModel
			, ast::ShaderStage type )
		{
			auto major = shaderModel / 10u;
			auto minor = shaderModel % 10u;
			auto model = std::to_string( major ) + "_" + std::to_string( minor );

			switch ( type )
			{
			case ast::ShaderStage::eVertex:
				model = "vs_" + model;
				break;
			case ast::ShaderStage::eTessellationControl:
				model = "hs_" + model;
				break;
			case ast::ShaderStage::eTessellationEvaluation:
				model = "ds_" + model;
				break;
			case ast::ShaderStage::eGeometry:
				model = "gs_" + model;
				break;
			case ast::ShaderStage::eCompute:
				model = "cs_" + model;
				break;
			case ast::ShaderStage::eFragment:
				model = "ps_" + model;
				break;
			case ast::ShaderStage::eMeshNV:
			case ast::ShaderStage::eMesh:
				model = "ms_" + model;
				break;
			case ast::ShaderStage::eTaskNV:
			case ast::ShaderStage::eTask:
				model = "as_" + model;
				break;
			case ast::ShaderStage::eCallable:
			case ast::ShaderStage::eRayGeneration:
			case ast::ShaderStage::eRayIntersection:
			case ast::ShaderStage::eRayMiss:
			case ast::ShaderStage::eRayAnyHit:
			case ast::ShaderStage::eRayClosestHit:
				model = "lib_" + model;
				break;
			default:
				break;
			}

			return model;
		}

		void checkConfig( HlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig )
		{
			if ( isRayTraceStage( writerConfig.shaderStage ) && writerConfig.shaderModel < hlsl::v6_3 )
			{
				throw UnsupportedExtensionException{ "Unsupported raytracing stage for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( isMeshStage( writerConfig.shaderStage ) && writerConfig.shaderModel < hlsl::v6_5 )
			{
				throw UnsupportedExtensionException{ "Unsupported Mesh/Amplification stage for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresWaveOps && writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported Wave ops for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresQuadControl && writerConfig.shaderModel < hlsl::v6_7 )
			{
				throw UnsupportedExtensionException{ "Unsupported Quad control ops for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresFullQuads && writerConfig.shaderModel < hlsl::v6_7 )
			{
				throw UnsupportedExtensionException{ "Unsupported Full Quads for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresMaximalReconvergence && writerConfig.shaderModel < hlsl::v6_7 )
			{
				throw UnsupportedExtensionException{ "Unsupported Maximal Reconvergence for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresControlBarrier
				&& writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
				&& writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported control barrier for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( writerConfig.shaderModel < hlsl::v5_0
				&& ( writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
					|| writerConfig.shaderStage == ast::ShaderStage::eTessellationEvaluation ) )
			{
				throw UnsupportedExtensionException{ "Unsupported Tessellation stage for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresDouble && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw UnsupportedExtensionException{ "Unsupported double type for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresInt8 )
			{
				throw UnsupportedExtensionException{ "Unsupported byte type for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresAtomicAddFloat )
			{
				throw UnsupportedExtensionException{ "Unsupported atomic add with floating point" };
			}

			if ( intrinsicsConfig.requiresInt16 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported short type for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresSInt64 )
			{
				throw UnsupportedExtensionException{ "Unsupported int64_t type" };
			}

			if ( intrinsicsConfig.requiresUInt64 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported uint64_t type for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresUAV && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw UnsupportedExtensionException{ "Unsupported UAV for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresInterpolate && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported interpolate for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresShadowOnTiled && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported sample shadow for tiled resource, for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresGather && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported gather, for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresSampledIndex && writerConfig.shaderModel < hlsl::v4_1 )
			{
				throw UnsupportedExtensionException{ "Unsupported SV_SampleIndex for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiresInterlockedOperations && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw UnsupportedExtensionException{ "Unsupported Interlocked operations for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
			}

			if ( intrinsicsConfig.requiredRaytracingTier > writerConfig.rayTracingTier )
			{
				throw UnsupportedExtensionException{ "Unsupported raytracing tier " + printRaytracingTier( intrinsicsConfig.requiredRaytracingTier ) };
			}

			if ( intrinsicsConfig.requiredRaytracingTier >= hlsl::t1_1
				&& writerConfig.shaderModel < hlsl::v6_5 )
			{
				throw UnsupportedExtensionException{ "Unsupported raytracing tier " + printRaytracingTier( intrinsicsConfig.requiredRaytracingTier ) + " for shader model " + printShaderModel( writerConfig.shaderModel, writerConfig.shaderStage ) };
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
