/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat2x4.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Mat2x4T< ValueT > & Mat2x4T< ValueT >::operator=( MaybeOptional< Mat2x4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat2x4T< ValueT > >( *this, rhs, sdw::makeAssign );
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
