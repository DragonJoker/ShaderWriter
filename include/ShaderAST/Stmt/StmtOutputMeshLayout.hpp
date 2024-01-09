/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtOutputMeshLayout_H___
#define ___AST_StmtOutputMeshLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class OutputMeshLayout
		: public Stmt
	{
	public:
		SDAST_API OutputMeshLayout( StmtCache & stmtCache
			, type::TypePtr type
			, type::OutputTopology topology
			, uint32_t maxVertices
			, uint32_t maxPrimitives );

		SDAST_API void accept( VisitorPtr vis )const override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		type::OutputTopology getTopology()const
		{
			return m_topology;
		}

		uint32_t getMaxVertices()const
		{
			return m_maxVertices;
		}

		uint32_t getMaxPrimitives()const
		{
			return m_maxPrimitives;
		}

	private:
		type::TypePtr m_type;
		type::OutputTopology m_topology;
		uint32_t m_maxVertices;
		uint32_t m_maxPrimitives;
	};
}

#endif
