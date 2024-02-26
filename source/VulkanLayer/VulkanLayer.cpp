/*
See LICENSE file in root folder
*/
#include "VulkanLayer/VulkanLayer.hpp"

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <iostream>
#include <sstream>
#pragma warning( pop )

namespace ast::vk
{
	bool checkError( VkResult result )
	{
		if ( result == VK_SUCCESS )
		{
			return true;
		}

		std::stringstream stream;
		stream << "Vulkan Error: ";

		switch ( result )
		{
		case VK_SUCCESS: stream << "vk_success"; break;
		case VK_NOT_READY: stream << "vk_not_ready"; break;
		case VK_TIMEOUT: stream << "vk_timeout"; break;
		case VK_EVENT_SET: stream << "vk_event_set"; break;
		case VK_EVENT_RESET: stream << "vk_event_reset"; break;
		case VK_INCOMPLETE: stream << "vk_incomplete"; break;
		case VK_ERROR_OUT_OF_HOST_MEMORY: stream << "vk_error_out_of_host_memory"; break;
		case VK_ERROR_OUT_OF_DEVICE_MEMORY: stream << "vk_error_out_of_device_memory"; break;
		case VK_ERROR_INITIALIZATION_FAILED: stream << "vk_error_initialization_failed"; break;
		case VK_ERROR_DEVICE_LOST: stream << "vk_error_device_lost"; break;
		case VK_ERROR_MEMORY_MAP_FAILED: stream << "vk_error_memory_map_failed"; break;
		case VK_ERROR_LAYER_NOT_PRESENT: stream << "vk_error_layer_not_present"; break;
		case VK_ERROR_EXTENSION_NOT_PRESENT: stream << "vk_error_extension_not_present"; break;
		case VK_ERROR_FEATURE_NOT_PRESENT: stream << "vk_error_feature_not_present"; break;
		case VK_ERROR_INCOMPATIBLE_DRIVER: stream << "vk_error_incompatible_driver"; break;
		case VK_ERROR_TOO_MANY_OBJECTS: stream << "vk_error_too_many_objects"; break;
		case VK_ERROR_FORMAT_NOT_SUPPORTED: stream << "vk_error_format_not_supported"; break;
		case VK_ERROR_FRAGMENTED_POOL: stream << "vk_error_fragmented_pool"; break;
#if VK_VERSION_1_1
		case VK_ERROR_OUT_OF_POOL_MEMORY: stream << "vk_error_out_of_pool_memory"; break;
		case VK_ERROR_INVALID_EXTERNAL_HANDLE: stream << "vk_error_invalid_external_handle"; break;
#else
#	if VK_KHR_maintenance1
		case VK_ERROR_OUT_OF_POOL_MEMORY_KHR: stream << "vk_error_out_of_pool_memory"; break;
#	endif
#	if VK_KHR_external_memory
		case VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR: stream << "vk_error_invalid_external_handle"; break;
#	endif
#endif
#if VK_VERSION_1_2
		case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: stream << "vk_error_invalid_opaque_capture_address"; break;
		case VK_ERROR_UNKNOWN: stream << "vk_error_unknown"; break;
		case VK_ERROR_FRAGMENTATION: stream << "vk_error_fragmentation"; break;
		case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: stream << "vk_error_full_screen_exclusive_mode_lost"; break;
#else
#	if VK_EXT_descriptor_indexing
		case VK_ERROR_FRAGMENTATION_EXT: stream << "vk_error_fragmentation"; break;
#	endif
#	if VK_EXT_buffer_device_address 
		case VK_ERROR_INVALID_DEVICE_ADDRESS_EXT: stream << "vk_error_invalid_device_address"; break;
#	elif VK_KHR_buffer_device_address
		case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR: stream << "vk_error_invalid_opaque_capture_address"; break;
#	endif
#endif
#if VK_KHR_surface
		case VK_ERROR_SURFACE_LOST_KHR: stream << "vk_error_surface_lost"; break;
		case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: stream << "vk_error_native_window_in_use"; break;
#endif
#if VK_KHR_swapchain
		case VK_SUBOPTIMAL_KHR: stream << "vk_suboptimal"; break;
		case VK_ERROR_OUT_OF_DATE_KHR: stream << "vk_error_out_of_date"; break;
		case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: stream << "vk_error_incompatible_display"; break;
#endif
#if VK_KHR_deferred_host_operations || (VK_HEADER_VERSION >= 140)
		case VK_THREAD_IDLE_KHR: stream << "vk_thread_idle"; break;
		case VK_THREAD_DONE_KHR: stream << "vk_thread_done"; break;
		case VK_OPERATION_DEFERRED_KHR: stream << "vk_operation_deferred"; break;
		case VK_OPERATION_NOT_DEFERRED_KHR: stream << "vk_operation_not_deferred"; break;
#endif
#if VK_KHR_ray_tracing
		case VK_ERROR_INCOMPATIBLE_VERSION_KHR: stream << "vk_error_incompatible_version"; break;
#endif
#if VK_EXT_debug_report
		case VK_ERROR_VALIDATION_FAILED_EXT: stream << "vk_error_validation_failed"; break;
#endif
#if VK_EXT_image_drm_format_modifier
		case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: stream << "vk_error_invalid_drm_format_modifier_plane_layout"; break;
#endif
#if VK_EXT_global_priority
		case VK_ERROR_NOT_PERMITTED_EXT: stream << "vk_error_not_permitted"; break;
#endif
#if VK_EXT_full_screen_exclusive
		case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: stream << "vk_error_full_screen_exclusive_mode_lost"; break;
#endif
#if VK_EXT_pipeline_creation_cache_control && VK_EXT_PIPELINE_CREATION_CACHE_CONTROL_SPEC_VERSION >= 3
		case VK_PIPELINE_COMPILE_REQUIRED_EXT: stream << "vk_pipeline_compile_required"; break;
#endif
#if VK_NV_glsl_shader
		case VK_ERROR_INVALID_SHADER_NV: stream << "vk_error_invalid_shader"; break;
#endif
#if VK_EXT_image_compression_control
		case VK_ERROR_COMPRESSION_EXHAUSTED_EXT: stream << "vk_error_compression_exhausted"; break;
#endif
#if VK_HEADER_VERSION < 140
		case VK_RESULT_RANGE_SIZE: stream << "vk_result_range_size"; break;
#endif
#if VK_KHR_video_queue
		case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR: stream << "vk_error_image_usage_not_supported"; break;
		case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR: stream << "vk_error_video_picture_layout_not_supported"; break;
		case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR: stream << "vk_error_video_profile_operation_not_supported"; break;
		case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR: stream << "vk_error_video_profile_format_not_supported"; break;
		case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR: stream << "vk_error_video_profile_codec_not_supported"; break;
		case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR: stream << "vk_error_video_std_version_not_supported"; break;
#endif
#if VK_KHR_video_encode_queue
		case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR: stream << "The specified Video Std parameters do not adhere to the syntactic or semantic requirements of the used video compression standard, or values derived from parameters according to the rules defined by the used video compression standard do not adhere to the capabilities of the video compression standard or the implementation."; break;
#endif
#if VK_EXT_shader_object
		case VK_ERROR_INCOMPATIBLE_SHADER_BINARY_EXT: stream << "The provided binary shader code is not compatible with this device"; break;
#endif
		case VK_RESULT_MAX_ENUM: stream << "vk_result_max_enum"; break;
		}

		std::cerr << stream.str() << std::endl;
		return false;
	}
}
