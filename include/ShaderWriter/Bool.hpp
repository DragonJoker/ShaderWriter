/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Boolean_H___
#define ___Writer_Boolean_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	struct Boolean
		: public Value
	{
		Boolean( Shader * shader
			, expr::ExprPtr expr );
		Boolean( Boolean && rhs );
		Boolean( Boolean const & rhs );
		Boolean( Value const & rhs );
		Boolean & operator=( Boolean const & rhs );
		template< typename T >
		inline Boolean & operator=( T const & rhs );
		Boolean & operator=( bool rhs );
		operator bool();
	};

	Boolean operator==( Value const & lhs, Value const & rhs );
	Boolean operator!=( Value const & lhs, Value const & rhs );
	Boolean operator||( Boolean const & lhs, Boolean const & rhs );
	Boolean operator&&( Boolean const & lhs, Boolean const & rhs );
}

#include "Bool.inl"

#endif
