/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#pragma once

#include <ShaderAST/ShaderASTPrerequisites.hpp>

namespace test
{
	/**
	*\~french
	*\brief
	*	Initialise les globales de glslang.
	*\~english
	*\brief
	*	Initialises glslang globals.
	*/
	void initialiseGlslang();
	/**
	*\~french
	*\brief
	*	Nettoie les globales de glslang.
	*\~english
	*\brief
	*	Cleans up glslang globals.
	*/
	void cleanupGlslang();
	/**
	*\~french
	*\brief
	*	Transpile un shader GLSL en SPIR-V.
	*\~english
	*\brief
	*	Transpiles a GLSL shader to SPIR-V.
	*/
	std::vector< uint32_t > compileGlslToSpv( ast::ShaderStage stage
		, std::string_view shader
		, uint32_t spvVersion = 100/* default to SPIR-V 1.0*/ );
}
