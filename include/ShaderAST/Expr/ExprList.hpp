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
	class Identifier;
	using IdentifierPtr = std::unique_ptr< Identifier >;

	namespace details
	{
		SDAST_API void getCache( type::TypesCache *& result
			, Expr const & expr );
		SDAST_API void getCache( type::TypesCache *& result
			, ExprPtr const & expr );
		SDAST_API void getCache( type::TypesCache *& result
			, ExprList const & list );
		SDAST_API bool isConstant( Expr const & expr );
		SDAST_API bool isConstant( ExprPtr const & expr );
		SDAST_API bool isConstant( Identifier const & expr );
		SDAST_API bool isConstant( IdentifierPtr const & expr );
		SDAST_API bool isConstant( ExprList const & list );

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
	inline type::TypesCache & getExprTypesCache( ParamsT const & ... params )
	{
		type::TypesCache * result{ nullptr };
		details::getExprCacheRec( result, params... );
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
