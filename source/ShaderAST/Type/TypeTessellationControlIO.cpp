/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTessellationControlIO.hpp"

namespace ast::type
{
	//*************************************************************************

	TessellationOutputPatch::TessellationOutputPatch( TypePtr type
		, uint32_t location )
		: Type{ type->getTypesCache(), Kind::eTessellationOutputPatch }
		, m_type{ type }
		, m_location{ location }
	{
	}

	//*************************************************************************

	TessellationControlInput::TessellationControlInput( TypePtr type
		, uint32_t inputVertices )
		: Type{ type->getTypesCache(), Kind::eTessellationControlInput }
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
		: Type{ type->getTypesCache(), Kind::eTessellationControlOutput }
		, m_type{ type }
		, m_domain{ domain }
		, m_partitioning{ partitioning }
		, m_topology{ topology }
		, m_order{ order }
		, m_outputVertices{ outputVertices }
	{
	}

	//*************************************************************************
}
