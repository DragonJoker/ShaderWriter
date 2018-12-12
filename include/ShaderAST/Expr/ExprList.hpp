/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprList_H___
#define ___AST_ExprList_H___
#pragma once

#include "Expr.hpp"

#include <vector>

namespace ast::expr
{
	using ExprList = std::vector< ExprPtr >;

	namespace details
	{
		void getCache( type::TypesCache *& result
			, Expr const & expr );
		void getCache( type::TypesCache *& result
			, ExprPtr const & expr );
		void getCache( type::TypesCache *& result
			, ExprList const & list );

		template< typename ParamT >
		inline void getExprCacheRec( type::TypesCache *& result
			, ParamT const & last )
		{
			getCache( result, last );
		}

		template< typename ParamT, typename ... ParamsT >
		inline void getExprCacheRec( type::TypesCache *& result
			, ParamT const & current
			, ParamsT const & ... params )
		{
			getCache( result, current );

			if ( !result )
			{
				getExprCacheRec( result, params... );
			}
		}
	}

	template< typename ... ParamsT >
	inline type::TypesCache & getExprTypesCache( ParamsT const & ... params )
	{
		type::TypesCache * result{ nullptr };
		details::getExprCacheRec( result, params... );
		return *result;
	}
}

#endif
