/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslStmtAdapter.hpp"

#include "ShaderWriter/HLSL/HlslExprAdapter.hpp"
#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/HLSL/HlslImageAccessFunctions.hpp"
#include "ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp"
#include "ShaderWriter/HLSL/HlslTextureAccessFunctions.hpp"

#include "ShaderWriter/Shader.hpp"

#include <ASTGenerator/Type/TypeSampledImage.hpp>
#include <ASTGenerator/Type/TypeImage.hpp>

namespace sdw::hlsl
{
	namespace
	{
		std::string getSemantic( std::string const & name
			, std::string const & default
			, uint32_t & index )
		{
			static std::map< std::string, std::string > const NamesMap
			{
				{ "gl_InvocationID", "SV_GSInstanceID" },
				{ "gl_LocalInvocationID", "SV_GroupThreadID" },
				{ "gl_LocalInvocationIndex", "SV_GroupIndex" },
				{ "gl_WorkGroupID", "SV_GroupID" },
				{ "gl_TessCord", "SV_DomainLocation" },
				{ "gl_GlobalInvocationID", "SV_DispatchThreadID" },
				{ "gl_FragDepth", "SV_Depth" },
				{ "gl_SampleMask", "SV_Coverage" },
				{ "gl_SampleMaskIn", "SV_Coverage" },
				{ "gl_CullDistance", "SV_CullDistance" },
				{ "gl_ClipDistance", "SV_ClipDistance" },
				{ "gl_TessLevelInner", "SV_InsideTessFactor" },
				{ "gl_InstanceID", "SV_InstanceID" },
				{ "gl_InstanceIndex", "SV_InstanceID" },
				{ "gl_FrontFacing", "SV_IsFrontFace" },
				{ "gl_Position", "SV_Position" },
				{ "gl_FragCoord", "SV_Position" },
				{ "gl_PrimitiveID", "SV_PrimitiveID" },
				{ "gl_Layer", "SV_RenderTargetArrayIndex" },
				{ "gl_SampleID", "SV_SampleIndex" },
				{ "gl_FragStencilRef", "SV_StencilRef" },
				{ "gl_TessLevelOuter", "SV_TessFactor" },
				{ "gl_VertexID", "SV_VertexID" },
				{ "gl_VertexIndex", "SV_VertexID" },
				{ "gl_ViewportIndex", "SV_ViewportArrayIndex" },
			};
			std::string result;
			auto it = NamesMap.find( name );

			if ( it != NamesMap.end() )
			{
				result = it->second;
			}
			else
			{
				result = default + std::to_string( index++ );
			}

			return result;
		}

		bool isShaderInput( std::string const & name
			, ShaderType type )
		{
			return
				( type == ShaderType::eCompute
					&& ( name == "gl_NumWorkGroups"
						|| name == "gl_WorkGroupID"
						|| name == "gl_LocalInvocationID"
						|| name == "gl_GlobalInvocationID"
						|| name == "gl_LocalInvocationIndex" ) )
				|| ( type == ShaderType::eFragment
					&& ( name == "gl_FragCoord"
						|| name == "gl_FrontFacing"
						|| name == "gl_PointCoord"
						|| name == "gl_SampleID"
						|| name == "gl_SamplePosition"
						|| name == "gl_SampleMaskIn"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveID"
						|| name == "gl_Layer"
						|| name == "gl_ViewportIndex" ) )
				|| ( type == ShaderType::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveIDIn"
						|| name == "gl_InvocationID" ) )
				|| ( type == ShaderType::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_InvocationID" ) )
				|| ( type == ShaderType::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_TessCord"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == ShaderType::eVertex
					&& ( name == "gl_VertexID"
						|| name == "gl_VertexIndex"
						|| name == "gl_InstanceID"
						|| name == "gl_InstanceIndex"
						|| name == "gl_DrawID"
						|| name == "gl_BaseVertex"
						|| name == "gl_BaseInstance"
						|| name == "gl_TessLevelOuter" ) );
		}

