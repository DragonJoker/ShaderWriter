#pragma once

#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderWriter/BaseTypes/Sampler.hpp>
#include <ShaderWriter/BaseTypes/StorageImage.hpp>
#include <ShaderWriter/Intrinsics/Intrinsics.hpp>
#include <ShaderWriter/Writer.hpp>
#include <ShaderWriter/WriterDebug.hpp>
#include <ShaderWriter/Source.hpp>
#include <ShaderWriter/MeshWriterNV.hpp>
#include <ShaderWriter/TaskWriterNV.hpp>

#if defined( _WIN32 )
#	if defined( TestWriterCommon_EXPORTS )
#		define SDWTest_API __declspec( dllexport )
#	else
#		define SDWTest_API __declspec( dllimport )
#	endif
#else
#	define SDWTest_API
#endif

#define ForceDisplayShaders false

#define Compilers_GLSL { false, false, true, ForceDisplayShaders }
#define Compilers_HLSL { false, true, false, ForceDisplayShaders }
#define Compilers_SPIRV { true, false, false, ForceDisplayShaders }

#define Compilers_NoGLSL { true, true, false, ForceDisplayShaders }
#define Compilers_NoHLSL { true, false, true, ForceDisplayShaders }
#define Compilers_NoSPIRV { false, true, true, ForceDisplayShaders }

#define Compilers_All { true, true, true, ForceDisplayShaders }
#define Compilers_AllButSpv16 { true, true, true, ForceDisplayShaders, 0x00010600u }

#define CurrentCompilers Compilers_All

namespace test
{
	namespace sdw_test
	{
		struct GLSLContext;
		struct HLSLContext;
		struct SPIRVContext;

		struct TestCounts
			: test::TestCounts
		{
			SDWTest_API TestCounts( test::TestSuite & suite );
			SDWTest_API ~TestCounts()noexcept override = default;

			bool isSpirVInitialised( uint32_t infoIndex )const;
			bool isSpvIgnored( uint32_t infoIndex, uint32_t ignoredSpvVersion )const;
			uint32_t getVulkanVersion( uint32_t infoIndex )const;
			uint32_t getSpirVVersion( uint32_t infoIndex )const;
			uint32_t getSpirvInfosSize()const;

			bool isHlslInitialised( uint32_t infoIndex )const;
			uint32_t getHlslVersion( uint32_t infoIndex )const;
			uint32_t getHlslInfosSize()const;

			bool isGlslInitialised( uint32_t infoIndex )const;
			uint32_t getGlslVersion( uint32_t infoIndex )const;
			uint32_t getGlslInfosSize()const;

			std::shared_ptr< GLSLContext > glsl;
			std::shared_ptr< HLSLContext > hlsl;
			std::shared_ptr< SPIRVContext > spirv;
			std::string expectedError;

		private:
			void doInitialise()override;
			void doCleanup()override;
		};

		struct TestSuite
			: test::TestSuite
		{
			using TestCountsType = test::sdw_test::TestCounts;

			SDWTest_API TestSuite( std::string name );
			SDWTest_API ~TestSuite();
		};
	}

	template< typename T >
	T getDefault( sdw::ShaderWriter & writer );

