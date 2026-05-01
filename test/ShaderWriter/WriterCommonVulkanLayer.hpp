#pragma once

#if SDW_Test_HasVulkan
#	include "WriterCommon.hpp"

#	include "VulkanLayer.hpp"

namespace test::sdw_test
{
	void validateShaderOnIndex( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers );
	void validateShaderOnIndex( vk::ShaderPtrs const & shaders
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers );
}

#endif
