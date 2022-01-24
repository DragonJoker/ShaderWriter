/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeMeshIO_H___
#define ___AST_TypeMeshIO_H___
#pragma once

#include "TypeTessellationControlIO.hpp"

namespace ast::type
{
	class MeshVertexOutput
		: public Type
	{
	public:
		SDAST_API MeshVertexOutput( TypePtr type
			, uint32_t maxVertices );

		type::TypePtr getType()const
		{
			return m_type;
		}

		uint32_t getMaxVertices()const
		{
			return m_maxVertices;
		}

	private:
		TypePtr m_type;
		uint32_t m_maxVertices;
	};
	using MeshVertexOutputPtr = std::shared_ptr< MeshVertexOutput >;

	inline MeshVertexOutputPtr makeMeshVertexOutputType( TypePtr type
		, uint32_t maxVertices )
	{
		return std::make_shared< MeshVertexOutput >( type
			, maxVertices );
	}

	class MeshPrimitiveOutput
		: public Type
	{
	public:
		SDAST_API MeshPrimitiveOutput( TypePtr type
			, OutputTopology topology
			, uint32_t maxPrimitives );

		type::TypePtr getType()const
		{
			return m_type;
		}

		OutputTopology getTopology()const
		{
			return m_topology;
		}

		uint32_t getMaxPrimitives()const
		{
			return m_maxPrimitives;
		}

	private:
		TypePtr m_type;
		OutputTopology m_topology;
		uint32_t m_maxPrimitives;
	};
	using MeshPrimitiveOutputPtr = std::shared_ptr< MeshPrimitiveOutput >;

	inline MeshPrimitiveOutputPtr makeMeshPrimitiveOutputType( TypePtr type
		, OutputTopology topology
		, uint32_t maxPrimitives )
	{
		return std::make_shared< MeshPrimitiveOutput >( type
			, topology
			, maxPrimitives );
	}
}

#endif
