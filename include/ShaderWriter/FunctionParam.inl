/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< typename ValueT >
	InParam< ValueT >::InParam( ShaderWriter & writer
		, std::string name )
		: ValueT{ &writer.getShader(), makeExpr( writer.registerInParam( std::move( name ), type::makeType( typeEnum< ValueT > ) ) ) }
	{
	}

	template< typename ValueT >
	InParam< ValueT >::InParam( ValueT const & other )
		: ValueT{ other.getShader(), makeExpr( other ) }
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
		: ValueT{ &writer.getShader(), makeExpr( writer.registerOutParam( std::move( name ), type::makeType( typeEnum< ValueT > ) ) ) }
	{
	}

	template< typename ValueT >
	OutParam< ValueT >::OutParam( ValueT const & other )
		: ValueT{ other.getShader(), makeExpr( other ) }
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
		: ValueT{ &writer.getShader(), makeExpr( writer.registerInOutParam( std::move( name ), type::makeType( typeEnum< ValueT > ) ) ) }
	{
	}

	template< typename ValueT >
	InOutParam< ValueT >::InOutParam( ValueT const & other )
		: ValueT{ other.getShader(), makeExpr( other ) }
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
