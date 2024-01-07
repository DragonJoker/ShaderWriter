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
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	Void::Void( ReturnWrapperT< Void > const & rhs )
		: Void{ *rhs.getWriter(), makeExpr( rhs ), rhs.isEnabled() }
	{
		addStmt( *this->getWriter(), sdw::makeSimple( getStmtCache( m_writer )
			, makeExpr( *this ) ) );
	}

	Void::Void()
		: Void{ sdw::getCurrentWriter(), makeExpr( sdw::getCurrentWriter(), 0 ), true }
	{
	}

	ast::type::TypePtr Void::makeType( ast::type::TypesCache & cache )
	{
		return cache.getVoid();
	}
}
