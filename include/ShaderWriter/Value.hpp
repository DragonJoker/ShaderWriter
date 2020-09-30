/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Value_H___
#define ___SDW_Value_H___

#include "ShaderWriterPrerequisites.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

namespace sdw
{
	template< typename T > struct is_type : public std::false_type {};

	struct Value
	{
		SDW_API Value( Shader * shader
			, expr::ExprPtr expr );
		SDW_API Value( Value && rhs );
		SDW_API Value( Value const & rhs );
		SDW_API virtual ~Value();
		SDW_API Value & operator=( Value const & rhs );
		SDW_API void updateContainer( Value const & variable );
		SDW_API stmt::Container * getContainer()const;
		SDW_API void updateExpr( expr::ExprPtr expr );

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

		template< typename OutputT, size_t CountT >
		static inline expr::ExprPtr ctorCast( expr::ExprPtr op )
		{
			if ( op->getType()->getKind() == typeEnum< OutputT >
				|| ( typeEnum< OutputT > == getComponentType( op->getType()->getKind() ) )
				|| ( CountT <= getComponentCount( op->getType()->getKind() ) ) )
			{
				return std::move( op );
			}

			auto & cache = op->getCache();
			return sdw::makeCast( cache.getBasicType( typeEnum< OutputT > )
				, std::move( op ) );
		}

		template< typename OutputT, size_t CountT >
		static inline Value ctorCast( Value op )
		{
			return Value{ op.m_shader
				, ctorCast< OutputT, CountT >( std::move( op.m_expr ) ) };
		}

	protected:
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

	SDW_API expr::ExprPtr getDummyExpr( Shader & shader
		, type::TypePtr type );
	SDW_API expr::ExprPtr makeExpr( Value const & variable
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, Value const & variable
		, bool force = true );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
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
