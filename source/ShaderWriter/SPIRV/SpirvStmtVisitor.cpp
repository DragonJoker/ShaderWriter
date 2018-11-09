/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvStmtVisitor.hpp"

#include "ShaderWriter/SPIRV/SpirvExprVisitor.hpp"
#include "ShaderWriter/SPIRV/SpirvHelpers.hpp"

#include <sstream>

namespace sdw::spirv
{
	namespace
	{
		int64_t getInt64Value( expr::Literal const & lit )
		{
			int64_t result{};

			switch ( lit.getLiteralType() )
			{
			case expr::LiteralType::eBool:
				result = int64_t( lit.getValue< expr::LiteralType::eBool >() );
				break;
			case expr::LiteralType::eInt:
				result = int64_t( lit.getValue< expr::LiteralType::eInt >() );
				break;
			case expr::LiteralType::eUInt:
				result = int64_t( lit.getValue< expr::LiteralType::eUInt >() );
				break;
			}

			return result;
		}
	}

	Module StmtVisitor::submit( stmt::Stmt * stmt
		, ShaderType type )
	{
		Module result{ getMemoryModel()
			, getExecutionModel( type ) };
		StmtVisitor vis{ result, type };
		stmt->accept( &vis );
		// Increment total ID count.
		++result.header[3];
		return result;
	}

	StmtVisitor::StmtVisitor( Module & result
		, ShaderType type )
		: m_result{ result }
	{
	}

	void StmtVisitor::visitContainerStmt( stmt::Container * stmt )
	{
		for ( auto & stmt : *stmt )
		{
			stmt->accept( this );
		}
	}

