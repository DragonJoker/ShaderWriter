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
		set( SDW_BUILD_GLSL TRUE )
	else ()
		set( SDW_BUILD_GLSL FALSE)
	endif ()
	if ( NOT DEFINED SDW_BUILD_EXPORTER_HLSL )
		option( SDW_BUILD_EXPORTER_HLSL "Build HLSL exporter" ON )
	endif ()
	if ( SDW_BUILD_EXPORTER_HLSL )
		set( SDW_BUILD_HLSL TRUE )
	else ()
		set( SDW_BUILD_HLSL FALSE)
	endif ()
	if ( NOT DEFINED SDW_BUILD_EXPORTER_SPIRV )
		option( SDW_BUILD_EXPORTER_SPIRV "Build SPIRV exporter" ON )
	endif ()
	if ( SDW_BUILD_EXPORTER_SPIRV )
		set( SDW_BUILD_SPIRV TRUE )
	else ()
		set( SDW_BUILD_SPIRV FALSE)
	endif ()
endif ()

if ( NOT DEFINED SDW_GENERATE_SOURCE )
	option( SDW_GENERATE_SOURCE "Build source files from .enum files, using Python" ON )
endif ()

if ( SDW_GENERATE_SOURCE )
	find_package( PythonInterp )
endif ()

add_subdirectory( ShaderAST )
add_subdirectory( ShaderWriter )

if ( SDW_BUILD_EXPORTERS )
	set( SDW_EXPORTERS_DEFINITIONS )
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

	set( SDW_EXPORTERS_DEFINITIONS
		${SDW_EXPORTERS_DEFINITIONS}
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
	DESTINATION lib/shaderwriter/cmake
)
include(CMakePackageConfigHelpers)
write_basic_package_version_file( ShaderWriterConfigVersion.cmake
	VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD}
	COMPATIBILITY AnyNewerVersion
)
