/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslStmtAdapter.hpp"

#include "ShaderWriter/HLSL/HlslExprAdapter.hpp"
#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw::hlsl
{
	stmt::ContainerPtr StmtAdapter::submit( Shader & shader, ShaderType type )
	{
		auto result = stmt::makeContainer();
		StmtAdapter vis{ shader, type, result.get() };
		shader.getStatements()->accept( &vis );
		vis.end();
		return result;
	}

	void StmtAdapter::end()
	{
		writeHlslFunctions( m_intrinsics, m_config );
	}

	StmtAdapter::StmtAdapter( Shader & shader
		, ShaderType type
		, stmt::Container * result )
		: m_shader{ shader }
		, m_result{ result }
		, m_type{ type }
	{
		m_inputStruct = type::makeStructType( "HLSL_SDW_Input" );
		m_outputStruct = type::makeStructType( "HLSL_SDW_Output" );
		m_result->addStmt( stmt::makeStructureDecl( m_inputStruct ) );
		m_result->addStmt( stmt::makeStructureDecl( m_outputStruct ) );
		auto cont = stmt::makeContainer();
		m_intrinsics = cont.get();
		m_result->addStmt( std::move( cont ) );
		m_inputVar = m_shader.registerName( "sdwInput", m_inputStruct, var::Flag::eInputParam );
		m_outputVar = m_shader.registerName( "sdwOutput", m_outputStruct );
	}

	void StmtAdapter::linkVars( var::VariablePtr textureSampler
		, var::VariablePtr texture
		, var::VariablePtr sampler )
	{
		m_linkedVars.emplace( std::move( textureSampler )
			, std::make_pair( std::move( texture )
				, std::move( sampler ) ) );
	}

	void StmtAdapter::visitContainerStmt( stmt::Container * cont )
	{
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtAdapter::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeConstantBufferDecl( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getBindingSet() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitDiscardStmt( stmt::Discard * stmt )
	{
		m_result->addStmt( stmt::makeDiscard() );
	}

	void StmtAdapter::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makePushConstantsBufferDecl( stmt->getName() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitCommentStmt( stmt::Comment * stmt )
	{
		m_result->addStmt( stmt::makeComment( stmt->getText() ) );
	}

	void StmtAdapter::visitCompoundStmt( stmt::Compound * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeContainer();
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeDoWhile( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeElseIf( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitElseStmt( stmt::Else * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeElse();
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitForStmt( stmt::For * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeFor( ExprAdapter::submit( stmt->getInitExpr()
				, m_config
				, m_linkedVars
				, m_inputMembers
				, m_outputMembers )
			, ExprAdapter::submit( stmt->getCtrlExpr()
				, m_config
				, m_linkedVars
				, m_inputMembers
				, m_outputMembers )
			, ExprAdapter::submit( stmt->getIncrExpr()
				, m_config
				, m_linkedVars
				, m_inputMembers
				, m_outputMembers ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		auto save = m_result;
		stmt::FunctionDeclPtr cont;
		auto linkedVars = m_linkedVars;

		if ( stmt->getName() == "main" )
		{
			std::string outputName = "TEXCOORD";
			std::string inputName = "TEXCOORD";
			uint32_t index = 0u;

			for ( auto & input : m_inputVars )
			{
				m_inputStruct->addMember( input.second->getType(), input.second->getName() + ": " + inputName + std::to_string( index++ ) );
			}

			index = 0u;

			if ( m_type == ShaderType::eFragment )
			{
				outputName = "SV_TARGET";
			}
			else if ( m_type == ShaderType::eCompute )
			{
			}

			for ( auto & output : m_outputVars )
			{
				if ( output.second->getName() == "gl_Position" )
				{
					m_outputStruct->addMember( output.second->getType(), output.second->getName() + ": SV_POSITION" );
				}
				else
				{
					m_outputStruct->addMember( output.second->getType(), output.second->getName() + ": " + outputName + std::to_string( index++ ) );
				}
			}

			assert( stmt->getParameters().empty() );
			assert( stmt->getRet()->getKind() == type::Kind::eVoid );
			var::VariableList parameters;
			parameters.emplace_back( m_inputVar );
			cont = stmt::makeFunctionDecl( m_outputStruct
				, stmt->getName()
				, parameters );
			cont->addStmt( stmt::makeVariableDecl( m_outputVar ) );
		}
		else
		{
			var::VariableList params;

			for ( auto & param : stmt->getParameters() )
			{
				if ( isSampler( param->getType()->getKind() ) )
				{
					auto texture = var::makeVariable( param->getType()
						, param->getName() + "_texture" );
					auto sampler = var::makeVariable( makeSampler()
						, param->getName() + "_sampler" );
					m_linkedVars.emplace( param, std::make_pair( texture, sampler ) );
					params.push_back( texture );
					params.push_back( sampler );
				}
				else
				{
					params.push_back( param );
				}
			}

			cont = stmt::makeFunctionDecl( stmt->getRet()
				, stmt->getName()
				, params );
		}

		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;

		if ( stmt->getName() == "main" )
		{
			cont->addStmt( stmt::makeReturn( expr::makeIdentifier( m_outputVar ) ) );
		}

		m_result->addStmt( std::move( cont ) );
		m_linkedVars = linkedVars;
	}

	void StmtAdapter::visitIfStmt( stmt::If * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeElseIf( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );

		for ( auto & elseIf : stmt->getElseIfList() )
		{
			elseIf->accept( this );
		}

		if ( stmt->getElse() )
		{
			stmt->getElse()->accept( this );
		}
	}

	void StmtAdapter::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		m_result->addStmt( stmt::makeImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getBindingSet() ) );
	}

	void StmtAdapter::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		auto & var = stmt->getVariable();

		if ( var->isShaderInput() )
		{
			m_inputVars.emplace( stmt->getLocation(), var );
			m_inputMembers.emplace( var, expr::makeMbrSelect( makeIdent( m_inputVar ), makeIdent( var ) ) );
		}
		else if ( var->isShaderOutput() )
		{
			m_outputVars.emplace( stmt->getLocation(), var );
			m_outputMembers.emplace( var, expr::makeMbrSelect( makeIdent( m_outputVar ), makeIdent( var ) ) );
		}
	}

	void StmtAdapter::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		m_inputComputeLayout = stmt;
	}

	void StmtAdapter::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		m_inputGeometryLayout = stmt;
	}

	void StmtAdapter::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		m_outputGeometryLayout = stmt;
	}

	void StmtAdapter::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		auto index = 128u;

		for ( auto & member : *stmt->getType() )
		{
			if ( member.name == "gl_Position" )
			{
				auto outputVar = m_shader.getVar( member.name, member.type );
				m_outputMembers.emplace( outputVar, expr::makeMbrSelect( makeIdent( m_outputVar ), makeIdent( outputVar ) ) );
				m_outputVars.emplace( index++, outputVar );
			}
		}
	}

	void StmtAdapter::visitReturnStmt( stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			m_result->addStmt( stmt::makeReturn( ExprAdapter::submit( stmt->getExpr()
				, m_config
				, m_linkedVars
				, m_inputMembers
				, m_outputMembers ) ) );
		}
		else
		{
			m_result->addStmt( stmt::makeReturn() );
		}
	}

	void StmtAdapter::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		auto originalVar = stmt->getVariable();
		auto textureVar = m_shader.registerImage( stmt->getVariable()->getName() + "_texture"
			, stmt->getVariable()->getType()
			, stmt->getBindingPoint()
			, stmt->getBindingSet() );
		textureVar->setFlag( var::Flag::eImplicit );
		m_result->addStmt( stmt::makeImageDecl( textureVar
			, stmt->getBindingPoint()
			, stmt->getBindingSet() ) );

		if ( stmt->getVariable()->getType()->getKind() != type::Kind::eSamplerBufferF
			&& stmt->getVariable()->getType()->getKind() != type::Kind::eSamplerBufferI
			&& stmt->getVariable()->getType()->getKind() != type::Kind::eSamplerBufferU )
		{
			auto samplerVar = m_shader.registerSampler( stmt->getVariable()->getName() + "_sampler"
				, makeSampler()
				, stmt->getBindingPoint()
				, stmt->getBindingSet() );
			samplerVar->setFlag( var::Flag::eImplicit );
			linkVars( originalVar, textureVar, samplerVar );
			m_result->addStmt( stmt::makeSamplerDecl( samplerVar
				, stmt->getBindingPoint()
				, stmt->getBindingSet() ) );
		}
	}

	void StmtAdapter::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeShaderBufferDecl( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getBindingSet() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitSimpleStmt( stmt::Simple * stmt )
	{
		m_result->addStmt( stmt::makeSimple( ExprAdapter::submit( stmt->getExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) ) );
	}

	void StmtAdapter::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		m_result->addStmt( stmt::makeStructureDecl( std::make_shared< type::Struct >( stmt->getType() ) ) );
	}

	void StmtAdapter::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeSwitchCase( expr::makeSwitchCase( std::make_unique< expr::Literal >( *stmt->getCaseExpr()->getLabel() ) ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitSwitchStmt( stmt::Switch * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeSwitch( expr::makeSwitchTest( ExprAdapter::submit( stmt->getTestExpr()->getValue()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		m_result->addStmt( stmt::makeVariableDecl( stmt->getVariable() ) );
	}

	void StmtAdapter::visitWhileStmt( stmt::While * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeWhile( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		m_result->addStmt( stmt::makePreprocDefine( preproc->getName(), ExprAdapter::submit( preproc->getExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) ) );
	}

	void StmtAdapter::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		m_result->addStmt( stmt::makePreprocElif( ExprAdapter::submit( preproc->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) ) );
	}

	void StmtAdapter::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		m_result->addStmt( stmt::makePreprocElse() );
	}

	void StmtAdapter::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
		m_result->addStmt( stmt::makePreprocEndif() );
	}

	void StmtAdapter::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
	}

	void StmtAdapter::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		m_result->addStmt( stmt::makePreprocIf( ExprAdapter::submit( preproc->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) ) );
	}

	void StmtAdapter::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		m_result->addStmt( stmt::makePreprocIfDef( makeIdent( preproc->getIdentExpr()->getVariable() ) ) );
	}

	void StmtAdapter::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
	}
}
