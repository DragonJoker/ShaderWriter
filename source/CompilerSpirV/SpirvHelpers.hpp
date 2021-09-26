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
	IdList makeBinOpOperands( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs );
	InstructionPtr makeImageTypeInstruction( ast::type::ImageConfiguration const & config
		, spv::Id resultId
		, spv::Id sampledTypeId );
	InstructionPtr makeBaseTypeInstruction( ast::type::Kind kind
		, spv::Id id );
	InstructionPtr makeIntrinsicInstruction( spv::Op op
		, IdList const & operands );
	InstructionPtr makeIntrinsicInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands );
	InstructionPtr makeTextureAccessInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands );
	InstructionPtr makeImageAccessInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands );
	InstructionPtr makeCastInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, spv::Id operandId );
	InstructionPtr makeUnInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind typeKind
		, spv::Id operand );
	InstructionPtr makeBinInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs );
	ast::expr::ExprPtr makeZero( ast::type::TypesCache & cache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeOne( ast::type::TypesCache & cache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeToBoolCast( ast::type::TypesCache & cache
		, ast::expr::ExprPtr expr );
	ast::expr::ExprPtr makeFromBoolCast( ast::type::TypesCache & cache
		, ast::expr::ExprPtr expr
		, ast::type::Kind dstScalarType );
	ast::var::VariablePtr createTmpVar( ast::type::TypePtr type
		, uint32_t & currentId );
	bool makeAlias( ast::stmt::Container * container
		, ast::expr::ExprPtr expr
		, bool param
		, ast::expr::ExprPtr & aliasExpr
		, ast::var::VariablePtr & aliasVar
		, uint32_t & currentId
		, bool force = false );
}

#endif
