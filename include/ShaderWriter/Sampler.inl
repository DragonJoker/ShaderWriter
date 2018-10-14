namespace sdw
{
	//*****************************************************************************************

	template< SamplerType ST >
	SamplerT< ST >::SamplerT( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< SamplerType ST >
	template< typename T >
	SamplerT< ST > & SamplerT< ST >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< SamplerType ST >
	SamplerT< ST >::operator uint32_t()
	{
		return 0u;
	}

	//*****************************************************************************************
}
