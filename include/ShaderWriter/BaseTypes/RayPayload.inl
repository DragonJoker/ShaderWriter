/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/RayPayload.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	//*********************************************************************************************

	template< ast::var::Flag FlagT, typename ValueT >
	template< typename ... ParamsT >
	RayPayloadBaseT< FlagT, ValueT >::RayPayloadBaseT( ShaderWriter & writer
		, uint32_t location
		, ParamsT ... params )
		: RayPayloadBaseT{ writer
			, makeExpr( writer
				, sdw::registerName( writer
					, FlagT == ast::var::Flag::eShaderInput ? std::string{ "payloadIn" } : std::string{ "payload" }
					, makeType( getTypesCache( writer )
						, location
						, std::forward< ParamsT >( params )... )
					, FlagT | ( FlagT == ast::var::Flag::eShaderInput ? ast::var::Flag::eIncomingRayPayload : ast::var::Flag::eRayPayload ) ) )
			, true }
	{
		if ( auto structType = getStructType( this->getType() ) )
		{
			addStmt( writer, sdw::makeStructDecl( structType ) );
		}

		addStmt( writer
			, sdw::makeInOutRayPayloadVariableDecl( ast::findIdentifier( this->getExpr() )->getVariable(), location ) );
	}

	template< ast::var::Flag FlagT, typename ValueT >
	RayPayloadBaseT< FlagT, ValueT >::RayPayloadBaseT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, std::move( expr ), enabled }
		, m_internal{ writer, ValueT::getExpr(), enabled }
	{
	}

	template< ast::var::Flag FlagT, typename ValueT >
	RayPayloadBaseT< FlagT, ValueT > & RayPayloadBaseT< FlagT, ValueT >::operator=( ValueT const & rhs )
	{
		ValueT::operator=( rhs );
		return *this;
	}

	template< ast::var::Flag FlagT, typename ValueT >
	template< typename ... ParamsT >
	ast::type::TypePtr RayPayloadBaseT< FlagT, ValueT >::makeType( ast::type::TypesCache & cache
		, uint32_t location
		, ParamsT ... params )
	{
		return cache.getRayPayload( ValueT::makeType( cache, std::forward< ParamsT >( params )... )
			, location );
	}

	template< ast::var::Flag FlagT, typename ValueT >
	void RayPayloadBaseT< FlagT, ValueT >::traceRay( AccelerationStructure const & topLevel
		, UInt const & rayFlags
		, UInt const & cullMask
		, UInt const & sbtRecordOffset
		, UInt const & sbtRecordStride
		, UInt const & missIndex
		, Vec3 const & origin
		, Float const & Tmin
		, Vec3 const & direction
		, Float const & Tmax )
	{
		m_internal.traceRay( topLevel
			, rayFlags
			, cullMask
			, sbtRecordOffset
			, sbtRecordStride
			, missIndex
			, origin
			, Tmin
			, direction
			, Tmax );
	}

	//*********************************************************************************************

	template< ast::var::Flag FlagT, typename ValueT >
	expr::ExprPtr makeExpr( RayPayloadBaseT< FlagT, ValueT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
