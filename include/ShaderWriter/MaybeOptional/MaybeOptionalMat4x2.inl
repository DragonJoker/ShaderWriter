/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat4x2.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Mat4x2T< ValueT > & Mat4x2T< ValueT >::operator=( MaybeOptional< Mat4x2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat4x2T< ValueT > >( *this, rhs, sdw::makeAssign );
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
