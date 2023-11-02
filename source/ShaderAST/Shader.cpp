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
		, m_variables{ m_allocator.get() }
	{
	}

	bool Shader::hasVar( std::string const & name )const
	{
		auto curBlockIt = std::find_if( m_variables.crbegin()
			, m_variables.crend()
			, [&name]( std::pair< size_t const, Set< var::VariablePtr > > const & lookup )
			{
				return shader::findVariable( lookup.second, name ) != lookup.second.end();
			} );
		return curBlockIt != m_variables.rend();
	}

	var::VariablePtr Shader::getVar( std::string const & name )const
	{
		Set< var::VariablePtr >::const_iterator it;
		auto curBlockIt = std::find_if( m_variables.crbegin()
			, m_variables.crend()
			, [&name, &it]( std::pair< size_t const, Set< var::VariablePtr > > const & lookup )
			{
				it = shader::findVariable( lookup.second, name );
				return it != lookup.second.end();
			} );

		if ( curBlockIt == m_variables.rend() )
		{
			std::string text;
			text += "No registered variable with the name [" + std::string( name ) + "].";
			throw std::runtime_error{ text };
		}

		return *it;
	}

	SdwShader Shader::getOpaqueHandle()const
	{
		return reinterpret_cast<SdwShader>(this);
	}

	Shader const & Shader::fromOpaqueHandle(SdwShader shader)
	{
		assert( shader != nullptr );

		return *reinterpret_cast<Shader const*>( shader );
	}

	void Shader::registerVar( size_t block, var::VariablePtr var )
	{
		auto & vars = m_variables.emplace( block, Set< var::VariablePtr >{ m_allocator.get() } ).first->second;
		vars.emplace( std::move( var ) );
	}
}
