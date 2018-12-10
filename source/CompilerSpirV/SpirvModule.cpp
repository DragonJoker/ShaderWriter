/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvModule.hpp"

#include "SpirvHelpers.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#include <algorithm>

namespace spirv
{
	//*************************************************************************

	namespace
	{
		UInt32List deserializePackedName( UInt32ListCIt & buffer
			, uint32_t & index )
		{
			auto popValue = [&buffer, &index]()
			{
				auto result = *buffer;
				++buffer;
				++index;
				return result;
			};
			auto value = popValue();
			UInt32List result;

			while ( ( value & 0xFF000000 ) != 0u )
			{
				result.push_back( value );
				value = popValue();
			}

			result.push_back( value );
			return result;
		}

		std::vector< uint32_t > const & packString( std::string const & name )
		{
			static std::map < std::string, std::vector< uint32_t > > cache;
			auto it = cache.find( name );

			if ( it == cache.end() )
			{
				std::vector< uint32_t > packed;
				uint32_t word{ 0u };
				uint32_t offset{ 0u };
				size_t i = 0u;

				while ( i < name.size() )
				{
					if ( i != 0 && ( i % 4u ) == 0u )
					{
						packed.push_back( word );
						word = 0u;
						offset = 0u;
					}

					word |= ( uint32_t( name[i] ) & 0x000000FF ) << offset;
					++i;
					offset += 8u;
				}

				if ( word )
				{
					packed.push_back( word );
				}

				if ( i != 0 && ( i % 4u ) == 0u )
				{
					packed.push_back( 0u );
				}

				it = cache.emplace( name, packed ).first;
			}

			return it->second;
		}

		std::string unpackString( std::vector< uint32_t > const & packed )
		{
			std::string result;

			for ( auto w : packed )
			{
				for ( uint32_t j = 0; j < 4; j++, w >>= 8 )
				{
					char c = w & 0xff;

					if ( c == '\0' )
					{
						return result;
					}

					result += c;
				}
			}

			assert( false && "Non terminated string" );
			return std::string{};
		}

		spv::BuiltIn getBuiltin( std::string const & name )
		{
			auto result = spv::BuiltIn( -1 );

			if ( name == "gl_Position" )
			{
				result = spv::BuiltInPosition;
			}
			else if ( name == "gl_PointSize" )
			{
				result = spv::BuiltInPointSize;
			}
			else if ( name == "gl_ClipDistance" )
			{
				result = spv::BuiltInClipDistance;
			}
			else if ( name == "gl_CullDistance" )
			{
				result = spv::BuiltInCullDistance;
			}
			else if ( name == "gl_VertexID" )
			{
				result = spv::BuiltInVertexId;
			}
			else if ( name == "gl_InstanceID" )
			{
				result = spv::BuiltInInstanceId;
			}
			else if ( name == "gl_PrimitiveID" )
			{
				result = spv::BuiltInPrimitiveId;
			}
			else if ( name == "gl_InvocationID" )
			{
				result = spv::BuiltInInvocationId;
			}
			else if ( name == "gl_Layer" )
			{
				result = spv::BuiltInLayer;
			}
			else if ( name == "gl_ViewportIndex" )
			{
				result = spv::BuiltInViewportIndex;
			}
			else if ( name == "gl_TessLevelOuter" )
			{
				result = spv::BuiltInTessLevelOuter;
			}
			else if ( name == "gl_TessLevelInner" )
			{
				result = spv::BuiltInTessLevelInner;
			}
			else if ( name == "gl_TessCoord" )
			{
				result = spv::BuiltInTessCoord;
			}
			else if ( name == "gl_PatchVertices" )
			{
				result = spv::BuiltInPatchVertices;
			}
			else if ( name == "gl_FragCoord" )
			{
				result = spv::BuiltInFragCoord;
			}
			else if ( name == "gl_PointCoord" )
			{
				result = spv::BuiltInPointCoord;
			}
			else if ( name == "gl_FrontFacing" )
			{
				result = spv::BuiltInFrontFacing;
			}
			else if ( name == "gl_SampleID" )
			{
				result = spv::BuiltInSampleId;
			}
			else if ( name == "gl_SamplePosition" )
			{
				result = spv::BuiltInSamplePosition;
			}
			else if ( name == "gl_SampleMask" )
			{
				result = spv::BuiltInSampleMask;
			}
			else if ( name == "gl_FragDepth" )
			{
				result = spv::BuiltInFragDepth;
			}
			else if ( name == "gl_HelperInvocation" )
			{
				result = spv::BuiltInHelperInvocation;
			}
			else if ( name == "gl_NumWorkgroups" )
			{
				result = spv::BuiltInNumWorkgroups;
			}
			else if ( name == "gl_WorkgroupSize" )
			{
				result = spv::BuiltInWorkgroupSize;
			}
			else if ( name == "gl_WorkgroupID" )
			{
				result = spv::BuiltInWorkgroupId;
			}
			else if ( name == "gl_LocalInvocationID" )
			{
				result = spv::BuiltInLocalInvocationId;
			}
			else if ( name == "gl_GlobalInvocationID" )
			{
				result = spv::BuiltInGlobalInvocationId;
			}
			else if ( name == "gl_LocalInvocationIndex" )
			{
				result = spv::BuiltInLocalInvocationIndex;
			}
			else if ( name == "gl_WorkDim" )
			{
				result = spv::BuiltInWorkDim;
			}
			else if ( name == "gl_GlobalSize" )
			{
				result = spv::BuiltInGlobalSize;
			}
			else if ( name == "gl_EnqueuedWorkgroupSize" )
			{
				result = spv::BuiltInEnqueuedWorkgroupSize;
			}
			else if ( name == "gl_GlobalOffset" )
			{
				result = spv::BuiltInGlobalOffset;
			}
			else if ( name == "gl_GlobalLinearID" )
			{
				result = spv::BuiltInGlobalLinearId;
			}
			else if ( name == "gl_SubgroupSize" )
			{
				result = spv::BuiltInSubgroupSize;
			}
			else if ( name == "gl_SubgroupMaxSize" )
			{
				result = spv::BuiltInSubgroupMaxSize;
			}
			else if ( name == "gl_NumSubgroups" )
			{
				result = spv::BuiltInNumSubgroups;
			}
			else if ( name == "gl_NumEnqueuedSubgroups" )
			{
				result = spv::BuiltInNumEnqueuedSubgroups;
			}
			else if ( name == "gl_SubgroupID" )
			{
				result = spv::BuiltInSubgroupId;
			}
			else if ( name == "gl_SubgroupLocalInvocationID" )
			{
				result = spv::BuiltInSubgroupLocalInvocationId;
			}
			else if ( name == "gl_VertexIndex" )
			{
				result = spv::BuiltInVertexIndex;
			}
			else if ( name == "gl_InstanceIndex" )
			{
				result = spv::BuiltInInstanceIndex;
			}
			else if ( name == "gl_SubgroupEqMaskKHR" )
			{
				result = spv::BuiltInSubgroupEqMaskKHR;
			}
			else if ( name == "gl_SubgroupGeMaskKHR" )
			{
				result = spv::BuiltInSubgroupGeMaskKHR;
			}
			else if ( name == "gl_SubgroupGtMaskKHR" )
			{
				result = spv::BuiltInSubgroupGtMaskKHR;
			}
			else if ( name == "gl_SubgroupLeMaskKHR" )
			{
				result = spv::BuiltInSubgroupLeMaskKHR;
			}
			else if ( name == "gl_SubgroupLtMaskKHR" )
			{
				result = spv::BuiltInSubgroupLtMaskKHR;
			}
			else if ( name == "gl_BaseVertex" )
			{
				result = spv::BuiltInBaseVertex;
			}
			else if ( name == "gl_BaseInstance" )
			{
				result = spv::BuiltInBaseInstance;
			}
			else if ( name == "gl_DrawIndex" )
			{
				result = spv::BuiltInDrawIndex;
			}
			else if ( name == "gl_DeviceIndex" )
			{
				result = spv::BuiltInDeviceIndex;
			}
			else if ( name == "gl_ViewIndex" )
			{
				result = spv::BuiltInViewIndex;
			}
			else if ( name == "gl_BaryCoordNoPerspAMD" )
			{
				result = spv::BuiltInBaryCoordNoPerspAMD;
			}
			else if ( name == "gl_BaryCoordNoPerspCentroidAMD" )
			{
				result = spv::BuiltInBaryCoordNoPerspCentroidAMD;
			}
			else if ( name == "gl_BaryCoordNoPerspSampleAMD" )
			{
				result = spv::BuiltInBaryCoordNoPerspSampleAMD;
			}
			else if ( name == "gl_BaryCoordSmoothAMD" )
			{
				result = spv::BuiltInBaryCoordSmoothAMD;
			}
			else if ( name == "gl_BaryCoordSmoothCentroidAMD" )
			{
				result = spv::BuiltInBaryCoordSmoothCentroidAMD;
			}
			else if ( name == "gl_BaryCoordSmoothSampleAMD" )
			{
				result = spv::BuiltInBaryCoordSmoothSampleAMD;
			}
			else if ( name == "gl_BaryCoordPullModelAMD" )
			{
				result = spv::BuiltInBaryCoordPullModelAMD;
			}
			else if ( name == "gl_FragStencilRefEXT" )
			{
				result = spv::BuiltInFragStencilRefEXT;
			}
			else if ( name == "gl_ViewportMaskNV" )
			{
				result = spv::BuiltInViewportMaskNV;
			}
			else if ( name == "gl_SecondaryPositionNV" )
			{
				result = spv::BuiltInSecondaryPositionNV;
			}
			else if ( name == "gl_SecondaryViewportMaskNV" )
			{
				result = spv::BuiltInSecondaryViewportMaskNV;
			}
			else if ( name == "gl_PositionPerViewNV" )
			{
				result = spv::BuiltInPositionPerViewNV;
			}
			else if ( name == "gl_ViewportMaskPerViewNV" )
			{
				result = spv::BuiltInViewportMaskPerViewNV;
			}

			return result;
		}

