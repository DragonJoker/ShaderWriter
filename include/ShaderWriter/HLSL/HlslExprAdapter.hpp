/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprAdapter_H___
#define ___SDW_HlslExprAdapter_H___
#pragma once

#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/Visitors/CloneExpr.hpp"

namespace sdw::hlsl
{
	class ExprAdapter
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, IntrinsicsConfig const & config
			, AdaptationData & adaptationData
			, stmt::Container * intrinsics );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, IntrinsicsConfig const & config
			, AdaptationData & adaptationData
			, stmt::Container * intrinsics );

	private:
		ExprAdapter( expr::ExprPtr & result
			, IntrinsicsConfig const & config
			, AdaptationData & adaptationData
			, stmt::Container * intrinsics );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;
		void visitFnCallExpr( expr::FnCall * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		void visitMbrSelectExpr( expr::MbrSelect * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;
		void visitTimesExpr( expr::Times * expr )override;

		bool doProcessSampledImageArg( expr::Expr & arg
			, bool writeSampler
			, expr::ExprList & args );
		void doProcessImageSize( expr::ImageAccessCall * expr );
		void doProcessImageLoad( expr::ImageAccessCall * expr );
		void doProcessImageAtomic( expr::ImageAccessCall * expr
			, std::string const & name
			, std::map< std::string, type::TypePtr > imageAtomicFuncs );
		void doProcessImageAtomicAdd( expr::ImageAccessCall * expr );
		void doProcessImageAtomicMin( expr::ImageAccessCall * expr );
		void doProcessImageAtomicMax( expr::ImageAccessCall * expr );
		void doProcessImageAtomicAnd( expr::ImageAccessCall * expr );
		void doProcessImageAtomicOr( expr::ImageAccessCall * expr );
		void doProcessImageAtomicXor( expr::ImageAccessCall * expr );
		void doProcessImageAtomicExchange( expr::ImageAccessCall * expr );
		void doProcessImageAtomicCompSwap( expr::ImageAccessCall * expr );
		void doProcessTextureSize( expr::TextureAccessCall * expr );
		void doProcessTextureQueryLod( expr::TextureAccessCall * expr );
		void doProcessTextureQueryLevels( expr::TextureAccessCall * expr );
		void doProcessTexelFetch( expr::TextureAccessCall * expr );
		void doProcessTextureGradShadow( expr::TextureAccessCall * expr );
		void doProcessTextureGather( expr::TextureAccessCall * expr );
		void doProcessTextureGatherOffsets( expr::TextureAccessCall * expr );
		void doProcessTexture( expr::TextureAccessCall * expr );

	private:
		IntrinsicsConfig const & m_config;
		AdaptationData & m_adaptationData;
		stmt::Container * m_intrinsics;
		std::map< std::string, type::TypePtr > m_imageSizeFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicAddFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicMinFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicMaxFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicAndFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicOrFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicXorFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicExchangeFuncs;
		std::map< std::string, type::TypePtr > m_imageAtomicCompSwapFuncs;
		std::map< std::string, type::TypePtr > m_imageLodFuncs;
		std::map< std::string, type::TypePtr > m_imageLevelsFuncs;
	};
}

#endif
