/*
See LICENSE file in root folder
*/
#include "SpirvExprVisitor.hpp"

#include "SpirvHelpers.hpp"
#include "SpirvGetSwizzleComponents.hpp"
#include "SpirvImageAccessConfig.hpp"
#include "SpirvImageAccessNames.hpp"
#include "SpirvIntrinsicConfig.hpp"
#include "SpirvIntrinsicNames.hpp"
#include "SpirvMakeAccessChain.hpp"
#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>
#include <ShaderAST/Visitors/GetOutermostExpr.hpp>

#include <algorithm>
#include <numeric>
#include <sstream>
#include <stdexcept>

namespace spirv
{
	namespace
	{
		class HasFnCall
			: public ast::expr::SimpleVisitor
		{
		public:
			static bool submit( ast::expr::Expr * expr )
			{
				bool result{ false };
				HasFnCall vis{ result };
				expr->accept( &vis );
				return result;
			}

		private:
			HasFnCall( bool & result )
				: m_result{ result }
			{
			}

		private:
			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				expr->getOperand()->accept( this );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				expr->getLHS()->accept( this );
				expr->getRHS()->accept( this );
			}

			void visitAggrInitExpr( ast::expr::AggrInit * expr )override
			{
				if ( expr->getIdentifier() )
				{
					expr->getIdentifier()->accept( this );
				}

				for ( auto & arg : expr->getInitialisers() )
				{
					arg->accept( this );
				}
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				expr->getOuterExpr()->accept( this );
			}

			void visitFnCallExpr( ast::expr::FnCall * expr )override
			{
				expr->getFn()->accept( this );

				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}

				m_result = true;
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
			{
				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}

				m_result = true;
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override
			{
				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}

				m_result = true;
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override
			{
				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}

				m_result = true;
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
			}

			void visitInitExpr( ast::expr::Init * expr )override
			{
				expr->getIdentifier()->accept( this );
				expr->getInitialiser()->accept( this );
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
			}

