/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtEmitPrimitive_H___
#define ___AST_StmtEmitPrimitive_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class EmitPrimitive
		: public Stmt
	{
	public:
		EmitPrimitive();

		void accept( VisitorPtr vis )override;
	};
	using EmitPrimitivePtr = std::unique_ptr< EmitPrimitive >;

	inline EmitPrimitivePtr makeEmitPrimitive()
	{
		return std::make_unique< EmitPrimitive >();
	}
}

#endif
