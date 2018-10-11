/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/Type.hpp"

namespace ast::type
{
	Type::Type( Kind kind
		, uint32_t arraySize )
		: m_kind{ kind }
		, m_arraySize{ arraySize }
	{
	}

	Type::~Type()
	{
	}
}
