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
	ReturnWrapperT< ValueT >::ReturnWrapperT( ReturnWrapperT && rhs )
		: ValueT{ std::move( rhs ) }
	{
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::~ReturnWrapperT()
	{
		if ( this->getExpr() && this->isEnabled() )
		{
			addStmt( *this->getWriter(), makeSimple( release() ) );
		}
	}

	template< typename ValueT >
	sdw::expr::ExprPtr ReturnWrapperT< ValueT >::release()const
	{
		assert( this->getExpr() );
		auto result = makeExpr( *this->getWriter(), this->getExpr() );
		const_cast< ReturnWrapperT< ValueT > & >( *this ).updateExpr( nullptr );
		return result;
	}

	template< typename ValueT >
	expr::ExprPtr ReturnWrapperT< ValueT >::makeCondition()
	{
		return release();
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::operator ValueT()
	{
		return ValueT{ *this->getWriter(), release(), this->isEnabled() };
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
		, bool force )
	{
		return variable.release();
	}

	//*************************************************************************
}
