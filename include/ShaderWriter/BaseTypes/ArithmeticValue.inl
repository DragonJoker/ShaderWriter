/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template<>
	struct ArithmeticValueTraits< ast::type::Kind::eInt >
	{
		using CppType = int32_t;
	};

	template<>
	struct ArithmeticValueTraits< ast::type::Kind::eUInt >
	{
		using CppType = uint32_t;
	};

	template<>
	struct ArithmeticValueTraits< ast::type::Kind::eHalf >
	{
		using CppType = float;
	};

	template<>
	struct ArithmeticValueTraits< ast::type::Kind::eFloat >
	{
		using CppType = float;
	};

	template<>
	struct ArithmeticValueTraits< ast::type::Kind::eDouble >
	{
		using CppType = double;
	};

	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
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
	ArithmeticValue< KindT >::ArithmeticValue( CppTypeT< KindT > rhs )
		: Value{ nullptr, makeExpr( sdw::getShader( sdw::getCurrentWriter() ), rhs ) }
	{
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( Value const & rhs )
		: Value{ rhs }
	{
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( ArithmeticValue< KindT > const & rhs )
	{
		if ( this->getContainer() )
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
	template< typename T >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	expr::ExprPtr ArithmeticValue< KindT >::makeCondition()const
	{
		auto & shader = *findShader( *this );
		return sdw::makeNEqual( makeExpr( shader, *this )
			, makeExpr( shader, CppTypeT< KindT >{} ) );
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
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator+=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator-=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator*=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator/=( CppTypeT< KindT > const & rhs )
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
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator-()
	{
		writeUnOperator< ArithmeticValue< KindT > >( *this, sdw::makeUnMinus );
		return *this;
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
	Bool operator==( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator!=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator<( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Bool operator<=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator>( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Bool operator>=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Bool operator==( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator!=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator<( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Bool operator<=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator>( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Bool operator>=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Bool operator==( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator!=( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator<( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Bool operator<=( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Bool operator>( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Bool operator>=( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
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
	Optional< Bool > operator==( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator!=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
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
	Optional< Bool > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
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
	Optional< Bool > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator==( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator!=( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<=( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>=( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< ArithmeticValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Optional< Bool > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