		ast::type::Kind getComponentType( ast::type::ImageFormat format )
		{
			ast::type::Kind result;

			switch ( format )
			{
			case ast::type::ImageFormat::eRgba32f:
			case ast::type::ImageFormat::eRgba16f:
			case ast::type::ImageFormat::eRg32f:
			case ast::type::ImageFormat::eRg16f:
			case ast::type::ImageFormat::eR32f:
			case ast::type::ImageFormat::eR16f:
				return ast::type::Kind::eFloat;

			case ast::type::ImageFormat::eRgba32i:
			case ast::type::ImageFormat::eRgba16i:
			case ast::type::ImageFormat::eRgba8i:
			case ast::type::ImageFormat::eRg32i:
			case ast::type::ImageFormat::eRg16i:
			case ast::type::ImageFormat::eRg8i:
			case ast::type::ImageFormat::eR32i:
			case ast::type::ImageFormat::eR16i:
			case ast::type::ImageFormat::eR8i:
				return ast::type::Kind::eInt;

			case ast::type::ImageFormat::eRgba32u:
			case ast::type::ImageFormat::eRgba16u:
			case ast::type::ImageFormat::eRgba8u:
			case ast::type::ImageFormat::eRg32u:
			case ast::type::ImageFormat::eRg16u:
			case ast::type::ImageFormat::eRg8u:
			case ast::type::ImageFormat::eR32u:
			case ast::type::ImageFormat::eR16u:
			case ast::type::ImageFormat::eR8u:
				return ast::type::Kind::eUInt;

			default:
				assert( false && "Unsupported ast::type::ImageFormat." );
				return ast::type::Kind::eFloat;
			}

			return result;
		}

		ast::type::TypePtr getUnqualifiedType( ast::type::TypePtr qualified );

		ast::type::StructPtr getUnqualifiedType( ast::type::Struct const & qualified )
		{
			auto result = qualified.getCache().getStruct( qualified.getMemoryLayout(), qualified.getName() );
			assert( result->empty() || ( result->size() == qualified.size() ) );

			if ( result->empty() && !qualified.empty() )
			{
				for ( auto & member : qualified )
				{
					auto type = getUnqualifiedType( member.type );

					if ( type->getKind() == ast::type::Kind::eArray )
					{
						result->declMember( member.name
							, std::static_pointer_cast< ast::type::Array >( type ) );
					}
					else if ( type->getKind() == ast::type::Kind::eStruct )
					{
						result->declMember( member.name
							, std::static_pointer_cast< ast::type::Struct >( type ) );
					}
					else
					{
						result->declMember( member.name
							, type );
					}
				}
			}

			return result;
		}

		ast::type::ArrayPtr getUnqualifiedType( ast::type::Array const & qualified )
		{
			return qualified.getCache().getArray( getUnqualifiedType( qualified.getType() ), qualified.getArraySize() );
		}

		ast::type::SamplerPtr getUnqualifiedType( ast::type::Sampler const & qualified )
		{
			return qualified.getCache().getSampler( qualified.isComparison() );
		}

		ast::type::SampledImagePtr getUnqualifiedType( ast::type::SampledImage const & qualified )
		{
			return qualified.getCache().getSampledImage( qualified.getConfig() );
		}

		ast::type::ImagePtr getUnqualifiedType( ast::type::Image const & qualified )
		{
			return qualified.getCache().getImage( qualified.getConfig() );
		}

