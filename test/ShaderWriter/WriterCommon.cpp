#include "WriterCommon.hpp"

#include "CompileGLSL.hpp"
#include "CompileHLSL.hpp"
#include "CompileSPIRV.hpp"
#include "GlslToSpv.hpp"
#include "WriterCommonDebug.hpp"
#include "WriterCommonGlsl.hpp"
#include "WriterCommonHlsl.hpp"
#include "WriterCommonSpirV.hpp"
#include "WriterCommonVulkanLayer.hpp"

#include <ShaderAST/Visitors/PreprocessShader.hpp>

#pragma warning( disable: 5262 )
#include <iomanip>

#if SDWTest_DisplayTimes
#	include <format>
#endif

namespace test
{
	namespace
	{
		std::string printNumber( uint32_t index )
		{
			std::stringstream stream;
			stream << std::setw( 6 ) << std::left << index;
			return stream.str();
		}

		std::string printStage( ast::ShaderStage stage )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				return "Vertex";
			case ast::ShaderStage::eTessellationControl:
				return "Tessellation Control";
			case ast::ShaderStage::eTessellationEvaluation:
				return "Tessellation Evaluation";
			case ast::ShaderStage::eGeometry:
				return "Geometry";
			case ast::ShaderStage::eFragment:
				return "Fragment";
			case ast::ShaderStage::eTaskNV:
				return "TaskNV";
			case ast::ShaderStage::eMeshNV:
				return "MeshNV";
			case ast::ShaderStage::eTask:
				return "Task";
			case ast::ShaderStage::eMesh:
				return "Mesh";
			case ast::ShaderStage::eCompute:
				return "Compute";
			case ast::ShaderStage::eRayGeneration:
				return "Ray Generation";
			case ast::ShaderStage::eRayClosestHit:
				return "Ray Closest Hit";
			case ast::ShaderStage::eRayMiss:
				return "Ray Miss";
			case ast::ShaderStage::eRayIntersection:
				return "Ray Intersection";
			case ast::ShaderStage::eRayAnyHit:
				return "Ray Any Hit";
			case ast::ShaderStage::eCallable:
				return "Ray Callable";
			default:
				return "Unknown???"; 
			}
		}

		uint32_t getVkMajor( uint32_t vkVersion )
		{
			return ( ( vkVersion >> 22u ) & 0x7FU );
		}

		uint32_t getVkMinor( uint32_t vkVersion )
		{
			return ( ( vkVersion >> 12u ) & 0x3FFU );
		}

		std::vector< uint8_t > getSpecData( ::ast::SpecConstantInfo const & info )
		{
			return std::vector< uint8_t >( size_t( getSize( info.type
					, ast::type::MemoryLayout::eStd430 ) )
				, 0 );
		}

		::ast::SpecialisationInfo getSpecialisationInfo( ::ast::Shader const & shader )
		{
			auto & specInfo = shader.getSpecConstants();
			::ast::SpecialisationInfo result;

			for ( auto & info : specInfo )
			{
				result.data.push_back( { info.second, getSpecData( info.second ) } );
			}

			return result;
		}

#if SDWTest_DisplayTimes
		float getMs( sdw_test::Duration const & duration )
		{
			return float( duration.count() ) / 1000.0f;
		}
