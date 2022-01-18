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

	spv::StorageClass getStorageClass( uint32_t version
		, ast::var::VariablePtr var );

	class ExprVisitor
		: public ast::expr::SimpleVisitor
	{
	public:
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool isAlias = false );
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, ValueId initialiser
			, bool hasFuncInit
			, bool isAlias = false );

	private:
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool isAlias );
		static ValueId submit( ast::expr::Expr * expr
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, ValueId initialiser
			, bool hasFuncInit
			, bool isAlias );

		ExprVisitor( ValueId & result
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, bool isAlias );
		ExprVisitor( ValueId & result
			, PreprocContext const & context
			, Block & currentBlock
			, Module & module
			, bool & allLiterals
			, ValueId initialiser
			, bool hasFuncInit
			, bool isAlias );
		ValueId doSubmit( ast::expr::Expr * expr );
		ValueId doSubmit( ast::expr::Expr * expr
			, ValueId initialiser
			, bool hasFuncInit );
		ValueId doSubmit( ast::expr::Expr * expr
			, bool & allLiterals );

		void visitUnaryExpr( ast::expr::Unary * expr )override;
		void visitBinaryExpr( ast::expr::Binary * expr )override;

		void visitCastExpr( ast::expr::Cast * expr )override;
		void visitCommaExpr( ast::expr::Comma * expr )override;
		void visitCopyExpr( ast::expr::Copy * expr )override;
		void visitAssignExpr( ast::expr::Assign * expr )override;
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
		void visitSwizzleExpr( ast::expr::Swizzle * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;
		void visitAliasExpr( ast::expr::Alias * expr )override;

		void visitPreDecrementExpr( ast::expr::PreDecrement * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitPreIncrementExpr( ast::expr::PreIncrement * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitPostDecrementExpr( ast::expr::PostDecrement * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitPostIncrementExpr( ast::expr::PostIncrement * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitUnaryPlusExpr( ast::expr::UnaryPlus * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitAddAssignExpr( ast::expr::AddAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitAndAssignExpr( ast::expr::AndAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitOrAssignExpr( ast::expr::OrAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitXorAssignExpr( ast::expr::XorAssign * expr )override
		{
			AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
		}

		void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
		{
			AST_Failure( "Unexpected ast::expr::StreamAppend expression." );
		}

		void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
		{
			AST_Failure( "Unexpected ast::expr::SwitchCase expression." );
		}

		void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
		{
			AST_Failure( "Unexpected ast::expr::SwitchTest expression." );
		}

		void handleTexelPointerImageAccessCall( spv::Op opCode, ast::expr::ImageAccessCall * expr );
		void handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		void handleExtensionIntrinsicCallExpr( spv::Id opCodeId, ast::expr::IntrinsicCall * expr );
		void handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr );
		ValueId getUnsignedExtendedResultTypeId( uint32_t count );
		ValueId getSignedExtendedResultTypeId( uint32_t count );
		ValueId getVariablePointer( ast::expr::Expr * expr );
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
		ValueId m_initialiser;
		bool m_hasFuncInit{ false };
		bool m_isAlias;
		std::array< ast::type::BaseStructPtr, 4u > m_unsignedExtendedTypes;
		std::array< ast::type::BaseStructPtr, 4u > m_signedExtendedTypes;
		uint32_t m_aliasId{ 1u };
	};
}

#endif
