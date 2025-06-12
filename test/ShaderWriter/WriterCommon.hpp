#pragma once

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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsequenced"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsequence-point"

#ifndef ForceDisplayShaders
#	define ForceDisplayShaders false
#endif

#define Compilers_None { true, false, false, false, ForceDisplayShaders }
#define Compilers_GLSL { false, false, false, true, ForceDisplayShaders }
#define Compilers_HLSL { false, false, true, false, ForceDisplayShaders }
#define Compilers_SPIRV { false, true, false, false, ForceDisplayShaders }

#define Compilers_NoGLSL { true, true, true, false, ForceDisplayShaders }
#define Compilers_NoHLSL { true, true, false, true, ForceDisplayShaders }
#define Compilers_NoSPIRV { true, false, true, true, ForceDisplayShaders }

#define Compilers_All { true, true, true, true, ForceDisplayShaders }
#define Compilers_AllButSpv16 { true, true, true, true, ForceDisplayShaders, 0x00010600u }

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
			SDWTest_API ~TestCounts()noexcept override = default;

			SDWTest_API TimerBlock beginTimer( std::string_view name );
			SDWTest_API void printTime( std::string const & text );
			ASTTest_API void printBlock( std::string const & text )override;
			ASTTest_API void printError( std::string const & text )override;

			bool isSpirVInitialised( uint32_t infoIndex )const;
			bool isSpvIgnored( uint32_t infoIndex, uint32_t ignoredSpvVersion )const;
			uint32_t getVulkanVersion( uint32_t infoIndex )const;
			uint32_t getSpirVVersion( uint32_t infoIndex )const;
			uint32_t getSpirvInfosSize()const;

			bool isHlslInitialised( uint32_t infoIndex )const;
			uint32_t getHlslVersion( uint32_t infoIndex )const;
			uint32_t getHlslInfosSize()const;

			bool isGlslInitialised( uint32_t infoIndex )const;
			uint32_t getGlslVersion( uint32_t infoIndex )const;
			uint32_t getGlslInfosSize()const;

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
			void doInitialise()override;
			void doCleanup()override;

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
			: public ::testing::Environment
		{
		public:
			SDWTest_API TestSuite( std::string const & name );
			SDWTest_API static void SetUpTestSuite();
			SDWTest_API static void TearDownTestSuite();
			SDWTest_API void SetUp() override;
			SDWTest_API void TearDown() override;

		private:
			std::unique_ptr< std::streambuf > tcout;
		};
	}

	struct Compilers
	{
		bool debug;
		bool spirV;
		bool hlsl;
		bool glsl;
		bool forceDisplay;
		uint32_t ignoredSpv{};
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

	SDWTest_API int testsMain( int argc, char ** argv, std::string_view testSuiteName );
}

class SDWTest
	: public ::testing::Test
{
public:
	SDWTest_API static void SetUpTestSuite();
	SDWTest_API static void TearDownTestSuite();
	SDWTest_API void SetUp() override;
	SDWTest_API void TearDown() override;

	SDWTest_API static std::shared_ptr< test::sdw_test::GLSLContext > glsl;
	SDWTest_API static std::shared_ptr< test::sdw_test::HLSLContext > hlsl;
	SDWTest_API static std::shared_ptr< test::sdw_test::SPIRVContext > spirv;
};

#define sdwTestBegin( name )\
	test::sdw_test::TestCounts testCounts;\
	testCounts.initialise( name );\
	{

#define sdwTestEnd()\
	}\
	testCounts.cleanup();

#define sdwTestSuiteMain()\
	int main( int argc, char ** argv )\
	{\
		return test::testsMain( argc, argv, SDW_TestSuiteNameString );\
	}

#pragma GCC diagnostic pop
#pragma clang diagnostic pop