#endif
	}

	namespace sdw_test
	{
		//*****************************************************************************************

		TestSuite::~TestSuite() = default;

		TestSuite::TestSuite( std::string const & name )
			: test::TestSuite{ name }
		{
		}

		void TestSuite::SetUp()
		{
			initialiseGlslang();
		}

		void TestSuite::TearDown()
		{
			cleanupGlslang();
		}

		//*****************************************************************************************

		TimerBlock::TimerBlock( std::string_view name
			, TestCounts & testCounts )
			: m_name{ name }
			, m_testCounts{ testCounts }
		{
		}

		TimerBlock::~TimerBlock()noexcept
		{
			m_testCounts.doEndTimer( m_name, m_start );
		}

		//*****************************************************************************************

		TestCounts::~TestCounts()noexcept = default;

		TestCounts::TestCounts()
			: m_glsl{ SDWTest::glsl }
			, m_hlsl{ SDWTest::hlsl }
			, m_spirv{ SDWTest::spirv }
		{
		}

		TimerBlock TestCounts::beginTimer( std::string_view name )
		{
			m_durations.try_emplace( std::string{ name }, Duration{}, uint32_t{} );
			return TimerBlock{ name, *this };
		}

		void TestCounts::printTime( std::string const & text )
		{
			std::cout << text << std::endl;
		}

		void TestCounts::printBlock( std::string const & text )
		{
			std::cout << text << std::endl;
			test::TestCounts::printBlock( text );
		}

		void TestCounts::printError( std::string const & text )
		{
			for ( auto rit = m_traces.rbegin(); rit != m_traces.rend(); ++rit )
			{
				auto trace = *rit;
				std::cout << trace->file << ":" << trace->line << " - " << trace->message << std::endl;
			}
			std::cout << text << std::endl;
			test::TestCounts::printError( text );
		}

		bool TestCounts::isSpirVInitialised( uint32_t infoIndex )const
		{
			return retrieveIsSpirVInitialised( *this, infoIndex );
		}

		bool TestCounts::isSpvIgnored( uint32_t infoIndex, uint32_t ignoredSpvVersion )const
		{
			return retrieveSPIRVVersion( *this, infoIndex ) == ignoredSpvVersion;
		}

		uint32_t TestCounts::getVulkanVersion( uint32_t infoIndex )const
		{
			return retrieveVulkanVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getSpirVVersion( uint32_t infoIndex )const
		{
			return retrieveSPIRVVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getSpirvInfosSize()const
		{
			return retrieveSpirVInfosSize( *this );
		}

		bool TestCounts::isHlslInitialised( uint32_t infoIndex )const
		{
			return retrieveIsHLSLInitialised( *this, infoIndex );
		}

		uint32_t TestCounts::getHlslVersion( uint32_t infoIndex )const
		{
			return retrieveHLSLVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getHlslInfosSize()const
		{
			return retrieveHLSLInfosSize( *this );
		}

		bool TestCounts::isGlslInitialised( uint32_t infoIndex )const
		{
			return retrieveIsGLSLInitialised( *this, infoIndex );
		}

		uint32_t TestCounts::getGlslVersion( uint32_t infoIndex )const
		{
			return retrieveGLSLVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getGlslInfosSize()const
		{
			return retrieveGLSLInfosSize( *this );
		}

		void TestCounts::doInitialise()
		{
			m_start = Clock::now();
		}

		void TestCounts::doCleanup()
		{
#if SDWTest_DisplayTimes
			auto endTime = Clock::now();
			size_t maxNameSize{};
			for ( auto & [name, _] : m_durations )
				maxNameSize = std::max( name.size(), maxNameSize );
			Duration counted{};
			std::stringstream stream;
			stream << testName << "\n";
			stream << std::format( "  {:>{}} {:>10} {:>10} {:>17}\n"
				, "name", maxNameSize, "total ms", "instances", "ms per instance" );

			for ( auto & [name, durationCount] : m_durations )
			{
				stream << std::format( "  {:>{}} {:>10.2f} {:>10} {:>17.2f}\n"
					, name, maxNameSize
					, getMs( durationCount.first ), durationCount.second
					, getMs( durationCount.first / durationCount.second )  );
				counted += durationCount.first;
			}

			Duration total = std::chrono::duration_cast< Duration >( endTime - m_start );
			stream << std::format( "  total: {:>.2f} ms, remnants: {:>.2f} ms\n"
				, getMs( total ), getMs( total - counted ) );
			printTime( stream.str() );
#endif
		}

		void TestCounts::doEndTimer( std::string const & name, TimePoint startTime )noexcept
		{
			auto endTime = Clock::now();
			if ( auto it = m_durations.find( name );
				it != m_durations.end() )
			{
				it->second.first += std::chrono::duration_cast< Duration >( endTime - startTime );
				++it->second.second;
			}
		}

		//*****************************************************************************************

		int testsMain( int argc, char ** argv, std::string_view testSuiteName )
		{
			std::locale::global( std::locale{ "C" } );
			testing::InitGoogleTest( &argc, argv );
			auto suite = new test::sdw_test::TestSuite{ std::string{ testSuiteName } };
			testing::AddGlobalTestEnvironment( suite );
			return RUN_ALL_TESTS();
		}

		//*****************************************************************************************
	}

	std::string printVkVersion( uint32_t vkVersion )
	{
		std::stringstream stream;
		stream << getVkMajor( vkVersion ) << "." << getVkMinor( vkVersion );
		return stream.str();
	}

	std::string printEntryPoint( ast::EntryPointConfig const & entryPoint )
	{
		return printStage( entryPoint.stage ) + " stage, entry point :[" + entryPoint.name + "]";
	}

	std::string printShader( std::string_view name
		, std::string const & shader
		, bool lines )
	{
		std::string result;

		if ( !name.empty() )
		{
			result += "////////////////////////////////////////////////////////////\n";
			result += "// " + std::string{ name } + "\n";
			result += "////////////////////////////////////////////////////////////\n";
		}

		if ( lines )
		{
			std::stringstream stream{ shader };
			std::stringstream out;
			std::string line;
			uint32_t index = 1u;

			while ( std::getline( stream, line, '\n' ) )
			{
				out << printNumber( index++ ) << line << std::endl;
			}

			result += out.str() + "\n";
		}
		else
		{
			result += "\n" + shader;
		}

		result += "\n";
		return result;
	}

	void displayShader( std::string_view name
		, std::string const & shader
		, test::TestCounts & testCounts
		, bool force
		, bool lines )
	{
		if ( force )
		{
			testCounts.printBlock( printShader( name, shader, lines ) );
		}
	}

	static ast::PreprocessResult preprocessShader( ::ast::ShaderAllocatorBlock & allocator
		, ::ast::Shader const & shader
		, ::ast::EntryPointConfig const & entryPoint
		, sdw_test::TestCounts & testCounts )
	{
		auto timerBlock = testCounts.beginTimer( "preprocessShader" );
		auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
		return ::ast::preprocessShader( allocator, shader, *statements );
	}

	void writeShader( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		auto allocatorBlock = testCounts.allocator.getBlock();
		auto specialisation = getSpecialisationInfo( shader );
		for ( auto & entryPoint : entryPoints )
		{
			astOn( printEntryPoint( entryPoint ) );
			auto preprocessedResult = preprocessShader( *allocatorBlock, shader, entryPoint, testCounts );
			testWriteDebug( shader, preprocessedResult, entryPoint.stage, specialisation, compilers, testCounts );
			testWriteSpirV( shader, preprocessedResult, entryPoint.stage, specialisation, compilers, testCounts );
			testWriteGlsl( shader, preprocessedResult, entryPoint.stage, specialisation, compilers, testCounts );
			testWriteHlsl( shader, preprocessedResult, entryPoint.stage, specialisation, compilers, testCounts );
		}
	}

	void writeShader( ::ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		ast::EntryPointConfigArray entryPoints{ &shader.getAllocator() };
		entryPoints.emplace_back( shader.getType(), "main" );
		writeShader( shader
			, entryPoints
			, testCounts
			, compilers );
	}

	void writeShader( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		writeShader( writer.getShader()
			, testCounts
			, compilers );
	}

	void writeShader( sdw::PipelineWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		writeShader( writer.getShader()
			, ast::listEntryPoints( *writer.getShader().getStatements() )
			, testCounts
			, compilers );
	}

	void writeProgram( ::ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		if ( astOn( "Write program" ) )
		{
			writeShader( shader
				, ast::listEntryPoints( *shader.getStatements() )
				, testCounts
				, compilers );
		}
	}

	void writeProgram( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		writeProgram( writer.getShader()
			, testCounts
			, compilers );
	}

	void expectError( std::string value
		, sdw_test::TestCounts & testCounts )
	{
		testCounts.expectedError = std::move( value );
	}

	void validateShaders( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		if ( astOn( "Validate shaders" ) )
		{
			testValidateSpirV( shader, entryPoints, compilers, testCounts );
		}
	}

	void validateShaders( ast::ShaderArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		if ( astOn( "Validate shaders" ) )
		{
			testValidateSpirV( shaders, compilers, testCounts );
		}
	}

	void validateShaders( ast::ShaderPtrArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		if ( astOn( "Validate shaders" ) )
		{
			testValidateSpirV( shaders, compilers, testCounts );
		}
	}

	void validateShader( ast::Shader const & shader
		, ast::EntryPointConfig const & entryPoint
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		if ( astOn( "Validate shader" ) )
		{
			ast::EntryPointConfigArray entryPoints{ &shader.getAllocator() };
			entryPoints.push_back( entryPoint );
			validateShaders( shader, entryPoints, testCounts, compilers );
		}
	}

	void validateShader( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		validateShader( shader
			, ::ast::EntryPointConfig{ shader.getType(), "main" }
			, testCounts
			, compilers );
	}

	void validateProgram( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		if ( astOn( "Validate program" ) )
		{
			if ( auto entryPoints = ast::listEntryPoints( *shader.getStatements() );
				entryPoints.size() > 1u )
			{
				validateShaders( shader
					, entryPoints
					, testCounts
					, compilers );
			}
			else
			{
				validateShader( shader
					, entryPoints.front()
					, testCounts
					, compilers );
			}
		}
	}

	void validateProgram( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		validateProgram( writer.getShader()
			, testCounts
			, compilers );
	}
}

//*************************************************************************************************

std::shared_ptr< test::sdw_test::GLSLContext > SDWTest::glsl;
std::shared_ptr< test::sdw_test::HLSLContext > SDWTest::hlsl;
std::shared_ptr< test::sdw_test::SPIRVContext > SDWTest::spirv;

SDWTest::~SDWTest() = default;

void SDWTest::SetUpTestSuite()
{
	test::createGLSLContext();
	test::createHLSLContext();
	test::createSPIRVContext();
}

void SDWTest::TearDownTestSuite()
{
	test::destroySPIRVContext();
	test::destroyHLSLContext();
	test::destroyGLSLContext();
}

void SDWTest::SetUp()
{
}

void SDWTest::TearDown()
{
}

//*************************************************************************************************
