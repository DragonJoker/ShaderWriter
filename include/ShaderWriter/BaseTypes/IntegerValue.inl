/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< ast::type::Kind KindT >
	IntegerValue< KindT >::IntegerValue( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT >::IntegerValue( CppTypeT< IntegerValue< KindT > > rhs )
		: Value{ sdw::getCurrentWriter(), makeExpr( sdw::getCurrentWriter(), rhs ), true }
	{
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT >::IntegerValue( Value rhs )
		: Value{ ctorCast< IntegerValue< KindT >, 1u >( std::move( rhs ) ) }
	{
	}

	template< ast::type::Kind KindT >
	template< typename T >
	IntegerValue< KindT > & IntegerValue< KindT >::operator=( T const & rhs )
	{
		static_assert( KindT == typeEnum< T > );
		this->updateContainer( rhs );
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	expr::ExprPtr IntegerValue< KindT >::makeCondition()const
	{
		auto & shader = findWriterMandat( *this );
		return sdw::makeNEqual( makeExpr( shader, *this )
			, makeExpr( shader, CppTypeT< IntegerValue< KindT > >{} ) );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator++()
	{
		return writeUnOperator< ReturnWrapperT< IntegerValue< KindT > > >( *this, sdw::makePreInc );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator++( int )
	{
		return writeUnOperator< ReturnWrapperT< IntegerValue< KindT > > >( *this, sdw::makePostInc );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator--()
	{
		return writeUnOperator< ReturnWrapperT< IntegerValue< KindT > > >( *this, sdw::makePreDec );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator--( int )
	{
		return writeUnOperator< ReturnWrapperT< IntegerValue< KindT > > >( *this, sdw::makePostDec );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator+=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator-=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator*=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator/=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator%=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeModuloAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator<<=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeLShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator>>=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeRShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator&=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAndAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator|=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeOrAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator^=( IntegerValue< KindT > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeXorAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator+=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator-=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator*=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator/=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator%=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeModuloAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator<<=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeLShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator>>=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeRShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator&=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAndAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator|=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeOrAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator^=( CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeXorAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > IntegerValue< KindT >::operator-()const
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makeUnMinus );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > IntegerValue< KindT >::operator+()const
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makeUnPlus );
	}

	template< ast::type::Kind KindT >
	ast::type::TypePtr IntegerValue< KindT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBasicType( KindT );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator+( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator-( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator*( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator/( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator~( IntegerValue< KindT > const & expr )
	{
		return writeUnOperator< IntegerValue< KindT > >( expr, sdw::makeBitNot );
	}

	template< ast::type::Kind KindT >
	Boolean operator==( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator!=( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator<( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Boolean operator<=( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator>( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Boolean operator>=( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator+( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator-( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator*( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator/( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator%( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator<<( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator>>( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator&( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator|( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator^( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	template< ast::type::Kind KindT >
	Boolean operator==( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator!=( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator<( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Boolean operator<=( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator>( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Boolean operator>=( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator+( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeAdd );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator-( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeMinus );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator*( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeTimes );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator/( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeDivide );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeModulo );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeLShift );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeRShift );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitOr );
	}

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeBinOperator< IntegerValue< KindT > >( lhs, rhs, sdw::makeBitXor );
	}

	template< ast::type::Kind KindT >
	Boolean operator==( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator!=( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator<( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ast::type::Kind KindT >
	Boolean operator<=( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ast::type::Kind KindT >
	Boolean operator>( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ast::type::Kind KindT >
	Boolean operator>=( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
