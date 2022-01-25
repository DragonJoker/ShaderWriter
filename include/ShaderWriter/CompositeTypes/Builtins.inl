/*
See LICENSE file in root folder
*/
#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Expr/ExprStreamAppend.hpp>
#include <ShaderAST/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region I/O
	/**
	*name
	*	I/O.
	*/
	/**@{*/
	template< ast::var::Flag FlagT >
	VoidT< FlagT >::VoidT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::var::Flag FlagT >
	ast::type::IOStructPtr VoidT< FlagT >::makeIOType( ast::type::TypesCache & cache )
	{
		return cache.getIOStruct( ast::type::MemoryLayout::eC
			, "SDW_Void"
				+ ( FlagT == ast::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } )
			, FlagT );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PatchInT< DataT >::PatchInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr PatchInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return DataT< FlagT >::makeIOType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PatchOutT< DataT >::PatchOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr PatchOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return DataT< FlagT >::makeIOType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	InputT< DataT >::InputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr InputT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return DataT< FlagT >::makeIOType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	OutputT< DataT >::OutputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr OutputT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return DataT< FlagT >::makeIOType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::var::Flag FlagT >
	PerTaskT< DataT, FlagT >::PerTaskT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< ast::var::Flag::ePerTask >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::var::Flag FlagT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr PerTaskT< DataT, FlagT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return DataT< FlagT >::makeIOType( cache
			, std::forward< ParamsT >( params )... );
	}
	/**@}*/
#pragma endregion
}
