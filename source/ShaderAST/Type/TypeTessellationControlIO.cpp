/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTessellationControlIO.hpp"

namespace ast::type
{
	//*************************************************************************

	TessellationOutputPatch::TessellationOutputPatch( TypePtr type
		, uint32_t location )
		: Type{ type->getCache(), Kind::eTessellationOutputPatch }
		, m_type{ type }
		, m_location{ location }
	{
	}

	//*************************************************************************

	TessellationControlInput::TessellationControlInput( TypePtr type
		, uint32_t inputVertices )
		: Type{ type->getCache(), Kind::eTessellationControlInput }
		, m_type{ std::move( type ) }
		, m_inputVertices{ inputVertices }
	{
	}

	//*************************************************************************

	TessellationControlOutput::TessellationControlOutput( TypePtr type
		, OutputDomain domain
		, OutputPartitioning partitioning
		, OutputTopology topology
		, OutputVertexOrder order
		, uint32_t outputVertices )
		: Type{ type->getCache(), Kind::eTessellationControlOutput }
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