		ast::type::TypePtr getUnqualifiedType( ast::type::Type const & qualified )
		{
			ast::type::TypePtr result;

			if ( qualified.getKind() == ast::type::Kind::eArray )
			{
				result = getUnqualifiedType( static_cast< ast::type::Array const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eStruct )
			{
				result = getUnqualifiedType( static_cast< ast::type::Struct const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eImage )
			{
				result = getUnqualifiedType( static_cast< ast::type::Image const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eSampledImage )
			{
				result = getUnqualifiedType( static_cast< ast::type::SampledImage const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eSampler )
			{
				result = getUnqualifiedType( static_cast< ast::type::Sampler const & >( qualified ) );
			}
			else if ( qualified.isMember() )
			{
				result = qualified.getCache().makeType( qualified.getKind() );
			}

			return result;
		}

		ast::type::TypePtr getUnqualifiedType( ast::type::TypePtr qualified )
		{
			ast::type::TypePtr result = getUnqualifiedType( *qualified );
			return result
				? result
				: qualified;
		}

		ast::type::MemoryLayout getMemoryLayout( ast::type::Type const & type )
		{
			ast::type::MemoryLayout result{ ast::type::MemoryLayout::eStd430 };
			auto kind = type.getKind();

			if ( kind == ast::type::Kind::eArray )
			{
				if ( type.isMember() )
				{
					result = getMemoryLayout( *type.getParent() );
				}
				else
				{
					result = getMemoryLayout( *static_cast< ast::type::Array const & >( type ).getType() );
				}
			}
			else if ( kind == ast::type::Kind::eStruct )
			{
				auto & structType = static_cast< ast::type::Struct const & >( type );
				result = structType.getMemoryLayout();
			}
			else if ( type.isMember() )
			{
				result = getMemoryLayout( *type.getParent() );
			}

			return result;
		}

		void writeArrayStride( Module & module
			, ast::type::TypePtr type
			, uint32_t typeId
			, uint32_t arrayStride )
		{
			auto kind = getNonArrayKind( type );

			if ( kind != ast::type::Kind::eImage
				&& kind != ast::type::Kind::eSampledImage
				&& kind != ast::type::Kind::eSampler )
			{
				module.decorate( typeId
					, IdList
					{
						uint32_t( spv::DecorationArrayStride ),
						arrayStride
					} );
			}
		}

		Instruction::Config const & getConfig( spv::Op opCode )
		{
			static Instruction::Config dummy{};

			switch ( opCode )
			{
			case spv::Op::OpSource:
				return SourceInstruction::config;
			case spv::Op::OpName:
				return NameInstruction::config;
			case spv::Op::OpMemberName:
				return MemberNameInstruction::config;
			case spv::Op::OpExtension:
				return ExtensionInstruction::config;
			case spv::Op::OpExtInstImport:
				return ExtInstImportInstruction::config;
			case spv::Op::OpExtInst:
				return ExtInstInstruction::config;
			case spv::Op::OpMemoryModel:
				return MemoryModelInstruction::config;
			case spv::Op::OpEntryPoint:
				return EntryPointInstruction::config;
			case spv::Op::OpExecutionMode:
				return ExecutionModeInstruction::config;
			case spv::Op::OpCapability:
				return CapabilityInstruction::config;
			case spv::Op::OpTypeVoid:
				return VoidTypeInstruction::config;
			case spv::Op::OpTypeBool:
				return BooleanTypeInstruction::config;
			case spv::Op::OpTypeInt:
				return IntTypeInstruction::config;
			case spv::Op::OpTypeFloat:
				return FloatTypeInstruction::config;
			case spv::Op::OpTypeVector:
				return VectorTypeInstruction::config;
			case spv::Op::OpTypeMatrix:
				return MatrixTypeInstruction::config;
			case spv::Op::OpTypeImage:
				return ImageTypeInstruction::config;
			case spv::Op::OpTypeSampler:
				return SamplerTypeInstruction::config;
			case spv::Op::OpTypeSampledImage:
				return SampledImageTypeInstruction::config;
			case spv::Op::OpTypeArray:
				return ArrayTypeInstruction::config;
			case spv::Op::OpTypeRuntimeArray:
				return RuntimeArrayTypeInstruction::config;
			case spv::Op::OpTypeStruct:
				return StructTypeInstruction::config;
			case spv::Op::OpTypePointer:
				return PointerTypeInstruction::config;
			case spv::Op::OpTypeFunction:
				return FunctionTypeInstruction::config;
			case spv::Op::OpConstantTrue:
				return ConstantTrueInstruction::config;
			case spv::Op::OpConstantFalse:
				return ConstantFalseInstruction::config;
			case spv::Op::OpConstant:
				return ConstantInstruction::config;
			case spv::Op::OpConstantComposite:
				return ConstantCompositeInstruction::config;
			case spv::Op::OpSpecConstantTrue:
				return SpecConstantTrueInstruction::config;
			case spv::Op::OpSpecConstantFalse:
				return SpecConstantFalseInstruction::config;
			case spv::Op::OpSpecConstant:
				return SpecConstantInstruction::config;
			case spv::Op::OpSpecConstantComposite:
				return SpecConstantCompositeInstruction::config;
			case spv::Op::OpSpecConstantOp:
				return SpecConstantOpInstruction::config;
			case spv::Op::OpFunction:
				return FunctionInstruction::config;
			case spv::Op::OpFunctionParameter:
				return FunctionParameterInstruction::config;
			case spv::Op::OpFunctionEnd:
				return FunctionEndInstruction::config;
			case spv::Op::OpFunctionCall:
				return FunctionCallInstruction::config;
			case spv::Op::OpVariable:
				return VariableInstruction::config;
			case spv::Op::OpImageTexelPointer:
				return ImageTexelPointerInstruction::config;
			case spv::Op::OpLoad:
				return LoadInstruction::config;
			case spv::Op::OpStore:
				return StoreInstruction::config;
			case spv::Op::OpAccessChain:
				return AccessChainInstruction::config;
			case spv::Op::OpDecorate:
				return DecorateInstruction::config;
			case spv::Op::OpMemberDecorate:
				return MemberDecorateInstruction::config;
			case spv::Op::OpVectorShuffle:
				return VectorShuffleInstruction::config;
			case spv::Op::OpCompositeConstruct:
				return CompositeConstructInstruction::config;
			case spv::Op::OpCompositeExtract:
				return CompositeExtractInstruction::config;
			case spv::Op::OpTranspose:
				return IntrinsicInstructionT< spv::Op::OpTranspose >::config;
			case spv::Op::OpImageSampleImplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleImplicitLod >::config;
			case spv::Op::OpImageSampleExplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleExplicitLod >::config;
			case spv::Op::OpImageSampleDrefImplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleDrefImplicitLod >::config;
			case spv::Op::OpImageSampleDrefExplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleDrefExplicitLod >::config;
			case spv::Op::OpImageSampleProjImplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleProjImplicitLod >::config;
			case spv::Op::OpImageSampleProjExplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleProjExplicitLod >::config;
			case spv::Op::OpImageSampleProjDrefImplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleProjDrefImplicitLod >::config;
			case spv::Op::OpImageSampleProjDrefExplicitLod:
				return TextureAccessInstructionT< spv::Op::OpImageSampleProjDrefExplicitLod >::config;
			case spv::Op::OpImageFetch:
				return TextureAccessInstructionT< spv::Op::OpImageFetch >::config;
			case spv::Op::OpImageGather:
				return TextureAccessInstructionT< spv::Op::OpImageGather >::config;
			case spv::Op::OpImageDrefGather:
				return TextureAccessInstructionT< spv::Op::OpImageDrefGather >::config;
			case spv::Op::OpImageRead:
				return ImageAccessInstructionT< spv::Op::OpImageRead >::config;
			case spv::Op::OpImageWrite:
				return ImageAccessInstructionT< spv::Op::OpImageWrite >::config;
			case spv::Op::OpImage:
				return ImageInstruction::config;
			case spv::Op::OpImageQueryFormat:
				return ImageAccessInstructionT< spv::Op::OpImageQueryFormat >::config;
			case spv::Op::OpImageQueryOrder:
				return ImageAccessInstructionT< spv::Op::OpImageQueryOrder >::config;
			case spv::Op::OpImageQuerySizeLod:
				return ImageAccessInstructionT< spv::Op::OpImageQuerySizeLod >::config;
			case spv::Op::OpImageQuerySize:
				return ImageAccessInstructionT< spv::Op::OpImageQuerySize >::config;
			case spv::Op::OpImageQueryLod:
				return ImageAccessInstructionT< spv::Op::OpImageQueryLod >::config;
			case spv::Op::OpImageQueryLevels:
				return ImageAccessInstructionT< spv::Op::OpImageQueryLevels >::config;
			case spv::Op::OpImageQuerySamples:
				return ImageAccessInstructionT< spv::Op::OpImageQuerySamples >::config;
			case spv::Op::OpConvertFToU:
				return UnInstructionT< spv::Op::OpConvertFToU >::config;
			case spv::Op::OpConvertFToS:
				return UnInstructionT< spv::Op::OpConvertFToS >::config;
			case spv::Op::OpConvertSToF:
				return UnInstructionT< spv::Op::OpConvertSToF >::config;
			case spv::Op::OpConvertUToF:
				return UnInstructionT< spv::Op::OpConvertUToF >::config;
			case spv::Op::OpUConvert:
				return UnInstructionT< spv::Op::OpUConvert >::config;
			case spv::Op::OpSConvert:
				return UnInstructionT< spv::Op::OpSConvert >::config;
			case spv::Op::OpFConvert:
				return UnInstructionT< spv::Op::OpFConvert >::config;
			case spv::Op::OpQuantizeToF16:
				return UnInstructionT< spv::Op::OpQuantizeToF16 >::config;
			case spv::Op::OpConvertPtrToU:
				return UnInstructionT< spv::Op::OpConvertPtrToU >::config;
			case spv::Op::OpSatConvertSToU:
				return UnInstructionT< spv::Op::OpSatConvertSToU >::config;
			case spv::Op::OpSatConvertUToS:
				return UnInstructionT< spv::Op::OpSatConvertUToS >::config;
			case spv::Op::OpConvertUToPtr:
				return UnInstructionT< spv::Op::OpConvertUToPtr >::config;
			case spv::Op::OpPtrCastToGeneric:
				return UnInstructionT< spv::Op::OpPtrCastToGeneric >::config;
			case spv::Op::OpGenericCastToPtr:
				return UnInstructionT< spv::Op::OpGenericCastToPtr >::config;
			case spv::Op::OpGenericCastToPtrExplicit:
				return UnInstructionT< spv::Op::OpGenericCastToPtrExplicit >::config;
			case spv::Op::OpBitcast:
				return UnInstructionT< spv::Op::OpBitcast >::config;
			case spv::Op::OpSNegate:
				return UnInstructionT< spv::Op::OpSNegate >::config;
			case spv::Op::OpFNegate:
				return UnInstructionT< spv::Op::OpFNegate >::config;
			case spv::Op::OpIAdd:
				return UnInstructionT < spv::Op::OpIAdd >::config;
			case spv::Op::OpFAdd:
				return UnInstructionT < spv::Op::OpFAdd >::config;
			case spv::Op::OpISub:
				return UnInstructionT < spv::Op::OpISub >::config;
			case spv::Op::OpFSub:
				return UnInstructionT < spv::Op::OpFSub >::config;
			case spv::Op::OpIMul:
				return UnInstructionT < spv::Op::OpIMul >::config;
			case spv::Op::OpFMul:
				return UnInstructionT < spv::Op::OpFMul >::config;
			case spv::Op::OpUDiv:
				return UnInstructionT < spv::Op::OpUDiv >::config;
			case spv::Op::OpSDiv:
				return UnInstructionT < spv::Op::OpSDiv >::config;
			case spv::Op::OpFDiv:
				return UnInstructionT < spv::Op::OpFDiv >::config;
			case spv::Op::OpUMod:
				return UnInstructionT < spv::Op::OpUMod >::config;
			case spv::Op::OpSRem:
				return UnInstructionT < spv::Op::OpSRem >::config;
			case spv::Op::OpSMod:
				return UnInstructionT < spv::Op::OpSMod >::config;
			case spv::Op::OpFRem:
				return UnInstructionT < spv::Op::OpFRem >::config;
			case spv::Op::OpFMod:
				return UnInstructionT < spv::Op::OpFMod >::config;
			case spv::Op::OpVectorTimesScalar:
				return UnInstructionT < spv::Op::OpVectorTimesScalar >::config;
			case spv::Op::OpMatrixTimesScalar:
				return UnInstructionT < spv::Op::OpMatrixTimesScalar >::config;
			case spv::Op::OpVectorTimesMatrix:
				return UnInstructionT < spv::Op::OpVectorTimesMatrix >::config;
			case spv::Op::OpMatrixTimesVector:
				return UnInstructionT < spv::Op::OpMatrixTimesVector >::config;
			case spv::Op::OpMatrixTimesMatrix:
				return UnInstructionT < spv::Op::OpMatrixTimesMatrix >::config;
			case spv::Op::OpOuterProduct:
				return IntrinsicInstructionT< spv::Op::OpOuterProduct >::config;
			case spv::Op::OpDot:
				return IntrinsicInstructionT< spv::Op::OpDot >::config;
			case spv::Op::OpIAddCarry:
				return IntrinsicInstructionT< spv::Op::OpIAddCarry >::config;
			case spv::Op::OpISubBorrow:
				return IntrinsicInstructionT< spv::Op::OpISubBorrow >::config;
			case spv::Op::OpUMulExtended:
				return IntrinsicInstructionT< spv::Op::OpUMulExtended >::config;
			case spv::Op::OpSMulExtended:
				return IntrinsicInstructionT< spv::Op::OpSMulExtended >::config;
			case spv::Op::OpAny:
				return IntrinsicInstructionT< spv::Op::OpAny >::config;
			case spv::Op::OpAll:
				return IntrinsicInstructionT< spv::Op::OpAll >::config;
			case spv::Op::OpIsNan:
				return IntrinsicInstructionT< spv::Op::OpIsNan >::config;
			case spv::Op::OpIsInf:
				return IntrinsicInstructionT< spv::Op::OpIsInf >::config;
			case spv::Op::OpIsFinite:
				return IntrinsicInstructionT< spv::Op::OpIsFinite >::config;
			case spv::Op::OpIsNormal:
				return IntrinsicInstructionT< spv::Op::OpIsNormal >::config;
			case spv::Op::OpSignBitSet:
				return IntrinsicInstructionT< spv::Op::OpSignBitSet >::config;
			case spv::Op::OpLogicalEqual:
				return BinInstructionT < spv::Op::OpLogicalEqual >::config;
			case spv::Op::OpLogicalNotEqual:
				return BinInstructionT < spv::Op::OpLogicalNotEqual >::config;
			case spv::Op::OpLogicalOr:
				return BinInstructionT < spv::Op::OpLogicalOr >::config;
			case spv::Op::OpLogicalAnd:
				return BinInstructionT < spv::Op::OpLogicalAnd >::config;
			case spv::Op::OpLogicalNot:
				return BinInstructionT < spv::Op::OpLogicalNot >::config;
			case spv::Op::OpSelect:
				return SelectInstruction::config;
			case spv::Op::OpIEqual:
				return BinInstructionT < spv::Op::OpIEqual >::config;
			case spv::Op::OpINotEqual:
				return BinInstructionT < spv::Op::OpINotEqual >::config;
			case spv::Op::OpUGreaterThan:
				return BinInstructionT < spv::Op::OpUGreaterThan >::config;
			case spv::Op::OpSGreaterThan:
				return BinInstructionT < spv::Op::OpSGreaterThan >::config;
			case spv::Op::OpUGreaterThanEqual:
				return BinInstructionT < spv::Op::OpUGreaterThanEqual >::config;
			case spv::Op::OpSGreaterThanEqual:
				return BinInstructionT < spv::Op::OpSGreaterThanEqual >::config;
			case spv::Op::OpULessThan:
				return BinInstructionT < spv::Op::OpULessThan >::config;
			case spv::Op::OpSLessThan:
				return BinInstructionT < spv::Op::OpSLessThan >::config;
			case spv::Op::OpULessThanEqual:
				return BinInstructionT < spv::Op::OpULessThanEqual >::config;
			case spv::Op::OpSLessThanEqual:
				return BinInstructionT < spv::Op::OpSLessThanEqual >::config;
			case spv::Op::OpFOrdEqual:
				return BinInstructionT < spv::Op::OpFOrdEqual >::config;
			case spv::Op::OpFUnordEqual:
				return BinInstructionT < spv::Op::OpFUnordEqual >::config;
			case spv::Op::OpFOrdNotEqual:
				return BinInstructionT < spv::Op::OpFOrdNotEqual >::config;
			case spv::Op::OpFUnordNotEqual:
				return BinInstructionT < spv::Op::OpFUnordNotEqual >::config;
			case spv::Op::OpFOrdLessThan:
				return BinInstructionT < spv::Op::OpFOrdLessThan >::config;
			case spv::Op::OpFUnordLessThan:
				return BinInstructionT < spv::Op::OpFUnordLessThan >::config;
			case spv::Op::OpFOrdGreaterThan:
				return BinInstructionT < spv::Op::OpFOrdGreaterThan >::config;
			case spv::Op::OpFUnordGreaterThan:
				return BinInstructionT < spv::Op::OpFUnordGreaterThan >::config;
			case spv::Op::OpFOrdLessThanEqual:
				return BinInstructionT < spv::Op::OpFOrdLessThanEqual >::config;
			case spv::Op::OpFUnordLessThanEqual:
				return BinInstructionT < spv::Op::OpFUnordLessThanEqual >::config;
			case spv::Op::OpFOrdGreaterThanEqual:
				return BinInstructionT < spv::Op::OpFOrdGreaterThanEqual >::config;
			case spv::Op::OpFUnordGreaterThanEqual:
				return BinInstructionT < spv::Op::OpFUnordGreaterThanEqual >::config;
			case spv::Op::OpShiftRightLogical:
				return BinInstructionT < spv::Op::OpShiftRightLogical >::config;
			case spv::Op::OpShiftRightArithmetic:
				return BinInstructionT < spv::Op::OpShiftRightArithmetic >::config;
			case spv::Op::OpShiftLeftLogical:
				return BinInstructionT < spv::Op::OpShiftLeftLogical >::config;
			case spv::Op::OpBitwiseOr:
				return BinInstructionT < spv::Op::OpBitwiseOr >::config;
			case spv::Op::OpBitwiseXor:
				return BinInstructionT < spv::Op::OpBitwiseXor >::config;
			case spv::Op::OpBitwiseAnd:
				return BinInstructionT < spv::Op::OpBitwiseAnd >::config;
			case spv::Op::OpNot:
				return UnInstructionT < spv::Op::OpNot >::config;
			case spv::Op::OpBitFieldInsert:
				return IntrinsicInstructionT< spv::Op::OpBitFieldInsert >::config;
			case spv::Op::OpBitFieldSExtract:
				return IntrinsicInstructionT< spv::Op::OpBitFieldSExtract >::config;
			case spv::Op::OpBitFieldUExtract:
				return IntrinsicInstructionT< spv::Op::OpBitFieldUExtract >::config;
			case spv::Op::OpBitReverse:
				return IntrinsicInstructionT< spv::Op::OpBitReverse >::config;
			case spv::Op::OpBitCount:
				return IntrinsicInstructionT< spv::Op::OpBitCount >::config;
			case spv::Op::OpDPdx:
				return IntrinsicInstructionT< spv::Op::OpDPdx >::config;
			case spv::Op::OpDPdy:
				return IntrinsicInstructionT< spv::Op::OpDPdy >::config;
			case spv::Op::OpFwidth:
				return IntrinsicInstructionT< spv::Op::OpFwidth >::config;
			case spv::Op::OpDPdxFine:
				return IntrinsicInstructionT< spv::Op::OpDPdxFine >::config;
			case spv::Op::OpDPdyFine:
				return IntrinsicInstructionT< spv::Op::OpDPdyFine >::config;
			case spv::Op::OpFwidthFine:
				return IntrinsicInstructionT< spv::Op::OpFwidthFine >::config;
			case spv::Op::OpDPdxCoarse:
				return IntrinsicInstructionT< spv::Op::OpDPdxCoarse >::config;
			case spv::Op::OpDPdyCoarse:
				return IntrinsicInstructionT< spv::Op::OpDPdyCoarse >::config;
			case spv::Op::OpFwidthCoarse:
				return IntrinsicInstructionT< spv::Op::OpFwidthCoarse >::config;
			case spv::Op::OpEmitVertex:
				return IntrinsicInstructionT< spv::Op::OpEmitVertex >::config;
			case spv::Op::OpEndPrimitive:
				return IntrinsicInstructionT< spv::Op::OpEndPrimitive >::config;
			case spv::Op::OpEmitStreamVertex:
				return IntrinsicInstructionT< spv::Op::OpEmitStreamVertex >::config;
			case spv::Op::OpEndStreamPrimitive:
				return IntrinsicInstructionT< spv::Op::OpEndStreamPrimitive >::config;
			case spv::Op::OpControlBarrier:
				return IntrinsicInstructionT< spv::Op::OpControlBarrier >::config;
			case spv::Op::OpMemoryBarrier:
				return IntrinsicInstructionT< spv::Op::OpMemoryBarrier >::config;
			case spv::Op::OpAtomicLoad:
				return IntrinsicInstructionT< spv::Op::OpAtomicLoad >::config;
			case spv::Op::OpAtomicStore:
				return IntrinsicInstructionT< spv::Op::OpAtomicStore >::config;
			case spv::Op::OpAtomicExchange:
				return IntrinsicInstructionT< spv::Op::OpAtomicExchange >::config;
			case spv::Op::OpAtomicCompareExchange:
				return IntrinsicInstructionT< spv::Op::OpAtomicCompareExchange >::config;
			case spv::Op::OpAtomicCompareExchangeWeak:
				return IntrinsicInstructionT< spv::Op::OpAtomicCompareExchangeWeak >::config;
			case spv::Op::OpAtomicIIncrement:
				return IntrinsicInstructionT< spv::Op::OpAtomicIIncrement >::config;
			case spv::Op::OpAtomicIDecrement:
				return IntrinsicInstructionT< spv::Op::OpAtomicIDecrement >::config;
			case spv::Op::OpAtomicIAdd:
				return IntrinsicInstructionT< spv::Op::OpAtomicIAdd >::config;
			case spv::Op::OpAtomicISub:
				return IntrinsicInstructionT< spv::Op::OpAtomicISub >::config;
			case spv::Op::OpAtomicSMin:
				return IntrinsicInstructionT< spv::Op::OpAtomicSMin >::config;
			case spv::Op::OpAtomicUMin:
				return IntrinsicInstructionT< spv::Op::OpAtomicUMin >::config;
			case spv::Op::OpAtomicSMax:
				return IntrinsicInstructionT< spv::Op::OpAtomicSMax >::config;
			case spv::Op::OpAtomicUMax:
				return IntrinsicInstructionT< spv::Op::OpAtomicUMax >::config;
			case spv::Op::OpAtomicAnd:
				return IntrinsicInstructionT< spv::Op::OpAtomicAnd >::config;
			case spv::Op::OpAtomicOr:
				return IntrinsicInstructionT< spv::Op::OpAtomicOr >::config;
			case spv::Op::OpAtomicXor:
				return IntrinsicInstructionT< spv::Op::OpAtomicXor >::config;
			case spv::Op::OpLoopMerge:
				return LoopMergeInstruction::config;
			case spv::Op::OpSelectionMerge:
				return SelectionMergeInstruction::config;
			case spv::Op::OpLabel:
				return LabelInstruction::config;
			case spv::Op::OpBranch:
				return BranchInstruction::config;
			case spv::Op::OpBranchConditional:
				return BranchConditionalInstruction::config;
			case spv::Op::OpSwitch:
				return SwitchInstruction::config;
			case spv::Op::OpKill:
				return KillInstruction::config;
			case spv::Op::OpReturn:
				return ReturnInstruction::config;
			case spv::Op::OpReturnValue:
				return ReturnValueInstruction::config;
			case spv::Op::OpImageSparseSampleImplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleImplicitLod >::config;
			case spv::Op::OpImageSparseSampleExplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleExplicitLod >::config;
			case spv::Op::OpImageSparseSampleDrefImplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleDrefImplicitLod >::config;
			case spv::Op::OpImageSparseSampleDrefExplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleDrefExplicitLod >::config;
			case spv::Op::OpImageSparseSampleProjImplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleProjImplicitLod >::config;
			case spv::Op::OpImageSparseSampleProjExplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleProjExplicitLod >::config;
			case spv::Op::OpImageSparseSampleProjDrefImplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleProjDrefImplicitLod >::config;
			case spv::Op::OpImageSparseSampleProjDrefExplicitLod:
				return ImageAccessInstructionT< spv::Op::OpImageSparseSampleProjDrefExplicitLod >::config;
			case spv::Op::OpImageSparseFetch:
				return ImageAccessInstructionT< spv::Op::OpImageSparseFetch >::config;
			case spv::Op::OpImageSparseGather:
				return ImageAccessInstructionT< spv::Op::OpImageSparseGather >::config;
			case spv::Op::OpImageSparseDrefGather:
				return ImageAccessInstructionT< spv::Op::OpImageSparseDrefGather >::config;
			case spv::Op::OpImageSparseTexelsResident:
				return ImageAccessInstructionT< spv::Op::OpImageSparseTexelsResident >::config;
			case spv::Op::OpImageSparseRead:
				return ImageAccessInstructionT < spv::Op::OpImageSparseRead >::config;
			default:
				assert( false && "Unsupported Instruction operator" );
				return dummy;
			}
		}
	}

	//*************************************************************************

	size_t IdListHasher::operator()( IdList const & list )const
	{
		assert( !list.empty() );
		auto hash = std::hash< spv::Id >{}( list[0] );

		std::for_each( list.begin() + 1u
			, list.end()
			, [&hash]( spv::Id id )
			{
				ast::type::hashCombine( hash, id );
			} );

		return hash;
	}

	//*************************************************************************

	Instruction::Instruction( Config const & config
		, spv::Op op
		, std::optional< spv::Id > returnTypeId
		, std::optional< spv::Id > resultId
		, IdList operands
		, std::optional< std::string > name
		, std::optional< std::map< int32_t, spv::Id > > labels )
		: returnTypeId{ returnTypeId }
		, resultId{ resultId }
		, operands{ operands }
		, packedName{ std::nullopt }
		, config{ config }
		, name{ name }
		, labels{ labels }
	{
		if ( bool( this->name ) )
		{
			packedName = packString( this->name.value() );
		}

		this->op.op = op;
		this->op.opCount = uint16_t( 1u
			+ ( bool( this->returnTypeId ) ? 1u : 0u )
			+ ( bool( this->resultId ) ? 1u : 0u )
			+ this->operands.size()
			+ ( bool( this->packedName ) ? this->packedName.value().size() : 0u ) );

		assertType( *this, config );
	}

	Instruction::Instruction( Config const & config
		, Op op
		, UInt32ListCIt & buffer )
		: op{ op }
		, config{ config }
	{
		uint32_t index = 1u;
		auto popValue = [&buffer, &index]()
		{
			auto result = *buffer;
			++buffer;
			++index;
			return result;
		};

		if ( config.hasReturnTypeId )
		{
			returnTypeId = popValue();
		}

		if ( config.hasResultId )
		{
			resultId = popValue();
		}

		if ( config.hasName )
		{
			packedName = deserializePackedName( buffer, index );
			name = unpackString( packedName.value() );
		}

		if ( config.operandsCount )
		{
			auto count = op.opCount - index;
			operands.resize( count );

			for ( auto & operand : operands )
			{
				operand = popValue();
			}
		}
		else if ( config.hasLabels )
		{
			auto count = ( op.opCount - index ) / 2u;
			labels = std::map< int32_t, spv::Id >{};

			for ( auto i = 0u; i < count; ++i )
			{
				auto label = popValue();
				labels.value()[label] = popValue();
			}
		}
	}

	Instruction::~Instruction()
	{
	}

	void Instruction::serialize( UInt32List & buffer
		, Instruction const & instruction )
	{
		assertType( instruction, instruction.config );

		auto pushValue = [&buffer]( uint32_t value )
		{
			buffer.push_back( value );
		};

		pushValue( instruction.op.opValue );

		if ( instruction.returnTypeId )
		{
			pushValue( instruction.returnTypeId.value() );
		}
		
		if ( instruction.resultId )
		{
			pushValue( instruction.resultId.value() );
		}

		if ( instruction.packedName )
		{
			for ( auto & c : instruction.packedName.value() )
			{
				pushValue( c );
			}
		}

		if ( !instruction.operands.empty() )
		{
			for ( auto & operand : instruction.operands )
			{
				pushValue( operand );
			}
		}

		if ( instruction.labels )
		{
			for ( auto & label : instruction.labels.value() )
			{
				pushValue( label.first );
				pushValue( label.second );
			}
		}
	}

	InstructionPtr Instruction::deserialize( UInt32ListCIt & buffer )
	{
		auto index = 0u;
		auto popValue = [&buffer, &index]()
		{
			auto result = *buffer;
			++buffer;
			++index;
			return result;
		};
		spirv::Op op;
		op.opValue = popValue();
		assert( op.opCode != spv::Op::OpNop );
		auto & config = getConfig( spv::Op( op.opCode ) );
		return std::make_unique< Instruction >( config, op, buffer );
	}

	//*************************************************************************

	Block Block::deserialize( InstructionPtr firstInstruction
		, InstructionListIt & buffer
		, InstructionListIt & end )
	{
		auto popValue = [&buffer]()
		{
			auto result = std::move( *buffer );
			++buffer;
			return result;
		};
		auto isLastBlockInstruction = []( spv::Op opCode )
		{
			return opCode == spv::Op::OpBranch
				|| opCode == spv::Op::OpBranchConditional
				|| opCode == spv::Op::OpFunctionEnd;
		};

		spv::Op op = spv::Op::OpNop;
		Block result;
		result.label = firstInstruction->resultId.value();
		result.instructions.emplace_back( std::move( firstInstruction ) );

		while ( buffer != end
			&& !isLastBlockInstruction( op ) )
		{
			op = spv::Op( ( *buffer )->op.opCode );

			if ( !isLastBlockInstruction( op ) )
			{
				result.instructions.emplace_back( popValue() );
			}
		}

		if ( buffer != end )
		{
			result.blockEnd = std::move( popValue() );
		}

		return result;
	}

	//*************************************************************************

	Function Function::deserialize( InstructionListIt & buffer
		, InstructionListIt & end )
	{
		auto popValue = [&buffer]()
		{
			auto result = std::move( *buffer );
			++buffer;
			return result;
		};
		auto isDeclarationInstruction = []( spv::Op opCode )
		{
			return opCode == spv::Op::OpFunction
				|| opCode == spv::Op::OpFunctionParameter
				|| opCode == spv::Op::OpVariable;
		};

		Function result;

		while ( buffer != end )
		{
			auto instruction = popValue();

			if ( isDeclarationInstruction( spv::Op( instruction->op.opCode ) ) )
			{
				result.declaration.emplace_back( std::move( instruction ) );
			}
			else
			{
				result.cfg.blocks.emplace_back( Block::deserialize( std::move( instruction ), buffer, end ) );
			}
		}
		
		return result;
	}

	//*************************************************************************

	Module::Module( ast::type::TypesCache & cache
		, spv::MemoryModel memoryModel
		, spv::ExecutionModel executionModel )
		: variables{ &globalDeclarations }
		, memoryModel{ makeInstruction< MemoryModelInstruction >( spv::Id( spv::AddressingModelLogical ), spv::Id( memoryModel ) ) }
		, m_cache{ &cache }
		, m_model{ executionModel }
	{
		header.push_back( spv::MagicNumber );
		header.push_back( spv::Version );
		header.push_back( 0x00100001 );
		header.push_back( 1u ); // Bound IDs.
		header.push_back( 0u ); // Schema.
		m_currentId = &header[3];
		auto id = getIntermediateResult();
		extensions.push_back( makeInstruction< ExtInstImportInstruction >( id
			, "GLSL.std.450" ) );
		debug.push_back( makeInstruction< SourceInstruction >( spv::Id( spv::SourceLanguageGLSL ), 450u ) );

		switch ( m_model )
		{
		case spv::ExecutionModelVertex:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			break;
		case spv::ExecutionModelTessellationControl:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			break;
		case spv::ExecutionModelTessellationEvaluation:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			break;
		case spv::ExecutionModelGeometry:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			break;
		case spv::ExecutionModelFragment:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			break;
		case spv::ExecutionModelGLCompute:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			break;
		case spv::ExecutionModelKernel:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityKernel ) ) );
			break;
		default:
			assert( false && "Unsupported ExecutionModel" );
			break;
		}
	}

