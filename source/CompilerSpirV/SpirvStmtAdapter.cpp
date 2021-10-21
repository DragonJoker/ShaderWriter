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
		, AdaptationData & adaptationData )
	{
		auto result = ast::stmt::makeContainer();
		StmtAdapter vis{ result, adaptationData };
		container->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( ast::stmt::ContainerPtr & result
		, AdaptationData & adaptationData )
		: StmtCloner{ result }
		, m_adaptationData{ adaptationData }
		, m_entryPointFinish{ ast::stmt::makeContainer() }
	{
	}

	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( expr, m_current, m_adaptationData );
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
		assert( stmt->getElseIfList().empty() && "ElseIf list is supposed to have been converted." );
		auto save = m_current;
		auto cont = ast::stmt::makeIf( doSubmit( stmt->getCtrlExpr() ) );
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

	void StmtAdapter::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getFlags() )
		{
			auto funcType = stmt->getType();
			bool isEntryPoint = stmt->isEntryPoint();

			for ( auto & param : *funcType )
			{
				auto type = param->getType();

				if ( type->getKind() == ast::type::Kind::eGeometryOutput )
				{
					doProcessGeometryOutput( param
						, static_cast< ast::type::GeometryOutput const & >( *type ) );
				}
				else if ( type->getKind() == ast::type::Kind::eGeometryInput )
				{
					doProcessGeometryInput( param
						, static_cast< ast::type::GeometryInput const & >( *type ) );
				}
				else
				{
					uint32_t arraySize = ast::type::NotArray;

					if ( type->getKind() == ast::type::Kind::eArray )
					{
						auto & arrayType = static_cast< ast::type::Array const & >( *type );
						type = arrayType.getType();
						arraySize = arrayType.getArraySize();
					}

					if ( type->getKind() == ast::type::Kind::eStruct )
					{
						auto structType = std::static_pointer_cast< ast::type::Struct >( type );

						if ( structType->isShaderInput() )
						{
							doProcessInput( param
								, static_cast< ast::type::IOStruct const & >( *structType )
								, isEntryPoint );
						}
						else if ( structType->isShaderOutput() )
						{
							doProcessOutput( param
								, static_cast< ast::type::IOStruct const & >( *structType )
								, isEntryPoint );
						}
						else if ( param->isPatchInput() )
						{
							doProcessInputPatch( param
								, structType
								, isEntryPoint );
						}
						else if ( param->isPatchOutput() )
						{
							doProcessOutputPatch( param
								, structType
								, isEntryPoint );
						}
					}
				}
			}

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
					m_adaptationData.context.constExprs.emplace( ident->getVariable()->getId()
						, doSubmit( init->getInitialiser() ) );
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

					m_adaptationData.context.constAggrExprs.emplace( ident->getVariable()->getId()
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
		m_adaptationData.context.constExprs.emplace( preproc->getId()
			, doSubmit( preproc->getExpr() ) );
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
		bool isTrue = eval( preproc->getCtrlExpr(), m_adaptationData.context );

		if ( isTrue )
		{
			visitContainerStmt( preproc );
		}
		else
		{
			uint32_t i = 0u;

			while ( i < preproc->getElifList().size()
				&& !( isTrue = eval( static_cast< ast::stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_adaptationData.context ) ) )
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
		bool isTrue = eval( preproc->getIdentExpr(), m_adaptationData.context );

		if ( isTrue )
		{
			visitContainerStmt( preproc );
		}
		else
		{
			uint32_t i = 0u;

			while ( i < preproc->getElifList().size()
				&& !( isTrue = eval( static_cast< ast::stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_adaptationData.context ) ) )
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

	void StmtAdapter::doProcessGeometryOutput( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderOutput() );
			doProcessOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, true );
		}

		m_current->addStmt( ast::stmt::makeOutputGeometryLayout( type
			, geomType.layout
			, geomType.count ) );
	}

	void StmtAdapter::doProcessGeometryInput( ast::var::VariablePtr var
		, ast::type::GeometryInput const & geomType )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderInput() );
			doProcessInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, true );
		}

		m_current->addStmt( ast::stmt::makeInputGeometryLayout( type
			, geomType.layout ) );
	}

	void StmtAdapter::doProcessOutput( ast::var::VariablePtr var
		, ast::type::IOStruct const & ioType
		, bool isEntryPoint )
	{
		for ( auto & mbr : ioType )
		{
			auto it = std::find_if( m_adaptationData.config.outputs.begin()
				, m_adaptationData.config.outputs.end()
				, [&mbr]( ast::var::VariablePtr const & lookup )
				{
					return lookup->getName() == "sdwOut_" + mbr.name;
				} );
			assert( it != m_adaptationData.config.outputs.end() );
			auto mbrVar = *it;
			m_adaptationData.outputs.emplace_back( mbrVar );

			if ( isEntryPoint )
			{
				m_current->addStmt( ast::stmt::makeInOutVariableDecl( mbrVar
					, mbr.location ) );
			}
		}
	}

	void StmtAdapter::doProcessInput( ast::var::VariablePtr var
		, ast::type::IOStruct const & ioType
		, bool isEntryPoint )
	{
		for ( auto & mbr : ioType )
		{
			auto it = std::find_if( m_adaptationData.config.inputs.begin()
				, m_adaptationData.config.inputs.end()
				, [&mbr]( ast::var::VariablePtr const & lookup )
				{
					return lookup->getName() == "sdwIn_" + mbr.name;
				} );
			assert( it != m_adaptationData.config.inputs.end() );
			auto mbrVar = *it;
			m_adaptationData.inputs.emplace_back( mbrVar );

			if ( isEntryPoint )
			{
				m_current->addStmt( ast::stmt::makeInOutVariableDecl( mbrVar
					, mbr.location ) );
			}
		}
	}

	void StmtAdapter::doProcessOutputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType
		, bool isEntryPoint )
	{
		if ( isEntryPoint )
		{
			m_current->addStmt( ast::stmt::makeStructureDecl( structType ) );
			m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
		}
	}

	void StmtAdapter::doProcessInputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType
		, bool isEntryPoint )
	{
		if ( isEntryPoint )
		{
			m_current->addStmt( ast::stmt::makeStructureDecl( structType ) );
			m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
		}
	}

	void StmtAdapter::doProcessEntryPoint( ast::stmt::FunctionDecl * stmt )
	{
		auto & cache = stmt->getType()->getCache();
		auto funcType = cache.getFunction( cache.getVoid(), {} );
		auto save = m_current;
		auto cont = ast::stmt::makeFunctionDecl( funcType, stmt->getName(), stmt->getFlags() );
		m_current = cont.get();
		visitContainerStmt( stmt );

		if ( stmt->isEntryPoint() )
		{
			visitContainerStmt( m_entryPointFinish.get() );
		}

		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtAdapter::doProcessPatchRoutine( ast::stmt::FunctionDecl * stmt )
	{
		auto save = m_current;
		m_current = m_entryPointFinish.get();
		visitContainerStmt( stmt );
		m_current = save;
	}
}
