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
		StructureDecl( type::StructPtr type );

		void accept( VisitorPtr vis )override;

		inline type::StructPtr getType()const
		{
			return m_type;
		}

	private:
		type::StructPtr m_type;
	};
	using StructureDeclPtr = std::unique_ptr< StructureDecl >;

	inline StructureDeclPtr makeStructureDecl( type::StructPtr type )
	{
		return std::make_unique< StructureDecl >( std::move( type ) );
	}
}

#endif
