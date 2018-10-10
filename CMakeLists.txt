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
	file( GLOB _FOLDER_SOURCE_FILES
		${CMAKE_SOURCE_DIR}/source/${_FOLDER}/*.c
		${CMAKE_SOURCE_DIR}/source/${_FOLDER}/*.cpp
	)
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

if ( MSVC OR NOT "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	# Build projects
	# ASTGenerator library
	project( ASTGenerator )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_HEADER_FILES
		include/${PROJECT_NAME}/*.h
		include/${PROJECT_NAME}/*.hpp
		include/${PROJECT_NAME}/*.inl
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
	add_library( ${PROJECT_NAME}
		STATIC
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
	)
	add_target_precompiled_header( ${PROJECT_NAME}
		${PROJECT_NAME}/ASTGeneratorPch.hpp
		${CMAKE_SOURCE_DIR}/source/${PROJECT_NAME}/ASTGeneratorPch.cpp
		${CMAKE_CXX_FLAGS}
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
	)
	set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17 )
	set_property( TARGET ${PROJECT_NAME} PROPERTY FOLDER "Core" )

	if ( SDW_BUILD_TESTS )
		add_subdirectory( test )
	endif ()
else()
	message( SEND_ERROR "Please select a build type (Debug, Release or RelWithDebInfo)" )
endif()
