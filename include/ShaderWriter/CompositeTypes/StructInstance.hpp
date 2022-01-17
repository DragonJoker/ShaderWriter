/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructInstance_H___
#define ___SDW_StructInstance_H___

#include "ShaderWriter/Value.hpp"

#include <ShaderAST/Type/TypeStruct.hpp>

namespace sdw
{
	SDW_API Boolean getBoolMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Int getIntMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UInt getUIntMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UInt64 getUInt64Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Float getFloatMember( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< Int > getIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Array< Float > getFloatMemberArray( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Vec2 getVec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Vec3 getVec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Vec4 getVec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UVec2 getUVec2Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UVec3 getUVec3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API UVec4 getUVec4Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Mat4x3 getMat4x3Member( StructInstance const & instance
		, ast::Builtin builtin );
	SDW_API Mat3x4 getMat3x4Member( StructInstance const & instance
		, ast::Builtin builtin );

	class StructInstance
		: public Value
	{
	public:
		SDW_DeclValue( SDW_API, StructInstance );

		SDW_API StructInstance( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline T getMember( std::string const & name
			, bool optional = false )const;
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name
			, bool optional = false )const;
		template< typename T >
		inline T getMember( ast::Builtin builtin )const;
		template< typename T >
		inline Array< T > getMemberArray( ast::Builtin builtin )const;

	private:
		type::StructPtr m_type;
	};
}

#define SDW_DeclStructInstance( expdecl, name )\
	expdecl ~name()override = default;\
	expdecl name & operator=( name const & rhs )\
	{\
		sdw::StructInstance::operator=( rhs );\
		return *this;\
	}\
	expdecl name & operator=( name && rhs )\
	{\
		sdw::StructInstance::operator=( std::move( rhs ) );\
		return *this;\
	}\
	expdecl name( name const & rhs ) = default;\
	expdecl name( name && rhs ) = default

#include "StructInstance.inl"

#endif
