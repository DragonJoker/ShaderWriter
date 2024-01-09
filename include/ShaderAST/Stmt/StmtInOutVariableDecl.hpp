/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInOutVariableDecl_H___
#define ___AST_StmtInOutVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class InOutVariableDecl
		: public Stmt
	{
	public:
		SDAST_API InOutVariableDecl( StmtCache & stmtCache
			, var::VariablePtr variable
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t blendIndex );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		inline uint32_t getLocation()const
		{
			return m_location;
		}

		inline uint32_t getStreamIndex()const
		{
			return m_streamIndex;
		}

		inline uint32_t getBlendIndex()const
		{
			return m_blendIndex;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_location;
		uint32_t m_streamIndex;
		uint32_t m_blendIndex;
	};
}

#endif
