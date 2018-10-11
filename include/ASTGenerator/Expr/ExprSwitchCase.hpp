/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSwitchCase_H___
#define ___AST_ExprSwitchCase_H___
#pragma once

#include "ExprLiteral.hpp"

namespace ast::expr
{
	class SwitchCase
		: public Expr
	{
	public:
		SwitchCase( LiteralPtr label );

		void accept( VisitorPtr vis )override;

		inline Literal * getLabel()const
		{
			return m_label.get();
		}

	private:
		LiteralPtr m_label;
	};
	using SwitchCasePtr = std::unique_ptr< SwitchCase >;
	using SwitchCaseList = std::vector< SwitchCasePtr >;

	inline SwitchCasePtr makeSwitchCase( LiteralPtr label )
	{
		return std::make_unique< SwitchCase >( std::move( label ) );
	}
}

#endif
