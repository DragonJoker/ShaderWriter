/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTessellationEvaluationIO.hpp"

namespace ast::type
{
	//*************************************************************************

	TessellationInputPatch::TessellationInputPatch( TypePtr type
		, PatchDomain domain
		, uint32_t location )
		: Type{ type->getTypesCache(), Kind::eTessellationInputPatch }
		, m_type{ type }
		, m_domain{ domain }
		, m_location{ location }
	{
	}

	//*************************************************************************

	TessellationEvaluationInput::TessellationEvaluationInput( TypePtr type
		, PatchDomain domain
		, Partitioning partitioning
		, PrimitiveOrdering order
		, uint32_t inputVertices )
		: Type{ type->getTypesCache(), Kind::eTessellationEvaluationInput }
		, m_type{ std::move( type ) }
		, m_domain{ domain }
		, m_partitioning{ partitioning }
		, m_order{ order }
		, m_inputVertices{ inputVertices }
	{
	}

	//*************************************************************************
}
