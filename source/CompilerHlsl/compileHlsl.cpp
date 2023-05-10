/*
See LICENSE file in root folder
*/
#include "CompilerHlsl/compileHlsl.hpp"

#include "HlslStmtAdapter.hpp"
#include "HlslStmtConfigFiller.hpp"
#include "HlslStmtVisitor.hpp"

#include <ShaderAST/Visitors/StmtSpecialiser.hpp>
#include <ShaderAST/Visitors/StmtSimplifier.hpp>
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
				throw std::runtime_error{ "Unsupported Ray Tracing stage for this shader model" };
			}

			if ( isMeshStage( writerConfig.shaderStage ) && writerConfig.shaderModel < hlsl::v6_5 )
			{
				throw std::runtime_error{ "Unsupported Mesh/Amplification stage for this shader model" };
			}

			if ( intrinsicsConfig.requiresWaveOps && writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw std::runtime_error{ "Unsupported Wave ops for this shader model" };
			}

			if ( intrinsicsConfig.requiresControlBarrier
				&& writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
				&& writerConfig.shaderModel < hlsl::v6_0 )
			{
				throw std::runtime_error{ "Unsupported control barrier for this shader model" };
			}

			if ( writerConfig.shaderModel < hlsl::v5_0
				&& ( writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
					|| writerConfig.shaderStage == ast::ShaderStage::eTessellationEvaluation ) )
			{
				throw std::runtime_error{ "Unsupported Tessellation stage for this shader model" };
			}

			if ( intrinsicsConfig.requiresDouble && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw std::runtime_error{ "Unsupported double type for this shader model" };
			}

			if ( intrinsicsConfig.requiresInt8 )
			{
				throw std::runtime_error{ "Unsupported byte type for this shader model" };
			}

			if ( intrinsicsConfig.requiresInt16 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw std::runtime_error{ "Unsupported short type for this shader model" };
			}

			if ( intrinsicsConfig.requiresSInt64 )
			{
				throw std::runtime_error{ "Unsupported int64_t type" };
			}

			if ( intrinsicsConfig.requiresUInt64 && writerConfig.shaderModel <= hlsl::v6_0 )
			{
				throw std::runtime_error{ "Unsupported uint64_t type for this shader model" };
			}

			if ( intrinsicsConfig.requiresUAV && writerConfig.shaderModel <= hlsl::v4_1 )
			{
				throw std::runtime_error{ "Unsupported UAV for this shader model" };
			}

			if ( intrinsicsConfig.requiresInterpolate && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw std::runtime_error{ "Unsupported interpolate for this shader model" };
			}

			if ( intrinsicsConfig.requiresShadowOnTiled && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw std::runtime_error{ "Unsupported sample shadow for tiled resource, for this shader model" };
			}

			if ( intrinsicsConfig.requiresGather && writerConfig.shaderModel < hlsl::v5_0 )
			{
				throw std::runtime_error{ "Unsupported gather, for this shader model" };
			}

			if ( intrinsicsConfig.requiresSampledIndex && writerConfig.shaderModel < hlsl::v4_1 )
			{
				throw std::runtime_error{ "Unsupported SV_SampleIndex for this shader model" };
			}
		}
	}

	std::string compileHlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig )
	{
		auto config = writerConfig;
		config.shaderStage = shader.getType();
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto statements = ast::transformSSA( shader.getTypesCache()
			, shader.getStatements()
			, ssaData );
		statements = ast::simplify( shader.getTypesCache()
			, statements.get() );
		HlslShader hlslShader{ shader };
		AdaptationData adaptationData{ hlslShader };
		adaptationData.aliasId = ssaData.aliasId;
		adaptationData.nextVarId = ssaData.nextVarId;
		auto intrinsicsConfig = hlsl::StmtConfigFiller::submit( hlslShader
			, adaptationData
			, statements.get() );
		checkConfig( config, intrinsicsConfig );

		statements = hlsl::StmtAdapter::submit( hlslShader
			, statements.get()
			, intrinsicsConfig
			, config
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::simplify( shader.getTypesCache()
			, statements.get() );
		statements = ast::StmtSpecialiser::submit( shader.getTypesCache()
			, statements.get()
			, specialisation );
		std::map< ast::var::VariablePtr, ast::expr::Expr * > aliases;
		return hlsl::StmtVisitor::submit( config, adaptationData.getRoutines(), aliases, statements.get() );
	}
}
