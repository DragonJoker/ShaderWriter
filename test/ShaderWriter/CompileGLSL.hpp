#pragma once

#include "WriterCommon.hpp"

namespace test
{
	bool retrieveIsGLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveGLSLVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveGLSLInfosSize( sdw_test::TestCounts const & testCounts );
	bool createGLSLContext( sdw_test::TestCounts & testCounts );
	void destroyGLSLContext( sdw_test::TestCounts & testCounts );
	bool compileGlsl( std::string_view shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
}
