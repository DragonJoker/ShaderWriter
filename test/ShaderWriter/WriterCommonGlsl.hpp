#pragma once

#include "WriterCommon.hpp"

namespace test::sdw_test
{
	void testWriteGlsl( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts );
}