			void visitQuestionExpr( ast::expr::Question * expr )override
			{
				expr->getCtrlExpr()->accept( this );
				expr->getTrueExpr()->accept( this );
				expr->getFalseExpr()->accept( this );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
			{
				expr->getLabel()->accept( this );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
			{
				expr->getValue()->accept( this );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				expr->getOuterExpr()->accept( this );
			}

		private:
			bool & m_result;
		};

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

		spv::Id loadVariable( spv::Id varId
			, ast::type::TypePtr type
			, Module & module
			, Block & currentBlock
			, LoadedVariableArray & loadedVariables )
		{
			auto it = std::find_if( loadedVariables.begin()
				, loadedVariables.end()
				, [varId]( LoadedVariable const & lookup )
				{
					return lookup.varId == varId;
				} );

			if ( loadedVariables.end() == it )
			{
				auto loadedRhsId = module.loadVariable( varId
					, type
					, currentBlock );
				loadedVariables.push_back( { varId, loadedRhsId } );
				it = loadedVariables.begin() + loadedVariables.size() - 1u;
			}

			return it->loadedId;
		}

		inline spv::Op getCastOp( ast::type::Kind src, ast::type::Kind dst )
		{
			spv::Op result = spv::OpNop;

			if ( isDoubleType( src ) )
			{
				if ( isFloatType( dst ) || isHalfType( dst ) )
				{
					result = spv::OpFConvert;
				}
				else if ( isSignedIntType( dst ) )
				{
					result = spv::OpConvertFToS;
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::OpConvertFToU;
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else if ( isFloatType( src ) )
			{
				if ( isDoubleType( dst ) || isHalfType( dst ) )
				{
					result = spv::OpFConvert;
				}
				else if ( isSignedIntType( dst ) )
				{
					result = spv::OpConvertFToS;
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::OpConvertFToU;
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else if ( isHalfType( src ) )
			{
				if ( isDoubleType( dst ) || isFloatType( dst ) )
				{
					result = spv::OpFConvert;
				}
				else if ( isSignedIntType( dst ) )
				{
					result = spv::OpConvertFToS;
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::OpConvertFToU;
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else if ( isSignedIntType( src ) )
			{
				if ( isDoubleType( dst )
					|| isFloatType( dst ) )
				{
					result = spv::OpConvertSToF;
				}
				else if ( isSignedIntType( dst ) )
				{
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::OpBitcast;
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else if ( isUnsignedIntType( src ) )
			{
				if ( isDoubleType( dst )
					|| isFloatType( dst ) )
				{
					result = spv::OpConvertUToF;
				}
				else if ( isSignedIntType( dst ) )
				{
					result = spv::OpBitcast;
				}
				else if ( isUnsignedIntType( dst ) )
				{
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else
			{
				assert( false && "Unsupported cast expression" );
			}

			return result;
		}
	}

	spv::StorageClass getStorageClass( ast::var::VariablePtr var )
	{
		var = getOutermost( var );
		spv::StorageClass result = spv::StorageClassFunction;

		if ( var->isLocale() )
		{
			result = spv::StorageClassFunction;
		}
		if ( var->isUniform() )
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
				assert( false && "Unsupported built-in variable storage." );
			}
		}
		else if ( var->isShaderInput() )
		{
			result = spv::StorageClassInput;
		}
		else if ( var->isShaderOutput() )
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
		else if ( var->isStatic() && var->isConstant() )
		{
			result = spv::StorageClassPrivate;
		}

		return result;
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool loadVariable )
	{
		bool allLiterals{ false };
		LoadedVariableArray loadedVariables;
		return submit( expr
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables );
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		bool allLiterals{ false };
		return submit( expr
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables );
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, spv::Id initialiser
		, bool hasFuncInit
		, LoadedVariableArray & loadedVariables )
	{
		bool allLiterals{ false };
		return submit( expr
			, currentBlock
			, module
			, allLiterals
			, initialiser
			, hasFuncInit
			, loadedVariables );
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool loadVariable )
	{
		LoadedVariableArray loadedVariables;
		return submit( expr
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables );
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		spv::Id result{ 0u };
		ExprVisitor vis{ result
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables };
		expr->accept( &vis );
		return result;
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, spv::Id initialiser
		, bool hasFuncInit
		, LoadedVariableArray & loadedVariables )
	{
		spv::Id result{ 0u };
		ExprVisitor vis{ result
			, currentBlock
			, module
			, allLiterals
			, initialiser
			, hasFuncInit
			, loadedVariables };
		expr->accept( &vis );
		return result;
	}

	ExprVisitor::ExprVisitor( spv::Id & result
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
		: m_result{ result }
		, m_currentBlock{ currentBlock }
		, m_module{ module }
		, m_allLiterals{ allLiterals }
		, m_loadVariable{ loadVariable }
		, m_initialiser{ 0u }
		, m_hasFuncInit{ false }
		, m_loadedVariables{ loadedVariables }
	{
	}

	ExprVisitor::ExprVisitor( spv::Id & result
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, spv::Id initialiser
		, bool hasFuncInit
		, LoadedVariableArray & loadedVariables )
		: m_result{ result }
		, m_currentBlock{ currentBlock }
		, m_module{ module }
		, m_allLiterals{ allLiterals }
		, m_loadVariable{ false }
		, m_initialiser{ initialiser }
		, m_hasFuncInit{ hasFuncInit }
		, m_loadedVariables{ loadedVariables }
	{
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr )
	{
		return submit( expr, m_currentBlock, m_module, m_loadVariable, m_loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, LoadedVariableArray & loadedVariables )
	{
		return submit( expr, m_currentBlock, m_module, m_loadVariable, loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool loadVariable )
	{
		return submit( expr, m_currentBlock, m_module, loadVariable, m_loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, spv::Id initialiser
		, bool hasFuncInit )
	{
		return submit( expr, m_currentBlock, m_module, initialiser, hasFuncInit, m_loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		return submit( expr, m_currentBlock, m_module, loadVariable, loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool & allLiterals
		, bool loadVariable )
	{
		return submit( expr, m_currentBlock, m_module, allLiterals, loadVariable, m_loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool & allLiterals
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		return submit( expr, m_currentBlock, m_module, allLiterals, loadVariable, loadedVariables );
	}

	void ExprVisitor::visitAssignmentExpr( ast::expr::Assign * expr )
	{
		m_allLiterals = false;

		if ( expr->getLHS()->getKind() == ast::expr::Kind::eSwizzle )
		{
			// For LHS swizzle, the variable must first be loaded,
			// then it must be shuffled with the RHS, to compute the final result.
			auto & lhsSwizzle = static_cast< ast::expr::Swizzle const & >( *expr->getLHS() );
			auto lhsSwizzleKind = lhsSwizzle.getSwizzle();

			// Process the RHS first, asking for the needed variables to be loaded.
			auto rhsId = doSubmit( expr->getRHS(), true, m_loadedVariables );

			auto lhsOuter = lhsSwizzle.getOuterExpr();
			assert( lhsOuter->getKind() == ast::expr::Kind::eIdentifier
				|| isAccessChain( lhsOuter ) );

			if ( lhsSwizzleKind.isOneComponent() )
			{
				// One component swizzles must be processed separately:
				// - Create an access chain to the selected component.
				//   No load to retrieve the variable ID.
				auto lhsId = getVariableIdNoLoad( lhsOuter );
				//   Register component selection as a literal.
				auto componentId = m_module.registerLiteral( lhsSwizzleKind.toIndex() );
				//   Register pointer type.
				auto typeId = m_module.registerType( lhsSwizzle.getType() );
				//   Retrieve outermost identifier, to be able to retrieve its variable's storage class.
				auto lhsOutermost = ast::getOutermostExpr( lhsOuter );
				assert( lhsOutermost->getKind() == ast::expr::Kind::eIdentifier );
				auto pointerTypeId = m_module.registerPointerType( typeId
					, getStorageClass( static_cast< ast::expr::Identifier const & >( *lhsOutermost ).getVariable() ) );
				//   Create the access chain.
				auto intermediateId = m_module.getIntermediateResult();
				m_currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( pointerTypeId
					, intermediateId
					, IdList{ lhsId, componentId } ) );
				// - Store the RHS into this access chain.
				m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( intermediateId, rhsId ) );
				m_result = intermediateId;
			}
			else
			{
				// - No load to retrieve the variable ID.
				auto lhsId = getVariableIdNoLoad( lhsOuter );
				// - Load the variable manually.
				auto loadedLhsId = loadVariable( lhsId
					, lhsOuter->getType() );
				// - The resulting shuffle indices will contain the RHS values for wanted LHS components,
				//   and LHS values for the remaining ones.
				auto typeId = m_module.registerType( lhsOuter->getType() );
				auto intermediateId = m_module.getIntermediateResult();
				IdList shuffle;
				shuffle.emplace_back( loadedLhsId );
				shuffle.emplace_back( rhsId );
				ast::expr::SwizzleKind rhsSwizzleKind;

				if ( expr->getRHS()->getKind() == ast::expr::Kind::eSwizzle
					&& static_cast< ast::expr::Swizzle const & >( *expr->getRHS() ).getOuterExpr()->getKind() != ast::expr::Kind::eIntrinsicCall
					&& static_cast< ast::expr::Swizzle const & >( *expr->getRHS() ).getOuterExpr()->getKind() != ast::expr::Kind::eTextureAccessCall
					&& static_cast< ast::expr::Swizzle const & >( *expr->getRHS() ).getOuterExpr()->getKind() != ast::expr::Kind::eImageAccessCall )
				{
					rhsSwizzleKind = static_cast< ast::expr::Swizzle const & >( *expr->getRHS() ).getSwizzle();
				}
				else
				{
					auto rhsCount = getComponentCount( expr->getRHS()->getType()->getKind() );
					assert( rhsCount >= 2u && rhsCount <= 4u );

					switch ( rhsCount )
					{
					case 2u:
						rhsSwizzleKind = ast::expr::SwizzleKind::e01;
						break;
					case 3u:
						rhsSwizzleKind = ast::expr::SwizzleKind::e012;
						break;
					default:
						rhsSwizzleKind = ast::expr::SwizzleKind::e0123;
						break;
					}
				}

				auto swizzleComponents = getSwizzleComponents( lhsSwizzleKind
					, rhsSwizzleKind
					, getComponentCount( lhsOuter->getType()->getKind() ) );
				shuffle.insert( shuffle.end()
					, swizzleComponents.begin()
					, swizzleComponents.end() );
				m_currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( typeId
					, intermediateId
					, shuffle ) );
				m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( lhsId, intermediateId ) );
				m_result = lhsId;
			}
		}
		else
		{
			// No load to retrieve the variable ID.
			auto lhsId = getVariableIdNoLoad( expr->getLHS() );
			// Ask for the needed variables to be loaded.
			auto rhsId = doSubmit( expr->getRHS(), true, m_loadedVariables );
			m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( lhsId, rhsId ) );
			m_result = lhsId;
		}
	}

	void ExprVisitor::visitOpAssignmentExpr( ast::expr::Assign * expr )
	{
		m_allLiterals = false;
		auto typeId = m_module.registerType( expr->getType() );
		// No load to retrieve the variable ID.
		auto lhsId = getVariableIdNoLoad( expr->getLHS() );
		// Load the variable manually.
		auto loadedLhsId = loadVariable( lhsId
			, expr->getType() );
		// Ask for the needed variables to be loaded.
		auto rhsId = doSubmit( expr->getRHS()
			, true );
		auto intermediateId = writeBinOpExpr( expr->getKind()
			, expr->getLHS()->getType()->getKind()
			, expr->getRHS()->getType()->getKind()
			, typeId
			, loadedLhsId
			, rhsId
			, expr->getLHS()->isSpecialisationConstant() );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( lhsId, intermediateId ) );
		m_module.putIntermediateResult( intermediateId );
		m_module.putIntermediateResult( loadedLhsId );
		m_result = lhsId;
	}

	void ExprVisitor::visitUnaryExpr( ast::expr::Unary * expr )
	{
		m_allLiterals = false;
		auto operandId = doSubmit( expr->getOperand() );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();

		if ( expr->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( typeId
				, m_result
				, makeOperands( spv::Id( getUnOpCode( expr->getKind(), expr->getType()->getKind() ) )
					, operandId ) ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeUnInstruction( typeId
				, m_result
				, expr->getKind()
				, expr->getType()->getKind()
				, operandId ) );
		}
	}

	void ExprVisitor::visitBinaryExpr( ast::expr::Binary * expr )
	{
		m_allLiterals = false;
		auto lhsId = doSubmit( expr->getLHS() );
		auto loadedLhsId = lhsId;
		auto rhsId = doSubmit( expr->getRHS() );
		auto loadedRhsId = rhsId;
		auto typeId = m_module.registerType( expr->getType() );
		m_result = writeBinOpExpr( expr->getKind()
			, expr->getLHS()->getType()->getKind()
			, expr->getRHS()->getType()->getKind()
			, typeId
			, loadedLhsId
			, loadedRhsId
			, expr->isSpecialisationConstant() );
	}

	void ExprVisitor::visitCastExpr( ast::expr::Cast * expr )
	{
		m_allLiterals = false;
		auto operandId = doSubmit( expr->getOperand() );
		auto dstTypeId = m_module.registerType( expr->getType() );
		auto op = getCastOp( expr->getOperand()->getType()->getKind()
			, expr->getType()->getKind() );

		if ( op == spv::OpNop )
		{
			m_result = operandId;
		}
		else
		{
			m_result = m_module.getIntermediateResult();

			if ( expr->isSpecialisationConstant() )
			{
				m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( dstTypeId
					, m_result
					, makeOperands( spv::Id( op )
						, operandId ) ) );
			}
			else
			{
				m_currentBlock.instructions.emplace_back( makeCastInstruction( dstTypeId
					, m_result
					, op
					, operandId ) );
			}
		}
	}

	void ExprVisitor::visitPreDecrementExpr( ast::expr::PreDecrement * expr )
	{
		m_allLiterals = false;
		auto literal = m_module.registerLiteral( 1 );
		auto operandId = doSubmit( expr->getOperand(), true );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eMinus
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal ) );
		operandId = m_module.getNonIntermediate( operandId );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( operandId, m_result ) );
	}

	void ExprVisitor::visitPreIncrementExpr( ast::expr::PreIncrement * expr )
	{
		m_allLiterals = false;
		auto literal = m_module.registerLiteral( 1 );
		auto operandId = doSubmit( expr->getOperand(), true );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal ) );
		operandId = m_module.getNonIntermediate( operandId );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( operandId, m_result ) );
	}

	void ExprVisitor::visitPostDecrementExpr( ast::expr::PostDecrement * expr )
	{
		m_allLiterals = false;
		auto literal1 = m_module.registerLiteral( 1 );
		auto literal0 = m_module.registerLiteral( 0 );
		// No load to retrieve the variable ID.
		auto originId = getVariableIdNoLoad( expr->getOperand() );
		// Load the variable manually.
		auto operandId = loadVariable( originId
			, expr->getType() );

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal0 ) );
		auto operand2 = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, operand2
			, ast::expr::Kind::eMinus
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal1 ) );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( originId, operand2 ) );
	}

	void ExprVisitor::visitPostIncrementExpr( ast::expr::PostIncrement * expr )
	{
		m_allLiterals = false;
		auto literal1 = m_module.registerLiteral( 1 );
		auto literal0 = m_module.registerLiteral( 0 );
		// No load to retrieve the variable ID.
		auto originId = getVariableIdNoLoad( expr->getOperand() );
		// Load the variable manually.
		auto operandId = loadVariable( originId
			, expr->getType() );

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal0 ) );
		auto operand2 = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, operand2
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal1 ) );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( originId, operand2 ) );
	}

	void ExprVisitor::visitUnaryPlusExpr( ast::expr::UnaryPlus * expr )
	{
		m_result = doSubmit( expr->getOperand() );
	}

	void ExprVisitor::visitAddAssignExpr( ast::expr::AddAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAndAssignExpr( ast::expr::AndAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAssignExpr( ast::expr::Assign * expr )
	{
		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitDivideAssignExpr( ast::expr::DivideAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitMinusAssignExpr( ast::expr::MinusAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitModuloAssignExpr( ast::expr::ModuloAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitOrAssignExpr( ast::expr::OrAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitTimesAssignExpr( ast::expr::TimesAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitXorAssignExpr( ast::expr::XorAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		auto typeId = m_module.registerType( expr->getType() );
		IdList initialisers;
		bool allLiterals = true;
		bool hasFuncInit = false;

		for ( auto & init : expr->getInitialisers() )
		{
			initialisers.push_back( doSubmit( init.get(), allLiterals, true ) );
			hasFuncInit = hasFuncInit || HasFnCall::submit( init.get() );
		}

		spv::Id init;

		if ( allLiterals )
		{
			init = m_module.registerLiteral( initialisers, expr->getType() );
		}
		else
		{
			init = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( typeId
				, init
				, initialisers ) );
		}

		if ( expr->getIdentifier() )
		{
			initialiseVariable( init
				, allLiterals
				, hasFuncInit
				, expr->getIdentifier()->getVariable()
				, expr->getType() );
		}
		else
		{
			assert( allLiterals );
			m_result = init;
		}

		m_allLiterals = false;
	}

	void ExprVisitor::visitArrayAccessExpr( ast::expr::ArrayAccess * expr )
	{
		m_allLiterals = false;
		m_result = makeAccessChain( expr, m_module, m_currentBlock, m_loadedVariables );
		auto typeKind = expr->getType()->getKind();

		if ( m_loadVariable
			&& !isImageType( typeKind )
			&& !isSampledImageType( typeKind )
			&& !isSamplerType( typeKind ) )
		{
			auto result = loadVariable( m_result
				, expr->getType() );
			m_module.putIntermediateResult( m_result );
			m_result = result;
		}
	}

	void ExprVisitor::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		m_allLiterals = false;
		m_result = makeAccessChain( expr, m_module, m_currentBlock, m_loadedVariables );

		if ( m_loadVariable )
		{
			auto result = loadVariable( m_result
				, expr->getType() );
			m_module.putIntermediateResult( m_result );
			m_result = result;
		}
	}

	void ExprVisitor::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		IdList params;
		bool allLiterals = true;
		auto paramsCount = 0u;

		for ( auto & arg : expr->getArgList() )
		{
			bool allLitsInit = true;
			auto id = doSubmit( arg.get(), allLitsInit, m_loadVariable );
			params.push_back( id );
			allLiterals = allLiterals && allLitsInit;
			paramsCount += ast::type::getComponentCount( arg->getType()->getKind() );
		}

		auto retCount = ast::type::getComponentCount( expr->getType()->getKind() )
			* ast::type::getComponentCount( ast::type::getComponentType( expr->getType()->getKind() ) );
		auto typeId = m_module.registerType( expr->getType() );

		if ( paramsCount == 1u && retCount != 1u )
		{
			params.resize( retCount, params.back() );
			paramsCount = retCount;
		}

		if ( allLiterals )
		{
			assert( paramsCount == retCount );
			m_result = m_module.registerLiteral( params, expr->getType() );
		}
		else
		{
			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( typeId
				, m_result
				, params ) );
		}

		m_allLiterals = m_allLiterals && allLiterals;
	}

	void ExprVisitor::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		IdList params;
		bool allLiterals = true;
		auto type = expr->getFn()->getType();
		assert( type->getKind() == ast::type::Kind::eFunction );
		auto fnType = std::static_pointer_cast< ast::type::Function >( type );
		assert( expr->getArgList().size() == fnType->size() );
		auto it = fnType->begin();

		struct OutputParam
		{
			spv::Id src;
			spv::Id dst;
			ast::type::TypePtr type;
		};
		std::vector< OutputParam > outputParams;

		for ( auto & arg : expr->getArgList() )
		{
			// Function parameters are pointers, hence the variables must not be loaded.
			auto id = getVariableIdNoLoad( arg.get() );
			allLiterals = allLiterals
				&& ( arg->getKind() == ast::expr::Kind::eLiteral );
			auto argTypeKind = arg->getType()->getKind();
			auto ident = ast::findIdentifier( arg );

			if ( ident
				&& getStorageClass( ident->getVariable() ) != spv::StorageClassFunction
				&& !isImageType( argTypeKind )
				&& !isSampledImageType( argTypeKind )
				&& !isSamplerType( argTypeKind ) )
			{
				// We must have a variable with function storage class.
				// Hence we create a temporary variable with this storage class,
				// and load the original variable into it.
				auto srcId = id;
				id = makeFunctionAlias( srcId, arg->getType() );

				if ( ( *it )->isOutputParam() )
				{
					outputParams.emplace_back( OutputParam{ srcId, id, arg->getType() } );
				}
			}

			params.push_back( id );
			++it;
		}

		auto typeId = m_module.registerType( expr->getType() );
		auto fnId = doSubmit( expr->getFn() );
		params.insert( params.begin(), fnId );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< FunctionCallInstruction >( typeId
			, m_result
			, params ) );

		for ( auto param : outputParams )
		{
			auto loadedId = m_module.loadVariable( param.dst, param.type, m_currentBlock );
			m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( param.src, loadedId ) );
		}

		m_allLiterals = m_allLiterals && allLiterals;
	}

	void ExprVisitor::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		m_allLiterals = false;
		auto var = expr->getVariable();

		if ( var->isMember() )
		{
			m_result = makeAccessChain( expr
				, m_module
				, m_currentBlock
				, m_loadedVariables );

			if ( m_loadVariable )
			{
				auto result = loadVariable( m_result
					, expr->getType() );
				m_module.putIntermediateResult( m_result );
				m_result = result;
			}
		}
		else
		{
			initialiseVariable( m_initialiser
				, true
				, m_hasFuncInit
				, var
				, expr->getType() );
			auto kind = var->getType()->getKind();

			if ( m_loadVariable
				&& ( var->isLocale()
					|| var->isShaderInput()
					|| var->isShaderOutput()
					|| var->isParam()
					|| isSampledImageType( kind )
					|| isImageType( kind )
					|| isSamplerType( kind ) ) )
			{
				m_result = loadVariable( m_result
					, expr->getType() );
			}
		}
	}

	void ExprVisitor::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		m_allLiterals = false;
		auto isStore = expr->getImageAccess() >= ast::expr::ImageAccess::eImageStore1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageStore2DMSArrayU;
		auto paramType = expr->getArgList()[0]->getType();
		assert( paramType->getKind() == ast::type::Kind::eImage );
		auto imageVarId = doSubmit( expr->getArgList()[0].get(), false );
		auto imageType = std::static_pointer_cast< ast::type::Image >( paramType );
		auto intermediateId = loadVariable( imageVarId, imageType );
		IdList params;
		params.push_back( intermediateId );

		for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
		{
			auto & arg = ( *it );
			auto id = doSubmit( arg.get() );
			params.push_back( id );
		}

		if ( isStore && imageType->getConfig().isMS )
		{
			// MS images image store's parameters need a bit reworking
			// since in SPIR-V the sample parameter is an optional one
			// and as such it has to be at the end.
			auto data = params.back();
			params.pop_back();
			auto sample = params.back();
			params.pop_back();
			params.push_back( data );
			params.push_back( spv::ImageOperandsSampleMask );
			params.push_back( sample );
		}

		IntrinsicConfig config;
		getSpirVConfig( expr->getImageAccess(), config );
		auto op = getSpirVName( expr->getImageAccess() );

		if ( isStore )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< ImageStoreInstruction >( params ) );
		}
		else if ( !config.needsTexelPointer )
		{
			auto typeId = m_module.registerType( expr->getType() );
			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( typeId
				, m_result
				, op
				, params ) );
		}
		else
		{
			IdList texelPointerParams;
			uint32_t index = 0u;
			texelPointerParams.push_back( imageVarId );
			++index;
			texelPointerParams.push_back( params[index++] );

			if ( imageType->getConfig().isMS )
			{
				texelPointerParams.push_back( params[index++] );
			}
			else
			{
				texelPointerParams.push_back( m_module.registerLiteral( 0u ) );
			}

			assert( expr->getArgList()[0]->getKind() == ast::expr::Kind::eIdentifier );
			auto imgParam = static_cast< ast::expr::Identifier const & >( *expr->getArgList()[0] ).getType();
			assert( imgParam->getKind() == ast::type::Kind::eImage );
			auto image = std::static_pointer_cast< ast::type::Image >( imgParam );
			auto sampledId = m_module.registerType( m_module.getCache().getBasicType( image->getConfig().sampledType ) );
			auto pointerTypeId = m_module.registerPointerType( sampledId
				, spv::StorageClassImage );
			auto pointerId = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< ImageTexelPointerInstruction >( pointerTypeId
				, pointerId
				, texelPointerParams ) );

			auto scopeId = m_module.registerLiteral( uint32_t( spv::ScopeDevice ) );
			IdList accessParams;
			accessParams.push_back( pointerId );
			accessParams.push_back( scopeId );

			if ( op == spv::OpAtomicCompareExchange )
			{
				auto equalMemorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
				auto unequalMemorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
				accessParams.push_back( equalMemorySemanticsId );
				accessParams.push_back( unequalMemorySemanticsId );
			}
			else
			{
				auto memorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
				accessParams.push_back( memorySemanticsId );
			}

			if ( params.size() > index )
			{
				accessParams.insert( accessParams.end()
					, params.begin() + index
					, params.end() );
			}


			auto typeId = m_module.registerType( expr->getType() );
			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( typeId
				, m_result
				, op
				, accessParams ) );
			m_module.putIntermediateResult( pointerId );
		}
	}

	void ExprVisitor::visitInitExpr( ast::expr::Init * expr )
	{
		m_allLiterals = false;
		m_module.registerType( expr->getType() );
		bool allLiterals = true;
		auto init = doSubmit( expr->getInitialiser(), allLiterals, m_loadVariable );
		m_info.lvalue = true;
		bool hasFuncInit = HasFnCall::submit( expr );
		initialiseVariable( init
			, allLiterals
			, hasFuncInit
			, expr->getIdentifier()->getVariable()
			, expr->getType() );
	}

	void ExprVisitor::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		m_allLiterals = false;
		IntrinsicConfig config;
		getSpirVConfig( expr->getIntrinsic(), config );
		auto opCodeId = getSpirVName( expr->getIntrinsic() );

		if ( !config.isExtension )
		{
			auto opCode = spv::Op( opCodeId );

			if ( config.isAtomic )
			{
				handleAtomicIntrinsicCallExpr( opCode, expr );
			}
			else if ( opCode == spv::OpIAddCarry
				|| opCode == spv::OpISubBorrow )
			{
				handleCarryBorrowIntrinsicCallExpr( opCode, expr );
			}
			else if ( opCode == spv::OpUMulExtended
				|| opCode == spv::OpSMulExtended )
			{
				handleMulExtendedIntrinsicCallExpr( opCode, expr );
			}
			else
			{
				handleOtherIntrinsicCallExpr( opCode, expr );
			}
		}
		else
		{
			handleExtensionIntrinsicCallExpr( opCodeId, expr );
		}
	}

	void ExprVisitor::visitLiteralExpr( ast::expr::Literal * expr )
	{
		switch ( expr->getLiteralType() )
		{
		case ast::expr::LiteralType::eBool:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eBool >() );
			break;
		case ast::expr::LiteralType::eInt:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eInt >() );
			break;
		case ast::expr::LiteralType::eUInt:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt >() );
			break;
		case ast::expr::LiteralType::eFloat:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eFloat >() );
			break;
		case ast::expr::LiteralType::eDouble:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eDouble >() );
			break;
		default:
			assert( false && "Unsupported literal type" );
			break;
		}
	}

	void ExprVisitor::visitQuestionExpr( ast::expr::Question * expr )
	{
		m_allLiterals = false;
		auto ctrlId = doSubmit( expr->getCtrlExpr() );
		auto trueId = doSubmit( expr->getTrueExpr() );
		auto falseId = doSubmit( expr->getFalseExpr() );
		auto type = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		auto branches = makeOperands( ctrlId, trueId, falseId );

		if ( expr->getCtrlExpr()->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( type
				, m_result
				, makeOperands( spv::Id( spv::OpSelect ), branches ) ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SelectInstruction >( type
				, m_result
				, branches ) );
		}
	}

	void ExprVisitor::visitSwitchCaseExpr( ast::expr::SwitchCase * expr )
	{
		m_result = doSubmit( expr->getLabel() );
	}

	void ExprVisitor::visitSwitchTestExpr( ast::expr::SwitchTest * expr )
	{
		m_result = doSubmit( expr->getValue() );
	}

	void ExprVisitor::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		m_allLiterals = false;

		if ( expr->getSwizzle().isOneComponent()
			&& expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier )
		{
			m_result = makeAccessChain( expr, m_module, m_currentBlock, m_loadedVariables );
			m_result = m_module.loadVariable( m_result, expr->getType(), m_currentBlock );
		}
		else
		{
			auto outerId = doSubmit( expr->getOuterExpr() );
			auto typeId = m_module.registerType( expr->getType() );
			m_result = writeShuffle( m_module
				, m_currentBlock
				, typeId
				, outerId
				, expr->getSwizzle() );
		}
	}

	void ExprVisitor::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		m_allLiterals = false;
		IdList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		auto typeId = m_module.registerType( expr->getType() );
		auto kind = expr->getTextureAccess();
		IntrinsicConfig config;
		getSpirVConfig( kind, config );
		auto op = getSpirVName( kind );

		// Load the sampled image variable
		auto sampledImageType = expr->getArgList()[0]->getType();
		assert( sampledImageType->getKind() == ast::type::Kind::eSampledImage );
		auto loadedSampleImageId = args[0];

		if ( isAccessChain( expr->getArgList()[0].get() ) )
		{
			// Store the access chain result to a temp var
			args[0] = loadVariable( args[0], sampledImageType );
		}

		if ( config.needsImage )
		{
			// We need to extract the image from the sampled image, to give it to the final instruction.
			auto imageType = std::static_pointer_cast< ast::type::SampledImage >( sampledImageType )->getImageType();
			auto imageTypeId = m_module.registerType( imageType );
			auto imageId = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< ImageInstruction >( imageTypeId
				, imageId
				, loadedSampleImageId ) );
			args[0] = imageId;
		}

		if ( config.imageOperandsIndex )
		{
			assert( args.size() >= config.imageOperandsIndex );
			auto mask = getMask( kind );
			args.insert( args.begin() + config.imageOperandsIndex, spv::Id( mask ) );
		}

		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeTextureAccessInstruction( typeId
			, m_result
			, op
			, args ) );
	}

	void ExprVisitor::handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is carry or borrow.
		assert( expr->getArgList().size() == 3u );
		IdList params;
		params.push_back( doSubmit( expr->getArgList()[0].get() ) );
		params.push_back( doSubmit( expr->getArgList()[1].get() ) );

		auto resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( expr->getType()->getKind() )
			? getComponentCount( expr->getType()->getKind() )
			: 1 );
		auto resultCarryBorrowId = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( resultStructTypeId
			, resultCarryBorrowId
			, opCode
			, params ) );

		auto & carryBorrowArg = *expr->getArgList()[2];
		auto carryBorrowTypeId = m_module.registerType( carryBorrowArg.getType() );
		auto intermediateId = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( carryBorrowTypeId
			, intermediateId
			, IdList{ resultCarryBorrowId, 1u } ) );
		auto carryBorrowId = getVariableIdNoLoad( &carryBorrowArg );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( carryBorrowId, intermediateId ) );

		auto resultTypeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( resultTypeId
			, m_result
			, IdList{ resultCarryBorrowId, 0u } ) );

		m_module.putIntermediateResult( intermediateId );
	}

	void ExprVisitor::handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is msb.
		// Arg 4 is lsb.
		assert( expr->getArgList().size() == 4u );
		IdList params;
		params.push_back( doSubmit( expr->getArgList()[0].get() ) );
		params.push_back( doSubmit( expr->getArgList()[1].get() ) );
		spv::Id resultStructTypeId;
		auto paramType = expr->getArgList()[0]->getType()->getKind();

		if ( isSignedIntType( paramType ) )
		{
			resultStructTypeId = getSignedExtendedResultTypeId( isVectorType( paramType )
				? getComponentCount( paramType )
				: 1 );
		}
		else
		{
			resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( paramType )
				? getComponentCount( paramType )
				: 1 );
		}

		auto resultMulExtendedId = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( resultStructTypeId
			, resultMulExtendedId
			, opCode
			, params ) );

		auto & msbArg = *expr->getArgList()[2];
		auto msbTypeId = m_module.registerType( msbArg.getType() );
		auto intermediateMsb = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( msbTypeId
			, intermediateMsb
			, IdList{ resultMulExtendedId, 1u } ) );
		auto msbId = getVariableIdNoLoad( &msbArg );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( msbId, intermediateMsb ) );

		auto & lsbArg = *expr->getArgList()[3];
		auto lsbTypeId = m_module.registerType( lsbArg.getType() );
		auto intermediateLsb = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( lsbTypeId
			, intermediateLsb
			, IdList{ resultMulExtendedId, 0u } ) );
		auto lsbId = getVariableIdNoLoad( &lsbArg );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( lsbId, intermediateLsb ) );

		m_module.putIntermediateResult( intermediateMsb );
		m_module.putIntermediateResult( intermediateLsb );
		m_module.putIntermediateResult( resultMulExtendedId );
	}

	void ExprVisitor::handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		IdList params;
		auto save = m_loadVariable;
		m_loadVariable = false;
		params.push_back( doSubmit( expr->getArgList()[0].get() ) );
		m_loadVariable = save;

		auto scopeId = m_module.registerLiteral( uint32_t( spv::ScopeDevice ) );
		auto memorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsAcquireReleaseMask ) );
		params.push_back( scopeId );
		params.push_back( memorySemanticsId );

		if ( expr->getIntrinsic() == ast::expr::Intrinsic::eAtomicCompSwapI
			|| expr->getIntrinsic() == ast::expr::Intrinsic::eAtomicCompSwapU )
		{
			auto memorySemanticsUnequalId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsAcquireMask ) );
			params.push_back( memorySemanticsUnequalId );
		}

		for ( auto i = 1u; i < expr->getArgList().size(); ++i )
		{
			params.push_back( doSubmit( expr->getArgList()[i].get() ) );
		}

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( typeId
			, m_result
			, opCode
			, params ) );
	}

	void ExprVisitor::handleExtensionIntrinsicCallExpr( spv::Id opCode, ast::expr::IntrinsicCall * expr )
	{
		auto intrinsic = expr->getIntrinsic();
		IdList params;

		if ( ( intrinsic >= ast::expr::Intrinsic::eModf1F
				&& intrinsic <= ast::expr::Intrinsic::eModf4D )
			|| ( intrinsic >= ast::expr::Intrinsic::eFrexp1F
				&& intrinsic <= ast::expr::Intrinsic::eFrexp4D ) )
		{
			// For modf and frexp intrinsics, second parameter is an output parameter,
			// hence we need to pass it as a pointer to the call.
			assert( expr->getArgList().size() == 2u );
			params.push_back( doSubmit( expr->getArgList()[0].get() ) );
			auto save = m_loadVariable;
			m_loadVariable = false;
			params.push_back( doSubmit( expr->getArgList()[1].get() ) );
			m_loadVariable = save;
		}
		else
		{
			for ( auto & arg : expr->getArgList() )
			{
				auto id = doSubmit( arg.get() );
				params.push_back( id );
			}
		}

		auto typeId = m_module.registerType( expr->getType() );
		params.insert( params.begin(), opCode );
		params.insert( params.begin(), 1u );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< ExtInstInstruction >( typeId
			, m_result
			, params ) );
	}

	void ExprVisitor::handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = doSubmit( arg.get() );
			params.push_back( id );
		}

		if ( opCode >= spv::OpEmitVertex
			&& opCode <= spv::OpEndStreamPrimitive )
		{
			m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( opCode
				, params ) );
		}
		else
		{
			auto typeId = m_module.registerType( expr->getType() );
			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( typeId
				, m_result
				, opCode
				, params ) );
		}
	}

	spv::Id ExprVisitor::getUnsignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_unsignedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeU" + std::to_string( count + 1u );
			m_unsignedExtendedTypes[count] = m_module.getCache().getStruct( ast::type::MemoryLayout::eStd430, name );
			auto type = count == 3
				? m_module.getCache().getVec4U()
				: ( count == 2
					? m_module.getCache().getVec3U()
					: ( count == 1
						? m_module.getCache().getVec2U()
						: ( m_module.getCache().getUInt() ) ) );

			if ( m_unsignedExtendedTypes[count]->empty() )
			{
				m_unsignedExtendedTypes[count]->declMember( "result", type );
				m_unsignedExtendedTypes[count]->declMember( "extended", type );
			}
		}

		return m_module.registerType( m_unsignedExtendedTypes[count] );
	}

	spv::Id ExprVisitor::getSignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_signedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeS" + std::to_string( count + 1u );
			m_signedExtendedTypes[count] = m_module.getCache().getStruct( ast::type::MemoryLayout::eStd430, name );
			auto type = count == 3
				? m_module.getCache().getVec4I()
				: ( count == 2
					? m_module.getCache().getVec3I()
					: ( count == 1
						? m_module.getCache().getVec2I()
						: ( m_module.getCache().getInt() ) ) );

			if ( m_signedExtendedTypes[count]->empty() )
			{
				m_signedExtendedTypes[count]->declMember( "result", type );
				m_signedExtendedTypes[count]->declMember( "extended", type );
			}
		}

		return m_module.registerType( m_signedExtendedTypes[count] );
	}

	spv::Id ExprVisitor::getVariableIdNoLoad( ast::expr::Expr * expr )
	{
		spv::Id result;

		if ( isAccessChain( expr ) )
		{
			auto save = m_loadVariable;
			m_loadVariable = false;
			result = doSubmit( expr );
			m_loadVariable = save;
		}
		else
		{
			auto ident = ast::findIdentifier( expr );

			if ( ident )
			{
				auto var = ident->getVariable();

				if ( var->isSpecialisationConstant()
					|| var->isConstant()
					|| var->isUniform()
					|| var->isInputParam()
					|| var->isPushConstant()
					|| var->isShaderInput() )
				{
					m_info.lvalue = false;
					m_info.rvalue = true;
				}

				result = m_module.registerVariable( adaptName( var->getName() )
					, getStorageClass( var )
					, expr->getType()
					, m_info ).id;
			}
			else
			{
				result = doSubmit( expr );
			}
		}

		return result;
	}

	spv::Id ExprVisitor::writeBinOpExpr( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id typeId
		, spv::Id lhsId
		, spv::Id rhsId
		, bool isLhsSpecConstant )
	{
		auto result = m_module.getIntermediateResult();

		if ( isLhsSpecConstant )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( typeId
				, result
				, makeBinOpOperands( exprKind
					, lhsTypeKind
					, rhsTypeKind
					, lhsId
					, rhsId ) ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
				, result
				, exprKind
				, lhsTypeKind
				, rhsTypeKind
				, lhsId
				, rhsId ) );
		}

		return result;
	}

	spv::Id ExprVisitor::loadVariable( spv::Id varId
		, ast::type::TypePtr type )
	{
		return spirv::loadVariable( varId
			, type
			, m_module
			, m_currentBlock
			, m_loadedVariables );
	}

	spv::Id ExprVisitor::makeFunctionAlias( spv::Id source
		, ast::type::TypePtr type )
	{
		VariableInfo info;
		info.rvalue = true;
		auto result = m_module.registerVariable( "functmp" + std::to_string( m_aliasId++ )
			, spv::StorageClassFunction
			, type
			, info ).id;
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( result, source ) );
		return result;
	}

	void ExprVisitor::initialiseVariable( spv::Id init
		, bool allLiterals
		, bool isFuncInit
		, ast::var::VariablePtr var
		, ast::type::TypePtr type )
	{
		spv::StorageClass storageClass{ getStorageClass( var ) };

		if ( allLiterals
			&& !var->isLoopVar()
			&& !isFuncInit )
		{
			m_result = m_module.registerVariable( adaptName( var->getName() )
				, storageClass
				, type
				, m_info
				, init ).id;
		}
		else
		{
			m_result = m_module.registerVariable( adaptName( var->getName() )
				, storageClass
				, type
				, m_info ).id;

			if ( init )
			{
				m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( m_result, init ) );
			}
		}
	}
}
