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
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::var::Flag FlagT >
	ast::type::TypePtr VoidT< FlagT >::makeType( ast::type::TypesCache & cache )
	{
		return Void::makeType( cache );
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
	ast::type::TypePtr PatchInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
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
	ast::type::TypePtr PatchOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
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
	ast::type::TypePtr InputT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
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
	ast::type::TypePtr OutputT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
}
