cmake_minimum_required( VERSION 3.1 )
cmake_policy( VERSION 3.1 )

#--------------------------------------------------------------------------------------------------
#	Initial configurations
#--------------------------------------------------------------------------------------------------
# Set project name, used in folders and in workspace creation
set( MAIN_PROJECT_NAME "ShaderWriter" )

# Set project version numbers
set( VERSION_MAJOR 0 )
set( VERSION_MINOR 1 )
set( VERSION_BUILD 0 )
set( VERSION_YEAR 2018 )

# Used to look for external modules
set( CMAKE_MODULE_PATH
	${CMAKE_SOURCE_DIR}/CMake
	${CMAKE_SOURCE_DIR}/CMake/Modules
	${CMAKE_SOURCE_DIR}/CMake/Toolchains
)
set( CMAKE_TEMPLATES_DIR ${CMAKE_SOURCE_DIR}/CMake/Templates )

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Experimental Precompiled headers support for GCC
include( PCHSupport )

set( CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "The configuration types" FORCE )

# Declare the project
project( ${MAIN_PROJECT_NAME} )

include( Setup )
include( Project )
include( CompilerVersion )
include( UnitTest )
include( CompilationFlags )
include( AStyleUtils )
include( ExternalDependencies )

# Organize projects into folders
set_property( GLOBAL PROPERTY USE_FOLDERS ON )

if ( WIN32 )
	set( BinLibraries
		Dbghelp
	)
else ()
	set( BinLibraries
		dl
	)
endif ()

#--------------------------------------------------------------------------------------------------
#	Looking for needed libraries
#--------------------------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
	DumpCompilerVersion( ${PROJECT_NAME}_COMPILER_VERSION )
	msg_debug( "GCC version : ${${PROJECT_NAME}_COMPILER_VERSION}" )
	if ( ${${PROJECT_NAME}_COMPILER_VERSION} LESS "49" )
		message( FATAL_ERROR "Your compiler is too old (${${PROJECT_NAME}_COMPILER_VERSION}), consider an update." )
	endif ()
