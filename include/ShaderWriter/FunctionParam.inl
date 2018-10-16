/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< typename TypeT >
	InParam< TypeT >::InParam( Shader * shader
		, std::string name )
		: TypeT{ shader, expr::makeIdentifier( var::makeVariable( type::makeType( TypeTraits< TypeT >::TypeEnum ), std::move( name ) ) ) }
	{
	}

	template< typename TypeT >
	InParam< TypeT >::InParam( TypeT const & other )
		: TypeT{ other.getShader(), makeExpr( other ) }
	{
	}

	template< typename TypeT >
	template< typename T >
	InParam< TypeT > InParam< TypeT >::operator=( T const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	OutParam< TypeT >::OutParam( Shader * shader
		, std::string name )
		: TypeT{ shader, expr::makeIdentifier( var::makeVariable( type::makeType( TypeTraits< TypeT >::TypeEnum ), std::move( name ) ) ) }
	{
	}

	template< typename TypeT >
	OutParam< TypeT >::OutParam( TypeT const & other )
		: TypeT{ other.getShader(), makeExpr( other ) }
	{
	}

	template< typename TypeT >
	template< typename T >
	OutParam< TypeT > OutParam< TypeT >::operator=( T const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	InOutParam< TypeT >::InOutParam( Shader * shader
		, std::string name )
		: TypeT{ shader, expr::makeIdentifier( var::makeVariable( type::makeType( TypeTraits< TypeT >::TypeEnum ), std::move( name ) ) ) }
	{
	}

	template< typename TypeT >
	InOutParam< TypeT >::InOutParam( TypeT const & other )
		: TypeT{ other.getShader(), makeExpr( other ) }
	{
	}

	template< typename TypeT >
	template< typename T >
	InOutParam< TypeT > InOutParam< TypeT >::operator=( T const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( InParam< TypeT > const & value )
	{
		return stmt::makeVariableDecl( makeVar( value
			, var::Flag::eInputParam ) );
	}

	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( OutParam< TypeT > const & value )
	{
		return stmt::makeVariableDecl( makeVar( value
			, var::Flag::eOutputParam ) );
	}

	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( InOutParam< TypeT > const & value )
	{
		return stmt::makeVariableDecl( makeVar( value
			, var::Flag::eInputParam | var::Flag::eOutputParam ) );
	}

	//*****************************************************************************************
}
