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
			, sdw::ShaderStage type )
		{
			return
				( type == sdw::ShaderStage::eCompute
					&& ( name == "gl_NumWorkGroups"
						|| name == "gl_WorkGroupID"
						|| name == "gl_LocalInvocationID"
						|| name == "gl_GlobalInvocationID"
						|| name == "gl_LocalInvocationIndex" ) )
				|| ( type == sdw::ShaderStage::eFragment
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
				|| ( type == sdw::ShaderStage::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveIDIn"
						|| name == "gl_InvocationID" ) )
				|| ( type == sdw::ShaderStage::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_InvocationID" ) )
				|| ( type == sdw::ShaderStage::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_TessCord"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == sdw::ShaderStage::eVertex
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
			, sdw::ShaderStage type )
		{
			return 
				( type == sdw::ShaderStage::eFragment
					&& ( name == "gl_FragDepth"
						|| name == "gl_SampleMask"
						|| name == "gl_FragStencilRef" ) )
				|| ( type == sdw::ShaderStage::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveID"
						|| name == "gl_Layer"
						|| name == "gl_ViewportIndex" ) )
				|| ( type == sdw::ShaderStage::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == sdw::ShaderStage::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance" ) )
				|| ( type == sdw::ShaderStage::eVertex
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance" ) );
		}

		bool isShaderInOut( std::string const & name
			, sdw::ShaderStage type )
		{
			return isShaderInput( name, type )
				&& isShaderOutput( name, type );
		}
	}

	ast::stmt::ContainerPtr StmtAdapter::submit( sdw::Shader const & shader
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig )
	{
		auto result = ast::stmt::makeContainer();
		StmtAdapter vis{ shader, intrinsicsConfig, writerConfig, result };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( sdw::Shader const & shader
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, ast::stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_intrinsicsConfig{ intrinsicsConfig }
		, m_writerConfig{ writerConfig }
		, m_shader{ shader }
		, m_cache{ shader.getTypesCache() }
	{
		auto cont = ast::stmt::makeContainer();
		m_adaptationData.mainInputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_MainInput" );
		m_adaptationData.globalInputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_Input" );
		cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.mainInputStruct ) );
		cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.globalInputStruct ) );
		m_adaptationData.inputVar = m_shader.registerName( "sdwInput", m_adaptationData.globalInputStruct, ast::var::Flag::eStatic );

		m_adaptationData.mainOutputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_MainOutput" );
		m_adaptationData.globalOutputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_Output" );
		cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.mainOutputStruct ) );
		cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.globalOutputStruct ) );
		m_adaptationData.outputVar = m_shader.registerName( "sdwOutput", m_adaptationData.globalOutputStruct, ast::var::Flag::eStatic );

		m_inOutDeclarations = cont.get();
		m_current->addStmt( std::move( cont ) );

		cont = ast::stmt::makeContainer();
		compileHlslIntrinsicFunctions( cont.get(), m_intrinsicsConfig );
		compileHlslTextureAccessFunctions( cont.get(), m_intrinsicsConfig );
		compileHlslImageAccessFunctions( cont.get(), m_intrinsicsConfig );
		m_intrinsics = cont.get();
		m_current->addStmt( std::move( cont ) );
	}

	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( m_cache
			, expr
			, m_intrinsicsConfig
			, m_writerConfig
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
			// Write function content into a temporary container
			auto save = m_current;
			auto cont = ast::stmt::makeContainer();
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;

			// Write SDW_main function
			rewriteShaderIOVars();
			ast::var::VariableList parameters;
			auto sdwMainCont = ast::stmt::makeFunctionDecl( m_cache.getFunction( stmt->getType()->getReturnType(), ast::var::VariableList{} )
				, "SDW_" + stmt->getName() );
			sdwMainCont->addStmt( std::move( cont ) );
			m_current->addStmt( std::move( sdwMainCont ) );

			// Write main function
			writeMain( stmt );
		}
		else
		{
			auto save = m_current;
			auto cont = rewriteFuncHeader( stmt );
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;
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
				, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.inputVar )
					, uint32_t( m_adaptationData.inputMembers.size() )
					, ast::expr::makeIdentifier( m_cache, var ) ) );
		}

		if ( var->isShaderOutput() )
		{
			m_adaptationData.outputVars.emplace( stmt->getLocation(), var );
			m_adaptationData.outputMembers.emplace( var
				, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar )
					, uint32_t( m_adaptationData.outputMembers.size() )
					, ast::expr::makeIdentifier( m_cache, var ) ) );
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
					, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar )
						, uint32_t( m_adaptationData.outputMembers.size() )
						, ast::expr::makeIdentifier( m_cache, outputVar ) ) );
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
			auto arrayType = std::static_pointer_cast< ast::type::Array >( stmt->getVariable()->getType() );
			auto realSampledType = std::static_pointer_cast< ast::type::SampledImage >( arrayType->getType() );
			imageType = m_cache.getArray( realSampledType->getImageType(), arrayType->getArraySize() );
			sampledType = m_cache.getArray( realSampledType, arrayType->getArraySize() );
			config = realSampledType->getConfig();

			if ( !m_intrinsicsConfig.requiresShadowSampler )
			{
				samplerType = m_cache.getArray( m_cache.getSampler( false ), arrayType->getArraySize() );
			}
			else
			{
				samplerType = m_cache.getArray( realSampledType->getSamplerType(), arrayType->getArraySize() );
			}
		}
		else
		{
			auto realSampledType = std::static_pointer_cast< ast::type::SampledImage >( stmt->getVariable()->getType() );
			imageType = realSampledType->getImageType();
			sampledType = realSampledType;
			config = realSampledType->getConfig();

			if ( !m_intrinsicsConfig.requiresShadowSampler )
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

		if ( isShaderInput( var->getName(), m_shader.getType() )
			|| isShaderOutput( var->getName(), m_shader.getType() ) )
		{
			if ( isShaderInput( var->getName(), m_shader.getType() ) )
			{
				m_adaptationData.inputVars.emplace( 128u, var );
				m_adaptationData.inputMembers.emplace( var
					, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.inputVar )
						, uint32_t( m_adaptationData.inputMembers.size() )
						, ast::expr::makeIdentifier( m_cache, var ) ) );
			}

			if ( isShaderOutput( var->getName(), m_shader.getType() ) )
			{
				m_adaptationData.outputVars.emplace( 128u, var );
				m_adaptationData.outputMembers.emplace( var
					, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar )
						, uint32_t( m_adaptationData.outputMembers.size() )
						, ast::expr::makeIdentifier( m_cache, var ) ) );
			}
		}
		else
		{
			m_current->addStmt( ast::stmt::makeVariableDecl( stmt->getVariable() ) );
		}
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
		std::string intInputName = "BLENDINDICES";
		std::string floatInputName = "TEXCOORD";

		for ( auto & input : m_adaptationData.inputVars )
		{
			if ( isSignedIntType( input.second->getType()->getKind() ) || isUnsignedIntType( input.second->getType()->getKind() ) )
			{
				m_adaptationData.mainInputStruct->declMember( input.second->getName()
					+ ": "
					+ getSemantic( input.second->getName()
						, intInputName
						, input.first )
					, input.second->getType() );
			}
			else
			{
				m_adaptationData.mainInputStruct->declMember( input.second->getName()
					+ ": "
					+ getSemantic( input.second->getName()
						, floatInputName
						, input.first )
					, input.second->getType() );
			}

			m_adaptationData.globalInputStruct->declMember( input.second->getName()
				, input.second->getType() );
		}

		if ( m_shader.getType() == sdw::ShaderStage::eFragment )
		{
			outputName = "SV_Target";
		}

		for ( auto & output : m_adaptationData.outputVars )
		{
			m_adaptationData.mainOutputStruct->declMember( output.second->getName()
				+ ": "
				+ getSemantic( output.second->getName()
					, outputName
					, output.first )
				, output.second->getType() );
			m_adaptationData.globalOutputStruct->declMember( output.second->getName()
				, output.second->getType() );
		}
	}

	void StmtAdapter::writeMain( ast::stmt::FunctionDecl * stmt )
	{
		assert( stmt->getType()->empty() );
		assert( stmt->getType()->getReturnType()->getKind() == ast::type::Kind::eVoid );
		ast::var::VariableList mainParameters;
		auto mainInputVar = m_shader.registerName( "sdwMainInput", m_adaptationData.mainInputStruct );
		auto mainOutputVar = m_shader.registerName( "sdwMainOutput", m_adaptationData.mainOutputStruct );

		if ( !m_adaptationData.mainInputStruct->empty() )
		{
			m_inOutDeclarations->addStmt( ast::stmt::makeVariableDecl( m_adaptationData.inputVar ) );
			mainParameters.emplace_back( mainInputVar );
		}

		ast::type::TypePtr mainRetType = m_cache.getVoid();

		if ( !m_adaptationData.mainOutputStruct->empty() )
		{
			m_inOutDeclarations->addStmt( ast::stmt::makeVariableDecl( m_adaptationData.outputVar ) );
			mainRetType = m_adaptationData.mainOutputStruct;
		}

		// Add compute layout
		if ( m_inputComputeLayout )
		{
			m_current->addStmt( ast::stmt::makeInputComputeLayout( m_inputComputeLayout->getWorkGroupsX()
				, m_inputComputeLayout->getWorkGroupsY()
				, m_inputComputeLayout->getWorkGroupsZ() ) );
		}

		auto cont = ast::stmt::makeFunctionDecl( m_cache.getFunction( mainRetType, mainParameters )
			, stmt->getName() );

		// Assign main inputs to global inputs, if needed
		if ( !m_adaptationData.mainInputStruct->empty() )
		{
			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( m_adaptationData.globalInputStruct
				, ast::expr::makeIdentifier( m_cache, m_adaptationData.inputVar )
				, ast::expr::makeIdentifier( m_cache, mainInputVar ) ) ) );
		}

		// Call SDW_main function.
		cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
			, ast::expr::makeIdentifier( m_cache
				, ast::var::makeFunction( m_cache.getFunction( m_cache.getVoid(), ast::var::VariableList{} )
					, "SDW_" + stmt->getName() ) )
			, ast::expr::ExprList{} ) ) );

		if ( !m_adaptationData.mainOutputStruct->empty() )
		{
			// Declare output.
			cont->addStmt( ast::stmt::makeVariableDecl( mainOutputVar ) );
			// Assign global outputs to main outputs
			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( m_adaptationData.mainOutputStruct
				, ast::expr::makeIdentifier( m_cache, mainOutputVar )
				, ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar ) ) ) );
			// Return output.
			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( m_cache, mainOutputVar ) ) );
		}

		m_current->addStmt( std::move( cont ) );
	}

	ast::stmt::FunctionDeclPtr StmtAdapter::rewriteFuncHeader( ast::stmt::FunctionDecl * stmt )
	{
		ast::var::VariableList params;
		// Split sampled textures in sampler + texture in parameters list.
		for ( auto & param : *stmt->getType() )
		{
			auto it = updateLinkedVars( param, m_adaptationData.linkedVars );

			if ( it != m_adaptationData.linkedVars.end() )
			{
				params.push_back( it->second.first );
				params.push_back( it->second.second );
			}
			else
			{
				params.push_back( param );
			}
		}

		return ast::stmt::makeFunctionDecl( m_cache.getFunction( stmt->getType()->getReturnType(), params )
			, stmt->getName() );
	}
}
