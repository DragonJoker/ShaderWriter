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
		: ValueT{ writer, std::move( expr ), enabled }
	{
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
	NonUniformT< ValueT >::operator ValueT()const
	{
		auto expr = makeExpr( *static_cast< ValueT const * >( this ) );
		expr->updateFlag( ast::expr::Flag::eNonUniform );
		return ValueT{ *this->getWriter()
			, std::move( expr )
			, this->isEnabled() };
	}

	template< typename ValueT >
	ast::type::TypePtr NonUniformT< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return ValueT::makeType( cache );
	}

	//*************************************************************************
}
