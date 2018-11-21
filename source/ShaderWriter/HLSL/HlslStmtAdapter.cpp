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

	stmt::ContainerPtr StmtAdapter::submit( Shader const & shader
		, IntrinsicsConfig const & config )
	{
		auto result = stmt::makeContainer();
		StmtAdapter vis{ shader, config, result };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( Shader const & shader
		, IntrinsicsConfig const & config
		, stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_config{ config }
		, m_shader{ shader }
	{
		m_adaptationData.inputStruct = type::makeStructType( type::MemoryLayout::eStd430, "HLSL_SDW_Input" );
		m_adaptationData.outputStruct = type::makeStructType( type::MemoryLayout::eStd430, "HLSL_SDW_Output" );
		m_current->addStmt( stmt::makeStructureDecl( m_adaptationData.inputStruct ) );
		m_current->addStmt( stmt::makeStructureDecl( m_adaptationData.outputStruct ) );

		auto cont = stmt::makeContainer();
		compileHlslIntrinsicFunctions( cont.get(), m_config );
		compileHlslTextureAccessFunctions( cont.get(), m_config );
		compileHlslImageAccessFunctions( cont.get(), m_config );
		m_intrinsics = cont.get();
		m_current->addStmt( std::move( cont ) );

		m_adaptationData.inputVar = m_shader.registerName( "sdwInput", m_adaptationData.inputStruct, var::Flag::eInputParam );
		m_adaptationData.outputVar = m_shader.registerName( "sdwOutput", m_adaptationData.outputStruct );
	}

	expr::ExprPtr StmtAdapter::doSubmit( expr::Expr * expr )
	{
		return ExprAdapter::submit( expr
			, m_config
			, m_adaptationData
			, m_intrinsics );
	}

	void StmtAdapter::linkVars( var::VariablePtr textureSampler
		, var::VariablePtr texture
		, var::VariablePtr sampler )
	{
		m_adaptationData.linkedVars.emplace( std::move( textureSampler )
			, std::make_pair( std::move( texture )
				, std::move( sampler ) ) );
	}

	void StmtAdapter::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		if ( stmt->getName() == "main" )
		{
			auto linkedVars = m_adaptationData.linkedVars;
			auto save = m_current;
			auto cont = stmt::makeContainer();
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;

			stmt::ContainerPtr funcCont;
			funcCont = rewriteMainHeader( stmt );
			funcCont->addStmt( std::move( cont ) );
			m_current = funcCont.get();
			rewriteMainFooter( stmt );
			m_current = save;
			m_adaptationData.linkedVars = linkedVars;
			m_current->addStmt( std::move( funcCont ) );
		}
		else
		{
			auto linkedVars = m_adaptationData.linkedVars;
			auto save = m_current;
			auto cont = rewriteFuncHeader( stmt );
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;
			m_adaptationData.linkedVars = linkedVars;
			m_current->addStmt( std::move( cont ) );
		}
	}

	void StmtAdapter::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		auto & var = stmt->getVariable();

		if ( var->isShaderInput() )
		{
			m_adaptationData.inputVars.emplace( stmt->getLocation(), var );
			m_adaptationData.inputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_adaptationData.inputVar )
					, uint32_t( m_adaptationData.inputMembers.size() )
					, makeIdent( var ) ) );
		}
		else if ( var->isShaderOutput() )
		{
			m_adaptationData.outputVars.emplace( stmt->getLocation(), var );
			m_adaptationData.outputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_adaptationData.outputVar )
					, uint32_t( m_adaptationData.outputMembers.size() )
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
				m_adaptationData.outputMembers.emplace( outputVar
					, expr::makeMbrSelect( makeIdent( m_adaptationData.outputVar )
						, uint32_t( m_adaptationData.outputMembers.size() )
						, makeIdent( outputVar ) ) );
				m_adaptationData.outputVars.emplace( index, outputVar );
			}
		}
	}

	void StmtAdapter::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		auto originalVar = stmt->getVariable();
		type::TypePtr sampledType;
		type::TypePtr samplerType;
		type::TypePtr imageType;
		type::ImageConfiguration config;

		if ( stmt->getVariable()->getType()->getKind() == type::Kind::eArray )
		{
			auto arrayType = std::static_pointer_cast< type::Array >( stmt->getVariable()->getType() );
			auto realSampledType = std::static_pointer_cast< type::SampledImage >( arrayType->getType() );
			imageType = type::makeArrayType( realSampledType->getImageType(), arrayType->getArraySize() );
			sampledType = type::makeArrayType( realSampledType, arrayType->getArraySize() );
			config = realSampledType->getConfig();

			if ( !m_config.requiresShadowSampler )
			{
				samplerType = type::makeArrayType( type::makeSamplerType( false ), arrayType->getArraySize() );
			}
			else
			{
				samplerType = type::makeArrayType( realSampledType->getSamplerType(), arrayType->getArraySize() );
			}
		}
		else
		{
			auto realSampledType = std::static_pointer_cast< type::SampledImage >( stmt->getVariable()->getType() );
			imageType = realSampledType->getImageType();
			sampledType = realSampledType;
			config = realSampledType->getConfig();

			if ( !m_config.requiresShadowSampler )
			{
				samplerType = type::makeSamplerType( false );
			}
			else
			{
				samplerType = realSampledType->getSamplerType();
			}
		}

		if ( config.dimension == type::ImageDim::eBuffer )
		{
			// Create Image
			auto textureVar = m_shader.registerImage( stmt->getVariable()->getName()
				, imageType
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() );
			textureVar->updateFlag( var::Flag::eImplicit );
			m_current->addStmt( stmt::makeImageDecl( textureVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );
		}
		else
		{
			// Create Image
			auto textureVar = m_shader.registerImage( stmt->getVariable()->getName() + "_texture"
				, imageType
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() );
			textureVar->updateFlag( var::Flag::eImplicit );
			m_current->addStmt( stmt::makeImageDecl( textureVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );

			// Create Sampler
			auto samplerVar = m_shader.registerSampler( stmt->getVariable()->getName() + "_sampler"
				, samplerType
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() );
			samplerVar->updateFlag( var::Flag::eImplicit );
			m_current->addStmt( stmt::makeSamplerDecl( samplerVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );

			// Link them
			linkVars( originalVar, textureVar, samplerVar );
		}
	}

	void StmtAdapter::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		m_adaptationData.ssboList.push_back( stmt->getSsboInstance() );
		auto save = m_current;
		auto cont = stmt::makeShaderBufferDecl( stmt->getSsboName()
			, stmt->getSsboInstance()
			, stmt->getData()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		auto & var = stmt->getVariable();

		if ( isShaderInOut( var->getName(), m_shader.getType() ) )
		{
			m_adaptationData.inputVars.emplace( 128u, var );
			m_adaptationData.inputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_adaptationData.inputVar )
					, uint32_t( m_adaptationData.inputMembers.size() )
					, makeIdent( var ) ) );
			m_adaptationData.outputVars.emplace( 128u, var );
			m_adaptationData.outputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_adaptationData.outputVar )
					, uint32_t( m_adaptationData.outputMembers.size() )
					, makeIdent( var ) ) );
		}
		else if ( isShaderInput( var->getName(), m_shader.getType() ) )
		{
			m_adaptationData.inputVars.emplace( 128u, var );
			m_adaptationData.inputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_adaptationData.inputVar )
					, uint32_t( m_adaptationData.inputMembers.size() )
					, makeIdent( var ) ) );
		}
		else if ( isShaderOutput( var->getName(), m_shader.getType() ) )
		{
			m_adaptationData.outputVars.emplace( 128u, var );
			m_adaptationData.outputMembers.emplace( var
				, expr::makeMbrSelect( makeIdent( m_adaptationData.outputVar )
					, uint32_t( m_adaptationData.outputMembers.size() )
					, makeIdent( var ) ) );
		}
		else
		{
			m_current->addStmt( stmt::makeVariableDecl( stmt->getVariable() ) );
		}
	}

	void StmtAdapter::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		if ( preproc->getExpr() )
		{
			auto var = m_shader.getVar( preproc->getName(), preproc->getExpr()->getType() );

			if ( var )
			{
				var->updateFlag( var::Flag::eConstant );

				if ( preproc->getExpr()->getKind() == expr::Kind::eAggrInit )
				{
					expr::ExprList initialisers;

					for ( auto & expr : static_cast< expr::AggrInit const & >( *preproc->getExpr() ).getInitialisers() )
					{
						initialisers.emplace_back( doSubmit( expr.get() ) );
					}

					m_current->addStmt( stmt::makeSimple( expr::makeAggrInit( makeIdent( var )
						, std::move( initialisers ) ) ) );
				}
				else
				{
					m_current->addStmt( stmt::makeSimple( expr::makeInit( makeIdent( var )
						, doSubmit( preproc->getExpr() ) ) ) );
				}
			}
		}
		else
		{
			m_current->addStmt( stmt::makePreprocDefine( preproc->getName(), doSubmit( preproc->getExpr() ) ) );
		}
	}

	void StmtAdapter::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
	}

	void StmtAdapter::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
	}

	void StmtAdapter::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
	}

	void StmtAdapter::rewriteShaderIOVars()
	{
		std::string outputName = "TEXCOORD";
		std::string inputName = "TEXCOORD";
		uint32_t index = 0u;

		for ( auto & input : m_adaptationData.inputVars )
		{
			m_adaptationData.inputStruct->declMember( input.second->getName()
				+ ": "
				+ getSemantic( input.second->getName()
					, inputName
					, index )
				, input.second->getType() );
		}

		index = 0u;

		if ( m_shader.getType() == ShaderType::eFragment )
		{
			outputName = "SV_Target";
		}
		else if ( m_shader.getType() == ShaderType::eCompute )
		{
		}

		for ( auto & output : m_adaptationData.outputVars )
		{
			m_adaptationData.outputStruct->declMember( output.second->getName()
				+ ": "
				+ getSemantic( output.second->getName()
					, outputName
					, index )
				, output.second->getType() );
		}
	}

	stmt::FunctionDeclPtr StmtAdapter::rewriteMainHeader( stmt::FunctionDecl * stmt )
	{
		rewriteShaderIOVars();
		assert( stmt->getParameters().empty() );
		assert( stmt->getRet()->getKind() == type::Kind::eVoid );
		var::VariableList parameters;

		if ( !m_adaptationData.inputStruct->empty() )
		{
			parameters.emplace_back( m_adaptationData.inputVar );
		}

		// Add input parameter
		if ( m_inputComputeLayout )
		{
			m_current->addStmt( stmt::makeInputComputeLayout( m_inputComputeLayout->getWorkGroupsX()
				, m_inputComputeLayout->getWorkGroupsY()
				, m_inputComputeLayout->getWorkGroupsZ() ) );
		}

		// Write output return if needed.
		stmt::FunctionDeclPtr result;

		if ( !m_adaptationData.outputStruct->empty() )
		{
			result = stmt::makeFunctionDecl( m_adaptationData.outputStruct
				, stmt->getName()
				, parameters );
			result->addStmt( stmt::makeVariableDecl( m_adaptationData.outputVar ) );
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
				auto sampledType = std::static_pointer_cast< type::SampledImage >( param->getType() );
				auto texture = var::makeVariable( sampledType->getImageType()
					, param->getName() + "_texture" );
				auto sampler = var::makeVariable( sampledType->getSamplerType()
					, param->getName() + "_sampler" );
				m_adaptationData.linkedVars.emplace( param, std::make_pair( texture, sampler ) );
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
			&& !m_adaptationData.outputStruct->empty() )
		{
			m_current->addStmt( stmt::makeReturn( expr::makeIdentifier( m_adaptationData.outputVar ) ) );
		}
	}
}
