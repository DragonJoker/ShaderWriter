#pragma once

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsequenced"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsequence-point"

#include "Common.hpp"
#include "WriterCommonHelpers.hpp"

#if defined( _WIN32 )
#	if defined( TestWriterCommon_EXPORTS )
#		define SDWTest_API __declspec( dllexport )
#	else
#		define SDWTest_API __declspec( dllimport )
#	endif
#else
#	define SDWTest_API
#endif

#ifndef ForceDisplayShaders
#	define ForceDisplayShaders false
#endif

#define MakeSPVVersion( major, minor ) uint32_t( ( uint32_t( major ) << 16u ) | ( uint32_t( minor ) << 8u ) )
#define MakeVkVersion( major, minor ) uint32_t( ( uint32_t( major ) << 22 ) | ( uint32_t( minor ) << 12 ) )
#define MakeHLSLVersion( major, minor ) uint32_t( ( uint32_t( major ) * 10 ) + uint32_t( minor ) )
#define MakeGLSLVersion( major, minor ) uint32_t( ( uint32_t( major ) * 100 ) + ( uint32_t( minor ) * 10 ) )

#define CompilerSPIRVToggleAll( v ) { v, 0u, 0u, 0u, 2u }
#define CompilerSPIRVDisabled CompilerSPIRVToggleAll( false )
#define CompilerSPIRVEnableAll CompilerSPIRVToggleAll( true )
#define CompilerSPIRVEnableOne( vkMajor, vkMinor, spvMajor, spvMinor, debugLevel ) { true, 0u, MakeSPVVersion( spvMajor, spvMinor ), MakeVkVersion( vkMajor, vkMinor ), debugLevel }
#define CompilerSPIRVIgnoreVersion( major, minor ) { true, MakeSPVVersion( major, minor ), 0u, 0u, 2u }

#define CompilerGLSLToggleAll( v ) { v, 0u }
#define CompilerGLSLDisabled CompilerGLSLToggleAll( false )
#define CompilerGLSLEnableAll CompilerGLSLToggleAll( true )
#define CompilerGLSLEnableOne( major, minor ) { true, MakeGLSLVersion( major, minor ) }

#define CompilerHLSLToggleAll( v ) { v, 0u }
#define CompilerHLSLDisabled CompilerHLSLToggleAll( false )
#define CompilerHLSLEnableAll CompilerHLSLToggleAll( true )
#define CompilerHLSLEnableOne( major, minor ) { true, MakeHLSLVersion( major, minor ) }

#define Compilers_None { true, CompilerSPIRVDisabled, CompilerHLSLDisabled, CompilerGLSLDisabled, ForceDisplayShaders }
#define Compilers_GLSL { false, CompilerSPIRVDisabled, CompilerHLSLDisabled, CompilerGLSLEnableAll, ForceDisplayShaders }
#define Compilers_HLSL { false, CompilerSPIRVDisabled, CompilerHLSLEnableAll, CompilerGLSLDisabled, ForceDisplayShaders }
#define Compilers_SPIRV { false, CompilerSPIRVEnableAll, CompilerHLSLDisabled, CompilerGLSLDisabled, ForceDisplayShaders }

#define Compilers_NoGLSL { true, CompilerSPIRVEnableAll, CompilerHLSLEnableAll, CompilerGLSLDisabled, ForceDisplayShaders }
#define Compilers_NoHLSL { true, CompilerSPIRVEnableAll, CompilerHLSLDisabled, CompilerGLSLEnableAll, ForceDisplayShaders }
#define Compilers_NoSPIRV { true, CompilerSPIRVDisabled, CompilerHLSLEnableAll, CompilerGLSLEnableAll, ForceDisplayShaders }

#define Compilers_All { true, CompilerSPIRVEnableAll, CompilerHLSLEnableAll, CompilerGLSLEnableAll, ForceDisplayShaders }

#define Compilers_AllButSPIRV16 { true, CompilerSPIRVIgnoreVersion( 1, 6 ), CompilerHLSLEnableAll, CompilerGLSLEnableAll, ForceDisplayShaders }
#define Compilers_OnlyOneSPIRV( vkMajor, vkMinor, spvMajor, spvMinor, debugLevel ) { false, CompilerSPIRVEnableOne( vkMajor, vkMinor, spvMajor, spvMinor, debugLevel ), CompilerHLSLDisabled, CompilerGLSLDisabled, ForceDisplayShaders }
#define Compilers_OnlyOneHLSL( major, minor ) { false, CompilerSPIRVDisabled, CompilerHLSLEnableOne( major, minor ), CompilerGLSLDisabled, ForceDisplayShaders }
#define Compilers_OnlyOneGLSL( major, minor ) { false, CompilerSPIRVDisabled, CompilerHLSLDisabled, CompilerGLSLEnableOne( major, minor ), ForceDisplayShaders }

#ifndef CurrentCompilers
#	define CurrentCompilers Compilers_All
#endif

class SDWTest;

namespace test
{
	namespace sdw_test
	{
		struct GLSLContext;
		struct HLSLContext;
		struct SPIRVContext;
		struct TestCounts;

		using Clock = std::chrono::steady_clock;
		using TimePoint = Clock::time_point;
		using Duration = std::chrono::microseconds;

		struct TimerBlock
		{
			operator bool()const
			{
				return true;
			}

			SDWTest_API TimerBlock( std::string_view name
				, TestCounts & testCounts );
			SDWTest_API ~TimerBlock()noexcept;

		private:
			std::string m_name;
			TestCounts & m_testCounts;
			TimePoint m_start{ Clock::now() };
		};

