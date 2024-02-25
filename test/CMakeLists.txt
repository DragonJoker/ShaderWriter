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

include( OpenCppCoverage )

if(OpenCppCoverage_FOUND)
	function(MyOpenCppCoverage_add_target target)
		cmake_parse_arguments(PARSE_ARGV 1 ARG "" "WORKING_DIRECTORY" "SOURCES;MODULES;OCC_ARGS;ARGS")
		if(ARG_UNPARSED_ARGUMENTS)
			message(FATAL_ERROR "Invalid argument(s): ${ARG_UNPARSED_ARGUMENTS}")
		endif()

		get_property(counter GLOBAL PROPERTY OpenCppCoverage_COUNTER)
		if(NOT counter)
			set(counter 1)
		else()
			math(EXPR counter "${counter} + 1")
		endif()
		set(outputFile ${CMAKE_CURRENT_BINARY_DIR}/OpenCppCoverage/cov-${counter}-${target}.bin)
		set_property(GLOBAL PROPERTY OpenCppCoverage_COUNTER "${counter}")
		set_property(GLOBAL APPEND PROPERTY OpenCppCoverage_SOURCES "${outputFile}")

		if(NOT ARG_WORKING_DIRECTORY)
			set(ARG_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
		endif()
		if(NOT ARG_SOURCES)
			file(TO_NATIVE_PATH ${PROJECT_SOURCE_DIR} ARG_SOURCES)
		endif()
		if(NOT ARG_MODULES)
			file(TO_NATIVE_PATH ${PROJECT_BINARY_DIR} ARG_MODULES)
		endif()

		set(args "${ARG_OCC_ARGS}")
		foreach(el IN LISTS ARG_SOURCES)
			list(APPEND args --sources ${el})
		endforeach()
		foreach(el IN LISTS ARG_MODULES)
			list(APPEND args --modules ${el})
		endforeach()
		file( TO_NATIVE_PATH "${args}" args )
		add_custom_command(TARGET ${target}
			POST_BUILD
			COMMENT "Creating coverage for ${target}"
			COMMAND ${OpenCppCoverage_BINARY}
				--working_dir $<TARGET_FILE_DIR:${target}>
				--export_type binary:${outputFile}
				--cover_children
				--quiet
				${args}
				-- $<TARGET_FILE:${target}> ${ARG_ARGS}
			VERBATIM
		)
	endfunction()
endif ()

add_subdirectory( ShaderAST )
add_subdirectory( ShaderWriter )

if ( PROJECTS_COVERAGE )
	if ( PROJECTS_COVERAGE_HTML_RESULTS )
		OpenCppCoverage_add_merge_target( ShaderWriterCoverage
			${PROJECTS_DOCUMENTATION_OUTPUT_DIR}/ShaderWriterCoverage
			FORMAT html )
	else ()
		OpenCppCoverage_add_merge_target( ShaderWriterCoverage
			${PROJECTS_DOCUMENTATION_OUTPUT_DIR}/ShaderWriterCoverage.xml
			FORMAT cobertura )
	endif ()
endif ()
