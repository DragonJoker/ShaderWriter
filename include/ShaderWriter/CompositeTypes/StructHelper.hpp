/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructHelper_H___
#define ___SDW_StructHelper_H___

#if SDW_EnableStructHelper

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"
#include "ShaderWriter/BaseTypes/Void.hpp"

namespace sdw
{
	template< size_t N >
	struct StringLiteralT
	{
		constexpr StringLiteralT( const char( &str )[N] )
		{
			std::copy_n( str, N, value );
		}

		char value[N];
	};
	// Help CTAD
	template< size_t N >
	StringLiteralT( const char( &str )[N] )->StringLiteralT< N >;

	template< typename FieldTypeT
		, StringLiteralT FieldNameT >
	struct StructFieldT
	{
		using TypeT = FieldTypeT;
		static constexpr std::string_view Name = FieldNameT.value;
		static constexpr uint32_t ArraySize = type::NotArray;

		template< typename HolderT >
		static void decl( HolderT & h )
		{
			h.template declMember< TypeT >( std::string( Name ) );
		}

		template< typename HolderT >
		static auto get( HolderT & h )
		{
			return h.template getMember< TypeT >( Name );
		}
	};

	template< typename FieldTypeT
		, StringLiteralT FieldNameT
		, uint32_t ArraySizeT >
	struct StructFieldArrayT
	{
		using TypeT = FieldTypeT;
		static constexpr std::string_view Name = FieldNameT.value;
		static constexpr uint32_t ArraySize = ArraySizeT;

		template< typename HolderT >
		static void decl( HolderT & h )
		{
			h.template declMember< TypeT >( std::string( Name ), ArraySize );
		}

		template< typename HolderT >
		static auto get( HolderT & h )
		{
			return h.template getMemberArray< TypeT >( Name );
		}
	};

	template< typename StructT
		, ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class StructHelperT : public StructT
	{
		static_assert( sizeof...( FieldsT ) > 0
			, "A structure must have at least one field" );

		struct EndType {};

		using StructT::declMember;
		using StructT::declStructMember;
		using StructT::end;
		using StructT::getMember;
		using StructT::getMemberArray;

	public:
		template< StringLiteralT FieldNameT >
		constexpr static auto getFieldByName()
		{
			return doGetFieldByName< FieldNameT, FieldsT..., EndType >();
		}

		template< StringLiteralT FieldNameT >
		using Field = decltype( getFieldByName< FieldNameT >() );

		template< StringLiteralT FieldNameT >
		auto getMember()
		{
			return Field< FieldNameT >::template get< StructT >( *this );
		}

	protected:
		template< typename ... ParamsT >
		explicit StructHelperT( ParamsT && ... params )
			: StructT{ std::forward< ParamsT >( params )... }
		{
			( FieldsT::template decl< StructT >( *this ), ... );
			end();
		}

	private:
		template< StringLiteralT FieldNameT, typename FieldU, typename... FieldsU >
		constexpr static auto doGetFieldByName()
		{
			static_assert( ! std::is_same_v<FieldU, EndType>, "That field does not exist in this structure" );

			if constexpr ( std::string_view( FieldNameT.value ) == FieldU::Name )
			{
				return FieldU{};
			}
			else
			{
				return doGetFieldByName< FieldNameT, FieldsU... >();
			}
		}
	};

