/*
See LICENSE file in root folder
*/
#include "GlslStmtAdapter.hpp"

#include "GlslExprAdapter.hpp"
#include "GlslHelpers.hpp"
#include "GlslTextureAccessFunctions.hpp"

#include <ShaderAST/Shader.hpp>

#include <algorithm>

namespace glsl
{
	namespace
	{
		void doEnableCoreExtension( ast::stmt::ContainerPtr & cont
			, GlslExtension const & extension
			, uint32_t shaderVersion )
		{
			if ( extension.reqVersion > shaderVersion )
			{
				cont->addStmt( ast::stmt::makePreprocExtension( extension.name
					, ast::stmt::PreprocExtension::ExtStatus::eRequired ) );
			}
		}

		void doEnableExtension( ast::stmt::ContainerPtr & cont
			, GlslExtension const & extension
			, uint32_t shaderVersion )
		{
			if ( extension.reqVersion <= shaderVersion )
			{
				cont->addStmt( ast::stmt::makePreprocExtension( extension.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}
		}

		ast::stmt::PerVertexDecl::Source getPerVertexSource( ast::ShaderStage stage
			, bool isInput )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				assert( !isInput );
				return ast::stmt::PerVertexDecl::eVertexOutput;
			case ast::ShaderStage::eTessellationControl:
				if ( isInput )
				{
					return ast::stmt::PerVertexDecl::eTessellationControlInput;
				}
				return ast::stmt::PerVertexDecl::eTessellationControlOutput;
			case ast::ShaderStage::eTessellationEvaluation:
				if ( isInput )
				{
					return ast::stmt::PerVertexDecl::eTessellationEvaluationInput;
				}
				return ast::stmt::PerVertexDecl::eTessellationEvaluationOutput;
			case ast::ShaderStage::eGeometry:
				if ( isInput )
				{
					return ast::stmt::PerVertexDecl::eGeometryInput;
				}
				return ast::stmt::PerVertexDecl::eGeometryOutput;
			case ast::ShaderStage::eFragment:
				AST_Failure( "Unexpected gl_PerVertex declaration in fragment shader." );
				return ast::stmt::PerVertexDecl::eVertexOutput;
			case ast::ShaderStage::eCompute:
				AST_Failure( "Unexpected gl_PerVertex declaration in fragment shader." );
				return ast::stmt::PerVertexDecl::eVertexOutput;
			default:
				AST_Failure( "Unexpected shader stage." );
				return ast::stmt::PerVertexDecl::eVertexOutput;
			}
		}

		ast::type::StructPtr getPerVertexBaseType( ast::type::TypesCache & cache
			, bool isInput )
		{
			auto result{ cache.getIOStruct( ast::type::MemoryLayout::eC
				, "gl_PerVertex"
				, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

			if ( !result->hasMember( ast::Builtin::ePosition ) )
			{
				result->declMember( ast::Builtin::ePosition
					, ast::type::Kind::eVec4F
					, ast::type::NotArray );
				result->declMember( ast::Builtin::ePointSize
					, ast::type::Kind::eFloat
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eClipDistance
					, ast::type::Kind::eFloat
					, 8u );
				result->declMember( ast::Builtin::eCullDistance
					, ast::type::Kind::eFloat
					, 8u );
			}

			return result;
		}

		ast::type::ArrayPtr getPerVertexArrayType( ast::type::TypesCache & cache
			, uint32_t count
			, bool isInput )
		{
			return cache.getArray( getPerVertexBaseType( cache, isInput )
				, count );
		}

		ast::type::TypePtr getPerVertexType( ast::type::TypesCache & cache
			, ast::ShaderStage stage
			, bool isInput
			, uint32_t maxPoint
			, ast::type::InputLayout inputLayout )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				assert( !isInput );
				return getPerVertexBaseType( cache
					, isInput );
			case ast::ShaderStage::eTessellationControl:
				if ( isInput )
				{
					return getPerVertexArrayType( cache
						, maxPoint
						, isInput );
				}
				return  getPerVertexArrayType( cache
					, 32u
					, isInput );
			case ast::ShaderStage::eTessellationEvaluation:
				if ( isInput )
				{
					return getPerVertexArrayType( cache
						, 32u
						, isInput );
				}
				return getPerVertexBaseType( cache
					, isInput );
			case ast::ShaderStage::eGeometry:
				if ( isInput )
				{
					return getPerVertexArrayType( cache
						, getArraySize( inputLayout )
						, isInput );
				}
				return getPerVertexBaseType( cache
					, isInput );
			case ast::ShaderStage::eFragment:
				AST_Failure( "Unexpected gl_PerVertex declaration in fragment shader." );
				return nullptr;
			case ast::ShaderStage::eCompute:
				AST_Failure( "Unexpected gl_PerVertex declaration in compute shader." );
				return nullptr;
			default:
				AST_Failure( "Unexpected shader stage." );
				return nullptr;
			}
		}
	}

