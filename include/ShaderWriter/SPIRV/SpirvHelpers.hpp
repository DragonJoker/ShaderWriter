/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvHelpers_H___
#define ___SDW_SpirvHelpers_H___
#pragma once

#include "SpirvOpHelpers.hpp"

#include <optional>
#include <string>
#include <vector>

namespace sdw::spirv
{
	struct PreprocContext
	{
		std::map< std::string, expr::Expr * > defines;
	};

	spv::MemoryModel getMemoryModel();
	spv::ExecutionModel getExecutionModel( ShaderType kind );
	std::string getTypeName( spv::Op op );
	std::string getOperatorName( spv::Op op );
	std::string getLocationName( var::Variable const & var );
	std::string getDirectionName( var::Variable const & var );
	std::string getStatusName( stmt::PreprocExtension::Status status );

	Instruction makeExtension( std::string const & name );
	Instruction makeName( spv::Op op
		, spv::Id id
		, std::string const & name );
	Instruction makeName( spv::Op op
		, spv::Id outerId
		, spv::Id memberIndex
		, std::string const & name );
	Instruction makeType( type::Kind kind
		, spv::Id id );
	Instruction makeType( type::Kind kind
		, spv::Id id
		, IdList const & subTypes );
	Instruction makeImageType( type::ImageConfiguration const & config
		, spv::Id id
		, spv::Id sampledTypeId );
	Instruction makeSamplerType( spv::Id id );
	Instruction makeSampledImageType( spv::Id id
		, spv::Id imgTypeId );
	Instruction makeStructType( spv::Id id
		, IdList const & subTypes );
	Instruction makeArrayType( type::Kind kind
		, spv::Id id
		, spv::Id elementTypeId );
	Instruction makeArrayType( type::Kind kind
		, spv::Id id
		, spv::Id elementTypeId
		, spv::Id lengthId );
	Instruction makeSwitch( spv::Id selector
		, spv::Id defaultId
		, std::map< int64_t, spv::Id > const & cases );
	Instruction makeVariable( spv::Id resultId
		, spv::Id typeId
		, spv::StorageClass storage );
	Instruction makeVariable( spv::Id resultId
		, spv::Id typeId
		, spv::StorageClass storage
		, spv::Id initialiser );
	Instruction makeAccessChain( spv::Op op
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & accessChain );
	Instruction makeVectorShuffle( spv::Id resultId
		, spv::Id typeId
		, spv::Id vector
		, std::vector< uint32_t >const & components );
	Instruction makeVectorShuffle( spv::Id resultId
		, spv::Id typeId
		, spv::Id vector1
		, spv::Id vector2
		, std::vector< uint32_t >const & components );

	Instruction makeInstruction( spv::Op op );
	Instruction makeInstruction( spv::Op op
		, spv::Id resultId );
	Instruction makeInstruction( spv::Op op
		, spv::Id resultId
		, spv::Id typeId );
	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind );
	Instruction makeInstruction( expr::ImageAccess kind );
	Instruction makeInstruction( expr::TextureAccess kind );

	Instruction makeInstruction( spv::Op op
		, IdList const & operands );
	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, IdList const & operands );
	Instruction makeInstruction( expr::ImageAccess kind
		, IdList operands );
	Instruction makeInstruction( expr::TextureAccess kind
		, IdList operands );

	Instruction makeInstruction( spv::Op op
		, IdList const & operands
		, std::string const & name );
	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, IdList const & operands
		, std::string const & name );
	Instruction makeInstruction( expr::ImageAccess kind
		, IdList operands
		, std::string const & name );
	Instruction makeInstruction( expr::TextureAccess kind
		, IdList operands
		, std::string const & name );

	Instruction makeInstruction( spv::Op op
		, spv::Id resultId
		, IdList const & operands );
	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, IdList const & operands );
	Instruction makeInstruction( expr::ImageAccess kind
		, spv::Id resultId
		, IdList operands );
	Instruction makeInstruction( expr::TextureAccess kind
		, spv::Id resultId
		, IdList operands );

	Instruction makeInstruction( spv::Op op
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands );
	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands );
	Instruction makeInstruction( expr::ImageAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList operands );
	Instruction makeInstruction( expr::TextureAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList operands );

	Instruction makeInstruction( spv::Op op
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands
		, std::string const & name );
	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands
		, std::string const & name );
	Instruction makeInstruction( expr::ImageAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands
		, std::string const & name );
	Instruction makeInstruction( expr::TextureAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands
		, std::string const & name );

	Instruction makeUnInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id const & operand );
	Instruction makeBinInstruction( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, spv::Id resultId
		, spv::Id lhs
		, spv::Id rhs );
	Instruction makeUnInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id typeId
		, spv::Id operand );
	Instruction makeBinInstruction( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, spv::Id resultId
		, spv::Id typeId
		, spv::Id lhs
		, spv::Id rhs );
	Instruction makeLoad( spv::Id resultId
		, spv::Id typeId
		, spv::Id varId );
	Instruction makeStore( spv::Id lhs
		, spv::Id rhs );
}

#endif
