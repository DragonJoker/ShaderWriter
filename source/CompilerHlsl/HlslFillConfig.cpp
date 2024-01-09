/*
See LICENSE file in root folder
*/
#include "HlslFillConfig.hpp"

#include "HlslCombinedImageAccessConfig.hpp"
#include "HlslCombinedImageAccessFunctions.hpp"
#include "HlslHelpers.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslIntrinsicFunctions.hpp"
#include "HlslShader.hpp"
#include "HlslStorageImageAccessConfig.hpp"
#include "HlslReplaceVariables.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

namespace hlsl
{
	namespace config
	{
		namespace helpers
		{
			static void checkBuiltin( ast::Builtin builtin
				, IntrinsicsConfig & config )
			{
				switch ( builtin )
				{
				case ast::Builtin::eSampleID:
					config.requiresSampledIndex = true;
					break;
				case ast::Builtin::eNumSubgroups:
				case ast::Builtin::eSubgroupID:
				case ast::Builtin::eSubgroupSize:
				case ast::Builtin::eSubgroupLocalInvocationID:
				case ast::Builtin::eSubgroupEqMask:
				case ast::Builtin::eSubgroupGeMask:
				case ast::Builtin::eSubgroupGtMask:
				case ast::Builtin::eSubgroupLeMask:
				case ast::Builtin::eSubgroupLtMask:
					config.requiresWaveOps = true;
					break;
				default:
					break;
				}
			}

			static void checkBuiltin( ast::var::Variable const & var
				, IntrinsicsConfig & config )
			{
				if ( var.isBuiltin() )
				{
					checkBuiltin( var.getBuiltin(), config );
				}
			}

			static void checkBuiltin( ast::type::Struct const & type
				, uint32_t index
				, IntrinsicsConfig & config )
			{
				auto mbr = *std::next( type.begin(), ptrdiff_t( index ) );

				if ( mbr.builtin != ast::Builtin::eNone )
				{
					checkBuiltin( mbr.builtin, config );
				}
			}

			static bool isOutput( ast::stmt::PerVertexDecl::Source source )
			{
				return source == ast::stmt::PerVertexDecl::Source::eGeometryOutput
					|| source == ast::stmt::PerVertexDecl::Source::eTessellationControlOutput
					|| source == ast::stmt::PerVertexDecl::Source::eTessellationEvaluationOutput
					|| source == ast::stmt::PerVertexDecl::Source::eVertexOutput;
			}
		}

