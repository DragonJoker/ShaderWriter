/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprList.hpp"
#include "ShaderAST/Expr/Expr.hpp"
#include "ShaderAST/Expr/ExprIdentifier.hpp"

#include <algorithm>

namespace ast::expr::details
{
	void getExprCache( ExprCache *& result
		, Expr const & expr )
	{
		result = &expr.getExprCache();
	}

	void getExprCache( ExprCache *& result
		, ExprList const & list )
	{
		assert( !list.empty() );
		result = &list[0]->getExprCache();
	}

	void getTypesCache( type::TypesCache *& result
		, Expr const & expr )
	{
		result = &expr.getTypesCache();
	}

	void getTypesCache( type::TypesCache *& result
		, ExprList const & list )
	{
		assert( !list.empty() );
		result = &list[0]->getTypesCache();
	}

	bool isConstant( Expr const & expr )
	{
		return expr.isConstant();
	}

	bool isConstant( ExprList const & list )
	{
		return std::all_of( list.begin()
			, list.end()
			, []( auto const & lookup )
			{
				return isConstant( *lookup );
			} );
	}
}
