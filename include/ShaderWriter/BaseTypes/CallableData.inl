/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/CallableData.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	//*********************************************************************************************

	template< ast::var::Flag FlagT, typename ValueT >
	template< typename ... ParamsT >
	CallableDataBaseT< FlagT, ValueT >::CallableDataBaseT( ShaderWriter & writer
		, uint32_t location
		, ParamsT && ... params )
		: CallableDataBaseT{ writer
			, makeExpr( writer
				, sdw::registerName( writer
					, FlagT == ast::var::Flag::eShaderInput ? std::string{ "callDataIn" } : std::string{ "callData" }
					, makeType( getTypesCache( writer )
						, location
						, std::forward< ParamsT >( params )... )
					, FlagT | ( FlagT == ast::var::Flag::eShaderInput ? ast::var::Flag::eIncomingCallableData : ast::var::Flag::eCallableData ) ) )
			, true }
	{
		if ( auto structType = getStructType( this->getType() ) )
		{
			addGlobalStmt( writer, makeStructureDecl( getStmtCache( writer ), structType ) );
		}

		addGlobalStmt( writer
			, makeInOutCallableDataVariableDecl( getStmtCache( writer ), ast::findIdentifier( *this->getExpr() )->getVariable(), location ) );
	}

	template< ast::var::Flag FlagT, typename ValueT >
	CallableDataBaseT< FlagT, ValueT >::CallableDataBaseT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, std::move( expr ), enabled }
		, m_internal{ writer, ValueT::getExpr(), enabled }
	{
	}

	template< ast::var::Flag FlagT, typename ValueT >
	CallableDataBaseT< FlagT, ValueT > & CallableDataBaseT< FlagT, ValueT >::operator=( ValueT const & rhs )
	{
		ValueT::operator=( rhs );
		return *this;
	}

	template< ast::var::Flag FlagT, typename ValueT >
	template< typename ... ParamsT >
	ast::type::TypePtr CallableDataBaseT< FlagT, ValueT >::makeType( ast::type::TypesCache & cache
		, uint32_t location
		, ParamsT && ... params )
	{
		return cache.getCallableData( ValueT::makeType( cache, std::forward< ParamsT >( params )... )
			, location );
	}

	template< ast::var::Flag FlagT, typename ValueT >
	void CallableDataBaseT< FlagT, ValueT >::execute( UInt32 const & sbtRecordIndex )
	{
		m_internal.execute( sbtRecordIndex );
	}

	//*********************************************************************************************

	template< ast::var::Flag FlagT, typename ValueT >
	expr::ExprPtr makeExpr( CallableDataBaseT< FlagT, ValueT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
