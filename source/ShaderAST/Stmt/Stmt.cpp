/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/Stmt.hpp"

namespace ast::stmt
{
	Stmt::Stmt( StmtCache & stmtCache
		, size_t size
		, Kind kind )
		: m_stmtCache{ stmtCache }
		, m_size{ size }
		, m_kind{ kind }
	{
	}
}
