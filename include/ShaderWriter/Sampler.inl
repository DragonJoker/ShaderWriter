namespace sdw
{
	//*****************************************************************************************

	template< SamplerType ST >
	SamplerT< ST >::SamplerT( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
	{
	}

	template< SamplerType ST >
	template< typename T >
	SamplerT< ST > & SamplerT< ST >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( m_expr->get()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	template< SamplerType ST >
	SamplerT< ST >::operator uint32_t()
	{
		return 0u;
	}

	//*****************************************************************************************
}
