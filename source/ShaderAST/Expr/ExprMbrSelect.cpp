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

			assert( isStructType( outerType ) );
			auto structOuter = getStructType( outerType );
			assert( structOuter->size() > memberIndex );
			auto result = ( structOuter->begin() + memberIndex )->type;

			if ( isPointer && result->getKind() != type::Kind::ePointer )
			{
				result = result->getTypesCache().getPointerType( result, storage );
			}

			return result;
		}
	}

	MbrSelect::MbrSelect( ExprCache & exprCache
		, ExprPtr outer
		, uint32_t memberIndex
		, uint64_t memberFlags )
		: Expr{ exprCache
			, sizeof( MbrSelect )
			, outer->getTypesCache()
			, getMbrType( outer->getType(), memberIndex )
			, Kind::eMbrSelect
			, ( isExprConstant( outer )
				? Flag::eConstant
				: Flag::eNone ) }
		, var::FlagHolder{ memberFlags }
		, m_outer{ std::move( outer ) }
		, m_memberIndex{ memberIndex }
	{
	}

	type::StructPtr MbrSelect::getOuterType()const
	{
		assert( isStructType( m_outer->getType() ) );
		return getStructType( m_outer->getType() );
	}

	void MbrSelect::accept( VisitorPtr vis )const
	{
		vis->visitMbrSelectExpr( this );
	}
}
