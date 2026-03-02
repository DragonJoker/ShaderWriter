/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		template< typename ... ValuesT >
		struct ComponentsCounterT;

		template<>
		struct ComponentsCounterT< void >
		{
			static constexpr size_t value = 0u;
		};

		template< typename ValueT >
		struct ComponentsCounterT< ValueT >
		{
			static constexpr size_t value = TypeTraits< ValueT >::ComponentCount;
		};

		template< typename ValueT, typename ... ValuesT >
		struct ComponentsCounterT< ValueT, ValuesT... >
		{
			static constexpr size_t value = TypeTraits< ValueT >::ComponentCount
				+ ComponentsCounterT< ValuesT... >::value;
		};

		template< typename ... ValuesT >
		static constexpr size_t componentsCountV = ComponentsCounterT< std::remove_cvref_t< ValuesT >... >::value;

		template< typename ... ValuesT >
		struct ValuesCounterT;

		template<>
		struct ValuesCounterT< void >
		{
			static constexpr size_t value = 0u;
		};

		template< typename ValueT >
		struct ValuesCounterT< ValueT >
		{
			static constexpr size_t value = 1u;
		};

		template< typename ValueT, typename ... ValuesT >
		struct ValuesCounterT< ValueT, ValuesT... >
		{
			static constexpr size_t value = 1u
				+ ValuesCounterT< ValuesT... >::value;
		};

		template< typename ... ValuesT >
		static constexpr size_t valuesCountV = ValuesCounterT< std::remove_cvref_t< ValuesT >... >::value;

		template< typename ... ValuesT >
		struct TypeKindGetterT;

		template<>
		struct TypeKindGetterT< void >
		{
			static constexpr ast::type::Kind value = ast::type::Kind::eVoid;
		};

		template< typename ValueT >
		struct TypeKindGetterT< ValueT >
		{
			static constexpr ast::type::Kind value = typeEnumV< ComponentTypeT< ValueT > >;
		};

		template< typename ValueT, typename ... ValuesT >
		struct TypeKindGetterT< ValueT, ValuesT... >
		{
			static constexpr ast::type::Kind value = typeEnumV< ComponentTypeT< ValueT > >;
		};

		template< typename ... ValuesT >
		static constexpr type::Kind componentsTypeKindV = TypeKindGetterT< std::remove_cvref_t< ValuesT >... >::value;
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Vec2T< ComponentT > vec2T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Vec2T< ComponentT > >
				&& ( details::componentsCountV< ValuesT... > == 3u || details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Vec2T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Vec3T< ComponentT > vec3T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Vec3T< ComponentT > >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Vec3T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Vec4T< ComponentT > vec4T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Vec4T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Vec2 vec2( ValuesT && ... values )
	{
		return vec2T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Vec3 vec3( ValuesT && ... values )
	{
		return vec3T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Vec4 vec4( ValuesT && ... values )
	{
		return vec4T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DVec2 dvec2( ValuesT && ... values )
	{
		return vec2T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DVec3 dvec3( ValuesT && ... values )
	{
		return vec3T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DVec4 dvec4( ValuesT && ... values )
	{
		return vec4T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline HVec2 f16vec2( ValuesT && ... values )
	{
		return vec2T< Half >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline HVec4 f16vec4( ValuesT && ... values )
	{
		return vec4T< Half >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I8Vec2 i8vec2( ValuesT && ... values )
	{
		return vec2T< Int8 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I8Vec3 i8vec3( ValuesT && ... values )
	{
		return vec3T< Int8 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I8Vec4 i8vec4( ValuesT && ... values )
	{
		return vec4T< Int8 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I16Vec2 i16vec2( ValuesT && ... values )
	{
		return vec2T< Int16 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I16Vec3 i16vec3( ValuesT && ... values )
	{
		return vec3T< Int16 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I16Vec4 i16vec4( ValuesT && ... values )
	{
		return vec4T< Int16 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec2 i32vec2( ValuesT && ... values )
	{
		return vec2T< Int32 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec3 i32vec3( ValuesT && ... values )
	{
		return vec3T< Int32 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec4 i32vec4( ValuesT && ... values )
	{
		return vec4T< Int32 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I64Vec2 i64vec2( ValuesT && ... values )
	{
		return vec2T< Int64 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I64Vec3 i64vec3( ValuesT && ... values )
	{
		return vec3T< Int64 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I64Vec4 i64vec4( ValuesT && ... values )
	{
		return vec4T< Int64 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U8Vec2 u8vec2( ValuesT && ... values )
	{
		return vec2T< UInt8 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U8Vec3 u8vec3( ValuesT && ... values )
	{
		return vec3T< UInt8 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U8Vec4 u8vec4( ValuesT && ... values )
	{
		return vec4T< UInt8 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U16Vec2 u16vec2( ValuesT && ... values )
	{
		return vec2T< UInt16 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U16Vec3 u16vec3( ValuesT && ... values )
	{
		return vec3T< UInt16 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U16Vec4 u16vec4( ValuesT && ... values )
	{
		return vec4T< UInt16 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec2 u32vec2( ValuesT && ... values )
	{
		return vec2T< UInt32 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec3 u32vec3( ValuesT && ... values )
	{
		return vec3T< UInt32 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec4 u32vec4( ValuesT && ... values )
	{
		return vec4T< UInt32 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U64Vec2 u64vec2( ValuesT && ... values )
	{
		return vec2T< UInt64 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U64Vec3 u64vec3( ValuesT && ... values )
	{
		return vec3T< UInt64 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U64Vec4 u64vec4( ValuesT && ... values )
	{
		return vec4T< UInt64 >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline BVec2 bvec2( ValuesT && ... values )
	{
		return vec2T< Boolean >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline BVec3 bvec3( ValuesT && ... values )
	{
		return vec3T< Boolean >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline BVec4 bvec4( ValuesT && ... values )
	{
		return vec4T< Boolean >( std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat2x2T< ComponentT > mat2x2T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat2x2T< ComponentT > >
				&& ( details::componentsCountV< ValuesT... > == 6u // 2x3 or 3x2
					|| details::componentsCountV< ValuesT... > == 8u // 2x4 or 4x2
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat2x2T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat2x3T< ComponentT > mat2x3T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 6u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat2x3T< ComponentT > >
				&& ( details::componentsCountV< ValuesT... > == 8u // 2x4
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat2x3T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat2x4T< ComponentT > mat2x4T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 8u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat2x4T< ComponentT > >
				&& ( details::componentsCountV< ValuesT... > == 12u // 3x4
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat2x4T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat3x2T< ComponentT > mat3x2T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 6u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat3x2T< ComponentT > >
				&& ( details::componentsCountV< ValuesT... > == 8u // 4x2
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat3x2T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat3x3T< ComponentT > mat3x3T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 9u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat3x3T< ComponentT > >
				&& ( details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat3x3T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat3x4T< ComponentT > mat3x4T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 12u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat3x4T< ComponentT > >
				&& details::componentsCountV< ValuesT... > == 16u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat3x4T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat4x2T< ComponentT > mat4x2T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 8u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat4x2T< ComponentT > >
				&& ( details::componentsCountV< ValuesT... > == 12u // 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat4x2T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat4x3T< ComponentT > mat4x3T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 12u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat4x3T< ComponentT > >
				&& details::componentsCountV< ValuesT... > == 16u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat4x3T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ComponentT, typename ... ValuesT >
	inline Mat4x4T< ComponentT > mat4x4T( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 16u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat4x4T< ComponentT > >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat2x2 mat2x2( ValuesT && ... values )
	{
		return mat2x2T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat2x3 mat2x3( ValuesT && ... values )
	{
		return mat2x3T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat2x4 mat2x4( ValuesT && ... values )
	{
		return mat2x4T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat3x2 mat3x2( ValuesT && ... values )
	{
		return mat3x2T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat3x3 mat3x3( ValuesT && ... values )
	{
		return mat3x3T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat3x4 mat3x4( ValuesT && ... values )
	{
		return mat3x4T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat4x2 mat4x2( ValuesT && ... values )
	{
		return mat4x2T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat4x3 mat4x3( ValuesT && ... values )
	{
		return mat4x3T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat4x4 mat4x4( ValuesT && ... values )
	{
		return mat4x4T< Float >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat2x2 dmat2x2( ValuesT && ... values )
	{
		return mat2x2T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat2x3 dmat2x3( ValuesT && ... values )
	{
		return mat2x3T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat2x4 dmat2x4( ValuesT && ... values )
	{
		return mat2x4T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat3x2 dmat3x2( ValuesT && ... values )
	{
		return mat3x2T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat3x3 dmat3x3( ValuesT && ... values )
	{
		return mat3x3T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat3x4 dmat3x4( ValuesT && ... values )
	{
		return mat3x4T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat4x2 dmat4x2( ValuesT && ... values )
	{
		return mat4x2T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat4x3 dmat4x3( ValuesT && ... values )
	{
		return mat4x3T< Double >( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat4x4 dmat4x4( ValuesT && ... values )
	{
		return mat4x4T< Double >( std::forward< ValuesT >( values )... );
	}

	template< ValueT ValT >
	inline NonUniformT< ValT > nonuniform( ValT const & value )
	{
		return NonUniformT< ValT >{ findWriterMandat( value )
			, makeExpr( value )
			, value.isEnabled() };
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > combine( SampledImageT< FormatT, DimT, ArrayedT, MsT > const & image
		, SamplerT< DepthT > const & sampler )
	{
		auto & writer = findWriterMandat( image, sampler );
		return getCombineCall< FormatT, DimT, ArrayedT, MsT, DepthT >( writer
			, image
			, sampler );
	}
}
