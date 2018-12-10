/*
See LICENSE file in root folder
*/
#include "SpirvHelpers.hpp"

namespace spirv
{
	//*************************************************************************

	spv::MemoryModel getMemoryModel()
	{
		return spv::MemoryModelGLSL450;
	}

	spv::ExecutionModel getExecutionModel( sdw::ShaderType kind )
	{
		spv::ExecutionModel result;

		switch ( kind )
		{
		case sdw::ShaderType::eVertex:
			result = spv::ExecutionModelVertex;
			break;
		case sdw::ShaderType::eTessellationControl:
			result = spv::ExecutionModelTessellationControl;
			break;
		case sdw::ShaderType::eTessellationEvaluation:
			result = spv::ExecutionModelTessellationEvaluation;
			break;
		case sdw::ShaderType::eGeometry:
			result = spv::ExecutionModelGeometry;
			break;
		case sdw::ShaderType::eCompute:
			result = spv::ExecutionModelGLCompute;
			break;
		case sdw::ShaderType::eFragment:
			result = spv::ExecutionModelFragment;
			break;
		default:
			assert( false && "Unsupported sdw::ShaderType." );
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

	//*************************************************************************

	spv::ImageFormat getImageFormat( ast::type::ImageFormat value )
	{
		switch ( value )
		{
		case ast::type::ImageFormat::eUnknown:
			return spv::ImageFormatUnknown;
		case ast::type::ImageFormat::eRgba32f:
			return spv::ImageFormatRgba32f;
		case ast::type::ImageFormat::eRgba16f:
			return spv::ImageFormatRgba16f;
		case ast::type::ImageFormat::eRg32f:
			return spv::ImageFormatRg32f;
		case ast::type::ImageFormat::eRg16f:
			return spv::ImageFormatRg16f;
		case ast::type::ImageFormat::eR32f:
			return spv::ImageFormatR32f;
		case ast::type::ImageFormat::eR16f:
			return spv::ImageFormatR16f;
		case ast::type::ImageFormat::eRgba32i:
			return spv::ImageFormatRgba32i;
		case ast::type::ImageFormat::eRgba16i:
			return spv::ImageFormatRgba16i;
		case ast::type::ImageFormat::eRgba8i:
			return spv::ImageFormatRgba8i;
		case ast::type::ImageFormat::eRg32i:
			return spv::ImageFormatRg32i;
		case ast::type::ImageFormat::eRg16i:
			return spv::ImageFormatRg16i;
		case ast::type::ImageFormat::eRg8i:
			return spv::ImageFormatRg8i;
		case ast::type::ImageFormat::eR32i:
			return spv::ImageFormatR32i;
		case ast::type::ImageFormat::eR16i:
			return spv::ImageFormatR16i;
		case ast::type::ImageFormat::eR8i:
			return spv::ImageFormatR8i;
		case ast::type::ImageFormat::eRgba32u:
			return spv::ImageFormatRgba32ui;
		case ast::type::ImageFormat::eRgba16u:
			return spv::ImageFormatRgba16ui;
		case ast::type::ImageFormat::eRgba8u:
			return spv::ImageFormatRgba8ui;
		case ast::type::ImageFormat::eRg32u:
			return spv::ImageFormatRg32ui;
		case ast::type::ImageFormat::eRg16u:
			return spv::ImageFormatRg16ui;
		case ast::type::ImageFormat::eRg8u:
			return spv::ImageFormatRg8ui;
		case ast::type::ImageFormat::eR32u:
			return spv::ImageFormatR32ui;
		case ast::type::ImageFormat::eR16u:
			return spv::ImageFormatR16ui;
		case ast::type::ImageFormat::eR8u:
			return spv::ImageFormatR8ui;
		default:
			assert( false && "Unsupported ast::type::ImageFormat" );
			return spv::ImageFormatRgba32f;
		}
	}

	InstructionPtr makeExtension( std::string const & name )
	{
		return makeInstruction< ExtensionInstruction >( name );
	}

	InstructionPtr makeFunctionType( spv::Id returnTypeId
		, IdList const & functionTypesId )
	{
		return makeInstruction< FunctionTypeInstruction >( returnTypeId
			, functionTypesId );
	}

	void getBinOpOperands( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs
		, IdList & operands
		, spv::Op & opCode )
	{
		bool needsMatchingVector;
		bool switchParams{ false };
		opCode = getBinOpCode( exprKind
			, lhsTypeKind
			, rhsTypeKind
			, switchParams
			, needsMatchingVector );

		if ( switchParams )
		{
			std::swap( lhs, rhs );
		}

		operands = makeOperands( lhs, rhs );
	}

	IdList makeBinOpOperands( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs )
	{
		IdList result;
		spv::Op opCode;
		getBinOpOperands( exprKind, lhsTypeKind, rhsTypeKind, lhs, rhs, result, opCode );
		return makeOperands( spv::Id( opCode ), result );
	}

	InstructionPtr makeImageTypeInstruction( ast::type::ImageConfiguration const & config
		, spv::Id resultId
		, spv::Id sampledTypeId )
	{
		IdList operands;
		operands.push_back( sampledTypeId );
		operands.push_back( spv::Id( config.dimension ) );
		operands.push_back( config.isDepth == ast::type::Trinary::eTrue
			? 1u
			: ( config.isDepth == ast::type::Trinary::eFalse
				? 0u
				: 2u ) );
		operands.push_back( config.isArrayed ? 1u : 0u );
		operands.push_back( config.isMS ? 1u : 0u );
		operands.push_back( config.isSampled == ast::type::Trinary::eTrue
			? 1u
			: ( config.isDepth == ast::type::Trinary::eFalse
				? 2u
				: 0u ) );
		operands.push_back( uint32_t( getImageFormat( config.format ) ) );
		// Only available in kernel mode.
		//operands.push_back( uint32_t( config.accessKind ) );

		return makeInstruction< ImageTypeInstruction >( resultId
			, operands );
	}

	InstructionPtr makeBaseTypeInstruction( ast::type::Kind kind
		, spv::Id id )
	{
		assert( !isStructType( kind )
			&& !isSamplerType( kind )
			&& !isImageType( kind )
			&& !isSampledImageType( kind ) );
		IdList operands;

		switch ( kind )
		{
		case ast::type::Kind::eVoid:
			return makeInstruction< VoidTypeInstruction >( id );
		case ast::type::Kind::eBoolean:
			return makeInstruction< BooleanTypeInstruction >( id );
		case ast::type::Kind::eInt:
			return makeInstruction< IntTypeInstruction >( id, 32u, 1u );
		case ast::type::Kind::eUInt:
			return makeInstruction< IntTypeInstruction >( id, 32u, 0u );
		case ast::type::Kind::eFloat:
			return makeInstruction< FloatTypeInstruction >( id, 32u );
		case ast::type::Kind::eDouble:
			return makeInstruction< FloatTypeInstruction >( id, 64u );
		case ast::type::Kind::eHalf:
			return makeInstruction< FloatTypeInstruction >( id, 16u );
		default:
			assert( false && "Unexpected type kind" );
		}

		return nullptr;
	}

	InstructionPtr makeIntrinsicInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::Op::OpFMod:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFMod > >( returnTypeId, resultId, operands );
		case spv::Op::OpIsNan:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpIsNan > >( returnTypeId, resultId, operands );
		case spv::Op::OpIsInf:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpIsInf > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitcast:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpBitcast > >( returnTypeId, resultId, operands );
		case spv::Op::OpDot:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpDot > >( returnTypeId, resultId, operands );
		case spv::Op::OpMatrixTimesMatrix:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpMatrixTimesMatrix > >( returnTypeId, resultId, operands );
		case spv::Op::OpOuterProduct:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpOuterProduct > >( returnTypeId, resultId, operands );
		case spv::Op::OpTranspose:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpTranspose > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdLessThan:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFOrdLessThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpSLessThan:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpSLessThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpULessThan:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpULessThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdLessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFOrdLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpSLessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpSLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpULessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpULessThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFOrdGreaterThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpSGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpSGreaterThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpUGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpUGreaterThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFOrdGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpSGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpSGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpUGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpUGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFOrdEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpIEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpIEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdNotEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFOrdNotEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpINotEqual:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpINotEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpAll:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAll > >( returnTypeId, resultId, operands );
		case spv::Op::OpAny:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAny > >( returnTypeId, resultId, operands );
		case spv::Op::OpLogicalNot:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpLogicalNot > >( returnTypeId, resultId, operands );
		case spv::Op::OpIAddCarry:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpIAddCarry > >( returnTypeId, resultId, operands );
		case spv::Op::OpISubBorrow:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpISubBorrow > >( returnTypeId, resultId, operands );
		case spv::Op::OpUMulExtended:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpUMulExtended > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitFieldSExtract:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpBitFieldSExtract > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitFieldUExtract:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpBitFieldUExtract > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitFieldInsert:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpBitFieldInsert > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitReverse:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpBitReverse > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitCount:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpBitCount > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicIAdd:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicIAdd > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicSMin:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicSMin > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicUMin:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicUMin > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicSMax:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicSMax > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicUMax:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicUMax > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicAnd:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicAnd > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicOr:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicOr > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicXor:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicXor > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicExchange:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicExchange > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicCompareExchange:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpAtomicCompareExchange > >( returnTypeId, resultId, operands );
		case spv::Op::OpDPdx:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpDPdx > >( returnTypeId, resultId, operands );
		case spv::Op::OpDPdxCoarse:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpDPdxCoarse > >( returnTypeId, resultId, operands );
		case spv::Op::OpDPdxFine:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpDPdxFine > >( returnTypeId, resultId, operands );
		case spv::Op::OpDPdy:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpDPdy > >( returnTypeId, resultId, operands );
		case spv::Op::OpDPdyCoarse:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpDPdyCoarse > >( returnTypeId, resultId, operands );
		case spv::Op::OpDPdyFine:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpDPdyFine > >( returnTypeId, resultId, operands );
		case spv::Op::OpFwidth:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpFwidth > >( returnTypeId, resultId, operands );
		case spv::Op::OpEmitStreamVertex:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpEmitStreamVertex > >( returnTypeId, resultId, operands );
		case spv::Op::OpEndStreamPrimitive:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpEndStreamPrimitive > >( returnTypeId, resultId, operands );
		case spv::Op::OpEmitVertex:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpEmitVertex > >( returnTypeId, resultId, operands );
		case spv::Op::OpEndPrimitive:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpEndPrimitive > >( returnTypeId, resultId, operands );
		case spv::Op::OpControlBarrier:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpControlBarrier > >( returnTypeId, resultId, operands );
		case spv::Op::OpMemoryBarrier:
			return makeInstruction< IntrinsicInstructionT< spv::Op::OpMemoryBarrier > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected intrinsic call Op" );
		}

		return nullptr;
	}

