/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvShader_H___
#define ___SDW_SpirvShader_H___
#pragma once

#include <ShaderWriter/Shader.hpp>

#include <set>

namespace spirv
{
	class SpirvShader
	{
	public:
		SpirvShader( sdw::Shader const & shader );

		void registerVariable( ast::var::VariablePtr var );
		ast::var::VariablePtr registerName( std::string const & name
			, ast::type::TypePtr type
			, uint32_t flags );
		ast::var::VariablePtr registerName( std::string const & name
			, ast::type::TypePtr type );
		ast::var::VariablePtr registerName( std::string const & name
			, ast::type::TypePtr type
			, ast::var::Flag flag );
		ast::var::VariablePtr getVar( std::string const & name
			, ast::type::TypePtr type );

	private:
		sdw::Shader const & m_shader;
		std::map< std::string, ast::var::VariablePtr > m_registered;
		std::map< std::string, sdw::SamplerInfo > m_samplers;
		std::map< std::string, sdw::ImageInfo > m_images;
		std::set< std::string > m_sampledImages;
	};
}

#endif
