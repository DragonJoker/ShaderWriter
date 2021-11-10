/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeFragmentIO.hpp"

namespace ast::type
{
	//*********************************************************************************************

	FragmentInput::FragmentInput( TypePtr type
		, ast::FragmentOrigin origin
		, ast::FragmentCenter center )
		: Type{ type->getCache(), Kind::eFragmentInput }
		, m_type{ type }
		, m_origin{ origin }
		, m_center{ center }
	{
	}

	//*********************************************************************************************
}