	InstructionPtr makeTextureAccessInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::Op::OpImageQuerySizeLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageQuerySizeLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageQuerySize:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageQuerySize > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageQueryLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageQueryLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageQueryLevels:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageQueryLevels > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleImplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleDrefImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleDrefImplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleProjImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleProjImplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleProjDrefImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleProjDrefImplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleExplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleDrefExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleDrefExplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleProjExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleProjExplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageSampleProjDrefExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageSampleProjDrefExplicitLod > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageFetch:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageFetch > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageGather:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageGather > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageDrefGather:
			return makeInstruction< TextureAccessInstructionT< spv::Op::OpImageDrefGather > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected texture access Op" );
		}

		return nullptr;
	}

	InstructionPtr makeImageAccessInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::Op::OpImageQuerySize:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpImageQuerySize > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageQuerySamples:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpImageQuerySamples > >( returnTypeId, resultId, operands );
		case spv::Op::OpImageRead:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpImageRead > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicIAdd:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicIAdd > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicUMin:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicUMin > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicSMin:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicSMin > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicUMax:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicUMax > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicSMax:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicSMax > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicAnd:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicAnd > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicOr:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicOr > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicXor:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicXor > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicExchange:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicExchange > >( returnTypeId, resultId, operands );
		case spv::Op::OpAtomicCompareExchange:
			return makeInstruction< ImageAccessInstructionT< spv::Op::OpAtomicCompareExchange > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected image access Op" );
		}

		return nullptr;
	}

	InstructionPtr makeCastInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, spv::Id operandId )
	{
		switch ( op )
		{
		case spv::Op::OpFConvert:
			return makeInstruction< UnInstructionT< spv::Op::OpFConvert > >( returnTypeId, resultId, operandId );
		case spv::Op::OpConvertFToS:
			return makeInstruction< UnInstructionT< spv::Op::OpConvertFToS > >( returnTypeId, resultId, operandId );
		case spv::Op::OpConvertFToU:
			return makeInstruction< UnInstructionT< spv::Op::OpConvertFToU > >( returnTypeId, resultId, operandId );
		case spv::Op::OpConvertSToF:
			return makeInstruction< UnInstructionT< spv::Op::OpConvertSToF > >( returnTypeId, resultId, operandId );
		case spv::Op::OpConvertUToF:
			return makeInstruction< UnInstructionT< spv::Op::OpConvertUToF > >( returnTypeId, resultId, operandId );
		case spv::Op::OpBitcast:
			return makeInstruction< UnInstructionT< spv::Op::OpBitcast > >( returnTypeId, resultId, operandId );
		default:
			assert( false && "Unexpected cast Op" );
		}

		return nullptr;
	}

	InstructionPtr makeUnInstruction( spv::Op op
		, spv::Id returnTypeId
		, spv::Id resultId
		, spv::Id operandId )
	{
		switch ( op )
		{
		case spv::Op::OpNot:
			return makeInstruction< UnInstructionT< spv::Op::OpNot > >( returnTypeId, resultId, operandId );
		case spv::Op::OpLogicalNot:
			return makeInstruction< UnInstructionT< spv::Op::OpLogicalNot > >( returnTypeId, resultId, operandId );
		case spv::Op::OpFNegate:
			return makeInstruction< UnInstructionT< spv::Op::OpFNegate > >( returnTypeId, resultId, operandId );
		case spv::Op::OpSNegate:
			return makeInstruction< UnInstructionT< spv::Op::OpSNegate > >( returnTypeId, resultId, operandId );
		default:
			assert( false && "Unexpected unary operation Op" );
		}

		return nullptr;
	}

	InstructionPtr makeUnInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind typeKind
		, spv::Id operand )
	{
		return makeUnInstruction( getUnOpCode( exprKind, typeKind )
			, returnTypeId
			, resultId
			, operand );
	}

	InstructionPtr makeBinInstruction( spv::Op op
		, spv::Id returnTypeId
		, spv::Id resultId
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::Op::OpFAdd:
			return makeInstruction< BinInstructionT< spv::Op::OpFAdd > >( returnTypeId, resultId, operands );
		case spv::Op::OpIAdd:
			return makeInstruction< BinInstructionT< spv::Op::OpIAdd > >( returnTypeId, resultId, operands );
		case spv::Op::OpFSub:
			return makeInstruction< BinInstructionT< spv::Op::OpFSub > >( returnTypeId, resultId, operands );
		case spv::Op::OpISub:
			return makeInstruction< BinInstructionT< spv::Op::OpISub > >( returnTypeId, resultId, operands );
		case spv::Op::OpFMul:
			return makeInstruction< BinInstructionT< spv::Op::OpFMul > >( returnTypeId, resultId, operands );
		case spv::Op::OpIMul:
			return makeInstruction< BinInstructionT< spv::Op::OpIMul > >( returnTypeId, resultId, operands );
		case spv::Op::OpFDiv:
			return makeInstruction< BinInstructionT< spv::Op::OpFDiv > >( returnTypeId, resultId, operands );
		case spv::Op::OpSDiv:
			return makeInstruction< BinInstructionT< spv::Op::OpSDiv > >( returnTypeId, resultId, operands );
		case spv::Op::OpUDiv:
			return makeInstruction< BinInstructionT< spv::Op::OpUDiv > >( returnTypeId, resultId, operands );
		case spv::Op::OpFMod:
			return makeInstruction< BinInstructionT< spv::Op::OpFMod > >( returnTypeId, resultId, operands );
		case spv::Op::OpSMod:
			return makeInstruction< BinInstructionT< spv::Op::OpSMod > >( returnTypeId, resultId, operands );
		case spv::Op::OpUMod:
			return makeInstruction< BinInstructionT< spv::Op::OpUMod > >( returnTypeId, resultId, operands );
		case spv::Op::OpMatrixTimesMatrix:
			return makeInstruction< BinInstructionT< spv::Op::OpMatrixTimesMatrix > >( returnTypeId, resultId, operands );
		case spv::Op::OpMatrixTimesVector:
			return makeInstruction< BinInstructionT< spv::Op::OpMatrixTimesVector > >( returnTypeId, resultId, operands );
		case spv::Op::OpMatrixTimesScalar:
			return makeInstruction< BinInstructionT< spv::Op::OpMatrixTimesScalar > >( returnTypeId, resultId, operands );
		case spv::Op::OpVectorTimesScalar:
			return makeInstruction< BinInstructionT< spv::Op::OpVectorTimesScalar > >( returnTypeId, resultId, operands );
		case spv::Op::OpShiftLeftLogical:
			return makeInstruction< BinInstructionT< spv::Op::OpShiftLeftLogical > >( returnTypeId, resultId, operands );
		case spv::Op::OpShiftRightArithmetic:
			return makeInstruction< BinInstructionT< spv::Op::OpShiftRightArithmetic > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitwiseAnd:
			return makeInstruction< BinInstructionT< spv::Op::OpBitwiseAnd > >( returnTypeId, resultId, operands );
		case spv::Op::OpNot:
			return makeInstruction< BinInstructionT< spv::Op::OpNot > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitwiseOr:
			return makeInstruction< BinInstructionT< spv::Op::OpBitwiseOr > >( returnTypeId, resultId, operands );
		case spv::Op::OpBitwiseXor:
			return makeInstruction< BinInstructionT< spv::Op::OpBitwiseXor > >( returnTypeId, resultId, operands );
		case spv::Op::OpLogicalAnd:
			return makeInstruction< BinInstructionT< spv::Op::OpLogicalAnd > >( returnTypeId, resultId, operands );
		case spv::Op::OpLogicalOr:
			return makeInstruction< BinInstructionT< spv::Op::OpLogicalOr > >( returnTypeId, resultId, operands );
		case spv::Op::OpStore:
			return makeInstruction< BinInstructionT< spv::Op::OpStore > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpFOrdEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpLogicalEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpLogicalEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpIEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpIEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdNotEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpFOrdNotEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpLogicalNotEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpLogicalNotEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpINotEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpINotEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdGreaterThan:
			return makeInstruction< BinInstructionT< spv::Op::OpFOrdGreaterThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpSGreaterThan:
			return makeInstruction< BinInstructionT< spv::Op::OpSGreaterThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpUGreaterThan:
			return makeInstruction< BinInstructionT< spv::Op::OpUGreaterThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdGreaterThanEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpFOrdGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpSGreaterThanEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpSGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpUGreaterThanEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpUGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdLessThan:
			return makeInstruction< BinInstructionT< spv::Op::OpFOrdLessThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpSLessThan:
			return makeInstruction< BinInstructionT< spv::Op::OpSLessThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpULessThan:
			return makeInstruction< BinInstructionT< spv::Op::OpULessThan > >( returnTypeId, resultId, operands );
		case spv::Op::OpFOrdLessThanEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpFOrdLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpSLessThanEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpSLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::Op::OpULessThanEqual:
			return makeInstruction< BinInstructionT< spv::Op::OpULessThanEqual > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected binary operation Op" );
		}

		return nullptr;
	}

	InstructionPtr makeBinInstruction( spv::Id typeId
		, spv::Id resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs )
	{
		IdList operands;
		spv::Op opCode;
		getBinOpOperands( exprKind, lhsTypeKind, rhsTypeKind, lhs, rhs, operands, opCode );
		return makeBinInstruction( opCode
			, typeId
			, resultId
			, operands );
	}

	//*************************************************************************
}
