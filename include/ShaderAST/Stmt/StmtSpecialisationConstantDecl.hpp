/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSpecialisationConstantDecl_H___
#define ___AST_StmtSpecialisationConstantDecl_H___
#pragma once

#include "Stmt.hpp"
#include "ShaderAST/Expr/ExprLiteral.hpp"

namespace ast::stmt
{
	class SpecialisationConstantDecl
		: public Stmt
	{
	public:
		SDAST_API SpecialisationConstantDecl( StmtCache & stmtCache
			, var::VariablePtr variable
			, uint32_t location
			, expr::LiteralPtr value );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		inline uint32_t getLocation()const
		{
			return m_location;
		}

		inline expr::Literal * getValue()const
		{
			return m_value.get();
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_location;
		expr::LiteralPtr m_value{};
	};
}

#endif
