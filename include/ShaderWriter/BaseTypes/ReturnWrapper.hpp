/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ReturnWrapper_H___
#define ___SDW_ReturnWrapper_H___
#pragma once

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

namespace sdw
{
	template< typename ValueT >
	struct ReturnWrapperT
		: public ValueT
	{
		ReturnWrapperT( ReturnWrapperT const & rhs ) = delete;
		ReturnWrapperT & operator=( ReturnWrapperT const & rhs ) = delete;
		ReturnWrapperT & operator=( ReturnWrapperT && rhs )noexcept = delete;

		ReturnWrapperT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		explicit ReturnWrapperT( ValueT const & rhs );
		ReturnWrapperT( ReturnWrapperT && rhs )noexcept;
		~ReturnWrapperT()noexcept override;

		type::TypePtr getType()const override;
		expr::Expr const * getExpr()const override;

		sdw::expr::ExprPtr release()const;
		expr::ExprPtr makeCondition();

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

	private:
		mutable ast::expr::ExprPtr m_remnExpr;
	};

	template< typename ValueT >
	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, ReturnWrapperT< ValueT > const & variable
		, bool force = true );

	template< typename ValueT >
	struct IsReturnWrapperT
		: std::false_type
	{
	};

	template< typename ValueT >
	struct IsReturnWrapperT< ReturnWrapperT< ValueT > >
		: std::true_type
	{
	};

	template< typename ValueT >
	static bool constexpr isReturnWrapperV = IsReturnWrapperT< ValueT >::value;
}

#include "ReturnWrapper.inl"

#endif
