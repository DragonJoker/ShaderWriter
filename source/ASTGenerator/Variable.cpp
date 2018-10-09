/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Variable.hpp"

namespace ast
{
	Variable::Variable( Type type
		, std::string name )
		: m_type{ type }
		, m_name{ std::move( name ) }
	{
	}
}
