/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvHelpers.hpp"

#include "ShaderWriter/SPIRV/SpirvImageAccessNames.hpp"
#include "ShaderWriter/SPIRV/SpirvTextureAccessNames.hpp"

namespace sdw::spirv
{
	//*************************************************************************

	Op getOp( spv::Op op, uint32_t count )
	{
		Op result;
		result.opCode = uint16_t( op );
		result.opCount = uint16_t( count ) + getOpBaseSize( op );
		return result;
	}

	Op getOp( spv::Op op, IdList const & operands )
	{
		return getOp( op, uint32_t( operands.size() ) );
	}

	Op getOp( spv::Op op, std::string const & name )
	{
		return getOp( op, uint32_t( name.size() ) );
	}

	Op getOp( spv::Op op )
	{
		return getOp( op, 0u );
	}

	spv::MemoryModel getMemoryModel()
	{
		return spv::MemoryModel::GLSL450;
	}

	spv::ExecutionModel getExecutionModel( ShaderType kind )
	{
		spv::ExecutionModel result;

		switch ( kind )
		{
		case sdw::ShaderType::eVertex:
			result = spv::ExecutionModel::Vertex;
			break;
		case sdw::ShaderType::eTessellationControl:
			result = spv::ExecutionModel::TessellationControl;
			break;
		case sdw::ShaderType::eTessellationEvaluation:
			result = spv::ExecutionModel::TessellationEvaluation;
			break;
		case sdw::ShaderType::eGeometry:
			result = spv::ExecutionModel::Geometry;
			break;
		case sdw::ShaderType::eCompute:
			result = spv::ExecutionModel::GLCompute;
			break;
		case sdw::ShaderType::eFragment:
			result = spv::ExecutionModel::Fragment;
			break;
		default:
			assert( false && "Unsupported ShaderType." );
			break;
		}

		return result;
	}

	std::string getTypeName( spv::Op op )
	{
		return getOpName( op );
	}

	std::string getOperatorName( spv::Op op )
	{
		return getOpName( op );
	}

	std::string getLocationName( var::Variable const & var )
	{
		std::string result;

		if ( var.isShaderConstant() )
		{
			result = "constant_id";
		}
		else if ( var.isShaderInput()
			|| var.isShaderOutput() )
		{
			result = "location";
		}

		return result;
	}

	std::string getDirectionName( var::Variable const & var )
	{
		std::string result;

		if ( var.isInputParam()
			&& var.isOutputParam() )
		{
			result = "inout";
		}
		else if ( var.isInputParam()
			|| var.isShaderInput() )
		{
			result = "in";
		}
		else if ( var.isOutputParam()
			|| var.isShaderOutput() )
		{
			result = "out";
		}
		else if ( var.isShaderConstant() )
		{
			result = "const";
		}

		return result;
	}

	std::string getStatusName( stmt::PreprocExtension::Status status )
	{
		std::string result;

		switch ( status )
		{
		case stmt::PreprocExtension::Status::eDisabled:
			result = "disable";
			break;

		case stmt::PreprocExtension::Status::eEnabled:
			result = "enable";
			break;

		case stmt::PreprocExtension::Status::eRequired:
			result = "required";
			break;

		}

		return result;
	}

	std::string getLayoutName( stmt::InputLayout layout )
	{
		std::string result;

		switch ( layout )
		{
		case ast::stmt::InputLayout::ePointList:
			result = "points";
			break;
		case ast::stmt::InputLayout::eLineList:
			result = "lines";
			break;
		case ast::stmt::InputLayout::eLineStrip:
			result = "lines";
			break;
		case ast::stmt::InputLayout::eTriangleList:
			result = "triangles";
			break;
		case ast::stmt::InputLayout::eTriangleStrip:
			result = "triangles";
			break;
		case ast::stmt::InputLayout::eTriangleFan:
			result = "triangles";
			break;
		case ast::stmt::InputLayout::eLineListWithAdjacency:
			result = "lines_adjacency";
			break;
		case ast::stmt::InputLayout::eLineStripWithAdjacency:
			result = "lines_adjacency";
			break;
		case ast::stmt::InputLayout::eTriangleListWithAdjacency:
			result = "triangles_adjacency";
			break;
		case ast::stmt::InputLayout::eTriangleStripWithAdjacency:
			result = "triangles_adjacency";
			break;
		default:
			throw std::runtime_error{ "Unsupported input layout." };
		}

		return result;
	}

