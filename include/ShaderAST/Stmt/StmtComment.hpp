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
		SDAST_API Comment( std::string text );

		SDAST_API void accept( VisitorPtr vis )override;

		inline std::string const & getText()
		{
			return m_text;
		}

	private:
		std::string m_text;
	};
	using CommentPtr = std::unique_ptr< Comment >;

	inline CommentPtr makeComment( std::string text )
	{
		return std::make_unique< Comment >( std::move( text ) );
	}
}

#endif