	ast::stmt::ContainerPtr StmtAdapter::submit( ast::type::TypesCache & cache
		, ast::stmt::Container * container
		, AdaptationData & adaptationData )
	{
		auto result = ast::stmt::makeContainer();
		auto it = std::find_if ( container->begin()
			, container->end()
			, []( ast::stmt::StmtPtr const & lookup )
			{
				return lookup->getKind() == ast::stmt::Kind::ePreprocVersion;
			} );

		if ( it == container->end() )
		{
			result->addStmt( ast::stmt::makePreprocVersion( std::to_string( adaptationData.writerConfig.wantedVersion ) ) );
			doEnableCoreExtension( result, ARB_explicit_attrib_location, adaptationData.writerConfig.wantedVersion );
			doEnableCoreExtension( result, ARB_explicit_uniform_location, adaptationData.writerConfig.wantedVersion );
			doEnableCoreExtension( result, ARB_separate_shader_objects, adaptationData.writerConfig.wantedVersion );
			doEnableCoreExtension( result, ARB_shading_language_420pack, adaptationData.writerConfig.wantedVersion );
			doEnableExtension( result, KHR_vulkan_glsl, adaptationData.writerConfig.wantedVersion );

			if ( adaptationData.intrinsicsConfig.requiresCubeMapArray )
			{
				doEnableCoreExtension( result, ARB_texture_cube_map_array, adaptationData.writerConfig.wantedVersion );
			}

			if ( adaptationData.intrinsicsConfig.requiresTextureGather )
			{
				doEnableCoreExtension( result, ARB_texture_gather, adaptationData.writerConfig.wantedVersion );
			}

			if ( adaptationData.intrinsicsConfig.requiresFp16 )
			{
				result->addStmt( ast::stmt::makePreprocExtension( NV_gpu_shader5.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}

			if ( adaptationData.intrinsicsConfig.requiresAtomicFloat )
			{
				result->addStmt( ast::stmt::makePreprocExtension( NV_shader_atomic_float.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );

				if ( adaptationData.intrinsicsConfig.requiresAtomicFp16Vector )
				{
					result->addStmt( ast::stmt::makePreprocExtension( NV_shader_atomic_fp16_vector.name
						, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
				}
			}

			if ( isRayTraceStage( adaptationData.stage ) )
			{
				result->addStmt( ast::stmt::makePreprocExtension( EXT_ray_tracing.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}

			if ( adaptationData.intrinsicsConfig.requiresUint64 )
			{
				result->addStmt( ast::stmt::makePreprocExtension( EXT_shader_explicit_arithmetic_types_int64.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}

			if ( adaptationData.intrinsicsConfig.requiresBufferReference )
			{
				result->addStmt( ast::stmt::makePreprocExtension( EXT_buffer_reference2.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}

			if ( adaptationData.intrinsicsConfig.requiresNonUniform )
			{
				result->addStmt( ast::stmt::makePreprocExtension( EXT_nonuniform_qualifier.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}

			if ( adaptationData.intrinsicsConfig.requiresScalarLayout )
			{
				result->addStmt( ast::stmt::makePreprocExtension( EXT_scalar_block_layout.name
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}
		}

		StmtAdapter vis{ cache, adaptationData, result };
		container->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( ast::type::TypesCache & cache
		, AdaptationData & adaptationData
		, ast::stmt::ContainerPtr & result )
		: ast::StmtCloner{ result }
		, m_cache{ cache }
		, m_adaptationData{ adaptationData }
		, m_entryPointFinish{ ast::stmt::makeContainer() }
	{
	}
	
	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( m_cache
			, expr
			, m_adaptationData );
	}

	void StmtAdapter::visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )
	{
		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
			&& !m_adaptationData.writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_adaptationData.writerConfig.hasDescriptorSets )
		{
			ast::StmtCloner::visitConstantBufferDeclStmt( stmt );
		}
		else
		{
			auto save = m_current;
			auto cont = ast::stmt::makeConstantBufferDecl( stmt->getName()
				, stmt->getMemoryLayout()
				, stmt->getBindingPoint()
				, InvalidIndex );
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;
			m_current->addStmt( std::move( cont ) );
		}
	}

	void StmtAdapter::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getFlags() )
		{
			auto isEntryPoint = stmt->isEntryPoint();
			auto funcType = stmt->getType();

			for ( auto & param : *funcType )
			{
				auto type = param->getType();

				switch ( type->getKind() )
				{
				case ast::type::Kind::eFragmentInput:
					doProcess( param, static_cast< ast::type::FragmentInput const & >( *type ) );
					break;
				case ast::type::Kind::eGeometryOutput:
					doProcess( param, static_cast< ast::type::GeometryOutput const & >( *type ) );
					break;
				case ast::type::Kind::eGeometryInput:
					doProcess( param, static_cast< ast::type::GeometryInput const & >( *type ) );
					break;
				case ast::type::Kind::eTessellationInputPatch:
					doProcess( param, static_cast< ast::type::TessellationInputPatch const & >( *type ) );
					break;
				case ast::type::Kind::eTessellationControlInput:
					doProcess( param, static_cast< ast::type::TessellationControlInput const & >( *type ) );
					break;
				case ast::type::Kind::eTessellationEvaluationInput:
					doProcess( param, static_cast< ast::type::TessellationEvaluationInput const & >( *type ) );
					break;
				case ast::type::Kind::eComputeInput:
					doProcess( param, static_cast< ast::type::ComputeInput const & >( *type ) );
					break;
				case ast::type::Kind::eTessellationOutputPatch:
					doProcess( param, static_cast< ast::type::TessellationOutputPatch const & >( *type ) );
					break;
				case ast::type::Kind::eTessellationControlOutput:
					doProcess( param, static_cast< ast::type::TessellationControlOutput const & >( *type ) );
					break;
				default:
					{
						uint32_t arraySize = ast::type::NotArray;

						if ( type->getKind() == ast::type::Kind::eArray )
						{
							auto & arrayType = static_cast< ast::type::Array const & >( *type );
							type = arrayType.getType();
							arraySize = arrayType.getArraySize();
						}

						if ( isStructType( type ) )
						{
							auto structType = getStructType( type );

							if ( structType->isShaderInput() )
							{
								doProcessInput( param
									, std::static_pointer_cast< ast::type::IOStruct >( structType )
									, arraySize
									, isEntryPoint );
							}
							else if ( structType->isShaderOutput() )
							{
								doProcessOutput( param
									, std::static_pointer_cast< ast::type::IOStruct >( structType )
									, arraySize
									, isEntryPoint );
							}
						}
					}
					break;
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
		if ( m_adaptationData.writerConfig.hasDescriptorSets )
		{
			ast::StmtCloner::visitImageDeclStmt( stmt );
		}
		else
		{
			m_current->addStmt( ast::stmt::makeImageDecl( stmt->getVariable()
				, stmt->getBindingPoint()
				, InvalidIndex ) );
		}
	}

	void StmtAdapter::visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )
	{
		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
			&& !m_adaptationData.writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_adaptationData.writerConfig.vulkanGlsl )
		{
			ast::StmtCloner::visitPushConstantsBufferDeclStmt( stmt );
		}
		else
		{
			// PCB are not supported, implement them as UBO.
			auto save = m_current;
			auto cont = ast::stmt::makeConstantBufferDecl( stmt->getName()
				, stmt->getMemoryLayout()
				, InvalidIndex
				, InvalidIndex );
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;
			m_current->addStmt( std::move( cont ) );
		}
	}

	void StmtAdapter::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		if ( m_adaptationData.writerConfig.hasDescriptorSets )
		{
			ast::StmtCloner::visitSampledImageDeclStmt( stmt );
		}
		else
		{
			m_current->addStmt( ast::stmt::makeSampledImageDecl( stmt->getVariable()
				, stmt->getBindingPoint()
				, InvalidIndex ) );
		}
	}

	void StmtAdapter::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
			&& !m_adaptationData.writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_adaptationData.writerConfig.hasDescriptorSets )
		{
			ast::StmtCloner::visitShaderBufferDeclStmt( stmt );
		}
		else
		{
			auto save = m_current;
			auto cont = ast::stmt::makeShaderBufferDecl( stmt->getVariable()
				, stmt->getBindingPoint()
				, InvalidIndex );
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;
			m_current->addStmt( std::move( cont ) );
		}
	}

	void StmtAdapter::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
			&& !m_adaptationData.writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_adaptationData.writerConfig.hasDescriptorSets )
		{
			ast::StmtCloner::visitShaderStructBufferDeclStmt( stmt );
		}
		else
		{
			m_current->addStmt( ast::stmt::makeShaderStructBufferDecl( stmt->getSsboName()
				, stmt->getSsboInstance()
				, stmt->getData()
				, stmt->getBindingPoint()
				, InvalidIndex ) );
		}
	}

	void StmtAdapter::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
		m_result->addStmt( ast::stmt::makePreprocVersion( preproc->getName() ) );
		auto cont = ast::stmt::makeContainer();
		compileGlslTextureAccessFunctions( cont.get(), m_adaptationData.intrinsicsConfig );

		if ( !cont->empty() )
		{
			m_result->addStmt( std::move( cont ) );
		}
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::FragmentInput const & fragType )
	{
		auto type = fragType.getType();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, ast::type::NotArray
				, true );
		}

		m_current->addStmt( ast::stmt::makeFragmentLayout( type
			, fragType.getOrigin()
			, fragType.getCenter() ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType )
	{
		auto type = geomType.getType();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderOutput() );
			doProcessOutput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, ast::type::NotArray
				, true );
		}

		m_current->addStmt( ast::stmt::makeOutputGeometryLayout( type
			, geomType.getLayout()
			, geomType.getCount() ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::GeometryInput const & geomType )
	{
		auto type = geomType.getType();
		m_inputLayout = geomType.getLayout();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, getArraySize( geomType.getLayout() )
				, true );
		}

		m_current->addStmt( ast::stmt::makeInputGeometryLayout( type
			, geomType.getLayout() ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TessellationControlOutput const & tessType )
	{
		auto type = tessType.getType();
		uint32_t arraySize = tessType.getOutputVertices();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderOutput() );
			doProcessOutput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, arraySize
				, true );
		}

		m_current->addStmt( ast::stmt::makeOutputTessellationControlLayout( type
			, tessType.getDomain()
			, tessType.getPartitioning()
			, tessType.getTopology()
			, tessType.getOrder()
			, tessType.getOutputVertices() ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TessellationInputPatch const & patchType )
	{
		if ( isStructType( patchType.getType() ) )
		{
			auto structType = getStructType( patchType.getType() );
			auto flags = structType->getFlag();
			auto outStructType = std::make_shared< ast::type::IOStruct >( patchType.getCache()
				, structType->getMemoryLayout()
				, structType->getName() + "Repl"
				, ast::var::Flag( flags ) );
			auto outBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getCache()
				, structType->getMemoryLayout()
				, structType->getName() + "Builtins"
				, ast::var::Flag::eShaderInput );
			auto othersVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Others" }
				, ast::type::makeTessellationInputPatchType( outStructType
					, patchType.getDomain()
					, patchType.getLocation() )
				, var->getFlags() );
			auto builtinsVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Builtins" }
				, outBuiltinsType );
			auto & io = m_adaptationData.inputs;

			for ( auto & mbr : *structType )
			{
				auto name = ( mbr.builtin != ast::Builtin::eNone
					? "gl_" + getName( mbr.builtin )
					: mbr.name );

				if ( mbr.builtin == ast::Builtin::eNone )
				{
					outStructType->declMember( mbr.name
						, mbr.type
						, mbr.location );
				}
				else
				{
					outBuiltinsType->declMember( mbr.builtin
						, getNonArrayType( mbr.type )->getKind()
						, getArraySize( mbr.type )
						, ast::type::Struct::InvalidLocation );
					auto typeIt = io.vars.emplace( outBuiltinsType, ast::var::VariableList{} ).first;
					auto it = std::find_if( typeIt->second.begin()
						, typeIt->second.end()
						, [&name]( ast::var::VariablePtr const & lookup )
						{
							return name == lookup->getName();
						} );

					if ( it == typeIt->second.end() )
					{
						auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, name }
							, mbr.type
							, ( outBuiltinsType->getFlag()
								| ast::var::Flag::eBuiltin ) );
						typeIt->second.emplace_back( mbrVar );
					}
				}
			}

			if ( !outStructType->empty() )
			{
				io.othersStructs.emplace( structType, othersVar );
				m_current->addStmt( ast::stmt::makeStructureDecl( outStructType ) );
				m_current->addStmt( ast::stmt::makeInOutVariableDecl( othersVar
					, patchType.getLocation() ) );
				io.setMainVar( var );
			}

			if ( !outBuiltinsType->empty() )
			{
				io.builtinsStructs.emplace( structType, std::make_pair( outBuiltinsType, uint32_t( outStructType->size() ) ) );
			}
		}
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TessellationOutputPatch const & patchType )
	{
		if ( isStructType( patchType.getType() ) )
		{
			auto structType = getStructType( patchType.getType() );
			auto flags = structType->getFlag();
			auto outStructType = std::make_shared< ast::type::IOStruct >( patchType.getCache()
				, structType->getMemoryLayout()
				, structType->getName() + "Repl"
				, ast::var::Flag( flags ) );
			auto outBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getCache()
				, structType->getMemoryLayout()
				, structType->getName() + "Builtins"
				, ast::var::Flag::eShaderOutput );
			auto othersVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Others" }
				, ast::type::makeTessellationOutputPatchType( outStructType
					, patchType.getLocation() )
				, var->getFlags() );
			auto builtinsVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Builtins" }
				, outBuiltinsType );
			auto & io = m_adaptationData.outputs;

			for ( auto & mbr : *structType )
			{
				auto name = ( mbr.builtin != ast::Builtin::eNone
					? "gl_" + getName( mbr.builtin )
					: mbr.name );

				if ( mbr.builtin == ast::Builtin::eNone )
				{
					outStructType->declMember( mbr.name
						, mbr.type
						, mbr.location );
				}
				else
				{
					outBuiltinsType->declMember( mbr.builtin
						, getNonArrayType( mbr.type )->getKind()
						, getArraySize( mbr.type )
						, ast::type::Struct::InvalidLocation );
					auto typeIt = io.vars.emplace( outBuiltinsType, ast::var::VariableList{} ).first;
					auto it = std::find_if( typeIt->second.begin()
						, typeIt->second.end()
						, [&name]( ast::var::VariablePtr const & lookup )
						{
							return name == lookup->getName();
						} );

					if ( it == typeIt->second.end() )
					{
						auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, name }
							, mbr.type
							, ( outBuiltinsType->getFlag()
								| ast::var::Flag::eBuiltin ) );
						typeIt->second.emplace_back( mbrVar );
					}
				}
			}

			if ( !outStructType->empty() )
			{
				io.othersStructs.emplace( structType, othersVar );
				m_current->addStmt( ast::stmt::makeStructureDecl( outStructType ) );
				m_current->addStmt( ast::stmt::makeInOutVariableDecl( othersVar
					, patchType.getLocation() ) );
				io.setMainVar( var );
			}

			if ( !outBuiltinsType->empty() )
			{
				io.builtinsStructs.emplace( structType, std::make_pair( outBuiltinsType, uint32_t( outStructType->size() ) ) );
			}
		}
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TessellationControlInput const & tessType )
	{
		auto type = tessType.getType();
		m_maxPoint = tessType.getInputVertices();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, 32u
				, true );
		}
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TessellationEvaluationInput const & tessType )
	{
		auto type = tessType.getType();
		m_maxPoint = tessType.getInputVertices();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, 32u
				, true );
		}

		m_current->addStmt( ast::stmt::makeInputTessellationEvaluationLayout( tessType.getType()
			, tessType.getDomain()
			, tessType.getPartitioning()
			, tessType.getPrimitiveOrdering() ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::ComputeInput const & compType )
	{
		auto type = compType.getType();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderInput() );
			doProcessInput( var
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, ast::type::NotArray
				, true );
		}

		m_current->addStmt( ast::stmt::makeInputComputeLayout( compType.getType()
			, compType.getLocalSizeX()
			, compType.getLocalSizeY()
			, compType.getLocalSizeZ() ) );
	}

	void StmtAdapter::doProcessOutput( ast::var::VariablePtr var
		, ast::type::IOStructPtr structType
		, uint32_t arraySize
		, bool declVar )
	{
		doProcessIO( var
			, structType
			, arraySize
			, declVar
			, false
			, m_adaptationData.outputs );
	}

	void StmtAdapter::doProcessInput( ast::var::VariablePtr var
		, ast::type::IOStructPtr structType
		, uint32_t arraySize
		, bool declVar )
	{
		doProcessIO( var
			, structType
			, arraySize
			, declVar
			, true
			, m_adaptationData.inputs );
	}

	void StmtAdapter::doProcessIO( ast::var::VariablePtr var
		, ast::type::IOStructPtr structType
		, uint32_t arraySize
		, bool declVar
		, bool isInput
		, IOVars & io )
	{
		io.setMainVar( var );

		for ( auto & mbr : *structType )
		{
			if ( isPerVertex( mbr.builtin
				, m_adaptationData.writerConfig.shaderStage ) )
			{
				auto type = doDeclarePerVertex( isInput, io );
				std::string outerName;

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					if ( isInput )
					{
						outerName = "gl_in";
					}
					else
					{
						outerName = "gl_out";
					}
				}

				io.perVertex = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, outerName }
					, type
					, ( ast::var::Flag::eBuiltin
						| ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) );
			}
			else
			{
				auto name = ( mbr.builtin != ast::Builtin::eNone
					? "gl_" + getName( mbr.builtin )
					: "sdw" + ( isInput ? std::string{ "In" } : std::string{ "Out" } ) + "_" + mbr.name );
				auto typeIt = io.vars.emplace( structType, ast::var::VariableList{} ).first;
				auto it = std::find_if( typeIt->second.begin()
					, typeIt->second.end()
					, [&name]( ast::var::VariablePtr const & lookup )
					{
						return name == lookup->getName();
					} );

				if ( it == typeIt->second.end() )
				{
					auto mbrFlags = structType->getFlag()
						| ( mbr.builtin != ast::Builtin::eNone
							? ast::var::Flag::eBuiltin
							: ast::var::Flag::eNone );
					auto compType = getComponentType( mbr.type );

					if ( ( m_adaptationData.writerConfig.shaderStage != ast::ShaderStage::eVertex
							|| !isInput )
						&& ( isUnsignedIntType( compType )
							|| isSignedIntType( compType ) ) )
					{
						mbrFlags = mbrFlags | ast::var::Flag::eFlat;
					}

					auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, name }
						, ( arraySize == ast::type::NotArray
							? mbr.type
							: m_cache.getArray( mbr.type, arraySize ) )
						, mbrFlags );
					typeIt->second.emplace_back( mbrVar );

					if ( declVar && mbr.builtin == ast::Builtin::eNone )
					{
						m_current->addStmt( ast::stmt::makeInOutVariableDecl( mbrVar
							, mbr.location ) );
					}
				}
			}
		}
	}

	void StmtAdapter::doProcessEntryPoint( ast::stmt::FunctionDecl * stmt )
	{
		auto funcType = m_cache.getFunction( m_cache.getVoid(), {} );
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

	void StmtAdapter::doDeclareStruct( ast::type::StructPtr const & structType )
	{
		if ( m_declaredStructs.emplace( structType ).second )
		{
			m_current->addStmt( ast::stmt::makeStructureDecl( structType ) );
		}
	}

	ast::type::TypePtr StmtAdapter::doDeclarePerVertex( bool isInput
		, IOVars & io )
	{
		if ( ( isInput && !m_inPerVertex )
			|| ( !isInput && !m_outPerVertex ) )
		{
			auto type = getPerVertexType( m_cache
				, m_adaptationData.writerConfig.shaderStage
				, isInput
				, m_maxPoint
				, m_inputLayout );
			m_current->addStmt( ast::stmt::makePerVertexDecl( getPerVertexSource( m_adaptationData.writerConfig.shaderStage
					, isInput )
				, type ) );

			if ( isInput )
			{
				m_inPerVertex = type;
			}
			else
			{
				m_outPerVertex = type;
			}

			return type;
		}

		if ( isInput )
		{
			return m_inPerVertex;
		}

		return m_outPerVertex;
	}
}
