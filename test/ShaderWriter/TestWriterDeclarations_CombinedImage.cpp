#include "WriterCommon.hpp"

namespace test
{
	static constexpr ast::type::ImageFormat FormatT = ast::type::ImageFormat::SDW_TestImageFormat;

	using CombinedImageTypesNames = CombinedImageTypesNamesT< FormatT >;

	static bool constexpr isShadowFormat = ( FormatT == ast::type::ImageFormat::eR32f )
		|| ( FormatT == ast::type::ImageFormat::eR16f );

	template< typename ParamT >
	struct CombinedImageDeclaration : public SDWTest
	{
	};

	TYPED_TEST_SUITE( CombinedImageDeclaration, CombinedImageTypes, CombinedImageTypesNames );

#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageBase )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 1u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( name, { .binding = 1u, .set = 1u } );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
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
		sdwTestEnd()
	}

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageArray )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 2u, 2u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( name, { .binding = 2u, .set = 2u }, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
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
		sdwTestEnd()
	}

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageOptionalDisabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "value", 1u, 1u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "value", { .binding = 1u, .set = 1u }, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
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
		sdwTestEnd()
	}

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageArrayOptionalDisabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( "value", 2u, 2u, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( "value", { .binding = 2u, .set = 2u }, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
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
		sdwTestEnd()
	}

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageOptionalEnabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 1u, 1u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( name, { .binding = 1u, .set = 1u }, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
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
		sdwTestEnd()
	}

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageArrayOptionalEnabled )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( name, 2u, 2u, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( name, { .binding = 2u, .set = 2u }, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
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
		sdwTestEnd()
	}

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageType )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declCombinedImg< sdw::CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > >( name, 1u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declCombinedImg< sdw::CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > >( name, { .binding = 1u, .set = 1u } );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
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
		sdwTestEnd()
	}

	TYPED_TEST( CombinedImageDeclaration, testCombinedImageTypeArray )
	{
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		static bool constexpr DepthT = TypeParam::Depth;
		sdwTestBegin( "testTextureBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
			+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "SplitParams" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declCombinedImgArray< sdw::CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > >( name, 2u, 2u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
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
		if constexpr ( !DepthT || isShadowFormat )
		{
			astOn( "BindingHelper" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declCombinedImgArray< sdw::CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > >( name, { .binding = 2u, .set = 2u }, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::CombinedImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eCombinedImageDecl );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
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
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
