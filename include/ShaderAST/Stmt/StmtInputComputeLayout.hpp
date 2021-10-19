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
		static constexpr uint32_t Uninit = ~( 0u );

		SDAST_API InputComputeLayout( uint32_t workGroupsX
			, uint32_t workGroupsY 
			, uint32_t workGroupsZ );

		SDAST_API void accept( VisitorPtr vis )override;

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
		uint32_t m_workGroupsX{ Uninit };
		uint32_t m_workGroupsY{ Uninit };
		uint32_t m_workGroupsZ{ Uninit };
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
