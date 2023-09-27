/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeCallableData.hpp"

namespace ast::type
{
	CallableData::CallableData( TypePtr dataType
		, uint32_t location )
		: Type{ dataType->getTypesCache(), Kind::eCallableData }
		, m_dataType{ dataType }
		, m_location{ location }
	{
	}
}
