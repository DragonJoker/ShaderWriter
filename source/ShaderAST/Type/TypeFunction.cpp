/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeFunction.hpp"

#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"
#include "ShaderAST/Var/Variable.hpp"

#include <algorithm>

namespace ast::type
{
	//*************************************************************************

	Function::Function( TypePtr returnType
		, var::VariableList parameters )
		: Type{ returnType->getTypesCache(), Kind::eFunction }
		, m_returnType{ std::move( returnType ) }
		, m_parameters{ std::move( parameters ) }
	{
	}

	//*************************************************************************

	size_t getHash( TypePtr returnType
		, var::VariableList const & parameters )noexcept
	{
		size_t result = std::hash< TypePtr >{}( returnType );

		for ( auto & parameter : parameters )
		{
			result = hashCombine( result, parameter->getType() );
			result = hashCombine( result, parameter->getName() );
			result = hashCombine( result, parameter->isParam() );
			result = hashCombine( result, parameter->isInputParam() );
			result = hashCombine( result, parameter->isOutputParam() );
		}

		return result;
	}

	bool operator==( Function const & lhs, Function const & rhs )noexcept
	{
		auto result = static_cast< Type const & >( *lhs.getReturnType() ) == static_cast< Type const & >( *rhs.getReturnType() )
			&& lhs.size() == rhs.size();
		auto itl = lhs.begin();
		auto itr = rhs.begin();

		while ( result && itl != lhs.end() )
		{
			auto & lhsVar = *itl;
			auto & rhsVar = *itr;
			result = lhsVar->getType()->getKind() == rhsVar->getType()->getKind()
				&& lhsVar->getName() == rhsVar->getName()
				&& lhsVar->isParam() == rhsVar->isParam()
				&& lhsVar->isInputParam() == rhsVar->isInputParam()
				&& lhsVar->isOutputParam() == rhsVar->isOutputParam();

			if ( result )
			{
				if ( lhsVar->getType()->getKind() == Kind::eStruct
					|| lhsVar->getType()->getKind() == Kind::eRayDesc )
				{
					result = static_cast< Struct const & >( *lhsVar->getType() ) == static_cast< Struct const & >( *rhsVar->getType() );
				}
				else
				{
					result = *lhsVar->getType() == *rhsVar->getType();
				}
			}

			++itl;
			++itr;
		}

		return result;
	}

	//*************************************************************************
}
