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
				, Compilers_NoSPIRV );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light >();
			auto lightUbo = writer.declUniformBuffer<>( "LightUbo", 0u, 0u );
			auto light = lightUbo.declStructMember< Light >( "light" );
			lightUbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoSPIRV );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
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
		auto lights = lightsUbo.declStructMember< Light >( "lights"
			, 2u );
		lightsUbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, Compilers_NoSPIRV );
		test::writeShader( writer
			, testCounts
			, Compilers_SPIRV );
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
				, Compilers_NoSPIRV );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light >();
			auto lightSsbo = writer.declUniformBuffer<>( "LightSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto light = lightSsbo.declStructMember< Light >( "light" );
			lightSsbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoSPIRV );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
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
		auto lights = lightsSsbo.declStructMember< Light >( "lights"
			, 2u );
		lightsSsbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, Compilers_NoSPIRV );
		test::writeShader( writer
			, testCounts
			, Compilers_SPIRV );
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
			, Compilers_NoSPIRV );
		test::writeShader( writer
			, testCounts
			, Compilers_SPIRV );
		testEnd();
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
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterCustomType )
