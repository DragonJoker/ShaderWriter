#pragma once

#include "WriterCommon.hpp"

#if SDW_HasCompilerHlsl
#	include <CompilerHlsl/compileHlsl.hpp>
#endif

namespace test
{
	bool retrieveIsHLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveHLSLVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveHLSLRaytracingTier( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveHLSLInfosSize( sdw_test::TestCounts const & testCounts );
	bool createHLSLContext();
	void destroyHLSLContext();
	bool compileHlsl( std::string_view shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex );
}
