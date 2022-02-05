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
		SDAST_API CombinedImageAccessCall( type::TypePtr type
			, CombinedImageAccess texelAccess
			, ExprList && argList );

		SDAST_API void accept( VisitorPtr vis )override;

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
	using CombinedImageAccessCallPtr = std::unique_ptr< CombinedImageAccessCall >;

	SDAST_API bool isBiasAndOffset( CombinedImageAccess value );
	SDAST_API bool isProj( ast::expr::CombinedImageAccess access );
	SDAST_API bool isShadow( CombinedImageAccess value );
	SDAST_API bool isShadowLodOffset( CombinedImageAccess value );
	SDAST_API CombinedImageAccess convert( SampledImageAccess value );

	inline CombinedImageAccessCallPtr makeCombinedImageAccessCall( type::TypePtr type
		, CombinedImageAccess texelAccess
		, ExprList && argList )
	{
		return std::make_unique< CombinedImageAccessCall >( std::move( type )
			, texelAccess
			, std::move( argList ) );
	}

	template< typename ... Params >
	inline CombinedImageAccessCallPtr makeCombinedImageAccessCall( type::TypePtr type
		, CombinedImageAccess texelAccess
		, Params ... args )
	{
		ExprList argList;
		helpers::fillArgsListRec( argList, std::forward< Params >( args )... );
		return makeCombinedImageAccessCall( std::move( type )
			, texelAccess
			, std::move( argList ) );
	}
}

#endif
