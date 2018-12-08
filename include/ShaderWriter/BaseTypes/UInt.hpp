/*
See LICENSE file in root folder
*/
#ifndef ___SDW_UInt_H___
#define ___SDW_UInt_H___
#pragma once

#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

namespace sdw
{
	struct UInt
		: public Value
	{
		UInt( Shader * shader
			, expr::ExprPtr expr );
		UInt( UInt && value );
		UInt( UInt const & value );
		explicit UInt( uint16_t rhs );
		explicit UInt( uint32_t rhs );
		explicit UInt( uint64_t rhs );
		explicit UInt( Value const & rhs );
		UInt & operator=( UInt const & rhs );
		expr::ExprPtr makeCondition()const;
		template< typename T >
		inline UInt & operator=( T const & rhs );
		UInt & operator=( uint32_t const & rhs );
		UInt & operator=( uint64_t const & rhs );
		UInt & operator++();
		UInt operator++( int );
		UInt & operator--();
		UInt operator--( int );
		UInt & operator+=( UInt const & rhs );
		UInt & operator-=( UInt const & rhs );
		UInt & operator*=( UInt const & rhs );
		UInt & operator/=( UInt const & rhs );
		UInt & operator+=( Optional< UInt > const & rhs );
		UInt & operator-=( Optional< UInt > const & rhs );
		UInt & operator*=( Optional< UInt > const & rhs );
		UInt & operator/=( Optional< UInt > const & rhs );
		UInt & operator+=( uint32_t const & rhs );
		UInt & operator-=( uint32_t const & rhs );
		UInt & operator*=( uint32_t const & rhs );
		UInt & operator/=( uint32_t const & rhs );
		UInt & operator%=( UInt const & rhs );
		UInt & operator%=( Optional< UInt > const & rhs );
		UInt & operator<<=( uint32_t const & rhs );
		UInt & operator>>=( uint32_t const & rhs );
		UInt & operator<<=( UInt const & rhs );
		UInt & operator>>=( UInt const & rhs );
		UInt & operator<<=( Optional< UInt > const & rhs );
		UInt & operator>>=( Optional< UInt > const & rhs );
		UInt & operator&=( uint32_t const & rhs );
		UInt & operator|=( uint32_t const & rhs );
		UInt & operator^=( uint32_t const & rhs );
		UInt & operator&=( UInt const & rhs );
		UInt & operator|=( UInt const & rhs );
		UInt & operator^=( UInt const & rhs );
		UInt & operator&=( Optional< UInt > const & rhs );
		UInt & operator|=( Optional< UInt > const & rhs );
		UInt & operator^=( Optional< UInt > const & rhs );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	UInt operator+( UInt const & rhs, UInt const & lhs );
	UInt operator-( UInt const & rhs, UInt const & lhs );
	UInt operator*( UInt const & rhs, UInt const & lhs );
	UInt operator/( UInt const & rhs, UInt const & lhs );
	UInt operator+( UInt const & rhs, uint32_t const & lhs );
	UInt operator-( UInt const & rhs, uint32_t const & lhs );
	UInt operator*( UInt const & rhs, uint32_t const & lhs );
	UInt operator/( UInt const & rhs, uint32_t const & lhs );
	UInt operator+( uint32_t const & lhs, UInt const & rhs );
	UInt operator-( uint32_t const & lhs, UInt const & rhs );
	UInt operator*( uint32_t const & lhs, UInt const & rhs );
	UInt operator/( uint32_t const & lhs, UInt const & rhs );
	UInt operator%( UInt const & lhs, uint32_t const & rhs );
	UInt operator%( UInt const & lhs, UInt const & rhs );

	UInt operator<<( UInt const & lhs, uint32_t const & rhs );
	UInt operator>>( UInt const & lhs, uint32_t const & rhs );
	UInt operator<<( UInt const & lhs, UInt const & rhs );
	UInt operator>>( UInt const & lhs, UInt const & rhs );
	UInt operator&( UInt const & lhs, uint32_t const & rhs );
	UInt operator|( UInt const & lhs, uint32_t const & rhs );
	UInt operator^( UInt const & lhs, uint32_t const & rhs );
	UInt operator&( UInt const & lhs, UInt const & rhs );
	UInt operator|( UInt const & lhs, UInt const & rhs );
	UInt operator^( UInt const & lhs, UInt const & rhs );
	UInt operator~( UInt const & value );

	Optional< UInt > operator+( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator+( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator-( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator*( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator/( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator+( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator+( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator+( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator-( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator*( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator/( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator%( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, Optional< UInt > const & rhs );

	Optional< UInt > operator<<( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator<<( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator<<( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator>>( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator<<( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator^( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator^( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator&( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator|( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator^( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator^( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator~( Optional< UInt > const & value );

	Boolean operator==( UInt const & lhs, UInt const & rhs );
	Boolean operator!=( UInt const & lhs, UInt const & rhs );
	Boolean operator<( UInt const & lhs, UInt const & rhs );
	Boolean operator<=( UInt const & lhs, UInt const & rhs );
	Boolean operator>( UInt const & lhs, UInt const & rhs );
	Boolean operator>=( UInt const & lhs, UInt const & rhs );
	Optional< Boolean > operator==( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< Boolean > operator!=( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< Boolean > operator<( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< Boolean > operator<=( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< Boolean > operator>( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< Boolean > operator>=( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< Boolean > operator==( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator!=( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator<( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator<=( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator>( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator>=( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator==( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator!=( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator<( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator<=( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator>( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator>=( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Boolean operator==( UInt const & lhs, uint32_t const & rhs );
	Boolean operator!=( UInt const & lhs, uint32_t const & rhs );
	Boolean operator<( UInt const & lhs, uint32_t const & rhs );
	Boolean operator<=( UInt const & lhs, uint32_t const & rhs );
	Boolean operator>( UInt const & lhs, uint32_t const & rhs );
	Boolean operator>=( UInt const & lhs, uint32_t const & rhs );
	Optional< Boolean > operator==( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< Boolean > operator!=( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< Boolean > operator<( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< Boolean > operator<=( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< Boolean > operator>( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< Boolean > operator>=( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< Boolean > operator==( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator!=( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator<( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator<=( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator>( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< Boolean > operator>=( uint32_t const & lhs, Optional< UInt > const & rhs );
}

inline sdw::UInt operator "" _u( unsigned long long value )
{
	return sdw::UInt{ nullptr, sdw::makeExpr( uint32_t( value ) ) };
}

#include "UInt.inl"

#endif