		bool isShaderOutput( std::string const & name
			, ShaderType type )
		{
			return 
				( type == ShaderType::eFragment
					&& ( name == "gl_FragDepth"
						|| name == "gl_SampleMask"
						|| name == "gl_FragStencilRef" ) )
				|| ( type == ShaderType::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveID"
						|| name == "gl_Layer"
						|| name == "gl_ViewportIndex" ) )
				|| ( type == ShaderType::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == ShaderType::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance" ) )
				|| ( type == ShaderType::eVertex
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance" ) );
		}

		bool isShaderInOut( std::string const & name
			, ShaderType type )
		{
			return isShaderInput( name, type )
				&& isShaderOutput( name, type );
		}
	}

	stmt::ContainerPtr StmtAdapter::submit( Shader const & shader, ShaderType type )
	{
		auto result = stmt::makeContainer();
		StmtAdapter vis{ shader, type, result.get() };
		shader.getStatements()->accept( &vis );
		vis.end();
		return result;
	}

	void StmtAdapter::end()
	{
		writeHlslIntrinsicFunctions( m_intrinsics, m_config );
		writeHlslTextureAccessFunctions( m_intrinsics, m_config );
		writeHlslImageAccessFunctions( m_intrinsics, m_config );
	}

	StmtAdapter::StmtAdapter( Shader const & shader
		, ShaderType type
		, stmt::Container * result )
		: m_shader{ shader }
		, m_result{ result }
		, m_type{ type }
	{
		m_inputStruct = type::makeStructType( type::MemoryLayout::eStd430, "HLSL_SDW_Input" );
		m_outputStruct = type::makeStructType( type::MemoryLayout::eStd430, "HLSL_SDW_Output" );
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
			, stmt->getDescriptorSet() );
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
		auto cont = m_ifStmts.back()->createElseIf( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );
		m_result = cont;
		visitContainerStmt( stmt );
		m_result = save;
	}

