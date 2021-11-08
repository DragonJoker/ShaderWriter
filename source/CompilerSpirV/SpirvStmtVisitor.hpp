/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtVisitor_H___
#define ___SDW_SpirvStmtVisitor_H___
#pragma once

#include "CompilerSpirV/SpirvCountActions.hpp"
#include "CompilerSpirV/SpirvHelpers.hpp"
#include "CompilerSpirV/SpirvModule.hpp"

#include <ShaderAST/Stmt/StmtVisitor.hpp>

namespace spirv
{
	class StmtVisitor
		: public ast::stmt::Visitor
	{
	public:
		static Module submit( ast::type::TypesCache & cache
			, ast::stmt::Stmt * stmt
			, ast::ShaderStage type
			, ModuleConfig const & moduleConfig
			, spirv::PreprocContext context
			, SpirVConfig const & spirvConfig
			, ShaderActions actions );

	private:
		StmtVisitor( Module & result
			, ast::ShaderStage type
			, ModuleConfig const & moduleConfig
			, spirv::PreprocContext context
			, SpirVConfig const & spirvConfig
			, ShaderActions actions );
		void visitContainerStmt( ast::stmt::Container * stmt )override;
		void visitBreakStmt( ast::stmt::Break * stmt )override;
		void visitContinueStmt( ast::stmt::Continue * stmt )override;
		void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override;
		void visitDiscardStmt( ast::stmt::Discard * stmt )override;
		void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override;
		void visitCommentStmt( ast::stmt::Comment * stmt )override;
		void visitCompoundStmt( ast::stmt::Compound * stmt )override;
		void visitDoWhileStmt( ast::stmt::DoWhile * stmt )override;
		void visitElseIfStmt( ast::stmt::ElseIf * stmt )override;
		void visitElseStmt( ast::stmt::Else * stmt )override;
		void visitForStmt( ast::stmt::For * stmt )override;
		void visitFragmentLayout( ast::stmt::FragmentLayout * stmt )override;
		void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override;
		void visitIfStmt( ast::stmt::If * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override;
		void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override;
		void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override;
		void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override;
		void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * )override;
		void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override;
		void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override;
		void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override;
		void visitReturnStmt( ast::stmt::Return * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override;
		void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitSimpleStmt( ast::stmt::Simple * stmt )override;
		void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override;
		void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override;
		void visitSwitchStmt( ast::stmt::Switch * stmt )override;
		void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override;
		void visitWhileStmt( ast::stmt::While * stmt )override;
		void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( ast::stmt::PreprocElif * preproc )override;
		void visitPreprocElse( ast::stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override;
		void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override;
		void visitPreprocIf( ast::stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override;
		void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override;

		ValueId visitVariable( ast::var::VariablePtr var );
		void interruptBlock( Block & block
			, InstructionPtr interruptInstruction
			, bool pushBlock );
		void endBlock( Block & block
			, spv::Id nextBlockLabel );
		void endBlock( Block & block
			, spv::Id mergeBlockLabel
			, spv::Id trueBlockLabel
			, spv::Id falseBlockLabel );

	private:
		struct Control
		{
			spv::Id breakLabel;
			spv::Id continueLabel;
		};

		spirv::PreprocContext m_context;
		ShaderActions m_actions;
		Module & m_result;
		Block m_currentBlock;
		Function * m_function{ nullptr };
		std::vector< Control > m_controlBlocks;
		uint32_t m_ifStmts{ 0u };
		ValueIdList m_inputs;
		ValueIdList m_outputs;
	};
}

#endif
