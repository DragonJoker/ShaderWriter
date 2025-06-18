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
	private:
		ReturnWrapperT( ReturnWrapperT const & rhs ) = delete;

	public:
		ReturnWrapperT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		explicit ReturnWrapperT( ValueT const & rhs );
		ReturnWrapperT( ReturnWrapperT && rhs )noexcept;
		~ReturnWrapperT()noexcept override;
		ReturnWrapperT< ValueT > operator=( ReturnWrapperT const & rhs );
		ReturnWrapperT< ValueT > operator=( ReturnWrapperT && rhs );
		template< typename T >
		ReturnWrapperT< ValueT > operator=( T const & rhs );

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

	template< typename LhsT, typename RhsT >
	auto operator+( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } + RhsT{ rhs };
	}

	template< typename LhsT, typename RhsT >
	auto operator-( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } - RhsT{ rhs };
	}

	template< typename LhsT, typename RhsT >
	auto operator*( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } *RhsT{ rhs };
	}

	template< typename LhsT, typename RhsT >
	auto operator/( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } / RhsT{ rhs };
	}

	template< IntegerT LhsT, IntegerT RhsT >
	auto operator%( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } % RhsT{ rhs };
	}

	template< IntegerT LhsT, IntegerT RhsT >
	auto operator<<( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } << RhsT{ rhs };
	}

	template< IntegerT LhsT, IntegerT RhsT >
	auto operator>>( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } >> RhsT{ rhs };
	}

	template< IntegerT LhsT, IntegerT RhsT >
	auto operator&( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } & RhsT{ rhs };
	}

	template< IntegerT LhsT, IntegerT RhsT >
	auto operator|( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } | RhsT{ rhs };
	}

	template< IntegerT LhsT, IntegerT RhsT >
	auto operator^( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } ^ RhsT{ rhs };
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT >
	auto operator==( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } == RhsT{ rhs };
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT >
	auto operator!=( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } != RhsT{ rhs };
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT >
	auto operator<( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } < RhsT{ rhs };
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT >
	auto operator<=( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } <= RhsT{ rhs };
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT >
	auto operator>( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } > RhsT{ rhs };
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT >
	auto operator>=( ReturnWrapperT< LhsT > const & lhs, ReturnWrapperT< RhsT > const & rhs )
	{
		return LhsT{ lhs } >= RhsT{ rhs };
	}
}

#include "ReturnWrapper.inl"

#endif
