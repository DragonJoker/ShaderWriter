#pragma once

#include "../Common.hpp"

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
			void initialise( std::string const & name );
			void cleanup();

			std::shared_ptr< GLSLContext > glsl;
			std::shared_ptr< HLSLContext > hlsl;
			std::shared_ptr< SPIRVContext > spirv;
			std::string expectedError;
		};
	}

	template< typename T >
	T getDefault( ast::Shader & shader );

	template<>
	inline sdw::Boolean getDefault< sdw::Boolean >( ast::Shader & shader )
	{
		return sdw::Boolean{ &shader, sdw::expr::makeLiteral( shader.getTypesCache(), true ) };
	}

	template<>
	inline sdw::Int getDefault< sdw::Int >( ast::Shader & shader )
	{
		return sdw::Int{ &shader, sdw::expr::makeLiteral( shader.getTypesCache(), 1 ) };
	}

	template<>
	inline sdw::UInt getDefault< sdw::UInt >( ast::Shader & shader )
	{
		return sdw::UInt{ &shader, sdw::expr::makeLiteral( shader.getTypesCache(), 1u ) };
	}

	template<>
	inline sdw::Float getDefault< sdw::Float >( ast::Shader & shader )
	{
		return sdw::Float{ &shader, sdw::expr::makeLiteral( shader.getTypesCache(), 1.0f ) };
	}

	template<>
	inline sdw::Double getDefault< sdw::Double >( ast::Shader & shader )
	{
		return sdw::Double{ &shader, sdw::expr::makeLiteral( shader.getTypesCache(), 1.0 ) };
	}

	template<>
	inline sdw::Vec2 getDefault< sdw::Vec2 >( ast::Shader & shader )
	{
		return sdw::vec2( getDefault< sdw::Float >( shader )
			, getDefault< sdw::Float >( shader ) );
	}

	template<>
	inline sdw::Vec3 getDefault< sdw::Vec3 >( ast::Shader & shader )
	{
		return sdw::vec3( getDefault< sdw::Float >( shader )
			, getDefault< sdw::Float >( shader )
			, getDefault< sdw::Float >( shader ) );
	}

	template<>
	inline sdw::Vec4 getDefault< sdw::Vec4 >( ast::Shader & shader )
	{
		return sdw::vec4( getDefault< sdw::Float >( shader )
			, getDefault< sdw::Float >( shader )
			, getDefault< sdw::Float >( shader )
			, getDefault< sdw::Float >( shader ) );
	}

	template<>
	inline sdw::DVec2 getDefault< sdw::DVec2 >( ast::Shader & shader )
	{
		return sdw::dvec2( getDefault< sdw::Double >( shader )
			, getDefault< sdw::Double >( shader ) );
	}

	template<>
	inline sdw::DVec3 getDefault< sdw::DVec3 >( ast::Shader & shader )
	{
		return sdw::dvec3( getDefault< sdw::Double >( shader )
			, getDefault< sdw::Double >( shader )
			, getDefault< sdw::Double >( shader ) );
	}

	template<>
	inline sdw::DVec4 getDefault< sdw::DVec4 >( ast::Shader & shader )
	{
		return sdw::dvec4( getDefault< sdw::Double >( shader )
			, getDefault< sdw::Double >( shader )
			, getDefault< sdw::Double >( shader )
			, getDefault< sdw::Double >( shader ) );
	}

	template<>
	inline sdw::BVec2 getDefault< sdw::BVec2 >( ast::Shader & shader )
	{
		return sdw::bvec2( getDefault< sdw::Boolean >( shader )
			, getDefault< sdw::Boolean >( shader ) );
	}

	template<>
	inline sdw::BVec3 getDefault< sdw::BVec3 >( ast::Shader & shader )
	{
		return sdw::bvec3( getDefault< sdw::Boolean >( shader )
			, getDefault< sdw::Boolean >( shader )
			, getDefault< sdw::Boolean >( shader ) );
	}

	template<>
	inline sdw::BVec4 getDefault< sdw::BVec4 >( ast::Shader & shader )
	{
		return sdw::bvec4( getDefault< sdw::Boolean >( shader )
			, getDefault< sdw::Boolean >( shader )
			, getDefault< sdw::Boolean >( shader )
			, getDefault< sdw::Boolean >( shader ) );
	}

	template<>
	inline sdw::IVec2 getDefault< sdw::IVec2 >( ast::Shader & shader )
	{
		return sdw::ivec2( getDefault< sdw::Int >( shader )
			, getDefault< sdw::Int >( shader ) );
	}

	template<>
	inline sdw::IVec3 getDefault< sdw::IVec3 >( ast::Shader & shader )
	{
		return sdw::ivec3( getDefault< sdw::Int >( shader )
			, getDefault< sdw::Int >( shader )
			, getDefault< sdw::Int >( shader ) );
	}

	template<>
	inline sdw::IVec4 getDefault< sdw::IVec4 >( ast::Shader & shader )
	{
		return sdw::ivec4( getDefault< sdw::Int >( shader )
			, getDefault< sdw::Int >( shader )
			, getDefault< sdw::Int >( shader )
			, getDefault< sdw::Int >( shader ) );
	}

	template<>
	inline sdw::UVec2 getDefault< sdw::UVec2 >( ast::Shader & shader )
	{
		return sdw::uvec2( getDefault< sdw::UInt >( shader )
			, getDefault< sdw::UInt >( shader ) );
	}

	template<>
	inline sdw::UVec3 getDefault< sdw::UVec3 >( ast::Shader & shader )
	{
		return sdw::uvec3( getDefault< sdw::UInt >( shader )
			, getDefault< sdw::UInt >( shader )
			, getDefault< sdw::UInt >( shader ) );
	}

	template<>
	inline sdw::UVec4 getDefault< sdw::UVec4 >( ast::Shader & shader )
	{
		return sdw::uvec4( getDefault< sdw::UInt >( shader )
			, getDefault< sdw::UInt >( shader )
			, getDefault< sdw::UInt >( shader )
			, getDefault< sdw::UInt >( shader ) );
	}

	template<>
	inline sdw::Mat2 getDefault< sdw::Mat2 >( ast::Shader & shader )
	{
		return sdw::mat2( getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader ) );
	}

	template<>
	inline sdw::Mat2x3 getDefault< sdw::Mat2x3 >( ast::Shader & shader )
	{
		return sdw::mat2x3( getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader ) );
	}

	template<>
	inline sdw::Mat2x4 getDefault< sdw::Mat2x4 >( ast::Shader & shader )
	{
		return sdw::mat2x4( getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader ) );
	}

	template<>
	inline sdw::Mat3 getDefault< sdw::Mat3 >( ast::Shader & shader )
	{
		return sdw::mat3( getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader ) );
	}

	template<>
	inline sdw::Mat3x2 getDefault< sdw::Mat3x2 >( ast::Shader & shader )
	{
		return sdw::mat3x2( getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader ) );
	}

	template<>
	inline sdw::Mat3x4 getDefault< sdw::Mat3x4 >( ast::Shader & shader )
	{
		return sdw::mat3x4( getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader ) );
	}

	template<>
	inline sdw::Mat4 getDefault< sdw::Mat4 >( ast::Shader & shader )
	{
		return sdw::mat4( getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader ) );
	}

	template<>
	inline sdw::Mat4x2 getDefault< sdw::Mat4x2 >( ast::Shader & shader )
	{
		return sdw::mat4x2( getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader ) );
	}

	template<>
	inline sdw::Mat4x3 getDefault< sdw::Mat4x3 >( ast::Shader & shader )
	{
		return sdw::mat4x3( getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader ) );
	}

	template<>
	inline sdw::DMat2 getDefault< sdw::DMat2 >( ast::Shader & shader )
	{
		return sdw::dmat2( getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader ) );
	}

	template<>
	inline sdw::DMat2x3 getDefault< sdw::DMat2x3 >( ast::Shader & shader )
	{
		return sdw::dmat2x3( getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader ) );
	}

	template<>
	inline sdw::DMat2x4 getDefault< sdw::DMat2x4 >( ast::Shader & shader )
	{
		return sdw::dmat2x4( getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader ) );
	}

	template<>
	inline sdw::DMat3 getDefault< sdw::DMat3 >( ast::Shader & shader )
	{
		return sdw::dmat3( getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader ) );
	}

	template<>
	inline sdw::DMat3x2 getDefault< sdw::DMat3x2 >( ast::Shader & shader )
	{
		return sdw::dmat3x2( getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader ) );
	}

	template<>
	inline sdw::DMat3x4 getDefault< sdw::DMat3x4 >( ast::Shader & shader )
	{
		return sdw::dmat3x4( getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader ) );
	}

	template<>
	inline sdw::DMat4 getDefault< sdw::DMat4 >( ast::Shader & shader )
	{
		return sdw::dmat4( getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader ) );
	}

	template<>
	inline sdw::DMat4x2 getDefault< sdw::DMat4x2 >( ast::Shader & shader )
	{
		return sdw::dmat4x2( getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader ) );
	}

	template<>
	inline sdw::DMat4x3 getDefault< sdw::DMat4x3 >( ast::Shader & shader )
	{
		return sdw::dmat4x3( getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader ) );
	}

	template< typename T >
	inline std::vector< T > getDefaultVector( ast::Shader & shader
		, uint32_t dimension )
	{
		std::vector< T > result;

		for ( auto i = 0u; i < dimension; ++i )
		{
			result.emplace_back( getDefault< T >( shader ) );
		}

		return result;
	}

	template< typename T >
	inline sdw::Array< T > getDefaultArray( ast::Shader & shader
		, uint32_t dimension )
	{
		ast::expr::ExprList initialisers;

		for ( auto i = 0u; i < dimension; ++i )
		{
			initialisers.emplace_back( sdw::makeExpr( getDefault< T >( shader ) ) );
		}

		return sdw::Array< T >{ &shader
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
	void expectError( std::string const & value
		, sdw_test::TestCounts & testCounts );
}

#define sdwTestSuiteBegin( name )\
	test::sdw_test::TestCounts testCounts;\
	testSuiteBeginEx( name, testCounts )

#define sdwTestSuiteEnd()\
	testSuiteEnd()
