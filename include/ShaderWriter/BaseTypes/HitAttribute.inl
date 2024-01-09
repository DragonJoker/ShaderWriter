/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/HitAttribute.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	template< typename ... ParamsT >
	HitAttributeT< ValueT >::HitAttributeT( ShaderWriter & writer
		, ParamsT && ... params )
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
			addStmt( writer, makeStructureDecl( getStmtCache( writer ), structType ) );
		}

		addStmt( writer
			, makeHitAttributeVariableDecl( getStmtCache( writer ), ast::findIdentifier( *this->getExpr() )->getVariable() ) );
	}

	template< typename ValueT >
	HitAttributeT< ValueT >::HitAttributeT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, std::move( expr ), enabled }
		, m_internal{ writer, ValueT::getExpr(), enabled }
	{
	}

	template< typename ValueT >
	template< typename ... ParamsT >
	ast::type::TypePtr HitAttributeT< ValueT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return cache.getHitAttribute( ValueT::makeType( cache, std::forward< ParamsT >( params )... ) );
	}

	template< typename ValueT >
	ReturnWrapperT< Boolean > HitAttributeT< ValueT >::reportIntersection( Float tHit
		, UInt32 const & hitKind )
	{
		return m_internal.reportIntersection( tHit
			, hitKind );
	}

	//*********************************************************************************************

	template< typename ValueT >
	expr::ExprPtr makeExpr( HitAttributeT< ValueT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
