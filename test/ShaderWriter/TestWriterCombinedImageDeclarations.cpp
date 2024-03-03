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

#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	void testTexture( test::sdw_test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( name, { .binding = 1u, .set = 1u } );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( name, { .binding = 2u, .set = 2u }, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( "value", 1u, 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 2u, 2u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declCombinedImg< sdw::CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declCombinedImgArray< sdw::CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;

			if constexpr ( DimT == ast::type::ImageDim::eBuffer )
			{
				test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
	}

	template< ast::type::ImageFormat FormatT >
	void testTextureFormat( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTexture" + getImageFormatName( FormatT ) );
		if constexpr ( isFloatFormat( FormatT ) )
		{
			testTexture< FormatT, Img1DBase, false >( testCounts );
			testTexture< FormatT, Img2DBase, false >( testCounts );
			testTexture< FormatT, Img3DBase, false >( testCounts );
			testTexture< FormatT, ImgCubeBase, false >( testCounts );
			testTexture< FormatT, ImgBufferBase, false >( testCounts );
			testTexture< FormatT, Img1DArrayBase, false >( testCounts );
			testTexture< FormatT, Img2DArrayBase, false >( testCounts );
			testTexture< FormatT, ImgCubeArrayBase, false >( testCounts );
			testTexture< FormatT, Img2DMSBase, false >( testCounts );
			testTexture< FormatT, Img2DMSArrayBase, false >( testCounts );

			if constexpr ( FormatT == ast::type::ImageFormat::eR32f
				|| FormatT == ast::type::ImageFormat::eR16f )
			{
				testTexture< FormatT, Img1DBase, true >( testCounts );
				testTexture< FormatT, Img2DBase, true >( testCounts );
				testTexture< FormatT, ImgCubeBase, true >( testCounts );
				testTexture< FormatT, Img1DArrayBase, true >( testCounts );
				testTexture< FormatT, Img2DArrayBase, true >( testCounts );
				testTexture< FormatT, ImgCubeArrayBase, true >( testCounts );
			}
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			testTexture< FormatT, Img1DBase, false >( testCounts );
			testTexture< FormatT, Img2DBase, false >( testCounts );
			testTexture< FormatT, Img3DBase, false >( testCounts );
			testTexture< FormatT, ImgCubeBase, false >( testCounts );
			testTexture< FormatT, ImgBufferBase, false >( testCounts );
			testTexture< FormatT, Img1DArrayBase, false >( testCounts );
			testTexture< FormatT, Img2DArrayBase, false >( testCounts );
			testTexture< FormatT, ImgCubeArrayBase, false >( testCounts );
			testTexture< FormatT, Img2DMSBase, false >( testCounts );
			testTexture< FormatT, Img2DMSArrayBase, false >( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			testTexture< FormatT, Img1DBase, false >( testCounts );
			testTexture< FormatT, Img2DBase, false >( testCounts );
			testTexture< FormatT, Img3DBase, false >( testCounts );
			testTexture< FormatT, ImgCubeBase, false >( testCounts );
			testTexture< FormatT, ImgBufferBase, false >( testCounts );
			testTexture< FormatT, Img1DArrayBase, false >( testCounts );
			testTexture< FormatT, Img2DArrayBase, false >( testCounts );
			testTexture< FormatT, ImgCubeArrayBase, false >( testCounts );
			testTexture< FormatT, Img2DMSBase, false >( testCounts );
			testTexture< FormatT, Img2DMSArrayBase, false >( testCounts );
		}
		testEnd();
	}
}

#define testName testConcat( TestWriterCombinedImageDeclarations, SDW_TestImageFormat )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
	testTextureFormat< ast::type::ImageFormat::SDW_TestImageFormat >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
