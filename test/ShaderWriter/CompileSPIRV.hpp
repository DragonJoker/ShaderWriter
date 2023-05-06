#pragma once

#include "WriterCommon.hpp"

#if SDW_Test_HasVulkan && SDW_HasVulkanLayer
#	pragma GCC diagnostic push
#	pragma GCC diagnostic ignored "-Wold-style-cast"
#	include <vulkan/vulkan.h>
#	include <VulkanLayer/VulkanLayer.hpp>
#	pragma GCC diagnostic pop
#endif

namespace test
{
	namespace sdw_test
	{
		struct SPIRVContext;
	}

	bool retrieveIsSpirVInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveVulkanVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveSPIRVVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
	uint32_t retrieveSpirVInfosSize( sdw_test::TestCounts const & testCounts );
	uint32_t getSpirVTargetEnv( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex );
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
