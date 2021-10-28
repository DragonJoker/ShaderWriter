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
			doProcessInOut( stmt->getType()
				, stmt->isEntryPoint() );

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

	void StmtAdapter::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
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

	void StmtAdapter::doProcessComputeInput( ast::var::VariablePtr var
		, ast::type::ComputeInput const & compType )
	{
		auto type = compType.getType();

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto structType = std::static_pointer_cast< ast::type::Struct >( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, true );
		}

		m_current->addStmt( ast::stmt::makeInputComputeLayout( type
			, compType.getLocalSizeX()
			, compType.getLocalSizeY()
			, compType.getLocalSizeZ() ) );
	}

	void StmtAdapter::doProcessGeometryOutput( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto structType = std::static_pointer_cast< ast::type::Struct >( type );
			assert( structType->isShaderOutput() );
			doProcessOutput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
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
			auto structType = std::static_pointer_cast< ast::type::Struct >( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, true );
		}

		m_current->addStmt( ast::stmt::makeInputGeometryLayout( type
			, geomType.layout ) );
	}

	void StmtAdapter::doProcessTessellationControlOutput( ast::var::VariablePtr var
		, ast::type::TessellationControlOutput const & tessType
		, bool isEntryPoint )
	{
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto structType = std::static_pointer_cast< ast::type::Struct >( type );
			assert( structType->isShaderOutput() );
			doProcessOutput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, true );
		}

		m_current->addStmt( ast::stmt::makeOutputTessellationControlLayout( type
			, tessType.getDomain()
			, tessType.getPartitioning()
			, tessType.getTopology()
			, tessType.getOrder()
			, tessType.getOutputVertices() ) );
	}

	void StmtAdapter::doProcessTessellationControlInput( ast::var::VariablePtr var
		, ast::type::TessellationControlInput const & geomType
		, bool isEntryPoint )
	{
		auto type = geomType.getType();

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto structType = std::static_pointer_cast< ast::type::Struct >( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, isEntryPoint );
		}
	}

	void StmtAdapter::doProcessOutput( ast::var::VariablePtr var
		, ast::type::IOStructPtr ioType
		, bool isEntryPoint )
	{
		//for ( auto & mbr : *ioType )
		//{
		//	auto it = std::find_if( m_adaptationData.config.outputs.begin()
		//		, m_adaptationData.config.outputs.end()
		//		, [&mbr]( ast::var::VariablePtr const & lookup )
		//		{
		//			return ( lookup->isBuiltin() && lookup->getBuiltin() == mbr.builtin )
		//				|| lookup->getName() == "sdwOut_" + mbr.name;
		//		} );
		//	assert( it != m_adaptationData.config.outputs.end() );
		//	auto mbrVar = *it;
		//	m_adaptationData.outputs[ioType].emplace_back( mbrVar );

		//	if ( isEntryPoint )
		//	{
		//		m_current->addStmt( ast::stmt::makeInOutVariableDecl( mbrVar
		//			, mbr.location ) );
		//	}
		//}
	}

	void StmtAdapter::doProcessInput( ast::var::VariablePtr var
		, ast::type::IOStructPtr ioType
		, bool isEntryPoint )
	{
		//for ( auto & mbr : *ioType )
		//{
		//	auto it = std::find_if( m_adaptationData.config.inputs.begin()
		//		, m_adaptationData.config.inputs.end()
		//		, [&mbr]( ast::var::VariablePtr const & lookup )
		//		{
		//			return ( lookup->isBuiltin() && lookup->getBuiltin() == mbr.builtin )
		//				|| lookup->getName() == "sdwIn_" + mbr.name;
		//		} );
		//	assert( it != m_adaptationData.config.inputs.end() );
		//	auto mbrVar = *it;
		//	m_adaptationData.inputs[ioType].emplace_back( mbrVar );

		//	if ( isEntryPoint && mbr.builtin != ast::Builtin::eWorkGroupSize )
		//	{
		//		m_current->addStmt( ast::stmt::makeInOutVariableDecl( mbrVar
		//			, mbr.location ) );
		//	}
		//}
	}

	void StmtAdapter::doProcessOutputPatch( ast::var::VariablePtr var
		, ast::type::TessellationOutputPatch const & patchType
		, bool isEntryPoint )
	{
		if ( isEntryPoint )
		{
			auto type = patchType.getType();

			if ( type->getKind() == ast::type::Kind::eStruct )
			{
				doDeclareStruct( std::static_pointer_cast< ast::type::Struct >( type ) );
			}

			if ( isEntryPoint )
			{
				m_current->addStmt( ast::stmt::makeInOutVariableDecl( var, patchType.getLocation() ) );
			}
			else
			{
				m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
			}
		}
	}

	void StmtAdapter::doProcessInputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType
		, bool isEntryPoint )
	{
		if ( isEntryPoint )
		{
			doDeclareStruct( structType );
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
			for ( auto & pending : m_pending )
			{
				doProcessInOut( pending.second.funcType
					, false );
				visitContainerStmt( pending.second.statements.get() );
			}
		}

		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtAdapter::doProcessPatchRoutine( ast::stmt::FunctionDecl * stmt )
	{
		auto save = m_current;
		auto cont = ast::stmt::makeContainer();
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_pending.emplace( stmt->getName()
			, PendingFunction{ stmt->getType(), std::move( cont ) } );
	}

	void StmtAdapter::doProcessInOut( ast::type::FunctionPtr funcType
		, bool isEntryPoint )
	{
		for ( auto & param : *funcType )
		{
			auto type = param->getType();

			if ( type->getKind() == ast::type::Kind::eComputeInput )
			{
				doProcessComputeInput( param
					, static_cast< ast::type::ComputeInput const & >( *type ) );
			}
			else if ( type->getKind() == ast::type::Kind::eGeometryOutput )
			{
				doProcessGeometryOutput( param
					, static_cast< ast::type::GeometryOutput const & >( *type ) );
			}
			else if ( type->getKind() == ast::type::Kind::eGeometryInput )
			{
				doProcessGeometryInput( param
					, static_cast< ast::type::GeometryInput const & >( *type ) );
			}
			else if ( type->getKind() == ast::type::Kind::eTessellationControlInput )
			{
				doProcessTessellationControlInput( param
					, static_cast< ast::type::TessellationControlInput const & >( *type )
					, isEntryPoint );
			}
			else if ( type->getKind() == ast::type::Kind::eTessellationControlOutput )
			{
				doProcessTessellationControlOutput( param
					, static_cast< ast::type::TessellationControlOutput const & >( *type )
					, isEntryPoint );
			}
			else if ( type->getKind() == ast::type::Kind::eTessellationOutputPatch )
			{
				doProcessOutputPatch( param
					, static_cast< ast::type::TessellationOutputPatch const & >( *type )
					, isEntryPoint );
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
							, std::static_pointer_cast< ast::type::IOStruct >( structType )
							, isEntryPoint );
					}
					else if ( structType->isShaderOutput() )
					{
						doProcessOutput( param
							, std::static_pointer_cast< ast::type::IOStruct >( structType )
							, isEntryPoint );
					}
					else if ( param->isPatchInput() )
					{
						doProcessInputPatch( param
							, structType
							, isEntryPoint );
					}
				}
			}
		}
	}

	void StmtAdapter::doDeclareStruct( ast::type::StructPtr const & structType )
	{
		if ( m_declaredStructs.emplace( structType ).second )
		{
			m_current->addStmt( ast::stmt::makeStructureDecl( structType ) );
		}
	}
}
