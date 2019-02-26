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

add_library( ${PROJECT_NAME}
	SHARED
	${SOURCE_DIR}/GlslImageAccessNames.hpp
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
	${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
)
target_compile_options( ${PROJECT_NAME} PRIVATE -D${PROJECT_NAME}_Exports )
target_link_libraries( ${PROJECT_NAME}
	ShaderAST
	ShaderWriter
)
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_SOVERSION}
)
target_include_directories( ${PROJECT_NAME} PRIVATE ${SOURCE_DIR} )
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17 )
set_property( TARGET ${PROJECT_NAME} PROPERTY FOLDER "Compilers" )

if ( WIN32 )
	#We install each .dll in <install_dir>/bin folder
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}
		CONFIGURATIONS Release
		EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION bin
	)
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}_dev
		CONFIGURATIONS RelWithDebInfo
		EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION bin/RelWithDebInfo
	)
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}_dev
		CONFIGURATIONS Debug
		EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION bin/Debug
	)
else ()
	#We install each .so in <install_dir>/lib folder
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}
		CONFIGURATIONS Release
		EXPORT ${PROJECT_NAME}
		LIBRARY DESTINATION lib
	)
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}_dev
		CONFIGURATIONS RelWithDebInfo
		EXPORT ${PROJECT_NAME}
		LIBRARY DESTINATION lib/RelWithDebInfo
	)
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}_dev
		CONFIGURATIONS Debug
		LIBRARY DESTINATION lib/Debug
	)
endif()

# We install headers to <install_dir>/include/${PROJECT_NAME}
target_install_headers( ${PROJECT_NAME} ${SDW_SOURCE_DIR}/include/${PROJECT_NAME} )