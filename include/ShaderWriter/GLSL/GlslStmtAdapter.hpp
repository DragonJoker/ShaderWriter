/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslStmtAdapter_H___
#define ___SDW_GlslStmtAdapter_H___
#pragma once

#include "ShaderWriter/CloneStmt.hpp"
#include "ShaderWriter/GLSL/GlslHelpers.hpp"

#include <ASTGenerator/Stmt/StmtVisitor.hpp>

#include <sstream>

namespace sdw::glsl
{
	class StmtAdapter
		: public StmtCloner
	{
	public:
		static stmt::ContainerPtr submit( Shader const & shader
			, ShaderType type
			, IntrinsicsConfig const & config );

	private:
		StmtAdapter( Shader const & shader
			, ShaderType type
			, IntrinsicsConfig const & config
			, stmt::ContainerPtr & result );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

		void visitPreprocVersion( stmt::PreprocVersion * preproc )override;

	private:
		IntrinsicsConfig const & m_config;
		stmt::Container * m_intrinsics;
		ShaderType m_type;
	};
}

#endif
