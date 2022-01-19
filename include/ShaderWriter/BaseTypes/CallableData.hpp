/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CallableData_H___
#define ___SDW_CallableData_H___
#pragma once

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	template< ast::var::Flag FlagT, typename ValueT >
	struct CallableDataBaseT
		: public ValueT
	{
		SDW_DeclValue( , CallableDataBaseT );

		template< typename ... ParamsT >
		CallableDataBaseT( ShaderWriter & writer
			, uint32_t location
			, ParamsT ... params );
		CallableDataBaseT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		CallableDataBaseT & operator=( ValueT const & rhs );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, uint32_t location
			, ParamsT ... params );
	};

	template< ast::var::Flag FlagT, typename ValueT >
	expr::ExprPtr makeExpr( CallableDataBaseT< FlagT, ValueT > const & value );
}

#include "CallableData.inl"

#endif
