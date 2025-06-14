#include "WriterCommon.hpp"

namespace
{
	static constexpr ast::type::ImageFormat FormatT = ast::type::ImageFormat::SDW_TestImageFormat;

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct SampledImageTypeT
	{
		static ast::type::ImageDim constexpr Dim = DimT;
		static bool constexpr Arrayed = ArrayedT;
		static bool constexpr Ms = MsT;
	};

	using ParamTypes = testing::Types< SampledImageTypeT< Img1DBase >
		, SampledImageTypeT< Img2DBase >
		, SampledImageTypeT< Img3DBase >
		, SampledImageTypeT< ImgCubeBase >
		, SampledImageTypeT< ImgBufferBase >
		, SampledImageTypeT< Img1DArrayBase >
		, SampledImageTypeT< Img2DArrayBase >
		, SampledImageTypeT< ImgCubeArrayBase > >;

	class ParamTypeNames
	{
	public:
		template< typename TypeParam >
		static std::string GetName( int )
		{
			static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
			static bool constexpr ArrayedT = TypeParam::Arrayed;
			static bool constexpr MsT = TypeParam::Ms;
			return sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
				+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
		}
	};

	template< typename ParamT >
	struct TestParamsT : public SDWTest
	{
	};

	TYPED_TEST_SUITE( TestParamsT, ParamTypes, ParamTypeNames );

#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	TYPED_TEST( TestParamsT, testSampledBase )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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

	TYPED_TEST( TestParamsT, testSampledBaseArray )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledBaseArray" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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

	TYPED_TEST( TestParamsT, testSampledOptDisabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledOptDisabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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

	TYPED_TEST( TestParamsT, testSampledArrayOptDisabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledArrayOptDisabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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

	TYPED_TEST( TestParamsT, testSampledOptEnabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledOptEnabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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

	TYPED_TEST( TestParamsT, testSampledArrayOptEnabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledArrayOptEnabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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

	TYPED_TEST( TestParamsT, testSampledType )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledType" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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

	TYPED_TEST( TestParamsT, testSampledTypeArray )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testSampledTypeArray" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
			+ sdw::debug::getImageTypeName( FormatT, DimT, ArrayedT, MsT );
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
