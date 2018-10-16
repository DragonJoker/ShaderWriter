/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprArrayAccess.hpp>

namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	Optional< Array< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Array< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	template< typename IndexT >
	Optional< ValueT > Optional< Array< ValueT > >::operator[]( IndexT const & offset )const
	{
		return Optional< ValueT >{ findShader( *this, offset )
			, expr::makeArrayAccess( makeType( this->getType()->getKind() )
				, makeExpr( *this )
				, makeExpr( offset ) )
			, areOptionalEnabled( *this, offset ) };
	}

	template< typename ValueT >
	bool Optional< Array< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************
}
