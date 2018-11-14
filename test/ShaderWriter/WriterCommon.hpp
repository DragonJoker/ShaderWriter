#pragma once

#include "../Common.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>
#include <ShaderWriter/Intrinsics.hpp>
#include <ShaderWriter/Sampler.hpp>
#include <ShaderWriter/Image.hpp>
#include <ShaderWriter/Writer.hpp>
#include <ShaderWriter/WriterDebug.hpp>

namespace test
{
	template< typename T >
	T getDefault( sdw::Shader & shader );

	template<>
	inline sdw::Boolean getDefault< sdw::Boolean >( sdw::Shader & shader )
	{
		return sdw::Boolean{ &shader, sdw::expr::makeLiteral( true ) };
	}

	template<>
	inline sdw::Int getDefault< sdw::Int >( sdw::Shader & shader )
	{
		return sdw::Int{ &shader, sdw::expr::makeLiteral( 1 ) };
	}

	template<>
	inline sdw::UInt getDefault< sdw::UInt >( sdw::Shader & shader )
	{
		return sdw::UInt{ &shader, sdw::expr::makeLiteral( 1u ) };
	}

	template<>
	inline sdw::Float getDefault< sdw::Float >( sdw::Shader & shader )
	{
		return sdw::Float{ &shader, sdw::expr::makeLiteral( 1.0f ) };
	}

	template<>
	inline sdw::Double getDefault< sdw::Double >( sdw::Shader & shader )
	{
		return sdw::Double{ &shader, sdw::expr::makeLiteral( 1.0 ) };
	}

	template<>
	inline sdw::Vec2 getDefault< sdw::Vec2 >( sdw::Shader & shader )
	{
		return sdw::vec2( getDefault< sdw::Float >( shader )
			, 0.0 );
	}

	template<>
	inline sdw::Vec3 getDefault< sdw::Vec3 >( sdw::Shader & shader )
	{
		return sdw::vec3( getDefault< sdw::Float >( shader )
			, 0.0
			, 0.0 );
	}

	template<>
	inline sdw::Vec4 getDefault< sdw::Vec4 >( sdw::Shader & shader )
	{
		return sdw::vec4( getDefault< sdw::Float >( shader )
			, 0.0
			, 0.0
			, 0.0 );
	}

	template<>
	inline sdw::DVec2 getDefault< sdw::DVec2 >( sdw::Shader & shader )
	{
		return sdw::dvec2( getDefault< sdw::Double >( shader )
			, 0.0 );
	}

	template<>
	inline sdw::DVec3 getDefault< sdw::DVec3 >( sdw::Shader & shader )
	{
		return sdw::dvec3( getDefault< sdw::Double >( shader )
			, 0.0
			, 0.0 );
	}

	template<>
	inline sdw::DVec4 getDefault< sdw::DVec4 >( sdw::Shader & shader )
	{
		return sdw::dvec4( getDefault< sdw::Double >( shader )
			, 0.0
			, 0.0
			, 0.0 );
	}

	template<>
	inline sdw::BVec2 getDefault< sdw::BVec2 >( sdw::Shader & shader )
	{
		return sdw::bvec2( getDefault< sdw::Boolean >( shader )
			, 0.0 );
	}

	template<>
	inline sdw::BVec3 getDefault< sdw::BVec3 >( sdw::Shader & shader )
	{
		return sdw::bvec3( getDefault< sdw::Boolean >( shader )
			, 0.0
			, 0.0 );
	}

	template<>
	inline sdw::BVec4 getDefault< sdw::BVec4 >( sdw::Shader & shader )
	{
		return sdw::bvec4( getDefault< sdw::Boolean >( shader )
			, 0.0
			, 0.0
			, 0.0 );
	}

	template<>
	inline sdw::IVec2 getDefault< sdw::IVec2 >( sdw::Shader & shader )
	{
		return sdw::ivec2( getDefault< sdw::Int >( shader )
			, 0 );
	}

	template<>
	inline sdw::IVec3 getDefault< sdw::IVec3 >( sdw::Shader & shader )
	{
		return sdw::ivec3( getDefault< sdw::Int >( shader )
			, 0
			, 0 );
	}

	template<>
	inline sdw::IVec4 getDefault< sdw::IVec4 >( sdw::Shader & shader )
	{
		return sdw::ivec4( getDefault< sdw::Int >( shader )
			, 0
			, 0
			, 0 );
	}

	template<>
	inline sdw::UVec2 getDefault< sdw::UVec2 >( sdw::Shader & shader )
	{
		return sdw::uvec2( getDefault< sdw::UInt >( shader )
			, 0u );
	}

