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
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator=( CppTypeT< IntegerValue< KindT > > rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator=( RhsT const & rhs )
	{
		this->updateContainer( rhs );
		return writeAssignOperator< IntegerValue >( *this, rhs, sdw::makeAssign );
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
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makePreInc );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator++( int )
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makePostInc );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator--()
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makePreDec );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator--( int )
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makePostDec );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator+=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAddAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator-=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator*=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator/=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator%=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeModuloAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator<<=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeLShiftAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator>>=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeRShiftAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator&=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAndAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator|=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeOrAssign );
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator^=( RhsT const & rhs )
	{
		return writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeXorAssign );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator-()const
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makeUnMinus );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > IntegerValue< KindT >::operator+()const
	{
		return writeUnOperator< IntegerValue< KindT > >( *this, sdw::makeUnPlus );
	}

	template< ast::type::Kind KindT >
	ast::type::TypePtr IntegerValue< KindT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBasicType( KindT );
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< Vec2T< IntegerValue< KindT > > > IntegerValue< KindT >::xx()const
	{
		return ReturnWrapperT< Vec2T< IntegerValue< KindT > > >{ *getWriter()
			, sdw::makeExpr( *this )
			, isEnabled() };
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< Vec3T< IntegerValue< KindT > > > IntegerValue< KindT >::xxx()const
	{
		return ReturnWrapperT< Vec3T< IntegerValue< KindT > > >{ *getWriter()
			, sdw::makeExpr( *this )
			, isEnabled() };
	}

	template< ast::type::Kind KindT >
	ReturnWrapperT< Vec4T< IntegerValue< KindT > > > IntegerValue< KindT >::xxxx()const
	{
		return ReturnWrapperT< Vec4T< IntegerValue< KindT > > >{ *getWriter()
			, sdw::makeExpr( *this )
			, isEnabled() };
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	ReturnWrapperT< IntegerValue< KindT > > operator~( IntegerValue< KindT > const & expr )
	{
		return writeUnOperator< IntegerValue< KindT > >( expr, sdw::makeBitNot );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator+( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > >( lhs, rhs, sdw::makeAdd );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator-( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeMinus );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator*( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeTimes );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator/( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeDivide );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator%( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeModulo );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator<<( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeLShift );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator>>( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeRShift );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator&( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator|( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeBitOr );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > > operator^( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeBitXor );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< Boolean > operator==( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< Boolean > operator!=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< Boolean > operator<( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< Boolean > operator<=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< Boolean > operator>( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	ReturnWrapperT< Boolean > operator>=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
