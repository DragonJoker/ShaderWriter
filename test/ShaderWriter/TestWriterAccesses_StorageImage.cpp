#include "WriterCommon.hpp"

#if !defined( __APPLE__ )

#include <ShaderAST/Type/ImageConfiguration.hpp>

namespace test
{
	static ast::type::ImageFormat constexpr FormatT = ast::type::ImageFormat::SDW_TestImageFormat;

	using StorageImageTypesNames = StorageImageTypesNamesT< FormatT >;

	static constexpr bool isAtomicFormatV = FormatT == ast::type::ImageFormat::eR32f
		|| FormatT == ast::type::ImageFormat::eR32i
		|| FormatT == ast::type::ImageFormat::eR32u;

	template< typename ParamT >
	struct StorageImageAccess : public SDWTest
	{
	};

	TYPED_TEST_SUITE( StorageImageAccess, StorageImageTypes, StorageImageTypesNames );

#pragma region imageSize
	/**
	*name
	*	imageSize
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageSize )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		sdwTestBegin( "imageSize" );
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
		sdwTestEnd()
	}
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageSamples )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( MsT )
		{
			sdwTestBegin( "imageSamples" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageLoad )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( sdw::isReadableV< AccessT > )
		{
			using Coords = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			sdwTestBegin( "imageLoad" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageStore
	/**
	*name
	*	imageStore
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageStore )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( sdw::isWritableV< AccessT > )
		{
			using Coords = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageStore" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicAdd )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isAtomicFloatFormat( FormatT )
				|| isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicAdd" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicMin
	/**
	*name
	*	imageAtomicMin
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicMin )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicMin" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicMax
	/**
	*name
	*	imageAtomicMax
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicMax )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicMax" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicAnd
	/**
	*name
	*	imageAtomicAnd
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicAnd )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicAnd" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicOr
	/**
	*name
	*	imageAtomicOr
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicOr )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicOr" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicXor
	/**
	*name
	*	imageAtomicXor
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicXor )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicXor" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchange
	/**
	*name
	*	imageAtomicExchange
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicExchange )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isAtomicFloatFormat( FormatT )
				|| isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicExchange" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwap
	/**
	*name
	*	imageAtomicCompSwap
	*/
	/**@{*/
	TYPED_TEST( StorageImageAccess, imageAtomicCompSwap )
	{
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto AccessT = TypeParam::Access;
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( isAtomicFormatV
			&& sdw::isReadWriteV< AccessT >
			&& ( isSingleInt32Format( FormatT ) ) )
		{
			using CoordsT = sdw::StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = sdw::ImageFetchT< FormatT >;
			sdwTestBegin( "imageAtomicCompSwap" );
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
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
}

#endif

sdwTestSuiteMain()
