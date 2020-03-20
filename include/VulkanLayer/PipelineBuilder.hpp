/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_PipelineBuilder_H___
#define ___SDWVK_PipelineBuilder_H___

#include "BuilderContext.hpp"
#include "ProgramPipeline.hpp"

#include <map>

namespace ast::vk
{
	class PipelineBuilder
	{
	public:
		PipelineBuilder( BuilderContext context
			, ProgramPipeline program );
		/**
		*\return
		*	The descriptor layouts, created from the info in the program.
		*	\see ast::vk::ProgramPipeline::getDescriptorLayouts.
		*/
		DescriptorSetLayoutArray createDescriptorSetLayouts();
		/**
		*\return
		*	The pipeline layout, created from the info in the program.
		*	\see ast::vk::ProgramPipeline::getPipelineLayout.
		*\param[in] layouts
		*	The descriptor layouts, to fill the blanks.
		*/
		VkPipelineLayout createPipelineLayout( DescriptorSetLayoutArray const & layouts );
		/**
		*\return
		*	The shader modules, created from the info in the program.
		*	\see ast::vk::ProgramPipeline::getShaderModules.
		*/
		ShaderModuleArray createShaderModules();
		/**
		*\return
		*	Filled array of ast::vk:PipelineShaderStageCreateInfo.
		*	\see ast::vk::ProgramPipeline::getShaderStages.
		*\param[in] modules
		*	The modules, to fill the blanks.
		*\param[in] specializationInfo
		*	Either empty, or one per module.
		*/
		PipelineShaderStageArray createShaderStages( ShaderModuleArray modules
			, std::vector< VkSpecializationInfoOpt > const & specializationInfo )const;
		/**
		*\brief
		*	Effectively creates a graphics VkPipeline, from filled create infos.
		*\return
		*	\p VK_ERROR_VALIDATION_FAILED if the create info don't match the infos expected by the program.
		*	\see ast::vk::ProgramPipeline::checkGraphicsPipeline.
		*/
		VkResult createGraphicsPipeline( VkGraphicsPipelineCreateInfo createInfos
			, VkPipeline * result )const;
		/**
		*\brief
		*	Effectively creates a compute VkPipeline, from filled create infos.
		*\return
		*	\p VK_ERROR_VALIDATION_FAILED if the create info don't match the infos expected by the program.
		*	\see ast::vk::ProgramPipeline::checkComputePipeline.
		*/
		VkResult createComputePipeline( VkComputePipelineCreateInfo createInfos
			, VkPipeline * result )const;

	private:
		BuilderContext m_context;
		ProgramPipeline m_program;
	};
}

#endif
