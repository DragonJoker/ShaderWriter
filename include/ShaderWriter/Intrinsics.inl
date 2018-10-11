/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	template< typename ... ValuesT >
	inline Vec2 vec2( Value const & value, ValuesT const & ... values )
	{
		return Vec2{ findContainer( value, values... )
			, getFunctionCall< Vec2, Value, ValuesT... >( "vec2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline Vec3 vec3( Value const & value, ValuesT const & ... values )
	{
		return Vec3{ findContainer( value, values... )
			, getFunctionCall< Vec3, Value, ValuesT... >( "vec3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline Vec4 vec4( Value const & value, ValuesT const & ... values )
	{
		return Vec4{ findContainer( value, values... )
			, getFunctionCall< Vec4, Value, ValuesT... >( "vec4", value, values... ) };
	}

	template< typename ... ValuesT >
	inline IVec2 ivec2( Value const & value, ValuesT const & ... values )
	{
		return IVec2{ findContainer( value, values... )
			, getFunctionCall< IVec2, Value, ValuesT... >( "ivec2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline IVec3 ivec3( Value const & value, ValuesT const & ... values )
	{
		return IVec3{ findContainer( value, values... )
			, getFunctionCall< IVec3, Value, ValuesT... >( "ivec3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline IVec4 ivec4( Value const & value, ValuesT const & ... values )
	{
		return IVec4{ findContainer( value, values... )
			, getFunctionCall< IVec4, Value, ValuesT... >( "ivec4", value, values... ) };
	}

	template< typename ... ValuesT >
	inline UVec2 uvec2( Value const & value, ValuesT const & ... values )
	{
		return UVec2{ findContainer( value, values... )
			, getFunctionCall< UVec2, Value, ValuesT... >( "uvec2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline UVec3 uvec3( Value const & value, ValuesT const & ... values )
	{
		return UVec3{ findContainer( value, values... )
			, getFunctionCall< UVec3, Value, ValuesT... >( "uvec3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline UVec4 uvec4( Value const & value, ValuesT const & ... values )
	{
		return UVec4{ findContainer( value, values... )
			, getFunctionCall< UVec4, Value, ValuesT... >( "uvec4", value, values... ) };
	}

	template< typename ... ValuesT >
	inline BVec2 bvec2( Value const & value, ValuesT const & ... values )
	{
		return BVec2{ findContainer( value, values... )
			, getFunctionCall< BVec2, Value, ValuesT... >( "bvec2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline BVec3 bvec3( Value const & value, ValuesT const & ... values )
	{
		return BVec3{ findContainer( value, values... )
			, getFunctionCall< BVec3, Value, ValuesT... >( "bvec3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline BVec4 bvec4( Value const & value, ValuesT const & ... values )
	{
		return BVec4{ findContainer( value, values... )
			, getFunctionCall< BVec4, Value, ValuesT... >( "bvec4", value, values... ) };
	}

	template< typename ... ValuesT >
	inline Mat2 mat2( Value const & value, ValuesT const & ... values )
	{
		return Mat2{ findContainer( value, values... )
			, getFunctionCall< Mat2, Value, ValuesT... >( "mat2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline Mat3 mat3( Value const & value, ValuesT const & ... values )
	{
		return Mat3{ findContainer( value, values... )
			, getFunctionCall< Mat3, Value, ValuesT... >( "mat3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline Mat4 mat4( Value const & value, ValuesT const & ... values )
	{
		return Mat4{ findContainer( value, values... )
			, getFunctionCall< Mat4, Value, ValuesT... >( "mat4", value, values... ) };
	}

	template< typename ... ValuesT >
	inline IMat2 imat2( Value const & value, ValuesT const & ... values )
	{
		return IMat2{ findContainer( value, values... )
			, getFunctionCall< IMat2, Value, ValuesT... >( "imat2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline IMat3 imat3( Value const & value, ValuesT const & ... values )
	{
		return IMat3{ findContainer( value, values... )
			, getFunctionCall< IMat3, Value, ValuesT... >( "imat3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline IMat4 imat4( Value const & value, ValuesT const & ... values )
	{
		return IMat4{ findContainer( value, values... )
			, getFunctionCall< IMat4, Value, ValuesT... >( "imat4", value, values... ) };
	}

	template< typename ... ValuesT >
	inline UMat2 umat2( Value const & value, ValuesT const & ... values )
	{
		return UMat2{ findContainer( value, values... )
			, getFunctionCall< UMat2, Value, ValuesT... >( "umat2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline UMat3 umat3( Value const & value, ValuesT const & ... values )
	{
		return UMat3{ findContainer( value, values... )
			, getFunctionCall< UMat3, Value, ValuesT... >( "umat3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline UMat4 umat4( Value const & value, ValuesT const & ... values )
	{
		return UMat4{ findContainer( value, values... )
			, getFunctionCall< UMat4, Value, ValuesT... >( "umat4", value, values... ) };
	}

	template< typename ... ValuesT >
	inline BMat2 bmat2( Value const & value, ValuesT const & ... values )
	{
		return BMat2{ findContainer( value, values... )
			, getFunctionCall< BMat2, Value, ValuesT... >( "bmat2", value, values... ) };
	}

	template< typename ... ValuesT >
	inline BMat3 bmat3( Value const & value, ValuesT const & ... values )
	{
		return BMat3{ findContainer( value, values... )
			, getFunctionCall< BMat3, Value, ValuesT... >( "bmat3", value, values... ) };
	}

	template< typename ... ValuesT >
	inline BMat4 bmat4( Value const & value, ValuesT const & ... values )
	{
		return BMat4{ findContainer( value, values... )
			, getFunctionCall< BMat4, Value, ValuesT... >( "bmat4", value, values... ) };
	}
#if 0
	//***********************************************************************************************

	template< typename ... ValuesT >
	inline Float dot( Value const & value, ValuesT const & ... values )
	{
		return getFunctionCall< Float, Value, ValuesT... >( findContainer( value, values... ), "dot", value, values... );
	}

	template< typename ... ValuesT >
	inline Float inversesqrt( Value const & value, ValuesT const & ... values )
	{
		return getFunctionCall< Float, Value, ValuesT... >( findContainer( value, values... ), "inversesqrt", value, values... );
	}

	template< typename ValueT, typename ... ValuesT >
	inline ValueT cross( ValueT const & value, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT, Value, ValuesT... >( findContainer( value, values... ), "cross", value, values... );
	}

	template< typename ValueT, typename ... ValuesT >
	inline ValueT clamp( ValueT const & value, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT, Value, ValuesT... >( findContainer( value, values... ), "clamp", value, values... );
	}

	template< typename ValueT, typename ... ValuesT >
	inline ValueT min( ValueT const & value, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT, Value, ValuesT... >( findContainer( value, values... ), "min", value, values... );
	}

	template< typename ValueT, typename ... ValuesT >
	inline ValueT max( ValueT const & value, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT, Value, ValuesT... >( findContainer( value, values... ), "max", value, values... );
	}

	template< typename ValueT, typename ... ValuesT >
	inline ValueT mix( ValueT const & value, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT, Value, ValuesT... >( findContainer( value, values... ), "mix", value, values... );
	}

	template< typename ValueT, typename ... ValuesT >
	inline ValueT reflect( Value const & value, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT, Value, ValuesT... >( findContainer( value, values... ), "reflect", value, values... );
	}

	template< typename ValueT >
	inline ValueT sqrt( ValueT const & value )
	{
		return getFunctionCall< ValueT, ValueT >( findContainer( value ), "sqrt", value );
	}

	template< typename ValueT >
	inline ValueT pow( ValueT const & x, ValueT const & y )
	{
		return getFunctionCall< ValueT >( x.m_container, "pow", x, y );
	}

	template< typename ValueT >
	inline ValueT pow( ValueT const & x, Optional< ValueT > const & y )
	{
		return getFunctionCall< ValueT >( x.m_container, "pow", x, y );
	}

	template< typename ValueT >
	inline ValueT pow2( ValueT const & p )
	{
		return getFunctionCall< ValueT >( p.m_container, "pow2", p );
	}

	template< typename ValueT >
	ValueT normalize( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "normalize", value );
	}

	template< typename Input, typename Output >
	inline Output normalize( Swizzle< Input, Output > const & value )
	{
		return getFunctionCall< Output >( findContainer( value ), "normalize", static_cast< Output const >( value ) );
	}

	template< typename ValueT >
	inline ValueT transpose( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "transpose", value );
	}

	template< typename ValueT >
	inline ValueT inverse( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "inverse", value );
	}

	template< typename ValueT >
	inline ValueT abs( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "abs", value );
	}

	template< typename ValueT >
	inline ValueT isinf( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "isinf", value );
	}

	template< typename ValueA, typename ValueB >
	ValueB smoothstep( ValueA const & edge0, ValueA const & edge1, ValueB const & x )
	{
		return getFunctionCall< ValueB >( findContainer( edge0, edge1, x ), "smoothstep", edge0, edge1,x );
	}

	template< typename ValueT >
	inline ValueT dFdx( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "dFdx", value );
	}

	template< typename ValueT >
	inline ValueT dFdy( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "dFdy", value );
	}

	template< typename ValueT >
	inline ValueT dFdxCoarse( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "dFdyCoarse", value );
	}

	template< typename ValueT >
	inline ValueT dFdyCoarse( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "dFdyCoarse", value );
	}

	template< typename ValueT >
	inline ValueT dFdxFine( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "dFdxFine", value );
	}

	template< typename ValueT >
	inline ValueT dFdyFine( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "dFdyFine", value );
	}

	template< typename ValueT >
	inline ValueT sign( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "sign", value );
	}

	template< typename ValueT >
	inline ValueT mod( ValueT const & x, ValueT const & y )
	{
		return getFunctionCall< ValueT >( x.m_container, "mod", x, y );
	}

	template< typename ValueT >
	inline ValueT mod( ValueT const & x, Float const & y )
	{
		return getFunctionCall< ValueT >( findContainer( x, y ), "mod", x, y );
	}

	template< typename ValueT >
	inline ValueT fract( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "fract", value );
	}

	template< typename ValueT >
	inline ValueT floor( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "floor", value );
	}

	template< typename ValueT >
	inline ValueT trunc( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "trunc", value );
	}

	template< typename ValueT >
	inline ValueT round( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "round", value );
	}

	template< typename ValueE, typename ValueX >
	inline ValueE step( ValueE const & edge, ValueX const & x )
	{
		return details::Step< ValueE, ValueX >::step( edge, x );
	}

	template< typename ValueT >
	inline ValueT step( ValueT const & edge, Float const & x )
	{
		return getFunctionCall< ValueT >( findContainer( edge, x ), "step", edge, x );
	}

	template< typename ValueT >
	inline ValueT neg( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "-", value );
	}

	template< typename Input, typename Output >
	inline Output neg( Swizzle< Input, Output > const & value )
	{
		return getFunctionCall< Output >( findContainer( value ), "-", static_cast< Output >( value ) );
	}

	template< typename ValueT >
	inline ValueT log( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "log", value );
	}

	template< typename ValueT >
	inline ValueT exp( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "exp", value );
	}

	template< typename ValueT >
	inline ValueT log2( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "log2", value );
	}

	template< typename ValueT >
	inline ValueT exp2( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "exp2", value );
	}

	template< typename ValueT >
	inline ValueT tan( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "tan", value );
	}

	template< typename ValueT >
	inline ValueT sin( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "sin", value );
	}

	template< typename ValueT >
	inline ValueT cos( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "cos", value );
	}

	template< typename ValueT >
	inline ValueT atan( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "atan", value );
	}

	template< typename ValueT >
	inline ValueT atan( ValueT const & y, ValueT const & x )
	{
		return getFunctionCall< ValueT >( findContainer( y, x ), "atan", y, x );
	}

	template< typename ValueT >
	inline ValueT asin( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "asin", value );
	}

	template< typename ValueT >
	inline ValueT acos( ValueT const & value )
	{
		return getFunctionCall< ValueT >( findContainer( value ), "acos", value );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, ValueT const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a, ValueT const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );

		if ( a.isEnabled() )
		{
			ValueT result{ writer };
			result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
			return result;
		}
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, Optional< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );

		if ( b.isEnabled() )
		{
			ValueT result{ writer };
			result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
			return result;
		}
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, ValueT const & b, Optional< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );

		if ( c.isEnabled() )
		{
			ValueT result{ writer };
			result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
			return result;
		}
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a, Optional< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );

		if ( a.isEnabled() && b.isEnabled() )
		{
			ValueT result{ writer };
			result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
			return result;
		}
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a, ValueT const & b, Optional< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );

		if ( a.isEnabled() && c.isEnabled() )
		{
			ValueT result{ writer };
			result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
			return result;
		}
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, Optional< ValueT > const & b, Optional< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );

		if ( b.isEnabled() && c.isEnabled() )
		{
			ValueT result{ writer };
			result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
			return result;
		}
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a, Optional< ValueT > const & b, Optional< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );

		if ( a.isEnabled() && b.isEnabled() && c.isEnabled() )
		{
			ValueT result{ writer };
			result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
			return result;
		}
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a, ValueT const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, InParam< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, ValueT const & b, InParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a, InParam< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a, ValueT const & b, InParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, InParam< ValueT > const & b, InParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a, InParam< ValueT > const & b, InParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a, ValueT const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, OutParam< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, ValueT const & b, OutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a, OutParam< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a, ValueT const & b, OutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, OutParam< ValueT > const & b, OutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a, OutParam< ValueT > const & b, OutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a, ValueT const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, InOutParam< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, ValueT const & b, InOutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a, InOutParam< ValueT > const & b, ValueT const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a, ValueT const & b, InOutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a, InOutParam< ValueT > const & b, InOutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a, InOutParam< ValueT > const & b, InOutParam< ValueT > const & c )
	{
		auto writer = findContainer( a, b, c );
		ValueT result{ writer };
		result.m_value << "((" << toString( a ) << ") * (" << toString( b ) << ") + (" << toString( c ) << "))";
		return result;
	}
#endif
	//***********************************************************************************************
}
