/*
See LICENSE file in root folder
*/
#include "HlslStmtAdapter.hpp"

#include "HlslExprAdapter.hpp"
#include "HlslHelpers.hpp"
#include "HlslImageAccessFunctions.hpp"
#include "HlslIntrinsicFunctions.hpp"
#include "HlslTextureAccessFunctions.hpp"

#include <ShaderWriter/Shader.hpp>

#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

namespace hlsl
{
	namespace
	{
		bool isShaderInput( std::string const & name
			, sdw::ShaderType type )
		{
			return
				( type == sdw::ShaderType::eCompute
					&& ( name == "gl_NumWorkGroups"
						|| name == "gl_WorkGroupID"
						|| name == "gl_LocalInvocationID"
						|| name == "gl_GlobalInvocationID"
						|| name == "gl_LocalInvocationIndex" ) )
				|| ( type == sdw::ShaderType::eFragment
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
				|| ( type == sdw::ShaderType::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveIDIn"
						|| name == "gl_InvocationID" ) )
				|| ( type == sdw::ShaderType::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_InvocationID" ) )
				|| ( type == sdw::ShaderType::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_TessCord"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == sdw::ShaderType::eVertex
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
			, sdw::ShaderType type )
		{
			return 
				( type == sdw::ShaderType::eFragment
					&& ( name == "gl_FragDepth"
						|| name == "gl_SampleMask"
						|| name == "gl_FragStencilRef" ) )
				|| ( type == sdw::ShaderType::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveID"
						|| name == "gl_Layer"
						|| name == "gl_ViewportIndex" ) )
				|| ( type == sdw::ShaderType::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == sdw::ShaderType::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance" ) )
				|| ( type == sdw::ShaderType::eVertex
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance" ) );
		}

		bool isShaderInOut( std::string const & name
			, sdw::ShaderType type )
		{
			return isShaderInput( name, type )
				&& isShaderOutput( name, type );
		}
	}

	ast::stmt::ContainerPtr StmtAdapter::submit( sdw::Shader const & shader
		, IntrinsicsConfig const & config )
	{
		auto result = ast::stmt::makeContainer();
		StmtAdapter vis{ shader, config, result };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( sdw::Shader const & shader
		, IntrinsicsConfig const & config
		, ast::stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_config{ config }
		, m_shader{ shader }
		, m_cache{ shader.getTypesCache() }
	{
		m_adaptationData.inputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_Input" );
		m_adaptationData.outputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_Output" );
		m_current->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.inputStruct ) );
		m_current->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.outputStruct ) );

		auto cont = ast::stmt::makeContainer();
		compileHlslIntrinsicFunctions( cont.get(), m_config );
		compileHlslTextureAccessFunctions( cont.get(), m_config );
		compileHlslImageAccessFunctions( cont.get(), m_config );
		m_intrinsics = cont.get();
		m_current->addStmt( std::move( cont ) );

		m_adaptationData.inputVar = m_shader.registerName( "sdwInput", m_adaptationData.inputStruct, ast::var::Flag::eInputParam );
		m_adaptationData.outputVar = m_shader.registerName( "sdwOutput", m_adaptationData.outputStruct );
	}

	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( m_cache
			, expr
			, m_config
			, m_adaptationData
			, m_intrinsics );
	}

	void StmtAdapter::linkVars( ast::var::VariablePtr textureSampler
		, ast::var::VariablePtr texture
		, ast::var::VariablePtr sampler )
	{
		m_adaptationData.linkedVars.emplace( std::move( textureSampler )
			, std::make_pair( std::move( texture )
				, std::move( sampler ) ) );
	}

