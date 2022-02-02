#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	void testTexture( test::sdw_test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::Texture > )
			+ sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declTexture< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Texture > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eTextureDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declTextureArray< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Texture > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eTextureDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declTexture< FormatT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Texture > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declTextureArray< FormatT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Texture > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declTexture< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Texture > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eTextureDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declTextureArray< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Texture > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eTextureDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
	}

	template< ast::type::ImageFormat FormatT >
	void testTextureFormat( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTexture" + ast::debug::getName( FormatT ) );
		if constexpr ( isFloatFormat( FormatT ) )
		{
			testTexture< FormatT, Img1D >( testCounts );
			testTexture< FormatT, Img2D >( testCounts );
			testTexture< FormatT, Img3D >( testCounts );
			testTexture< FormatT, ImgCube >( testCounts );
			testTexture< FormatT, ImgBuffer >( testCounts );
			testTexture< FormatT, Img1DArray >( testCounts );
			testTexture< FormatT, Img2DArray >( testCounts );
			testTexture< FormatT, ImgCubeArray >( testCounts );
			testTexture< FormatT, Img2DMS >( testCounts );
			testTexture< FormatT, Img2DMSArray >( testCounts );

			if constexpr ( FormatT == ast::type::ImageFormat::eR32f
				|| FormatT == ast::type::ImageFormat::eR16f )
			{
				testTexture< FormatT, Img1DShadow >( testCounts );
				testTexture< FormatT, Img2DShadow >( testCounts );
				testTexture< FormatT, ImgCubeShadow >( testCounts );
				testTexture< FormatT, Img1DArrayShadow >( testCounts );
				testTexture< FormatT, Img2DArrayShadow >( testCounts );
				testTexture< FormatT, ImgCubeArrayShadow >( testCounts );
			}
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			testTexture< FormatT, Img1D >( testCounts );
			testTexture< FormatT, Img2D >( testCounts );
			testTexture< FormatT, Img3D >( testCounts );
			testTexture< FormatT, ImgCube >( testCounts );
			testTexture< FormatT, ImgBuffer >( testCounts );
			testTexture< FormatT, Img1DArray >( testCounts );
			testTexture< FormatT, Img2DArray >( testCounts );
			testTexture< FormatT, ImgCubeArray >( testCounts );
			testTexture< FormatT, Img2DMS >( testCounts );
			testTexture< FormatT, Img2DMSArray >( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			testTexture< FormatT, Img1D >( testCounts );
			testTexture< FormatT, Img2D >( testCounts );
			testTexture< FormatT, Img3D >( testCounts );
			testTexture< FormatT, ImgCube >( testCounts );
			testTexture< FormatT, ImgBuffer >( testCounts );
			testTexture< FormatT, Img1DArray >( testCounts );
			testTexture< FormatT, Img2DArray >( testCounts );
			testTexture< FormatT, ImgCubeArray >( testCounts );
			testTexture< FormatT, Img2DMS >( testCounts );
			testTexture< FormatT, Img2DMSArray >( testCounts );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterTextureDeclarations )
{
	sdwTestSuiteBegin();
	testTextureFormat< ast::type::ImageFormat::eRgba32f >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRgba16f >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg32f >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg16f >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR32f >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR16f >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRgba32i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRgba16i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRgba8i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg32i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg16i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg8i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR32i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR16i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR8i >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRgba32u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRgba16u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRgba8u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg32u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg16u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eRg8u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR32u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR16u >( testCounts );
	testTextureFormat< ast::type::ImageFormat::eR8u >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterTextureDeclarations )
