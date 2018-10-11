/*
See LICENSE file in root folder
*/
#ifndef ___Writer_VOID_H___
#define ___Writer_VOID_H___

#include "Value.hpp"

namespace sdw
{
	struct Void
		: public Type
	{
		inline Void();
		inline Void( Shader * shader );
	};
}

#include "Void.inl"

#endif
