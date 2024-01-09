/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CallableData_H___
#define ___SDW_CallableData_H___
#pragma once

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	struct CallableData
	{
		SDW_API CallableData( ShaderWriter & writer
			, expr::Expr const * expr
			, bool enabled );

		SDW_API void execute( UInt32 const & sbtRecordIndex )const;

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
	struct CallableDataBaseT
		: public ValueT
	{
		SDW_DeclValue( , CallableDataBaseT );

		template< typename ... ParamsT >
		CallableDataBaseT( ShaderWriter & writer
			, uint32_t location
			, ParamsT && ... params );
		CallableDataBaseT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		CallableDataBaseT & operator=( ValueT const & rhs );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, uint32_t location
			, ParamsT && ... params );

		void execute( UInt32 const & sbtRecordIndex );

	private:
		CallableData m_internal;
	};

	SDW_API expr::ExprPtr makeExpr( CallableData const & value );

	template< ast::var::Flag FlagT, typename ValueT >
	expr::ExprPtr makeExpr( CallableDataBaseT< FlagT, ValueT > const & value );
}

#include "CallableData.inl"

#endif
