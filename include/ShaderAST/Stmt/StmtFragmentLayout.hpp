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
		FragmentLayout( FragmentOrigin origin
			, FragmentCenter center );

		void accept( VisitorPtr vis )override;

		inline FragmentOrigin getFragmentOrigin()const
		{
			return m_origin;
		}

		inline FragmentCenter getFragmentCenter()const
		{
			return m_center;
		}

	private:
		FragmentOrigin m_origin{ FragmentOrigin::eUpperLeft };
		FragmentCenter m_center{ FragmentCenter::eHalfPixel };
	};
	using FragmentLayoutPtr = std::unique_ptr< FragmentLayout >;

	inline FragmentLayoutPtr makeFragmentLayout( FragmentOrigin origin
		, FragmentCenter center )
	{
		return std::make_unique< FragmentLayout >( origin
			, center );
	}
}

#endif
