#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain \
	writer.implementMainT< sdw::VoidT >( 16u, []( sdw::ComputeIn ){} )

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	void testImage( test::sdw_test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::StorageImage > )
			+ sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", 1u, 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declStorageImg< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer;
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declStorageImgArray< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT >
	void testImageAccessFormat( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testImage" + ast::debug::getName( FormatT ) );
		if constexpr ( isFloatFormat( FormatT ) )
		{
			testImage< FormatT, AccessT, Img1DBase >( testCounts );
			testImage< FormatT, AccessT, Img2DBase >( testCounts );
			testImage< FormatT, AccessT, Img3DBase >( testCounts );
			testImage< FormatT, AccessT, ImgCubeBase >( testCounts );
			testImage< FormatT, AccessT, ImgBufferBase >( testCounts );
			testImage< FormatT, AccessT, Img1DArrayBase >( testCounts );
			testImage< FormatT, AccessT, Img2DArrayBase >( testCounts );
			testImage< FormatT, AccessT, ImgCubeArrayBase >( testCounts );
			testImage< FormatT, AccessT, Img2DMSBase >( testCounts );
			testImage< FormatT, AccessT, Img2DMSArrayBase >( testCounts );
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			testImage< FormatT, AccessT, Img1DBase >( testCounts );
			testImage< FormatT, AccessT, Img2DBase >( testCounts );
			testImage< FormatT, AccessT, Img3DBase >( testCounts );
			testImage< FormatT, AccessT, ImgCubeBase >( testCounts );
			testImage< FormatT, AccessT, ImgBufferBase >( testCounts );
			testImage< FormatT, AccessT, Img1DArrayBase >( testCounts );
			testImage< FormatT, AccessT, Img2DArrayBase >( testCounts );
			testImage< FormatT, AccessT, ImgCubeArrayBase >( testCounts );
			testImage< FormatT, AccessT, Img2DMSBase >( testCounts );
			testImage< FormatT, AccessT, Img2DMSArrayBase >( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			testImage< FormatT, AccessT, Img1DBase >( testCounts );
			testImage< FormatT, AccessT, Img2DBase >( testCounts );
			testImage< FormatT, AccessT, Img3DBase >( testCounts );
			testImage< FormatT, AccessT, ImgCubeBase >( testCounts );
			testImage< FormatT, AccessT, ImgBufferBase >( testCounts );
			testImage< FormatT, AccessT, Img1DArrayBase >( testCounts );
			testImage< FormatT, AccessT, Img2DArrayBase >( testCounts );
			testImage< FormatT, AccessT, ImgCubeArrayBase >( testCounts );
			testImage< FormatT, AccessT, Img2DMSBase >( testCounts );
			testImage< FormatT, AccessT, Img2DMSArrayBase >( testCounts );
		}
		testEnd();
	}

	template< ast::type::ImageFormat FormatT >
		void testImageFormat( test::sdw_test::TestCounts & testCounts )
	{
			testImageAccessFormat< FormatT, ast::type::AccessKind::eRead >( testCounts );
			testImageAccessFormat< FormatT, ast::type::AccessKind::eWrite >( testCounts );
			testImageAccessFormat< FormatT, ast::type::AccessKind::eReadWrite >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterStorageImageDeclarations )
{
	sdwTestSuiteBegin();
	testImageFormat< ast::type::ImageFormat::eRgba32f >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRgba16f >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg32f >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg16f >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR32f >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR16f >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRgba32i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRgba16i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRgba8i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg32i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg16i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg8i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR32i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR16i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR8i >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRgba32u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRgba16u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRgba8u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg32u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg16u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eRg8u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR32u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR16u >( testCounts );
	testImageFormat< ast::type::ImageFormat::eR8u >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterStorageImageDeclarations )