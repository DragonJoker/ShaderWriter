/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Value_H___
#define ___SDW_Value_H___

#include "ShaderWriter/BaseTypes/ReturnWrapper.hpp"
#include "ShaderWriter/BaseTypes/Defaulted.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

namespace sdw
{
	struct Value
	{
		SDW_API Value( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		SDW_API virtual ~Value() = default;
		SDW_API Value( Value && rhs )noexcept;
		SDW_API Value( Value const & rhs );
		SDW_API Value & operator=( Value && rhs )noexcept = default;
		SDW_API Value & operator=( Value const & rhs );

		SDW_API void updateContainer( Value const & variable );
		SDW_API stmt::Container * getContainer()const;
		SDW_API void updateExpr( expr::ExprPtr expr );

		SDW_API ast::ShaderBuilder & getBuilder()const;

		virtual type::TypePtr getType()const
		{
			return m_expr->getType();
		}

		virtual expr::Expr const * getExpr()const
		{
			return m_expr.get();
		}

		inline ShaderWriter * getWriter()const
		{
			return m_writer;
		}

		inline bool isEnabled()const
		{
			return m_enabled;
		}

		template< typename OutputT, size_t CountT >
		static inline expr::ExprPtr ctorCast( expr::ExprPtr op )
		{
			auto result = std::move( op );

			if ( result->getType()->getKind() != typeEnumV< OutputT >
				&& ( typeEnumV< OutputT > != getComponentType( result->getType()->getKind() ) )
				&& ( CountT > getComponentCount( result->getType()->getKind() ) ) )
			{
				auto & cache = result->getTypesCache();
				result = sdw::makeCast( cache.getBasicType( typeEnumV< OutputT > )
					, std::move( result ) );
			}

			return result;
		}

		template< typename OutputT, size_t CountT >
		static inline Value ctorCast( Value op )
		{
			return Value{ *op.m_writer
				, ctorCast< OutputT, CountT >( std::move( op.m_expr ) )
				, op.isEnabled() };
		}

	protected:
		SDW_API void doCopy( Value const & rhs );
		SDW_API void doMove( Value && rhs )noexcept;

	protected:
		expr::ExprPtr m_expr;
		ShaderWriter * m_writer{};
		stmt::Container * m_container{};
		bool m_enabled;
	};

	inline bool isOptionalEnabled( bool const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( int8_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( int16_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( int32_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( int64_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint8_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint16_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint32_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( uint64_t const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( float const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( double const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( long double const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( type::Scope const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( type::MemorySemantics const & )
	{
		return true;
	}

	inline bool isOptionalEnabled( ShaderWriter const & )
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
	inline ShaderWriter & findWriterMandat( ValuesT && ... values );
	template< typename ... ValuesT >
	inline ast::expr::ExprCache & findExprCache( ValuesT const & ... values );
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

#define SDW_DeclValue( expdecl, name )\
	expdecl name( name && rhs )noexcept = default;\
	expdecl name( name const & rhs ) = default;\
	expdecl name & operator=( name && rhs )noexcept\
	{\
		sdw::Value::doMove( std::move( rhs ) );\
		return *this;\
	}\
	expdecl name & operator=( name const & rhs )\
	{\
		sdw::Value::doCopy( rhs );\
		return *this;\
	}\
	expdecl name & operator=( sdw::ReturnWrapperT< name > && rhs )\
	{\
		if ( rhs.isEnabled() && this->isEnabled() && this->m_expr && !this->m_expr->isConstant() )\
		{\
			sdw::ShaderWriter & writer = sdw::findWriterMandat( *this, rhs );\
			sdw::addStmt( writer\
				, sdw::makeSimple( getStmtCache( writer )\
					, sdw::makeAssign( this->getType()\
						, sdw::makeExpr( writer, *this )\
						, std::move( rhs.m_expr ) ) ) );\
		}\
		return *this;\
	}\
	expdecl name & operator=( sdw::ReturnWrapperT< name > const & rhs )\
	{\
		if ( rhs.isEnabled() && this->isEnabled() && this->m_expr && !this->m_expr->isConstant() )\
		{\
			sdw::ShaderWriter & writer = sdw::findWriterMandat( *this, rhs );\
			sdw::addStmt( writer\
				, sdw::makeSimple( getStmtCache( writer )\
					, sdw::makeAssign( this->getType()\
						, sdw::makeExpr( writer, *this )\
						, sdw::makeExpr( writer, rhs ) ) ) );\
		}\
		return *this;\
	}\
	expdecl ~name()override = default

#include "Value.inl"

#endif
