/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvHelpers_H___
#define ___SDW_SpirvHelpers_H___
#pragma once

#include "SpirvOpHelpers.hpp"

#include <ShaderAST/Expr/ExprList.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>

#include <set>
#include <string>
#include <vector>

namespace spirv
{
	struct ModuleConfig
	{
		std::set< spv::Capability > requiredCapabilities;
		std::set< ast::var::VariablePtr > inputs;
		std::set< ast::var::VariablePtr > outputs;
		mutable uint32_t nextVarId{ 0u };
		mutable uint32_t aliasId{ 0u };
	};

	struct IntrinsicConfig
	{
		// Intrinsic
		bool isExtension{ false };
		bool isAtomic{ false };
		// Image
		bool needsTexelPointer{ false };
		// Texture
		uint32_t imageOperandsIndex{ 0u };
		bool needsImage{ false };
		spv::ImageOperandsMask mask{ spv::ImageOperandsMaskNone };
		uint32_t returnComponentsCount{ 0u };
		uint32_t offsetIndex{ 0u };
	};

	struct PreprocContext
	{
		std::map< std::string, ast::expr::ExprPtr > constExprs;
		std::map< std::string, ast::expr::ExprList > constAggrExprs;
	};

	spv::BuiltIn getBuiltin( std::string const & name );
	spv::MemoryModel getMemoryModel();
	spv::ExecutionModel getExecutionModel( ast::ShaderStage kind );
	std::string getTypeName( spv::Op op );
	std::string getOperatorName( spv::Op op );
	std::string getName( spv::Capability value );
	ValueIdList makeBinOpOperands( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs );
	InstructionPtr makeImageTypeInstruction( ast::type::ImageConfiguration const & config
		, ValueId resultId
		, ValueId sampledTypeId );
	InstructionPtr makeBaseTypeInstruction( ast::type::Kind kind
		, ValueId id );
	InstructionPtr makeIntrinsicInstruction( spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeIntrinsicInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeTextureAccessInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeImageAccessInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeCastInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueId operandId );
	InstructionPtr makeUnInstruction( ValueId returnTypeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind typeKind
		, ValueId operand );
	InstructionPtr makeBinInstruction( ValueId returnTypeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs );
	InstructionPtr makeVariableInstruction( ValueId typeId
		, ValueId varId
		, ValueId initialiser = {} );
	ast::expr::ExprPtr makeZero( ast::type::TypesCache & cache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeOne( ast::type::TypesCache & cache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeToBoolCast( ast::type::TypesCache & cache
		, ast::expr::ExprPtr expr );
	ast::expr::ExprPtr makeFromBoolCast( ast::type::TypesCache & cache
		, ast::expr::ExprPtr expr
		, ast::type::Kind dstScalarType );
}

#endif
