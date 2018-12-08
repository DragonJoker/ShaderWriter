#pragma once

#include "WriterCommon.hpp"

namespace test
{
	bool createSPIRVContext( sdw_test::TestCounts & testCounts );
	void destroySPIRVContext( sdw_test::TestCounts & testCounts );
	bool compileSpirV( ::sdw::Shader const & shader
		, std::vector< uint32_t > const & spirv
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
}
