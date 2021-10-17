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

	struct GeometryInput
		: public Type
	{
		SDAST_API GeometryInput( TypePtr ptype
			, InputLayout playout );

		TypePtr type;
		InputLayout layout;
	};
	using GeometryInputPtr = std::shared_ptr< GeometryInput >;

	inline GeometryInputPtr makeGeometryInputType( TypePtr type
		, InputLayout layout )
	{
		return std::make_shared< GeometryInput >( type, layout );
	}

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

		TypePtr type;
		OutputLayout layout;
		uint32_t count;
	};
	using GeometryOutputPtr = std::shared_ptr< GeometryOutput >;

	inline GeometryOutputPtr makeGeometryOutputType( TypePtr type
		, OutputLayout layout
		, uint32_t count )
	{
		return std::make_shared< GeometryOutput >( type, layout, count );
	}

}

#endif
