/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeGeometryIO.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	//*********************************************************************************************

	GeometryInput::GeometryInput( TypePtr ptype
		, InputLayout playout )
		: Type{ ptype->getTypesCache(), Kind::eGeometryInput, false }
		, m_type{ ptype }
		, m_layout{ playout }
	{
	}

	//*********************************************************************************************

	GeometryOutput::GeometryOutput( TypePtr ptype
		, OutputLayout playout
		, uint32_t pcount )
		: Type{ ptype->getTypesCache(), Kind::eGeometryOutput, false }
		, m_type{ ptype }
		, m_layout{ playout }
		, m_count{ pcount }
	{
	}

	//*********************************************************************************************

	size_t getHash( TypePtr type
		, InputLayout layout )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, uint32_t( layout ) );
		return result;
	}

	size_t getHash( TypePtr type
		, OutputLayout layout
		, uint32_t count )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, uint32_t( layout ) );
		result = hashCombine( result, count );
		return result;
	}

	//*********************************************************************************************
}
