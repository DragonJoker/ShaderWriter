/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeComputeIO.hpp"

namespace ast::type
{
	//*********************************************************************************************

	ComputeInput::ComputeInput( TypePtr type
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
		: Type{ type->getTypesCache(), Kind::eComputeInput, false }
		, m_type{ type }
		, m_localSizeX{ localSizeX }
		, m_localSizeY{ localSizeY }
		, m_localSizeZ{ localSizeZ }
	{
	}

	//*********************************************************************************************

	size_t getHash( TypePtr type
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, localSizeX );
		result = hashCombine( result, localSizeY );
		result = hashCombine( result, localSizeZ );
		return result;
	}

	//*********************************************************************************************
}
