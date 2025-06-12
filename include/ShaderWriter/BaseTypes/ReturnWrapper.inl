/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	ReturnWrapperT< ValueT >::ReturnWrapperT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::ReturnWrapperT( ValueT const & rhs )
		: ValueT{ rhs }
	{
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::ReturnWrapperT( ReturnWrapperT && rhs )noexcept
		: ValueT{ std::move( rhs ) }
	{
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::~ReturnWrapperT()noexcept
	{
		if ( this->m_expr.get() && this->isEnabled() )
		{
			ast::expr::ExprPtr expr = release();

			if ( expr->getKind() != ast::expr::Kind::eIdentifier
				&& expr->getKind() != ast::expr::Kind::eLiteral
				&& expr->getKind() != ast::expr::Kind::eAdd
				&& expr->getKind() != ast::expr::Kind::eMinus
				&& expr->getKind() != ast::expr::Kind::eTimes
				&& expr->getKind() != ast::expr::Kind::eDivide
				&& expr->getKind() != ast::expr::Kind::eModulo
				&& expr->getKind() != ast::expr::Kind::eLShift
				&& expr->getKind() != ast::expr::Kind::eRShift
				&& expr->getKind() != ast::expr::Kind::eBitAnd
				&& expr->getKind() != ast::expr::Kind::eBitNot
				&& expr->getKind() != ast::expr::Kind::eBitOr
				&& expr->getKind() != ast::expr::Kind::eBitXor
				&& expr->getKind() != ast::expr::Kind::eLogAnd
				&& expr->getKind() != ast::expr::Kind::eLogNot
				&& expr->getKind() != ast::expr::Kind::eLogOr
				&& expr->getKind() != ast::expr::Kind::eCast
				&& expr->getKind() != ast::expr::Kind::eCompositeConstruct
				&& expr->getKind() != ast::expr::Kind::eEqual
				&& expr->getKind() != ast::expr::Kind::eGreater
				&& expr->getKind() != ast::expr::Kind::eGreaterEqual
				&& expr->getKind() != ast::expr::Kind::eLess
				&& expr->getKind() != ast::expr::Kind::eLessEqual
				&& expr->getKind() != ast::expr::Kind::eNotEqual
				&& expr->getKind() != ast::expr::Kind::eMbrSelect
				&& expr->getKind() != ast::expr::Kind::eSwizzle
				&& expr->getKind() != ast::expr::Kind::eUnaryMinus
				&& expr->getKind() != ast::expr::Kind::eUnaryPlus
				&& expr->getKind() != ast::expr::Kind::eArrayAccess )
			{
				addStmt( *this->getWriter()
					, sdw::makeSimple( getStmtCache( *this->getWriter() ), std::move( expr ) ) );
			}
		}
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT > ReturnWrapperT< ValueT >::operator=( ReturnWrapperT< ValueT > const & rhs )
	{
		auto & writer = *this->getWriter();
		return ReturnWrapperT< ValueT >{ writer
			, sdw::makeAssign( this->getType()
				, makeExpr( writer, *this )
				, makeExpr( writer, rhs ) )
			, areOptionalEnabled( *this, rhs ) };
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT > ReturnWrapperT< ValueT >::operator=( ReturnWrapperT< ValueT > && rhs )
	{
		auto & writer = *this->getWriter();
		return ReturnWrapperT< ValueT >{ writer
			, sdw::makeAssign( this->getType()
				, makeExpr( writer, *this )
				, makeExpr( writer, rhs ) )
			, areOptionalEnabled( *this, rhs ) };
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT > ReturnWrapperT< ValueT >::operator=( ValueT const & rhs )
	{
		auto & writer = *this->getWriter();
		return ReturnWrapperT< ValueT >{ writer
			, sdw::makeAssign( this->getType()
				, makeExpr( writer, *this )
				, makeExpr( writer, rhs ) )
			, areOptionalEnabled( *this, rhs ) };
	}

	template< typename ValueT >
	type::TypePtr ReturnWrapperT< ValueT >::getType()const
	{
		if ( this->m_expr )
		{
			return this->m_expr->getType();
		}

		return m_remnExpr->getType();
	}

	template< typename ValueT >
	expr::Expr const * ReturnWrapperT< ValueT >::getExpr()const
	{
		if ( !m_remnExpr )
			m_remnExpr = std::move( release() );
		return m_remnExpr.get();
	}

	template< typename ValueT >
	sdw::expr::ExprPtr ReturnWrapperT< ValueT >::release()const
	{
		assert( this->m_expr.get() );
		auto result = makeExpr( *this->getWriter(), *this->m_expr );
		const_cast< ReturnWrapperT< ValueT > & >( *this ).updateExpr( nullptr );
		return result;
	}

	template< typename ValueT >
	expr::ExprPtr ReturnWrapperT< ValueT >::makeCondition()
	{
		return release();
	}

	template< typename ValueT >
	ast::type::TypePtr ReturnWrapperT< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return ValueT::makeType( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, ReturnWrapperT< ValueT > const & variable
		, [[maybe_unused]] bool force )
	{
		return makeExpr( writer, variable.getExpr() );
	}

	//*************************************************************************
}
