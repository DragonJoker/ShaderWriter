/*
See LICENSE file in root folder
*/
#include "VulkanLayer/ProgramPipeline.hpp"

#include "VulkanLayer/MakeVkType.hpp"

#include <CompilerSpirV/compileSpirV.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <iostream>
#include <iomanip>
#include <sstream>
#pragma warning( pop )
#include <algorithm>
#include <optional>

namespace ast::vk
{
	//*********************************************************************************************

	namespace
	{
		std::ostream & operator<<( std::ostream & stream
			, VkSpecializationInfo const & value )
		{
			stream << "  Entries (" << value.mapEntryCount << "):\n";

			for ( uint32_t i = 0u; i < value.mapEntryCount; ++i )
			{
				auto & entry = value.pMapEntries[i];
				stream << "    ID: " << entry.constantID << ", Off: " << entry.offset << ", Size: " << entry.size << "\n";
			}

			stream << "  Data (" << value.dataSize << "):\n";

			if ( value.pData )
			{
				auto buffer = reinterpret_cast< uint8_t const * >( value.pData );

				for ( uint32_t i = 0u; i < value.dataSize; i += 16u )
				{
					for ( uint32_t j = i; j < i + 16u && j < value.dataSize; j += 4u )
					{
						for ( uint32_t k = j; k < j + 4u && k < value.dataSize; ++k )
						{
							stream << std::hex << std::setw( 2u ) << ( *buffer );
							++buffer;
						}

						stream << ' ';
					}

					stream << '\n';
				}
			}

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream
			, SpecializationInfo const & value )
		{
			stream << value.data;
			return stream;
		}

		template< typename T >
		std::ostream & operator<<( std::ostream & stream
			, std::optional< T > const & value )
		{
			if ( value )
			{
				stream << value.value();
			}
			else
			{
				stream << "nullopt";
			}

			return stream;
		}

		template< typename T >
		std::ostream & operator<<( std::ostream & stream
			, std::vector< T > const & values )
		{
			for ( auto & value : values )
			{
				stream << value << '\n';
			}

			return stream;
		}

