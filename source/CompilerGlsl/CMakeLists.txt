if ( NOT DEFINED SDW_BUILD_EXPORTER_GLSL_STATIC )
	option( SDW_BUILD_EXPORTER_GLSL_STATIC "Build GLSL exporter as a static library" OFF )
endif ()

project( CompilerGlsl )

set( ${PROJECT_NAME}_VERSION_MAJOR 0 )
set( ${PROJECT_NAME}_VERSION_MINOR 1 )
set( ${PROJECT_NAME}_VERSION_BUILD 0 )
set( ${PROJECT_NAME}_VERSION_YEAR 2019 )

set( PROJECT_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}" )
set( PROJECT_SOVERSION "${${PROJECT_NAME}_VERSION_BUILD}" )

set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/${PROJECT_NAME} )
set( SOURCE_DIR ${SDW_SOURCE_DIR}/source/${PROJECT_NAME} )

file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/*.h
	${INCLUDE_DIR}/*.hpp
	${INCLUDE_DIR}/*.inl
)

file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/*.h
	${SOURCE_DIR}/*.hpp
	${SOURCE_DIR}/*.inl
	${SOURCE_DIR}/*.c
	${SOURCE_DIR}/*.cpp
)

if ( SDW_GENERATE_SOURCE AND PYTHONINTERP_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${PROJECT_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${PROJECT_NAME} )
	add_custom_command( OUTPUT ${SOURCE_DIR}/GlslImageAccessNames.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genGlslNameFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/ImageAccess.enum ${GENERATED_DIR}/GlslImageAccessNames.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GlslImageAccessNames.hpp ${SOURCE_DIR}/GlslImageAccessNames.hpp
		COMMENT "Generating GlslImageAccessNames.hpp"
		DEPENDS ${SCRIPT_DIR}/genGlslNameFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/ImageAccess.enum
	)
	source_group( "Script Files" FILES
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	source_group( "Header Files" FILES
		${SOURCE_DIR}/GLSL/GlslImageAccessNames.hpp
	)
endif ()

if ( SDW_BUILD_EXPORTER_GLSL_STATIC )
	add_library( ${PROJECT_NAME}
		STATIC
		${SOURCE_DIR}/GlslImageAccessNames.hpp
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PUBLIC
			${PROJECT_NAME}_Static
			SDW_Has${PROJECT_NAME}
	)
else ()
	add_library( ${PROJECT_NAME}
		SHARED
		${SOURCE_DIR}/GlslImageAccessNames.hpp
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PRIVATE
			${PROJECT_NAME}_Exports
		PUBLIC
			SDW_Has${PROJECT_NAME}
	)
endif ()

add_library( sdw::${PROJECT_NAME}
	ALIAS
	${PROJECT_NAME}
)
target_link_libraries( ${PROJECT_NAME} PUBLIC
	sdw::ShaderAST
	sdw::ShaderWriter
)
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_SOVERSION}
		CXX_STANDARD 17
		FOLDER "${SDW_BASE_DIR}/Exporters"
)
target_include_directories( ${PROJECT_NAME} PRIVATE
	${SDW_SOURCE_DIR}/source
	${INCLUDE_DIR}
	${SOURCE_DIR}
)

# We install headers to <install_dir>/include/${PROJECT_NAME}
target_install_headers( ${PROJECT_NAME} ${SDW_SOURCE_DIR}/include/${PROJECT_NAME} )

set( SDW_EXPORTERS_LIST
	${SDW_EXPORTERS_LIST}
	sdw::${PROJECT_NAME}
	PARENT_SCOPE
)

set( SDW_INSTEXP_LIST
	${SDW_INSTEXP_LIST}
	${PROJECT_NAME}
	PARENT_SCOPE
)
