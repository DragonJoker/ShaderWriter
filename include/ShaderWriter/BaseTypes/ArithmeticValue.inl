/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
		assert( this->getType()->getKind() == KindT );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( ArithmeticValue< KindT > && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( ArithmeticValue< KindT > const & rhs )
		: Value{ rhs }
	{
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( CppTypeT< ArithmeticValue< KindT > > rhs )
		: Value{ &sdw::getShader( sdw::getCurrentWriter() ), makeExpr( sdw::getShader( sdw::getCurrentWriter() ), rhs ) }
	{
		assert( this->getType()->getKind() == KindT );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( Value rhs )
		: Value{ ctorCast< ArithmeticValue< KindT >, 1u >( std::move( rhs ) ) }
	{
		assert( this->getType()->getKind() == KindT );
	}

	template< ast::type::Kind KindT >
	inline ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( ArithmeticValue< KindT > const & rhs )
	{
		if ( getContainer() )
		{
			writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< ast::type::Kind KindT >
	inline ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( Optional< ArithmeticValue< KindT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( getContainer() )
			{
				writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< ast::type::Kind KindT >
	inline ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( MaybeOptional< ArithmeticValue< KindT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( getContainer() )
			{
				writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< ast::type::Kind KindT >
	template< typename T >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( T const & rhs )
	{
		static_assert( KindT == typeEnum< T > );
		this->updateContainer( rhs );
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	expr::ExprPtr ArithmeticValue< KindT >::makeCondition()const
	{
		auto & shader = *findShader( *this );
		return sdw::makeNEqual( makeExpr( shader, *this )
			, makeExpr( shader, CppTypeT< ArithmeticValue< KindT > >{} ) );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator+=( ArithmeticValue< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator-=( ArithmeticValue< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator*=( ArithmeticValue< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator/=( ArithmeticValue< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator+=( CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator-=( CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator*=( CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator/=( CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator+=( Optional< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator-=( Optional< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator*=( Optional< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator/=( Optional< ArithmeticValue< KindT > > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > ArithmeticValue< KindT >::operator-()const
	{
		return writeUnOperator< ArithmeticValue< KindT > >( *this, sdw::makeUnMinus );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > ArithmeticValue< KindT >::operator+()const
	{
		return writeUnOperator< ArithmeticValue< KindT > >( *this, sdw::makeUnPlus );
	}

	template< ast::type::Kind KindT >
	ast::type::TypePtr ArithmeticValue< KindT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBasicType( KindT );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Boolean operator==( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator!=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator<( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Boolean operator<=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator>( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Boolean operator>=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Boolean operator==( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator!=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator<( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Boolean operator<=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator>( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Boolean operator>=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Boolean operator==( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator!=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator<( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Boolean operator<=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator>( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Boolean operator>=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