elseif ( ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang" )
	DumpCompilerVersion( ${PROJECT_NAME}_COMPILER_VERSION )
	msg_debug( "clang version : ${${PROJECT_NAME}_COMPILER_VERSION}" )
elseif ( MSVC )
	if ( MSVC60 OR MSVC70 OR MSVC71 OR MSVC80 OR MSVC10 OR MSVC11 OR MSVC12 )
		message( FATAL_ERROR "Your compiler is too old, consider an update." )
	endif ()
else ()
	message( FATAL_ERROR "Unsupported compiler." )
endif ()

add_compile_options( $<$<CXX_COMPILER_ID:MSVC>:/MP> )

find_package( Doxygen )

if( DOXYGEN_FOUND )
	message( STATUS "+ Found Doxygen (version ${DOXYGEN_VERSION})" )
endif ()

#--------------------------------------------------------------------------------------------------
#	MSVC specifics
#--------------------------------------------------------------------------------------------------
if( MSVC )
	# We remove the existing /Zm flag to replace it by /Zm300
	string( REGEX REPLACE ".*(/Zm[0-9]+).*" "\\1" ZmFlag ${CMAKE_CXX_FLAGS} )
	if( (NOT "${ZmFlag}" STREQUAL "") AND (NOT "${CMAKE_CXX_FLAGS}" STREQUAL "${ZmFlag}") )
		string( REPLACE ${ZmFlag} "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} )
	endif()
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zm300" )
	add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif()

add_definitions(
 -DVERSION_MAJOR=${VERSION_MAJOR}
 -DVERSION_MINOR=${VERSION_MINOR}
 -DVERSION_BUILD=${VERSION_BUILD}
)

# Small macro to add subdirectory files to current target source and header files
macro( parse_subdir_files _FOLDER _GROUP )
	file( GLOB _FOLDER_HEADER_FILES
		${CMAKE_SOURCE_DIR}/include/${_FOLDER}/*.h
		${CMAKE_SOURCE_DIR}/include/${_FOLDER}/*.hpp
		${CMAKE_SOURCE_DIR}/include/${_FOLDER}/*.inl
	)
	file( GLOB _FOLDER_ENUM_FILES
		${CMAKE_SOURCE_DIR}/include/${_FOLDER}/*.enum
	)
	file( GLOB _FOLDER_SOURCE_FILES
		${CMAKE_SOURCE_DIR}/source/${_FOLDER}/*.c
		${CMAKE_SOURCE_DIR}/source/${_FOLDER}/*.cpp
	)
	source_group( "Enum Files\\${_GROUP}" FILES ${_FOLDER_ENUM_FILES} )
	source_group( "Header Files\\${_GROUP}" FILES ${_FOLDER_HEADER_FILES} )
	source_group( "Source Files\\${_GROUP}" FILES ${_FOLDER_SOURCE_FILES} )
endmacro()

#--------------------------------------------------------------------------------------------------
#	Adding include dirs to include search path
#--------------------------------------------------------------------------------------------------
include_directories(
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_BINARY_DIR}/include
)

option( SDW_BUILD_TESTS "Build ShaderWriter test applications" OFF )

find_package( Python )

if ( MSVC OR NOT "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	# Build projects
	# ASTGenerator library
	project( ASTGenerator )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_HEADER_FILES
		include/${PROJECT_NAME}/*.h
		include/${PROJECT_NAME}/*.hpp
		include/${PROJECT_NAME}/*.inl
	)
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_ENUM_FILES
		include/${PROJECT_NAME}/*.enum
	)
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SOURCE_FILES
		source/${PROJECT_NAME}/*.c
		source/${PROJECT_NAME}/*.cpp
	)
	parse_subdir_files( ${PROJECT_NAME}/Debug "Debug" )
	parse_subdir_files( ${PROJECT_NAME}/Expr "Expr" )
	parse_subdir_files( ${PROJECT_NAME}/Stmt "Stmt" )
	parse_subdir_files( ${PROJECT_NAME}/Type "Type" )
	parse_subdir_files( ${PROJECT_NAME}/Var "Var" )

	set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME} )

	if ( Python_FOUND )
		set( SCRIPT_DIR ${CMAKE_SOURCE_DIR}/scripts/${PROJECT_NAME} )
		file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SCRIPT_FILES
			${SCRIPT_DIR}/*.py
		)
		set( GENERATED_DIR ${CMAKE_BINARY_DIR}/generated/${PROJECT_NAME} )
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumImageAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum ${GENERATED_DIR}/EnumImageAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumImageAccess.hpp ${INCLUDE_DIR}/Expr/EnumImageAccess.hpp
			COMMENT "Generating EnumImageAccess.hpp"
			DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetImageAccessName.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum ${GENERATED_DIR}/GetImageAccessName.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetImageAccessName.hpp ${INCLUDE_DIR}/Expr/GetImageAccessName.hpp
			COMMENT "Generating GetImageAccessName.hpp"
			DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeImageAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genMakeFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum ${GENERATED_DIR}/MakeImageAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeImageAccess.hpp ${INCLUDE_DIR}/Expr/MakeImageAccess.hpp
			COMMENT "Generating MakeImageAccess.hpp"
			DEPENDS ${SCRIPT_DIR}/genMakeFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumTextureAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum ${GENERATED_DIR}/EnumTextureAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumTextureAccess.hpp ${INCLUDE_DIR}/Expr/EnumTextureAccess.hpp
			COMMENT "Generating EnumTextureAccess.hpp"
			DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetTextureAccessName.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum ${GENERATED_DIR}/GetTextureAccessName.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetTextureAccessName.hpp ${INCLUDE_DIR}/Expr/GetTextureAccessName.hpp
			COMMENT "Generating GetTextureAccessName.hpp"
			DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeTextureAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genMakeFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum ${GENERATED_DIR}/MakeTextureAccess.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeTextureAccess.hpp ${INCLUDE_DIR}/Expr/MakeTextureAccess.hpp
			COMMENT "Generating MakeTextureAccess.hpp"
			DEPENDS ${SCRIPT_DIR}/genMakeFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/EnumIntrinsic.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumIntrinsic.hpp ${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
			COMMENT "Generating EnumIntrinsic.hpp"
			DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/GetIntrinsicName.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetIntrinsicName.hpp ${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
			COMMENT "Generating GetIntrinsicName.hpp"
			DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genMakeFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/MakeIntrinsic.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeIntrinsic.hpp ${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
			COMMENT "Generating MakeIntrinsic.hpp"
			DEPENDS ${SCRIPT_DIR}/genMakeFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
		)
		source_group( "Script Files" FILES
			${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
		)
	endif ()

	source_group( "Header Files\\Expr" FILES
		${INCLUDE_DIR}/Expr/EnumImageAccess.hpp
		${INCLUDE_DIR}/Expr/GetImageAccessName.hpp
		${INCLUDE_DIR}/Expr/MakeImageAccess.hpp
		${INCLUDE_DIR}/Expr/GetTextureAccessName.hpp
		${INCLUDE_DIR}/Expr/EnumTextureAccess.hpp
		${INCLUDE_DIR}/Expr/MakeTextureAccess.hpp
		${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
		${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
		${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
	)

	add_library( ${PROJECT_NAME}
		STATIC
		${INCLUDE_DIR}/Expr/EnumImageAccess.hpp
		${INCLUDE_DIR}/Expr/GetImageAccessName.hpp
		${INCLUDE_DIR}/Expr/MakeImageAccess.hpp
		${INCLUDE_DIR}/Expr/GetTextureAccessName.hpp
		${INCLUDE_DIR}/Expr/EnumTextureAccess.hpp
		${INCLUDE_DIR}/Expr/MakeTextureAccess.hpp
		${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
		${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
		${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
		${${PROJECT_NAME}_FOLDER_ENUM_FILES}
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	add_target_precompiled_header( ${PROJECT_NAME}
		${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/ASTGeneratorPch.hpp
		${CMAKE_SOURCE_DIR}/source/${PROJECT_NAME}/ASTGeneratorPch.cpp
		"${CMAKE_CXX_FLAGS}"
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
	)
	set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17 )
	set_property( TARGET ${PROJECT_NAME} PROPERTY FOLDER "Core" )

	# ShaderWriter library
	project( ShaderWriter )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_HEADER_FILES
		include/${PROJECT_NAME}/*.h
		include/${PROJECT_NAME}/*.hpp
		include/${PROJECT_NAME}/*.inl
	)
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SOURCE_FILES
		source/${PROJECT_NAME}/*.c
		source/${PROJECT_NAME}/*.cpp
	)
	parse_subdir_files( ${PROJECT_NAME}/HLSL "HLSL" )
	parse_subdir_files( ${PROJECT_NAME}/GLSL "GLSL" )
	parse_subdir_files( ${PROJECT_NAME}/SPIRV "SPIRV" )
	parse_subdir_files( ${PROJECT_NAME}/SPIRV/spirv "SPIRV\\\\spirv" )

	set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME} )

	if ( Python_FOUND )
		set( SCRIPT_DIR ${CMAKE_SOURCE_DIR}/scripts/${PROJECT_NAME} )
		file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SCRIPT_FILES
			${SCRIPT_DIR}/*.py
		)
		set( GENERATED_DIR ${CMAKE_BINARY_DIR}/generated/${PROJECT_NAME} )
		add_custom_command( OUTPUT ${INCLUDE_DIR}/ImageAccessFunctions.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genFunctionFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/ImageAccess.enum ${GENERATED_DIR}/ImageAccessFunctions.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/ImageAccessFunctions.hpp ${INCLUDE_DIR}/ImageAccessFunctions.hpp
			COMMENT "Generating ImageAccessFunctions.hpp"
			DEPENDS ${SCRIPT_DIR}/genFunctionFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/ImageAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/TextureAccessFunctions.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genFunctionFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/TextureAccess.enum ${GENERATED_DIR}/TextureAccessFunctions.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/TextureAccessFunctions.hpp ${INCLUDE_DIR}/TextureAccessFunctions.hpp
			COMMENT "Generating TextureAccessFunctions.hpp"
			DEPENDS ${SCRIPT_DIR}/genFunctionFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/TextureAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/IntrinsicFunctions.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genFunctionFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/Intrinsic.enum ${GENERATED_DIR}/IntrinsicFunctions.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/IntrinsicFunctions.hpp ${INCLUDE_DIR}/IntrinsicFunctions.hpp
			COMMENT "Generating IntrinsicFunctions.hpp"
			DEPENDS ${SCRIPT_DIR}/genFunctionFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/Intrinsic.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/GLSL/GlslImageAccessNames.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGlslNameFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/ImageAccess.enum ${GENERATED_DIR}/GlslImageAccessNames.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GlslImageAccessNames.hpp ${INCLUDE_DIR}/GLSL/GlslImageAccessNames.hpp
			COMMENT "Generating GlslImageAccessNames.hpp"
			DEPENDS ${SCRIPT_DIR}/genGlslNameFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/ImageAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/GLSL/GlslTextureAccessNames.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGlslNameFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/TextureAccess.enum ${GENERATED_DIR}/GlslTextureAccessNames.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GlslTextureAccessNames.hpp ${INCLUDE_DIR}/GLSL/GlslTextureAccessNames.hpp
			COMMENT "Generating GlslTextureAccessNames.hpp"
			DEPENDS ${SCRIPT_DIR}/genGlslNameFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/TextureAccess.enum
		)
		add_custom_command( OUTPUT ${INCLUDE_DIR}/GLSL/GlslIntrinsicNames.hpp
			COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
			COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGlslNameFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/Intrinsic.enum ${GENERATED_DIR}/GlslIntrinsicNames.hpp
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GlslIntrinsicNames.hpp ${INCLUDE_DIR}/GLSL/GlslIntrinsicNames.hpp
			COMMENT "Generating GlslIntrinsicNames.hpp"
			DEPENDS ${SCRIPT_DIR}/genGlslNameFromEnum.py ${CMAKE_SOURCE_DIR}/include/ASTGenerator/Expr/Intrinsic.enum
		)
		source_group( "Script Files" FILES
			${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
		)
	endif ()

	source_group( "Header Files\\GLSL" FILES
		${INCLUDE_DIR}/GLSL/GlslImageAccessNames.hpp
		${INCLUDE_DIR}/GLSL/GlslTextureAccessNames.hpp
		${INCLUDE_DIR}/GLSL/GlslIntrinsicNames.hpp
	)

	add_library( ${PROJECT_NAME}
		STATIC
		${INCLUDE_DIR}/GLSL/GlslImageAccessNames.hpp
		${INCLUDE_DIR}/GLSL/GlslTextureAccessNames.hpp
		${INCLUDE_DIR}/GLSL/GlslIntrinsicNames.hpp
		${INCLUDE_DIR}/ImageAccessFunctions.hpp
		${INCLUDE_DIR}/TextureAccessFunctions.hpp
		${INCLUDE_DIR}/IntrinsicFunctions.hpp
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
	add_target_precompiled_header( ${PROJECT_NAME}
		${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/ShaderWriterPch.hpp
		${CMAKE_SOURCE_DIR}/source/${PROJECT_NAME}/ShaderWriterPch.cpp
		"${CMAKE_CXX_FLAGS}"
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
	)
	target_link_libraries( ${PROJECT_NAME}
		ASTGenerator
	)
	set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17 )
	set_property( TARGET ${PROJECT_NAME} PROPERTY FOLDER "Core" )

	if ( SDW_BUILD_TESTS )
		add_subdirectory( test )
	endif ()
else()
	message( SEND_ERROR "Please select a build type (Debug, Release or RelWithDebInfo)" )
endif()
