/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprVisitor_H___
#define ___SDW_SpirvExprVisitor_H___
#pragma once

#include "CompilerSpirV/SpirvModule.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>

#include <array>

namespace spirv
{
	spv::StorageClass getStorageClass( ast::var::VariablePtr var );

	class ExprVisitor
		: public ast::expr::SimpleVisitor
	{
	public:
		static spv::Id submit( ast::expr::Expr * expr
			, Block & currentBlock
			, Module & module
			, bool loadVariable = true );
		static spv::Id submit( ast::expr::Expr * expr
			, Block & currentBlock
			, Module & module
			, bool loadVariable
			, LoadedVariableArray & loadedVariables );
		static spv::Id submit( ast::expr::Expr * expr
			, Block & currentBlock
			, Module & module
			, spv::Id initialiser
			, bool hasFuncInit
			, LoadedVariableArray & loadedVariables );

	private:
		static spv::Id submit( ast::expr::Expr * expr
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool loadVariable );
		static spv::Id submit( ast::expr::Expr * expr
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool loadVariable
			, LoadedVariableArray & loadedVariables );
		static spv::Id submit( ast::expr::Expr * expr
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, spv::Id initialiser
			, bool hasFuncInit
			, LoadedVariableArray & loadedVariables );

		ExprVisitor( spv::Id & result
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool loadVariable
			, LoadedVariableArray & loadedVariables );
		ExprVisitor( spv::Id & result
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, spv::Id initialiser
			, bool hasFuncInit
			, LoadedVariableArray & loadedVariables );
		spv::Id doSubmit( ast::expr::Expr * expr );
		spv::Id doSubmit( ast::expr::Expr * expr
			, LoadedVariableArray & loadedVariables );
		spv::Id doSubmit( ast::expr::Expr * expr
			, bool loadVariable );
		spv::Id doSubmit( ast::expr::Expr * expr
			, spv::Id initialiser
			, bool hasFuncInit );
		spv::Id doSubmit( ast::expr::Expr * expr
			, bool loadVariable
			, LoadedVariableArray & loadedVariables );
		spv::Id doSubmit( ast::expr::Expr * expr
			, bool & allLiterals
			, bool loadVariable );
		spv::Id doSubmit( ast::expr::Expr * expr
			, bool & allLiterals
			, bool loadVariable
			, LoadedVariableArray & loadedVariables );

		void visitAssignmentExpr( ast::expr::Assign * expr );
		void visitOpAssignmentExpr( ast::expr::Assign * expr );

		void visitUnaryExpr( ast::expr::Unary * expr )override;
		void visitBinaryExpr( ast::expr::Binary * expr )override;

		void visitCastExpr( ast::expr::Cast * expr )override;
		void visitPreDecrementExpr( ast::expr::PreDecrement * expr )override;
		void visitPreIncrementExpr( ast::expr::PreIncrement * expr )override;
		void visitPostDecrementExpr( ast::expr::PostDecrement * expr )override;
		void visitPostIncrementExpr( ast::expr::PostIncrement * expr )override;
		void visitUnaryPlusExpr( ast::expr::UnaryPlus * expr )override;
		void visitAddAssignExpr( ast::expr::AddAssign * expr )override;
		void visitAndAssignExpr( ast::expr::AndAssign * expr )override;
		void visitAssignExpr( ast::expr::Assign * expr )override;
		void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override;
		void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override;
		void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override;
		void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override;
		void visitOrAssignExpr( ast::expr::OrAssign * expr )override;
		void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override;
		void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override;
		void visitXorAssignExpr( ast::expr::XorAssign * expr )override;
		void visitAggrInitExpr( ast::expr::AggrInit * expr )override;
		void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override;
		void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitFnCallExpr( ast::expr::FnCall * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitInitExpr( ast::expr::Init * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitLiteralExpr( ast::expr::Literal * expr )override;
		void visitQuestionExpr( ast::expr::Question *expr )override;
		void visitSwitchCaseExpr( ast::expr::SwitchCase *expr )override;
		void visitSwitchTestExpr( ast::expr::SwitchTest *expr )override;
		void visitSwizzleExpr( ast::expr::Swizzle * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;

		void handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleExtensionIntrinsicCallExpr( spv::Id opCode, ast::expr::IntrinsicCall * expr );
		void handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		spv::Id getUnsignedExtendedResultTypeId( uint32_t count );
		spv::Id getSignedExtendedResultTypeId( uint32_t count );
		spv::Id getVariableIdNoLoad( ast::expr::Expr * expr );
		spv::Id loadVariable( spv::Id varId
			, ast::type::TypePtr type );
		spv::Id makeFunctionAlias( spv::Id source
			, ast::type::TypePtr type );

		spv::Id writeBinOpExpr( ast::expr::Kind exprKind
			, ast::type::Kind lhsTypeKind
			, ast::type::Kind rhsTypeKind
			, spv::Id typeId
			, spv::Id lhsId
			, spv::Id rhsId
			, bool isLhsSpecConstant );

		void initialiseVariable( spv::Id init
			, bool allLiterals
			, bool isFuncInit
			, ast::var::VariablePtr var
			, ast::type::TypePtr type );
	private:
		spv::Id & m_result;
		Block & m_currentBlock;
		Module & m_module;
		bool & m_allLiterals;
		bool m_loadVariable;
		spv::Id m_initialiser;
		bool m_hasFuncInit{ false };
		LoadedVariableArray & m_loadedVariables;
		std::array< ast::type::StructPtr, 4u > m_unsignedExtendedTypes;
		std::array< ast::type::StructPtr, 4u > m_signedExtendedTypes;
		VariableInfo m_info;
		uint32_t m_aliasId{ 1u };
	};
}

#endif
