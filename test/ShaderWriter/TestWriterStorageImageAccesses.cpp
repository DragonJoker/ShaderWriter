#include "Common.hpp"
#include "WriterCommon.hpp"

#if !defined( __APPLE__ )

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
		, bool MsT >
	struct ImageSizeTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageSize" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::ComputeWriter writer{ &testCounts.allocator };
				auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
				writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
					{
						auto j = writer.declLocale( "j"
							, s.getSize() );
					} );
				test::writeShader( writer
					, testCounts
					, Compilers_SPIRV );
				test::writeShader( writer
					, testCounts
					, Compilers_NoSPIRV );
				test::validateShader( writer.getShader()
					, testCounts
					, CurrentCompilers );
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
		, bool MsT >
	struct ImageSamplesTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( MsT )
			{
				auto name = "testImageSamples" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
						{
							auto j = writer.declLocale( "j"
								, s.getSamples() );
						} );
					test::writeShader( writer
						, testCounts
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageLoadTester
	{
		using Coords = sdw::StorageImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadableV< AccessT > )
			{
				auto name = "testImageLoad" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageStoreTester
	{
		using Coords = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isWritableV< AccessT > )
			{
				auto name = "testImageStore" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageAtomicAddTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isAtomicFloatFormat( FormatT )
					|| isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicAdd" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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

					test::writeShader( writer
						, testCounts
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, Compilers_SPIRV );
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
		, bool MsT >
	struct ImageAtomicMinTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicMin" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageAtomicMaxTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicMax" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageAtomicAndTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicAnd" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageAtomicOrTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicOr" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageAtomicXorTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicXor" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
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
		, bool MsT >
	struct ImageAtomicExchangeTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isAtomicFloatFormat( FormatT )
					|| isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicExchange" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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

					test::writeShader( writer
						, testCounts
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, Compilers_SPIRV );
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
		, bool MsT >
	struct ImageAtomicCompSwapTester
	{
		using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
		using FetchT = sdw::ImageFetchT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( sdw::isReadWriteV< AccessT >
				&& ( isSingleInt32Format( FormatT ) ) )
			{
				auto name = "testImageAtomicCompSwap" + sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
				testBegin( name );
				using namespace sdw;
				{
					sdw::ComputeWriter writer{ &testCounts.allocator };
					auto s = writer.declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( "s", 0u, 0u );
					writer.implementMainT< sdw::VoidT >( 1u, [&]( sdw::ComputeInT< sdw::VoidT > in )
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
						, Compilers_SPIRV );
					test::writeShader( writer
						, testCounts
						, Compilers_NoSPIRV );
					test::validateShader( writer.getShader()
						, testCounts
						, CurrentCompilers );
				}
				testEnd();
			}
		}
	};
	/**@}*/
#pragma endregion

	template< ast::type::AccessKind AccessT
		, ast::type::ImageFormat FormatT
		, template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool > typename TesterT >
	void testsImageFormats( test::sdw_test::TestCounts & testCounts )
	{
		if constexpr ( isFloatFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1DBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img3DBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBufferBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArrayBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArrayBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArrayBase >::test( testCounts );
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1DBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img3DBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBufferBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArrayBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArrayBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArrayBase >::test( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1DBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img3DBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBufferBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArrayBase >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArrayBase >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArrayBase >::test( testCounts );
		}
	}

	template< template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool > typename TesterT >
	void testsImage( test::sdw_test::TestCounts & testCounts )
	{
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::SDW_TestImageFormat, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::SDW_TestImageFormat, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::SDW_TestImageFormat, TesterT >( testCounts );
	}

	template< ast::type::ImageFormat FormatT, template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool > typename TesterT >
	void testsImageAtomic( test::sdw_test::TestCounts & testCounts )
	{
		if constexpr ( FormatT == ast::type::ImageFormat::eR32f
			|| FormatT == ast::type::ImageFormat::eR32i
			|| FormatT == ast::type::ImageFormat::eR32u )
		{
			testsImageFormats< ast::type::AccessKind::eReadWrite, FormatT, TesterT >( testCounts );
		}
	}
}

#endif

#define testName testConcat( TestWriterStorageImageAccesses, SDW_TestImageFormat )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
#if !defined( __APPLE__ )

	testsImage< ImageSizeTester >( testCounts );
	testsImage< ImageSamplesTester >( testCounts );
	testsImage< ImageLoadTester >( testCounts );
	testsImage< ImageStoreTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicAddTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicMinTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicMaxTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicAndTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicOrTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicXorTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicExchangeTester >( testCounts );
	testsImageAtomic< ast::type::ImageFormat::SDW_TestImageFormat, ImageAtomicCompSwapTester >( testCounts );

#endif
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