	Module::Module( Header const & header
		, InstructionList && instructions )
		: variables{ &globalDeclarations }
	{
		this->header.push_back( header.magic );
		this->header.push_back( header.version );
		this->header.push_back( header.builder );
		this->header.push_back( header.boundIds );
		this->header.push_back( header.schema );
		auto it = instructions.begin();

		while ( it != instructions.end() )
		{
			InstructionList * list{ nullptr };

			switch ( spv::Op( ( *it )->op.opCode ) )
			{
			case spv::Op::OpSource:
			case spv::Op::OpName:
			case spv::Op::OpMemberName:
				list = &debug;
				break;
			case spv::Op::OpExtInstImport:
			case spv::Op::OpExtension:
				list = &extensions;
				break;
			case spv::Op::OpCapability:
				list = &capabilities;
				break;
			case spv::Op::OpExecutionMode:
				list = &executionModes;
				break;
			case spv::Op::OpDecorate:
			case spv::Op::OpMemberDecorate:
				list = &decorations;
				break;
			case spv::Op::OpTypeVoid:
			case spv::Op::OpTypeBool:
			case spv::Op::OpTypeInt:
			case spv::Op::OpTypeFloat:
			case spv::Op::OpTypeVector:
			case spv::Op::OpTypeMatrix:
			case spv::Op::OpTypeImage:
			case spv::Op::OpTypeSampler:
			case spv::Op::OpTypeSampledImage:
			case spv::Op::OpTypeArray:
			case spv::Op::OpTypeRuntimeArray:
			case spv::Op::OpTypeStruct:
			case spv::Op::OpTypeOpaque:
			case spv::Op::OpTypePointer:
			case spv::Op::OpTypeFunction:
			case spv::Op::OpTypeEvent:
			case spv::Op::OpTypeDeviceEvent:
			case spv::Op::OpTypeReserveId:
			case spv::Op::OpTypeQueue:
			case spv::Op::OpTypePipe:
			case spv::Op::OpTypeForwardPointer:
			case spv::Op::OpVariable:
			case spv::Op::OpConstant:
			case spv::Op::OpConstantComposite:
			case spv::Op::OpConstantFalse:
			case spv::Op::OpConstantTrue:
			case spv::Op::OpSpecConstant:
			case spv::Op::OpSpecConstantComposite:
			case spv::Op::OpSpecConstantFalse:
			case spv::Op::OpSpecConstantTrue:
				list = &globalDeclarations;
				break;
			case spv::Op::OpFunction:
				functions.emplace_back( Function::deserialize( it, instructions.end() ) );
				break;
			case spv::Op::OpMemoryModel:
				memoryModel = std::move( *it );
				++it;
				break;
			case spv::Op::OpEntryPoint:
				entryPoint = std::move( *it );
				++it;
				break;
			}

			if ( list )
			{
				list->emplace_back( std::move( *it ) );
				++it;
			}
		}
	}

