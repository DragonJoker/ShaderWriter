/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeTessellationControlIO_H___
#define ___AST_TypeTessellationControlIO_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
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
		TypePtr m_type;
		uint32_t m_location;
	};
	using TessellationOutputPatchPtr = std::shared_ptr< TessellationOutputPatch >;

	inline TessellationOutputPatchPtr makeTessellationOutputPatchType( TypePtr type
		, uint32_t location )
	{
		return std::make_shared< TessellationOutputPatch >( type
			, location );
	}

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
		TypePtr m_type;
		uint32_t m_inputVertices;
	};
	using TessellationControlInputPtr = std::shared_ptr< TessellationControlInput >;

	inline TessellationControlInputPtr makeTessellationControlInputType( TypePtr type
		, uint32_t inputVertices )
	{
		return std::make_shared< TessellationControlInput >( type
			, inputVertices );
	}

	enum class OutputPartitioning
	{
		eEqual,
		eFractionalEven,
		eFractionalOdd,
	};

	enum class OutputVertexOrder
	{
		eCW,
		eCCW,
	};

	enum class OutputDomain
	{
		eIsolines,
		eTriangles,
		eQuads,
	};

	enum class OutputTopology
	{
		ePoint,
		eLine,
		eTriangle,
		eQuad,
	};

	class TessellationControlOutput
		: public Type
	{
	public:
		SDAST_API TessellationControlOutput( TypePtr type
			, OutputDomain domain
			, OutputPartitioning partitioning
			, OutputTopology topology
			, OutputVertexOrder order
			, uint32_t outputVertices );

		type::TypePtr getType()const
		{
			return m_type;
		}

		OutputDomain getDomain()const
		{
			return m_domain;
		}

		OutputPartitioning getPartitioning()const
		{
			return m_partitioning;
		}

		OutputTopology getTopology()const
		{
			return m_topology;
		}

		OutputVertexOrder getOrder()const
		{
			return m_order;
		}

		uint32_t getOutputVertices()const
		{
			return m_outputVertices;
		}

	private:
		TypePtr m_type;
		OutputDomain m_domain;
		OutputPartitioning m_partitioning;
		OutputTopology m_topology;
		OutputVertexOrder m_order;
		uint32_t m_outputVertices;
	};
	using TessellationControlOutputPtr = std::shared_ptr< TessellationControlOutput >;

	inline TessellationControlOutputPtr makeTessellationControlOutputType( TypePtr type
		, OutputDomain domain
		, OutputPartitioning partitioning
		, OutputTopology topology
		, OutputVertexOrder order
		, uint32_t outputVertices )
	{
		return std::make_shared< TessellationControlOutput >( type
			, domain
			, partitioning
			, topology
			, order
			, outputVertices );
	}
}

#endif
