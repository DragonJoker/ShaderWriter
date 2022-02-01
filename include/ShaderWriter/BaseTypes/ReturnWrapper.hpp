/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ReturnWrapper_H___
#define ___SDW_ReturnWrapper_H___
#pragma once

#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	template< typename ValueT >
	struct ReturnWrapperT
		: public ValueT
	{
		ReturnWrapperT( ReturnWrapperT const & rhs ) = delete;
		ReturnWrapperT & operator=( ReturnWrapperT const & rhs ) = delete;
		ReturnWrapperT & operator=( ReturnWrapperT && rhs ) = delete;

		ReturnWrapperT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		ReturnWrapperT( ValueT const & rhs );
		ReturnWrapperT( ReturnWrapperT && rhs );
		~ReturnWrapperT()override;

		expr::Expr * getExpr()const override;

		sdw::expr::ExprPtr release()const;
		expr::ExprPtr makeCondition();

		operator ValueT &&();

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

	private:
		mutable ast::expr::ExprPtr m_remnExpr;
	};

	template< typename ValueT >
	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, ReturnWrapperT< ValueT > const & variable
		, bool force = true );

	template< typename ValueT >
	struct IsReturnWrapper
		: std::false_type
	{
	};

	template< typename ValueT >
	struct IsReturnWrapper< ReturnWrapperT< ValueT > >
		: std::true_type
	{
	};

	template< typename ValueT >
	static bool constexpr isReturnWrapper = IsReturnWrapper< ValueT >::value;
}

#include "ReturnWrapper.inl"

#endif
