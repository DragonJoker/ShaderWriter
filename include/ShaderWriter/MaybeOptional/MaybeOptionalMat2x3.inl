/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat2x3.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Mat2x3T< ValueT > & Mat2x3T< ValueT >::operator=( MaybeOptional< Mat2x3T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat2x3T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	//*************************************************************************
}
