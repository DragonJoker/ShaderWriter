/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Vec4T< ValueT >::Vec4T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Vec4T< ValueT >::Vec4T( Vec4T const & rhs )
		: Value{ rhs.getShader(), makeExpr( *findShader( *this, rhs ), rhs ) }
	{
	}

	template< typename ValueT >
	inline Vec4T< ValueT > & Vec4T< ValueT >::operator=( Vec4T< ValueT > const & rhs )
	{
		if ( getContainer() )
		{
			writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	inline ValueT Vec4T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ValueT Vec4T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ValueT Vec4T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator+=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator-=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator*=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator/=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator+=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator-=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator*=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator/=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator+=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator-=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator*=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator/=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > Vec4T< ValueT >::operator-()const
	{
		return writeUnOperator< Vec4T< ValueT > >( *this, sdw::makeUnMinus );
	}

	template< typename ValueT >
	Vec4T< ValueT > Vec4T< ValueT >::operator+()const
	{
		return writeUnOperator< Vec4T< ValueT > >( *this, sdw::makeUnPlus );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Vec4T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Vec4T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	Vec4T< Boolean > operator==( Vec4T< ValueT > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Vec4T< Boolean > operator!=( Vec4T< ValueT > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Vec4T< Boolean > operator<( Vec4T< ValueT > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Vec4T< Boolean > operator<=( Vec4T< ValueT > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Vec4T< Boolean > operator>( Vec4T< ValueT > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Vec4T< Boolean > operator>=( Vec4T< ValueT > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator==( Optional< Vec4T< ValueT > > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator!=( Optional< Vec4T< ValueT > > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator<( Optional< Vec4T< ValueT > > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator<=( Optional< Vec4T< ValueT > > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator>( Optional< Vec4T< ValueT > > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator>=( Optional< Vec4T< ValueT > > const & lhs, Vec4T< ValueT > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator==( Vec4T< ValueT > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator!=( Vec4T< ValueT > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator<( Vec4T< ValueT > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator<=( Vec4T< ValueT > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator>( Vec4T< ValueT > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator>=( Vec4T< ValueT > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator==( Optional< Vec4T< ValueT > > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator!=( Optional< Vec4T< ValueT > > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator<( Optional< Vec4T< ValueT > > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator<=( Optional< Vec4T< ValueT > > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator>( Optional< Vec4T< ValueT > > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Optional< Vec4T< Boolean > > operator>=( Optional< Vec4T< ValueT > > const & lhs, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeComparator< Vec4T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
