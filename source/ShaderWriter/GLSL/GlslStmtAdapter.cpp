/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslStmtAdapter.hpp"

#include "ShaderWriter/GLSL/GlslExprAdapter.hpp"
#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/GLSL/GlslTextureAccessFunctions.hpp"

#include "ShaderWriter/Shader.hpp"

#include <algorithm>

namespace sdw::glsl
{
	void doEnableExtension( stmt::ContainerPtr & cont
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
			doEnableExtension( result, "GL_ARB_explicit_attrib_location", 330u, writerConfig.shaderLanguageVersion );
			doEnableExtension( result, "GL_ARB_explicit_uniform_location", 430u, writerConfig.shaderLanguageVersion );
			doEnableExtension( result, "GL_ARB_separate_shader_objects", 410u, writerConfig.shaderLanguageVersion );
			doEnableExtension( result, "GL_ARB_shading_language_420pack", 420u, writerConfig.shaderLanguageVersion );
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
