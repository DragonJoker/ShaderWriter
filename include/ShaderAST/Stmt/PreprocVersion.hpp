/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocVersion_H___
#define ___AST_PreprocVersion_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocVersion
		: public Stmt
	{
	public:
		SDAST_API explicit PreprocVersion( StmtCache & stmtCache
			, std::string name );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		std::string m_name;
	};
}

#endif