	std::string getLayoutName( stmt::OutputLayout layout )
	{
		std::string result;

		switch ( layout )
		{
		case ast::stmt::OutputLayout::ePointList:
			result = "points";
			break;
		case ast::stmt::OutputLayout::eLineStrip:
			result = "line_strip";
			break;
		case ast::stmt::OutputLayout::eTriangleStrip:
			result = "triangle_strip";
			break;
		default:
			throw std::runtime_error{ "Unsupported output layout." };
		}

		return result;
	}

	//*************************************************************************

	Instruction makeExtension( std::string const & name )
	{
		return Instruction
		{
			getOp( spv::Op::OpExtension, name ),
			std::nullopt,
			std::nullopt,
			{},
			name,
		};
	}

	Instruction makeName( spv::Op op, spv::Id id, std::string const & name )
	{
		return Instruction
		{
			getOp( op, name ),
			std::nullopt,
			id,
			{},
			name,
		};
	}

	Instruction makeName( spv::Op op, spv::Id outerId, spv::Id memberIndex, std::string const & name )
	{
		return Instruction
		{
			getOp( op, uint32_t( name.size() + 2u ) ),
			std::nullopt,
			std::nullopt,
			{ outerId, memberIndex },
			name,
		};
	}

	spv::ImageFormat getImageFormat( type::Kind kind )
	{
		spv::ImageFormat result;

		switch ( kind )
		{
		case ast::type::Kind::eSamplerBufferF:
		case ast::type::Kind::eSampler1DF:
		case ast::type::Kind::eSampler2DF:
		case ast::type::Kind::eSampler3DF:
		case ast::type::Kind::eSamplerCubeF:
		case ast::type::Kind::eSampler2DRectF:
		case ast::type::Kind::eSampler1DArrayF:
		case ast::type::Kind::eSampler2DArrayF:
		case ast::type::Kind::eSamplerCubeArrayF:
		case ast::type::Kind::eSampler1DShadowF:
		case ast::type::Kind::eSampler2DShadowF:
		case ast::type::Kind::eSamplerCubeShadowF:
		case ast::type::Kind::eSampler2DRectShadowF:
		case ast::type::Kind::eSampler1DArrayShadowF:
		case ast::type::Kind::eSampler2DArrayShadowF:
		case ast::type::Kind::eSamplerCubeArrayShadowF:
		case ast::type::Kind::eImageBufferF:
		case ast::type::Kind::eImage1DF:
		case ast::type::Kind::eImage2DF:
		case ast::type::Kind::eImage3DF:
		case ast::type::Kind::eImageCubeF:
		case ast::type::Kind::eImage2DRectF:
		case ast::type::Kind::eImage1DArrayF:
		case ast::type::Kind::eImage2DArrayF:
		case ast::type::Kind::eImageCubeArrayF:
		case ast::type::Kind::eImage2DMSF:
		case ast::type::Kind::eImage2DMSArrayF:
			return spv::ImageFormat::Rgba32f;

		case ast::type::Kind::eSamplerBufferI:
		case ast::type::Kind::eSampler1DI:
		case ast::type::Kind::eSampler2DI:
		case ast::type::Kind::eSampler3DI:
		case ast::type::Kind::eSamplerCubeI:
		case ast::type::Kind::eSampler2DRectI:
		case ast::type::Kind::eSampler1DArrayI:
		case ast::type::Kind::eSampler2DArrayI:
		case ast::type::Kind::eSamplerCubeArrayI:
		case ast::type::Kind::eImageBufferI:
		case ast::type::Kind::eImage1DI:
		case ast::type::Kind::eImage2DI:
		case ast::type::Kind::eImage3DI:
		case ast::type::Kind::eImageCubeI:
		case ast::type::Kind::eImage2DRectI:
		case ast::type::Kind::eImage1DArrayI:
		case ast::type::Kind::eImage2DArrayI:
		case ast::type::Kind::eImageCubeArrayI:
		case ast::type::Kind::eImage2DMSI:
		case ast::type::Kind::eImage2DMSArrayI:
			return spv::ImageFormat::Rgba8Snorm;

		case ast::type::Kind::eSamplerBufferU:
		case ast::type::Kind::eSampler1DU:
		case ast::type::Kind::eSampler2DU:
		case ast::type::Kind::eSampler3DU:
		case ast::type::Kind::eSamplerCubeU:
		case ast::type::Kind::eSampler2DRectU:
		case ast::type::Kind::eSampler1DArrayU:
		case ast::type::Kind::eSampler2DArrayU:
		case ast::type::Kind::eSamplerCubeArrayU:
		case ast::type::Kind::eImageBufferU:
		case ast::type::Kind::eImage1DU:
		case ast::type::Kind::eImage2DU:
		case ast::type::Kind::eImage3DU:
		case ast::type::Kind::eImageCubeU:
		case ast::type::Kind::eImage2DRectU:
		case ast::type::Kind::eImage1DArrayU:
		case ast::type::Kind::eImage2DArrayU:
		case ast::type::Kind::eImageCubeArrayU:
		case ast::type::Kind::eImage2DMSU:
		case ast::type::Kind::eImage2DMSArrayU:
			return spv::ImageFormat::Rgba8ui;

		default:
			assert( false && "Unsupported type::Kind" );
			return spv::ImageFormat::Rgba32f;
		}

		return result;
	}

