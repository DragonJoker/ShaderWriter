/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprAdapter_H___
#define ___SDW_SpirvExprAdapter_H___
#pragma once

#include "SpirvStmtAdapter.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace spirv
{
	class ExprAdapter
		: public ast::ExprCloner
	{
		friend struct IOMapping;

	public:
		static ast::expr::ExprPtr submit( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, ast::expr::Expr * expr
			, ast::stmt::Container * container
			, ast::stmt::Container * ioDeclarations
			, AdaptationData & adaptationData );

	private:
		ExprAdapter( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, ast::stmt::Container * container
			, ast::stmt::Container * ioDeclarations
			, AdaptationData & adaptationData
			, ast::expr::ExprPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		ast::expr::ExprPtr doSubmit( ast::expr::ExprPtr const & expr )override;
		void visitAssignExpr( ast::expr::Assign * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override;
		void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override;

	private:
		ast::type::TypesCache & m_typesCache;
		ast::stmt::Container * m_container;
		ast::stmt::Container * m_ioDeclarations;
		AdaptationData & m_adaptationData;
	};
}

#endif
