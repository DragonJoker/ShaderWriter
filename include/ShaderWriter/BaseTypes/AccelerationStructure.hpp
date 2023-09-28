/*
See LICENSE file in root folder
*/
#ifndef ___SDW_AccelerationStructure_H___
#define ___SDW_AccelerationStructure_H___
#pragma once

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	struct AccelerationStructure
		: public Value
	{
		SDW_API AccelerationStructure( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool writeStmt = true );
		SDW_API explicit AccelerationStructure( Value rhs );

		SDW_API ~AccelerationStructure()override = default;
		SDW_API AccelerationStructure( AccelerationStructure && rhs ) = default;
		SDW_API AccelerationStructure( AccelerationStructure const & rhs ) = default;
		SDW_API AccelerationStructure & operator=( AccelerationStructure && rhs ) = default;
		SDW_API AccelerationStructure & operator=( AccelerationStructure const & rhs ) = default;

		SDW_API static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#endif
