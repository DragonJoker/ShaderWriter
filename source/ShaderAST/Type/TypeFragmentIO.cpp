/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeFragmentIO.hpp"

namespace ast::type
{
	//*********************************************************************************************

	FragmentInput::FragmentInput( TypePtr type
		, FragmentOrigin origin
		, FragmentCenter center
		, InvocationOrdering ordering )
		: Type{ type->getTypesCache(), Kind::eFragmentInput }
		, m_type{ type }
		, m_origin{ origin }
		, m_center{ center }
		, m_ordering{ ordering }
	{
	}

	//*********************************************************************************************
}
