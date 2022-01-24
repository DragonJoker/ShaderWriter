/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeMeshIO.hpp"

namespace ast::type
{
	//*************************************************************************

	MeshVertexOutput::MeshVertexOutput( TypePtr type
		, uint32_t maxVertices )
		: Type{ type->getCache(), Kind::eMeshVertexOutput }
		, m_type{ type }
		, m_maxVertices{ maxVertices }
	{
	}

	//*************************************************************************

	MeshPrimitiveOutput::MeshPrimitiveOutput( TypePtr type
		, OutputTopology topology
		, uint32_t maxPrimitives )
		: Type{ type->getCache(), Kind::eMeshPrimitiveOutput }
		, m_type{ std::move( type ) }
		, m_topology{ topology }
		, m_maxPrimitives{ maxPrimitives }
	{
	}

	//*************************************************************************
}
