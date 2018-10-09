/*
See LICENSE file in root folder
*/
#ifndef ___AST_Variable_H___
#define ___AST_Variable_H___
#pragma once

#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

namespace ast
{
	class Variable
	{
	public:
		Variable( Type type
			, std::string name );

		inline Type getType()const
		{
			return m_type;
		}

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		Type m_type;
		std::string m_name;
	};
}

#endif
