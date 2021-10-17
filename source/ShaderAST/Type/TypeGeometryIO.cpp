/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeGeometryIO.hpp"

namespace ast::type
{
	//*********************************************************************************************

	GeometryInput::GeometryInput( TypePtr ptype
		, InputLayout playout )
		: Type{ ptype->getCache(), Kind::eGeometryInput }
		, type{ ptype }
		, layout{ playout }
	{
	}

	//*********************************************************************************************

	GeometryOutput::GeometryOutput( TypePtr ptype
		, OutputLayout playout
		, uint32_t pcount )
		: Type{ ptype->getCache(), Kind::eGeometryOutput }
		, type{ ptype }
		, layout{ playout }
		, count{ pcount }
	{
	}

	//*********************************************************************************************
}
