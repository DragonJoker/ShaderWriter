/*
See LICENSE file in root folder
*/
#include "SpirvStmtAdapter.hpp"

#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include <ShaderAST/Shader.hpp>

#pragma warning( disable: 4706 )

namespace spirv
{
	ast::stmt::ContainerPtr StmtAdapter::submit( ast::stmt::Container * container
		, ModuleConfig const & config
		, PreprocContext & context )
	{
		auto result = ast::stmt::makeContainer();
		StmtAdapter vis{ result, config, context };
		container->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( ast::stmt::ContainerPtr & result
		, ModuleConfig const & config
		, PreprocContext & context )
		: StmtCloner{ result }
		, m_context{ context }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( expr, m_current, m_context, m_config );
	}

	void StmtAdapter::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		AST_Failure( "Unexpected ElseIf statement." );
	}

	void StmtAdapter::visitElseStmt( ast::stmt::Else * stmt )
	{
		AST_Failure( "Unexpected Else statement." );
	}

	void StmtAdapter::visitIfStmt( ast::stmt::If * stmt )
	{
		auto save = m_current;
		auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
		auto & cache = ctrlExpr->getCache();
		auto scalarType = getScalarType( ctrlExpr->getType()->getKind() );
		auto cont = ast::stmt::makeIf( ( scalarType != ast::type::Kind::eBoolean )
			? makeToBoolCast( cache, std::move( ctrlExpr ) )
			: std::move( ctrlExpr ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		auto currentIf = cont.get();
		m_current->addStmt( std::move( cont ) );

		// Replace all else ifs by the following :
		// Origin:
		// if (condA){}
		// else if (condB){}
		// else{}
		//
		// Result:
		// if (condA){}
		// else
		// {
		//   if (condB){}
		//   else{}
		// }
		if ( stmt->getElse()
			|| !stmt->getElseIfList().empty() )
		{
			auto & elseIfs = stmt->getElseIfList();
			auto it = elseIfs.begin();

			while ( it != elseIfs.end() )
			{
				auto elseStmt = currentIf->createElse();
				auto & elseIf = *it;
				ctrlExpr = doSubmit( elseIf->getCtrlExpr() );
				scalarType = getScalarType( ctrlExpr->getType()->getKind() );
				cont = ast::stmt::makeIf( ( scalarType != ast::type::Kind::eBoolean )
					? makeToBoolCast( cache, std::move( ctrlExpr ) )
					: std::move( ctrlExpr ) );
				m_current = cont.get();
				visitContainerStmt( elseIf.get() );
				m_current = save;
				currentIf = cont.get();
				elseStmt->addStmt( std::move( cont ) );
				++it;
			}

			if ( stmt->getElse() )
			{
				auto elseStmt = currentIf->createElse();
				m_current = elseStmt;
				visitContainerStmt( stmt->getElse() );
				m_current = save;
			}
		}
	}

	void StmtAdapter::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		StmtCloner::visitImageDeclStmt( stmt );
	}

	void StmtAdapter::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
		StmtCloner::visitPerVertexDeclStmt( stmt );
	}

	void StmtAdapter::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		StmtCloner::visitSampledImageDeclStmt( stmt );
	}

	void StmtAdapter::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		StmtCloner::visitShaderStructBufferDeclStmt( stmt );
	}

	void StmtAdapter::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		bool processed = false;

		if ( stmt->getExpr()->isConstant() )
		{
			if ( stmt->getExpr()->getKind() == ast::expr::Kind::eInit )
			{
				auto init = static_cast< ast::expr::Init * >( stmt->getExpr() );
				auto ident = init->getIdentifier();

				if ( ident )
				{
					m_context.constExprs.insert( { ident->getVariable()->getName()
						, doSubmit( init->getInitialiser() ) } );
					processed = true;
				}
			}
			else if ( stmt->getExpr()->getKind() == ast::expr::Kind::eAggrInit )
			{
				auto aggrInit = static_cast< ast::expr::AggrInit * >( stmt->getExpr() );
				auto ident = aggrInit->getIdentifier();

				if ( ident )
				{
					ast::expr::ExprList initialisers;

					for ( auto & init : aggrInit->getInitialisers() )
					{
						initialisers.emplace_back( doSubmit( init.get() ) );
					}

					m_context.constAggrExprs.emplace( ident->getVariable()->getName()
						, std::move( initialisers ) );
					processed = true;
				}
			}
		}

		if ( !processed )
		{
			StmtCloner::visitSimpleStmt( stmt );
		}
	}

	void StmtAdapter::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		StmtCloner::visitStructureDeclStmt( stmt );
	}

	void StmtAdapter::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		StmtCloner::visitVariableDeclStmt( stmt );
	}

	void StmtAdapter::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		m_context.constExprs.emplace( preproc->getName(), doSubmit( preproc->getExpr() ) );
	}

	void StmtAdapter::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtAdapter::visitPreprocElse( ast::stmt::PreprocElse * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtAdapter::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
	}

	void StmtAdapter::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
		bool isTrue = eval( preproc->getCtrlExpr(), m_context );

		if ( isTrue )
		{
			visitContainerStmt( preproc );
		}
		else
		{
			uint32_t i = 0u;

			while ( i < preproc->getElifList().size()
				&& !( isTrue = eval( static_cast< ast::stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_context ) ) )
			{
				++i;
			}

			if ( isTrue )
			{
				preproc->getElifList()[i]->accept( this );
			}
			else if ( preproc->getElse() )
			{
				preproc->getElse()->accept( this );
			}
		}
	}

	void StmtAdapter::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		bool isTrue = eval( preproc->getIdentExpr(), m_context );

		if ( isTrue )
		{
			visitContainerStmt( preproc );
		}
		else
		{
			uint32_t i = 0u;

			while ( i < preproc->getElifList().size()
				&& !( isTrue = eval( static_cast< ast::stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_context ) ) )
			{
				++i;
			}

			if ( isTrue )
			{
				preproc->getElifList()[i]->accept( this );
			}
			else if ( preproc->getElse() )
			{
				preproc->getElse()->accept( this );
			}
		}
	}
}
