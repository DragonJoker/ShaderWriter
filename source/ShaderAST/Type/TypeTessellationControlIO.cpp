/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTessellationControlIO.hpp"

namespace ast::type
{
	//*************************************************************************

	TessellationOutputPatch::TessellationOutputPatch( TypePtr type
		, uint32_t location )
		: Type{ type->getTypesCache(), Kind::eTessellationOutputPatch, false }
		, m_type{ type }
		, m_location{ location }
	{
	}

	//*************************************************************************

	TessellationControlInput::TessellationControlInput( TypePtr type
		, uint32_t inputVertices )
		: Type{ type->getTypesCache(), Kind::eTessellationControlInput, false }
		, m_type{ std::move( type ) }
		, m_inputVertices{ inputVertices }
	{
	}

	//*************************************************************************

	TessellationControlOutput::TessellationControlOutput( TypePtr type
		, PatchDomain domain
		, Partitioning partitioning
		, OutputTopology topology
		, PrimitiveOrdering order
		, uint32_t outputVertices )
		: Type{ type->getTypesCache(), Kind::eTessellationControlOutput, false }
		, m_type{ type }
		, m_domain{ domain }
		, m_partitioning{ partitioning }
		, m_topology{ topology }
		, m_order{ order }
		, m_outputVertices{ outputVertices }
	{
	}

	//*************************************************************************

	size_t getHash( TypePtr type
		, PatchDomain domain
		, Partitioning partitioning
		, OutputTopology topology
		, PrimitiveOrdering order
		, uint32_t outputVertices )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, uint32_t( domain ) );
		result = hashCombine( result, uint32_t( partitioning ) );
		result = hashCombine( result, uint32_t( topology ) );
		result = hashCombine( result, uint32_t( order ) );
		result = hashCombine( result, outputVertices );
		return result;
	}

	//*************************************************************************
}
