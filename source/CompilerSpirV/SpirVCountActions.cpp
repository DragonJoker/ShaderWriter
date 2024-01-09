/*
See LICENSE file in root folder
*/
#include "SpirVCountActions.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

namespace spirv
{
	namespace count
	{
		class ExprActionsCounter
			: public ast::expr::SimpleVisitor
		{
		public:
			static void submit( ast::expr::Expr const & expr
				, FunctionActions & actions
				, bool isMember = false )
			{
				ExprActionsCounter vis{ actions, isMember };
				expr.accept( &vis );
			}

		private:
			explicit ExprActionsCounter( FunctionActions & result
				, bool isMember )
				: m_result{ result }
				, m_isMember{ isMember }
			{
			}

			void submit( ast::expr::Expr const & expr
				, bool isMember = false )
			{
				submit( expr, m_result, isMember );
			}

			void setIdentifier( ast::expr::Expr const & expr )
			{
				if ( auto ident = ast::findIdentifier( expr ) )
				{
					auto it = m_result.try_emplace( ident->getVariable()->getEntityName() ).first;
					it->second.sets++;
				}
			}

			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				submit( *expr->getOperand() );
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				submit( *expr->getLHS() );
				submit( *expr->getRHS() );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
			{
				submit( *expr->getLHS(), true );
				submit( *expr->getRHS() );
			}

			void visitAssignExpr( ast::expr::Assign const * expr )override
			{
				setIdentifier( *expr->getLHS() );
				submit( *expr->getRHS() );
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					setIdentifier( expr->getIdentifier() );
				}

				for ( auto & init : expr->getInitialisers() )
				{
					submit( *init );
				}
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( *init );
				}
			}

			void visitFnCallExpr( ast::expr::FnCall const * expr )override
			{
				auto & funcType = static_cast< ast::type::Function const & >( *expr->getFn()->getType() );
				auto itParam = funcType.begin();

				for ( auto & init : expr->getArgList() )
				{
					auto & param = *itParam;

					if ( param->isOutputParam() )
					{
						setIdentifier( *init );
					}

					if ( param->isInputParam() )
					{
						submit( *init );
					}

					++itParam;
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				auto it = m_result.try_emplace( expr->getVariable()->getEntityName() ).first;

				if ( m_isMember )
				{
					it->second.usesThroughMember++;
				}
				else
				{
					it->second.uses++;
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( *init );
				}
			}

			void visitInitExpr( ast::expr::Init const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					setIdentifier( expr->getIdentifier() );
				}

				submit( *expr->getInitialiser() );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( *init );
				}
			}

			void visitLiteralExpr( ast::expr::Literal const * expr )override
			{
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				submit( *expr->getOuterExpr(), true );
			}

			void visitQuestionExpr( ast::expr::Question const * expr )override
			{
				submit( *expr->getCtrlExpr() );
				submit( *expr->getTrueExpr() );
				submit( *expr->getFalseExpr() );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
			{
				submit( *expr->getOperand() );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
			{
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
			{
				submit( *expr->getValue() );
			}

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				submit( *expr->getOuterExpr() );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
			{
				for ( auto & init : expr->getArgList() )
				{
					submit( *init );
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
			static ShaderActions submit( ast::stmt::Stmt const & stmt )
			{
				ShaderActions result{ &stmt.getStmtCache().getAllocator() };
				StmtActionsCounter vis{ result };
				stmt.accept( &vis );
				return result;
			}

		private:
			explicit StmtActionsCounter( ShaderActions & result )
				: m_result{ result }
			{
			}

			void submit( ast::expr::Expr const & expr )
			{
				if ( m_currentActions )
				{
					ExprActionsCounter::submit( expr, *m_currentActions );
				}
			}

			void visitContainerStmt( ast::stmt::Container const * cont )override
			{
				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}
			}

			void visitCompoundStmt( ast::stmt::Compound const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile const * stmt )override
			{
				visitContainerStmt( stmt );
				submit( *stmt->getCtrlExpr() );
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				submit( *stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitForStmt( ast::stmt::For const * stmt )override
			{
				submit( *stmt->getInitExpr() );
				submit( *stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
				submit( *stmt->getIncrExpr() );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
			{
				assert( m_currentActions == nullptr );
				FunctionActions actions{ &stmt->getStmtCache().getAllocator() };
				m_currentActions = &actions;
				visitContainerStmt( stmt );
				m_currentActions = nullptr;
				m_result.try_emplace( stmt->getName(), std::move( actions ) );
			}

			void visitIfStmt( ast::stmt::If const * stmt )override
			{
				submit( *stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
			}

			void visitReturnStmt( ast::stmt::Return const * stmt )override
			{
				if ( auto expr = stmt->getExpr() )
				{
					submit( *expr );
				}
			}

			void visitSimpleStmt( ast::stmt::Simple const * stmt )override
			{
				submit( *stmt->getExpr() );
			}

			void visitSwitchStmt( ast::stmt::Switch const * stmt )override
			{
				submit( *stmt->getTestExpr() );
				visitContainerStmt( stmt );
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh const * stmt )override
			{
				submit( *stmt->getNumGroupsX() );
				submit( *stmt->getNumGroupsY() );
				submit( *stmt->getNumGroupsZ() );

				if ( stmt->getPayload() )
				{
					submit( *stmt->getPayload() );
				}
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl const * stmt )override
			{
			}

			void visitBreakStmt( ast::stmt::Break const * stmt )override
			{
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl const * stmt )override
			{
			}

			void visitContinueStmt( ast::stmt::Continue const * stmt )override
			{
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl const * stmt )override
			{
			}

			void visitDemoteStmt( ast::stmt::Demote const * stmt )override
			{
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation const * stmt )override
			{
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl const * stmt )override
			{
			}

			void visitCommentStmt( ast::stmt::Comment const * stmt )override
			{
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout const * stmt )override
			{
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl const * stmt )override
			{
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl const * stmt )override
			{
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection const * stmt )override
			{
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
			{
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
			{
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl const * stmt )override
			{
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout const * stmt )override
			{
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout const * stmt )override
			{
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout const * stmt )override
			{
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout const * stmt )override
			{
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout const * stmt )override
			{
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout const * stmt )override
			{
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl const * stmt )override
			{
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl const * stmt )override
			{
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
			{
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl const * stmt )override
			{
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase const * stmt )override
			{
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay const * stmt )override
			{
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
			}

			void visitWhileStmt( ast::stmt::While const * stmt )override
			{
				AST_Failure( "Unexpected While statement." );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension const * preproc )override
			{
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
			}

		private:
			ShaderActions & m_result;
			FunctionActions * m_currentActions{};
		};
	}

	ShaderActions listActions( ast::stmt::Container const & container )
	{
		return count::StmtActionsCounter::submit( container );
	}
}
