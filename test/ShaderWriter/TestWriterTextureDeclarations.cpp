#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain writer.implementFunction< sdw::Void >( "main", [](){} )

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	void testSampledImage( test::sdw_test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::SampledImage > )
			+ sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::SampledImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declSampledImageArray< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::SampledImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::SampledImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImageArray< FormatT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::SampledImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::SampledImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declSampledImageArray< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::SampledImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
	}

	template< ast::type::ImageFormat FormatT >
	void testSampledImageFormat( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSampledImage" + ast::debug::getName( FormatT ) );
		if constexpr ( isFloatFormat( FormatT ) )
		{
			testSampledImage< FormatT, Img1D >( testCounts );
			testSampledImage< FormatT, Img2D >( testCounts );
			testSampledImage< FormatT, Img3D >( testCounts );
			testSampledImage< FormatT, ImgCube >( testCounts );
			testSampledImage< FormatT, ImgBuffer >( testCounts );
			testSampledImage< FormatT, Img1DArray >( testCounts );
			testSampledImage< FormatT, Img2DArray >( testCounts );
			testSampledImage< FormatT, ImgCubeArray >( testCounts );
			testSampledImage< FormatT, Img2DMS >( testCounts );
			testSampledImage< FormatT, Img2DMSArray >( testCounts );

			if constexpr ( FormatT == ast::type::ImageFormat::eR32f
				|| FormatT == ast::type::ImageFormat::eR16f )
			{
				testSampledImage< FormatT, Img1DShadow >( testCounts );
				testSampledImage< FormatT, Img2DShadow >( testCounts );
				testSampledImage< FormatT, ImgCubeShadow >( testCounts );
				testSampledImage< FormatT, Img1DArrayShadow >( testCounts );
				testSampledImage< FormatT, Img2DArrayShadow >( testCounts );
				testSampledImage< FormatT, ImgCubeArrayShadow >( testCounts );
			}
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			testSampledImage< FormatT, Img1D >( testCounts );
			testSampledImage< FormatT, Img2D >( testCounts );
			testSampledImage< FormatT, Img3D >( testCounts );
			testSampledImage< FormatT, ImgCube >( testCounts );
			testSampledImage< FormatT, ImgBuffer >( testCounts );
			testSampledImage< FormatT, Img1DArray >( testCounts );
			testSampledImage< FormatT, Img2DArray >( testCounts );
			testSampledImage< FormatT, ImgCubeArray >( testCounts );
			testSampledImage< FormatT, Img2DMS >( testCounts );
			testSampledImage< FormatT, Img2DMSArray >( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			testSampledImage< FormatT, Img1D >( testCounts );
			testSampledImage< FormatT, Img2D >( testCounts );
			testSampledImage< FormatT, Img3D >( testCounts );
			testSampledImage< FormatT, ImgCube >( testCounts );
			testSampledImage< FormatT, ImgBuffer >( testCounts );
			testSampledImage< FormatT, Img1DArray >( testCounts );
			testSampledImage< FormatT, Img2DArray >( testCounts );
			testSampledImage< FormatT, ImgCubeArray >( testCounts );
			testSampledImage< FormatT, Img2DMS >( testCounts );
			testSampledImage< FormatT, Img2DMSArray >( testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	sdwTestSuiteBegin( "TestWriterTextureDeclarations" );
	testSampledImageFormat< ast::type::ImageFormat::eRgba32f >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRgba16f >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg32f >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg16f >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR32f >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR16f >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRgba32i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRgba16i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRgba8i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg32i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg16i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg8i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR32i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR16i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR8i >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRgba32u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRgba16u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRgba8u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg32u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg16u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eRg8u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR32u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR16u >( testCounts );
	testSampledImageFormat< ast::type::ImageFormat::eR8u >( testCounts );
	sdwTestSuiteEnd();
}
