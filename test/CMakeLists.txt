enable_testing()

if ( NOT DEFINED SDW_GENERATE_SOURCE )
	option( SDW_GENERATE_SOURCE "Build source files from .enum files, using Python" OFF )
endif ()
if ( SDW_GENERATE_SOURCE )
	find_package( Python QUIET COMPONENTS Interpreter )
endif ()

set( GTest_DIR ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/gtest )
find_package( GTest CONFIG REQUIRED GTest::gtest GTest::gtest_main )

get_filename_component( SDW_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY )
get_filename_component( SDW_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY )

set( TEST_COMMON_INCLUDE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}
)
set( TEST_COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.hpp
)
set( TEST_COMMON_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.cpp
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
