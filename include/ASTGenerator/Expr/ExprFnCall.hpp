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
		
		FnCall( type::TypePtr type
			, IdentifierPtr fn
			, ExprPtr instance
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

		inline bool isMember()const
		{
			return m_instance != nullptr;
		}

		inline Expr * getInstance()const
		{
			assert( isMember() );
			return m_instance.get();
		}

	private:
		IdentifierPtr m_fn;
		ExprList m_argList;
		ExprPtr m_instance;
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

	inline FnCallPtr makeMemberFnCall( type::TypePtr type
		, IdentifierPtr fn
		, ExprPtr instance
		, ExprList && argList )
	{
		return std::make_unique< FnCall >( std::move( type )
			, std::move( fn )
			, std::move( instance )
			, std::move( argList ) );
	}
}

#endif
