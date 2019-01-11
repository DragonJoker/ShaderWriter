/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprAdapter_H___
#define ___SDW_SpirvExprAdapter_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace spirv
{
	class ExprAdapter
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr
			, ast::stmt::Container * container
			, PreprocContext const & context
			, ModuleConfig const & config );

	private:
		ExprAdapter( ast::type::TypesCache & cache
			, ast::stmt::Container * container
			, PreprocContext const & context
			, ModuleConfig const & config
			, ast::expr::ExprPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitAddAssignExpr( ast::expr::AddAssign * expr )override;
		void visitAddExpr( ast::expr::Add * expr )override;
		void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override;
		void visitDivideExpr( ast::expr::Divide * expr )override;
		void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override;
		void visitMinusExpr( ast::expr::Minus * expr )override;
		void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override;
		void visitTimesExpr( ast::expr::Times * expr )override;
		void visitCastExpr( ast::expr::Cast * expr )override;
		void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override;
		void visitFnCallExpr( ast::expr::FnCall * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitQuestionExpr( ast::expr::Question * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;

		ast::expr::ExprPtr doMakeAlias( ast::expr::ExprPtr expr
			, bool param = false );
		ast::type::TypePtr doPromoteScalar( ast::expr::ExprPtr & lhs
			, ast::expr::ExprPtr & rhs );
		ast::expr::ExprPtr doWriteBinaryOperation( ast::expr::Kind operation
			, ast::type::TypePtr resType
			, ast::expr::Expr * lhs
			, ast::expr::Expr * rhs );
		ast::expr::ExprPtr doWriteMatrixBinaryOperation( ast::expr::Kind operation
			, ast::type::TypePtr resType
			, ast::expr::Expr * lhs
			, ast::expr::Expr * rhs );

		void doConstructVector( ast::expr::CompositeConstruct * expr
			, ast::expr::ExprPtr const & newArg
			, ast::type::Kind destKind
			, ast::expr::ExprList & args );
		void doConstructMatrix( ast::expr::CompositeConstruct * expr
			, ast::expr::ExprPtr const & newArg
			, ast::type::Kind destKind
			, ast::expr::ExprList & args );
		void doConstructOther( ast::expr::CompositeConstruct * expr
			, ast::expr::ExprList & args );

		ast::expr::ExprPtr doWriteToBoolCast( ast::expr::Expr * expr );
		ast::expr::ExprPtr doWriteFromBoolCast( ast::expr::Expr * expr );

	private:
		ast::type::TypesCache & m_cache;
		ast::stmt::Container * m_container;
		PreprocContext const & m_context;
		ModuleConfig const & m_config;
	};
}

#endif
