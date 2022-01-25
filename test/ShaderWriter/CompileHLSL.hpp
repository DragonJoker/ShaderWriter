#pragma once

#include "WriterCommon.hpp"

namespace test
{
	bool createHLSLContext( sdw_test::TestCounts & testCounts );
	void destroyHLSLContext( sdw_test::TestCounts & testCounts );
	bool compileHlsl( std::string_view shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
}
