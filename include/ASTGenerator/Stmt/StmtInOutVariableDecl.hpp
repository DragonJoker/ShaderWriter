/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInOutVariableDecl_H___
#define ___AST_StmtInOutVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class StmtInOutVariableDecl
		: public Stmt
	{
	public:
		enum class Direction
		{
			eIn = 1,
			eOut = 2,
			eInOut = 3,
		};

	public:
		StmtInOutVariableDecl( VariablePtr variable
			, uint32_t location
			, Direction direction );

		void accept( StmtVisitorPtr vis )override;

		inline Variable const & getVariable()const
		{
			return *m_variable;
		}

		inline uint32_t getLocation()const
		{
			return m_location;
		}

		inline Direction getDirection()const
		{
			return m_direction;
		}

	private:
		VariablePtr m_variable;
		uint32_t m_location;
		Direction m_direction;
	};

	inline std::unique_ptr< StmtInOutVariableDecl > makeInOutVariableDeclStmt( VariablePtr variable
		, uint32_t location
		, StmtInOutVariableDecl::Direction direction )
	{
		return std::make_unique< StmtInOutVariableDecl >( std::move( variable )
			, location
			, direction );
	}
}

#endif
