enable_testing()

set( TEST_COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.hpp
)
set( TEST_COMMON_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.cpp
)

include_directories(
	${CMAKE_SOURCE_DIR}/include
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
target_link_libraries( TestCommon
	PUBLIC
		sdw::ShaderAST
)
target_compile_definitions( TestCommon
	PUBLIC
		${SDW_EXPORTERS_DEFINITIONS}
)
set_property( TARGET TestCommon PROPERTY CXX_STANDARD 17 )
set_property( TARGET TestCommon PROPERTY FOLDER "Tests" )

add_subdirectory( ShaderAST )
add_subdirectory( ShaderWriter )
