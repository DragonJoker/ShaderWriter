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
		PushConstantsBufferDecl( std::string name
			, type::MemoryLayout layout );
		void add( VariableDeclPtr decl );

		void accept( VisitorPtr vis )override;

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
	using PushConstantsBufferDeclPtr = std::unique_ptr< PushConstantsBufferDecl >;

	inline PushConstantsBufferDeclPtr makePushConstantsBufferDecl( std::string name
		, type::MemoryLayout layout )
	{
		return std::make_unique< PushConstantsBufferDecl >( std::move( name )
			, layout );
	}
}

#endif
