/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLShiftAssign_H___
#define ___AST_ExprLShiftAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class LShiftAssign
		: public Assign
	{
	public:
		SDAST_API LShiftAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using LShiftAssignPtr = std::unique_ptr< LShiftAssign >;

	inline LShiftAssignPtr makeLShiftAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< LShiftAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
