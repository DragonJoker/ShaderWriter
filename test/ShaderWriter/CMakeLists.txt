file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )

set( SPIRV_CROSS_DIR ${CMAKE_SOURCE_DIR}/external/SPIRV-Cross )

include_directories( ${SPIRV_CROSS_DIR} )

set( TEST_WRITER_COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/WriterCommon.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileHLSL.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileGLSL.hpp
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
	${CMAKE_CURRENT_SOURCE_DIR}/CompileHLSL.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CompileGLSL.cpp
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
set_property( TARGET TestWriterCommon PROPERTY CXX_STANDARD 17 )
set_property( TARGET TestWriterCommon PROPERTY FOLDER "Tests/ShaderWriter" )

add_dependencies( TestWriterCommon
	ShaderAST
	ShaderWriter
	CompilerGlsl
	CompilerHlsl
	CompilerSpirV
)

find_package( OpenGL )

foreach ( TEST_FILE ${TEST_FILES} )
	get_filename_component( TEST_NAME ${TEST_FILE} NAME_WE )
	add_executable( ${TEST_NAME}
		$<TARGET_OBJECTS:TestCommon>
		${TEST_FILE}
	)
	target_link_libraries( ${TEST_NAME}
		ShaderAST
		ShaderWriter
		CompilerGlsl
		CompilerHlsl
		CompilerSpirV
		TestWriterCommon
		${BinLibraries}
		${OPENGL_gl_LIBRARY}
	)

	if ( MSVC )
		add_compile_options( -bigobj )
	endif ()

	set_property( TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 17 )
	set_property( TARGET ${TEST_NAME} PROPERTY FOLDER "Tests/ShaderWriter" )

	add_test(
		NAME ${TEST_NAME}
		COMMAND ${TEST_NAME}
	)
endforeach ()
