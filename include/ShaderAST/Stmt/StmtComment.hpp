/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtComment_H___
#define ___AST_StmtComment_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class Comment
		: public Stmt
	{
	public:
		SDAST_API explicit Comment( StmtCache & stmtCache
			, std::string text );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline std::string const & getText()const noexcept
		{
			return m_text;
		}

	private:
		std::string m_text;
	};
}

#endif
