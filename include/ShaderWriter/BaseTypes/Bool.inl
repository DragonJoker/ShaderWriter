/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename T >
	inline Bool & Bool::operator=( T const & rhs )
	{
		updateContainer( rhs );
		Shader & shader = *findShader( *this, rhs );
		addStmt( shader
			, sdw::makeSimple( sdw::makeAssign( getTypesCache( shader ).getBool()
				, sdw::makeExpr( shader, *this )
				, sdw::makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename LhsT, typename RhsT, typename CreatorT >
	inline Bool writeComparator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return Bool{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Bool > writeComparator( Optional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return Optional< Bool >{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Bool > writeComparator( LhsT const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return Optional< Bool >{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Bool > writeComparator( Optional< LhsT > const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return Optional< Bool >{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Bool > writeComparator( MaybeOptional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Bool >{ &shader
				, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return Bool{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Bool > writeComparator( LhsT const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Bool >{ &shader
				, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return Bool{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Bool > writeComparator( MaybeOptional< LhsT > const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Bool >{ &shader
				, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return Bool{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	//*************************************************************************
}
