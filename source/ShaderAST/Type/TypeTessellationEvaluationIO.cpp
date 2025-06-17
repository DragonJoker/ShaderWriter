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
		: Type{ type->getTypesCache(), Kind::eTessellationInputPatch, false }
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
		: Type{ type->getTypesCache(), Kind::eTessellationEvaluationInput, false }
		, m_type{ std::move( type ) }
		, m_domain{ domain }
		, m_partitioning{ partitioning }
		, m_order{ order }
		, m_inputVertices{ inputVertices }
	{
	}

	//*************************************************************************

	size_t getHash( TypePtr type
		, PatchDomain domain
		, uint32_t location )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, uint32_t( domain ) );
		result = hashCombine( result, location );
		return result;
	}

	size_t getHash( TypePtr type
		, PatchDomain domain
		, Partitioning partitioning
		, PrimitiveOrdering order
		, uint32_t inputVertices )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, uint32_t( domain ) );
		result = hashCombine( result, uint32_t( partitioning ) );
		result = hashCombine( result, uint32_t( order ) );
		result = hashCombine( result, inputVertices );
		return result;
	}

	//*************************************************************************
}
