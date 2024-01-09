/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInputComputeLayout_H___
#define ___AST_StmtInputComputeLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class InputComputeLayout
		: public Stmt
	{
	public:
		static constexpr uint32_t Uninit = ~0u;

		SDAST_API InputComputeLayout( StmtCache & stmtCache
			, type::TypePtr type
			, uint32_t workGroupsX
			, uint32_t workGroupsY 
			, uint32_t workGroupsZ );

		SDAST_API void accept( VisitorPtr vis )const override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		uint32_t getWorkGroupsX()const
		{
			return m_workGroupsX;
		}

		uint32_t getWorkGroupsY()const
		{
			return m_workGroupsY;
		}

		uint32_t getWorkGroupsZ()const
		{
			return m_workGroupsZ;
		}

	private:
		type::TypePtr m_type;
		uint32_t m_workGroupsX{ Uninit };
		uint32_t m_workGroupsY{ Uninit };
		uint32_t m_workGroupsZ{ Uninit };
	};
}

#endif
