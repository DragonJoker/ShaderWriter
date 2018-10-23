/*
See LICENSE file in root folder
*/
#ifndef ___ShaderWriter_HlslExprAdapter_H___
#define ___ShaderWriter_HlslExprAdapter_H___
#pragma once

#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/CloneExpr.hpp"

namespace sdw::hlsl
{
	class ExprAdapter
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, IntrinsicsConfig & config
			, LinkedVars const & linkedVars
			, VariableExprMap const & inputMembers
			, VariableExprMap const & outputMembers );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, IntrinsicsConfig & config
			, LinkedVars const & linkedVars
			, VariableExprMap const & inputMembers
			, VariableExprMap const & outputMembers );

	private:
		ExprAdapter( expr::ExprPtr & result
			, IntrinsicsConfig & config
			, LinkedVars const & linkedVars
			, VariableExprMap const & inputMembers
			, VariableExprMap const & outputMembers );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;
		void visitFnCallExpr( expr::FnCall * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;
		void visitTimesExpr( expr::Times * expr )override;

	private:
		IntrinsicsConfig & m_config;
		LinkedVars const & m_linkedVars;
		VariableExprMap const & m_inputMembers;
		VariableExprMap const & m_outputMembers;
	};
}

#endif
