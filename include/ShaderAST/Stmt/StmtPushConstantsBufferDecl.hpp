/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtPushConstantsBufferDecl_H___
#define ___AST_StmtPushConstantsBufferDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class PushConstantsBufferDecl
		: public Compound
	{
	public:
		SDAST_API PushConstantsBufferDecl( StmtCache & stmtCache
			, std::string name
			, type::MemoryLayout layout );
		SDAST_API void add( VariableDeclPtr decl );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline type::MemoryLayout getMemoryLayout()const
		{
			return m_layout;
		}

	private:
		using Compound::addStmt;

	private:
		std::string m_name;
		type::MemoryLayout m_layout;
	};
}

#endif
