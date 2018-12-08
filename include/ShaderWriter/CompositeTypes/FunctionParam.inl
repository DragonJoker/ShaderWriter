/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< typename ValueT >
	Param< ValueT >::Param( ShaderWriter & writer
		, std::string name )
		: ValueT{ &sdw::getShader( writer ), makeExpr( var::makeVariable( ValueT::makeType( writer.getTypesCache() ), std::move( name ), var::Flag::eParam ) ) }
	{
	}

	template< typename ValueT >
	Param< ValueT >::Param( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	Param< ValueT > Param< ValueT >::operator=( T const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
	
	//*****************************************************************************************

	template< typename ValueT >
	InParam< ValueT >::InParam( ShaderWriter & writer
		, std::string name )
		: ValueT{ &sdw::getShader( writer ), makeExpr( var::makeVariable( ValueT::makeType( writer.getTypesCache() ), std::move( name ), var::Flag::eInputParam ) ) }
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
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename ValueT >
	OutParam< ValueT >::OutParam( ShaderWriter & writer
		, std::string name )
		: ValueT{ &sdw::getShader( writer ), makeExpr( var::makeVariable( ValueT::makeType( writer.getTypesCache() ), std::move( name ), var::Flag::eOutputParam ) ) }
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
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename ValueT >
	InOutParam< ValueT >::InOutParam( ShaderWriter & writer
		, std::string name )
		: ValueT{ &sdw::getShader( writer ), makeExpr( var::makeVariable( ValueT::makeType( writer.getTypesCache() ), std::move( name ), var::Flag::eInputParam | var::Flag::eOutputParam ) ) }
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
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
	
	//*****************************************************************************************

	template< typename ValueT >
	Param< Array< ValueT > >::Param( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize )
		: ValueT{ &sdw::getShader( writer ), makeExpr( var::makeVariable( Array< ValueT >::makeType( writer.getTypesCache(), arraySize ), std::move( name ), var::Flag::eParam ) ) }
	{
	}

	template< typename ValueT >
	Param< Array< ValueT > >::Param( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	Param< Array< ValueT > > Param< Array< ValueT > >::operator=( T const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
	
	//*****************************************************************************************

	template< typename ValueT >
	InParam< Array< ValueT > >::InParam( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize )
		: Array< ValueT >{ &sdw::getShader( writer ), makeExpr( var::makeVariable( Array< ValueT >::makeType( writer.getTypesCache(), arraySize ), std::move( name ), var::Flag::eInputParam ) ) }
	{
	}

	template< typename ValueT >
	InParam< Array< ValueT > >::InParam( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	InParam< Array< ValueT > > InParam< Array< ValueT > >::operator=( T const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename ValueT >
	OutParam< Array< ValueT > >::OutParam( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize )
		: Array< ValueT >{ &sdw::getShader( writer ), makeExpr( var::makeVariable( Array< ValueT >::makeType( writer.getTypesCache(), arraySize ), std::move( name ), var::Flag::eOutputParam ) ) }
	{
	}

	template< typename ValueT >
	OutParam< Array< ValueT > >::OutParam( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	OutParam< Array< ValueT > > OutParam< Array< ValueT > >::operator=( T const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< typename ValueT >
	InOutParam< Array< ValueT > >::InOutParam( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize )
		: Array< ValueT >{ &sdw::getShader( writer ), makeExpr( var::makeVariable( Array< ValueT >::makeType( writer.getTypesCache(), arraySize ), std::move( name ), var::Flag::eInputParam | var::Flag::eOutputParam ) ) }
	{
	}

	template< typename ValueT >
	InOutParam< Array< ValueT > >::InOutParam( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	template< typename T >
	InOutParam< Array< ValueT > > InOutParam< Array< ValueT > >::operator=( T const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( this->getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************
}
