/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtTerminateInvocation_H___
#define ___AST_StmtTerminateInvocation_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class TerminateInvocation
		: public Stmt
	{
	public:
		SDAST_API TerminateInvocation();

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using TerminateInvocationPtr = std::unique_ptr< TerminateInvocation >;

	inline TerminateInvocationPtr makeTerminateInvocation()
	{
		return std::make_unique< TerminateInvocation >();
	}
}

#endif
