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
			uint32_t count;
			ShaderStageFlags stages;
		};
		using DescriptorMap = std::map< DescriptorBinding, DescriptorData >;
		using DescriptorsMap = std::vector< DescriptorMap >;
		using SsboMap = std::map< DescriptorBinding, SsboInfo const * >;
		using UboMap = std::map< DescriptorBinding, UboInfo const * >;
		using PcbMap = std::vector< PcbInfo const * >;
		using SamplerMap = std::map< DescriptorBinding, SamplerInfo const * >;
		using TextureMap = std::map< DescriptorBinding, TextureInfo const * >;
		using ImageMap = std::map< DescriptorBinding, ImageInfo const * >;
		using SpecConstantsMap = std::map< AttributeInfo, SpecConstantInfo const * >;
		using InputMap = std::map< AttributeInfo, InputInfo const * >;
		using OutputMap = std::map< AttributeInfo, OutputInfo const * >;
		using InOutMap = std::map< InOutInfo, InOutInfo const * >;

		ShaderDataPtr( ShaderData const & rhs
			, EntryPoint entryPoint
			, ShaderStageFlags stages );

		void merge( ShaderDataPtr const & rhs );

		SsboMap ssbos;
		UboMap ubos;
		SamplerMap samplers;
		TextureMap textures;
		TextureMap uniformTexels;
		ImageMap images;
		ImageMap storageTexels;
		DescriptorsMap descriptors;
		PcbMap pcbs;
		SpecConstantsMap specConstants;
		InputMap inputs;
		OutputMap outputs;
		InOutMap inOuts;
		AccStructInfo const * accelerationStruct;
		uint32_t tessellationControlPoints{};

	private:
		DescriptorsMap gatherDescriptors( ShaderStageFlags stages )const;
	};
}

#endif
