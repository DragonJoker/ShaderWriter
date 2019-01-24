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
		Break( bool switchCaseBreak );

		void accept( VisitorPtr vis )override;

		bool isSwitchCaseBreak()const
		{
			return m_switchCaseBreak;
		}

	private:
		bool m_switchCaseBreak;
	};
	using BreakPtr = std::unique_ptr< Break >;

	inline BreakPtr makeBreak( bool switchCaseBreak )
	{
		return std::make_unique< Break >( switchCaseBreak );
	}
}

#endif
