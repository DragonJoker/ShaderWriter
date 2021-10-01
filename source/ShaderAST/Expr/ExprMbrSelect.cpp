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
			bool isPointer = false;
			type::Storage storage{};

			if ( outerType->getKind() == type::Kind::ePointer )
			{
				auto & pointer = static_cast< type::Pointer const & >( *outerType );
				outerType = pointer.getPointerType();
				isPointer = true;
				storage = pointer.getStorage();
			}

			assert( outerType->getKind() == type::Kind::eStruct );
			assert( static_cast< type::Struct const & >( *outerType ).size() > memberIndex );
			auto result = ( static_cast< type::Struct const & >( *outerType ).begin() + memberIndex )->type;

			if ( isPointer && result->getKind() != type::Kind::ePointer )
			{
				result = result->getCache().getPointerType( result, storage );
			}

			return result;
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
