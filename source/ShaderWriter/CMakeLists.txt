set( _FOLDER_NAME ShaderWriter )
project( ${_FOLDER_NAME} )

set( ${PROJECT_NAME}_VERSION_MAJOR ${VERSION_MAJOR} )
set( ${PROJECT_NAME}_VERSION_MINOR ${VERSION_MINOR} )
set( ${PROJECT_NAME}_VERSION_BUILD ${VERSION_BUILD} )
set( ${PROJECT_NAME}_VERSION_YEAR ${VERSION_YEAR} )

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
	${INCLUDE_DIR}/WriterDebug.hpp
	${SOURCE_DIR}/WriterInt.hpp
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${SOURCE_DIR}/Helpers.cpp
	${SOURCE_DIR}/Value.cpp
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
	${INCLUDE_DIR}/CallableWriter.hpp
	${INCLUDE_DIR}/CallableWriter.inl
	${INCLUDE_DIR}/ComputeWriter.hpp
	${INCLUDE_DIR}/ComputeWriter.inl
	${INCLUDE_DIR}/EntryPointWriter.hpp
	${INCLUDE_DIR}/EntryPointWriter.inl
	${INCLUDE_DIR}/FragmentWriter.hpp
	${INCLUDE_DIR}/FragmentWriter.inl
	${INCLUDE_DIR}/GeometryWriter.hpp
	${INCLUDE_DIR}/GeometryWriter.inl
	${INCLUDE_DIR}/GraphicsPipelineWriter.hpp
	${INCLUDE_DIR}/GraphicsPipelineWriter.inl
	${INCLUDE_DIR}/MeshWriter.hpp
	${INCLUDE_DIR}/MeshWriterEXT.hpp
	${INCLUDE_DIR}/MeshWriterEXT.inl
	${INCLUDE_DIR}/MeshWriterNV.hpp
	${INCLUDE_DIR}/MeshWriterNV.inl
	${INCLUDE_DIR}/ModernGraphicsWriter.hpp
	${INCLUDE_DIR}/ModernGraphicsWriterEXT.hpp
	${INCLUDE_DIR}/ModernGraphicsWriterEXT.inl
	${INCLUDE_DIR}/ModernGraphicsWriterNV.hpp
	${INCLUDE_DIR}/ModernGraphicsWriterNV.inl
	${INCLUDE_DIR}/PipelineWriter.hpp
	${INCLUDE_DIR}/PipelineWriter.inl
	${INCLUDE_DIR}/RayAnyHitWriter.hpp
	${INCLUDE_DIR}/RayAnyHitWriter.inl
	${INCLUDE_DIR}/RayClosestHitWriter.hpp
	${INCLUDE_DIR}/RayClosestHitWriter.inl
	${INCLUDE_DIR}/RayGenerationWriter.hpp
	${INCLUDE_DIR}/RayIntersectionWriter.hpp
	${INCLUDE_DIR}/RayTraceWriter.hpp
	${INCLUDE_DIR}/RayTraceWriter.inl
	${INCLUDE_DIR}/RayMissWriter.hpp
	${INCLUDE_DIR}/RayMissWriter.inl
	${INCLUDE_DIR}/TaskWriter.hpp
	${INCLUDE_DIR}/TaskWriterEXT.hpp
	${INCLUDE_DIR}/TaskWriterEXT.inl
	${INCLUDE_DIR}/TaskWriterNV.hpp
	${INCLUDE_DIR}/TaskWriterNV.inl
	${INCLUDE_DIR}/TessellationControlWriter.hpp
	${INCLUDE_DIR}/TessellationControlWriter.inl
	${INCLUDE_DIR}/TessellationEvaluationWriter.hpp
	${INCLUDE_DIR}/TessellationEvaluationWriter.inl
	${INCLUDE_DIR}/TraditionalGraphicsWriter.hpp
	${INCLUDE_DIR}/TraditionalGraphicsWriter.inl
	${INCLUDE_DIR}/VertexWriter.hpp
	${INCLUDE_DIR}/VertexWriter.inl
	${INCLUDE_DIR}/Writer.hpp
	${INCLUDE_DIR}/Writer.inl
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/CallableWriter.cpp
	${SOURCE_DIR}/ComputeWriter.cpp
	${SOURCE_DIR}/EntryPointWriter.cpp
	${SOURCE_DIR}/FragmentWriter.cpp
	${SOURCE_DIR}/GeometryWriter.cpp
	${SOURCE_DIR}/GraphicsPipelineWriter.cpp
	${SOURCE_DIR}/MeshWriterEXT.cpp
	${SOURCE_DIR}/MeshWriterNV.cpp
	${SOURCE_DIR}/ModernGraphicsWriterEXT.cpp
	${SOURCE_DIR}/ModernGraphicsWriterNV.cpp
	${SOURCE_DIR}/PipelineWriter.cpp
	${SOURCE_DIR}/RayAnyHitWriter.cpp
	${SOURCE_DIR}/RayClosestHitWriter.cpp
	${SOURCE_DIR}/RayGenerationWriter.cpp
	${SOURCE_DIR}/RayIntersectionWriter.cpp
	${SOURCE_DIR}/RayMissWriter.cpp
	${SOURCE_DIR}/RayTraceWriter.cpp
	${SOURCE_DIR}/TaskWriterEXT.cpp
	${SOURCE_DIR}/TaskWriterNV.cpp
	${SOURCE_DIR}/TessellationControlWriter.cpp
	${SOURCE_DIR}/TessellationEvaluationWriter.cpp
	${SOURCE_DIR}/TraditionalGraphicsWriter.cpp
	${SOURCE_DIR}/VertexWriter.cpp
	${SOURCE_DIR}/Writer.cpp
)
source_group( "Header Files\\Writers"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Writers"
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
	${INCLUDE_DIR}/BaseTypes/AccelerationStructure.hpp
	${INCLUDE_DIR}/BaseTypes/ArithmeticValue.hpp
	${INCLUDE_DIR}/BaseTypes/ArithmeticValue.inl
	${INCLUDE_DIR}/BaseTypes/Array.hpp
	${INCLUDE_DIR}/BaseTypes/Array.inl
	${INCLUDE_DIR}/BaseTypes/Boolean.hpp
	${INCLUDE_DIR}/BaseTypes/Boolean.inl
	${INCLUDE_DIR}/BaseTypes/CallableData.hpp
	${INCLUDE_DIR}/BaseTypes/CallableData.inl
	${INCLUDE_DIR}/BaseTypes/CombinedImage.hpp
	${INCLUDE_DIR}/BaseTypes/CombinedImage.inl
	${INCLUDE_DIR}/BaseTypes/Defaulted.hpp
	${INCLUDE_DIR}/BaseTypes/Double.hpp
	${INCLUDE_DIR}/BaseTypes/Float.hpp
	${INCLUDE_DIR}/BaseTypes/HitAttribute.hpp
	${INCLUDE_DIR}/BaseTypes/HitAttribute.inl
	${INCLUDE_DIR}/BaseTypes/Image.hpp
	${INCLUDE_DIR}/BaseTypes/Image.inl
	${INCLUDE_DIR}/BaseTypes/Int.hpp
	${INCLUDE_DIR}/BaseTypes/IntegerValue.hpp
	${INCLUDE_DIR}/BaseTypes/IntegerValue.inl
	${INCLUDE_DIR}/BaseTypes/NonUniform.hpp
	${INCLUDE_DIR}/BaseTypes/NonUniform.inl
	${INCLUDE_DIR}/BaseTypes/RayPayload.hpp
	${INCLUDE_DIR}/BaseTypes/RayPayload.inl
	${INCLUDE_DIR}/BaseTypes/ReturnWrapper.hpp
	${INCLUDE_DIR}/BaseTypes/ReturnWrapper.inl
	${INCLUDE_DIR}/BaseTypes/SampledImage.hpp
	${INCLUDE_DIR}/BaseTypes/SampledImage.inl
	${INCLUDE_DIR}/BaseTypes/Sampler.hpp
	${INCLUDE_DIR}/BaseTypes/Sampler.inl
	${INCLUDE_DIR}/BaseTypes/StorageImage.hpp
	${INCLUDE_DIR}/BaseTypes/StorageImage.inl
	${INCLUDE_DIR}/BaseTypes/TaskPayloadEXT.hpp
	${INCLUDE_DIR}/BaseTypes/TaskPayloadEXT.inl
	${INCLUDE_DIR}/BaseTypes/TaskPayloadNV.hpp
	${INCLUDE_DIR}/BaseTypes/TaskPayloadNV.inl
	${INCLUDE_DIR}/BaseTypes/UInt.hpp
	${INCLUDE_DIR}/BaseTypes/Void.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/BaseTypes/AccelerationStructure.cpp
	${SOURCE_DIR}/BaseTypes/Boolean.cpp
	${SOURCE_DIR}/BaseTypes/CallableData.cpp
	${SOURCE_DIR}/BaseTypes/CombinedImage.cpp
	${SOURCE_DIR}/BaseTypes/Double.cpp
	${SOURCE_DIR}/BaseTypes/Float.cpp
	${SOURCE_DIR}/BaseTypes/HitAttribute.cpp
	${SOURCE_DIR}/BaseTypes/Int.cpp
	${SOURCE_DIR}/BaseTypes/RayPayload.cpp
	${SOURCE_DIR}/BaseTypes/SampledImage.cpp
	${SOURCE_DIR}/BaseTypes/Sampler.cpp
	${SOURCE_DIR}/BaseTypes/StorageImage.cpp
	${SOURCE_DIR}/BaseTypes/TaskPayloadEXT.cpp
	${SOURCE_DIR}/BaseTypes/TaskPayloadNV.cpp
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
	${INCLUDE_DIR}/CompositeTypes/ArrayStorageBuffer.hpp
	${INCLUDE_DIR}/CompositeTypes/ArrayStorageBuffer.inl
	${INCLUDE_DIR}/CompositeTypes/BufferReference.hpp
	${INCLUDE_DIR}/CompositeTypes/BufferReference.inl
	${INCLUDE_DIR}/CompositeTypes/Builtins.hpp
	${INCLUDE_DIR}/CompositeTypes/Builtins.inl
	${INCLUDE_DIR}/CompositeTypes/Function.hpp
	${INCLUDE_DIR}/CompositeTypes/Function.inl
	${INCLUDE_DIR}/CompositeTypes/FunctionParam.hpp
	${INCLUDE_DIR}/CompositeTypes/FunctionParam.inl
	${INCLUDE_DIR}/CompositeTypes/IOStructHelper.hpp
	${INCLUDE_DIR}/CompositeTypes/IOStructInstanceHelper.hpp
	${INCLUDE_DIR}/CompositeTypes/MixedStructHelper.hpp
	${INCLUDE_DIR}/CompositeTypes/MixedStructInstanceHelper.hpp
	${INCLUDE_DIR}/CompositeTypes/PerPrimitive.hpp
	${INCLUDE_DIR}/CompositeTypes/PerVertex.hpp
	${INCLUDE_DIR}/CompositeTypes/PushConstantBuffer.hpp
	${INCLUDE_DIR}/CompositeTypes/PushConstantBuffer.inl
	${INCLUDE_DIR}/CompositeTypes/RayDesc.hpp
	${INCLUDE_DIR}/CompositeTypes/StorageBuffer.hpp
	${INCLUDE_DIR}/CompositeTypes/StorageBuffer.inl
	${INCLUDE_DIR}/CompositeTypes/Struct.hpp
	${INCLUDE_DIR}/CompositeTypes/Struct.inl
	${INCLUDE_DIR}/CompositeTypes/StructHelper.hpp
	${INCLUDE_DIR}/CompositeTypes/StructInstance.hpp
	${INCLUDE_DIR}/CompositeTypes/StructInstance.inl
	${INCLUDE_DIR}/CompositeTypes/StructInstanceHelper.hpp
	${INCLUDE_DIR}/CompositeTypes/UniformBuffer.hpp
	${INCLUDE_DIR}/CompositeTypes/UniformBuffer.inl
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/CompositeTypes/ArrayStorageBuffer.cpp
	${SOURCE_DIR}/CompositeTypes/PerPrimitive.cpp
	${SOURCE_DIR}/CompositeTypes/PerVertex.cpp
	${SOURCE_DIR}/CompositeTypes/PushConstantBuffer.cpp
	${SOURCE_DIR}/CompositeTypes/RayDesc.cpp
	${SOURCE_DIR}/CompositeTypes/StorageBuffer.cpp
	${SOURCE_DIR}/CompositeTypes/Struct.cpp
	${SOURCE_DIR}/CompositeTypes/StructInstance.cpp
	${SOURCE_DIR}/CompositeTypes/UniformBuffer.cpp
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
	${INCLUDE_DIR}/VecTypes/Swizzle.hpp
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

if ( SDW_GENERATE_SOURCE AND PYTHON_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${_FOLDER_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum ${GENERATED_DIR}/IntrinsicFunctions.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/IntrinsicFunctions.hpp ${INCLUDE_DIR}/Intrinsics/IntrinsicFunctions.hpp
		COMMENT "Generating IntrinsicFunctions.hpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionHeaderFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum
	)
	add_custom_command( OUTPUT ${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum ${GENERATED_DIR}/IntrinsicFunctions.cpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/IntrinsicFunctions.cpp ${SOURCE_DIR}/Intrinsics/IntrinsicFunctions.cpp
		COMMENT "Generating IntrinsicFunctions.cpp"
		DEPENDS ${SCRIPT_DIR}/genFunctionSourceFromEnum.py ${SDW_SOURCE_DIR}/include/ShaderAST/Expr/Intrinsic.enum
	)
	source_group( "Script Files" FILES
		${${PROJECT_NAME}_SCRIPT_FILES}
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
target_sources( ${PROJECT_NAME} 
	PRIVATE
		${SDW_EDITORCONFIG_FILE}
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
		CXX_STANDARD 20
		PREFIX ${SDW_LIB_PREFIX}
		FOLDER "${SDW_BASE_DIR}/Core"
		UNITY_BUILD "${PROJECTS_UNITY_BUILD}"
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
if ( PROJECTS_COMPILER_GCC )
	if ( CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 10 )
		target_compile_definitions( ${PROJECT_NAME}
			PUBLIC
				SDW_EnableStructHelper=1
		)
	endif ()
elseif ( PROJECTS_COMPILER_CLANG )
	if ( CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 12 )
		target_compile_definitions( ${PROJECT_NAME}
			PUBLIC
				SDW_EnableStructHelper=1
		)
	endif ()
elseif ( PROJECTS_COMPILER_MSVC AND NOT SDW_BUILD_STATIC )
	if ( MSVC_VERSION GREATER_EQUAL 1930 )
		target_compile_definitions( ${PROJECT_NAME}
			PUBLIC
				SDW_EnableStructHelper=1
		)
	endif ()
	install( FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
		DESTINATION bin
		OPTIONAL
	)
endif ()
target_add_coverage_flags( ${PROJECT_NAME} )
target_add_compilation_flags( ${PROJECT_NAME} )
target_install_headers_ex( ${PROJECT_NAME}
	ShaderWriter
	${SDW_SOURCE_DIR}/include/${_FOLDER_NAME}
)
