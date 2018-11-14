/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprAdapter_H___
#define ___SDW_HlslExprAdapter_H___
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
			, IntrinsicsConfig const & config
			, LinkedVars const & linkedVars
			, VariableExprMap const & inputMembers
			, VariableExprMap const & outputMembers
			, stmt::Container * intrinsics );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, IntrinsicsConfig const & config
			, LinkedVars const & linkedVars
			, VariableExprMap const & inputMembers
			, VariableExprMap const & outputMembers
			, stmt::Container * intrinsics );

	private:
		ExprAdapter( expr::ExprPtr & result
			, IntrinsicsConfig const & config
			, LinkedVars const & linkedVars
			, VariableExprMap const & inputMembers
			, VariableExprMap const & outputMembers
			, stmt::Container * intrinsics );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;
		void visitFnCallExpr( expr::FnCall * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;
		void visitTimesExpr( expr::Times * expr )override;

		bool doProcessSampledImageArg( expr::Expr & arg
			, bool writeSampler
			, expr::ExprList & args );
		expr::ExprPtr doProcessImageSize( expr::ImageAccessCall * expr );
		expr::ExprPtr doProcessImageLoad( expr::ImageAccessCall * expr );
		void doProcessTextureQueries( expr::TextureAccessCall * expr );
		void doProcessTexelFetch( expr::TextureAccessCall * expr );
		void doProcessTextureGradShadow( expr::TextureAccessCall * expr );
		void doProcessTextureGather( expr::TextureAccessCall * expr );
		void doProcessTextureGatherOffsets( expr::TextureAccessCall * expr );
		void doProcessTexture( expr::TextureAccessCall * expr );

	private:
		IntrinsicsConfig const & m_config;
		LinkedVars const & m_linkedVars;
		VariableExprMap const & m_inputMembers;
		VariableExprMap const & m_outputMembers;
		stmt::Container * m_intrinsics;
		std::map< std::string, type::TypePtr > m_imageSizeFuncs;
	};
}

#endif
