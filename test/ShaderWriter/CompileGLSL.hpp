#pragma once

#include "WriterCommon.hpp"

namespace test
{
	bool createGLSLContext( sdw_test::TestCounts & testCounts );
	void destroyGLSLContext( sdw_test::TestCounts & testCounts );
	bool compileGlsl( std::string const & shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
}
