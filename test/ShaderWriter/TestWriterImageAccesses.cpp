#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>

namespace
{
#pragma region imageSize
	/**
	*name
	*	imageSize
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSizeTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageSize" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto j = writer.declLocale( "j"
							, s.getSize() );
					} );
				test::writeShader( writer
					, testCounts
					, true, false, false );
				test::writeShader( writer
					, testCounts
					, false, true, true );
				test::validateShader( writer.getShader()
					, testCounts );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSamplesTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( MsT )
			{
				auto name = "testImageSamples" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							auto j = writer.declLocale( "j"
								, s.getSamples() );
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageLoadTester
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadableV< AccessT > )
			{
				auto name = "testImageLoad" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.load( test::getDefault< Coords >( writer )
										, test::getDefault< sdw::Int >( writer ) ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
										, s.load( test::getDefault< Coords >( writer ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageStore
	/**
	*name
	*	imageStore
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageStoreTester
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isWritableV< AccessT > )
			{
				auto name = "testImageStore" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								s.store( test::getDefault< Coords >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								s.store( test::getDefault< Coords >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicAddTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isAtomicFloatFormat( FormatT )
					|| isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicAdd" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicAdd( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicAdd( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicAdd( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicAdd( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicAdd( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicAdd( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicAdd( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicAdd( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );

					if constexpr ( !isAtomicFloatFormat( FormatT ) )
					{
						test::writeShader( writer
							, testCounts
							, true, false, false );
						test::validateShader( writer.getShader()
							, testCounts );
					}

					test::writeShader( writer
						, testCounts
						, false, ( FormatT == ast::type::ImageFormat::eR32i || FormatT == ast::type::ImageFormat::eR32u ), true );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicMin
	/**
	*name
	*	imageAtomicMin
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicMinTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicMin" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicMin( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicMin( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicMin( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicMin( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicMin( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicMin( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicMin( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicMin( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicMax
	/**
	*name
	*	imageAtomicMax
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicMaxTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicMax" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicMax( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicMax( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicMax( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicMax( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicMax( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicMax( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicMax( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicMax( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicAnd
	/**
	*name
	*	imageAtomicAnd
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicAndTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicAnd" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicAnd( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicAnd( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicAnd( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicAnd( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicAnd( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicAnd( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicAnd( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicAnd( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicOr
	/**
	*name
	*	imageAtomicOr
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicOrTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicOr" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicOr( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicOr( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicOr( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicOr( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicOr( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicOr( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicOr( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicOr( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicXor
	/**
	*name
	*	imageAtomicXor
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicXorTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicXor" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicXor( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicXor( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicXor( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicXor( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicXor( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicXor( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicXor( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicXor( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchange
	/**
	*name
	*	imageAtomicExchange
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicExchangeTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isAtomicFloatFormat( FormatT )
					|| isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicExchange" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicExchange( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicExchange( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicExchange( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicExchange( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicExchange( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicExchange( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicExchange( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicExchange( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );

					if constexpr ( !isFloatFormat( FormatT ) )
					{
						test::writeShader( writer
							, testCounts
							, true, false, false );
						test::validateShader( writer.getShader()
							, testCounts );
					}

					test::writeShader( writer
						, testCounts
						, false, ( FormatT == ast::type::ImageFormat::eR32i || FormatT == ast::type::ImageFormat::eR32u ), true );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwap
	/**
	*name
	*	imageAtomicCompSwap
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicCompSwapTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicCompSwap" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto j = writer.declLocale( "j"
									, s.atomicCompSwap( test::getDefault< CoordsT >( writer )
										, test::getDefault< sdw::Int >( writer )
										, test::getDefault< FetchT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicCompSwap( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicCompSwap( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicCompSwap( test::getDefault< CoordsT >( writer )
									, test::getDefault< sdw::Int >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
							else
							{
								auto j = writer.declLocale( "j"
									, s.atomicCompSwap( test::getDefault< CoordsT >( writer )
										, test::getDefault< FetchT >( writer )
										, test::getDefault< FetchT >( writer ) ) );
								s.atomicCompSwap( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j * s.atomicCompSwap( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer )
									, test::getDefault< FetchT >( writer ) );
								j = s.atomicCompSwap( test::getDefault< CoordsT >( writer )
									, test::getDefault< FetchT >( writer )
									, test::getDefault< FetchT >( writer ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion

	template< ast::type::AccessKind AccessT
		, ast::type::ImageFormat FormatT
		, template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageFormats( test::sdw_test::TestCounts & testCounts )
	{
		if constexpr ( isFloatFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1D >::test( testCounts );
			TesterT< FormatT, AccessT, Img2D >::test( testCounts );
			TesterT< FormatT, AccessT, Img3D >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCube >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArray >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArray >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArray >::test( testCounts );

			if constexpr ( FormatT == ast::type::ImageFormat::eR32f
				|| FormatT == ast::type::ImageFormat::eR16f )
			{
				TesterT< FormatT, AccessT, Img1DShadow >::test( testCounts );
				TesterT< FormatT, AccessT, Img2DShadow >::test( testCounts );
				TesterT< FormatT, AccessT, ImgCubeShadow >::test( testCounts );
				TesterT< FormatT, AccessT, Img1DArrayShadow >::test( testCounts );
				TesterT< FormatT, AccessT, Img2DArrayShadow >::test( testCounts );
				TesterT< FormatT, AccessT, ImgCubeArrayShadow >::test( testCounts );
			}
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1D >::test( testCounts );
			TesterT< FormatT, AccessT, Img2D >::test( testCounts );
			TesterT< FormatT, AccessT, Img3D >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCube >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArray >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArray >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArray >::test( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1D >::test( testCounts );
			TesterT< FormatT, AccessT, Img2D >::test( testCounts );
			TesterT< FormatT, AccessT, Img3D >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCube >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArray >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArray >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArray >::test( testCounts );
		}
	}

	template< template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImage( test::sdw_test::TestCounts & testCounts )
	{
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR8u, TesterT >( testCounts );
	}

	template< template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageAtomic( test::sdw_test::TestCounts & testCounts )
	{
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterImageAccesses )
{
#if !defined( __APPLE__ )

	sdwTestSuiteBegin();
	testsImage< ImageSizeTester >( testCounts );
	testsImage< ImageSamplesTester >( testCounts );
	testsImage< ImageLoadTester >( testCounts );
	testsImage< ImageStoreTester >( testCounts );
	testsImageAtomic< ImageAtomicAddTester >( testCounts );
	testsImageAtomic< ImageAtomicMinTester >( testCounts );
	testsImageAtomic< ImageAtomicMaxTester >( testCounts );
	testsImageAtomic< ImageAtomicAndTester >( testCounts );
	testsImageAtomic< ImageAtomicOrTester >( testCounts );
	testsImageAtomic< ImageAtomicXorTester >( testCounts );
	testsImageAtomic< ImageAtomicExchangeTester >( testCounts );
	testsImageAtomic< ImageAtomicCompSwapTester >( testCounts );
	sdwTestSuiteEnd();

#endif
}

sdwTestSuiteLaunch( TestWriterImageAccesses )
