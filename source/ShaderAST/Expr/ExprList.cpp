/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprList.hpp"
#include "ShaderAST/Expr/Expr.hpp"
#include "ShaderAST/Expr/ExprIdentifier.hpp"

#include <algorithm>

namespace ast::expr
{
	namespace details
	{
		void getCache( type::TypesCache *& result
			, Expr const & expr )
		{
			result = &expr.getCache();
		}

		void getCache( type::TypesCache *& result
			, ExprPtr const & expr )
		{
			result = &expr->getCache();
		}

		void getCache( type::TypesCache *& result
			, ExprList const & list )
		{
			assert( !list.empty() );
			result = &list[0]->getCache();
		}

		bool isConstant( Expr const & expr )
		{
			return expr.isConstant();
		}

		bool isConstant( ExprPtr const & expr )
		{
			return expr->isConstant();
		}

		bool isConstant( Identifier const & expr )
		{
			return expr.isConstant();
		}

		bool isConstant( IdentifierPtr const & expr )
		{
			return expr->isConstant();
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
}
