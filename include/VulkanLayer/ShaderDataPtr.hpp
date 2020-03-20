/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_ShaderDataPtr_H___
#define ___SDWVK_ShaderDataPtr_H___

#include "ShaderStageFlag.hpp"

#include <ShaderAST/Shader.hpp>

#include <map>
#include <vector>

namespace ast::vk
{
	struct ShaderDataPtr
	{
		struct DescriptorData
		{
			DescriptorType type;
			ShaderStageFlags stages;
		};
		using DescriptorMap = std::map< DescriptorBinding, DescriptorData >;
		using DescriptorsMap = std::vector< DescriptorMap >;
		using SsboMap = std::map< DescriptorBinding, SsboInfo const * >;
		using UboMap = std::map< DescriptorBinding, UboInfo const * >;
		using PcbMap = std::vector< PcbInfo const * >;
		using SamplerMap = std::map< DescriptorBinding, SamplerInfo const * >;
		using ImageMap = std::map< DescriptorBinding, ImageInfo const * >;
		using SpecConstantsMap = std::map< AttributeInfo, SpecConstantInfo const * >;
		using InputMap = std::map< AttributeInfo, InputInfo const * >;
		using OutputMap = std::map< AttributeInfo, OutputInfo const * >;

		ShaderDataPtr( ShaderData const & rhs
			, ShaderStageFlags stages );

		void merge( ShaderDataPtr const & rhs );

		SsboMap ssbos;
		UboMap ubos;
		SamplerMap samplers;
		ImageMap images;
		DescriptorsMap descriptors;
		PcbMap pcbs;
		SpecConstantsMap specConstants;
		InputMap inputs;
		OutputMap outputs;

	private:
		DescriptorsMap gatherDescriptors( ShaderStageFlags stages );
	};
}

#endif
