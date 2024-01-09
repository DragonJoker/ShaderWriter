/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInputGeometryLayout_H___
#define ___AST_StmtInputGeometryLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class InputGeometryLayout
		: public Stmt
	{
	public:
		SDAST_API InputGeometryLayout( StmtCache & stmtCache
			, type::TypePtr type
			, type::InputLayout layout );

		SDAST_API void accept( VisitorPtr vis )const override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		type::InputLayout getLayout()const
		{
			return m_layout;
		}

	private:
		type::TypePtr m_type;
		type::InputLayout m_layout;
	};
}

#endif