	void StmtVisitor::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
		m_result.bindBufferVariable( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, spv::Decoration::Block );
	}

	void StmtVisitor::visitDiscardStmt( stmt::Discard * stmt )
	{
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpKill, {} );
		m_function->cfg.blocks.emplace_back( std::move( m_currentBlock ) );
		m_currentBlock = m_result.newBlock();
	}

	void StmtVisitor::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitCommentStmt( stmt::Comment * stmt )
	{
	}

	void StmtVisitor::visitCompoundStmt( stmt::Compound * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		auto loopBlock = m_result.newBlock();
		auto ifBlock = m_result.newBlock();
		auto mergeBlock = m_result.newBlock();
		auto contentBlock = m_result.newBlock();

		// End current block, to branch to the loop header block.
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ loopBlock.label } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		// The loop header block, to which continue target will branch, branches to the loop content block.
		loopBlock.instructions.emplace_back( makeInstruction( spv::Op::OpLoopMerge, { mergeBlock.label, ifBlock.label } ) );
		loopBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ contentBlock.label } );
		m_function->cfg.blocks.push_back( loopBlock );

		// The current block becomes the loop content block.
		m_currentBlock = contentBlock;

		// Instructions go to loop content block.
		visitContainerStmt( stmt );

		// Branch current block to the continue target block.
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ ifBlock.label } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		// The if block, branches either back to the loop header block (true) or to the loop merge block (false).
		auto intermediateIfId = ExprVisitor::submit( stmt->getCtrlExpr(), ifBlock, m_result );
		ifBlock.blockEnd = makeInstruction( spv::Op::OpBranchConditional, { intermediateIfId, loopBlock.label, mergeBlock.label } );
		m_function->cfg.blocks.push_back( ifBlock );

		// Current block becomes the merge block.
		m_currentBlock = mergeBlock;
	}

	void StmtVisitor::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		assert( false && "Unexpected ElseIf statement." );
	}

	void StmtVisitor::visitElseStmt( stmt::Else * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitForStmt( stmt::For * stmt )
	{
		auto loopBlock = m_result.newBlock();
		auto ifBlock = m_result.newBlock();
		auto continueBlock = m_result.newBlock();
		auto mergeBlock = m_result.newBlock();

		// End current block, to branch to the loop header block.
		auto intermediateInitId = ExprVisitor::submit( stmt->getInitExpr(), m_currentBlock, m_result );
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ loopBlock.label } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		// The current block becomes the loop content block.
		m_currentBlock = m_result.newBlock();

		// The loop header block, to which continue target will branch, branches to the if block.
		loopBlock.instructions.emplace_back( makeInstruction( spv::Op::OpLoopMerge, { mergeBlock.label, continueBlock.label } ) );
		loopBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ ifBlock.label } );
		m_function->cfg.blocks.push_back( loopBlock );

		// The if block, branches to either loop content block (true) or loop merge block (false).
		auto intermediateIfId = ExprVisitor::submit( stmt->getCtrlExpr(), ifBlock, m_result );
		ifBlock.blockEnd = makeInstruction( spv::Op::OpBranchConditional, { intermediateIfId, m_currentBlock.label, mergeBlock.label } );
		m_function->cfg.blocks.push_back( ifBlock );

		// Instructions go to loop content block.
		visitContainerStmt( stmt );

		// Branch current block to the continue target block.
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ continueBlock.label } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		// The continue target block, branches back to loop header.
		auto intermediateIncrId = ExprVisitor::submit( stmt->getIncrExpr(), continueBlock, m_result );
		continueBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ loopBlock.label } );
		m_function->cfg.blocks.push_back( continueBlock );

		// Current block becomes the merge block.
		m_currentBlock = mergeBlock;
	}

	void StmtVisitor::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		auto retType = m_result.registerType( stmt->getRet() );
		m_function = m_result.beginFunction( stmt->getName()
			, retType
			, stmt->getParameters() );
		m_currentBlock = m_result.newBlock();

		if ( stmt->getName() == "main" )
		{
			m_result.registerEntryPoint( m_function->declaration.front().resultId.value()
				, stmt->getName()
				, m_inputs
				, m_outputs );
		}

		visitContainerStmt( stmt );

		if ( !m_function->hasReturn )
		{
			m_currentBlock.instructions.push_back( makeInstruction( spv::Op::OpReturn ) );
		}

		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpFunctionEnd );
		m_function->cfg.blocks.push_back( m_currentBlock );
		m_result.endFunction();
		m_function = nullptr;
	}

	void StmtVisitor::visitIfStmt( stmt::If * stmt )
	{
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
		m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpSelectionMerge, IdList{ mergeBlock.label } ) );
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranchConditional, { intermediateIfId, contentBlock.label, falseBlockLabel } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		// The current block becomes the if content block.
		m_currentBlock = contentBlock;
		visitContainerStmt( stmt );
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ mergeBlock.label } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		if ( stmt->getElse() )
		{
			m_currentBlock = elseBlock;
			stmt->getElse()->accept( this );
			m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ mergeBlock.label } );
			m_function->cfg.blocks.push_back( m_currentBlock );
		}

		// Current block becomes the merge block.
		m_currentBlock = mergeBlock;
	}

	void StmtVisitor::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		m_result.bindVariable( visitVariable( stmt->getVariable() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
	}

	void StmtVisitor::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		auto varId = visitVariable( var );

		if ( var->isShaderConstant() )
		{
			m_result.decorate( varId, { spv::Id( spv::Decoration::SpecId ), stmt->getLocation() } );
		}
		else
		{
			m_result.decorate( varId, { spv::Id( spv::Decoration::Location ), stmt->getLocation() } );

			if ( stmt->getVariable()->isShaderInput() )
			{
				m_inputs.push_back( varId );
			}

			if ( stmt->getVariable()->isShaderOutput() )
			{
				m_outputs.push_back( varId );
			}
		}
	}

	void StmtVisitor::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		m_result.registerExecutionMode( spv::ExecutionMode::LocalSize
			, { stmt->getWorkGroupsX(), stmt->getWorkGroupsY(), stmt->getWorkGroupsZ() } );
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		auto layout = stmt->getLayout();

		switch ( layout )
		{
		case stmt::InputLayout::ePointList:
			m_result.registerExecutionMode( spv::ExecutionMode::InputPoints );
			break;
		case stmt::InputLayout::eLineList:
		case stmt::InputLayout::eLineStrip:
			m_result.registerExecutionMode( spv::ExecutionMode::InputLines );
			break;
		case stmt::InputLayout::eTriangleList:
		case stmt::InputLayout::eTriangleStrip:
		case stmt::InputLayout::eTriangleFan:
			m_result.registerExecutionMode( spv::ExecutionMode::Triangles );
			break;
		case stmt::InputLayout::eTriangleListWithAdjacency:
		case stmt::InputLayout::eTriangleStripWithAdjacency:
			m_result.registerExecutionMode( spv::ExecutionMode::InputTrianglesAdjacency );
			break;
		case stmt::InputLayout::eLineListWithAdjacency:
		case stmt::InputLayout::eLineStripWithAdjacency:
			m_result.registerExecutionMode( spv::ExecutionMode::InputLinesAdjacency );
			break;
		default:
			assert( false && "Unsupported InputLayout" );
			break;
		}
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		auto layout = stmt->getLayout();

		switch ( layout )
		{
		case stmt::OutputLayout::ePointList:
			m_result.registerExecutionMode( spv::ExecutionMode::OutputPoints );
			break;
		case stmt::OutputLayout::eLineStrip:
			m_result.registerExecutionMode( spv::ExecutionMode::OutputLineStrip );
			break;
		case stmt::OutputLayout::eTriangleStrip:
			m_result.registerExecutionMode( spv::ExecutionMode::OutputTriangleStrip );
			break;
		default:
			assert( false && "Unsupported OutputLayout" );
			break;
		}
	}

	void StmtVisitor::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		//m_result->addStmt( stmt::makePerVertexDecl( stmt->getSource()
		//	, stmt->getType() ) );
	}

	void StmtVisitor::visitReturnStmt( stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			auto result = ExprVisitor::submit( stmt->getExpr(), m_currentBlock, m_result );
			m_currentBlock.instructions.push_back( makeInstruction( spv::Op::OpReturnValue, { result } ) );
		}
		else
		{
			m_currentBlock.instructions.push_back( makeInstruction( spv::Op::OpReturn, {} ) );
		}

		m_function->hasReturn = true;
	}

	void StmtVisitor::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		m_result.bindVariable( visitVariable( stmt->getVariable() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
	}

	void StmtVisitor::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		m_result.bindVariable( visitVariable( stmt->getVariable() )
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
	}

	void StmtVisitor::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
		m_result.bindBufferVariable( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, spv::Decoration::BufferBlock );
	}

	void StmtVisitor::visitSimpleStmt( stmt::Simple * stmt )
	{
		ExprVisitor::submit( stmt->getExpr(), m_currentBlock, m_result );
	}

	void StmtVisitor::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		m_result.registerType( stmt->getType() );
	}

	void StmtVisitor::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitSwitchStmt( stmt::Switch * stmt )
	{
		std::map< expr::Literal *, Block > caseBlocks;
		std::map< int64_t, spv::Id > caseBlocksIds;
		Block defaultBlock;
		spv::Id defaultId{};

		for ( auto & it : *stmt )
		{
			auto & caseStmt = static_cast< stmt::SwitchCase const & >( *it );

			if ( caseStmt.getCaseExpr() )
			{
				auto block = m_result.newBlock();
				caseBlocksIds.emplace( getInt64Value( caseStmt.getCaseExpr()->getLabel() ), block.label );
				caseBlocks.emplace( caseStmt.getCaseExpr()->getLabel(), std::move( block ) );
			}
			else
			{
				// Default
				defaultBlock = m_result.newBlock();
				defaultId = defaultBlock.label;
			}
		}

		auto intermediate = ExprVisitor::submit( stmt->getTestExpr()->getValue(), m_currentBlock, m_result );
		m_currentBlock.blockEnd = makeSwitch( intermediate, defaultId, caseBlocksIds );

		visitContainerStmt( stmt );
	}

	void StmtVisitor::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		auto id = visitVariable( stmt->getVariable() );
	}

	void StmtVisitor::visitWhileStmt( stmt::While * stmt )
	{
		auto loopBlock = m_result.newBlock();
		auto ifBlock = m_result.newBlock();
		auto continueBlock = m_result.newBlock();
		auto mergeBlock = m_result.newBlock();

		// End current block, to branch to the loop header block.
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ loopBlock.label } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		// The current block becomes the loop content block.
		m_currentBlock = m_result.newBlock();

		// The loop header block, to which continue target will branch, branches to the if block.
		loopBlock.instructions.emplace_back( makeInstruction( spv::Op::OpLoopMerge, { mergeBlock.label, continueBlock.label } ) );
		loopBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ ifBlock.label } );
		m_function->cfg.blocks.push_back( loopBlock );

		// The if block, branches to either loop content block (true) or loop merge block (false).
		auto intermediateIfId = ExprVisitor::submit( stmt->getCtrlExpr(), ifBlock, m_result );
		ifBlock.blockEnd = makeInstruction( spv::Op::OpBranchConditional, { intermediateIfId, m_currentBlock.label, mergeBlock.label } );
		m_function->cfg.blocks.push_back( ifBlock );

		// Instructions go to loop content block.
		visitContainerStmt( stmt );

		// Branch current block to the continue target block.
		m_currentBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ continueBlock.label } );
		m_function->cfg.blocks.push_back( m_currentBlock );

		// The continue target block, branches back to loop header.
		continueBlock.blockEnd = makeInstruction( spv::Op::OpBranch, IdList{ loopBlock.label } );
		m_function->cfg.blocks.push_back( continueBlock );

		// Current block becomes the merge block.
		m_currentBlock = mergeBlock;
	}

	void StmtVisitor::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		assert( false && "Unexpected PreprocDefine statement." );
	}

	void StmtVisitor::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		assert( false && "Unexpected PreprocElif statement." );
	}

	void StmtVisitor::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		assert( false && "Unexpected PreprocElse statement." );
	}

	void StmtVisitor::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
		assert( false && "Unexpected PreprocEndif statement." );
	}

	void StmtVisitor::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		m_result.registerExtension( preproc->getName() );
	}

	void StmtVisitor::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		assert( false && "Unexpected PreprocIf statement." );
	}

	void StmtVisitor::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		assert( false && "Unexpected PreprocIfDef statement." );
	}

	void StmtVisitor::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		//TODO m_result->addStmt( stmt::makePreprocVersion( preproc->getName() ) );
	}

	spv::Id StmtVisitor::visitVariable( var::VariablePtr var )
	{
		spv::Id result;

		if ( var->isMember() )
		{
			auto outer = m_result.registerVariable( var->getOuter()->getName()
				, getStorageClass( getOutermost( var ) )
				, var->getOuter()->getType() );
			result = m_result.registerMemberVariable( outer
				, var->getName()
				, var->getType() );
		}
		else
		{
			result = m_result.registerVariable( var->getName()
				, getStorageClass( getOutermost( var ) )
				, var->getType() );
		}

		return result;
	}
}
