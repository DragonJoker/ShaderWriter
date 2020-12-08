/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	Mat4T< ValueT >::Mat4T( ShaderWriter & writer
		, expr::ExprPtr expr )
		: Value{ writer, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat4T< ValueT >::Mat4T( Mat4T const & rhs )
		: Value{ *rhs.getWriter(), makeExpr( *findWriter( *this, rhs ), rhs ) }
	{
	}

	template< typename ValueT >
	Mat4T< ValueT > & Mat4T< ValueT >::operator=( Mat4T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			writeAssignOperator< Mat4T< ValueT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline Mat4T< ValueT > & Mat4T< ValueT >::operator=( Optional< Mat4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat4T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	inline Mat4T< ValueT > & Mat4T< ValueT >::operator=( MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat4T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	inline Mat4T< ValueT > & Mat4T< ValueT >::operator+=( Mat4T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat4T< ValueT > & Mat4T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat4T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec4T< ValueT > Mat4T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat4T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat4T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat4T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat4T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat4T< ValueT > operator*( ValueT const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*********************************************************************************************

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
