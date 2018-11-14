/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslStmtAdapter_H___
#define ___SDW_GlslStmtAdapter_H___
#pragma once

#include "ShaderWriter/GLSL/GlslHelpers.hpp"

#include <ASTGenerator/Stmt/StmtVisitor.hpp>

#include <sstream>

namespace sdw::glsl
{
	class StmtAdapter
		: public stmt::Visitor
	{
	public:
		static stmt::ContainerPtr submit( Shader const & shader
			, ShaderType type
			, IntrinsicsConfig const & config );

	private:
		StmtAdapter( Shader const & shader
			, ShaderType type
			, IntrinsicsConfig const & config
			, stmt::Container * result );

		void visitContainerStmt( stmt::Container * cont )override;
		void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override;
		void visitDiscardStmt( stmt::Discard * stmt )override;
		void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override;
		void visitCommentStmt( stmt::Comment * stmt )override;
		void visitCompoundStmt( stmt::Compound * stmt )override;
		void visitDoWhileStmt( stmt::DoWhile * stmt )override;
		void visitElseIfStmt( stmt::ElseIf * stmt )override;
		void visitElseStmt( stmt::Else * stmt )override;
		void visitForStmt( stmt::For * stmt )override;
		void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override;
		void visitIfStmt( stmt::If * stmt )override;
		void visitImageDeclStmt( stmt::ImageDecl * stmt )override;
		void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override;
		void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override;
		void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override;
		void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override;
		void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override;
		void visitReturnStmt( stmt::Return * stmt )override;
		void visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )override;
		void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override;
		void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override;
		void visitSimpleStmt( stmt::Simple * stmt )override;
		void visitStructureDeclStmt( stmt::StructureDecl * stmt )override;
		void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override;
		void visitSwitchStmt( stmt::Switch * stmt )override;
		void visitVariableDeclStmt( stmt::VariableDecl * stmt )override;
		void visitWhileStmt( stmt::While * stmt )override;
		void visitPreprocDefine( stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( stmt::PreprocElif * preproc )override;
		void visitPreprocElse( stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( stmt::PreprocEndif * preproc )override;
		void visitPreprocExtension( stmt::PreprocExtension * preproc )override;
		void visitPreprocIf( stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( stmt::PreprocIfDef * preproc )override;
		void visitPreprocVersion( stmt::PreprocVersion * preproc )override;

	private:
		IntrinsicsConfig const & m_config;
		stmt::Container * m_result;
		stmt::Container * m_intrinsics;
		ShaderType m_type;
		std::vector< stmt::If * > m_ifStmts;
		std::vector< stmt::Switch * > m_switchStmts;
		std::vector< stmt::PreprocIf * > m_preprocIfStmts;
		std::vector< stmt::PreprocIfDef * > m_preprocIfDefStmts;
		std::vector< bool > m_preprocIfDefs;
	};
}

#endif
