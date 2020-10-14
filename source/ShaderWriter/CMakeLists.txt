set( _FOLDER_NAME ShaderWriter )
project( ${_FOLDER_NAME} )

set( ${PROJECT_NAME}_VERSION_MAJOR 0 )
set( ${PROJECT_NAME}_VERSION_MINOR 1 )
set( ${PROJECT_NAME}_VERSION_BUILD 0 )
set( ${PROJECT_NAME}_VERSION_YEAR 2019 )

set( PROJECT_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}" )
set( PROJECT_SOVERSION "${${PROJECT_NAME}_VERSION_BUILD}" )

set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/${_FOLDER_NAME} )
set( SOURCE_DIR ${SDW_SOURCE_DIR}/source/${_FOLDER_NAME} )

set( ${PROJECT_NAME}_HEADER_FILES
	${INCLUDE_DIR}/Helpers.hpp
	${INCLUDE_DIR}/Helpers.inl
	${INCLUDE_DIR}/ShaderWriterPrerequisites.hpp
	${INCLUDE_DIR}/ShaderWriterPrerequisites.inl
	${INCLUDE_DIR}/Source.hpp
	${INCLUDE_DIR}/Value.hpp
	${INCLUDE_DIR}/Value.inl
	${INCLUDE_DIR}/Writer.hpp
	${INCLUDE_DIR}/Writer.inl
	${INCLUDE_DIR}/WriterDebug.hpp
	${SOURCE_DIR}/WriterInt.hpp
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${SOURCE_DIR}/Helpers.cpp
	${SOURCE_DIR}/ShaderWriterPrerequisites.cpp
	${SOURCE_DIR}/Value.cpp
	${SOURCE_DIR}/Writer.cpp
	${SOURCE_DIR}/WriterDebug.cpp
	${SOURCE_DIR}/WriterInt.cpp
)
source_group( "Header Files"
	FILES
		${${PROJECT_NAME}_HEADER_FILES}
)
source_group( "Source Files"
	FILES
		${${PROJECT_NAME}_SOURCE_FILES}
)

set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/BaseTypes/ArithmeticValue.hpp
	${INCLUDE_DIR}/BaseTypes/ArithmeticValue.inl
	${INCLUDE_DIR}/BaseTypes/Array.hpp
	${INCLUDE_DIR}/BaseTypes/Array.inl
	${INCLUDE_DIR}/BaseTypes/Bool.hpp
	${INCLUDE_DIR}/BaseTypes/Bool.inl
	${INCLUDE_DIR}/BaseTypes/Double.hpp
	${INCLUDE_DIR}/BaseTypes/Double.inl
	${INCLUDE_DIR}/BaseTypes/Float.hpp
	${INCLUDE_DIR}/BaseTypes/Float.inl
	${INCLUDE_DIR}/BaseTypes/Image.hpp
	${INCLUDE_DIR}/BaseTypes/Image.inl
	${INCLUDE_DIR}/BaseTypes/Int.hpp
	${INCLUDE_DIR}/BaseTypes/Int.inl
	${INCLUDE_DIR}/BaseTypes/IntegerValue.hpp
	${INCLUDE_DIR}/BaseTypes/IntegerValue.inl
	${INCLUDE_DIR}/BaseTypes/SampledImage.hpp
	${INCLUDE_DIR}/BaseTypes/SampledImage.inl
	${INCLUDE_DIR}/BaseTypes/Sampler.hpp
	${INCLUDE_DIR}/BaseTypes/Sampler.inl
	${INCLUDE_DIR}/BaseTypes/UInt.hpp
	${INCLUDE_DIR}/BaseTypes/UInt.inl
	${INCLUDE_DIR}/BaseTypes/Void.hpp
	${INCLUDE_DIR}/BaseTypes/Void.inl
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/BaseTypes/Bool.cpp
	${SOURCE_DIR}/BaseTypes/Double.cpp
	${SOURCE_DIR}/BaseTypes/Float.cpp
	${SOURCE_DIR}/BaseTypes/Image.cpp
	${SOURCE_DIR}/BaseTypes/Int.cpp
	${SOURCE_DIR}/BaseTypes/SampledImage.cpp
	${SOURCE_DIR}/BaseTypes/Sampler.cpp
	${SOURCE_DIR}/BaseTypes/UInt.cpp
	${SOURCE_DIR}/BaseTypes/Void.cpp
)
source_group( "Header Files\\BaseTypes"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\BaseTypes"
	FILES
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${${PROJECT_NAME}_SOURCE_FILES}
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)

