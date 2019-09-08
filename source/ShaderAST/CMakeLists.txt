project( ShaderAST )

set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/${PROJECT_NAME} )
set( SOURCE_DIR ${SDW_SOURCE_DIR}/source/${PROJECT_NAME} )

file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/*.h
	${INCLUDE_DIR}/*.hpp
	${INCLUDE_DIR}/*.inl
)
file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_ENUM_FILES
	${INCLUDE_DIR}/*.enum
)
file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/*.c
	${SOURCE_DIR}/*.cpp
)
parse_subdir_files( ${SDW_SOURCE_DIR} Debug "Debug" )
parse_subdir_files( ${SDW_SOURCE_DIR} Expr "Expr" )
parse_subdir_files( ${SDW_SOURCE_DIR} Stmt "Stmt" )
parse_subdir_files( ${SDW_SOURCE_DIR} Type "Type" )
parse_subdir_files( ${SDW_SOURCE_DIR} Var "Var" )
parse_subdir_files( ${SDW_SOURCE_DIR} Visitors "Visitors" )

if ( SDW_GENERATE_SOURCE AND PYTHONINTERP_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${PROJECT_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_FOLDER_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${PROJECT_NAME} )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum ${GENERATED_DIR}/EnumImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumImageAccess.hpp ${INCLUDE_DIR}/Expr/EnumImageAccess.hpp
		COMMENT "Generating EnumImageAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetImageAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum ${GENERATED_DIR}/GetImageAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetImageAccessName.hpp ${INCLUDE_DIR}/Expr/GetImageAccessName.hpp
		COMMENT "Generating GetImageAccessName.hpp"
		DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genMakeHeaderFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum ${GENERATED_DIR}/MakeImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeImageAccess.hpp ${INCLUDE_DIR}/Expr/MakeImageAccess.hpp
		COMMENT "Generating MakeImageAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genMakeHeaderFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Expr/MakeImageAccess.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum ${GENERATED_DIR}/MakeImageAccess.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeImageAccess.cpp ${SOURCE_DIR}/Expr/MakeImageAccess.cpp
		COMMENT "Generating MakeImageAccess.cpp"
		DEPENDS ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/ImageAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumTextureAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum ${GENERATED_DIR}/EnumTextureAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumTextureAccess.hpp ${INCLUDE_DIR}/Expr/EnumTextureAccess.hpp
		COMMENT "Generating EnumTextureAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetTextureAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum ${GENERATED_DIR}/GetTextureAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetTextureAccessName.hpp ${INCLUDE_DIR}/Expr/GetTextureAccessName.hpp
		COMMENT "Generating GetTextureAccessName.hpp"
		DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeTextureAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genMakeHeaderFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum ${GENERATED_DIR}/MakeTextureAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeTextureAccess.hpp ${INCLUDE_DIR}/Expr/MakeTextureAccess.hpp
		COMMENT "Generating MakeTextureAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genMakeHeaderFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Expr/MakeTextureAccess.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum ${GENERATED_DIR}/MakeTextureAccess.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeTextureAccess.cpp ${SOURCE_DIR}/Expr/MakeTextureAccess.cpp
		COMMENT "Generating MakeTextureAccess.cpp"
		DEPENDS ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/TextureAccess.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/EnumIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumIntrinsic.hpp ${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
		COMMENT "Generating EnumIntrinsic.hpp"
		DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/GetIntrinsicName.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetIntrinsicName.hpp ${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
		COMMENT "Generating GetIntrinsicName.hpp"
		DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genMakeHeaderFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/MakeIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeIntrinsic.hpp ${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
		COMMENT "Generating MakeIntrinsic.hpp"
		DEPENDS ${SCRIPT_DIR}/genMakeHeaderFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Expr/MakeIntrinsic.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/MakeIntrinsic.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeIntrinsic.cpp ${SOURCE_DIR}/Expr/MakeIntrinsic.cpp
		COMMENT "Generating MakeIntrinsic.cpp"
		DEPENDS ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
	source_group( "Script Files" FILES
		${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
	)
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
	source_group( "Source Files\\Expr" FILES
		${SOURCE_DIR}/Expr/MakeImageAccess.cpp
		${SOURCE_DIR}/Expr/MakeTextureAccess.cpp
		${SOURCE_DIR}/Expr/MakeIntrinsic.cpp
	)
endif ()

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
	${SOURCE_DIR}/Expr/MakeImageAccess.cpp
	${SOURCE_DIR}/Expr/MakeTextureAccess.cpp
	${SOURCE_DIR}/Expr/MakeIntrinsic.cpp
	${${PROJECT_NAME}_FOLDER_ENUM_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
	${${PROJECT_NAME}_FOLDER_SCRIPT_FILES}
)
add_target_precompiled_header( ${PROJECT_NAME}
	${SDW_SOURCE_DIR}/include/${PROJECT_NAME}/ShaderASTPch.hpp
	${SDW_SOURCE_DIR}/source/${PROJECT_NAME}/ShaderASTPch.cpp
	"${CMAKE_CXX_FLAGS}"
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17 )
set_property( TARGET ${PROJECT_NAME} PROPERTY FOLDER "Core" )

#We copy each lib in <install_dir>/lib folder
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

# We install headers to <install_dir>/include/${PROJECT_NAME}
target_install_headers( ${PROJECT_NAME} ${SDW_SOURCE_DIR}/include/${PROJECT_NAME} )
