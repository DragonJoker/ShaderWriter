/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Void.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>

namespace sdw
{
	Void::Void( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
		shader->addStmt( stmt::makeSimple( sdw::makeExpr( *this ) ) );
	}

	Void::Void( Void && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Void::Void( Void const & rhs )
		: Value{ rhs }
	{
	}

	Void::Void( Value rhs )
		: Value{ std::move( rhs ) }
	{
	}

	ast::type::TypePtr Void::makeType( ast::type::TypesCache & cache )
	{
		return cache.getVoid();
	}
}
