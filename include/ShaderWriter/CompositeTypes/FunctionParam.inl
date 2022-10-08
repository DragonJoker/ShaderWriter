/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	Param< ValueT >::Param( ShaderWriter & writer
		, std::string name
		, ParamsT && ... params )
		: ValueT{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, ValueT::makeType( getTypesCache( writer )
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eParam ) )
			, true }
	{
	}

	template< typename ValueT >
	Param< ValueT >::Param( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	Param< ValueT >::Param( DefaultedT< ValueT > const & other )
		: ValueT{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	Param< ValueT > Param< ValueT >::operator=( T const & rhs )
	{
		writeAssignOperator< Param< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void Param< ValueT >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}

	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	InParam< ValueT >::InParam( ShaderWriter & writer
		, std::string name
		, ParamsT && ... params )
		: ValueT{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, ValueT::makeType( getTypesCache( writer )
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eInputParam ) )
			, true }
	{
	}

	template< typename ValueT >
	InParam< ValueT >::InParam( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	InParam< ValueT >::InParam( DefaultedT< ValueT > const & other )
		: ValueT{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	InParam< ValueT > InParam< ValueT >::operator=( T const & rhs )
	{
		writeAssignOperator< InParam< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void InParam< ValueT >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}

	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	OutParam< ValueT >::OutParam( ShaderWriter & writer
		, std::string name
		, ParamsT && ... params )
		: ValueT{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, ValueT::makeType( getTypesCache( writer )
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eOutputParam ) )
			, true }
	{
	}

	template< typename ValueT >
	OutParam< ValueT >::OutParam( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	OutParam< ValueT >::OutParam( DefaultedT< ValueT > const & other )
		: ValueT{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	OutParam< ValueT > OutParam< ValueT >::operator=( T const & rhs )
	{
		writeAssignOperator< OutParam< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void OutParam< ValueT >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}

	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	InOutParam< ValueT >::InOutParam( ShaderWriter & writer
		, std::string name
		, ParamsT && ... params )
		: ValueT{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, ValueT::makeType( getTypesCache( writer )
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eInputParam | var::Flag::eOutputParam ) )
			, true }
	{
	}

	template< typename ValueT >
	InOutParam< ValueT >::InOutParam( ValueT const & other )
		: ValueT{ other }
	{
	}

	template< typename ValueT >
	InOutParam< ValueT >::InOutParam( DefaultedT< ValueT > const & other )
		: ValueT{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	InOutParam< ValueT > InOutParam< ValueT >::operator=( T const & rhs )
	{
		writeAssignOperator< InOutParam< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void InOutParam< ValueT >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}
	
	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	Param< Array< ValueT > >::Param( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize
		, ParamsT && ... params )
		: Array< ValueT >{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, Array< ValueT >::makeType( getTypesCache( writer )
						, arraySize
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eParam ) )
			, true }
	{
	}

	template< typename ValueT >
	Param< Array< ValueT > >::Param( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	Param< Array< ValueT > >::Param( DefaultedT< Array< ValueT > > const & other )
		: Array< ValueT >{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	Param< Array< ValueT > > Param< Array< ValueT > >::operator=( T const & rhs )
	{
		writeAssignOperator< Param< Array< ValueT > > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void Param< Array< ValueT > >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}
	
	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	InParam< Array< ValueT > >::InParam( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize
		, ParamsT && ... params )
		: Array< ValueT >{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, Array< ValueT >::makeType( getTypesCache( writer )
						, arraySize
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eInputParam ) )
			, true }
	{
	}

	template< typename ValueT >
	InParam< Array< ValueT > >::InParam( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	InParam< Array< ValueT > >::InParam( DefaultedT< Array< ValueT > > const & other )
		: Array< ValueT >{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	InParam< Array< ValueT > > InParam< Array< ValueT > >::operator=( T const & rhs )
	{
		writeAssignOperator< InParam< Array< ValueT > > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void InParam< Array< ValueT > >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}

	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	OutParam< Array< ValueT > >::OutParam( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize
		, ParamsT && ... params )
		: Array< ValueT >{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, Array< ValueT >::makeType( getTypesCache( writer )
						, arraySize
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eOutputParam ) )
			, true }
	{
	}

	template< typename ValueT >
	OutParam< Array< ValueT > >::OutParam( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	OutParam< Array< ValueT > >::OutParam( DefaultedT< Array< ValueT > > const & other )
		: Array< ValueT >{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	OutParam< Array< ValueT > > OutParam< Array< ValueT > >::operator=( T const & rhs )
	{
		writeAssignOperator< OutParam< Array< ValueT > > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void OutParam< Array< ValueT > >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}

	//*****************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	InOutParam< Array< ValueT > >::InOutParam( ShaderWriter & writer
		, std::string name
		, uint32_t arraySize
		, ParamsT && ... params )
		: Array< ValueT >{ writer
			, makeExpr( writer
				, var::makeVariable( getNextVarId( writer )
					, Array< ValueT >::makeType( getTypesCache( writer )
						, arraySize
						, std::forward< ParamsT >( params )... )
					, std::move( name )
					, var::Flag::eInputParam | var::Flag::eOutputParam ) )
			, true }
	{
	}

	template< typename ValueT >
	InOutParam< Array< ValueT > >::InOutParam( Array< ValueT > const & other )
		: Array< ValueT >{ other }
	{
	}

	template< typename ValueT >
	InOutParam< Array< ValueT > >::InOutParam( DefaultedT< Array< ValueT > > const & other )
		: Array< ValueT >{ other.getValue() }
	{
	}

	template< typename ValueT >
	template< typename T >
	InOutParam< Array< ValueT > > InOutParam< Array< ValueT > >::operator=( T const & rhs )
	{
		writeAssignOperator< InOutParam< Array< ValueT > > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	void InOutParam< Array< ValueT > >::setVar( var::VariableList::const_iterator & var )
	{
		this->updateExpr( makeExpr( *this->getWriter(), *var ) );
		++var;
	}

	//*****************************************************************************************
}
