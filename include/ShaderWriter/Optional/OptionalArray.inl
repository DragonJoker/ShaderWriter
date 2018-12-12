/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	Optional< Array< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Array< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Array< ValueT > >::Optional( Optional< Array< ValueT > > const & rhs )
		: Array< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	template< typename IndexT >
	Optional< ValueT > Optional< Array< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	bool Optional< Array< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************
}
