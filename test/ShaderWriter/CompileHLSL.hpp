#pragma once

#include "WriterCommon.hpp"

namespace test
{
	bool createHLSLContext( sdw_test::TestCounts & testCounts );
	void destroyHLSLContext( sdw_test::TestCounts & testCounts );
	bool compileHlsl( std::string const & shader
		, ::sdw::ShaderType type
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
}
