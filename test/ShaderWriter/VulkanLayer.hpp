/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_VulkanLayer_H___
#define ___SDWVK_VulkanLayer_H___

#define VK_NO_PROTOYPES
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma warning( push )
#pragma warning( disable: 4865 )
#include <vulkan/vulkan.h>
#pragma warning( pop )
#pragma GCC diagnostic pop

#include <ShaderAST/ShaderASTPrerequisites.hpp>

#pragma warning( push )
#pragma warning( disable: 5262 )
#include <map>
#include <optional>
#include <variant>
#include <vector>
#pragma warning( pop )

namespace test::vk
{
	using ShaderPtrs = std::vector< ast::Shader const * >;
	/**
	*\brief
	*	Fixed size std::vector wrapper.
	*\remarks
	*	Copiable and movable.
	*/
	template< typename ValueT >
	struct FixedSizeArrayT
		: private std::vector< ValueT >
	{
		using VecT = std::vector< ValueT >;

		FixedSizeArrayT()
			: VecT{}
		{
		}

		FixedSizeArrayT( ValueT const * pbegin
			, ValueT const * pend )
			: VecT{ pbegin, pend }
		{
		}

		FixedSizeArrayT( size_t count
			, ValueT const & value )
			: VecT{}
		{
			VecT::resize( count, value );
		}

		explicit FixedSizeArrayT( ValueT const & value )
			: FixedSizeArrayT{ 1u, value }
		{
		}

		using VecT::empty;
		using VecT::data;
		using VecT::size;
		using VecT::begin;
		using VecT::end;
		using VecT::cbegin;
		using VecT::cend;
		using VecT::operator[];
		using VecT::at;
	};
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
	*	Array owner for VkWriteDescriptorSetAccelerationStructureKHR::pAccelerationStructures.
	*\remarks
	*	Copiable and movable.
	*/
	struct AccelerationStructureWriteDescriptorSet
	{
		using VecT = FixedSizeArrayT< VkAccelerationStructureKHR >;

		AccelerationStructureWriteDescriptorSet()
			: write{ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR, nullptr, 0u, nullptr }
			, data{ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET, nullptr, nullptr, 0u, 0u, 0u
				, VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR, nullptr, nullptr, nullptr }
		{
			updateData( nullptr, 0u );
		}

		static VkAccelerationStructureKHR const * const * getAccStructPtr( VkWriteDescriptorSet const & data )
		{
			struct VkStructure
			{
				VkStructureType sType;
				VkStructure * pNext;
			};

			if ( auto structType = reinterpret_cast< VkStructure const * >( data.pNext );
				structType && structType->sType == VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR )
			{
				return &reinterpret_cast< VkWriteDescriptorSetAccelerationStructureKHR const * >( structType )->pAccelerationStructures;
			}

			return nullptr;
		}

		AccelerationStructureWriteDescriptorSet( VkWriteDescriptorSet && pwrite )
			: values{ ( ( pwrite.descriptorCount && getAccStructPtr( pwrite ) )
				? VecT{ *getAccStructPtr( pwrite ), *getAccStructPtr( pwrite ) + pwrite.descriptorCount }
				: ( pwrite.descriptorCount
					? [&pwrite](){ return VecT{ size_t( pwrite.descriptorCount ), VkAccelerationStructureKHR{} }; }()
					: VecT{} ) ) }
			, write{ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR, nullptr, 0u, nullptr }
			, data{ pwrite }
		{
			updateData();
		}

		AccelerationStructureWriteDescriptorSet( AccelerationStructureWriteDescriptorSet const & rhs )noexcept
			: values{ rhs.values }
			, write{ rhs.write }
			, data{ rhs.data }
		{
			updateData();
		}

		AccelerationStructureWriteDescriptorSet & operator=( AccelerationStructureWriteDescriptorSet const & rhs )noexcept
		{
			values = rhs.values;
			write = rhs.write;
			data = rhs.data;
			updateData();

			return *this;
		}

		AccelerationStructureWriteDescriptorSet( AccelerationStructureWriteDescriptorSet && rhs )noexcept
			: values{ std::move( rhs.values ) }
			, write{ rhs.write }
			, data{ rhs.data }
		{
			rhs.write = {};
			rhs.data = {};
			updateData();
		}

		AccelerationStructureWriteDescriptorSet & operator=( AccelerationStructureWriteDescriptorSet && rhs )noexcept
		{
			values = std::move( rhs.values );
			write = rhs.write;
			data = rhs.data;

			rhs.write = {};
			rhs.data = {};
			updateData();

			return *this;
		}

		VecT values;
		VkWriteDescriptorSetAccelerationStructureKHR write;
		VkWriteDescriptorSet data;

	private:
		void updateData( VkAccelerationStructureKHR * ptr
			, uint32_t size )
		{
			write.pAccelerationStructures = ptr;
			write.accelerationStructureCount = size;
			data.descriptorCount = size;
			data.pNext = &write;
		}

		void updateData()
		{
			updateData( values.data()
				, uint32_t( values.size() ) );
		}
	};
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
		, BufferViewWriteDescriptorSet
		, AccelerationStructureWriteDescriptorSet >;

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
	ShaderPtrs convert( ast::ShaderArray const & shaders );
	ShaderPtrs convert( ast::ShaderPtrArray const & shaders );
}

#endif
