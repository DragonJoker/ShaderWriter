#pragma once

#if SDW_Test_HasVulkan && SDW_HasVulkanLayer
#	include "WriterCommon.hpp"

#	include <VulkanLayer/VulkanLayer.hpp>

namespace test::sdw_test
{
	void validateShaderOnIndex( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers );
	void validateShaderOnIndex( ast::vk::ShaderPtrs const & shaders
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers );
}

#endif