	Module Module::deserialize( UInt32List const & spirv )
	{
		auto it = spirv.cbegin();
		auto popValue = [&it]( uint32_t & value )
		{
			value = *it;
			++it;
		};
		auto popInstruction = [&it]()
		{
			return spirv::Instruction::deserialize( it );
		};
		Header header{};
		popValue( header.magic );
		popValue( header.version );
		popValue( header.builder );
		popValue( header.boundIds );
		popValue( header.schema );
		assert( header.magic = spv::MagicNumber );
		spirv::InstructionList instructions;

		while ( it != spirv.end() )
		{
			instructions.emplace_back( popInstruction() );
		}

		return Module{ header, std::move( instructions ) };
	}

	spv::Id Module::registerType( ast::type::TypePtr type )
	{
		return registerType( type
			, ast::type::NotMember
			, 0u
			, 0u );
	}

	spv::Id Module::registerPointerType( spv::Id type, spv::StorageClass storage )
	{
		uint64_t key = ( uint64_t( type ) << 32 ) | uint64_t( storage );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			spv::Id id{ getNextId() };
			it = m_registeredPointerTypes.emplace( key, id ).first;
			globalDeclarations.push_back( makeInstruction< PointerTypeInstruction >( id
				, spv::Id( storage ), type ) );
		}

