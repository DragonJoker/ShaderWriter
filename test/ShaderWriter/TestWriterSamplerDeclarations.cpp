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
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSampler< ComparisonT >( name
				, { .binding = binding, .set = set } );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto name = "Value_dis";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set
				, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto name = "Value_dis";
			auto value = writer.declSampler< ComparisonT >( name
				, { .binding = binding, .set = set }
				, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value_en";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set
				, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value_en";
			auto value = writer.declSampler< ComparisonT >( name
				, { .binding = binding, .set = set }
				, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
	void testSamplerType( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSamplerType" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSampler< sdw::SamplerT< ComparisonT > >( name
				, binding
				, set );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSampler< sdw::SamplerT< ComparisonT > >( name
				, { .binding = binding, .set = set } );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
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
	void testSamplerArray( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSamplerArray" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, binding
				, set
				, 4u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, { .binding = binding, .set = set }
				, 4u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
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
	void testSamplerArrayOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSamplerArrayOptionalDisabled" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto name = "Value_dis";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, binding
				, set
				, 4u
				, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto name = "Value_dis";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, { .binding = binding, .set = set }
				, 4u
				, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< bool ComparisonT >
	void testSamplerArrayOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSamplerArrayOptionalEnabled" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value_en";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, binding
				, set
				, 4u
				, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value_en";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, { .binding = binding, .set = set }
				, 4u
				, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
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
	void testSamplerArrayType( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		testBegin( "testSamplerArrayType" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSamplerArray< sdw::SamplerT< ComparisonT > >( name
				, binding
				, set
				, 4u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSamplerArray< sdw::SamplerT< ComparisonT > >( name
				, { .binding = binding, .set = set }
				, 4u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			check( var->getName() == name );
			require( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			require( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
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
		testSamplerType< ComparisonT >( testCounts );

		testSamplerArray< ComparisonT >( testCounts );
		testSamplerArrayOptionalDisabled< ComparisonT >( testCounts );
		testSamplerArrayOptionalEnabled< ComparisonT >( testCounts );
		testSamplerArrayType< ComparisonT >( testCounts );
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
