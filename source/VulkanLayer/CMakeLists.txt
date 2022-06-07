if ( NOT DEFINED SDW_BUILD_VULKAN_LAYER )
	option( SDW_BUILD_VULKAN_LAYER "Build VulkanLayer library" ON )
endif ()

set( _FOLDER_NAME VulkanLayer )
project( ${_FOLDER_NAME} )

find_package( Vulkan )

if ( SDW_BUILD_VULKAN_LAYER AND Vulkan_FOUND )
	set( ${PROJECT_NAME}_VERSION_MAJOR 2 )
	set( ${PROJECT_NAME}_VERSION_MINOR 3 )
	set( ${PROJECT_NAME}_VERSION_BUILD 0 )
	set( ${PROJECT_NAME}_VERSION_YEAR 2022 )

	set( PROJECT_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}" )
	set( PROJECT_SOVERSION "${${PROJECT_NAME}_VERSION_BUILD}" )

	set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/${_FOLDER_NAME} )
	set( SOURCE_DIR ${SDW_SOURCE_DIR}/source/${_FOLDER_NAME} )

	set( ${PROJECT_NAME}_HEADER_FILES
		${INCLUDE_DIR}/ArrayHolder.hpp
		${INCLUDE_DIR}/BuilderContext.hpp
		${INCLUDE_DIR}/MakeVkType.hpp
		${INCLUDE_DIR}/PipelineBuilder.hpp
		${INCLUDE_DIR}/PipelineShaderStageCreateInfo.hpp
		${INCLUDE_DIR}/ProgramPipeline.hpp
		${INCLUDE_DIR}/ShaderDataPtr.hpp
		${INCLUDE_DIR}/ShaderStageFlag.hpp
		${INCLUDE_DIR}/VulkanLayer.hpp
	)
	set( ${PROJECT_NAME}_SOURCE_FILES
		${SOURCE_DIR}/PipelineBuilder.cpp
		${SOURCE_DIR}/ProgramPipeline.cpp
		${SOURCE_DIR}/ShaderDataPtr.cpp
		${SOURCE_DIR}/VulkanLayer.cpp
	)
	add_library( ${PROJECT_NAME}
		STATIC
		${${PROJECT_NAME}_HEADER_FILES}
		${${PROJECT_NAME}_SOURCE_FILES}
		${${PROJECT_NAME}_SCRIPT_FILES}
	)
	add_library( sdw::${_FOLDER_NAME}
		ALIAS
		${PROJECT_NAME}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PUBLIC
			${_FOLDER_NAME}_Static
			SDW_Has${_FOLDER_NAME}
	)
	target_link_libraries( ${PROJECT_NAME}
		PUBLIC
			sdw::CompilerSpirV
		PRIVATE
			${Vulkan_LIBRARIES}
	)
	set_target_properties( ${PROJECT_NAME}
		PROPERTIES
			VERSION ${PROJECT_VERSION}
			SOVERSION ${PROJECT_SOVERSION}
			CXX_STANDARD 20
			PREFIX sdw
			FOLDER "${SDW_BASE_DIR}/Core"
			UNITY_BUILD "${SDW_UNITY_BUILD}"
	)
	target_include_directories( ${PROJECT_NAME}
		PRIVATE
			${SDW_SOURCE_DIR}/source
			${INCLUDE_DIR}
			${SOURCE_DIR}
		PUBLIC
			$<BUILD_INTERFACE:${Vulkan_INCLUDE_DIRS}>
	)
	target_add_compilation_flags( ${PROJECT_NAME} )
	target_install_headers( ${PROJECT_NAME}
		${SDW_SOURCE_DIR}/include/${_FOLDER_NAME}
	)

	set( SDW_INSTEXP_LIST
		${SDW_INSTEXP_LIST}
		${PROJECT_NAME}
		PARENT_SCOPE
	)
endif ()
