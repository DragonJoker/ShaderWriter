/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTaskIO.hpp"

namespace ast::type
{
	//*************************************************************************

	TaskPayloadNV::TaskPayloadNV( TypePtr type )
		: Type{ type->getTypesCache(), Kind::eTaskPayloadNV }
		, m_type{ type }
	{
	}

	//*************************************************************************

	TaskPayload::TaskPayload( TypePtr type )
		: Type{ type->getTypesCache(), Kind::eTaskPayload }
		, m_type{ type }
	{
	}

	//*************************************************************************
}
