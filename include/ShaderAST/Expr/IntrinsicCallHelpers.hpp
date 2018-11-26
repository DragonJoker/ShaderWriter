/*
See LICENSE file in root folder
*/
#ifndef ___AST_IntrinsicCallHelpers_H___
#define ___AST_IntrinsicCallHelpers_H___
#pragma once

#include "ExprList.hpp"

namespace ast::expr::helpers
{
	inline void fillArgsListRec( ExprList & result )
	{
	}

	template< typename Param >
	inline void fillArgsListRec( ExprList & result
		, Param arg )
	{
		result.emplace_back( std::move( arg ) );
	}

	template< typename Param, typename ... Params >
	inline void fillArgsListRec( ExprList & result
		, Param arg
		, Params ... args )
	{
		result.emplace_back( std::move( arg ) );
		fillArgsListRec( result, std::forward< Params >( args )... );
	}
}

#endif
