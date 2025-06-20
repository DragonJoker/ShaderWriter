#include "WriterCommon.hpp"

namespace test
{
	static constexpr ast::type::ImageFormat FormatT = ast::type::ImageFormat::SDW_TestImageFormat;

	using SampledImageTypesNames = SampledImageTypesNamesT< FormatT >;

	template< typename ParamT >
	struct SampledImageDeclaration : public SDWTest
	{
	};

	TYPED_TEST_SUITE( SampledImageDeclaration, SampledImageTypes, SampledImageTypesNames );

#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	TYPED_TEST( SampledImageDeclaration, testSampledBase )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( name, 1u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( name, { .binding = 1u, .set = 1u } );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SampledImageDeclaration, testSampledBaseArray )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledBaseArray" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( name, { .binding = 2u, .set = 2u }, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SampledImageDeclaration, testSampledOptDisabled )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledOptDisabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "value", 1u, 1u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "value", { .binding = 1u, .set = 1u }, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SampledImageDeclaration, testSampledArrayOptDisabled )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledArrayOptDisabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( "value", 1u, 1u, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( "value", { .binding = 1u, .set = 1u }, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SampledImageDeclaration, testSampledOptEnabled )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledOptEnabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( name, 1u, 1u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( name, { .binding = 1u, .set = 1u }, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SampledImageDeclaration, testSampledArrayOptEnabled )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledArrayOptEnabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( name, { .binding = 2u, .set = 2u }, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SampledImageDeclaration, testSampledType )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledType" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declSampledImg< sdw::SampledImageT< FormatT, DimT, ArrayedT, MsT > >( name, 1u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declSampledImg< sdw::SampledImageT< FormatT, DimT, ArrayedT, MsT > >( name, { .binding = 1u, .set = 1u });
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SampledImageDeclaration, testSampledTypeArray )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledTypeArray" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, sdw::type::AccessKind::eRead, DimT, sdw::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declSampledImgArray< sdw::SampledImageT< FormatT, DimT, ArrayedT, MsT > >( name, 2u, 2u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declSampledImgArray< sdw::SampledImageT< FormatT, DimT, ArrayedT, MsT > >( name, { .binding = 2u, .set = 2u }, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::SampledImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SampledImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
