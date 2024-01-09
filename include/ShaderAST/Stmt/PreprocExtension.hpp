/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocExtension_H___
#define ___AST_PreprocExtension_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocExtension
		: public Stmt
	{
	public:
		enum class ExtStatus
		{
			eDisabled,
			eEnabled,
			eRequired,
		};

	public:
		SDAST_API PreprocExtension( StmtCache & stmtCache
			, std::string name
			, ExtStatus status );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline ExtStatus getStatus()const
		{
			return m_status;
		}

	private:
		std::string m_name;
		ExtStatus m_status;
	};
}

#endif
