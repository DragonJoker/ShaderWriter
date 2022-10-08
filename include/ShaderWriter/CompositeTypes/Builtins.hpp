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

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache );
	};
	/**
	*	Holds input patch data for shaders.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct PatchInT
		: public DataT< ast::var::Flag::ePatchInput >
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
		: public DataT< ast::var::Flag::ePatchOutput >
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
	template< template< ast::var::Flag FlagT > typename DataT >
	struct InputT
		: public DataT< ast::var::Flag::eShaderInput >
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
	template< template< ast::var::Flag FlagT > typename DataT >
	struct OutputT
		: public DataT< ast::var::Flag::eShaderOutput >
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
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::var::Flag FlagT >
	struct PerTaskT
		: public DataT< ast::var::Flag::ePerTask >
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
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::var::Flag FlagT >
	struct PerTaskNVT
		: public DataT< ast::var::Flag::ePerTaskNV >
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
