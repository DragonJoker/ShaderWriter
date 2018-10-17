#include "Common.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>
#include <ShaderWriter/Intrinsics.hpp>
#include <ShaderWriter/Sampler.hpp>
#include <ShaderWriter/Writer.hpp>
#include <ShaderWriter/WriterDebug.hpp>

namespace test
{
	template< typename T >
	T getDefault( sdw::Shader & shader );

	template<>
	sdw::Boolean getDefault< sdw::Boolean >( sdw::Shader & shader )
	{
		return sdw::Boolean{ &shader, sdw::expr::makeLiteral( true ) };
	}

	template<>
	sdw::Int getDefault< sdw::Int >( sdw::Shader & shader )
	{
		return sdw::Int{ &shader, sdw::expr::makeLiteral( 1 ) };
	}

	template<>
	sdw::UInt getDefault< sdw::UInt >( sdw::Shader & shader )
	{
		return sdw::UInt{ &shader, sdw::expr::makeLiteral( 1u ) };
	}
	template<>
	sdw::Float getDefault< sdw::Float >( sdw::Shader & shader )
	{
		return sdw::Float{ &shader, sdw::expr::makeLiteral( 1.0f ) };
	}

	template<>
	sdw::Vec2 getDefault< sdw::Vec2 >( sdw::Shader & shader )
	{
		return sdw::vec2( getDefault< sdw::Float >( shader )
			, 0.0 );
	}

	template<>
	sdw::Vec3 getDefault< sdw::Vec3 >( sdw::Shader & shader )
	{
		return sdw::vec3( getDefault< sdw::Float >( shader )
			, 0.0
			, 0.0 );
	}

	template<>
	sdw::Vec4 getDefault< sdw::Vec4 >( sdw::Shader & shader )
	{
		return sdw::vec4( getDefault< sdw::Float >( shader )
			, 0.0
			, 0.0
			, 0.0 );
	}

	template<>
	sdw::BVec2 getDefault< sdw::BVec2 >( sdw::Shader & shader )
	{
		return sdw::bvec2( getDefault< sdw::Boolean >( shader )
			, 0.0 );
	}

	template<>
	sdw::BVec3 getDefault< sdw::BVec3 >( sdw::Shader & shader )
	{
		return sdw::bvec3( getDefault< sdw::Boolean >( shader )
			, 0.0
			, 0.0 );
	}

	template<>
	sdw::BVec4 getDefault< sdw::BVec4 >( sdw::Shader & shader )
	{
		return sdw::bvec4( getDefault< sdw::Boolean >( shader )
			, 0.0
			, 0.0
			, 0.0 );
	}

	template<>
	sdw::IVec2 getDefault< sdw::IVec2 >( sdw::Shader & shader )
	{
		return sdw::ivec2( getDefault< sdw::Int >( shader )
			, 0 );
	}

	template<>
	sdw::IVec3 getDefault< sdw::IVec3 >( sdw::Shader & shader )
	{
		return sdw::ivec3( getDefault< sdw::Int >( shader )
			, 0
			, 0 );
	}

	template<>
	sdw::IVec4 getDefault< sdw::IVec4 >( sdw::Shader & shader )
	{
		return sdw::ivec4( getDefault< sdw::Int >( shader )
			, 0
			, 0
			, 0 );
	}

	template<>
	sdw::UVec2 getDefault< sdw::UVec2 >( sdw::Shader & shader )
	{
		return sdw::uvec2( getDefault< sdw::UInt >( shader )
			, 0u );
	}

	template<>
	sdw::UVec3 getDefault< sdw::UVec3 >( sdw::Shader & shader )
	{
		return sdw::uvec3( getDefault< sdw::UInt >( shader )
			, 0u
			, 0u );
	}

	template<>
	sdw::UVec4 getDefault< sdw::UVec4 >( sdw::Shader & shader )
	{
		return sdw::uvec4( getDefault< sdw::UInt >( shader )
			, 0u
			, 0u
			, 0u );
	}

