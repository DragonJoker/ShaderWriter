/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeAccelerationStructure.hpp"

namespace ast::type
{
	AccelerationStructure::AccelerationStructure( TypesCache & cache )
		: Type{ cache, Kind::eAccelerationStructure }
	{
	}
}
