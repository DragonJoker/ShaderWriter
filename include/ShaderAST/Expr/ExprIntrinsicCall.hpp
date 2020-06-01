/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprIntrinsicCall_H___
#define ___AST_ExprIntrinsicCall_H___
#pragma once

#include "ExprList.hpp"

#include "EnumIntrinsic.hpp"
#include "IntrinsicCallHelpers.hpp"

namespace ast::expr
{
	class IntrinsicCall
		: public Expr
	{
	public:
		IntrinsicCall( type::TypePtr type
			, Intrinsic intrinsic
			, ExprList && argList );

		void accept( VisitorPtr vis )override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline Intrinsic getIntrinsic()const
		{
			return m_intrinsic;
		}

	private:
		Intrinsic m_intrinsic;
		ExprList m_argList;
	};
	using IntrinsicCallPtr = std::unique_ptr< IntrinsicCall >;

	inline IntrinsicCallPtr makeIntrinsicCall( type::TypePtr type
		, Intrinsic intrinsic
		, ExprList && argList )
	{
		return std::make_unique< IntrinsicCall >( std::move( type )
			, intrinsic
			, std::move( argList ) );
	}

	template< typename ... Params >
	inline IntrinsicCallPtr makeIntrinsicCall( type::TypePtr type
		, Intrinsic intrinsic
		, Params ... args )
	{
		ExprList argList;
		helpers::fillArgsListRec( argList, std::forward< Params >( args )... );
		return makeIntrinsicCall( std::move( type )
			, intrinsic
			, std::move( argList ) );
	}
}

#endif
