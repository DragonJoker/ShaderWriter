/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtBreak_H___
#define ___AST_StmtBreak_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class Break
		: public Stmt
	{
	public:
		SDAST_API explicit Break( StmtCache & stmtCache
			, bool switchCaseBreak );

		SDAST_API void accept( VisitorPtr vis )const override;

		bool isSwitchCaseBreak()const
		{
			return m_switchCaseBreak;
		}

	private:
		bool m_switchCaseBreak;
	};
}

#endif
