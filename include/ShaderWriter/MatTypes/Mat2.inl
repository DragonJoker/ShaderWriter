/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	Mat2T< ValueT >::Mat2T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat2T< ValueT >::Mat2T( Mat2T const & rhs )
		: Value{ rhs.getShader(), makeExpr( *findShader( *this, rhs ), rhs ) }
	{
	}

	template< typename ValueT >
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( Mat2T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			writeAssignOperator< Mat2T< ValueT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline Mat2T< ValueT > & Mat2T< ValueT >::operator=( Optional< Mat2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat2T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	inline Mat2T< ValueT > & Mat2T< ValueT >::operator=( MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat2T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	inline Mat2T< ValueT > & Mat2T< ValueT >::operator+=( Mat2T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat2T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec2T< ValueT > Mat2T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat2T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat2T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat2T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Vec2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat2T< ValueT > operator*( ValueT const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*********************************************************************************************

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
