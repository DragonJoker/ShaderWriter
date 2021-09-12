#pragma once

#include "Common.hpp"

#include <ShaderAST/Debug/DebugCommon.hpp>
#include <ShaderAST/Debug/DebugStmtVisitor.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderWriter/BaseTypes/Sampler.hpp>
#include <ShaderWriter/BaseTypes/Image.hpp>
#include <ShaderWriter/Intrinsics/Intrinsics.hpp>
#include <ShaderWriter/Writer.hpp>
#include <ShaderWriter/WriterDebug.hpp>
#include <ShaderWriter/Source.hpp>

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
			TestCounts( test::TestSuite & suite );

			void initialise();
			TestResults cleanup();

			uint32_t getSpirVVersion()const;

			std::shared_ptr< GLSLContext > glsl;
			std::shared_ptr< HLSLContext > hlsl;
			std::shared_ptr< SPIRVContext > spirv;
			std::string expectedError;
		};

		struct TestSuite
			: test::TestSuite
		{
			using TestCountsType = test::sdw_test::TestCounts;

			TestSuite( std::string const & name );
			~TestSuite();
		};
	}

	template< typename T >
	T getDefault( sdw::ShaderWriter & writer );

	template<>
	inline sdw::Boolean getDefault< sdw::Boolean >( sdw::ShaderWriter & writer )
	{
		return sdw::Boolean{ writer
			, sdw::expr::makeLiteral( writer.getTypesCache(), true )
			, true };
	}

	template<>
	inline sdw::Int getDefault< sdw::Int >( sdw::ShaderWriter & writer )
	{
		return sdw::Int{ writer
			, sdw::expr::makeLiteral( writer.getTypesCache(), 1 )
			, true };
	}

	template<>
	inline sdw::UInt getDefault< sdw::UInt >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt{ writer
			, sdw::expr::makeLiteral( writer.getTypesCache(), 1u )
			, true };
	}

	template<>
	inline sdw::Half getDefault< sdw::Half >( sdw::ShaderWriter & writer )
	{
		return sdw::Half{ writer
			, sdw::expr::makeCast( writer.getTypesCache().getHalf()
				, sdw::expr::makeLiteral( writer.getTypesCache(), 1.0f ) )
			, true };
	}

	template<>
	inline sdw::Float getDefault< sdw::Float >( sdw::ShaderWriter & writer )
	{
		return sdw::Float{ writer
			, sdw::expr::makeLiteral( writer.getTypesCache(), 1.0f )
			, true };
	}

	template<>
	inline sdw::Double getDefault< sdw::Double >( sdw::ShaderWriter & writer )
	{
		return sdw::Double{ writer
			, sdw::expr::makeLiteral( writer.getTypesCache(), 1.0 )
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
	inline sdw::IVec2 getDefault< sdw::IVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec2( getDefault< sdw::Int >( writer )
			, getDefault< sdw::Int >( writer ) );
	}

	template<>
	inline sdw::IVec3 getDefault< sdw::IVec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec3( getDefault< sdw::Int >( writer )
			, getDefault< sdw::Int >( writer )
			, getDefault< sdw::Int >( writer ) );
	}

	template<>
	inline sdw::IVec4 getDefault< sdw::IVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec4( getDefault< sdw::Int >( writer )
			, getDefault< sdw::Int >( writer )
			, getDefault< sdw::Int >( writer )
			, getDefault< sdw::Int >( writer ) );
	}

	template<>
	inline sdw::UVec2 getDefault< sdw::UVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec2( getDefault< sdw::UInt >( writer )
			, getDefault< sdw::UInt >( writer ) );
	}

	template<>
	inline sdw::UVec3 getDefault< sdw::UVec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec3( getDefault< sdw::UInt >( writer )
			, getDefault< sdw::UInt >( writer )
			, getDefault< sdw::UInt >( writer ) );
	}

	template<>
	inline sdw::UVec4 getDefault< sdw::UVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec4( getDefault< sdw::UInt >( writer )
			, getDefault< sdw::UInt >( writer )
			, getDefault< sdw::UInt >( writer )
			, getDefault< sdw::UInt >( writer ) );
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

		return sdw::Array< T >{ &writer
			, ast::expr::makeAggrInit( ast::type::TypePtr{}
				, std::move( initialisers ) ) };
	}

	void writeShader( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, bool validateSpirV = true
		, bool validateHlsl = true
		, bool validateGlsl = true );
	void writeShader( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, bool validateSpirV = true
		, bool validateHlsl = true
		, bool validateGlsl = true );
	void validateShaders( ast::ShaderArray const & shaders
		, sdw_test::TestCounts & testCounts );
	void validateShader( ast::Shader const & writer
		, sdw_test::TestCounts & testCounts );
	void expectError( std::string const & value
		, sdw_test::TestCounts & testCounts );
}

#define sdwTestSuiteMain( testName )\
	static test::TestResults launch##testName( test::sdw_test::TestSuite & suite, test::sdw_test::TestCounts & testCounts )

#define sdwTestSuiteBegin()\
	testSuiteBeginEx( testCounts )

#define sdwTestSuiteLaunch( name )\
	testSuiteLaunchEx( name, test::sdw_test::TestSuite )

#define sdwTestSuiteEnd()\
	testSuiteEnd()
