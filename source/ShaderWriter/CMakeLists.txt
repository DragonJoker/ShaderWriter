project( ShaderWriter )

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
	${SOURCE_DIR}/*.c
	${SOURCE_DIR}/*.cpp
	${SOURCE_DIR}/*.hpp
)
parse_subdir_files( ${SDW_SOURCE_DIR} BaseTypes "BaseTypes" )
parse_subdir_files( ${SDW_SOURCE_DIR} CompositeTypes "CompositeTypes" )
parse_subdir_files( ${SDW_SOURCE_DIR} HLSL "HLSL" )
parse_subdir_files( ${SDW_SOURCE_DIR} Intrinsics "Intrinsics" )
parse_subdir_files( ${SDW_SOURCE_DIR} MatTypes "MatTypes" )
parse_subdir_files( ${SDW_SOURCE_DIR} MaybeOptional "MaybeOptional" )
parse_subdir_files( ${SDW_SOURCE_DIR} Optional "Optional" )
parse_subdir_files( ${SDW_SOURCE_DIR} VecTypes "VecTypes" )
parse_subdir_files( ${SDW_SOURCE_DIR} Visitors "Visitors" )

if ( SDW_GENERATE_SOURCE AND PYTHONINTERP_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${PROJECT_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${PROJECT_NAME} )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Intrinsics/ImageAccessFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/ImageAccess.enum ${GENERATED_DIR}/ImageAccessFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/ImageAccessFunctions.hpp ${INCLUDE_DIR}/Intrinsics/ImageAccessFunctions.hpp
		COMMENT "Generating ImageAccessFunctions.hpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/ImageAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Intrinsics/TextureAccessFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/TextureAccess.enum ${GENERATED_DIR}/TextureAccessFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/TextureAccessFunctions.hpp ${INCLUDE_DIR}/Intrinsics/TextureAccessFunctions.hpp
		COMMENT "Generating TextureAccessFunctions.hpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/TextureAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum ${GENERATED_DIR}/IntrinsicFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/IntrinsicFunctions.hpp ${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
		COMMENT "Generating IntrinsicFunctions.hpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Intrinsics/ImageAccessFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/ImageAccess.enum ${GENERATED_DIR}/ImageAccessFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/ImageAccessFunctions.cpp ${SOURCE_DIR}/Intrinsics/ImageAccessFunctions.cpp
		COMMENT "Generating ImageAccessFunctions.cpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/ImageAccess.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Intrinsics/TextureAccessFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/TextureAccess.enum ${GENERATED_DIR}/TextureAccessFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/TextureAccessFunctions.cpp ${SOURCE_DIR}/Intrinsics/TextureAccessFunctions.cpp
		COMMENT "Generating TextureAccessFunctions.cpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/TextureAccess.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum ${GENERATED_DIR}/IntrinsicFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/IntrinsicFunctions.cpp ${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
		COMMENT "Generating IntrinsicFunctions.cpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum
	)
	source_group( "Script Files" FILES
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	source_group( "Header Files\\Intrinsics" FILES
		${INCLUDE_DIR}/Intrinsics/ImageAccessFunctions.hpp
		${INCLUDE_DIR}/Intrinsics/TextureAccessFunctions.hpp
		${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
	)
	source_group( "Source Files\\Intrinsics" FILES
		${SOURCE_DIR}/Intrinsics/ImageAccessFunctions.cpp
		${SOURCE_DIR}/Intrinsics/TextureAccessFunctions.cpp
		${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
	)
endif ()

add_library( ${PROJECT_NAME}
	SHARED
	${INCLUDE_DIR}/Intrinsics/ImageAccessFunctions.hpp
	${INCLUDE_DIR}/Intrinsics/TextureAccessFunctions.hpp
	${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
	${SOURCE_DIR}/Intrinsics/ImageAccessFunctions.cpp
	${SOURCE_DIR}/Intrinsics/TextureAccessFunctions.cpp
	${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
	${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
)
add_target_precompiled_header( ${PROJECT_NAME}
	${SDW_SOURCE_DIR}/include/${PROJECT_NAME}/ShaderWriterPch.hpp
	${SDW_SOURCE_DIR}/source/${PROJECT_NAME}/ShaderWriterPch.cpp
	"${CMAKE_CXX_FLAGS}"
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)
target_compile_options( ${PROJECT_NAME} PRIVATE -D${PROJECT_NAME}_Exports )
target_link_libraries( ${PROJECT_NAME}
	ShaderAST
)
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_SOVERSION}
)
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17 )
set_property( TARGET ${PROJECT_NAME} PROPERTY FOLDER "Core" )

if ( WIN32 )
	#We install each .dll in <install_dir>/bin folder
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}
		CONFIGURATIONS Release
		EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION bin
		ARCHIVE DESTINATION lib
		LIBRARY DESTINATION lib
	)
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}_dev
		CONFIGURATIONS RelWithDebInfo
		EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION bin/RelWithDebInfo
		ARCHIVE DESTINATION lib/RelWithDebInfo
		LIBRARY DESTINATION lib/RelWithDebInfo
	)
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT ${PROJECT_NAME}_dev
		CONFIGURATIONS Debug
		EXPORT ${PROJECT_NAME}
		RUNTIME DESTINATION bin/Debug
		ARCHIVE DESTINATION lib/Debug
		LIBRARY DESTINATION lib/Debug
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
