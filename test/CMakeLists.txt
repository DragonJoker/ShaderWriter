enable_testing()

if ( NOT DEFINED SDW_GENERATE_SOURCE )
	option( SDW_GENERATE_SOURCE "Build source files from .enum files, using Python" OFF )
endif ()
if ( SDW_GENERATE_SOURCE )
	find_package( Python QUIET COMPONENTS Interpreter )
endif ()

get_filename_component( SDW_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY )
get_filename_component( SDW_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY )

set( TEST_COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.hpp
)
set( TEST_COMMON_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.cpp
)
add_library( TestCommon
	OBJECT
	${TEST_COMMON_HEADER_FILES}
	${TEST_COMMON_SOURCE_FILES}
)
add_library( sdw::test::Common
	ALIAS
	TestCommon
)
target_sources( TestCommon
	PRIVATE
		${SDW_EDITORCONFIG_FILE}
)
target_include_directories( TestCommon
	PUBLIC
		${CMAKE_SOURCE_DIR}/include
)
target_link_libraries( TestCommon
	PUBLIC
		sdw::ShaderAST
	PRIVATE
		${SDW_EXPORTERS_LIST}
)
if ( NOT WIN32 )
	target_link_libraries( TestCommon
		PUBLIC
			pthread
	)
endif ()
target_include_directories( TestCommon
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)
target_add_compilation_flags( TestCommon )
set_target_properties( TestCommon
	PROPERTIES
		CXX_STANDARD 20
		FOLDER "Tests"
)

add_subdirectory( ShaderAST )

if ( SDW_BUILD_WRITER )
	add_subdirectory( ShaderWriter )
endif ()

if ( PROJECTS_COVERAGE )
	coverage_add_merge_target( ShaderWriterCoverage
		${PROJECTS_DOCUMENTATION_OUTPUT_DIR}/ShaderWriterCoverage
	)
endif ()
