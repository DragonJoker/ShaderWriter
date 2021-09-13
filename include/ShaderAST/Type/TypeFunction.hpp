/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeFunction_H___
#define ___AST_TypeFunction_H___
#pragma once

#include "ShaderAST/Var/VariableList.hpp"

#include <vector>

namespace ast::type
{
	class Function
		: public Type
	{
	public:
		SDAST_API Function( TypePtr returnType
			, var::VariableList parameters );

		inline TypePtr getReturnType()const
		{
			return m_returnType;
		}

		inline size_t size()const
		{
			return m_parameters.size();
		}

		inline bool empty()const
		{
			return m_parameters.empty();
		}

		inline auto begin()const
		{
			return m_parameters.begin();
		}

		inline auto end()const
		{
			return m_parameters.end();
		}

		inline auto front()const
		{
			return m_parameters.front();
		}

		inline auto back()const
		{
			return m_parameters.back();
		}

	private:
		TypePtr m_returnType;
		var::VariableList m_parameters;
	};

	SDAST_API size_t getHash( TypePtr returnType
		, var::VariableList const & parameters )noexcept;

	SDAST_API bool operator==( Function const & lhs, Function const & rhs )noexcept;
}

#endif
