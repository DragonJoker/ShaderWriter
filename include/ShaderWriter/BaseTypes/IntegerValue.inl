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
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator=( RhsT const & rhs )
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
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator+=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator-=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator*=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator/=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator%=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeModuloAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator<<=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeLShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator>>=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeRShiftAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator&=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeAndAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator|=( RhsT const & rhs )
	{
		writeAssignOperator< IntegerValue< KindT > >( *this, rhs, sdw::makeOrAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< IntegerT RhsT >
	IntegerValue< KindT > & IntegerValue< KindT >::operator^=( RhsT const & rhs )
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

	template< ast::type::Kind KindT >
	Vec2T< IntegerValue< KindT > > IntegerValue< KindT >::xx()const
	{
		return Vec2T< IntegerValue< KindT > >{ *getWriter()
			, sdw::makeExpr( *this )
			, isEnabled() };
	}

	template< ast::type::Kind KindT >
	Vec3T< IntegerValue< KindT > > IntegerValue< KindT >::xxx()const
	{
		return Vec3T< IntegerValue< KindT > >{ *getWriter()
			, sdw::makeExpr( *this )
			, isEnabled() };
	}

	template< ast::type::Kind KindT >
	Vec4T< IntegerValue< KindT > > IntegerValue< KindT >::xxxx()const
	{
		return Vec4T< IntegerValue< KindT > >{ *getWriter()
			, sdw::makeExpr( *this )
			, isEnabled() };
	}

	//*************************************************************************

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator~( IntegerValue< KindT > const & expr )
	{
		return writeUnOperator< IntegerValue< KindT > >( expr, sdw::makeBitNot );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator+( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeAdd );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator-( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeMinus );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator*( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeTimes );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator/( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeDivide );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator%( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeModulo );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator<<( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeLShift );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator>>( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeRShift );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator&( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeBitAnd );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator|( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeBitOr );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator^( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< IntegerValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeBitXor );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator==( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator!=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator<( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator<=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator>( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator>=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
