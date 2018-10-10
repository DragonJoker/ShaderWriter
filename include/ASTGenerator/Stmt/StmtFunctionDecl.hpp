/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFunctionDecl_H___
#define ___AST_StmtFunctionDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "ASTGenerator/Var/VariableList.hpp"

namespace ast
{
	class StmtFunctionDecl
		: public StmtCompound
	{
	public:
		StmtFunctionDecl( TypePtr retType
			, std::string name
			, VariableList parameters );

		void accept( StmtVisitorPtr vis )override;

		inline TypePtr getRetType()const
		{
			return m_retType;
		}

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline VariableList const & getParameters()const
		{
			return m_parameters;
		}

	private:
		TypePtr m_retType;
		std::string m_name;
		VariableList m_parameters;
	};

	inline std::unique_ptr< StmtFunctionDecl > makeFunctionDeclStmt( TypePtr retType
		, std::string name
		, VariableList parameters )
	{
		return std::make_unique< StmtFunctionDecl >( std::move( retType )
			, std::move( name )
			, std::move( parameters ) );
	}
}

#endif
