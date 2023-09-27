/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeHitAttribute.hpp"

namespace ast::type
{
	HitAttribute::HitAttribute( TypePtr dataType )
		: Type{ dataType->getTypesCache(), Kind::eHitAttribute }
		, m_dataType{ dataType }
	{
	}
}
