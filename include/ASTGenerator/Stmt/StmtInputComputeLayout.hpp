/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInputComputeLayout_H___
#define ___AST_StmtInputComputeLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast::stmt
{
	class InputComputeLayout
		: public Stmt
	{
	public:
		InputComputeLayout( uint32_t workGroupsX
			, uint32_t workGroupsY 
			, uint32_t workGroupsZ );

		void accept( VisitorPtr vis )override;

		inline uint32_t getWorkGroupsX()const
		{
			return m_workGroupsX;
		}

		inline uint32_t getWorkGroupsY()const
		{
			return m_workGroupsY;
		}

		inline uint32_t getWorkGroupsZ()const
		{
			return m_workGroupsZ;
		}

	private:
		uint32_t m_workGroupsX;
		uint32_t m_workGroupsY;
		uint32_t m_workGroupsZ;
	};
	using InputComputeLayoutPtr = std::unique_ptr< InputComputeLayout >;

	inline InputComputeLayoutPtr makeInputComputeLayout( uint32_t workGroupsX
		, uint32_t workGroupsY
		, uint32_t workGroupsZ )
	{
		return std::make_unique< InputComputeLayout >( workGroupsX
			, workGroupsY
			, workGroupsZ );
	}
}

#endif
