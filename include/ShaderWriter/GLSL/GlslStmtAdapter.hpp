/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslStmtAdapter_H___
#define ___SDW_GlslStmtAdapter_H___
#pragma once

#include "ShaderWriter/WriterGlsl.hpp"
#include "ShaderWriter/GLSL/GlslHelpers.hpp"

#include <ASTGenerator/Visitors/CloneStmt.hpp>

namespace sdw::glsl
{
	class StmtAdapter
		: public ast::StmtCloner
	{
	public:
		static stmt::ContainerPtr submit( Shader const & shader
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig );

	private:
		StmtAdapter( Shader const & shader
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig
			, stmt::ContainerPtr & result );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

		void visitPreprocVersion( stmt::PreprocVersion * preproc )override;

	private:
		GlslConfig const & m_writerConfig;
		IntrinsicsConfig const & m_intrinsicsConfig;
		stmt::Container * m_intrinsics;
		ShaderType m_type;
	};
}

#endif
