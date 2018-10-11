/*
See LICENSE file in root folder
*/
#ifndef ___Writer_TYPE_H___
#define ___Writer_TYPE_H___

#include "ShaderWriterPrerequisites.hpp"

#include <ASTGenerator/Expr/ExprAdd.hpp>
#include <ASTGenerator/Expr/ExprDivide.hpp>
#include <ASTGenerator/Expr/ExprMinus.hpp>
#include <ASTGenerator/Expr/ExprTimes.hpp>

namespace sdw
{
	template< typename T > struct is_type : public std::false_type {};

	struct Value
	{
		Value( stmt::Container * container
			, expr::ExprPtr expr );
		Value( Value && rhs );
		Value( Value const & rhs );
		virtual ~Value();
		Value & operator=( Value const & rhs );
		void updateContainer( Value const & variable );

		stmt::Container * m_container;
		expr::ExprPtr m_expr;
	};

	template< typename T >
	T const & operator-( T const & value );
	template< typename T >
	T const & operator+( T const & value );

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values );

	expr::ExprPtr makeExpr( Value const & variable );
	var::VariablePtr makeVar( Value const & variable );
}

#include "Value.inl"

#endif
