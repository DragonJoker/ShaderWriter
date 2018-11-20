/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvModule.hpp"

#include "ShaderWriter/SPIRV/SpirvHelpers.hpp"

#include <ASTGenerator/Type/TypeImage.hpp>
#include <ASTGenerator/Type/TypeSampledImage.hpp>

#include <algorithm>

namespace sdw::spirv
{
	//*************************************************************************

	namespace
	{
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

		spv::BuiltIn getBuiltin( std::string const & name )
		{
			auto result = spv::BuiltIn( -1 );

			if ( name == "gl_Position" )
			{
				result = spv::BuiltIn::Position;
			}
			else if ( name == "gl_PointSize" )
			{
				result = spv::BuiltIn::PointSize;
			}
			else if ( name == "gl_ClipDistance" )
			{
				result = spv::BuiltIn::ClipDistance;
			}
			else if ( name == "gl_CullDistance" )
			{
				result = spv::BuiltIn::CullDistance;
			}
			else if ( name == "gl_VertexID" )
			{
				result = spv::BuiltIn::VertexId;
			}
			else if ( name == "gl_InstanceID" )
			{
				result = spv::BuiltIn::InstanceId;
			}
			else if ( name == "gl_PrimitiveID" )
			{
				result = spv::BuiltIn::PrimitiveId;
			}
			else if ( name == "gl_InvocationID" )
			{
				result = spv::BuiltIn::InvocationId;
			}
			else if ( name == "gl_Layer" )
			{
				result = spv::BuiltIn::Layer;
			}
			else if ( name == "gl_ViewportIndex" )
			{
				result = spv::BuiltIn::ViewportIndex;
			}
			else if ( name == "gl_TessLevelOuter" )
			{
				result = spv::BuiltIn::TessLevelOuter;
			}
			else if ( name == "gl_TessLevelInner" )
			{
				result = spv::BuiltIn::TessLevelInner;
			}
			else if ( name == "gl_TessCoord" )
			{
				result = spv::BuiltIn::TessCoord;
			}
			else if ( name == "gl_PatchVertices" )
			{
				result = spv::BuiltIn::PatchVertices;
			}
			else if ( name == "gl_FragCoord" )
			{
				result = spv::BuiltIn::FragCoord;
			}
			else if ( name == "gl_PointCoord" )
			{
				result = spv::BuiltIn::PointCoord;
			}
			else if ( name == "gl_FrontFacing" )
			{
				result = spv::BuiltIn::FrontFacing;
			}
			else if ( name == "gl_SampleID" )
			{
				result = spv::BuiltIn::SampleId;
			}
			else if ( name == "gl_SamplePosition" )
			{
				result = spv::BuiltIn::SamplePosition;
			}
			else if ( name == "gl_SampleMask" )
			{
				result = spv::BuiltIn::SampleMask;
			}
			else if ( name == "gl_FragDepth" )
			{
				result = spv::BuiltIn::FragDepth;
			}
			else if ( name == "gl_HelperInvocation" )
			{
				result = spv::BuiltIn::HelperInvocation;
			}
			else if ( name == "gl_NumWorkgroups" )
			{
				result = spv::BuiltIn::NumWorkgroups;
			}
			else if ( name == "gl_WorkgroupSize" )
			{
				result = spv::BuiltIn::WorkgroupSize;
			}
			else if ( name == "gl_WorkgroupID" )
			{
				result = spv::BuiltIn::WorkgroupId;
			}
			else if ( name == "gl_LocalInvocationID" )
			{
				result = spv::BuiltIn::LocalInvocationId;
			}
			else if ( name == "gl_GlobalInvocationID" )
			{
				result = spv::BuiltIn::GlobalInvocationId;
			}
			else if ( name == "gl_LocalInvocationIndex" )
			{
				result = spv::BuiltIn::LocalInvocationIndex;
			}
			else if ( name == "gl_WorkDim" )
			{
				result = spv::BuiltIn::WorkDim;
			}
			else if ( name == "gl_GlobalSize" )
			{
				result = spv::BuiltIn::GlobalSize;
			}
			else if ( name == "gl_EnqueuedWorkgroupSize" )
			{
				result = spv::BuiltIn::EnqueuedWorkgroupSize;
			}
			else if ( name == "gl_GlobalOffset" )
			{
				result = spv::BuiltIn::GlobalOffset;
			}
			else if ( name == "gl_GlobalLinearID" )
			{
				result = spv::BuiltIn::GlobalLinearId;
			}
			else if ( name == "gl_SubgroupSize" )
			{
				result = spv::BuiltIn::SubgroupSize;
			}
			else if ( name == "gl_SubgroupMaxSize" )
			{
				result = spv::BuiltIn::SubgroupMaxSize;
			}
			else if ( name == "gl_NumSubgroups" )
			{
				result = spv::BuiltIn::NumSubgroups;
			}
			else if ( name == "gl_NumEnqueuedSubgroups" )
			{
				result = spv::BuiltIn::NumEnqueuedSubgroups;
			}
			else if ( name == "gl_SubgroupID" )
			{
				result = spv::BuiltIn::SubgroupId;
			}
			else if ( name == "gl_SubgroupLocalInvocationID" )
			{
				result = spv::BuiltIn::SubgroupLocalInvocationId;
			}
			else if ( name == "gl_VertexIndex" )
			{
				result = spv::BuiltIn::VertexIndex;
			}
			else if ( name == "gl_InstanceIndex" )
			{
				result = spv::BuiltIn::InstanceIndex;
			}
			else if ( name == "gl_SubgroupEqMaskKHR" )
			{
				result = spv::BuiltIn::SubgroupEqMaskKHR;
			}
			else if ( name == "gl_SubgroupGeMaskKHR" )
			{
				result = spv::BuiltIn::SubgroupGeMaskKHR;
			}
			else if ( name == "gl_SubgroupGtMaskKHR" )
			{
				result = spv::BuiltIn::SubgroupGtMaskKHR;
			}
			else if ( name == "gl_SubgroupLeMaskKHR" )
			{
				result = spv::BuiltIn::SubgroupLeMaskKHR;
			}
			else if ( name == "gl_SubgroupLtMaskKHR" )
			{
				result = spv::BuiltIn::SubgroupLtMaskKHR;
			}
			else if ( name == "gl_BaseVertex" )
			{
				result = spv::BuiltIn::BaseVertex;
			}
			else if ( name == "gl_BaseInstance" )
			{
				result = spv::BuiltIn::BaseInstance;
			}
			else if ( name == "gl_DrawIndex" )
			{
				result = spv::BuiltIn::DrawIndex;
			}
			else if ( name == "gl_DeviceIndex" )
			{
				result = spv::BuiltIn::DeviceIndex;
			}
			else if ( name == "gl_ViewIndex" )
			{
				result = spv::BuiltIn::ViewIndex;
			}
			else if ( name == "gl_BaryCoordNoPerspAMD" )
			{
				result = spv::BuiltIn::BaryCoordNoPerspAMD;
			}
			else if ( name == "gl_BaryCoordNoPerspCentroidAMD" )
			{
				result = spv::BuiltIn::BaryCoordNoPerspCentroidAMD;
			}
			else if ( name == "gl_BaryCoordNoPerspSampleAMD" )
			{
				result = spv::BuiltIn::BaryCoordNoPerspSampleAMD;
			}
			else if ( name == "gl_BaryCoordSmoothAMD" )
			{
				result = spv::BuiltIn::BaryCoordSmoothAMD;
			}
			else if ( name == "gl_BaryCoordSmoothCentroidAMD" )
			{
				result = spv::BuiltIn::BaryCoordSmoothCentroidAMD;
			}
			else if ( name == "gl_BaryCoordSmoothSampleAMD" )
			{
				result = spv::BuiltIn::BaryCoordSmoothSampleAMD;
			}
			else if ( name == "gl_BaryCoordPullModelAMD" )
			{
				result = spv::BuiltIn::BaryCoordPullModelAMD;
			}
			else if ( name == "gl_FragStencilRefEXT" )
			{
				result = spv::BuiltIn::FragStencilRefEXT;
			}
			else if ( name == "gl_ViewportMaskNV" )
			{
				result = spv::BuiltIn::ViewportMaskNV;
			}
			else if ( name == "gl_SecondaryPositionNV" )
			{
				result = spv::BuiltIn::SecondaryPositionNV;
			}
			else if ( name == "gl_SecondaryViewportMaskNV" )
			{
				result = spv::BuiltIn::SecondaryViewportMaskNV;
			}
			else if ( name == "gl_PositionPerViewNV" )
			{
				result = spv::BuiltIn::PositionPerViewNV;
			}
			else if ( name == "gl_ViewportMaskPerViewNV" )
			{
				result = spv::BuiltIn::ViewportMaskPerViewNV;
			}

			return result;
		}

