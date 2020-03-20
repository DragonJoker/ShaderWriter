/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_ProgramPipeline_H___
#define ___SDWVK_ProgramPipeline_H___

#include "ArrayHolder.hpp"
#include "PipelineShaderStageCreateInfo.hpp"
#include "ShaderDataPtr.hpp"

#include <array>

namespace ast::vk
{
	class ProgramPipeline
	{
	public:
		ProgramPipeline( ShaderArray const & shaders );
		ProgramPipeline( Shader const & shader );
		/**
		*\return
		*	Pre-filled array of ast::vk:SpecializationInfo.
		*\remarks
		*	The \p offset member of each VkSpecializationMapEntry in each non nullopt VkSpecializationInfo must be set by the client.
		*	The \p pData member of each non nullopt VkSpecializationInfo must be filled by the client.
		*	\see ast::vk::SpecializationInfo.
		*/
		std::vector< SpecializationInfoOpt > getSpecializationInfos()const;
		/**
		*\return
		*	Pre-filled array of ast::vk:PipelineShaderStageCreateInfo.
		*\remarks
		*	The \p module member of each VkPipelineShaderStageCreateInfo must be set by the client.
		*	For informations about VkSpecializationInfo, \see ast::vk::ProgramPipeline::getSpecializationInfos.
		*	\see ast::vk::PipelineShaderStageCreateInfo.
		*/
		std::vector< PipelineShaderStageCreateInfo > getShaderStages()const;
		/**
		*\return
		*	Pre-filled array of WriteDescriptorSet for given descriptor set.
		*\param[in] setIndex
		*	The descriptor set index.
		*\remarks
		*	The \p descriptorCount member of each VkWriteDescriptorSet is set with the appropriate count of descriptors.
		*	The \p descriptorType member of each VkWriteDescriptorSet is set with the appropriate type of descriptors.
		*	The \p dstBinding member of each VkWriteDescriptorSet is set with the appropriate descriptor set binding.
		*	The \p imageLayout member of each VkDescriptorImageInfo will be filled with expected layout.
		*	The \p range member of each VkDescriptorBufferInfo will be filled with the expected size of the buffer.
		*	Other members of the appropriate descriptor infos (VkDescriptorImageInfo, VkDescriptorBufferInfo, or VkBufferView)
		*	must be filled by the client (they're initialised with the appropriate size, which is in \p descriptorCount).
		*	\see ast::vk::WriteDescriptorSet, and \see ast::vk::WriteDescriptorType.
		*/
		std::vector< WriteDescriptorSet > getDescriptorSetWrites( uint32_t setIndex )const;
		/**
		*\return
		*	Pre-filled array of VkVertexInputAttributeDescription.
		*\remarks
		*	The \p binding member of each VkVertexInputAttributeDescription must be set by the client.
		*	The \p offset member of each VkVertexInputAttributeDescription must be set by the client.
		*/
		std::vector< VkVertexInputAttributeDescription > getVertexAttributes()const;
		/**
		*\return
		*	Pre-filled map of VkAttachmentDescription.
		*	The map's key is the shader location of the attachment (for the subpass).
		*\remarks
		*	The only filled member is the \p format member, all others must be set by the client.
		*/
		std::map< uint32_t, VkAttachmentDescription > getAttachmentDescriptions()const;
		/**
		*\return
		*	Filled array of VkShaderModuleCreateInfo (all memory held by ProgramPipeline).
		*/
		std::vector< VkShaderModuleCreateInfo > getShaderModules()const;
		/**
		*\return
		*	Filled array of VkDescriptorSetLayoutCreateInfo (all memory held by ProgramPipeline).
		*/
		std::vector< VkDescriptorSetLayoutCreateInfo > getDescriptorLayouts()const;
		/**
		*\return
		*	Filled array of VkDescriptorPoolSize.
		*\param[in] maxSets
		*	Multiplicator applied to all base counts.
		*/
		std::vector< VkDescriptorPoolSize > getDescriptorPoolSizes( uint32_t maxSets )const;
		/**
		*\return
		*	Filled array of VkPushConstantRange.
		*/
		std::vector< VkPushConstantRange > const & getPushConstantRange()const;
		/**
		*\return
		*	Filled VkPipelineLayoutCreateInfo.
		*\param[in] layouts
		*	The descriptor set layouts used to complete the pipeline layout create info.
		*/
		VkPipelineLayoutCreateInfo getPipelineLayout( std::vector< VkDescriptorSetLayout > const & layouts )const;
		/**
		*\return
		*	Filled array of ast::vk:PipelineShaderStageCreateInfo.
		*\param[in] modules
		*	One per shader initially provided.
		*\param[in] specializationInfo
		*	Either empty, or one per module in \p modules.
		*/
		std::vector< PipelineShaderStageCreateInfo > getShaderStages( ShaderModuleArray modules
			, std::vector< VkSpecializationInfoOpt > const & specializationInfo )const;
		/**
		*\return
		*	\p true if the given create infos match the expectations for this ProgramPipeline.
		*/
		bool checkGraphicsPipeline( VkGraphicsPipelineCreateInfo & createInfos )const;
		/**
		*\return
		*	\p true if the given create infos match the expectations for this ProgramPipeline.
		*/
		bool checkComputePipeline( VkComputePipelineCreateInfo & createInfos )const;
		/**
		*\return
		*	The VkShaderStageFlagBits combination describing all stages used by this program.
		*/
		inline VkShaderStageFlags getStageFlags()const
		{
			return m_stageFlags;
		}
		/**
		*\return
		*	The count of shader stages.
		*/
		inline uint32_t getStageCount()const
		{
			return uint32_t( m_stages.size() );
		}

