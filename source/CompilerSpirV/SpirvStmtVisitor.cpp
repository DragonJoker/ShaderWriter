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
				result = int32_t( lit.getValue< ast::expr::LiteralType::eInt >() );
				break;
			case ast::expr::LiteralType::eUInt:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eUInt >() );
				break;
			default:
				break;
			}

			return result;
		}
	}

	Module StmtVisitor::submit( ast::type::TypesCache & cache
		, ast::stmt::Stmt * stmt
		, ast::ShaderStage type
		, ModuleConfig const & config )
	{
		Module result{ cache
			, getMemoryModel()
			, getExecutionModel( type ) };
		StmtVisitor vis{ result, type, config };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( Module & result
		, ast::ShaderStage type
		, ModuleConfig const & config )
		: m_result{ result }
	{
		for ( auto & capability : config.requiredCapabilities )
		{
			m_result.capabilities.emplace_back( makeInstruction< CapabilityInstruction >( spv::Id( capability ) ) );
		}

		VariableInfo info;

		for ( auto & input : config.inputs )
		{
			m_inputs.push_back( m_result.registerVariable( adaptName( input->getName() ), spv::StorageClassInput, input->getType(), info ).id );
		}

		for ( auto & output : config.outputs )
		{
			m_outputs.push_back( m_result.registerVariable( adaptName( output->getName() ), spv::StorageClassOutput, output->getType(), info ).id );
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
			, makeInstruction< BranchInstruction >( m_controlBlocks.back().breakLabel )
			, !stmt->isSwitchCaseBreak() );
	}

	void StmtVisitor::visitContinueStmt( ast::stmt::Continue * stmt )
	{
		interruptBlock( m_currentBlock
			, makeInstruction< BranchInstruction >( m_controlBlocks.back().continueLabel )
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
			block.blockEnd = makeInstruction< BranchInstruction >( nextBlockLabel );
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
			block.blockEnd = makeInstruction< BranchConditionalInstruction >( makeOperands( trueBlockLabel
				, falseBlockLabel
				, mergeBlockLabel ) );
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
		loopBlock.instructions.emplace_back( makeInstruction< LoopMergeInstruction >( makeOperands( mergeBlock.label, ifBlock.label, 0u ) ) );
		endBlock( loopBlock, contentBlock.label );

		// The current block becomes the loop content block.
		m_currentBlock = std::move( contentBlock );

		// Instructions go to loop content block.
		visitContainerStmt( stmt );

		// Branch current block to the continue target block.
		endBlock( m_currentBlock, ifBlock.label );

		// The if block, branches either back to the loop header block (true) or to the loop merge block (false).
		auto intermediateIfId = ExprVisitor::submit( stmt->getCtrlExpr(), ifBlock, m_result );
		endBlock( ifBlock, intermediateIfId, loopBlockLabel, mergeBlock.label );

		// Current block becomes the merge block.
		m_controlBlocks.pop_back();
		m_currentBlock = std::move( mergeBlock );
	}

	void StmtVisitor::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		assert( false && "Unexpected ElseIf statement." );
	}

	void StmtVisitor::visitElseStmt( ast::stmt::Else * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitForStmt( ast::stmt::For * stmt )
	{
		auto loopBlock = m_result.newBlock();
		auto ifBlock = m_result.newBlock();
		auto continueBlock = m_result.newBlock();
		auto mergeBlock = m_result.newBlock();
		m_controlBlocks.push_back( { mergeBlock.label, continueBlock.label } );

		// End current block, to branch to the loop header block.
		auto intermediateInitId = ExprVisitor::submit( stmt->getInitExpr(), m_currentBlock, m_result );
		endBlock( m_currentBlock, loopBlock.label );

		// The current block becomes the loop content block.
		m_currentBlock = m_result.newBlock();

		// The loop header block, to which continue target will branch, branches to the if block.
		auto loopBlockLabel = loopBlock.label;
		loopBlock.instructions.emplace_back( makeInstruction< LoopMergeInstruction >( makeOperands( mergeBlock.label, continueBlock.label, 0u ) ) );
		endBlock( loopBlock, ifBlock.label );

		// The if block, branches to either loop content block (true) or loop merge block (false).
		auto intermediateIfId = ExprVisitor::submit( stmt->getCtrlExpr(), ifBlock, m_result );
		endBlock( ifBlock, intermediateIfId, m_currentBlock.label, mergeBlock.label );

		// Instructions go to loop content block.
		visitContainerStmt( stmt );

		// Branch current block to the continue target block.
		endBlock( m_currentBlock, continueBlock.label );

		// The continue target block, branches back to loop header.
		auto intermediateIncrId = ExprVisitor::submit( stmt->getIncrExpr(), continueBlock, m_result, false );
		endBlock( continueBlock, loopBlockLabel );

		// Current block becomes the merge block.
		m_controlBlocks.pop_back();
		m_currentBlock = std::move( mergeBlock );
	}

	void StmtVisitor::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		auto type = stmt->getType();
		auto retType = m_result.registerType( type->getReturnType() );
		m_function = m_result.beginFunction( stmt->getName()
			, retType
			, ast::var::VariableList{ type->begin(), type->end() } );
		m_currentBlock = m_result.newBlock();

		if ( stmt->getName() == "main" )
		{
			m_result.registerEntryPoint( m_function->declaration.front()->resultId.value()
				, stmt->getName()
				, m_inputs
				, m_outputs );
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
				auto retId = m_result.getIntermediateResult();
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
		auto intermediateIfId = ExprVisitor::submit( stmt->getCtrlExpr(), m_currentBlock, m_result );
		m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( mergeBlock.label, 0u ) );
		endBlock( m_currentBlock, intermediateIfId, contentBlock.label, falseBlockLabel );

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
		else
		{
			m_result.decorate( varId, { spv::Id( spv::DecorationLocation ), stmt->getLocation() } );
		}

		if ( var->isFlat() )
		{
			m_result.decorate( varId, IdList{ spv::Id( spv::DecorationFlat ) } );
		}
	}

	void StmtVisitor::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		auto var = stmt->getVariable();
		auto varId = m_result.registerSpecConstant( var->getName()
			, stmt->getLocation()
			, var->getType()
			, *stmt->getValue() );
	}

	void StmtVisitor::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		m_result.registerExecutionMode( spv::ExecutionModeLocalSize
			, { stmt->getWorkGroupsX(), stmt->getWorkGroupsY(), stmt->getWorkGroupsZ() } );
		IdList ids;
		ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsX() ) );
		ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsY() ) );
		ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsZ() ) );
		auto id = m_result.registerLiteral( ids, m_result.getCache().getVec3I() );
		m_result.decorate( id, { spv::Id( spv::DecorationBuiltIn ), spv::Id( spv::BuiltInWorkgroupSize ) } );
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		auto layout = stmt->getLayout();

		switch ( layout )
		{
		case ast::stmt::InputLayout::ePointList:
			m_result.registerExecutionMode( spv::ExecutionModeInputPoints );
			break;
		case ast::stmt::InputLayout::eLineList:
		case ast::stmt::InputLayout::eLineStrip:
			m_result.registerExecutionMode( spv::ExecutionModeInputLines );
			break;
		case ast::stmt::InputLayout::eTriangleList:
		case ast::stmt::InputLayout::eTriangleStrip:
		case ast::stmt::InputLayout::eTriangleFan:
			m_result.registerExecutionMode( spv::ExecutionModeTriangles );
			break;
		case ast::stmt::InputLayout::eTriangleListWithAdjacency:
		case ast::stmt::InputLayout::eTriangleStripWithAdjacency:
			m_result.registerExecutionMode( spv::ExecutionModeInputTrianglesAdjacency );
			break;
		case ast::stmt::InputLayout::eLineListWithAdjacency:
		case ast::stmt::InputLayout::eLineStripWithAdjacency:
			m_result.registerExecutionMode( spv::ExecutionModeInputLinesAdjacency );
			break;
		default:
			assert( false && "Unsupported InputLayout" );
			break;
		}
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		auto layout = stmt->getLayout();

		switch ( layout )
		{
		case ast::stmt::OutputLayout::ePointList:
			m_result.registerExecutionMode( spv::ExecutionModeOutputPoints );
			break;
		case ast::stmt::OutputLayout::eLineStrip:
			m_result.registerExecutionMode( spv::ExecutionModeOutputLineStrip );
			break;
		case ast::stmt::OutputLayout::eTriangleStrip:
			m_result.registerExecutionMode( spv::ExecutionModeOutputTriangleStrip );
			break;
		default:
			assert( false && "Unsupported OutputLayout" );
			break;
		}
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
			auto kind = stmt->getExpr()->getType()->getKind();
			auto result = ExprVisitor::submit( stmt->getExpr()
				, m_currentBlock
				, m_result );
			interruptBlock( m_currentBlock
				, makeInstruction< ReturnValueInstruction >( result )
				, true );
		}
		else
		{
			interruptBlock( m_currentBlock
				, makeInstruction< ReturnInstruction >()
				, true );
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
		ExprVisitor::submit( stmt->getExpr(), m_currentBlock, m_result );
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

		auto selector = ExprVisitor::submit( stmt->getTestExpr()->getValue(), m_currentBlock, m_result );
		m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( mergeBlock.label, 0u ) );
		m_currentBlock.blockEnd = makeInstruction< SwitchInstruction >( IdList{ selector, defaultBlock.label }, caseBlocksIds );
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
		auto id = visitVariable( stmt->getVariable() );
	}

	void StmtVisitor::visitWhileStmt( ast::stmt::While * stmt )
	{
		auto loopBlock = m_result.newBlock();
		auto ifBlock = m_result.newBlock();
		auto continueBlock = m_result.newBlock();
		auto mergeBlock = m_result.newBlock();
		m_controlBlocks.push_back( { mergeBlock.label, continueBlock.label } );

		// End current block, to branch to the loop header block.
		endBlock( m_currentBlock, loopBlock.label );

		// The current block becomes the loop content block.
		m_currentBlock = m_result.newBlock();

		// The loop header block, to which continue target will branch, branches to the if block.
		auto loopBlockLabel = loopBlock.label;
		loopBlock.instructions.emplace_back( makeInstruction< LoopMergeInstruction >( makeOperands( mergeBlock.label, continueBlock.label, 0u ) ) );
		endBlock( loopBlock, ifBlock.label );

		// The if block, branches to either loop content block (true) or loop merge block (false).
		auto intermediateIfId = ExprVisitor::submit( stmt->getCtrlExpr(), ifBlock, m_result );
		endBlock( ifBlock, intermediateIfId, m_currentBlock.label, mergeBlock.label );

		// Instructions go to loop content block.
		visitContainerStmt( stmt );

		// Branch current block to the continue target block.
		endBlock( m_currentBlock, continueBlock.label );

		// The continue target block, branches back to loop header.
		endBlock( continueBlock, loopBlockLabel );

		// Current block becomes the merge block.
		m_controlBlocks.pop_back();
		m_currentBlock = std::move( mergeBlock );
	}

	void StmtVisitor::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		assert( false && "Unexpected PreprocDefine statement." );
	}

	void StmtVisitor::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		assert( false && "Unexpected PreprocElif statement." );
	}

	void StmtVisitor::visitPreprocElse( ast::stmt::PreprocElse * preproc )
	{
		assert( false && "Unexpected PreprocElse statement." );
	}

	void StmtVisitor::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
		assert( false && "Unexpected PreprocEndif statement." );
	}

	void StmtVisitor::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
		m_result.registerExtension( preproc->getName() );
	}

	void StmtVisitor::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
		assert( false && "Unexpected PreprocIf statement." );
	}

	void StmtVisitor::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		assert( false && "Unexpected PreprocIfDef statement." );
	}

	void StmtVisitor::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
		//TODO m_result->addStmt( ast::stmt::makePreprocVersion( preproc->getName() ) );
	}

	spv::Id StmtVisitor::visitVariable( ast::var::VariablePtr var )
	{
		spv::Id result;
		VariableInfo info;

		if ( var->isMember() )
		{
			auto outer = m_result.registerVariable( var->getOuter()->getName()
				, getStorageClass( var )
				, var->getOuter()->getType()
				, info ).id;
			result = m_result.registerMemberVariable( outer
				, var->getName()
				, var->getType() );
		}
		else
		{
			result = m_result.registerVariable( var->getName()
				, getStorageClass( var )
				, var->getType()
				, info ).id;
		}

		return result;
	}
}
