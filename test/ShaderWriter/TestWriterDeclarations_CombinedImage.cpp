#include "WriterCommon.hpp"

namespace
{
	static constexpr ast::type::ImageFormat FormatT = ast::type::ImageFormat::SDW_TestImageFormat;

	static bool constexpr isShadowFormat = ( FormatT == ast::type::ImageFormat::eR32f )
		|| ( FormatT == ast::type::ImageFormat::eR16f );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct CombinedImageTypeT
	{
		static ast::type::ImageDim constexpr Dim = DimT;
		static bool constexpr Arrayed = ArrayedT;
		static bool constexpr Ms = MsT;
		static bool constexpr Depth = DepthT;
	};

	using ParamTypes = testing::Types< CombinedImageTypeT< Img1DBase, false >
		, CombinedImageTypeT< Img2DBase, false >
		, CombinedImageTypeT< Img3DBase, false >
		, CombinedImageTypeT< ImgCubeBase, false >
		, CombinedImageTypeT< ImgBufferBase, false >
		, CombinedImageTypeT< Img1DArrayBase, false >
		, CombinedImageTypeT< Img2DArrayBase, false >
		, CombinedImageTypeT< ImgCubeArrayBase, false >
		, CombinedImageTypeT< Img1DBase, true >
		, CombinedImageTypeT< Img2DBase, true >
		, CombinedImageTypeT< ImgCubeBase, true >
		, CombinedImageTypeT< Img1DArrayBase, true >
		, CombinedImageTypeT< Img2DArrayBase, true >
		, CombinedImageTypeT< ImgCubeArrayBase, true > >;

	class ParamTypeNames
	{
	public:
		template< typename TypeParam >
		static std::string GetName( int )
		{
			static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
			static bool constexpr ArrayedT = TypeParam::Arrayed;
			static bool constexpr MsT = TypeParam::Ms;
			static bool constexpr DepthT = TypeParam::Depth;
			return sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
				+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		}
	};

	template< typename ParamT >
	struct TestParamsT : public SDWTest
	{
	};

	TYPED_TEST_SUITE( TestParamsT, ParamTypes, ParamTypeNames );

#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	TYPED_TEST( TestParamsT, testCombinedImageBase )
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

	TYPED_TEST( TestParamsT, testCombinedImageArray )
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

	TYPED_TEST( TestParamsT, testCombinedImageOptionalDisabled )
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

	TYPED_TEST( TestParamsT, testCombinedImageArrayOptionalDisabled )
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

	TYPED_TEST( TestParamsT, testCombinedImageOptionalEnabled )
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

	TYPED_TEST( TestParamsT, testCombinedImageArrayOptionalEnabled )
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

	TYPED_TEST( TestParamsT, testCombinedImageType )
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

	TYPED_TEST( TestParamsT, testCombinedImageTypeArray )
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
