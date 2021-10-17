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
		auto funcType = stmt->getType();

		if ( stmt->getName() == "main"
			&& !funcType->empty() )
		{
			m_adaptationData.geomOutput = ( *funcType->begin() );
			auto type = m_adaptationData.geomOutput->getType();

			if ( type->getKind() == ast::type::Kind::eGeometryOutput )
			{
				auto & geomType = static_cast< ast::type::GeometryOutput const & >( *type );
				type = geomType.type;

				if ( type->getKind() == ast::type::Kind::eStruct )
				{
					for ( auto & mbr : static_cast< ast::type::Struct const & >( *type ) )
					{
						auto var = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, mbr.name }
							, mbr.type
							, mbr.flag );
						m_adaptationData.geomOutputs.emplace_back( var );
						m_current->addStmt( ast::stmt::makeInOutVariableDecl( var
							, mbr.location ) );
					}
				}

				m_current->addStmt( ast::stmt::makeOutputGeometryLayout( type
					, geomType.layout
					, geomType.count ) );
			}

			funcType = m_cache.getFunction( m_cache.getVoid(), {} );
			auto save = m_current;
			auto cont = ast::stmt::makeFunctionDecl( funcType, stmt->getName() );
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;
			m_current->addStmt( std::move( cont ) );
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
}
