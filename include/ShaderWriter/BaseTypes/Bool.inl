/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename T >
	inline Boolean & Boolean::operator=( T const & rhs )
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

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	inline RetT writeComparator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return RetT{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< RetT > writeComparator( Optional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return Optional< RetT >{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< RetT > writeComparator( LhsT const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return Optional< RetT >{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< RetT > writeComparator( Optional< LhsT > const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return Optional< RetT >{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< RetT > writeComparator( MaybeOptional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< RetT >{ &shader
				, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return RetT{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< RetT > writeComparator( LhsT const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< RetT >{ &shader
				, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return RetT{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< RetT > writeComparator( MaybeOptional< LhsT > const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		Shader & shader = *findShader( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
		ast::type::TypePtr lhsType = details::getType( shader, lhs );
		ast::type::TypePtr rhsType = details::getType( shader, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< RetT >{ &shader
				, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return RetT{ &shader
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) ) };
	}

	//*************************************************************************
}
