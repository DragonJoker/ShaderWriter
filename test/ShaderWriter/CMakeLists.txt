file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )

if ( ${CMAKE_VERSION} VERSION_GREATER "3.10.2" ) 
	cmake_policy( SET CMP0072 NEW )
endif()

option( SDW_TESTS_ENABLE_VALIDATION "Enables validation through respective API (Vulkan, OpenGL, and Direct3D" OFF )

if ( SDW_TESTS_ENABLE_VALIDATION )
	set( CMAKE_MAP_IMPORTED_CONFIG_MINSIZEREL "" Release )
	set( CMAKE_MAP_IMPORTED_CONFIG_RELWITHDEBINFO "" Release )
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

	if ( ( TARGET CompilerHlsl ) AND WIN32 )
		set( OptionalCompileDefinitions
			${OptionalCompileDefinitions}
			SDW_Test_HasDirect3D11=1
		)
		find_package( DXC )
		if ( DXC_FOUND )
			set( OptionalCompileDefinitions
				${OptionalCompileDefinitions}
				SDW_Test_HasDXC=1
			)
			set( TargetLinkLibraries
				${TargetLinkLibraries}
				DXC::dxc
			)
		endif ()
	endif ()
endif ()

if ( VCPKG_TOOLCHAIN )
	find_package( glslang CONFIG REQUIRED glslang OGLCompiler OSDependent SPIRV SPVRemapper )
	get_target_property( glslang_INCLUDE_DIR SPIRV INTERFACE_INCLUDE_DIRECTORIES )
	set( TargetLinkLibraries
		${TargetLinkLibraries}
		OSDependent
		glslang
		OGLCompiler
		SPIRV
		SPVRemapper
	)
	find_package( SPIRV-Tools CONFIG )
	if ( SPIRV-Tools_FOUND )
		set( TargetLinkLibraries
			${TargetLinkLibraries}
			SPIRV-Tools-static
		)
		set( OptionalCompileDefinitions
			${OptionalCompileDefinitions}
			SDW_Test_HasSpirVTools=1
		)
	endif ()
elseif ( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../external/glslang/ )
	set( glslang_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../external )
	if ( NOT TARGET glslang )
		set( ENABLE_GLSLANG_BINARIES FALSE CACHE BOOL "Builds glslangValidator and spirv-remap" FORCE )
		set( ENABLE_AMD_EXTENSIONS FALSE CACHE BOOL "Enables support of AMD-specific extensions" FORCE )
		set( ENABLE_NV_EXTENSIONS FALSE CACHE BOOL "Enables support of Nvidia-specific extensions" FORCE )
		set( ENABLE_HLSL FALSE CACHE BOOL "Enables HLSL input support" FORCE )
		set( BUILD_TESTING OFF )
		set( SKIP_GLSLANG_INSTALL ON )
		add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/../../external/glslang ${CMAKE_BINARY_DIR}/external/glslang )
		set_property( TARGET glslang PROPERTY FOLDER "External/glslang" )
		set_property( TARGET OGLCompiler PROPERTY FOLDER "External/glslang" )
		set_property( TARGET OSDependent PROPERTY FOLDER "External/glslang" )
		set_property( TARGET SPIRV PROPERTY FOLDER "External/glslang" )
		set_property( TARGET SPVRemapper PROPERTY FOLDER "External/glslang" )
	endif ()
	set( TargetLinkLibraries
		${TargetLinkLibraries}
		OSDependent
		glslang
		OGLCompiler
		SPIRV
		SPVRemapper
	)
	find_package( SPIRV-Tools )
	if ( SPIRV-Tools_FOUND )
		set( TargetLinkLibraries
			${TargetLinkLibraries}
			SPIRV-Tools
		)
		set( OptionalCompileDefinitions
			${OptionalCompileDefinitions}
			SDW_Test_HasSpirVTools=1
		)
	endif ()
else ()
	message( FATAL_ERROR "glslang_INCLUDE_DIR couldn't be defined." )
endif ()

