/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeTessellationControlIO_H___
#define ___AST_TypeTessellationControlIO_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	enum class PatchDomain
	{
		eIsolines,
		eTriangles,
		eQuads,
	};

	enum class Partitioning
	{
		eEqual,
		eFractionalEven,
		eFractionalOdd,
	};

	enum class PrimitiveOrdering
	{
		eCW,
		eCCW,
	};

	enum class OutputTopology
	{
		ePoint,
		eLine,
		eTriangle,
		eQuad,
	};

	class TessellationOutputPatch
		: public Type
	{
	public:
		SDAST_API TessellationOutputPatch( TypePtr type
			, uint32_t location );

		type::TypePtr getType()const
		{
			return m_type;
		}

		uint32_t getLocation()const
		{
			return m_location;
		}

	private:
		TypePtr m_type{};
		uint32_t m_location;
	};
	using TessellationOutputPatchPtr = TessellationOutputPatch *;

	class TessellationControlInput
		: public Type
	{
	public:
		SDAST_API TessellationControlInput( TypePtr type
			, uint32_t inputVertices );

		type::TypePtr getType()const
		{
			return m_type;
		}

		uint32_t getInputVertices()const
		{
			return m_inputVertices;
		}

	private:
		TypePtr m_type{};
		uint32_t m_inputVertices;
	};
	using TessellationControlInputPtr = TessellationControlInput *;

	class TessellationControlOutput
		: public Type
	{
	public:
		SDAST_API TessellationControlOutput( TypePtr type
			, PatchDomain domain
			, Partitioning partitioning
			, OutputTopology topology
			, PrimitiveOrdering order
			, uint32_t outputVertices );

		type::TypePtr getType()const
		{
			return m_type;
		}

		PatchDomain getDomain()const
		{
			return m_domain;
		}

		Partitioning getPartitioning()const
		{
			return m_partitioning;
		}

		OutputTopology getTopology()const
		{
			return m_topology;
		}

		PrimitiveOrdering getOrder()const
		{
			return m_order;
		}

		uint32_t getOutputVertices()const
		{
			return m_outputVertices;
		}

	private:
		TypePtr m_type{};
		PatchDomain m_domain;
		Partitioning m_partitioning;
		OutputTopology m_topology;
		PrimitiveOrdering m_order;
		uint32_t m_outputVertices;
	};
	using TessellationControlOutputPtr = TessellationControlOutput *;

	SDAST_API size_t getHash( TypePtr type
		, PatchDomain domain
		, Partitioning partitioning
		, OutputTopology topology
		, PrimitiveOrdering order
		, uint32_t outputVertices );
}

#endif
