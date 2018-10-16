enable_testing()

set( TEST_COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/TestWriterCommon.hpp
)
set( TEST_COMMON_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Common.cpp
)

add_library( TestCommon
	OBJECT
	${TEST_COMMON_HEADER_FILES}
	${TEST_COMMON_SOURCE_FILES}
)
set_property( TARGET TestCommon PROPERTY CXX_STANDARD 17 )
set_property( TARGET TestCommon PROPERTY FOLDER "Tests" )

file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )

foreach ( TEST_FILE ${TEST_FILES} )
	get_filename_component( TEST_NAME ${TEST_FILE} NAME_WE )
	add_executable( ${TEST_NAME}
		$<TARGET_OBJECTS:TestCommon>
		${TEST_FILE}
	)
	target_link_libraries( ${TEST_NAME}
		ASTGenerator
		ShaderWriter
		${BinLibraries}
	)
	if ( MSVC )
		add_compile_options( -bigobj )
	endif ()
	set_property( TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 17 )
	set_property( TARGET ${TEST_NAME} PROPERTY FOLDER "Tests" )
	add_test(
		NAME ${TEST_NAME}
		COMMAND ${TEST_NAME}
	)
endforeach ()
