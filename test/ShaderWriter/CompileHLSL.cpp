#include "CompileHLSL.hpp"

#if defined( _WIN32 ) && SDW_Test_HasDirect3D11

#define _WIN32_WINNT 0x600

#include <cstdio>
#include <d3dcompiler.h>

#pragma warning( disable: 5262 )
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
		std::string getShaderModelA( ast::ShaderStage type
			, uint32_t shaderModel )
		{
			auto major = shaderModel / 10u;
			auto minor = shaderModel % 10u;
			auto model = std::to_string( major ) + "_" + std::to_string( minor );

			switch ( type )
			{
			case ast::ShaderStage::eVertex:
				model = "vs_" + model;
				break;
			case ast::ShaderStage::eTessellationControl:
				model = "hs_" + model;
				break;
			case ast::ShaderStage::eTessellationEvaluation:
				model = "ds_" + model;
				break;
			case ast::ShaderStage::eGeometry:
				model = "gs_" + model;
				break;
			case ast::ShaderStage::eCompute:
				model = "cs_" + model;
				break;
			case ast::ShaderStage::eFragment:
				model = "ps_" + model;
				break;
			case ast::ShaderStage::eMeshNV:
			case ast::ShaderStage::eMesh:
				model = "ms_" + model;
				break;
			case ast::ShaderStage::eTaskNV:
			case ast::ShaderStage::eTask:
				model = "as_" + model;
				break;
			case ast::ShaderStage::eCallable:
			case ast::ShaderStage::eRayGeneration:
			case ast::ShaderStage::eRayIntersection:
			case ast::ShaderStage::eRayMiss:
			case ast::ShaderStage::eRayAnyHit:
			case ast::ShaderStage::eRayClosestHit:
				model = "lib_" + model;
				break;
			default:
				break;
			}

			return model;
		}

		std::wstring getShaderModelW( ast::ShaderStage type
			, uint32_t shaderModel )
		{
			auto major = shaderModel / 10u;
			auto minor = shaderModel % 10u;
			auto model = std::to_wstring( major ) + L"_" + std::to_wstring( minor );

			switch ( type )
			{
			case ast::ShaderStage::eVertex:
				model = L"vs_" + model;
				break;
			case ast::ShaderStage::eTessellationControl:
				model = L"hs_" + model;
				break;
			case ast::ShaderStage::eTessellationEvaluation:
				model = L"ds_" + model;
				break;
			case ast::ShaderStage::eGeometry:
				model = L"gs_" + model;
				break;
			case ast::ShaderStage::eCompute:
				model = L"cs_" + model;
				break;
			case ast::ShaderStage::eFragment:
				model = L"ps_" + model;
				break;
			case ast::ShaderStage::eTaskNV:
			case ast::ShaderStage::eTask:
				model = L"as_" + model;
				break;
			case ast::ShaderStage::eMeshNV:
			case ast::ShaderStage::eMesh:
				model = L"ms_" + model;
				break;
			case ast::ShaderStage::eCallable:
			case ast::ShaderStage::eRayGeneration:
			case ast::ShaderStage::eRayIntersection:
			case ast::ShaderStage::eRayMiss:
			case ast::ShaderStage::eRayAnyHit:
			case ast::ShaderStage::eRayClosestHit:
				model = L"lib_" + model;
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

			DxcBuffer sourceBuffer{};
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
			std::vector< uint32_t > const & getShaderModels()const
			{
				return m_shaderModels;
			}

		private:
			std::vector< uint32_t > m_shaderModels{ 40u, 41u, 50u, 51u, 60u, 61u, 62u, 63u, 64u, 65u, 66u };
		};
	}

	bool retrieveIsHLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return true;
	}

	uint32_t retrieveHLSLVersion( sdw_test::TestCounts const & testCounts
		, [[maybe_unused]] uint32_t infoIndex )
	{
#if SDW_Test_Coverage
		return testCounts.hlsl->getShaderModels().back();
#else
		return testCounts.hlsl->getShaderModels()[infoIndex];
#endif
	}

	uint32_t retrieveHLSLInfosSize( [[maybe_unused]] sdw_test::TestCounts const & testCounts )
	{
#if SDW_Test_Coverage
		return 1u;
#else
		return uint32_t( testCounts.hlsl->getShaderModels().size() );
#endif
	}

	bool createHLSLContext( sdw_test::TestCounts & testCounts )
	{
		bool result = false;

		try
		{
			testCounts.hlsl = std::make_shared< sdw_test::HLSLContext >();
			result = true;
		}
		catch ( std::exception & exc )
		{
			testCounts << exc.what() << endl;
		}

		return result;
	}

	void destroyHLSLContext( sdw_test::TestCounts & testCounts )
	{
		testCounts.hlsl.reset();
	}

	bool compileHlsl( std::string_view shader
		, ast::ShaderStage type
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
		auto shaderModel = testCounts.hlsl->getShaderModels()[infoIndex];

		if ( isRayTraceStage( type )
			|| isMeshStage( type )
			|| shaderModel >= 60u )
		{
			return compileHlslDXC( shader
				, getShaderModelW( type, shaderModel )
				, errors
				, testCounts );
		}

		return compileHlslD3D11( shader
			, getShaderModelA( type, shaderModel )
			, errors
			, testCounts );
	}
}

#else

namespace test
{
	static std::vector< uint32_t > const & getShaderModels()
	{
		static std::vector< uint32_t > shaderModels{ 40u, 41u, 50u, 51u, 60u, 61u, 62u, 63u, 64u, 65u, 66u };
		return shaderModels;
	}

	bool retrieveIsHLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return false;
	}

	uint32_t retrieveHLSLVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
#if SDW_Test_Coverage
		return getShaderModels().back();
#else
		return getShaderModels()[infoIndex];
#endif
	}

	uint32_t retrieveHLSLInfosSize( sdw_test::TestCounts const & testCounts )
	{
#if SDW_Test_Coverage
		return 1u;
#else
		return uint32_t( getShaderModels().size() );
#endif
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
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
		return true;
	}
}

#endif
