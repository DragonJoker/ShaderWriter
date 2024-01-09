/*
See LICENSE file in root folder
*/
#ifndef ___AST_PerPrimitiveDecl_H___
#define ___AST_PerPrimitiveDecl_H___
#pragma once

#include "Stmt.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class PerPrimitiveDecl
		: public Stmt
	{
	public:
		SDAST_API explicit PerPrimitiveDecl( StmtCache & stmtCache
			, type::TypePtr type );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline type::TypePtr getType()const
		{
			return m_type;
		}

	private:
		type::TypePtr m_type;
	};
}

#endif
