/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprAdapter_H___
#define ___SDW_SpirvExprAdapter_H___
#pragma once

#include "SpirvHelpers.hpp"
#include "SpirvShader.hpp"
#include <ASTGenerator/Visitors/CloneExpr.hpp>

namespace sdw::spirv
{
	class ExprAdapter
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, PreprocContext const & context );

	private:
		ExprAdapter( expr::ExprPtr & result
			, PreprocContext const & context );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;

	private:
		PreprocContext const & m_context;
	};
}

#endif
