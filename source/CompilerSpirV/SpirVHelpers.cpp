/*
See LICENSE file in root folder
*/
#include "SpirVHelpers.hpp"

#include "SpirVExprAdapter.hpp"
#include "SpirVModule.hpp"

#include <ShaderAST/Expr/ExprCompositeConstruct.hpp>
#include <ShaderAST/Expr/ExprNotEqual.hpp>
#include <ShaderAST/Expr/ExprQuestion.hpp>
#include <ShaderAST/Expr/ExprSwizzle.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Stmt/StmtStructureDecl.hpp>
#include <ShaderAST/Stmt/StmtVariableDecl.hpp>
#include <ShaderAST/Stmt/StmtInOutVariableDecl.hpp>
#include <ShaderAST/Type/ImageConfiguration.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <sstream>

namespace spirv
{
	//*************************************************************************

	namespace hlp
	{
		static spv::Dim getImageDim( ast::type::ImageDim dimension )
		{
			spv::Dim result{};

			switch ( dimension )
			{
			case ast::type::ImageDim::e1D:
				result = spv::Dim1D;
				break;
			case ast::type::ImageDim::e2D:
				result = spv::Dim2D;
				break;
			case ast::type::ImageDim::e3D:
				result = spv::Dim3D;
				break;
			case ast::type::ImageDim::eCube:
				result = spv::DimCube;
				break;
			case ast::type::ImageDim::eBuffer:
				result = spv::DimBuffer;
				break;
			default:
				break;
			}

			return result;
		}