set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/CompositeTypes/ArraySsbo.hpp
	${INCLUDE_DIR}/CompositeTypes/ArraySsbo.inl
	${INCLUDE_DIR}/CompositeTypes/Builtins.hpp
	${INCLUDE_DIR}/CompositeTypes/Function.hpp
	${INCLUDE_DIR}/CompositeTypes/Function.inl
	${INCLUDE_DIR}/CompositeTypes/FunctionParam.hpp
	${INCLUDE_DIR}/CompositeTypes/FunctionParam.inl
	${INCLUDE_DIR}/CompositeTypes/Pcb.hpp
	${INCLUDE_DIR}/CompositeTypes/Pcb.inl
	${INCLUDE_DIR}/CompositeTypes/PerVertex.hpp
	${INCLUDE_DIR}/CompositeTypes/Ssbo.hpp
	${INCLUDE_DIR}/CompositeTypes/Ssbo.inl
	${INCLUDE_DIR}/CompositeTypes/Struct.hpp
	${INCLUDE_DIR}/CompositeTypes/Struct.inl
	${INCLUDE_DIR}/CompositeTypes/StructInstance.hpp
	${INCLUDE_DIR}/CompositeTypes/StructInstance.inl
	${INCLUDE_DIR}/CompositeTypes/Ubo.hpp
	${INCLUDE_DIR}/CompositeTypes/Ubo.inl
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/CompositeTypes/ArraySsbo.cpp
	${SOURCE_DIR}/CompositeTypes/Builtins.cpp
	${SOURCE_DIR}/CompositeTypes/Pcb.cpp
	${SOURCE_DIR}/CompositeTypes/PerVertex.cpp
	${SOURCE_DIR}/CompositeTypes/Ssbo.cpp
	${SOURCE_DIR}/CompositeTypes/Struct.cpp
	${SOURCE_DIR}/CompositeTypes/StructInstance.cpp
	${SOURCE_DIR}/CompositeTypes/Ubo.cpp
)
source_group( "Header Files\\CompositeTypes"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\CompositeTypes"
	FILES
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${${PROJECT_NAME}_SOURCE_FILES}
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)

set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
	${INCLUDE_DIR}/Intrinsics/Intrinsics.hpp
	${INCLUDE_DIR}/Intrinsics/Intrinsics.inl
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
	${SOURCE_DIR}/Intrinsics/Intrinsics.cpp
)
source_group( "Header Files\\Intrinsics"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Intrinsics"
	FILES
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${${PROJECT_NAME}_SOURCE_FILES}
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)

set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/MatTypes/Mat2.hpp
	${INCLUDE_DIR}/MatTypes/Mat2.inl
	${INCLUDE_DIR}/MatTypes/Mat2x3.hpp
	${INCLUDE_DIR}/MatTypes/Mat2x3.inl
	${INCLUDE_DIR}/MatTypes/Mat2x4.hpp
	${INCLUDE_DIR}/MatTypes/Mat2x4.inl
	${INCLUDE_DIR}/MatTypes/Mat3.hpp
	${INCLUDE_DIR}/MatTypes/Mat3.inl
	${INCLUDE_DIR}/MatTypes/Mat3x2.hpp
	${INCLUDE_DIR}/MatTypes/Mat3x2.inl
	${INCLUDE_DIR}/MatTypes/Mat3x4.hpp
	${INCLUDE_DIR}/MatTypes/Mat3x4.inl
	${INCLUDE_DIR}/MatTypes/Mat4.hpp
	${INCLUDE_DIR}/MatTypes/Mat4.inl
	${INCLUDE_DIR}/MatTypes/Mat4x2.hpp
	${INCLUDE_DIR}/MatTypes/Mat4x2.inl
	${INCLUDE_DIR}/MatTypes/Mat4x3.hpp
	${INCLUDE_DIR}/MatTypes/Mat4x3.inl
)
source_group( "Header Files\\MatTypes"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)

