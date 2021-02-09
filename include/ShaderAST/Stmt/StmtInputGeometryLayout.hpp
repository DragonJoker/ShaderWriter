/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInputGeometryLayout_H___
#define ___AST_StmtInputGeometryLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
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

	class InputGeometryLayout
		: public Stmt
	{
	public:
		SDAST_API InputGeometryLayout( InputLayout layout );

		SDAST_API void accept( VisitorPtr vis )override;

		inline InputLayout getLayout()const
		{
			return m_layout;
		}

	private:
		InputLayout m_layout;
	};
	using InputGeometryLayoutPtr = std::unique_ptr< InputGeometryLayout >;

	inline InputGeometryLayoutPtr makeInputGeometryLayout( InputLayout layout )
	{
		return std::make_unique< InputGeometryLayout >( layout );
	}
}

#endif
