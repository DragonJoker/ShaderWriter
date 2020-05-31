/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Vec2T< ValueT >::Vec2T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Vec2T< ValueT >::Vec2T( Vec2T const & rhs )
		: Value{ rhs.getShader(), makeExpr( *findShader( *this, rhs ), rhs ) }
	{
	}

	template< typename ValueT >
	inline Vec2T< ValueT > & Vec2T< ValueT >::operator=( Vec2T< ValueT > const & rhs )
	{
		if ( getContainer() )
		{
			writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline Vec2T< ValueT > & Vec2T< ValueT >::operator=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	inline Vec2T< ValueT > & Vec2T< ValueT >::operator=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	inline ValueT Vec2T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ValueT Vec2T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ValueT Vec2T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator/=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator/=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator/=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}
	
	template< typename ValueT >
	Vec2T< ValueT > Vec2T< ValueT >::operator-()const
	{
		return writeUnOperator< Vec2T< ValueT > >( *this, sdw::makeUnMinus );
	}

	template< typename ValueT >
	Vec2T< ValueT > Vec2T< ValueT >::operator+()const
	{
		return writeUnOperator< Vec2T< ValueT > >( *this, sdw::makeUnPlus );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Vec2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Vec2T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	Vec2T< Boolean > operator==( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Vec2T< Boolean > operator!=( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Vec2T< Boolean > operator<( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Vec2T< Boolean > operator<=( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Vec2T< Boolean > operator>( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Vec2T< Boolean > operator>=( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator==( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator!=( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator<( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator<=( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator>( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator>=( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator==( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator!=( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator<( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator<=( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator>( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator>=( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator==( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator!=( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator<( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator<=( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator>( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Optional< Vec2T< Boolean > > operator>=( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	//*************************************************************************
}