		VkShaderStageFlagBits getShaderStage( ShaderStage stage )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				return VK_SHADER_STAGE_VERTEX_BIT;
			case ast::ShaderStage::eTessellationControl:
				return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
			case ast::ShaderStage::eTessellationEvaluation:
				return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
			case ast::ShaderStage::eGeometry:
				return VK_SHADER_STAGE_GEOMETRY_BIT;
			case ast::ShaderStage::eCompute:
				return VK_SHADER_STAGE_COMPUTE_BIT;
			case ast::ShaderStage::eFragment:
				return VK_SHADER_STAGE_FRAGMENT_BIT;
#if VK_NV_mesh_shader
			case ast::ShaderStage::eMeshNV:
				return VK_SHADER_STAGE_MESH_BIT_NV;
			case ast::ShaderStage::eTaskNV:
				return VK_SHADER_STAGE_TASK_BIT_NV;
#endif
#if VK_EXT_mesh_shader
			case ast::ShaderStage::eMesh:
				return VK_SHADER_STAGE_MESH_BIT_EXT;
			case ast::ShaderStage::eTask:
				return VK_SHADER_STAGE_TASK_BIT_EXT;
#endif
#if VK_KHR_ray_tracing_pipeline
			case ast::ShaderStage::eRayGeneration:
				return VK_SHADER_STAGE_RAYGEN_BIT_KHR;
			case ast::ShaderStage::eRayAnyHit:
				return VK_SHADER_STAGE_ANY_HIT_BIT_KHR;
			case ast::ShaderStage::eRayClosestHit:
				return VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR;
			case ast::ShaderStage::eRayMiss:
				return VK_SHADER_STAGE_MISS_BIT_KHR;
			case ast::ShaderStage::eCallable:
				return VK_SHADER_STAGE_CALLABLE_BIT_KHR;
			case ast::ShaderStage::eRayIntersection:
				return VK_SHADER_STAGE_INTERSECTION_BIT_KHR;
#elif VK_NV_ray_tracing
			case ast::ShaderStage::eRayGeneration:
				return VK_SHADER_STAGE_RAYGEN_BIT_NV;
			case ast::ShaderStage::eRayAnyHit:
				return VK_SHADER_STAGE_ANY_HIT_BIT_NV;
			case ast::ShaderStage::eRayClosestHit:
				return VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV;
			case ast::ShaderStage::eRayMiss:
				return VK_SHADER_STAGE_MISS_BIT_NV;
			case ast::ShaderStage::eCallable:
				return VK_SHADER_STAGE_CALLABLE_BIT_NV;
			case ast::ShaderStage::eRayIntersection:
				return VK_SHADER_STAGE_INTERSECTION_BIT_NV;
#endif
			default:
				std::cerr << "Unsupported ShaderStage.\n";
				return VK_SHADER_STAGE_COMPUTE_BIT;
			}
		}

		std::string getName( ShaderStage value )
		{
			switch ( value )
			{
			case ast::ShaderStage::eVertex:
				return "Vertex";
			case ast::ShaderStage::eTessellationControl:
				return "TessellationControl";
			case ast::ShaderStage::eTessellationEvaluation:
				return "TessellationEvaluation";
			case ast::ShaderStage::eGeometry:
				return "Geometry";
			case ast::ShaderStage::eCompute:
				return "Compute";
			case ast::ShaderStage::eFragment:
				return "Fragment";
			case ast::ShaderStage::eTaskNV:
				return "TaskNV";
			case ast::ShaderStage::eMeshNV:
				return "MeshNV";
			case ast::ShaderStage::eTask:
				return "Task";
			case ast::ShaderStage::eMesh:
				return "Mesh";
			case ast::ShaderStage::eRayGeneration:
				return "RayGeneration";
			case ast::ShaderStage::eRayAnyHit:
				return "RayAnyHit";
			case ast::ShaderStage::eRayClosestHit:
				return "RayClosestHit";
			case ast::ShaderStage::eRayMiss:
				return "RayMiss";
			case ast::ShaderStage::eCallable:
				return "Callable";
			case ast::ShaderStage::eRayIntersection:
				return "RayIntersection";
			default:
				assert( false );
				return "Unsupported";
			}
		}

		std::string getName( VkFormat format )
		{
			switch ( format )
			{
			case VK_FORMAT_R8_UNORM:
				return "VK_FORMAT_R8_UNORM";
			case VK_FORMAT_R32_SINT:
				return "VK_FORMAT_R32_SINT";
			case VK_FORMAT_R32_UINT:
				return "VK_FORMAT_R32_UINT";
			case VK_FORMAT_R16_SFLOAT:
				return "VK_FORMAT_R16_SFLOAT";
			case VK_FORMAT_R32_SFLOAT:
				return "VK_FORMAT_R32_SFLOAT";
			case VK_FORMAT_R64_SFLOAT:
				return "VK_FORMAT_R64_SFLOAT";
			case VK_FORMAT_R8G8_UNORM:
				return "VK_FORMAT_R8G8_UNORM";
			case VK_FORMAT_R8G8B8_UNORM:
				return "VK_FORMAT_R8G8B8_UNORM";
			case VK_FORMAT_R8G8B8A8_UNORM:
				return "VK_FORMAT_R8G8B8A8_UNORM";
			case VK_FORMAT_R32G32_SINT:
				return "VK_FORMAT_R32G32_SINT";
			case VK_FORMAT_R32G32B32_SINT:
				return "VK_FORMAT_R32G32B32_SINT";
			case VK_FORMAT_R32G32B32A32_SINT:
				return "VK_FORMAT_R32G32B32A32_SINT";
			case VK_FORMAT_R32G32_UINT:
				return "VK_FORMAT_R32G32_UINT";
			case VK_FORMAT_R32G32B32_UINT:
				return "VK_FORMAT_R32G32B32_UINT";
			case VK_FORMAT_R32G32B32A32_UINT:
				return "VK_FORMAT_R32G32B32A32_UINT";
			case VK_FORMAT_R16G16_SFLOAT:
				return "VK_FORMAT_R16G16_SFLOAT";
			case VK_FORMAT_R16G16B16_SFLOAT:
				return "VK_FORMAT_R16G16B16_SFLOAT";
			case VK_FORMAT_R16G16B16A16_SFLOAT:
				return "VK_FORMAT_R16G16B16A16_SFLOAT";
			case VK_FORMAT_R32G32_SFLOAT:
				return "VK_FORMAT_R32G32_SFLOAT";
			case VK_FORMAT_R32G32B32_SFLOAT:
				return "VK_FORMAT_R32G32B32_SFLOAT";
			case VK_FORMAT_R32G32B32A32_SFLOAT:
				return "VK_FORMAT_R32G32B32A32_SFLOAT";
			case VK_FORMAT_R64G64_SFLOAT:
				return "VK_FORMAT_R64G64_SFLOAT";
			case VK_FORMAT_R64G64B64_SFLOAT:
				return "VK_FORMAT_R64G64B64_SFLOAT";
			case VK_FORMAT_R64G64B64A64_SFLOAT:
				return "VK_FORMAT_R64G64B64A64_SFLOAT";
			default:
				return "unsupported";
			}
		}

		VkFormat getVkFormat( type::Kind kind )
		{
			switch ( kind )
			{
			case ast::type::Kind::eBoolean:
				return VK_FORMAT_R8_UNORM;
			case ast::type::Kind::eInt8:
				return VK_FORMAT_R8_SINT;
			case ast::type::Kind::eInt16:
				return VK_FORMAT_R16_SINT;
			case ast::type::Kind::eInt32:
				return VK_FORMAT_R32_SINT;
			case ast::type::Kind::eInt64:
				return VK_FORMAT_R64_SINT;
			case ast::type::Kind::eUInt8:
				return VK_FORMAT_R8_UINT;
			case ast::type::Kind::eUInt16:
				return VK_FORMAT_R16_UINT;
			case ast::type::Kind::eUInt32:
				return VK_FORMAT_R32_UINT;
			case ast::type::Kind::eUInt64:
				return VK_FORMAT_R64_UINT;
			case ast::type::Kind::eHalf:
				return VK_FORMAT_R16_SFLOAT;
			case ast::type::Kind::eFloat:
				return VK_FORMAT_R32_SFLOAT;
			case ast::type::Kind::eDouble:
				return VK_FORMAT_R64_SFLOAT;
			case ast::type::Kind::eVec2B:
				return VK_FORMAT_R8G8_UNORM;
			case ast::type::Kind::eVec3B:
				return VK_FORMAT_R8G8B8_UNORM;
			case ast::type::Kind::eVec4B:
				return VK_FORMAT_R8G8B8A8_UNORM;
			case ast::type::Kind::eVec2I8:
				return VK_FORMAT_R8G8_SINT;
			case ast::type::Kind::eVec3I8:
				return VK_FORMAT_R8G8B8_SINT;
			case ast::type::Kind::eVec4I8:
				return VK_FORMAT_R8G8B8A8_SINT;
			case ast::type::Kind::eVec2I16:
				return VK_FORMAT_R16G16_SINT;
			case ast::type::Kind::eVec3I16:
				return VK_FORMAT_R16G16B16_SINT;
			case ast::type::Kind::eVec4I16:
				return VK_FORMAT_R16G16B16A16_SINT;
			case ast::type::Kind::eVec2I32:
				return VK_FORMAT_R32G32_SINT;
			case ast::type::Kind::eVec3I32:
				return VK_FORMAT_R32G32B32_SINT;
			case ast::type::Kind::eVec4I32:
				return VK_FORMAT_R32G32B32A32_SINT;
			case ast::type::Kind::eVec2I64:
				return VK_FORMAT_R64G64_SINT;
			case ast::type::Kind::eVec3I64:
				return VK_FORMAT_R64G64B64_SINT;
			case ast::type::Kind::eVec4I64:
				return VK_FORMAT_R64G64B64A64_SINT;
			case ast::type::Kind::eVec2U8:
				return VK_FORMAT_R8G8_UINT;
			case ast::type::Kind::eVec3U8:
				return VK_FORMAT_R8G8B8_UINT;
			case ast::type::Kind::eVec4U8:
				return VK_FORMAT_R8G8B8A8_UINT;
			case ast::type::Kind::eVec2U16:
				return VK_FORMAT_R16G16_UINT;
			case ast::type::Kind::eVec3U16:
				return VK_FORMAT_R16G16B16_UINT;
			case ast::type::Kind::eVec4U16:
				return VK_FORMAT_R16G16B16A16_UINT;
			case ast::type::Kind::eVec2U32:
				return VK_FORMAT_R32G32_UINT;
			case ast::type::Kind::eVec3U32:
				return VK_FORMAT_R32G32B32_UINT;
			case ast::type::Kind::eVec4U32:
				return VK_FORMAT_R32G32B32A32_UINT;
			case ast::type::Kind::eVec2U64:
				return VK_FORMAT_R64G64_UINT;
			case ast::type::Kind::eVec3U64:
				return VK_FORMAT_R64G64B64_UINT;
			case ast::type::Kind::eVec4U64:
				return VK_FORMAT_R64G64B64A64_UINT;
			case ast::type::Kind::eVec2H:
				return VK_FORMAT_R16G16B16_SFLOAT;
			case ast::type::Kind::eVec4H:
				return VK_FORMAT_R16G16B16A16_SFLOAT;
			case ast::type::Kind::eVec2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eVec3F:
				return VK_FORMAT_R32G32B32_SFLOAT;
			case ast::type::Kind::eVec4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eVec2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eVec3D:
				return VK_FORMAT_R64G64B64_SFLOAT;
			case ast::type::Kind::eVec4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat2x2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eMat2x3F:
				return VK_FORMAT_R32G32B32_SFLOAT;
			case ast::type::Kind::eMat2x4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat3x2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eMat3x3F:
				return VK_FORMAT_R32G32B32_SFLOAT;
			case ast::type::Kind::eMat3x4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat4x2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eMat4x3F:
				return VK_FORMAT_R32G32B32_SFLOAT;
			case ast::type::Kind::eMat4x4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat2x2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eMat2x3D:
				return VK_FORMAT_R64G64B64_SFLOAT;
			case ast::type::Kind::eMat2x4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat3x2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eMat3x3D:
				return VK_FORMAT_R64G64B64_SFLOAT;
			case ast::type::Kind::eMat3x4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat4x2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eMat4x3D:
				return VK_FORMAT_R64G64B64_SFLOAT;
			case ast::type::Kind::eMat4x4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			default:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			}
		}

		VkFormat getVkFormat( type::Type const & in )
		{
			return getVkFormat( in.getKind() );
		}

		VkFormat getAttachVkFormat( type::Kind kind )
		{
			switch ( kind )
			{
			case ast::type::Kind::eBoolean:
				return VK_FORMAT_R8_UNORM;
			case ast::type::Kind::eInt8:
				return VK_FORMAT_R8_SINT;
			case ast::type::Kind::eInt16:
				return VK_FORMAT_R16_SINT;
			case ast::type::Kind::eInt32:
				return VK_FORMAT_R32_SINT;
			case ast::type::Kind::eInt64:
				return VK_FORMAT_R64_SINT;
			case ast::type::Kind::eUInt8:
				return VK_FORMAT_R8_UINT;
			case ast::type::Kind::eUInt16:
				return VK_FORMAT_R16_UINT;
			case ast::type::Kind::eUInt32:
				return VK_FORMAT_R32_UINT;
			case ast::type::Kind::eUInt64:
				return VK_FORMAT_R64_UINT;
			case ast::type::Kind::eHalf:
				return VK_FORMAT_R16_SFLOAT;
			case ast::type::Kind::eFloat:
				return VK_FORMAT_R32_SFLOAT;
			case ast::type::Kind::eDouble:
				return VK_FORMAT_R64_SFLOAT;
			case ast::type::Kind::eVec2B:
				return VK_FORMAT_R8G8_UNORM;
			case ast::type::Kind::eVec3B:
				return VK_FORMAT_R8G8B8A8_UNORM;
			case ast::type::Kind::eVec4B:
				return VK_FORMAT_R8G8B8A8_UNORM;
			case ast::type::Kind::eVec2I8:
				return VK_FORMAT_R8G8_SINT;
			case ast::type::Kind::eVec3I8:
				return VK_FORMAT_R8G8B8A8_SINT;
			case ast::type::Kind::eVec4I8:
				return VK_FORMAT_R8G8B8A8_SINT;
			case ast::type::Kind::eVec2I16:
				return VK_FORMAT_R16G16_SINT;
			case ast::type::Kind::eVec3I16:
				return VK_FORMAT_R16G16B16A16_SINT;
			case ast::type::Kind::eVec4I16:
				return VK_FORMAT_R16G16B16A16_SINT;
			case ast::type::Kind::eVec2I32:
				return VK_FORMAT_R32G32_SINT;
			case ast::type::Kind::eVec3I32:
				return VK_FORMAT_R32G32B32A32_SINT;
			case ast::type::Kind::eVec4I32:
				return VK_FORMAT_R32G32B32A32_SINT;
			case ast::type::Kind::eVec2I64:
				return VK_FORMAT_R64G64_SINT;
			case ast::type::Kind::eVec3I64:
				return VK_FORMAT_R64G64B64A64_SINT;
			case ast::type::Kind::eVec4I64:
				return VK_FORMAT_R64G64B64A64_SINT;
			case ast::type::Kind::eVec2U8:
				return VK_FORMAT_R8G8_UINT;
			case ast::type::Kind::eVec3U8:
				return VK_FORMAT_R8G8B8A8_UINT;
			case ast::type::Kind::eVec4U8:
				return VK_FORMAT_R8G8B8A8_UINT;
			case ast::type::Kind::eVec2U16:
				return VK_FORMAT_R16G16_UINT;
			case ast::type::Kind::eVec3U16:
				return VK_FORMAT_R16G16B16A16_UINT;
			case ast::type::Kind::eVec4U16:
				return VK_FORMAT_R16G16B16A16_UINT;
			case ast::type::Kind::eVec2U32:
				return VK_FORMAT_R32G32_UINT;
			case ast::type::Kind::eVec3U32:
				return VK_FORMAT_R32G32B32A32_UINT;
			case ast::type::Kind::eVec4U32:
				return VK_FORMAT_R32G32B32A32_UINT;
			case ast::type::Kind::eVec2U64:
				return VK_FORMAT_R64G64_UINT;
			case ast::type::Kind::eVec3U64:
				return VK_FORMAT_R64G64B64A64_UINT;
			case ast::type::Kind::eVec4U64:
				return VK_FORMAT_R64G64B64A64_UINT;
			case ast::type::Kind::eVec2H:
				return VK_FORMAT_R16G16B16A16_SFLOAT;
			case ast::type::Kind::eVec4H:
				return VK_FORMAT_R16G16B16A16_SFLOAT;
			case ast::type::Kind::eVec2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eVec3F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eVec4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eVec2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eVec3D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eVec4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat2x2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eMat2x3F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat2x4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat3x2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eMat3x3F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat3x4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat4x2F:
				return VK_FORMAT_R32G32_SFLOAT;
			case ast::type::Kind::eMat4x3F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat4x4F:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			case ast::type::Kind::eMat2x2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eMat2x3D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat2x4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat3x2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eMat3x3D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat3x4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat4x2D:
				return VK_FORMAT_R64G64_SFLOAT;
			case ast::type::Kind::eMat4x3D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			case ast::type::Kind::eMat4x4D:
				return VK_FORMAT_R64G64B64A64_SFLOAT;
			default:
				return VK_FORMAT_R32G32B32A32_SFLOAT;
			}
		}

		VkFormat getAttachVkFormat( type::Type const & in )
		{
			return getAttachVkFormat( in.getKind() );
		}

		VkShaderStageFlags getVkShaderStages( uint32_t in )
		{
			VkShaderStageFlags result{ 0u };

			if ( in & uint32_t( ShaderStageFlag::eVertex ) )
			{
				result |= VK_SHADER_STAGE_VERTEX_BIT;
			}

			if ( in & uint32_t( ShaderStageFlag::eTessellationControl ) )
			{
				result |= VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
			}

			if ( in & uint32_t( ShaderStageFlag::eTessellationEvaluation ) )
			{
				result |= VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
			}

			if ( in & uint32_t( ShaderStageFlag::eGeometry ) )
			{
				result |= VK_SHADER_STAGE_GEOMETRY_BIT;
			}

			if ( in & uint32_t( ShaderStageFlag::eFragment ) )
			{
				result |= VK_SHADER_STAGE_FRAGMENT_BIT;
			}

			if ( in & uint32_t( ShaderStageFlag::eCompute ) )
			{
				result |= VK_SHADER_STAGE_COMPUTE_BIT;
			}

#if VK_EXT_mesh_shader
			if ( in & uint32_t( ShaderStageFlag::eTask ) )
			{
				result |= VK_SHADER_STAGE_TASK_BIT_EXT;
			}

			if ( in & uint32_t( ShaderStageFlag::eMesh ) )
			{
				result |= VK_SHADER_STAGE_MESH_BIT_EXT;
			}
#endif

#if VK_NV_mesh_shader
			if ( in & uint32_t( ShaderStageFlag::eTaskNV ) )
			{
				result |= VK_SHADER_STAGE_TASK_BIT_NV;
			}

			if ( in & uint32_t( ShaderStageFlag::eMeshNV ) )
			{
				result |= VK_SHADER_STAGE_MESH_BIT_NV;
			}
#endif

#if VK_KHR_ray_tracing_pipeline
			if ( in & uint32_t( ShaderStageFlag::eRayGeneration ) )
			{
				result |= VK_SHADER_STAGE_RAYGEN_BIT_KHR;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayClosestHit ) )
			{
				result |= VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayAnyHit ) )
			{
				result |= VK_SHADER_STAGE_ANY_HIT_BIT_KHR;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayMiss ) )
			{
				result |= VK_SHADER_STAGE_MISS_BIT_KHR;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayIntersection ) )
			{
				result |= VK_SHADER_STAGE_INTERSECTION_BIT_KHR;
			}

			if ( in & uint32_t( ShaderStageFlag::eCallable ) )
			{
				result |= VK_SHADER_STAGE_CALLABLE_BIT_KHR;
			}
