/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Defaulted_H___
#define ___SDW_Defaulted_H___
#pragma once

#include "ShaderWriter/BaseTypes/ReturnWrapper.hpp"

namespace sdw
{
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

		operator bool()const
		{
			return m_wasEnabled;
		}

		ValueT const & getDefault()const
		{
			return m_default;
		}

		ValueT const & getValue()const
		{
			return *this;
		}

		expr::Expr const * getExpr()const override
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

	template< typename ValueT >
	struct IsDefaultedT
		: std::false_type
	{
	};

	template< typename ValueT >
	struct IsDefaultedT< DefaultedT< ValueT > >
		: std::true_type
	{
	};

	template< typename ValueT >
	static bool constexpr isDefaultedV = IsDefaultedT< ValueT >::value;
}

#endif
