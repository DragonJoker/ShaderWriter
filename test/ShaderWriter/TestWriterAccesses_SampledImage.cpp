#include "WriterCommon.hpp"

#if !defined( __APPLE__ )

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace test
{
	static ast::type::ImageFormat constexpr FormatT = ast::type::ImageFormat::SDW_TestImageFormat;

	using SampledImageTypesNames = SampledImageTypesNamesT< FormatT >;

	template< ast::type::ImageDim DimT >
	struct CompilerHolderT
	{
		static constexpr test::Compilers value = CurrentCompilers;
	};

	template<>
	struct CompilerHolderT< ast::type::ImageDim::eBuffer >
	{
		static constexpr test::Compilers value = Compilers_AllButSpv16;
	};

	template< ast::type::ImageDim DimT >
	inline constexpr test::Compilers CompilersT = CompilerHolderT< DimT >::value;

#pragma region Helpers
	/**
	*name
	*	Helpers
	*/
	/**@{*/
	static constexpr bool isShadowFormatV = FormatT == ast::type::ImageFormat::eR32f
		|| FormatT == ast::type::ImageFormat::eR16f;

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static constexpr bool isShadowV = ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
		|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
		|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
		|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
		|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
		|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > );

	template< typename ParamT >
	struct SampledImageAccess : public SDWTest
	{
	};

	TYPED_TEST_SUITE( SampledImageAccess, SampledImageTypes, SampledImageTypesNames );
	/**@}*/
#pragma endregion
#pragma region texture
	/**
	*name
	*	texture
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, texture )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "texture" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( isShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureBias
	/**
	*name
	*	textureBias
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureBias )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureBias" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureProj
	/**
	*name
	*	textureProj
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProj )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProj" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureProjBias
	/**
	*name
	*	textureProjBias
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProjBias )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProjBias" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureLod
	/**
	*name
	*	textureLod
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureLod )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureLod" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureOffset
	/**
	*name
	*	textureOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureOffset" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, test::getDefault < OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault < OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureOffsetBias
	/**
	*name
	*	textureOffsetBias
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureOffsetBias )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureOffsetBias" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjOffset
	/**
	*name
	*	textureProjOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProjOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProjOffset" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureProjOffsetBias
	/**
	*name
	*	textureProjOffsetBias
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProjOffsetBias )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProjOffsetBias" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureLodOffset
	/**
	*name
	*	textureLodOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureLodOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureLodOffset" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjLod
	/**
	*name
	*	textureProjLod
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProjLod )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProjLod" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureProjLodOffset
	/**
	*name
	*	textureProjLodOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProjLodOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProjLodOffset" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureGrad
	/**
	*name
	*	textureGrad
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureGrad )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureGrad" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureGradOffset
	/**
	*name
	*	textureGradOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureGradOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureGradOffset" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureProjGrad
	/**
	*name
	*	textureProjGrad
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProjGrad )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProjGrad" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureProjGradOffset
	/**
	*name
	*	textureProjGradOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureProjGradOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureProjGradOffset" );
			if constexpr ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > ) 
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > )
			{
				using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
				using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGather
	/**
	*name
	*	textureGather
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureGather )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureGather" );
			if constexpr ( sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureGatherConstOffset
	/**
	*name
	*	textureGatherConstOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureGatherConstOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureGatherConstOffset" );
			if constexpr ( sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureGatherOffset
	/**
	*name
	*	textureGatherOffset
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureGatherOffset )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureGatherOffset" );
			if constexpr ( sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto p = writer.declConstant< OffsetT >( "p"
							, test::getDefault< OffsetT >( writer ) );
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i
								, p ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto p = writer.declConstant< OffsetT >( "p"
							, test::getDefault< OffsetT >( writer ) );
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, p ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsets
	/**
	*name
	*	textureGatherOffsets
	*/
	/**@{*/
	TYPED_TEST( SampledImageAccess, textureGatherOffsets )
	{
		static constexpr auto DimT = TypeParam::Dim;
		static constexpr auto ArrayedT = TypeParam::Arrayed;
		static constexpr auto DepthT = TypeParam::Depth;
		static constexpr auto MsT = TypeParam::Ms;
		if constexpr ( !DepthT || isShadowFormatV )
		{
			sdwTestBegin( "textureGatherOffsets" );
			if constexpr ( sdw::is2dV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i
								, offsets ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			else if constexpr ( sdw::is2dShadowV< DimT, ArrayedT, DepthT >
				|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > )
			{
				using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
				using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, offsets ) );
					} );
				test::writeShader( writer, testCounts, CompilersT< DimT > );
			}
			sdwTestEnd()
		}
	}
	/**@}*/
#pragma endregion
}

#endif

sdwTestSuiteMain()
