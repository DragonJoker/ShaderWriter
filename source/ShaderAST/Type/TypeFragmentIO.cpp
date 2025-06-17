/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeFragmentIO.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	//*********************************************************************************************

	FragmentInput::FragmentInput( TypePtr type
		, FragmentOrigin origin
		, FragmentCenter center
		, InvocationOrdering ordering )
		: Type{ type->getTypesCache(), Kind::eFragmentInput, false }
		, m_type{ type }
		, m_origin{ origin }
		, m_center{ center }
		, m_ordering{ ordering }
	{
	}

	//*********************************************************************************************

	size_t getHash( TypePtr type
		, FragmentOrigin origin
		, FragmentCenter center
		, InvocationOrdering ordering )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, uint32_t( origin ) );
		result = hashCombine( result, uint32_t( center ) );
		result = hashCombine( result, uint32_t( ordering ) );
		return result;
	}

	//*********************************************************************************************
}
