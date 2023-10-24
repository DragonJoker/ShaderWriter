#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp>

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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Colour"
				, entryPoint
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

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Colour" );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
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

	enum class Flags
	{
		None,
		Positions,
		Normals,
		Both,
	};

	struct Parameterized
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , Parameterized );

		Parameterized( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position", true ) }
			, normal{ getMember< sdw::Vec3 >( "normal", true ) }
		{
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache
			, Flags flags )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140
				, "Parameterized" + std::to_string( uint32_t( flags ) ) );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray
					, uint32_t( flags ) & 0x01 );
				result->declMember( "normal"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray
					, uint32_t( flags ) & 0x02 );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec3 normal;

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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::FragmentWriter writer{ &testCounts.allocator };
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

		sdw::FragmentWriter writer{ &testCounts.allocator };

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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::FragmentWriter writer{ &testCounts.allocator };
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

		sdw::FragmentWriter writer{ &testCounts.allocator };

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

		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto lights = writer.declArrayStorageBuffer< Light >( "LightsSsbo", 1u, 0u );

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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::FragmentWriter writer{ &testCounts.allocator };
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

		sdw::FragmentWriter writer{ &testCounts.allocator };

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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::FragmentWriter writer{ &testCounts.allocator };
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

		sdw::FragmentWriter writer{ &testCounts.allocator };

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

		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto lights = writer.declArrayStorageBuffer< Light2 >( "Light2sSsbo", 1u, 0u );

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

	void singleParamUbo( test::sdw_test::TestCounts & testCounts
		, Flags flags )
	{
		testBegin( "singleParamUbo" + std::to_string( uint32_t( flags ) ) );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.declType< Parameterized >( flags );
			auto paramUbo = writer.declUniformBuffer<>( "ParamUbo", 0u, 0u );
			auto param = paramUbo.declMember< Parameterized >( "param", true, flags );
			paramUbo.end();

			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( param.position * param.normal, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = vec3( 1.0_f );
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
		
	void paramArrayUbo( test::sdw_test::TestCounts & testCounts
		, Flags flags )
	{
		testBegin( "paramArrayUbo" + std::to_string( uint32_t( flags ) ) );
		using namespace sdw;

		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.declType< Parameterized >( flags );
		auto paramsUbo = writer.declUniformBuffer<>( "ParamsUbo", 0u, 0u );
		auto params = paramsUbo.declMember< Parameterized >( "params", 2u, true, flags );
		paramsUbo.end();

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				out.vtx.position = vec4( params[0].position * params[0].normal, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void singleParamSsbo( test::sdw_test::TestCounts & testCounts
		, Flags flags )
	{
		testBegin( "singleParamSsbo" + std::to_string( uint32_t( flags ) ) );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.declType< Parameterized >( flags );
			auto paramSsbo = writer.declUniformBuffer<>( "ParamSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto param = paramSsbo.declMember< Parameterized >( "param", true, flags );
			paramSsbo.end();

			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( param.position * param.normal, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = vec3( 1.0_f );
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

	void paramArraySsbo( test::sdw_test::TestCounts & testCounts
		, Flags flags )
	{
		testBegin( "paramArraySsbo" + std::to_string( uint32_t( flags ) ) );
		using namespace sdw;

		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.declType< Parameterized >( flags );
		auto paramsSsbo = writer.declUniformBuffer<>( "ParamsSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
		auto params = paramsSsbo.declMember< Parameterized >( "params", 2u, true, flags );
		paramsSsbo.end();

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				out.vtx.position = vec4( params[0].position * params[0].normal, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void arraySsboParam( test::sdw_test::TestCounts & testCounts
		, Flags flags )
	{
		testBegin( "arraySsboParam" + std::to_string( uint32_t( flags ) ) );
		using namespace sdw;

		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.declType< Parameterized >( flags );
		auto params = writer.declArrayStorageBuffer< Parameterized >( "Light2sSsbo"
			, 1u
			, 0u
			, true
			, flags );

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				out.vtx.position = vec4( params[0].position * params[0].normal, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
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

	singleLight2Ubo( testCounts );
	light2ArrayUbo( testCounts );
	singleLight2Ssbo( testCounts );
	light2ArraySsbo( testCounts );
	arraySsboLight2( testCounts );

	singleParamUbo( testCounts, Flags::Positions );
	paramArrayUbo( testCounts, Flags::Positions );
	singleParamSsbo( testCounts, Flags::Positions );
	paramArraySsbo( testCounts, Flags::Positions );
	arraySsboParam( testCounts, Flags::Positions );

	singleParamUbo( testCounts, Flags::Normals );
	paramArrayUbo( testCounts, Flags::Normals );
	singleParamSsbo( testCounts, Flags::Normals );
	paramArraySsbo( testCounts, Flags::Normals );
	arraySsboParam( testCounts, Flags::Normals );

	singleParamUbo( testCounts, Flags::Both );
	paramArrayUbo( testCounts, Flags::Both );
	singleParamSsbo( testCounts, Flags::Both );
	paramArraySsbo( testCounts, Flags::Both );
	arraySsboParam( testCounts, Flags::Both );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterCustomType )
