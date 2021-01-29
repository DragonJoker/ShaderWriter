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
		: m_value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::ReturnWrapperT( ValueT const & rhs )
		: m_value{ rhs }
	{
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::ReturnWrapperT( ReturnWrapperT && rhs )
		: m_value{ std::move( rhs.m_value ) }
	{
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::~ReturnWrapperT()
	{
		if ( m_value.getExpr() && m_value.isEnabled() )
		{
			addStmt( *getWriter(), makeSimple( release() ) );
		}
	}

	template< typename ValueT >
	sdw::expr::ExprPtr ReturnWrapperT< ValueT >::release()const
	{
		if ( !m_value.getExpr() )
		{
			return makeDummyExpr( *getWriter(), getType() );
		}

		auto result = makeExpr( *getWriter(), m_value.getExpr() );
		m_value.updateExpr( nullptr );
		return result;
	}

	template< typename ValueT >
	expr::ExprPtr ReturnWrapperT< ValueT >::makeCondition()const
	{
		return release();
	}

	template< typename ValueT >
	ShaderWriter * ReturnWrapperT< ValueT >::getWriter()const
	{
		return m_value.getWriter();
	}

	template< typename ValueT >
	Shader * ReturnWrapperT< ValueT >::getShader()const
	{
		return m_value.getShader();
	}

	template< typename ValueT >
	bool ReturnWrapperT< ValueT >::isEnabled()const
	{
		return m_value.isEnabled();
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT >::operator ValueT()const
	{
		return std::move( m_value );
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
