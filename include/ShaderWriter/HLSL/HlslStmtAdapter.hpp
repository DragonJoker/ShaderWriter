/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslStmtAdapter_H___
#define ___SDW_HlslStmtAdapter_H___
#pragma once

#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/HLSL/HlslShader.hpp"

#include <ASTGenerator/Stmt/StmtVisitor.hpp>

#include <sstream>

namespace sdw::hlsl
{
	class StmtAdapter
		: public stmt::Visitor
	{
	public:
		static stmt::ContainerPtr submit( Shader const & shader
			, ShaderType type );

		void end();

	private:
		StmtAdapter( Shader const & shader
			, ShaderType type
			, stmt::Container * result );

		void linkVars( var::VariablePtr textureSampler
			, var::VariablePtr texture
			, var::VariablePtr sampler );

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
		void rewriteShaderIOVars();
		stmt::FunctionDeclPtr rewriteMainHeader( stmt::FunctionDecl * stmt );
		stmt::FunctionDeclPtr rewriteFuncHeader( stmt::FunctionDecl * stmt );
		void rewriteMainFooter( stmt::FunctionDecl * stmt );

	private:
		HlslShader m_shader;
		stmt::Container * m_result;
		stmt::Container * m_intrinsics;
		std::map< uint32_t, var::VariablePtr > m_inputVars;
		std::map< uint32_t, var::VariablePtr > m_outputVars;
		stmt::InputComputeLayout * m_inputComputeLayout{ nullptr };
		stmt::InputGeometryLayout * m_inputGeometryLayout{ nullptr };
		stmt::OutputGeometryLayout * m_outputGeometryLayout{ nullptr };
		type::StructPtr m_inputStruct;
		type::StructPtr m_outputStruct;
		var::VariablePtr m_inputVar;
		var::VariablePtr m_outputVar;
		VariableExprMap m_inputMembers;
		VariableExprMap m_outputMembers;
		LinkedVars m_linkedVars;
		ShaderType m_type;
		IntrinsicsConfig m_config;
		stmt::If * m_ifStmt{ nullptr };
		stmt::Switch * m_switchStmt{ nullptr };
		stmt::PreprocIf * m_preprocIfStmt{ nullptr };
		stmt::PreprocIfDef * m_preprocIfDefStmt{ nullptr };
	};
}

#endif
