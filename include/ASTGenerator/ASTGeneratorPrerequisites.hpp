/*
See LICENSE file in root folder
*/
#ifndef ___AST_Prerequisites_H___
#define ___AST_Prerequisites_H___
#pragma once

#include <cassert>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace ast
{
	class Expr;
	class Stmt;
	class Variable;
	class ExprVisitor;
	class StmtVisitor;

	using ExprPtr = std::unique_ptr< Expr >;
	using StmtPtr = std::unique_ptr< Stmt >;
	using VariablePtr = std::shared_ptr< Variable >;
	using ExprVisitorPtr = ExprVisitor *;
	using StmtVisitorPtr = StmtVisitor *;

	enum class Type
		: uint8_t
	{
		eUndefined,
		eFunction,
		eBoolean,
		eInt,
		eUInt,
		eFloat,
		eVec2B,
		eVec3B,
		eVec4B,
		eVec2I,
		eVec3I,
		eVec4I,
		eVec2UI,
		eVec3UI,
		eVec4UI,
		eVec2F,
		eVec3F,
		eVec4F,
		eMat2x2B,
		eMat3x3B,
		eMat4x4B,
		eMat2x2I,
		eMat3x3I,
		eMat4x4I,
		eMat2x2UI,
		eMat3x3UI,
		eMat4x4UI,
		eMat2x2F,
		eMat3x3F,
		eMat4x4F,
		eConstantsBuffer,
		eShaderBuffer,
		eSamplerBuffer,
		eSampler1D,
		eSampler2D,
		eSampler3D,
		eSamplerCube,
		eSampler2DRect,
		eSampler1DArray,
		eSampler2DArray,
		eSamplerCubeArray,
		eSampler1DShadow,
		eSampler2DShadow,
		eSamplerCubeShadow,
		eSampler2DRectShadow,
		eSampler1DArrayShadow,
		eSampler2DArrayShadow,
		eSamplerCubeArrayShadow,
		eCount,
		eMin = eUndefined,
		eMax = eSamplerCubeArrayShadow,
	};
}

#endif
