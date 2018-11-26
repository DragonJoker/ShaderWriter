/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtOutputGeometryLayout_H___
#define ___AST_StmtOutputGeometryLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	enum class OutputLayout
	{
		ePointList,
		eLineStrip,
		eTriangleStrip,
	};

	class OutputGeometryLayout
		: public Stmt
	{
	public:
		OutputGeometryLayout( OutputLayout layout
			, uint32_t primCount );

		void accept( VisitorPtr vis )override;

		inline OutputLayout getLayout()const
		{
			return m_layout;
		}

		inline uint32_t getPrimCount()const
		{
			return m_primCount;
		}

	private:
		OutputLayout m_layout;
		uint32_t m_primCount;
	};
	using OutputGeometryLayoutPtr = std::unique_ptr< OutputGeometryLayout >;

	inline OutputGeometryLayoutPtr makeOutputGeometryLayout( OutputLayout layout
		, uint32_t primCount )
	{
		return std::make_unique< OutputGeometryLayout >( layout
			, primCount );
	}
}

#endif