		return it->second;
	}

	void Module::decorate( spv::Id id, spv::Decoration decoration )
	{
		decorate( id, IdList{ spv::Id( decoration ) } );
	}

	void Module::decorate( spv::Id id
		, IdList const & decoration )
	{
		IdList operands;
		operands.push_back( id );
		operands.insert( operands.end(), decoration.begin(), decoration.end() );
		decorations.push_back( makeInstruction< DecorateInstruction >( operands ) );
	}

	void Module::decorateMember( spv::Id id
		, uint32_t index
		, spv::Decoration decoration )
	{
		decorateMember( id, index, IdList{ spv::Id( decoration ) } );
	}

	void Module::decorateMember( spv::Id id
		, uint32_t index
		, IdList const & decoration )
	{
		IdList operands;
		operands.push_back( id );
		operands.push_back( index );
		operands.insert( operands.end(), decoration.begin(), decoration.end() );
		decorations.push_back( makeInstruction< MemberDecorateInstruction >( operands ) );
	}

	spv::Id Module::loadVariable( spv::Id variable
		, ast::type::TypePtr type
		, Block & currentBlock )
	{
		auto result = getIntermediateResult();
		currentBlock.instructions.push_back( makeInstruction< LoadInstruction >( registerType( type )
			, result
			, variable ) );
		lnkIntermediateResult( result, variable );
		return result;
	}

	void Module::bindVariable( spv::Id varId
		, uint32_t bindingPoint
		, uint32_t descriptorSet )
	{
		decorate( varId, { spv::Id( spv::DecorationBinding ), bindingPoint } );
		decorate( varId, { spv::Id( spv::DecorationDescriptorSet ), descriptorSet } );
	}

	void Module::bindBufferVariable( std::string const & name
		, uint32_t bindingPoint
		, uint32_t descriptorSet
		, spv::Decoration structDecoration )
	{
		auto varIt = m_registeredVariables.find( name );

		if ( varIt != m_registeredVariables.end() )
		{
			auto varId = varIt->second;
			decorate( varId, { spv::Id( spv::DecorationBinding ), bindingPoint } );
			decorate( varId, { spv::Id( spv::DecorationDescriptorSet ), descriptorSet } );

			auto typeIt = m_registeredVariablesTypes.find( varId );

			if ( typeIt != m_registeredVariablesTypes.end() )
			{
				auto typeId = typeIt->second;
				decorate( typeId, structDecoration );
			}
		}
	}

	VariableInfo & Module::registerVariable( std::string const & name
		, spv::StorageClass storage
		, ast::type::TypePtr type
		, VariableInfo & info )
	{
		auto it = m_registeredVariables.find( name );

		if ( it == m_registeredVariables.end() )
		{
			spv::Id id{ getNextId() };
			it = m_registeredVariables.emplace( name, id ).first;

			if ( type->getKind() != ast::type::Kind::eStruct
				|| std::static_pointer_cast< ast::type::Struct >( type )->getName() != name )
			{
				debug.push_back( makeInstruction< NameInstruction >( id, name ) );
			}
			else if ( type->getKind() == ast::type::Kind::eStruct
				|| std::static_pointer_cast< ast::type::Struct >( type )->getName() == name )
			{
				debug.push_back( makeInstruction< NameInstruction >( id, name + "Inst" ) );
			}

			auto builtin = getBuiltin( name );

			if ( builtin != spv::BuiltIn( -1 ) )
			{
				decorate( id, { spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) } );
			}

			auto rawTypeId = registerType( type );
			auto varTypeId = registerPointerType( rawTypeId, storage );

			if ( storage == spv::StorageClassFunction
				&& m_currentFunction )
			{
				m_currentFunction->variables.push_back( makeInstruction< VariableInstruction >( varTypeId
					, id
					, spv::Id( storage ) ) );
			}
			else
			{
				globalDeclarations.push_back( makeInstruction< VariableInstruction >( varTypeId
					, id
					, spv::Id( storage ) ) );
			}

			m_registeredVariablesTypes.emplace( id, rawTypeId );
		}

