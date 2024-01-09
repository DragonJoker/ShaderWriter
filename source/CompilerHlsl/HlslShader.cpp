/*
See LICENSE file in root folder
*/
#include "HlslShader.hpp"

#include <ShaderAST/Shader.hpp>

namespace hlsl
{
	HlslShader::HlslShader( ast::Shader const & shader
		, ast::ShaderStage stage )
		: m_shader{ shader }
		, m_shaderStage{ stage }
	{
	}

	void HlslShader::registerVariable( ast::var::VariablePtr var )
	{
#if !defined( NDEBUG )
		auto [_, res] = m_registered.try_emplace( var->getName(), var );
		assert( res );
#else
		m_registered.try_emplace( var->getName(), var );
#endif
	}

	ast::var::VariablePtr HlslShader::registerBuiltin( ast::Builtin builtin
		, ast::type::TypePtr type
		, uint64_t flags )
	{
		auto name = ast::getName( builtin );
		auto [it, res] = m_registered.try_emplace( name );

		if ( res )
		{
			++m_shader.getData().nextVarId;
			it->second = ast::var::makeBuiltin( m_shader.getData().nextVarId
				, builtin
				, type
				, flags );
		}

		return it->second;
	}

	ast::var::VariablePtr HlslShader::registerName( std::string name
		, ast::type::TypePtr type
		, uint64_t flags )
	{
		auto [it, res] = m_registered.try_emplace( name );

		if ( res )
		{
			++m_shader.getData().nextVarId;
			it->second = ast::var::makeVariable( m_shader.getData().nextVarId
				, type
				, std::move( name )
				, flags );
		}

		return it->second;
	}

	ast::var::VariablePtr HlslShader::registerName( std::string name
		, ast::type::TypePtr type
		, ast::var::Flag flag )
	{
		return registerName( std::move( name )
			, type
			, uint64_t( flag ) );
	}

	ast::var::VariablePtr HlslShader::registerName( std::string name
		, ast::type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, 0u );
	}

	ast::var::VariablePtr HlslShader::registerSampler( std::string name
		, ast::type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		ast::var::VariablePtr result;

		if ( enabled )
		{
			result = registerName( name
				, type
				, ast::var::Flag::eUniform );

			m_samplers.try_emplace( std::move( name )
				, ast::SamplerInfo{ { type, { binding, set } } } );
		}
		else
		{
			result = registerName( std::move( name )
				, type
				, ast::var::Flag::eUniform );
		}

		return result;
	}

	ast::var::VariablePtr HlslShader::registerImage( std::string name
		, ast::type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		ast::var::VariablePtr result;

		if ( enabled )
		{
			result = registerName( name
				, type
				, ast::var::Flag::eUniform );

			m_images.try_emplace( std::move( name )
				, ast::ImageInfo{ { type, { binding, set } } } );
		}
		else
		{
			result = registerName( std::move( name )
				, type
				, ast::var::Flag::eUniform );
		}

		return result;
	}

	bool HlslShader::hasGlobalVariable( std::string const & name )
	{
		if ( m_shader.hasGlobalVariable( name ) )
		{
			return true;
		}

		if ( auto it = m_registered.find( name );
			it != m_registered.end() )
		{
			return true;
		}

		return false;
	}

	ast::var::VariablePtr HlslShader::getGlobalVariable( std::string const & name )
	{
		auto result = ( m_shader.hasGlobalVariable( name )
			? m_shader.getGlobalVariable( name )
			: nullptr );

		if ( !result )
		{
			auto it = m_registered.find( name );

			if ( it == m_registered.end() )
			{
				std::string text;
				text += "No registered variable with the name [" + name + "].";
				throw ast::Exception{ text };
			}

			result = it->second;
		}

		return result;
	}
}
