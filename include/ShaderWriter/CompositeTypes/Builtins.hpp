/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Builtins_H___
#define ___SDW_Builtins_H___

#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/CompositeTypes/PerVertex.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"
#include "ShaderWriter/VecTypes/Vec3.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
#pragma region Shader I/O
	/**
	*name
	*	I/O.
	*/
	/**@{*/
	/**
	*	Placeholder for I/O empty types.
	*/
	template< ast::var::Flag FlagT >
	struct VoidT
		: public StructInstance
	{
		VoidT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache
			, ast::EntryPoint entryPoint );
	};
	/**
	*	Entry point type.
	*/
	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	struct EntryTypeT
		: public DataT< FlagT >
	{
		EntryTypeT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		
		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};
	/**
	*	Holds input patch data for shaders.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct PatchInT
		: public EntryTypeT< ast::EntryPoint::eTessellationEvaluation, ast::var::Flag::ePatchInput, DataT >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::ePatchInput;

		PatchInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};
	/**
	*	Holds output patch data for shaders.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct PatchOutT
		: public EntryTypeT< ast::EntryPoint::eTessellationControl, ast::var::Flag::ePatchOutput, DataT >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::ePatchOutput;

		PatchOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};
	/**
	*	Holds input data for shaders.
	*/
	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	struct InputT
		: public EntryTypeT< EntryPointT, ast::var::Flag::eShaderInput, DataT >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		InputT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};
	/**
	*	Holds output data for shaders.
	*/
	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	struct OutputT
		: public EntryTypeT< EntryPointT, ast::var::Flag::eShaderOutput, DataT >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderOutput;

		OutputT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};
	/**
	*	Holds output data for shaders.
	*/
	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	struct PerTaskT
		: public EntryTypeT< EntryPointT, ast::var::Flag::ePerTask, DataT >
	{
		PerTaskT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};
	/**
	*	Holds output data for shaders.
	*/
	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	struct PerTaskNVT
		: public EntryTypeT< EntryPointT, ast::var::Flag::ePerTaskNV, DataT >
	{
		PerTaskNVT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};
	/**@}*/
#pragma endregion
}

#include "Builtins.inl"

#endif
