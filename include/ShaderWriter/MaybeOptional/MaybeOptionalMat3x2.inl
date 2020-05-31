/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat3x2.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Mat3x2T< ValueT > & Mat3x2T< ValueT >::operator=( MaybeOptional< Mat3x2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat3x2T< ValueT > >( *this, rhs, sdw::makeAssign );
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
