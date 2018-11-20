/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtAdapter_H___
#define ___SDW_SpirvStmtAdapter_H___
#pragma once

#include "SpirvHelpers.hpp"
#include "SpirvShader.hpp"

#include "ShaderWriter/CloneStmt.hpp"

#include <sstream>

namespace sdw::spirv
{
	class StmtAdapter
		: public StmtCloner
	{
	public:
		static stmt::ContainerPtr submit( Shader const & shader
			, ShaderType type );

	private:
		StmtAdapter( Shader const & shader
			, ShaderType type
			, stmt::ContainerPtr & result );
		
		expr::ExprPtr doSubmit( expr::Expr * expr )override;

		void visitElseIfStmt( stmt::ElseIf * stmt )override;
		void visitElseStmt( stmt::Else * stmt )override;
		void visitIfStmt( stmt::If * stmt )override;
		void visitPreprocDefine( stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( stmt::PreprocElif * preproc )override;
		void visitPreprocElse( stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( stmt::PreprocEndif * preproc )override;
		void visitPreprocIf( stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( stmt::PreprocIfDef * preproc )override;

	private:
		SpirvShader m_shader;
		ShaderType m_type;
		PreprocContext m_context;
		std::vector< stmt::Switch * > m_switchStmts;
	};
}

#endif
