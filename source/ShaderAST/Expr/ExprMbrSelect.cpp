/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprMbrSelect.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	namespace
	{
		type::TypePtr getMbrType( type::TypePtr outerType
			, uint32_t memberIndex )
		{
			assert( outerType->getKind() == type::Kind::eStruct );
			return ( static_cast< type::Struct const & >( *outerType ).begin() + memberIndex )->type;
		}
	}

	MbrSelect::MbrSelect( ExprPtr outer
		, uint32_t memberIndex
		, uint32_t memberFlags )
		: Expr{ outer->getCache(), getMbrType( outer->getType(), memberIndex ), Kind::eMbrSelect }
		, var::FlagHolder{ memberFlags }
		, m_outer{ std::move( outer ) }
		, m_memberIndex{ memberIndex }
	{
	}

	void MbrSelect::accept( VisitorPtr vis )
	{
		vis->visitMbrSelectExpr( this );
	}
}
