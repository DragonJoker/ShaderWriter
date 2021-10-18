/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprMbrSelect.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	namespace
	{
		bool isStructType( type::TypePtr type )
		{
			return type->getKind() == type::Kind::eStruct
				|| ( type->getKind() == type::Kind::eGeometryInput
					&& ( static_cast< type::GeometryInput const & >( *type ).type->getKind() == type::Kind::eStruct
						|| ( static_cast< type::GeometryInput const & >( *type ).type->getKind() == type::Kind::eArray
							&& static_cast< type::Array const & >( *static_cast< type::GeometryInput const & >( *type ).type ).getType()->getKind() == type::Kind::eStruct ) ) )
				|| ( type->getKind() == type::Kind::eGeometryOutput
					&& static_cast< type::GeometryOutput const & >( *type ).type->getKind() == type::Kind::eStruct );
		}

		type::StructPtr getStructType( type::TypePtr type )
		{
			if ( type->getKind() == type::Kind::eGeometryInput )
			{
				type = static_cast< type::GeometryInput const & >( *type ).type;

				if ( type->getKind() == type::Kind::eArray )
				{
					return getStructType( static_cast< type::Array const & >( *type ).getType() );
				}

				return nullptr;
			}

			if ( type->getKind() == type::Kind::eGeometryOutput )
			{
				return getStructType( static_cast< type::GeometryOutput const & >( *type ).type );
			}

			return std::static_pointer_cast< type::Struct >( type );
		}

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
				result = result->getCache().getPointerType( result, storage );
			}

			return result;
		}
	}

	MbrSelect::MbrSelect( ExprPtr outer
		, uint32_t memberIndex
		, uint32_t memberFlags )
		: Expr{ outer->getCache()
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
		return getStructType( m_outer->getType() );
	}

	void MbrSelect::accept( VisitorPtr vis )
	{
		vis->visitMbrSelectExpr( this );
	}
}
