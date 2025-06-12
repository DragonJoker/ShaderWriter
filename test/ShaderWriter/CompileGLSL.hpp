#pragma once

#include "WriterCommon.hpp"

#if SDW_HasCompilerGlsl
#	include <CompilerGlsl/compileGlsl.hpp>
#endif

namespace test
{
	bool retrieveIsGLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveGLSLVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveGLSLInfosSize( sdw_test::TestCounts const & testCounts );
	bool createGLSLContext();
	void destroyGLSLContext();
	bool compileGlsl( std::string_view shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
#if SDW_HasCompilerGlsl
	glsl::GlslExtensionSet getExtensions( uint32_t glslVersion );
	glsl::GlslConfig getGlslConfig( uint32_t glslVersion );
#endif
}
