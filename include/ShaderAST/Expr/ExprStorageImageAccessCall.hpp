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
	class ImageAccessCall
		: public Expr
	{
	public:
		SDAST_API ImageAccessCall( type::TypePtr type
			, StorageImageAccess imageAccess
			, ExprList && argList );

		SDAST_API void accept( VisitorPtr vis )override;

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
	using ImageAccessCallPtr = std::unique_ptr< ImageAccessCall >;

	inline ImageAccessCallPtr makeImageAccessCall( type::TypePtr type
		, StorageImageAccess imageAccess
		, ExprList && argList )
	{
		return std::make_unique< ImageAccessCall >( std::move( type )
			, imageAccess
			, std::move( argList ) );
	}

	template< typename ... Params >
	inline ImageAccessCallPtr makeImageAccessCall( type::TypePtr type
		, StorageImageAccess imageAccess
		, Params ... args )
	{
		ExprList argList;
		helpers::fillArgsListRec( argList, std::forward< Params >( args )... );
		return makeImageAccessCall( std::move( type )
			, imageAccess
			, std::move( argList ) );
	}
}

#endif
