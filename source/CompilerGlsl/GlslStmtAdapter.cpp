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
			, std::string const & extensionName
			, uint32_t coreInVersion
			, uint32_t shaderVersion )
		{
			if ( coreInVersion > shaderVersion )
			{
				cont->addStmt( ast::stmt::makePreprocExtension( extensionName
					, ast::stmt::PreprocExtension::ExtStatus::eRequired ) );
			}
		}

		void doEnableExtension( ast::stmt::ContainerPtr & cont
			, std::string const & extensionName
			, uint32_t requiredVersion
			, uint32_t shaderVersion )
		{
			if ( requiredVersion <= shaderVersion )
			{
				cont->addStmt( ast::stmt::makePreprocExtension( extensionName
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
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
			result->addStmt( ast::stmt::makePreprocVersion( std::to_string( adaptationData.writerConfig.shaderLanguageVersion ) ) );
			doEnableCoreExtension( result, "GL_ARB_explicit_attrib_location", 330u, adaptationData.writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_explicit_uniform_location", 430u, adaptationData.writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_separate_shader_objects", 410u, adaptationData.writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_shading_language_420pack", 420u, adaptationData.writerConfig.shaderLanguageVersion );
			doEnableExtension( result, "GL_KHR_vulkan_glsl", 460u, adaptationData.writerConfig.shaderLanguageVersion );

			if ( adaptationData.intrinsicsConfig.requiresCubeMapArray )
			{
				doEnableCoreExtension( result, "GL_ARB_texture_cube_map_array", 400u, adaptationData.writerConfig.shaderLanguageVersion );
			}

			if ( adaptationData.intrinsicsConfig.requiresTextureGather )
			{
				doEnableCoreExtension( result, "GL_ARB_texture_gather", 400u, adaptationData.writerConfig.shaderLanguageVersion );
			}

			if ( adaptationData.intrinsicsConfig.requiresFp16 )
			{
				result->addStmt( ast::stmt::makePreprocExtension( "GL_NV_gpu_shader5"
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
			}

			if ( adaptationData.intrinsicsConfig.requiresAtomicFloat )
			{
				result->addStmt( ast::stmt::makePreprocExtension( "GL_NV_shader_atomic_float"
					, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );

				if ( adaptationData.intrinsicsConfig.requiresAtomicFp16Vector )
				{
					result->addStmt( ast::stmt::makePreprocExtension( "GL_NV_shader_atomic_fp16_vector"
						, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
				}
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
								, arraySize
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
				, getArraySize( geomType.layout )
				, true );
		}

		m_current->addStmt( ast::stmt::makeInputGeometryLayout( type
			, geomType.layout ) );
	}

	void StmtAdapter::doProcessOutput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType
		, bool entryPoint )
	{
		m_adaptationData.output = var;

		for ( auto & mbr : structType )
		{
			auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, "sdwOut_" + mbr.name }
				, mbr.type
				, structType.getFlag() );
			m_adaptationData.outputs.emplace_back( mbrVar );

			if ( entryPoint )
			{
				m_current->addStmt( ast::stmt::makeInOutVariableDecl( mbrVar
					, mbr.location ) );
			}
		}
	}

	void StmtAdapter::doProcessInput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType
		, uint32_t arraySize
		, bool entryPoint )
	{
		m_adaptationData.input = var;

		for ( auto & mbr : structType )
		{
			auto mbrVar = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, "sdwIn_" + mbr.name }
				, ( arraySize == ast::type::NotArray
					? mbr.type
					: m_cache.getArray( mbr.type, arraySize ) )
				, structType.getFlag() );
			m_adaptationData.inputs.emplace_back( mbrVar );

			if ( entryPoint )
			{
				m_current->addStmt( ast::stmt::makeInOutVariableDecl( mbrVar
					, mbr.location ) );
			}
		}
	}

	void StmtAdapter::doProcessOutputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType
		, bool entryPoint )
	{
		if ( entryPoint )
		{
			doDeclareStruct( structType );
			m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
		}
	}

	void StmtAdapter::doProcessInputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType
		, bool entryPoint )
	{
		if ( entryPoint )
		{
			doDeclareStruct( structType );
			m_current->addStmt( ast::stmt::makeVariableDecl( var ) );
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
}
