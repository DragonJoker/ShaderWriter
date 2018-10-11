/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprFnCall_H___
#define ___AST_ExprFnCall_H___
#pragma once

#include "ExprIdentifier.hpp"
#include "ExprList.hpp"

namespace ast::expr
{
	class FnCall
		: public Expr
	{
	public:
		FnCall( type::TypePtr type
			, IdentifierPtr fn
			, ExprList && argList );

		void accept( VisitorPtr vis )override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline Identifier * getFn()const
		{
			return m_fn.get();
		}

	private:
		IdentifierPtr m_fn;
		ExprList m_argList;
	};
	using FnCallPtr = std::unique_ptr< FnCall >;

	inline FnCallPtr makeFnCall( type::TypePtr type
		, IdentifierPtr fn
		, ExprList && argList )
	{
		return std::make_unique< FnCall >( std::move( type )
			, std::move( fn )
			, std::move( argList ) );
	}
}

#endif
