/*
See LICENSE file in root folder
*/
#include "SpirVAdaptStatements.hpp"

#include "SpirVExprAdapter.hpp"
#include "SpirVEvaluateExpr.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/CloneStmt.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>

#include <unordered_set>

#pragma warning( disable: 4706 )

namespace spirv
{
	namespace adapt
	{
		class StmtAdapter
			: public ast::StmtCloner
		{
		public:
			static ast::stmt::ContainerPtr submit( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::stmt::Container * container
				, AdaptationData & adaptationData )
			{
				auto result = stmtCache.makeContainer();
				StmtAdapter vis{ stmtCache, exprCache, typesCache, result, adaptationData };
				container->accept( &vis );
				return result;
			}

		private:
			StmtAdapter( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::stmt::ContainerPtr & result
				, AdaptationData & adaptationData )
				: StmtCloner{ stmtCache, exprCache, result }
				, m_typesCache{ typesCache }
				, m_adaptationData{ adaptationData }
				, m_declaredStructs{ &stmtCache.getAllocator() }
				, m_pending{ &stmtCache.getAllocator() }
			{
				auto cont = m_stmtCache.makeContainer();
				m_ioDeclarations = cont.get();
				m_current->addStmt( std::move( cont ) );
			}

			ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override
			{
				return ExprAdapter::submit( m_exprCache, m_typesCache, expr, m_current, m_ioDeclarations, m_adaptationData );
			}

			void visitElseIfStmt( ast::stmt::ElseIf * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else * stmt )override
			{
				AST_Failure( "Unexpected Else statement." );
			}

			void visitIfStmt( ast::stmt::If * stmt )override
			{
				TraceFunc;
				assert( stmt->getElseIfList().empty() && "ElseIf list is supposed to have been converted." );
				auto save = m_current;
				auto cont = m_stmtCache.makeIf( doSubmit( stmt->getCtrlExpr() ) );
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;

				auto currentIf = cont.get();
				m_current->addStmt( std::move( cont ) );

				if ( stmt->getElse() )
				{
					auto elseStmt = currentIf->createElse();
					m_current = elseStmt;
					visitContainerStmt( stmt->getElse() );
					m_current = save;
				}
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override
			{
				TraceFunc;
				if ( stmt->getFlags() )
				{
					if ( stmt->isEntryPoint() )
					{
						doProcessEntryPoint( stmt );
					}
					else if ( stmt->isPatchRoutine() )
					{
						doProcessPatchRoutine( stmt );
					}
				}
				else
				{
					ast::StmtCloner::visitFunctionDeclStmt( stmt );
				}
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )override
			{
				TraceFunc;
				m_ioDeclarations->addStmt( m_stmtCache.makeHitAttributeVariableDecl( stmt->getVariable() ) );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )override
			{
				TraceFunc;
				m_ioDeclarations->addStmt( m_stmtCache.makeInOutCallableDataVariableDecl( stmt->getVariable()
					, stmt->getLocation() ) );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )override
			{
				TraceFunc;
				m_ioDeclarations->addStmt( m_stmtCache.makeInOutRayPayloadVariableDecl( stmt->getVariable()
					, stmt->getLocation() ) );
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override
			{
				TraceFunc;
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override
			{
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::ComputeInput const & compType )
			{
				TraceFunc;
				auto type = compType.getType();
				m_current->addStmt( m_stmtCache.makeInputComputeLayout( type
					, compType.getLocalSizeX()
					, compType.getLocalSizeY()
					, compType.getLocalSizeZ() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::FragmentInput const & fragType )
			{
				TraceFunc;
				auto type = fragType.getType();
				m_current->addStmt( m_stmtCache.makeFragmentLayout( type
					, fragType.getOrigin()
					, fragType.getCenter() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::GeometryOutput const & geomType )
			{
				TraceFunc;
				auto type = geomType.getType();
				m_current->addStmt( m_stmtCache.makeOutputGeometryLayout( type
					, geomType.getLayout()
					, geomType.getCount() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::GeometryInput const & geomType )
			{
				TraceFunc;
				auto type = geomType.getType();
				m_current->addStmt( m_stmtCache.makeInputGeometryLayout( type
					, geomType.getLayout() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationControlOutput const & tessType
				, bool isEntryPoint )
			{
				TraceFunc;
				auto type = tessType.getType();
				m_current->addStmt( m_stmtCache.makeOutputTessellationControlLayout( type
					, tessType.getDomain()
					, tessType.getPartitioning()
					, tessType.getTopology()
					, tessType.getOrder()
					, tessType.getOutputVertices() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationControlInput const & geomType
				, bool isEntryPoint )
			{
				TraceFunc;
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationEvaluationInput const & tessType )
			{
				TraceFunc;
				m_current->addStmt( m_stmtCache.makeInputTessellationEvaluationLayout( tessType.getType()
					, tessType.getDomain()
					, tessType.getPartitioning()
					, tessType.getPrimitiveOrdering() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::MeshVertexOutput const & meshType )
			{
				TraceFunc;
				m_maxVertices = meshType.getMaxVertices();

				if ( m_maxPrimitives )
				{
					m_current->addStmt( m_stmtCache.makeOutputMeshLayout( meshType.getType()
						, m_topology
						, m_maxVertices
						, m_maxPrimitives ) );
				}
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::MeshPrimitiveOutput const & meshType )
			{
				TraceFunc;
				m_maxPrimitives = meshType.getMaxPrimitives();
				m_topology = meshType.getTopology();

				if ( m_maxVertices )
				{
					m_current->addStmt( m_stmtCache.makeOutputMeshLayout( meshType.getType()
						, meshType.getTopology()
						, m_maxVertices
						, m_maxPrimitives ) );
				}
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TaskPayloadNV const & taskType )
			{
				TraceFunc;
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TaskPayload const & taskType )
			{
				TraceFunc;
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TaskPayloadInNV const & taskType )
			{
				TraceFunc;
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TaskPayloadIn const & taskType )
			{
				TraceFunc;
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationInputPatch const & patchType )
			{
				TraceFunc;
				var = m_adaptationData.config.getInputPatch( var );

				if ( !getStructType( var->getType() )->empty() )
				{
					m_current->addStmt( m_stmtCache.makeInOutVariableDecl( var, patchType.getLocation() ) );
				}
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationOutputPatch const & patchType
				, bool isEntryPoint )
			{
				TraceFunc;
				var = m_adaptationData.config.getOutputPatch( var );

				if ( !getStructType( var->getType() )->empty() )
				{
					m_current->addStmt( m_stmtCache.makeInOutVariableDecl( var, patchType.getLocation() ) );
				}
			}

			void doProcessEntryPoint( ast::stmt::FunctionDecl * stmt )
			{
				TraceFunc;
				auto & typesCache = stmt->getType()->getTypesCache();
				auto funcType = typesCache.getFunction( typesCache.getVoid(), {} );
				doProcessInOut( stmt->getType(), true );
				auto save = m_current;
				auto funcVar = stmt->getFuncVar();
				funcVar = ast::var::makeVariable( funcVar->getId()
					, funcType
					, stmt->getName()
					, funcVar->getFlags() );
				m_adaptationData.funcVarReplacements.emplace( funcVar->getId(), funcVar );
				auto cont = m_stmtCache.makeFunctionDecl( funcVar, stmt->getFlags() );
				m_current = cont.get();
				visitContainerStmt( stmt );

				for ( auto & pending : m_pending )
				{
					doProcessInOut( pending.second.funcType
						, false );
					visitContainerStmt( pending.second.statements.get() );
				}

				m_current = save;
				m_current->addStmt( std::move( cont ) );
			}

			void doProcessPatchRoutine( ast::stmt::FunctionDecl * stmt )
			{
				TraceFunc;
				auto save = m_current;
				auto cont = m_stmtCache.makeContainer();
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;
				m_pending.emplace( stmt->getName()
					, PendingFunction{ stmt->getType(), std::move( cont ) } );
			}

			void doProcessInOut( ast::type::FunctionPtr funcType
				, bool isEntryPoint )
			{
				TraceFunc;
				for ( auto & param : *funcType )
				{
					auto type = param->getType();

					switch ( type->getKind() )
					{
					case ast::type::Kind::eFragmentInput:
						doProcess( param, static_cast< ast::type::FragmentInput const & >( *type ) );
						break;
					case ast::type::Kind::eGeometryOutput:
						doProcess( param, static_cast< ast::type::GeometryOutput const & >( *type ) );
						break;
					case ast::type::Kind::eGeometryInput:
						doProcess( param, static_cast< ast::type::GeometryInput const & >( *type ) );
						break;
					case ast::type::Kind::eTessellationInputPatch:
						doProcess( param, static_cast< ast::type::TessellationInputPatch const & >( *type ) );
						break;
					case ast::type::Kind::eTessellationControlInput:
						doProcess( param, static_cast< ast::type::TessellationControlInput const & >( *type ), isEntryPoint );
						break;
					case ast::type::Kind::eTessellationEvaluationInput:
						doProcess( param, static_cast< ast::type::TessellationEvaluationInput const & >( *type ) );
						break;
					case ast::type::Kind::eComputeInput:
						doProcess( param, static_cast< ast::type::ComputeInput const & >( *type ) );
						break;
					case ast::type::Kind::eTessellationOutputPatch:
						doProcess( param, static_cast< ast::type::TessellationOutputPatch const & >( *type ), isEntryPoint );
						break;
					case ast::type::Kind::eTessellationControlOutput:
						doProcess( param, static_cast< ast::type::TessellationControlOutput const & >( *type ), isEntryPoint );
						break;
					case ast::type::Kind::eMeshVertexOutput:
						doProcess( param, static_cast< ast::type::MeshVertexOutput const & >( *type ) );
						break;
					case ast::type::Kind::eMeshPrimitiveOutput:
						doProcess( param, static_cast< ast::type::MeshPrimitiveOutput const & >( *type ) );
						break;
					case ast::type::Kind::eTaskPayloadNV:
						doProcess( param, static_cast< ast::type::TaskPayloadNV const & >( *type ) );
						break;
					case ast::type::Kind::eTaskPayload:
						doProcess( param, static_cast< ast::type::TaskPayload const & >( *type ) );
						break;
					case ast::type::Kind::eTaskPayloadInNV:
						doProcess( param, static_cast< ast::type::TaskPayloadInNV const & >( *type ) );
						break;
					case ast::type::Kind::eTaskPayloadIn:
						doProcess( param, static_cast< ast::type::TaskPayloadIn const & >( *type ) );
						break;
					default:
						break;
					}
				}
			}

			void doDeclareStruct( ast::type::StructPtr const & structType )
			{
				TraceFunc;
				if ( m_declaredStructs.emplace( structType ).second )
				{
					m_current->addStmt( m_stmtCache.makeStructureDecl( structType ) );
				}
			}

		private:
			ast::type::TypesCache & m_typesCache;
			AdaptationData & m_adaptationData;
			ast::stmt::Container * m_ioDeclarations;
			ast::UnorderedSet< ast::type::StructPtr > m_declaredStructs;
			struct PendingFunction
			{
				ast::type::FunctionPtr funcType;
				ast::stmt::ContainerPtr statements;
			};
			ast::Map< std::string, PendingFunction > m_pending;
			ast::type::OutputTopology m_topology;
			uint32_t m_maxVertices{};
			uint32_t m_maxPrimitives{};
		};
	}

	ast::stmt::ContainerPtr adaptStatements( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Container * container
		, AdaptationData & adaptationData )
	{
		return adapt::StmtAdapter::submit( stmtCache
			, exprCache
			, typesCache
			, container
			, adaptationData );
	}
}