		type::Kind getComponentType( type::ImageFormat format )
		{
			type::Kind result;

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
				assert( false && "Unsupported type::ImageFormat." );
				return ast::type::Kind::eFloat;
			}

			return result;
		}

		type::TypePtr getUnqualifiedType( type::Type const & qualified )
		{
			type::TypePtr result;

			if ( qualified.getKind() == type::Kind::eStruct )
			{
				auto resultStruct = static_cast< type::Struct const & >( qualified ).getUnqualifiedType();
				static std::vector< type::StructPtr > cache;
				auto it = std::find_if( cache.begin()
					, cache.end()
					, [&resultStruct]( type::StructPtr lookup )
					{
						return *resultStruct == *lookup;
					} );

				if ( it == cache.end() )
				{
					cache.push_back( resultStruct );
					it = cache.begin() + cache.size() - 1u;
				}

				result = *it;
			}
			else if ( qualified.isMember() )
			{
				auto unqualifiedStruct = std::static_pointer_cast< type::Struct >( getUnqualifiedType( *qualified.getParent() ) );
				auto it = unqualifiedStruct->begin() + qualified.getIndex();
				result = it->type;
			}

			return result;
		}

		type::TypePtr getUnqualifiedType( type::TypePtr qualified )
		{
			auto result = qualified;

			if ( result->getKind() == type::Kind::eArray )
			{
				auto resultArray = std::static_pointer_cast< type::Array >( result );
				auto arrayedType = resultArray->getType();

				if ( arrayedType->getKind() != type::Kind::eImage
					&& arrayedType->getKind() != type::Kind::eSampledImage 
					&& arrayedType->getKind() != type::Kind::eSampler )
				{
					static std::vector< type::ArrayPtr > cache;
					auto it = std::find_if( cache.begin()
						, cache.end()
						, [&resultArray]( type::ArrayPtr lookup )
						{
							return *resultArray == *lookup;
						} );

					if ( it == cache.end() )
					{
						cache.push_back( resultArray );
						it = cache.begin() + cache.size() - 1u;
					}

					result = *it;
				}
				else
				{
					auto unqualifiedType = getUnqualifiedType( arrayedType );
					auto unqualifiedArray = type::makeArrayType( unqualifiedType, resultArray->getArraySize() );
					static std::vector< type::ArrayPtr > cache;
					auto it = std::find_if( cache.begin()
						, cache.end()
						, [&unqualifiedArray]( type::ArrayPtr lookup )
						{
							return unqualifiedArray->getArraySize() == lookup->getArraySize()
								&& unqualifiedArray->getType() == lookup->getType();
						} );

					if ( it == cache.end() )
					{
						cache.push_back( resultArray );
						it = cache.begin() + cache.size() - 1u;
					}

					result = *it;
				}
			}
			else if ( result->isMember()
				|| result->getKind() == type::Kind::eStruct )
			{
				result = getUnqualifiedType( *qualified );
			}
			else if ( result->getKind() == type::Kind::eImage )
			{
				auto image = std::static_pointer_cast< type::Image >( result );
				auto config = image->getConfig();
				auto hash = getHash( config );
				static std::map< size_t, type::ImagePtr > cache;
				auto it = cache.find( hash );

				if ( it == cache.end() )
				{
					it = cache.emplace( hash, std::move( image ) ).first;
				}

				result = it->second;
			}
			else if ( result->getKind() == type::Kind::eSampledImage )
			{
				auto sampledImage = std::static_pointer_cast< type::SampledImage >( result );
				auto config = sampledImage->getConfig();
				auto hash = getHash( config );
				static std::map< size_t, type::SampledImagePtr > cache;
				auto it = cache.find( hash );

				if ( it == cache.end() )
				{
					it = cache.emplace( hash, std::move( sampledImage ) ).first;
				}

				result = it->second;
			}

			return result;
		}

