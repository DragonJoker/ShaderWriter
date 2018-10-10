/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Var/BoundVariable.hpp"

namespace ast
{
	BoundVariable::BoundVariable( Type type
		, std::string name
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Variable{ type, std::move( name ), Flag::eBound }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
		switch ( type )
		{
		case Type::eConstantsBuffer:
		case Type::eShaderBuffer:
		case Type::eSamplerBuffer:
		case Type::eSampler1D:
		case Type::eSampler2D:
		case Type::eSampler3D:
		case Type::eSamplerCube:
		case Type::eSampler2DRect:
		case Type::eSampler1DArray:
		case Type::eSampler2DArray:
		case Type::eSamplerCubeArray:
		case Type::eSampler1DShadow:
		case Type::eSampler2DShadow:
		case Type::eSamplerCubeShadow:
		case Type::eSampler2DRectShadow:
		case Type::eSampler1DArrayShadow:
		case Type::eSampler2DArrayShadow:
		case Type::eSamplerCubeArrayShadow:
			break;
		default:
			throw std::runtime_error{ "Invalid type for a bound variable" };
		}
	}
}