	template<>
	inline sdw::Boolean getDefault< sdw::Boolean >( sdw::ShaderWriter & writer )
	{
		return sdw::Boolean{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), true )
			, true };
	}

	template<>
	inline sdw::Int8 getDefault< sdw::Int8 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int8{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int8_t( 1 ) )
			, true };
	}

	template<>
	inline sdw::Int16 getDefault< sdw::Int16 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int16{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int16_t( 1 ) )
			, true };
	}

	template<>
	inline sdw::Int32 getDefault< sdw::Int32 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int32{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 1 )
			, true };
	}

	template<>
	inline sdw::Int64 getDefault< sdw::Int64 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int64{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 1ll )
			, true };
	}

	template<>
	inline sdw::UInt8 getDefault< sdw::UInt8 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt8{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint8_t( 1 ) )
			, true };
	}

	template<>
	inline sdw::UInt16 getDefault< sdw::UInt16 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt16{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint16_t( 1 ) )
			, true };
	}

	template<>
	inline sdw::UInt32 getDefault< sdw::UInt32 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt32{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 1u )
			, true };
	}

	template<>
	inline sdw::UInt64 getDefault< sdw::UInt64 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt64{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 1ull )
			, true };
	}

	template<>
	inline sdw::Half getDefault< sdw::Half >( sdw::ShaderWriter & writer )
	{
		return sdw::Half{ writer
			, getExprCache( writer ).makeCast( writer.getTypesCache().getHalf()
				, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 1.0f ) )
			, true };
	}

	template<>
	inline sdw::Float getDefault< sdw::Float >( sdw::ShaderWriter & writer )
	{
		return sdw::Float{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 1.0f )
			, true };
	}

	template<>
	inline sdw::Double getDefault< sdw::Double >( sdw::ShaderWriter & writer )
	{
		return sdw::Double{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 1.0 )
			, true };
	}

	template<>
	inline sdw::Vec2 getDefault< sdw::Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::vec2( getDefault< sdw::Float >( writer )
			, getDefault< sdw::Float >( writer ) );
	}

	template<>
	inline sdw::Vec3 getDefault< sdw::Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::vec3( getDefault< sdw::Float >( writer )
			, getDefault< sdw::Float >( writer )
			, getDefault< sdw::Float >( writer ) );
	}

	template<>
	inline sdw::Vec4 getDefault< sdw::Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::vec4( getDefault< sdw::Float >( writer )
			, getDefault< sdw::Float >( writer )
			, getDefault< sdw::Float >( writer )
			, getDefault< sdw::Float >( writer ) );
	}

	template<>
	inline sdw::DVec2 getDefault< sdw::DVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dvec2( getDefault< sdw::Double >( writer )
			, getDefault< sdw::Double >( writer ) );
	}

	template<>
	inline sdw::DVec3 getDefault< sdw::DVec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dvec3( getDefault< sdw::Double >( writer )
			, getDefault< sdw::Double >( writer )
			, getDefault< sdw::Double >( writer ) );
	}

	template<>
	inline sdw::DVec4 getDefault< sdw::DVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dvec4( getDefault< sdw::Double >( writer )
			, getDefault< sdw::Double >( writer )
			, getDefault< sdw::Double >( writer )
			, getDefault< sdw::Double >( writer ) );
	}

	template<>
	inline sdw::HVec2 getDefault< sdw::HVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::f16vec2( getDefault< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::HVec4 getDefault< sdw::HVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::f16vec4( getDefault< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::BVec2 getDefault< sdw::BVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::bvec2( getDefault< sdw::Boolean >( writer )
			, getDefault< sdw::Boolean >( writer ) );
	}

	template<>
	inline sdw::BVec3 getDefault< sdw::BVec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::bvec3( getDefault< sdw::Boolean >( writer )
			, getDefault< sdw::Boolean >( writer )
			, getDefault< sdw::Boolean >( writer ) );
	}

	template<>
	inline sdw::BVec4 getDefault< sdw::BVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::bvec4( getDefault< sdw::Boolean >( writer )
			, getDefault< sdw::Boolean >( writer )
			, getDefault< sdw::Boolean >( writer )
			, getDefault< sdw::Boolean >( writer ) );
	}

	template<>
	inline sdw::I8Vec2 getDefault< sdw::I8Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::i8vec2( getDefault< sdw::Int8 >( writer )
			, getDefault< sdw::Int8 >( writer ) );
	}

	template<>
	inline sdw::I8Vec3 getDefault< sdw::I8Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::i8vec3( getDefault< sdw::Int8 >( writer )
			, getDefault< sdw::Int8 >( writer )
			, getDefault< sdw::Int8 >( writer ) );
	}

	template<>
	inline sdw::I8Vec4 getDefault< sdw::I8Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::i8vec4( getDefault< sdw::Int8 >( writer )
			, getDefault< sdw::Int8 >( writer )
			, getDefault< sdw::Int8 >( writer )
			, getDefault< sdw::Int8 >( writer ) );
	}

	template<>
	inline sdw::I16Vec2 getDefault< sdw::I16Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::i16vec2( getDefault< sdw::Int16 >( writer )
			, getDefault< sdw::Int16 >( writer ) );
	}

	template<>
	inline sdw::I16Vec3 getDefault< sdw::I16Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::i16vec3( getDefault< sdw::Int16 >( writer )
			, getDefault< sdw::Int16 >( writer )
			, getDefault< sdw::Int16 >( writer ) );
	}

	template<>
	inline sdw::I16Vec4 getDefault< sdw::I16Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::i16vec4( getDefault< sdw::Int16 >( writer )
			, getDefault< sdw::Int16 >( writer )
			, getDefault< sdw::Int16 >( writer )
			, getDefault< sdw::Int16 >( writer ) );
	}

	template<>
	inline sdw::I32Vec2 getDefault< sdw::I32Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec2( getDefault< sdw::Int32 >( writer )
			, getDefault< sdw::Int32 >( writer ) );
	}

	template<>
	inline sdw::I32Vec3 getDefault< sdw::I32Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec3( getDefault< sdw::Int32 >( writer )
			, getDefault< sdw::Int32 >( writer )
			, getDefault< sdw::Int32 >( writer ) );
	}

	template<>
	inline sdw::I32Vec4 getDefault< sdw::I32Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec4( getDefault< sdw::Int32 >( writer )
			, getDefault< sdw::Int32 >( writer )
			, getDefault< sdw::Int32 >( writer )
			, getDefault< sdw::Int32 >( writer ) );
	}

	template<>
	inline sdw::I64Vec2 getDefault< sdw::I64Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::i64vec2( getDefault< sdw::Int64 >( writer )
			, getDefault< sdw::Int64 >( writer ) );
	}

	template<>
	inline sdw::I64Vec3 getDefault< sdw::I64Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::i64vec3( getDefault< sdw::Int64 >( writer )
			, getDefault< sdw::Int64 >( writer )
			, getDefault< sdw::Int64 >( writer ) );
	}

	template<>
	inline sdw::I64Vec4 getDefault< sdw::I64Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::i64vec4( getDefault< sdw::Int64 >( writer )
			, getDefault< sdw::Int64 >( writer )
			, getDefault< sdw::Int64 >( writer )
			, getDefault< sdw::Int64 >( writer ) );
	}

	template<>
	inline sdw::U8Vec2 getDefault< sdw::U8Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::u8vec2( getDefault< sdw::UInt8 >( writer )
			, getDefault< sdw::UInt8 >( writer ) );
	}

	template<>
	inline sdw::U8Vec3 getDefault< sdw::U8Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::u8vec3( getDefault< sdw::UInt8 >( writer )
			, getDefault< sdw::UInt8 >( writer )
			, getDefault< sdw::UInt8 >( writer ) );
	}

	template<>
	inline sdw::U8Vec4 getDefault< sdw::U8Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::u8vec4( getDefault< sdw::UInt8 >( writer )
			, getDefault< sdw::UInt8 >( writer )
			, getDefault< sdw::UInt8 >( writer )
			, getDefault< sdw::UInt8 >( writer ) );
	}

	template<>
	inline sdw::U16Vec2 getDefault< sdw::U16Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::u16vec2( getDefault< sdw::UInt16 >( writer )
			, getDefault< sdw::UInt16 >( writer ) );
	}

	template<>
	inline sdw::U16Vec3 getDefault< sdw::U16Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::u16vec3( getDefault< sdw::UInt16 >( writer )
			, getDefault< sdw::UInt16 >( writer )
			, getDefault< sdw::UInt16 >( writer ) );
	}

	template<>
	inline sdw::U16Vec4 getDefault< sdw::U16Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::u16vec4( getDefault< sdw::UInt16 >( writer )
			, getDefault< sdw::UInt16 >( writer )
			, getDefault< sdw::UInt16 >( writer )
			, getDefault< sdw::UInt16 >( writer ) );
	}

	template<>
	inline sdw::U32Vec2 getDefault< sdw::U32Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec2( getDefault< sdw::UInt32 >( writer )
			, getDefault< sdw::UInt32 >( writer ) );
	}

	template<>
	inline sdw::U32Vec3 getDefault< sdw::U32Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec3( getDefault< sdw::UInt32 >( writer )
			, getDefault< sdw::UInt32 >( writer )
			, getDefault< sdw::UInt32 >( writer ) );
	}

	template<>
	inline sdw::U32Vec4 getDefault< sdw::U32Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec4( getDefault< sdw::UInt32 >( writer )
			, getDefault< sdw::UInt32 >( writer )
			, getDefault< sdw::UInt32 >( writer )
			, getDefault< sdw::UInt32 >( writer ) );
	}

	template<>
	inline sdw::U64Vec2 getDefault< sdw::U64Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::u64vec2( getDefault< sdw::UInt64 >( writer )
			, getDefault< sdw::UInt64 >( writer ) );
	}

	template<>
	inline sdw::U64Vec3 getDefault< sdw::U64Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::u64vec3( getDefault< sdw::UInt64 >( writer )
			, getDefault< sdw::UInt64 >( writer )
			, getDefault< sdw::UInt64 >( writer ) );
	}

	template<>
	inline sdw::U64Vec4 getDefault< sdw::U64Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::u64vec4( getDefault< sdw::UInt64 >( writer )
			, getDefault< sdw::UInt64 >( writer )
			, getDefault< sdw::UInt64 >( writer )
			, getDefault< sdw::UInt64 >( writer ) );
	}

	template<>
	inline sdw::Mat2 getDefault< sdw::Mat2 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat2( getDefault< sdw::Vec2 >( writer )
			, getDefault< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::Mat2x3 getDefault< sdw::Mat2x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat2x3( getDefault< sdw::Vec3 >( writer )
			, getDefault< sdw::Vec3 >( writer ) );
	}

	template<>
	inline sdw::Mat2x4 getDefault< sdw::Mat2x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat2x4( getDefault< sdw::Vec4 >( writer )
			, getDefault< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::Mat3 getDefault< sdw::Mat3 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat3( getDefault< sdw::Vec3 >( writer )
			, getDefault< sdw::Vec3 >( writer )
			, getDefault< sdw::Vec3 >( writer ) );
	}

	template<>
	inline sdw::Mat3x2 getDefault< sdw::Mat3x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat3x2( getDefault< sdw::Vec2 >( writer )
			, getDefault< sdw::Vec2 >( writer )
			, getDefault< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::Mat3x4 getDefault< sdw::Mat3x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat3x4( getDefault< sdw::Vec4 >( writer )
			, getDefault< sdw::Vec4 >( writer )
			, getDefault< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::Mat4 getDefault< sdw::Mat4 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat4( getDefault< sdw::Vec4 >( writer )
			, getDefault< sdw::Vec4 >( writer )
			, getDefault< sdw::Vec4 >( writer )
			, getDefault< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::Mat4x2 getDefault< sdw::Mat4x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat4x2( getDefault< sdw::Vec2 >( writer )
			, getDefault< sdw::Vec2 >( writer )
			, getDefault< sdw::Vec2 >( writer )
			, getDefault< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::Mat4x3 getDefault< sdw::Mat4x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat4x3( getDefault< sdw::Vec3 >( writer )
			, getDefault< sdw::Vec3 >( writer )
			, getDefault< sdw::Vec3 >( writer )
			, getDefault< sdw::Vec3 >( writer ) );
	}

	template<>
	inline sdw::DMat2 getDefault< sdw::DMat2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat2( getDefault< sdw::DVec2 >( writer )
			, getDefault< sdw::DVec2 >( writer ) );
	}

	template<>
	inline sdw::DMat2x3 getDefault< sdw::DMat2x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat2x3( getDefault< sdw::DVec3 >( writer )
			, getDefault< sdw::DVec3 >( writer ) );
	}

	template<>
	inline sdw::DMat2x4 getDefault< sdw::DMat2x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat2x4( getDefault< sdw::DVec4 >( writer )
			, getDefault< sdw::DVec4 >( writer ) );
	}

	template<>
	inline sdw::DMat3 getDefault< sdw::DMat3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat3( getDefault< sdw::DVec3 >( writer )
			, getDefault< sdw::DVec3 >( writer )
			, getDefault< sdw::DVec3 >( writer ) );
	}

	template<>
	inline sdw::DMat3x2 getDefault< sdw::DMat3x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat3x2( getDefault< sdw::DVec2 >( writer )
			, getDefault< sdw::DVec2 >( writer )
			, getDefault< sdw::DVec2 >( writer ) );
	}

	template<>
	inline sdw::DMat3x4 getDefault< sdw::DMat3x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat3x4( getDefault< sdw::DVec4 >( writer )
			, getDefault< sdw::DVec4 >( writer )
			, getDefault< sdw::DVec4 >( writer ) );
	}

	template<>
	inline sdw::DMat4 getDefault< sdw::DMat4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat4( getDefault< sdw::DVec4 >( writer )
			, getDefault< sdw::DVec4 >( writer )
			, getDefault< sdw::DVec4 >( writer )
			, getDefault< sdw::DVec4 >( writer ) );
	}

	template<>
	inline sdw::DMat4x2 getDefault< sdw::DMat4x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat4x2( getDefault< sdw::DVec2 >( writer )
			, getDefault< sdw::DVec2 >( writer )
			, getDefault< sdw::DVec2 >( writer )
			, getDefault< sdw::DVec2 >( writer ) );
	}

	template<>
	inline sdw::DMat4x3 getDefault< sdw::DMat4x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat4x3( getDefault< sdw::DVec3 >( writer )
			, getDefault< sdw::DVec3 >( writer )
			, getDefault< sdw::DVec3 >( writer )
			, getDefault< sdw::DVec3 >( writer ) );
	}

	template< typename T >
	inline std::vector< T > getDefaultVector( sdw::ShaderWriter & writer
		, uint32_t dimension )
	{
		std::vector< T > result;

		for ( auto i = 0u; i < dimension; ++i )
		{
			result.emplace_back( getDefault< T >( writer ) );
		}

		return result;
	}

	template< typename T >
	inline sdw::Array< T > getDefaultArray( sdw::ShaderWriter & writer
		, uint32_t dimension )
	{
		ast::expr::ExprList initialisers;

		for ( auto i = 0u; i < dimension; ++i )
		{
			initialisers.emplace_back( sdw::makeExpr( getDefault< T >( writer ) ) );
		}

		auto type = writer.getTypesCache().getArray( initialisers.front()->getType(), dimension );
		return sdw::Array< T >{ writer
			, getExprCache( writer ).makeAggrInit( std::move( type ), std::move( initialisers ) )
			, true };
	}

	struct Compilers
	{
		bool spirV;
		bool hlsl;
		bool glsl;
		bool forceDisplay;
		uint32_t ignoredSpv{};
	};

	SDWTest_API void writeShader( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void writeShader( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShaders( ast::ShaderArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShaders( ast::ShaderPtrArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void validateShader( ast::Shader const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers );
	SDWTest_API void expectError( std::string value
		, sdw_test::TestCounts & testCounts );
}

#	define sdwTestSuiteMain( testName )\
	static test::TestResults testConcat2( launch, testName )( test::sdw_test::TestSuite & suite, test::sdw_test::TestCounts & testCounts )

#define sdwTestSuiteBegin()\
	testSuiteBeginEx( testCounts )

#define sdwTestSuiteLaunch( name )\
	testSuiteLaunchEx( name, test::sdw_test::TestSuite )

#define sdwTestSuiteEnd()\
	testSuiteEnd()
