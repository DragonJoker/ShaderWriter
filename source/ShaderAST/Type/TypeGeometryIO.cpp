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
		, m_type{ ptype }
		, m_layout{ playout }
	{
	}

	//*********************************************************************************************

	GeometryOutput::GeometryOutput( TypePtr ptype
		, OutputLayout playout
		, uint32_t pcount )
		: Type{ ptype->getCache(), Kind::eGeometryOutput }
		, m_type{ ptype }
		, m_layout{ playout }
		, m_count{ pcount }
	{
	}

	//*********************************************************************************************
}
