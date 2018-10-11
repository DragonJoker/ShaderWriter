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
		PreprocVersion( std::string name );

		void accept( VisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		std::string m_name;
	};
	using PreprocVersionPtr = std::unique_ptr< PreprocVersion >;

	inline PreprocVersionPtr makePreprocVersion( std::string name )
	{
		return std::make_unique< PreprocVersion >( std::move( name ) );
	}
}

#endif
