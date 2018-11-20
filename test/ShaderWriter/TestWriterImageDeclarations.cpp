#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>
#include <ShaderWriter/Intrinsics.hpp>
#include <ShaderWriter/Sampler.hpp>
#include <ShaderWriter/Shader.hpp>
#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

namespace
{
#define DummyMain writer.implementFunction< void >( "main", [](){} )

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	void testImage( test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::Image > )
			+ sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declImage< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Image > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declImageArray< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Image > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Image > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declImageArray< FormatT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, 6u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Image > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declImage< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Image > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declImageArray< FormatT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 6u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< sdw::Image > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
	}

	template< ast::type::ImageFormat FormatT >
	void testImageFormat( test::TestCounts & testCounts )
	{
		testBegin( "testImage" + ast::debug::getName( FormatT ) );
		if ( isFloatFormat( FormatT ) )
		{
			testImage< FormatT, Img1D >( testCounts );
			testImage< FormatT, Img2D >( testCounts );
			testImage< FormatT, Img3D >( testCounts );
			testImage< FormatT, ImgRect >( testCounts );
			testImage< FormatT, ImgCube >( testCounts );
			testImage< FormatT, ImgBuffer >( testCounts );
			testImage< FormatT, Img1DArray >( testCounts );
			testImage< FormatT, Img2DArray >( testCounts );
			testImage< FormatT, ImgCubeArray >( testCounts );
			testImage< FormatT, Img2DMS >( testCounts );
			testImage< FormatT, Img2DMSArray >( testCounts );
		}
		else if ( isSIntFormat( FormatT ) )
		{
			testImage< FormatT, Img1D >( testCounts );
			testImage< FormatT, Img2D >( testCounts );
			testImage< FormatT, Img3D >( testCounts );
			testImage< FormatT, ImgRect >( testCounts );
			testImage< FormatT, ImgCube >( testCounts );
			testImage< FormatT, ImgBuffer >( testCounts );
			testImage< FormatT, Img1DArray >( testCounts );
			testImage< FormatT, Img2DArray >( testCounts );
			testImage< FormatT, ImgCubeArray >( testCounts );
			testImage< FormatT, Img2DMS >( testCounts );
			testImage< FormatT, Img2DMSArray >( testCounts );
		}
		else if ( isUIntFormat( FormatT ) )
		{
			testImage< FormatT, Img1D >( testCounts );
			testImage< FormatT, Img2D >( testCounts );
			testImage< FormatT, Img3D >( testCounts );
			testImage< FormatT, ImgRect >( testCounts );
			testImage< FormatT, ImgCube >( testCounts );
			testImage< FormatT, ImgBuffer >( testCounts );
			testImage< FormatT, Img1DArray >( testCounts );
			testImage< FormatT, Img2DArray >( testCounts );
			testImage< FormatT, ImgCubeArray >( testCounts );
			testImage< FormatT, Img2DMS >( testCounts );
			testImage< FormatT, Img2DMSArray >( testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterImageDeclarations" );
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
	testSuiteEnd();
}