	template< StringLiteralT FieldNameT > using BooleanField = StructFieldT< Boolean, FieldNameT >;
	template< StringLiteralT FieldNameT > using HalfField = StructFieldT< Half, FieldNameT >;
	template< StringLiteralT FieldNameT > using FloatField = StructFieldT< Float, FieldNameT >;
	template< StringLiteralT FieldNameT > using DoubleField = StructFieldT< Double, FieldNameT >;
	template< StringLiteralT FieldNameT > using IntField = StructFieldT< Int, FieldNameT >;
	template< StringLiteralT FieldNameT > using UIntField = StructFieldT< UInt, FieldNameT >;
	template< StringLiteralT FieldNameT > using UInt64Field = StructFieldT< UInt64, FieldNameT >;
	template< StringLiteralT FieldNameT > using Vec2Field = StructFieldT< Vec2, FieldNameT >;
	template< StringLiteralT FieldNameT > using Vec3Field = StructFieldT< Vec3, FieldNameT >;
	template< StringLiteralT FieldNameT > using Vec4Field = StructFieldT< Vec4, FieldNameT >;
	template< StringLiteralT FieldNameT > using DVec2Field = StructFieldT< DVec2, FieldNameT >;
	template< StringLiteralT FieldNameT > using DVec3Field = StructFieldT< DVec3, FieldNameT >;
	template< StringLiteralT FieldNameT > using DVec4Field = StructFieldT< DVec4, FieldNameT >;
	template< StringLiteralT FieldNameT > using HVec2Field = StructFieldT< HVec2, FieldNameT >;
	template< StringLiteralT FieldNameT > using HVec4Field = StructFieldT< HVec4, FieldNameT >;
	template< StringLiteralT FieldNameT > using IVec2Field = StructFieldT< IVec2, FieldNameT >;
	template< StringLiteralT FieldNameT > using IVec3Field = StructFieldT< IVec3, FieldNameT >;
	template< StringLiteralT FieldNameT > using IVec4Field = StructFieldT< IVec4, FieldNameT >;
	template< StringLiteralT FieldNameT > using UVec2Field = StructFieldT< UVec2, FieldNameT >;
	template< StringLiteralT FieldNameT > using UVec3Field = StructFieldT< UVec3, FieldNameT >;
	template< StringLiteralT FieldNameT > using UVec4Field = StructFieldT< UVec4, FieldNameT >;
	template< StringLiteralT FieldNameT > using U64Vec2Field = StructFieldT< U64Vec2, FieldNameT >;
	template< StringLiteralT FieldNameT > using U64Vec3Field = StructFieldT< U64Vec3, FieldNameT >;
	template< StringLiteralT FieldNameT > using U64Vec4Field = StructFieldT< U64Vec4, FieldNameT >;
	template< StringLiteralT FieldNameT > using BVec2Field = StructFieldT< BVec2, FieldNameT >;
	template< StringLiteralT FieldNameT > using BVec3Field = StructFieldT< BVec3, FieldNameT >;
	template< StringLiteralT FieldNameT > using BVec4Field = StructFieldT< BVec4, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat2Field = StructFieldT< Mat2, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat2x2Field = StructFieldT< Mat2x2, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat2x3Field = StructFieldT< Mat2x3, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat2x4Field = StructFieldT< Mat2x4, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat3Field = StructFieldT< Mat3, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat3x3Field = StructFieldT< Mat3x3, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat3x2Field = StructFieldT< Mat3x2, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat3x4Field = StructFieldT< Mat3x4, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat4Field = StructFieldT< Mat4, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat4x4Field = StructFieldT< Mat4x4, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat4x2Field = StructFieldT< Mat4x2, FieldNameT >;
	template< StringLiteralT FieldNameT > using Mat4x3Field = StructFieldT< Mat4x3, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat2Field = StructFieldT< DMat2, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat2x2Field = StructFieldT< DMat2x2, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat2x3Field = StructFieldT< DMat2x3, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat2x4Field = StructFieldT< DMat2x4, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat3Field = StructFieldT< DMat3, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat3x2Field = StructFieldT< DMat3x2, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat3x3Field = StructFieldT< DMat3x3, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat3x4Field = StructFieldT< DMat3x4, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat4Field = StructFieldT< DMat4, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat4x2Field = StructFieldT< DMat4x2, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat4x3Field = StructFieldT< DMat4x3, FieldNameT >;
	template< StringLiteralT FieldNameT > using DMat4x4Field = StructFieldT< DMat4x4, FieldNameT >;

	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using BooleanArrayField = StructFieldArrayT< Boolean, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using HalfArrayField = StructFieldArrayT< Half, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using FloatArrayField = StructFieldArrayT< Float, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DoubleArrayField = StructFieldArrayT< Double, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using IntArrayField = StructFieldArrayT< Int, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using UIntArrayField = StructFieldArrayT< UInt, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using UInt64ArrayField = StructFieldArrayT< UInt64, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Vec2ArrayField = StructFieldArrayT< Vec2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Vec3ArrayField = StructFieldArrayT< Vec3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Vec4ArrayField = StructFieldArrayT< Vec4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DVec2ArrayField = StructFieldArrayT< DVec2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DVec3ArrayField = StructFieldArrayT< DVec3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DVec4ArrayField = StructFieldArrayT< DVec4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using HVec2ArrayField = StructFieldArrayT< HVec2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using HVec4ArrayField = StructFieldArrayT< HVec4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using IVec2ArrayField = StructFieldArrayT< IVec2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using IVec3ArrayField = StructFieldArrayT< IVec3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using IVec4ArrayField = StructFieldArrayT< IVec4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using UVec2ArrayField = StructFieldArrayT< UVec2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using UVec3ArrayField = StructFieldArrayT< UVec3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using UVec4ArrayField = StructFieldArrayT< UVec4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using U64Vec2ArrayField = StructFieldArrayT< U64Vec2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using U64Vec3ArrayField = StructFieldArrayT< U64Vec3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using U64Vec4ArrayField = StructFieldArrayT< U64Vec4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using BVec2ArrayField = StructFieldArrayT< BVec2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using BVec3ArrayField = StructFieldArrayT< BVec3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using BVec4ArrayField = StructFieldArrayT< BVec4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat2ArrayField = StructFieldArrayT< Mat2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat2x2ArrayField = StructFieldArrayT< Mat2x2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat2x3ArrayField = StructFieldArrayT< Mat2x3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat2x4ArrayField = StructFieldArrayT< Mat2x4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat3ArrayField = StructFieldArrayT< Mat3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat3x3ArrayField = StructFieldArrayT< Mat3x3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat3x2ArrayField = StructFieldArrayT< Mat3x2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat3x4ArrayField = StructFieldArrayT< Mat3x4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat4ArrayField = StructFieldArrayT< Mat4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat4x4ArrayField = StructFieldArrayT< Mat4x4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat4x2ArrayField = StructFieldArrayT< Mat4x2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using Mat4x3ArrayField = StructFieldArrayT< Mat4x3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat2ArrayField = StructFieldArrayT< DMat2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat2x2ArrayField = StructFieldArrayT< DMat2x2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat2x3ArrayField = StructFieldArrayT< DMat2x3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat2x4ArrayField = StructFieldArrayT< DMat2x4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat3ArrayField = StructFieldArrayT< DMat3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat3x2ArrayField = StructFieldArrayT< DMat3x2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat3x3ArrayField = StructFieldArrayT< DMat3x3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat3x4ArrayField = StructFieldArrayT< DMat3x4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat4ArrayField = StructFieldArrayT< DMat4, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat4x2ArrayField = StructFieldArrayT< DMat4x2, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat4x3ArrayField = StructFieldArrayT< DMat4x3, FieldNameT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t ArraySizeT > using DMat4x4ArrayField = StructFieldArrayT< DMat4x4, FieldNameT, ArraySizeT >;
}

#endif

#endif
