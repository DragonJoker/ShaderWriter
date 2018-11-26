/*
See LICENSE file in root folder
*/
#include "HlslShader.hpp"

#include <ShaderWriter/Shader.hpp>

namespace hlsl
{
	HlslShader::HlslShader( sdw::Shader const & shader )
		: m_shader{ shader }
	{
	}

	void HlslShader::registerVariable( ast::var::VariablePtr var )
	{
		auto it = m_registered.find( var->getName() );
		assert( it == m_registered.end() );
		m_registered.emplace( var->getName(), var );
	}

	ast::var::VariablePtr HlslShader::registerName( std::string const & name
		, ast::type::TypePtr type
		, uint32_t flags )
	{
		auto it = m_registered.find( name );
		assert( it == m_registered.end() );
		it = m_registered.emplace( name, ast::var::makeVariable( type, name, flags ) ).first;
		return it->second;
	}

	ast::var::VariablePtr HlslShader::registerName( std::string const & name
		, ast::type::TypePtr type
		, ast::var::Flag flag )
	{
		return registerName( name
			, type
			, uint32_t( flag ) );
	}

	ast::var::VariablePtr HlslShader::registerName( std::string const & name
		, ast::type::TypePtr type )
	{
		return registerName( name
			, type
			, 0u );
	}

	ast::var::VariablePtr HlslShader::registerSampler( std::string const & name
		, ast::type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, ast::var::Flag::eUniform );

		if ( enabled )
		{
			m_samplers.emplace( name, sdw::SamplerInfo{ type, binding, set } );
		}

		return result;
	}

	ast::var::VariablePtr HlslShader::registerImage( std::string const & name
		, ast::type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, ast::var::Flag::eUniform );

		if ( enabled )
		{
			m_images.emplace( name, sdw::ImageInfo{ type, binding, set } );
		}

		return result;
	}

	bool HlslShader::hasVar( std::string const & name )
	{
		try
		{
			getVar( name, nullptr );
			return true;
		}
		catch ( ... )
		{
			return false;
		}
	}

	ast::var::VariablePtr HlslShader::getVar( std::string const & name
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
