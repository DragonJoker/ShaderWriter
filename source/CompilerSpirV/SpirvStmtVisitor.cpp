/*
See LICENSE file in root folder
*/
#include "SpirvStmtVisitor.hpp"

#include "SpirvExprVisitor.hpp"
#include "SpirvHelpers.hpp"

#include <sstream>

namespace spirv
{
	namespace
	{
		std::string adaptName( std::string const & name )
		{
			static std::map< std::string, std::string > const names
			{
				{ "gl_InstanceID", "gl_InstanceIndex" },
				{ "gl_VertexID", "gl_VertexIndex" },
			};

			auto it = names.find( name );

			if ( it != names.end() )
			{
				return it->second;
			}

			return name;
		}

		int32_t getInt32Value( ast::expr::Literal const & lit )
		{
			int32_t result{};

			switch ( lit.getLiteralType() )
			{
			case ast::expr::LiteralType::eBool:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eBool >() );
				break;
			case ast::expr::LiteralType::eInt:
				result = lit.getValue< ast::expr::LiteralType::eInt >();
				break;
			case ast::expr::LiteralType::eUInt:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eUInt >() );
				break;
			default:
				break;
			}

			return result;
		}

		void checkCapabilitySupport( spv::Capability capability
			, SpirVConfig const & spirvConfig )
		{
			if ( capability == spv::CapabilityAtomicFloat32AddEXT
				|| capability == spv::CapabilityAtomicFloat64AddEXT )
			{
				if ( spirvConfig.specVersion < 0x00010500 )
				{
					throw std::runtime_error{ "Current SPIR-V specification version doesn't support " + getName( capability ) };
				}
			}
		}
	}

	Module StmtVisitor::submit( ast::type::TypesCache & cache
		, ast::stmt::Stmt * stmt
		, ast::ShaderStage type
		, ModuleConfig const & moduleConfig
		, spirv::PreprocContext context
		, SpirVConfig const & spirvConfig
		, ShaderActions actions )
	{
		Module result{ cache
			, spirvConfig
			, getMemoryModel()
			, getExecutionModel( type ) };
		StmtVisitor vis{ result, type, moduleConfig, std::move( context ), spirvConfig, std::move( actions ) };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( Module & result
		, ast::ShaderStage type
		, ModuleConfig const & moduleConfig
		, spirv::PreprocContext context
		, SpirVConfig const & spirvConfig
		, ShaderActions actions )
		: m_context{ std::move( context ) }
		, m_actions{ std::move( actions ) }
		, m_result{ result }
	{
		for ( auto & capability : moduleConfig.requiredCapabilities )
		{
			checkCapabilitySupport( capability, spirvConfig );
			m_result.capabilities.emplace_back( makeInstruction< CapabilityInstruction >( ValueId{ spv::Id( capability ) } ) );
		}

		VariableInfo info;

		for ( auto & input : moduleConfig.getInputs() )
		{
			if ( input->getBuiltin() != ast::Builtin::eWorkGroupSize )
			{
				m_inputs.push_back( m_result.registerVariable( adaptName( input->getName() )
					, input->getBuiltin()
					, spv::StorageClassInput
					, input->isAlias()
					, input->isParam()
					, input->isOutputParam()
					, input->getType()
					, info ).id );
			}
		}

		for ( auto & output : moduleConfig.getOutputs() )
		{
			m_outputs.push_back( m_result.registerVariable( adaptName( output->getName() )
				, output->getBuiltin()
				, spv::StorageClassOutput
				, output->isAlias()
				, output->isParam()
				, output->isOutputParam()
				, output->getType()
				, info ).id );
		}
	}

	void StmtVisitor::visitContainerStmt( ast::stmt::Container * cont )
	{
		for ( auto & stmt : *cont )
		{
			if ( !m_currentBlock.isInterrupted )
			{
				stmt->accept( this );
			}
		}
	}

	void StmtVisitor::visitBreakStmt( ast::stmt::Break * stmt )
	{
		interruptBlock( m_currentBlock
			, makeInstruction< BranchInstruction >( ValueId{ m_controlBlocks.back().breakLabel } )
			, !stmt->isSwitchCaseBreak() );
	}

	void StmtVisitor::visitContinueStmt( ast::stmt::Continue * stmt )
	{
		interruptBlock( m_currentBlock
			, makeInstruction< BranchInstruction >( ValueId{ m_controlBlocks.back().continueLabel } )
			, true );
	}

	void StmtVisitor::visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
		m_result.bindBufferVariable( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, spv::DecorationBlock );
	}

	void StmtVisitor::visitDiscardStmt( ast::stmt::Discard * stmt )
	{
		interruptBlock( m_currentBlock
			, makeInstruction< KillInstruction >()
			, true );
	}

	void StmtVisitor::visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitCommentStmt( ast::stmt::Comment * stmt )
	{
	}

	void StmtVisitor::visitCompoundStmt( ast::stmt::Compound * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::interruptBlock( Block & block
		, InstructionPtr interruptInstruction
		, bool pushBlock )
	{
		m_currentBlock.blockEnd = std::move( interruptInstruction );
		m_currentBlock.isInterrupted = true;

		if ( pushBlock && !m_ifStmts )
		{
			m_function->cfg.blocks.emplace_back( std::move( m_currentBlock ) );
			m_currentBlock = m_result.newBlock();
		}
	}

	void StmtVisitor::endBlock( Block & block
		, spv::Id nextBlockLabel )
	{
		if ( !block.isInterrupted )
		{
			block.blockEnd = makeInstruction< BranchInstruction >( ValueId{ nextBlockLabel } );
		}

		m_function->cfg.blocks.emplace_back( std::move( block ) );
	}

	void StmtVisitor::endBlock( Block & block
		, spv::Id trueBlockLabel
		, spv::Id falseBlockLabel
		, spv::Id mergeBlockLabel )
	{
		if ( !block.isInterrupted )
		{
			block.blockEnd = makeInstruction< BranchConditionalInstruction >( makeOperands( ValueId{ trueBlockLabel }
				, ValueId{ falseBlockLabel }
				, ValueId{ mergeBlockLabel } ) );
		}

		m_function->cfg.blocks.emplace_back( std::move( block ) );
	}

	void StmtVisitor::visitDoWhileStmt( ast::stmt::DoWhile * stmt )
	{
		auto loopBlock = m_result.newBlock();
		auto ifBlock = m_result.newBlock();
		auto mergeBlock = m_result.newBlock();
		auto contentBlock = m_result.newBlock();
		m_controlBlocks.push_back( { mergeBlock.label, ifBlock.label } );

		// End current block, to branch to the loop header block.
		endBlock( m_currentBlock, loopBlock.label );

		// The loop header block, to which continue target will branch, branches to the loop content block.
		auto loopBlockLabel = loopBlock.label;
		loopBlock.instructions.emplace_back( makeInstruction< LoopMergeInstruction >( makeOperands( ValueId{ mergeBlock.label }
			, ValueId{ ifBlock.label }
			, ValueId{ 0u } ) ) );
		endBlock( loopBlock, contentBlock.label );

		// The current block becomes the loop content block.
		m_currentBlock = std::move( contentBlock );

		// Instructions go to loop content block.
		visitContainerStmt( stmt );

		// Branch current block to the continue target block.
		endBlock( m_currentBlock, ifBlock.label );

		// The if block, branches either back to the loop header block (true) or to the loop merge block (false).
		auto intermediateIfId = m_result.loadVariable( ExprVisitor::submit( stmt->getCtrlExpr(), m_context, ifBlock, m_result ), m_currentBlock );
		endBlock( ifBlock, intermediateIfId.id, loopBlockLabel, mergeBlock.label );

		// Current block becomes the merge block.
		m_controlBlocks.pop_back();
		m_currentBlock = std::move( mergeBlock );
	}

	void StmtVisitor::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		AST_Failure( "Unexpected ElseIf statement." );
	}

	void StmtVisitor::visitElseStmt( ast::stmt::Else * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitForStmt( ast::stmt::For * stmt )
	{
		AST_Failure( "Unexpected For statement." );
	}

	void StmtVisitor::visitFragmentLayout( ast::stmt::FragmentLayout * stmt )
	{
		switch ( stmt->getFragmentCenter() )
		{
		case ast::FragmentCenter::eCenterInteger:
			m_result.registerExecutionMode( spv::ExecutionModePixelCenterInteger );
			break;
		case ast::FragmentCenter::eHalfPixel:
			// Half pixel is default mode
			break;
		default:
			break;
		}

		switch ( stmt->getFragmentOrigin() )
		{
		case ast::FragmentOrigin::eLowerLeft:
			m_result.registerExecutionMode( spv::ExecutionModeOriginLowerLeft );
			break;
		case ast::FragmentOrigin::eUpperLeft:
			m_result.registerExecutionMode( spv::ExecutionModeOriginUpperLeft );
			break;
		default:
			break;
		}
	}

	void StmtVisitor::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		auto type = stmt->getType();
		auto retType = m_result.registerType( type->getReturnType() );
		m_function = m_result.beginFunction( stmt->getName()
			, retType
			, ast::var::VariableList{ type->begin(), type->end() } );
		m_currentBlock = m_result.newBlock();

		if ( stmt->isEntryPoint() )
		{
			m_result.registerEntryPoint( ValueId{ m_function->declaration.front()->resultId.value() }
				, stmt->getName()
				, m_inputs
				, m_outputs );
		}

		auto itFunction = m_actions.find( stmt->getName() );

		for ( auto & param : *stmt->getType() )
		{
			bool requiresPtrVar = param->isOutputParam();

			if ( !requiresPtrVar
				&& itFunction != m_actions.end() )
			{
				auto itVar = itFunction->second.find( param->getEntityName() );

				if ( itVar != itFunction->second.end() )
				{
					requiresPtrVar = itVar->second.sets > 0
						|| itVar->second.usesThroughMember > 0;
				}
			}

			if ( requiresPtrVar )
			{
				VariableInfo sourceInfo;
				auto varInfo = m_result.registerVariable( param->getName()
					, ast::Builtin::eNone
					, spv::StorageClassFunction
					, false
					, false
					, param->isOutputParam()
					, param->getType()
					, sourceInfo
					, {} );

				if ( !sourceInfo.id.isPointer() )
				{
					m_result.storeVariable( varInfo.id, sourceInfo.id, m_currentBlock );
				}
			}
		}

		visitContainerStmt( stmt );

		if ( !m_currentBlock.blockEnd )
		{
			if ( type->getReturnType()->getKind() == ast::type::Kind::eVoid )
			{
				m_currentBlock.blockEnd = makeInstruction< ReturnInstruction >();
			}
			else
			{
				auto retId = ValueId{ m_result.getIntermediateResult(), retType.type };
				m_currentBlock.instructions.emplace_back( makeInstruction< UndefInstruction >( retType, retId ) );
				m_currentBlock.blockEnd = makeInstruction< ReturnValueInstruction >( retId );
			}
		}

		m_currentBlock.instructions.emplace_back( std::move( m_currentBlock.blockEnd ) );
		m_currentBlock.blockEnd = makeInstruction< FunctionEndInstruction >();
		m_function->cfg.blocks.emplace_back( std::move( m_currentBlock ) );
		m_result.endFunction();
		m_function = nullptr;
	}

	void StmtVisitor::visitIfStmt( ast::stmt::If * stmt )
	{
		++m_ifStmts;
		auto contentBlock = m_result.newBlock();
		auto mergeBlock = m_result.newBlock();

		// Retrieve the if false branch block label.
		// It will be the else block if it exists, or the merge block.
		BlockList elseIfBlocks;
		Block elseBlock;
		auto falseBlockLabel = mergeBlock.label;
		assert( stmt->getElseIfList().empty() && "ElseIf list is supposed to have been converted." );

		if ( stmt->getElse() )
		{
			elseBlock = m_result.newBlock();
			falseBlockLabel = elseBlock.label;
		}

		// End current block, to branch to the if content block (true) or to the false branch block (false).
		auto intermediateIfId = m_result.loadVariable( ExprVisitor::submit( stmt->getCtrlExpr(), m_context, m_currentBlock, m_result ), m_currentBlock );
		m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( ValueId{ mergeBlock.label }, ValueId{ 0u } ) );
		endBlock( m_currentBlock, intermediateIfId.id, contentBlock.label, falseBlockLabel );

		// The current block becomes the if content block.
		m_currentBlock = std::move( contentBlock );
		visitContainerStmt( stmt );
		endBlock( m_currentBlock, mergeBlock.label );

		if ( stmt->getElse() )
		{
			m_currentBlock = std::move( elseBlock );
			stmt->getElse()->accept( this );
			endBlock( m_currentBlock, mergeBlock.label );
		}

		// Current block becomes the merge block.
		m_currentBlock = std::move( mergeBlock );
		--m_ifStmts;
	}

	void StmtVisitor::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		m_result.bindVariable( visitVariable( stmt->getVariable() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
	}

	void StmtVisitor::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		auto varId = visitVariable( var );

		if ( var->isShaderConstant() )
		{
			m_result.decorate( varId, { spv::Id( spv::DecorationSpecId ), stmt->getLocation() } );
		}
		else if ( !var->isBuiltin() )
		{
			m_result.decorate( varId, { spv::Id( spv::DecorationLocation ), stmt->getLocation() } );
		}

		if ( var->isBlendIndex() )
		{
			m_result.decorate( varId, { spv::Id( spv::DecorationIndex ), stmt->getBlendIndex() } );
		}

		if ( var->isGeometryStream() )
		{
			m_result.decorate( varId, { spv::Id( spv::DecorationStream ), stmt->getStreamIndex() } );
		}

		if ( var->isFlat() )
		{
			m_result.decorate( varId, IdList{ spv::Id( spv::DecorationFlat ) } );
		}

		if ( var->isNoPerspective() )
		{
			m_result.decorate( varId, IdList{ spv::Id( spv::DecorationNoPerspective ) } );
		}

		if ( var->isCentroid() )
		{
			m_result.decorate( varId, IdList{ spv::Id( spv::DecorationCentroid ) } );
		}

		if ( var->isPerSample() )
		{
			m_result.decorate( varId, IdList{ spv::Id( spv::DecorationSample ) } );
		}

		if ( var->isPatch() )
		{
			m_result.decorate( varId, IdList{ spv::Id( spv::DecorationPatch ) } );
		}
	}

	void StmtVisitor::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		auto var = stmt->getVariable();
		m_result.registerSpecConstant( var->getName()
			, stmt->getLocation()
			, var->getType()
			, *stmt->getValue() );
	}

	void StmtVisitor::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		m_result.registerExecutionMode( spv::ExecutionModeLocalSize
			, { ValueId{ stmt->getWorkGroupsX() }, ValueId{ stmt->getWorkGroupsY() }, ValueId{ stmt->getWorkGroupsZ() } } );
		ValueIdList ids;
		ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsX() ) );
		ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsY() ) );
		ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsZ() ) );
		m_context.workGroupSizeExpr = m_result.registerLiteral( ids, m_result.getCache().getVec3U() );
		m_result.decorate( m_context.workGroupSizeExpr, { spv::Id( spv::DecorationBuiltIn ), spv::Id( spv::BuiltInWorkgroupSize ) } );
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		m_result.registerExecutionMode( stmt->getLayout() );
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		m_result.registerExecutionMode( stmt->getLayout(), stmt->getPrimCount() );
	}

	void StmtVisitor::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
		m_result.registerExecutionMode( stmt->getDomain()
			, stmt->getPartitioning()
			, stmt->getTopology()
			, stmt->getPrimitiveOrdering()
			, stmt->getOutputVertices() );
	}

	void StmtVisitor::visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )
	{
		m_result.registerExecutionMode( stmt->getDomain()
			, stmt->getPartitioning()
			, stmt->getPrimitiveOrdering() );
	}

	void StmtVisitor::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
		switch ( stmt->getSource() )
		{
		case ast::stmt::PerVertexDecl::Source::eVertexOutput:
		case ast::stmt::PerVertexDecl::Source::eTessellationControlInput:
		case ast::stmt::PerVertexDecl::Source::eTessellationControlOutput:
		case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
		case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
		case ast::stmt::PerVertexDecl::Source::eGeometryInput:
		case ast::stmt::PerVertexDecl::Source::eGeometryOutput:
		default:
			break;
		}
	}

	void StmtVisitor::visitReturnStmt( ast::stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			auto result = m_result.loadVariable( ExprVisitor::submit( stmt->getExpr()
					, m_context
					, m_currentBlock
					, m_result )
				, m_currentBlock );
			interruptBlock( m_currentBlock
				, makeInstruction< ReturnValueInstruction >( result )
				, false );
		}
		else
		{
			interruptBlock( m_currentBlock
				, makeInstruction< ReturnInstruction >()
				, false );
		}
	}

	void StmtVisitor::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		m_result.bindVariable( visitVariable( stmt->getVariable() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
	}

	void StmtVisitor::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
		m_result.bindVariable( visitVariable( stmt->getVariable() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
	}

	void StmtVisitor::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
		m_result.bindBufferVariable( stmt->getSsboName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, spv::DecorationBufferBlock );
	}

	void StmtVisitor::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		visitVariable( stmt->getSsboInstance() );
		m_result.bindBufferVariable( stmt->getSsboInstance()->getName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, spv::DecorationBufferBlock );
	}

	void StmtVisitor::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		ExprVisitor::submit( stmt->getExpr(), m_context, m_currentBlock, m_result );
	}

	void StmtVisitor::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		m_result.registerType( stmt->getType() );
	}

	void StmtVisitor::visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		std::vector< Block > caseBlocks;
		std::map< int32_t, spv::Id > caseBlocksIds;
		auto mergeBlock = m_result.newBlock();
		m_controlBlocks.push_back( { mergeBlock.label, 0u } );
		ast::stmt::SwitchCase * defaultStmt{ nullptr };
		Block defaultBlock = m_result.newBlock();

		for ( auto & it : *stmt )
		{
			assert( it->getKind() == ast::stmt::Kind::eSwitchCase );
			auto & caseStmt = static_cast< ast::stmt::SwitchCase const & >( *it );

			if ( caseStmt.getCaseExpr() )
			{
				auto block = m_result.newBlock();
				caseBlocksIds.emplace( getInt32Value( *caseStmt.getCaseExpr()->getLabel() ), block.label );
				caseBlocks.emplace_back( std::move( block ) );
			}
			else
			{
				// Default
				defaultStmt = static_cast< ast::stmt::SwitchCase * >( it.get() );
			}
		}

		auto selector = m_result.loadVariable( ExprVisitor::submit( stmt->getTestExpr()->getValue(), m_context, m_currentBlock, m_result ), m_currentBlock );
		m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( ValueId{ mergeBlock.label }, ValueId{ 0u } ) );
		m_currentBlock.blockEnd = makeInstruction< SwitchInstruction >( ValueIdList{ selector, ValueId{ defaultBlock.label } }, caseBlocksIds );
		m_currentBlock.isInterrupted = true;

		if ( !caseBlocks.empty() )
		{
			endBlock( m_currentBlock, caseBlocks.front().label );
			uint32_t index = 0u;

			for ( auto & it : *stmt )
			{
				assert( it->getKind() == ast::stmt::Kind::eSwitchCase );
				auto & caseStmt = static_cast< ast::stmt::SwitchCase & >( *it );
				m_currentBlock = std::move( caseBlocks[index] );

				visitContainerStmt( &caseStmt );

				if ( m_currentBlock.isInterrupted )
				{
					// Branch to merge block.
					endBlock( m_currentBlock, mergeBlock.label );
				}
				else
				{
					// No break statement.
					if ( index == caseBlocks.size() - 1u )
					{
						// Branch to default block.
						endBlock( m_currentBlock, defaultBlock.label );
					}
					else
					{
						// Branch to next case block.
						endBlock( m_currentBlock, caseBlocks[index + 1u].label );
					}
				}

				++index;
			}
		}
		else
		{
			endBlock( m_currentBlock, defaultBlock.label );
		}

		// Write default block.
		m_currentBlock = std::move( defaultBlock );

		if ( defaultStmt )
		{
			visitContainerStmt( defaultStmt );
		}

		endBlock( m_currentBlock, mergeBlock.label );

		m_controlBlocks.pop_back();
		m_currentBlock = std::move( mergeBlock );
	}

	void StmtVisitor::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		auto result = visitVariable( stmt->getVariable() );

		if ( stmt->getVariable()->isPatch() )
		{
			m_result.decorate( result, spv::DecorationPatch );
		}
	}

	void StmtVisitor::visitWhileStmt( ast::stmt::While * stmt )
	{
		AST_Failure( "Unexpected While statement." );
	}

	void StmtVisitor::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		AST_Failure( "Unexpected PreprocDefine statement." );
	}

	void StmtVisitor::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		AST_Failure( "Unexpected PreprocElif statement." );
	}

	void StmtVisitor::visitPreprocElse( ast::stmt::PreprocElse * preproc )
	{
		AST_Failure( "Unexpected PreprocElse statement." );
	}

	void StmtVisitor::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
		AST_Failure( "Unexpected PreprocEndif statement." );
	}

	void StmtVisitor::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
		m_result.registerExtension( preproc->getName() );
	}

	void StmtVisitor::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
		AST_Failure( "Unexpected PreprocIf statement." );
	}

	void StmtVisitor::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		AST_Failure( "Unexpected PreprocIfDef statement." );
	}

	void StmtVisitor::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
		//TODO m_result->addStmt( ast::stmt::makePreprocVersion( preproc->getName() ) );
	}

	ValueId StmtVisitor::visitVariable( ast::var::VariablePtr var )
	{
		VariableInfo info;

		if ( var->isMember() )
		{
			auto outer = m_result.registerVariable( var->getOuter()->getName()
				, var->getOuter()->getBuiltin()
				, getStorageClass( var )
				, var->isAlias()
				, var->isParam()
				, var->isOutputParam()
				, var->getOuter()->getType()
				, info ).id;
			return m_result.registerMemberVariable( outer
				, var->getName()
				, var->getType() );
		}

		return m_result.registerVariable( var->getName()
			, var->getBuiltin()
			, getStorageClass( var )
			, var->isAlias()
			, var->isParam()
			, var->isOutputParam()
			, var->getType()
			, info ).id;
	}
}
