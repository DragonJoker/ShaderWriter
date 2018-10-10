/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtBoundVariableDecl_H___
#define ___AST_StmtBoundVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class StmtBoundVariableDecl
		: public Stmt
	{
	public:
		StmtBoundVariableDecl( VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		void accept( StmtVisitorPtr vis )override;

		inline Variable const & getVariable()const
		{
			return *m_variable;
		}

		inline uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		inline uint32_t getBindingSet()const
		{
			return m_bindingSet;
		}

	private:
		VariablePtr m_variable;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};

	inline std::unique_ptr< StmtBoundVariableDecl > makeBoundVariableDeclStmt( VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< StmtBoundVariableDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}
}

#endif
