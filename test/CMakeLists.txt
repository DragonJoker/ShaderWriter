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
set_property( TARGET TestCommon PROPERTY CXX_STANDARD 17 )
set_property( TARGET TestCommon PROPERTY FOLDER "Tests" )

add_dependencies( TestCommon
	ShaderAST
)

add_subdirectory( ShaderAST )
add_subdirectory( ShaderWriter )
