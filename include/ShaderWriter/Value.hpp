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
		SDW_API Value( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
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

		inline ShaderWriter * getWriter()const
		{
			return m_writer;
		}

		inline Shader * getShader()const
		{
			return m_shader;
		}

		inline bool isEnabled()const
		{
			return m_enabled;
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
			return Value{ *op.m_writer
				, ctorCast< OutputT, CountT >( std::move( op.m_expr ) )
				, op.isEnabled() };
		}

	protected:
		expr::ExprPtr m_expr;
		ShaderWriter * m_writer;
		Shader * m_shader;
		stmt::Container * m_container;
		bool m_enabled;
	};

	inline bool isOptionalEnabled( bool const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( int8_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( int16_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( int32_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( int64_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint8_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint16_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint32_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint64_t const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( float const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( double const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( long double const & value )
	{
		return true;
	}

	inline bool isOptionalEnabled( ShaderWriter const & value )
	{
		return true;
	}

	template< typename ValueT >
	inline bool isOptionalEnabled( ValueT const & value );

	template< typename ... ParamsT >
	inline bool areOptionalEnabled( ParamsT const & ... values );

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values );
	template< typename ... ValuesT >
	inline ShaderWriter * findWriter( ValuesT && ... values );
	template< typename ... ValuesT >
	inline ast::type::TypesCache & findTypesCache( ValuesT const & ... values );

	SDW_API expr::ExprPtr getDummyExpr( ShaderWriter const & writer
		, type::TypePtr type );
	SDW_API expr::ExprPtr makeExpr( Value const & variable
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, Value const & variable
		, bool force = true );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, Value const & variable );

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	void writeAssignOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator );

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
