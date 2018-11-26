/*
See LICENSE file in root folder
*/
#include "GlslStmtAdapter.hpp"

#include "GlslExprAdapter.hpp"
#include "GlslHelpers.hpp"
#include "GlslTextureAccessFunctions.hpp"

#include <ShaderWriter/Shader.hpp>

#include <algorithm>

using namespace ast;
using namespace sdw;

namespace glsl
{
	void doEnableCoreExtension( stmt::ContainerPtr & cont
		, std::string const & extensionName
		, uint32_t coreInVersion
		, uint32_t shaderVersion )
	{
		if ( coreInVersion > shaderVersion )
		{
			cont->addStmt( stmt::makePreprocExtension( extensionName
				, stmt::PreprocExtension::Status::eRequired ) );
		}
	}
	
	void doEnableExtension( stmt::ContainerPtr & cont
		, std::string const & extensionName
		, uint32_t requiredVersion
		, uint32_t shaderVersion )
	{
		if ( requiredVersion <= shaderVersion )
		{
			cont->addStmt( stmt::makePreprocExtension( extensionName
				, stmt::PreprocExtension::Status::eEnabled ) );
		}
	}

	stmt::ContainerPtr StmtAdapter::submit( Shader const & shader
		, GlslConfig const & writerConfig
		, IntrinsicsConfig const & intrinsicsConfig )
	{
		auto result = stmt::makeContainer();
		auto cont = shader.getStatements();
		auto it = std::find_if ( cont->begin()
			, cont->end()
			, []( stmt::StmtPtr const & lookup )
			{
				return lookup->getKind() == stmt::Kind::ePreprocVersion;
			} );

		if ( it == cont->end() )
		{
			result->addStmt( stmt::makePreprocVersion( std::to_string( writerConfig.shaderLanguageVersion ) ) );
			doEnableCoreExtension( result, "GL_ARB_explicit_attrib_location", 330u, writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_explicit_uniform_location", 430u, writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_separate_shader_objects", 410u, writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_shading_language_420pack", 420u, writerConfig.shaderLanguageVersion );
			doEnableCoreExtension( result, "GL_ARB_shading_language_420pack", 420u, writerConfig.shaderLanguageVersion );
			doEnableExtension( result, "GL_KHR_vulkan_glsl", 450u, writerConfig.shaderLanguageVersion );
		}

		StmtAdapter vis{ shader, writerConfig, intrinsicsConfig, result };
		cont->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( Shader const & shader
		, GlslConfig const & writerConfig
		, IntrinsicsConfig const & intrinsicsConfig
		, stmt::ContainerPtr & result )
		: ast::StmtCloner{ result }
		, m_writerConfig{ writerConfig }
		, m_intrinsicsConfig{ intrinsicsConfig }
	{
	}
	
	expr::ExprPtr StmtAdapter::doSubmit( expr::Expr * expr )
	{
		return ExprAdapter::submit( expr, m_writerConfig, m_intrinsicsConfig );
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
			auto cont = stmt::makeConstantBufferDecl( stmt->getName()
				, stmt->getMemoryLayout()
				, stmt->getBindingPoint()
				, ~( 0u ) );
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
			m_current->addStmt( stmt::makeImageDecl( stmt->getVariable()
				, stmt->getBindingPoint()
				, ~( 0u ) ) );
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
			auto cont = stmt::makeConstantBufferDecl( stmt->getName()
				, stmt->getMemoryLayout()
				, ~( 0u )
				, ~( 0u ) );
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
			m_current->addStmt( stmt::makeSampledImageDecl( stmt->getVariable()
				, stmt->getBindingPoint()
				, ~( 0u ) ) );
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
			auto cont = stmt::makeShaderBufferDecl( stmt->getSsboName()
				, stmt->getMemoryLayout()
				, stmt->getBindingPoint()
				, ~( 0u ) );
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
			m_current->addStmt( stmt::makeShaderStructBufferDecl( stmt->getSsboName()
				, stmt->getSsboInstance()
				, stmt->getData()
				, stmt->getBindingPoint()
				, ~( 0u ) ) );
		}
	}

	void StmtAdapter::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		m_result->addStmt( stmt::makePreprocVersion( preproc->getName() ) );
		auto cont = stmt::makeContainer();
		compileGlslTextureAccessFunctions( cont.get(), m_intrinsicsConfig );

		if ( !cont->empty() )
		{
			m_result->addStmt( std::move( cont ) );
		}
	}
}
