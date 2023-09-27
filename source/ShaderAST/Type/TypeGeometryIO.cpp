/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeGeometryIO.hpp"

namespace ast::type
{
	//*********************************************************************************************

	GeometryInput::GeometryInput( TypePtr ptype
		, InputLayout playout )
		: Type{ ptype->getTypesCache(), Kind::eGeometryInput }
		, m_type{ ptype }
		, m_layout{ playout }
	{
	}

	//*********************************************************************************************

	GeometryOutput::GeometryOutput( TypePtr ptype
		, OutputLayout playout
		, uint32_t pcount )
		: Type{ ptype->getTypesCache(), Kind::eGeometryOutput }
		, m_type{ ptype }
		, m_layout{ playout }
		, m_count{ pcount }
	{
	}

	//*********************************************************************************************
}
