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

	template< typename ... ValuesT >
	inline Vec2 vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Vec3 vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Vec4 vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DVec2 dvec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DVec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DVec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DVec3 dvec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DVec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DVec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DVec4 dvec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DVec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline HVec2 f16vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< HVec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< HVec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline HVec4 f16vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< HVec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I8Vec2 i8vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I8Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I8Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I8Vec3 i8vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I8Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I8Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I8Vec4 i8vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I8Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I16Vec2 i16vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I16Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I16Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I16Vec3 i16vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I16Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I16Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I16Vec4 i16vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I16Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec2 i32vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I32Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I32Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec3 i32vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I32Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I32Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec4 i32vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I32Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I64Vec2 i64vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I64Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I64Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I64Vec3 i64vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< I64Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I64Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I64Vec4 i64vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< I64Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U8Vec2 u8vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U8Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U8Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U8Vec3 u8vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U8Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U8Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U8Vec4 u8vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U8Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U16Vec2 u16vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U16Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U16Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U16Vec3 u16vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U16Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U16Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U16Vec4 u16vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U16Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec2 u32vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U32Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U32Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec3 u32vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U32Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U32Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec4 u32vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U32Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U64Vec2 u64vec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U64Vec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U64Vec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U64Vec3 u64vec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< U64Vec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U64Vec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U64Vec4 u64vec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< U64Vec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline BVec2 bvec2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 2u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< BVec2 >
				&& ( details::componentsCountV< ValuesT... > == 3u
					|| details::componentsCountV< ValuesT... > == 4u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< BVec2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline BVec3 bvec3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 3u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< BVec3 >
				&& details::componentsCountV< ValuesT... > == 4u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< BVec3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline BVec4 bvec4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< BVec4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat2x2 mat2x2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat2x2 >
				&& ( details::componentsCountV< ValuesT... > == 6u // 2x3 or 3x2
					|| details::componentsCountV< ValuesT... > == 8u // 2x4 or 4x2
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat2x2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat2x3 mat2x3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 6u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat2x3 >
				&& ( details::componentsCountV< ValuesT... > == 8u // 2x4
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat2x3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat2x4 mat2x4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 8u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat2x4 >
				&& ( details::componentsCountV< ValuesT... > == 12u // 3x4
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat2x4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat3x2 mat3x2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 6u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat3x2 >
				&& ( details::componentsCountV< ValuesT... > == 8u // 4x2
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat3x2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat3x3 mat3x3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 9u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat3x3 >
				&& ( details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat3x3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat3x4 mat3x4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 12u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat3x4 >
				&& details::componentsCountV< ValuesT... > == 16u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat3x4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat4x2 mat4x2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 8u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat4x2 >
				&& ( details::componentsCountV< ValuesT... > == 12u // 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat4x2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat4x3 mat4x3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 12u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< Mat4x3 >
				&& details::componentsCountV< ValuesT... > == 16u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat4x3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat4x4 mat4x4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 16u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< Mat4x4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat2x2 dmat2x2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 4u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat2x2 >
				&& ( details::componentsCountV< ValuesT... > == 6u // 2x3 or 3x2
					|| details::componentsCountV< ValuesT... > == 8u // 2x4 or 4x2
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat2x2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat2x3 dmat2x3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 6u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat2x3 >
				&& ( details::componentsCountV< ValuesT... > == 8u // 2x4
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat2x3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat2x4 dmat2x4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 8u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat2x4 >
				&& ( details::componentsCountV< ValuesT... > == 12u // 3x4
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat2x4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat3x2 dmat3x2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 6u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat3x2 >
				&& ( details::componentsCountV< ValuesT... > == 8u // 4x2
					|| details::componentsCountV< ValuesT... > == 9u // 3x3
					|| details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat3x2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat3x3 dmat3x3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 9u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat3x3 >
				&& ( details::componentsCountV< ValuesT... > == 12u // 3x4 or 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat3x3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat3x4 dmat3x4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 12u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat3x4 >
				&& details::componentsCountV< ValuesT... > == 16u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat3x4 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat4x2 dmat4x2( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 8u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat4x2 >
				&& ( details::componentsCountV< ValuesT... > == 12u // 4x3
					|| details::componentsCountV< ValuesT... > == 16u ) ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat4x2 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat4x3 dmat4x3( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 12u
			|| details::componentsCountV< ValuesT... > == 1u
			|| ( details::valuesCountV< ValuesT... > == 1u
				&& details::componentsTypeKindV< ValuesT ... > == details::componentsTypeKindV< DMat4x3 >
				&& details::componentsCountV< ValuesT... > == 16u ) );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat4x3 >( writer, std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat4x4 dmat4x4( ValuesT && ... values )
	{
		static_assert( details::componentsCountV< ValuesT... > == 16u );
		auto & writer = findWriterMandat( values... );
		return getCtorCall< DMat4x4 >( writer, std::forward< ValuesT >( values )... );
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
