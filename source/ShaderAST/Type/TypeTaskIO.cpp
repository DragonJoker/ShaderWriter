/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTaskIO.hpp"

namespace ast::type
{
	TaskPayload::TaskPayload( TypePtr type )
		: Type{ type->getCache(), Kind::eTaskPayload }
		, m_type{ type }
	{
	}
}
