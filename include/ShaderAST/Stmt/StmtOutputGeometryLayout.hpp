/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtOutputGeometryLayout_H___
#define ___AST_StmtOutputGeometryLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class OutputGeometryLayout
		: public Stmt
	{
	public:
		SDAST_API OutputGeometryLayout( StmtCache & stmtCache
			, type::TypePtr type
			, type::OutputLayout layout
			, uint32_t primCount );

		SDAST_API void accept( VisitorPtr vis )const override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		type::OutputLayout getLayout()const
		{
			return m_layout;
		}

		uint32_t getPrimCount()const
		{
			return m_primCount;
		}

	private:
		type::TypePtr m_type;
		type::OutputLayout m_layout;
		uint32_t m_primCount;
	};
}

#endif
