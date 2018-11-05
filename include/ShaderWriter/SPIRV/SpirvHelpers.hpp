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
	struct LinkedVar
	{
		var::VariablePtr image;
		var::VariablePtr sampler;
		var::VariablePtr sampledImage;
	};
	using LinkedVars = std::map< var::VariablePtr, LinkedVar >;

	class SampledImage
		: public type::Type
	{
	public:
		SampledImage()
			: type::Type{ type::Kind::eCount }
		{
		}
	};

	using SampledImagePtr = std::shared_ptr< SampledImage >;

	inline SampledImagePtr makeSampledImage()
	{
		return std::make_shared< SampledImage >();
	}

	class Sampler
		: public type::Type
	{
	public:
		Sampler()
			: type::Type{ type::Kind( uint32_t( type::Kind::eCount ) + 1u ) }
		{
		}
	};

	using SamplerPtr = std::shared_ptr< Sampler >;

	inline SamplerPtr makeSampler()
	{
		return std::make_shared< Sampler >();
	}

	struct PreprocContext
	{
		std::map< std::string, expr::Expr * > defines;
	};

	Op getOp( spv::Op op, std::string const & name );
	Op getOp( spv::Op op, IdList const & operands );
	spv::MemoryModel getMemoryModel();
	spv::ExecutionModel getExecutionModel( ShaderType kind );
	std::string getTypeName( spv::Op op );
	std::string getOperatorName( spv::Op op );
	std::string getLocationName( var::Variable const & var );
	std::string getDirectionName( var::Variable const & var );
	std::string getStatusName( stmt::PreprocExtension::Status status );

	Instruction makeExtension( std::string const & name );
	Instruction makeName( spv::Op op, spv::Id id, std::string const & name );
	Instruction makeName( spv::Op op, spv::Id outerId, spv::Id memberIndex, std::string const & name );
	Instruction makeType( type::Kind kind, spv::Id id );
	Instruction makeType( type::Kind kind, spv::Id id, IdList const & subTypes );
	Instruction makeImageType( type::Kind kind, spv::Id id, spv::Id sampledId );
	Instruction makeSamplerType( spv::Id id );
	Instruction makeSampledImageType( type::Kind kind, spv::Id id, spv::Id imageId );
	Instruction makeStructType( spv::Id id, IdList const & subTypes );
	Instruction makeArrayType( type::Kind kind, spv::Id id, spv::Id elementTypeId );
	Instruction makeArrayType( type::Kind kind, spv::Id id, spv::Id elementTypeId, uint32_t length );
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
