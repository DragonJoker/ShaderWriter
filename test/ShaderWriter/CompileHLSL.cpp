#include "CompileHLSL.hpp"

#if defined( _WIN32 ) && SDW_Test_HasDirect3D11

#define _WIN32_WINNT 0x600

#include <cstdio>
#include <d3dcompiler.h>

#include <string>
#include <iostream>

#pragma comment(lib,"d3dcompiler.lib")

namespace test
{
	namespace sdw_test
	{
		struct HLSLContext
		{
		};
	}

	bool createHLSLContext( sdw_test::TestCounts & testCounts )
	{
		return true;
	}

	void destroyHLSLContext( sdw_test::TestCounts & testCounts )
	{
	}

	bool compileHlsl( std::string const & shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts )
	{
		std::string model;

		switch ( type )
		{
		case ast::ShaderStage::eVertex:
			model = "vs_5_0";
			break;
		case ast::ShaderStage::eTessellationControl:
			model = "ds_5_0";
			break;
		case ast::ShaderStage::eTessellationEvaluation:
			model = "hs_5_0";
			break;
		case ast::ShaderStage::eGeometry:
			model = "gs_5_0";
			break;
		case ast::ShaderStage::eCompute:
			model = "cs_5_0";
			break;
		case ast::ShaderStage::eFragment:
			model = "ps_5_0";
			break;
		default:
			break;
		}

		UINT flags = D3DCOMPILE_DEBUG;

		ID3DBlob * shaderBlob{ nullptr };
		ID3DBlob * errorBlob{ nullptr };
		HRESULT hr = D3DCompile( shader.data()
			, shader.size()
			, nullptr
			, nullptr
			, D3D_COMPILE_STANDARD_FILE_INCLUDE
			, "main"
			, model.c_str()
			, flags
			, 0
			, &shaderBlob
			, &errorBlob );

		if ( errorBlob )
		{
			errors += reinterpret_cast< char * >( errorBlob->GetBufferPointer() );
			errorBlob->Release();
		}

		if ( shaderBlob )
		{
			shaderBlob->Release();
		}

		return !FAILED( hr );
	}
}

#else

namespace test
{
	bool createHLSLContext( sdw_test::TestCounts & testCounts )
	{
		return true;
	}

	void destroyHLSLContext( sdw_test::TestCounts & testCounts )
	{
	}

	bool compileHlsl( std::string const & shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts )
	{
		return true;
	}
}

#endif
