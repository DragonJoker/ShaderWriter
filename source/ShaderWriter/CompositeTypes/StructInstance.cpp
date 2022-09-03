/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

#include "ShaderWriter/BaseTypes/Boolean.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"
#include "ShaderWriter/VecTypes/Vec2.hpp"
#include "ShaderWriter/VecTypes/Vec3.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <ShaderAST/Shader.hpp>

namespace sdw
{
	//*********************************************************************************************

	Boolean getBoolMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Boolean >( builtin );
	}

	Int8 getInt8Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int8 >( builtin );
	}

	Int16 getInt16Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int16 >( builtin );
	}

	Int32 getInt32Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int32 >( builtin );
	}

	Int64 getInt64Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int64 >( builtin );
	}

	Int32 getIntMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getInt32Member( instance, builtin );
	}

	UInt8 getUInt8Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt8 >( builtin );
	}

	UInt16 getUInt16Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt16 >( builtin );
	}

	UInt32 getUInt32Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt32 >( builtin );
	}

	UInt64 getUInt64Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt64 >( builtin );
	}

	UInt32 getUIntMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getUInt32Member( instance, builtin );
	}

	Float getFloatMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Float >( builtin );
	}

	Vec2 getVec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Vec2 >( builtin );
	}

	Vec3 getVec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Vec3 >( builtin );
	}

	Vec4 getVec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Vec4 >( builtin );
	}

	U8Vec2 getU8Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U8Vec2 >( builtin );
	}

	U8Vec3 getU8Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U8Vec3 >( builtin );
	}

	U8Vec4 getU8Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U8Vec4 >( builtin );
	}

	U16Vec2 getU16Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U16Vec2 >( builtin );
	}

	U16Vec3 getU16Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U16Vec3 >( builtin );
	}

	U16Vec4 getU16Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U16Vec4 >( builtin );
	}

	U32Vec2 getU32Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U32Vec2 >( builtin );
	}

	U32Vec3 getU32Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U32Vec3 >( builtin );
	}

	U32Vec4 getU32Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U32Vec4 >( builtin );
	}

	U64Vec2 getU64Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U64Vec2 >( builtin );
	}

	U64Vec3 getU64Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U64Vec3 >( builtin );
	}

	U64Vec4 getU64Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U64Vec4 >( builtin );
	}

	U32Vec2 getUVec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getU32Vec2Member( instance, builtin );
	}

	U32Vec3 getUVec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getU32Vec3Member( instance, builtin );
	}

	U32Vec4 getUVec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getU32Vec4Member( instance, builtin );
	}

	I8Vec2 getI8Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I8Vec2 >( builtin );
	}

	I8Vec3 getI8Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I8Vec3 >( builtin );
	}

	I8Vec4 getI8Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I8Vec4 >( builtin );
	}

	I16Vec2 getI16Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I16Vec2 >( builtin );
	}

	I16Vec3 getI16Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I16Vec3 >( builtin );
	}

	I16Vec4 getI16Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I16Vec4 >( builtin );
	}

	I32Vec2 getI32Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I32Vec2 >( builtin );
	}

	I32Vec3 getI32Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I32Vec3 >( builtin );
	}

	I32Vec4 getI32Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I32Vec4 >( builtin );
	}

	I64Vec2 getI64Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I64Vec2 >( builtin );
	}

	I64Vec3 getI64Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I64Vec3 >( builtin );
	}

	I64Vec4 getI64Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I64Vec4 >( builtin );
	}

	I32Vec2 getIVec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getI32Vec2Member( instance, builtin );
	}

	I32Vec3 getIVec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getI32Vec3Member( instance, builtin );
	}

	I32Vec4 getIVec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getI32Vec4Member( instance, builtin );
	}

	Mat4x3 getMat4x3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Mat4x3 >( builtin );
	}

	Mat3x4 getMat3x4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Mat3x4 >( builtin );
	}

	Array< Int32 > getIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Int32 >( builtin );
	}

	Array< UInt32 > getUIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< UInt32 >( builtin );
	}

	Array< Float > getFloatMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Float >( builtin );
	}

	Array< Vec4 > getVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Vec4 >( builtin );
	}

	Array< I32Vec2 > getIVec2MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< I32Vec2 >( builtin );
	}

	Array< I32Vec3 > getIVec3MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< I32Vec3 >( builtin );
	}

	Array< I32Vec4 > getIVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< I32Vec4 >( builtin );
	}

	Array< U32Vec2 > getUVec2MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< U32Vec2 >( builtin );
	}

	Array< U32Vec3 > getUVec3MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< U32Vec3 >( builtin );
	}

	Array< U32Vec4 > getUVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< U32Vec4 >( builtin );
	}

	Array< Array< Int32 > > getIntMemberArrayArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Array< Int32 > >( builtin );
	}

	Array< Array< Float > > getFloatMemberArrayArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Array< Float > >( builtin );
	}

	//*********************************************************************************************

	StructInstance::StructInstance( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_type{ getStructType( getType() ) }
	{
		assert( m_type != nullptr && "Non structure type ?" );
	}

	//*********************************************************************************************
}
