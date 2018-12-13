/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Void_H___
#define ___SDW_Void_H___
#pragma once

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	struct Void
		: public Value
	{
		SDW_API Void( Shader * shader
			, expr::ExprPtr expr );
		SDW_API Void( Void && rhs );
		SDW_API Void( Void const & rhs );
		SDW_API explicit Void( Value const & rhs );

		SDW_API static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

}

#endif
