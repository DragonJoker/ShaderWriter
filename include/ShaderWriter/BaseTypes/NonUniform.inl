/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	namespace nonunif
	{
		static expr::ExprPtr updateExpr( expr::ExprPtr expr )
		{
			expr->updateFlag( ast::expr::Flag::eNonUniform );
			return sdw::makeCopy( std::move( expr ) );
		}
	}

	//*************************************************************************

	template< typename ValueT >
	NonUniformT< ValueT >::NonUniformT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, nonunif::updateExpr( std::move( expr ) ), enabled }
	{
	}

	template< typename ValueT >
	NonUniformT< ValueT >::NonUniformT( ValueT const & rhs )
		: ValueT{ rhs }
	{
	}

	template< typename ValueT >
	NonUniformT< ValueT >::NonUniformT( NonUniformT && rhs )noexcept
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
