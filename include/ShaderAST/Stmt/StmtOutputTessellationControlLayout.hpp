/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtOutputTessellationControlLayout_H___
#define ___AST_StmtOutputTessellationControlLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class OutputTessellationControlLayout
		: public Stmt
	{
	public:
		SDAST_API OutputTessellationControlLayout( StmtCache & stmtCache
			, type::TypePtr type
			, type::PatchDomain domain
			, type::Partitioning partitioning
			, type::OutputTopology topology
			, type::PrimitiveOrdering order
			, uint32_t outputVertices );

		SDAST_API void accept( VisitorPtr vis )const override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		type::PatchDomain getDomain()const
		{
			return m_domain;
		}

		type::Partitioning getPartitioning()const
		{
			return m_partitioning;
		}

		type::OutputTopology getTopology()const
		{
			return m_topology;
		}

		type::PrimitiveOrdering getPrimitiveOrdering()const
		{
			return m_order;
		}

		uint32_t getOutputVertices()const
		{
			return m_outputVertices;
		}

	private:
		type::TypePtr m_type;
		type::PatchDomain m_domain;
		type::Partitioning m_partitioning;
		type::OutputTopology m_topology;
		type::PrimitiveOrdering m_order;
		uint32_t m_outputVertices;
	};
}

#endif
