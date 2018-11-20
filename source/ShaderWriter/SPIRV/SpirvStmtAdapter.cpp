/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvStmtAdapter.hpp"

#include "ShaderWriter/CloneExpr.hpp"
#include "ShaderWriter/SPIRV/SpirvExprAdapter.hpp"
#include "ShaderWriter/SPIRV/SpirvExprEvaluator.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw::spirv
{
	stmt::ContainerPtr StmtAdapter::submit( Shader const & shader, ShaderType type )
	{
		auto result = stmt::makeContainer();
		StmtAdapter vis{ shader, type, result };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( Shader const & shader
		, ShaderType type
		, stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_shader{ shader }
		, m_type{ type }
	{
	}

	expr::ExprPtr StmtAdapter::doSubmit( expr::Expr * expr )
	{
		return ExprAdapter::submit( expr, m_context );
	}

	void StmtAdapter::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		assert( false && "Unexpected ElseIf statement." );
	}

	void StmtAdapter::visitElseStmt( stmt::Else * stmt )
	{
		assert( false && "Unexpected Else statement." );
	}

	void StmtAdapter::visitIfStmt( stmt::If * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makeIf( ExprAdapter::submit( stmt->getCtrlExpr(), m_context ) );
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
				cont = stmt::makeIf( ExprAdapter::submit( elseIf->getCtrlExpr(), m_context ) );
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

	void StmtAdapter::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		m_context.defines.emplace( preproc->getName(), preproc->getExpr() );
	}

	void StmtAdapter::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtAdapter::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtAdapter::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
	}

	void StmtAdapter::visitPreprocIf( stmt::PreprocIf * preproc )
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
				&& !( isTrue = eval( static_cast< stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_context ) ) )
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

	void StmtAdapter::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
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
				&& !( isTrue = eval( static_cast< stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_context ) ) )
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
