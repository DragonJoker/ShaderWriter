/*
See LICENSE file in root folder
*/
#include "HlslStmtAdapter.hpp"

#include "HlslExprAdapter.hpp"
#include "HlslHelpers.hpp"
#include "HlslImageAccessFunctions.hpp"
#include "HlslIntrinsicFunctions.hpp"
#include "HlslTextureAccessFunctions.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

namespace hlsl
{
	namespace
	{
		bool isShaderInput( std::string const & name
			, ast::ShaderStage type )
		{
			return
				( type == ast::ShaderStage::eCompute
					&& ( name == "gl_NumWorkGroups"
						|| name == "gl_WorkGroupID"
						|| name == "gl_LocalInvocationID"
						|| name == "gl_GlobalInvocationID"
						|| name == "gl_LocalInvocationIndex" ) )
				|| ( type == ast::ShaderStage::eFragment
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
				|| ( type == ast::ShaderStage::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PrimitiveIDIn"
						|| name == "gl_InvocationID" ) )
				|| ( type == ast::ShaderStage::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_InvocationID" ) )
				|| ( type == ast::ShaderStage::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_TessCord"
						|| name == "gl_PatchVerticesIn"
						|| name == "gl_PrimitiveID"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == ast::ShaderStage::eVertex
					&& ( name == "gl_VertexID"
						|| name == "gl_VertexIndex"
						|| name == "gl_InstanceID"
						|| name == "gl_InstanceIndex"
						|| name == "gl_DrawID"
						|| name == "gl_BaseVertex"
						|| name == "gl_BaseInstance"
						|| name == "gl_TessLevelOuter" ) );
		}

		bool isOutput( ast::stmt::PerVertexDecl::Source source )
		{
			return source == ast::stmt::PerVertexDecl::Source::eGeometryOutput
				|| source == ast::stmt::PerVertexDecl::Source::eTessellationControlOutput
				|| source == ast::stmt::PerVertexDecl::Source::eTessellationEvaluationOutput
				|| source == ast::stmt::PerVertexDecl::Source::eVertexOutput;
		}

		bool isShaderOutput( std::string const & name
			, ast::ShaderStage type )
		{
			return 
				( type == ast::ShaderStage::eFragment
					&& ( name == "gl_FragDepth"
						|| name == "gl_SampleMask"
						|| name == "gl_FragStencilRef" ) )
				|| ( type == ast::ShaderStage::eGeometry
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_CullDistance"
						|| name == "gl_PrimitiveID"
						|| name == "gl_Layer"
						|| name == "gl_ViewportIndex" ) )
				|| ( type == ast::ShaderStage::eTessellationControl
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_CullDistance"
						|| name == "gl_TessLevelInner"
						|| name == "gl_TessLevelOuter" ) )
				|| ( type == ast::ShaderStage::eTessellationEvaluation
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance" ) )
				|| ( type == ast::ShaderStage::eVertex
					&& ( name == "gl_Position"
						|| name == "gl_PointSize"
						|| name == "gl_ClipDistance"
						|| name == "gl_CullDistance" ) );
		}

		ast::type::Kind getBuiltinHlslKind( std::string const & name
			, ast::type::Kind input )
		{
			ast::type::Kind result = input;

			if ( name == "gl_VertexID"
				|| name == "gl_InstanceID"
				|| name == "gl_DrawID"
				|| name == "gl_BaseVertex"
				|| name == "gl_BaseInstance"
				|| name == "gl_PatchVerticesIn"
				|| name == "gl_PrimitiveID"
				|| name == "gl_InvocationID"
				|| name == "gl_PrimitiveIDIn"
				|| name == "gl_SampleID"
				|| name == "gl_Layer"
				|| name == "gl_ViewportIndex" )
			{
				result = ast::type::Kind::eUInt;
			}

			return result;
		}
	}

