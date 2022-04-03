/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtVariableDecl_H___
#define ___AST_StmtVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class VariableDecl
		: public Stmt
	{
	public:
		SDAST_API explicit VariableDecl( var::VariablePtr variable );

		SDAST_API bool isMember()const;

		SDAST_API void accept( VisitorPtr vis )override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

	private:
		var::VariablePtr m_variable;
	};
	using VariableDeclPtr = std::unique_ptr< VariableDecl >;

	inline std::unique_ptr< VariableDecl > makeVariableDecl( var::VariablePtr variable )
	{
		return std::make_unique< VariableDecl >( std::move( variable ) );
	}
}

#endif
