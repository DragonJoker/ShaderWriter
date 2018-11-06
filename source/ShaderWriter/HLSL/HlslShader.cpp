/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslShader.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw::hlsl
{
	HlslShader::HlslShader( Shader const & shader )
		: m_shader{ shader }
	{
	}

	void HlslShader::registerVariable( var::VariablePtr var )
	{
		auto it = m_registered.find( var->getName() );
		assert( it == m_registered.end() );
		m_registered.emplace( var->getName(), var );
	}

	var::VariablePtr HlslShader::registerName( std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		auto it = m_registered.find( name );
		assert( it == m_registered.end() );
		it = m_registered.emplace( name, var::makeVariable( type, name, flags ) ).first;
		return it->second;
	}

	var::VariablePtr HlslShader::registerName( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerName( name
			, type
			, uint32_t( flag ) );
	}

	var::VariablePtr HlslShader::registerName( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, 0u );
	}

	var::VariablePtr HlslShader::registerSampler( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eUniform );

		if ( enabled )
		{
			m_samplers.emplace( name, SamplerInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr HlslShader::registerImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eUniform );

		if ( enabled )
		{
			m_images.emplace( name, ImageInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr HlslShader::getVar( std::string const & name
		, type::TypePtr type )
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
