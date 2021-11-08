/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInputTessellationEvaluationLayout_H___
#define ___AST_StmtInputTessellationEvaluationLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class InputTessellationEvaluationLayout
		: public Stmt
	{
	public:
		SDAST_API InputTessellationEvaluationLayout( type::TypePtr type
			, type::PatchDomain domain
			, type::Partitioning partitioning
			, type::PrimitiveOrdering order );

		SDAST_API void accept( VisitorPtr vis )override;

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

		type::PrimitiveOrdering getPrimitiveOrdering()const
		{
			return m_order;
		}

	private:
		type::TypePtr m_type;
		type::PatchDomain m_domain;
		type::Partitioning m_partitioning;
		type::PrimitiveOrdering m_order;
	};
	using InputTessellationEvaluationLayoutPtr = std::unique_ptr< InputTessellationEvaluationLayout >;

	inline InputTessellationEvaluationLayoutPtr makeInputTessellationEvaluationLayout( type::TypePtr type
		, type::PatchDomain domain
		, type::Partitioning partitioning
		, type::PrimitiveOrdering order )
	{
		return std::make_unique< InputTessellationEvaluationLayout >( std::move( type )
			, domain
			, partitioning
			, order );
	}
}

#endif
