/*
See LICENSE file in root folder
*/
#ifndef ___AST_StreamAppend_H___
#define ___AST_StreamAppend_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class StreamAppend
		: public Unary
	{
	public:
		SDAST_API StreamAppend( type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using StreamAppendPtr = std::unique_ptr< StreamAppend >;

	inline StreamAppendPtr makeStreamAppend( ExprPtr operand )
	{
		auto type = operand->getType();
		return std::make_unique< StreamAppend >( std::move( type )
			, std::move( operand ) );
	}
}

#endif
