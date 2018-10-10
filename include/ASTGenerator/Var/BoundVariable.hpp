/*
See LICENSE file in root folder
*/
#ifndef ___AST_BoundVariable_H___
#define ___AST_BoundVariable_H___
#pragma once

#include "Variable.hpp"

namespace ast
{
	class BoundVariable
		: public Variable
	{
	public:
		BoundVariable( Type type
			, std::string name
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		inline uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		inline uint32_t getBindingSet()const
		{
			return m_bindingSet;
		}

	private:
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using BoundVariablePtr = std::shared_ptr< BoundVariable >;
}

#endif
