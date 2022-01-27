#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/ArraySsbo.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	template< sdw::var::Flag FlagT >
	struct ColourT
		: sdw::StructInstance
	{
		ColourT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, colour{ getMember< sdw::Vec3 >( "colour" ) }
		{
		}

		SDW_DeclStructInstance( , ColourT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eStd430
				, ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "Colour"
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 0u );
			}

			return result;
		}

		sdw::Vec3 colour;
	};

	struct Light
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , Light );

		Light( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, colorIntensity{ getMember< sdw::Vec4 >( "colorIntensity" ) }
			, color{ colorIntensity.xyz() }
			, intensity{ colorIntensity.w() }
		{
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140
				, "Light" );

			if ( result->empty() )
			{
				result->declMember( "colorIntensity", ast::type::Kind::eVec4F );
			}

			return result;
		}

		sdw::Vec4 colorIntensity;
		sdw::Vec3 color;
		sdw::Float intensity;

	private:
		using sdw::StructInstance::getMember;
		using sdw::StructInstance::getMemberArray;
	};

	Writer_Parameter( Light );

#if SDW_EnableStructHelper

	struct Light2
		: public sdw::StructInstanceHelperT< "Light"
			, ast::type::MemoryLayout::eStd140
			, sdw::StructFieldT< sdw::Vec4, "colorIntensity" > >
	{
		Light2( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstanceHelperT{ writer, std::move( expr ), enabled }
		{
		}

		auto colorIntensity() { return getMember< "colorIntensity" >(); }
		auto color() { return colorIntensity().xyz(); }
		auto intensity() { return colorIntensity().w(); }
	};

	Writer_Parameter( Light2 );

#endif
}

namespace
{
	void singleLightUbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "singleLightUbo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light >();
			auto lightUbo = writer.declUniformBuffer<>( "LightUbo", 0u, 0u );
			auto light = lightUbo.declMember< Light >( "light" );
			lightUbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}
		
	void lightArrayUbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lightArrayUbo" );
		using namespace sdw;

		FragmentWriter writer;

		writer.declType< Light >();
		auto lightsUbo = writer.declUniformBuffer<>( "LightsUbo", 0u, 0u );
		auto lights = lightsUbo.declMember< Light >( "lights"
			, 2u );
		lightsUbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void singleLightSsbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "singleLightSsbo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light >();
			auto lightSsbo = writer.declUniformBuffer<>( "LightSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto light = lightSsbo.declMember< Light >( "light" );
			lightSsbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void lightArraySsbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lightArraySsbo" );
		using namespace sdw;

		FragmentWriter writer;

		writer.declType< Light >();
		auto lightsSsbo = writer.declUniformBuffer<>( "LightsSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
		auto lights = lightsSsbo.declMember< Light >( "lights"
			, 2u );
		lightsSsbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void arraySsboLight( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arraySsboLight" );
		using namespace sdw;

		FragmentWriter writer;

		auto lights = writer.declArrayShaderStorageBuffer< Light >( "LightsSsbo", 1u, 0u );

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void singleLight2Ubo( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "singleLight2Ubo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light2 >();
			auto lightUbo = writer.declUniformBuffer<>( "Light2Ubo", 0u, 0u );
			auto light = lightUbo.declMember< Light2 >( "light" );
			lightUbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color() * light.intensity();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();

#endif
	}
		
	void light2ArrayUbo( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "light2ArrayUbo" );
		using namespace sdw;

		FragmentWriter writer;

		writer.declType< Light2 >();
		auto lightsUbo = writer.declUniformBuffer<>( "Light2sUbo", 0u, 0u );
		auto lights = lightsUbo.declMember< Light2 >( "lights"
			, 2u );
		lightsUbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color() * lights[1].intensity();
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();

#endif
	}

	void singleLight2Ssbo( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "singleLight2Ssbo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light2 >();
			auto lightSsbo = writer.declUniformBuffer<>( "Light2Ssbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto light = lightSsbo.declMember< Light2 >( "light" );
			lightSsbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color() * light.intensity();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();

#endif
	}

	void light2ArraySsbo( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "light2ArraySsbo" );
		using namespace sdw;

		FragmentWriter writer;

		writer.declType< Light2 >();
		auto lightsSsbo = writer.declUniformBuffer<>( "Light2sSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
		auto lights = lightsSsbo.declMember< Light2 >( "lights"
			, 2u );
		lightsSsbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color() * lights[1].intensity();
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();

#endif
	}

	void arraySsboLight2( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "arraySsboLight2" );
		using namespace sdw;

		FragmentWriter writer;

		auto lights = writer.declArrayShaderStorageBuffer< Light2 >( "Light2sSsbo", 1u, 0u );

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color() * lights[1].intensity();
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();

#endif
	}
}

sdwTestSuiteMain( TestWriterCustomType )
{
	sdwTestSuiteBegin();
	singleLightUbo( testCounts );
	lightArrayUbo( testCounts );
	singleLightSsbo( testCounts );
	lightArraySsbo( testCounts );
	arraySsboLight( testCounts );
	singleLight2Ubo( testCounts );
	light2ArrayUbo( testCounts );
	singleLight2Ssbo( testCounts );
	light2ArraySsbo( testCounts );
	arraySsboLight2( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterCustomType )
