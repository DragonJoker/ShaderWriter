/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvModule.hpp"

#include "ShaderWriter/SPIRV/SpirvHelpers.hpp"

#include <algorithm>

namespace sdw::spirv
{
	//*************************************************************************

	namespace
	{
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
	}
	
	//*************************************************************************

	Module::Module( spv::MemoryModel memoryModel
		, spv::ExecutionModel executionModel )
		: variables{ &globals }
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
				, { spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::TessellationControl:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, { spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::TessellationEvaluation:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, { spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::Geometry:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, { spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::Fragment:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, { spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::GLCompute:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, { spv::Id( spv::Capability::Shader ) } ) );
			break;
		case spv::ExecutionModel::Kernel:
			capabilities.push_back( makeInstruction( spv::Op::OpCapability
				, { spv::Id( spv::Capability::Kernel ) } ) );
			break;
		default:
			assert( false && "Unsupported ExecutionModel" );
			break;
		}
	}

	type::TypePtr getUnqualifiedType( type::TypePtr qualified )
	{
		auto result = qualified;

		if ( result->getKind() == type::Kind::eStruct )
		{
			auto resultStruct = std::static_pointer_cast< type::Struct >( result )->getUnqualifiedType();
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
		else if ( result->getKind() == type::Kind::eCount )
		{
			static type::TypePtr cache = qualified;
			result = cache;
		}
		else if ( result->getKind() == type::Kind( uint32_t( type::Kind::eCount ) + 1u ) )
		{
			static type::TypePtr cache = qualified;
			result = cache;
		}
		else if ( result->isMember() )
		{
			result = type::makeType( result->getKind()
				, result->getArraySize() );
		}

		return result;
	}

	spv::Id Module::registerType( type::TypePtr type )
	{
		spv::Id result;
		type = getUnqualifiedType( type );
		auto it = m_registeredTypes.find( type );

		if ( it == m_registeredTypes.end() )
		{
			if ( type->getArraySize() == type::NotArray )
			{
				result = registerBaseType( type );
			}
			else if ( type->getArraySize() != type::UnknownArraySize )
			{
				auto elementType = registerBaseType( type );
				result = ++*m_currentId;
				types.push_back( spirv::makeArrayType( type->getKind(), result, elementType, type->getArraySize() ) );
				decorate( result, IdList{ uint32_t( spv::Decoration::ArrayStride ), getSize( type, type::MemoryLayout::eStd140 ) / type->getArraySize() } );
			}
			else
			{
				auto elementType = registerBaseType( type );
				result = ++*m_currentId;
				types.push_back( spirv::makeArrayType( type->getKind(), result, elementType ) );
			}

			m_registeredTypes.emplace( type, result );
		}
		else
		{
			result = it->second;
		}

		return result;
	}

	spv::Id Module::registerPointerType( spv::Id type, spv::StorageClass storage )
	{
		uint64_t key = ( uint64_t( type ) << 32 ) | uint64_t( storage );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			spv::Id id{ ++*m_currentId };
			it = m_registeredPointerTypes.emplace( key, id ).first;
			types.push_back( spirv::makeInstruction( spv::Op::OpTypePointer, id, IdList{ spv::Id( storage ), type } ) );
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

	spv::Id Module::registerVariable( std::string name
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

			auto builtin = getBuiltin( name );

			if ( builtin != spv::BuiltIn( -1 ) )
			{
				decorate( id, { spv::Id( spv::Decoration::BuiltIn ), spv::Id( builtin ) } );
			}

			auto rawType = registerType( type );
			auto varType = registerPointerType( rawType, storage );

			if ( storage == spv::StorageClass::Function
				&& m_currentFunction )
			{
				m_currentFunction->variables.push_back( makeVariable( id, varType, storage ) );
			}
			else
			{
				globals.push_back( makeVariable( id, varType, storage ) );
			}
		}

		return it->second;
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
		assert( type->isMember()  );
		auto fullName = it->first + "::" + name;
		auto outerId = it->second;
		it = m_registeredVariables.find( fullName );

		if ( it == m_registeredVariables.end() )
		{
			spv::Id id{ ++*m_currentId };
			m_registeredMemberVariables.insert( { fullName, { outer, id } } );
			it = m_registeredVariables.emplace( fullName, id ).first;
			assert( type->isMember() );
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
			constants.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ value ? 1u : 0u } ) );
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
			constants.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ uint32_t( value ) } ) );
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
			constants.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ value } ) );
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
			constants.push_back( makeInstruction( spv::Op::OpConstant, result, type, IdList{ *reinterpret_cast< uint32_t * >( &value ) } ) );
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
			constants.push_back( makeInstruction( spv::Op::OpConstant, result, type, list ) );
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
			constants.push_back( makeInstruction( spv::Op::OpConstantComposite
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
		if ( m_intermediates.end() != m_intermediates.find( id ) )
		{
			m_freeIntermediates.insert( id );
			auto it = m_busyIntermediates.begin();

			while ( it != m_busyIntermediates.end() )
			{
				if ( it->first == id
					|| it->second == id )
				{
					it = m_busyIntermediates.erase( it );
				}
				else
				{
					++it;
				}
			}
		}
	}

	spv::Id Module::getNonIntermediate( spv::Id id )
	{
		while ( m_intermediates.end() != m_intermediates.find( id ) )
		{
			id = m_busyIntermediates.find( id )->second;
		}

		return id;
	}

	Function * Module::beginFunction( std::string name
		, spv::Id retType
		, ParameterList params )
	{
		IdList funcTypes;
		funcTypes.push_back( retType );

		for ( auto & param : params )
		{
			funcTypes.push_back( param.type );
		}

		spv::Id funcType{ ++*m_currentId };
		types.push_back( spirv::makeType( type::Kind::eFunction
			, funcType
			, funcTypes ) );
		spv::Id result{ ++*m_currentId };
		functions.push_back( Function
			{
				retType,
				result,
				uint32_t( spv::FunctionControlMask::MaskNone ),
				funcType,
				params,
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
		return Block
		{
			++*m_currentId
		};
	}

	void Module::endFunction()
	{
		if ( m_currentFunction
			&& !m_currentFunction->cfg.blocks.empty()
			&& !m_currentFunction->variables.empty() )
		{
			m_currentFunction->cfg.blocks.begin()->instructions.insert( m_currentFunction->cfg.blocks.begin()->instructions.begin()
				, m_currentFunction->variables.begin()
				, m_currentFunction->variables.end() );
		}

		variables = &globals;
		m_currentFunction = nullptr;
	}

	spv::Id Module::registerBaseType( type::Kind kind )
	{
		assert( kind != type::Kind::eStruct );

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
			types.push_back( spirv::makeType( kind, result, subTypes ) );
		}
		else if ( kind == type::Kind::eCount )
		{
			// The Sampler Type.
			result = ++*m_currentId;
			types.push_back( spirv::makeSamplerType( result ) );
		}
		else if ( isImageType( kind )
			|| isSamplerType( kind ) )
		{
			// The Sampled Type.
			auto sampledType = registerType( makeType( getComponentType( kind ) ) );
			// The Image Type.
			result = ++*m_currentId;
			types.push_back( spirv::makeImageType( kind, result, sampledType ) );

			if ( isSamplerType( kind ) )
			{
				// The Sampled Image Type.
				auto imageType = result;
				result = ++*m_currentId;
				types.push_back( spirv::makeSampledImageType( kind, result, imageType ) );
			}
		}
		else
		{
			result = ++*m_currentId;
			types.push_back( spirv::makeType( kind, result ) );
		}

		return result;
	}

	spv::Id Module::registerBaseType( type::StructPtr type )
	{
		spv::Id result{ ++*m_currentId };
		IdList subTypes;

		for ( auto & member : *type )
		{
			subTypes.push_back( registerType( member.type ) );
		}

		types.push_back( spirv::makeStructType( result, subTypes ) );
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

	spv::Id Module::registerBaseType( type::TypePtr type )
	{
		spv::Id result{};
		auto kind = type->getKind();

		if ( kind == type::Kind::eCount )
		{
			// Implicit Sampler
			result = ++*m_currentId;
			types.push_back( spirv::makeSamplerType( result ) );
		}
		else if ( kind == type::Kind( uint32_t( type::Kind::eCount ) + 1u ) )
		{
			// Implicit Sampled Image
			result = ++*m_currentId;
			types.push_back( spirv::makeSampledImageType( kind, result, 0u ) );
		}
		else if ( kind == type::Kind::eStruct )
		{
			result = registerBaseType( std::static_pointer_cast< type::Struct >( type ) );
		}
		else
		{
			result = registerBaseType( type->getKind() );
		}

		return result;
	}

	//*************************************************************************
}