	Instruction makeType( type::Kind kind
		, spv::Id id )
	{
		assert( !isSamplerType( kind )
			&& !isImageType( kind ) );
		IdList operands;

		switch ( kind )
		{
		case ast::type::Kind::eInt:
			operands.push_back( 32u );
			operands.push_back( 1u );
			break;
		case ast::type::Kind::eUInt:
			operands.push_back( 32u );
			operands.push_back( 0u );
			break;
		case ast::type::Kind::eFloat:
			operands.push_back( 32u );
			break;
		case ast::type::Kind::eDouble:
			operands.push_back( 64u );
			break;
		case ast::type::Kind::eHalf:
			operands.push_back( 16u );
			break;
		}

		return Instruction
		{
			getOp( getOpCode( kind ), 0u ),
			std::nullopt,
			id,
			operands,
		};
	}

	Instruction makeType( type::Kind kind
		, spv::Id id
		, IdList const & subTypes )
	{
		return Instruction
		{
			getOp( getOpCode( kind ), subTypes ),
			std::nullopt,
			id,
			subTypes
		};
	}

	Instruction makeImageType( type::Kind kind
		, spv::Id id
		, spv::Id sampledId )
	{
		assert( isSamplerType( kind )
			|| isImageType( kind ) );
		IdList operands;
		auto config = getImageConfig( kind );
		operands.push_back( sampledId );
		operands.push_back( spv::Id( config.dimension ) );
		operands.push_back( config.isDepth == ast::type::Ternary::eTrue
			? 1u
			: ( config.isDepth == ast::type::Ternary::eFalse
				? 0u
				: 2u ) );
		operands.push_back( config.isArrayed ? 1u : 0u );
		operands.push_back( config.isMS ? 1u : 0u );
		operands.push_back( config.isSampled == ast::type::Ternary::eTrue
			? 1u
			: ( config.isDepth == ast::type::Ternary::eFalse
				? 2u
				: 0u ) );
		operands.push_back( uint32_t( getImageFormat( kind ) ) );
		operands.push_back( uint32_t( config.accessKind ) );

		return Instruction
		{
			getOp( getImageOpCode( kind ), 1u ),
			std::nullopt,
			id,
			operands,
		};
	}

