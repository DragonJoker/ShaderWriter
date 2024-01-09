/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtSpecialisationConstantDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	SpecialisationConstantDecl::SpecialisationConstantDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t location
		, expr::LiteralPtr value )
		: Stmt{ stmtCache, sizeof( SpecialisationConstantDecl ), Kind::eSpecialisationConstantDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
		, m_value{ std::move( value ) }
	{
	}

	void SpecialisationConstantDecl::accept( VisitorPtr vis )const
	{
		vis->visitSpecialisationConstantDeclStmt( this );
	}
}
