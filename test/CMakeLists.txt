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
	# find_program( OPENCPPCOVERAGE_EXECUTABLE
		# NAME OpenCppCoverage
	# )
	# set( Sources "--sources=${CMAKE_SOURCE_DIR}/include" )
	# set( Sources "${Sources} --sources=${CMAKE_SOURCE_DIR}/source" )
	# set( Sources "${Sources} --sources=${CMAKE_SOURCE_DIR}/test" )
	# set( Sources "${Sources} --sources=${CMAKE_BINARY_DIR}/include" )
	# set( Sources "${Sources} --sources=${CMAKE_BINARY_DIR}/source" )
	# set( Sources "${Sources} --sources=${CMAKE_BINARY_DIR}/test" )
	# file( TO_NATIVE_PATH ${Sources} Sources )

	# set( ModulesRelease "${PROJECTS_BINARIES_OUTPUT_DIR_RELEASE}/bin --modules=${PROJECTS_BINARIES_OUTPUT_DIR_RELEASE}/lib" )
	# set( ModulesDebug "--modules=${PROJECTS_BINARIES_OUTPUT_DIR_DEBUG}/bin --modules=${PROJECTS_BINARIES_OUTPUT_DIR_DEBUG}/lib" )
	# set( ModulesRelWithDebInfo "--modules=${PROJECTS_BINARIES_OUTPUT_DIR_RELWITHDEBINFO}/bin --modules=${PROJECTS_BINARIES_OUTPUT_DIR_RELWITHDEBINFO}/lib" )
	# file( TO_NATIVE_PATH ${CMAKE_CTEST_COMMAND} ModulesCTest )
	# file( TO_NATIVE_PATH ${ModulesRelease} ModulesRelease )
	# file( TO_NATIVE_PATH ${ModulesDebug} ModulesDebug )
	# file( TO_NATIVE_PATH ${ModulesRelWithDebInfo} ModulesRelWithDebInfo )
	# file( TO_NATIVE_PATH ${PROJECTS_BINARIES_OUTPUT_DIR_RELEASE}/bin WorkingDirRelease )
	# file( TO_NATIVE_PATH ${PROJECTS_BINARIES_OUTPUT_DIR_DEBUG}/bin WorkingDirDebug )
	# file( TO_NATIVE_PATH ${PROJECTS_BINARIES_OUTPUT_DIR_RELWITHDEBINFO}/bin WorkingDirRelWithDebInfo )
	# file( TO_NATIVE_PATH ${PROJECTS_DOCUMENTATION_OUTPUT_DIR}/${TARGET_NAME}Coverage HtmlOutput )
	# file( TO_NATIVE_PATH ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}Coverage.cov BinaryOutput )
	# add_custom_target( ShaderWriterCoverage
		# COMMAND ${OPENCPPCOVERAGE_EXECUTABLE}
			# ${Sources}
			# --modules=${ModulesCTest}
			# $<$<CONFIG:Release>:${ModulesRelease}>
			# $<$<CONFIG:RelWithDebInfo>:${ModulesRelWithDebInfo}>
			# $<$<CONFIG:Debug>:${ModulesDebug}>
			# --export_type=html:${HtmlOutput}
			# --export_type=binary:${BinaryOutput}
			# --cover_children
			# -- ${CMAKE_CTEST_COMMAND} -VV -C $<CONFIG>
	# )
endif ()
