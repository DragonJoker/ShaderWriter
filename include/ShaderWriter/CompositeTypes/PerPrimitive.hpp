/*
See LICENSE file in root folder
*/
#ifndef ___SDW_PerPrimitive_H___
#define ___SDW_PerPrimitive_H___
#pragma once

#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"

#include <ShaderAST/Stmt/StmtPerPrimitiveDecl.hpp>

namespace sdw
{
	struct PerPrimitive
	{
		SDW_API PerPrimitive( ShaderWriter & writer
			, StructInstance & instance
			, ast::var::Flag flag );

		Int primitiveID;
		Int layer;
		Int viewportIndex;
		Array< Int > viewportMask;

		SDW_API static void fillType( ast::type::IOStruct & structType );
	};
}

#endif
