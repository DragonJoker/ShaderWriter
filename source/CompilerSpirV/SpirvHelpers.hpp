/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvHelpers_H___
#define ___SDW_SpirvHelpers_H___
#pragma once

#include "SpirvOpHelpers.hpp"

#include <set>
#include <string>
#include <vector>

namespace spirv
{
	struct LoadedVariable
	{
		spv::Id varId;
		spv::Id loadedId;
	};

	using LoadedVariableArray = std::vector< LoadedVariable >;

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
		std::map< std::string, ast::expr::Expr * > defines;
	};

	spv::MemoryModel getMemoryModel();
	spv::ExecutionModel getExecutionModel( sdw::ShaderType kind );
	std::string getTypeName( spv::Op op );
	std::string getOperatorName( spv::Op op );
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
}

#endif
