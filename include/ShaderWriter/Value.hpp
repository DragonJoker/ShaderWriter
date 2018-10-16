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
#include <ASTGenerator/Expr/ExprUnaryMinus.hpp>

namespace sdw
{
	template< typename T > struct is_type : public std::false_type {};

	struct Value
	{
		Value( Shader * shader
			, expr::ExprPtr expr );
		Value( Value && rhs );
		Value( Value const & rhs );
		virtual ~Value();
		Value & operator=( Value const & rhs );
		void updateContainer( Value const & variable );
		stmt::Container * getContainer()const;
		void updateExpr( expr::ExprPtr expr );

		inline type::TypePtr getType()const
		{
			return m_expr->getType();
		}

		inline expr::Expr * getExpr()const
		{
			return m_expr.get();
		}

		inline Shader * getShader()const
		{
			return m_shader;
		}

	private:
		expr::ExprPtr m_expr;
		Shader * m_shader;
		stmt::Container * m_container;
	};

	template< typename T >
	T operator-( T const & value );
	template< typename T >
	T operator+( T const & value );

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Shader * findShader( ValuesT const & ... values );

	expr::ExprPtr makeExpr( Value const & variable );
	var::VariablePtr makeVar( Value const & variable
		, var::Flag flag );
	var::VariablePtr makeVar( Value const & variable
		, uint32_t flags = 0u );
}

#include "Value.inl"

#endif
