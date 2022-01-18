/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	NonUniformT< ValueT >::NonUniformT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, sdw::makeCopy( std::move( expr ) ), enabled }
	{
		this->getExpr()->updateFlag( ast::expr::Flag::eNonUniform );
	}

	template< typename ValueT >
	NonUniformT< ValueT >::NonUniformT( ValueT const & rhs )
		: ValueT{ rhs }
	{
	}

	template< typename ValueT >
	NonUniformT< ValueT >::NonUniformT( NonUniformT && rhs )
		: ValueT{ std::move( rhs ) }
	{
	}

	template< typename ValueT >
	ast::type::TypePtr NonUniformT< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return ValueT::makeType( cache );
	}

	//*************************************************************************
}
