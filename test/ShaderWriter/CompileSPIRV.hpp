#pragma once

#include "WriterCommon.hpp"

#include <VulkanLayer/VulkanLayer.hpp>

namespace test
{
	bool createSPIRVContext( sdw_test::TestCounts & testCounts );
	void destroySPIRVContext( sdw_test::TestCounts & testCounts );
	ast::vk::BuilderContext createBuilderContext( sdw_test::TestCounts & testCounts );
	bool compileSpirV( ::ast::Shader const & shader
		, std::vector< uint32_t > const & spirv
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
	void validateProgram( ast::vk::ProgramPipeline const & program
		, sdw_test::TestCounts & testCounts );
}
