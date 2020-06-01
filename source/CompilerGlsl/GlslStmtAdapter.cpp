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

	ast::stmt::ContainerPtr StmtAdapter::submit( ast::type::TypesCache & cache
		, ast::stmt::Container * container
		, GlslConfig const & writerConfig
		, IntrinsicsConfig const & intrinsicsConfig )
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
			result->addStmt( ast::stmt::makePreprocVersion( std::to_string( writerConfig.shaderLanguageVersion ) ) );
			doEnableCoreExtension( result, "GL_ARB_explicit_attrib_location", 330u, writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_explicit_uniform_location", 430u, writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_separate_shader_objects", 410u, writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_shading_language_420pack", 420u, writerConfig.shaderLanguageVersion );
			doEnableExtension( result, "GL_KHR_vulkan_glsl", 460u, writerConfig.shaderLanguageVersion );

			if ( intrinsicsConfig.requiresCubeMapArray )
			{
				doEnableCoreExtension( result, "GL_ARB_texture_cube_map_array", 400u, writerConfig.shaderLanguageVersion );
			}

			if ( intrinsicsConfig.requiresTextureGather )
			{
				doEnableCoreExtension( result, "GL_ARB_texture_gather", 400u, writerConfig.shaderLanguageVersion );
			}
		}

		StmtAdapter vis{ cache, writerConfig, intrinsicsConfig, result };
		container->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( ast::type::TypesCache & cache
		, GlslConfig const & writerConfig
		, IntrinsicsConfig const & intrinsicsConfig
		, ast::stmt::ContainerPtr & result )
		: ast::StmtCloner{ result }
		, m_cache{ cache }
		, m_writerConfig{ writerConfig }
		, m_intrinsicsConfig{ intrinsicsConfig }
	{
	}
	
	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( m_cache
			, expr
			, m_writerConfig
			, m_intrinsicsConfig );
	}

	void StmtAdapter::visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )
	{
		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
			&& !m_writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_writerConfig.hasDescriptorSets )
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

	void StmtAdapter::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		if ( m_writerConfig.hasDescriptorSets )
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
			&& !m_writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_writerConfig.vulkanGlsl )
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
		if ( m_writerConfig.hasDescriptorSets )
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
			&& !m_writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_writerConfig.hasDescriptorSets )
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
			&& !m_writerConfig.hasStd430Layout )
		{
			throw std::runtime_error{ "std430 layout is not supported, consider using std140" };
		}

		if ( m_writerConfig.hasDescriptorSets )
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
		compileGlslTextureAccessFunctions( cont.get(), m_intrinsicsConfig );

		if ( !cont->empty() )
		{
			m_result->addStmt( std::move( cont ) );
		}
	}
}
