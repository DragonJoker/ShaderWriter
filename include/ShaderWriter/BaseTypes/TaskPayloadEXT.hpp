/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskPayloadEXT_H___
#define ___SDW_TaskPayloadEXT_H___
#pragma once

#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/CompositeTypes/Builtins.hpp"

namespace sdw
{
	struct TaskPayloadEXT
	{
		SDW_API TaskPayloadEXT( ShaderWriter & writer
			, expr::Expr const * expr
			, bool enabled );

		SDW_API void dispatchMesh( UInt32 const taskCountX
			, UInt32 const taskCountY
			, UInt32 const taskCountZ )const;

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
	/**
	*	Holds output data for a task shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TaskPayloadOutEXTT
		: public PerTaskT< ast::EntryPoint::eTask, OutputT< ast::EntryPoint::eTask, DataT >::FlagT, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< ast::EntryPoint::eTask, DataT >::FlagT;

		TaskPayloadOutEXTT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		template< typename ... ParamsT >
		TaskPayloadOutEXTT( ShaderWriter & writer
			, ParamsT && ... params );

		void dispatchMesh( UInt32 taskCountX
			, UInt32 taskCountY
			, UInt32 taskCountZ )const;

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

	private:
		TaskPayloadEXT m_internal;
	};

	using TaskPayloadOutEXT = TaskPayloadOutEXTT< VoidT >;
	/**
	*	Holds input data from a task shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TaskPayloadInEXTT
		: public PerTaskT< ast::EntryPoint::eMesh, InputT< ast::EntryPoint::eMesh, DataT >::FlagT, DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< ast::EntryPoint::eMesh, DataT >::FlagT;

		TaskPayloadInEXTT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		template< typename ... ParamsT >
		TaskPayloadInEXTT( ShaderWriter & writer
			, ParamsT && ... params );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};

	using TaskPayloadInEXT = TaskPayloadInEXTT< VoidT >;

	SDW_API expr::ExprPtr makeExpr( TaskPayloadEXT const & value );

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadOutEXTT< DataT > const & value );

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadInEXTT< DataT > const & value );
}

#include "TaskPayloadEXT.inl"

#endif
