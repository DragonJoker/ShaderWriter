/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFunctionDecl_H___
#define ___AST_StmtFunctionDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "ASTGenerator/Var/VariableList.hpp"

namespace ast::stmt
{
	class FunctionDecl
		: public Compound
	{
	public:
		FunctionDecl( type::TypePtr retType
			, std::string name
			, var::VariableList parameters );

		void accept( VisitorPtr vis )override;

		inline type::TypePtr getRet()const
		{
			return m_retType;
		}

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline var::VariableList const & getParameters()const
		{
			return m_parameters;
		}

	private:
		type::TypePtr m_retType;
		std::string m_name;
		var::VariableList m_parameters;
	};
	using FunctionDeclPtr = std::unique_ptr< FunctionDecl >;

	inline FunctionDeclPtr makeFunctionDecl( type::TypePtr retType
		, std::string name
		, var::VariableList parameters )
	{
		return std::make_unique< FunctionDecl >( std::move( retType )
			, std::move( name )
			, std::move( parameters ) );
	}
}

#endif
