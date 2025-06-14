#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	template< bool ComparisonT >
	struct SamplerTypeT
	{
		static bool constexpr Comparison = ComparisonT;
	};

	using ParamTypes = testing::Types< SamplerTypeT< false >, SamplerTypeT< true > >;

	class ParamTypeNames
	{
	public:
		template< typename TypeParam >
		static std::string GetName( int )
		{
			if constexpr ( TypeParam::Comparison ) return "Comp";
			else return "NonComp";
		}
	};

	template< typename ParamT >
	struct TestParamsT : public SDWTest
	{
	};

	TYPED_TEST_SUITE( TestParamsT, ParamTypes, ParamTypeNames );

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

	TYPED_TEST( TestParamsT, testSampler )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSampler" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSamplerOptionalDisabled )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSamplerOptionalDisabled" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSamplerOptionalEnabled )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSamplerOptionalEnabled" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSamplerType )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSamplerType" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSamplerArray )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSamplerArray" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSamplerArrayOptionalDisabled )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSamplerArrayOptionalDisabled" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSamplerArrayOptionalEnabled )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSamplerArrayOptionalEnabled" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSamplerArrayType )
	{
		static bool constexpr ComparisonT = TypeParam::Comparison;
		sdwTestBegin( "testSamplerArrayType" );
		{
			astOn( "SplitParams" );
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
			astOn( "BindingHelper" );
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
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
