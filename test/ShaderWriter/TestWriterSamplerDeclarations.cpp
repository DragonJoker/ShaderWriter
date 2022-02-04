#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	uint32_t constexpr binding{ 4u };
	uint32_t constexpr set{ 3u };

	void checkStmt( sdw::stmt::SamplerDecl const & stmt
		, test::sdw_test::TestCounts & testCounts )
	{
		check( stmt.getBindingPoint() == binding );
		check( stmt.getDescriptorSet() == set );
	}

	template< bool ComparisonT >
	void checkSampler( sdw::type::Sampler const & sampler
		, test::sdw_test::TestCounts & testCounts )
	{
		check( sampler.isComparison() == ComparisonT );
	}

	template< bool ComparisonT >
	void testSampler( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSampler" + nameBase );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Sampler > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< bool ComparisonT >
	void testSamplerOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSamplerOptionalDisabled" + nameBase );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto name = "Value_dis";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set
				, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Sampler > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< bool ComparisonT >
	void testSamplerOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSamplerOptionalEnabled" + nameBase );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = "Value_en";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set
				, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Sampler > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< bool ComparisonT >
	void testSamplerComp( test::sdw_test::TestCounts & testCounts )
	{
		testSampler< ComparisonT >( testCounts );
		testSamplerOptionalDisabled< ComparisonT >( testCounts );
		testSamplerOptionalEnabled< ComparisonT >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterSamplerDeclarations )
{
	sdwTestSuiteBegin();
	testSamplerComp< false >( testCounts );
	testSamplerComp< true >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterSamplerDeclarations )
