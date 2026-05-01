/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_ShaderDataPtr_H___
#define ___SDWVK_ShaderDataPtr_H___

#include "ShaderStageFlag.hpp"

#include <ShaderAST/Shader.hpp>

#include <map>
#include <vector>

namespace test::vk
{
	struct ShaderDataPtr
	{
		struct DescriptorData
		{
			ast::DescriptorType type;
			uint32_t count;
			ShaderStageFlags stages;
		};
		using DescriptorMap = std::map< ast::DescriptorBinding, DescriptorData >;
		using DescriptorsMap = std::vector< DescriptorMap >;
		using SsboMap = std::map< ast::DescriptorBinding, ast::SsboInfo const * >;
		using UboMap = std::map< ast::DescriptorBinding, ast::UboInfo const * >;
		using PcbMap = std::vector< ast::PcbInfo const * >;
		using SamplerMap = std::map< ast::DescriptorBinding, ast::SamplerInfo const * >;
		using TextureMap = std::map< ast::DescriptorBinding, ast::TextureInfo const * >;
		using ImageMap = std::map< ast::DescriptorBinding, ast::ImageInfo const * >;
		using SpecConstantsMap = std::map< ast::AttributeInfo, ast::SpecConstantInfo const * >;
		using InputMap = std::map< ast::AttributeInfo, ast::InputInfo const * >;
		using OutputMap = std::map< ast::AttributeInfo, ast::OutputInfo const * >;
		using InOutMap = std::map< ast::InOutInfo, ast::InOutInfo const * >;

		ShaderDataPtr( ast::ShaderData::SsboMap const & ssbos
			, ast::ShaderData::UboMap const & ubos
			, ast::ShaderData::PcbMap const & ppcbs
			, ast::ShaderData::SamplerMap const & psamplers
			, ast::ShaderData::TextureMap const & ptextures
			, ast::ShaderData::TextureMap const & puniformTexels
			, ast::ShaderData::ImageMap const & pimages
			, ast::ShaderData::ImageMap const & pstorageTexels
			, ast::ShaderData::AllInputsMap const & pinputs
			, ast::ShaderData::AllOutputsMap const & poutputs
			, ast::ShaderData::InOutMap const & pinOuts
			, ast::AccStructInfo const & paccelerationStruct
			, uint32_t tessellationControlPoints
			, ast::EntryPoint entryPoint
			, ShaderStageFlags stages );

		void merge( ShaderDataPtr const & rhs );

		SsboMap ssbos;
		UboMap ubos;
		SamplerMap samplers;
		TextureMap textures;
		TextureMap uniformTexels;
		ImageMap images;
		ImageMap storageTexels;
		ast::AccStructInfo const * accelerationStruct{};
		DescriptorsMap descriptors;
		PcbMap pcbs;
		SpecConstantsMap specConstants;
		InputMap inputs;
		OutputMap outputs;
		InOutMap inOuts;
		uint32_t tessellationControlPoints{};

	private:
		DescriptorsMap gatherDescriptors( ShaderStageFlags stages )const;
	};
}

#endif
