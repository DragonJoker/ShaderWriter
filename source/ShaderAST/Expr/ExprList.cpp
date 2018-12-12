/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprList.hpp"

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
	}
}
