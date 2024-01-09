/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtDispatchMesh_H___
#define ___AST_StmtDispatchMesh_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class DispatchMesh
		: public Stmt
	{
	public:
		SDAST_API DispatchMesh( StmtCache & stmtCache
			, expr::ExprPtr numGroupsX
			, expr::ExprPtr numGroupsY
			, expr::ExprPtr numGroupsZ
			, expr::ExprPtr payload );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline expr::Expr const * getNumGroupsX()const
		{
			return m_numGroupsX.get();
		}

		inline expr::Expr const * getNumGroupsY()const
		{
			return m_numGroupsY.get();
		}

		inline expr::Expr const * getNumGroupsZ()const
		{
			return m_numGroupsZ.get();
		}

		inline expr::Expr const * getPayload()const
		{
			return m_payload.get();
		}

	private:
		expr::ExprPtr m_numGroupsX{};
		expr::ExprPtr m_numGroupsY{};
		expr::ExprPtr m_numGroupsZ{};
		expr::ExprPtr m_payload{};
	};
}

#endif
