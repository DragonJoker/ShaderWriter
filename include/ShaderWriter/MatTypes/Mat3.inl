/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat3T< ValueT >::Mat3T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat3T< ValueT >::Mat3T( Mat3T const & rhs )
		: Value{ rhs.getShader(), makeExpr( rhs ) }
	{
	}

	template< typename ValueT >
	Mat3T< ValueT > & Mat3T< ValueT >::operator=( Mat3T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( makeType( this->getType()->getKind() )
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat3T< ValueT > & Mat3T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( makeType( this->getType()->getKind() )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec3T< ValueT > Mat3T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec3T< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Mat3T< ValueT > & Mat3T< ValueT >::operator+=( Mat3T< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( makeType( this->getType()->getKind() )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return Mat3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( ValueT const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		return Mat3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Mat3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}
}
