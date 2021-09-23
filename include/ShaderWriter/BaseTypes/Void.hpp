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
		SDW_API Void( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool writeStmt = true );
		SDW_API explicit Void( Value rhs );

		SDW_API ~Void()override = default;
		SDW_API Void( Void && rhs ) = default;
		SDW_API Void( Void const & rhs ) = default;

		SDW_API static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#endif
