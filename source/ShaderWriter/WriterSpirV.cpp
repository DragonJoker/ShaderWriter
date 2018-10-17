/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterSpirV.hpp"

#include "ShaderWriter/Shader.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>
#include <ASTGenerator/Stmt/StmtVisitor.hpp>

namespace sdw
{
	namespace spirv
	{
		class StmtVisitor
			: public stmt::Visitor
		{
		protected:
			StmtVisitor( std::vector< uint32_t > & result );

		public:
			static std::vector< uint32_t > submit( stmt::Stmt * stmt );

		private:
			void doAppendLineEnd();

			void visitCompoundStmt( stmt::Compound * stmt )override;
			void visitContainerStmt( stmt::Container * stmt )override;
			void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override;
			void visitDiscardStmt( stmt::Discard * stmt )override;
			void visitDoWhileStmt( stmt::DoWhile * stmt )override;
			void visitElseIfStmt( stmt::ElseIf * stmt )override;
			void visitElseStmt( stmt::Else * stmt )override;
			void visitEmitPrimitiveStmt( stmt::EmitPrimitive * stmt )override;
			void visitEmitVertexStmt( stmt::EmitVertex * stmt )override;
			void visitForStmt( stmt::For * stmt )override;
			void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override;
			void visitIfStmt( stmt::If * stmt )override;
			void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override;
			void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override;
			void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override;
			void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override;
			void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override;
			void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override;
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
			std::string m_indent;
			bool m_appendSemiColon{ false };
			bool m_appendLineEnd{ false };
			std::vector< uint32_t > & m_result;
		};
	}

	std::vector< uint32_t > writeSpirV( Shader & shader )
	{
		return spirv::StmtVisitor::submit( shader.getStatements() );
	}
}
