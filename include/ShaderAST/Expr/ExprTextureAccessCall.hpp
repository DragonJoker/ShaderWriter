/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprTextureAccessCall_H___
#define ___AST_ExprTextureAccessCall_H___
#pragma once

#include "ExprList.hpp"
#include "EnumTextureAccess.hpp"
#include "IntrinsicCallHelpers.hpp"

namespace ast::expr
{
	class TextureAccessCall
		: public Expr
	{
	public:
		TextureAccessCall( type::TypePtr type
			, TextureAccess texelAccess
			, ExprList && argList );

		void accept( VisitorPtr vis )override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline TextureAccess getTextureAccess()const
		{
			return m_textureAccess;
		}

	private:
		TextureAccess m_textureAccess;
		ExprList m_argList;
	};
	using TextureAccessCallPtr = std::unique_ptr< TextureAccessCall >;

	inline TextureAccessCallPtr makeTextureAccessCall( type::TypePtr type
		, TextureAccess texelAccess
		, ExprList && argList )
	{
		return std::make_unique< TextureAccessCall >( std::move( type )
			, texelAccess
			, std::move( argList ) );
	}

	template< typename ... Params >
	inline TextureAccessCallPtr makeTextureAccessCall( type::TypePtr type
		, TextureAccess texelAccess
		, Params ... args )
	{
		ExprList argList;
		helpers::fillArgsListRec( argList, std::forward< Params >( args )... );
		return makeTextureAccessCall( std::move( type )
			, texelAccess
			, std::move( argList ) );
	}
}

#include "MakeTextureAccess.hpp"

#endif
