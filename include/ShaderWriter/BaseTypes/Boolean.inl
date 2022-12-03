/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	inline RetT writeComparator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		ShaderWriter & writer = findWriterMandat( lhs, rhs );
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
