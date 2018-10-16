/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< typename TypeT >
	InParam< TypeT >::InParam( Shader * shader
		, std::string name )
		: TypeT{ shader, expr::makeIdentifier( var::makeVariable( type::makeType( typeEnum< TypeT > ), std::move( name ), var::Flag::eInputParam ) ) }
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
			, stmt::makeSimple( expr::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	OutParam< TypeT >::OutParam( Shader * shader
		, std::string name )
		: TypeT{ shader, expr::makeIdentifier( var::makeVariable( type::makeType( typeEnum< TypeT > ), std::move( name ), var::Flag::eOutputParam ) ) }
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
			, stmt::makeSimple( expr::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename TypeT >
	InOutParam< TypeT >::InOutParam( Shader * shader
		, std::string name )
		: TypeT{ shader, expr::makeIdentifier( var::makeVariable( type::makeType( typeEnum< TypeT > ), std::move( name ), uint32_t( var::Flag::eInputParam ) | uint32_t( var::Flag::eOutputParam ) ) ) }
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
			, stmt::makeSimple( expr::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************
}
