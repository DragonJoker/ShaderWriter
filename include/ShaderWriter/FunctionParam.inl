/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< typename TypeT >
	InParam< TypeT >::InParam( stmt::Container * container
		, expr::ExprPtr expr )
		: TypeT{ container, std::move( expr ) }
	{
	}

	template< typename TypeT >
	InParam< TypeT >::InParam( TypeT const & other )
		: TypeT{ other.m_container, makeExpr( other ) }
	{
	}

	template< typename TypeT >
	template< typename T >
	InParam< TypeT > InParam< TypeT >::operator=( T const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	OutParam< TypeT >::OutParam( stmt::Container * container
		, expr::ExprPtr expr )
		: TypeT{ container, std::move( expr ) }
	{
	}

	template< typename TypeT >
	OutParam< TypeT >::OutParam( TypeT const & other )
		: TypeT{ other.m_container, makeExpr( other ) }
	{
	}

	template< typename TypeT >
	template< typename T >
	OutParam< TypeT > OutParam< TypeT >::operator=( T const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	InOutParam< TypeT >::InOutParam( stmt::Container * container
		, expr::ExprPtr expr )
		: TypeT{ container, std::move( expr ) }
	{
	}

	template< typename TypeT >
	InOutParam< TypeT >::InOutParam( TypeT const & other )
		: TypeT{ other.m_container, makeExpr( other ) }
	{
	}

	template< typename TypeT >
	template< typename T >
	InOutParam< TypeT > InOutParam< TypeT >::operator=( T const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( InParam< TypeT > const & value )
	{
		return stmt::makeVariableDecl( makeVar( value )
			, stmt::VariableDecl::Flag::eIn );
	}

	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( OutParam< TypeT > const & value )
	{
		return stmt::makeVariableDecl( makeVar( value )
			, stmt::VariableDecl::Flag::eOut );
	}

	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( InOutParam< TypeT > const & value )
	{
		return stmt::makeVariableDecl( makeVar( value )
			, stmt::VariableDecl::Flag::eIn | stmt::VariableDecl::Flag::eOut );
	}

	//*****************************************************************************************
}
