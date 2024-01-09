/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprImageAccessCall_H___
#define ___AST_ExprImageAccessCall_H___
#pragma once

#include "ExprList.hpp"
#include "EnumStorageImageAccess.hpp"
#include "IntrinsicCallHelpers.hpp"

namespace ast::expr
{
	class StorageImageAccessCall
		: public Expr
	{
	public:
		SDAST_API StorageImageAccessCall( ExprCache & exprCache
			, type::TypePtr type
			, StorageImageAccess imageAccess
			, ExprList argList );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline StorageImageAccess getImageAccess()const
		{
			return m_imageAccess;
		}

	private:
		StorageImageAccess m_imageAccess;
		ExprList m_argList;
	};
}

#endif
