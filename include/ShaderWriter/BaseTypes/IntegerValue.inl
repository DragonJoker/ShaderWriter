/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT >::IntegerValue( Shader * shader
		, expr::ExprPtr expr )
		: ArithmeticValue{ shader, std::move( expr ) }
	{
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT >::IntegerValue( IntegerValue< KindT > && rhs )
		: ArithmeticValue{ std::move( rhs ) }
	{
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT >::IntegerValue( IntegerValue< KindT > const & rhs )
		: ArithmeticValue{ rhs }
	{
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT >::IntegerValue( CppTypeT< KindT > rhs )
		: ArithmeticValue{ rhs }
	{
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT >::IntegerValue( Value const & rhs )
		: ArithmeticValue{ rhs }
	{
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator=( IntegerValue< KindT > const & rhs )
	{
		if ( this->getContainer() )
		{
			writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< ast::type::Kind KindT >
	template< typename T >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator++()
	{
		this->updateExpr( sdw::makePreInc( makeExpr( *getShader(), *this ) ) );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > IntegerValue< KindT >::operator++( int )
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makePostInc );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator--()
	{
		this->updateExpr( sdw::makePreDec( makeExpr( *getShader(), *this ) ) );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > IntegerValue< KindT >::operator--( int )
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makePostDec );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator+=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator-=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator*=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator/=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator%=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeModuloAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator<<=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeLShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator>>=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeRShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator&=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAndAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator|=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeOrAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator^=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeXorAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator+=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator-=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator*=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator/=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator%=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeModuloAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator<<=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeLShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator>>=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeRShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator&=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAndAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator|=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeOrAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator^=( Optional< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeXorAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator+=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator-=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator*=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator/=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator%=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeModuloAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator<<=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeLShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator>>=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeRShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator&=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAndAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator|=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeOrAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > & IntegerValue< KindT >::operator^=( CppTypeT< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeXorAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	inline ast::type::TypePtr IntegerValue< KindT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBasicType( KindT );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator~( IntegerValue< KindT > const & expr )
	{
		return writeUnOperator< IntegerValue< KindT > >( expr, sdw::makeBitNot );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator~( Optional< IntegerValue< KindT > > const & expr )
	{
		return writeUnOperator< IntegerValue< KindT > >( expr, sdw::makeBitNot );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator%( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator<<( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator>>( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator&( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator|( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator^( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	//*************************************************************************
}
