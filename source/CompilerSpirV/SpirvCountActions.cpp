/*
See LICENSE file in root folder
*/
#include "SpirvCountActions.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#pragma warning( disable: 4365 )
#include <sstream>

namespace spirv
{
	namespace
	{
		class ExprActionsCounter
			: public ast::expr::SimpleVisitor
		{
		public:
			static void submit( ast::expr::Expr * expr
				, FunctionActions & actions
				, bool isMember = false )
			{
				ExprActionsCounter vis{ actions, isMember };
				expr->accept( &vis );
			}

		private:
			ExprActionsCounter( FunctionActions & result
				, bool isMember )
				: m_result{ result }
				, m_isMember{ isMember }
			{
			}

			void submit( ast::expr::Expr * expr
				, bool isMember = false )
			{
				if ( expr )
				{
					submit( expr, m_result, isMember );
				}
			}

			void setIdentifier( ast::expr::Expr * expr )
			{
				if ( expr )
				{
					auto ident = ast::findIdentifier( expr );

					if ( ident )
					{
						auto it = m_result.emplace( ident->getVariable()->getEntityName(), VarActions{} ).first;
						it->second.sets++;
					}
				}
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				submit( expr->getOperand() );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				submit( expr->getLHS() );
				submit( expr->getRHS() );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				submit( expr->getLHS(), true );
				submit( expr->getRHS() );
			}

			void visitAssignExpr( ast::expr::Assign * expr )override
			{
				setIdentifier( expr->getLHS() );
				submit( expr->getRHS() );
			}

			void visitAggrInitExpr( ast::expr::AggrInit * expr )override
			{
				setIdentifier( expr->getIdentifier() );

				for ( auto & init : expr->getInitialisers() )
				{
					submit( init.get() );
				}
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( init.get() );
				}
			}

			void visitFnCallExpr( ast::expr::FnCall * expr )override
			{
				auto & funcType = static_cast< ast::type::Function const & >( *expr->getFn()->getType() );
				auto itParam = funcType.begin();

				for ( auto & init : expr->getArgList() )
				{
					auto & param = *itParam;

					if ( param->isOutputParam() )
					{
						setIdentifier( init.get() );
					}

					if ( param->isInputParam() )
					{
						submit( init.get() );
					}

					++itParam;
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				auto it = m_result.emplace( expr->getVariable()->getEntityName(), VarActions{} ).first;

				if ( m_isMember )
				{
					it->second.usesThroughMember++;
				}
				else
				{
					it->second.uses++;
				}
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( init.get() );
				}
			}

			void visitInitExpr( ast::expr::Init * expr )override
			{
				setIdentifier( expr->getIdentifier() );
				submit( expr->getInitialiser() );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( init.get() );
				}
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				submit( expr->getOuterExpr(), true );
			}

			void visitQuestionExpr( ast::expr::Question * expr )override
			{
				submit( expr->getCtrlExpr() );
				submit( expr->getTrueExpr() );
				submit( expr->getFalseExpr() );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
			{
				submit( expr->getOperand() );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
			{
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
			{
				submit( expr->getValue() );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				submit( expr->getOuterExpr() );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( init.get() );
				}
			}

		private:
			FunctionActions & m_result;
			bool m_isMember;
		};

		class StmtActionsCounter
			: public ast::stmt::Visitor
		{
		public:
			static ShaderActions submit( ast::stmt::Stmt * stmt )
			{
				ShaderActions result;
				StmtActionsCounter vis{ result };
				stmt->accept( &vis );
				return result;
			}

		private:
			StmtActionsCounter( ShaderActions & result )
				: ast::stmt::Visitor{}
				, m_result{ result }
			{
			}

			void submit( ast::expr::Expr * expr )
			{
				if ( expr && m_currentActions )
				{
					ExprActionsCounter::submit( expr, *m_currentActions );
				}
			}

			void visitContainerStmt( ast::stmt::Container * cont )override
			{
				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}
			}

			void visitCompoundStmt( ast::stmt::Compound * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile * stmt )override
			{
				visitContainerStmt( stmt );
				submit( stmt->getCtrlExpr() );
			}

			void visitElseIfStmt( ast::stmt::ElseIf * stmt )override
			{
				submit( stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
			}

			void visitElseStmt( ast::stmt::Else * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitForStmt( ast::stmt::For * stmt )override
			{
				submit( stmt->getInitExpr() );
				submit( stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
				submit( stmt->getIncrExpr() );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override
			{
				assert( m_currentActions == nullptr );
				FunctionActions actions;
				m_currentActions = &actions;
				visitContainerStmt( stmt );
				m_currentActions = nullptr;
				m_result.emplace( stmt->getName(), std::move( actions ) );
			}

			void visitIfStmt( ast::stmt::If * stmt )override
			{
				submit( stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
			}

			void visitReturnStmt( ast::stmt::Return * stmt )override
			{
				submit( stmt->getExpr() );
			}

			void visitSimpleStmt( ast::stmt::Simple * stmt )override
			{
				submit( stmt->getExpr() );
			}

			void visitSwitchStmt( ast::stmt::Switch * stmt )override
			{
				submit( stmt->getTestExpr() );
				visitContainerStmt( stmt );
			}

			void visitBreakStmt( ast::stmt::Break * stmt )override
			{
			}

			void visitContinueStmt( ast::stmt::Continue * stmt )override
			{
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override
			{
			}

			void visitDiscardStmt( ast::stmt::Discard * stmt )override
			{
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override
			{
			}

			void visitCommentStmt( ast::stmt::Comment * stmt )override
			{
			}

			void visitFragmentLayout( ast::stmt::FragmentLayout * stmt )override
			{
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override
			{
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override
			{
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override
			{
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override
			{
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override
			{
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )override
			{
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override
			{
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override
			{
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override
			{
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override
			{
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override
			{
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override
			{
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override
			{
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override
			{
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override
			{
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override
			{
			}

			void visitWhileStmt( ast::stmt::While * stmt )override
			{
				AST_Failure( "Unexpected While statement." );
			}

			void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override
			{
				AST_Failure( "Unexpected PreprocDefine statement." );
			}

			void visitPreprocElif( ast::stmt::PreprocElif * preproc )override
			{
				AST_Failure( "Unexpected PreprocElif statement." );
			}

			void visitPreprocElse( ast::stmt::PreprocElse * preproc )override
			{
				AST_Failure( "Unexpected PreprocElse statement." );
			}

			void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override
			{
				AST_Failure( "Unexpected PreprocEndif statement." );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override
			{
			}

			void visitPreprocIf( ast::stmt::PreprocIf * preproc )override
			{
				AST_Failure( "Unexpected PreprocIf statement." );
			}

			void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override
			{
				AST_Failure( "Unexpected PreprocIfDef statement." );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override
			{
			}

		private:
			ShaderActions & m_result;
			FunctionActions * m_currentActions{};
		};
	}

	ShaderActions listActions( ast::stmt::Container * container )
	{
		return StmtActionsCounter::submit( container );
	}
}
