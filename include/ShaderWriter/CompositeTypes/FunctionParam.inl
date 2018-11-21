/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< typename ValueT >
	InParam< ValueT >::InParam( ShaderWriter & writer
		, std::string name )
		: ValueT{ &writer.getShader(), makeExpr( var::makeVariable( makeType< ValueT >(), std::move( name ), var::Flag::eInputParam ) ) }
	{
	}

	template< typename ValueT >
	InParam< ValueT >::InParam( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	InParam< ValueT > InParam< ValueT >::operator=( T const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename ValueT >
	OutParam< ValueT >::OutParam( ShaderWriter & writer
		, std::string name )
		: ValueT{ &writer.getShader(), makeExpr( var::makeVariable( makeType< ValueT >(), std::move( name ), var::Flag::eOutputParam ) ) }
	{
	}

	template< typename ValueT >
	OutParam< ValueT >::OutParam( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	OutParam< ValueT > OutParam< ValueT >::operator=( T const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename ValueT >
	InOutParam< ValueT >::InOutParam( ShaderWriter & writer
		, std::string name )
		: ValueT{ &writer.getShader(), makeExpr( var::makeVariable( makeType< ValueT >(), std::move( name ), var::Flag::eInputParam | var::Flag::eOutputParam ) ) }
	{
	}

	template< typename ValueT >
	InOutParam< ValueT >::InOutParam( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	InOutParam< ValueT > InOutParam< ValueT >::operator=( T const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************
}
