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
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
							makeExpr( a ),
							makeExpr( b ) ),
						makeExpr( c ) ) };
			}

			static inline Optional< ValueT > submitOpt( Optional< ValueT > const & a
				, ValueT const & b
				, ValueT const & c )
			{
				return Optional< ValueT >{ findShader( a, b, c )
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
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
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
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
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
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
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
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
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
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
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
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
					, sdw::makeAdd( a.getType(),
						sdw::makeTimes( a.getType(),
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
	inline DVec2 dvec2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DVec2 >( "dvec2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DVec3 dvec3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DVec3 >( "dvec3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DVec4 dvec4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DVec4 >( "dvec4"
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
	inline Mat2x3 mat2x3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat2x3 >( "mat2x3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat2x4 mat2x4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat2x4 >( "mat2x4"
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
	inline Mat3x2 mat3x2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat3x2 >( "mat3x2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat3x4 mat3x4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat3x4 >( "mat3x4"
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
	inline Mat4x2 mat4x2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat4x2 >( "mat4x2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat4x3 mat4x3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< Mat4x3 >( "mat4x3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat2 dmat2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat2 >( "dmat2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat2x3 dmat2x3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat2x3 >( "dmat2x3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat2x4 dmat2x4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat2x4 >( "dmat2x4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat3 dmat3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat3 >( "dmat3"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat3x2 dmat3x2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat3x2 >( "dmat3x2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat3x4 dmat3x4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat3x4 >( "dmat3x4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat4 dmat4( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat4 >( "dmat4"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat4x2 dmat4x2( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat4x2 >( "dmat4x2"
			, value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat4x3 dmat4x3( Value const & value
		, ValuesT const & ... values )
	{
		return getFunctionCall< DMat4x3 >( "dmat4x3"
			, value
			, values... );
	}

	//***********************************************************************************************
}
