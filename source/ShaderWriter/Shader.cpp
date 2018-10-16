/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Shader::Shader()
	{
		m_blocks.push( { {}, &m_container } );
	}

	void Shader::registerName( std::string const & name, type::Kind type )
	{
		auto & block = m_blocks.top();
		auto it = block.registered.find( name );
		block.registered.emplace( name, type );
	}

	void Shader::checkNameExists( std::string const & name
		, type::Kind type )
	{
		auto & block = m_blocks.top();
		auto it = block.registered.find( name );

		if ( it == block.registered.end() )
		{
			std::string text;
			text += "No registered variable with the name [" + name + "].";
			throw std::runtime_error{ text };
		}
	}

	void Shader::addStmt( stmt::StmtPtr stmt )
	{
		getContainer()->addStmt( std::move( stmt ) );
	}

	void Shader::registerSsbo( std::string const & name
		, Ssbo::Info const & info )
	{
		m_ssbos.emplace( name, info );
	}

	void Shader::registerUbo( std::string const & name
		, Ubo::Info const & info )
	{
		m_ubos.emplace( name, info );
	}

	void Shader::registerConstant( std::string const & name
		, type::Kind type )
	{
		registerName( name, type );
		m_constants.emplace( name, type );
	}

	void Shader::registerSampler( std::string const & name
		, type::Kind type
		, uint32_t binding
		, uint32_t set
		, uint32_t count
		, bool enabled )
	{
		registerName( name, type );

		if ( enabled )
		{
			m_samplers.emplace( name, SamplerInfo{ type, binding, set, count } );
		}
	}

	void Shader::registerInput( std::string const & name
		, uint32_t location
		, type::Kind type )
	{
		registerName( name, type );
		m_inputs.emplace( name, InputInfo{ type, location } );
	}

	void Shader::registerOutput( std::string const & name
		, uint32_t location
		, type::Kind type )
	{
		registerName( name, type );
		m_outputs.emplace( name, OutputInfo{ type, location } );
	}
}
