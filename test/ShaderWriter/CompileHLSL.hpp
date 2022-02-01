#pragma once

#include "WriterCommon.hpp"

namespace test
{
	bool retrieveIsHLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveHLSLVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveHLSLInfosSize( sdw_test::TestCounts const & testCounts );
	bool createHLSLContext( sdw_test::TestCounts & testCounts );
	void destroyHLSLContext( sdw_test::TestCounts & testCounts );
	bool compileHlsl( std::string_view shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex );
}
