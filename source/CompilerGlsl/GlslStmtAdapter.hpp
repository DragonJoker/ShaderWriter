/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslStmtAdapter_H___
#define ___SDW_GlslStmtAdapter_H___
#pragma once

#include "CompilerGlsl/compileGlsl.hpp"
#include "GlslHelpers.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

namespace glsl
{
	class StmtAdapter
		: public ast::StmtCloner
	{
	public:
		static ast::stmt::ContainerPtr submit( ast::type::TypesCache & cache
			, ast::stmt::Container * container
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig );

	private:
		StmtAdapter( ast::type::TypesCache & cache
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig
			, ast::stmt::ContainerPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;

		void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override;

	private:
		ast::type::TypesCache & m_cache;
		GlslConfig const & m_writerConfig;
		IntrinsicsConfig const & m_intrinsicsConfig;
		ast::stmt::Container * m_intrinsics;
		ast::ShaderStage m_type;
	};
}

#endif
