/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprAdapter_H___
#define ___SDW_HlslExprAdapter_H___
#pragma once

#include "HlslHelpers.hpp"
#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace hlsl
{
	class ExprAdapter
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr
			, IntrinsicsConfig const & config
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics );
		static ast::expr::ExprPtr submit( ast::expr::ExprPtr const & expr
			, IntrinsicsConfig const & config
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics );

	private:
		ExprAdapter( ast::expr::ExprPtr & result
			, IntrinsicsConfig const & config
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitFnCallExpr( ast::expr::FnCall * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;
		void visitTimesExpr( ast::expr::Times * expr )override;

		bool doProcessSampledImageArg( ast::expr::Expr & arg
			, bool writeSampler
			, ast::expr::ExprList & args );
		void doProcessImageSize( ast::expr::ImageAccessCall * expr );
		void doProcessImageLoad( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomic( ast::expr::ImageAccessCall * expr
			, std::string const & name
			, std::map< std::string, ast::type::TypePtr > imageAtomicFuncs );
		void doProcessImageAtomicAdd( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomicMin( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomicMax( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomicAnd( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomicOr( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomicXor( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomicExchange( ast::expr::ImageAccessCall * expr );
		void doProcessImageAtomicCompSwap( ast::expr::ImageAccessCall * expr );
		void doProcessTextureSize( ast::expr::TextureAccessCall * expr );
		void doProcessTextureQueryLod( ast::expr::TextureAccessCall * expr );
		void doProcessTextureQueryLevels( ast::expr::TextureAccessCall * expr );
		void doProcessTexelFetch( ast::expr::TextureAccessCall * expr );
		void doProcessTextureGradShadow( ast::expr::TextureAccessCall * expr );
		void doProcessTextureGather( ast::expr::TextureAccessCall * expr );
		void doProcessTextureGatherOffsets( ast::expr::TextureAccessCall * expr );
		void doProcessTexture( ast::expr::TextureAccessCall * expr );

	private:
		IntrinsicsConfig const & m_config;
		AdaptationData & m_adaptationData;
		ast::stmt::Container * m_intrinsics;
		std::map< std::string, ast::type::TypePtr > m_imageSizeFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicAddFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicMinFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicMaxFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicAndFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicOrFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicXorFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicExchangeFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageAtomicCompSwapFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageLodFuncs;
		std::map< std::string, ast::type::TypePtr > m_imageLevelsFuncs;
	};
}

#endif