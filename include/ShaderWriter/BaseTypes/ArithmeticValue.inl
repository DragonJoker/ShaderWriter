/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
		assert( this->getType()->getKind() == KindT );
	}

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT >::ArithmeticValue( CppTypeT< ArithmeticValue< KindT > > rhs )
		: Value{ sdw::getCurrentWriter(), makeExpr( sdw::getCurrentWriter(), rhs ), true }
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
	template< ArithmeticT RhsT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator=( RhsT const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	expr::ExprPtr ArithmeticValue< KindT >::makeCondition()const
	{
		auto & writer = findWriterMandat( *this );
		return sdw::makeNEqual( makeExpr( writer, *this )
			, makeExpr( writer, CppTypeT< ArithmeticValue< KindT > >{} ) );
	}

	template< ast::type::Kind KindT >
	template< ArithmeticT RhsT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator+=( RhsT const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< ArithmeticT RhsT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator-=( RhsT const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< ArithmeticT RhsT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator*=( RhsT const & rhs )
	{
		writeAssignOperator< ArithmeticValue< KindT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< ast::type::Kind KindT >
	template< ArithmeticT RhsT >
	ArithmeticValue< KindT > & ArithmeticValue< KindT >::operator/=( RhsT const & rhs )
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
	Vec2T< ArithmeticValue< KindT > > ArithmeticValue< KindT >::xx()const
	{
		return Vec2T< ArithmeticValue< KindT > >{ *getWriter()
			, sdw::makeExpr( this )
			, isEnabled() };
	}

	template< ast::type::Kind KindT >
	Vec3T< ArithmeticValue< KindT > > ArithmeticValue< KindT >::xxx()const
	{
		return Vec3T< ArithmeticValue< KindT > >{ *getWriter()
			, sdw::makeExpr( this )
			, isEnabled() };
	}

	template< ast::type::Kind KindT >
	Vec4T< ArithmeticValue< KindT > > ArithmeticValue< KindT >::xxxx()const
	{
		return Vec4T< ArithmeticValue< KindT > >{ *getWriter()
			, sdw::makeExpr( this )
			, isEnabled() };
	}

	template< ast::type::Kind KindT >
	ast::type::TypePtr ArithmeticValue< KindT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBasicType( KindT );
	}

	//*************************************************************************

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator+( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeAdd );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator-( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeMinus );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator*( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeTimes );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator/( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeBinOperator< ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > >( lhs, rhs, sdw::makeDivide );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator==( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator!=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator<( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLess );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator<=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLEqual );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator>( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGreater );
	}

	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator>=( LhsT const & lhs
		, RhsT const & rhs )
	{
		static_assert( typeEnumV< LhsT > == typeEnumV< RhsT > );
		return writeComparator< Boolean >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
