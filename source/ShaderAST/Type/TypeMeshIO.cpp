/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeMeshIO.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	//*************************************************************************

	TaskPayloadInNV::TaskPayloadInNV( TypePtr type )
		: Type{ type->getTypesCache(), Kind::eTaskPayloadInNV }
		, m_type{ type }
	{
	}

	//*************************************************************************

	TaskPayloadIn::TaskPayloadIn( TypePtr type )
		: Type{ type->getTypesCache(), Kind::eTaskPayloadIn }
		, m_type{ type }
	{
	}

	//*************************************************************************

	MeshVertexOutput::MeshVertexOutput( TypePtr type
		, uint32_t maxVertices )
		: Type{ type->getTypesCache(), Kind::eMeshVertexOutput }
		, m_type{ type }
		, m_maxVertices{ maxVertices }
	{
	}

	//*************************************************************************

	MeshPrimitiveOutput::MeshPrimitiveOutput( TypePtr type
		, OutputTopology topology
		, uint32_t maxPrimitives )
		: Type{ type->getTypesCache(), Kind::eMeshPrimitiveOutput }
		, m_type{ std::move( type ) }
		, m_topology{ topology }
		, m_maxPrimitives{ maxPrimitives }
	{
	}

	//*************************************************************************

	size_t getHash( TypePtr type
		, OutputTopology topology
		, uint32_t maxPrimitives )
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, uint32_t( topology ) );
		result = hashCombine( result, maxPrimitives );
		return result;
	}

	//*************************************************************************
}
