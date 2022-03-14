/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslStmtAdapter.hpp"
#include "GlslStmtConfigFiller.hpp"
#include "GlslStmtVisitor.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/StmtSpecialiser.hpp>
#include <ShaderAST/Visitors/StmtSimplifier.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace glsl
{
	namespace
	{
		void checkConfig( GlslConfig & writerConfig
			, IntrinsicsConfig & intrinsicsConfig )
		{
			if ( writerConfig.wantedVersion >= v4_6 )
			{
				writerConfig.availableExtensions.insert( KHR_vulkan_glsl );
				intrinsicsConfig.requiredExtensions.insert( KHR_vulkan_glsl );
			}

			if ( intrinsicsConfig.requiresSeparateSamplers )
			{
				if ( ( !writerConfig.vulkanGlsl )
					|| writerConfig.availableExtensions.end() == writerConfig.availableExtensions.find( KHR_vulkan_glsl ) )
				{
					throw std::runtime_error{ "Separate Samplers are only supported with extension [" + KHR_vulkan_glsl.name + "] which is not available" };
				}

				writerConfig.requiredExtensions.insert( EXT_separate_samplers );
				writerConfig.availableExtensions.insert( EXT_separate_samplers );
			}

			if ( writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
				|| writerConfig.shaderStage == ast::ShaderStage::eTessellationEvaluation )
			{
				intrinsicsConfig.requiredExtensions.insert( ARB_tessellation_shader );
			}

			if ( writerConfig.wantedVersion >= ARB_explicit_attrib_location.specVersion )
			{
				writerConfig.availableExtensions.insert( ARB_explicit_attrib_location );
				intrinsicsConfig.requiredExtensions.insert( ARB_explicit_attrib_location );
			}

			if ( writerConfig.wantedVersion >= ARB_explicit_uniform_location.specVersion )
			{
				writerConfig.availableExtensions.insert( ARB_explicit_uniform_location );
				intrinsicsConfig.requiredExtensions.insert( ARB_explicit_uniform_location );
			}

			if ( writerConfig.wantedVersion >= ARB_separate_shader_objects.specVersion )
			{
				writerConfig.availableExtensions.insert( ARB_separate_shader_objects );
				intrinsicsConfig.requiredExtensions.insert( ARB_separate_shader_objects );
			}

			if ( intrinsicsConfig.requiresBlendIndex
				&& ( writerConfig.wantedVersion < v4_3
					|| ( writerConfig.availableExtensions.end() == writerConfig.availableExtensions.find( ARB_explicit_attrib_location )
						&& writerConfig.availableExtensions.end() == writerConfig.availableExtensions.find( ARB_separate_shader_objects ) ) ) )
			{
				throw std::runtime_error{ "GLSL specification version (" + writeValue( writerConfig.wantedVersion )
					+ ") doesn't support blend index attributes (required version: " + writeValue( v4_3 ) +
					+" or extension [" + ARB_explicit_attrib_location.name + "])" };
			}

			if ( writerConfig.wantedVersion >= ARB_shading_language_420pack.specVersion )
			{
				writerConfig.availableExtensions.insert( ARB_shading_language_420pack );
				intrinsicsConfig.requiredExtensions.insert( ARB_shading_language_420pack );
			}

			if ( writerConfig.wantedVersion >= KHR_vulkan_glsl.specVersion
				&& writerConfig.vulkanGlsl )
			{
				writerConfig.availableExtensions.insert( KHR_vulkan_glsl );
				intrinsicsConfig.requiredExtensions.insert( KHR_vulkan_glsl );
			}

			for ( auto & extension : intrinsicsConfig.requiredExtensions )
			{
				if ( extension.reqVersion > writerConfig.wantedVersion )
				{
					throw std::runtime_error{ "GLSL specification version (" + writeValue( writerConfig.wantedVersion )
						+ ") doesn't support extension [" + extension.name
						+ "] (required version: " + writeValue( extension.reqVersion ) + ")" };
				}
			}
		}
	}

	std::string compileGlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & writerConfig )
	{
		writerConfig.shaderStage = shader.getType();
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto intrinsics = glsl::StmtConfigFiller::submit( shader.getType()
			, shader.getStatements() );
		checkConfig( writerConfig, intrinsics );

		auto statements = ast::transformSSA( shader.getTypesCache()
			, shader.getStatements()
			, ssaData );
		statements = ast::StmtSimplifier::submit( shader.getTypesCache()
			, statements.get() );
		glsl::AdaptationData adaptationData{ shader.getType()
			, writerConfig
			, std::move( intrinsics )
			, ssaData.nextVarId };
		statements = glsl::StmtAdapter::submit( shader.getTypesCache()
			, statements.get()
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::StmtSimplifier::submit( shader.getTypesCache()
			, statements.get() );
		statements = ast::StmtSpecialiser::submit( shader.getTypesCache(), statements.get(), specialisation );
		std::map< ast::var::VariablePtr, ast::expr::Expr * > aliases;
		return glsl::StmtVisitor::submit( writerConfig, aliases, statements.get() );
	}
}
