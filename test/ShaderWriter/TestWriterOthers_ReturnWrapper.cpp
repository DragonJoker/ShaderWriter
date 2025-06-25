#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace test
{
	template< typename ParamT >
	struct FloatDoubleIntUIntParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct FloatDoubleIntUIntCppParamsT : public SDWTest
	{
	};

	template< typename LhsT, typename BlockT, typename RhsT >
	struct TypesT
	{
		using LhsType = LhsT;
		using BlockType = BlockT;
		using RhsType = RhsT;
	};

	using FloatDoubleIntUIntCppTypes = testing::Types< TypesT< sdw::Int8, sdw::Int32, int8_t >
		, TypesT< sdw::Int16, sdw::Int32, int16_t >
		, TypesT< sdw::Int32, sdw::Int32, int32_t >
		, TypesT< sdw::Int64, sdw::Int64, int64_t >
		, TypesT< sdw::UInt8, sdw::UInt32, uint8_t >
		, TypesT< sdw::UInt16, sdw::UInt32, uint16_t >
		, TypesT< sdw::UInt32, sdw::UInt32, uint32_t >
		, TypesT< sdw::UInt64, sdw::UInt64, uint64_t >
		, TypesT< sdw::Float, sdw::Float, float >
		, TypesT< sdw::Double, sdw::Float, double > >;

	class CppTypesNames
	{
	public:
		template< typename T >
		static std::string GetName( int v )
		{
			return TypesNames::GetName< typename T::LhsType >( v );
		}
	};

	TYPED_TEST_SUITE( FloatDoubleIntUIntParamsT, FloatDoubleIntUIntTypes, TypesNames );
	TYPED_TEST_SUITE( FloatDoubleIntUIntCppParamsT, FloatDoubleIntUIntCppTypes, CppTypesNames );

	TYPED_TEST( FloatDoubleIntUIntParamsT, testLocaleFromReturnWrapper )
	{
		sdwTestBegin( "testLocaleFromReturnWrapper" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			sdw::ArrayStorageBufferT< TypeParam > ssbo{ writer, "ssbo", TypeParam::makeType( writer.getTypesCache() ), ast::type::MemoryLayout::eStd430, 1, 0, true };

			auto func = writer.implementFunction< TypeParam >( "func"
				, [&writer]()
				{
					writer.returnStmt( getDefault< TypeParam >( writer ) );
				} );

			writer.implementMain( 32u
				, [&writer, &func, &ssbo]( sdw::ComputeIn const & in )
				{
					auto result = writer.declLocale( "result", func() );
					ssbo[in.localInvocationIndex] = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntCppParamsT, testReturnWrapperFromCpp )
	{
		using SdwType = typename TypeParam::LhsType;
		using BlockType = typename TypeParam::BlockType;
		using CppType = typename TypeParam::RhsType;
		sdwTestBegin( "testReturnWrapperFromCpp" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			sdw::ArrayStorageBufferT< BlockType > ssbo{ writer, "ssbo", BlockType::makeType( writer.getTypesCache() ), ast::type::MemoryLayout::eStd430, 1, 0, true };

			writer.implementMain( 32u
				, [&writer, &ssbo]( sdw::ComputeIn const & in )
				{
					auto result = writer.declLocale< SdwType >( "result" );
					result = CppType( 15 );
					ssbo[in.localInvocationIndex] = writer.cast< BlockType >( result );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

}

sdwTestSuiteMain()
