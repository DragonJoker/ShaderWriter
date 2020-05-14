/*
See LICENSE file in root folder
*/
#include "VulkanLayer/VulkanLayer.hpp"

#include <iostream>
#include <sstream>

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
		case VK_ERROR_OUT_OF_POOL_MEMORY: stream << "vk_error_out_of_pool_memory"; break;
		case VK_ERROR_INVALID_EXTERNAL_HANDLE: stream << "vk_error_invalid_external_handle"; break;
		case VK_ERROR_SURFACE_LOST_KHR: stream << "vk_error_surface_lost_khr"; break;
		case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: stream << "vk_error_native_window_in_use_khr"; break;
		case VK_SUBOPTIMAL_KHR: stream << "vk_suboptimal_khr"; break;
		case VK_ERROR_OUT_OF_DATE_KHR: stream << "vk_error_out_of_date_khr"; break;
		case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: stream << "vk_error_incompatible_display_khr"; break;
		case VK_ERROR_VALIDATION_FAILED_EXT: stream << "vk_error_validation_failed_ext"; break;
		case VK_ERROR_INVALID_SHADER_NV: stream << "vk_error_invalid_shader_nv"; break;
		case VK_ERROR_NOT_PERMITTED_EXT: stream << "vk_error_not_permitted_ext"; break;
#if VK_VERSION_1_2 
		case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: stream << "vk_error_invalid_opaque_capture_address"; break;
		case VK_ERROR_UNKNOWN: stream << "vk_error_unknown"; break;
		case VK_ERROR_FRAGMENTATION: stream << "vk_error_fragmentation"; break;
		case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: stream << "vk_error_full_screen_exclusive_mode_lost_ext"; break;
#else
#	if VK_EXT_descriptor_indexing
		case VK_ERROR_FRAGMENTATION_EXT: stream << "vk_error_fragmentation_ext"; break;
#	endif
#	if VK_KHR_buffer_device_address 
		case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR: stream << "vk_error_invalid_opaque_capture_address_khr"; break;
#	elif VK_EXT_buffer_device_address 
		case VK_ERROR_INVALID_DEVICE_ADDRESS_EXT: stream << "vk_error_invalid_device_address_ext"; break;
#	endif
#endif
#if VK_EXT_image_drm_format_modifier
		case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: stream << "vk_error_invalid_drm_format_modifier_plane_layout_ext"; break;
#endif
#if VK_EXT_full_screen_exclusive
		case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: stream << "vk_error_full_screen_exclusive_mode_lost_ext"; break;
#endif
		default: stream << "Unknown error"; break;
		}

		std::cerr << stream.str() << std::endl;
		return false;
	}
}