	private:
		std::vector< uint32_t > createShaderSource( Shader const & shader );
		std::vector< std::vector< uint32_t > > createShaderSources( ShaderArray const & shaders );
		SpecializationInfoOpt createSpecializationInfo( Shader const & shader );
		std::vector< SpecializationInfoOpt > createSpecializationInfos( ShaderArray const & shaders );
		PipelineShaderStageCreateInfo createShaderStage( Shader const & shader );
		std::vector< PipelineShaderStageCreateInfo > createShaderStages( ShaderArray const & shaders );
		ShaderDataPtr createShaderData( Shader const & shader );
		ShaderDataPtr createShaderData( ShaderArray const & shaders );
		ShaderModuleCreateInfo createShaderModule( Shader const & shader );
		std::vector< ShaderModuleCreateInfo > createShaderModules( ShaderArray const & shaders );
		std::vector< VkPushConstantRange > createPushConstantRanges( Shader const & shader );
		std::vector< VkPushConstantRange > createPushConstantRanges( ShaderArray const & shaders );
		std::vector< DescriptorSetLayoutCreateInfo > createDescriptorLayouts();
		std::vector< VkDescriptorPoolSize > createDescriptorPoolSizes();
		std::vector< WriteDescriptorSetArray > createDescriptorSetsWrites();
		VkPipelineLayoutCreateInfo createPipelineLayout();
		std::vector< VkVertexInputAttributeDescription > createVertexAttributes();
		std::map< uint32_t, VkAttachmentDescription > createAttachmentDescriptions();
		bool checkTessellationState( VkPipelineTessellationStateCreateInfo const & state )const;
		bool checkVertexInputState( VkPipelineVertexInputStateCreateInfo const & state )const;
		bool checkSpecializationInfos( std::vector< VkSpecializationInfoOpt > const & infos )const;

	private:
		VkShaderStageFlags m_stageFlags{ 0u };
		std::map< ShaderStage, uint32_t > m_indices;
		std::map< uint32_t, ShaderStage > m_revIndices;
		std::vector< std::vector< uint32_t > > m_sources;
		std::vector< SpecializationInfoOpt > m_specializationInfos;
		std::vector< PipelineShaderStageCreateInfo > m_stages;
		ShaderDataPtr m_data;
		std::vector< ShaderModuleCreateInfo > m_shaderModules;
		std::vector< VkPushConstantRange > m_pushConstantRanges;
		std::vector< DescriptorSetLayoutCreateInfo > m_descriptorLayouts;
		std::vector< VkDescriptorPoolSize > m_descriptorPoolSizes;
		std::vector< WriteDescriptorSetArray > m_descriptorSetsWrites;
		VkPipelineLayoutCreateInfo m_pipelineLayout{};
		std::vector< VkVertexInputAttributeDescription > m_vertexAttributes;
		std::map< uint32_t, VkAttachmentDescription > m_attachmentDescriptions;
	};
}

#endif
