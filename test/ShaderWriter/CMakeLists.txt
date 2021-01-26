file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )

if ( ${CMAKE_VERSION} VERSION_GREATER "3.10.2" ) 
	cmake_policy( SET CMP0072 NEW )
endif()

if ( APPLE )
	option( SDW_TESTS_ENABLE_VALIDATION "Enables validation through respective API (Vulkan, OpenGL, and Direct3D" OFF )
else ()
	option( SDW_TESTS_ENABLE_VALIDATION "Enables validation through respective API (Vulkan, OpenGL, and Direct3D" ON )
endif ()

set( SPIRV_CROSS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../external/SPIRV-Cross )
set( GLSLANG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../external/glslang )

if ( SDW_TESTS_ENABLE_VALIDATION )
	find_package( OpenGL )
	find_package( Vulkan )

	set( OptionalCompileDefinitions )

	if ( ( TARGET CompilerGlsl )
		AND ( OpenGL_FOUND OR OPENGL_FOUND )
		AND ( WIN32 ) )
		if ( WIN32 )
			set( TargetLinkLibraries
				${TargetLinkLibraries}
				OpenGL::GL
			)
		else ()
			find_package( X11 )
			set( TargetLinkLibraries
				${TargetLinkLibraries}
				${X11_X11_LIB}
				OpenGL::GLX
				OpenGL::OpenGL
			)
		endif ()
		set( OptionalCompileDefinitions
			${OptionalCompileDefinitions}
			SDW_Test_HasOpenGL=1
		)
	endif ()

	if ( ( TARGET CompilerSpirV )
		AND ( Vulkan_FOUND OR VULKAN_FOUND ) )
		set( TargetIncludeDirectories
			${TargetIncludeDirectories}
			${Vulkan_INCLUDE_DIR}
		)
		set( TargetLinkLibraries
			${TargetLinkLibraries}
			${Vulkan_LIBRARY}
		)
		set( OptionalCompileDefinitions
			${OptionalCompileDefinitions}
			SDW_Test_HasVulkan=1
		)
		if ( SDW_BUILD_VULKAN_LAYER )
			set( TargetLinkLibraries
				${TargetLinkLibraries}
				sdw::VulkanLayer
			)
		endif ()
	endif ()

	if ( ( TARGET CompilerHlsl )
		AND WIN32 )
		set( OptionalCompileDefinitions
			${OptionalCompileDefinitions}
			SDW_Test_HasDirect3D11=1
		)
	endif ()
endif ()

if ( NOT TARGET glslang )
	set( ENABLE_GLSLANG_BINARIES FALSE CACHE BOOL "Builds glslangValidator and spirv-remap" FORCE )
	set( ENABLE_AMD_EXTENSIONS FALSE CACHE BOOL "Enables support of AMD-specific extensions" FORCE )
	set( ENABLE_NV_EXTENSIONS FALSE CACHE BOOL "Enables support of Nvidia-specific extensions" FORCE )
	set( ENABLE_HLSL FALSE CACHE BOOL "Enables HLSL input support" FORCE )
	set( BUILD_TESTING OFF )
	set( SKIP_GLSLANG_INSTALL ON )
	add_subdirectory( ${GLSLANG_DIR} ${CMAKE_BINARY_DIR}/external/glslang )
	set_property( TARGET glslang PROPERTY FOLDER "glslang" )
	set_property( TARGET OGLCompiler PROPERTY FOLDER "glslang" )
	set_property( TARGET OSDependent PROPERTY FOLDER "glslang" )
	set_property( TARGET SPIRV PROPERTY FOLDER "glslang" )
	set_property( TARGET SPVRemapper PROPERTY FOLDER "glslang" )
endif ()

