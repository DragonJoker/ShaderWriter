file( GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Test*.cpp )

foreach ( TEST_FILE ${TEST_FILES} )
	get_filename_component( TEST_NAME ${TEST_FILE} NAME_WE )
	if ( PROJECTS_COVERAGE )
		set( PROJECTS_COVERAGE_SRC_FILES
			${PROJECTS_COVERAGE_SRC_FILES}
			${TEST_FILE}
		)
		set( PROJECTS_COVERAGE_TEST_NAMES
			${PROJECTS_COVERAGE_TEST_NAMES}
			${TEST_NAME}
		)
	endif ()
	add_executable( ${TEST_NAME}
		$<TARGET_OBJECTS:TestCommon>
		${TEST_FILE}
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

		if ( PROJECTS_COVERAGE )
			OpenCppCoverage_add_target( ${TEST_NAME}
				MODULES $<TARGET_FILE_NAME:ShaderAST>
				SOURCES ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/source
			)
		endif ()
	endif ()

	set_property( TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20 )
	set_property( TARGET ${TEST_NAME} PROPERTY FOLDER "Tests/ShaderAST" )

	add_test(
		NAME ${TEST_NAME}
		COMMAND ${TEST_NAME}
	)
endforeach ()

if ( PROJECTS_COVERAGE )
	set( PROJECTS_COVERAGE_SRC_FILES
		${PROJECTS_COVERAGE_SRC_FILES}
		PARENT_SCOPE
	)
	set( PROJECTS_COVERAGE_TEST_NAMES
		${PROJECTS_COVERAGE_TEST_NAMES}
		PARENT_SCOPE
	)
endif ()
