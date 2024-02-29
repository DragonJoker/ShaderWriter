file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )

if ( ${CMAKE_VERSION} VERSION_GREATER "3.10.2" ) 
	cmake_policy( SET CMP0072 NEW )
endif()

option( SDW_ALL_TESTS "Builds all tests (relative to data type and image pixel formats)" ON )
option( SDW_TESTS_ENABLE_VALIDATION "Enables validation through respective API (Vulkan, OpenGL, and Direct3D" OFF )

find_package( glslang CONFIG REQUIRED glslang OGLCompiler OSDependent SPIRV SPVRemapper )
find_package( Threads REQUIRED )
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
	SHARED
	${TEST_WRITER_COMMON_HEADER_FILES}
	${TEST_WRITER_COMMON_SOURCE_FILES}
)
add_library( sdw::test::WriterCommon
	ALIAS
	TestWriterCommon
)
target_sources( TestWriterCommon
	PRIVATE
		${SDW_EDITORCONFIG_FILE}
)
target_link_libraries( TestWriterCommon
	PUBLIC
		sdw::ShaderAST
		sdw::ShaderWriter
		sdw::test::Common
		${BinLibraries}
		glslang::OSDependent
		glslang::glslang
		glslang::OGLCompiler
		glslang::SPIRV
		glslang::SPVRemapper
		Threads::Threads
	PRIVATE
		${SDW_EXPORTERS_LIST}
)
target_add_compilation_flags( TestWriterCommon )

if ( PROJECTS_COVERAGE )
	target_compile_definitions( TestWriterCommon
		PRIVATE
			SDW_Test_SpirVAllDebugLevels=0
			SDW_Test_Coverage=1
		)
else ()
	target_compile_definitions( TestWriterCommon
		PRIVATE
			SDW_Test_SpirVAllDebugLevels=1
			SDW_Test_Coverage=0
		)
	if ( SDW_TESTS_ENABLE_VALIDATION )
		set( CMAKE_MAP_IMPORTED_CONFIG_MINSIZEREL "" Release )
		set( CMAKE_MAP_IMPORTED_CONFIG_RELWITHDEBINFO "" Release )
		find_package( OpenGL )
		find_package( Vulkan )

		if ( ( TARGET CompilerGlsl )
			AND ( OpenGL_FOUND OR OPENGL_FOUND )
			AND ( WIN32 ) )
			if ( WIN32 )
				target_link_libraries( TestWriterCommon PRIVATE OpenGL::GL )
			else ()
				find_package( X11 )
				target_link_libraries( TestWriterCommon PRIVATE ${X11_X11_LIB} OpenGL::GLX OpenGL::OpenGL )
			endif ()
			target_compile_definitions( TestWriterCommon PRIVATE SDW_Test_HasOpenGL=1 )
		endif ()

		if ( ( TARGET CompilerSpirV )
			AND ( Vulkan_FOUND OR VULKAN_FOUND ) )
			target_include_directories( TestWriterCommon PRIVATE ${Vulkan_INCLUDE_DIR} )
			target_link_libraries( TestWriterCommon PRIVATE ${Vulkan_LIBRARY} )
			target_compile_definitions( TestWriterCommon PRIVATE SDW_Test_HasVulkan=1 )
			if ( SDW_BUILD_VULKAN_LAYER )
				target_link_libraries( TestWriterCommon PRIVATE sdw::VulkanLayer )
			endif ()
		endif ()

		if ( ( TARGET CompilerHlsl ) AND WIN32 )
			target_compile_definitions( TestWriterCommon PRIVATE SDW_Test_HasDirect3D11=1 )
			find_package( DXC )
			if ( DXC_FOUND )
				target_compile_definitions( TestWriterCommon PRIVATE SDW_Test_HasDXC=1 )
				target_link_libraries( TestWriterCommon PRIVATE DXC::dxc )
			endif ()
		endif ()
	endif ()
endif ()
set_target_properties( TestWriterCommon
	PROPERTIES
		CXX_STANDARD 20
		FOLDER "Tests/ShaderWriter"
)
find_package( spirv_cross_core CONFIG )
find_package( spirv_cross_glsl CONFIG )
find_package( spirv_cross_hlsl CONFIG )
if ( TARGET spirv-cross-core AND TARGET spirv-cross-glsl AND TARGET spirv-cross-hlsl )
	target_link_libraries( TestWriterCommon PRIVATE spirv-cross-core spirv-cross-glsl spirv-cross-hlsl )
	target_compile_definitions( TestWriterCommon PRIVATE SDW_Test_HasSpirVCross=1 )
endif ()

find_package( SPIRV-Tools CONFIG )
if ( SPIRV-Tools_FOUND )
	target_link_libraries( TestWriterCommon PRIVATE SPIRV-Tools-static )
	target_compile_definitions( TestWriterCommon PRIVATE SDW_Test_HasSpirVTools=1 )
endif ()

set( TargetLinkLibraries
)

if ( SDW_ALL_TESTS )
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
elseif ( PROJECTS_COVERAGE )
	set( IMAGE_FORMATS
		eRgba32f
	)
	set( BO_TYPES
		Vec4
	)
else ()
	set( IMAGE_FORMATS
		eRgba32f
		eRg16f
		eR32f
		eRgba16i
		eRg8i
		eR32i
		eRgba8u
		eRg32u
		eR16u
	)
	set( BO_TYPES
		Int8
		UInt16
		Float
		Vec4
		DVec3
		I8Vec2
		I16Vec3
		I32Vec4
		U64Vec2
		Mat2x3
		Mat4x4
		DMat3x2
		DMat3x3
	)
endif ()

function( SDW_AddTest TEST_FILE TEST_NAME NAME_SUFFIX ADDITIONAL_DEFINITIONS )
	set( REAL_TEST_NAME ${TEST_NAME}${NAME_SUFFIX} )
	add_executable( ${REAL_TEST_NAME}
		$<TARGET_OBJECTS:TestCommon>
		${TEST_FILE}
	)
	target_sources( ${REAL_TEST_NAME} 
		PRIVATE
			${SDW_EDITORCONFIG_FILE}
	)
	target_link_libraries( ${REAL_TEST_NAME} PRIVATE
		sdw::test::WriterCommon
	)
	target_compile_definitions( ${REAL_TEST_NAME} PRIVATE
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
	endif ()
	if ( PROJECTS_COVERAGE )
		coverage_add_target( ${REAL_TEST_NAME}
			MODULES
				$<TARGET_FILE_NAME:ShaderAST>
				$<TARGET_FILE_NAME:ShaderWriter>
				$<TARGET_FILE_NAME:CompilerGlsl>
				$<TARGET_FILE_NAME:CompilerHlsl>
				$<TARGET_FILE_NAME:CompilerSpirV>
				$<TARGET_FILE_NAME:GlslCommon>
				$<TARGET_FILE_NAME:${REAL_TEST_NAME}>
			SOURCES
				${CMAKE_SOURCE_DIR}/include
				${CMAKE_SOURCE_DIR}/source
		)
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
