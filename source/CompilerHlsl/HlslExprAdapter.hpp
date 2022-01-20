/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprAdapter_H___
#define ___SDW_HlslExprAdapter_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>

namespace hlsl
{
	class ExprAdapter
		: public ast::ExprCloner
	{
		friend struct IOMapping;

	public:
		static ast::expr::ExprPtr submit( ast::type::TypesCache & cache
			, ast::expr::Expr * expr
			, ast::stmt::Container * container
			, IntrinsicsConfig const & intrinsicsConfig
			, HlslConfig const & writerConfig
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics
			, bool preventVarTypeReplacement );
		static ast::expr::ExprPtr submit( ast::type::TypesCache & cache
			, ast::expr::ExprPtr const & expr
			, ast::stmt::Container * container
			, IntrinsicsConfig const & intrinsicsConfig
			, HlslConfig const & writerConfig
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics
			, bool preventVarTypeReplacement );

	private:
		ExprAdapter( ast::type::TypesCache & cache
			, ast::expr::ExprPtr & result
			, ast::stmt::Container * container
			, IntrinsicsConfig const & intrinsicsConfig
			, HlslConfig const & writerConfig
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics
			, bool preventVarTypeReplacement );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override;
		void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitFnCallExpr( ast::expr::FnCall * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;
		void visitTimesExpr( ast::expr::Times * expr )override;

		bool doProcessSampledImageArg( ast::expr::Expr & arg
			, bool writeSampler
			, ast::expr::ExprList & args );
		void doProcessImageSize( ast::expr::ImageAccessCall * expr );
		void doProcessImageLoad( ast::expr::ImageAccessCall * expr );
		void doProcessImageStore( ast::expr::ImageAccessCall * expr
			, std::map< std::string, ast::type::FunctionPtr > & imageStoreFuncs );
		void doProcessImageAtomic( ast::expr::ImageAccessCall * expr
			, std::string const & name
			, std::map< std::string, ast::type::FunctionPtr > & imageAtomicFuncs );
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

		ast::var::VariablePtr doMakeAlias( ast::type::TypePtr type );

	private:
		ast::type::TypesCache & m_cache;
		ast::stmt::Container * m_container;
		IntrinsicsConfig const & m_intrinsicsConfig;
		HlslConfig const & m_writerConfig;
		AdaptationData & m_adaptationData;
		ast::stmt::Container * m_intrinsics;
		bool m_preventVarTypeReplacement{ false };
	};
}

#endif
