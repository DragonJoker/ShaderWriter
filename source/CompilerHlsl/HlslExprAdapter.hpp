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
	struct IntrinsicAdaptationInfo;

	class ExprAdapter
		: public ast::ExprCloner
	{
		friend struct IOMapping;
		friend struct Routine;

	public:
		static ast::expr::ExprPtr submit( ast::stmt::StmtCache & stmtCache
			, ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, ast::expr::Expr const & expr
			, ast::stmt::Container * container
			, IntrinsicsConfig const & intrinsicsConfig
			, HlslConfig const & writerConfig
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics
			, bool preventVarTypeReplacement );

	private:
		ExprAdapter( ast::stmt::StmtCache & stmtCache
			, ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, ast::expr::ExprPtr & result
			, ast::stmt::Container * container
			, IntrinsicsConfig const & intrinsicsConfig
			, HlslConfig const & writerConfig
			, AdaptationData & adaptationData
			, ast::stmt::Container * intrinsics
			, bool preventVarTypeReplacement );

		using ast::ExprCloner::doSubmit;
		ast::expr::ExprPtr doSubmit( ast::expr::Expr const & expr )override;
		void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override;
		void visitAssignExpr( ast::expr::Assign const * expr )override;
		void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier const * expr )override;
		void visitFnCallExpr( ast::expr::FnCall const * expr )override;
		void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override;
		void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override;
		void visitTimesExpr( ast::expr::Times const * expr )override;

		void doPushSplImgArg( ast::expr::Expr const & imageArg
			, ast::var::VariablePtr imageVar
			, ast::expr::Expr const & samplerArg
			, ast::var::VariablePtr samplerVar
			, bool writeSampler
			, ast::expr::ExprList & args );
		void doProcessIntrinsicOperator( ast::expr::IntrinsicCall const & expr
			, IntrinsicAdaptationInfo const & adaptationInfo );
		void doProcessIntrinsicAtomic( ast::expr::IntrinsicCall const & expr );
		void doProcessIntrinsicPackedPrimitiveIndices( ast::expr::IntrinsicCall const & expr );
		void doProcessSingleArgCompositeConstruct( ast::expr::CompositeConstruct const & expr );
		bool doProcessTextureArg( ast::expr::Expr const & arg
			, bool writeSampler
			, ast::expr::ExprList & args );
		void doProcessImageSize( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageLoad( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageStore( ast::expr::StorageImageAccessCall const & expr
			, std::map< std::string, FuncNames::Function, std::less<> > & imageStoreFuncs );
		void doProcessImageAtomic( ast::expr::StorageImageAccessCall const & expr
			, std::string const & name
			, std::map< std::string, FuncNames::Function, std::less<> > & imageAtomicFuncs );
		void doProcessImageAtomicAdd( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageAtomicMin( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageAtomicMax( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageAtomicAnd( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageAtomicOr( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageAtomicXor( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageAtomicExchange( ast::expr::StorageImageAccessCall const & expr );
		void doProcessImageAtomicCompSwap( ast::expr::StorageImageAccessCall const & expr );
		void doProcessTextureSize( ast::expr::CombinedImageAccessCall const & expr );
		void doProcessTextureQueryLod( ast::expr::CombinedImageAccessCall const & expr );
		void doProcessTextureQueryLevels( ast::expr::CombinedImageAccessCall const & expr );
		void doProcessTexelFetch( ast::expr::CombinedImageAccessCall const & expr );
		void doProcessTextureGradShadow( ast::expr::CombinedImageAccessCall const & expr );
		void doProcessTextureGather( ast::expr::CombinedImageAccessCall const & expr );
		void doProcessTextureGatherOffsets( ast::expr::CombinedImageAccessCall const & expr );
		void doProcessTexture( ast::expr::CombinedImageAccessCall const & expr );

		ast::var::VariablePtr doMakeAlias( ast::type::TypePtr type );

		ast::expr::ExprPtr doWriteUnpack1( ast::expr::Expr const & packed );
		ast::expr::ExprPtr doWriteUnpack2( ast::expr::Expr const & packed );
		ast::expr::ExprPtr doWriteUnpack3( ast::expr::Expr const & packed );

	private:
		ast::stmt::StmtCache & m_stmtCache;
		ast::type::TypesCache & m_typesCache;
		ast::stmt::Container * m_container;
		IntrinsicsConfig const & m_intrinsicsConfig;
		HlslConfig const & m_writerConfig;
		AdaptationData & m_adaptationData;
		ast::stmt::Container * m_intrinsics;
		bool m_preventVarTypeReplacement{ false };
	};
}

#endif
