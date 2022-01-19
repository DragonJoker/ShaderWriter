/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HitAttribute_H___
#define ___SDW_HitAttribute_H___
#pragma once

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	template< typename ValueT >
	struct HitAttributeT
		: public ValueT
	{
		SDW_DeclValue( , HitAttributeT );

		template< typename ... ParamsT >
		HitAttributeT( ShaderWriter & writer
			, ParamsT ... params );
		HitAttributeT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		HitAttributeT & operator=( ValueT const & rhs );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );
	};

	template< typename ValueT >
	expr::ExprPtr makeExpr( HitAttributeT< ValueT > const & value );
}

#include "HitAttribute.inl"

#endif