	Instruction makeSamplerType( spv::Id id )
	{
		return Instruction
		{
			getOp( spv::Op::OpTypeSampler, 0u ),
			std::nullopt,
			id,
		};
	}

	Instruction makeSampledImageType( type::Kind kind
		, spv::Id id
		, spv::Id imageId )
	{
		IdList operands;
		operands.push_back( imageId );
		return Instruction
		{
			getOp( getOpCode( kind ), 0u ),
			std::nullopt,
			id,
			operands,
		};
	}

	Instruction makeStructType( spv::Id id, IdList const & subTypes )
	{
		return Instruction
		{
			getOp( spv::Op::OpTypeStruct, subTypes ),
			std::nullopt,
			id,
			subTypes
		};
	}

	Instruction makeArrayType( type::Kind kind, spv::Id id, spv::Id elementTypeId )
	{
		return Instruction
		{
			getOp( spv::Op::OpTypeRuntimeArray, 0u ),
			std::nullopt,
			id,
			{ elementTypeId }
		};
	}

	Instruction makeArrayType( type::Kind kind, spv::Id id, spv::Id elementTypeId, uint32_t length )
	{
		return Instruction
		{
			getOp( spv::Op::OpTypeArray, 0u ),
			std::nullopt,
			id,
			{ elementTypeId, length }
		};
	}

	Instruction makeType( type::TypePtr type, spv::Id id )
	{
		return Instruction
		{
			getOp( getOpCode( type ), 0u ),
			std::nullopt,
			id,
		};
	}

	Instruction makeSwitch( spv::Id selector
		, spv::Id defaultId
		, std::map< int64_t, spv::Id > const & cases )
	{
		return Instruction
		{
			getOp( spv::Op::OpSwitch, uint32_t( ( cases.size() * 2u ) + 1u ) ),
			std::nullopt,
			std::nullopt,
			{},
			{},
			cases
		};
	}

	Instruction makeVariable( spv::Id resultId
		, spv::Id typeId
		, spv::StorageClass storage )
	{
		return Instruction
		{
			getOp( spv::Op::OpVariable, 0u ),
			typeId,
			resultId,
		{ spv::Id( storage ) },
		};
	}

	Instruction makeVariable( spv::Id resultId
		, spv::Id typeId
		, spv::StorageClass storage
		, spv::Id initialiser )
	{
		return Instruction
		{
			getOp( spv::Op::OpVariable, 0u ),
			typeId,
			resultId,
			{ spv::Id( storage ), initialiser },
		};
	}

	Instruction makeAccessChain( spv::Op op
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & accessChain )
	{
		return Instruction
		{
			getOp( op, uint32_t( accessChain.size() - 1u ) ),
			typeId,
			resultId,
			accessChain,
		};
	}

	Instruction makeVectorShuffle( spv::Id resultId
		, spv::Id typeId
		, spv::Id vector
		, std::vector< uint32_t >const & components )
	{
		return makeVectorShuffle( resultId
			, typeId
			, vector
			, vector
			, components );
	}

	Instruction makeVectorShuffle( spv::Id resultId
		, spv::Id typeId
		, spv::Id vector1
		, spv::Id vector2
		, std::vector< uint32_t >const & components )
	{
		IdList total;
		total.push_back( vector1 );
		total.push_back( vector2 );
		total.insert( total.end(), components.begin(), components.end() );
		return Instruction
		{
			getOp( spv::Op::OpVectorShuffle, components ),
			typeId,
			resultId,
			total,
		};
	}

