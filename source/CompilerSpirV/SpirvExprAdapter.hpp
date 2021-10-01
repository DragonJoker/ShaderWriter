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
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;

	private:
		ast::type::TypesCache & m_cache;
		ast::stmt::Container * m_container;
		PreprocContext const & m_context;
		ModuleConfig const & m_config;
	};
}

#endif
