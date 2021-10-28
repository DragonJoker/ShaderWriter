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
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr
			, ast::stmt::Container * container
			, AdaptationData & adaptationData );

	private:
		ExprAdapter( ast::type::TypesCache & cache
			, ast::stmt::Container * container
			, AdaptationData & adaptationData
			, ast::expr::ExprPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;

	private:
		ast::type::TypesCache & m_cache;
		ast::stmt::Container * m_container;
		AdaptationData & m_adaptationData;
	};
}

#endif