	void StmtAdapter::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getName() == "main" )
		{
			auto linkedVars = m_adaptationData.linkedVars;
			auto save = m_current;
			auto cont = ast::stmt::makeContainer();
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;

			ast::stmt::ContainerPtr funcCont;
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

	void StmtAdapter::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		auto var = stmt->getVariable();

		if ( var->isShaderInput() )
		{
			m_adaptationData.inputVars.emplace( stmt->getLocation(), var );
			m_adaptationData.inputMembers.emplace( var
				, ast::expr::makeMbrSelect( sdw::makeIdent( m_adaptationData.inputVar )
					, uint32_t( m_adaptationData.inputMembers.size() )
					, sdw::makeIdent( var ) ) );
		}
		else if ( var->isShaderOutput() )
		{
			m_adaptationData.outputVars.emplace( stmt->getLocation(), var );
			m_adaptationData.outputMembers.emplace( var
				, ast::expr::makeMbrSelect( sdw::makeIdent( m_adaptationData.outputVar )
					, uint32_t( m_adaptationData.outputMembers.size() )
					, sdw::makeIdent( var ) ) );
		}
	}

	void StmtAdapter::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		m_inputComputeLayout = stmt;
	}

	void StmtAdapter::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		m_inputGeometryLayout = stmt;
	}

	void StmtAdapter::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		m_outputGeometryLayout = stmt;
	}

	void StmtAdapter::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
		auto index = 128u;

		for ( auto & member : *stmt->getType() )
		{
			if ( member.name == "gl_Position" )
			{
				auto outputVar = m_shader.getVar( member.name, member.type );
				m_adaptationData.outputMembers.emplace( outputVar
					, ast::expr::makeMbrSelect( sdw::makeIdent( m_adaptationData.outputVar )
						, uint32_t( m_adaptationData.outputMembers.size() )
						, sdw::makeIdent( outputVar ) ) );
				m_adaptationData.outputVars.emplace( index, outputVar );
			}
		}
	}

	void StmtAdapter::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		auto originalVar = stmt->getVariable();
		ast::type::TypePtr sampledType;
		ast::type::TypePtr samplerType;
		ast::type::TypePtr imageType;
		ast::type::ImageConfiguration config;

		if ( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eArray )
		{
			auto & cache = stmt->getVariable()->getType()->getCache();
			auto arrayType = std::static_pointer_cast< ast::type::Array >( stmt->getVariable()->getType() );
			auto realSampledType = std::static_pointer_cast< ast::type::SampledImage >( arrayType->getType() );
			imageType = cache.getArray( realSampledType->getImageType(), arrayType->getArraySize() );
			sampledType = cache.getArray( realSampledType, arrayType->getArraySize() );
			config = realSampledType->getConfig();

			if ( !m_config.requiresShadowSampler )
			{
				samplerType = cache.getArray( m_cache.getSampler( false ), arrayType->getArraySize() );
			}
			else
			{
				samplerType = cache.getArray( realSampledType->getSamplerType(), arrayType->getArraySize() );
			}
		}
		else
		{
			auto realSampledType = std::static_pointer_cast< ast::type::SampledImage >( stmt->getVariable()->getType() );
			imageType = realSampledType->getImageType();
			sampledType = realSampledType;
			config = realSampledType->getConfig();

			if ( !m_config.requiresShadowSampler )
			{
				samplerType = m_cache.getSampler( false );
			}
			else
			{
				samplerType = realSampledType->getSamplerType();
			}
		}

		if ( config.dimension == ast::type::ImageDim::eBuffer )
		{
			// Create Image
			auto textureVar = m_shader.registerImage( stmt->getVariable()->getName()
				, imageType
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() );
			textureVar->updateFlag( ast::var::Flag::eImplicit );
			m_current->addStmt( ast::stmt::makeImageDecl( textureVar
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
			textureVar->updateFlag( ast::var::Flag::eImplicit );
			m_current->addStmt( ast::stmt::makeImageDecl( textureVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );

			// Create Sampler
			auto samplerVar = m_shader.registerSampler( stmt->getVariable()->getName() + "_sampler"
				, samplerType
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() );
			samplerVar->updateFlag( ast::var::Flag::eImplicit );
			m_current->addStmt( ast::stmt::makeSamplerDecl( samplerVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );

			// Link them
			linkVars( originalVar, textureVar, samplerVar );
		}
	}

	void StmtAdapter::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		auto cont = ast::stmt::makeShaderBufferDecl( stmt->getSsboName()
			, stmt->getMemoryLayout()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		auto save = m_current;
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		m_adaptationData.ssboList.push_back( stmt->getSsboInstance() );
		m_current->addStmt( ast::stmt::makeShaderStructBufferDecl( stmt->getSsboName()
			, stmt->getSsboInstance()
			, stmt->getData()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtAdapter::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		auto var = stmt->getVariable();

		if ( isShaderInOut( var->getName(), m_shader.getType() ) )
		{
			m_adaptationData.inputVars.emplace( 128u, var );
			m_adaptationData.inputMembers.emplace( var
				, ast::expr::makeMbrSelect( sdw::makeIdent( m_adaptationData.inputVar )
					, uint32_t( m_adaptationData.inputMembers.size() )
					, sdw::makeIdent( var ) ) );
			m_adaptationData.outputVars.emplace( 128u, var );
			m_adaptationData.outputMembers.emplace( var
				, ast::expr::makeMbrSelect( sdw::makeIdent( m_adaptationData.outputVar )
					, uint32_t( m_adaptationData.outputMembers.size() )
					, sdw::makeIdent( var ) ) );
		}
		else if ( isShaderInput( var->getName(), m_shader.getType() ) )
		{
			m_adaptationData.inputVars.emplace( 128u, var );
			m_adaptationData.inputMembers.emplace( var
				, ast::expr::makeMbrSelect( sdw::makeIdent( m_adaptationData.inputVar )
					, uint32_t( m_adaptationData.inputMembers.size() )
					, sdw::makeIdent( var ) ) );
		}
		else if ( isShaderOutput( var->getName(), m_shader.getType() ) )
		{
			m_adaptationData.outputVars.emplace( 128u, var );
			m_adaptationData.outputMembers.emplace( var
				, ast::expr::makeMbrSelect( sdw::makeIdent( m_adaptationData.outputVar )
					, uint32_t( m_adaptationData.outputMembers.size() )
					, sdw::makeIdent( var ) ) );
		}
		else
		{
			m_current->addStmt( ast::stmt::makeVariableDecl( stmt->getVariable() ) );
		}
	}

	void StmtAdapter::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		if ( preproc->getExpr() )
		{
			auto var = m_shader.getVar( preproc->getName(), preproc->getExpr()->getType() );

			if ( var )
			{
				var->updateFlag( ast::var::Flag::eConstant );

				if ( preproc->getExpr()->getKind() == ast::expr::Kind::eAggrInit )
				{
					ast::expr::ExprList initialisers;

					for ( auto & expr : static_cast< ast::expr::AggrInit const & >( *preproc->getExpr() ).getInitialisers() )
					{
						initialisers.emplace_back( doSubmit( expr.get() ) );
					}

					m_current->addStmt( ast::stmt::makeSimple( ast::expr::makeAggrInit( sdw::makeIdent( var )
						, std::move( initialisers ) ) ) );
				}
				else
				{
					m_current->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( sdw::makeIdent( var )
						, doSubmit( preproc->getExpr() ) ) ) );
				}
			}
		}
		else
		{
			m_current->addStmt( ast::stmt::makePreprocDefine( preproc->getName(), doSubmit( preproc->getExpr() ) ) );
		}
	}

	void StmtAdapter::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
	}

	void StmtAdapter::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
	}

	void StmtAdapter::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
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

		if ( m_shader.getType() == sdw::ShaderType::eFragment )
		{
			outputName = "SV_Target";
		}
		else if ( m_shader.getType() == sdw::ShaderType::eCompute )
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

	ast::stmt::FunctionDeclPtr StmtAdapter::rewriteMainHeader( ast::stmt::FunctionDecl * stmt )
	{
		rewriteShaderIOVars();
		assert( stmt->getParameters().empty() );
		assert( stmt->getRet()->getKind() == ast::type::Kind::eVoid );
		ast::var::VariableList parameters;

		if ( !m_adaptationData.inputStruct->empty() )
		{
			parameters.emplace_back( m_adaptationData.inputVar );
		}

		// Add input parameter
		if ( m_inputComputeLayout )
		{
			m_current->addStmt( ast::stmt::makeInputComputeLayout( m_inputComputeLayout->getWorkGroupsX()
				, m_inputComputeLayout->getWorkGroupsY()
				, m_inputComputeLayout->getWorkGroupsZ() ) );
		}

		// Write output return if needed.
		ast::stmt::FunctionDeclPtr result;

		if ( !m_adaptationData.outputStruct->empty() )
		{
			result = ast::stmt::makeFunctionDecl( m_adaptationData.outputStruct
				, stmt->getName()
				, parameters );
			result->addStmt( ast::stmt::makeVariableDecl( m_adaptationData.outputVar ) );
		}
		else
		{
			result = ast::stmt::makeFunctionDecl( stmt->getRet()
				, stmt->getName()
				, parameters );
		}

		return result;
	}

	ast::stmt::FunctionDeclPtr StmtAdapter::rewriteFuncHeader( ast::stmt::FunctionDecl * stmt )
	{
		ast::var::VariableList params;
		// Split sampled textures in sampler + texture in parameters list.
		for ( auto & param : stmt->getParameters() )
		{
			if ( isSampledImageType( param->getType()->getKind() ) )
			{
				auto sampledType = std::static_pointer_cast< ast::type::SampledImage >( param->getType() );
				auto texture = ast::var::makeVariable( sampledType->getImageType()
					, param->getName() + "_texture" );
				auto sampler = ast::var::makeVariable( sampledType->getSamplerType()
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

		return ast::stmt::makeFunctionDecl( stmt->getRet()
			, stmt->getName()
			, params );
	}

	void StmtAdapter::rewriteMainFooter( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getName() == "main"
			&& !m_adaptationData.outputStruct->empty() )
		{
			m_current->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( m_adaptationData.outputVar ) ) );
		}
	}
}
