#pragma once

#include "WriterCommon.hpp"

namespace test::sdw_test
{
	void testWriteDebug( ::ast::Shader const & shader
		, ::ast::PreprocessResult const & preprocessResult
		, ::ast::ShaderStage stage
		, ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, TestCounts & testCounts );
}
