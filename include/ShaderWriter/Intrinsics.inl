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
		return getCtorCall< Vec2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Vec3 vec3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Vec3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Vec4 vec4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Vec4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DVec2 dvec2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DVec2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DVec3 dvec3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DVec3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DVec4 dvec4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DVec4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline IVec2 ivec2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< IVec2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline IVec3 ivec3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< IVec3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline IVec4 ivec4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< IVec4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline UVec2 uvec2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< UVec2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline UVec3 uvec3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< UVec3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline UVec4 uvec4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< UVec4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline BVec2 bvec2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< BVec2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline BVec3 bvec3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< BVec3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline BVec4 bvec4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< BVec4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat2 mat2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat2x3 mat2x3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat2x3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat2x4 mat2x4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat2x4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat3 mat3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat3x2 mat3x2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat3x2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat3x4 mat3x4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat3x4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat4 mat4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat4x2 mat4x2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat4x2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline Mat4x3 mat4x3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< Mat4x3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat2 dmat2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat2x3 dmat2x3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat2x3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat2x4 dmat2x4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat2x4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat3 dmat3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat3 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat3x2 dmat3x2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat3x2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat3x4 dmat3x4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat3x4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat4 dmat4( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat4 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat4x2 dmat4x2( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat4x2 >( value
			, values... );
	}

	template< typename ... ValuesT >
	inline DMat4x3 dmat4x3( Value const & value
		, ValuesT const & ... values )
	{
		return getCtorCall< DMat4x3 >( value
			, values... );
	}

	//***********************************************************************************************
}
