/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElse_H___
#define ___AST_StmtElse_H___
#pragma once

#include "StmtCompound.hpp"
#include "ASTGenerator/VariableList.hpp"

namespace ast
{
	class StmtFunctionDecl
		: public StmtCompound
	{
	public:
		StmtFunctionDecl( Type retType
			, std::string name
			, VariableList parameters );

		inline Type getRetType()const
		{
			return m_retType;
		}

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline VariableList const & getVariable()const
		{
			return m_parameters;
		}

	private:
		Type m_retType;
		std::string m_name;
		VariableList m_parameters;
	};
}

#endif