	ast::stmt::ContainerPtr StmtAdapter::submit( ast::Shader const & shader
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData )
	{
		auto result = ast::stmt::makeContainer();
		StmtAdapter vis{ shader, intrinsicsConfig, writerConfig, adaptationData, result };
		container->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( ast::Shader const & shader
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_intrinsicsConfig{ intrinsicsConfig }
		, m_writerConfig{ writerConfig }
		, m_adaptationData{ adaptationData }
		, m_shader{ shader }
		, m_cache{ shader.getTypesCache() }
	{
		auto cont = ast::stmt::makeContainer();
		m_adaptationData.mainInputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_MainInput" );
		m_adaptationData.mainOutputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_MainOutput" );
		cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.mainInputStruct ) );
		cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.mainOutputStruct ) );

		if ( shader.getType() != ast::ShaderStage::eGeometry )
		{
			m_adaptationData.globalInputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_Input" );
			m_adaptationData.globalOutputStruct = shader.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, "HLSL_SDW_Output" );
			cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.globalInputStruct ) );
			cont->addStmt( ast::stmt::makeStructureDecl( m_adaptationData.globalOutputStruct ) );

			m_adaptationData.inputVar = m_shader.registerName( "sdwInput"
				, m_adaptationData.globalInputStruct
				, ast::var::Flag::eStatic );
			m_adaptationData.outputVar = m_shader.registerName( "sdwOutput"
				, m_adaptationData.globalOutputStruct
				, ast::var::Flag::eStatic );
		}
		else
		{
			m_adaptationData.outputVar = m_shader.registerName( "sdwOutput"
				, m_adaptationData.mainOutputStruct
				, ast::var::Flag::eShaderOutput );
		}

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
			, m_current
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
		auto funcType = stmt->getType();

		if ( stmt->getName() == "main" )
		{
			if ( m_shader.getType() == ast::ShaderStage::eGeometry )
			{
				assert( !funcType->empty() );

				for ( auto & param : *funcType )
				{
					auto type = param->getType();

					if ( type->getKind() == ast::type::Kind::eGeometryInput )
					{
						registerGeometryInput( param, static_cast< ast::type::GeometryInput const & >( *type ) );
					}
					else if ( type->getKind() == ast::type::Kind::eGeometryOutput )
					{
						registerGeometryOutput( param, static_cast< ast::type::GeometryOutput const & >( *type ) );
					}
				}

				ast::var::VariableList parameters;
				parameters.push_back( m_adaptationData.inputVar );
				parameters.push_back( m_adaptationData.mainOutputVar );
				auto cont = ast::stmt::makeFunctionDecl( m_cache.getFunction( stmt->getType()->getReturnType(), parameters )
					, stmt->getName() );
				auto save = m_current;
				m_current = cont.get();
				m_current->addStmt( ast::stmt::makeVariableDecl( m_adaptationData.outputVar ) );
				visitContainerStmt( stmt );
				m_current = save;

				m_current->addStmt( std::move( cont ) );
			}
			else
			{
				// Write function content into a temporary container
				auto save = m_current;
				auto cont = ast::stmt::makeContainer();
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;

				// Write SDW_main function
				rewriteShaderIOVars();
				auto sdwMainCont = ast::stmt::makeFunctionDecl( m_cache.getFunction( stmt->getType()->getReturnType(), ast::var::VariableList{} )
					, "SDW_" + stmt->getName() );
				sdwMainCont->addStmt( std::move( cont ) );
				m_current->addStmt( std::move( sdwMainCont ) );

				// Write main function
				writeMain( stmt );
			}
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
			auto index = uint32_t( m_adaptationData.inputMembers.size() );
			m_adaptationData.addPendingInput( var, index );

			if ( m_shader.getType() != ast::ShaderStage::eGeometry )
			{
				m_adaptationData.processPendingInput( var );
			}
		}

		if ( var->isShaderOutput() )
		{
			auto index = uint32_t( m_adaptationData.outputMembers.size() );
			m_adaptationData.addPendingOutput( var, index );

			if ( m_shader.getType() != ast::ShaderStage::eGeometry )
			{
				m_adaptationData.processPendingOutput( var );
			}
		}
	}

	void StmtAdapter::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		m_inputComputeLayout = stmt;
	}

	void StmtAdapter::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
	}

	void StmtAdapter::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
		auto index = 0u;
		auto type = getNonArrayType( stmt->getType() );
		assert( type->getKind() == ast::type::Kind::eStruct );

		for ( auto & member : static_cast< ast::type::Struct const & >( *type ) )
		{
			auto var = ( m_shader.hasVar( member.name )
				? m_shader.getVar( member.name, member.type )
				: m_shader.registerName( member.name, member.type, ast::var::Flag::eBuiltin ) );

			if ( isOutput( stmt->getSource() ) )
			{
				m_adaptationData.addPendingOutput( var, index++ );
			}
			else
			{
				m_adaptationData.addPendingInput( var, index++ );
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

		if ( originalVar->getType()->getKind() == ast::type::Kind::eArray )
		{
			auto arrayType = std::static_pointer_cast< ast::type::Array >( originalVar->getType() );
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
			auto realSampledType = std::static_pointer_cast< ast::type::SampledImage >( originalVar->getType() );
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
			auto textureVar = m_shader.registerImage( originalVar->getName()
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
			auto textureVar = m_shader.registerImage( originalVar->getName() + "_texture"
				, imageType
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() );
			textureVar->updateFlag( ast::var::Flag::eImplicit );
			m_current->addStmt( ast::stmt::makeImageDecl( textureVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );

			// Create Sampler
			auto samplerVar = m_shader.registerSampler( originalVar->getName() + "_sampler"
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
		auto ssboVar = stmt->getVariable();
		m_adaptationData.ssboList.push_back( ssboVar );
		m_current->addStmt( ast::stmt::makeStructureDecl( stmt->getType() ) );
		m_current->addStmt( ast::stmt::makeShaderStructBufferDecl( stmt->getSsboName()
			, ast::var::makeVariable( ++m_adaptationData.nextVarId
				, ssboVar->getType()
				, ssboVar->getName() + "Inst" )
			, ssboVar
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
		uint32_t mbrIndex = 0u;

		for ( auto & curStmt : *stmt )
		{
			assert( curStmt->getKind() == ast::stmt::Kind::eVariableDecl );
			auto var = static_cast< ast::stmt::VariableDecl const & >( *curStmt ).getVariable();
			m_adaptationData.replacedVars.emplace( var
				, ast::expr::makeMbrSelect( ast::expr::makeArrayAccess( ssboVar->getType()
						, ast::expr::makeIdentifier( m_cache
							, ast::var::makeVariable( ++m_adaptationData.nextVarId
								, m_cache.getArray( ssboVar->getType(), 1u )
								, ssboVar->getName() ) )
						, ast::expr::makeLiteral( m_cache, 0 ) )
					, mbrIndex++
					, uint32_t( ast::var::Flag::eUniform ) ) );
		}
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
				auto hlslKind = getBuiltinHlslKind( var->getName()
					, var->getType()->getKind() );

				if ( hlslKind != var->getType()->getKind() )
				{
					var = m_shader.registerName( var->getName()
						, m_cache.getBasicType( hlslKind ) );
				}

				auto index = uint32_t( 128u + m_adaptationData.inputVars.size() );
				m_adaptationData.addPendingInput( var, index );
				m_adaptationData.inputVars.emplace( index, var );
				m_adaptationData.inputMembers.emplace( var
					, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.inputVar )
						, uint32_t( m_adaptationData.inputMembers.size() )
						, var->getFlags() ) );
			}

			if ( isShaderOutput( var->getName(), m_shader.getType() ) )
			{
				auto hlslKind = getBuiltinHlslKind( var->getName()
					, var->getType()->getKind() );

				if ( hlslKind != var->getType()->getKind() )
				{
					var = m_shader.registerName( var->getName()
						, m_cache.getBasicType( hlslKind ) );
				}

				auto index = uint32_t( 128u + m_adaptationData.outputVars.size() );
				m_adaptationData.addPendingOutput( var, index );
				m_adaptationData.outputVars.emplace( index, var );
				m_adaptationData.outputMembers.emplace( var
					, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar )
						, uint32_t( m_adaptationData.outputMembers.size() )
						, var->getFlags() ) );
			}
		}
		else
		{
			m_current->addStmt( ast::stmt::makeVariableDecl( stmt->getVariable() ) );
		}
	}

	void StmtAdapter::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
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
		Semantic intSem = { "BLENDINDICES", 0u };
		Semantic fltSem = { "TEXCOORD", 0u };
		Semantic * pintSem = &intSem;
		Semantic * pfltSem = &fltSem;

		if ( m_adaptationData.globalInputStruct )
		{
			for ( auto & input : m_adaptationData.inputVars )
			{
				auto var = input.second;
				addInputMember( m_adaptationData.mainInputStruct
					, var->getName()
					, var->getType()
					, *pintSem
					, *pfltSem );

				if ( !m_adaptationData.globalInputStruct->hasMember( var->getName() ) )
				{
					m_adaptationData.globalInputStruct->declMember( var->getName()
						, var->getType() );
				}
				else
				{
					assert( var->getType()->getKind() == m_adaptationData.globalInputStruct->getMember( var->getName() ).type->getKind() );
				}
			}
		}

		if ( m_adaptationData.globalOutputStruct )
		{
			if ( m_shader.getType() == ast::ShaderStage::eFragment )
			{
				intSem.name = "SV_Target";
				pfltSem = &intSem;
			}

			intSem.index = 0u;
			fltSem.index = 0u;

			for ( auto & output : m_adaptationData.outputVars )
			{
				auto var = output.second;
				addOutputMember( m_adaptationData.mainOutputStruct
					, var->getName()
					, var->getType()
					, *pintSem
					, *pfltSem );
			}
		}
	}

	void StmtAdapter::writeMain( ast::stmt::FunctionDecl * stmt )
	{
		assert( stmt->getType()->empty() );
		assert( stmt->getType()->getReturnType()->getKind() == ast::type::Kind::eVoid );
		ast::var::VariableList mainParameters;
		auto mainInputVar = m_shader.registerName( "sdwMainInput", m_adaptationData.mainInputStruct );
		auto mainOutputVar = m_shader.registerName( "sdwMainOutput", m_adaptationData.mainOutputStruct );

		if ( !m_adaptationData.mainInputStruct->empty()
			&& m_adaptationData.inputVar )
		{
			m_inOutDeclarations->addStmt( ast::stmt::makeVariableDecl( m_adaptationData.inputVar ) );
			mainParameters.emplace_back( mainInputVar );
		}

		ast::type::TypePtr mainRetType = m_cache.getVoid();

		if ( !m_adaptationData.mainOutputStruct->empty()
			&& m_adaptationData.outputVar )
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
		if ( !m_adaptationData.mainInputStruct->empty()
			&& m_adaptationData.inputVar )
		{
			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( m_adaptationData.globalInputStruct
				, ast::expr::makeIdentifier( m_cache, m_adaptationData.inputVar )
				, ast::expr::makeIdentifier( m_cache, mainInputVar ) ) ) );
		}

		// Call SDW_main function.
		cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
			, ast::expr::makeIdentifier( m_cache
				, ast::var::makeFunction( ++m_adaptationData.nextVarId
					, m_cache.getFunction( m_cache.getVoid(), ast::var::VariableList{} )
					, "SDW_" + stmt->getName() ) )
			, ast::expr::ExprList{} ) ) );

		if ( !m_adaptationData.mainOutputStruct->empty()
			&& m_adaptationData.outputVar )
		{
			// Declare output.
			cont->addStmt( ast::stmt::makeVariableDecl( mainOutputVar ) );

			if ( m_shader.getType() == ast::ShaderStage::eVertex )
			{
				// Assign global outputs to main outputs, member wise
				auto inIndex = 0u;
				auto outIndex = 0u;

				for ( auto & var : m_adaptationData.outputVars )
				{
					if ( var.second->getName() == "gl_ClipDistance" )
					{
						for ( uint32_t i = 0u; i < 4u; ++i )
						{
							cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( var.second->getType()
								, ast::expr::makeSwizzle( ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, mainOutputVar )
										, inIndex
										, 0u )
									, ast::expr::SwizzleKind::fromOffset( i ) )
								, ast::expr::makeArrayAccess( m_cache.getFloat()
									, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar )
										, outIndex
										, 0u )
									, ast::expr::makeLiteral( m_cache, i ) ) ) ) );
						}

						++inIndex;

						for ( uint32_t i = 0u; i < 4u; ++i )
						{
							cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( var.second->getType()
								, ast::expr::makeSwizzle( ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, mainOutputVar )
										, inIndex
										, 0u )
									, ast::expr::SwizzleKind::fromOffset( i ) )
								, ast::expr::makeArrayAccess( m_cache.getFloat()
									, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar )
										, outIndex
										, 0u )
									, ast::expr::makeLiteral( m_cache, i + 4u ) ) ) ) );
						}

						++inIndex;
						++outIndex;
					}
					else if ( var.second->getName() == "gl_CullDistance" )
					{
					}
					else
					{
						cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( var.second->getType()
							, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, mainOutputVar )
								, inIndex
								, uint32_t( ast::var::Flag::eImplicit ) )
							, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar )
								, outIndex
								, uint32_t( ast::var::Flag::eImplicit ) ) ) ) );
						++inIndex;
						++outIndex;
					}
				}
			}
			else
			{
				// Assign global outputs to main outputs
				cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( m_adaptationData.mainOutputStruct
					, ast::expr::makeIdentifier( m_cache, mainOutputVar )
					, ast::expr::makeIdentifier( m_cache, m_adaptationData.outputVar ) ) ) );
			}
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
			auto it = updateLinkedVars( param
				, m_adaptationData.linkedVars
				, m_adaptationData.nextVarId );

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

	void StmtAdapter::registerGeometryInput( ast::var::VariablePtr var
		, ast::type::GeometryInput const & geomType )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			uint32_t index = 0u;

			for ( auto & mbr : static_cast< ast::type::Struct const & >( *type ) )
			{
				auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, mbr.name }
					, mbr.type
					, mbr.flag );
				m_adaptationData.addPendingInput( mbrVar, index++ );
			}
		}

		assert( !m_adaptationData.inputVar );
		m_adaptationData.inputVar = m_shader.registerName( "mainInput"
			, ast::type::makeGeometryInputType( m_adaptationData.mainInputStruct
				, geomType.layout )
			, ast::var::Flag::eInputParam | ast::var::Flag::eShaderInput );
		m_adaptationData.paramToMain.emplace( var, m_adaptationData.inputVar );
	}

	void StmtAdapter::registerGeometryOutput( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			uint32_t index = 0u;

			for ( auto & mbr : static_cast< ast::type::Struct const & >( *type ) )
			{
				auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, mbr.name }
					, mbr.type
					, mbr.flag );
				m_adaptationData.addPendingOutput( mbrVar, index++ );
			}
		}

		assert( !m_adaptationData.mainOutputVar );
		m_adaptationData.mainOutputVar = m_shader.registerName( "mainOutput"
			, ast::type::makeGeometryOutputType( m_adaptationData.mainOutputStruct
				, geomType.layout
				, geomType.count )
			, ast::var::Flag::eInputParam | ast::var::Flag::eOutputParam | ast::var::Flag::eShaderOutput );
		m_adaptationData.paramToMain.emplace( var, m_adaptationData.mainOutputVar );
	}
}
