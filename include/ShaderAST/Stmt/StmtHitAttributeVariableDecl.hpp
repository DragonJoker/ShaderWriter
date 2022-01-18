/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtHitAttributeVariableDecl_H___
#define ___AST_StmtHitAttributeVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class HitAttributeVariableDecl
		: public Stmt
	{
	public:
		SDAST_API HitAttributeVariableDecl( var::VariablePtr variable );

		SDAST_API void accept( VisitorPtr vis )override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

	private:
		var::VariablePtr m_variable;
	};
	using HitAttributeVariableDeclPtr = std::unique_ptr< HitAttributeVariableDecl >;

	inline HitAttributeVariableDeclPtr makeHitAttributeVariableDecl( var::VariablePtr variable )
	{
		return std::make_unique< HitAttributeVariableDecl >( std::move( variable ) );
	}
}

#endif