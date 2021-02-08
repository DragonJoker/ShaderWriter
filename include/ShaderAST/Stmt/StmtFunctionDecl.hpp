/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFunctionDecl_H___
#define ___AST_StmtFunctionDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "ShaderAST/Var/VariableList.hpp"

namespace ast::stmt
{
	class FunctionDecl
		: public Compound
	{
	public:
		SDAST_API FunctionDecl( type::FunctionPtr type
			, std::string name );

		SDAST_API void accept( VisitorPtr vis )override;

		inline type::FunctionPtr getType()const
		{
			return m_type;
		}

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		type::FunctionPtr m_type;
		std::string m_name;
	};
	using FunctionDeclPtr = std::unique_ptr< FunctionDecl >;

	inline FunctionDeclPtr makeFunctionDecl( type::FunctionPtr type
		, std::string name )
	{
		return std::make_unique< FunctionDecl >( std::move( type )
			, std::move( name ) );
	}
}

#endif
