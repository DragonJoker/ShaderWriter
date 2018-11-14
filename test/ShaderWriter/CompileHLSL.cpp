#define _WIN32_WINNT 0x600

#include <stdio.h>
#include <d3dcompiler.h>

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

#include <string>
#include <iostream>

#pragma comment(lib,"d3dcompiler.lib")

namespace test
{
	bool compileHlsl( std::string const & shader
		, sdw::ShaderType type )
	{
		ID3DBlob * result{ nullptr };
		std::string model;

		switch ( type )
		{
		case sdw::ShaderType::eVertex:
			model = "vs_5_0";
			break;
		case sdw::ShaderType::eTessellationControl:
			model = "ds_5_0";
			break;
		case sdw::ShaderType::eTessellationEvaluation:
			model = "hs_5_0";
			break;
		case sdw::ShaderType::eGeometry:
			model = "gs_5_0";
			break;
		case sdw::ShaderType::eCompute:
			model = "cs_5_0";
			break;
		case sdw::ShaderType::eFragment:
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

		if ( FAILED( hr ) )
		{
			if ( errorBlob )
			{
				std::cout << reinterpret_cast< char * >( errorBlob->GetBufferPointer() ) << std::endl;
				errorBlob->Release();
			}

			if ( shaderBlob )
			{
				shaderBlob->Release();
			}

			return false;
		}

		if ( errorBlob )
		{
			errorBlob->Release();
		}

		if ( shaderBlob )
		{
			shaderBlob->Release();
		}

		return true;
	}
}
