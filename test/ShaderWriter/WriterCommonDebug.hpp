#pragma once

#include "WriterCommon.hpp"

namespace test::sdw_test
{
	void testWriteDebug( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, Compilers const & compilers
		, TestCounts & testCounts );
}
