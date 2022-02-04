/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSampledImageAccessCall_H___
#define ___AST_ExprSampledImageAccessCall_H___
#pragma once

#include "ExprList.hpp"
#include "EnumSampledImageAccess.hpp"
#include "IntrinsicCallHelpers.hpp"

namespace ast::expr
{
	class SampledImageAccessCall
		: public Expr
	{
	public:
		SDAST_API SampledImageAccessCall( type::TypePtr type
			, SampledImageAccess texelAccess
			, ExprList && argList );

		SDAST_API void accept( VisitorPtr vis )override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline SampledImageAccess getSampledImageAccess()const
		{
			return m_sampledImageAccess;
		}

	private:
		SampledImageAccess m_sampledImageAccess;
		ExprList m_argList;
	};
	using SampledImageAccessCallPtr = std::unique_ptr< SampledImageAccessCall >;

	SDAST_API bool isBiasAndOffset( SampledImageAccess value );
	SDAST_API bool isProj( ast::expr::SampledImageAccess access );
	SDAST_API bool isShadow( SampledImageAccess value );
	SDAST_API bool isShadowLodOffset( SampledImageAccess value );

	inline SampledImageAccessCallPtr makeSampledImageAccessCall( type::TypePtr type
		, SampledImageAccess texelAccess
		, ExprList && argList )
	{
		return std::make_unique< SampledImageAccessCall >( std::move( type )
			, texelAccess
			, std::move( argList ) );
	}

	template< typename ... Params >
	inline SampledImageAccessCallPtr makeSampledImageAccessCall( type::TypePtr type
		, SampledImageAccess texelAccess
		, Params ... args )
	{
		ExprList argList;
		helpers::fillArgsListRec( argList, std::forward< Params >( args )... );
		return makeSampledImageAccessCall( std::move( type )
			, texelAccess
			, std::move( argList ) );
	}
}

#endif
