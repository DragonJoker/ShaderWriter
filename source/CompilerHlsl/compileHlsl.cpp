/*
See LICENSE file in root folder
*/
#include "CompilerHlsl/compileHlsl.hpp"

#include "HlslFillConfig.hpp"
#include "HlslGenerateStatements.hpp"
#include "HlslAdaptStatements.hpp"

#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SelectEntryPoint.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace hlsl
{
	namespace
	{
		void checkConfig( HlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig )
		{
			if ( isRayTraceStage( writerConfig.shaderStage ) && writerConfig.shaderModel < hlsl::v6_3 )
			{
				throw ast::Exception{ "Unsupported Ray Tracing stage for this shader model" };
			}

			if ( isMeshStage( writerConfig.shaderStage ) && writerConfig.shaderModel < hlsl::v6_5 )
			{
				throw ast::Exception{ "Unsupported Mesh/Amplification stage for this shader model" };
			}

			if ( intrinsicsConfig.requiresWaveOps && writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw ast::Exception{ "Unsupported Wave ops for this shader model" };
			}

			if ( intrinsicsConfig.requiresControlBarrier
				&& writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
				&& writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw ast::Exception{ "Unsupported control barrier for this shader model" };
			}

			if ( writerConfig.shaderModel < hlsl::v5_0
				&& ( writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
					|| writerConfig.shaderStage == ast::ShaderStage::eTessellationEvaluation ) )
			{
				throw ast::Exception{ "Unsupported Tessellation stage for this shader model" };
			}

			if ( intrinsicsConfig.requiresDouble && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw ast::Exception{ "Unsupported double type for this shader model" };
			}

			if ( intrinsicsConfig.requiresInt8 )
			{
				throw ast::Exception{ "Unsupported byte type for this shader model" };
			}

			if ( intrinsicsConfig.requiresAtomicAddFloat )
			{
				throw ast::Exception{ "Unsupported atomic add with floating point" };
			}

			if ( intrinsicsConfig.requiresInt16 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw ast::Exception{ "Unsupported short type for this shader model" };
			}

			if ( intrinsicsConfig.requiresSInt64 )
			{
				throw ast::Exception{ "Unsupported int64_t type" };
			}

			if ( intrinsicsConfig.requiresUInt64 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw ast::Exception{ "Unsupported uint64_t type for this shader model" };
			}

			if ( intrinsicsConfig.requiresUAV && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw ast::Exception{ "Unsupported UAV for this shader model" };
			}

			if ( intrinsicsConfig.requiresInterpolate && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw ast::Exception{ "Unsupported interpolate for this shader model" };
			}

			if ( intrinsicsConfig.requiresShadowOnTiled && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw ast::Exception{ "Unsupported sample shadow for tiled resource, for this shader model" };
			}

			if ( intrinsicsConfig.requiresGather && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw ast::Exception{ "Unsupported gather, for this shader model" };
			}

			if ( intrinsicsConfig.requiresSampledIndex && writerConfig.shaderModel < hlsl::v4_1 )
			{
				throw ast::Exception{ "Unsupported SV_SampleIndex for this shader model" };
			}
		}
	}

	std::string compileHlsl( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const * stmt
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig )
	{
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getVarId();
		auto & typesCache = shader.getTypesCache();
		auto config = writerConfig;
		config.shaderStage = stage;
		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
		auto statements = ast::transformSSA( compileStmtCache
			, compileExprCache
			, typesCache
			, *stmt
			, ssaData
			, false );
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, typesCache
			, *statements );
		statements = ast::resolveConstants( compileStmtCache
			, compileExprCache
			, *statements );
		HlslShader hlslShader{ shader, stage };
		AdaptationData adaptationData{ compileExprCache
			, hlslShader };
		adaptationData.aliasId = ssaData.aliasId;
		adaptationData.nextVarId = ssaData.nextVarId;
		auto intrinsicsConfig = hlsl::fillConfig( hlslShader
			, adaptationData
			, *statements );
		checkConfig( config, intrinsicsConfig );

		statements = hlsl::adaptStatements( compileStmtCache
			, compileExprCache
			, hlslShader
			, *statements
			, intrinsicsConfig
			, config
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
		std::map< ast::var::VariablePtr, ast::expr::Expr const * > aliases;
		return hlsl::generateStatements( config, adaptationData.getRoutines(), aliases, *statements );
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
