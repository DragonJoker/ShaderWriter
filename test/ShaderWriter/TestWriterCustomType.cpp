#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/ArraySsbo.hpp>

namespace
{
	struct Light
		: public sdw::StructInstance
	{
		Light( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, colorIntensity{ getMember< sdw::Vec4 >( "colorIntensity" ) }
			, color{ colorIntensity.xyz() }
			, intensity{ colorIntensity.w() }
		{
		}

		Light & operator=( Light const & rhs )
		{
			StructInstance::operator=( rhs );
			return *this;
		}

		static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
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

	enum class TypeName
	{
		eLight = int( ast::type::Kind::eCount ),
	};
}

namespace sdw
{
	template<>
	struct TypeTraits< Light >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind( TypeName::eLight );
	};
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
			auto out = writer.getOut();
			writer.implementFunction< Void >( "main"
				, [&]()
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, false, true, true );
			test::writeShader( writer
				, testCounts
				, true, false, false );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light >();
			auto lightUbo = writer.declUniformBuffer<>( "LightUbo", 0u, 0u );
			auto light = lightUbo.declStructMember< Light >( "light" );
			lightUbo.end();

			auto fragOutput = writer.declOutput< Vec3 >( "fragOutput", 0u );

			writer.implementFunction< Void >( "main"
				, [&]()
				{
					fragOutput = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, false, true, true );
			test::writeShader( writer
				, testCounts
				, true, false, false );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
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

		auto fragOutput = writer.declOutput< Vec3 >( "fragOutput", 0u );

		writer.implementFunction< Void >( "main"
			, [&]()
			{
				fragOutput = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, false, true, true );
		test::writeShader( writer
			, testCounts
			, true, false, false );
		testEnd();
	}

	void singleLightSsbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "singleLightSsbo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			auto out = writer.getOut();
			writer.implementFunction< Void >( "main"
				, [&]()
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, false, true, true );
			test::writeShader( writer
				, testCounts
				, true, false, false );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;
			writer.declType< Light >();
			auto lightSsbo = writer.declUniformBuffer<>( "LightSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto light = lightSsbo.declStructMember< Light >( "light" );
			lightSsbo.end();

			auto fragOutput = writer.declOutput< Vec3 >( "fragOutput", 0u );

			writer.implementFunction< Void >( "main"
				, [&]()
				{
					fragOutput = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, false, true, true );
			test::writeShader( writer
				, testCounts
				, true, false, false );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
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

		auto fragOutput = writer.declOutput< Vec3 >( "fragOutput", 0u );

		writer.implementFunction< Void >( "main", [&]()
			{
				fragOutput = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, false, true, true );
		test::writeShader( writer
			, testCounts
			, true, false, false );
		testEnd();
	}

	void arraySsboLight( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arraySsboLight" );
		using namespace sdw;

		FragmentWriter writer;

		auto lights = writer.declArrayShaderStorageBuffer< Light >( "LightsSsbo", 1u, 0u );
		auto fragOutput = writer.declOutput< Vec3 >( "fragOutput", 0u );

		writer.implementFunction< Void >( "main", [&]()
			{
				fragOutput = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, false, true, true );
		test::writeShader( writer
			, testCounts
			, true, false, false );
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
