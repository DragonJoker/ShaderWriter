/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/SelectEntryPoint.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"
#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	namespace selentpt
	{
		namespace helpers
		{
			static bool isEntryPointForStage( stmt::FunctionDecl const & stmt, ShaderStage stage )
			{
				switch ( stage )
				{
				case ShaderStage::eVertex: return stmt.isVertexEntryPoint();
				case ShaderStage::eTessellationControl: return stmt.isTessellationControlEntryPoint();
				case ShaderStage::eTessellationEvaluation: return stmt.isTessellationEvaluationEntryPoint();
				case ShaderStage::eGeometry: return stmt.isGeometryEntryPoint();
				case ShaderStage::eFragment: return stmt.isFragmentEntryPoint();
				case ShaderStage::eCompute: return stmt.isComputeEntryPoint();
				case ShaderStage::eTaskNV: return stmt.isTaskEntryPointNV();
				case ShaderStage::eMeshNV: return stmt.isMeshEntryPointNV();
				case ShaderStage::eTask: return stmt.isTaskEntryPoint();
				case ShaderStage::eMesh: return stmt.isMeshEntryPoint();
				case ShaderStage::eRayGeneration: return stmt.isRayGenerationEntryPoint();
				case ShaderStage::eRayAnyHit: return stmt.isRayAnyHitEntryPoint();
				case ShaderStage::eRayClosestHit: return stmt.isRayClosestHitEntryPoint();
				case ShaderStage::eRayMiss: return stmt.isRayMissEntryPoint();
				case ShaderStage::eRayIntersection: return stmt.isRayIntersectionEntryPoint();
				case ShaderStage::eCallable: return stmt.isCallableEntryPoint();
				default:
					AST_Failure( "Unsupported shader stage to check for entry point." );
					return false;
				}
			}

			static ShaderStage getStageForEntryPoint( stmt::FunctionDecl const & stmt )
			{
				if ( stmt.isVertexEntryPoint() )
				{
					return ShaderStage::eVertex;
				}
				if ( stmt.isTessellationControlEntryPoint() )
				{
					return ShaderStage::eTessellationControl;
				}
				if ( stmt.isTessellationEvaluationEntryPoint() )
				{
					return ShaderStage::eTessellationEvaluation;
				}
				if ( stmt.isGeometryEntryPoint() )
				{
					return ShaderStage::eGeometry;
				}
				if ( stmt.isFragmentEntryPoint() )
				{
					return ShaderStage::eFragment;
				}
				if ( stmt.isComputeEntryPoint() )
				{
					return ShaderStage::eCompute;
				}
				if ( stmt.isTaskEntryPointNV() )
				{
					return ShaderStage::eTaskNV;
				}
				if ( stmt.isMeshEntryPointNV() )
				{
					return ShaderStage::eMeshNV;
				}
				if ( stmt.isTaskEntryPoint() )
				{
					return ShaderStage::eTask;
				}
				if ( stmt.isMeshEntryPoint() )
				{
					return ShaderStage::eMesh;
				}
				if ( stmt.isRayGenerationEntryPoint() )
				{
					return ShaderStage::eRayGeneration;
				}
				if ( stmt.isRayAnyHitEntryPoint() )
				{
					return ShaderStage::eRayAnyHit;
				}
				if ( stmt.isRayClosestHitEntryPoint() )
				{
					return ShaderStage::eRayClosestHit;
				}
				if ( stmt.isRayMissEntryPoint() )
				{
					return ShaderStage::eRayMiss;
				}
				if ( stmt.isRayIntersectionEntryPoint() )
				{
					return ShaderStage::eRayIntersection;
				}
				if ( stmt.isCallableEntryPoint() )
				{
					return ShaderStage::eCallable;
				}

				AST_Failure( "Unsupported entry point type to check for shader stage." );
				return ShaderStage::eCompute;
			}
		}

		struct Used
		{
			explicit Used( ShaderAllocatorBlock & allocator )
				: vars{ &allocator }
				, types{ &allocator }
				, names{ &allocator }
			{
			}

			Set< var::VariablePtr > vars;
			Set< type::TypePtr > types;
			Set< std::string > names;
		};

		static void markType( type::TypePtr type
			, Used & used )
		{
			used.types.insert( type );

			switch ( type->getRawKind() )
			{
			case ast::type::Kind::eArray:
				markType( getNonArrayType( type ), used );
				break;
			case ast::type::Kind::eFunction:
			{
				auto & funcType = static_cast< type::Function const & >( *type );
				markType( funcType.getReturnType(), used );

				for ( auto & arg : funcType )
				{
					markType( arg->getType(), used );
				}
			}
			break;
			case ast::type::Kind::eStruct:
			case ast::type::Kind::eRayDesc:
				if ( auto structType = getStructType( type ) )
				{
					for ( auto & mbr : *structType )
					{
						markType( mbr.type, used );
					}
				}
				break;
			case ast::type::Kind::eRayPayload:
				markType( static_cast< ast::type::RayPayload const & >( *type ).getDataType(), used );
				break;
			case ast::type::Kind::eCallableData:
				markType( static_cast< ast::type::CallableData const & >( *type ).getDataType(), used );
				break;
			case ast::type::Kind::eHitAttribute:
				markType( static_cast< ast::type::HitAttribute const & >( *type ).getDataType(), used );
				break;
			case ast::type::Kind::ePointer:
				markType( static_cast< ast::type::Pointer const & >( *type ).getPointerType(), used );
				break;
			case ast::type::Kind::eGeometryInput:
				markType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eGeometryOutput:
				markType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTessellationInputPatch:
				markType( static_cast< ast::type::TessellationInputPatch const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTessellationOutputPatch:
				markType( static_cast< ast::type::TessellationOutputPatch const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTessellationControlInput:
				markType( static_cast< ast::type::TessellationControlInput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTessellationControlOutput:
				markType( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTessellationEvaluationInput:
				markType( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eFragmentInput:
				markType( static_cast< ast::type::FragmentInput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eComputeInput:
				markType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eMeshVertexOutput:
				markType( static_cast< ast::type::MeshVertexOutput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eMeshPrimitiveOutput:
				markType( static_cast< ast::type::MeshPrimitiveOutput const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTaskPayloadNV:
				markType( static_cast< ast::type::TaskPayloadNV const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTaskPayload:
				markType( static_cast< ast::type::TaskPayload const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTaskPayloadInNV:
				markType( static_cast< ast::type::TaskPayloadInNV const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eTaskPayloadIn:
				markType( static_cast< ast::type::TaskPayloadIn const & >( *type ).getType(), used );
				break;
			case ast::type::Kind::eVoid:
			case ast::type::Kind::eUndefined:
				break;
			default:
				break;
			}
		}

		static void markVariable( var::VariablePtr variable
			, std::map< std::string, Used > const & buffers
			, Used & used )
		{
			if ( !variable->isLocale() )
			{
				markType( variable->getType(), used );
				used.vars.insert( variable );

				if ( variable->isMember() )
				{
					auto outermost = variable->getOutermost();
					markType( outermost->getType(), used );
					used.vars.insert( outermost );
					used.names.insert( outermost->getName() );
					auto it = buffers.find( outermost->getName() );

					if ( it != buffers.end() )
					{
						for ( auto & var : it->second.vars )
						{
							markVariable( var, {}, used );
						}

						for ( auto & type : it->second.types )
						{
							markType( type, used );
						}
					}
				}
			}
		}

		static void markFunctionCall( std::string const & funcName
			, std::map< std::string, Used > const & functions
			, std::map< std::string, Used > const & buffers
			, Used & used )
		{
			auto it = functions.find( funcName );

			if ( it != functions.end() )
			{
				for ( auto & var : it->second.vars )
				{
					markVariable( var, buffers, used );
				}

				for ( auto & type : it->second.types )
				{
					markType( type, used );
				}
			}
		}

		static Used markEntryPoint( EntryPointConfig const & config
			, stmt::Container * stmt )
		{
			class ExprVisitor
				: public expr::SimpleVisitor
			{
			public:
				static void submit( Used & result
					, std::map< std::string, Used > const & functions
					, std::map< std::string, Used > const & buffers
					, expr::Expr * expr )
				{
					ExprVisitor vis{ result, functions, buffers };
					expr->accept( &vis );
				}

			private:
				ExprVisitor( Used & result
					, std::map< std::string, Used > const & functions
					, std::map< std::string, Used > const & buffers )
					: m_result{ result }
					, m_functions{ functions }
					, m_buffers{ buffers }
				{
				}

				void visitUnaryExpr( expr::Unary * expr )override
				{
					expr->getOperand()->accept( this );
				}

				void visitBinaryExpr( expr::Binary * expr )override
				{
					expr->getLHS()->accept( this );
					expr->getRHS()->accept( this );
				}

				void visitAggrInitExpr( expr::AggrInit * expr )override
				{
					if ( expr->getIdentifier() )
					{
						expr->getIdentifier()->accept( this );
					}

					for ( auto & init : expr->getInitialisers() )
					{
						init->accept( this );
					}
				}

				void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
				{
					for ( auto & init : expr->getArgList() )
					{
						init->accept( this );
					}
				}

				void visitFnCallExpr( expr::FnCall * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}

					expr->getFn()->accept( this );
					// Mark the called function data as used from the current scope
					markFunctionCall( expr->getFn()->getVariable()->getName()
						, m_functions
						, m_buffers
						, m_result );
				}

				void visitIdentifierExpr( expr::Identifier * expr )override
				{
					markVariable( expr->getVariable(), m_buffers, m_result );
				}

				void visitImageAccessCallExpr( expr::StorageImageAccessCall * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}

				void visitInitExpr( expr::Init * expr )override
				{
					if ( expr->getIdentifier() )
					{
						expr->getIdentifier()->accept( this );
					}

					expr->getInitialiser()->accept( this );
				}

				void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}

				void visitLiteralExpr( expr::Literal * expr )override
				{
				}

				void visitMbrSelectExpr( expr::MbrSelect * expr )override
				{
					expr->getOuterExpr()->accept( this );
				}

				void visitQuestionExpr( expr::Question * expr )override
				{
					expr->getCtrlExpr()->accept( this );
					expr->getTrueExpr()->accept( this );
					expr->getFalseExpr()->accept( this );
				}

				void visitStreamAppendExpr( expr::StreamAppend * expr )override
				{
					expr->getOperand()->accept( this );
				}

				void visitSwitchCaseExpr( expr::SwitchCase * expr )override
				{
				}

				void visitSwitchTestExpr( expr::SwitchTest * expr )override
				{
					expr->getValue()->accept( this );
				}

				void visitSwizzleExpr( expr::Swizzle * expr )override
				{
					expr->getOuterExpr()->accept( this );
				}

				void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}

			private:
				Used & m_result;
				std::map< std::string, Used > const & m_functions;
				std::map< std::string, Used > const & m_buffers;
			};

			class StmtVisitor
				: public stmt::SimpleVisitor
			{
			public:
				static void submit( EntryPointConfig const & config
					, Used & result
					, stmt::Container * stmt )
				{
					StmtVisitor vis{ config, result };
					stmt->accept( &vis );
				}

			private:
				StmtVisitor( EntryPointConfig const & config
					, Used & result )
					: m_config{ config }
					, m_result{ result }
					, m_current{ &m_result }
				{
				}

				void doSubmit( expr::Expr & expr )
				{
					ExprVisitor::submit( *m_current, m_functions, m_buffers, &expr );
				}

				void parseFunction( stmt::FunctionDecl * stmt )
				{
					Used function{ *m_result.vars.get_allocator().getAllocator() };
					auto save = m_current;
					m_current = &function;
					visitContainerStmt( stmt );
					m_current = save;
					m_functions.emplace( stmt->getName(), std::move( function ) );
				}

				void parseBuffer( std::string const & name
					, stmt::Container* stmt )
				{
					Used buffer{ *m_result.vars.get_allocator().getAllocator() };
					auto save = m_current;
					m_current = &buffer;
					m_isBuffer = true;
					visitContainerStmt( stmt );
					m_isBuffer = false;
					m_current = save;
					m_buffers.emplace( name, std::move( buffer ) );
				}

				void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl * stmt )override
				{
					markType( stmt->getType(), *m_current );
				}

				void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override
				{
					parseBuffer( stmt->getName(), stmt );
				}

				void visitDispatchMeshStmt( stmt::DispatchMesh * stmt )override
				{
					doSubmit( *stmt->getNumGroupsX() );
					doSubmit( *stmt->getNumGroupsY() );
					doSubmit( *stmt->getNumGroupsZ() );
				}

				void visitDoWhileStmt( stmt::DoWhile * stmt )override
				{
					doSubmit( *stmt->getCtrlExpr() );
					visitCompoundStmt( stmt );
				}

				void visitElseIfStmt( stmt::ElseIf * stmt )override
				{
					doSubmit( *stmt->getCtrlExpr() );
					visitCompoundStmt( stmt );
				}

				void visitForStmt( stmt::For * stmt )override
				{
					doSubmit( *stmt->getInitExpr() );
					doSubmit( *stmt->getCtrlExpr() );
					doSubmit( *stmt->getIncrExpr() );
					visitCompoundStmt( stmt );
				}

				void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override
				{
					parseFunction( stmt );

					if ( stmt->isEntryPoint() )
					{
						// Only pick entry point which matches given configuration
						if ( helpers::isEntryPointForStage( *stmt, m_config.stage )
							&& ( m_config.name.empty() || stmt->getName() == m_config.name ) )
						{
							markVariable( stmt->getFuncVar(), m_buffers, *m_current );
							markFunctionCall( stmt->getName(), m_functions, m_buffers, *m_current );
						}
					}
					else if ( stmt->isPatchRoutine()
						&& m_config.stage == ShaderStage::eTessellationControl )
					{
						markVariable( stmt->getFuncVar(), m_buffers, *m_current );
						markFunctionCall( stmt->getName(), m_functions, m_buffers, *m_current );
					}
				}

				void visitIfStmt( stmt::If * stmt )override
				{
					doSubmit( *stmt->getCtrlExpr() );
					visitCompoundStmt( stmt );

					for ( auto & elseIf : stmt->getElseIfList() )
					{
						elseIf->accept( this );
					}

					if ( stmt->getElse() )
					{
						stmt->getElse()->accept( this );
					}
				}

				void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override
				{
					parseBuffer( stmt->getName(), stmt );
				}

				void visitReturnStmt( stmt::Return * stmt )override
				{
					if ( stmt->getExpr() )
					{
						doSubmit( *stmt->getExpr() );
					}
				}

				void visitSimpleStmt( stmt::Simple * stmt )override
				{
					doSubmit( *stmt->getExpr() );
				}

				void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override
				{
					if ( stmt->getCaseExpr() )
					{
						doSubmit( *stmt->getCaseExpr() );
					}

					visitCompoundStmt( stmt );
				}

				void visitSwitchStmt( stmt::Switch * stmt )override
				{
					doSubmit( *stmt->getTestExpr() );
					visitCompoundStmt( stmt );
				}

				void visitVariableDeclStmt( stmt::VariableDecl * stmt )override
				{
					if ( m_isBuffer )
					{
						markVariable( stmt->getVariable(), {}, *m_current );
					}
				}

				void visitWhileStmt( stmt::While * stmt )override
				{
					doSubmit( *stmt->getCtrlExpr() );
					visitCompoundStmt( stmt );
				}

			private:
				EntryPointConfig const & m_config;
				Used & m_result;
				Used * m_current{};
				bool m_isBuffer{};
				std::map< std::string, Used > m_functions;
				std::map< std::string, Used > m_buffers;
			};
			Used result{ stmt->getStmtCache().getAllocator() };
			StmtVisitor::submit( config, result, stmt );
			return result;
		}

		static stmt::ContainerPtr selectUsedVars( stmt::StmtCache & stmtCache
			, expr::ExprCache & exprCache
			, ShaderStage stage
			, Used const & used
			, stmt::Container * stmt )
		{
			class StmtVisitor
				: public StmtCloner
			{
			public:
				static stmt::ContainerPtr submit( stmt::StmtCache & stmtCache
					, expr::ExprCache & exprCache
					, ShaderStage stage
					, Used const & used
					, stmt::Container * stmt )
				{
					auto result = stmtCache.makeContainer();
					StmtVisitor vis{ stmtCache, exprCache, stage, used, result };
					stmt->accept( &vis );
					return result;
				}

			private:
				StmtVisitor( stmt::StmtCache & stmtCache
					, expr::ExprCache & exprCache
					, ShaderStage stage
					, Used const & used
					, stmt::ContainerPtr & result )
					: StmtCloner{ stmtCache, exprCache, result }
					, m_stage{ stage }
					, m_used{ used }
				{
				}

				bool isUsed( var::VariablePtr variable )
				{
					return m_used.vars.end() != m_used.vars.find( variable );
				}

				bool isUsed( type::TypePtr type )
				{
					return m_used.types.end() != m_used.types.find( type );
				}

				bool isUsed( std::string const & name )
				{
					return m_used.names.end() != m_used.names.find( name );
				}

				void visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitAccelerationStructureDeclStmt( stmt );
					}
				}

				void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl * stmt )override
				{
					if ( isUsed( stmt->getType() ) )
					{
						StmtCloner::visitBufferReferenceDeclStmt( stmt );
					}
				}

				void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override
				{
					if ( isUsed( stmt->getName() ) )
					{
						StmtCloner::visitConstantBufferDeclStmt( stmt );
					}
				}

				void visitFragmentLayoutStmt( stmt::FragmentLayout * stmt )override
				{
					if ( m_stage == ShaderStage::eFragment )
					{
						StmtCloner::visitFragmentLayoutStmt( stmt );
					}
				}

				void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override
				{
					if ( isUsed( stmt->getFuncVar() ) )
					{
						if ( stmt->isEntryPoint() )
						{
							// Rename it as "main".
							auto save = m_current;
							auto cont = m_stmtCache.makeFunctionDecl( ast::var::makeVariable( stmt->getFuncVar()->getId()
									, stmt->getType()
									, "main"
									, stmt->getFuncVar()->getFlags() )
								, stmt->getFlags() );
							m_current = cont.get();
							visitContainerStmt( stmt );
							m_current = save;
							m_current->addStmt( std::move( cont ) );
						}
						else
						{
							StmtCloner::visitFunctionDeclStmt( stmt );
						}
					}
				}

				void visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitHitAttributeVariableDeclStmt( stmt );
					}
				}

				void visitImageDeclStmt( stmt::ImageDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitImageDeclStmt( stmt );
					}
				}

				void visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitInOutCallableDataVariableDeclStmt( stmt );
					}
				}

				void visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitInOutRayPayloadVariableDeclStmt( stmt );
					}
				}

				void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitInOutVariableDeclStmt( stmt );
					}
				}

				void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override
				{
					if ( m_stage == ShaderStage::eCompute )
					{
						StmtCloner::visitInputComputeLayoutStmt( stmt );
					}
				}

				void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override
				{
					if ( m_stage == ShaderStage::eGeometry )
					{
						StmtCloner::visitInputGeometryLayoutStmt( stmt );
					}
				}

				void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )override
				{
					if ( m_stage == ShaderStage::eTessellationEvaluation )
					{
						StmtCloner::visitInputTessellationEvaluationLayoutStmt( stmt );
					}
				}

				void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override
				{
					if ( m_stage == ShaderStage::eGeometry )
					{
						StmtCloner::visitOutputGeometryLayoutStmt( stmt );
					}
				}

				void visitOutputMeshLayoutStmt( stmt::OutputMeshLayout * stmt )override
				{
					if ( m_stage == ShaderStage::eMesh )
					{
						StmtCloner::visitOutputMeshLayoutStmt( stmt );
					}
				}

				void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override
				{
					if ( m_stage == ast::ShaderStage::eVertex
						|| m_stage == ast::ShaderStage::eTessellationControl
						|| m_stage == ast::ShaderStage::eTessellationEvaluation
						|| m_stage == ast::ShaderStage::eGeometry
						|| m_stage == ast::ShaderStage::eFragment )
					{
						StmtCloner::visitPerVertexDeclStmt( stmt );
					}
				}

				void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override
				{
					if ( isUsed( stmt->getName() ) )
					{
						StmtCloner::visitPushConstantsBufferDeclStmt( stmt );
					}
				}

				void visitCombinedImageDeclStmt( stmt::CombinedImageDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitCombinedImageDeclStmt( stmt );
					}
				}

				void visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitSampledImageDeclStmt( stmt );
					}
				}

				void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitSamplerDeclStmt( stmt );
					}
				}

				void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitShaderBufferDeclStmt( stmt );
					}
				}

				void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )override
				{
					if ( isUsed( stmt->getSsboInstance() )
						|| isUsed( stmt->getData() ) )
					{
						StmtCloner::visitShaderStructBufferDeclStmt( stmt );
					}
				}

				void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )override
				{
					if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitSpecialisationConstantDeclStmt( stmt );
					}
				}

				void visitStructureDeclStmt( stmt::StructureDecl * stmt )override
				{
					if ( isUsed( stmt->getType() ) )
					{
						StmtCloner::visitStructureDeclStmt( stmt );
					}
				}

				void visitVariableDeclStmt( stmt::VariableDecl * stmt )override
				{
					if ( stmt->getVariable()->isLocale() )
					{
						StmtCloner::visitVariableDeclStmt( stmt );
					}
					else if ( isUsed( stmt->getVariable() ) )
					{
						StmtCloner::visitVariableDeclStmt( stmt );
					}
				}

			private:
				ShaderStage m_stage;
				Used const & m_used;
			};
			return StmtVisitor::submit( stmtCache
				, exprCache
				, stage
				, used
				, stmt );
		}

		static EntryPointConfigArray listEntryPoints( stmt::Container * stmt )
		{
			EntryPointConfigArray result{ &stmt->getStmtCache().getAllocator() };

			for ( auto & st : *stmt )
			{
				if ( st->getKind() == stmt::Kind::eFunctionDecl )
				{
					auto & funcDecl = static_cast< stmt::FunctionDecl const & >( *st );

					if ( funcDecl.isEntryPoint() )
					{
						result.push_back( { helpers::getStageForEntryPoint( funcDecl ), funcDecl.getName() } );
					}
				}
			}

			return result;
		}
	}

	stmt::ContainerPtr selectEntryPoint( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, EntryPointConfig const & config
		, stmt::Container * stmt )
	{
		auto used = selentpt::markEntryPoint( config, stmt );
		return selentpt::selectUsedVars( stmtCache
			, exprCache
			, config.stage
			, used
			, stmt );
	}

	EntryPointConfigArray listEntryPoints( stmt::Container * stmt )
	{
		return selentpt::listEntryPoints( stmt );
	}
}