		type::MemoryLayout getMemoryLayout( type::Type const & type )
		{
			type::MemoryLayout result{ type::MemoryLayout::eStd140 };
			auto kind = getNonArrayKind( type );

			if ( kind == type::Kind::eStruct )
			{
				auto & structType = static_cast< type::Struct const & >( type );
				result = structType.getMemoryLayout();
			}
			else if ( type.isMember() )
			{
				result = getMemoryLayout( *type.getParent() );
			}

			return result;
		}

		void writeArrayStride( Module & module
			, type::TypePtr type
			, uint32_t typeId )
		{
			auto kind = getNonArrayKind( type );
			auto arraySize = getArraySize( type );
			auto layout = getMemoryLayout( *type );
			auto div = arraySize == type::UnknownArraySize
				? 1u
				: arraySize;
			assert( div != 0u );

			if ( kind != type::Kind::eImage
				&& kind != type::Kind::eSampledImage
				&& kind != type::Kind::eSampler )
			{
				module.decorate( typeId
					, IdList
					{
						uint32_t( spv::Decoration::ArrayStride ),
						getSize( type, layout ) / div
					} );
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

	Instruction::Instruction( spv::Op op
		, std::optional< spv::Id > resultType
		, std::optional< spv::Id > resultId
		, IdList operands
		, std::optional< std::string > name
		, std::optional< std::map< int64_t, spv::Id > > labels )
		: resultType{ resultType }
		, resultId{ resultId }
		, operands{ operands }
		, packedName{ std::nullopt }
		, name{ name }
		, labels{ labels }
	{
		if ( this->name.has_value() )
		{
			packedName = packString( this->name.value() );
		}

		this->op.op = op;
		this->op.opCount = uint16_t( 1u
			+ ( this->resultType.has_value() ? 1u : 0u )
			+ ( this->resultId.has_value() ? 1u : 0u )
			+ this->operands.size()
			+ ( this->packedName.has_value() ? this->packedName.value().size() : 0u ) );
	}

	//*************************************************************************

	Module::Module( spv::MemoryModel memoryModel
		, spv::ExecutionModel executionModel )
		: variables{ &globalDeclarations }
		, memoryModel{ makeInstruction( spv::Op::OpMemoryModel
			, IdList{ spv::Id( spv::AddressingModel::Logical ), spv::Id( memoryModel ) } ) }
		, m_model{ executionModel }
	{
		header.push_back( spv::MagicNumber );
		header.push_back( spv::Version );
		header.push_back( 0x00100001 );
		header.push_back( 0u ); // Bound IDs.
		header.push_back( 0u ); // Schema.
		m_currentId = &header[3];
		auto id = getIntermediateResult();
		extensions.push_back( makeName( spv::Op::OpExtInstImport
			, id
			, "GLSL.std.450" ) );
		debug.push_back( makeInstruction( spv::Op::OpSource
			, { spv::Id( spv::SourceLanguage::GLSL ), 450u } ) );

		switch ( m_model )
		{
		case spv::ExecutionModel::Vertex:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, IdList{ spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::TessellationControl:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, IdList{ spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::TessellationEvaluation:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, IdList{ spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::Geometry:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, IdList{ spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::Fragment:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, IdList{ spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::GLCompute:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, IdList{ spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::Kernel:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, IdList{ spv::Id( spv::Capability::Kernel ) } ) );
			break;
		default:
			assert( false && "Unsupported ExecutionModel" );
			break;
		}
	}

	spv::Id Module::registerType( type::TypePtr type )
	{
		return registerType( type
			, type::NotMember
			, 0u );
	}

	spv::Id Module::registerPointerType( spv::Id type, spv::StorageClass storage )
	{
		uint64_t key = ( uint64_t( type ) << 32 ) | uint64_t( storage );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			spv::Id id{ ++*m_currentId };
			it = m_registeredPointerTypes.emplace( key, id ).first;
			globalDeclarations.push_back( spirv::makeInstruction( spv::Op::OpTypePointer, id, IdList{ spv::Id( storage ), type } ) );
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
		decorations.push_back( makeInstruction( spv::Op::OpDecorate
			, operands ) );
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
		decorations.push_back( makeInstruction( spv::Op::OpMemberDecorate
			, operands ) );
	}

	spv::Id Module::loadVariable( spv::Id variable
		, type::TypePtr type
		, Block & currentBlock )
	{
		auto result = getIntermediateResult();
		currentBlock.instructions.push_back( makeLoad( result
			, registerType( type )
			, variable ) );
		lnkIntermediateResult( result, variable );
		return result;
	}

	void Module::bindVariable( spv::Id varId
		, uint32_t bindingPoint
		, uint32_t descriptorSet )
	{
		decorate( varId, { spv::Id( spv::Decoration::Binding ), bindingPoint } );
		decorate( varId, { spv::Id( spv::Decoration::DescriptorSet ), descriptorSet } );
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
			decorate( varId, { spv::Id( spv::Decoration::Binding ), bindingPoint } );
			decorate( varId, { spv::Id( spv::Decoration::DescriptorSet ), descriptorSet } );

			auto typeIt = m_registeredVariablesTypes.find( varId );

			if ( typeIt != m_registeredVariablesTypes.end() )
			{
				auto typeId = typeIt->second;
				decorate( typeId, structDecoration );
			}
		}
	}

	spv::Id Module::registerVariable( std::string const & name
		, spv::StorageClass storage
		, type::TypePtr type )
	{
		auto it = m_registeredVariables.find( name );

		if ( it == m_registeredVariables.end() )
		{
			spv::Id id{ ++*m_currentId };
			it = m_registeredVariables.emplace( name, id ).first;

			if ( type->getKind() != type::Kind::eStruct
				|| std::static_pointer_cast< type::Struct >( type )->getName() != name )
			{
				debug.push_back( makeName( spv::Op::OpName, id, name ) );
			}
			else if ( type->getKind() == type::Kind::eStruct
				|| std::static_pointer_cast< type::Struct >( type )->getName() == name )
			{
				debug.push_back( makeName( spv::Op::OpName, id, name + "Inst" ) );
			}

			auto builtin = getBuiltin( name );

			if ( builtin != spv::BuiltIn( -1 ) )
			{
				decorate( id, { spv::Id( spv::Decoration::BuiltIn ), spv::Id( builtin ) } );
			}

			auto rawTypeId = registerType( type );
			auto varTypeId = registerPointerType( rawTypeId, storage );

			if ( storage == spv::StorageClass::Function
				&& m_currentFunction )
			{
				m_currentFunction->variables.push_back( makeVariable( id, varTypeId, storage ) );
			}
			else
			{
				globalDeclarations.push_back( makeVariable( id, varTypeId, storage ) );
			}

			m_registeredVariablesTypes.emplace( id, rawTypeId );
		}

		return it->second;
	}

	spv::Id Module::registerSpecConstant( std::string name
		, uint32_t location
		, type::TypePtr type
		, expr::Literal const & value )
	{
		auto it = m_registeredVariables.find( name );

		if ( it == m_registeredVariables.end() )
		{
			spv::Id id{ ++*m_currentId };
			it = m_registeredVariables.emplace( name, id ).first;
			auto rawTypeId = registerType( type );
			IdList operands;
			debug.push_back( makeName( spv::Op::OpName, id, name ) );

			switch ( value.getLiteralType() )
			{
			case expr::LiteralType::eBool:
				operands.emplace_back( value.getValue< expr::LiteralType::eBool >() ? 1u : 0u );
				break;
			case expr::LiteralType::eInt:
				operands.emplace_back( uint32_t( value.getValue< expr::LiteralType::eInt >() ) );
				break;
			case expr::LiteralType::eUInt:
				operands.emplace_back( value.getValue< expr::LiteralType::eUInt >() );
				break;
			case expr::LiteralType::eFloat:
				{
					operands.resize( sizeof( float ) / sizeof( uint32_t ) );
					auto dst = reinterpret_cast< float * >( operands.data() );
					*dst = value.getValue< expr::LiteralType::eFloat >();
				}
				break;
			case expr::LiteralType::eDouble:
				{
					operands.resize( sizeof( double ) / sizeof( uint32_t ) );
					auto dst = reinterpret_cast< double * >( operands.data() );
					*dst = value.getValue< expr::LiteralType::eDouble >();
				}
				break;
			}

			globalDeclarations.emplace_back( makeInstruction( spv::Op::OpSpecConstant, id, rawTypeId, operands ) );
			decorate( id, { spv::Id( spv::Decoration::SpecId ), spv::Id( location ) } );
			m_registeredVariablesTypes.emplace( id, rawTypeId );
			m_registeredConstants.emplace( id, value.getType() );
		}

		return it->second;
	}

	spv::Id Module::registerParameter( type::TypePtr type )
	{
		auto typeId = registerType( type );
		auto paramId = ++*m_currentId;
		return paramId;
	}

	spv::Id Module::registerMemberVariableIndex( type::TypePtr type )
	{
		assert( type->isMember() );
		return registerLiteral( type->getIndex() );
	}

	spv::Id Module::registerMemberVariable( spv::Id outer
		, std::string name
		, type::TypePtr type )
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
			spv::Id id{ ++*m_currentId };
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
			spv::Id result{ ++*m_currentId };
			auto type = registerType( type::getBool() );
			globalDeclarations.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ value ? 1u : 0u } ) );
			it = m_registeredBoolConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, type::getBool() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( int32_t value )
	{
		auto it = m_registeredIntConstants.find( value );

		if ( it == m_registeredIntConstants.end() )
		{
			spv::Id result{ ++*m_currentId };
			auto type = registerType( type::getInt() );
			globalDeclarations.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ uint32_t( value ) } ) );
			it = m_registeredIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, type::getInt() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( uint32_t value )
	{
		auto it = m_registeredUIntConstants.find( value );

		if ( it == m_registeredUIntConstants.end() )
		{
			spv::Id result{ ++*m_currentId };
			auto type = registerType( type::getUInt() );
			globalDeclarations.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ value } ) );
			it = m_registeredUIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, type::getUInt() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( float value )
	{
		auto it = m_registeredFloatConstants.find( value );

		if ( it == m_registeredFloatConstants.end() )
		{
			spv::Id result{ ++*m_currentId };
			auto type = registerType( type::getFloat() );
			globalDeclarations.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ *reinterpret_cast< uint32_t * >( &value ) } ) );
			it = m_registeredFloatConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, type::getFloat() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( double value )
	{
		auto it = m_registeredDoubleConstants.find( value );

		if ( it == m_registeredDoubleConstants.end() )
		{
			spv::Id result{ ++*m_currentId };
			auto type = registerType( type::getDouble() );
			IdList list;
			list.resize( 2u );
			auto dst = reinterpret_cast< double * >( list.data() );
			*dst = value;
			globalDeclarations.push_back( makeInstruction( spv::Op::OpConstant, result, type, list ) );
			it = m_registeredDoubleConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, type::getDouble() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( IdList const & initialisers
		, type::TypePtr type )
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
			spv::Id result{ ++*m_currentId };
			globalDeclarations.push_back( makeInstruction( spv::Op::OpConstantComposite
				, result
				, typeId
				, initialisers ) );
			m_registeredCompositeConstants.emplace_back( initialisers, result );
			it = m_registeredCompositeConstants.begin() + m_registeredCompositeConstants.size() - 1u;
			m_registeredConstants.emplace( result, type );
		}

		return it->second;
	}

	void Module::registerExtension( std::string const & name )
	{
		extensions.push_back( makeExtension( name ) );
	}

	void Module::registerEntryPoint( spv::Id functionId
		, std::string const & name
		, IdList const & inputs
		, IdList const & outputs )
	{
		IdList operands;
		operands.push_back( spv::Id( m_model ) );
		operands.push_back( functionId );
		operands.insert( operands.end(), inputs.begin(), inputs.end() );
		operands.insert( operands.end(), outputs.begin(), outputs.end() );
		entryPoint = makeInstruction( spv::Op::OpEntryPoint
			, operands
			, name );

		switch ( m_model )
		{
		case spv::ExecutionModel::Vertex:
			break;
		case spv::ExecutionModel::TessellationControl:
			break;
		case spv::ExecutionModel::TessellationEvaluation:
			break;
		case spv::ExecutionModel::Geometry:
			break;
		case spv::ExecutionModel::Fragment:
			registerExecutionMode( spv::ExecutionMode::OriginLowerLeft );
			break;
		case spv::ExecutionModel::GLCompute:
			break;
		case spv::ExecutionModel::Kernel:
			break;
		case spv::ExecutionModel::Max:
			break;
		default:
			break;
		}

		for ( auto & executionMode : m_pendingExecutionModes )
		{
			executionModes.emplace_back( std::move( executionMode ) );
			executionModes.back().operands[0u] = functionId;
		}

		m_pendingExecutionModes.clear();
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode )
	{
		registerExecutionMode( mode, {} );
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode, IdList const & operands )
	{
		if ( entryPoint.operands.empty() )
		{
			IdList ops;
			ops.push_back( spv::Id( 0u ) );
			ops.push_back( spv::Id( mode ) );
			ops.insert( ops.end(), operands.begin(), operands.end() );
			m_pendingExecutionModes.push_back( makeInstruction( spv::Op::OpExecutionMode, ops ) );
		}
		else
		{
			IdList ops;
			ops.push_back( spv::Id( entryPoint.operands[1] ) );
			ops.push_back( spv::Id( mode ) );
			ops.insert( ops.end(), operands.begin(), operands.end() );
			executionModes.push_back( makeInstruction( spv::Op::OpExecutionMode, ops ) );
		}
	}

	spv::Id Module::getIntermediateResult()
	{
		spv::Id result{};

		if ( m_freeIntermediates.empty() )
		{
			result = ++*m_currentId;
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
		, var::VariableList const & params )
	{
		IdList funcTypes;
		IdList funcParams;
		funcTypes.push_back( retType );

		for ( auto & param : params )
		{
			funcTypes.push_back( registerType( param->getType() ) );
			spv::Id paramId{ ++*m_currentId };
			funcParams.push_back( paramId );
			debug.push_back( makeName( spv::Op::OpName, paramId, param->getName() ) );
			m_registeredVariables.emplace( param->getName(), funcParams.back() );
			m_registeredVariablesTypes.emplace( funcParams.back(), funcTypes.back() );
		}

		spv::Id funcType{ ++*m_currentId };
		globalDeclarations.push_back( spirv::makeType( type::Kind::eFunction
			, funcType
			, funcTypes ) );
		spv::Id result{ ++*m_currentId };
		InstructionList declaration;
		declaration.emplace_back( makeInstruction( spv::Op::OpFunction
			, result
			, retType
			, { spv::Id( spv::FunctionControlMask::MaskNone ), funcType } ) );
		auto itType = funcTypes.begin() + 1u;
		auto itParam = funcParams.begin();

		for ( auto & param : params )
		{
			declaration.emplace_back( makeInstruction( spv::Op::OpFunctionParameter
				, *itParam
				, *itType ) );
			++itType;
			++itParam;
		}

		m_registeredVariables.emplace( name, result );
		m_registeredVariablesTypes.emplace( result, funcType );
		functions.push_back( Function
			{
				declaration,
				{},
				{},
				m_currentId,
			} );
		debug.push_back( spirv::makeName( spv::Op::OpName, result, name ) );
		m_currentFunction = &functions.back();
		variables = &m_currentFunction->variables;

		return m_currentFunction;
	}

	Block Module::newBlock()
	{
		Block result
		{
			++*m_currentId
		};
		result.instructions.push_back( makeInstruction( spv::Op::OpLabel, result.label ) );
		return result;
	}

	void Module::endFunction()
	{
		if ( m_currentFunction
			&& !m_currentFunction->cfg.blocks.empty()
			&& !m_currentFunction->variables.empty() )
		{
			auto & instructions = m_currentFunction->cfg.blocks.begin()->instructions;
			instructions.insert( instructions.begin() + 1u
				, m_currentFunction->variables.begin()
				, m_currentFunction->variables.end() );
			m_currentFunction->variables.clear();
		}

		variables = &globalDeclarations;
		m_currentFunction = nullptr;
	}

	spv::Id Module::doRegisterNonArrayType( type::TypePtr type
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
				, parentId );
			m_registeredTypes.emplace( unqualifiedType, result );
		}
		else
		{
			result = it->second;
		}

		return result;
	}

	spv::Id Module::registerType( type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		spv::Id result;

		if ( type->getKind() == type::Kind::eArray )
		{
			auto arrayedType = std::static_pointer_cast< type::Array >( type )->getType();
			auto arraySize = getArraySize( type );
			auto elementTypeId = registerType( arrayedType
				, mbrIndex
				, parentId );

			auto unqualifiedType = getUnqualifiedType( type );
			auto it = m_registeredTypes.find( unqualifiedType );

			if ( it == m_registeredTypes.end() )
			{
				if ( arraySize != type::UnknownArraySize )
				{
					auto lengthId = registerLiteral( arraySize );
					result = ++*m_currentId;
					globalDeclarations.push_back( spirv::makeArrayType( getNonArrayKind( unqualifiedType )
						, result
						, elementTypeId
						, lengthId ) );
					writeArrayStride( *this
						, unqualifiedType
						, result );
				}
				else
				{
					result = ++*m_currentId;
					globalDeclarations.push_back( spirv::makeArrayType( getNonArrayKind( unqualifiedType )
						, result
						, elementTypeId ) );
					writeArrayStride( *this
						, unqualifiedType
						, result );
				}

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

	spv::Id Module::registerBaseType( type::Kind kind
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		assert( kind != type::Kind::eStruct );
		assert( kind != type::Kind::eImage );
		assert( kind != type::Kind::eSampledImage );

		spv::Id result{};
		auto type = type::makeType( kind );

		if ( isVectorType( kind )
			|| isMatrixType( kind ) )
		{
			IdList subTypes;
			auto componentType = registerType( makeType( getComponentType( kind ) ) );
			subTypes.push_back( componentType );
			subTypes.push_back( getComponentCount( kind ) );
			result = ++*m_currentId;
			globalDeclarations.push_back( spirv::makeType( kind, result, subTypes ) );

			if ( isMatrixType( kind ) )
			{
				if ( mbrIndex != type::NotMember )
				{
					decorateMember( parentId
						, mbrIndex
						, spv::Decoration::ColMajor );
				}
				else
				{
					decorate( result
						, spv::Decoration::ColMajor );
				}
			}
		}
		else
		{
			result = ++*m_currentId;
			globalDeclarations.push_back( spirv::makeType( kind, result ) );
		}

		return result;
	}

	spv::Id Module::registerBaseType( type::SampledImagePtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		auto imgTypeId = registerType( std::static_pointer_cast< type::SampledImage >( type )->getImageType() );
		auto result = ++*m_currentId;
		globalDeclarations.push_back( spirv::makeSampledImageType( result, imgTypeId ) );
		return result;
	}

	spv::Id Module::registerBaseType( type::ImagePtr type
		, uint32_t mbrIndex
		, spv::Id parent )
	{
		// The Sampled Type.
		auto sampledTypeId = registerType( makeType( type->getConfig().sampledType ) );
		// The Image Type.
		auto result = ++*m_currentId;
		globalDeclarations.push_back( spirv::makeImageType( type->getConfig(), result, sampledTypeId ) );
		return result;
	}

	spv::Id Module::registerBaseType( type::StructPtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		spv::Id result{ ++*m_currentId };
		IdList subTypes;

		for ( auto & member : *type )
		{
			subTypes.push_back( registerType( member.type
				, member.type->getIndex()
				, result ) );
		}

		globalDeclarations.push_back( spirv::makeStructType( result, subTypes ) );
		debug.push_back( spirv::makeName( spv::Op::OpName, result, type->getName() ) );

		for ( auto & member : *type )
		{
			auto index = member.type->getIndex();
			debug.push_back( spirv::makeName( spv::Op::OpMemberName, result, index, member.name ) );
			decorateMember( result
				, index
				, IdList{ uint32_t( spv::Decoration::Offset ), member.offset } );
		}

		return result;
	}

	spv::Id Module::registerBaseType( type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		spv::Id result{};

		if ( type->getKind() == type::Kind::eArray )
		{
			type = std::static_pointer_cast< type::Array >( type )->getType();
		}

		auto kind = type->getKind();

		if ( kind == type::Kind::eSampledImage )
		{
			result = registerBaseType( std::static_pointer_cast< type::SampledImage >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == type::Kind::eImage )
		{
			result = registerBaseType( std::static_pointer_cast< type::Image >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == type::Kind::eStruct )
		{
			result = registerBaseType( std::static_pointer_cast< type::Struct >( type )
				, mbrIndex
				, parentId );
		}
		else
		{
			result = registerBaseType( kind
				, mbrIndex
				, parentId );
		}

		return result;
	}

	//*************************************************************************
}
