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
		auto ires = m_registered.emplace( var->getName(), var );
		assert( ires.second );
#else
		m_registered.emplace( var->getName(), var );
#endif
	}

	ast::var::VariablePtr HlslShader::registerBuiltin( ast::Builtin builtin
		, ast::type::TypePtr type
		, uint64_t flags )
	{
		auto name = ast::getName( builtin );
		auto ires = m_registered.emplace( name, nullptr );

		if ( ires.second )
		{
			ires.first->second = ast::var::makeBuiltin( ++m_shader.getData().nextVarId
				, builtin
				, type
				, flags );
		}

		return ires.first->second;
	}

	ast::var::VariablePtr HlslShader::registerName( std::string name
		, ast::type::TypePtr type
		, uint64_t flags )
	{
		auto ires = m_registered.emplace( name, nullptr );

		if ( ires.second )
		{
			ires.first->second = ast::var::makeVariable( ++m_shader.getData().nextVarId
				, type
				, std::move( name )
				, flags );
		}

		return ires.first->second;
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

			m_samplers.emplace( std::move( name ), ast::SamplerInfo{ { type, { binding, set } } } );
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

			m_images.emplace( std::move( name ), ast::ImageInfo{ { type, { binding, set } } } );
		}
		else
		{
			result = registerName( std::move( name )
				, type
				, ast::var::Flag::eUniform );
		}

		return result;
	}

	bool HlslShader::hasVar( std::string const & name )
	{
		if ( m_shader.hasVar( name ) )
		{
			return true;
		}

		auto it = m_registered.find( name );

		if ( it != m_registered.end() )
		{
			return true;
		}

		return false;
	}

	ast::var::VariablePtr HlslShader::getVar( std::string const & name
		, ast::type::TypePtr type )
	{
		auto result = ( m_shader.hasVar( name )
			? m_shader.getVar( name )
			: nullptr );

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