#elif VK_NV_ray_tracing
			if ( in & uint32_t( ShaderStageFlag::eRayGeneration ) )
			{
				result |= VK_SHADER_STAGE_RAYGEN_BIT_NV;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayClosestHit ) )
			{
				result |= VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayAnyHit ) )
			{
				result |= VK_SHADER_STAGE_ANY_HIT_BIT_NV;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayMiss ) )
			{
				result |= VK_SHADER_STAGE_MISS_BIT_NV;
			}

			if ( in & uint32_t( ShaderStageFlag::eRayIntersection ) )
			{
				result |= VK_SHADER_STAGE_INTERSECTION_BIT_NV;
			}

			if ( in & uint32_t( ShaderStageFlag::eCallable ) )
			{
				result |= VK_SHADER_STAGE_CALLABLE_BIT_NV;
			}
#endif

			return result;
		}

		VkDescriptorType getVkDescriptorType( DescriptorType in )
		{
			switch ( in )
			{
			case ast::DescriptorType::eUniformBuffer:
				return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
			case ast::DescriptorType::eStorageBuffer:
				return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
			case ast::DescriptorType::eSampler:
				return VK_DESCRIPTOR_TYPE_SAMPLER;
			case ast::DescriptorType::eTexture:
				return VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
			case ast::DescriptorType::eStorageImage:
				return VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
			case ast::DescriptorType::eUniformTexelBuffer:
				return VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;
			case ast::DescriptorType::eStorageTexelBuffer:
				return VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;
			default:
				AST_Failure( "Unsupported DescriptorType." );
				return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
			}
		}

		VkWriteDescriptorSet makeWrite( uint32_t binding
			, uint32_t descriptorCount
			, VkDescriptorType descriptorType )
		{
			return makeVkStruct< VkWriteDescriptorSet >( nullptr
				, binding
				, 0u
				, descriptorCount
				, descriptorType
				, nullptr
				, nullptr
				, nullptr );
		}
	}

	//*********************************************************************************************

	ProgramPipeline::ProgramPipeline( uint32_t spvVersion
		, ShaderPtrArray const & shaders )
		: m_sources{ createShaderSources( spvVersion, shaders.begin(), shaders.end() ) }
		, m_specializationInfos{ createSpecializationInfos( shaders.begin(), shaders.end() ) }
		, m_stages{ createShaderStages( shaders.begin(), shaders.end() ) }
		, m_data{ createShaderData( shaders.begin(), shaders.end() ) }
		, m_shaderModules{ createShaderModules( shaders.begin(), shaders.end() ) }
		, m_pushConstantRanges{ createPushConstantRanges( shaders.begin(), shaders.end() ) }
		, m_descriptorLayouts{ createDescriptorLayouts() }
		, m_descriptorPoolSizes{ createDescriptorPoolSizes() }
		, m_descriptorSetsWrites{ createDescriptorSetsWrites() }
		, m_pipelineLayout{ createPipelineLayout() }
		, m_vertexAttributes{ createVertexAttributes() }
		, m_attachmentDescriptions{ createAttachmentDescriptions() }
	{
	}

	ProgramPipeline::ProgramPipeline( uint32_t spvVersion
		, ShaderArray const & shaders )
		: m_sources{ createShaderSources( spvVersion, shaders.begin(), shaders.end() ) }
		, m_specializationInfos{ createSpecializationInfos( shaders.begin(), shaders.end() ) }
		, m_stages{ createShaderStages( shaders.begin(), shaders.end() ) }
		, m_data{ createShaderData( shaders.begin(), shaders.end() ) }
		, m_shaderModules{ createShaderModules( shaders.begin(), shaders.end() ) }
		, m_pushConstantRanges{ createPushConstantRanges( shaders.begin(), shaders.end() ) }
		, m_descriptorLayouts{ createDescriptorLayouts() }
		, m_descriptorPoolSizes{ createDescriptorPoolSizes() }
		, m_descriptorSetsWrites{ createDescriptorSetsWrites() }
		, m_pipelineLayout{ createPipelineLayout() }
		, m_vertexAttributes{ createVertexAttributes() }
		, m_attachmentDescriptions{ createAttachmentDescriptions() }
	{
	}

	ProgramPipeline::ProgramPipeline( uint32_t spvVersion
		, Shader const & shader
		, EntryPointConfigArray const & entryPoints )
		: m_sources{ createShaderSources( spvVersion, shader, entryPoints.begin(), entryPoints.end() ) }
		, m_specializationInfos{ createSpecializationInfos( shader, entryPoints.begin(), entryPoints.end() ) }
		, m_stages{ createShaderStages( entryPoints.begin(), entryPoints.end() ) }
		, m_data{ createShaderData( shader, entryPoints.begin(), entryPoints.end() ) }
		, m_shaderModules{ createShaderModules( entryPoints.begin(), entryPoints.end() ) }
		, m_pushConstantRanges{ createPushConstantRanges( shader, entryPoints.begin(), entryPoints.end() ) }
		, m_descriptorLayouts{ createDescriptorLayouts() }
		, m_descriptorPoolSizes{ createDescriptorPoolSizes() }
		, m_descriptorSetsWrites{ createDescriptorSetsWrites() }
		, m_pipelineLayout{ createPipelineLayout() }
		, m_vertexAttributes{ createVertexAttributes() }
		, m_attachmentDescriptions{ createAttachmentDescriptions() }
	{
	}

	std::vector< SpecializationInfoOpt > ProgramPipeline::getSpecializationInfos()const
	{
		std::vector< SpecializationInfoOpt > result;

		for ( auto & info : m_specializationInfos )
		{
			if ( info )
			{
				result.emplace_back( SpecializationInfo{ info.value().data } );
			}
			else
			{
				result.emplace_back( std::nullopt );
			}
		}

		return result;
	}

	PipelineShaderStageArray ProgramPipeline::getShaderStages()const
	{
		return m_stages;
	}

	std::vector< VkVertexInputAttributeDescription > ProgramPipeline::getVertexAttributes()const
	{
		return m_vertexAttributes;
	}

	std::map< uint32_t, VkAttachmentDescription > ProgramPipeline::getAttachmentDescriptions()const
	{
		return m_attachmentDescriptions;
	}

	std::vector< VkShaderModuleCreateInfo > ProgramPipeline::getShaderModules()const
	{
		std::vector< VkShaderModuleCreateInfo > result;

		for ( auto & shaderModule : m_shaderModules )
		{
			result.push_back( shaderModule.data );
		}

		return result;
	}

	std::vector< DescriptorSetLayoutCreateInfo > const & ProgramPipeline::getDescriptorLayouts()const
	{
		return m_descriptorLayouts;
	}

	std::vector< VkDescriptorPoolSize > ProgramPipeline::getDescriptorPoolSizes( uint32_t maxSets )const
	{
		std::vector< VkDescriptorPoolSize > result{ m_descriptorPoolSizes };
		std::transform( result.begin()
			, result .end()
			, result.begin()
			, [&maxSets]( VkDescriptorPoolSize sizes )
			{
				sizes.descriptorCount *= maxSets;
				return sizes;
			} );
		return result;
	}

	WriteDescriptorSetArray ProgramPipeline::getDescriptorSetWrites( uint32_t setIndex )const
	{
		assert( m_descriptorSetsWrites.size() > setIndex );
		return m_descriptorSetsWrites[setIndex];
	}

	std::vector< WriteDescriptorSetArray > ProgramPipeline::getDescriptorSetWrites()const
	{
		return m_descriptorSetsWrites;
	}

	std::vector< VkPushConstantRange > const & ProgramPipeline::getPushConstantRanges()const
	{
		return m_pushConstantRanges;
	}

	VkPipelineLayoutCreateInfo ProgramPipeline::getPipelineLayout( std::vector< VkDescriptorSetLayout > const & layouts )const
	{
		assert( layouts.size() == m_pipelineLayout.setLayoutCount );
		VkPipelineLayoutCreateInfo result{ m_pipelineLayout };
		result.pSetLayouts = layouts.data();
		return result;
	}

	PipelineShaderStageArray ProgramPipeline::getShaderStages( VkShaderModuleArray modules
		, std::vector< VkSpecializationInfoOpt > const & specializationInfo )const
	{
		checkSpecializationInfos( specializationInfo );
		PipelineShaderStageArray result{ m_stages };
		assert( result.size() == modules.size() );
		assert( specializationInfo.empty() || result.size() == specializationInfo.size() );
		auto lit = result.begin();
		auto rit = modules.begin();
		auto sit = specializationInfo.begin();

		while ( lit != result.end() && rit != modules.end() )
		{
			( *lit )->module = *rit;

			if ( sit != specializationInfo.end() )
			{
				if ( ( *lit )->pSpecializationInfo )
				{
					( *lit )->pSpecializationInfo = ( *sit )
						? &sit->value()
						: nullptr;
				}

				++sit;
			}

			++lit;
			++rit;
		}

		return result;
	}

	bool ProgramPipeline::checkGraphicsPipeline( VkGraphicsPipelineCreateInfo const & createInfos )const
	{
		if ( m_stages.empty() )
		{
			std::cerr << "No shader stage was expected (WTF ?)" << std::endl;
			return false;
		}

		if ( m_stages.size() != createInfos.stageCount )
		{
			std::cerr << "Expected " << m_stages.size() << " shader stages, "
				<< "but user provided " << createInfos.stageCount << std::endl;
			return false;
		}

		bool result = true;

		if ( createInfos.pVertexInputState )
		{
			result = checkVertexInputState( *createInfos.pVertexInputState ) && result;
		}

		if ( createInfos.pTessellationState )
		{
			result = checkTessellationState( *createInfos.pTessellationState ) && result;
		}

		return result;
	}

	bool ProgramPipeline::checkComputePipeline()const
	{
		if ( m_stages.empty() )
		{
			std::cerr << "No shader stage was expected. (WTF ?)" << std::endl;
			return false;
		}

		bool result = true;

		if ( m_stages.size() > 1u )
		{
			std::cerr << "Multiple shader stages expected, make sure you want a compute pipeline." << std::endl;
			result = false;
		}

		return result;
	}

	std::vector< uint32_t > ProgramPipeline::createShaderSource( uint32_t spvVersion
		, Shader const & shader
		, EntryPointConfig const & entryPoint )
	{
		auto size = uint32_t( m_indices.size() );
		m_stageFlags |= getShaderStage( entryPoint.stage );
		m_indices[entryPoint.stage] = size;
		m_revIndices[size] = entryPoint.stage;
		spirv::SpirVConfig config;
		spirv::SpirVExtensionSet extensions;
		config.specVersion = spvVersion;

		if ( config.specVersion >= spirv::v1_6 )
		{
			extensions.emplace( spirv::EXT_mesh_shader );
		}

		if ( config.specVersion >= spirv::v1_5 )
		{
			extensions.emplace( spirv::KHR_terminate_invocation );
			extensions.emplace( spirv::EXT_shader_atomic_float_add );
		}

		if ( config.specVersion >= spirv::v1_4 )
		{
			extensions.emplace( spirv::EXT_demote_to_helper_invocation );
			extensions.emplace( spirv::KHR_ray_tracing );
		}

		if ( config.specVersion >= spirv::v1_3 )
		{
			extensions.emplace( spirv::NV_mesh_shader );
			extensions.emplace( spirv::EXT_descriptor_indexing );
			extensions.emplace( spirv::EXT_physical_storage_buffer );
			extensions.emplace( spirv::KHR_shader_subgroup );
		}

		if ( config.specVersion >= spirv::v1_2 )
		{
			extensions.emplace( spirv::KHR_8bit_storage );
		}

		if ( config.specVersion >= spirv::v1_1 )
		{
			extensions.emplace( spirv::KHR_shader_draw_parameters );
		}

		config.availableExtensions = &extensions;
		auto statements = ::ast::selectEntryPoint( shader.getStmtCache()
			, shader.getExprCache()
			, entryPoint
			, *shader.getStatements() );

		if ( statements == nullptr )
		{
			throw ast::Exception{ "Shader entry point selection failed." };
		}

		auto result = spirv::serialiseSpirv( shader, statements.get(), entryPoint.stage, config );

		if ( result.empty() )
		{
			throw ast::Exception{ "Shader serialization failed." };
		}

		return result;
	}

	SpecializationInfoOpt ProgramPipeline::createSpecializationInfo( Shader const & shader )const
	{
		SpecializationInfoOpt result{ std::nullopt };

		if ( !shader.getData().specConstants.empty() )
		{
			size_t size = 0u;
			std::vector< VkSpecializationMapEntry > entries;

			for ( auto const & [_, specConstant] : shader.getData().specConstants )
			{
				auto specSize = type::getSize( specConstant.type
					, type::MemoryLayout::eC );
				entries.push_back( { specConstant.location
						, 0u
						, specSize } );
				size += specSize;
			}

			std::sort( entries.begin()
				, entries.end()
				, []( VkSpecializationMapEntry const & lhs
					, VkSpecializationMapEntry const & rhs )
				{
					return lhs.constantID < rhs.constantID;
				} );
			result = SpecializationInfo{ { uint32_t( entries.size() )
					, entries.data()
					, size
					, nullptr } };
		}

		return result;
	}

	PipelineShaderStageCreateInfo ProgramPipeline::createShaderStage( EntryPointConfig const & entryPoint )
	{
		auto const& specInfo = m_specializationInfos[m_indices[entryPoint.stage]];
		return { 0u
			, getShaderStage( entryPoint.stage )
			, nullptr
			, specInfo };
	}

	ShaderDataPtr ProgramPipeline::createShaderData( Shader const & shader
		, EntryPointConfig const & entryPoint )
	{
		ShaderDataPtr result{ shader.getData()
			, getEntryPointType( entryPoint.stage )
			, makeFlag( entryPoint.stage ) };
		m_tessellationControlPoints = std::max( m_tessellationControlPoints, result.tessellationControlPoints );
		return result;
	}

	ShaderModuleCreateInfo ProgramPipeline::createShaderModule( EntryPointConfig const & entryPoint )
	{
		auto & code = m_sources[m_indices[entryPoint.stage]];
		return ShaderModuleCreateInfo{ makeVkStruct< VkShaderModuleCreateInfo >( 0u
			, code.size() * sizeof( uint32_t )
			, code.data() ) };
	}

	std::vector< VkPushConstantRange > ProgramPipeline::createPushConstantRanges( Shader const & shader
		, EntryPointConfig const & entryPoint )const
	{
		std::vector< VkPushConstantRange > result;
		uint32_t size = 0u;

		for ( auto const & [_, pcb] : shader.getData().pcbs )
		{
			auto pcbSize = getSize( pcb.getType()
				, pcb.getType()->getMemoryLayout() );
			result.push_back( { VkShaderStageFlags( getShaderStage( entryPoint.stage ) )
				, size
				, pcbSize } );
			size += pcbSize;
		}

		return result;
	}

	std::vector< DescriptorSetLayoutCreateInfo > ProgramPipeline::createDescriptorLayouts()const
	{
		std::vector< DescriptorSetLayoutCreateInfo > result;

		for ( auto & set : m_data.descriptors )
		{
			std::vector< VkDescriptorSetLayoutBinding > bindings;

			for ( auto const & [binding, data] : set )
			{
				bindings.push_back( { binding.binding
					, getVkDescriptorType( data.type )
					, data.count
					, getVkShaderStages( data.stages )
					, nullptr } );
			}

			result.emplace_back( makeVkStruct< VkDescriptorSetLayoutCreateInfo >( 0u
				, uint32_t( bindings.size() )
				, bindings.data() ) );
		}

		return result;
	}

	std::vector< VkDescriptorPoolSize > ProgramPipeline::createDescriptorPoolSizes()
	{
		std::vector< VkDescriptorPoolSize > result;

		for ( uint32_t i = 0u; i < m_descriptorLayouts.size(); ++i )
		{
			auto count = uint32_t( std::count_if( m_data.ssbos.begin()
				, m_data.ssbos.end()
				, [i]( auto & lookup )
				{
					return lookup.first.set == i;
				} ) );

			if ( count )
			{
				result.push_back( { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, count } );
			}

			count = uint32_t( std::count_if( m_data.ubos.begin()
				, m_data.ubos.end()
				, [i]( auto & lookup )
				{
					return lookup.first.set == i;
				} ) );

			if ( count )
			{
				result.push_back( { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, count } );
			}

			count = uint32_t( std::count_if( m_data.samplers.begin()
				, m_data.samplers.end()
				, [i]( auto & lookup )
				{
					return lookup.first.set == i;
				} ) );

			if ( count )
			{
				result.push_back( { VK_DESCRIPTOR_TYPE_SAMPLER, count } );
			}

			count = uint32_t( std::count_if( m_data.textures.begin()
				, m_data.textures.end()
				, [i]( auto & lookup )
				{
					return lookup.first.set == i;
				} ) );

			if ( count )
			{
				result.push_back( { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, count } );
			}

			count = uint32_t( std::count_if( m_data.images.begin()
				, m_data.images.end()
				, [i]( auto & lookup )
				{
					return lookup.first.set == i;
				} ) );

			if ( count )
			{
				result.push_back( { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, count } );
			}
		}

		return result;
	}

	std::vector< WriteDescriptorSetArray > ProgramPipeline::createDescriptorSetsWrites()const
	{
		std::vector< WriteDescriptorSetArray > result;

		for ( uint32_t i = 0u; i < m_descriptorLayouts.size(); ++i )
		{
			WriteDescriptorSetArray setWrites;

			for ( auto & [binding, data] : m_data.ssbos )
			{
				if ( binding.set == i )
				{
					auto size = ast::type::getSize( *data->type
						, data->type->getMemoryLayout() );
					BufferWriteDescriptorSet write{ makeWrite( binding.binding
						, 1u
						, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER ) };
					write.values[0].range = size;
					setWrites.emplace_back( std::move( write ) );
				}
			}

			for ( auto & [binding, data] : m_data.ubos )
			{
				if ( binding.set == i )
				{
					auto size = ast::type::getSize( *data->type
						, data->type->getMemoryLayout() );
					BufferWriteDescriptorSet write{ makeWrite( binding.binding
						, 1u
						, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER ) };
					write.values[0].range = size;
					setWrites.emplace_back( std::move( write ) );
				}
			}

			for ( auto & [binding, _] : m_data.samplers )
			{
				if ( binding.set == i )
				{
					ImageWriteDescriptorSet write{ makeWrite( binding.binding
						, 1u
						, VK_DESCRIPTOR_TYPE_SAMPLER ) };
					setWrites.emplace_back( std::move( write ) );
				}
			}

			for ( auto & [binding, _] : m_data.textures )
			{
				if ( binding.set == i )
				{
					ImageWriteDescriptorSet write{ makeWrite( binding.binding
						, 1u
						, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER ) };
					write.values[0].imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
					setWrites.emplace_back( std::move( write ) );
				}
			}

			for ( auto & [binding, _] : m_data.images )
			{
				if ( binding.set == i )
				{
					ImageWriteDescriptorSet write{ makeWrite( binding.binding
						, 1u
						, VK_DESCRIPTOR_TYPE_STORAGE_IMAGE ) };
					write.values[0].imageLayout = VK_IMAGE_LAYOUT_GENERAL;
					setWrites.emplace_back( std::move( write ) );
				}
			}

			result.emplace_back( std::move( setWrites ) );
		}

		return result;
	}

	VkPipelineLayoutCreateInfo ProgramPipeline::createPipelineLayout()
	{
		return makeVkStruct< VkPipelineLayoutCreateInfo >( 0u
			, uint32_t( m_descriptorLayouts.size() )
			, nullptr
			, uint32_t( m_pushConstantRanges.size() )
			, ( m_pushConstantRanges.empty()
				? nullptr
				: m_pushConstantRanges.data() ) );
	}

	std::vector< VkVertexInputAttributeDescription > ProgramPipeline::createVertexAttributes()const
	{
		std::vector< VkVertexInputAttributeDescription > result;

		if ( hasStages( VK_SHADER_STAGE_VERTEX_BIT ) )
		{
			for ( auto const & [input, _] : m_data.inputs )
			{
				result.push_back( { input.location
					, 0u
					, getVkFormat( *input.type )
					, 0u } );
			}
		}

		return result;
	}

	std::map< uint32_t, VkAttachmentDescription > ProgramPipeline::createAttachmentDescriptions()const
	{
		std::map< uint32_t, VkAttachmentDescription > result;

		if ( hasStages( VK_SHADER_STAGE_FRAGMENT_BIT ) )
		{
			for ( auto const & [output, _] : m_data.outputs )
			{
				VkAttachmentDescription desc{};
				desc.format = getAttachVkFormat( *output.type );
				desc.samples = VK_SAMPLE_COUNT_1_BIT;
				result.try_emplace( output.location, std::move( desc ) );
			}
		}

		return result;
	}

	bool ProgramPipeline::checkTessellationState( VkPipelineTessellationStateCreateInfo const & )const
	{
		bool result = true;

		if ( !hasTessellationStage() )
		{
			std::cerr << "Tessellation state was given whilst no tessellation shader stage exists." << std::endl;
			result = false;
		}

		return result;
	}

	bool ProgramPipeline::checkVertexInputState( VkPipelineVertexInputStateCreateInfo const & state )const
	{
		bool result = true;

		if ( hasStages( VK_SHADER_STAGE_VERTEX_BIT ) )
		{
			auto end = state.pVertexAttributeDescriptions + state.vertexAttributeDescriptionCount;

			for ( auto & attribute : m_vertexAttributes )
			{
				auto it = std::find_if( state.pVertexAttributeDescriptions
					, end
					, [&attribute]( VkVertexInputAttributeDescription const & lookup )
					{
						return lookup.location == attribute.location;
					} );

				if ( it == end )
				{
					std::cerr << "Shader expects attribute at location " << attribute.location
						<< " which could not be found in provided vertex input state." << std::endl;
					result = false;
				}
				else if ( it->format != attribute.format )
				{
					std::cerr << "Type mismatch for attribute at location " << attribute.location
						<< ", shader expects " << getName( attribute.format )
						<< " , user provided " << getName( it->format ) << std::endl;
					result = false;
				}
			}

			for ( auto lit = state.pVertexAttributeDescriptions; lit != end; ++lit )
			{
				VkVertexInputAttributeDescription const & lhs = *lit;
				auto rit = std::find_if( m_vertexAttributes.begin()
					, m_vertexAttributes.end()
					, [&lhs]( VkVertexInputAttributeDescription const & rhs )
					{
						return lhs.location == rhs.location;
					} );

				if ( rit == m_vertexAttributes.end() )
				{
					std::cout << "User provided an attribute of type " << getName( lhs.format )
						<< " at location " << lhs.location
						<< " which is not used by the shader." << std::endl;
				}
			}
		}

		return result;
	}

	bool ProgramPipeline::checkSpecializationInfos( std::vector< VkSpecializationInfoOpt > const & infos )const
	{
		if ( infos.empty() )
		{
			if ( !m_specializationInfos.empty()
				&& std::any_of( m_specializationInfos.begin()
					, m_specializationInfos.end()
					, []( SpecializationInfoOpt const & lookup )
					{
						return bool( lookup );
					} ) )
			{
				std::cerr << "The shader expects specialization constants that were not provided by the user" << std::endl;
				return false;
			}

			return true;
		}

		if ( infos.size() != m_specializationInfos.size() )
		{
			std::cerr << "Mismatch in the count of specialization infos (nullopt counted): "
				<< "Expected " << m_specializationInfos.size() << ", "
				<< "received " << infos.size() << std::endl;
			return false;
		}

		uint32_t index = 0u;
		auto lit = m_specializationInfos.begin();
		auto rit = infos.begin();
		bool globalError = false;

		while ( lit != m_specializationInfos.end() )
		{
			// Check for map entries
			if ( ( *lit && !*rit )
				|| ( !*lit && *rit ) )
			{
				std::cerr << "Mismatch between the " << getName( m_revIndices.at( index ) )
					<< " shader expected specialization infos and the user provided ones." << std::endl;
				globalError = globalError || ( *lit && !*rit );
				++lit;
				++rit;
				++index;
				continue;
			}

			auto lend = lit->value().values.end();
			auto rend = rit->value().pMapEntries + rit->value().mapEntryCount;
			uint32_t error = 0u;

			for ( VkSpecializationMapEntry const & lentry : lit->value().values )
			{
				if ( auto it = std::find_if( rit->value().pMapEntries
					, rend
					, [&lentry]( VkSpecializationMapEntry const & rentry )
					{
						return lentry.constantID == rentry.constantID;
					} );
					it == rend )
				{
					std::cerr << "The " << getName( m_revIndices.at( index ) )
						<< " shader expects a speialization constant at ID " << lentry.constantID
						<< ", which was not provided by the user." << std::endl;
					globalError = true;
					error = 2u;
				}
			}

			std::for_each( rit->value().pMapEntries
				, rend
				, [&index, &error, &lit, &lend, this ]( VkSpecializationMapEntry const & rentry )
				{
					if ( auto it = std::find_if( lit->value().values.begin()
						, lend
						, [&rentry]( VkSpecializationMapEntry const & lentry )
						{
							return lentry.constantID == rentry.constantID;
						} );
						it == lend )
					{
						std::cout << "The user provided a constant at ID " << rentry.constantID
							<< ", the " << getName( m_revIndices.at( index ) )
							<< " shader didn't expect it." << std::endl;
						error = std::max( error, 1u );
					}
				} );

			std::stringstream stream;
			stream << "Shader expects:\n"
				<< m_specializationInfos
				<< "\nUser provided:\n"
				<< infos;

			if ( error == 2u )
			{
				std::cerr << stream.str() << std::endl;
			}
			else if ( error == 1u )
			{
				std::cout << stream.str() << std::endl;
			}

			++lit;
			++rit;
			++index;
		}

		return !globalError;
	}

	//*********************************************************************************************
}
