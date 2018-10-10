/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocExtension_H___
#define ___AST_PreprocExtension_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class PreprocExtension
		: public Stmt
	{
	public:
		enum class Status
		{
			eDisabled,
			eEnabled,
			eRequired,
		};

	public:
		PreprocExtension( std::string name
			, Status status );

		void accept( StmtVisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline Status getStatus()const
		{
			return m_status;
		}

	private:
		std::string m_name;
		Status m_status;
	};

	inline std::unique_ptr< PreprocExtension > makePreprocExtension( std::string name
		, PreprocExtension::Status status )
	{
		return std::make_unique< PreprocExtension >( std::move( name )
			, status );
	}
}

#endif
