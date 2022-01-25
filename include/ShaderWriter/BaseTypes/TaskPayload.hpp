/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskPayload_H___
#define ___SDW_TaskPayload_H___
#pragma once

#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/CompositeTypes/Builtins.hpp"

namespace sdw
{
	struct TaskPayload
	{
		SDW_API TaskPayload( ShaderWriter & writer
			, expr::Expr * expr
			, bool enabled );

		SDW_API void dispatchMesh( UInt taskCount );

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
	/**
	*	Holds output data for a task shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TaskPayloadOutT
		: public PerTaskT< DataT, OutputT< DataT >::FlagT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		TaskPayloadOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		template< typename ... ParamsT >
		TaskPayloadOutT( ShaderWriter & writer
			, ParamsT ... params );

		void dispatchMesh( UInt taskCount );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );

	private:
		TaskPayload m_internal;
	};

	using TaskPayloadOut = TaskPayloadOutT< VoidT >;
	/**
	*	Holds input data from a task shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TaskPayloadInT
		: public PerTaskT< DataT, InputT< DataT >::FlagT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		TaskPayloadInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		template< typename ... ParamsT >
		TaskPayloadInT( ShaderWriter & writer
			, ParamsT ... params );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );
	};

	using TaskPayloadIn = TaskPayloadInT< VoidT >;

	SDW_API expr::ExprPtr makeExpr( TaskPayload const & value );

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadOutT< DataT > const & value );

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadInT< DataT > const & value );
}

#include "TaskPayload.inl"

#endif
