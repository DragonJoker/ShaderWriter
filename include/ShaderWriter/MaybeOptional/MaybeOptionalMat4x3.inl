/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat4x3.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Mat4x3T< ValueT > & Mat4x3T< ValueT >::operator=( MaybeOptional< Mat4x3T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat4x3T< ValueT > >( *this, rhs, sdw::makeAssign );
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
