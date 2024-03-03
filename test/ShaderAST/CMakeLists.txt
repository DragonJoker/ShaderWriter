file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )

set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/ShaderAST )

if ( SDW_GENERATE_SOURCE AND PYTHON_FOUND )
	set( SCRIPT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/scripts )
	file( GLOB_RECURSE ${PROJECT_NAME}_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
	add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/TestASTIntrinsics.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genTestASTIntrinsicsFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/TestASTIntrinsics.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/TestASTIntrinsics.cpp ${CMAKE_CURRENT_SOURCE_DIR}/TestASTIntrinsics.cpp
		COMMENT "Generating TestASTIntrinsics.cpp"
		DEPENDS ${SCRIPT_DIR}/genTestASTIntrinsicsFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
endif ()

foreach ( TEST_FILE ${TEST_FILES} )
	get_filename_component( TEST_NAME ${TEST_FILE} NAME_WE )
	add_executable( ${TEST_NAME}
		$<TARGET_OBJECTS:TestCommon>
		${TEST_FILE}
	)
	target_sources( ${TEST_NAME}
		PRIVATE
			${SDW_EDITORCONFIG_FILE}
	)
	target_link_libraries( ${TEST_NAME}
		PRIVATE
			sdw::ShaderAST
			sdw::test::Common
			${BinLibraries}
	)
	target_compile_definitions( ${TEST_NAME} PRIVATE
		SDW_COMPILE_TESTS
	)
	target_add_compilation_flags( ${TEST_NAME} )

	if ( MSVC )
		target_compile_options( ${TEST_NAME} PRIVATE
			-bigobj
		)
	endif ()
	if ( PROJECTS_COVERAGE )
		coverage_add_target( ${TEST_NAME}
			MODULES
				$<TARGET_FILE_NAME:ShaderAST>
				$<TARGET_FILE_NAME:${TEST_NAME}>
			SOURCES
				${CMAKE_SOURCE_DIR}/include/ShaderAST
				${CMAKE_SOURCE_DIR}/source/ShaderAST
		)
	endif ()

	set_property( TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20 )
	set_property( TARGET ${TEST_NAME} PROPERTY FOLDER "Tests/ShaderAST" )

	add_test(
		NAME ${TEST_NAME}
		COMMAND ${TEST_NAME}
	)
endforeach ()
