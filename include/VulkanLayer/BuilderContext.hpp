/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_BuilderContext_H___
#define ___SDWVK_BuilderContext_H___

#include "VulkanLayer.hpp"

namespace ast::vk
{
	struct BuilderContext
	{
		VkDevice device{ VK_NULL_HANDLE };
		VkPipelineCache cache{ VK_NULL_HANDLE };
		VkAllocationCallbacks const * allocator{ nullptr };
		PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipeline{ nullptr };
		PFN_vkCreateComputePipelines vkCreateComputePipeline{ nullptr };
		PFN_vkCreateShaderModule vkCreateModule{ nullptr };
		PFN_vkCreatePipelineLayout vkCreatePipelineLayout{ nullptr };
		PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout{ nullptr };
	};
}

#endif
