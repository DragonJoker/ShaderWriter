/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Value_H___
#define ___SDW_Value_H___

#include "ShaderWriterPrerequisites.hpp"

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

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Shader * findShader( ValuesT const & ... values );
	template< typename ... ValuesT >
	inline ast::type::TypesCache & findTypesCache( ValuesT const & ... values );

	expr::ExprPtr makeExpr( Shader const & shader
		, Value const & variable
		, bool force = true );
	expr::ExprList makeFnArg( Shader const & shader
		, Value const & variable );

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline ReturnT writeUnOperator( OperandT const & operand
		, CreatorT creator );

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	inline ReturnT writeBinOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator );
}

#include "Value.inl"

#endif
