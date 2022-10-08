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
		ReturnWrapperT & operator=( ReturnWrapperT && rhs ) = delete;

		ReturnWrapperT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		explicit ReturnWrapperT( ValueT const & rhs );
		ReturnWrapperT( ReturnWrapperT && rhs );
		~ReturnWrapperT()override;

		type::TypePtr getType()const override;
		expr::Expr * getExpr()const override;

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

	template< typename ValueT >
	struct DefaultedT
		: ValueT
	{
		DefaultedT( ValueT const & value
			, ValueT def )
			: ValueT{ findWriterMandat( value, def ), makeExpr( value ), true }
			, m_default{ std::move( def ) }
			, m_wasEnabled{ value.isEnabled() }
		{
		}

		DefaultedT & operator=( ReturnWrapperT< ValueT > const & rhs )
		{
			if ( m_wasEnabled )
			{
				ValueT::operator=( rhs );
			}

			return *this;
		}

		DefaultedT & operator=( ValueT const & rhs )
		{
			if ( m_wasEnabled )
			{
				ValueT::operator=( rhs );
			}

			return *this;
		}

		ValueT & operator*()
		{
			return value();
		}

		operator ValueT()const
		{
			return value();
		}

		operator sdw::Param< ValueT >()const
		{
			return { value() };
		}

		operator sdw::InParam< ValueT >()const
		{
			return { value() };
		}

		operator sdw::InOutParam< ValueT >()
		{
			return { value() };
		}

		operator sdw::OutParam< ValueT >()
		{
			return { value() };
		}

		ValueT const & getDefault()const
		{
			return m_default;
		}

		ValueT const & getValue()const
		{
			return *this;
		}

		expr::Expr * getExpr()const override
		{
			return m_wasEnabled
				? ValueT::getExpr()
				: m_default.getExpr();
		}

	private:
		ValueT const & value()const
		{
			return m_wasEnabled
				? *this
				: m_default;
		}

		ValueT & value()
		{
			return *this;
		}

	private:
		ValueT m_default;
		bool m_wasEnabled;
	};
}

#include "ReturnWrapper.inl"

#endif
