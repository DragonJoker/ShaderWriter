/*
See LICENSE file in root folder
*/
#include "ShaderAST/Shader.hpp"

#include "ShaderAST/Stmt/StmtSimple.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"

#include <algorithm>
#include <string_view>

namespace ast
{
	namespace shader
	{
		static auto findVariable( Set< var::VariablePtr > const & vars
			, std::string_view name )
		{
			return std::find_if( vars.begin()
				, vars.end()
				, [name]( var::VariablePtr const & var )
				{
					return ( var->getFullName() == name
						|| var->getName() == name );
				} );
		}
	}

	Shader::Shader( ast::ShaderStage type
		, ShaderAllocator * allocator )
		: m_type{ type }
		, m_ownAllocator{ allocator ? nullptr : std::make_unique< ShaderAllocator >() }
		, m_allocator{ allocator ? allocator->getBlock() : m_ownAllocator->getBlock() }
		, m_typesCache{ std::make_unique< ast::type::TypesCache >() }
		, m_stmtCache{ std::make_unique< ast::stmt::StmtCache >( *m_allocator ) }
		, m_exprCache{ std::make_unique< ast::expr::ExprCache >( *m_allocator ) }
		, m_container{ m_stmtCache->makeContainer() }
		, m_globalVariables{ m_allocator.get() }
	{
	}

	bool Shader::hasGlobalVariable( std::string_view const & name )const
	{
		return shader::findVariable( m_globalVariables, name ) != m_globalVariables.end();
	}

	var::VariablePtr Shader::getGlobalVariable( std::string_view const & name )const
	{
		auto it = shader::findVariable( m_globalVariables, name );

		if ( it == m_globalVariables.end() )
		{
			std::string text;
			text += "No registered variable with the name [" + std::string( name ) + "].";
			throw Exception{ text };
		}

		return *it;
	}

	void Shader::registerGlobalVariable( var::VariablePtr var )
	{
		m_globalVariables.emplace( std::move( var ) );
	}

	SdwShader Shader::getOpaqueHandle()const
	{
		return reinterpret_cast< SdwShader >( this );
	}

	Shader const & Shader::fromOpaqueHandle(SdwShader shader)
	{
		assert( shader != nullptr );

		return *reinterpret_cast< Shader const * >( shader );
	}
}