	template<>
	inline sdw::UVec3 getDefault< sdw::UVec3 >( sdw::Shader & shader )
	{
		return sdw::uvec3( getDefault< sdw::UInt >( shader )
			, 0u
			, 0u );
	}

	template<>
	inline sdw::UVec4 getDefault< sdw::UVec4 >( sdw::Shader & shader )
	{
		return sdw::uvec4( getDefault< sdw::UInt >( shader )
			, 0u
			, 0u
			, 0u );
	}

	template<>
	inline sdw::Mat2 getDefault< sdw::Mat2 >( sdw::Shader & shader )
	{
		return sdw::mat2( getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader ) );
	}

	template<>
	inline sdw::Mat2x3 getDefault< sdw::Mat2x3 >( sdw::Shader & shader )
	{
		return sdw::mat2x3( getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader ) );
	}

	template<>
	inline sdw::Mat2x4 getDefault< sdw::Mat2x4 >( sdw::Shader & shader )
	{
		return sdw::mat2x4( getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader ) );
	}

	template<>
	inline sdw::Mat3 getDefault< sdw::Mat3 >( sdw::Shader & shader )
	{
		return sdw::mat3( getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader ) );
	}

	template<>
	inline sdw::Mat3x2 getDefault< sdw::Mat3x2 >( sdw::Shader & shader )
	{
		return sdw::mat3x2( getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader ) );
	}

	template<>
	inline sdw::Mat3x4 getDefault< sdw::Mat3x4 >( sdw::Shader & shader )
	{
		return sdw::mat3x4( getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader ) );
	}

	template<>
	inline sdw::Mat4 getDefault< sdw::Mat4 >( sdw::Shader & shader )
	{
		return sdw::mat4( getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader ) );
	}

	template<>
	inline sdw::Mat4x2 getDefault< sdw::Mat4x2 >( sdw::Shader & shader )
	{
		return sdw::mat4x2( getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader ) );
	}

	template<>
	inline sdw::Mat4x3 getDefault< sdw::Mat4x3 >( sdw::Shader & shader )
	{
		return sdw::mat4x3( getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader ) );
	}

	template<>
	inline sdw::DMat2 getDefault< sdw::DMat2 >( sdw::Shader & shader )
	{
		return sdw::dmat2( getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader ) );
	}

	template<>
	inline sdw::DMat2x3 getDefault< sdw::DMat2x3 >( sdw::Shader & shader )
	{
		return sdw::dmat2x3( getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader ) );
	}

	template<>
	inline sdw::DMat2x4 getDefault< sdw::DMat2x4 >( sdw::Shader & shader )
	{
		return sdw::dmat2x4( getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader )
			, getDefault< sdw::DVec2 >( shader ) );
	}

	template<>
	inline sdw::DMat3 getDefault< sdw::DMat3 >( sdw::Shader & shader )
	{
		return sdw::dmat3( getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader ) );
	}

	template<>
	inline sdw::DMat3x2 getDefault< sdw::DMat3x2 >( sdw::Shader & shader )
	{
		return sdw::dmat3x2( getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader ) );
	}

	template<>
	inline sdw::DMat3x4 getDefault< sdw::DMat3x4 >( sdw::Shader & shader )
	{
		return sdw::dmat3x4( getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader )
			, getDefault< sdw::DVec3 >( shader ) );
	}

	template<>
	inline sdw::DMat4 getDefault< sdw::DMat4 >( sdw::Shader & shader )
	{
		return sdw::dmat4( getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader ) );
	}

	template<>
	inline sdw::DMat4x2 getDefault< sdw::DMat4x2 >( sdw::Shader & shader )
	{
		return sdw::dmat4x2( getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader ) );
	}

	template<>
	inline sdw::DMat4x3 getDefault< sdw::DMat4x3 >( sdw::Shader & shader )
	{
		return sdw::dmat4x3( getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader )
			, getDefault< sdw::DVec4 >( shader ) );
	}

	template< typename T >
	inline std::vector< T > getDefaultVector( sdw::Shader & shader
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
	inline sdw::Array< T > getDefaultArray( sdw::Shader & shader
		, uint32_t dimension )
	{
		ast::expr::ExprList initialisers;

		for ( auto i = 0u; i < dimension; ++i )
		{
			initialisers.emplace_back( sdw::makeExpr( getDefault< T >( shader ) ) );
		}

		return sdw::Array< T >{ &shader
			, ast::expr::makeAggrInit( nullptr
				, std::move( initialisers ) ) };
	}

	void writeShader( sdw::ShaderWriter const & writer
		, test::TestCounts & testCounts
		, bool validateSpirV = true
		, bool validateHlsl = true
		, bool validateGlsl = true );
}