		class ExprConfigFiller
			: public ast::expr::SimpleVisitor
		{
		public:
			static void submit( ast::expr::Expr const & expr
				, AdaptationData & adaptationData
				, IntrinsicsConfig & config )
			{
				ExprConfigFiller vis{ adaptationData, config };
				expr.accept( &vis );
			}

		private:
			ExprConfigFiller( AdaptationData & adaptationData
				, IntrinsicsConfig & config )
				: m_adaptationData{ adaptationData }
				, m_config{ config }
			{
			}


			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getOperand()->accept( this );
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getLHS()->accept( this );
				expr->getRHS()->accept( this );
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
			{
				checkType( expr->getType(), m_config );

				if ( expr->hasIdentifier() )
				{
					expr->getIdentifier().accept( this );
				}

				for ( auto & init : expr->getInitialisers() )
				{
					init->accept( this );
				}
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
			{
				checkType( expr->getType(), m_config );

				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				checkType( expr->getType(), m_config );
				helpers::checkBuiltin( *expr->getOuterType(), expr->getMemberIndex(), m_config );
				expr->getOuterExpr()->accept( this );

				if ( isRayTraceStage( m_adaptationData.shader->getType() ) )
				{
					return;
				}

				if ( expr->isBuiltin() )
				{
					m_adaptationData.addMbrBuiltin( *expr->getOuterExpr()
						, expr->getMemberIndex()
						, *expr
						, 0u );
				}
				else if ( !expr->isPerTaskNV()
					&& !expr->isPerTask()
					&& ( expr->isShaderInput() || expr->isShaderOutput() ) )
				{
					if ( auto ident = ast::findIdentifier( *expr );
						ident && ( ident->getVariable()->isPerTaskNV() || ident->getVariable()->isPerTask() ) )
					{
						return;
					}

					auto type = expr->getOuterType();
					auto mbr = type->getMember( expr->getMemberIndex() );

					if ( expr->isShaderInput() )
					{
						m_adaptationData.addPendingMbrInput( *expr->getOuterExpr()
							, expr->getMemberIndex()
							, *expr
							, mbr.location );
					}
					else
					{
						m_adaptationData.addPendingMbrOutput( *expr->getOuterExpr()
							, expr->getMemberIndex()
							, *expr
							, mbr.location );
					}
				}
			}

			void visitFnCallExpr( ast::expr::FnCall const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getFn()->accept( this );

				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
			{
				checkType( expr->getType(), m_config );
				getHlslConfig( expr->getIntrinsic(), m_config );

				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier
					|| expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
				{
					ast::type::Scope memory;
					bool isControlBarrier = ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );

					if ( isControlBarrier )
					{
						if ( expr->getArgList().size() < 3u )
						{
							throw ast::Exception{ "Wrong number of parameters for a control barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[1] ) );
					}
					else
					{
						if ( expr->getArgList().size() < 2u )
						{
							throw ast::Exception{ "Wrong number of parameters for a memory barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[0] ) );
					}

					if ( memory == ast::type::Scope::eSubgroup )
					{
						m_config.requiresWaveOps = true;
					}

					if ( isControlBarrier )
					{
						m_config.requiresControlBarrier = true;
					}
					else
					{
						m_config.requiresMemoryBarrier = true;
					}
				}
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
			{
				checkType( expr->getType(), m_config );
				getHlslConfig( expr->getCombinedImageAccess(), m_config );

				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
			{
				checkType( expr->getType(), m_config );
				getHlslConfig( expr->getImageAccess(), m_config );

				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				helpers::checkBuiltin( *expr->getVariable(), m_config );
				checkType( expr->getType(), m_config );
			}

			void visitInitExpr( ast::expr::Init const * expr )override
			{
				checkType( expr->getType(), m_config );

				if ( expr->hasIdentifier() )
				{
					expr->getIdentifier().accept( this );
				}

				expr->getInitialiser()->accept( this );
			}

			void visitLiteralExpr( ast::expr::Literal const * expr )override
			{
				checkType( expr->getType(), m_config );
			}

			void visitQuestionExpr( ast::expr::Question const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getCtrlExpr()->accept( this );
				expr->getTrueExpr()->accept( this );
				expr->getFalseExpr()->accept( this );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getOperand()->accept( this );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getLabel()->accept( this );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getValue()->accept( this );
			}

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				checkType( expr->getType(), m_config );
				expr->getOuterExpr()->accept( this );
			}

		private:
			AdaptationData & m_adaptationData;
			IntrinsicsConfig & m_config;
		};

		class StmtConfigFiller
			: public ast::stmt::Visitor
		{
		public:
			static IntrinsicsConfig submit( HlslShader & shader
				, AdaptationData & adaptationData
				, ast::stmt::Container const & container )
			{
				IntrinsicsConfig result{};
				StmtConfigFiller vis{ shader, adaptationData, result };
				container.accept( &vis );
				return result;
			}


		private:
			StmtConfigFiller( HlslShader & shader
				, AdaptationData & adaptationData
				, IntrinsicsConfig & result )
				: m_shader{ shader }
				, m_adaptationData{ adaptationData }
				, m_result{ result }
			{
			}

			void doSubmit( ast::expr::Expr const & expr )
			{
				ExprConfigFiller::submit( expr, m_adaptationData, m_result );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitContainerStmt( ast::stmt::Container const * cont )override
			{
				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitCompoundStmt( ast::stmt::Compound const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile const * stmt )override
			{
				doSubmit( *stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				doSubmit( *stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitForStmt( ast::stmt::For const * stmt )override
			{
				doSubmit( *stmt->getInitExpr() );
				doSubmit( *stmt->getCtrlExpr() );
				doSubmit( *stmt->getIncrExpr() );
				visitContainerStmt( stmt );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
			{
				if ( stmt->getFlags()
					&& !isRayTraceStage( m_shader.getType() ) )
				{
					if ( !stmt->isEntryPoint() )
					{
						m_adaptationData.addEntryPoint( *stmt );
					}

					m_adaptationData.updateCurrentEntryPoint( stmt );
					m_adaptationData.initialiseEntryPoint( *stmt );
				}

				visitContainerStmt( stmt );

				m_adaptationData.updateCurrentEntryPoint( nullptr );
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl const * stmt )override
			{
				throw ast::Exception{ "ast::stmt::BufferReferenceDecl are not supported in HLSL" };
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitIfStmt( ast::stmt::If const * stmt )override
			{
				doSubmit( *stmt->getCtrlExpr() );
				visitContainerStmt( stmt );

				for ( auto & elseIf : stmt->getElseIfList() )
				{
					elseIf->accept( this );
				}

				if ( stmt->getElse() )
				{
					stmt->getElse()->accept( this );
				}
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl const * stmt )override
			{
				m_result.requiresUAV = true;
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );

				auto var = stmt->getVariable();

				if ( var->isShaderInput() )
				{
					m_adaptationData.addInputVar( var
						, stmt->getLocation() );
				}

				if ( var->isShaderOutput() )
				{
					m_adaptationData.addOutputVar( var
						, stmt->getLocation() );
				}
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl const * stmt )override
			{
				auto index = 0u;
				auto type = getNonArrayType( stmt->getType() );
				auto structType = getStructType( type );
				assert( structType );

				for ( auto & member : *structType )
				{
					auto name = ast::getName( member.builtin );
					auto var = ( m_shader.hasGlobalVariable( name )
						? m_shader.getGlobalVariable( name )
						: m_shader.registerBuiltin( member.builtin, member.type, 0u ) );

					if ( structType->isShaderOutput() )
					{
						m_adaptationData.addPendingOutput( var, index );
					}
					else
					{
						m_adaptationData.addPendingInput( var, index );
					}

					++index;
				}
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl const * stmt )override
			{
				auto index = 0u;
				auto type = getNonArrayType( stmt->getType() );
				assert( type->getKind() == ast::type::Kind::eStruct );

				for ( auto & member : static_cast< ast::type::Struct const & >( *type ) )
				{
					auto name = ast::getName( member.builtin );
					auto var = ( m_shader.hasGlobalVariable( name )
						? m_shader.getGlobalVariable( name )
						: m_shader.registerBuiltin( member.builtin, member.type, 0u ) );

					if ( helpers::isOutput( stmt->getSource() ) )
					{
						m_adaptationData.addPendingOutput( var, index );
					}
					else
					{
						m_adaptationData.addPendingInput( var, index );
					}

					++index;
				}
			}

			void visitReturnStmt( ast::stmt::Return const * stmt )override
			{
				if ( auto expr = stmt->getExpr() )
				{
					doSubmit( *expr );
				}
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
				m_result.requiresUAV = true;
				visitContainerStmt( stmt );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
				m_result.requiresUAV = true;

				for ( auto & type : static_cast< ast::type::Struct const & >( *stmt->getSsboInstance()->getType() ) )
				{
					checkType( type.type, m_result );
				}
			}

			void visitSimpleStmt( ast::stmt::Simple const * stmt )override
			{
				doSubmit( *stmt->getExpr() );
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
				for ( auto & type : *stmt->getType() )
				{
					checkType( type.type, m_result );
				}
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitSwitchStmt( ast::stmt::Switch const * stmt )override
			{
				doSubmit( *stmt->getTestExpr()->getValue() );
				visitContainerStmt( stmt );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitWhileStmt( ast::stmt::While const * stmt )override
			{
				doSubmit( *stmt->getCtrlExpr() );
				visitContainerStmt( stmt );
			}

			void visitBreakStmt( ast::stmt::Break const * stmt )override
			{
			}

			void visitContinueStmt( ast::stmt::Continue const * stmt )override
			{
			}

			void visitDemoteStmt( ast::stmt::Demote const * stmt )override
			{
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh const * stmt )override
			{
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation const * stmt )override
			{
			}

			void visitCommentStmt( ast::stmt::Comment const * stmt )override
			{
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout const * stmt )override
			{
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl const * stmt )override
			{
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection const * stmt )override
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

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl const * stmt )override
			{
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
			{
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl const * stmt )override
			{
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay const * stmt )override
			{
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension const * preproc )override
			{
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
			}

		private:
			HlslShader & m_shader;
			AdaptationData & m_adaptationData;
			IntrinsicsConfig & m_result;
		};
	}

	IntrinsicsConfig fillConfig( HlslShader & shader
		, AdaptationData & adaptationData
		, ast::stmt::Container const & container )
	{
		return config::StmtConfigFiller::submit( shader, adaptationData, container );
	}
}
