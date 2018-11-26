/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLShift_H___
#define ___AST_ExprLShift_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LShift
		: public Binary
	{
	public:
		LShift( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using LShiftPtr = std::unique_ptr< LShift >;

	inline LShiftPtr makeLShift( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< LShift >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
