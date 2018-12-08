/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtAdapter_H___
#define ___SDW_SpirvStmtAdapter_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

namespace spirv
{
	class StmtAdapter
		: public ast::StmtCloner
	{
	public:
		static ast::stmt::ContainerPtr submit( ast::stmt::Container * container
			, ModuleConfig const & config );

	private:
		StmtAdapter( ast::stmt::ContainerPtr & result
			, ModuleConfig const & config );
		
		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;

		void visitElseIfStmt( ast::stmt::ElseIf * stmt )override;
		void visitElseStmt( ast::stmt::Else * stmt )override;
		void visitIfStmt( ast::stmt::If * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitSimpleStmt( ast::stmt::Simple * stmt )override;
		void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override;
		void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override;
		void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( ast::stmt::PreprocElif * preproc )override;
		void visitPreprocElse( ast::stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override;
		void visitPreprocIf( ast::stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override;

	private:
		PreprocContext m_context;
		ModuleConfig const & m_config;
		std::vector< ast::stmt::Switch * > m_switchStmts;
	};
}

#endif
