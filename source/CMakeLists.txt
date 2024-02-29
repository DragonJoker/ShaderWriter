add_compile_options( $<$<CXX_COMPILER_ID:MSVC>:/MP> )
add_compile_options( $<$<CXX_COMPILER_ID:MSVC>:/bigobj> )

set( TargetCompileDefinitions
	SDW_VERSION_MAJOR=${VERSION_MAJOR}
	SDW_VERSION_MINOR=${VERSION_MINOR}
	SDW_VERSION_BUILD=${VERSION_BUILD}
)

get_filename_component( SDW_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY )
get_filename_component( SDW_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY )

if ( SDW_BUILD_EXPORTERS )
	set( SDW_EXPORTERS_LIST )
	if ( NOT DEFINED SDW_BUILD_EXPORTER_GLSL )
		option( SDW_BUILD_EXPORTER_GLSL "Build GLSL exporter" ON )
	endif ()
	if ( SDW_BUILD_EXPORTER_GLSL )
		set( SDW_BUILD_GLSL ON )
	else ()
		set( SDW_BUILD_GLSL OFF )
	endif ()
	if ( NOT DEFINED SDW_BUILD_EXPORTER_HLSL )
		option( SDW_BUILD_EXPORTER_HLSL "Build HLSL exporter" ON )
	endif ()
	if ( SDW_BUILD_EXPORTER_HLSL )
		set( SDW_BUILD_HLSL ON )
	else ()
		set( SDW_BUILD_HLSL OFF )
	endif ()
	if ( NOT DEFINED SDW_BUILD_EXPORTER_SPIRV )
		option( SDW_BUILD_EXPORTER_SPIRV "Build SPIRV exporter" ON )
	endif ()
	if ( SDW_BUILD_EXPORTER_SPIRV )
		set( SDW_BUILD_SPIRV ON )
	else ()
		set( SDW_BUILD_SPIRV OFF )
	endif ()
endif ()

if ( NOT DEFINED SDW_GENERATE_SOURCE )
	option( SDW_GENERATE_SOURCE "Build source files from .enum files, using Python" OFF )
endif ()
if ( SDW_GENERATE_SOURCE )
	find_package( Python QUIET COMPONENTS Interpreter )
endif ()

if ( ( DEFINED SDW_BUILD_STATIC_EXPORTERS )
	AND SDW_BUILD_STATIC_EXPORTERS )
	set( SDW_BUILD_STATIC ON )
endif ()
if ( ( DEFINED SDW_BUILD_STATIC_SDW )
	AND SDW_BUILD_STATIC_SDW )
	set( SDW_BUILD_STATIC ON )
endif ()
if ( ( DEFINED SDW_BUILD_STATIC_SDAST )
	AND SDW_BUILD_STATIC_SDAST )
	set( SDW_BUILD_STATIC ON )
endif ()
if ( NOT DEFINED SDW_BUILD_STATIC )
	option( SDW_BUILD_STATIC "Build all libraries as a static libraries" OFF )
endif ()

if ( WIN32 )
	set( SDW_LIB_PREFIX sdw )
else ()
	set( SDW_LIB_PREFIX libsdw )
endif ()

add_subdirectory( ShaderAST )
add_subdirectory( VulkanLayer )

if ( SDW_BUILD_WRITER )
	add_subdirectory( ShaderWriter )
endif ()

if ( SDW_BUILD_EXPORTERS )
	if ( SDW_BUILD_GLSL OR SDW_BUILD_SPIRV )
		add_subdirectory( GlslCommon )
	endif ()

	if ( SDW_BUILD_GLSL )
		add_subdirectory( CompilerGlsl )
	endif ()

	if ( SDW_BUILD_HLSL )
		add_subdirectory( CompilerHlsl )
	endif ()

	if ( SDW_BUILD_SPIRV )
		add_subdirectory( CompilerSpirV )
	endif ()

	set( SDW_EXPORTERS_LIST
		${SDW_EXPORTERS_LIST}
		PARENT_SCOPE
	)
endif ()

if ( SDW_BUILD_WRITER )
	install(
		TARGETS ShaderAST ShaderWriter ${SDW_INSTEXP_LIST}
		COMPONENT ShaderWriter
		EXPORT ShaderWriter
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
	)
else ()
	install(
		TARGETS ShaderAST ${SDW_INSTEXP_LIST}
		COMPONENT ShaderWriter
		EXPORT ShaderWriter
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
	)
endif ()
install( EXPORT ShaderWriter
	COMPONENT ShaderWriter
	FILE ShaderWriterConfig.cmake
	NAMESPACE sdw::
	DESTINATION lib/cmake/shaderwriter
)
include(CMakePackageConfigHelpers)
write_basic_package_version_file( ShaderWriterConfigVersion.cmake
	VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD}
	COMPATIBILITY AnyNewerVersion
)
