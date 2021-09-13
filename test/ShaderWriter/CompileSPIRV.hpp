#pragma once

#include "WriterCommon.hpp"

#if SDW_Test_HasVulkan && SDW_HasVulkanLayer
#	include <VulkanLayer/VulkanLayer.hpp>
#endif

namespace test
{
	namespace sdw_test
	{
		struct SPIRVContext;
	}

	uint32_t retrieveSPIRVVersion( sdw_test::SPIRVContext const & context );
	bool createSPIRVContext( sdw_test::TestCounts & testCounts );
	void destroySPIRVContext( sdw_test::TestCounts & testCounts );
	bool compileSpirV( ::ast::Shader const & shader
		, std::vector< uint32_t > const & spirv
		, std::string & errors
		, sdw_test::TestCounts & testCounts );
#if SDW_Test_HasVulkan && SDW_HasVulkanLayer
	ast::vk::BuilderContext createBuilderContext( sdw_test::TestCounts & testCounts );
	bool validateProgram( ast::vk::ProgramPipeline const & program
		, sdw_test::TestCounts & testCounts );
#endif
}
