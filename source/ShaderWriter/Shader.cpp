/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Shader::Shader()
		: m_container{ stmt::makeContainer() }
	{
		push( m_container.get() );
	}

	void Shader::push( stmt::Container * container )
	{
		m_blocks.push_back( { {}, container } );
	}

	void Shader::pop()
	{
		m_blocks.erase( m_blocks.begin() + m_blocks.size() - 1u );
	}

	void Shader::registerVariable( var::VariablePtr var )
	{
		auto & block = m_blocks.back();
		auto it = block.registered.find( var->getName() );
		assert( it == block.registered.end() );
		block.registered.emplace( var->getName(), var );
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		auto & block = m_blocks.back();
		auto it = block.registered.find( name );
		assert( it == block.registered.end() );
		it = block.registered.emplace( name, var::makeVariable( type, name, flags ) ).first;
		return it->second;
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerName( name
			, type
			, uint32_t( flag ) );
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, 0u );
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		auto & block = m_blocks.back();
		auto it = block.registered.find( name );
		assert( it == block.registered.end() );
		it = block.registered.emplace( name, var::makeVariable( outer, type, name, flags | var::Flag::eMember ) ).first;
		return it->second;
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerMember( std::move( outer )
			, name
			, type
			, uint32_t( flag ) );
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type )
	{
		return registerMember( std::move( outer )
			, name
			, type
			, 0u );
	}

	var::VariablePtr Shader::registerConstant( std::string const & name
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eShaderConstant );
		m_constants.emplace( name, type );
		return result;
	}

	var::VariablePtr Shader::registerSpecConstant( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eSpecialisationConstant );
		m_specConstants.emplace( name, SpecConstantInfo{ type, location } );
		return result;
	}

	var::VariablePtr Shader::registerSampledImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eUniform | var::Flag::eConstant );

		if ( enabled )
		{
			m_samplers.emplace( name, SamplerInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr Shader::registerImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eUniform | var::Flag::eConstant );

		if ( enabled )
		{
			m_images.emplace( name, ImageInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr Shader::registerInput( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eShaderInput );
		m_inputs.emplace( name, InputInfo{ type, location } );
		return result;
	}

	var::VariablePtr Shader::registerOutput( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eShaderOutput );
		m_outputs.emplace( name, OutputInfo{ type, location } );
		return result;
	}

	var::VariablePtr Shader::registerBuiltin( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		var::VariablePtr result = registerName( name
			, type
			, var::Flag::eBuiltin | flag );
		return result;
	}

	var::VariablePtr Shader::registerLocale( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eLocale );
	}

	var::VariablePtr Shader::registerInParam( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eInputParam );
	}

	var::VariablePtr Shader::registerOutParam( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eOutputParam );
	}

	var::VariablePtr Shader::registerInOutParam( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, uint32_t( var::Flag::eInputParam ) | uint32_t( var::Flag::eOutputParam ) );
	}

	var::VariablePtr Shader::getVar( std::string const & name )const
	{
		auto & block = m_blocks.back();
		auto it = block.registered.find( name );

		if ( it == block.registered.end() )
		{
			it = m_blocks.front().registered.find( name );

			if ( it == m_blocks.front().registered.end() )
			{
				std::string text;
				text += "No registered variable with the name [" + name + "].";
				throw std::runtime_error{ text };
			}
		}

		return it->second;
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
}
