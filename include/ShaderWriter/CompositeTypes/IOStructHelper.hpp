/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IOStructHelper_H___
#define ___SDW_IOStructHelper_H___

#if SDW_EnableStructHelper

#include "ShaderWriter/CompositeTypes/StructHelper.hpp"

namespace sdw
{
	template< typename FieldTypeT
		, StringLiteralT FieldNameT
		, uint32_t LocationT >
	struct IOStructFieldT
	{
		using TypeT = FieldTypeT;
		static constexpr std::string_view Name = FieldNameT.value;
		static constexpr uint32_t Location = LocationT;
		static constexpr uint32_t ArraySize = type::NotArray;

		template< typename HolderT >
		static void decl( HolderT & h )
		{
			h.template declMember< TypeT >( std::string( Name ), LocationT );
		}

		template< typename HolderT >
		static auto get( HolderT & h )
		{
			return h.template getMember< TypeT >( Name );
		}
	};

	template< typename FieldTypeT
		, StringLiteralT FieldNameT
		, uint32_t LocationT
		, uint32_t ArraySizeT >
	struct IOStructFieldArrayT
	{
		using TypeT = FieldTypeT;
		static constexpr std::string_view Name = FieldNameT.value;
		static constexpr uint32_t Location = LocationT;
		static constexpr uint32_t ArraySize = ArraySizeT;

		template< typename HolderT >
		static void decl( HolderT & h )
		{
			h.template declMember< TypeT >( std::string( Name ), LocationT, ArraySize );
		}

		template< typename HolderT >
		static auto get( HolderT & h )
		{
			return h.template getMemberArray< TypeT >( Name );
		}
	};

	template< typename StructT
		, typename... FieldsT >
	class IOStructHelperT : public StructT
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
		auto getMember()const
		{
			return Field< FieldNameT >::template get< StructT >( *this );
		}