	Instruction makeInstruction( spv::Op op )
	{
		return Instruction
		{
			getOp( op ),
			std::nullopt,
			std::nullopt,
			{},
		};
	}

	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind )
	{
		return makeInstruction( getOpCode( exprKind, typeKind ) );
	}

	Instruction makeInstruction( expr::ImageAccess kind )
	{
		return makeInstruction( getSpirVName( kind ) );
	}

	Instruction makeInstruction( expr::TextureAccess kind )
	{
		return makeInstruction( getSpirVName( kind ) );
	}

	Instruction makeInstruction( spv::Op op
		, IdList const & operands )
	{
		return Instruction
		{
			getOp( op, operands ),
			std::nullopt,
			std::nullopt,
			operands,
		};
	}

	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, IdList const & operands )
	{
		return makeInstruction( getOpCode( exprKind, typeKind )
			, operands );
	}

	Instruction makeInstruction( expr::ImageAccess kind
		, IdList operands )
	{
		return makeInstruction( getSpirVName( kind )
			, operands );
	}

	Instruction makeInstruction( expr::TextureAccess kind
		, IdList operands )
	{
		auto mask = getMask( kind );
		operands.insert( operands.begin() + 2u, spv::Id( mask ) );

		if ( uint32_t( mask ) & uint32_t( spv::ImageOperandsMask::Bias ) )
		{
			// Bias is usually last parameter, but it has to be the first optional one.
			// Two first operands are the image and its sampler
			operands.insert( operands.begin() + 3u, operands.back() );
			operands.erase( operands.begin() + operands.size() - 1u );
		}

		return makeInstruction( getSpirVName( kind )
			, operands );
	}

	Instruction makeInstruction( spv::Op op
		, IdList const & operands
		, std::string const & name )
	{
		return Instruction
		{
			getOp( op, operands ),
			std::nullopt,
			std::nullopt,
			operands,
			name,
		};
	}

	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, IdList const & operands
		, std::string const & name )
	{
		return makeInstruction( getOpCode( exprKind, typeKind )
			, operands
			, name );
	}

	Instruction makeInstruction( expr::ImageAccess kind
		, IdList operands
		, std::string const & name )
	{
		return makeInstruction( getSpirVName( kind )
			, operands
			, name );
	}

	Instruction makeInstruction( expr::TextureAccess kind
		, IdList operands
		, std::string const & name )
	{
		auto mask = getMask( kind );
		operands.insert( operands.begin() + 2u, spv::Id( mask ) );

		if ( uint32_t( mask ) & uint32_t( spv::ImageOperandsMask::Bias ) )
		{
			// Bias is usually last parameter, but it has to be the first optional one.
			// Two first operands are the image and its sampler
			operands.insert( operands.begin() + 3u, operands.back() );
			operands.erase( operands.begin() + operands.size() - 1u );
		}

		return makeInstruction( getSpirVName( kind )
			, operands
			, name );
	}

	Instruction makeInstruction( spv::Op op
		, spv::Id resultId
		, IdList const & operands )
	{
		return Instruction
		{
			getOp( op, operands ),
			std::nullopt,
			resultId,
			operands,
		};
	}

	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, IdList const & operands )
	{
		return makeInstruction( getOpCode( exprKind, typeKind )
			, resultId
			, operands );
	}

	Instruction makeInstruction( expr::ImageAccess kind
		, spv::Id resultId
		, IdList operands )
	{
		return makeInstruction( getSpirVName( kind )
			, resultId
			, operands );
	}

	Instruction makeInstruction( expr::TextureAccess kind
		, spv::Id resultId
		, IdList operands )
	{
		auto mask = getMask( kind );
		operands.insert( operands.begin() + 2u, spv::Id( mask ) );

		if ( uint32_t( mask ) & uint32_t( spv::ImageOperandsMask::Bias ) )
		{
			// Bias is usually last parameter, but it has to be the first optional one.
			// Two first operands are the image and its sampler
			operands.insert( operands.begin() + 3u, operands.back() );
			operands.erase( operands.begin() + operands.size() - 1u );
		}

		return makeInstruction( getSpirVName( kind )
			, resultId
			, operands );
	}

	Instruction makeInstruction( spv::Op op
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands )
	{
		return Instruction
		{
			getOp( op, operands ),
			typeId,
			resultId,
			operands,
		};
	}

	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands )
	{
		return makeInstruction( getOpCode( exprKind, typeKind )
			, resultId
			, typeId
			, operands );
	}

	Instruction makeInstruction( expr::ImageAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList operands )
	{
		return makeInstruction( getSpirVName( kind )
			, resultId
			, typeId
			, operands );
	}

	Instruction makeInstruction( expr::TextureAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList operands )
	{
		auto mask = getMask( kind );
		operands.insert( operands.begin() + 2u, spv::Id( mask ) );

		if ( uint32_t( mask ) & uint32_t( spv::ImageOperandsMask::Bias ) )
		{
			// Bias is usually last parameter, but it has to be the first optional one.
			// Two first operands are the image and its sampler
			operands.insert( operands.begin() + 3u, operands.back() );
			operands.erase( operands.begin() + operands.size() - 1u );
		}

		return makeInstruction( getSpirVName( kind )
			, resultId
			, typeId
			, operands );
	}

	Instruction makeInstruction( spv::Op op
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands
		, std::string const & name )
	{
		return Instruction
		{
			getOp( op, operands ),
			typeId,
			resultId,
			operands,
			name,
		};
	}

	Instruction makeInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id typeId
		, IdList const & operands
		, std::string const & name )
	{
		return makeInstruction( getOpCode( exprKind, typeKind )
			, resultId
			, typeId
			, operands
			, name );
	}

	Instruction makeInstruction( expr::ImageAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList operands
		, std::string const & name )
	{
		return makeInstruction( getSpirVName( kind )
			, resultId
			, typeId
			, operands
			, name );
	}

	Instruction makeInstruction( expr::TextureAccess kind
		, spv::Id resultId
		, spv::Id typeId
		, IdList operands
		, std::string const & name )
	{
		auto mask = getMask( kind );
		operands.insert( operands.begin() + 2u, spv::Id( mask ) );

		if ( uint32_t( mask ) & uint32_t( spv::ImageOperandsMask::Bias ) )
		{
			// Bias is usually last parameter, but it has to be the first optional one.
			// Two first operands are the image and its sampler
			operands.insert( operands.begin() + 3u, operands.back() );
			operands.erase( operands.begin() + operands.size() - 1u );
		}

		return makeInstruction( getSpirVName( kind )
			, resultId
			, typeId
			, operands
			, name );
	}

	Instruction makeUnInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id const & operand )
	{
		return makeInstruction( getOpCode( exprKind, typeKind )
			, resultId
			, { operand } );
	}

	Instruction makeBinInstruction( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, spv::Id resultId
		, spv::Id lhs
		, spv::Id rhs )
	{
		bool switchParams;
		auto opCode = getBinOpCode( exprKind, lhsTypeKind, rhsTypeKind, switchParams );

		if ( switchParams )
		{
			return makeInstruction( opCode
				, resultId
				, { rhs, lhs } );
		}

		return makeInstruction( opCode
			, resultId
			, { lhs, rhs } );
	}

	Instruction makeUnInstruction( expr::Kind exprKind
		, type::Kind typeKind
		, spv::Id resultId
		, spv::Id typeId
		, spv::Id operand )
	{
		return makeInstruction( getOpCode( exprKind, typeKind )
			, resultId
			, typeId
			, IdList{ operand } );
	}

	Instruction makeBinInstruction( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, spv::Id resultId
		, spv::Id typeId
		, spv::Id lhs
		, spv::Id rhs )
	{
		bool switchParams;
		auto opCode = getBinOpCode( exprKind, lhsTypeKind, rhsTypeKind, switchParams );

		if ( switchParams )
		{
			return makeInstruction( opCode
				, resultId
				, typeId
				, { rhs, lhs } );
		}

		return makeInstruction( opCode
			, resultId
			, typeId
			, { lhs, rhs } );
	}

	Instruction makeLoad( spv::Id resultId
		, spv::Id typeId
		, spv::Id varId )
	{
		return makeInstruction( spv::Op::OpLoad
			, resultId
			, typeId
			, { varId } );
	}

	Instruction makeStore( spv::Id lhs
		, spv::Id rhs )
	{
		return makeInstruction( spv::Op::OpStore
			, { lhs, rhs } );
	}

	//*************************************************************************
}
