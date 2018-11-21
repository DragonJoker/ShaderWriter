/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslStmtAdapter.hpp"

#include "ShaderWriter/GLSL/GlslExprAdapter.hpp"
#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/GLSL/GlslTextureAccessFunctions.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw::glsl
{
	stmt::ContainerPtr StmtAdapter::submit( Shader const & shader
		, IntrinsicsConfig const & config )
	{
		auto result = stmt::makeContainer();
		StmtAdapter vis{ shader, config, result };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( Shader const & shader
		, IntrinsicsConfig const & config
		, stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_config{ config }
	{
	}
	
	expr::ExprPtr StmtAdapter::doSubmit( expr::Expr * expr )
	{
		return ExprAdapter::submit( expr, m_config );
	}

	void StmtAdapter::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		m_result->addStmt( stmt::makePreprocVersion( preproc->getName() ) );
		auto cont = stmt::makeContainer();
		compileGlslTextureAccessFunctions( cont.get(), m_config );

		if ( !cont->empty() )
		{
			m_result->addStmt( std::move( cont ) );
		}
	}
}
