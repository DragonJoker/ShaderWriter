set( _FOLDER_NAME GlslCommon )
project( ${_FOLDER_NAME} )

set( ${PROJECT_NAME}_VERSION_MAJOR ${VERSION_MAJOR} )
set( ${PROJECT_NAME}_VERSION_MINOR ${VERSION_MINOR} )
set( ${PROJECT_NAME}_VERSION_BUILD ${VERSION_BUILD} )
set( ${PROJECT_NAME}_VERSION_YEAR ${VERSION_YEAR} )

set( PROJECT_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}" )
set( PROJECT_SOVERSION "${${PROJECT_NAME}_VERSION_BUILD}" )

set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/${_FOLDER_NAME} )
set( SOURCE_DIR ${SDW_SOURCE_DIR}/source/${_FOLDER_NAME} )

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

if ( SDW_GENERATE_SOURCE AND PYTHON_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${_FOLDER_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
	add_custom_command( OUTPUT ${SOURCE_DIR}/GlslStorageImageAccessNames.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGlslNameFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/StorageImageAccess.enum ${GENERATED_DIR}/GlslStorageImageAccessNames.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GlslStorageImageAccessNames.hpp ${SOURCE_DIR}/GlslStorageImageAccessNames.hpp
		COMMENT "Generating GlslStorageImageAccessNames.hpp"
		DEPENDS ${SCRIPT_DIR}/genGlslNameFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/StorageImageAccess.enum
	)
	source_group( "Script Files" FILES
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	source_group( "Header Files" FILES
		${SOURCE_DIR}/GlslStorageImageAccessNames.hpp
	)
endif ()

if ( ${PROJECTS_UNITY_BUILD} )
	file( GLOB ${PROJECT_NAME}_FOLDER_SRC_FILES
		${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir/Unity/*.cxx
	)
	source_group( "Source Files\\Unity" FILES ${${PROJECT_NAME}_FOLDER_SRC_FILES} )
endif ()

if ( SDW_BUILD_STATIC )
	add_library( ${PROJECT_NAME}
		STATIC
		${SOURCE_DIR}/GlslStorageImageAccessNames.hpp
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PUBLIC
			${_FOLDER_NAME}_Static
			SDW_Has${_FOLDER_NAME}
	)
else ()
	add_library( ${PROJECT_NAME}
		SHARED
		${SOURCE_DIR}/GlslStorageImageAccessNames.hpp
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PRIVATE
			${_FOLDER_NAME}_Exports
		PUBLIC
			SDW_Has${_FOLDER_NAME}
	)
endif ()

add_library( sdw::${_FOLDER_NAME}
	ALIAS
	${PROJECT_NAME}
)
target_sources( ${PROJECT_NAME} 
	PRIVATE
		${SDW_EDITORCONFIG_FILE}
)
target_link_libraries( ${PROJECT_NAME}
	PUBLIC
		sdw::ShaderAST
)
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_SOVERSION}
		CXX_STANDARD 20
		PREFIX ${SDW_LIB_PREFIX}
		FOLDER "${SDW_BASE_DIR}/Exporters"
		UNITY_BUILD "${PROJECTS_UNITY_BUILD}"
)
target_include_directories( ${PROJECT_NAME}
	PRIVATE
		${SDW_SOURCE_DIR}/source
		${INCLUDE_DIR}
		${SOURCE_DIR}
)
target_add_coverage_flags( ${PROJECT_NAME} )
target_add_compilation_flags( ${PROJECT_NAME} )
target_install_headers_ex( ${PROJECT_NAME}
	ShaderWriter
	${SDW_SOURCE_DIR}/include/${_FOLDER_NAME}
)
set( SDW_EXPORTERS_LIST
	${SDW_EXPORTERS_LIST}
	sdw::${_FOLDER_NAME}
	PARENT_SCOPE
)

set( SDW_INSTEXP_LIST
	${SDW_INSTEXP_LIST}
	${PROJECT_NAME}
	PARENT_SCOPE
)
