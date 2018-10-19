/*
See LICENSE file in root folder
*/
#ifndef ___ShaderWriter_Void_H___
#define ___ShaderWriter_Void_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	struct Void
		: public Value
	{
		Void( Shader * shader
			, expr::ExprPtr expr );
		Void( Void && rhs );
		Void( Void const & rhs );
		Void( Value const & rhs );
	};

}

#endif
