/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeGeometryIO_H___
#define ___AST_TypeGeometryIO_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	enum class InputLayout
	{
		ePointList,
		eLineList,
		eLineStrip,
		eTriangleList,
		eTriangleStrip,
		eTriangleFan,
		eLineListWithAdjacency,
		eLineStripWithAdjacency,
		eTriangleListWithAdjacency,
		eTriangleStripWithAdjacency,
	};

	constexpr uint32_t getArraySize( InputLayout layout )
	{
		switch ( layout )
		{
		case InputLayout::ePointList:
			return 1u;
		case InputLayout::eLineList:
		case InputLayout::eLineStrip:
			return 2u;
		case InputLayout::eTriangleList:
		case InputLayout::eTriangleStrip:
		case InputLayout::eTriangleFan:
			return 3u;
		case InputLayout::eLineListWithAdjacency:
		case InputLayout::eLineStripWithAdjacency:
			return 4u;
		case InputLayout::eTriangleListWithAdjacency:
		case InputLayout::eTriangleStripWithAdjacency:
			return 6u;
		default:
			return 1u;
		}
	}

	struct GeometryInput
		: public Type
	{
		SDAST_API GeometryInput( TypePtr ptype
			, InputLayout playout );

		TypePtr getType()const
		{
			return m_type;
		}

		InputLayout getLayout()const
		{
			return m_layout;
		}

	private:
		TypePtr m_type{};
		InputLayout m_layout;
	};
	using GeometryInputPtr = GeometryInput *;

	SDAST_API size_t getHash( TypePtr type
		, InputLayout layout );

	enum class OutputLayout
	{
		ePointList,
		eLineStrip,
		eTriangleStrip,
	};

	struct GeometryOutput
		: public Type
	{
		SDAST_API GeometryOutput( TypePtr ptype
			, OutputLayout playout
			, uint32_t pcount );

		TypePtr getType()const
		{
			return m_type;
		}

		OutputLayout getLayout()const
		{
			return m_layout;
		}

		uint32_t getCount()const
		{
			return m_count;
		}

	private:
		TypePtr m_type{};
		OutputLayout m_layout;
		uint32_t m_count;
	};
	using GeometryOutputPtr = GeometryOutput *;

	SDAST_API size_t getHash( TypePtr type
		, OutputLayout layout
		, uint32_t count );
}

#endif
