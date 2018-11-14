/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslShader_H___
#define ___SDW_HlslShader_H___
#pragma once

#include "ShaderWriter/Shader.hpp"

namespace sdw::hlsl
{
	class HlslShader
	{
	public:
		HlslShader( Shader const & shader );

		void registerVariable( var::VariablePtr var );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		var::VariablePtr registerSampler( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		var::VariablePtr registerImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		bool hasVar( std::string const & name );
		var::VariablePtr getVar( std::string const & name
			, type::TypePtr type );

	private:
		sdw::Shader const & m_shader;
		std::map< std::string, var::VariablePtr > m_registered;
		std::map< std::string, SamplerInfo > m_samplers;
		std::map< std::string, ImageInfo > m_images;
	};
}

#endif
