set( _FOLDER_NAME CompilerGlsl )
project( ${_FOLDER_NAME} )

set( ${PROJECT_NAME}_VERSION_MAJOR 2 )
set( ${PROJECT_NAME}_VERSION_MINOR 3 )
set( ${PROJECT_NAME}_VERSION_BUILD 0 )
set( ${PROJECT_NAME}_VERSION_YEAR 2022 )

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

if ( SDW_GENERATE_SOURCE AND PYTHONINTERP_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${_FOLDER_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
	add_custom_command( OUTPUT ${SOURCE_DIR}/GlslStorageImageAccessNames.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genGlslNameFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/StorageImageAccess.enum ${GENERATED_DIR}/GlslStorageImageAccessNames.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GlslStorageImageAccessNames.hpp ${SOURCE_DIR}/GlslStorageImageAccessNames.hpp
		COMMENT "Generating GlslStorageImageAccessNames.hpp"
		DEPENDS ${SCRIPT_DIR}/genGlslNameFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/StorageImageAccess.enum
	)
	source_group( "Script Files" FILES
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	source_group( "Header Files" FILES
		${SOURCE_DIR}/GLSL/GlslStorageImageAccessNames.hpp
	)
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
		UNITY_BUILD "${SDW_UNITY_BUILD}"
)
target_include_directories( ${PROJECT_NAME}
	PRIVATE
		${SDW_SOURCE_DIR}/source
		${INCLUDE_DIR}
		${SOURCE_DIR}
)
target_add_compilation_flags( ${PROJECT_NAME} )
target_install_headers_ex( ${PROJECT_NAME}
	SdwCompilers
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
