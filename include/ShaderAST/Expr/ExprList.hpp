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
	namespace details
	{
		SDAST_API void getExprCache( ExprCache *& result
			, Expr const & expr );
		SDAST_API void getExprCache( ExprCache *& result
			, ExprList const & list );

		template< typename ExprT >
		void getExprCache( ExprCache *& result
			, ExprPtrT< ExprT > const & expr )
		{
			if ( expr )
			{
				getExprCache( result, *expr );
			}
		}

		SDAST_API void getTypesCache( type::TypesCache *& result
			, Expr const & expr );
		SDAST_API void getTypesCache( type::TypesCache *& result
			, ExprList const & list );

		template< typename ExprT >
		void getTypesCache( type::TypesCache *& result
			, ExprPtrT< ExprT > const & expr )
		{
			if ( expr )
			{
				getTypesCache( result, *expr );
			}
		}

		SDAST_API bool isConstant( Expr const & expr );
		SDAST_API bool isConstant( ExprList const & list );

		template< typename ExprT >
		bool isConstant( ExprPtrT< ExprT > const & expr )
		{
			if ( !expr )
			{
				return true;
			}

			return isConstant( *expr );
		}

		template< typename ParamT >
		inline void getExprExprCacheRec( ExprCache *& result
			, ParamT const & last )
		{
			getExprCache( result, last );
		}

		template< typename ParamT, typename ... ParamsT >
		inline void getExprExprCacheRec( ExprCache *& result
			, ParamT const & current
			, ParamsT const & ... params )
		{
			getExprCache( result, current );

			if ( !result )
			{
				getExprExprCacheRec( result, params... );
			}
		}

		template< typename ParamT >
		inline void getExprTypesCacheRec( type::TypesCache *& result
			, ParamT const & last )
		{
			getTypesCache( result, last );
		}

		template< typename ParamT, typename ... ParamsT >
		inline void getExprTypesCacheRec( type::TypesCache *& result
			, ParamT const & current
			, ParamsT const & ... params )
		{
			getTypesCache( result, current );

			if ( !result )
			{
				getExprTypesCacheRec( result, params... );
			}
		}

		template< typename ParamT >
		inline void isExprConstantRec( bool & result
			, ParamT const & last )
		{
			result = isConstant( last );
		}

		template< typename ParamT, typename ... ParamsT >
		inline void isExprConstantRec( bool & result
			, ParamT const & current
			, ParamsT const & ... params )
		{
			result = isConstant( current );

			if ( result )
			{
				isExprConstantRec( result, params... );
			}
		}
	}

	template< typename ... ParamsT >
	inline ExprCache & getExprExprCache( ParamsT const & ... params )
	{
		ExprCache * result{ nullptr };
		details::getExprExprCacheRec( result, params... );
		return *result;
	}

	template< typename ... ParamsT >
	inline type::TypesCache & getExprTypesCache( ParamsT const & ... params )
	{
		type::TypesCache * result{ nullptr };
		details::getExprTypesCacheRec( result, params... );
		return *result;
	}

	template< typename ... ParamsT >
	inline bool isExprConstant( ParamsT const & ... params )
	{
		bool result{ true };
		details::isExprConstantRec( result, params... );
		return result;
	}
}

#endif
