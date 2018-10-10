/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocVersion_H___
#define ___AST_PreprocVersion_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class PreprocVersion
		: public Stmt
	{
	public:
		PreprocVersion( std::string name );

		void accept( StmtVisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		std::string m_name;
	};

	inline std::unique_ptr< PreprocVersion > makePreprocVersion( std::string name )
	{
		return std::make_unique< PreprocVersion >( std::move( name ) );
	}
}

#endif
