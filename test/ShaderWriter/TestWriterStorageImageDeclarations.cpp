#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	std::string getImageFormatName( ast::type::ImageFormat value )
	{
		std::string result{ "Undefined" };

		switch ( value )
		{
		case ast::type::ImageFormat::eUnknown:
			result = "Unknown";
			break;
		case ast::type::ImageFormat::eRgba32f:
			result = "RGBA32f";
			break;
		case ast::type::ImageFormat::eRgba16f:
			result = "RGBA16f";
			break;
		case ast::type::ImageFormat::eRg32f:
			result = "RG32f";
			break;
		case ast::type::ImageFormat::eRg16f:
			result = "RG16f";
			break;
		case ast::type::ImageFormat::eR32f:
			result = "R32f";
			break;
		case ast::type::ImageFormat::eR16f:
			result = "R16f";
			break;
		case ast::type::ImageFormat::eRgba32i:
			result = "RGBA32i";
			break;
		case ast::type::ImageFormat::eRgba16i:
			result = "RGBA16i";
			break;
		case ast::type::ImageFormat::eRgba8i:
			result = "RGBA8i";
			break;
		case ast::type::ImageFormat::eRg32i:
			result = "RG32i";
			break;
		case ast::type::ImageFormat::eRg16i:
			result = "RG16i";
			break;
		case ast::type::ImageFormat::eRg8i:
			result = "RG8i";
			break;
		case ast::type::ImageFormat::eR32i:
			result = "R32i";
			break;
		case ast::type::ImageFormat::eR16i:
			result = "R16i";
			break;
		case ast::type::ImageFormat::eR8i:
			result = "R8i";
			break;
		case ast::type::ImageFormat::eRgba32u:
			result = "RGBA32u";
			break;
		case ast::type::ImageFormat::eRgba16u:
			result = "RGBA16u";
			break;
		case ast::type::ImageFormat::eRgba8u:
			result = "RGBA8u";
			break;
		case ast::type::ImageFormat::eRg32u:
			result = "RG32u";
			break;
		case ast::type::ImageFormat::eRg16u:
			result = "RG16u";
			break;
		case ast::type::ImageFormat::eRg8u:
			result = "RG8u";
			break;
		case ast::type::ImageFormat::eR32u:
			result = "R32u";
			break;
		case ast::type::ImageFormat::eR16u:
			result = "R16u";
			break;
		case ast::type::ImageFormat::eR8u:
			result = "R8u";
			break;
		default:
			break;
		}

		return result;
	}

#define DummyMain \
	writer.implementMainT< sdw::VoidT >( 16u, []( sdw::ComputeIn ){} )

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	void testImage( test::sdw_test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 1u, .set = 1u } );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 2u, .set = 2u }, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", { .binding = 1u, .set = 1u }, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", 1u, 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", { .binding = 1u, .set = 1u }, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 1u, .set = 1u }, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 2u, .set = 2u }, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declStorageImg< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declStorageImg< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, { .binding = 1u, .set = 1u } );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declStorageImgArray< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declStorageImgArray< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, { .binding = 2u, .set = 2u }, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
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
		testBegin( "testImage" + getImageFormatName( FormatT ) );
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

#define testName testConcat( TestWriterStorageImageDeclarations, SDW_TestImageFormat )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
	testImageFormat< ast::type::ImageFormat::SDW_TestImageFormat >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
