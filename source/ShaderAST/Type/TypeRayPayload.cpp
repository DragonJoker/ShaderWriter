/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeRayPayload.hpp"

namespace ast::type
{
	RayPayload::RayPayload( TypePtr dataType
		, uint32_t location )
		: Type{ dataType->getTypesCache(), Kind::eRayPayload }
		, m_dataType{ dataType }
		, m_location{ location }
	{
	}
}
