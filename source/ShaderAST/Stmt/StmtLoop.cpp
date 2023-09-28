/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtLoop.hpp"

namespace ast::stmt
{
	Loop::Loop( StmtCache & stmtCache
		, size_t size
		, Kind kind )
		: Compound{ stmtCache, size, kind }
	{
	}
}
