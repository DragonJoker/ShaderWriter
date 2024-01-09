/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskPayloadNV_H___
#define ___SDW_TaskPayloadNV_H___
#pragma once

#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/CompositeTypes/Builtins.hpp"

namespace sdw
{
	struct TaskPayloadNV
	{
		SDW_API TaskPayloadNV( ShaderWriter & writer
			, expr::Expr const * expr
			, bool enabled );

		SDW_API void dispatchMesh( UInt32 taskCount )const;

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
	struct TaskPayloadOutNVT
		: public PerTaskNVT< ast::EntryPoint::eTaskNV, OutputT< ast::EntryPoint::eTaskNV, DataT >::FlagT, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< ast::EntryPoint::eTaskNV, DataT >::FlagT;

		TaskPayloadOutNVT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		template< typename ... ParamsT >
		TaskPayloadOutNVT( ShaderWriter & writer
			, ParamsT && ... params );

		void dispatchMesh( UInt32 taskCount )const;

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

	private:
		TaskPayloadNV m_internal;
	};

	using TaskPayloadOutNV = TaskPayloadOutNVT< VoidT >;
	/**
	*	Holds input data from a task shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TaskPayloadInNVT
		: public PerTaskNVT< ast::EntryPoint::eMeshNV, InputT< ast::EntryPoint::eMeshNV, DataT >::FlagT, DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< ast::EntryPoint::eMeshNV, DataT >::FlagT;

		TaskPayloadInNVT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		template< typename ... ParamsT >
		TaskPayloadInNVT( ShaderWriter & writer
			, ParamsT && ... params );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};

	using TaskPayloadInNV = TaskPayloadInNVT< VoidT >;

	SDW_API expr::ExprPtr makeExpr( TaskPayloadNV const & value );

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadOutNVT< DataT > const & value );

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadInNVT< DataT > const & value );
}

#include "TaskPayloadNV.inl"

#endif
