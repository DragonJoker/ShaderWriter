/*
See LICENSE file in root folder
*/
#include "VulkanLayer/PipelineBuilder.hpp"

#include "VulkanLayer/ProgramPipeline.hpp"

#include <ShaderAST/Shader.hpp>

#include <CompilerSpirV/compileSpirV.hpp>

#include <iostream>
#include <optional>
#include <sstream>

namespace ast::vk
{
	//*********************************************************************************************

	PipelineBuilder::PipelineBuilder( BuilderContext context
		, ProgramPipeline program )
		: m_context{ std::move( context ) }
		, m_program{ std::move( program ) }
	{
	}

	DescriptorSetLayoutArray PipelineBuilder::createDescriptorSetLayouts()
	{
		DescriptorSetLayoutArray result;
		auto layouts = m_program.getDescriptorLayouts();

		for ( auto & createInfo : layouts )
		{
			VkDescriptorSetLayout layout;
			auto res = m_context.vkCreateDescriptorSetLayout( m_context.device
				, &createInfo
				, m_context.allocator
				, &layout );

			if ( !checkError( res ) )
			{
				throw std::runtime_error{ "VkDescriptorSetLayout creation failed." };
			}

			result.push_back( layout );
		}

		return result;
	}

	VkPipelineLayout PipelineBuilder::createPipelineLayout( DescriptorSetLayoutArray const & layouts )
	{
		VkPipelineLayout result{ VK_NULL_HANDLE };
		auto createInfo = m_program.getPipelineLayout( layouts );
		auto res = m_context.vkCreatePipelineLayout( m_context.device
			, &createInfo
			, m_context.allocator
			, &result );

		if ( !checkError( res ) )
		{
			throw std::runtime_error{ "VkPipelineLayout creation failed." };
		}

		return result;
	}

	ShaderModuleArray PipelineBuilder::createShaderModules()
	{
		ShaderModuleArray result;
		auto modules = m_program.getShaderModules();

		for ( auto & createInfo : modules )
		{
			VkShaderModule mod{ VK_NULL_HANDLE };
			auto res = m_context.vkCreateModule( m_context.device
				, &createInfo
				, m_context.allocator
				, &mod );

			if ( !checkError( res ) )
			{
				throw std::runtime_error{ "VkShaderModule creation failed." };
			}

			result.push_back( mod );
		}

		return result;
	}

	PipelineShaderStageArray PipelineBuilder::createShaderStages( ShaderModuleArray modules
		, std::vector< VkSpecializationInfoOpt > const & specializationInfo )const
	{
		return m_program.getShaderStages( modules, specializationInfo );
	}

	VkResult PipelineBuilder::createGraphicsPipeline( VkGraphicsPipelineCreateInfo createInfos
		, VkPipeline * result )const
	{
		if ( !m_program.checkGraphicsPipeline( createInfos ) )
		{
			return VK_ERROR_VALIDATION_FAILED_EXT;
		}

		auto err = m_context.vkCreateGraphicsPipeline( m_context.device
			, m_context.cache
			, 1u
			, &createInfos
			, m_context.allocator
			, result );
		checkError( err );
		return err;
	}

	VkResult PipelineBuilder::createComputePipeline( VkComputePipelineCreateInfo createInfos
		, VkPipeline * result )const
	{
		if ( !m_program.checkComputePipeline( createInfos ) )
		{
			return VK_ERROR_VALIDATION_FAILED_EXT;
		}

		auto err = m_context.vkCreateComputePipeline( m_context.device
			, m_context.cache
			, 1u
			, &createInfos
			, m_context.allocator
			, result );
		checkError( err );
		return err;
	}

	//*********************************************************************************************
}
