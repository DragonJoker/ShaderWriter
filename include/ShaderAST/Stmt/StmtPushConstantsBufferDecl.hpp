/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtPushConstantsBufferDecl_H___
#define ___AST_StmtPushConstantsBufferDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

namespace ast::stmt
{
	class PushConstantsBufferDecl
		: public Compound
	{
	public:
		PushConstantsBufferDecl( std::string name );
		void add( VariableDeclPtr decl );

		void accept( VisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		using Compound::addStmt;

	private:
		std::string m_name;
	};
	using PushConstantsBufferDeclPtr = std::unique_ptr< PushConstantsBufferDecl >;

	inline PushConstantsBufferDeclPtr makePushConstantsBufferDecl( std::string name )
	{
		return std::make_unique< PushConstantsBufferDecl >( std::move( name ) );
	}
}

#endif
