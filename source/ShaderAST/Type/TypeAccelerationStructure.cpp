/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeAccelerationStructure.hpp"

namespace ast::type
{
	AccelerationStructure::AccelerationStructure( TypesCache & typesCache )
		: Type{ typesCache, Kind::eAccelerationStructure }
	{
	}
}
