/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvShader.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw::spirv
{
	SpirvShader::SpirvShader( Shader const & shader )
		: m_shader{ shader }
	{
	}

	void SpirvShader::registerVariable( var::VariablePtr var )
	{
		auto it = m_registered.find( var->getName() );
		assert( it == m_registered.end() );
		m_registered.emplace( var->getName(), var );
	}

	var::VariablePtr SpirvShader::registerName( std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		auto it = m_registered.find( name );
		assert( it == m_registered.end() );
		it = m_registered.emplace( name, var::makeVariable( type, name, flags ) ).first;
		return it->second;
	}

	var::VariablePtr SpirvShader::registerName( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerName( name
			, type
			, uint32_t( flag ) );
	}

	var::VariablePtr SpirvShader::registerName( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, 0u );
	}

	var::VariablePtr SpirvShader::registerSampler( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eSampler );

		if ( enabled )
		{
			m_samplers.emplace( name, SamplerInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr SpirvShader::registerSampledImage( std::string const & name
		, type::TypePtr type
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eSampler | var::Flag::eImage );

		if ( enabled )
		{
			m_sampledImages.insert( name );
		}

		return result;
	}

	var::VariablePtr SpirvShader::registerImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eImage );

		if ( enabled )
		{
			m_images.emplace( name, ImageInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr SpirvShader::getVar( std::string const & name
		, type::TypePtr type )
	{
		auto result = m_shader.getVar( name, type );

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
