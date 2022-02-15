/*
See LICENSE file in root folder
*/
#include "VulkanLayer/PipelineBuilder.hpp"

#include "VulkanLayer/ProgramPipeline.hpp"

#include <ShaderAST/Shader.hpp>

#include <CompilerSpirV/compileSpirV.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <iostream>
#pragma warning( pop )
#include <optional>
#include <sstream>

#if defined( WIN32 )
#	include <Windows.h>
#endif

namespace ast::vk
{
	//*********************************************************************************************

	PipelineBuilder::PipelineBuilder( BuilderContext context
		, ProgramPipeline program )
		: m_context{ std::move( context ) }
		, m_program{ std::move( program ) }
	{
	}

	VkDescriptorSetLayoutArray PipelineBuilder::createDescriptorSetLayouts()
	{
		VkDescriptorSetLayoutArray result;
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

	VkPipelineLayout PipelineBuilder::createPipelineLayout( VkDescriptorSetLayoutArray const & layouts )
	{
		VkPipelineLayout result{ nullptr };
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

	VkShaderModuleArray PipelineBuilder::createShaderModules()
	{
		VkShaderModuleArray result;
		auto modules = m_program.getShaderModules();

		for ( auto & createInfo : modules )
		{
			VkShaderModule mod{ nullptr };
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

	PipelineShaderStageArray PipelineBuilder::createShaderStages( VkShaderModuleArray modules
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

#	if defined( WIN32 )
		__try
		{
#	endif
			auto err = m_context.vkCreateGraphicsPipeline( m_context.device
				, m_context.cache
				, 1u
				, &createInfos
				, m_context.allocator
				, result );
			checkError( err );
			return err;
#	if defined( WIN32 )
		}
		__except ( GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION )
		{
			return VK_ERROR_INITIALIZATION_FAILED;
		}
#	endif
	}

	VkResult PipelineBuilder::createComputePipeline( VkComputePipelineCreateInfo createInfos
		, VkPipeline * result )const
	{
		if ( !m_program.checkComputePipeline( createInfos ) )
		{
			return VK_ERROR_VALIDATION_FAILED_EXT;
		}

#	if defined( WIN32 )
		__try
		{
#	endif
			auto err = m_context.vkCreateComputePipeline( m_context.device
				, m_context.cache
				, 1u
				, &createInfos
				, m_context.allocator
				, result );
			checkError( err );
			return err;
#	if defined( WIN32 )
		}
		__except ( GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION )
		{
			return VK_ERROR_INITIALIZATION_FAILED;
		}
#	endif
	}

	//*********************************************************************************************
}
