set( _FOLDER_NAME ShaderAST )
project( sdw${_FOLDER_NAME} )

set( INCLUDE_DIR ${SDW_SOURCE_DIR}/include/${_FOLDER_NAME} )
set( SOURCE_DIR ${SDW_SOURCE_DIR}/source/${_FOLDER_NAME} )

set( ${PROJECT_NAME}_HEADER_FILES
	${INCLUDE_DIR}/BoInfo.hpp
	${INCLUDE_DIR}/Shader.hpp
	${INCLUDE_DIR}/ShaderASTPrerequisites.hpp
)
set( ${PROJECT_NAME}_SOURCE_FILES
	${SOURCE_DIR}/Shader.cpp
	${SOURCE_DIR}/ShaderASTPrerequisites.cpp
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
set( ${PROJECT_NAME}_SOURCE_FILES
	${${PROJECT_NAME}_SOURCE_FILES}
	${${PROJECT_NAME}_NATVIS_FILES}
)
set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/Debug/DebugCommon.hpp
	${INCLUDE_DIR}/Debug/DebugExprVisitor.hpp
	${INCLUDE_DIR}/Debug/DebugStmtVisitor.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Debug/DebugCommon.cpp
	${SOURCE_DIR}/Debug/DebugExprVisitor.cpp
	${SOURCE_DIR}/Debug/DebugStmtVisitor.cpp
)
source_group( "Header Files\\Debug"
	FILES
		${${PROJECT_NAME}_FOLDER_HEADER_FILES}
)
source_group( "Source Files\\Debug"
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

set( ${PROJECT_NAME}_FOLDER_ENUM_FILES
	${INCLUDE_DIR}/Expr/ImageAccess.enum
	${INCLUDE_DIR}/Expr/Intrinsic.enum
	${INCLUDE_DIR}/Expr/TextureAccess.enum
)
set( ${PROJECT_NAME}_FOLDER_HEADER_FILES
	${INCLUDE_DIR}/Expr/EnumImageAccess.hpp
	${INCLUDE_DIR}/Expr/EnumIntrinsic.hpp
	${INCLUDE_DIR}/Expr/EnumTextureAccess.hpp
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
	${INCLUDE_DIR}/Expr/ExprCast.hpp
	${INCLUDE_DIR}/Expr/ExprComma.hpp
	${INCLUDE_DIR}/Expr/ExprCompositeConstruct.hpp
	${INCLUDE_DIR}/Expr/ExprDivide.hpp
	${INCLUDE_DIR}/Expr/ExprDivideAssign.hpp
	${INCLUDE_DIR}/Expr/ExprEqual.hpp
	${INCLUDE_DIR}/Expr/ExprFnCall.hpp
	${INCLUDE_DIR}/Expr/ExprGreater.hpp
	${INCLUDE_DIR}/Expr/ExprGreaterEqual.hpp
	${INCLUDE_DIR}/Expr/ExprIdentifier.hpp
	${INCLUDE_DIR}/Expr/ExprImageAccessCall.hpp
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
	${INCLUDE_DIR}/Expr/ExprSwitchCase.hpp
	${INCLUDE_DIR}/Expr/ExprSwitchTest.hpp
	${INCLUDE_DIR}/Expr/ExprSwizzle.hpp
	${INCLUDE_DIR}/Expr/ExprTextureAccessCall.hpp
	${INCLUDE_DIR}/Expr/ExprTimes.hpp
	${INCLUDE_DIR}/Expr/ExprTimesAssign.hpp
	${INCLUDE_DIR}/Expr/ExprUnary.hpp
	${INCLUDE_DIR}/Expr/ExprUnaryMinus.hpp
	${INCLUDE_DIR}/Expr/ExprUnaryPlus.hpp
	${INCLUDE_DIR}/Expr/ExprVisitor.hpp
	${INCLUDE_DIR}/Expr/ExprXorAssign.hpp
	${INCLUDE_DIR}/Expr/GetImageAccessName.hpp
	${INCLUDE_DIR}/Expr/GetIntrinsicName.hpp
	${INCLUDE_DIR}/Expr/GetTextureAccessName.hpp
	${INCLUDE_DIR}/Expr/IntrinsicCallHelpers.hpp
	${INCLUDE_DIR}/Expr/MakeImageAccess.hpp
	${INCLUDE_DIR}/Expr/MakeIntrinsic.hpp
	${INCLUDE_DIR}/Expr/MakeTextureAccess.hpp
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
	${SOURCE_DIR}/Expr/ExprCast.cpp
	${SOURCE_DIR}/Expr/ExprComma.cpp
	${SOURCE_DIR}/Expr/ExprCompositeConstruct.cpp
	${SOURCE_DIR}/Expr/ExprDivide.cpp
	${SOURCE_DIR}/Expr/ExprDivideAssign.cpp
	${SOURCE_DIR}/Expr/ExprEqual.cpp
	${SOURCE_DIR}/Expr/ExprFnCall.cpp
	${SOURCE_DIR}/Expr/ExprGreater.cpp
	${SOURCE_DIR}/Expr/ExprGreaterEqual.cpp
	${SOURCE_DIR}/Expr/ExprIdentifier.cpp
	${SOURCE_DIR}/Expr/ExprImageAccessCall.cpp
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
	${SOURCE_DIR}/Expr/ExprSwitchCase.cpp
	${SOURCE_DIR}/Expr/ExprSwitchTest.cpp
	${SOURCE_DIR}/Expr/ExprSwizzle.cpp
	${SOURCE_DIR}/Expr/ExprTextureAccessCall.cpp
	${SOURCE_DIR}/Expr/ExprTimes.cpp
	${SOURCE_DIR}/Expr/ExprTimesAssign.cpp
	${SOURCE_DIR}/Expr/ExprUnary.cpp
	${SOURCE_DIR}/Expr/ExprUnaryMinus.cpp
	${SOURCE_DIR}/Expr/ExprUnaryPlus.cpp
	${SOURCE_DIR}/Expr/ExprXorAssign.cpp
	${SOURCE_DIR}/Expr/MakeImageAccess.cpp
	${SOURCE_DIR}/Expr/MakeIntrinsic.cpp
	${SOURCE_DIR}/Expr/MakeTextureAccess.cpp
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
	${INCLUDE_DIR}/Stmt/PreprocDefine.hpp
	${INCLUDE_DIR}/Stmt/PreprocElif.hpp
	${INCLUDE_DIR}/Stmt/PreprocElse.hpp
	${INCLUDE_DIR}/Stmt/PreprocEndif.hpp
	${INCLUDE_DIR}/Stmt/PreprocExtension.hpp
	${INCLUDE_DIR}/Stmt/PreprocIf.hpp
	${INCLUDE_DIR}/Stmt/PreprocIfDef.hpp
	${INCLUDE_DIR}/Stmt/PreprocVersion.hpp
	${INCLUDE_DIR}/Stmt/Stmt.hpp
	${INCLUDE_DIR}/Stmt/StmtBreak.hpp
	${INCLUDE_DIR}/Stmt/StmtComment.hpp
	${INCLUDE_DIR}/Stmt/StmtCompound.hpp
	${INCLUDE_DIR}/Stmt/StmtConstantBufferDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtContainer.hpp
	${INCLUDE_DIR}/Stmt/StmtContinue.hpp
	${INCLUDE_DIR}/Stmt/StmtDiscard.hpp
	${INCLUDE_DIR}/Stmt/StmtDoWhile.hpp
	${INCLUDE_DIR}/Stmt/StmtElse.hpp
	${INCLUDE_DIR}/Stmt/StmtElseIf.hpp
	${INCLUDE_DIR}/Stmt/StmtFor.hpp
	${INCLUDE_DIR}/Stmt/StmtFragmentLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtFunctionDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtIf.hpp
	${INCLUDE_DIR}/Stmt/StmtImageDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtInOutVariableDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtInputComputeLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtInputGeometryLayout.hpp
	${INCLUDE_DIR}/Stmt/StmtList.hpp
	${INCLUDE_DIR}/Stmt/StmtLoop.hpp
	${INCLUDE_DIR}/Stmt/StmtOutputGeometryLayout.hpp
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
	${INCLUDE_DIR}/Stmt/StmtVariableDecl.hpp
	${INCLUDE_DIR}/Stmt/StmtVisitor.hpp
	${INCLUDE_DIR}/Stmt/StmtWhile.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Stmt/PreprocDefine.cpp
	${SOURCE_DIR}/Stmt/PreprocElif.cpp
	${SOURCE_DIR}/Stmt/PreprocElse.cpp
	${SOURCE_DIR}/Stmt/PreprocEndif.cpp
	${SOURCE_DIR}/Stmt/PreprocExtension.cpp
	${SOURCE_DIR}/Stmt/PreprocIf.cpp
	${SOURCE_DIR}/Stmt/PreprocIfDef.cpp
	${SOURCE_DIR}/Stmt/PreprocVersion.cpp
	${SOURCE_DIR}/Stmt/Stmt.cpp
	${SOURCE_DIR}/Stmt/StmtBreak.cpp
	${SOURCE_DIR}/Stmt/StmtComment.cpp
	${SOURCE_DIR}/Stmt/StmtCompound.cpp
	${SOURCE_DIR}/Stmt/StmtConstantBufferDecl.cpp
	${SOURCE_DIR}/Stmt/StmtContainer.cpp
	${SOURCE_DIR}/Stmt/StmtContinue.cpp
	${SOURCE_DIR}/Stmt/StmtDiscard.cpp
	${SOURCE_DIR}/Stmt/StmtDoWhile.cpp
	${SOURCE_DIR}/Stmt/StmtElse.cpp
	${SOURCE_DIR}/Stmt/StmtElseIf.cpp
	${SOURCE_DIR}/Stmt/StmtFor.cpp
	${SOURCE_DIR}/Stmt/StmtFragmentLayout.cpp
	${SOURCE_DIR}/Stmt/StmtFunctionDecl.cpp
	${SOURCE_DIR}/Stmt/StmtIf.cpp
	${SOURCE_DIR}/Stmt/StmtImageDecl.cpp
	${SOURCE_DIR}/Stmt/StmtInOutVariableDecl.cpp
	${SOURCE_DIR}/Stmt/StmtInputComputeLayout.cpp
	${SOURCE_DIR}/Stmt/StmtInputGeometryLayout.cpp
	${SOURCE_DIR}/Stmt/StmtLoop.cpp
	${SOURCE_DIR}/Stmt/StmtOutputGeometryLayout.cpp
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
	${INCLUDE_DIR}/Type/TypeArray.hpp
	${INCLUDE_DIR}/Type/TypeCache.hpp
	${INCLUDE_DIR}/Type/TypeFunction.hpp
	${INCLUDE_DIR}/Type/TypeImage.hpp
	${INCLUDE_DIR}/Type/TypeSampledImage.hpp
	${INCLUDE_DIR}/Type/TypeSampler.hpp
	${INCLUDE_DIR}/Type/TypeStruct.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Type/ImageConfiguration.cpp
	${SOURCE_DIR}/Type/Type.cpp
	${SOURCE_DIR}/Type/TypeArray.cpp
	${SOURCE_DIR}/Type/TypeCache.cpp
	${SOURCE_DIR}/Type/TypeFunction.cpp
	${SOURCE_DIR}/Type/TypeImage.cpp
	${SOURCE_DIR}/Type/TypeSampledImage.cpp
	${SOURCE_DIR}/Type/TypeSampler.cpp
	${SOURCE_DIR}/Type/TypeStruct.cpp
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
	${INCLUDE_DIR}/Visitors/ExprSpecialiser.hpp
	${INCLUDE_DIR}/Visitors/GetExprName.hpp
	${INCLUDE_DIR}/Visitors/GetOutermostExpr.hpp
	${INCLUDE_DIR}/Visitors/StmtSimplifier.hpp
	${INCLUDE_DIR}/Visitors/StmtSpecialiser.hpp
)
set( ${PROJECT_NAME}_FOLDER_SOURCE_FILES
	${SOURCE_DIR}/Visitors/CloneExpr.cpp
	${SOURCE_DIR}/Visitors/CloneStmt.cpp
	${SOURCE_DIR}/Visitors/ExprSpecialiser.cpp
	${SOURCE_DIR}/Visitors/GetExprName.cpp
	${SOURCE_DIR}/Visitors/GetOutermostExpr.cpp
	${SOURCE_DIR}/Visitors/StmtSimplifier.cpp
	${SOURCE_DIR}/Visitors/StmtSpecialiser.cpp
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

if ( SDW_GENERATE_SOURCE AND PYTHONINTERP_FOUND )
	set( SCRIPT_DIR ${SDW_SOURCE_DIR}/scripts/${_FOLDER_NAME} )
	file( GLOB_RECURSE ${PROJECT_NAME}_SCRIPT_FILES
		${SCRIPT_DIR}/*.py
	)
	set( GENERATED_DIR ${SDW_BINARY_DIR}/generated/${_FOLDER_NAME} )
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
		${${PROJECT_NAME}_SCRIPT_FILES}
	)
endif ()

add_library( ${PROJECT_NAME}
	STATIC
	${${PROJECT_NAME}_ENUM_FILES}
	${${PROJECT_NAME}_HEADER_FILES}
	${${PROJECT_NAME}_SOURCE_FILES}
	${${PROJECT_NAME}_SCRIPT_FILES}
)
add_library( sdw::${_FOLDER_NAME}
	ALIAS
	${PROJECT_NAME}
)
set_target_properties( ${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 17
		FOLDER "${SDW_BASE_DIR}/Core"
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

# We install headers to <install_dir>/include/${_FOLDER_NAME}
target_install_headers( ${PROJECT_NAME} ${SDW_SOURCE_DIR}/include/${_FOLDER_NAME} )
