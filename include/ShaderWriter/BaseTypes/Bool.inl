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
		auto & writer = *findWriter( *this, rhs );
		addStmt( writer
			, sdw::makeSimple( sdw::makeAssign( getTypesCache( writer ).getBool()
				, sdw::makeExpr( writer, *this )
				, sdw::makeExpr( writer, rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	inline RetT writeComparator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( lhs, rhs );
		ast::expr::ExprPtr lhsExpr = sdw::makeExpr( writer, lhs );
		ast::expr::ExprPtr rhsExpr = sdw::makeExpr( writer, rhs );
		ast::type::TypePtr lhsType = details::getType( writer, lhs );
		ast::type::TypePtr rhsType = details::getType( writer, rhs );

		if ( rhsType != lhsType
			&& ast::type::getComponentCount( rhsType ) != ast::type::getComponentCount( lhsType )
			&& ast::type::getComponentType( rhsType ) != ast::type::getComponentType( lhsType ) )
		{
			rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
		}

		return RetT{ writer
			, creator( std::move( lhsExpr ), std::move( rhsExpr ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
