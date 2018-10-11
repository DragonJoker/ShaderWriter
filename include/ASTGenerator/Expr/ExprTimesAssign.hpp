/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprTimesAssign_H___
#define ___AST_ExprTimesAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class TimesAssign
		: public Assign
	{
	public:
		TimesAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using TimesAssignPtr = std::unique_ptr< TimesAssign >;

	inline TimesAssignPtr makeTimesAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< TimesAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
