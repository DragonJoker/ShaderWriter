/*
See LICENSE file in root folder
*/
#include "SpirvShader.hpp"

namespace spirv
{
	SpirvShader::SpirvShader( sdw::Shader const & shader )
		: m_shader{ shader }
	{
	}

	void SpirvShader::registerVariable( ast::var::VariablePtr var )
	{
		auto it = m_registered.find( var->getName() );
		assert( it == m_registered.end() );
		m_registered.emplace( var->getName(), var );
	}

	ast::var::VariablePtr SpirvShader::registerName( std::string const & name
		, ast::type::TypePtr type
		, uint32_t flags )
	{
		auto it = m_registered.find( name );
		assert( it == m_registered.end() );
		it = m_registered.emplace( name, ast::var::makeVariable( type, name, flags ) ).first;
		return it->second;
	}

	ast::var::VariablePtr SpirvShader::registerName( std::string const & name
		, ast::type::TypePtr type
		, ast::var::Flag flag )
	{
		return registerName( name
			, type
			, uint32_t( flag ) );
	}

	ast::var::VariablePtr SpirvShader::registerName( std::string const & name
		, ast::type::TypePtr type )
	{
		return registerName( name
			, type
			, 0u );
	}

	ast::var::VariablePtr SpirvShader::getVar( std::string const & name
		, ast::type::TypePtr type )
	{
		auto result = m_shader.getVar( name );

		if ( !result )
		{
			auto it = m_registered.find( name );

			if ( it == m_registered.end() )
			{
				std::string text;
				text += "No registered variable with the name [" + name + "].";
				throw std::runtime_error{ text };
			}

			result = it->second;
		}

		return result;
	}
}
