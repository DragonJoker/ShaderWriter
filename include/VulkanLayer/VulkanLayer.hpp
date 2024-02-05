/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_VulkanLayer_H___
#define ___SDWVK_VulkanLayer_H___

#define VK_NO_PROTOYPES
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <vulkan/vulkan.h>
#pragma GCC diagnostic pop

#include <ShaderAST/ShaderASTPrerequisites.hpp>

#pragma warning( push )
#pragma warning( disable: 5262 )
#include <map>
#include <optional>
#include <variant>
#include <vector>
#pragma warning( pop )

namespace ast::vk
{
	/**
	*\brief
	*	Fixed size std::vector wrapper.
	*\remarks
	*	Copiable and movable.
	*/
	template< typename ValueT >
	struct FixedSizeArrayT;
	/**
	*\brief
	*	Holds the memory for an array in a Vulkan structure.
	*	This memory is held by \p values member, which is a fixed size array.
	*\remarks
	*	Copiable and movable.
	*\tparam DataT
	*	The Vulkan structure
	*\tparam ValueT
	*	The array value type.
	*\tparam CountT
	*	The array count value type.
	*\tparam DataOffsetT
	*	The binary offset to the member array pointer, in the Vulkan structure.
	*\tparam CountOffsetT
	*	The binary offset to the member array count, in the Vulkan structure.
	*\tparam DivisorT
	*	The divisor to apply to the count, to obtain the real size of the array.
	*/
	template< typename DataT
		, typename ValueT
		, typename CountT
		, size_t DataOffsetT
		, size_t CountOffsetT
		, size_t DivisorT = 1u >
	struct ArrayHolder;
	/**
	*\brief
	*	Holds pointers to the ast::ShaderDatas' attributes, descriptors and all.
	*	The only member from ast::ShaderData that is not pointed to is \p constants.
	*/
	struct ShaderDataPtr;
	/**
	*\brief
	*	Context of device, pipeline cache, allocation callbacks,
	*	and the necessary set of functions to be able to create a pipeline.
	*/
	struct BuilderContext;
	/**
	*\brief
	*	Wrapper to a VkPipelineShaderStageCreateInfo, owning its memory.
	*\remarks
	*	Copiable and movable.
	*/
	struct PipelineShaderStageCreateInfo;
	/**
	*\brief
	*	Used to retrieve creation infos to build a pipeline.
	*\remarks
	*	Copiable and movable.
	*/
	class ProgramPipeline;
	/**
	*\brief
	*	Used to build a pipeline from a ProgramPipeline.
	*\remarks
	*	Copiable and movable.
	*/
	class PipelineBuilder;
	/**
	*\brief
	*	Array owner for VkDescriptorSetLayoutCreateInfo::pBindings.
	*\remarks
	*	Copiable and movable.
	*/
	using DescriptorSetLayoutCreateInfo = ArrayHolder< VkDescriptorSetLayoutCreateInfo
		, VkDescriptorSetLayoutBinding
		, uint32_t
		, offsetof( VkDescriptorSetLayoutCreateInfo, pBindings )
		, offsetof( VkDescriptorSetLayoutCreateInfo, bindingCount ) >;
	/**
	*\brief
	*	Array owner for VkSpecializationInfo::pMapEntries.
	*\remarks
	*	Copiable and movable.
	*/
	using SpecializationInfo = ArrayHolder< VkSpecializationInfo
		, VkSpecializationMapEntry
		, uint32_t
		, offsetof( VkSpecializationInfo, pMapEntries )
		, offsetof( VkSpecializationInfo, mapEntryCount ) >;
	/**
	*\brief
	*	Array owner for VkShaderModuleCreateInfo::pCode.
	*\remarks
	*	Copiable and movable.
	*/
	using ShaderModuleCreateInfo = ArrayHolder< VkShaderModuleCreateInfo
		, uint32_t
		, size_t
		, offsetof( VkShaderModuleCreateInfo, pCode )
		, offsetof( VkShaderModuleCreateInfo, codeSize )
		, 4u >;
	/**
	*\brief
	*	Array owner for VkWriteDescriptorSet::pImageInfo.
	*\remarks
	*	Copiable and movable.
	*/
	using ImageWriteDescriptorSet = ArrayHolder< VkWriteDescriptorSet
		, VkDescriptorImageInfo
		, uint32_t
		, offsetof( VkWriteDescriptorSet, pImageInfo )
		, offsetof( VkWriteDescriptorSet, descriptorCount ) >;
	/**
	*\brief
	*	Array owner for VkWriteDescriptorSet::pBufferInfo.
	*\remarks
	*	Copiable and movable.
	*/
	using BufferWriteDescriptorSet = ArrayHolder< VkWriteDescriptorSet
		, VkDescriptorBufferInfo
		, uint32_t
		, offsetof( VkWriteDescriptorSet, pBufferInfo )
		, offsetof( VkWriteDescriptorSet, descriptorCount ) >;
	/**
	*\brief
	*	Array owner for VkWriteDescriptorSet::pTexelBufferView.
	*\remarks
	*	Copiable and movable.
	*/
	using BufferViewWriteDescriptorSet = ArrayHolder< VkWriteDescriptorSet
		, VkBufferView
		, uint32_t
		, offsetof( VkWriteDescriptorSet, pTexelBufferView )
		, offsetof( VkWriteDescriptorSet, descriptorCount ) >;
	/**
	*\brief
	*	A variant containing either of the 3 possible descriptor set writes (image, buffer, texel buffer view).
	*/
	using WriteDescriptorSet = std::variant< ImageWriteDescriptorSet
		, BufferWriteDescriptorSet
		, BufferViewWriteDescriptorSet >;

	using SpecializationInfoOpt = std::optional< SpecializationInfo >;
	using VkSpecializationInfoOpt = std::optional< VkSpecializationInfo >;

	using PipelineShaderStageArray = std::vector< PipelineShaderStageCreateInfo >;
	using WriteDescriptorSetArray = std::vector< WriteDescriptorSet >;
	using VkDescriptorSetLayoutArray = std::vector< VkDescriptorSetLayout >;
	using VkShaderModuleArray = std::vector< VkShaderModule >;
	using VkPipelineShaderStageArray = std::vector< VkPipelineShaderStageCreateInfo >;

	struct CompareSpecInfoOpt
	{
		static inline bool comp( VkSpecializationInfo const & lhs
			, VkSpecializationInfo const & rhs )
		{
			return lhs.dataSize < rhs.dataSize
				|| lhs.mapEntryCount < rhs.mapEntryCount
				|| lhs.pData == nullptr
				|| lhs.pMapEntries == nullptr;
		}

		inline bool operator()( VkSpecializationInfoOpt const & lhs
			, VkSpecializationInfoOpt const & rhs )const
		{
			return ( lhs.has_value()
				? ( rhs.has_value()
					? comp( lhs.value(), rhs.value() )
					: false )
				: true );
		}
	};

	using ShaderModuleMap = std::map< VkSpecializationInfoOpt, VkShaderModuleArray, CompareSpecInfoOpt >;

	bool checkError( VkResult result );
}

#endif