set( SPIRV_CROSS_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/../../external/SPIRV-Cross
)
if ( EXISTS ${SPIRV_CROSS_DIR}/spirv.hpp )
	set( SPIRV_CROSS_HEADER_FILES
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
	set( SPIRV_CROSS_SOURCE_FILES
		${SPIRV_CROSS_DIR}/spirv_cross.cpp
		${SPIRV_CROSS_DIR}/spirv_cross_parsed_ir.cpp
		${SPIRV_CROSS_DIR}/spirv_parser.cpp
		${SPIRV_CROSS_DIR}/spirv_cfg.cpp
		${SPIRV_CROSS_DIR}/spirv_glsl.cpp
		${SPIRV_CROSS_DIR}/spirv_hlsl.cpp
	)
	add_library( SdwSpirvCross
		STATIC
		${SPIRV_CROSS_HEADER_FILES}
		${SPIRV_CROSS_SOURCE_FILES}
	)
	add_library( sdw::test::SpirvCross
		ALIAS
		SdwSpirvCross
	)
	target_include_directories( SdwSpirvCross
		PUBLIC
			${SPIRV_CROSS_DIR}
	)
	set_target_properties( SdwSpirvCross
		PROPERTIES
			CXX_STANDARD 20
			FOLDER "Tests/ShaderWriter"
	)
	set( TargetLinkLibraries
		${TargetLinkLibraries}
		sdw::test::SpirvCross
	)
	set( OptionalCompileDefinitions
		${OptionalCompileDefinitions}
		SDW_Test_HasSpirVCross=1
	)
endif ()

set( TEST_WRITER_COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/WriterCommon.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/GlslToSpv.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileHLSL.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileGLSL.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileSPIRV.hpp
)
set( TEST_WRITER_COMMON_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/WriterCommon.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/GlslToSpv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileHLSL.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileGLSL.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileSPIRV.cpp
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
		sdw::test::Common
		${BinLibraries}
		${TargetLinkLibraries}
)
target_compile_definitions( TestWriterCommon
	PUBLIC
		${OptionalCompileDefinitions}
)
target_include_directories( TestWriterCommon
	PUBLIC
		${GLSLANG_DIR}
		${glslang_INCLUDE_DIR}
)
target_add_compilation_flags( TestWriterCommon )
set_target_properties( TestWriterCommon
	PROPERTIES
		CXX_STANDARD 20
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

set( IMAGE_FORMATS
	eRgba32f
	eRgba16f
	eRg32f
	eRg16f
	eR32f
	eR16f
	eRgba32i
	eRgba16i
	eRgba8i
	eRg32i
	eRg16i
	eRg8i
	eR32i
	eR16i
	eR8i
	eRgba32u
	eRgba16u
	eRgba8u
	eRg32u
	eRg16u
	eRg8u
	eR32u
	eR16u
	eR8u
)

set( BO_TYPES
	Int8
	Int16
	Int32
	Int64
	UInt8
	UInt16
	UInt32
	UInt64
	Float
	Double
	Vec2
	Vec3
	Vec4
	DVec2
	DVec3
	DVec4
	I8Vec2
	I8Vec3
	I8Vec4
	I16Vec2
	I16Vec3
	I16Vec4
	I32Vec2
	I32Vec3
	I32Vec4
	I64Vec2
	I64Vec3
	I64Vec4
	U8Vec2
	U8Vec3
	U8Vec4
	U16Vec2
	U16Vec3
	U16Vec4
	U32Vec2
	U32Vec3
	U32Vec4
	U64Vec2
	U64Vec3
	U64Vec4
	Mat2x2
	Mat2x3
	Mat2x4
	Mat3x2
	Mat3x3
	Mat3x4
	Mat4x2
	Mat4x3
	Mat4x4
	DMat2x2
	DMat2x3
	DMat2x4
	DMat3x2
	DMat3x3
	DMat3x4
	DMat4x2
	DMat4x3
	DMat4x4
)

function( SDW_AddTest TEST_FILE TEST_NAME NAME_SUFFIX ADDITIONAL_DEFINITIONS )
	set( REAL_TEST_NAME ${TEST_NAME}${NAME_SUFFIX} )
	if ( PROJECTS_COVERAGE )
		set( PROJECTS_COVERAGE_SRC_FILES
			${PROJECTS_COVERAGE_SRC_FILES}
			${TEST_FILE}
		)
		set( PROJECTS_COVERAGE_TEST_NAMES
			${PROJECTS_COVERAGE_TEST_NAMES}
			${REAL_TEST_NAME}
		)
	endif ()
	add_executable( ${REAL_TEST_NAME}
		$<TARGET_OBJECTS:TestCommon>
		${TEST_FILE}
	)
	target_link_libraries( ${REAL_TEST_NAME} PRIVATE
		${TargetLinkLibraries}
	)
	target_include_directories( ${REAL_TEST_NAME} PRIVATE
		${TargetIncludeDirectories}
	)
	target_compile_definitions( ${REAL_TEST_NAME} PRIVATE
		${TargetCompileDefinitions}
		${ADDITIONAL_DEFINITIONS}
		SDW_COMPILE_TESTS
	)
	target_add_compilation_flags( ${REAL_TEST_NAME} )
	if ( "${NAME_SUFFIX}" STREQUAL "" )
		set_target_properties( ${REAL_TEST_NAME} PROPERTIES
			CXX_STANDARD 20
			FOLDER "Tests/ShaderWriter"
		)
	else ()
		set_target_properties( ${REAL_TEST_NAME} PROPERTIES
			CXX_STANDARD 20
			FOLDER "Tests/ShaderWriter/${TEST_NAME}"
		)
	endif ()

	if ( MSVC )
		target_compile_options( ${REAL_TEST_NAME} PRIVATE
			-bigobj
		)

		if ( PROJECTS_COVERAGE )
			OpenCppCoverage_add_target( ${REAL_TEST_NAME}
				MODULES $<TARGET_FILE_NAME:ShaderAST> $<TARGET_FILE_NAME:ShaderWriter>
				SOURCES ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/source
			)
		endif ()
	endif ()

	add_test(
		NAME ${REAL_TEST_NAME}
		COMMAND ${REAL_TEST_NAME}
	)
endfunction( SDW_AddTest )

foreach ( TEST_FILE ${TEST_FILES} )
	get_filename_component( TEST_NAME ${TEST_FILE} NAME_WE )
	string( FIND ${TEST_FILE} "Image" IS_IMAGE )
	string( FIND ${TEST_FILE} "Ssbo" IS_SSBO )
	string( FIND ${TEST_FILE} "Ubo" IS_UBO )
	string( FIND ${TEST_FILE} "Struct" IS_STRUCT )
	string( FIND ${TEST_FILE} "Pcb" IS_PCB )

	if ( IS_IMAGE GREATER -1 )
		foreach( FORMAT ${IMAGE_FORMATS} )
			SDW_AddTest( ${TEST_FILE} ${TEST_NAME} _${FORMAT} "SDW_TestImageFormat=${FORMAT}" )
		endforeach ()
	elseif ( IS_SSBO GREATER -1 )
		foreach( BO_TYPE ${BO_TYPES} )
			SDW_AddTest( ${TEST_FILE} ${TEST_NAME} _${BO_TYPE} "SDW_TestType=${BO_TYPE}" )
		endforeach ()
	elseif ( IS_UBO GREATER -1 )
		foreach( BO_TYPE ${BO_TYPES} )
			SDW_AddTest( ${TEST_FILE} ${TEST_NAME} _${BO_TYPE} "SDW_TestType=${BO_TYPE}" )
		endforeach ()
	elseif ( IS_STRUCT GREATER -1 )
		foreach( BO_TYPE ${BO_TYPES} )
			SDW_AddTest( ${TEST_FILE} ${TEST_NAME} _${BO_TYPE} "SDW_TestType=${BO_TYPE}" )
		endforeach ()
	elseif ( IS_PCB GREATER -1 )
		foreach( BO_TYPE ${BO_TYPES} )
			SDW_AddTest( ${TEST_FILE} ${TEST_NAME} _${BO_TYPE} "SDW_TestType=${BO_TYPE}" )
		endforeach ()
	else ()
		SDW_AddTest( ${TEST_FILE} ${TEST_NAME} "" "" )
	endif ()
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
