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
	ast::type::IOStructPtr VoidT< FlagT >::makeIOType( ast::type::TypesCache & cache
		, ast::EntryPoint entryPoint )
	{
		return cache.getIOStruct( "SDW_Void"
			, entryPoint
			, FlagT );
	}

	//*************************************************************************

	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	EntryTypeT< EntryPointT, FlagT, DataT >::EntryTypeT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr EntryTypeT< EntryPointT, FlagT, DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return DataT< FlagT >::makeIOType( cache
			, EntryPointT
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PatchInT< DataT >::PatchInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: EntryTypeT< ast::EntryPoint::eTessellationEvaluation, FlagT, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr PatchInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return EntryTypeT< ast::EntryPoint::eTessellationEvaluation, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PatchOutT< DataT >::PatchOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: EntryTypeT< ast::EntryPoint::eTessellationControl, FlagT, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr PatchOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return EntryTypeT< ast::EntryPoint::eTessellationControl, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	InputT< EntryPointT, DataT >::InputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: EntryTypeT< EntryPointT, FlagT, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr InputT< EntryPointT, DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return EntryTypeT< EntryPointT, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	OutputT< EntryPointT, DataT >::OutputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: EntryTypeT< EntryPointT, FlagT, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr OutputT< EntryPointT, DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return EntryTypeT< EntryPointT, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	PerTaskT< EntryPointT, FlagT, DataT >::PerTaskT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: EntryTypeT< EntryPointT, ast::var::Flag::ePerTask, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr PerTaskT< EntryPointT, FlagT, DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return EntryTypeT< EntryPointT, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	PerTaskNVT< EntryPointT, FlagT, DataT >::PerTaskNVT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: EntryTypeT< EntryPointT, ast::var::Flag::ePerTaskNV, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::EntryPoint EntryPointT
		, ast::var::Flag FlagT
		, template< ast::var::Flag DataFlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr PerTaskNVT< EntryPointT, FlagT, DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return EntryTypeT< EntryPointT, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}
	/**@}*/
#pragma endregion
}
