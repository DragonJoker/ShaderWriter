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
		friend struct Routine;

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
		void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override;
		void visitTimesExpr( ast::expr::Times * expr )override;

		void doPushSplImgArg( ast::expr::Expr & imageArg
			, ast::var::VariablePtr imageVar
			, ast::expr::Expr & samplerArg
			, ast::var::VariablePtr samplerVar
			, bool writeSampler
			, ast::expr::ExprList & args );
		bool doProcessTextureArg( ast::expr::Expr & arg
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
		void doProcessTextureSize( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTextureQueryLod( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTextureQueryLevels( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTexelFetch( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTextureGradShadow( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTextureGather( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTextureGatherOffsets( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTexture( ast::expr::CombinedImageAccessCall * expr );

		ast::var::VariablePtr doMakeAlias( ast::type::TypePtr type );

		ast::expr::ExprPtr doWriteUnpack1( ast::expr::Expr & index
			, ast::expr::Expr & packed );
		ast::expr::ExprPtr doWriteUnpack2( ast::expr::Expr & index
			, ast::expr::Expr & packed );
		ast::expr::ExprPtr doWriteUnpack3( ast::expr::Expr & index
			, ast::expr::Expr & packed );

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
