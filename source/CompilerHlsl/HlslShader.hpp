/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslShader_H___
#define ___SDW_HlslShader_H___
#pragma once

#include <ShaderAST/Shader.hpp>

namespace hlsl
{
	class HlslShader
	{
	public:
		HlslShader( ast::Shader const & shader );

		void registerVariable( ast::var::VariablePtr var );
		ast::var::VariablePtr registerBuiltin( ast::Builtin builtin
			, ast::type::TypePtr type
			, uint64_t flags );
		ast::var::VariablePtr registerName( std::string const & name
			, ast::type::TypePtr type
			, uint64_t flags );
		ast::var::VariablePtr registerName( std::string const & name
			, ast::type::TypePtr type );
		ast::var::VariablePtr registerName( std::string const & name
			, ast::type::TypePtr type
			, ast::var::Flag flag );
		ast::var::VariablePtr registerSampler( std::string const & name
			, ast::type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		ast::var::VariablePtr registerImage( std::string const & name
			, ast::type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		bool hasVar( std::string const & name );
		ast::var::VariablePtr getVar( std::string const & name
			, ast::type::TypePtr type );

		inline ast::ShaderStage getType()const
		{
			return m_shader.getType();
		}

		inline ast::type::TypesCache & getTypesCache()const
		{
			return m_shader.getTypesCache();
		}

	private:
		ast::Shader const & m_shader;
		std::map< std::string, ast::var::VariablePtr > m_registered;
		std::map< std::string, ast::SamplerInfo > m_samplers;
		std::map< std::string, ast::ImageInfo > m_images;
	};
}

#endif
