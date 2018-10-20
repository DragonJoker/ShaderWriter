/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInOutVariableDecl_H___
#define ___AST_StmtInOutVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class InOutVariableDecl
		: public Stmt
	{
	public:
		InOutVariableDecl( var::VariablePtr variable
			, uint32_t location );

		void accept( VisitorPtr vis )override;

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
	using InOutVariableDeclPtr = std::unique_ptr< InOutVariableDecl >;

	inline InOutVariableDeclPtr makeInOutVariableDecl( var::VariablePtr variable
		, uint32_t location )
	{
		return std::make_unique< InOutVariableDecl >( std::move( variable )
			, location );
	}
}

#endif
