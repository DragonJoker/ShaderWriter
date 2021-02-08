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
	option( SDW_GENERATE_SOURCE "Build source files from .enum files, using Python" ON )
endif ()
if ( DEFINED SDW_BUILD_STATIC_EXPORTERS )
	set( SDW_BUILD_EXPORTER_GLSL_STATIC ${SDW_BUILD_STATIC_EXPORTERS} )
	set( SDW_BUILD_EXPORTER_HLSL_STATIC ${SDW_BUILD_STATIC_EXPORTERS} )
	set( SDW_BUILD_EXPORTER_SPIRV_STATIC ${SDW_BUILD_STATIC_EXPORTERS} )
else ()
	option( SDW_BUILD_EXPORTERS "Build all exporter plugins as a static libraries" OFF )
endif ()
# Force static build for ShaderWriter if any exporter is staticly linked.
if ( SDW_BUILD_EXPORTER_GLSL_STATIC
	OR SDW_BUILD_EXPORTER_HLSL_STATIC
	OR SDW_BUILD_EXPORTER_SPIRV_STATIC )
	set( SDW_BUILD_STATIC_SDW ON )
	set( SDW_BUILD_STATIC_SDAST ON )
endif ()
if ( NOT DEFINED SDW_BUILD_STATIC_SDW )
	option( SDW_BUILD_STATIC_SDW "Build ShaderWriter as a static library" OFF )
endif ()
if ( NOT DEFINED SDW_BUILD_STATIC_SDAST )
	option( SDW_BUILD_STATIC_SDAST "Build ShaderAST as a static library" OFF )
endif ()

if ( SDW_GENERATE_SOURCE )
	find_package( PythonInterp QUIET )
endif ()

if ( WIN32 )
	set( SDW_LIB_PREFIX sdw )
else ()
	set( SDW_LIB_PREFIX libsdw )
endif ()

add_subdirectory( ShaderAST )
add_subdirectory( ShaderWriter )
add_subdirectory( VulkanLayer )

if ( SDW_BUILD_EXPORTERS )
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

install(
	TARGETS ShaderAST ShaderWriter ${SDW_INSTEXP_LIST}
	EXPORT ShaderWriter
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
install( EXPORT ShaderWriter
	FILE ShaderWriterConfig.cmake
	NAMESPACE sdw::
	DESTINATION lib/cmake/shaderwriter
)
include(CMakePackageConfigHelpers)
write_basic_package_version_file( ShaderWriterConfigVersion.cmake
	VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD}
	COMPATIBILITY AnyNewerVersion
)
