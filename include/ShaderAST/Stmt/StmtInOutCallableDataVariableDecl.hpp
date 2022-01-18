/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInOutCallableDataVariableDecl_H___
#define ___AST_StmtInOutCallableDataVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class InOutCallableDataVariableDecl
		: public Stmt
	{
	public:
		SDAST_API InOutCallableDataVariableDecl( var::VariablePtr variable
			, uint32_t location );

		SDAST_API void accept( VisitorPtr vis )override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		inline uint32_t getLocation()const
		{
			return m_location;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_location;
	};
	using InOutCallableDataVariableDeclPtr = std::unique_ptr< InOutCallableDataVariableDecl >;

	inline InOutCallableDataVariableDeclPtr makeInOutCallableDataVariableDecl( var::VariablePtr variable
		, uint32_t location )
	{
		return std::make_unique< InOutCallableDataVariableDecl >( std::move( variable )
			, location );
	}
}

#endif