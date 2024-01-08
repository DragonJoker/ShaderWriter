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

		PipelineShaderStageCreateInfo()
			: spec{ std::nullopt }
			, data{ get() }
		{
			updateData();
		}

		explicit PipelineShaderStageCreateInfo( VkPipelineShaderStageCreateInfo rhs )
			: spec{ ( rhs.pSpecializationInfo
				? SpecializationInfoOpt{ SpecializationInfo{ *rhs.pSpecializationInfo } }
				: std::nullopt ) }
			, data{ std::move( rhs ) }
		{
			updateData();
		}

		PipelineShaderStageCreateInfo( VkPipelineShaderStageCreateFlags flags
			, VkShaderStageFlagBits stage
			, VkShaderModule shaderModule
			, SpecializationInfoOpt pspec )
			: spec{ std::move( pspec ) }
			, data{ get( flags, stage, shaderModule ) }
		{
			updateData();
		}

		PipelineShaderStageCreateInfo( PipelineShaderStageCreateInfo const & rhs )
			: spec{ rhs.spec }
			, data{ rhs.data }
		{
			updateData();
		}

		PipelineShaderStageCreateInfo( PipelineShaderStageCreateInfo && rhs )noexcept
			: spec{ std::move( rhs.spec ) }
			, data{ std::move( rhs.data ) }
		{
			rhs.data = get();
			updateData();
		}

		PipelineShaderStageCreateInfo & operator=( PipelineShaderStageCreateInfo const & rhs )
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

		PipelineShaderStageCreateInfo & operator=( PipelineShaderStageCreateInfo && rhs )noexcept
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

		~PipelineShaderStageCreateInfo() = default;

		VkPipelineShaderStageCreateInfo * operator->()
		{
			return &data;
		}

		VkPipelineShaderStageCreateInfo const * operator->()const
		{
			return &data;
		}

		VkPipelineShaderStageCreateInfo & operator*()
		{
			return data;
		}

		VkPipelineShaderStageCreateInfo const & operator*()const
		{
			return data;
		}

		static VkPipelineShaderStageCreateInfo get( VkPipelineShaderStageCreateFlags flags = 0u
			, VkShaderStageFlagBits stage = VkShaderStageFlagBits::VK_SHADER_STAGE_ALL
			, VkShaderModule shaderModule = nullptr )
		{
			return VkPipelineShaderStageCreateInfo
			{
				VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
				nullptr,
				flags,
				stage,
				shaderModule,
				"main",
				nullptr,
			};
		}

	private:
		void updateData()
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