	protected:
		template< typename ... ParamsT >
		explicit IOStructHelperT( ParamsT && ... params )
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

	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOBooleanField = IOStructFieldT< Boolean, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOHalfField = IOStructFieldT< Half, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOFloatField = IOStructFieldT< Float, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODoubleField = IOStructFieldT< Double, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOIntField = IOStructFieldT< Int, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOUIntField = IOStructFieldT< UInt, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOUInt64Field = IOStructFieldT< UInt64, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOVec2Field = IOStructFieldT< Vec2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOVec3Field = IOStructFieldT< Vec3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOVec4Field = IOStructFieldT< Vec4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODVec2Field = IOStructFieldT< DVec2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODVec3Field = IOStructFieldT< DVec3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODVec4Field = IOStructFieldT< DVec4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOHVec2Field = IOStructFieldT< HVec2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOHVec4Field = IOStructFieldT< HVec4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOIVec2Field = IOStructFieldT< IVec2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOIVec3Field = IOStructFieldT< IVec3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOIVec4Field = IOStructFieldT< IVec4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOUVec2Field = IOStructFieldT< UVec2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOUVec3Field = IOStructFieldT< UVec3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOUVec4Field = IOStructFieldT< UVec4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOU64Vec2Field = IOStructFieldT< U64Vec2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOU64Vec3Field = IOStructFieldT< U64Vec3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOU64Vec4Field = IOStructFieldT< U64Vec4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOBVec2Field = IOStructFieldT< BVec2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOBVec3Field = IOStructFieldT< BVec3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOBVec4Field = IOStructFieldT< BVec4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat2Field = IOStructFieldT< Mat2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat2x2Field = IOStructFieldT< Mat2x2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat2x3Field = IOStructFieldT< Mat2x3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat2x4Field = IOStructFieldT< Mat2x4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat3Field = IOStructFieldT< Mat3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat3x3Field = IOStructFieldT< Mat3x3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat3x2Field = IOStructFieldT< Mat3x2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat3x4Field = IOStructFieldT< Mat3x4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat4Field = IOStructFieldT< Mat4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat4x4Field = IOStructFieldT< Mat4x4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat4x2Field = IOStructFieldT< Mat4x2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IOMat4x3Field = IOStructFieldT< Mat4x3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat2Field = IOStructFieldT< DMat2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat2x2Field = IOStructFieldT< DMat2x2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat2x3Field = IOStructFieldT< DMat2x3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat2x4Field = IOStructFieldT< DMat2x4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat3Field = IOStructFieldT< DMat3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat3x2Field = IOStructFieldT< DMat3x2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat3x3Field = IOStructFieldT< DMat3x3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat3x4Field = IOStructFieldT< DMat3x4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat4Field = IOStructFieldT< DMat4, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat4x2Field = IOStructFieldT< DMat4x2, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat4x3Field = IOStructFieldT< DMat4x3, LocationT, FieldNameT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT > using IODMat4x4Field = IOStructFieldT< DMat4x4, LocationT, FieldNameT >;

	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOBooleanArrayField = IOStructFieldArrayT< Boolean, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOHalfArrayField = IOStructFieldArrayT< Half, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOFloatArrayField = IOStructFieldArrayT< Float, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODoubleArrayField = IOStructFieldArrayT< Double, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOIntArrayField = IOStructFieldArrayT< Int, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOUIntArrayField = IOStructFieldArrayT< UInt, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOUInt64ArrayField = IOStructFieldArrayT< UInt64, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOVec2ArrayField = IOStructFieldArrayT< Vec2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOVec3ArrayField = IOStructFieldArrayT< Vec3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOVec4ArrayField = IOStructFieldArrayT< Vec4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODVec2ArrayField = IOStructFieldArrayT< DVec2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODVec3ArrayField = IOStructFieldArrayT< DVec3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODVec4ArrayField = IOStructFieldArrayT< DVec4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOHVec2ArrayField = IOStructFieldArrayT< HVec2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOHVec4ArrayField = IOStructFieldArrayT< HVec4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOIVec2ArrayField = IOStructFieldArrayT< IVec2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOIVec3ArrayField = IOStructFieldArrayT< IVec3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOIVec4ArrayField = IOStructFieldArrayT< IVec4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOUVec2ArrayField = IOStructFieldArrayT< UVec2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOUVec3ArrayField = IOStructFieldArrayT< UVec3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOUVec4ArrayField = IOStructFieldArrayT< UVec4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOU64Vec2ArrayField = IOStructFieldArrayT< U64Vec2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOU64Vec3ArrayField = IOStructFieldArrayT< U64Vec3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOU64Vec4ArrayField = IOStructFieldArrayT< U64Vec4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOBVec2ArrayField = IOStructFieldArrayT< BVec2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOBVec3ArrayField = IOStructFieldArrayT< BVec3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOBVec4ArrayField = IOStructFieldArrayT< BVec4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat2ArrayField = IOStructFieldArrayT< Mat2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat2x2ArrayField = IOStructFieldArrayT< Mat2x2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat2x3ArrayField = IOStructFieldArrayT< Mat2x3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat2x4ArrayField = IOStructFieldArrayT< Mat2x4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat3ArrayField = IOStructFieldArrayT< Mat3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat3x3ArrayField = IOStructFieldArrayT< Mat3x3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat3x2ArrayField = IOStructFieldArrayT< Mat3x2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat3x4ArrayField = IOStructFieldArrayT< Mat3x4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat4ArrayField = IOStructFieldArrayT< Mat4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat4x4ArrayField = IOStructFieldArrayT< Mat4x4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat4x2ArrayField = IOStructFieldArrayT< Mat4x2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IOMat4x3ArrayField = IOStructFieldArrayT< Mat4x3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat2ArrayField = IOStructFieldArrayT< DMat2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat2x2ArrayField = IOStructFieldArrayT< DMat2x2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat2x3ArrayField = IOStructFieldArrayT< DMat2x3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat2x4ArrayField = IOStructFieldArrayT< DMat2x4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat3ArrayField = IOStructFieldArrayT< DMat3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat3x2ArrayField = IOStructFieldArrayT< DMat3x2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat3x3ArrayField = IOStructFieldArrayT< DMat3x3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat3x4ArrayField = IOStructFieldArrayT< DMat3x4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat4ArrayField = IOStructFieldArrayT< DMat4, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat4x2ArrayField = IOStructFieldArrayT< DMat4x2, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat4x3ArrayField = IOStructFieldArrayT< DMat4x3, FieldNameT, LocationT, ArraySizeT >;
	template< StringLiteralT FieldNameT, uint32_t LocationT, uint32_t ArraySizeT > using IODMat4x4ArrayField = IOStructFieldArrayT< DMat4x4, FieldNameT, LocationT, ArraySizeT >;
}

#endif

#endif
