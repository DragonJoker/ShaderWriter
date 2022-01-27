/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Void.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>

namespace sdw
{
	Void::Void( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool writeStmt )
		: Value{ writer, std::move( expr ), true }
	{
		if ( writeStmt )
		{
			getShader()->addStmt( sdw::makeSimple( makeExpr( *this ) ) );
		}
	}

	Void::Void( Value rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Void::Void()
		: Void{ 0_i }
	{
	}

	ast::type::TypePtr Void::makeType( ast::type::TypesCache & cache )
	{
		return cache.getVoid();
	}
}
