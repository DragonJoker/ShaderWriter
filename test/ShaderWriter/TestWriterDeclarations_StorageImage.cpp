#include "WriterCommon.hpp"

namespace test
{
	static constexpr ast::type::ImageFormat FormatT = ast::type::ImageFormat::SDW_TestImageFormat;

	using StorageImageTypesNames = StorageImageTypesNamesT< FormatT >;

	template< typename ParamT >
	struct StorageImageDeclaration : public SDWTest
	{
	};

	TYPED_TEST_SUITE( StorageImageDeclaration, StorageImageTypes, StorageImageTypesNames );

#define DummyMain \
	writer.implementMainT< sdw::VoidT >( 16u, []( sdw::ComputeIn ){} )

	TYPED_TEST( StorageImageDeclaration, testImage )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageBase" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 1u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 1u, .set = 1u } );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( StorageImageDeclaration, testImageArray )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageArray" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 2u, .set = 2u }, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( StorageImageDeclaration, testImageOptionalDisabled )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageOptionalDisabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", 1u, 1u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", { .binding = 1u, .set = 1u }, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( StorageImageDeclaration, testImageArrayOptionalDisabled )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageArrayOptionalDisabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", 1u, 1u, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( "value", { .binding = 1u, .set = 1u }, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( StorageImageDeclaration, testImageOptionalEnabled )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageOptionalEnabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 1u, 1u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 1u, .set = 1u }, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( StorageImageDeclaration, testImageArrayOptionalEnabled )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageArrayOptionalEnabled" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, 2u, 2u, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( name, { .binding = 2u, .set = 2u }, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( StorageImageDeclaration, testImageType )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageType" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declStorageImg< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, 1u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_T";
			auto value = writer.declStorageImg< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, { .binding = 1u, .set = 1u } );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( StorageImageDeclaration, testImageTypeArray )
	{
		static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
		static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
		static bool constexpr ArrayedT = TypeParam::Arrayed;
		static bool constexpr MsT = TypeParam::Ms;
		sdwTestBegin( "testImageTypeArray" );
		auto nameBase = sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
			+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		{
			astOn( "SplitParams" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declStorageImgArray< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, 2u, 2u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		{
			astOn( "BindingHelper" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_T";
			auto value = writer.declStorageImgArray< sdw::StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >( name, { .binding = 2u, .set = 2u }, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< sdw::StorageImage > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
			test::validateShader( writer.getShader(), testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
