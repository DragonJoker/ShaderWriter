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
	class InputGeometryLayout
		: public Stmt
	{
	public:
		SDAST_API InputGeometryLayout( type::TypePtr type
			, type::InputLayout layout );

		SDAST_API void accept( VisitorPtr vis )override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		type::InputLayout getLayout()const
		{
			return m_layout;
		}

	private:
		type::TypePtr m_type;
		type::InputLayout m_layout;
	};
	using InputGeometryLayoutPtr = std::unique_ptr< InputGeometryLayout >;

	inline InputGeometryLayoutPtr makeInputGeometryLayout( type::TypePtr type
		, type::InputLayout layout )
	{
		return std::make_unique< InputGeometryLayout >( std::move( type )
			, layout );
	}
}

#endif
