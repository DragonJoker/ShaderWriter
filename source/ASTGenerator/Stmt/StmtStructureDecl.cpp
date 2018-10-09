/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtStructureDecl.hpp"

namespace ast
{
	StmtStructureDecl::StmtStructureDecl( std::string const & name )
		: StmtCompound{ Kind::eStructureDecl }
	{
	}

	void StmtStructureDecl::add( StmtVariableDeclPtr decl )
	{
		addStmt( std::move( decl ) );
	}
}
