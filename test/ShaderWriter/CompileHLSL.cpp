#include "CompileHLSL.hpp"

#if defined( _WIN32 ) && SDW_Test_HasDirect3D11

#define _WIN32_WINNT 0x600

#include <cstdio>
#include <d3dcompiler.h>

#include <string>
#include <string_view>
#include <iostream>

#pragma comment(lib,"d3dcompiler.lib")

#if SDW_Test_HasDXC
#	pragma warning( disable:5204 )
#	include <Windows.h>
#	include <wrl/client.h>
#	include <dxcapi.h>
#endif

namespace test
{
	namespace
	{
		std::string getShaderModelA( ast::ShaderStage type )
		{
			std::string model;

			switch ( type )
			{
			case ast::ShaderStage::eVertex:
				model = "vs_5_0";
				break;
			case ast::ShaderStage::eTessellationControl:
				model = "hs_5_0";
				break;
			case ast::ShaderStage::eTessellationEvaluation:
				model = "ds_5_0";
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
			case ast::ShaderStage::eCallable:
				model = "ps_6_6";
				break;
			case ast::ShaderStage::eRayGeneration:
				model = "ps_6_6";
				break;
			case ast::ShaderStage::eRayIntersection:
				model = "ps_6_6";
				break;
			case ast::ShaderStage::eRayMiss:
				model = "ps_6_6";
				break;
			case ast::ShaderStage::eRayAnyHit:
				model = "ps_6_6";
				break;
			case ast::ShaderStage::eRayClosestHit:
				model = "ps_6_6";
				break;
			default:
				break;
			}

			return model;
		}

		std::wstring getShaderModelW( ast::ShaderStage type )
		{
			std::wstring model;

			switch ( type )
			{
			case ast::ShaderStage::eVertex:
				model = L"vs_5_0";
				break;
			case ast::ShaderStage::eTessellationControl:
				model = L"hs_5_0";
				break;
			case ast::ShaderStage::eTessellationEvaluation:
				model = L"ds_5_0";
				break;
			case ast::ShaderStage::eGeometry:
				model = L"gs_5_0";
				break;
			case ast::ShaderStage::eCompute:
				model = L"cs_5_0";
				break;
			case ast::ShaderStage::eFragment:
				model = L"ps_5_0";
				break;
			case ast::ShaderStage::eTask:
				model = L"as_6_5";
				break;
			case ast::ShaderStage::eMesh:
				model = L"ms_6_5";
				break;
			case ast::ShaderStage::eCallable:
				model = L"lib_6_6";
				break;
			case ast::ShaderStage::eRayGeneration:
				model = L"lib_6_6";
				break;
			case ast::ShaderStage::eRayIntersection:
				model = L"lib_6_6";
				break;
			case ast::ShaderStage::eRayMiss:
				model = L"lib_6_6";
				break;
			case ast::ShaderStage::eRayAnyHit:
				model = L"lib_6_6";
				break;
			case ast::ShaderStage::eRayClosestHit:
				model = L"lib_6_6";
				break;
			default:
				break;
			}

			return model;
		}

		bool compileHlslDXC( std::string_view shader
			, std::wstring const & model
			, std::string & errors
			, sdw_test::TestCounts & testCounts )
		{
#if SDW_Test_HasDXC
			using namespace Microsoft::WRL;

			ComPtr< IDxcUtils > pUtils;
			auto hr = DxcCreateInstance( CLSID_DxcUtils
				, IID_PPV_ARGS( pUtils.GetAddressOf() ) );

			ComPtr< IDxcBlobEncoding > pSource;
			hr = pUtils->CreateBlob( shader.data()
				, uint32_t( shader.size() )
				, CP_UTF8
				, pSource.GetAddressOf() );

			std::vector< LPCWSTR > arguments;
			//-E for the entry point (eg. PSMain)
			arguments.push_back( L"-E" );
			arguments.push_back( L"main" );

			//-T for the target profile (eg. ps_6_2)
			arguments.push_back( L"-T" );
			arguments.push_back( model.c_str() );

			//Strip reflection data and pdbs (see later)
			arguments.push_back( L"-Qstrip_debug" );
			arguments.push_back( L"-Qstrip_reflect" );

			arguments.push_back( DXC_ARG_WARNINGS_ARE_ERRORS ); //-WX
			arguments.push_back( DXC_ARG_DEBUG ); //-Zi
			arguments.push_back( DXC_ARG_PACK_MATRIX_ROW_MAJOR ); //-Zp

			DxcBuffer sourceBuffer;
			sourceBuffer.Ptr = pSource->GetBufferPointer();
			sourceBuffer.Size = pSource->GetBufferSize();
			sourceBuffer.Encoding = 0;

			ComPtr< IDxcCompiler3 > pCompiler;
			hr = DxcCreateInstance( CLSID_DxcCompiler, IID_PPV_ARGS( &pCompiler ) );

			ComPtr< IDxcResult > pCompileResult;
			hr = pCompiler->Compile( &sourceBuffer
				, arguments.data()
				, uint32_t( arguments.size() )
				, nullptr
				, IID_PPV_ARGS( pCompileResult.GetAddressOf() ) );

			//Error Handling
			ComPtr< IDxcBlobUtf8 > pErrors;
			hr = pCompileResult->GetOutput( DXC_OUT_ERRORS
				, IID_PPV_ARGS( pErrors.GetAddressOf() )
				, nullptr );
			bool isCompiled = false;

			if ( pErrors && pErrors->GetStringLength() > 0 )
			{
				std::vector< std::string > ignored{ "DXIL.dll not found."
					, "Resulting DXIL will not be signed for use in release environments."
					, "warning:   \r\n\n" };
				std::string compErrors = ( char * )pErrors->GetBufferPointer();

				for ( auto & ignore : ignored )
				{
					auto i = compErrors.find( ignore );

					if ( i != std::string::npos )
					{
						compErrors.replace( i, ignore.size(), "" );
					}
				}

				isCompiled = compErrors.empty();

				if ( !isCompiled )
				{
					errors += compErrors;
				}
			}
			else
			{
				isCompiled = true;
			}

			return isCompiled;
#else
			return true;
#endif
		}

		bool compileHlslD3D11( std::string_view shader
			, std::string const & model
			, std::string & errors
			, sdw_test::TestCounts & testCounts )
		{
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

	bool compileHlsl( std::string_view shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts )
	{
		if ( isRayTraceStage( type )
			|| isMeshStage( type ) )
		{
			return compileHlslDXC( shader
				, getShaderModelW( type )
				, errors
				, testCounts );
		}

		return compileHlslD3D11( shader
			, getShaderModelA( type )
			, errors
			, testCounts );
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