	template<>
	sdw::Mat2 getDefault< sdw::Mat2 >( sdw::Shader & shader )
	{
		return sdw::mat2( getDefault< sdw::Vec2 >( shader )
			, getDefault< sdw::Vec2 >( shader ) );
	}

	template<>
	sdw::Mat3 getDefault< sdw::Mat3 >( sdw::Shader & shader )
	{
		return sdw::mat3( getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader )
			, getDefault< sdw::Vec3 >( shader ) );
	}

	template<>
	sdw::Mat4 getDefault< sdw::Mat4 >( sdw::Shader & shader )
	{
		return sdw::mat4( getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader )
			, getDefault< sdw::Vec4 >( shader ) );
	}

	template<>
	sdw::BMat2 getDefault< sdw::BMat2 >( sdw::Shader & shader )
	{
		return sdw::bmat2( getDefault< sdw::BVec2 >( shader )
			, getDefault< sdw::BVec2 >( shader ) );
	}

	template<>
	sdw::BMat3 getDefault< sdw::BMat3 >( sdw::Shader & shader )
	{
		return sdw::bmat3( getDefault< sdw::BVec3 >( shader )
			, getDefault< sdw::BVec3 >( shader )
			, getDefault< sdw::BVec3 >( shader ) );
	}

	template<>
	sdw::BMat4 getDefault< sdw::BMat4 >( sdw::Shader & shader )
	{
		return sdw::bmat4( getDefault< sdw::BVec4 >( shader )
			, getDefault< sdw::BVec4 >( shader )
			, getDefault< sdw::BVec4 >( shader )
			, getDefault< sdw::BVec4 >( shader ) );
	}

	template<>
	sdw::IMat2 getDefault< sdw::IMat2 >( sdw::Shader & shader )
	{
		return sdw::imat2( getDefault< sdw::IVec2 >( shader )
			, getDefault< sdw::IVec2 >( shader ) );
	}

	template<>
	sdw::IMat3 getDefault< sdw::IMat3 >( sdw::Shader & shader )
	{
		return sdw::imat3( getDefault< sdw::IVec3 >( shader )
			, getDefault< sdw::IVec3 >( shader )
			, getDefault< sdw::IVec3 >( shader ) );
	}

	template<>
	sdw::IMat4 getDefault< sdw::IMat4 >( sdw::Shader & shader )
	{
		return sdw::imat4( getDefault< sdw::IVec4 >( shader )
			, getDefault< sdw::IVec4 >( shader )
			, getDefault< sdw::IVec4 >( shader )
			, getDefault< sdw::IVec4 >( shader ) );
	}

	template<>
	sdw::UMat2 getDefault< sdw::UMat2 >( sdw::Shader & shader )
	{
		return sdw::umat2( getDefault< sdw::UVec2 >( shader )
			, getDefault< sdw::UVec2 >( shader ) );
	}

	template<>
	sdw::UMat3 getDefault< sdw::UMat3 >( sdw::Shader & shader )
	{
		return sdw::umat3( getDefault< sdw::UVec3 >( shader )
			, getDefault< sdw::UVec3 >( shader )
			, getDefault< sdw::UVec3 >( shader ) );
	}

	template<>
	sdw::UMat4 getDefault< sdw::UMat4 >( sdw::Shader & shader )
	{
		return sdw::umat4( getDefault< sdw::UVec4 >( shader )
			, getDefault< sdw::UVec4 >( shader )
			, getDefault< sdw::UVec4 >( shader )
			, getDefault< sdw::UVec4 >( shader ) );
	}

	template< typename T >
	std::vector< T > getDefaultArray( sdw::Shader & shader
		, uint32_t dimension )
	{
		std::vector< T > result;

		for ( auto i = 0u; i < dimension; ++i )
		{
			result.emplace_back( getDefault< T >( shader ) );
		}

		return result;
	}
}
