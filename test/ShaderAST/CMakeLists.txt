project( TestASTCommon )

set( ${PROJECT_NAME}_DESCRIPTION "${PROJECT_NAME} library" )
set( ${PROJECT_NAME}_VERSION_MAJOR 0 )
set( ${PROJECT_NAME}_VERSION_MINOR 6 )
set( ${PROJECT_NAME}_VERSION_BUILD 0 )

add_library( ${PROJECT_NAME}
	STATIC
		${TEST_COMMON_HEADER_FILES}
		${TEST_COMMON_SOURCE_FILES}
)
target_sources( ${PROJECT_NAME}
	PRIVATE
		${SDW_EDITORCONFIG_FILE}
)
target_include_directories( ${PROJECT_NAME}
	PUBLIC
		${TEST_COMMON_INCLUDE_DIRS}
)
target_compile_definitions( ${PROJECT_NAME}
	PUBLIC
		TestCommon_STATIC
)
target_link_libraries( ${PROJECT_NAME}
	PUBLIC
		sdw::ShaderAST
	PRIVATE
		GTest::gtest
)
target_add_compilation_flags( ${PROJECT_NAME} )
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 20
		CXX_EXTENSIONS OFF
		FOLDER "Tests/ShaderAST"
		DEBUG_POSTFIX "d"
)

if ( SDW_GENERATE_SOURCE AND PYTHON_FOUND )
	set( SCRIPT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/scripts )
	file( GLOB_RECURSE ${PROJECT_NAME}_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
	set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/ShaderAST )
	add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/TestASTBase_Intrinsics.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genTestASTIntrinsicsFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/TestASTBase_Intrinsics.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/TestASTBase_Intrinsics.cpp ${CMAKE_CURRENT_SOURCE_DIR}/TestASTBase_Intrinsics.cpp
		COMMENT "Generating TestASTBase_Intrinsics.cpp"
		DEPENDS ${SCRIPT_DIR}/genTestASTIntrinsicsFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
endif ()

macro( create_test TEST_FILE )
	get_filename_component( TARGET_NAME ${TEST_FILE} NAME_WE )
	string( REPLACE "TestAST" "" TEST_NAME ${TARGET_NAME} )
	string( REGEX MATCH "[^_]*" TEST_CATEGORY ${TARGET_NAME} )
	string( REPLACE "TestAST" "" TEST_CATEGORY ${TEST_CATEGORY} )
	add_executable( ${TARGET_NAME}
		${TEST_FILE}
	)
	target_sources( ${TARGET_NAME}
		PRIVATE
			${SDW_EDITORCONFIG_FILE}
	)
	target_link_libraries( ${TARGET_NAME}
		PRIVATE
			GTest::gtest_main
			${PROJECT_NAME}
	)
	target_compile_definitions( ${TARGET_NAME}
		PRIVATE
			AST_TestSuiteName=${TEST_NAME}
	)
	target_add_compilation_flags( ${TARGET_NAME} )
	target_compile_options( ${TARGET_NAME}
		PRIVATE
			$<$<CXX_COMPILER_ID:MSVC>:/bigobj>
	)
	set_target_properties( ${TARGET_NAME}
		PROPERTIES
			CXX_STANDARD 20
			CXX_EXTENSIONS OFF
			FOLDER "Tests/ShaderAST/${TEST_CATEGORY}"
			DEBUG_POSTFIX "d"
	)
	if ( PROJECTS_COVERAGE )
		coverage_add_target( ${TARGET_NAME}
			MODULES
				$<TARGET_FILE_NAME:ShaderAST>
				$<TARGET_FILE_NAME:${TARGET_NAME}>
			SOURCES
				${CMAKE_SOURCE_DIR}/include/ShaderAST
				${CMAKE_SOURCE_DIR}/source/ShaderAST
		)
	endif ()

	add_test( NAME ${TARGET_NAME}
		COMMAND ${TARGET_NAME}
	)
endmacro()

file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )
foreach ( TEST_FILE ${TEST_FILES} )
	create_test( ${TEST_FILE} )
endforeach ()
