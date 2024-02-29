set( _FOLDER_NAME ShaderAST )
project( ${_FOLDER_NAME} )

set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/${_FOLDER_NAME} )
set( SOURCE_DIR ${SDW_SOURCE_DIR}/source/${_FOLDER_NAME} )

set( ${PROJECT_NAME}_HEADER_FILES
	${INCLUDE_DIR}/BoInfo.hpp
	${INCLUDE_DIR}/Shader.hpp
	${INCLUDE_DIR}/ShaderAllocator.hpp
	${INCLUDE_DIR}/ShaderASTPrerequisites.hpp
	${INCLUDE_DIR}/ShaderBuilder.hpp
	${INCLUDE_DIR}/ShaderStlTypes.hpp
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${SOURCE_DIR}/Shader.cpp
	${SOURCE_DIR}/ShaderAllocator.cpp
	${SOURCE_DIR}/ShaderASTPrerequisites.cpp
	${SOURCE_DIR}/ShaderBuilder.cpp
)
set( ${PROJECT_NAME}_NATVIS_FILES
	${SOURCE_DIR}/ShaderAST.natvis
)
source_group( "Header Files"
	FILES
		${${PROJECT_NAME}_HEADER_FILES}
)
source_group( "Source Files"
	FILES
		${${PROJECT_NAME}_SOURCE_FILES}
)
source_group( "Natvis Files"
	FILES
		${${PROJECT_NAME}_NATVIS_FILES}
)
set( ${PROJECT_NAME}_HEADER_FILES
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${${PROJECT_NAME}_SOURCE_FILES}
	${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)

set( ${PROJECT_NAME}_FOLDER_ENUM_FILES
	${INCLUDE_DIR}/Expr/Intrinsic.enum
	${INCLUDE_DIR}/Expr/CombinedImageAccess.enum
	${INCLUDE_DIR}/Expr/StorageImageAccess.enum
)
set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
	${INCLUDE_DIR}/Expr/EnumCombinedImageAccess.hpp
	${INCLUDE_DIR}/Expr/EnumStorageImageAccess.hpp
	${INCLUDE_DIR}/Expr/Expr.hpp
	${INCLUDE_DIR}/Expr/ExprAdd.hpp
	${INCLUDE_DIR}/Expr/ExprAddAssign.hpp
	${INCLUDE_DIR}/Expr/ExprAggrInit.hpp
	${INCLUDE_DIR}/Expr/ExprAlias.hpp
	${INCLUDE_DIR}/Expr/ExprAndAssign.hpp
	${INCLUDE_DIR}/Expr/ExprArrayAccess.hpp
	${INCLUDE_DIR}/Expr/ExprAssign.hpp
	${INCLUDE_DIR}/Expr/ExprBinary.hpp
	${INCLUDE_DIR}/Expr/ExprBitAnd.hpp
	${INCLUDE_DIR}/Expr/ExprBitNot.hpp
	${INCLUDE_DIR}/Expr/ExprBitOr.hpp
	${INCLUDE_DIR}/Expr/ExprBitXor.hpp
	${INCLUDE_DIR}/Expr/ExprCache.hpp
	${INCLUDE_DIR}/Expr/ExprCast.hpp
	${INCLUDE_DIR}/Expr/ExprCombinedImageAccessCall.hpp
	${INCLUDE_DIR}/Expr/ExprComma.hpp
	${INCLUDE_DIR}/Expr/ExprCompositeConstruct.hpp
	${INCLUDE_DIR}/Expr/ExprCopy.hpp
	${INCLUDE_DIR}/Expr/ExprDivide.hpp
	${INCLUDE_DIR}/Expr/ExprDivideAssign.hpp
	${INCLUDE_DIR}/Expr/ExprEqual.hpp
	${INCLUDE_DIR}/Expr/ExprFnCall.hpp
	${INCLUDE_DIR}/Expr/ExprGreater.hpp
	${INCLUDE_DIR}/Expr/ExprGreaterEqual.hpp
	${INCLUDE_DIR}/Expr/ExprIdentifier.hpp
	${INCLUDE_DIR}/Expr/ExprInit.hpp
	${INCLUDE_DIR}/Expr/ExprIntrinsicCall.hpp
	${INCLUDE_DIR}/Expr/ExprLess.hpp
	${INCLUDE_DIR}/Expr/ExprLessEqual.hpp
	${INCLUDE_DIR}/Expr/ExprList.hpp
	${INCLUDE_DIR}/Expr/ExprLiteral.hpp
	${INCLUDE_DIR}/Expr/ExprLiteral.inl
	${INCLUDE_DIR}/Expr/ExprLogAnd.hpp
	${INCLUDE_DIR}/Expr/ExprLogNot.hpp
	${INCLUDE_DIR}/Expr/ExprLogOr.hpp
	${INCLUDE_DIR}/Expr/ExprLShift.hpp
	${INCLUDE_DIR}/Expr/ExprLShiftAssign.hpp
	${INCLUDE_DIR}/Expr/ExprMbrSelect.hpp
	${INCLUDE_DIR}/Expr/ExprMinus.hpp
	${INCLUDE_DIR}/Expr/ExprMinusAssign.hpp
	${INCLUDE_DIR}/Expr/ExprModulo.hpp
	${INCLUDE_DIR}/Expr/ExprModuloAssign.hpp
	${INCLUDE_DIR}/Expr/ExprNotEqual.hpp
	${INCLUDE_DIR}/Expr/ExprOrAssign.hpp
	${INCLUDE_DIR}/Expr/ExprPostDecrement.hpp
	${INCLUDE_DIR}/Expr/ExprPostIncrement.hpp
	${INCLUDE_DIR}/Expr/ExprPreDecrement.hpp
	${INCLUDE_DIR}/Expr/ExprPreIncrement.hpp
	${INCLUDE_DIR}/Expr/ExprQuestion.hpp
	${INCLUDE_DIR}/Expr/ExprRShift.hpp
	${INCLUDE_DIR}/Expr/ExprRShiftAssign.hpp
	${INCLUDE_DIR}/Expr/ExprStorageImageAccessCall.hpp
	${INCLUDE_DIR}/Expr/ExprStreamAppend.hpp
	${INCLUDE_DIR}/Expr/ExprSwitchCase.hpp
	${INCLUDE_DIR}/Expr/ExprSwitchTest.hpp
	${INCLUDE_DIR}/Expr/ExprSwizzle.hpp
	${INCLUDE_DIR}/Expr/ExprTimes.hpp
	${INCLUDE_DIR}/Expr/ExprTimesAssign.hpp
	${INCLUDE_DIR}/Expr/ExprUnary.hpp
	${INCLUDE_DIR}/Expr/ExprUnaryMinus.hpp
	${INCLUDE_DIR}/Expr/ExprUnaryPlus.hpp
	${INCLUDE_DIR}/Expr/ExprVisitor.hpp
	${INCLUDE_DIR}/Expr/ExprXorAssign.hpp
	${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
	${INCLUDE_DIR}/Expr/GetCombinedImageAccessName.hpp
	${INCLUDE_DIR}/Expr/GetStorageImageAccessName.hpp
	${INCLUDE_DIR}/Expr/IntrinsicCallHelpers.hpp
	${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
	${INCLUDE_DIR}/Expr/MakeCombinedImageAccess.hpp
	${INCLUDE_DIR}/Expr/MakeStorageImageAccess.hpp
	${INCLUDE_DIR}/Expr/SwizzleKind.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Expr/Expr.cpp
	${SOURCE_DIR}/Expr/ExprAdd.cpp
	${SOURCE_DIR}/Expr/ExprAddAssign.cpp
	${SOURCE_DIR}/Expr/ExprAggrInit.cpp
	${SOURCE_DIR}/Expr/ExprAlias.cpp
	${SOURCE_DIR}/Expr/ExprAndAssign.cpp
	${SOURCE_DIR}/Expr/ExprArrayAccess.cpp
	${SOURCE_DIR}/Expr/ExprAssign.cpp
	${SOURCE_DIR}/Expr/ExprBinary.cpp
	${SOURCE_DIR}/Expr/ExprBitAnd.cpp
	${SOURCE_DIR}/Expr/ExprBitNot.cpp
	${SOURCE_DIR}/Expr/ExprBitOr.cpp
	${SOURCE_DIR}/Expr/ExprBitXor.cpp
	${SOURCE_DIR}/Expr/ExprCache.cpp
	${SOURCE_DIR}/Expr/ExprCast.cpp
	${SOURCE_DIR}/Expr/ExprCombinedImageAccessCall.cpp
	${SOURCE_DIR}/Expr/ExprComma.cpp
	${SOURCE_DIR}/Expr/ExprCompositeConstruct.cpp
	${SOURCE_DIR}/Expr/ExprCopy.cpp
	${SOURCE_DIR}/Expr/ExprDivide.cpp
	${SOURCE_DIR}/Expr/ExprDivideAssign.cpp
	${SOURCE_DIR}/Expr/ExprEqual.cpp
	${SOURCE_DIR}/Expr/ExprFnCall.cpp
	${SOURCE_DIR}/Expr/ExprGreater.cpp
	${SOURCE_DIR}/Expr/ExprGreaterEqual.cpp
	${SOURCE_DIR}/Expr/ExprIdentifier.cpp
	${SOURCE_DIR}/Expr/ExprInit.cpp
	${SOURCE_DIR}/Expr/ExprIntrinsicCall.cpp
	${SOURCE_DIR}/Expr/ExprLess.cpp
	${SOURCE_DIR}/Expr/ExprLessEqual.cpp
	${SOURCE_DIR}/Expr/ExprList.cpp
	${SOURCE_DIR}/Expr/ExprLiteral.cpp
	${SOURCE_DIR}/Expr/ExprLogAnd.cpp
	${SOURCE_DIR}/Expr/ExprLogNot.cpp
	${SOURCE_DIR}/Expr/ExprLogOr.cpp
	${SOURCE_DIR}/Expr/ExprLShift.cpp
	${SOURCE_DIR}/Expr/ExprLShiftAssign.cpp
	${SOURCE_DIR}/Expr/ExprMbrSelect.cpp
	${SOURCE_DIR}/Expr/ExprMinus.cpp
	${SOURCE_DIR}/Expr/ExprMinusAssign.cpp
	${SOURCE_DIR}/Expr/ExprModulo.cpp
	${SOURCE_DIR}/Expr/ExprModuloAssign.cpp
	${SOURCE_DIR}/Expr/ExprNotEqual.cpp
	${SOURCE_DIR}/Expr/ExprOrAssign.cpp
	${SOURCE_DIR}/Expr/ExprPostDecrement.cpp
	${SOURCE_DIR}/Expr/ExprPostIncrement.cpp
	${SOURCE_DIR}/Expr/ExprPreDecrement.cpp
	${SOURCE_DIR}/Expr/ExprPreIncrement.cpp
	${SOURCE_DIR}/Expr/ExprQuestion.cpp
	${SOURCE_DIR}/Expr/ExprRShift.cpp
	${SOURCE_DIR}/Expr/ExprRShiftAssign.cpp
	${SOURCE_DIR}/Expr/ExprStorageImageAccessCall.cpp
	${SOURCE_DIR}/Expr/ExprStreamAppend.cpp
	${SOURCE_DIR}/Expr/ExprSwitchCase.cpp
	${SOURCE_DIR}/Expr/ExprSwitchTest.cpp
	${SOURCE_DIR}/Expr/ExprSwizzle.cpp
	${SOURCE_DIR}/Expr/ExprTimes.cpp
	${SOURCE_DIR}/Expr/ExprTimesAssign.cpp
	${SOURCE_DIR}/Expr/ExprUnary.cpp
	${SOURCE_DIR}/Expr/ExprUnaryMinus.cpp
	${SOURCE_DIR}/Expr/ExprUnaryPlus.cpp
	${SOURCE_DIR}/Expr/ExprXorAssign.cpp
	${SOURCE_DIR}/Expr/SwizzleKind.cpp
)
source_group( "Enum Files\\Expr"
	FILES
		${${PROJECT_NAME}_FOLDER_ENUM_FILES}
)
source_group( "Header Files\\Expr"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Expr"
	FILES
		${${PROJECT_NAME}_FOLDER_SOURCE_FILES}
)
set( ${PROJECT_NAME}_ENUM_FILES
	${${PROJECT_NAME}_ENUM_FILES}
	${${PROJECT_NAME}_FOLDER_ENUM_FILES}
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
	${INCLUDE_DIR}/Stmt/PreprocExtension.hpp
	${INCLUDE_DIR}/Stmt/PreprocVersion.hpp
	${INCLUDE_DIR}/Stmt/Stmt.hpp
	${INCLUDE_DIR}/Stmt/StmtAccelerationStructureDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtBreak.hpp
	${INCLUDE_DIR}/Stmt/StmtBufferReferenceDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtCache.hpp
	${INCLUDE_DIR}/Stmt/StmtCombinedImageDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtComment.hpp
	${INCLUDE_DIR}/Stmt/StmtCompound.hpp
	${INCLUDE_DIR}/Stmt/StmtConstantBufferDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtContainer.hpp
	${INCLUDE_DIR}/Stmt/StmtContinue.hpp
	${INCLUDE_DIR}/Stmt/StmtDemote.hpp
	${INCLUDE_DIR}/Stmt/StmtDispatchMesh.hpp
	${INCLUDE_DIR}/Stmt/StmtDoWhile.hpp
	${INCLUDE_DIR}/Stmt/StmtElse.hpp
	${INCLUDE_DIR}/Stmt/StmtElseIf.hpp
	${INCLUDE_DIR}/Stmt/StmtFor.hpp
	${INCLUDE_DIR}/Stmt/StmtFragmentLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtFunctionDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtHitAttributeVariableDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtIf.hpp
	${INCLUDE_DIR}/Stmt/StmtImageDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtIgnoreIntersection.hpp
	${INCLUDE_DIR}/Stmt/StmtInOutCallableDataVariableDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtInOutRayPayloadVariableDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtInOutVariableDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtInputComputeLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtInputGeometryLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtInputTessellationEvaluationLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtLoop.hpp
	${INCLUDE_DIR}/Stmt/StmtOutputGeometryLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtOutputMeshLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtOutputTessellationControlLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtPerPrimitiveDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtPerVertexDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtPushConstantsBufferDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtReturn.hpp
	${INCLUDE_DIR}/Stmt/StmtSampledImageDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtSamplerDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtShaderBufferDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtShaderStructBufferDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtSimple.hpp
	${INCLUDE_DIR}/Stmt/StmtSpecialisationConstantDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtStructureDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtSwitch.hpp
	${INCLUDE_DIR}/Stmt/StmtSwitchCase.hpp
	${INCLUDE_DIR}/Stmt/StmtTerminateInvocation.hpp
	${INCLUDE_DIR}/Stmt/StmtTerminateRay.hpp
	${INCLUDE_DIR}/Stmt/StmtVariableDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtVisitor.hpp
	${INCLUDE_DIR}/Stmt/StmtWhile.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Stmt/PreprocExtension.cpp
	${SOURCE_DIR}/Stmt/PreprocVersion.cpp
	${SOURCE_DIR}/Stmt/Stmt.cpp
	${SOURCE_DIR}/Stmt/StmtAccelerationStructureDecl.cpp
	${SOURCE_DIR}/Stmt/StmtBreak.cpp
	${SOURCE_DIR}/Stmt/StmtBufferReferenceDecl.cpp
	${SOURCE_DIR}/Stmt/StmtCache.cpp
	${SOURCE_DIR}/Stmt/StmtCombinedImageDecl.cpp
	${SOURCE_DIR}/Stmt/StmtComment.cpp
	${SOURCE_DIR}/Stmt/StmtCompound.cpp
	${SOURCE_DIR}/Stmt/StmtConstantBufferDecl.cpp
	${SOURCE_DIR}/Stmt/StmtContainer.cpp
	${SOURCE_DIR}/Stmt/StmtContinue.cpp
	${SOURCE_DIR}/Stmt/StmtDemote.cpp
	${SOURCE_DIR}/Stmt/StmtDispatchMesh.cpp
	${SOURCE_DIR}/Stmt/StmtDoWhile.cpp
	${SOURCE_DIR}/Stmt/StmtElse.cpp
	${SOURCE_DIR}/Stmt/StmtElseIf.cpp
	${SOURCE_DIR}/Stmt/StmtFor.cpp
	${SOURCE_DIR}/Stmt/StmtFragmentLayout.cpp
	${SOURCE_DIR}/Stmt/StmtFunctionDecl.cpp
	${SOURCE_DIR}/Stmt/StmtHitAttributeVariableDecl.cpp
	${SOURCE_DIR}/Stmt/StmtIf.cpp
	${SOURCE_DIR}/Stmt/StmtImageDecl.cpp
	${SOURCE_DIR}/Stmt/StmtIgnoreIntersection.cpp
	${SOURCE_DIR}/Stmt/StmtInOutCallableDataVariableDecl.cpp
	${SOURCE_DIR}/Stmt/StmtInOutRayPayloadVariableDecl.cpp
	${SOURCE_DIR}/Stmt/StmtInOutVariableDecl.cpp
	${SOURCE_DIR}/Stmt/StmtInputComputeLayout.cpp
	${SOURCE_DIR}/Stmt/StmtInputGeometryLayout.cpp
	${SOURCE_DIR}/Stmt/StmtInputTessellationEvaluationLayout.cpp
	${SOURCE_DIR}/Stmt/StmtLoop.cpp
	${SOURCE_DIR}/Stmt/StmtOutputGeometryLayout.cpp
	${SOURCE_DIR}/Stmt/StmtOutputMeshLayout.cpp
	${SOURCE_DIR}/Stmt/StmtOutputTessellationControlLayout.cpp
	${SOURCE_DIR}/Stmt/StmtPerPrimitiveDecl.cpp
	${SOURCE_DIR}/Stmt/StmtPerVertexDecl.cpp
	${SOURCE_DIR}/Stmt/StmtPushConstantsBufferDecl.cpp
	${SOURCE_DIR}/Stmt/StmtReturn.cpp
	${SOURCE_DIR}/Stmt/StmtSampledImageDecl.cpp
	${SOURCE_DIR}/Stmt/StmtSamplerDecl.cpp
	${SOURCE_DIR}/Stmt/StmtShaderBufferDecl.cpp
	${SOURCE_DIR}/Stmt/StmtShaderStructBufferDecl.cpp
	${SOURCE_DIR}/Stmt/StmtSimple.cpp
	${SOURCE_DIR}/Stmt/StmtSpecialisationConstantDecl.cpp
	${SOURCE_DIR}/Stmt/StmtStructureDecl.cpp
	${SOURCE_DIR}/Stmt/StmtSwitch.cpp
	${SOURCE_DIR}/Stmt/StmtSwitchCase.cpp
	${SOURCE_DIR}/Stmt/StmtTerminateInvocation.cpp
	${SOURCE_DIR}/Stmt/StmtTerminateRay.cpp
	${SOURCE_DIR}/Stmt/StmtVariableDecl.cpp
	${SOURCE_DIR}/Stmt/StmtWhile.cpp
)
source_group( "Header Files\\Stmt"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Stmt"
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
	${INCLUDE_DIR}/Type/ImageConfiguration.hpp
	${INCLUDE_DIR}/Type/ImageConfiguration.inl
	${INCLUDE_DIR}/Type/Type.hpp
	${INCLUDE_DIR}/Type/TypeAccelerationStructure.hpp
	${INCLUDE_DIR}/Type/TypeArray.hpp
	${INCLUDE_DIR}/Type/TypeCache.hpp
	${INCLUDE_DIR}/Type/TypeCallableData.hpp
	${INCLUDE_DIR}/Type/TypeCombinedImage.hpp
	${INCLUDE_DIR}/Type/TypeComputeIO.hpp
	${INCLUDE_DIR}/Type/TypeFragmentIO.hpp
	${INCLUDE_DIR}/Type/TypeFunction.hpp
	${INCLUDE_DIR}/Type/TypeGeometryIO.hpp
	${INCLUDE_DIR}/Type/TypeHitAttribute.hpp
	${INCLUDE_DIR}/Type/TypeImage.hpp
	${INCLUDE_DIR}/Type/TypeMeshIO.hpp
	${INCLUDE_DIR}/Type/TypePointer.hpp
	${INCLUDE_DIR}/Type/TypeRayPayload.hpp
	${INCLUDE_DIR}/Type/TypeSampledImage.hpp
	${INCLUDE_DIR}/Type/TypeSampler.hpp
	${INCLUDE_DIR}/Type/TypeStruct.hpp
	${INCLUDE_DIR}/Type/TypeTaskIO.hpp
	${INCLUDE_DIR}/Type/TypeTessellationControlIO.hpp
	${INCLUDE_DIR}/Type/TypeTessellationEvaluationIO.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Type/ImageConfiguration.cpp
	${SOURCE_DIR}/Type/Type.cpp
	${SOURCE_DIR}/Type/TypeAccelerationStructure.cpp
	${SOURCE_DIR}/Type/TypeArray.cpp
	${SOURCE_DIR}/Type/TypeCache.cpp
	${SOURCE_DIR}/Type/TypeCallableData.cpp
	${SOURCE_DIR}/Type/TypeCombinedImage.cpp
	${SOURCE_DIR}/Type/TypeComputeIO.cpp
	${SOURCE_DIR}/Type/TypeFragmentIO.cpp
	${SOURCE_DIR}/Type/TypeFunction.cpp
	${SOURCE_DIR}/Type/TypeGeometryIO.cpp
	${SOURCE_DIR}/Type/TypeHitAttribute.cpp
	${SOURCE_DIR}/Type/TypeImage.cpp
	${SOURCE_DIR}/Type/TypeMeshIO.cpp
	${SOURCE_DIR}/Type/TypePointer.cpp
	${SOURCE_DIR}/Type/TypeRayPayload.cpp
	${SOURCE_DIR}/Type/TypeSampledImage.cpp
	${SOURCE_DIR}/Type/TypeSampler.cpp
	${SOURCE_DIR}/Type/TypeStruct.cpp
	${SOURCE_DIR}/Type/TypeTaskIO.cpp
	${SOURCE_DIR}/Type/TypeTessellationControlIO.cpp
	${SOURCE_DIR}/Type/TypeTessellationEvaluationIO.cpp
)
source_group( "Header Files\\Type"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Type"
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
	${INCLUDE_DIR}/Var/FlagHolder.hpp
	${INCLUDE_DIR}/Var/Variable.hpp
	${INCLUDE_DIR}/Var/VariableList.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Var/Variable.cpp
)
source_group( "Header Files\\Var"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Var"
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
	${INCLUDE_DIR}/Visitors/CloneExpr.hpp
	${INCLUDE_DIR}/Visitors/CloneStmt.hpp
	${INCLUDE_DIR}/Visitors/DebugDisplayStatements.hpp
	${INCLUDE_DIR}/Visitors/GetExprName.hpp
	${INCLUDE_DIR}/Visitors/GetOutermostExpr.hpp
	${INCLUDE_DIR}/Visitors/ResolveConstants.hpp
	${INCLUDE_DIR}/Visitors/SelectEntryPoint.hpp
	${INCLUDE_DIR}/Visitors/SimplifyStatements.hpp
	${INCLUDE_DIR}/Visitors/SpecialiseStatements.hpp
	${INCLUDE_DIR}/Visitors/TransformSSA.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Visitors/CloneExpr.cpp
	${SOURCE_DIR}/Visitors/CloneStmt.cpp
	${SOURCE_DIR}/Visitors/DebugDisplayStatements.cpp
	${SOURCE_DIR}/Visitors/GetExprName.cpp
	${SOURCE_DIR}/Visitors/GetOutermostExpr.cpp
	${SOURCE_DIR}/Visitors/ResolveConstants.cpp
	${SOURCE_DIR}/Visitors/SelectEntryPoint.cpp
	${SOURCE_DIR}/Visitors/SimplifyStatements.cpp
	${SOURCE_DIR}/Visitors/SpecialiseStatements.cpp
	${SOURCE_DIR}/Visitors/TransformSSA.cpp
)
source_group( "Header Files\\Visitors"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Visitors"
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

if ( SDW_GENERATE_SOURCE AND PYTHON_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${_FOLDER_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumStorageImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/StorageImageAccess.enum ${GENERATED_DIR}/EnumStorageImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumStorageImageAccess.hpp ${INCLUDE_DIR}/Expr/EnumStorageImageAccess.hpp
		COMMENT "Generating EnumStorageImageAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/StorageImageAccess.enum
	)
	set( ${PROJECT_NAME}_HEADER_FILES ${${PROJECT_NAME}_HEADER_FILES} ${INCLUDE_DIR}/Expr/EnumStorageImageAccess.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetStorageImageAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/StorageImageAccess.enum ${GENERATED_DIR}/GetStorageImageAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetStorageImageAccessName.hpp ${INCLUDE_DIR}/Expr/GetStorageImageAccessName.hpp
		COMMENT "Generating GetStorageImageAccessName.hpp"
		DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/StorageImageAccess.enum
	)
	set( ${PROJECT_NAME}_SOURCE_FILES ${${PROJECT_NAME}_SOURCE_FILES} ${INCLUDE_DIR}/Expr/GetStorageImageAccessName.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeStorageImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/StorageImageAccess.enum ${GENERATED_DIR}/MakeStorageImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeStorageImageAccess.hpp ${INCLUDE_DIR}/Expr/MakeStorageImageAccess.hpp
		COMMENT "Generating MakeStorageImageAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/StorageImageAccess.enum
	)
	set( ${PROJECT_NAME}_SOURCE_FILES ${${PROJECT_NAME}_SOURCE_FILES} ${INCLUDE_DIR}/Expr/MakeStorageImageAccess.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumCombinedImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/CombinedImageAccess.enum ${GENERATED_DIR}/EnumCombinedImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumCombinedImageAccess.hpp ${INCLUDE_DIR}/Expr/EnumCombinedImageAccess.hpp
		COMMENT "Generating EnumCombinedImageAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/CombinedImageAccess.enum
	)
	set( ${PROJECT_NAME}_HEADER_FILES ${${PROJECT_NAME}_HEADER_FILES} ${INCLUDE_DIR}/Expr/EnumCombinedImageAccess.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetCombinedImageAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/CombinedImageAccess.enum ${GENERATED_DIR}/GetCombinedImageAccessName.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetCombinedImageAccessName.hpp ${INCLUDE_DIR}/Expr/GetCombinedImageAccessName.hpp
		COMMENT "Generating GetCombinedImageAccessName.hpp"
		DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/CombinedImageAccess.enum
	)
	set( ${PROJECT_NAME}_HEADER_FILES ${${PROJECT_NAME}_HEADER_FILES} ${INCLUDE_DIR}/Expr/GetCombinedImageAccessName.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeCombinedImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/CombinedImageAccess.enum ${GENERATED_DIR}/MakeCombinedImageAccess.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeCombinedImageAccess.hpp ${INCLUDE_DIR}/Expr/MakeCombinedImageAccess.hpp
		COMMENT "Generating MakeCombinedImageAccess.hpp"
		DEPENDS ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/CombinedImageAccess.enum
	)
	set( ${PROJECT_NAME}_HEADER_FILES ${${PROJECT_NAME}_HEADER_FILES} ${INCLUDE_DIR}/Expr/MakeCombinedImageAccess.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/EnumIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/EnumIntrinsic.hpp ${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
		COMMENT "Generating EnumIntrinsic.hpp"
		DEPENDS ${SCRIPT_DIR}/genEnumFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
	set( ${PROJECT_NAME}_HEADER_FILES ${${PROJECT_NAME}_HEADER_FILES} ${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/GetIntrinsicName.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/GetIntrinsicName.hpp ${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
		COMMENT "Generating GetIntrinsicName.hpp"
		DEPENDS ${SCRIPT_DIR}/genGetNameFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
	set( ${PROJECT_NAME}_HEADER_FILES ${${PROJECT_NAME}_HEADER_FILES} ${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp )
	add_custom_command( OUTPUT ${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
		COMMAND ${Python_EXECUTABLE} ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum ${GENERATED_DIR}/MakeIntrinsic.hpp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GENERATED_DIR}/MakeIntrinsic.hpp ${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
		COMMENT "Generating MakeIntrinsic.hpp"
		DEPENDS ${SCRIPT_DIR}/genMakeSourceFromEnum.py ${INCLUDE_DIR}/Expr/Intrinsic.enum
	)
	set( ${PROJECT_NAME}_HEADER_FILES ${${PROJECT_NAME}_HEADER_FILES} ${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp )
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
		${${PROJECT_NAME}_ENUM_FILES}
		${${PROJECT_NAME}_HEADER_FILES}
		${${PROJECT_NAME}_SOURCE_FILES}
		${${PROJECT_NAME}_SCRIPT_FILES}
		${${PROJECT_NAME}_NATVIS_FILES}
	)
	target_compile_definitions( ${PROJECT_NAME}
		PUBLIC
			${_FOLDER_NAME}_Static
	)
else ()
	add_library( ${PROJECT_NAME}
		SHARED
		${${PROJECT_NAME}_ENUM_FILES}
		${${PROJECT_NAME}_HEADER_FILES}
		${${PROJECT_NAME}_SOURCE_FILES}
		${${PROJECT_NAME}_SCRIPT_FILES}
		${${PROJECT_NAME}_NATVIS_FILES}
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
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 20
		PREFIX ${SDW_LIB_PREFIX}
		FOLDER "${SDW_BASE_DIR}/Core"
		UNITY_BUILD "${PROJECTS_UNITY_BUILD}"
)
target_add_precompiled_header( ${PROJECT_NAME}
	${SDW_SOURCE_DIR}/include/${_FOLDER_NAME}/ShaderASTPch.hpp
	${SDW_SOURCE_DIR}/source/${_FOLDER_NAME}/ShaderASTPch.cpp
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
target_add_coverage_flags( ${PROJECT_NAME} )
target_add_compilation_flags( ${PROJECT_NAME} )
target_install_headers_ex( ${PROJECT_NAME}
	ShaderWriter
	${SDW_SOURCE_DIR}/include/${_FOLDER_NAME}
)
if ( PROJECTS_COMPILER_MSVC AND NOT SDW_BUILD_STATIC )
	install( FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
		DESTINATION bin
		OPTIONAL
	)
endif ()