		static spv::ImageFormat getImageFormat( ast::type::ImageFormat value )
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
				AST_Failure( "Unsupported ast::type::ImageFormat" );
				return spv::ImageFormatRgba32f;
			}
		}

		static void getBinOpOperands( ast::expr::Kind exprKind
			, ast::type::Kind lhsTypeKind
			, ast::type::Kind rhsTypeKind
			, ValueId lhs
			, ValueId rhs
			, ValueIdList & operands
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

			operands = makeOperands( operands.get_allocator().getAllocator(), lhs, rhs );
		}

		static InstructionPtr makeUnInstruction( NamesCache & nameCache
			, spv::Op op
			, ValueId returnTypeId
			, ValueId resultId
			, ValueId operandId )
		{
			switch ( op )
			{
			case spv::OpNot:
				return makeInstruction< UnInstructionT< spv::OpNot > >( nameCache, returnTypeId, resultId, operandId );
			case spv::OpLogicalNot:
				return makeInstruction< UnInstructionT< spv::OpLogicalNot > >( nameCache, returnTypeId, resultId, operandId );
			case spv::OpFNegate:
				return makeInstruction< UnInstructionT< spv::OpFNegate > >( nameCache, returnTypeId, resultId, operandId );
			case spv::OpSNegate:
				return makeInstruction< UnInstructionT< spv::OpSNegate > >( nameCache, returnTypeId, resultId, operandId );
			default:
				AST_Failure( "Unexpected unary operation Op" );
			}

			return nullptr;
		}

		static InstructionPtr makeBinInstruction( NamesCache & nameCache
			, spv::Op op
			, ValueId returnTypeId
			, ValueId resultId
			, ValueIdList const & operands )
		{
			switch ( op )
			{
			case spv::OpFAdd:
				return makeInstruction< BinInstructionT< spv::OpFAdd > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpIAdd:
				return makeInstruction< BinInstructionT< spv::OpIAdd > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFSub:
				return makeInstruction< BinInstructionT< spv::OpFSub > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpISub:
				return makeInstruction< BinInstructionT< spv::OpISub > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFMul:
				return makeInstruction< BinInstructionT< spv::OpFMul > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpIMul:
				return makeInstruction< BinInstructionT< spv::OpIMul > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFDiv:
				return makeInstruction< BinInstructionT< spv::OpFDiv > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpSDiv:
				return makeInstruction< BinInstructionT< spv::OpSDiv > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpUDiv:
				return makeInstruction< BinInstructionT< spv::OpUDiv > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFMod:
				return makeInstruction< BinInstructionT< spv::OpFMod > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpSMod:
				return makeInstruction< BinInstructionT< spv::OpSMod > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpUMod:
				return makeInstruction< BinInstructionT< spv::OpUMod > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpMatrixTimesMatrix:
				return makeInstruction< BinInstructionT< spv::OpMatrixTimesMatrix > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpMatrixTimesVector:
				return makeInstruction< BinInstructionT< spv::OpMatrixTimesVector > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpMatrixTimesScalar:
				return makeInstruction< BinInstructionT< spv::OpMatrixTimesScalar > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpVectorTimesMatrix:
				return makeInstruction< BinInstructionT< spv::OpVectorTimesMatrix > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpVectorTimesScalar:
				return makeInstruction< BinInstructionT< spv::OpVectorTimesScalar > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpShiftLeftLogical:
				return makeInstruction< BinInstructionT< spv::OpShiftLeftLogical > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpShiftRightLogical:
				return makeInstruction< BinInstructionT< spv::OpShiftRightLogical > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpBitwiseAnd:
				return makeInstruction< BinInstructionT< spv::OpBitwiseAnd > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpNot:
				return makeInstruction< BinInstructionT< spv::OpNot > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpBitwiseOr:
				return makeInstruction< BinInstructionT< spv::OpBitwiseOr > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpBitwiseXor:
				return makeInstruction< BinInstructionT< spv::OpBitwiseXor > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpLogicalAnd:
				return makeInstruction< BinInstructionT< spv::OpLogicalAnd > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpLogicalOr:
				return makeInstruction< BinInstructionT< spv::OpLogicalOr > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpStore:
				return makeInstruction< BinInstructionT< spv::OpStore > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFOrdEqual:
				return makeInstruction< BinInstructionT< spv::OpFOrdEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpLogicalEqual:
				return makeInstruction< BinInstructionT< spv::OpLogicalEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpIEqual:
				return makeInstruction< BinInstructionT< spv::OpIEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFOrdNotEqual:
				return makeInstruction< BinInstructionT< spv::OpFOrdNotEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpLogicalNotEqual:
				return makeInstruction< BinInstructionT< spv::OpLogicalNotEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpINotEqual:
				return makeInstruction< BinInstructionT< spv::OpINotEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFOrdGreaterThan:
				return makeInstruction< BinInstructionT< spv::OpFOrdGreaterThan > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpSGreaterThan:
				return makeInstruction< BinInstructionT< spv::OpSGreaterThan > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpUGreaterThan:
				return makeInstruction< BinInstructionT< spv::OpUGreaterThan > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFOrdGreaterThanEqual:
				return makeInstruction< BinInstructionT< spv::OpFOrdGreaterThanEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpSGreaterThanEqual:
				return makeInstruction< BinInstructionT< spv::OpSGreaterThanEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpUGreaterThanEqual:
				return makeInstruction< BinInstructionT< spv::OpUGreaterThanEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFOrdLessThan:
				return makeInstruction< BinInstructionT< spv::OpFOrdLessThan > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpSLessThan:
				return makeInstruction< BinInstructionT< spv::OpSLessThan > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpULessThan:
				return makeInstruction< BinInstructionT< spv::OpULessThan > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpFOrdLessThanEqual:
				return makeInstruction< BinInstructionT< spv::OpFOrdLessThanEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpSLessThanEqual:
				return makeInstruction< BinInstructionT< spv::OpSLessThanEqual > >( nameCache, returnTypeId, resultId, operands );
			case spv::OpULessThanEqual:
				return makeInstruction< BinInstructionT< spv::OpULessThanEqual > >( nameCache, returnTypeId, resultId, operands );
			default:
				AST_Failure( "Unexpected binary operation Op" );
			}

			return nullptr;
		}

		static bool isShaderInput( ast::Builtin builtin
			, ast::ShaderStage type )
		{
			return
				( type == ast::ShaderStage::eCompute
					&& ( builtin == ast::Builtin::eNumWorkGroups
						|| builtin == ast::Builtin::eWorkGroupID
						|| builtin == ast::Builtin::eLocalInvocationID
						|| builtin == ast::Builtin::eGlobalInvocationID
						|| builtin == ast::Builtin::eLocalInvocationIndex ) )
				|| ( ( type == ast::ShaderStage::eMeshNV || type == ast::ShaderStage::eMesh )
					&& ( builtin == ast::Builtin::eWorkGroupID
						|| builtin == ast::Builtin::eLocalInvocationID
						|| builtin == ast::Builtin::eGlobalInvocationID
						|| builtin == ast::Builtin::eLocalInvocationIndex ) )
				|| ( ( type == ast::ShaderStage::eTaskNV || type == ast::ShaderStage::eTask )
					&& ( builtin == ast::Builtin::eWorkGroupID
						|| builtin == ast::Builtin::eLocalInvocationID
						|| builtin == ast::Builtin::eGlobalInvocationID
						|| builtin == ast::Builtin::eLocalInvocationIndex ) )
				|| ( type == ast::ShaderStage::eFragment
					&& ( builtin == ast::Builtin::eFragCoord
						|| builtin == ast::Builtin::eFrontFacing
						|| builtin == ast::Builtin::ePointCoord
						|| builtin == ast::Builtin::eSampleID
						|| builtin == ast::Builtin::eSamplePosition
						|| builtin == ast::Builtin::eSampleMaskIn
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eLayer
						|| builtin == ast::Builtin::eViewportIndex ) )
				|| ( type == ast::ShaderStage::eGeometry
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::ePrimitiveIDIn
						|| builtin == ast::Builtin::eInvocationID ) )
				|| ( type == ast::ShaderStage::eTessellationControl
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::ePatchVerticesIn
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eInvocationID ) )
				|| ( type == ast::ShaderStage::eTessellationEvaluation
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eTessCoord
						|| builtin == ast::Builtin::ePatchVerticesIn
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eTessLevelInner
						|| builtin == ast::Builtin::eTessLevelOuter ) )
				|| ( type == ast::ShaderStage::eVertex
					&& ( builtin == ast::Builtin::eVertexIndex
						|| builtin == ast::Builtin::eInstanceIndex
						|| builtin == ast::Builtin::eDrawIndex
						|| builtin == ast::Builtin::eBaseVertex
						|| builtin == ast::Builtin::eBaseInstance
						|| builtin == ast::Builtin::eTessLevelOuter ) )
				// Ray tracing stages only have input built-ins
				|| isRayTraceStage( type );
		}

		static bool isShaderOutput( ast::Builtin builtin
			, ast::ShaderStage type )
		{
			return
				( type == ast::ShaderStage::eFragment
					&& ( builtin == ast::Builtin::eFragDepth
						|| builtin == ast::Builtin::eSampleMask
						|| builtin == ast::Builtin::eFragStencilRefEXT ) )
				|| ( type == ast::ShaderStage::eGeometry
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eCullDistance
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eLayer
						|| builtin == ast::Builtin::eViewportIndex ) )
				|| ( type == ast::ShaderStage::eTessellationControl
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eCullDistance
						|| builtin == ast::Builtin::eTessLevelInner
						|| builtin == ast::Builtin::eTessLevelOuter ) )
				|| ( type == ast::ShaderStage::eTessellationEvaluation
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance ) )
				|| ( type == ast::ShaderStage::eVertex
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eCullDistance ) )
				|| ( ( type == ast::ShaderStage::eMeshNV || type == ast::ShaderStage::eMesh )
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eCullDistance
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eLayer
						|| builtin == ast::Builtin::eViewportIndex
						|| builtin == ast::Builtin::eViewportMaskNV ) );
		}

		static uint32_t getMajor( uint32_t spvVersion )
		{
			return ( spvVersion >> 16u );
		}

		static uint32_t getMinor( uint32_t spvVersion )
		{
			return ( ( spvVersion >> 8u ) & 0xFF );
		}

		static std::string printSpvVersion( uint32_t spvVersion )
		{
			std::stringstream stream;
			stream << getMajor( spvVersion ) << "." << getMinor( spvVersion );
			return stream.str();
		}

		static void checkType( ast::type::Kind kind
			, ModuleConfig & config )
		{
			if ( isDoubleType( kind ) )
			{
				config.registerCapability( spv::CapabilityFloat64 );
			}
			else if ( isHalfType( kind ) )
			{
				config.registerCapability( spv::CapabilityFloat16 );
			}
			else if ( isUnsignedInt8Type( kind ) || isSignedInt8Type( kind ) )
			{
				config.registerCapability( spv::CapabilityInt8 );
				config.registerCapability( spv::CapabilityStorageBuffer8BitAccess );
			}
			else if ( isUnsignedInt16Type( kind ) || isSignedInt16Type( kind ) )
			{
				config.registerCapability( spv::CapabilityInt16 );
				config.registerCapability( spv::CapabilityStorageBuffer16BitAccess );
			}
			else if ( isUnsignedInt64Type( kind ) || isSignedInt64Type( kind ) )
			{
				config.registerCapability( spv::CapabilityInt64 );
			}
			else if ( isAccelerationStructureType( kind ) )
			{
				if ( isRayTraceStage( config.stage ) )
				{
					config.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					config.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}
		}

		static void checkType( ast::type::ImageConfiguration const & image
			, uint32_t arraySize
			, bool sampled
			, ModuleConfig & config )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				config.registerCapability( spv::CapabilityRuntimeDescriptorArray );
			}

			switch ( image.format )
			{
			case ast::type::ImageFormat::eRg32f:
			case ast::type::ImageFormat::eRg16f:
			case ast::type::ImageFormat::eR32f:
			case ast::type::ImageFormat::eR16f:
			case ast::type::ImageFormat::eRg32i:
			case ast::type::ImageFormat::eRg16i:
			case ast::type::ImageFormat::eRg8i:
			case ast::type::ImageFormat::eR32i:
			case ast::type::ImageFormat::eR16i:
			case ast::type::ImageFormat::eR8i:
			case ast::type::ImageFormat::eRg32u:
			case ast::type::ImageFormat::eRg16u:
			case ast::type::ImageFormat::eRg8u:
			case ast::type::ImageFormat::eR32u:
			case ast::type::ImageFormat::eR16u:
			case ast::type::ImageFormat::eR8u:
				config.registerCapability( spv::CapabilityStorageImageExtendedFormats );
				break;
			default:
				break;
			}

			if ( sampled )
			{
				if ( image.dimension == ast::type::ImageDim::e1D )
				{
					config.registerCapability( spv::CapabilitySampled1D );
				}

				if ( image.dimension == ast::type::ImageDim::eBuffer )
				{
					config.registerCapability( spv::CapabilitySampledBuffer );
				}
			}
		}

		static void checkType( ast::type::Image const & type
			, uint32_t arraySize
			, ModuleConfig & config )
		{
			checkType( type.getConfig(), arraySize, false, config );
		}

		static void checkType( ast::type::SampledImage const & type
			, uint32_t arraySize
			, ModuleConfig & config )
		{
			checkType( type.getConfig(), arraySize, true, config );
		}

		static void checkType( ast::type::CombinedImage const & type
			, uint32_t arraySize
			, ModuleConfig & config )
		{
			checkType( type.getConfig(), arraySize, true, config );
		}
	}

	//*********************************************************************************************

	void checkType( ast::type::TypePtr ptype
		, ModuleConfig & config )
	{
		traverseType( ptype, 1u
			, [&config]( ast::type::TypePtr type
				, uint32_t arraySize )
			{
				switch ( type->getRawKind() )
				{
				case ast::type::Kind::eImage:
					hlp::checkType( static_cast< ast::type::Image const & >( *type ), arraySize, config );
					break;
				case ast::type::Kind::eCombinedImage:
					hlp::checkType( static_cast< ast::type::CombinedImage const & >( *type ), arraySize, config );
					break;
				case ast::type::Kind::eSampledImage:
					hlp::checkType( static_cast< ast::type::SampledImage const & >( *type ), arraySize, config );
					break;
				case ast::type::Kind::eSampler:
				case ast::type::Kind::eAccelerationStructure:
					return;
				default:
					hlp::checkType( type->getKind(), config );
					break;
				}
			} );
	}

	void checkBuiltin( ast::Builtin builtin
		, ast::ShaderStage stage
		, ModuleConfig & config )
	{
		switch ( builtin )
		{
		case ast::Builtin::ePosition:
		case ast::Builtin::ePointSize:
			config.registerCapability( spv::CapabilityShader );
			break;
		case ast::Builtin::eClipDistance:
			config.registerCapability( spv::CapabilityClipDistance );
			break;
		case ast::Builtin::eCullDistance:
			config.registerCapability( spv::CapabilityCullDistance );
			break;
		case ast::Builtin::ePrimitiveID:
			if ( stage == ast::ShaderStage::eMeshNV )
			{
				config.registerCapability( spv::CapabilityMeshShadingNV );
			}
			else if ( stage == ast::ShaderStage::eMesh )
			{
				config.registerCapability( spv::CapabilityMeshShadingEXT );
			}
			else if ( !isRayTraceStage( stage ) )
			{
				config.registerCapability( spv::CapabilityGeometry );
			}
			break;
		case ast::Builtin::ePrimitiveIDIn:
		case ast::Builtin::eInvocationID:
			// Tessellation or Geometry
			break;
		case ast::Builtin::eLayer:
			if ( stage == ast::ShaderStage::eMeshNV )
			{
				config.registerCapability( spv::CapabilityMeshShadingNV );
			}
			else if ( stage == ast::ShaderStage::eMesh )
			{
				config.registerCapability( spv::CapabilityMeshShadingEXT );
			}
			else if ( stage == ast::ShaderStage::eGeometry )
			{
				config.registerCapability( spv::CapabilityGeometry );
			}
			else
			{
				config.registerCapability( spv::CapabilityShaderLayer );
			}
			break;
		case ast::Builtin::eViewportIndex:
			if ( stage == ast::ShaderStage::eMeshNV )
			{
				config.registerCapability( spv::CapabilityMeshShadingNV );
			}
			else if ( stage == ast::ShaderStage::eMesh )
			{
				config.registerCapability( spv::CapabilityMeshShadingEXT );
			}
			else
			{
				config.registerCapability( spv::CapabilityMultiViewport );
			}
			break;
		case ast::Builtin::eTessLevelOuter:
		case ast::Builtin::eTessLevelInner:
		case ast::Builtin::eTessCoord:
		case ast::Builtin::ePatchVertices:
		case ast::Builtin::ePatchVerticesIn:
			config.registerCapability( spv::CapabilityTessellation );
			break;
		case ast::Builtin::eFragCoord:
		case ast::Builtin::ePointCoord:
		case ast::Builtin::eFrontFacing:
			config.registerCapability( spv::CapabilityShader );
			break;
		case ast::Builtin::eSampleID:
		case ast::Builtin::eSamplePosition:
			config.registerCapability( spv::CapabilitySampleRateShading );
			break;
		case ast::Builtin::eSampleMask:
		case ast::Builtin::eSampleMaskIn:
		case ast::Builtin::eHelperInvocation:
			config.registerCapability( spv::CapabilityShader );
			break;
		case ast::Builtin::eFragDepth:
			config.registerCapability( spv::CapabilityShader );
			config.executionModes.insert( spv::ExecutionModeDepthReplacing );
			break;
		case ast::Builtin::eNumWorkGroups:
			break;
		case ast::Builtin::eWorkGroupSize:
			break;
		case ast::Builtin::eWorkGroupID:
		case ast::Builtin::eLocalInvocationID:
		case ast::Builtin::eGlobalInvocationID:
		case ast::Builtin::eLocalInvocationIndex:
			if ( isMeshNVStage( stage ) )
			{
				config.registerCapability( spv::CapabilityMeshShadingNV );
			}
			else if ( isMeshStage( stage ) )
			{
				config.registerCapability( spv::CapabilityMeshShadingEXT );
			}
			break;
		case ast::Builtin::eWorkDim:
		case ast::Builtin::eGlobalSize:
		case ast::Builtin::eEnqueuedWorkgroupSize:
		case ast::Builtin::eGlobalLinearID:
		case ast::Builtin::eNumEnqueuedSubgroups:
			config.registerCapability( spv::CapabilityKernel );
			break;
		case ast::Builtin::eVertexIndex:
		case ast::Builtin::eInstanceIndex:
		case ast::Builtin::eInstanceID:
			config.registerCapability( spv::CapabilityShader );
			break;
		case ast::Builtin::eSubgroupSize:
		case ast::Builtin::eSubgroupMaxSize:
		case ast::Builtin::eNumSubgroups:
		case ast::Builtin::eSubgroupID:
		case ast::Builtin::eSubgroupLocalInvocationID:
		case ast::Builtin::eSubgroupEqMask:
		case ast::Builtin::eSubgroupGeMask:
		case ast::Builtin::eSubgroupGtMask:
		case ast::Builtin::eSubgroupLeMask:
		case ast::Builtin::eSubgroupLtMask:
			config.registerCapability( spv::CapabilityGroupNonUniformBallot );
			break;
		case ast::Builtin::eBaseVertex:
		case ast::Builtin::eBaseInstance:
		case ast::Builtin::eDrawIndex:
			config.registerCapability( spv::CapabilityDrawParameters );
			break;
		case ast::Builtin::eDeviceIndex:
			config.registerCapability( spv::CapabilityDeviceGroup );
			break;
		case ast::Builtin::eViewIndex:
			config.registerCapability( spv::CapabilityMultiView );
			break;
		case ast::Builtin::eBaryCoordNoPerspAMD:
			break;
		case ast::Builtin::eBaryCoordNoPerspCentroidAMD:
			break;
		case ast::Builtin::eBaryCoordNoPerspSampleAMD:
			break;
		case ast::Builtin::eBaryCoordSmoothAMD:
			break;
		case ast::Builtin::eBaryCoordSmoothCentroidAMD:
			break;
		case ast::Builtin::eBaryCoordSmoothSampleAMD:
			break;
		case ast::Builtin::eBaryCoordPullModelAMD:
			break;
		case ast::Builtin::eFragStencilRefEXT:
			config.registerCapability( spv::CapabilityStencilExportEXT );
			break;
		case ast::Builtin::eViewportMaskNV:
			if ( stage == ast::ShaderStage::eMeshNV )
			{
				config.registerCapability( spv::CapabilityMeshShadingNV );
			}
			else if ( stage == ast::ShaderStage::eMesh )
			{
				config.registerCapability( spv::CapabilityMeshShadingEXT );
			}
			else
			{
				config.registerCapability( spv::CapabilityShaderViewportMaskNV );
			}
			break;
		case ast::Builtin::eSecondaryPositionNV:
		case ast::Builtin::eSecondaryViewportMaskNV:
			config.registerCapability( spv::CapabilityShaderStereoViewNV );
			break;
		case ast::Builtin::ePositionPerViewNV:
		case ast::Builtin::eViewportMaskPerViewNV:
			config.registerCapability( spv::CapabilityPerViewAttributesNV );
			break;
		case ast::Builtin::eLaunchID:
		case ast::Builtin::eLaunchSize:
		case ast::Builtin::eInstanceCustomIndex:
		case ast::Builtin::eGeometryIndex:
		case ast::Builtin::eWorldRayOrigin:
		case ast::Builtin::eWorldRayDirection:
		case ast::Builtin::eObjectRayOrigin:
		case ast::Builtin::eObjectRayDirection:
		case ast::Builtin::eRayTmin:
		case ast::Builtin::eRayTmax:
		case ast::Builtin::eIncomingRayFlags:
		case ast::Builtin::eHitKind:
		case ast::Builtin::eObjectToWorld:
		case ast::Builtin::eWorldToObject:
			if ( isRayTraceStage( config.stage ) )
			{
				config.registerCapability( spv::CapabilityRayTracingKHR );
			}
			else
			{
				config.registerCapability( spv::CapabilityRayQueryKHR );
			}
			break;
		default:
			break;
		}
	}

	//*********************************************************************************************

	IOMapping::IOMapping( ast::ShaderAllocatorBlock * alloc
		, ast::type::TypesCache & ptypesCache
		, ast::ShaderStage pstage
		, bool pisInput
		, uint32_t & pnextVarId )
		: typesCache{ ptypesCache }
		, stage{ pstage }
		, isInput{ pisInput }
		, nextVarId{ &pnextVarId }
		, splitVarsBuiltins{ alloc }
		, splitVarsOthers{ alloc }
		, m_pending{ alloc }
		, m_pendingMbr{ alloc }
		, m_processedBuiltins{ alloc }
		, m_processedIOs{ alloc }
	{
	}

	void IOMapping::addPatch( ast::var::VariablePtr patchVar )
	{
		m_processed.push_back( patchVar );
	}

	ast::var::VariablePtr IOMapping::getPatch( ast::var::VariablePtr patchVar )
	{
		if ( auto splitIt = splitVarsOthers.find( patchVar );
			splitIt != splitVarsOthers.end() )
		{
			patchVar = splitIt->second.first;
		}

		return patchVar;
	}

	void IOMapping::add( ast::var::VariablePtr var )
	{
		m_processed.push_back( var );
	}

	void IOMapping::addPending( ast::var::VariablePtr pendingVar
		, uint32_t location )
	{
		auto [it, res] = m_pending.try_emplace(pendingVar->getEntityName());

		if ( res )
		{
			it->second.location = location;
			it->second.arraySize = ast::type::NotArray;
			it->second.flags = pendingVar->getFlags();
			it->second.var = pendingVar;
		}
	}

	void IOMapping::addPendingMbr( ast::var::VariablePtr outerVar
		, uint32_t mbrIndex
		, uint64_t flags
		, uint32_t location
		, uint32_t arraySize )
	{
		auto it = std::find_if( m_pendingMbr.begin()
			, m_pendingMbr.end()
			, [&outerVar, &mbrIndex]( PendingMbrIO const & lookup )
			{
				return lookup.index == mbrIndex
					&& lookup.outer == outerVar;
			} );

		if ( it == m_pendingMbr.end() )
		{
			PendingIO io{};
			io.location = location;
			io.arraySize = arraySize;
			io.flags = flags;
			m_pendingMbr.emplace_back( outerVar, mbrIndex, io );
		}
	}

	void IOMapping::addPendingMbr( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location
		, uint32_t arraySize )
	{
		auto ident = ast::findIdentifier( outer );
		assert( ident );
		addPendingMbr( ident->getVariable()
			, mbrIndex
			, flags.getFlags()
			, location
			, arraySize );
	}

	ast::expr::ExprPtr IOMapping::processPendingMbr( ast::expr::ExprCache & exprCache
		, ast::var::VariablePtr outerVar
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & pflags
		, ast::stmt::Container * cont )
	{
		if ( !pflags.isShaderInput() && !pflags.isShaderOutput() )
		{
			return nullptr;
		}

		if ( !pflags.isBuiltin() )
		{
			auto splitIt = splitVarsOthers.find( outerVar );

			if ( splitIt != splitVarsOthers.end() )
			{
				return exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, splitIt->second.first )
					, mbrIndex
					, pflags.getFlags() );
			}
		}

		auto it = std::find_if( m_pendingMbr.begin()
			, m_pendingMbr.end()
			, [&outerVar, &mbrIndex]( PendingMbrIO const & lookup )
			{
				return lookup.index == mbrIndex
					&& lookup.outer == outerVar;
			} );

		if ( m_pendingMbr.end() == it )
		{
			return nullptr;
		}

		auto & mbr = *it;

		if ( !mbr.io.result.var )
		{
			ast::type::StructPtr structType;
			mbrIndex = mbr.index;

			if ( mbr.io.flags & uint64_t( ast::var::Flag::eBuiltin ) )
			{
				auto splitIt = splitVarsBuiltins.find( mbr.outer );

				if ( splitIt != splitVarsBuiltins.end() )
				{
					structType = getStructType( splitIt->second.first->getType() );
					mbrIndex -= splitIt->second.second;
				}
			}

			if ( !structType )
			{
				structType = getStructType( mbr.outer->getType() );
			}

			mbr.io.result = processPendingType( *structType
				, mbrIndex
				, mbr.io.flags
				, mbr.io.location
				, mbr.io.arraySize
				, cont );
		}

		return exprCache.makeIdentifier( typesCache, mbr.io.result.var );
	}

	ast::expr::ExprPtr IOMapping::processPendingMbr( ast::expr::ExprCache & exprCache
		, ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & pflags
		, ExprAdapter & adapter
		, ast::stmt::Container * cont )
	{
		if ( !pflags.isShaderInput() && !pflags.isShaderOutput() )
		{
			return nullptr;
		}

		auto ident = ast::findIdentifier( outer );

		if ( !ident )
		{
			return nullptr;
		}

		auto result = processPendingMbr( exprCache
			, ident->getVariable()
			, mbrIndex
			, pflags
			, cont );

		if ( result
			&& outer.getKind() == ast::expr::Kind::eArrayAccess )
		{
			auto type = result->getType();
			assert( type->getKind() == ast::type::Kind::eArray );
			auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( outer );
			result = exprCache.makeArrayAccess( static_cast< ast::type::Array const & >( *type ).getType()
				, std::move( result )
				, adapter.doSubmit( arrayAccess.getRHS() ) );
		}

		return result;
	}

	ast::expr::ExprPtr IOMapping::processPending( ast::expr::ExprCache & exprCache
		, ast::Builtin builtin
		, ast::stmt::Container * cont )
	{
		for ( auto & pending : m_pendingMbr )
		{
			if ( isStructType( pending.outer->getType() ) )
			{
				auto structType = getStructType( pending.outer->getType() );
				auto mbrIndex = structType->findMember( builtin );

				if ( mbrIndex != ast::type::Struct::NotFound )
				{
					return processPendingMbr( exprCache
						, pending.outer
						, mbrIndex
						, ast::var::FlagHolder{ pending.io.flags }
						, cont );
				}
			}
		}

		return nullptr;
	}

	ast::expr::ExprPtr IOMapping::processPending( ast::expr::ExprCache & exprCache
		, ast::EntityName const & name
		, ast::stmt::Container * cont )
	{
		auto it = m_pending.find( name );

		if ( m_pending.end() == it )
		{
			return nullptr;
		}

		auto & [_, mbrIo] = *it;
		auto const & pendingVar = *mbrIo.var;
		auto type = pendingVar.getType();
		auto location = it->second.location;

		if ( !mbrIo.result.var )
		{
			mbrIo.result = processPendingType( type
				, pendingVar.getName()
				, pendingVar.isBuiltin() ? pendingVar.getBuiltin() : ast::Builtin::eNone
				, mbrIo.flags
				, location
				, mbrIo.arraySize
				, cont );
		}

		return exprCache.makeIdentifier( typesCache, mbrIo.result.var );
	}

	ast::expr::ExprPtr IOMapping::processPending( ast::expr::ExprCache & exprCache
		, ast::var::VariablePtr srcVar
		, ast::stmt::Container * cont )
	{
		if ( auto result = processPending( exprCache
			, srcVar->getEntityName()
			, cont ) )
		{
			return result;
		}

		return exprCache.makeIdentifier( srcVar->getType()->getTypesCache()
				, srcVar );
	}

	bool IOMapping::isValid( ast::Builtin builtin )const
	{
		if ( isInput )
		{
			return hlp::isShaderInput( builtin, stage );
		}

		return hlp::isShaderOutput( builtin, stage );
	}

	PendingResult IOMapping::processPendingType( ast::type::TypePtr type
		, std::string const & name
		, ast::Builtin builtin
		, uint64_t flags
		, uint32_t location
		, uint32_t arraySize
		, ast::stmt::Container * cont )
	{
		auto compType = getComponentType( type );

		if ( stage != ast::ShaderStage::eCompute
			&& !isMeshStage( stage )
			&& !isRayTraceStage( stage )
			&& ( isSignedIntType( compType ) || isUnsignedIntType( compType ) ) )
		{
			if ( isInput )
			{
				if ( stage != ast::ShaderStage::eVertex )
				{
					flags = flags | ast::var::Flag::eFlat;
				}
			}
			else if ( stage != ast::ShaderStage::eFragment )
			{
				flags = flags | ast::var::Flag::eFlat;
			}
		}

		if ( builtin == ast::Builtin::ePrimitiveIndicesNV )
		{
			arraySize *= getComponentCount( type );
			type = type->getTypesCache().getBasicType( compType );
		}

		if ( arraySize != ast::type::NotArray )
		{
			type = type->getTypesCache().getArray( type, arraySize );
		}

		if ( builtin == ast::Builtin::eTessLevelOuter )
		{
			type = typesCache.getArray( typesCache.getFloat(), 4u );
		}
		else if ( builtin == ast::Builtin::eTessLevelInner )
		{
			type = typesCache.getArray( typesCache.getFloat(), 2u );
		}

		if ( builtin != ast::Builtin::eNone )
		{
			auto [it, res] = m_processedBuiltins.try_emplace( builtin );

			if ( res )
			{
				++( *nextVarId );
				it->second = ast::var::makeBuiltin( *nextVarId
					, builtin
					, type
					, flags );
				m_processed.push_back( it->second );
				cont->addStmt( cont->getStmtCache().makeInOutVariableDecl( it->second
					, location ) );
			}

			return { it->second };
		}

		auto [it, res] = m_processedIOs.try_emplace( name );

		if ( res )
		{
			auto prefix = isInput ? std::string{ "sdwIn_" } : std::string{ "sdwOut_" };
			++( *nextVarId );
			it->second = ast::var::makeVariable( { *nextVarId, prefix + name }
				, type
				, flags );
			m_processed.push_back( it->second );
			cont->addStmt( cont->getStmtCache().makeInOutVariableDecl( it->second
				, location ) );
		}

		return { it->second };
	}

	PendingResult IOMapping::processPendingType( ast::type::Struct const & structType
		, uint32_t mbrIndex
		, uint64_t mbrFlags
		, uint32_t mbrLocation
		, uint32_t mbrArraySize
		, ast::stmt::Container * cont )
	{
		auto & mbr = *std::next( structType.begin(), ptrdiff_t( mbrIndex ) );
		return processPendingType( mbr.type
			, mbr.name
			, mbr.builtin
			, mbrFlags
			, mbrLocation
			, mbrArraySize
			, cont );
	}

	//*************************************************************************

	ModuleConfig::ModuleConfig( ast::ShaderAllocatorBlock * alloc
		, SpirVConfig & pspirvConfig
		, ast::type::TypesCache & typesCache
		, ast::ShaderStage pstage
		, uint32_t pnextVarId
		, uint32_t paliasId )
		: nextVarId{ pnextVarId }
		, aliasId{ paliasId }
		, stage{ pstage }
		, executionModes{ alloc }
		, spirvConfig{ pspirvConfig }
		, inputs{ alloc, typesCache, stage, true, nextVarId }
		, outputs{ alloc, typesCache, stage, false, nextVarId }
		, requiredCapabilities{ alloc }
	{
		if ( spirvConfig.debugLevel == DebugLevel::eDebugInfo )
		{
			registerExtension( KHR_non_semantic_info );
		}
	}

	void ModuleConfig::registerCapability( spv::Capability capability )
	{
		bool add = true;

		switch ( capability )
		{
		case spv::CapabilityMatrix:
			break;
		case spv::CapabilityShader:
			break;
		case spv::CapabilityGeometry:
			break;
		case spv::CapabilityTessellation:
			break;
		case spv::CapabilityAddresses:
			break;
		case spv::CapabilityLinkage:
			break;
		case spv::CapabilityKernel:
			break;
		case spv::CapabilityVector16:
			break;
		case spv::CapabilityFloat16Buffer:
			break;
		case spv::CapabilityFloat16:
			break;
		case spv::CapabilityFloat64:
			break;
		case spv::CapabilityInt64:
			break;
		case spv::CapabilityInt64Atomics:
			break;
		case spv::CapabilityImageBasic:
			break;
		case spv::CapabilityImageReadWrite:
			break;
		case spv::CapabilityImageMipmap:
			break;
		case spv::CapabilityPipes:
			break;
		case spv::CapabilityGroups:
			break;
		case spv::CapabilityDeviceEnqueue:
			break;
		case spv::CapabilityLiteralSampler:
			break;
		case spv::CapabilityAtomicStorage:
			break;
		case spv::CapabilityInt16:
			break;
		case spv::CapabilityTessellationPointSize:
			break;
		case spv::CapabilityGeometryPointSize:
			break;
		case spv::CapabilityImageGatherExtended:
			break;
		case spv::CapabilityStorageImageMultisample:
			break;
		case spv::CapabilityUniformBufferArrayDynamicIndexing:
			break;
		case spv::CapabilitySampledImageArrayDynamicIndexing:
			break;
		case spv::CapabilityStorageBufferArrayDynamicIndexing:
			break;
		case spv::CapabilityStorageImageArrayDynamicIndexing:
			break;
		case spv::CapabilityClipDistance:
			break;
		case spv::CapabilityCullDistance:
			break;
		case spv::CapabilityImageCubeArray:
			break;
		case spv::CapabilitySampleRateShading:
			break;
		case spv::CapabilityImageRect:
			break;
		case spv::CapabilitySampledRect:
			break;
		case spv::CapabilityGenericPointer:
			break;
		case spv::CapabilityInt8:
			break;
		case spv::CapabilityInputAttachment:
			break;
		case spv::CapabilitySparseResidency:
			break;
		case spv::CapabilityMinLod:
			break;
		case spv::CapabilitySampled1D:
			break;
		case spv::CapabilityImage1D:
			break;
		case spv::CapabilitySampledCubeArray:
			break;
		case spv::CapabilitySampledBuffer:
			break;
		case spv::CapabilityImageBuffer:
			break;
		case spv::CapabilityImageMSArray:
			break;
		case spv::CapabilityStorageImageExtendedFormats:
			break;
		case spv::CapabilityImageQuery:
			break;
		case spv::CapabilityDerivativeControl:
			break;
		case spv::CapabilityInterpolationFunction:
			break;
		case spv::CapabilityTransformFeedback:
			break;
		case spv::CapabilityGeometryStreams:
			break;
		case spv::CapabilityStorageImageReadWithoutFormat:
			break;
		case spv::CapabilityStorageImageWriteWithoutFormat:
			break;
		case spv::CapabilityMultiViewport:
			break;
		case spv::CapabilitySubgroupDispatch:
			break;
		case spv::CapabilityNamedBarrier:
			break;
		case spv::CapabilityPipeStorage:
			break;
		case spv::CapabilityGroupNonUniform:
		case spv::CapabilityGroupNonUniformVote:
		case spv::CapabilityGroupNonUniformArithmetic:
		case spv::CapabilityGroupNonUniformBallot:
		case spv::CapabilityGroupNonUniformShuffle:
		case spv::CapabilityGroupNonUniformShuffleRelative:
		case spv::CapabilityGroupNonUniformClustered:
		case spv::CapabilityGroupNonUniformQuad:
			registerExtension( KHR_shader_subgroup );
			break;
		case spv::CapabilityShaderLayer:
			registerExtension( EXT_shader_viewport_index_layer );
			break;
		case spv::CapabilityShaderViewportIndex:
			break;
		case spv::CapabilitySubgroupBallotKHR:
			registerExtension( KHR_shader_ballot );
			break;
		case spv::CapabilityDrawParameters:
			registerExtension( KHR_shader_draw_parameters );
			break;
		case spv::CapabilitySubgroupVoteKHR:
			break;
		case spv::CapabilityStorageBuffer16BitAccess:
			registerExtension( KHR_16bit_storage );
			break;
		case spv::CapabilityStorageUniform16:
			break;
		case spv::CapabilityStoragePushConstant16:
			break;
		case spv::CapabilityStorageInputOutput16:
			break;
		case spv::CapabilityDeviceGroup:
			registerExtension( KHR_device_group );
			break;
		case spv::CapabilityMultiView:
			registerExtension( KHR_multiview );
			break;
		case spv::CapabilityVariablePointersStorageBuffer:
			break;
		case spv::CapabilityVariablePointers:
			break;
		case spv::CapabilityAtomicStorageOps:
			break;
		case spv::CapabilitySampleMaskPostDepthCoverage:
			break;
		case spv::CapabilityStorageBuffer8BitAccess:
			registerExtension( KHR_8bit_storage );
			break;
		case spv::CapabilityUniformAndStorageBuffer8BitAccess:
			break;
		case spv::CapabilityStoragePushConstant8:
			break;
		case spv::CapabilityDenormPreserve:
			break;
		case spv::CapabilityDenormFlushToZero:
			break;
		case spv::CapabilitySignedZeroInfNanPreserve:
			break;
		case spv::CapabilityRoundingModeRTE:
			break;
		case spv::CapabilityRoundingModeRTZ:
			break;
		case spv::CapabilityRayQueryProvisionalKHR:
			registerExtension( KHR_ray_query );
			break;
		case spv::CapabilityFloat16ImageAMD:
			break;
		case spv::CapabilityImageGatherBiasLodAMD:
			break;
		case spv::CapabilityFragmentMaskAMD:
			break;
		case spv::CapabilityStencilExportEXT:
			registerExtension( EXT_shader_stencil_export );
			break;
		case spv::CapabilityImageReadWriteLodAMD:
			break;
		case spv::CapabilityShaderClockKHR:
			break;
		case spv::CapabilitySampleMaskOverrideCoverageNV:
			break;
		case spv::CapabilityGeometryShaderPassthroughNV:
			break;
		case spv::CapabilityShaderViewportIndexLayerEXT:
			break;
		case spv::CapabilityShaderViewportMaskNV:
			registerExtension( NV_viewport_array2 );
			break;
		case spv::CapabilityShaderStereoViewNV:
			registerExtension( NV_stereo_view_rendering );
			break;
		case spv::CapabilityPerViewAttributesNV:
			registerExtension( NVX_multiview_per_view_attributes );
			break;
		case spv::CapabilityFragmentFullyCoveredEXT:
			break;
		case spv::CapabilityMeshShadingNV:
			registerExtension( NV_mesh_shader );
			break;
		case spv::CapabilityImageFootprintNV:
			break;
		case spv::CapabilityMeshShadingEXT:
			registerExtension( EXT_mesh_shader );
			break;
		case spv::CapabilityFragmentBarycentricNV:
			break;
		case spv::CapabilityComputeDerivativeGroupQuadsNV:
			if ( registerExtension( NV_compute_shader_derivatives, true ) )
			{
				executionModes.insert( spv::ExecutionModeDerivativeGroupQuadsNV );
			}
			break;
		case spv::CapabilityFragmentDensityEXT:
			break;
		case spv::CapabilityGroupNonUniformPartitionedNV:
			break;
		case spv::CapabilityShaderNonUniform:
			break;
		case spv::CapabilityRuntimeDescriptorArray:
			registerExtension( EXT_descriptor_indexing );
			break;
		case spv::CapabilityInputAttachmentArrayDynamicIndexing:
			break;
		case spv::CapabilityUniformTexelBufferArrayDynamicIndexing:
			break;
		case spv::CapabilityStorageTexelBufferArrayDynamicIndexing:
			break;
		case spv::CapabilityUniformBufferArrayNonUniformIndexing:
			break;
		case spv::CapabilitySampledImageArrayNonUniformIndexing:
			break;
		case spv::CapabilityStorageBufferArrayNonUniformIndexing:
			break;
		case spv::CapabilityStorageImageArrayNonUniformIndexing:
			break;
		case spv::CapabilityInputAttachmentArrayNonUniformIndexing:
			break;
		case spv::CapabilityUniformTexelBufferArrayNonUniformIndexing:
			break;
		case spv::CapabilityStorageTexelBufferArrayNonUniformIndexing:
			break;
		case spv::CapabilityRayTracingNV:
			break;
		case spv::CapabilityVulkanMemoryModel:
			break;
		case spv::CapabilityVulkanMemoryModelDeviceScope:
			break;
		case spv::CapabilityPhysicalStorageBufferAddresses:
			registerExtension( EXT_physical_storage_buffer );
			break;
		case spv::CapabilityComputeDerivativeGroupLinearNV:
			break;
		case spv::CapabilityCooperativeMatrixNV:
			break;
		case spv::CapabilityFragmentShaderSampleInterlockEXT:
			break;
		case spv::CapabilityFragmentShaderShadingRateInterlockEXT:
			break;
		case spv::CapabilityShaderSMBuiltinsNV:
			break;
		case spv::CapabilityFragmentShaderPixelInterlockEXT:
			break;
		case spv::CapabilityDemoteToHelperInvocationEXT:
			add = registerExtension( EXT_demote_to_helper_invocation, true );
			break;
		case spv::CapabilitySubgroupShuffleINTEL:
			break;
		case spv::CapabilitySubgroupBufferBlockIOINTEL:
			break;
		case spv::CapabilitySubgroupImageBlockIOINTEL:
			break;
		case spv::CapabilitySubgroupImageMediaBlockIOINTEL:
			break;
		case spv::CapabilityIntegerFunctions2INTEL:
			break;
		case spv::CapabilityFunctionPointersINTEL:
			break;
		case spv::CapabilityIndirectReferencesINTEL:
			break;
		case spv::CapabilitySubgroupAvcMotionEstimationINTEL:
			break;
		case spv::CapabilitySubgroupAvcMotionEstimationIntraINTEL:
			break;
		case spv::CapabilitySubgroupAvcMotionEstimationChromaINTEL:
			break;
		case spv::CapabilityFPGAMemoryAttributesINTEL:
			break;
		case spv::CapabilityUnstructuredLoopControlsINTEL:
			break;
		case spv::CapabilityFPGALoopControlsINTEL:
			break;
		case spv::CapabilityKernelAttributesINTEL:
			break;
		case spv::CapabilityFPGAKernelAttributesINTEL:
			break;
		case spv::CapabilityBlockingPipesINTEL:
			break;
		case spv::CapabilityFPGARegINTEL:
			break;
		case spv::CapabilityAtomicFloat32AddEXT:
		case spv::CapabilityAtomicFloat64AddEXT:
			registerExtension( EXT_shader_atomic_float_add );
			break;
		case spv::CapabilityRayTraversalPrimitiveCullingKHR:
			registerExtension( KHR_ray_tracing );
			break;
		case spv::CapabilityRayTracingProvisionalKHR:
			registerExtension( KHR_ray_tracing );
			break;
		case spv::CapabilityRayTracingKHR:
			registerExtension( KHR_ray_tracing );
			break;
		case spv::CapabilityMax:
			break;
		default:
			break;
		}

		if ( add )
		{
			requiredCapabilities.insert( capability );
		}
	}

	bool ModuleConfig::registerExtension( SpirVExtension extension
		, bool optional )
	{
		if ( optional )
		{
			if ( spirvConfig.specVersion >= extension.specVersion 
				&& ( !spirvConfig.availableExtensions
					|| spirvConfig.availableExtensions->contains( extension ) ) )
			{
				requiredExtensions.insert( extension );
				spirvConfig.requiredExtensions.insert( std::move( extension ) );
				return true;
			}

			return false;
		}

		if ( spirvConfig.specVersion < extension.specVersion )
		{
			if ( extension.isMarker )
			{
				throw ast::Exception{ "SPIR-V specification version (" + hlp::printSpvVersion( spirvConfig.specVersion )
					+ ") doesn't support [" + extension.name
					+ "] (required version: " + hlp::printSpvVersion( extension.specVersion ) + ")" };
			}

			throw ast::Exception{ "SPIR-V specification version (" + hlp::printSpvVersion( spirvConfig.specVersion )
				+ ") doesn't support extension [" + extension.name
				+ "] (required version: " + hlp::printSpvVersion( extension.specVersion ) + ")" };
		}

		if ( spirvConfig.availableExtensions
			&& !spirvConfig.availableExtensions->contains( extension ) )
		{
			throw ast::Exception{ "Extension [" + extension.name + "] was not found in the list of available extension" };
		}

		requiredExtensions.insert( extension );
		spirvConfig.requiredExtensions.insert( std::move( extension ) );
		return true;
	}

	bool ModuleConfig::hasExtension( SpirVExtension const & extension )const
	{
		return requiredExtensions.contains( extension );
	}

	void ModuleConfig::fillModule( Module & shaderModule )const
	{
		for ( auto & capability : requiredCapabilities )
		{
			insertCapability( shaderModule.getNameCache(), shaderModule.capabilities, capability );
		}

		for ( auto & extension : requiredExtensions )
		{
			if ( !extension.isMarker )
			{
				shaderModule.registerExtension( extension.name );
			}
		}
	}

	void ModuleConfig::initialise( ast::stmt::FunctionDecl const & stmt )
	{
		auto funcType = stmt.getType();

		for ( auto & param : *funcType )
		{
			auto type = param->getType();

			switch ( type->getKind() )
			{
			case ast::type::Kind::eFragmentInput:
				registerParam( param, static_cast< ast::type::FragmentInput const & >( *type ) );
				break;
			case ast::type::Kind::eGeometryOutput:
				registerParam( param, static_cast< ast::type::GeometryOutput const & >( *type ) );
				break;
			case ast::type::Kind::eGeometryInput:
				registerParam( param, static_cast< ast::type::GeometryInput const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationInputPatch:
				registerParam( param, static_cast< ast::type::TessellationInputPatch const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationControlInput:
				registerParam( param, static_cast< ast::type::TessellationControlInput const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationEvaluationInput:
				registerParam( param, static_cast< ast::type::TessellationEvaluationInput const & >( *type ) );
				break;
			case ast::type::Kind::eComputeInput:
				registerParam( param, static_cast< ast::type::ComputeInput const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationOutputPatch:
				registerParam( param, static_cast< ast::type::TessellationOutputPatch const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationControlOutput:
				registerParam( param, static_cast< ast::type::TessellationControlOutput const & >( *type ) );
				break;
			case ast::type::Kind::eMeshVertexOutput:
				registerParam( param, static_cast< ast::type::MeshVertexOutput const & >( *type ) );
				break;
			case ast::type::Kind::eMeshPrimitiveOutput:
				registerParam( param, static_cast< ast::type::MeshPrimitiveOutput const & >( *type ) );
				break;
			case ast::type::Kind::eTaskPayloadNV:
				registerParam( param, static_cast< ast::type::TaskPayloadNV const & >( *type ) );
				break;
			case ast::type::Kind::eTaskPayload:
				registerParam( param, static_cast< ast::type::TaskPayload const & >( *type ) );
				break;
			case ast::type::Kind::eTaskPayloadInNV:
				registerParam( param, static_cast< ast::type::TaskPayloadInNV const & >( *type ) );
				break;
			case ast::type::Kind::eTaskPayloadIn:
				registerParam( param, static_cast< ast::type::TaskPayloadIn const & >( *type ) );
				break;
			default:
				{
					uint32_t arraySize = ast::type::NotArray;

					if ( type->getKind() == ast::type::Kind::eArray )
					{
						auto & arrayType = static_cast< ast::type::Array const & >( *type );
						type = arrayType.getType();
						arraySize = arrayType.getArraySize();
					}

					if ( isStructType( type ) )
					{
						auto structType = getStructType( type );

						if ( structType->isShaderInput() )
						{
							registerInput( param
								, static_cast< ast::type::IOStruct const & >( *structType )
								, arraySize );
						}
						else if ( structType->isShaderOutput() )
						{
							registerOutput( param
								, static_cast< ast::type::IOStruct const & >( *structType )
								, arraySize );
						}
					}
				}
				break;
			}
		}
	}

	ast::stmt::ContainerPtr ModuleConfig::declare( ast::stmt::StmtCache & stmtCache )const
	{
		return stmtCache.makeContainer();
	}

	void ModuleConfig::addInputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		inputs.addPending( var, location );
	}

	void ModuleConfig::addOutputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		outputs.addPending( var, location );
	}

	ast::expr::ExprPtr ModuleConfig::processPendingMbr( ast::expr::ExprCache & exprCache
		, ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, ExprAdapter & adapter
		, ast::stmt::Container * cont )
	{
		if ( flags.isShaderInput() )
		{
			return processPendingMbrInput( exprCache
				, outer
				, mbrIndex
				, flags
				, adapter
				, cont );
		}

		return processPendingMbrOutput( exprCache
			, outer
			, mbrIndex
			, flags
			, adapter
			, cont );
	}

	ast::expr::ExprPtr ModuleConfig::processPending( ast::expr::ExprCache & exprCache
		, ast::Builtin builtin
		, ast::stmt::Container * cont )
	{
		if ( hlp::isShaderInput( builtin, inputs.stage ) )
		{
			return inputs.processPending( exprCache, builtin, cont );
		}

		return outputs.processPending( exprCache, builtin, cont );
	}

	ast::expr::ExprPtr ModuleConfig::processPending( ast::expr::ExprCache & exprCache
		, ast::var::VariablePtr var
		, ast::stmt::Container * cont )
	{
		if ( var->isShaderInput() )
		{
			return processPendingInput( exprCache
				, var
				, cont );
		}

		return processPendingOutput( exprCache
			, var
			, cont );
	}

	bool ModuleConfig::isInput( ast::Builtin builtin )const
	{
		return inputs.isValid( builtin );
	}

	bool ModuleConfig::isOutput( ast::Builtin builtin )const
	{
		return outputs.isValid( builtin );
	}

	void ModuleConfig::addMbrBuiltin( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location
		, uint32_t arraySize )
	{
		if ( flags.isShaderOutput() )
		{
			addPendingMbrOutput( outer
				, mbrIndex
				, flags
				, location
				, arraySize );
		}
		else
		{
			addPendingMbrInput( outer
				, mbrIndex
				, flags
				, location
				, arraySize );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::ComputeInput const & compType )
	{
		auto type = compType.getType();

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, ast::type::NotArray );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::FragmentInput const & fragType )
	{
		auto type = fragType.getType();

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, ast::type::NotArray );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::GeometryInput const & geomType )
	{
		auto type = geomType.getType();

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, getArraySize( geomType.getLayout() ) );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType )
	{
		auto type = geomType.getType();

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, ast::type::NotArray );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationInputPatch const & patchType )
	{
		if ( isStructType( patchType.getType() ) )
		{
			auto const & structType = *getStructType( patchType.getType() );
			uint32_t indexBuiltins = 0u;
			auto inStructType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
				, structType.getMemoryLayout()
				, structType.getName() + "Repl"
				, getEntryPointType( stage )
				, ast::var::Flag::ePatchInput );
			auto inBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
				, structType.getMemoryLayout()
				, structType.getName() + "Builtins"
				, getEntryPointType( stage )
				, ast::var::Flag::eShaderInput );
			auto othersVar = ast::var::makeVariable( { ++nextVarId, var->getName() + "Others" }
				, ast::type::makeTessellationInputPatchType( inStructType
					, patchType.getDomain()
					, patchType.getLocation() )
				, var->getFlags() );
			auto builtinsVar = ast::var::makeVariable( { ++nextVarId, var->getName() + "Builtins" }
				, inBuiltinsType );
			inputs.splitVarsOthers.try_emplace( var, othersVar, 0u );
			auto it = inputs.splitVarsBuiltins.try_emplace( var, builtinsVar, 0u ).first;

			for ( auto & mbr : structType )
			{
				if ( mbr.builtin == ast::Builtin::eNone )
				{
					it->second.second++;
					inStructType->declMember( mbr.name
						, mbr.type
						, mbr.location );
				}
				else
				{
					inBuiltinsType->declMember( mbr.builtin
						, getNonArrayType( mbr.type )->getKind()
						, getArraySize( mbr.type )
						, ast::type::Struct::InvalidLocation );
					inputs.addPendingMbr( builtinsVar
						, indexBuiltins
						, ( ast::var::Flag::eShaderInput | ast::var::Flag::eBuiltin )
						, ast::type::Struct::InvalidLocation
						, ast::type::NotArray );
					++indexBuiltins;
				}
			}

			if ( !inStructType->empty() )
			{
				inputs.addPatch( othersVar );
			}
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationOutputPatch const & patchType )
	{
		if ( isStructType( patchType.getType() ) )
		{
			auto const & structType = *getStructType( patchType.getType() );
			uint32_t indexBuiltins = 0u;
			auto flags = structType.getFlag();
			auto outStructType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
				, structType.getMemoryLayout()
				, structType.getName() + "Repl"
				, getEntryPointType( stage )
				, ast::var::Flag( flags ) );
			auto outBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
				, structType.getMemoryLayout()
				, structType.getName() + "Builtins"
				, getEntryPointType( stage )
				, ast::var::Flag::eShaderOutput );
			auto othersVar = ast::var::makeVariable( { ++nextVarId, var->getName() + "Others" }
				, ast::type::makeTessellationOutputPatchType( outStructType
					, patchType.getLocation() )
				, var->getFlags() );
			auto builtinsVar = ast::var::makeVariable( { ++nextVarId, var->getName() + "Builtins" }
			, outBuiltinsType );
			outputs.splitVarsOthers.try_emplace( var, othersVar, 0u );
			auto it = outputs.splitVarsBuiltins.try_emplace( var, builtinsVar, 0u ).first;

			for ( auto & mbr : structType )
			{
				if ( mbr.builtin == ast::Builtin::eNone )
				{
					it->second.second++;
					outStructType->declMember( mbr.name
						, mbr.type
						, mbr.location );
				}
				else
				{
					outBuiltinsType->declMember( mbr.builtin
						, getNonArrayType( mbr.type )->getKind()
						, getArraySize( mbr.type )
						, ast::type::Struct::InvalidLocation );
					outputs.addPendingMbr( builtinsVar
						, indexBuiltins
						, ( ast::var::Flag::eShaderOutput | ast::var::Flag::eBuiltin )
						, ast::type::Struct::InvalidLocation
						, ast::type::NotArray );
					++indexBuiltins;
				}
			}

			if ( !outStructType->empty() )
			{
				outputs.addPatch( othersVar );
			}
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationControlInput const & tessType )
	{
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, tessType.getInputVertices() );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationControlOutput const & tessType )
	{
		auto type = tessType.getType();

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, tessType.getOutputVertices() );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationEvaluationInput const & tessType )
	{
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, tessType.getInputVertices() );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::MeshVertexOutput const & meshType )
	{
		auto type = meshType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, meshType.getMaxVertices() );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::MeshPrimitiveOutput const & meshType )
	{
		auto type = meshType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, meshType.getMaxPrimitives() );
		}
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TaskPayloadNV const & )
	{
		addOutput( var );
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TaskPayload const & )
	{
		addOutput( var );
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TaskPayloadInNV const & )
	{
		addInput( var );
	}

	void ModuleConfig::registerParam( ast::var::VariablePtr var
		, ast::type::TaskPayloadIn const & )
	{
		addInput( var );
	}

	void ModuleConfig::registerInput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType
		, uint32_t arraySize )
	{
		uint32_t index = 0u;
		auto flags = structType.getFlag();

		for ( auto & mbr : structType )
		{
			inputs.addPendingMbr( var
				, index
				, ( flags
					| ( ( mbr.builtin == ast::Builtin::eNone )
						? ast::var::Flag::eNone
						: ast::var::Flag::eBuiltin ) )
				, ( ( mbr.builtin == ast::Builtin::eNone )
					? mbr.location
					: ast::type::Struct::InvalidLocation )
				, arraySize );
			++index;
		}
	}

	void ModuleConfig::registerOutput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType
		, uint32_t arraySize )
	{
		uint32_t index = 0u;
		auto flags = structType.getFlag();

		for ( auto & mbr : structType )
		{
			outputs.addPendingMbr( var
				, index
				, ( flags
					| ( ( mbr.builtin == ast::Builtin::eNone )
						? ast::var::Flag::eNone
						: ast::var::Flag::eBuiltin ) )
				, ( ( mbr.builtin == ast::Builtin::eNone )
					? mbr.location
					: ast::type::Struct::InvalidLocation )
				, arraySize );
			++index;
		}
	}

	//*************************************************************************

	size_t ConstExprIdentifierHasher::operator()( ConstExprIdentifier const & obj )const
	{
		auto result = std::hash< ast::type::TypePtr >{}( obj.type );
		result = ast::type::hashCombine( result, obj.scopeId );
		result = ast::type::hashCombine( result, obj.name );
		return result;
	}

	//*************************************************************************

	spv::BuiltIn getBuiltin( ast::Builtin builtin
		, spv::ExecutionModel executionModel
		, ast::Vector< spv::Decoration > & additionalDecorations )
	{
		switch ( builtin )
		{
		case ast::Builtin::ePosition:
			return spv::BuiltInPosition;
		case ast::Builtin::ePointSize:
			return spv::BuiltInPointSize;
		case ast::Builtin::eClipDistance:
			return spv::BuiltInClipDistance;
		case ast::Builtin::eCullDistance:
			return spv::BuiltInCullDistance;
		case ast::Builtin::ePrimitiveID:
			if ( executionModel == spv::ExecutionModelMeshEXT
				|| executionModel == spv::ExecutionModelMeshNV )
			{
				additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			}
			return spv::BuiltInPrimitiveId;
		case ast::Builtin::ePrimitiveIDIn:
			return spv::BuiltInPrimitiveId;
		case ast::Builtin::eInvocationID:
			return spv::BuiltInInvocationId;
		case ast::Builtin::eLayer:
			if ( executionModel == spv::ExecutionModelMeshEXT
				|| executionModel == spv::ExecutionModelMeshNV )
			{
				additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			}
			return spv::BuiltInLayer;
		case ast::Builtin::eViewportIndex:
			if ( executionModel == spv::ExecutionModelMeshEXT
				|| executionModel == spv::ExecutionModelMeshNV )
			{
				additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			}
			return spv::BuiltInViewportIndex;
		case ast::Builtin::eTessLevelOuter:
			return spv::BuiltInTessLevelOuter;
		case ast::Builtin::eTessLevelInner:
			return spv::BuiltInTessLevelInner;
		case ast::Builtin::eTessCoord:
			return spv::BuiltInTessCoord;
		case ast::Builtin::ePatchVertices:
		case ast::Builtin::ePatchVerticesIn:
			return spv::BuiltInPatchVertices;
		case ast::Builtin::eFragCoord:
			return spv::BuiltInFragCoord;
		case ast::Builtin::ePointCoord:
			return spv::BuiltInPointCoord;
		case ast::Builtin::eFrontFacing:
			return spv::BuiltInFrontFacing;
		case ast::Builtin::eSampleID:
			return spv::BuiltInSampleId;
		case ast::Builtin::eSamplePosition:
			return spv::BuiltInSamplePosition;
		case ast::Builtin::eSampleMask:
		case ast::Builtin::eSampleMaskIn:
			return spv::BuiltInSampleMask;
		case ast::Builtin::eFragDepth:
			return spv::BuiltInFragDepth;
		case ast::Builtin::eHelperInvocation:
			return spv::BuiltInHelperInvocation;
		case ast::Builtin::eNumWorkGroups:
			return spv::BuiltInNumWorkgroups;
		case ast::Builtin::eWorkGroupSize:
			return spv::BuiltInWorkgroupSize;
		case ast::Builtin::eWorkGroupID:
			return spv::BuiltInWorkgroupId;
		case ast::Builtin::eLocalInvocationID:
			return spv::BuiltInLocalInvocationId;
		case ast::Builtin::eGlobalInvocationID:
			return spv::BuiltInGlobalInvocationId;
		case ast::Builtin::eLocalInvocationIndex:
			return spv::BuiltInLocalInvocationIndex;
		case ast::Builtin::eWorkDim:
			return spv::BuiltInWorkDim;
		case ast::Builtin::eGlobalSize:
			return spv::BuiltInGlobalSize;
		case ast::Builtin::eEnqueuedWorkgroupSize:
			return spv::BuiltInEnqueuedWorkgroupSize;
		case ast::Builtin::eGlobalLinearID:
			return spv::BuiltInGlobalLinearId;
		case ast::Builtin::eSubgroupSize:
			return spv::BuiltInSubgroupSize;
		case ast::Builtin::eSubgroupMaxSize:
			return spv::BuiltInSubgroupMaxSize;
		case ast::Builtin::eNumSubgroups:
			return spv::BuiltInNumSubgroups;
		case ast::Builtin::eNumEnqueuedSubgroups:
			return spv::BuiltInNumEnqueuedSubgroups;
		case ast::Builtin::eSubgroupID:
			return spv::BuiltInSubgroupId;
		case ast::Builtin::eSubgroupLocalInvocationID:
			return spv::BuiltInSubgroupLocalInvocationId;
		case ast::Builtin::eVertexIndex:
			return spv::BuiltInVertexIndex;
		case ast::Builtin::eInstanceIndex:
			return spv::BuiltInInstanceIndex;
		case ast::Builtin::eSubgroupEqMask:
			return spv::BuiltInSubgroupEqMask;
		case ast::Builtin::eSubgroupGeMask:
			return spv::BuiltInSubgroupGeMask;
		case ast::Builtin::eSubgroupGtMask:
			return spv::BuiltInSubgroupGtMask;
		case ast::Builtin::eSubgroupLeMask:
			return spv::BuiltInSubgroupLeMask;
		case ast::Builtin::eSubgroupLtMask:
			return spv::BuiltInSubgroupLtMask;
		case ast::Builtin::eBaseVertex:
			return spv::BuiltInBaseVertex;
		case ast::Builtin::eBaseInstance:
			return spv::BuiltInBaseInstance;
		case ast::Builtin::eDrawIndex:
			return spv::BuiltInDrawIndex;
		case ast::Builtin::eDeviceIndex:
			return spv::BuiltInDeviceIndex;
		case ast::Builtin::eViewIndex:
			return spv::BuiltInViewIndex;
		case ast::Builtin::eBaryCoordNoPerspAMD:
			return spv::BuiltInBaryCoordNoPerspAMD;
		case ast::Builtin::eBaryCoordNoPerspCentroidAMD:
			return spv::BuiltInBaryCoordNoPerspCentroidAMD;
		case ast::Builtin::eBaryCoordNoPerspSampleAMD:
			return spv::BuiltInBaryCoordNoPerspSampleAMD;
		case ast::Builtin::eBaryCoordSmoothAMD:
			return spv::BuiltInBaryCoordSmoothAMD;
		case ast::Builtin::eBaryCoordSmoothCentroidAMD:
			return spv::BuiltInBaryCoordSmoothCentroidAMD;
		case ast::Builtin::eBaryCoordSmoothSampleAMD:
			return spv::BuiltInBaryCoordSmoothSampleAMD;
		case ast::Builtin::eBaryCoordPullModelAMD:
			return spv::BuiltInBaryCoordPullModelAMD;
		case ast::Builtin::eFragStencilRefEXT:
			return spv::BuiltInFragStencilRefEXT;
		case ast::Builtin::eViewportMaskNV:
			if ( executionModel == spv::ExecutionModelMeshEXT
				|| executionModel == spv::ExecutionModelMeshNV )
			{
				additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			}
			return spv::BuiltInViewportMaskNV;
		case ast::Builtin::eSecondaryPositionNV:
			return spv::BuiltInSecondaryPositionNV;
		case ast::Builtin::eSecondaryViewportMaskNV:
			return spv::BuiltInSecondaryViewportMaskNV;
		case ast::Builtin::ePositionPerViewNV:
			if ( executionModel == spv::ExecutionModelMeshEXT
				|| executionModel == spv::ExecutionModelMeshNV )
			{
				additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			}
			additionalDecorations.push_back( spv::DecorationPerViewNV );
			return spv::BuiltInPositionPerViewNV;
		case ast::Builtin::eViewportMaskPerViewNV:
			additionalDecorations.push_back( spv::DecorationPerViewNV );
			return spv::BuiltInViewportMaskPerViewNV;
		case ast::Builtin::ePrimitiveIndicesNV:
			additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			return spv::BuiltInPrimitiveIndicesNV;
		case ast::Builtin::ePrimitiveCountNV:
			return spv::BuiltInPrimitiveCountNV;
		case ast::Builtin::eTaskCountNV:
			return spv::BuiltInTaskCountNV;
		case ast::Builtin::eClipDistancePerViewNV:
			if ( executionModel == spv::ExecutionModelMeshEXT
				|| executionModel == spv::ExecutionModelMeshNV )
			{
				additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			}
			additionalDecorations.push_back( spv::DecorationPerViewNV );
			return spv::BuiltInClipDistancePerViewNV;
		case ast::Builtin::eCullDistancePerViewNV:
			if ( executionModel == spv::ExecutionModelMeshEXT
				|| executionModel == spv::ExecutionModelMeshNV )
			{
				additionalDecorations.push_back( spv::DecorationPerPrimitiveNV );
			}
			additionalDecorations.push_back( spv::DecorationPerViewNV );
			return spv::BuiltInCullDistancePerViewNV;
		case ast::Builtin::eLayerPerViewNV:
			additionalDecorations.push_back( spv::DecorationPerViewNV );
			return spv::BuiltInLayerPerViewNV;
		case ast::Builtin::eMeshViewCountNV:
			return spv::BuiltInMeshViewCountNV;
		case ast::Builtin::eMeshViewIndicesNV:
			return spv::BuiltInMeshViewIndicesNV;
		case ast::Builtin::eLaunchID:
			return spv::BuiltInLaunchIdKHR;
		case ast::Builtin::eLaunchSize:
			return spv::BuiltInLaunchSizeKHR;
		case ast::Builtin::eInstanceCustomIndex:
			return spv::BuiltInInstanceCustomIndexKHR;
		case ast::Builtin::eGeometryIndex:
			return spv::BuiltInRayGeometryIndexKHR;
		case ast::Builtin::eWorldRayOrigin:
			return spv::BuiltInWorldRayOriginKHR;
		case ast::Builtin::eWorldRayDirection:
			return spv::BuiltInWorldRayDirectionKHR;
		case ast::Builtin::eObjectRayOrigin:
			return spv::BuiltInObjectRayOriginKHR;
		case ast::Builtin::eObjectRayDirection:
			return spv::BuiltInObjectRayDirectionKHR;
		case ast::Builtin::eRayTmin:
			return spv::BuiltInRayTminKHR;
		case ast::Builtin::eRayTmax:
			return spv::BuiltInRayTmaxKHR;
		case ast::Builtin::eIncomingRayFlags:
			return spv::BuiltInIncomingRayFlagsKHR;
		case ast::Builtin::eHitKind:
			return spv::BuiltInHitKindKHR;
		case ast::Builtin::eObjectToWorld:
			return spv::BuiltInObjectToWorldKHR;
		case ast::Builtin::eWorldToObject:
			return spv::BuiltInWorldToObjectKHR;
		case ast::Builtin::ePrimitivePointIndices:
			return spv::BuiltInPrimitivePointIndicesEXT;
		case ast::Builtin::ePrimitiveLineIndices:
			return spv::BuiltInPrimitiveLineIndicesEXT;
		case ast::Builtin::ePrimitiveTriangleIndices:
			return spv::BuiltInPrimitiveTriangleIndicesEXT;
		default:
			AST_Failure( "Unsupported ast::Builtin" );
			return spv::BuiltInMax;
		}
	}

	spv::MemoryModel getMemoryModel()
	{
		return spv::MemoryModelGLSL450;
	}

	spv::ExecutionModel getExecutionModel( ast::ShaderStage kind )
	{
		spv::ExecutionModel result{};

		switch ( kind )
		{
		case ast::ShaderStage::eVertex:
			result = spv::ExecutionModelVertex;
			break;
		case ast::ShaderStage::eTessellationControl:
			result = spv::ExecutionModelTessellationControl;
			break;
		case ast::ShaderStage::eTessellationEvaluation:
			result = spv::ExecutionModelTessellationEvaluation;
			break;
		case ast::ShaderStage::eGeometry:
			result = spv::ExecutionModelGeometry;
			break;
		case ast::ShaderStage::eFragment:
			result = spv::ExecutionModelFragment;
			break;
		case ast::ShaderStage::eTaskNV:
			result = spv::ExecutionModelTaskNV;
			break;
		case ast::ShaderStage::eTask:
			result = spv::ExecutionModelTaskEXT;
			break;
		case ast::ShaderStage::eMeshNV:
			result = spv::ExecutionModelMeshNV;
			break;
		case ast::ShaderStage::eMesh:
			result = spv::ExecutionModelMeshEXT;
			break;
		case ast::ShaderStage::eCompute:
			result = spv::ExecutionModelGLCompute;
			break;
		case ast::ShaderStage::eRayGeneration:
			result = spv::ExecutionModelRayGenerationKHR;
			break;
		case ast::ShaderStage::eRayClosestHit:
			result = spv::ExecutionModelClosestHitKHR;
			break;
		case ast::ShaderStage::eRayMiss:
			result = spv::ExecutionModelMissKHR;
			break;
		case ast::ShaderStage::eRayIntersection:
			result = spv::ExecutionModelIntersectionKHR;
			break;
		case ast::ShaderStage::eRayAnyHit:
			result = spv::ExecutionModelAnyHitKHR;
			break;
		case ast::ShaderStage::eCallable:
			result = spv::ExecutionModelCallableKHR;
			break;
		default:
			AST_Failure( "Unsupported sdw::ShaderStage." );
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

	std::string getName( spv::Capability value )
	{
		switch ( value )
		{
		case spv::CapabilityMatrix:
			return "Matrix";
		case spv::CapabilityShader:
			return "Shader";
		case spv::CapabilityGeometry:
			return "Geometry";
		case spv::CapabilityTessellation:
			return "Tessellation";
		case spv::CapabilityAddresses:
			return "Addresses";
		case spv::CapabilityLinkage:
			return "Linkage";
		case spv::CapabilityKernel:
			return "Kernel";
		case spv::CapabilityVector16:
			return "Vector16";
		case spv::CapabilityFloat16Buffer:
			return "Float16Buffer";
		case spv::CapabilityFloat16:
			return "Float16";
		case spv::CapabilityFloat64:
			return "Float64";
		case spv::CapabilityInt64:
			return "Int64";
		case spv::CapabilityInt64Atomics:
			return "Int64Atomics";
		case spv::CapabilityImageBasic:
			return "ImageBasic";
		case spv::CapabilityImageReadWrite:
			return "ImageReadWrite";
		case spv::CapabilityImageMipmap:
			return "ImageMipmap";
		case spv::CapabilityPipes:
			return "Pipes";
		case spv::CapabilityGroups:
			return "Groups";
		case spv::CapabilityDeviceEnqueue:
			return "DeviceEnqueue";
		case spv::CapabilityLiteralSampler:
			return "LiteralSampler";
		case spv::CapabilityAtomicStorage:
			return "AtomicStorage";
		case spv::CapabilityInt16:
			return "Int16";
		case spv::CapabilityTessellationPointSize:
			return "TessellationPointSize";
		case spv::CapabilityGeometryPointSize:
			return "GeometryPointSize";
		case spv::CapabilityImageGatherExtended:
			return "ImageGatherExtended";
		case spv::CapabilityStorageImageMultisample:
			return "StorageImageMultisample";
		case spv::CapabilityUniformBufferArrayDynamicIndexing:
			return "UniformBufferArrayDynamicIndexing";
		case spv::CapabilitySampledImageArrayDynamicIndexing:
			return "SampledImageArrayDynamicIndexing";
		case spv::CapabilityStorageBufferArrayDynamicIndexing:
			return "StorageBufferArrayDynamicIndexing";
		case spv::CapabilityStorageImageArrayDynamicIndexing:
			return "StorageImageArrayDynamicIndexing";
		case spv::CapabilityClipDistance:
			return "ClipDistance";
		case spv::CapabilityCullDistance:
			return "CullDistance";
		case spv::CapabilityImageCubeArray:
			return "ImageCubeArray";
		case spv::CapabilitySampleRateShading:
			return "SampleRateShading";
		case spv::CapabilityImageRect:
			return "ImageRect";
		case spv::CapabilitySampledRect:
			return "SampledRect";
		case spv::CapabilityGenericPointer:
			return "GenericPointer";
		case spv::CapabilityInt8:
			return "Int8";
		case spv::CapabilityInputAttachment:
			return "InputAttachment";
		case spv::CapabilitySparseResidency:
			return "SparseResidency";
		case spv::CapabilityMinLod:
			return "MinLod";
		case spv::CapabilitySampled1D:
			return "Sampled1D";
		case spv::CapabilityImage1D:
			return "Image1D";
		case spv::CapabilitySampledCubeArray:
			return "SampledCubeArray";
		case spv::CapabilitySampledBuffer:
			return "SampledBuffer";
		case spv::CapabilityImageBuffer:
			return "ImageBuffer";
		case spv::CapabilityImageMSArray:
			return "ImageMSArray";
		case spv::CapabilityStorageImageExtendedFormats:
			return "StorageImageExtendedFormats";
		case spv::CapabilityImageQuery:
			return "ImageQuery";
		case spv::CapabilityDerivativeControl:
			return "DerivativeControl";
		case spv::CapabilityInterpolationFunction:
			return "InterpolationFunction";
		case spv::CapabilityTransformFeedback:
			return "TransformFeedback";
		case spv::CapabilityGeometryStreams:
			return "GeometryStreams";
		case spv::CapabilityStorageImageReadWithoutFormat:
			return "StorageImageReadWithoutFormat";
		case spv::CapabilityStorageImageWriteWithoutFormat:
			return "StorageImageWriteWithoutFormat";
		case spv::CapabilityMultiViewport:
			return "MultiViewport";
		case spv::CapabilitySubgroupDispatch:
			return "SubgroupDispatch";
		case spv::CapabilityNamedBarrier:
			return "NamedBarrier";
		case spv::CapabilityPipeStorage:
			return "PipeStorage";
		case spv::CapabilityGroupNonUniform:
			return "GroupNonUniform";
		case spv::CapabilityGroupNonUniformVote:
			return "GroupNonUniformVote";
		case spv::CapabilityGroupNonUniformArithmetic:
			return "GroupNonUniformArithmetic";
		case spv::CapabilityGroupNonUniformBallot:
			return "GroupNonUniformBallot";
		case spv::CapabilityGroupNonUniformShuffle:
			return "GroupNonUniformShuffle";
		case spv::CapabilityGroupNonUniformShuffleRelative:
			return "GroupNonUniformShuffleRelative";
		case spv::CapabilityGroupNonUniformClustered:
			return "GroupNonUniformClustered";
		case spv::CapabilityGroupNonUniformQuad:
			return "GroupNonUniformQuad";
		case spv::CapabilityShaderLayer:
			return "ShaderLayer";
		case spv::CapabilityShaderViewportIndex:
			return "ShaderViewportIndex";
		case spv::CapabilityUniformDecoration:
			return "UniformDecoration";
		case spv::CapabilityCoreBuiltinsARM:
			return "CoreBuiltinsARM";
		case spv::CapabilityTileImageColorReadAccessEXT:
			return "TileImageColorReadAccessEXT";
		case spv::CapabilityTileImageDepthReadAccessEXT:
			return "TileImageDepthReadAccessEXT";
		case spv::CapabilityTileImageStencilReadAccessEXT:
			return "TileImageStencilReadAccessEXT";
		case spv::CapabilityFragmentShadingRateKHR:
			return "FragmentShadingRateKHR";
		case spv::CapabilitySubgroupBallotKHR:
			return "SubgroupBallotKHR";
		case spv::CapabilityDrawParameters:
			return "DrawParameters";
		case spv::CapabilityWorkgroupMemoryExplicitLayoutKHR:
			return "WorkgroupMemoryExplicitLayoutKHR";
		case spv::CapabilityWorkgroupMemoryExplicitLayout8BitAccessKHR:
			return "WorkgroupMemoryExplicitLayout8BitAccessKHR";
		case spv::CapabilityWorkgroupMemoryExplicitLayout16BitAccessKHR:
			return "WorkgroupMemoryExplicitLayout16BitAccessKHR";
		case spv::CapabilitySubgroupVoteKHR:
			return "SubgroupVoteKHR";
		case spv::CapabilityStorageBuffer16BitAccess:
			return "StorageBuffer16BitAccess";
		case spv::CapabilityStorageUniform16:
			return "StorageUniform16";
		case spv::CapabilityStoragePushConstant16:
			return "StoragePushConstant16";
		case spv::CapabilityStorageInputOutput16:
			return "StorageInputOutput16";
		case spv::CapabilityDeviceGroup:
			return "DeviceGroup";
		case spv::CapabilityMultiView:
			return "MultiView";
		case spv::CapabilityVariablePointersStorageBuffer:
			return "VariablePointersStorageBuffer";
		case spv::CapabilityVariablePointers:
			return "VariablePointers";
		case spv::CapabilityAtomicStorageOps:
			return "AtomicStorageOps";
		case spv::CapabilitySampleMaskPostDepthCoverage:
			return "SampleMaskPostDepthCoverage";
		case spv::CapabilityStorageBuffer8BitAccess:
			return "StorageBuffer8BitAccess";
		case spv::CapabilityUniformAndStorageBuffer8BitAccess:
			return "UniformAndStorageBuffer8BitAccess";
		case spv::CapabilityStoragePushConstant8:
			return "StoragePushConstant8";
		case spv::CapabilityDenormPreserve:
			return "DenormPreserve";
		case spv::CapabilityDenormFlushToZero:
			return "DenormFlushToZero";
		case spv::CapabilitySignedZeroInfNanPreserve:
			return "SignedZeroInfNanPreserve";
		case spv::CapabilityRoundingModeRTE:
			return "RoundingModeRTE";
		case spv::CapabilityRoundingModeRTZ:
			return "RoundingModeRTZ";
		case spv::CapabilityRayQueryProvisionalKHR:
			return "RayQueryProvisionalKHR";
		case spv::CapabilityRayQueryKHR:
			return "RayQueryKHR";
		case spv::CapabilityRayTraversalPrimitiveCullingKHR:
			return "RayTraversalPrimitiveCullingKHR";
		case spv::CapabilityRayTracingKHR:
			return "RayTracingKHR";
		case spv::CapabilityTextureSampleWeightedQCOM:
			return "TextureSampleWeightedQCOM";
		case spv::CapabilityTextureBoxFilterQCOM:
			return "TextureBoxFilterQCOM";
		case spv::CapabilityTextureBlockMatchQCOM:
			return "TextureBlockMatchQCOM";
		case spv::CapabilityTextureBlockMatch2QCOM:
			return "TextureBlockMatch2QCOM";
		case spv::CapabilityFloat16ImageAMD:
			return "Float16ImageAMD";
		case spv::CapabilityImageGatherBiasLodAMD:
			return "ImageGatherBiasLodAMD";
		case spv::CapabilityFragmentMaskAMD:
			return "FragmentMaskAMD";
		case spv::CapabilityStencilExportEXT:
			return "StencilExportEXT";
		case spv::CapabilityImageReadWriteLodAMD:
			return "ImageReadWriteLodAMD";
		case spv::CapabilityInt64ImageEXT:
			return "Int64ImageEXT";
		case spv::CapabilityShaderClockKHR:
			return "ShaderClockKHR";
		case spv::CapabilityShaderEnqueueAMDX:
			return "ShaderEnqueueAMDX";
		case spv::CapabilityQuadControlKHR:
			return "QuadControlKHR";
		case spv::CapabilitySampleMaskOverrideCoverageNV:
			return "SampleMaskOverrideCoverageNV";
		case spv::CapabilityGeometryShaderPassthroughNV:
			return "GeometryShaderPassthroughNV";
		case spv::CapabilityShaderViewportIndexLayerEXT:
			return "ShaderViewportIndexLayerEXT";
		case spv::CapabilityShaderViewportMaskNV:
			return "ShaderViewportMaskNV";
		case spv::CapabilityShaderStereoViewNV:
			return "ShaderStereoViewNV";
		case spv::CapabilityPerViewAttributesNV:
			return "PerViewAttributesNV";
		case spv::CapabilityFragmentFullyCoveredEXT:
			return "FragmentFullyCoveredEXT";
		case spv::CapabilityMeshShadingNV:
			return "MeshShadingNV";
		case spv::CapabilityImageFootprintNV:
			return "ImageFootprintNV";
		case spv::CapabilityMeshShadingEXT:
			return "MeshShadingEXT";
		case spv::CapabilityFragmentBarycentricKHR:
			return "FragmentBarycentricKHR";
		case spv::CapabilityComputeDerivativeGroupQuadsNV:
			return "ComputeDerivativeGroupQuadsNV";
		case spv::CapabilityFragmentDensityEXT:
			return "FragmentDensityEXT";
		case spv::CapabilityGroupNonUniformPartitionedNV:
			return "GroupNonUniformPartitionedNV";
		case spv::CapabilityShaderNonUniform:
			return "ShaderNonUniform";
		case spv::CapabilityRuntimeDescriptorArray:
			return "RuntimeDescriptorArray";
		case spv::CapabilityInputAttachmentArrayDynamicIndexing:
			return "InputAttachmentArrayDynamicIndexing";
		case spv::CapabilityUniformTexelBufferArrayDynamicIndexing:
			return "UniformTexelBufferArrayDynamicIndexing";
		case spv::CapabilityStorageTexelBufferArrayDynamicIndexing:
			return "StorageTexelBufferArrayDynamicIndexing";
		case spv::CapabilityUniformBufferArrayNonUniformIndexing:
			return "UniformBufferArrayNonUniformIndexing";
		case spv::CapabilitySampledImageArrayNonUniformIndexing:
			return "SampledImageArrayNonUniformIndexing";
		case spv::CapabilityStorageBufferArrayNonUniformIndexing:
			return "StorageBufferArrayNonUniformIndexing";
		case spv::CapabilityStorageImageArrayNonUniformIndexing:
			return "StorageImageArrayNonUniformIndexing";
		case spv::CapabilityInputAttachmentArrayNonUniformIndexing:
			return "InputAttachmentArrayNonUniformIndexing";
		case spv::CapabilityUniformTexelBufferArrayNonUniformIndexing:
			return "UniformTexelBufferArrayNonUniformIndexing";
		case spv::CapabilityStorageTexelBufferArrayNonUniformIndexing:
			return "StorageTexelBufferArrayNonUniformIndexing";
		case spv::CapabilityRayTracingPositionFetchKHR:
			return "RayTracingPositionFetchKHR";
		case spv::CapabilityRayTracingNV:
			return "RayTracingNV";
		case spv::CapabilityRayTracingMotionBlurNV:
			return "RayTracingMotionBlurNV";
		case spv::CapabilityVulkanMemoryModel:
			return "VulkanMemoryModel";
		case spv::CapabilityVulkanMemoryModelDeviceScope:
			return "VulkanMemoryModelDeviceScope";
		case spv::CapabilityPhysicalStorageBufferAddresses:
			return "PhysicalStorageBufferAddresses";
		case spv::CapabilityComputeDerivativeGroupLinearNV:
			return "ComputeDerivativeGroupLinearNV";
		case spv::CapabilityRayTracingProvisionalKHR:
			return "RayTracingProvisionalKHR";
		case spv::CapabilityCooperativeMatrixNV:
			return "CooperativeMatrixNV";
		case spv::CapabilityFragmentShaderSampleInterlockEXT:
			return "FragmentShaderSampleInterlockEXT";
		case spv::CapabilityFragmentShaderShadingRateInterlockEXT:
			return "FragmentShaderShadingRateInterlockEXT";
		case spv::CapabilityShaderSMBuiltinsNV:
			return "ShaderSMBuiltinsNV";
		case spv::CapabilityFragmentShaderPixelInterlockEXT:
			return "FragmentShaderPixelInterlockEXT";
		case spv::CapabilityDemoteToHelperInvocation:
			return "DemoteToHelperInvocation";
		case spv::CapabilityDisplacementMicromapNV:
			return "DisplacementMicromapNV";
		case spv::CapabilityRayTracingOpacityMicromapEXT:
			return "RayTracingOpacityMicromapEXT";
		case spv::CapabilityShaderInvocationReorderNV:
			return "ShaderInvocationReorderNV";
		case spv::CapabilityBindlessTextureNV:
			return "BindlessTextureNV";
		case spv::CapabilityRayQueryPositionFetchKHR:
			return "RayQueryPositionFetchKHR";
		case spv::CapabilityAtomicFloat16VectorNV:
			return "AtomicFloat16VectorNV";
		case spv::CapabilityRayTracingDisplacementMicromapNV:
			return "RayTracingDisplacementMicromapNV";
		case spv::CapabilitySubgroupShuffleINTEL:
			return "SubgroupShuffleINTEL";
		case spv::CapabilitySubgroupBufferBlockIOINTEL:
			return "SubgroupBufferBlockIOINTEL";
		case spv::CapabilitySubgroupImageBlockIOINTEL:
			return "SubgroupImageBlockIOINTEL";
		case spv::CapabilitySubgroupImageMediaBlockIOINTEL:
			return "SubgroupImageMediaBlockIOINTEL";
		case spv::CapabilityRoundToInfinityINTEL:
			return "RoundToInfinityINTEL";
		case spv::CapabilityFloatingPointModeINTEL:
			return "FloatingPointModeINTEL";
		case spv::CapabilityIntegerFunctions2INTEL:
			return "IntegerFunctions2INTEL";
		case spv::CapabilityFunctionPointersINTEL:
			return "FunctionPointersINTEL";
		case spv::CapabilityIndirectReferencesINTEL:
			return "IndirectReferencesINTEL";
		case spv::CapabilityAsmINTEL:
			return "AsmINTEL";
		case spv::CapabilityAtomicFloat32MinMaxEXT:
			return "AtomicFloat32MinMaxEXT";
		case spv::CapabilityAtomicFloat64MinMaxEXT:
			return "AtomicFloat64MinMaxEXT";
		case spv::CapabilityAtomicFloat16MinMaxEXT:
			return "AtomicFloat16MinMaxEXT";
		case spv::CapabilityVectorComputeINTEL:
			return "VectorComputeINTEL";
		case spv::CapabilityVectorAnyINTEL:
			return "VectorAnyINTEL";
		case spv::CapabilityExpectAssumeKHR:
			return "ExpectAssumeKHR";
		case spv::CapabilitySubgroupAvcMotionEstimationINTEL:
			return "SubgroupAvcMotionEstimationINTEL";
		case spv::CapabilitySubgroupAvcMotionEstimationIntraINTEL:
			return "SubgroupAvcMotionEstimationIntraINTEL";
		case spv::CapabilitySubgroupAvcMotionEstimationChromaINTEL:
			return "SubgroupAvcMotionEstimationChromaINTEL";
		case spv::CapabilityVariableLengthArrayINTEL:
			return "VariableLengthArrayINTEL";
		case spv::CapabilityFunctionFloatControlINTEL:
			return "FunctionFloatControlINTEL";
		case spv::CapabilityFPGAMemoryAttributesINTEL:
			return "FPGAMemoryAttributesINTEL";
		case spv::CapabilityFPFastMathModeINTEL:
			return "FPFastMathModeINTEL";
		case spv::CapabilityArbitraryPrecisionIntegersINTEL:
			return "ArbitraryPrecisionIntegersINTEL";
		case spv::CapabilityArbitraryPrecisionFloatingPointINTEL:
			return "ArbitraryPrecisionFloatingPointINTEL";
		case spv::CapabilityUnstructuredLoopControlsINTEL:
			return "UnstructuredLoopControlsINTEL";
		case spv::CapabilityFPGALoopControlsINTEL:
			return "FPGALoopControlsINTEL";
		case spv::CapabilityKernelAttributesINTEL:
			return "KernelAttributesINTEL";
		case spv::CapabilityFPGAKernelAttributesINTEL:
			return "FPGAKernelAttributesINTEL";
		case spv::CapabilityFPGAMemoryAccessesINTEL:
			return "FPGAMemoryAccessesINTEL";
		case spv::CapabilityFPGAClusterAttributesINTEL:
			return "FPGAClusterAttributesINTEL";
		case spv::CapabilityLoopFuseINTEL:
			return "LoopFuseINTEL";
		case spv::CapabilityFPGADSPControlINTEL:
			return "FPGADSPControlINTEL";
		case spv::CapabilityMemoryAccessAliasingINTEL:
			return "MemoryAccessAliasingINTEL";
		case spv::CapabilityFPGAInvocationPipeliningAttributesINTEL:
			return "FPGAInvocationPipeliningAttributesINTEL";
		case spv::CapabilityFPGABufferLocationINTEL:
			return "FPGABufferLocationINTEL";
		case spv::CapabilityArbitraryPrecisionFixedPointINTEL:
			return "ArbitraryPrecisionFixedPointINTEL";
		case spv::CapabilityUSMStorageClassesINTEL:
			return "USMStorageClassesINTEL";
		case spv::CapabilityRuntimeAlignedAttributeINTEL:
			return "RuntimeAlignedAttributeINTEL";
		case spv::CapabilityIOPipesINTEL:
			return "IOPipesINTEL";
		case spv::CapabilityBlockingPipesINTEL:
			return "BlockingPipesINTEL";
		case spv::CapabilityFPGARegINTEL:
			return "FPGARegINTEL";
		case spv::CapabilityDotProductInputAll:
			return "DotProductInputAll";
		case spv::CapabilityDotProductInput4x8Bit:
			return "DotProductInput4x8Bit";
		case spv::CapabilityDotProductInput4x8BitPacked:
			return "DotProductInput4x8BitPacked";
		case spv::CapabilityDotProduct:
			return "DotProduct";
		case spv::CapabilityRayCullMaskKHR:
			return "RayCullMaskKHR";
		case spv::CapabilityCooperativeMatrixKHR:
			return "CooperativeMatrixKHR";
		case spv::CapabilityBitInstructions:
			return "BitInstructions";
		case spv::CapabilityGroupNonUniformRotateKHR:
			return "GroupNonUniformRotateKHR";
		case spv::CapabilityFloatControls2:
			return "FloatControls2";
		case spv::CapabilityAtomicFloat32AddEXT:
			return "AtomicFloat32AddEXT";
		case spv::CapabilityAtomicFloat64AddEXT:
			return "AtomicFloat64AddEXT";
		case spv::CapabilityLongCompositesINTEL:
			return "LongCompositesINTEL";
		case spv::CapabilityOptNoneINTEL:
			return "OptNoneINTEL";
		case spv::CapabilityAtomicFloat16AddEXT:
			return "AtomicFloat16AddEXT";
		case spv::CapabilityDebugInfoModuleINTEL:
			return "DebugInfoModuleINTEL";
		case spv::CapabilityBFloat16ConversionINTEL:
			return "BFloat16ConversionINTEL";
		case spv::CapabilitySplitBarrierINTEL:
			return "SplitBarrierINTEL";
		case spv::CapabilityFPGAClusterAttributesV2INTEL:
			return "FPGAClusterAttributesV2INTEL";
		case spv::CapabilityFPGAKernelAttributesv2INTEL:
			return "FPGAKernelAttributesv2INTEL";
		case spv::CapabilityFPMaxErrorINTEL:
			return "FPMaxErrorINTEL";
		case spv::CapabilityFPGALatencyControlINTEL:
			return "FPGALatencyControlINTEL";
		case spv::CapabilityFPGAArgumentInterfacesINTEL:
			return "FPGAArgumentInterfacesINTEL";
		case spv::CapabilityGlobalVariableHostAccessINTEL:
			return "GlobalVariableHostAccessINTEL";
		case spv::CapabilityGlobalVariableFPGADecorationsINTEL:
			return "GlobalVariableFPGADecorationsINTEL";
		case spv::CapabilityGroupUniformArithmeticKHR:
			return "GroupUniformArithmeticKHR";
		case spv::CapabilityMaskedGatherScatterINTEL:
			return "MaskedGatherScatterINTEL";
		case spv::CapabilityCacheControlsINTEL:
			return "CacheControlsINTEL";
		default:
			AST_Failure( "Unsupported Capability" );
			return "Undefined";
		}
	}

	//*************************************************************************

	ast::type::ImageFormat getImageFormat( spv::ImageFormat value )
	{
		switch ( value )
		{
		case spv::ImageFormatUnknown:
			return ast::type::ImageFormat::eUnknown;
		case spv::ImageFormatRgba32f:
			return ast::type::ImageFormat::eRgba32f;
		case spv::ImageFormatRgba16f:
			return ast::type::ImageFormat::eRgba16f;
		case spv::ImageFormatRg32f:
			return ast::type::ImageFormat::eRg32f;
		case spv::ImageFormatRg16f:
			return ast::type::ImageFormat::eRg16f;
		case spv::ImageFormatR32f:
			return ast::type::ImageFormat::eR32f;
		case spv::ImageFormatR16f:
			return ast::type::ImageFormat::eR16f;
		case spv::ImageFormatRgba32i:
			return ast::type::ImageFormat::eRgba32i;
		case spv::ImageFormatRgba16i:
			return ast::type::ImageFormat::eRgba16i;
		case spv::ImageFormatRgba8i:
			return ast::type::ImageFormat::eRgba8i;
		case spv::ImageFormatRg32i:
			return ast::type::ImageFormat::eRg32i;
		case spv::ImageFormatRg16i:
			return ast::type::ImageFormat::eRg16i;
		case spv::ImageFormatRg8i:
			return ast::type::ImageFormat::eRg8i;
		case spv::ImageFormatR32i:
			return ast::type::ImageFormat::eR32i;
		case spv::ImageFormatR16i:
			return ast::type::ImageFormat::eR16i;
		case spv::ImageFormatR8i:
			return ast::type::ImageFormat::eR8i;
		case spv::ImageFormatRgba32ui:
			return ast::type::ImageFormat::eRgba32u;
		case spv::ImageFormatRgba16ui:
			return ast::type::ImageFormat::eRgba16u;
		case spv::ImageFormatRgba8ui:
			return ast::type::ImageFormat::eRgba8u;
		case spv::ImageFormatRg32ui:
			return ast::type::ImageFormat::eRg32u;
		case spv::ImageFormatRg16ui:
			return ast::type::ImageFormat::eRg16u;
		case spv::ImageFormatRg8ui:
			return ast::type::ImageFormat::eRg8u;
		case spv::ImageFormatR32ui:
			return ast::type::ImageFormat::eR32u;
		case spv::ImageFormatR16ui:
			return ast::type::ImageFormat::eR16u;
		case spv::ImageFormatR8ui:
			return ast::type::ImageFormat::eR8u;
		default:
			AST_Failure( "Unsupported spv::ImageFormat" );
			return ast::type::ImageFormat::eRgba32f;
		}
	}

	ValueIdList makeBinOpOperands( ast::ShaderAllocatorBlock * alloc
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs )
	{
		ValueIdList result{ alloc };
		spv::Op opCode;
		hlp::getBinOpOperands( exprKind, lhsTypeKind, rhsTypeKind, lhs, rhs, result, opCode );
		return makeOperands( alloc, ValueId{ spv::Id( opCode ) }, result );
	}

	InstructionPtr makeImageTypeInstruction( NamesCache & nameCache
		, ast::type::ImageConfiguration const & config
		, ast::type::Trinary isComparison
		, ValueId resultId
		, ValueId sampledTypeId )
	{
		ValueIdList operands{ nameCache.get_allocator() };
		operands.push_back( sampledTypeId );
		operands.emplace_back( spv::Id( hlp::getImageDim( config.dimension ) ) );
		operands.emplace_back( isComparison == ast::type::Trinary::eTrue
			? 1u
			: ( isComparison == ast::type::Trinary::eFalse
				? 0u
				: 2u ) );
		operands.emplace_back( config.isArrayed ? 1u : 0u );
		operands.emplace_back( config.isMS ? 1u : 0u );
		operands.emplace_back( config.isSampled == ast::type::Trinary::eTrue
			? 1u
			: ( isComparison == ast::type::Trinary::eFalse
				? 2u
				: 0u ) );
		operands.emplace_back( uint32_t( hlp::getImageFormat( config.format ) ) );
		// Only available in kernel mode.
		// operands.push_back( uint32_t( config.accessKind ) );

		return makeInstruction< ImageTypeInstruction >( nameCache, resultId, operands );
	}

	InstructionPtr makeAccelerationStructureTypeInstruction( NamesCache & nameCache
		, ValueId resultId )
	{
		return makeInstruction< AccelerationStructureTypeInstruction >( nameCache, resultId );
	}

	InstructionPtr makeBaseTypeInstruction( NamesCache & nameCache
		, ast::type::Kind kind
		, ValueId id )
	{
		assert( !id.isPointer() );
		assert( !isStructType( kind )
			&& !isOpaqueType( kind ) );

		switch ( kind )
		{
		case ast::type::Kind::eVoid:
			return makeInstruction< VoidTypeInstruction >( nameCache, id );
		case ast::type::Kind::eBoolean:
			return makeInstruction< BooleanTypeInstruction >( nameCache, id );
		case ast::type::Kind::eInt8:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 8u }, ValueId{ 1u } );
		case ast::type::Kind::eInt16:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 16u }, ValueId{ 1u } );
		case ast::type::Kind::eInt32:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 32u }, ValueId{ 1u } );
		case ast::type::Kind::eInt64:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 64u }, ValueId{ 1u } );
		case ast::type::Kind::eUInt8:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 8u }, ValueId{ 0u } );
		case ast::type::Kind::eUInt16:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 16u }, ValueId{ 0u } );
		case ast::type::Kind::eUInt32:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 32u }, ValueId{ 0u } );
		case ast::type::Kind::eUInt64:
			return makeInstruction< IntTypeInstruction >( nameCache, id, ValueId{ 64u }, ValueId{ 0u } );
		case ast::type::Kind::eFloat:
			return makeInstruction< FloatTypeInstruction >( nameCache, id, ValueId{ 32u } );
		case ast::type::Kind::eDouble:
			return makeInstruction< FloatTypeInstruction >( nameCache, id, ValueId{ 64u } );
		case ast::type::Kind::eHalf:
			return makeInstruction< FloatTypeInstruction >( nameCache, id, ValueId{ 16u } );
		default:
			AST_Failure( "Unexpected type kind" );
		}

		return nullptr;
	}

	InstructionPtr makeIntrinsicInstruction( NamesCache & nameCache
		, spv::Op op
		, ValueIdList const & operands )
	{
		switch ( op )
		{
		case spv::OpEmitStreamVertex:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEmitStreamVertex > >( nameCache, operands );
		case spv::OpEndStreamPrimitive:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEndStreamPrimitive > >( nameCache, operands );
		case spv::OpEmitVertex:
			assert( operands.empty() );
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEmitVertex > >( nameCache, operands );
		case spv::OpEndPrimitive:
			assert( operands.empty() );
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEndPrimitive > >( nameCache, operands );
		case spv::OpControlBarrier:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpControlBarrier > >( nameCache, operands );
		case spv::OpMemoryBarrier:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpMemoryBarrier > >( nameCache, operands );
		case spv::OpExecuteCallableKHR:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpExecuteCallableKHR > >( nameCache, operands );
		case spv::OpTraceRayKHR:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpTraceRayKHR > >( nameCache, operands );
		case spv::OpWritePackedPrimitiveIndices4x8NV:
			return makeInstruction< WritePackedPrimitiveIndices4x8Instruction >( nameCache, operands );
		case spv::OpSetMeshOutputsEXT:
			return makeInstruction< SetMeshOutputsInstruction >( nameCache, operands );
		case spv::OpEmitMeshTasksEXT:
			return makeInstruction< EmitMeshTasksInstruction >( nameCache, operands );
		default:
			AST_Failure( "Unexpected intrinsic call Op" );
		}

		return nullptr;
	}

	InstructionPtr makeIntrinsicInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands )
	{
		switch ( op )
		{
		case spv::OpFMod:
			return makeInstruction< IntrinsicInstructionT< spv::OpFMod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpIsNan:
			return makeInstruction< IntrinsicInstructionT< spv::OpIsNan > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpIsInf:
			return makeInstruction< IntrinsicInstructionT< spv::OpIsInf > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpBitcast:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitcast > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpDot:
			return makeInstruction< IntrinsicInstructionT< spv::OpDot > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpMatrixTimesMatrix:
			return makeInstruction< IntrinsicInstructionT< spv::OpMatrixTimesMatrix > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpOuterProduct:
			return makeInstruction< IntrinsicInstructionT< spv::OpOuterProduct > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpTranspose:
			return makeInstruction< IntrinsicInstructionT< spv::OpTranspose > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpFOrdLessThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdLessThan > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSLessThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpSLessThan > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpULessThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpULessThan > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpFOrdLessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdLessThanEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSLessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpSLessThanEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpULessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpULessThanEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpFOrdGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdGreaterThan > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpSGreaterThan > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpUGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpUGreaterThan > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpFOrdGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdGreaterThanEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpSGreaterThanEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpUGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpUGreaterThanEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpFOrdEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpIEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpIEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpFOrdNotEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdNotEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpINotEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpINotEqual > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAll:
			return makeInstruction< IntrinsicInstructionT< spv::OpAll > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAny:
			return makeInstruction< IntrinsicInstructionT< spv::OpAny > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpLogicalNot:
			return makeInstruction< IntrinsicInstructionT< spv::OpLogicalNot > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpIAddCarry:
			return makeInstruction< IntrinsicInstructionT< spv::OpIAddCarry > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpISubBorrow:
			return makeInstruction< IntrinsicInstructionT< spv::OpISubBorrow > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpUMulExtended:
			return makeInstruction< IntrinsicInstructionT< spv::OpUMulExtended > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSMulExtended:
			return makeInstruction< IntrinsicInstructionT< spv::OpSMulExtended > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpBitFieldSExtract:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitFieldSExtract > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpBitFieldUExtract:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitFieldUExtract > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpBitFieldInsert:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitFieldInsert > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpBitReverse:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitReverse > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpBitCount:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitCount > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicIAdd:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicIAdd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicFAddEXT:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicFAddEXT > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicSMin:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicSMin > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicUMin:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicUMin > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicSMax:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicSMax > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicUMax:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicUMax > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicAnd:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicAnd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicOr:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicOr > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicXor:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicXor > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicExchange:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicExchange > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicCompareExchange:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicCompareExchange > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpDPdx:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdx > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpDPdxCoarse:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdxCoarse > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpDPdxFine:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdxFine > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpDPdy:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdy > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpDPdyCoarse:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdyCoarse > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpDPdyFine:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdyFine > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpFwidth:
			return makeInstruction< IntrinsicInstructionT< spv::OpFwidth > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpReportIntersectionKHR:
			return makeInstruction< IntrinsicInstructionT< spv::OpReportIntersectionKHR > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpIsHelperInvocationEXT:
			return makeInstruction< IntrinsicInstructionT< spv::OpIsHelperInvocationEXT > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformElect:
			return makeInstruction< GroupNonUniformElectInstruction >( nameCache, returnTypeId, resultId, operands.front() );
		case spv::OpGroupNonUniformAll:
			return makeInstruction< GroupNonUniformAllInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformAny:
			return makeInstruction< GroupNonUniformAnyInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformAllEqual:
			return makeInstruction< GroupNonUniformAllEqualInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBroadcast:
			return makeInstruction< GroupNonUniformBroadcastInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBroadcastFirst:
			return makeInstruction< GroupNonUniformBroadcastFirstInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBallot:
			return makeInstruction< GroupNonUniformBallotInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformInverseBallot:
			return makeInstruction< GroupNonUniformInverseBallotInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBallotBitExtract:
			return makeInstruction< GroupNonUniformBallotBitExtractInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBallotBitCount:
			return makeInstruction< GroupNonUniformBallotBitCountInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBallotFindLSB:
			return makeInstruction< GroupNonUniformBallotFindLSBInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBallotFindMSB:
			return makeInstruction< GroupNonUniformBallotFindMSBInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformShuffle:
			return makeInstruction< GroupNonUniformShuffleInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformShuffleXor:
			return makeInstruction< GroupNonUniformShuffleXorInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformShuffleUp:
			return makeInstruction< GroupNonUniformShuffleUpInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformShuffleDown:
			return makeInstruction< GroupNonUniformShuffleDownInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformFAdd:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformFAdd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformIAdd:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformIAdd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformFMul:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformFMul > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformIMul:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformIMul > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformFMin:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformFMin > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformSMin:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformSMin > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformUMin:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformUMin > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformFMax:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformFMax > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformSMax:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformSMax > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformUMax:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformUMax > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBitwiseAnd:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformBitwiseAnd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformLogicalAnd:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformLogicalAnd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBitwiseOr:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformBitwiseOr > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformLogicalOr:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformLogicalOr > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformBitwiseXor:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformBitwiseXor > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformLogicalXor:
			return makeInstruction< IntrinsicInstructionT< spv::OpGroupNonUniformLogicalXor > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSubgroupBallotKHR:
			return makeInstruction< IntrinsicInstructionT< spv::OpSubgroupBallotKHR > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSubgroupReadInvocationKHR:
			return makeInstruction< IntrinsicInstructionT< spv::OpSubgroupReadInvocationKHR > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpSubgroupFirstInvocationKHR:
			return makeInstruction< IntrinsicInstructionT< spv::OpSubgroupFirstInvocationKHR > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformQuadBroadcast:
			return makeInstruction< GroupNonUniformQuadBroadcastInstruction >( nameCache, returnTypeId, resultId, operands );
		case spv::OpGroupNonUniformQuadSwap:
			return makeInstruction< GroupNonUniformQuadSwapInstruction >( nameCache, returnTypeId, resultId, operands );
		default:
			AST_Failure( "Unexpected intrinsic call Op" );
		}

		return nullptr;
	}

	InstructionPtr makeSampledImageAccessInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands )
	{
		switch ( op )
		{
		case spv::OpImageSampleImplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleDrefImplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleDrefImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjImplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleProjImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjDrefImplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleProjDrefImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleExplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleDrefExplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleDrefExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjExplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleProjExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjDrefExplicitLod:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageSampleProjDrefExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageGather:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageGather > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageDrefGather:
			return makeInstruction< SampledImageAccessInstructionT< spv::OpImageDrefGather > >( nameCache, returnTypeId, resultId, operands );
		default:
			AST_Failure( "Unexpected texture access Op" );
		}

		return nullptr;
	}

	InstructionPtr makeTextureAccessInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands )
	{
		switch ( op )
		{
		case spv::OpImageQuerySizeLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQuerySizeLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageQuerySize:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQuerySize > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageQueryLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQueryLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageQueryLevels:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQueryLevels > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleDrefImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleDrefImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjDrefImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjDrefImplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleDrefExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleDrefExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageSampleProjDrefExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjDrefExplicitLod > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageFetch:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageFetch > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageGather:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageGather > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageDrefGather:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageDrefGather > >( nameCache, returnTypeId, resultId, operands );
		default:
			AST_Failure( "Unexpected texture access Op" );
		}

		return nullptr;
	}

	InstructionPtr makeImageAccessInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands )
	{
		switch ( op )
		{
		case spv::OpImageQuerySize:
			return makeInstruction< ImageAccessInstructionT< spv::OpImageQuerySize > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageQuerySamples:
			return makeInstruction< ImageAccessInstructionT< spv::OpImageQuerySamples > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageRead:
			return makeInstruction< ImageAccessInstructionT< spv::OpImageRead > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpImageWrite:
			AST_Failure( "OpImageWrite has its own instruction type: ImageStoreInstruction, use makeInstruction" );
			return makeInstruction< VariadicInstructionT< spv::OpImageWrite, false, false > >( nameCache, operands );
		case spv::OpAtomicIAdd:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicIAdd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicUMin:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicUMin > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicSMin:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicSMin > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicUMax:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicUMax > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicSMax:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicSMax > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicAnd:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicAnd > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicOr:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicOr > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicXor:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicXor > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicExchange:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicExchange > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicCompareExchange:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicCompareExchange > >( nameCache, returnTypeId, resultId, operands );
		case spv::OpAtomicFAddEXT:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicFAddEXT > >( nameCache, returnTypeId, resultId, operands );
		default:
			AST_Failure( "Unexpected image access Op" );
		}

		return nullptr;
	}

	InstructionPtr makeCastInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueId operandId )
	{
		switch ( op )
		{
		case spv::OpFConvert:
			return makeInstruction< UnInstructionT< spv::OpFConvert > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpConvertFToS:
			return makeInstruction< UnInstructionT< spv::OpConvertFToS > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpConvertFToU:
			return makeInstruction< UnInstructionT< spv::OpConvertFToU > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpConvertSToF:
			return makeInstruction< UnInstructionT< spv::OpConvertSToF > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpConvertUToF:
			return makeInstruction< UnInstructionT< spv::OpConvertUToF > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpBitcast:
			return makeInstruction< UnInstructionT< spv::OpBitcast > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpUConvert:
			return makeInstruction< UnInstructionT< spv::OpUConvert > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpSConvert:
			return makeInstruction< UnInstructionT< spv::OpSConvert > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpConvertUToAccelerationStructureKHR:
			return makeInstruction< UnInstructionT< spv::OpConvertUToAccelerationStructureKHR > >( nameCache, returnTypeId, resultId, operandId );
		case spv::OpConvertUToPtr:
			return makeInstruction< UnInstructionT< spv::OpConvertUToPtr > >( nameCache, returnTypeId, resultId, operandId );
		default:
			AST_Failure( "Unexpected cast Op" );
		}

		return nullptr;
	}

	InstructionPtr makeUnInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind typeKind
		, ValueId operandId )
	{
		return hlp::makeUnInstruction( nameCache
			, getUnOpCode( exprKind, typeKind )
			, returnTypeId
			, resultId
			, operandId );
	}

	InstructionPtr makeBinInstruction( NamesCache & nameCache
		, ValueId typeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs )
	{
		ValueIdList operands{ nameCache.get_allocator() };
		spv::Op opCode;
		hlp::getBinOpOperands( exprKind
			, lhsTypeKind
			, rhsTypeKind
			, lhs
			, rhs
			, operands
			, opCode );
		return hlp::makeBinInstruction( nameCache
			, opCode
			, typeId
			, resultId
			, operands );
	}

	InstructionPtr makeVariableInstruction( NamesCache & nameCache
		, ValueId typeId
		, ValueId varId
		, ValueId initialiser )
	{
		if ( initialiser )
		{
			return makeInstruction< VariableInstruction >( nameCache
				, typeId
				, varId
				, ValueId{ spv::Id( convert( varId.getStorage() ) ) }
				, initialiser );
		}

		return makeInstruction< VariableInstruction >( nameCache
			, typeId
			, varId
			, ValueId{ spv::Id( convert( varId.getStorage() ) ) } );
	}

	ast::expr::ExprPtr makeZero( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::type::Kind kind )
	{
		using ast::type::Kind;
		switch ( kind )
		{
		case Kind::eInt8:
			return exprCache.makeLiteral( typesCache, int8_t( 0 ) );
		case Kind::eInt16:
			return exprCache.makeLiteral( typesCache, int16_t( 0 ) );
		case Kind::eInt32:
			return exprCache.makeLiteral( typesCache, int32_t( 0 ) );
		case Kind::eInt64:
			return exprCache.makeLiteral( typesCache, int64_t( 0 ) );
		case Kind::eUInt8:
			return exprCache.makeLiteral( typesCache, uint8_t( 0u ) );
		case Kind::eUInt16:
			return exprCache.makeLiteral( typesCache, uint16_t( 0u ) );
		case Kind::eUInt32:
			return exprCache.makeLiteral( typesCache, uint32_t( 0u ) );
		case Kind::eUInt64:
			return exprCache.makeLiteral( typesCache, uint64_t( 0u ) );
		case Kind::eHalf:
		case Kind::eFloat:
			return exprCache.makeLiteral( typesCache, 0.0f );
		case Kind::eDouble:
			return exprCache.makeLiteral( typesCache, 0.0 );
		default:
			AST_Failure( "Unsupported type kind for 0 literal" );
			return nullptr;
		}
	}

	ast::expr::ExprPtr makeOne( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::type::Kind kind )
	{
		using ast::type::Kind;
		switch ( kind )
		{
		case Kind::eInt8:
			return exprCache.makeLiteral( typesCache, int8_t( 1 ) );
		case Kind::eInt16:
			return exprCache.makeLiteral( typesCache, int16_t( 1 ) );
		case Kind::eInt32:
			return exprCache.makeLiteral( typesCache, int32_t( 1 ) );
		case Kind::eInt64:
			return exprCache.makeLiteral( typesCache, int64_t( 1 ) );
		case Kind::eUInt8:
			return exprCache.makeLiteral( typesCache, uint8_t( 1u ) );
		case Kind::eUInt16:
			return exprCache.makeLiteral( typesCache, uint16_t( 1u ) );
		case Kind::eUInt32:
			return exprCache.makeLiteral( typesCache, uint32_t( 1u ) );
		case Kind::eUInt64:
			return exprCache.makeLiteral( typesCache, uint64_t( 1u ) );
		case Kind::eHalf:
		case Kind::eFloat:
			return exprCache.makeLiteral( typesCache, 1.0f );
		case Kind::eDouble:
			return exprCache.makeLiteral( typesCache, 1.0 );
		default:
			AST_Failure( "Unsupported type kind for 0 literal" );
			return nullptr;
		}
	}

	ast::expr::ExprPtr makeToBoolCast( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::expr::ExprPtr expr )
	{
		auto componentCount = getComponentCount( expr->getType()->getKind() );
		ast::expr::ExprPtr result{};
		auto type = expr->getType()->getKind();

		if ( componentCount == 1u )
		{
			result = exprCache.makeNotEqual( typesCache
				, std::move( expr )
				, makeZero( exprCache, typesCache, type ) );
		}
		else
		{
			ast::expr::ExprList args;
			ast::expr::ExprPtr newExpr = std::move( expr );

			for ( auto i = 0u; i < componentCount; ++i )
			{
				args.emplace_back( exprCache.makeNotEqual( typesCache
					, exprCache.makeSwizzle( ast::ExprCloner::submit( exprCache, *newExpr ), ast::expr::SwizzleKind::fromOffset( i ) )
					, makeZero( exprCache, typesCache, type ) ) );
			}

			result = exprCache.makeCompositeConstruct( ast::expr::CompositeType( componentCount )
				, ast::type::Kind::eBoolean
				, std::move( args ) );
		}

		return result;
	}

	ast::expr::ExprPtr makeFromBoolCast( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::expr::ExprPtr expr
		, ast::type::Kind dstScalarType )
	{
		auto componentCount = getComponentCount( expr->getType()->getKind() );
		ast::expr::ExprPtr result{};

		if ( componentCount == 1u )
		{
			auto scalarType = typesCache.getBasicType( dstScalarType );
			result = exprCache.makeQuestion( scalarType
				, std::move( expr )
				, makeOne( exprCache, typesCache, dstScalarType )
				, makeZero( exprCache, typesCache, dstScalarType ) );
		}
		else
		{
			ast::expr::ExprList args;
			ast::expr::ExprPtr newExpr = std::move( expr );
			auto scalarType = typesCache.getBasicType( dstScalarType );

			for ( auto i = 0u; i < componentCount; ++i )
			{
				args.emplace_back( exprCache.makeQuestion( scalarType
					, exprCache.makeSwizzle( ast::ExprCloner::submit( exprCache, *newExpr ), ast::expr::SwizzleKind::fromOffset( i ) )
					, makeOne( exprCache, typesCache, dstScalarType )
					, makeZero( exprCache, typesCache, dstScalarType ) ) );
			}

			result = exprCache.makeCompositeConstruct( ast::expr::CompositeType( componentCount )
				, dstScalarType
				, std::move( args ) );
		}

		return result;
	}

	bool isPointerParam( ast::type::TypePtr type
		, bool isOutputParam )
	{
		return isOpaqueType( type->getKind() )
			|| isOutputParam;
	}

	bool isPointerParam( ast::var::Variable const & param )
	{
		return isPointerParam( param.getType()
			, param.isOutputParam() );
	}

	void insertCapability( NamesCache & nameCache
		, InstructionList & capabilities
		, spv::Capability capa )
	{
		auto it = std::find_if( capabilities.begin()
			, capabilities.end()
			, [capa]( InstructionPtr const & lookup )
			{
				return lookup->operands.front() == spv::Id( capa );
			} );

		if ( it == capabilities.end() )
		{
			capabilities.push_back( makeInstruction< CapabilityInstruction >( nameCache
				, ValueId{ spv::Id( capa ) } ) );
		}
	}

	void decorateVar( ast::var::Variable const & var
		, DebugId const & varId
		, Module & shaderModule )
	{
		if ( var.isFlat() )
		{
			shaderModule.decorate( varId, spv::DecorationFlat );
		}

		if ( var.isNoPerspective() )
		{
			shaderModule.decorate( varId, spv::DecorationNoPerspective );
		}

		if ( var.isCentroid() )
		{
			shaderModule.decorate( varId, spv::DecorationCentroid );
		}

		if ( var.isPerSample() )
		{
			shaderModule.decorate( varId, spv::DecorationSample );
		}

		if ( var.isPatch() )
		{
			shaderModule.decorate( varId, spv::DecorationPatch );
		}

		if ( var.isPerPrimitive()
			|| var.getType()->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
		{
			shaderModule.decorate( varId, spv::DecorationPerPrimitiveNV );
		}

		if ( var.isPerTaskNV()
			|| var.getType()->getKind() == ast::type::Kind::eTaskPayloadNV
			|| var.getType()->getKind() == ast::type::Kind::eTaskPayloadInNV )
		{
			shaderModule.decorate( varId, spv::DecorationPerTaskNV );
		}
	}

	spv::StorageClass getStorageClass( uint32_t version
		, ast::var::VariablePtr var
		, spv::StorageClass fallback )
	{
		var = getOutermost( var );
		spv::StorageClass result = fallback;

		if ( var->isHitAttribute() )
		{
			result = spv::StorageClassHitAttributeKHR;
		}
		else if ( var->isIncomingCallableData() )
		{
			result = spv::StorageClassIncomingCallableDataKHR;
		}
		else if ( var->isCallableData() )
		{
			result = spv::StorageClassCallableDataKHR;
		}
		else if ( var->isIncomingRayPayload() )
		{
			result = spv::StorageClassIncomingRayPayloadKHR;
		}
		else if ( var->isRayPayload() )
		{
			result = spv::StorageClassRayPayloadKHR;
		}
		else if ( var->isPerTask() )
		{
			result = spv::StorageClassTaskPayloadWorkgroupEXT;
		}
		else if ( var->isStorageBuffer() )
		{
			if ( version > v1_3 )
			{
				result = spv::StorageClassStorageBuffer;
			}
			else if ( var->isConstant() )
			{
				result = spv::StorageClassUniformConstant;
			}
			else
			{
				result = spv::StorageClassUniform;
			}
		}
		else if ( var->isUniform() )
		{
			if ( var->isConstant() )
			{
				result = spv::StorageClassUniformConstant;
			}
			else
			{
				result = spv::StorageClassUniform;
			}
		}
		else if ( var->isBuiltin() )
		{
			if ( var->isShaderInput() )
			{
				result = spv::StorageClassInput;
			}
			else if ( var->isShaderOutput() )
			{
				result = spv::StorageClassOutput;
			}
			else
			{
				AST_Failure( "Unsupported built-in variable storage." );
			}
		}
		else if ( var->isShaderInput()
			|| var->isPatchInput() )
		{
			result = spv::StorageClassInput;
		}
		else if ( var->isShaderOutput()
			|| var->isPatchOutput() )
		{
			result = spv::StorageClassOutput;
		}
		else if ( var->isShaderConstant() )
		{
			result = spv::StorageClassInput;
		}
		else if ( var->isSpecialisationConstant() )
		{
			result = spv::StorageClassInput;
		}
		else if ( var->isPushConstant() )
		{
			result = spv::StorageClassPushConstant;
		}
		else if ( var->isStatic() )
		{
			result = spv::StorageClassPrivate;
		}
		else if ( var->isShared() )
		{
			result = spv::StorageClassWorkgroup;
		}

		return result;
	}

	//*************************************************************************
}
