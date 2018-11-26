/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprAdapter_H___
#define ___SDW_SpirvExprAdapter_H___
#pragma once

#include "SpirvHelpers.hpp"
#include "SpirvShader.hpp"
#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace spirv
{
	class ExprAdapter
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr
			, PreprocContext const & context );

	private:
		ExprAdapter( ast::expr::ExprPtr & result
			, PreprocContext const & context );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;

	private:
		PreprocContext const & m_context;
	};
}

#endif
