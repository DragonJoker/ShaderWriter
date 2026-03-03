/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Void_H___
#define ___SDW_Void_H___
#pragma once

#include "ShaderWriter/Value.hpp"
#include "ShaderWriter/BaseTypes/ReturnWrapper.hpp"

namespace sdw
{
	struct Void
		: public Value
	{
		SDW_API Void();
		SDW_API Void( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );
		// Intently non explicit
		SDW_API Void( ReturnWrapperT< Void > const & rhs );

		~Void()override = default;
		Void( Void && rhs ) = default;
		Void( Void const & rhs ) = default;

		SDW_API static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	using RetVoid = ReturnWrapperT< Void >;
}

#endif
