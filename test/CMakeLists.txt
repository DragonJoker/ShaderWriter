enable_testing()

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
target_include_directories( TestCommon
	PUBLIC
		${CMAKE_SOURCE_DIR}/include
)
target_link_libraries( TestCommon
	PUBLIC
		sdw::ShaderAST
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

if ( PROJECTS_COVERAGE )
	set( PROJECTS_COVERAGE_LIB_FILES
		sdw::test::Common
	)
endif ()

include( OpenCppCoverage )

add_subdirectory( ShaderAST )
add_subdirectory( ShaderWriter )

if ( PROJECTS_COVERAGE )
	OpenCppCoverage_add_merge_target( ShaderWriterCoverage
		${PROJECTS_DOCUMENTATION_OUTPUT_DIR}/${TARGET_NAME}Coverage
		FORMAT html )
endif ()
