/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayPayload_H___
#define ___SDW_RayPayload_H___
#pragma once

#include "ShaderWriter/Value.hpp"
#include "ShaderWriter/CompositeTypes/RayDesc.hpp"

namespace sdw
{
	struct RayPayload
	{
		SDW_API RayPayload( ShaderWriter & writer
			, expr::Expr const * expr
			, bool enabled );

		SDW_API void traceRay( AccelerationStructure const topLevel
			, UInt32 const rayFlags
			, UInt32 const cullMask
			, UInt32 const sbtRecordOffset
			, UInt32 const sbtRecordStride
			, UInt32 const missIndex
			, RayDesc const rayDesc )const;

		ShaderWriter * getWriter()const
		{
			return m_plWriter;
		}

		ast::expr::Expr const * getExpr()const
		{
			return m_plExpr;
		}

		bool isEnabled()const
		{
			return m_plEnabled;
		}

	private:
		ShaderWriter * m_plWriter;
		expr::Expr const * m_plExpr;
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
			, ParamsT && ... params );
		RayPayloadBaseT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		RayPayloadBaseT & operator=( ValueT const & rhs );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, uint32_t location
			, ParamsT && ... params );

		void traceRay( AccelerationStructure const topLevel
			, UInt32 const rayFlags
			, UInt32 const cullMask
			, UInt32 const sbtRecordOffset
			, UInt32 const sbtRecordStride
			, UInt32 const missIndex
			, RayDesc const rayDesc );

	private:
		RayPayload m_internal;
	};

	SDW_API expr::ExprPtr makeExpr( RayPayload const & value );

	template< ast::var::Flag FlagT, typename ValueT >
	expr::ExprPtr makeExpr( RayPayloadBaseT< FlagT, ValueT > const & value );
}

#include "RayPayload.inl"

#endif
