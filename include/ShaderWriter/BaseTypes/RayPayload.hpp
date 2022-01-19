/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayPayload_H___
#define ___SDW_RayPayload_H___
#pragma once

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	struct RayPayload
	{
		SDW_API RayPayload( ShaderWriter & writer
			, expr::Expr * expr
			, bool enabled );

		SDW_API void traceRay( AccelerationStructure const & topLevel
			, UInt const & rayFlags
			, UInt const & cullMask
			, UInt const & sbtRecordOffset
			, UInt const & sbtRecordStride
			, UInt const & missIndex
			, Vec3 const & origin
			, Float const & Tmin
			, Vec3 const & direction
			, Float const & Tmax );

		ShaderWriter * getWriter()const
		{
			return m_plWriter;
		}

		ast::expr::Expr * getExpr()const
		{
			return m_plExpr;
		}

		bool isEnabled()const
		{
			return m_plEnabled;
		}

	private:
		ShaderWriter * m_plWriter;
		expr::Expr * m_plExpr;
		bool m_plEnabled;
	};

	template< ast::var::Flag FlagT, typename ValueT >
	struct RayPayloadBaseT
		: public ValueT
	{
		SDW_DeclValue( , RayPayloadBaseT );

		template< typename ... ParamsT >
		RayPayloadBaseT( ShaderWriter & writer
			, uint32_t location
			, ParamsT ... params );
		RayPayloadBaseT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		RayPayloadBaseT & operator=( ValueT const & rhs );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, uint32_t location
			, ParamsT ... params );

		void traceRay( AccelerationStructure const & topLevel
			, UInt const & rayFlags
			, UInt const & cullMask
			, UInt const & sbtRecordOffset
			, UInt const & sbtRecordStride
			, UInt const & missIndex
			, Vec3 const & origin
			, Float const & Tmin
			, Vec3 const & direction
			, Float const & Tmax );

	private:
		RayPayload m_internal;
	};

	SDW_API expr::ExprPtr makeExpr( RayPayload const & value );

	template< ast::var::Flag FlagT, typename ValueT >
	expr::ExprPtr makeExpr( RayPayloadBaseT< FlagT, ValueT > const & value );
}

#include "RayPayload.inl"

#endif
