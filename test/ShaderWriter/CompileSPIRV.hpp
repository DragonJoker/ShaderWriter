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

	bool retrieveIsInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveVulkanVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveSPIRVVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveSpirvInfosSize( sdw_test::TestCounts const & testCounts );
	bool createSPIRVContext( sdw_test::TestCounts & testCounts );
	void destroySPIRVContext( sdw_test::TestCounts & testCounts );
	bool compileSpirV( ::ast::Shader const & shader
		, std::vector< uint32_t > const & spirv
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex );
#if SDW_Test_HasVulkan && SDW_HasVulkanLayer
	ast::vk::BuilderContext createBuilderContext( sdw_test::TestCounts & testCounts
		, uint32_t infoIndex );
	bool validateProgram( ast::vk::ProgramPipeline const & program
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex );
#endif
}
