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
		explicit HlslShader( ast::Shader const & shader
			, ast::ShaderStage stage );

		void registerVariable( ast::var::VariablePtr var );
		ast::var::VariablePtr registerBuiltin( ast::Builtin builtin
			, ast::type::TypePtr type
			, uint64_t flags );
		ast::var::VariablePtr registerName( std::string name
			, ast::type::TypePtr type
			, uint64_t flags );
		ast::var::VariablePtr registerName( std::string name
			, ast::type::TypePtr type );
		ast::var::VariablePtr registerName( std::string name
			, ast::type::TypePtr type
			, ast::var::Flag flag );
		ast::var::VariablePtr registerSampler( std::string name
			, ast::type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		ast::var::VariablePtr registerImage( std::string name
			, ast::type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		bool hasGlobalVariable( std::string const & name );
		ast::var::VariablePtr getGlobalVariable( std::string const & name
			, ast::type::TypePtr type );

		inline ast::ShaderStage getType()const
		{
			return m_shaderStage;
		}

		inline ast::type::TypesCache & getTypesCache()const
		{
			return m_typesCache;
		}

	private:
		ast::Shader const & m_shader;
		ast::ShaderStage m_shaderStage;
		mutable ast::type::TypesCache m_typesCache;
		std::map< std::string, ast::var::VariablePtr > m_registered;
		std::map< std::string, ast::SamplerInfo > m_samplers;
		std::map< std::string, ast::ImageInfo > m_images;
	};
}

#endif
