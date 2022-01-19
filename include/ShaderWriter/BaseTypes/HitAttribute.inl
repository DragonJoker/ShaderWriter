/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/HitAttribute.hpp"

namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	HitAttributeT< ValueT >::HitAttributeT( ShaderWriter & writer
		, ParamsT ... params )
		: HitAttributeT{ writer
		, makeExpr( writer
			, sdw::registerName( writer
				, "hitAttrib"
				, makeType( getTypesCache( writer )
					, std::forward< ParamsT >( params )... )
				, uint64_t( ast::var::Flag::eHitAttribute ) ) ) }
	{
		if ( auto structType = getStructType( this->getType() ) )
		{
			addStmt( writer, sdw::makeStructDecl( structType ) );
		}

		addStmt( writer
			, sdw::makeHitAttributeVariableDecl( ast::findIdentifier( this->getExpr() )->getVariable() ) );
	}

	template< typename ValueT >
	HitAttributeT< ValueT >::HitAttributeT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	template< typename ... ParamsT >
	ast::type::TypePtr HitAttributeT< ValueT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return ValueT::makeType( cache );
	}

	//*********************************************************************************************

	template< typename ValueT >
	expr::ExprPtr makeExpr( HitAttributeT< ValueT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
