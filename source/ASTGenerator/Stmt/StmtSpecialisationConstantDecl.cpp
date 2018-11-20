/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSpecialisationConstantDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	SpecialisationConstantDecl::SpecialisationConstantDecl( var::VariablePtr variable
		, uint32_t location
		, expr::LiteralPtr value )
		: Stmt{ Kind::eSpecialisationConstantDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
		, m_value{ std::move( value ) }
	{
	}

	void SpecialisationConstantDecl::accept( VisitorPtr vis )
	{
		vis->visitSpecialisationConstantDeclStmt( this );
	}
}