set( TEST_WRITER_COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/WriterCommon.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/GlslToSpv.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileHLSL.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileGLSL.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileSPIRV.hpp
	${SPIRV_CROSS_DIR}/GLSL.std.450.h
	${SPIRV_CROSS_DIR}/spirv_common.hpp
	${SPIRV_CROSS_DIR}/spirv.hpp
	${SPIRV_CROSS_DIR}/spirv_cross.hpp
	${SPIRV_CROSS_DIR}/spirv_cross_parsed_ir.hpp
	${SPIRV_CROSS_DIR}/spirv_parser.hpp
	${SPIRV_CROSS_DIR}/spirv_cfg.hpp
	${SPIRV_CROSS_DIR}/spirv_glsl.hpp
	${SPIRV_CROSS_DIR}/spirv_hlsl.hpp
)
set( TEST_WRITER_COMMON_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/WriterCommon.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/GlslToSpv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileHLSL.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileGLSL.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileSPIRV.cpp
	${SPIRV_CROSS_DIR}/spirv_cross.cpp
	${SPIRV_CROSS_DIR}/spirv_cross_parsed_ir.cpp
	${SPIRV_CROSS_DIR}/spirv_parser.cpp
	${SPIRV_CROSS_DIR}/spirv_cfg.cpp
	${SPIRV_CROSS_DIR}/spirv_glsl.cpp
	${SPIRV_CROSS_DIR}/spirv_hlsl.cpp
)

add_library( TestWriterCommon
	STATIC
	${TEST_WRITER_COMMON_HEADER_FILES}
	${TEST_WRITER_COMMON_SOURCE_FILES}
)
add_library( sdw::test::WriterCommon
	ALIAS
	TestWriterCommon
)
target_link_libraries( TestWriterCommon
	PUBLIC
		sdw::ShaderAST
		sdw::ShaderWriter
		${BinLibraries}
		glslang
		OGLCompiler
		OSDependent
		SPVRemapper
		SPIRV
		sdw::test::Common
		${TargetLinkLibraries}
)
target_compile_definitions( TestWriterCommon
	PUBLIC
		${OptionalCompileDefinitions}
)
target_include_directories( TestWriterCommon
	PUBLIC
		${SPIRV_CROSS_DIR}
		${GLSLANG_DIR}
)
set_target_properties( TestWriterCommon
	PROPERTIES
		CXX_STANDARD 17
		FOLDER "Tests/ShaderWriter"
)
set( TargetLinkLibraries
	sdw::test::WriterCommon
)

if ( PROJECTS_COVERAGE )
	set( PROJECTS_COVERAGE_LIB_FILES
		${PROJECTS_COVERAGE_LIB_FILES}
		sdw::test::WriterCommon
	)
endif ()

foreach ( TEST_FILE ${TEST_FILES} )
	get_filename_component( TEST_NAME ${TEST_FILE} NAME_WE )
	if ( PROJECTS_COVERAGE )
		set( PROJECTS_COVERAGE_SRC_FILES
			${PROJECTS_COVERAGE_SRC_FILES}
			${TEST_FILE}
		)
		set( PROJECTS_COVERAGE_TEST_NAMES
			${PROJECTS_COVERAGE_TEST_NAMES}
			${TEST_NAME}
		)
	endif ()
	add_executable( ${TEST_NAME}
		$<TARGET_OBJECTS:TestCommon>
		${TEST_FILE}
	)
	target_link_libraries( ${TEST_NAME} PRIVATE
		${TargetLinkLibraries}
	)
	target_include_directories( ${TEST_NAME} PRIVATE
		${TargetIncludeDirectories}
	)
	target_compile_definitions( ${TEST_NAME} PRIVATE
		${TargetCompileDefinitions}
		SDW_COMPILE_TESTS
	)
	set_target_properties( ${TEST_NAME} PROPERTIES
		CXX_STANDARD 17
		FOLDER "Tests/ShaderWriter"
	)

	if ( MSVC )
		target_compile_options( ${TEST_NAME} PRIVATE
			-bigobj
		)

		if ( PROJECTS_COVERAGE )
			OpenCppCoverage_add_target( ${TEST_NAME}
				MODULES $<TARGET_FILE_NAME:ShaderAST> $<TARGET_FILE_NAME:ShaderWriter>
				SOURCES ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/source
			)
		endif ()
	endif ()

	add_test(
		NAME ${TEST_NAME}
		COMMAND ${TEST_NAME}
	)
endforeach ()

if ( PROJECTS_COVERAGE )
	set( PROJECTS_COVERAGE_LIB_FILES
		${PROJECTS_COVERAGE_LIB_FILES}
		PARENT_SCOPE
	)
	set( PROJECTS_COVERAGE_SRC_FILES
		${PROJECTS_COVERAGE_SRC_FILES}
		PARENT_SCOPE
	)
	set( PROJECTS_COVERAGE_TEST_NAMES
		${PROJECTS_COVERAGE_TEST_NAMES}
		PARENT_SCOPE
	)
endif ()
