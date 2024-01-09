/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtBufferReferenceDecl_H___
#define ___AST_StmtBufferReferenceDecl_H___
#pragma once

#include "Stmt.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class BufferReferenceDecl
		: public Stmt
	{
	public:
		SDAST_API explicit BufferReferenceDecl( StmtCache & stmtCache
			, type::TypePtr type );

		SDAST_API void accept( VisitorPtr vis )const override;

		type::TypePtr getType()const
		{
			return m_type;
		}

	private:
		type::TypePtr m_type;
	};
}

#endif
