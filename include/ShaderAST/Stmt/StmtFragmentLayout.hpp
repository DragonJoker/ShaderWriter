/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFragmentLayout_H___
#define ___AST_StmtFragmentLayout_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class FragmentLayout
		: public Stmt
	{
	public:
		SDAST_API FragmentLayout( StmtCache & stmtCache
			, type::TypePtr type
			, FragmentOrigin origin
			, FragmentCenter center );

		SDAST_API void accept( VisitorPtr vis )const override;

		type::TypePtr getType()const
		{
			return m_type;
		}

		FragmentOrigin getFragmentOrigin()const
		{
			return m_origin;
		}

		FragmentCenter getFragmentCenter()const
		{
			return m_center;
		}

	private:
		type::TypePtr m_type;
		FragmentOrigin m_origin{ FragmentOrigin::eUpperLeft };
		FragmentCenter m_center{ FragmentCenter::eHalfPixel };
	};
}

#endif
