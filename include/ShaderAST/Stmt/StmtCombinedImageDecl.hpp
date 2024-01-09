/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtCombinedImageDecl_H___
#define ___AST_StmtCombinedImageDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class CombinedImageDecl
		: public Stmt
	{
	public:
		SDAST_API CombinedImageDecl( StmtCache & stmtCache
			, var::VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		inline uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		inline uint32_t getDescriptorSet()const
		{
			return m_bindingSet;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
}

#endif
