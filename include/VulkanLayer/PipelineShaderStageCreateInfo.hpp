/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_PipelineShaderStageCreateInfo_H___
#define ___SDWVK_PipelineShaderStageCreateInfo_H___

#include "ArrayHolder.hpp"

#include <map>

namespace ast::vk
{
	struct PipelineShaderStageCreateInfo
	{
		SpecializationInfoOpt spec;
		VkPipelineShaderStageCreateInfo data;

		inline PipelineShaderStageCreateInfo()
			: spec{ std::nullopt }
			, data{ get() }
		{
			updateData();
		}

		inline PipelineShaderStageCreateInfo( VkPipelineShaderStageCreateInfo rhs )
			: spec{ ( rhs.pSpecializationInfo
				? SpecializationInfoOpt{ SpecializationInfo{ *rhs.pSpecializationInfo } }
				: std::nullopt ) }
			, data{ std::move( rhs ) }
		{
			updateData();
		}

		inline PipelineShaderStageCreateInfo( VkPipelineShaderStageCreateFlags flags
			, VkShaderStageFlagBits stage
			, VkShaderModule module
			, SpecializationInfoOpt pspec )
			: spec{ std::move( pspec ) }
			, data{ get( flags, stage, module ) }
		{
			updateData();
		}

		inline PipelineShaderStageCreateInfo( PipelineShaderStageCreateInfo const & rhs )
			: spec{ rhs.spec }
			, data{ rhs.data }
		{
			updateData();
		}

		inline PipelineShaderStageCreateInfo( PipelineShaderStageCreateInfo && rhs )noexcept
			: spec{ std::move( rhs.spec ) }
			, data{ std::move( rhs.data ) }
		{
			rhs.data = get();
			updateData();
		}

		inline PipelineShaderStageCreateInfo & operator=( PipelineShaderStageCreateInfo const & rhs )
		{
			if ( rhs.spec )
			{
				spec = rhs.spec.value();
			}
			else
			{
				spec = std::nullopt;
			}

			data = rhs.data;
			updateData();
			return *this;
		}

		inline PipelineShaderStageCreateInfo & operator=( PipelineShaderStageCreateInfo && rhs )noexcept
		{
			if ( rhs.spec )
			{
				spec = std::move( rhs.spec.value() );
				rhs.spec = std::nullopt;
			}
			else
			{
				spec = std::nullopt;
			}

			data = std::move( rhs.data );
			rhs.data = get();
			updateData();
			return *this;
		}

		inline VkPipelineShaderStageCreateInfo * operator->()
		{
			return &data;
		}

		inline VkPipelineShaderStageCreateInfo const * operator->()const
		{
			return &data;
		}

		inline VkPipelineShaderStageCreateInfo & operator*()
		{
			return data;
		}

		inline VkPipelineShaderStageCreateInfo const & operator*()const
		{
			return data;
		}

		static inline VkPipelineShaderStageCreateInfo get( VkPipelineShaderStageCreateFlags flags = 0u
			, VkShaderStageFlagBits stage = VkShaderStageFlagBits::VK_SHADER_STAGE_ALL
			, VkShaderModule module = nullptr )
		{
			return VkPipelineShaderStageCreateInfo
			{
				VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
				nullptr,
				flags,
				stage,
				module,
				"main",
				nullptr,
			};
		}

	private:
		inline void updateData()
		{
			if ( spec )
			{
				data.pSpecializationInfo = &spec.value().data;
			}
			else
			{
				data.pSpecializationInfo = nullptr;
			}
		}
	};
}

#endif
