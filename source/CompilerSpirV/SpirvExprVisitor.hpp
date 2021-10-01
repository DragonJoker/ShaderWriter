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
	struct PreprocContext;
	spv::StorageClass getStorageClass( ast::var::VariablePtr var );

	class ExprVisitor
		: public ast::expr::SimpleVisitor
	{
	public:
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool loadVariable = true
			, bool isAlias = false );
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool loadVariable
			, LoadedVariableArray & loadedVariables
			, bool isAlias = false );
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, ValueId initialiser
			, bool hasFuncInit
			, LoadedVariableArray & loadedVariables
			, bool isAlias = false );

	private:
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool loadVariable
			, bool isAlias );
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool loadVariable
			, LoadedVariableArray & loadedVariables
			, bool isAlias );
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, ValueId initialiser
			, bool hasFuncInit
			, LoadedVariableArray & loadedVariables
			, bool isAlias );

		ExprVisitor( ValueId & result
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool loadVariable
			, LoadedVariableArray & loadedVariables
			, bool isAlias );
		ExprVisitor( ValueId & result
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, ValueId initialiser
			, bool hasFuncInit
			, LoadedVariableArray & loadedVariables
			, bool isAlias );
		ValueId doSubmit( ast::expr::Expr * expr );
		ValueId doSubmit( ast::expr::Expr * expr
			, LoadedVariableArray & loadedVariables );
		ValueId doSubmit( ast::expr::Expr * expr
			, bool loadVariable );
		ValueId doSubmit( ast::expr::Expr * expr
			, ValueId initialiser
			, bool hasFuncInit );
		ValueId doSubmit( ast::expr::Expr * expr
			, bool loadVariable
			, LoadedVariableArray & loadedVariables );
		ValueId doSubmit( ast::expr::Expr * expr
			, bool & allLiterals
			, bool loadVariable );
		ValueId doSubmit( ast::expr::Expr * expr
			, bool & allLiterals
			, bool loadVariable
			, LoadedVariableArray & loadedVariables );

		void visitUnaryExpr( ast::expr::Unary * expr )override;
		void visitBinaryExpr( ast::expr::Binary * expr )override;

		void visitCastExpr( ast::expr::Cast * expr )override;
		void visitCommaExpr( ast::expr::Comma * expr )override;
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
		void visitAliasExpr( ast::expr::Alias * expr )override;

		void handleTexelPointerImageAccessCall( spv::Op opCode, ast::expr::ImageAccessCall * expr );
		void handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleExtensionIntrinsicCallExpr( spv::Id opCodeId, ast::expr::IntrinsicCall * expr );
		void handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		ValueId getUnsignedExtendedResultTypeId( uint32_t count );
		ValueId getSignedExtendedResultTypeId( uint32_t count );
		ValueId getVariablePointerId( ast::expr::Expr * expr );
		ValueId loadVariable( ValueId varId );
		void storeVariable( ValueId varId, ValueId valId );
		ValueId makeFunctionAlias( ValueId source );
		ValueId makeFunctionAlias( ValueId source
			, ast::type::TypePtr type );

		ValueId writeBinOpExpr( ast::expr::Kind exprKind
			, ast::type::Kind lhsTypeKind
			, ast::type::Kind rhsTypeKind
			, ValueId typeId
			, ValueId lhsId
			, ValueId rhsId
			, bool isLhsSpecConstant );

		bool initialiseVariable( ValueId init
			, bool allLiterals
			, bool isFuncInit
			, ast::var::VariablePtr var
			, ast::type::TypePtr type );
		ValueId visitInitialisers( ast::expr::ExprList const & initialisers
			, ast::type::TypePtr type
			, bool & allLiterals
			, bool & hasFuncInit );
	private:
		spirv::PreprocContext const & m_context;
		ValueId & m_result;
		Block & m_currentBlock;
		Module & m_module;
		bool & m_allLiterals;
		bool m_loadVariable;
		ValueId m_initialiser;
		bool m_hasFuncInit{ false };
		bool m_isAlias;
		LoadedVariableArray & m_loadedVariables;
		std::array< ast::type::StructPtr, 4u > m_unsignedExtendedTypes;
		std::array< ast::type::StructPtr, 4u > m_signedExtendedTypes;
		uint32_t m_aliasId{ 1u };
	};
}

#endif
