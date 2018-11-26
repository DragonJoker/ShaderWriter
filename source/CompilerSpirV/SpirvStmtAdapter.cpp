/*
See LICENSE file in root folder
*/
#include "SpirvStmtAdapter.hpp"

#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include <ShaderWriter/Shader.hpp>

namespace spirv
{
	ast::stmt::ContainerPtr StmtAdapter::submit( sdw::Shader const & shader )
	{
		auto result = ast::stmt::makeContainer();
		StmtAdapter vis{ shader, result };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( sdw::Shader const & shader
		, ast::stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_shader{ shader }
	{
	}

	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( expr, m_context );
	}

	void StmtAdapter::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		assert( false && "Unexpected ElseIf statement." );
	}

	void StmtAdapter::visitElseStmt( ast::stmt::Else * stmt )
	{
		assert( false && "Unexpected Else statement." );
	}

	void StmtAdapter::visitIfStmt( ast::stmt::If * stmt )
	{
		auto save = m_current;
		auto cont = ast::stmt::makeIf( ExprAdapter::submit( stmt->getCtrlExpr(), m_context ) );
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
				cont = ast::stmt::makeIf( ExprAdapter::submit( elseIf->getCtrlExpr(), m_context ) );
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

	void StmtAdapter::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		m_context.defines.emplace( preproc->getName(), preproc->getExpr() );
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
