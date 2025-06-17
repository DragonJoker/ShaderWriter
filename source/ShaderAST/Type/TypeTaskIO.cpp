/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTaskIO.hpp"

namespace ast::type
{
	//*************************************************************************

	TaskPayloadNV::TaskPayloadNV( TypePtr type )
		: Type{ type->getTypesCache(), Kind::eTaskPayloadNV, false }
		, m_type{ type }
	{
	}

	//*************************************************************************

	TaskPayload::TaskPayload( TypePtr type )
		: Type{ type->getTypesCache(), Kind::eTaskPayload, false }
		, m_type{ type }
	{
	}

	//*************************************************************************
}
