/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirVExprAdapter_H___
#define ___SDW_SpirVExprAdapter_H___
#pragma once

#include "SpirVAdaptStatements.hpp"

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
			, ast::expr::Expr const & expr
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

		using ast::ExprCloner::doSubmit;
		ast::expr::ExprPtr doSubmit( ast::expr::Expr const & expr )override;
		void visitAliasExpr( ast::expr::Alias const * expr )override;
		void visitAssignExpr( ast::expr::Assign const * expr )override;
		void visitFnCallExpr( ast::expr::FnCall const * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier const * expr )override;
		void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override;
		void visitInitExpr( ast::expr::Init const * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override;
		void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override;

		ast::expr::ExprPtr doProcessAssignExplicitToNonExplicit( ast::expr::Expr const & lhs
			, ast::expr::Expr const & rhs );

	private:
		ast::type::TypesCache & m_typesCache;
		ast::stmt::Container * m_container;
		ast::stmt::Container * m_ioDeclarations;
		AdaptationData & m_adaptationData;
	};
}

#endif
