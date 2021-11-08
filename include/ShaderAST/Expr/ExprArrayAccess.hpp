/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprArrayAccess_H___
#define ___AST_ExprArrayAccess_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class ArrayAccess
		: public Binary
	{
	public:
		SDAST_API ArrayAccess( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using ArrayAccessPtr = std::unique_ptr< ArrayAccess >;

	inline ArrayAccessPtr makeArrayAccess( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		assert( lhs->getType()->getKind() == type::Kind::eArray
			|| lhs->getType()->getKind() == type::Kind::eGeometryInput
			|| lhs->getType()->getKind() == type::Kind::eTessellationControlInput
			|| lhs->getType()->getKind() == type::Kind::eTessellationControlOutput
			|| lhs->getType()->getKind() == type::Kind::eTessellationEvaluationInput
			|| isVectorType( lhs->getType()->getKind() )
			|| isMatrixType( lhs->getType()->getKind() ) );
		return std::make_unique< ArrayAccess >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
