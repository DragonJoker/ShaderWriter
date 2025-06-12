#pragma once

#include "WriterCommon.hpp"

namespace test::sdw_test
{
	std::string validateSpirVToGlsl( std::vector< uint32_t > const & spirv
		, ast::ShaderStage stage
		, test::TestCounts & testCounts
		, bool vulkanSemantics );
	std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
		, ast::ShaderStage stage
		, test::TestCounts & testCounts );
	std::string printSpvVersion( uint32_t spvVersion );

	void testWriteSpirV( ::ast::Shader const & shader
		, ::ast::PreprocessResult & preprocessResult
		, ::ast::ShaderStage stage
		, ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts );

	void testValidateSpirV( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts );
	void testValidateSpirV( ::ast::ShaderArray const & shader
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts );
	void testValidateSpirV( ::ast::ShaderPtrArray const & shader
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts );
}