		struct TestCounts
			: test::TestCounts
		{
			SDWTest_API TestCounts();
			SDWTest_API ~TestCounts()noexcept override;

			SDWTest_API TimerBlock beginTimer( std::string_view name );
			SDWTest_API void printTime( std::string const & text );
			SDWTest_API void printBlock( std::string const & text )override;
			SDWTest_API void printError( std::string const & text )override;

			SDWTest_API bool isSpirVInitialised( uint32_t infoIndex )const;
			SDWTest_API bool isSpvIgnored( uint32_t infoIndex, uint32_t ignoredVersion )const;
			SDWTest_API bool isSpvRequested( uint32_t infoIndex, uint32_t requestedVersion )const;
			SDWTest_API bool isVulkanRequested( uint32_t infoIndex, uint32_t requestedVersion )const;
			SDWTest_API uint32_t getVulkanVersion( uint32_t infoIndex )const;
			SDWTest_API uint32_t getSpirVVersion( uint32_t infoIndex )const;
			SDWTest_API uint32_t getSpirvInfosSize()const;

			SDWTest_API bool isHlslInitialised( uint32_t infoIndex )const;
			SDWTest_API bool isHlslRequested( uint32_t infoIndex, uint32_t requestedVersion )const;
			SDWTest_API uint32_t getHlslVersion( uint32_t infoIndex )const;
			SDWTest_API uint32_t getHlslInfosSize()const;

			SDWTest_API bool isGlslInitialised( uint32_t infoIndex )const;
			SDWTest_API bool isGlslRequested( uint32_t infoIndex, uint32_t requestedVersion )const;
			SDWTest_API uint32_t getGlslVersion( uint32_t infoIndex )const;
			SDWTest_API uint32_t getGlslInfosSize()const;

			GLSLContext const & glsl()const
			{
				return *m_glsl;
			}

			HLSLContext const & hlsl()const
			{
				return *m_hlsl;
			}

			SPIRVContext const & spirv()const
			{
				return *m_spirv;
			}

			std::string expectedError;

		private:
			SDWTest_API void doInitialise()override;
			SDWTest_API void doCleanup()override;

			friend struct TimerBlock;
			void doEndTimer( std::string const & name, TimePoint startTime )noexcept;

		private:
			TimePoint m_start;
			std::map< std::string, std::pair< Duration, uint32_t > > m_durations;
			std::shared_ptr< GLSLContext > m_glsl;
			std::shared_ptr< HLSLContext > m_hlsl;
			std::shared_ptr< SPIRVContext > m_spirv;
		};

		class TestSuite
			: public test::TestSuite
		{
		public:
			SDWTest_API TestSuite( std::string const & name );
			SDWTest_API ~TestSuite()override;
			SDWTest_API void SetUp() override;
			SDWTest_API void TearDown() override;

		private:
			std::unique_ptr< std::streambuf > tcout;
		};

		SDWTest_API int testsMain( int argc, char ** argv, std::string_view testSuiteName );
	}

	struct SpirvCompiler
	{
		bool enable;
		uint32_t ignoredSpv{};
		uint32_t requestedSpv{};
		uint32_t requestedVulkan{};
		uint32_t requestedDebugLevel{ ~0u };
	};

	struct HlslCompiler
	{
		bool enable;
		uint32_t requestedModel{};
	};

	struct GlslCompiler
	{
		bool enable;
		uint32_t requestedVersion{};
	};

	struct Compilers
	{
		bool debug;
		SpirvCompiler spirV;
		HlslCompiler hlsl;
		GlslCompiler glsl;
		bool forceDisplay;
	};

	std::string printVkVersion( uint32_t vkVersion );
	std::string printEntryPoint( ast::EntryPointConfig const & entryPoint );
	void displayShader( std::string_view name
		, std::string const & shader
		, test::TestCounts & testCounts
		, bool force
		, bool lines );
	std::string printShader( std::string_view name
		, std::string const & shader
		, bool lines );

	SDWTest_API void writeShader( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void writeShader( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void writeShader( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void writeShader( sdw::PipelineWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShaders( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShaders( ast::ShaderArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShaders( ast::ShaderPtrArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShader( ast::Shader const & writer
		, ast::EntryPointConfig const & entryPoint
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShader( ast::Shader const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );

	SDWTest_API void writeProgram( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void writeProgram( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateProgram( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateProgram( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );

	SDWTest_API void expectError( std::string value
		, sdw_test::TestCounts & testCounts );
}

class SDWTest
	: public ::testing::Test
{
public:
	SDWTest_API static void SetUpTestSuite();
	SDWTest_API static void TearDownTestSuite();

	SDWTest_API ~SDWTest()override;
	SDWTest_API void SetUp() override;
	SDWTest_API void TearDown() override;

	SDWTest_API static std::shared_ptr< test::sdw_test::GLSLContext > glsl;
	SDWTest_API static std::shared_ptr< test::sdw_test::HLSLContext > hlsl;
	SDWTest_API static std::shared_ptr< test::sdw_test::SPIRVContext > spirv;
};

#define sdwTestBegin( name )\
	test::sdw_test::TestCounts testCounts;\
	testCounts.initialise( name );\
	{\
		astOn( name )

#define sdwTestEnd()\
	}\
	testCounts.cleanup();

#define sdwTestSuiteMain()\
	int main( int argc, char ** argv )\
	{\
		return test::sdw_test::testsMain( argc, argv, SDW_TestSuiteNameString );\
	}

#pragma GCC diagnostic pop
#pragma clang diagnostic pop
