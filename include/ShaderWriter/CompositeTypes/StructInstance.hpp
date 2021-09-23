/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructInstance_H___
#define ___SDW_StructInstance_H___

#include "ShaderWriter/Value.hpp"

#include <ShaderAST/Type/TypeStruct.hpp>

namespace sdw
{
	class StructInstance
		: public Value
	{
	public:
		SDW_DeclValue( SDW_API, StructInstance );

		SDW_API StructInstance( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline T getMember( std::string const & name )const;
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name )const;

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
