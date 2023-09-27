/*
See LICENSE file in root folder
*/
#include "GlslStmtAdapter.hpp"

#include "GlslExprAdapter.hpp"
#include "GlslHelpers.hpp"
#include "GlslCombinedImageAccessFunctions.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Type/TypeCache.hpp>

#include <algorithm>

namespace glsl
{
	namespace
	{
		void doEnableExtension( ast::stmt::ContainerPtr & cont
			, GlslExtension const & extension
			, uint32_t shaderVersion )
		{
			if ( extension.coreVersion > shaderVersion )
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
			case ast::ShaderStage::eMeshNV:
			case ast::ShaderStage::eMesh:
				return ast::stmt::PerVertexDecl::eMeshOutput;
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

		ast::type::StructPtr getPerVertexBaseType( ast::type::TypesCache & typesCache
			, bool isInput )
		{
			auto result{ typesCache.getIOStruct( ast::type::MemoryLayout::eC
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

		ast::type::ArrayPtr getPerVertexArrayType( ast::type::TypesCache & typesCache
			, uint32_t count
			, bool isInput )
		{
			return typesCache.getArray( getPerVertexBaseType( typesCache, isInput )
				, count );
		}

		ast::type::StructPtr getMeshNVPerVertexBaseType( ast::type::TypesCache & typesCache
			, bool isInput )
		{
			auto result{ typesCache.getIOStruct( ast::type::MemoryLayout::eC
				, "gl_MeshPerVertexNV"
				, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

			if ( !result->hasMember( ast::Builtin::ePosition ) )
			{
				result->declMember( ast::Builtin::ePosition
					, ast::type::Kind::eVec4F
					, ast::type::NotArray );
				result->declMember( ast::Builtin::ePositionPerViewNV
					, ast::type::Kind::eVec4F
					, ast::type::UnknownArraySize );
				result->declMember( ast::Builtin::ePointSize
					, ast::type::Kind::eFloat
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eClipDistance
					, ast::type::Kind::eFloat
					, 8u );
				result->declMember( ast::Builtin::eClipDistancePerViewNV
					, typesCache.getArray( typesCache.getFloat(), 8u )
					, ast::type::UnknownArraySize );
				result->declMember( ast::Builtin::eCullDistance
					, ast::type::Kind::eFloat
					, 8u );
				result->declMember( ast::Builtin::eCullDistancePerViewNV
					, typesCache.getArray( typesCache.getFloat(), 8u )
					, ast::type::UnknownArraySize );
			}

			return result;
		}

		ast::type::ArrayPtr getMeshNVPerVertexArrayType( ast::type::TypesCache & typesCache
			, uint32_t count
			, bool isInput )
		{
			return typesCache.getArray( getMeshNVPerVertexBaseType( typesCache, isInput )
				, count );
		}

		ast::type::StructPtr getMeshPerVertexBaseType( ast::type::TypesCache & typesCache
			, bool isInput )
		{
			auto result{ typesCache.getIOStruct( ast::type::MemoryLayout::eC
				, "gl_MeshPerVertexEXT"
				, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

			if ( !result->hasMember( ast::Builtin::ePosition ) )
			{
				result->declMember( ast::Builtin::ePosition
					, ast::type::Kind::eVec4F
					, ast::type::NotArray );
				result->declMember( ast::Builtin::ePositionPerViewNV
					, ast::type::Kind::eVec4F
					, ast::type::UnknownArraySize );
				result->declMember( ast::Builtin::ePointSize
					, ast::type::Kind::eFloat
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eClipDistance
					, ast::type::Kind::eFloat
					, 8u );
				result->declMember( ast::Builtin::eClipDistancePerViewNV
					, typesCache.getArray( typesCache.getFloat(), 8u )
					, ast::type::UnknownArraySize );
				result->declMember( ast::Builtin::eCullDistance
					, ast::type::Kind::eFloat
					, 8u );
				result->declMember( ast::Builtin::eCullDistancePerViewNV
					, typesCache.getArray( typesCache.getFloat(), 8u )
					, ast::type::UnknownArraySize );
			}

			return result;
		}

		ast::type::ArrayPtr getMeshPerVertexArrayType( ast::type::TypesCache & typesCache
			, uint32_t count
			, bool isInput )
		{
			return typesCache.getArray( getMeshPerVertexBaseType( typesCache, isInput )
				, count );
		}

		ast::type::TypePtr getPerVertexType( ast::type::TypesCache & typesCache
			, ast::ShaderStage stage
			, bool isInput
			, uint32_t maxPoint
			, ast::type::InputLayout inputLayout )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				assert( !isInput );
				return getPerVertexBaseType( typesCache
					, isInput );
			case ast::ShaderStage::eTessellationControl:
				if ( isInput )
				{
					return getPerVertexArrayType( typesCache
						, maxPoint
						, isInput );
				}
				return  getPerVertexArrayType( typesCache
					, 32u
					, isInput );
			case ast::ShaderStage::eTessellationEvaluation:
				if ( isInput )
				{
					return getPerVertexArrayType( typesCache
						, 32u
						, isInput );
				}
				return getPerVertexBaseType( typesCache
					, isInput );
			case ast::ShaderStage::eGeometry:
				if ( isInput )
				{
					return getPerVertexArrayType( typesCache
						, getArraySize( inputLayout )
						, isInput );
				}
				return getPerVertexBaseType( typesCache
					, isInput );
			case ast::ShaderStage::eMeshNV:
				assert( !isInput );
				return getMeshNVPerVertexArrayType( typesCache
					, getArraySize( inputLayout )
					, isInput );
			case ast::ShaderStage::eMesh:
				assert( !isInput );
				return getMeshPerVertexArrayType( typesCache
					, getArraySize( inputLayout )
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

		ast::type::StructPtr getPerPrimitiveNVBaseType( ast::type::TypesCache & typesCache
			, bool isInput )
		{
			auto result{ typesCache.getIOStruct( ast::type::MemoryLayout::eC
				, "gl_MeshPerPrimitiveNV"
				, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

			if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
			{
				result->declMember( ast::Builtin::ePrimitiveID
					, ast::type::Kind::eInt32
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eLayer
					, ast::type::Kind::eInt32
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eLayerPerViewNV
					, ast::type::Kind::eInt32
					, ast::type::UnknownArraySize );
				result->declMember( ast::Builtin::eViewportIndex
					, ast::type::Kind::eInt32
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eViewportMaskNV
					, ast::type::Kind::eInt32
					, 1u );
				result->declMember( ast::Builtin::eViewportMaskPerViewNV
					, typesCache.getArray( typesCache.getInt32(), 1u )
					, ast::type::UnknownArraySize );
			}

			return result;
		}

		ast::type::ArrayPtr getPerPrimitiveNVArrayType( ast::type::TypesCache & typesCache
			, uint32_t count
			, bool isInput )
		{
			return typesCache.getArray( getPerPrimitiveNVBaseType( typesCache, isInput )
				, count );
		}

		ast::type::StructPtr getPerPrimitiveBaseType( ast::type::TypesCache & typesCache
			, bool isInput )
		{
			auto result{ typesCache.getIOStruct( ast::type::MemoryLayout::eC
				, "gl_MeshPerPrimitiveEXT"
				, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

			if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
			{
				result->declMember( ast::Builtin::ePrimitiveID
					, ast::type::Kind::eInt32
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eLayer
					, ast::type::Kind::eInt32
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eLayerPerViewNV
					, ast::type::Kind::eInt32
					, ast::type::UnknownArraySize );
				result->declMember( ast::Builtin::eViewportIndex
					, ast::type::Kind::eInt32
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eCullPrimitive
					, ast::type::Kind::eBoolean
					, ast::type::NotArray );
				result->declMember( ast::Builtin::eViewportMaskNV
					, ast::type::Kind::eInt32
					, 1u );
				result->declMember( ast::Builtin::eViewportMaskPerViewNV
					, typesCache.getArray( typesCache.getInt32(), 1u )
					, ast::type::UnknownArraySize );
			}

			return result;
		}

		ast::type::ArrayPtr getPerPrimitiveArrayType( ast::type::TypesCache & typesCache
			, uint32_t count
			, bool isInput )
		{
			return typesCache.getArray( getPerPrimitiveBaseType( typesCache, isInput )
				, count );
		}

		ast::type::TypePtr getPerPrimitiveType( ast::type::TypesCache & typesCache
			, ast::ShaderStage stage
			, bool isInput
			, uint32_t maxPrimitives )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eMeshNV:
				assert( !isInput );
				return getPerPrimitiveNVArrayType( typesCache
					, maxPrimitives
					, isInput );
			case ast::ShaderStage::eMesh:
				assert( !isInput );
				return getPerPrimitiveArrayType( typesCache
					, maxPrimitives
					, isInput );
			case ast::ShaderStage::eVertex:
				AST_Failure( "Unexpected gl_PerVertex declaration in vertex shader." );
				return nullptr;
			case ast::ShaderStage::eTessellationControl:
				AST_Failure( "Unexpected gl_PerVertex declaration in tessellation control shader." );
				return nullptr;
			case ast::ShaderStage::eTessellationEvaluation:
				AST_Failure( "Unexpected gl_PerVertex declaration in tessellation evaluation shader." );
				return nullptr;
			case ast::ShaderStage::eGeometry:
				AST_Failure( "Unexpected gl_PerVertex declaration in geometry shader." );
				return nullptr;
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

	ast::stmt::ContainerPtr StmtAdapter::submit( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
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
			result->addStmt( ast::stmt::makePreprocVersion( writeValue( adaptationData.writerConfig.wantedVersion ) ) );

			for ( auto & extension : adaptationData.intrinsicsConfig.requiredExtensions )
			{
				doEnableExtension( result, extension, adaptationData.writerConfig.wantedVersion );
			}
		}

		StmtAdapter vis{ exprCache, typesCache, adaptationData, result.get(), result };
		container->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, AdaptationData & adaptationData
		, ast::stmt::Container * globalsCont
		, ast::stmt::ContainerPtr & result )
		: ast::StmtCloner{ exprCache, result }
		, m_typesCache{ typesCache }
		, m_adaptationData{ adaptationData }
		, m_entryPointFinish{ ast::stmt::makeContainer() }
		, m_globalsCont{ globalsCont }
	{
		if ( m_adaptationData.intrinsicsConfig.requiresRayDescDecl )
		{
			declareType( typesCache.getRayDesc() );
		}
	}
	
	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( m_exprCache
			, m_typesCache
			, expr
			, m_adaptationData
			, m_current );
	}
	
	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::ExprPtr const & expr )
	{
		return doSubmit( expr.get() );
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
				case ast::type::Kind::eMeshVertexOutput:
					doProcess( param, static_cast< ast::type::MeshVertexOutput const & >( *type ) );
					break;
				case ast::type::Kind::eMeshPrimitiveOutput:
					doProcess( param, static_cast< ast::type::MeshPrimitiveOutput const & >( *type ) );
					break;
				case ast::type::Kind::eTaskPayloadNV:
					doProcess( param, static_cast< ast::type::TaskPayloadNV const & >( *type ) );
					break;
				case ast::type::Kind::eTaskPayload:
					doProcess( param, static_cast< ast::type::TaskPayload const & >( *type ) );
					break;
				case ast::type::Kind::eTaskPayloadInNV:
					doProcess( param, static_cast< ast::type::TaskPayloadInNV const & >( *type ) );
					break;
				case ast::type::Kind::eTaskPayloadIn:
					doProcess( param, static_cast< ast::type::TaskPayloadIn const & >( *type ) );
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

	void StmtAdapter::visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		declareType( var->getType() );
		m_globalsCont->addStmt( ast::stmt::makeHitAttributeVariableDecl( var ) );
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

	void StmtAdapter::visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		declareType( var->getType() );

		if ( var->isCallableData() )
		{
			var->updateFlag( ast::var::Flag::eShaderOutput );
			m_globalsCont->addStmt( ast::stmt::makeInOutCallableDataVariableDecl( var
				, stmt->getLocation() ) );
		}
		else
		{
			StmtCloner::visitInOutCallableDataVariableDeclStmt( stmt );
		}
	}

	void StmtAdapter::visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		declareType( var->getType() );

		if ( var->isRayPayload() )
		{
			var->updateFlag( ast::var::Flag::eShaderOutput );
			m_globalsCont->addStmt( ast::stmt::makeInOutRayPayloadVariableDecl( var
				, stmt->getLocation() ) );
		}
		else
		{
			StmtCloner::visitInOutRayPayloadVariableDeclStmt( stmt );
		}
	}

	void StmtAdapter::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		declareType( stmt->getVariable()->getType() );
		StmtCloner::visitInOutVariableDeclStmt( stmt );
	}

	void StmtAdapter::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		declareType( stmt->getType() );
		StmtCloner::visitInputComputeLayoutStmt( stmt );
	}

	void StmtAdapter::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		declareType( stmt->getType() );
		StmtCloner::visitInputGeometryLayoutStmt( stmt );
	}

	void StmtAdapter::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		declareType( stmt->getType() );
		StmtCloner::visitOutputGeometryLayoutStmt( stmt );
	}

	void StmtAdapter::visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )
	{
		declareType( stmt->getType() );
		StmtCloner::visitOutputMeshLayoutStmt( stmt );
	}

	void StmtAdapter::visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )
	{
		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
			&& !m_adaptationData.writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		auto save = m_current;
		ast::stmt::ContainerPtr cont;

		if ( m_adaptationData.writerConfig.vulkanGlsl )
		{
			cont = ast::stmt::makePushConstantsBufferDecl( stmt->getName()
				, stmt->getMemoryLayout() );
		}
		else
		{
			// PCB are not supported, implement them as UBO.
			cont = ast::stmt::makeConstantBufferDecl( stmt->getName()
				, stmt->getMemoryLayout()
				, InvalidIndex
				, InvalidIndex );
		}

		m_current = cont.get();
		m_inPCB = true;
		visitContainerStmt( stmt );
		m_inPCB = false;
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )
	{
		if ( m_adaptationData.writerConfig.hasDescriptorSets )
		{
			ast::StmtCloner::visitCombinedImageDeclStmt( stmt );
		}
		else
		{
			m_current->addStmt( ast::stmt::makeCombinedImageDecl( stmt->getVariable()
				, stmt->getBindingPoint()
				, InvalidIndex ) );
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
		declareType( stmt->getData()->getType() );

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

	void StmtAdapter::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		declareType( var->getType() );

		if ( m_inPCB )
		{
			var = m_adaptationData.aliases.emplace( var
				, ast::var::makeVariable( { ++m_adaptationData.nextVarId, "pcb_" + var->getName() }
					, var->getType() ) ).first->second;
			m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
		}
		else
		{
			ast::StmtCloner::visitVariableDeclStmt( stmt );
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

	void StmtAdapter::declareType( ast::type::TypePtr type )
	{
		if ( auto structType = getStructType( getNonArrayType( type ) ) )
		{
			if ( type->getKind() != ast::type::Kind::eTaskPayloadNV
				&& type->getKind() != ast::type::Kind::eTaskPayloadInNV
				&& m_declaredStructs.insert( structType->getName() ).second )
			{
				m_globalsCont->addStmt( ast::stmt::makeStructureDecl( structType ) );
			}
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
			auto outStructType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
				, structType->getMemoryLayout()
				, structType->getName() + "Repl"
				, ast::var::Flag( flags ) );
			auto outBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
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
				declareType( outStructType );
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
			auto outStructType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
				, structType->getMemoryLayout()
				, structType->getName() + "Repl"
				, ast::var::Flag( flags ) );
			auto outBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
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
				declareType( outStructType );
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
		, ast::type::MeshVertexOutput const & meshType )
	{
		m_meshVtxVar = var;
		m_meshVtxType = &meshType;
		m_maxPoint = meshType.getMaxVertices();

		if ( m_meshPrimType )
		{
			doProcessMeshOutputs();
			m_current->addStmt( ast::stmt::makeOutputMeshLayout( meshType.getType()
				, m_meshPrimType->getTopology()
				, m_maxPoint
				, m_maxPrimitives ) );
		}
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::MeshPrimitiveOutput const & meshType )
	{
		m_meshPrimVar = var;
		m_meshPrimType = &meshType;
		m_maxPrimitives = meshType.getMaxPrimitives();

		if ( m_meshVtxType )
		{
			doProcessMeshOutputs();
			m_current->addStmt( ast::stmt::makeOutputMeshLayout( meshType.getType()
				, meshType.getTopology()
				, m_maxPoint
				, m_maxPrimitives ) );
		}
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TaskPayloadNV const & meshType )
	{
		m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TaskPayload const & meshType )
	{
		m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TaskPayloadInNV const & meshType )
	{
		m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
	}

	void StmtAdapter::doProcess( ast::var::VariablePtr var
		, ast::type::TaskPayloadIn const & meshType )
	{
		m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
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

		if ( isMeshNVStage( m_adaptationData.stage ) )
		{
			m_current->addStmt( ast::stmt::makeInputComputeLayout( compType.getType()
				, compType.getLocalSizeX() * compType.getLocalSizeY() * compType.getLocalSizeZ()
				, 1u
				, 1u ) );
		}
		else
		{
			m_current->addStmt( ast::stmt::makeInputComputeLayout( compType.getType()
				, compType.getLocalSizeX()
				, compType.getLocalSizeY()
				, compType.getLocalSizeZ() ) );
		}
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
					else if ( m_adaptationData.writerConfig.shaderStage == ast::ShaderStage::eMesh )
					{
						outerName = "gl_MeshVerticesEXT";
					}
					else if ( m_adaptationData.writerConfig.shaderStage == ast::ShaderStage::eMeshNV )
					{
						outerName = "gl_MeshVerticesNV";
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
			else if ( isPerPrimitive( mbr.builtin
				, m_adaptationData.writerConfig.shaderStage ) )
			{
				auto type = doDeclarePerPrimitive( isInput, io );
				io.perPrimitive = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, "gl_MeshPrimitivesNV" }
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
					auto mbrType = mbr.type;
					auto compType = getComponentType( mbrType );

					if ( mbr.builtin == ast::Builtin::ePrimitiveIndicesNV
						|| mbr.builtin == ast::Builtin::ePrimitivePointIndices
						|| mbr.builtin == ast::Builtin::ePrimitiveLineIndices
						|| mbr.builtin == ast::Builtin::ePrimitiveTriangleIndices )
					{
						mbrType = m_typesCache.getBasicType( compType );
					}
					else if ( ( m_adaptationData.writerConfig.shaderStage != ast::ShaderStage::eVertex || !isInput )
						&& !isMeshStage( m_adaptationData.writerConfig.shaderStage )
						&& !isRayTraceStage( m_adaptationData.writerConfig.shaderStage )
						&& ( isUnsignedIntType( compType ) || isSignedIntType( compType ) ) )
					{
						mbrFlags = mbrFlags | ast::var::Flag::eFlat;
					}

					auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, name }
						, ( arraySize == ast::type::NotArray
							? mbrType
							: m_typesCache.getArray( mbrType, arraySize ) )
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
		auto funcType = m_typesCache.getFunction( m_typesCache.getVoid(), {} );
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

	ast::type::TypePtr StmtAdapter::doDeclarePerVertex( bool isInput
		, IOVars & io )
	{
		if ( ( isInput && !m_inPerVertex )
			|| ( !isInput && !m_outPerVertex ) )
		{
			auto type = getPerVertexType( m_typesCache
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

	ast::type::TypePtr StmtAdapter::doDeclarePerPrimitive( bool isInput
		, IOVars & io )
	{
		if ( ( isInput && !m_inPerPrimitive )
			|| ( !isInput && !m_outPerPrimitive ) )
		{
			auto type = getPerPrimitiveType( m_typesCache
				, m_adaptationData.writerConfig.shaderStage
				, isInput
				, m_maxPrimitives );
			m_current->addStmt( ast::stmt::makePerPrimitiveDecl( type ) );

			if ( isInput )
			{
				m_inPerPrimitive = type;
			}
			else
			{
				m_outPerPrimitive = type;
			}

			return type;
		}

		if ( isInput )
		{
			return m_inPerPrimitive;
		}

		return m_outPerPrimitive;
	}

	void StmtAdapter::doProcessMeshOutputs()
	{
		auto type = m_meshVtxType->getType();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderOutput() );
			doProcessOutput( m_meshVtxVar
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, ast::type::UnknownArraySize
				, true );
		}

		type = m_meshPrimType->getType();

		if ( isStructType( type ) )
		{
			auto structType = getStructType( type );
			assert( structType->isShaderOutput() );
			doProcessOutput( m_meshPrimVar
				, std::static_pointer_cast< ast::type::IOStruct >( structType )
				, ast::type::UnknownArraySize
				, true );
		}
	}
}
