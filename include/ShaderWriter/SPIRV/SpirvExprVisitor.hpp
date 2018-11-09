/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprVisitor_H___
#define ___SDW_SpirvExprVisitor_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>

#include <array>

namespace sdw::spirv
{
	spv::StorageClass getStorageClass( var::VariablePtr var );

	class ExprVisitor
		: public expr::SimpleVisitor
	{
	public:
		static spv::Id submit( expr::Expr * expr
			, Block & currentBlock
			, Module & module );

	private:
		ExprVisitor( spv::Id & result
			, Block & currentBlock
			, Module & module );
		void visitAssignmentExpr( expr::Assign * expr );
		void visitOpAssignmentExpr( expr::Assign * expr );

		void visitUnaryExpr( expr::Unary * expr )override;
		void visitBinaryExpr( expr::Binary * expr )override;

		void visitPreDecrementExpr( expr::PreDecrement * expr )override;
		void visitPreIncrementExpr( expr::PreIncrement * expr )override;
		void visitPostDecrementExpr( expr::PostDecrement * expr )override;
		void visitPostIncrementExpr( expr::PostIncrement * expr )override;
		void visitUnaryPlusExpr( expr::UnaryPlus * expr )override;
		void visitAddAssignExpr( expr::AddAssign * expr )override;
		void visitAndAssignExpr( expr::AndAssign * expr )override;
		void visitAssignExpr( expr::Assign * expr )override;
		void visitDivideAssignExpr( expr::DivideAssign * expr )override;
		void visitLShiftAssignExpr( expr::LShiftAssign * expr )override;
		void visitMinusAssignExpr( expr::MinusAssign * expr )override;
		void visitModuloAssignExpr( expr::ModuloAssign * expr )override;
		void visitOrAssignExpr( expr::OrAssign * expr )override;
		void visitRShiftAssignExpr( expr::RShiftAssign * expr )override;
		void visitTimesAssignExpr( expr::TimesAssign * expr )override;
		void visitXorAssignExpr( expr::XorAssign * expr )override;
		void visitAggrInitExpr( expr::AggrInit * expr )override;
		void visitArrayAccessExpr( expr::ArrayAccess * expr )override;
		void visitMbrSelectExpr( expr::MbrSelect * expr )override;
		void visitFnCallExpr( expr::FnCall * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitInitExpr( expr::Init * expr )override;
		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		void visitLiteralExpr( expr::Literal * expr )override;
		void visitQuestionExpr( expr::Question *expr )override;
		void visitSwitchCaseExpr( expr::SwitchCase *expr )override;
		void visitSwitchTestExpr( expr::SwitchTest *expr )override;
		void visitSwizzleExpr( expr::Swizzle * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;

		void handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr );
		void handleMulExtendedIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr );
		void handleAtomicIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr );
		void handleExtensionIntrinsicCallExpr( spv::Id opCode, expr::IntrinsicCall * expr );
		void handleOtherIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr );
		spv::Id getUnsignedExtendedResultTypeId( uint32_t count );
		spv::Id getSignedExtendedResultTypeId( uint32_t count );
		spv::Id getVariableIdNoLoad( expr::Expr * expr );

	private:
		spv::Id & m_result;
		Block & m_currentBlock;
		Module & m_module;
		std::array< type::StructPtr, 4u > m_unsignedExtendedTypes;
		std::array< type::StructPtr, 4u > m_signedExtendedTypes;
	};
}

#endif
