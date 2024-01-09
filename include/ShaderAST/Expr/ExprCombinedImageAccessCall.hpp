/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCombinedImageAccessCall_H___
#define ___AST_ExprCombinedImageAccessCall_H___
#pragma once

#include "ExprList.hpp"
#include "EnumCombinedImageAccess.hpp"
#include "IntrinsicCallHelpers.hpp"

namespace ast::expr
{
	enum class SampledImageAccess : uint32_t;

	class CombinedImageAccessCall
		: public Expr
	{
	public:
		SDAST_API CombinedImageAccessCall( ExprCache & exprCache
			, type::TypePtr type
			, CombinedImageAccess texelAccess
			, ExprList argList );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline CombinedImageAccess getCombinedImageAccess()const
		{
			return m_textureAccess;
		}

	private:
		CombinedImageAccess m_textureAccess;
		ExprList m_argList;
	};

	SDAST_API bool isBiasAndOffset( CombinedImageAccess value );
	SDAST_API bool isProj( ast::expr::CombinedImageAccess access );
	SDAST_API bool isShadow( CombinedImageAccess value );
	SDAST_API bool isShadowLodOffset( CombinedImageAccess value );
	SDAST_API CombinedImageAccess convert( SampledImageAccess value );
}

#endif
