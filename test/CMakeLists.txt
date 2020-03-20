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
set_target_properties( TestCommon
	PROPERTIES
		CXX_STANDARD 17
		FOLDER "Tests"
)

add_subdirectory( ShaderAST )
add_subdirectory( ShaderWriter )