set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/MaybeOptional/MaybeOptional.hpp
	${INCLUDE_DIR}/MaybeOptional/MaybeOptional.inl
)
source_group( "Header Files\\MaybeOptional"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)

set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/Optional/Optional.hpp
	${INCLUDE_DIR}/Optional/Optional.inl
	${INCLUDE_DIR}/Optional/OptionalUbo.hpp
	${INCLUDE_DIR}/Optional/OptionalUbo.inl
)
source_group( "Header Files\\Optional"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/VecTypes/Swizzle.hpp
	${INCLUDE_DIR}/VecTypes/Swizzle.inl
	${INCLUDE_DIR}/VecTypes/Vec2.hpp
	${INCLUDE_DIR}/VecTypes/Vec2.inl
	${INCLUDE_DIR}/VecTypes/Vec3.hpp
	${INCLUDE_DIR}/VecTypes/Vec3.inl
	${INCLUDE_DIR}/VecTypes/Vec4.hpp
	${INCLUDE_DIR}/VecTypes/Vec4.inl
)
source_group( "Header Files\\VecTypes"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)

if ( SDW_GENERATE_SOURCE AND PYTHONINTERP_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${_FOLDER_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum ${GENERATED_DIR}/IntrinsicFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/IntrinsicFunctions.hpp ${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
		COMMENT "Generating IntrinsicFunctions.hpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum ${GENERATED_DIR}/IntrinsicFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/IntrinsicFunctions.cpp ${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
		COMMENT "Generating IntrinsicFunctions.cpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum
	)
	source_group( "Script Files" FILES
		${${PROJECT_NAME}_SCRIPT_FILES}
	)
endif ()

if ( SDW_BUILD_STATIC_SDW )
	add_library( ${PROJECT_NAME}
		STATIC
		${${PROJECT_NAME}_HEADER_FILES}
		${${PROJECT_NAME}_SOURCE_FILES}
		${${PROJECT_NAME}_SCRIPT_FILES}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PUBLIC
			${_FOLDER_NAME}_Static
	)
else ()
	add_library( ${PROJECT_NAME}
		SHARED
		${${PROJECT_NAME}_HEADER_FILES}
		${${PROJECT_NAME}_SOURCE_FILES}
		${${PROJECT_NAME}_SCRIPT_FILES}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PRIVATE
			${_FOLDER_NAME}_Exports
	)
endif ()

add_library( sdw::${_FOLDER_NAME}
	ALIAS
	${PROJECT_NAME}
)
target_add_precompiled_header( ${PROJECT_NAME}
	${SDW_SOURCE_DIR}/include/${_FOLDER_NAME}/ShaderWriterPch.hpp
	${SDW_SOURCE_DIR}/source/${_FOLDER_NAME}/ShaderWriterPch.cpp
)
target_link_libraries( ${PROJECT_NAME}
	PUBLIC
		sdw::ShaderAST
)
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_SOVERSION}
		CXX_STANDARD 17
		PREFIX sdw
		FOLDER "${SDW_BASE_DIR}/Core"
)
target_include_directories( ${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${SDW_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${SDW_SOURCE_DIR}/source
		${INCLUDE_DIR}
		${SOURCE_DIR}
)
target_install_headers( ${PROJECT_NAME}
	${SDW_SOURCE_DIR}/include/${_FOLDER_NAME}
)