	void StmtAdapter::visitElseStmt( stmt::Else * stmt )
	{
		auto save = m_result;
		auto cont = m_ifStmts.back()->createElse();
		m_result = cont;
		visitContainerStmt( stmt );
		m_result = save;
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

	void StmtAdapter::rewriteShaderIOVars()
	{
		std::string outputName = "TEXCOORD";
		std::string inputName = "TEXCOORD";
		uint32_t index = 0u;

		for ( auto & input : m_inputVars )
		{
			m_inputStruct->declMember( input.second->getName()
				+ ": "
				+ getSemantic( input.second->getName()
					, inputName
					, index )
				, input.second->getType()->getKind()
				, input.second->getType()->getArraySize() );
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
			m_outputStruct->declMember( output.second->getName()
				+ ": "
				+ getSemantic( output.second->getName()
					, outputName
					, index )
				, output.second->getType()->getKind()
				, output.second->getType()->getArraySize() );
		}
	}

	stmt::FunctionDeclPtr StmtAdapter::rewriteMainHeader( stmt::FunctionDecl * stmt )
	{
		rewriteShaderIOVars();
		assert( stmt->getParameters().empty() );
		assert( stmt->getRet()->getKind() == type::Kind::eVoid );
		var::VariableList parameters;
		parameters.emplace_back( m_inputVar );

		// Add input parameter
		if ( m_inputComputeLayout )
		{
			m_result->addStmt( stmt::makeInputComputeLayout( m_inputComputeLayout->getWorkGroupsX()
				, m_inputComputeLayout->getWorkGroupsY()
				, m_inputComputeLayout->getWorkGroupsZ() ) );
		}

		// Write output return if needed.
		stmt::FunctionDeclPtr result;

		if ( !m_outputStruct->empty() )
		{
			result = stmt::makeFunctionDecl( m_outputStruct
				, stmt->getName()
				, parameters );
			result->addStmt( stmt::makeVariableDecl( m_outputVar ) );
		}
		else
		{
			result = stmt::makeFunctionDecl( stmt->getRet()
				, stmt->getName()
				, parameters );
		}

		return result;
	}

	stmt::FunctionDeclPtr StmtAdapter::rewriteFuncHeader( stmt::FunctionDecl * stmt )
	{
		var::VariableList params;
		// Split sampled textures in sampler + texture in parameters list.
		for ( auto & param : stmt->getParameters() )
		{
			if ( isSampledImageType( param->getType()->getKind() ) )
			{
				auto config = std::static_pointer_cast< type::SampledImage >( param->getType() )->getConfig();
				auto texture = var::makeVariable( type::getImage( config, param->getType()->getArraySize() )
					, param->getName() + "_texture" );
				auto sampler = var::makeVariable( makeType( type::Kind::eSampler, param->getType()->getArraySize() )
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

		return stmt::makeFunctionDecl( stmt->getRet()
			, stmt->getName()
			, params );
	}

	void StmtAdapter::rewriteMainFooter( stmt::FunctionDecl * stmt )
	{
		if ( stmt->getName() == "main"
			&& !m_outputStruct->empty() )
		{
			m_result->addStmt( stmt::makeReturn( expr::makeIdentifier( m_outputVar ) ) );
		}
	}

	void StmtAdapter::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		auto save = m_result;
		stmt::FunctionDeclPtr cont;
		auto linkedVars = m_linkedVars;

		if ( stmt->getName() == "main" )
		{
			cont = rewriteMainHeader( stmt );
		}
		else
		{
			cont = rewriteFuncHeader( stmt );
		}

		m_result = cont.get();
		visitContainerStmt( stmt );
		rewriteMainFooter( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
		m_linkedVars = linkedVars;
	}

	void StmtAdapter::visitIfStmt( stmt::If * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeIf( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_ifStmts.push_back( cont.get() );
		m_result->addStmt( std::move( cont ) );

		for ( auto & elseIf : stmt->getElseIfList() )
		{
			elseIf->accept( this );
		}

		if ( stmt->getElse() )
		{
			stmt->getElse()->accept( this );
		}

		m_ifStmts.pop_back();
	}

	void StmtAdapter::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		m_result->addStmt( stmt::makeImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtAdapter::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		auto & var = stmt->getVariable();

		if ( var->isShaderInput() )
		{
			m_inputVars.emplace( stmt->getLocation(), var );
			m_inputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_inputVar )
					, uint32_t( m_inputMembers.size() )
					, makeIdent( var ) ) );
		}
		else if ( var->isShaderOutput() )
		{
			m_outputVars.emplace( stmt->getLocation(), var );
			m_outputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_outputVar )
					, uint32_t( m_outputMembers.size() )
					, makeIdent( var ) ) );
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
				m_outputMembers.emplace( outputVar
					, expr::makeMbrSelect( makeIdent( m_outputVar )
						, uint32_t( m_outputMembers.size() )
						, makeIdent( outputVar ) ) );
				m_outputVars.emplace( index, outputVar );
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

	void StmtAdapter::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		auto originalVar = stmt->getVariable();
		auto config = std::static_pointer_cast< type::SampledImage >( stmt->getVariable()->getType() )->getConfig();
		// Create Image
		auto textureVar = m_shader.registerImage( stmt->getVariable()->getName() + "_texture"
			, type::getImage( config, stmt->getVariable()->getType()->getArraySize() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		textureVar->setFlag( var::Flag::eImplicit );
		m_result->addStmt( stmt::makeImageDecl( textureVar
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );

		// Create Sampler
		auto samplerVar = m_shader.registerSampler( stmt->getVariable()->getName() + "_sampler"
			, makeType( type::Kind::eSampler, stmt->getVariable()->getType()->getArraySize() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		samplerVar->setFlag( var::Flag::eImplicit );
		m_result->addStmt( stmt::makeSamplerDecl( samplerVar
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );

		// Link them
		linkVars( originalVar, textureVar, samplerVar );
	}

	void StmtAdapter::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		auto samplerVar = m_shader.registerSampler( stmt->getVariable()->getName()
			, stmt->getVariable()->getType()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
	}

	void StmtAdapter::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeShaderBufferDecl( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
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
		m_result->addStmt( stmt::makeStructureDecl( stmt->getType() ) );
	}

	void StmtAdapter::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		stmt::SwitchCase * cont;

		if ( stmt->getCaseExpr() )
		{
			cont = m_switchStmts.back()->createCase( expr::makeSwitchCase( std::make_unique< expr::Literal >( *stmt->getCaseExpr()->getLabel() ) ) );
		}
		else
		{
			cont = m_switchStmts.back()->createDefault();
		}

		auto save = m_result;
		m_result = cont;
		visitContainerStmt( stmt );
		m_result = save;
	}

	void StmtAdapter::visitSwitchStmt( stmt::Switch * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeSwitch( expr::makeSwitchTest( ExprAdapter::submit( stmt->getTestExpr()->getValue()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) ) );
		m_switchStmts.push_back( cont.get() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
		m_switchStmts.pop_back();
	}

	void StmtAdapter::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		auto & var = stmt->getVariable();

		if ( isShaderInOut( var->getName(), m_type ) )
		{
			m_inputVars.emplace( 128u, var );
			m_inputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_inputVar )
					, uint32_t( m_inputMembers.size() )
					, makeIdent( var ) ) );
			m_outputVars.emplace( 128u, var );
			m_outputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_inputVar )
					, uint32_t( m_outputMembers.size() )
					, makeIdent( var ) ) );
		}
		else if ( isShaderInput( var->getName(), m_type ) )
		{
			m_inputVars.emplace( 128u, var );
			m_inputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_inputVar )
					, uint32_t( m_inputMembers.size() )
					, makeIdent( var ) ) );
		}
		else if ( isShaderOutput( var->getName(), m_type ) )
		{
			m_outputVars.emplace( 128u, var );
			m_outputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_outputVar )
					, uint32_t( m_outputMembers.size() )
					, makeIdent( var ) ) );
		}
		else
		{
			m_result->addStmt( stmt::makeVariableDecl( stmt->getVariable() ) );
		}
	}

	void StmtAdapter::visitWhileStmt( stmt::While * stmt )
	{
		auto cont = stmt::makeWhile( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );

		auto save = m_result;
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
		stmt::PreprocElif * cont;

		if ( !m_preprocIfDefs.back() )
		{
			cont = m_preprocIfStmts.back()->createElif( ExprAdapter::submit( preproc->getCtrlExpr()
				, m_config
				, m_linkedVars
				, m_inputMembers
				, m_outputMembers ) );
		}
		else
		{
			cont = m_preprocIfDefStmts.back()->createElif( ExprAdapter::submit( preproc->getCtrlExpr()
				, m_config
				, m_linkedVars
				, m_inputMembers
				, m_outputMembers ) );
		}

		auto save = m_result;
		m_result = cont;
		visitContainerStmt( preproc );
		m_result = save;
	}

	void StmtAdapter::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		stmt::PreprocElse * cont;

		if ( !m_preprocIfDefs.back() )
		{
			cont = m_preprocIfStmts.back()->createElse();
		}
		else
		{
			cont = m_preprocIfDefStmts.back()->createElse();
		}

		auto save = m_result;
		m_result = cont;
		visitContainerStmt( preproc );
		m_result = save;
	}

	void StmtAdapter::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
	}

	void StmtAdapter::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
	}

	void StmtAdapter::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		auto cont = stmt::makePreprocIf( ExprAdapter::submit( preproc->getCtrlExpr()
			, m_config
			, m_linkedVars
			, m_inputMembers
			, m_outputMembers ) );
		m_preprocIfStmts.push_back( cont.get() );
		m_preprocIfDefs.push_back( false );

		auto save = m_result;
		m_result = cont.get();
		visitContainerStmt( preproc );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
		m_preprocIfStmts.pop_back();
	}

	void StmtAdapter::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		auto cont = stmt::makePreprocIfDef( makeIdent( preproc->getIdentExpr()->getVariable() ) );
		m_preprocIfDefStmts.push_back( cont.get() );
		m_preprocIfDefs.push_back( true );

		auto save = m_result;
		m_result = cont.get();
		visitContainerStmt( preproc );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
		m_preprocIfDefStmts.pop_back();
	}

	void StmtAdapter::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
	}
}
