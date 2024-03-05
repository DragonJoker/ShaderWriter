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
		astCheck( stmt.getBindingPoint() == binding );
		astCheck( stmt.getDescriptorSet() == set );
	}

	template< bool ComparisonT >
	void checkSampler( sdw::type::Sampler const & sampler
		, test::sdw_test::TestCounts & testCounts )
	{
		astCheck( sampler.isComparison() == ComparisonT );
	}

	template< bool ComparisonT >
	void testSampler( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSampler" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
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
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
	}

	template< bool ComparisonT >
	void testSamplerOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSamplerOptionalDisabled" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto name = "Value_dis";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set
				, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			astCheck( shader.getStatements()->size() == count );
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
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
	}

	template< bool ComparisonT >
	void testSamplerOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSamplerOptionalEnabled" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value_en";
			auto value = writer.declSampler< ComparisonT >( name
				, binding
				, set
				, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
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
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
	}

	template< bool ComparisonT >
	void testSamplerType( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSamplerType" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSampler< sdw::SamplerT< ComparisonT > >( name
				, binding
				, set );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
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
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *var->getType() )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
	}

	template< bool ComparisonT >
	void testSamplerArray( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSamplerArray" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, binding
				, set
				, 4u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
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
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
	}

	template< bool ComparisonT >
	void testSamplerArrayOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSamplerArrayOptionalDisabled" + nameBase );
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
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			astCheck( shader.getStatements()->size() == count );
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
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
	}

	template< bool ComparisonT >
	void testSamplerArrayOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSamplerArrayOptionalEnabled" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value_en";
			auto value = writer.declSamplerArray< ComparisonT >( name
				, binding
				, set
				, 4u
				, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
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
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
	}

	template< bool ComparisonT >
	void testSamplerArrayType( test::sdw_test::TestCounts & testCounts )
	{
		std::string nameBase;

		if ( ComparisonT )
		{
			nameBase = "Comp";
		}

		astTestBegin( "testSamplerArrayType" + nameBase );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = "Value";
			auto value = writer.declSamplerArray< sdw::SamplerT< ComparisonT > >( name
				, binding
				, set
				, 4u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
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
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::Sampler > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			sdw::var::VariablePtr var = static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable();
			astCheck( var->getName() == name );
			astRequire( var->getType()->getKind() == sdw::type::Kind::eArray );
			auto elemType = static_cast< ast::type::Array const & >( *var->getType() ).getType();
			astRequire( elemType->getKind() == sdw::type::Kind::eSampler );
			checkSampler< ComparisonT >( static_cast< sdw::type::Sampler const & >( *elemType )
				, testCounts );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			checkStmt( static_cast< sdw::stmt::SamplerDecl const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
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
