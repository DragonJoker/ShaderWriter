/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
		template< typename ValueT >
		struct Fma
		{
			static inline ValueT submit( ValueT const & a
				, ValueT const & b
				, ValueT const & c )
			{
				return ValueT{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) ) };
			}

			static inline Optional< ValueT > submitOpt( Optional< ValueT > const & a
				, ValueT const & b
				, ValueT const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) )
					, areOptionalEnabled( a, b, c ) };
			}

			static inline Optional< ValueT > submitOpt( ValueT const & a
				, Optional< ValueT > const & b
				, ValueT const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) )
					, areOptionalEnabled( a, b, c ) };
			}

			static inline Optional< ValueT > submitOpt( ValueT const & a
				, ValueT const & b
				, Optional< ValueT > const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) )
					, areOptionalEnabled( a, b, c ) };
			}

			static inline Optional< ValueT > submitOpt( Optional< ValueT > const & a
				, Optional< ValueT > const & b
				, ValueT const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) )
					, areOptionalEnabled( a, b, c ) };
			}

			static inline Optional< ValueT > submitOpt( Optional< ValueT > const & a
				, ValueT const & b
				, Optional< ValueT > const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) )
					, areOptionalEnabled( a, b, c ) };
			}

			static inline Optional< ValueT > submitOpt( ValueT const & a
				, Optional< ValueT > const & b
				, Optional< ValueT > const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) )
					, areOptionalEnabled( a, b, c ) };
			}

			static inline Optional< ValueT > submitOpt( Optional< ValueT > const & a
				, Optional< ValueT > const & b
				, Optional< ValueT > const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, expr::makeAdd( a.getType(),
						expr::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) )
					, areOptionalEnabled( a, b, c ) };
			}
		};
	}

	//***********************************************************************************************

	template< typename ... ValuesT >
	inline Vec2 vec2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Vec2 >( "vec2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Vec3 vec3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Vec3 >( "vec3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Vec4 vec4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Vec4 >( "vec4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline IVec2 ivec2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< IVec2 >( "ivec2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline IVec3 ivec3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< IVec3 >( "ivec3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline IVec4 ivec4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< IVec4 >( "ivec4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline UVec2 uvec2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< UVec2 >( "uvec2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline UVec3 uvec3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< UVec3 >( "uvec3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline UVec4 uvec4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< UVec4 >( "uvec4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline BVec2 bvec2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< BVec2 >( "bvec2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline BVec3 bvec3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< BVec3 >( "bvec3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline BVec4 bvec4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< BVec4 >( "bvec4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat2 mat2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat2 >( "mat2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat3 mat3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat3 >( "mat3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat4 mat4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat4 >( "mat4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline IMat2 imat2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< IMat2 >( "imat2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline IMat3 imat3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< IMat3 >( "imat3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline IMat4 imat4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< IMat4 >( "imat4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline UMat2 umat2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< UMat2 >( "umat2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline UMat3 umat3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< UMat3 >( "umat3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline UMat4 umat4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< UMat4 >( "umat4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline BMat2 bmat2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< BMat2 >( "bmat2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline BMat3 bmat3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< BMat3 >( "bmat3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline BMat4 bmat4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< BMat4 >( "bmat4"
			, value
			, values... );
	}

	//***********************************************************************************************

	template< typename ... ValuesT >
	inline Float dot( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Float >( "dot"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Float inversesqrt( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Float >( "inversesqrt"
			, value
			, values... );
	}

	template< typename ValueT
		, typename ... ValuesT >
		inline ValueT cross( ValueT const & value
			, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT >( "cross"
			, value
			, values... );
	}

	template< typename ValueT
		, typename ... ValuesT >
		inline ValueT clamp( ValueT const & value
			, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT >( "clamp"
			, value
			, values... );
	}

	template< typename ValueT
		, typename ... ValuesT >
		inline ValueT min( ValueT const & value
			, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT >( "min"
			, value
			, values... );
	}

	template< typename ValueT
		, typename ... ValuesT >
		inline ValueT max( ValueT const & value
			, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT >( "max"
			, value
			, values... );
	}

	template< typename ValueT
		, typename ... ValuesT >
		inline ValueT mix( ValueT const & value
			, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT >( "mix"
			, value
			, values... );
	}

	template< typename ValueT
		, typename ... ValuesT >
		inline ValueT reflect( Value const & value
			, ValuesT const & ... values )
	{
		return getFunctionCall< ValueT >( "reflect"
			, value
			, values... );
	}

	template< typename ValueT >
	inline ValueT sqrt( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "sqrt"
			, value );
	}

	template< typename ValueT >
	inline ValueT pow( ValueT const & x
		, ValueT const & y )
	{
		return getFunctionCall< ValueT >( "pow"
			, x
			, y );
	}

	template< typename ValueT >
	inline ValueT pow( ValueT const & x
		, Optional< ValueT > const & y )
	{
		return getFunctionCall< ValueT >( "pow"
			, x
			, y );
	}

	template< typename ValueT >
	inline ValueT pow2( ValueT const & p )
	{
		return getFunctionCall< ValueT >( "pow2"
			, p );
	}

	template< typename ValueT >
	ValueT normalize( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "normalize"
			, value );
	}

#if Writer_UseSwizzle

	template< typename InputT
		, typename OutputT >
		inline OutputT normalize( Swizzle< InputT, OutputT > const & value )
	{
		return getFunctionCall< OutputT >( "normalize"
			, static_cast< OutputT const & >( value ) );
	}

	template< typename InputT
		, typename OutputT >
		inline OutputT neg( Swizzle< InputT, OutputT > const & value )
	{
		return getFunctionCall< OutputT >( "-"
			, static_cast< OutputT const & >( value ) );
	}

#endif

	template< typename ValueT >
	inline ValueT transpose( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "transpose"
			, value );
	}

	template< typename ValueT >
	inline ValueT inverse( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "inverse"
			, value );
	}

	template< typename ValueT >
	inline ValueT abs( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "abs"
			, value );
	}

	template< typename ValueT >
	inline ValueT isinf( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "isinf"
			, value );
	}

	template< typename ValueA, typename ValueB >
	ValueB smoothstep( ValueA const & edge0
		, ValueA const & edge1
		, ValueB const & x )
	{
		return getFunctionCall< ValueB >( "smoothstep"
			, edge0
			, edge1
			, x );
	}

	template< typename ValueT >
	inline ValueT dFdx( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "dFdx"
			, value );
	}

	template< typename ValueT >
	inline ValueT dFdy( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "dFdy"
			, value );
	}

	template< typename ValueT >
	inline ValueT dFdxCoarse( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "dFdyCoarse"
			, value );
	}

	template< typename ValueT >
	inline ValueT dFdyCoarse( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "dFdyCoarse"
			, value );
	}

	template< typename ValueT >
	inline ValueT dFdxFine( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "dFdxFine"
			, value );
	}

	template< typename ValueT >
	inline ValueT dFdyFine( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "dFdyFine"
			, value );
	}

	template< typename ValueT >
	inline ValueT sign( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "sign"
			, value );
	}

	template< typename ValueT >
	inline ValueT mod( ValueT const & x
		, ValueT const & y )
	{
		return getFunctionCall< ValueT >( "mod"
			, x
			, y );
	}

	template< typename ValueT >
	inline ValueT mod( ValueT const & x
		, Float const & y )
	{
		return getFunctionCall< ValueT >( "mod"
			, x
			, y );
	}

	template< typename ValueT >
	inline ValueT fract( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "fract"
			, value );
	}

	template< typename ValueT >
	inline ValueT floor( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "floor"
			, value );
	}

	template< typename ValueT >
	inline ValueT trunc( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "trunc"
			, value );
	}

	template< typename ValueT >
	inline ValueT round( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "round"
			, value );
	}

	template< typename ValueE
		, typename ValueX >
		inline ValueE step( ValueE const & edge
			, ValueX const & x )
	{
		return getFunctionCall< ValueE >( "sterp"
			, edge
			, x );
	}

	template< typename ValueT >
	inline ValueT step( ValueT const & edge
		, Float const & x )
	{
		return getFunctionCall< ValueT >( "step"
			, edge
			, x );
	}

	template< typename ValueT >
	inline ValueT neg( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "-"
			, value );
	}

	template< typename ValueT >
	inline ValueT log( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "log"
			, value );
	}

	template< typename ValueT >
	inline ValueT exp( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "exp"
			, value );
	}

	template< typename ValueT >
	inline ValueT log2( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "log2"
			, value );
	}

	template< typename ValueT >
	inline ValueT exp2( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "exp2"
			, value );
	}

	template< typename ValueT >
	inline ValueT tan( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "tan"
			, value );
	}

	template< typename ValueT >
	inline ValueT sin( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "sin"
			, value );
	}

	template< typename ValueT >
	inline ValueT cos( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "cos"
			, value );
	}

	template< typename ValueT >
	inline ValueT atan( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "atan"
			, value );
	}

	template< typename ValueT >
	inline ValueT atan( ValueT const & y
		, ValueT const & x )
	{
		return getFunctionCall< ValueT >( "atan"
			, y
			, x );
	}

	template< typename ValueT >
	inline ValueT asin( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "asin"
			, value );
	}

	template< typename ValueT >
	inline ValueT acos( ValueT const & value )
	{
		return getFunctionCall< ValueT >( "acos"
			, value );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, ValueT const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a
		, ValueT const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submitOpt( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, Optional< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submitOpt( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, ValueT const & b
		, Optional< ValueT > const & c )
	{
		return details::Fma< ValueT >::submitOpt( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a
		, Optional< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submitOpt( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a
		, ValueT const & b
		, Optional< ValueT > const & c )
	{
		return details::Fma< ValueT >::submitOpt( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, Optional< ValueT > const & b
		, Optional< ValueT > const & c )
	{
		return details::Fma< ValueT >::submitOpt( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( Optional< ValueT > const & a
		, Optional< ValueT > const & b
		, Optional< ValueT > const & c )
	{
		return details::Fma< ValueT >::submitOpt( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a
		, ValueT const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, InParam< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, ValueT const & b
		, InParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a
		, InParam< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a
		, ValueT const & b
		, InParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, InParam< ValueT > const & b
		, InParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InParam< ValueT > const & a
		, InParam< ValueT > const & b
		, InParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a
		, ValueT const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, OutParam< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, ValueT const & b
		, OutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a
		, OutParam< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a
		, ValueT const & b
		, OutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, OutParam< ValueT > const & b
		, OutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( OutParam< ValueT > const & a
		, OutParam< ValueT > const & b
		, OutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a
		, ValueT const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, InOutParam< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, ValueT const & b
		, InOutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a
		, InOutParam< ValueT > const & b
		, ValueT const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a
		, ValueT const & b
		, InOutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, InOutParam< ValueT > const & b
		, InOutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	template< typename ValueT >
	inline ValueT fma( InOutParam< ValueT > const & a
		, InOutParam< ValueT > const & b
		, InOutParam< ValueT > const & c )
	{
		return details::Fma< ValueT >::submit( a
			, b
			, c );
	}

	//***********************************************************************************************
}
