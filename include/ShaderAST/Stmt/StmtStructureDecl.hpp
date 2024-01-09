/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtStructureDecl_H___
#define ___AST_StmtStructureDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class StructureDecl
		: public Stmt
	{
	public:
		SDAST_API explicit StructureDecl( StmtCache & stmtCache
			, type::StructPtr type );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline type::StructPtr getType()const
		{
			return m_type;
		}

	private:
		type::StructPtr m_type;
	};
}

#endif
