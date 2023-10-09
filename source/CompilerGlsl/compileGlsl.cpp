/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslAdaptStatements.hpp"
#include "GlslFillConfig.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
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

			if ( writerConfig.wantedVersion >= ARB_shading_language_420pack.coreVersion )
			{
				writerConfig.availableExtensions.insert( ARB_shading_language_420pack );
			}

			if ( writerConfig.wantedVersion >= KHR_vulkan_glsl.specVersion
				&& writerConfig.vulkanGlsl )
			{
				writerConfig.availableExtensions.insert( KHR_vulkan_glsl );
				intrinsicsConfig.requiredExtensions.insert( KHR_vulkan_glsl );
			}

			if ( intrinsicsConfig.requiresInt8 )
			{
				if ( writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( NV_gpu_shader5 ) )
				{
					intrinsicsConfig.requiredExtensions.insert( NV_gpu_shader5 );
				}
				else if ( writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( EXT_shader_explicit_arithmetic_types_int8 ) )
				{
					intrinsicsConfig.requiredExtensions.insert( EXT_shader_explicit_arithmetic_types_int8 );
				}
				else
				{
					throw std::runtime_error{ "int8_t and uint8_t need either of [" + EXT_shader_explicit_arithmetic_types_int8.name
						+ "] or [" + NV_gpu_shader5.name + "]" };
				}
			}

			if ( intrinsicsConfig.requiresInt16 )
			{
				if ( writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( NV_gpu_shader5 ) )
				{
					intrinsicsConfig.requiredExtensions.insert( NV_gpu_shader5 );
				}
				else if ( writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( EXT_shader_explicit_arithmetic_types_int16 ) )
				{
					intrinsicsConfig.requiredExtensions.insert( EXT_shader_explicit_arithmetic_types_int16 );
				}
				else
				{
					throw std::runtime_error{ "int16_t and uint16_t need either of [" + EXT_shader_explicit_arithmetic_types_int16.name
						+ "] or [" + NV_gpu_shader5.name + "]" };
				}
			}

			if ( intrinsicsConfig.requiresInt64 )
			{
				if ( writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( ARB_gpu_shader_int64 ) )
				{
					intrinsicsConfig.requiredExtensions.insert( ARB_gpu_shader_int64 );
				}
				else if ( writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( NV_gpu_shader5 ) )
				{
					intrinsicsConfig.requiredExtensions.insert( NV_gpu_shader5 );
				}
				else if ( writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( EXT_shader_explicit_arithmetic_types_int64 ) )
				{
					intrinsicsConfig.requiredExtensions.insert( EXT_shader_explicit_arithmetic_types_int64 );
				}
				else
				{
					throw std::runtime_error{ "int64_t and uint64_t need either of [" + EXT_shader_explicit_arithmetic_types_int16.name
						+ "] or [" + ARB_gpu_shader_int64.name + "]"
						+ "] or [" + NV_gpu_shader5.name };
				}
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
		, GlslConfig & config )
	{
		config.shaderStage = shader.getType();
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto intrinsics = glsl::fillConfig( shader.getType()
			, shader.getStatements() );
		checkConfig( config, intrinsics );

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
		return glsl::generateGlslStatements( config, statements.get() ).source;
	}
}
