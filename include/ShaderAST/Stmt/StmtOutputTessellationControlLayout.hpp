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
		SDAST_API OutputTessellationControlLayout( type::TypePtr type
			, type::PatchDomain domain
			, type::OutputPartitioning partitioning
			, type::OutputTopology topology
			, type::OutputVertexOrder order
			, uint32_t outputVertices );

		SDAST_API void accept( VisitorPtr vis )override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		type::PatchDomain getDomain()const
		{
			return m_domain;
		}

		type::OutputPartitioning getPartitioning()const
		{
			return m_partitioning;
		}

		type::OutputTopology getTopology()const
		{
			return m_topology;
		}

		type::OutputVertexOrder getVertexOrder()const
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
		type::OutputPartitioning m_partitioning;
		type::OutputTopology m_topology;
		type::OutputVertexOrder m_order;
		uint32_t m_outputVertices;
	};
	using OutputTessellationControlLayoutPtr = std::unique_ptr< OutputTessellationControlLayout >;

	inline OutputTessellationControlLayoutPtr makeOutputTessellationControlLayout( type::TypePtr type
		, type::PatchDomain domain
		, type::OutputPartitioning partitioning
		, type::OutputTopology topology
		, type::OutputVertexOrder order
		, uint32_t outputVertices )
	{
		return std::make_unique< OutputTessellationControlLayout >( std::move( type )
			, domain
			, partitioning
			, topology
			, order
			, outputVertices );
	}
}

#endif
