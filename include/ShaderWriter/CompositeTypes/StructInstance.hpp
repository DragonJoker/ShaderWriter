/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructInstance_H___
#define ___SDW_StructInstance_H___

#include "ShaderWriter/Value.hpp"
#include "ShaderWriter/CompositeTypes/StructHelper.hpp"

#include <ShaderAST/Type/TypeStruct.hpp>

namespace sdw
{
	SDW_API ast::expr::ExprPtr getZeroValue( ast::type::TypePtr type );
	SDW_API Boolean getBoolMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Int8 getInt8Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Int16 getInt16Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Int32 getInt32Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Int64 getInt64Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Int32 getIntMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UInt8 getUInt8Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UInt16 getUInt16Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UInt32 getUInt32Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UInt64 getUInt64Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UInt32 getUIntMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Float getFloatMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Vec2 getVec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Vec3 getVec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Vec4 getVec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U8Vec2 getU8Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U8Vec3 getU8Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U8Vec4 getU8Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U16Vec2 getU16Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U16Vec3 getU16Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U16Vec4 getU16Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U32Vec2 getU32Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U32Vec3 getU32Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U32Vec4 getU32Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U64Vec2 getU64Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U64Vec3 getU64Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U64Vec4 getU64Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U32Vec2 getUVec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U32Vec3 getUVec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API U32Vec4 getUVec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I8Vec2 getI8Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I8Vec3 getI8Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I8Vec4 getI8Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I16Vec2 getI16Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I16Vec3 getI16Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I16Vec4 getI16Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I32Vec2 getI32Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I32Vec3 getI32Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I32Vec4 getI32Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I64Vec2 getI64Vec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I64Vec3 getI64Vec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I64Vec4 getI64Vec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I32Vec2 getIVec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I32Vec3 getIVec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API I32Vec4 getIVec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Mat4x3 getMat4x3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Mat3x4 getMat3x4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< Int32 > getIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< UInt32 > getUIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< Float > getFloatMemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< Vec4 > getVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< I32Vec2 > getIVec2MemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< I32Vec3 > getIVec3MemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< I32Vec4 > getIVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< U32Vec2 > getUVec2MemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< U32Vec3 > getUVec3MemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< U32Vec4 > getUVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< Array< Int32 > > getIntMemberArrayArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< Array< Float > > getFloatMemberArrayArray( StructInstance const & instance
		, ast::Builtin builtin );

	class StructInstance
		: public Value
	{
	public:
		SDW_DeclValue( SDW_API, StructInstance );

		SDW_API StructInstance( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		bool hasMember( std::string_view name )const;
		template< typename T >
		T getMember( std::string_view name
			, bool optional = false )const;
		template< ValueT T >
		DefaultedT< T > getMember( std::string_view name
			, T optionalValue )const;
		template< typename T >
		Array< T > getMemberArray( std::string_view name
			, bool optional = false )const;
		template< ValueT T >
		DefaultedT< Array< T > > getMemberArray( std::string_view name
			, Array< T > optionalValue )const;
		bool hasMember( ast::Builtin builtin );
		template< typename T >
		T getMember( ast::Builtin builtin )const;
		template< typename T >
		Array< T > getMemberArray( ast::Builtin builtin )const;

	protected:
		SDW_API static ast::expr::ExprPtr makeInitExpr( ast::type::StructPtr type
			, StructInstance const * rhs );

	private:
		ast::expr::ExprPtr doGetMember( uint32_t mbrIndex )const;

	private:
		type::StructPtr m_type;
	};
}

#define SDW_DeclStructInstance( expdecl, name )\
	expdecl ~name()noexcept override = default;\
	expdecl name & operator=( name const & rhs )\
	{\
		sdw::StructInstance::operator=( rhs );\
		return *this;\
	}\
	expdecl name & operator=( name && rhs )noexcept\
	{\
		sdw::StructInstance::operator=( std::move( rhs ) );\
		return *this;\
	}\
	template< typename ... ParamsT >\
	name( sdw::StructInstance const & rhs\
		, ParamsT && ... params )\
		: name{ *rhs.getWriter()\
			, sdw::StructInstance::makeInitExpr( name::makeType( sdw::findTypesCache( rhs ), std::forward< ParamsT >( params )... ), &rhs )\
			, rhs.isEnabled() }\
	{\
	}\
	expdecl name( name const & rhs ) = default;\
	expdecl name( name && rhs )noexcept = default

#include "StructInstance.inl"
#include "StructInstanceHelper.hpp"

#endif
