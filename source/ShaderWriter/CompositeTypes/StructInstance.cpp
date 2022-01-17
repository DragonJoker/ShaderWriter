/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

#include "ShaderWriter/BaseTypes/Bool.hpp"
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

	Int getIntMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int >( builtin );
	}

	UInt getUIntMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt >( builtin );
	}

	UInt64 getUInt64Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt64 >( builtin );
	}

	Float getFloatMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Float >( builtin );
	}

	Array< Int > getIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Int >( builtin );
	}

	Array< Float > getFloatMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Float >( builtin );
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

	UVec2 getUVec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UVec2 >( builtin );
	}

	UVec3 getUVec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UVec3 >( builtin );
	}

	UVec4 getUVec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UVec4 >( builtin );
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

	//*********************************************************************************************

	StructInstance::StructInstance( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_type{ getStructType( getType() ) }
	{
	}

	//*********************************************************************************************
}