		info.id = it->second;
		return info;
	}

	spv::Id Module::registerSpecConstant( std::string name
		, uint32_t location
		, ast::type::TypePtr type
		, ast::expr::Literal const & value )
	{
		auto it = m_registeredVariables.find( name );

		if ( it == m_registeredVariables.end() )
		{
			spv::Id id{ getNextId() };
			it = m_registeredVariables.emplace( name, id ).first;
			auto rawTypeId = registerType( type );
			IdList operands;
			debug.push_back( makeInstruction< NameInstruction >( id, name ) );

			if ( value.getLiteralType() == ast::expr::LiteralType::eBool )
			{
				if ( value.getValue< ast::expr::LiteralType::eBool >() )
				{
					globalDeclarations.emplace_back( makeInstruction< SpecConstantTrueInstruction >( rawTypeId, id ) );
				}
				else
				{
					globalDeclarations.emplace_back( makeInstruction< SpecConstantFalseInstruction >( rawTypeId, id ) );
				}
			}
			else
			{
				switch ( value.getLiteralType() )
				{
				case ast::expr::LiteralType::eInt:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt >() ) );
					break;
				case ast::expr::LiteralType::eUInt:
					operands.emplace_back( value.getValue< ast::expr::LiteralType::eUInt >() );
					break;
				case ast::expr::LiteralType::eFloat:
				{
					operands.resize( sizeof( float ) / sizeof( uint32_t ) );
					auto dst = reinterpret_cast< float * >( operands.data() );
					*dst = value.getValue< ast::expr::LiteralType::eFloat >();
				}
				break;
				case ast::expr::LiteralType::eDouble:
				{
					operands.resize( sizeof( double ) / sizeof( uint32_t ) );
					auto dst = reinterpret_cast< double * >( operands.data() );
					*dst = value.getValue< ast::expr::LiteralType::eDouble >();
				}
				break;
				}

				globalDeclarations.emplace_back( makeInstruction< SpecConstantInstruction >( rawTypeId
					, id
					, operands ) );
			}

			decorate( id, { spv::Id( spv::DecorationSpecId ), spv::Id( location ) } );
			m_registeredVariablesTypes.emplace( id, rawTypeId );
			m_registeredConstants.emplace( id, value.getType() );
		}

		return it->second;
	}

	spv::Id Module::registerParameter( ast::type::TypePtr type )
	{
		auto typeId = registerType( type );
		auto paramId = getNextId();
		return paramId;
	}

	spv::Id Module::registerMemberVariableIndex( ast::type::TypePtr type )
	{
		assert( type->isMember() );
		return registerLiteral( type->getIndex() );
	}

	spv::Id Module::registerMemberVariable( spv::Id outer
		, std::string name
		, ast::type::TypePtr type )
	{
		auto it = std::find_if( m_registeredVariables.begin()
			, m_registeredVariables.end()
			, [outer]( std::map< std::string, spv::Id >::value_type const & pair )
			{
				return pair.second == outer;
			} );
		assert( it != m_registeredVariables.end() );
		assert( type->isMember() );
		auto fullName = it->first + "::" + name;
		auto outerId = it->second;
		it = m_registeredVariables.find( fullName );

		if ( it == m_registeredVariables.end() )
		{
			spv::Id id{ getNextId() };
			m_registeredMemberVariables.insert( { fullName, { outer, id } } );
			it = m_registeredVariables.emplace( fullName, id ).first;
			registerLiteral( type->getIndex() );
		}

		return it->second;
	}

	ast::type::Kind Module::getLiteralType( spv::Id litId )const
	{
		auto it = m_registeredConstants.find( litId );
		assert( it != m_registeredConstants.end() );
		return it->second->getKind();
	}

	spv::Id Module::getOuterVariable( spv::Id mbrId )const
	{
		auto itInner = std::find_if( m_registeredMemberVariables.begin()
			, m_registeredMemberVariables.end()
			, [mbrId]( std::map< std::string, std::pair< spv::Id, spv::Id > >::value_type const & pair )
			{
				return pair.second.second == mbrId;
			} );
		assert( itInner != m_registeredMemberVariables.end() );
		
		auto result = itInner->second.first;
		auto itOuter = m_registeredMemberVariables.end();

		while ( ( itOuter = std::find_if( m_registeredMemberVariables.begin()
				, m_registeredMemberVariables.end()
				, [result]( std::map< std::string, std::pair< spv::Id, spv::Id > >::value_type const & pair )
				{
					return pair.second.second == result;
				} ) ) != m_registeredMemberVariables.end() )
		{
			result = itOuter->second.first;
		}

		auto itOutermost = std::find_if( m_registeredVariables.begin()
			, m_registeredVariables.end()
			, [result]( std::map< std::string, spv::Id >::value_type const & pair )
			{
					return pair.second == result;
			} );
		assert( itOutermost != m_registeredVariables.end() );
		result = itOutermost->second;
		return result;
	}

	spv::Id Module::registerLiteral( bool value )
	{
		auto it = m_registeredBoolConstants.find( value );

		if ( it == m_registeredBoolConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getBool() );

			if ( value )
			{
				globalDeclarations.push_back( makeInstruction< ConstantTrueInstruction >( type, result ) );
			}
			else
			{
				globalDeclarations.push_back( makeInstruction< ConstantFalseInstruction >( type, result ) );
			}

			it = m_registeredBoolConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getBool() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( int32_t value )
	{
		auto it = m_registeredIntConstants.find( value );

		if ( it == m_registeredIntConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getInt() );
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, IdList{ uint32_t( value ) } ) );
			it = m_registeredIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getInt() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( uint32_t value )
	{
		auto it = m_registeredUIntConstants.find( value );

		if ( it == m_registeredUIntConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getUInt() );
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, IdList{ value } ) );
			it = m_registeredUIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getUInt() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( float value )
	{
		auto it = m_registeredFloatConstants.find( value );

		if ( it == m_registeredFloatConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getFloat() );
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, IdList{ *reinterpret_cast< uint32_t * >( &value ) } ) );
			it = m_registeredFloatConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getFloat() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( double value )
	{
		auto it = m_registeredDoubleConstants.find( value );

		if ( it == m_registeredDoubleConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getDouble() );
			IdList list;
			list.resize( 2u );
			auto dst = reinterpret_cast< double * >( list.data() );
			*dst = value;
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, list ) );
			it = m_registeredDoubleConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getDouble() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( IdList const & initialisers
		, ast::type::TypePtr type )
	{
		auto typeId = registerType( type );
		auto it = std::find_if( m_registeredCompositeConstants.begin()
			, m_registeredCompositeConstants.end()
			, [initialisers]( std::pair< IdList, spv::Id > const & lookup )
			{
				return lookup.first == initialisers;
			} );

		if ( it == m_registeredCompositeConstants.end() )
		{
			spv::Id result{ getNextId() };
			globalDeclarations.push_back( makeInstruction< ConstantCompositeInstruction >( typeId
				, result
				, initialisers ) );
			m_registeredCompositeConstants.emplace_back( initialisers, result );
			it = m_registeredCompositeConstants.begin() + m_registeredCompositeConstants.size() - 1u;
			m_registeredConstants.emplace( result, type );
		}

		return it->second;
	}

	void Module::registerExtension( std::string const & name )
	{
		extensions.push_back( makeInstruction< ExtensionInstruction >( name ) );
	}

	void Module::registerEntryPoint( spv::Id functionId
		, std::string const & name
		, IdList const & inputs
		, IdList const & outputs )
	{
		IdList operands;
		operands.insert( operands.end(), inputs.begin(), inputs.end() );
		operands.insert( operands.end(), outputs.begin(), outputs.end() );
		entryPoint = makeInstruction< EntryPointInstruction >( spv::Id( m_model )
			, functionId
			, operands
			, name );

		switch ( m_model )
		{
		case spv::ExecutionModelVertex:
			break;
		case spv::ExecutionModelTessellationControl:
			break;
		case spv::ExecutionModelTessellationEvaluation:
			break;
		case spv::ExecutionModelGeometry:
			break;
		case spv::ExecutionModelFragment:
			registerExecutionMode( spv::ExecutionModeOriginLowerLeft );
			break;
		case spv::ExecutionModelGLCompute:
			break;
		case spv::ExecutionModelKernel:
			break;
		case spv::ExecutionModelMax:
			break;
		default:
			break;
		}

		for ( auto & executionMode : m_pendingExecutionModes )
		{
			executionModes.emplace_back( std::move( executionMode ) );
			executionModes.back()->operands[0] = functionId;
		}

		m_pendingExecutionModes.clear();
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode )
	{
		registerExecutionMode( mode, {} );
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode, IdList const & operands )
	{
		if ( !entryPoint || entryPoint->operands.empty() )
		{
			IdList ops;
			ops.push_back( spv::Id( 0u ) );
			ops.push_back( spv::Id( mode ) );
			ops.insert( ops.end(), operands.begin(), operands.end() );
			m_pendingExecutionModes.push_back( makeInstruction< ExecutionModeInstruction >( ops ) );
		}
		else
		{
			IdList ops;
			ops.push_back( entryPoint->resultId.value() );
			ops.push_back( spv::Id( mode ) );
			ops.insert( ops.end(), operands.begin(), operands.end() );
			executionModes.push_back( makeInstruction< ExecutionModeInstruction >( ops ) );
		}
	}

	spv::Id Module::getIntermediateResult()
	{
		spv::Id result{};

		if ( m_freeIntermediates.empty() )
		{
			result = getNextId();
			m_intermediates.insert( result );
			m_freeIntermediates.insert( result );
		}

		result = *m_freeIntermediates.begin();
		m_freeIntermediates.erase( m_freeIntermediates.begin() );
		return result;
	}

	void Module::lnkIntermediateResult( spv::Id intermediate, spv::Id var )
	{
		if ( m_intermediates.end() != m_intermediates.find( intermediate ) )
		{
			m_busyIntermediates.emplace( intermediate, var );
		}
	}

	void Module::putIntermediateResult( spv::Id id )
	{
		//if ( m_intermediates.end() != m_intermediates.find( id ) )
		//{
		//	m_freeIntermediates.insert( id );
		//	auto it = m_busyIntermediates.begin();

		//	while ( it != m_busyIntermediates.end() )
		//	{
		//		if ( it->first == id
		//			|| it->second == id )
		//		{
		//			it = m_busyIntermediates.erase( it );
		//		}
		//		else
		//		{
		//			++it;
		//		}
		//	}
		//}
	}

	spv::Id Module::getNonIntermediate( spv::Id id )
	{
		while ( m_intermediates.end() != m_intermediates.find( id ) )
		{
			id = m_busyIntermediates.find( id )->second;
		}

		return id;
	}

	Function * Module::beginFunction( std::string const & name
		, spv::Id retType
		, ast::var::VariableList const & params )
	{
		IdList funcTypes;
		IdList funcParams;
		funcTypes.push_back( retType );

		for ( auto & param : params )
		{
			funcTypes.push_back( registerType( param->getType() ) );
			spv::Id paramId{ getNextId() };
			funcParams.push_back( paramId );
			debug.push_back( makeInstruction< NameInstruction >( paramId, param->getName() ) );

			if ( isSampledImageType( param->getType()->getKind() )
				|| isImageType( param->getType()->getKind() ) )
			{
				funcTypes.back() = registerPointerType( funcTypes.back(), spv::StorageClassFunction );
			}

			m_registeredVariables.emplace( param->getName(), funcParams.back() );
			m_registeredVariablesTypes.emplace( funcParams.back(), funcTypes.back() );
		}

		spv::Id funcType{ getNextId() };
		globalDeclarations.push_back( makeInstruction< FunctionTypeInstruction >( funcType
			, funcTypes ) );
		spv::Id result{ getNextId() };
		InstructionList declaration;
		declaration.emplace_back( makeInstruction< FunctionInstruction >( retType
			, result
			, spv::Id( spv::FunctionControlMaskNone )
			, funcType ) );
		auto itType = funcTypes.begin() + 1u;
		auto itParam = funcParams.begin();

		for ( auto & param : params )
		{
			declaration.emplace_back( makeInstruction< FunctionParameterInstruction >( *itType
				, *itParam ) );
			++itType;
			++itParam;
		}

		m_registeredVariables.emplace( name, result );
		m_registeredVariablesTypes.emplace( result, funcType );
		functions.emplace_back( Function
			{
				std::move( declaration ),
				{},
				{},
			} );
		debug.push_back( makeInstruction< NameInstruction >( result, name ) );
		m_currentFunction = &functions.back();
		variables = &m_currentFunction->variables;

		return m_currentFunction;
	}

	Block Module::newBlock()
	{
		Block result
		{
			getNextId()
		};
		result.instructions.push_back( makeInstruction< LabelInstruction >( result.label ) );
		return result;
	}

	void Module::endFunction()
	{
		if ( m_currentFunction
			&& !m_currentFunction->cfg.blocks.empty()
			&& !m_currentFunction->variables.empty() )
		{
			auto & instructions = m_currentFunction->cfg.blocks.begin()->instructions;
			auto variables = std::move( m_currentFunction->variables );
			std::reverse( variables.begin(), variables.end() );

			for ( auto & variable : variables )
			{
				instructions.emplace( instructions.begin() + 1u
					, std::move( variable ) );
			}

			m_currentFunction->variables.clear();
		}

		variables = &globalDeclarations;
		m_currentFunction = nullptr;
	}

	spv::Id Module::doRegisterNonArrayType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		spv::Id result;

		auto unqualifiedType = getUnqualifiedType( type );
		auto it = m_registeredTypes.find( unqualifiedType );

		if ( it == m_registeredTypes.end() )
		{
			result = registerBaseType( unqualifiedType
				, mbrIndex
				, parentId
				, 0u );
			m_registeredTypes.emplace( unqualifiedType, result );
		}
		else
		{
			result = it->second;
		}

		return result;
	}

	spv::Id Module::registerType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId
		, uint32_t arrayStride )
	{
		spv::Id result;

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			auto arrayedType = std::static_pointer_cast< ast::type::Array >( type )->getType();
			auto arraySize = getArraySize( type );
			auto elementTypeId = registerType( arrayedType
				, mbrIndex
				, parentId
				, arrayStride );

			auto unqualifiedType = getUnqualifiedType( type );
			auto it = m_registeredTypes.find( unqualifiedType );

			if ( it == m_registeredTypes.end() )
			{
				if ( arraySize != ast::type::UnknownArraySize )
				{
					auto lengthId = registerLiteral( arraySize );
					result = getNextId();
					globalDeclarations.push_back( makeInstruction< ArrayTypeInstruction >( result
						, elementTypeId
						, lengthId ) );
				}
				else
				{
					result = getNextId();
					globalDeclarations.push_back( makeInstruction< RuntimeArrayTypeInstruction >( result
						, elementTypeId ) );
				}

				writeArrayStride( *this
					, unqualifiedType
					, result
					, arrayStride );
				m_registeredTypes.emplace( unqualifiedType, result );
			}
			else
			{
				result = it->second;
			}
		}
		else
		{
			result = doRegisterNonArrayType( type
				, mbrIndex
				, parentId );
		}

		return result;
	}

	spv::Id Module::registerBaseType( ast::type::Kind kind
		, uint32_t mbrIndex
		, spv::Id parentId
		, uint32_t arrayStride )
	{
		assert( kind != ast::type::Kind::eStruct );
		assert( kind != ast::type::Kind::eImage );
		assert( kind != ast::type::Kind::eSampledImage );

		spv::Id result{};
		auto type = m_cache->makeType( kind );

		if ( isVectorType( kind )
			|| isMatrixType( kind ) )
		{
			auto componentType = registerType( m_cache->makeType( getComponentType( kind ) ) );
			result = getNextId();

			if ( isMatrixType( kind ) )
			{
				globalDeclarations.push_back( makeInstruction< MatrixTypeInstruction >( result
					, componentType
					, getComponentCount( kind ) ) );

				if ( mbrIndex != ast::type::NotMember )
				{
					decorateMember( parentId
						, mbrIndex
						, spv::DecorationColMajor );
				}
				else
				{
					decorate( result
						, spv::DecorationColMajor );
				}
			}
			else
			{
				globalDeclarations.push_back( makeInstruction< VectorTypeInstruction >( result
					, componentType
					, getComponentCount( kind ) ) );
			}
		}
		else
		{
			result = getNextId();
			globalDeclarations.push_back( makeBaseTypeInstruction( kind, result ) );
		}

		return result;
	}

	spv::Id Module::registerBaseType( ast::type::SampledImagePtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		auto imgTypeId = registerType( std::static_pointer_cast< ast::type::SampledImage >( type )->getImageType() );
		auto result = getNextId();
		globalDeclarations.push_back( makeInstruction< SampledImageTypeInstruction >( result
			, imgTypeId ) );
		return result;
	}

	spv::Id Module::registerBaseType( ast::type::ImagePtr type
		, uint32_t mbrIndex
		, spv::Id parent )
	{
		// The Sampled Type.
		auto sampledTypeId = registerType( m_cache->makeType( type->getConfig().sampledType ) );
		// The Image Type.
		auto result = getNextId();
		globalDeclarations.push_back( makeImageTypeInstruction( type->getConfig(), result, sampledTypeId ) );
		return result;
	}

	spv::Id Module::registerBaseType( ast::type::StructPtr type
		, uint32_t
		, spv::Id )
	{
		spv::Id result{ getNextId() };
		IdList subTypes;

		for ( auto & member : *type )
		{
			subTypes.push_back( registerType( member.type
				, member.type->getIndex()
				, result
				, member.arrayStride ) );
		}

		globalDeclarations.push_back( makeInstruction< StructTypeInstruction >( result, subTypes ) );
		debug.push_back( makeInstruction< NameInstruction >( result, type->getName() ) );

		for ( auto & member : *type )
		{
			auto index = member.type->getIndex();
			debug.push_back( makeInstruction< MemberNameInstruction >( result, index, member.name ) );
			decorateMember( result
				, index
				, makeOperands( uint32_t( spv::DecorationOffset ), member.offset ) );

			if ( isMatrixType( member.type->getKind() ) )
			{
				auto colType = getComponentType( member.type->getKind() );
				auto size = getSize( *member.type->getCache().makeType( colType )
					, ast::type::MemoryLayout::eStd430 );
				decorateMember( result
					, index
					, makeOperands( uint32_t( spv::DecorationMatrixStride ), size ) );
			}
		}

		return result;
	}

	spv::Id Module::registerBaseType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId
		, uint32_t arrayStride )
	{
		spv::Id result{};

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		auto kind = type->getKind();

		if ( kind == ast::type::Kind::eSampledImage )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::SampledImage >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eImage )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::Image >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eStruct )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::Struct >( type )
				, mbrIndex
				, parentId );
		}
		else
		{
			result = registerBaseType( kind
				, mbrIndex
				, parentId
				, arrayStride );
		}

		return result;
	}

	spv::Id Module::getNextId()
	{
		auto result = *m_currentId;
		++*m_currentId;
		return result;
	}

	//*************************************************************************
}
