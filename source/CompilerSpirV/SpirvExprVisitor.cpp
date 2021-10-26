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

			void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
			{
				expr->getOperand()->accept( this );
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
					AST_Failure( "Unsupported cast expression" );
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
					AST_Failure( "Unsupported cast expression" );
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
					AST_Failure( "Unsupported cast expression" );
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
					AST_Failure( "Unsupported cast expression" );
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
					AST_Failure( "Unsupported cast expression" );
				}
			}
			else
			{
				AST_Failure( "Unsupported cast expression" );
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
		else if ( var->isStatic() && var->isConstant() )
		{
			result = spv::StorageClassPrivate;
		}

		return result;
	}

	ValueId ExprVisitor::submit( ast::expr::Expr * expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module
		, bool isAlias )
	{
		bool allLiterals{ false };
		return submit( expr
			, context
			, currentBlock
			, module
			, allLiterals
			, isAlias );
	}

	ValueId ExprVisitor::submit( ast::expr::Expr * expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module
		, ValueId initialiser
		, bool hasFuncInit
		, bool isAlias )
	{
		bool allLiterals{ false };
		return submit( expr
			, context
			, currentBlock
			, module
			, allLiterals
			, initialiser
			, hasFuncInit
			, isAlias );
	}

	ValueId ExprVisitor::submit( ast::expr::Expr * expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool isAlias )
	{
		ValueId result{ 0u, expr->getType() };
		ExprVisitor vis{ result
			, context
			, currentBlock
			, module
			, allLiterals
			, isAlias };
		expr->accept( &vis );
		return result;
	}

	ValueId ExprVisitor::submit( ast::expr::Expr * expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, ValueId initialiser
		, bool hasFuncInit
		, bool isAlias )
	{
		ValueId result{ 0u, expr->getType() };
		ExprVisitor vis{ result
			, context
			, currentBlock
			, module
			, allLiterals
			, initialiser
			, hasFuncInit
			, isAlias };
		expr->accept( &vis );
		return result;
	}

	ExprVisitor::ExprVisitor( ValueId & result
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool isAlias )
		: m_context{ context }
		, m_result{ result }
		, m_currentBlock{ currentBlock }
		, m_module{ module }
		, m_allLiterals{ allLiterals }
		, m_initialiser{ 0u }
		, m_hasFuncInit{ false }
		, m_isAlias{ isAlias }
	{
	}

	ExprVisitor::ExprVisitor( ValueId & result
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, ValueId initialiser
		, bool hasFuncInit
		, bool isAlias )
		: m_context{ context }
		, m_result{ result }
		, m_currentBlock{ currentBlock }
		, m_module{ module }
		, m_allLiterals{ allLiterals }
		, m_initialiser{ initialiser }
		, m_hasFuncInit{ hasFuncInit }
		, m_isAlias{ isAlias }
	{
	}

	ValueId ExprVisitor::doSubmit( ast::expr::Expr * expr )
	{
		return submit( expr, m_context, m_currentBlock, m_module, false );
	}

	ValueId ExprVisitor::doSubmit( ast::expr::Expr * expr
		, ValueId initialiser
		, bool hasFuncInit )
	{
		return submit( expr, m_context, m_currentBlock, m_module, initialiser, hasFuncInit, false );
	}

	ValueId ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool & allLiterals )
	{
		return submit( expr, m_context, m_currentBlock, m_module, allLiterals, false );
	}

	void ExprVisitor::visitUnaryExpr( ast::expr::Unary * expr )
	{
		m_allLiterals = false;
		auto operandId = loadVariable( doSubmit( expr->getOperand() ) );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = { m_module.getIntermediateResult(), typeId.type };

		if ( expr->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( typeId
				, m_result
				, makeOperands( ValueId{ spv::Id( getUnOpCode( expr->getKind(), expr->getType()->getKind() ) ) }
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
		auto lhsId = loadVariable( doSubmit( expr->getLHS() ) );
		auto rhsId = loadVariable( doSubmit( expr->getRHS() ) );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = writeBinOpExpr( expr->getKind()
			, expr->getLHS()->getType()->getKind()
			, expr->getRHS()->getType()->getKind()
			, { typeId }
			, lhsId
			, rhsId
			, expr->isSpecialisationConstant() );
	}

	void ExprVisitor::visitCastExpr( ast::expr::Cast * expr )
	{
		m_allLiterals = false;
		auto operandId = loadVariable( doSubmit( expr->getOperand() ) );
		auto dstTypeId = m_module.registerType( expr->getType() );
		auto op = getCastOp( expr->getOperand()->getType()->getKind()
			, expr->getType()->getKind() );

		if ( op == spv::OpNop )
		{
			m_result = operandId;
		}
		else
		{
			m_result = { m_module.getIntermediateResult(), dstTypeId.type };

			if ( expr->isSpecialisationConstant() )
			{
				m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( dstTypeId
					, m_result
					, makeOperands( ValueId{ spv::Id( op ) }
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

	void ExprVisitor::visitCommaExpr( ast::expr::Comma * expr )
	{
		doSubmit( expr->getLHS() );
		m_result = doSubmit( expr->getRHS() );
	}

	void ExprVisitor::visitAssignExpr( ast::expr::Assign * expr )
	{
		m_allLiterals = false;

		if ( expr->getLHS()->getKind() == ast::expr::Kind::eSwizzle )
		{
			// For LHS swizzle, the variable must first be loaded,
			// then it must be shuffled with the RHS, to compute the final result.
			auto & lhsSwizzle = static_cast< ast::expr::Swizzle const & >( *expr->getLHS() );
			auto lhsSwizzleKind = lhsSwizzle.getSwizzle();

			// Process the RHS first, asking for the needed variables to be loaded.
			auto rhsId = loadVariable( doSubmit( expr->getRHS() ) );

			auto lhsOuter = lhsSwizzle.getOuterExpr();
			assert( lhsOuter->getKind() == ast::expr::Kind::eIdentifier
				|| isAccessChain( lhsOuter ) );

			if ( lhsSwizzleKind.isOneComponent() )
			{
				// One component swizzles must be processed separately:
				// - Create an access chain to the selected component.
				//   No load to retrieve the variable ID.
				auto lhsId = getVariablePointer( lhsOuter );
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
				auto intermediateId = ValueId{ m_module.getIntermediateResult(), pointerTypeId.type };
				m_currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( pointerTypeId
					, intermediateId
					, ValueIdList{ lhsId, componentId } ) );
				// - Store the RHS into this access chain.
				m_module.storeVariable( intermediateId
					, rhsId
					, m_currentBlock );
				m_result = intermediateId;
			}
			else
			{
				// - No load to retrieve the variable ID.
				auto lhsId = getVariablePointer( lhsOuter );
				// - Load the variable manually.
				auto loadedLhsId = loadVariable( lhsId );
				// - The resulting shuffle indices will contain the RHS values for wanted LHS components,
				//   and LHS values for the remaining ones.
				auto typeId = m_module.registerType( lhsOuter->getType() );
				ValueIdList shuffle;
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

				auto swizzleComponents = convert( getSwizzleComponents( lhsSwizzleKind
					, rhsSwizzleKind
					, getComponentCount( lhsOuter->getType()->getKind() ) ) );
				shuffle.insert( shuffle.end()
					, swizzleComponents.begin()
					, swizzleComponents.end() );
				auto intermediateId = ValueId{ m_module.getIntermediateResult(), typeId.type };
				m_currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( typeId
					, intermediateId
					, shuffle ) );
				m_module.storeVariable( lhsId
					, intermediateId
					, m_currentBlock );
				m_result = lhsId;
			}
		}
		else
		{
			// No load to retrieve the variable ID.
			auto lhsId = getVariablePointer( expr->getLHS() );
			// Ask for the needed variables to be loaded.
			auto rhsId = loadVariable( doSubmit( expr->getRHS() ) );
			m_module.storeVariable( lhsId
				, rhsId
				, m_currentBlock );
			m_result = lhsId;
		}
	}

	void ExprVisitor::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		bool allLiterals = true;
		bool hasFuncInit = false;
		auto init = visitInitialisers( expr->getInitialisers()
			, expr->getType()
			, allLiterals
			, hasFuncInit );

		if ( expr->getIdentifier() )
		{
			auto var = expr->getIdentifier()->getVariable();
			auto it = m_context.constAggrExprs.find( var->getId() );

			if ( it == m_context.constAggrExprs.end() )
			{
				initialiseVariable( init
					, allLiterals
					, hasFuncInit
					, expr->getIdentifier()->getVariable()
					, expr->getType() );
			}
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
		m_result = makeAccessChain( expr
			, m_context
			, m_module
			, m_currentBlock );
	}

	void ExprVisitor::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		m_allLiterals = false;
		m_result = makeAccessChain( expr
			, m_context
			, m_module
			, m_currentBlock );
	}

	void ExprVisitor::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		ValueIdList params;
		bool allLiterals = true;
		auto paramsCount = 0u;

		for ( auto & arg : expr->getArgList() )
		{
			bool allLitsInit = true;
			auto id = loadVariable( doSubmit( arg.get(), allLitsInit ) );
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
			m_result = { m_module.registerLiteral( params, expr->getType() ) };
		}
		else
		{
			m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
			m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( typeId
				, m_result
				, params ) );
		}

		m_allLiterals = m_allLiterals && allLiterals;
	}

	void ExprVisitor::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		ValueIdList params;
		bool allLiterals = true;
		auto type = expr->getFn()->getType();
		assert( type->getKind() == ast::type::Kind::eFunction );
		auto fnType = std::static_pointer_cast< ast::type::Function >( type );
		assert( expr->getArgList().size() == fnType->size() );
		auto it = fnType->begin();

		struct OutputParam
		{
			ValueId src;
			ValueId dst;
			ast::type::TypePtr type;
		};
		std::vector< OutputParam > outputParams;

		for ( auto & arg : expr->getArgList() )
		{
			auto & param = *it;
			ValueId id;

			if ( isPointerParam( *param ) )
			{
				// Opaque and Output function parameters are pointers, hence their variables must not be loaded.
				id = getVariablePointer( arg.get() );
				assert( !isOpaqueType( param->getType()->getKind() )
					|| id.getStorage() == ast::type::Storage::eUniformConstant );

				if ( param->isOutputParam() )
				{
					if ( id.getStorage() != ast::type::Storage::eFunction )
					{
						// We must have a variable with function storage class.
						// Hence we create a temporary variable with this storage class,
						// and load the original variable into it.
						auto srcId = id;
						id = makeFunctionAlias( srcId, arg->getType() );
						outputParams.emplace_back( OutputParam{ srcId, id, arg->getType() } );
					}
				}
			}
			else
			{
				id = loadVariable( doSubmit( arg.get() ) );
			}

			allLiterals = allLiterals
				&& ( arg->getKind() == ast::expr::Kind::eLiteral );
			params.push_back( id );
			++it;
		}

		auto typeId = m_module.registerType( expr->getType() );
		auto fnId = doSubmit( expr->getFn() );
		params.insert( params.begin(), fnId );
		m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
		m_currentBlock.instructions.emplace_back( makeInstruction< FunctionCallInstruction >( typeId
			, m_result
			, params ) );

		for ( auto param : outputParams )
		{
			auto loadedId = loadVariable( param.dst );
			m_module.storeVariable( param.src
				, loadedId
				, m_currentBlock );
		}

		m_allLiterals = m_allLiterals && allLiterals;
	}

	void ExprVisitor::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		m_allLiterals = false;
		auto var = expr->getVariable();
		auto it = m_context.constAggrExprs.find( var->getId() );

		if ( it != m_context.constAggrExprs.end() )
		{
			bool allLiterals = true;
			bool hasFuncInit = false;
			m_result = visitInitialisers( it->second
				, expr->getType()
				, allLiterals
				, hasFuncInit );
		}
		else if ( var->getBuiltin() == ast::Builtin::eWorkGroupSize )
		{
			m_result = m_context.workGroupSizeExpr;
		}
		else if ( var->isMember() )
		{
			m_result = makeAccessChain( expr
				, m_context
				, m_module
				, m_currentBlock );
		}
		else
		{
			initialiseVariable( m_initialiser
				, true
				, m_hasFuncInit
				, var
				, expr->getType() );
		}
	}

	void ExprVisitor::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		m_allLiterals = false;
		auto isStore = expr->getImageAccess() >= ast::expr::ImageAccess::eImageStore1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageStore2DMSArrayU;
		auto paramType = expr->getArgList()[0]->getType();
		assert( paramType->getKind() == ast::type::Kind::eImage );
		auto imageVarId = doSubmit( expr->getArgList()[0].get() );
		auto imageType = std::static_pointer_cast< ast::type::Image >( paramType );
		auto intermediateId = loadVariable( imageVarId );
		ValueIdList params;
		params.push_back( intermediateId );

		for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
		{
			auto & arg = ( *it );
			auto id = loadVariable( doSubmit( arg.get() ) );
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
			params.push_back( { spv::ImageOperandsSampleMask } );
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
			m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
			m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( typeId
				, m_result
				, op
				, params ) );
		}
		else
		{
			ValueIdList texelPointerParams;
			uint32_t index = 0u;
			assert( imageVarId.isPointer() );
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
			auto sampledType = m_module.getCache().getBasicType( image->getConfig().sampledType );
			auto sampledId = m_module.registerType( sampledType );
			auto pointerTypeId = m_module.registerPointerType( sampledId
				, spv::StorageClassImage );
			auto pointerId = ValueId{ m_module.getIntermediateResult(), pointerTypeId.type };
			m_currentBlock.instructions.emplace_back( makeInstruction< ImageTexelPointerInstruction >( pointerTypeId
				, pointerId
				, texelPointerParams ) );

			auto scopeId = m_module.registerLiteral( uint32_t( spv::ScopeDevice ) );
			ValueIdList accessParams;
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
			m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
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
		auto init = loadVariable( doSubmit( expr->getInitialiser(), allLiterals ) );
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
			AST_Failure( "Unsupported literal type" );
			break;
		}
	}

	void ExprVisitor::visitQuestionExpr( ast::expr::Question * expr )
	{
		m_allLiterals = false;
		auto ctrlId = loadVariable( doSubmit( expr->getCtrlExpr() ) );
		auto trueId = loadVariable( doSubmit( expr->getTrueExpr() ) );
		auto falseId = loadVariable( doSubmit( expr->getFalseExpr() ) );
		auto type = m_module.registerType( expr->getType() );
		m_result = ValueId{ m_module.getIntermediateResult(), type.type };
		auto branches = makeOperands( ctrlId, trueId, falseId );

		if ( expr->getCtrlExpr()->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( type
				, m_result
				, makeOperands( ValueId{ spv::Id( spv::OpSelect ) }, branches ) ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SelectInstruction >( type
				, m_result
				, branches ) );
		}
	}

	void ExprVisitor::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		m_allLiterals = false;

		if ( expr->getSwizzle().isOneComponent()
			&& expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier
			&& !static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->isTempVar()
			&& static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getBuiltin() != ast::Builtin::eWorkGroupSize )
		{
			m_result = loadVariable( makeAccessChain( expr
				, m_context
				, m_module
				, m_currentBlock ) );
		}
		else
		{
			m_result = loadVariable( makeVectorShuffle( expr
				, m_context
				, m_module
				, m_currentBlock ) );
		}
	}

	void ExprVisitor::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		m_allLiterals = false;
		ValueIdList args;
		bool first = true;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );

			if ( !first )
			{
				args.back() = loadVariable( args.back() );
			}

			first = false;
		}

		auto typeId = m_module.registerType( expr->getType() );
		auto kind = expr->getTextureAccess();
		IntrinsicConfig config;
		getSpirVConfig( kind, config );
		auto op = getSpirVName( kind );

		// Load the sampled image variable
		auto sampledImageType = expr->getArgList()[0]->getType();
		assert( sampledImageType->getKind() == ast::type::Kind::eSampledImage );
		args[0] = loadVariable( args[0] );

		if ( config.needsImage )
		{
			// We need to extract the image from the sampled image, to give it to the final instruction.
			auto imageType = std::static_pointer_cast< ast::type::SampledImage >( sampledImageType )->getImageType();
			auto imageTypeId = m_module.registerType( imageType );
			auto imageId = ValueId{ m_module.getIntermediateResult(), imageTypeId.type };
			m_currentBlock.instructions.emplace_back( makeInstruction< ImageInstruction >( imageTypeId
				, imageId
				, args[0] ) );
			args[0] = imageId;
		}

		if ( config.imageOperandsIndex )
		{
			assert( args.size() >= config.imageOperandsIndex );
			bool constOffset = false;

			if ( config.offsetIndex )
			{
				assert( expr->getArgList().size() >= config.offsetIndex );
				constOffset = expr->getArgList()[config.offsetIndex - 1u]->isConstant();
			}

			auto mask = getMask( kind, constOffset );
			auto it = args.begin() + config.imageOperandsIndex;
			it = args.insert( it, ValueId{ spv::Id( mask ) } );
			++it;
		}

		m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
		m_currentBlock.instructions.emplace_back( makeTextureAccessInstruction( typeId
			, m_result
			, op
			, args ) );
	}

	void ExprVisitor::visitAliasExpr( ast::expr::Alias * expr )
	{
		m_result = submit( expr->getRHS()
			, m_context
			, m_currentBlock
			, m_module
			, true );
		auto var = expr->getLHS()->getVariable();
		// Aliases don't store pointers, hence make sure the result isn't.
		//m_result = loadVariable( m_result, m_currentBlock );
		m_module.registerAlias( var->getName()
			, var->getType()
			, m_result );
	}

	void ExprVisitor::handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is carry or borrow.
		assert( expr->getArgList().size() == 3u );
		ValueIdList params;
		params.push_back( loadVariable( doSubmit( expr->getArgList()[0].get() ) ) );
		params.push_back( loadVariable( doSubmit( expr->getArgList()[1].get() ) ) );

		auto resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( expr->getType()->getKind() )
			? getComponentCount( expr->getType()->getKind() )
			: 1 );
		auto resultCarryBorrowId = ValueId{ m_module.getIntermediateResult(), resultStructTypeId.type };
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( resultStructTypeId
			, resultCarryBorrowId
			, opCode
			, params ) );

		auto & carryBorrowArg = *expr->getArgList()[2];
		auto carryBorrowTypeId = m_module.registerType( carryBorrowArg.getType() );
		auto intermediateId = ValueId{ m_module.getIntermediateResult(), carryBorrowTypeId.type };
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( carryBorrowTypeId
			, intermediateId
			, ValueIdList{ resultCarryBorrowId, { 1u } } ) );
		auto carryBorrowId = getVariablePointer( &carryBorrowArg );
		m_module.storeVariable( carryBorrowId
			, intermediateId
			, m_currentBlock );

		auto resultTypeId = m_module.registerType( expr->getType() );
		m_result = ValueId{ m_module.getIntermediateResult(), resultTypeId.type };
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( resultTypeId
			, m_result
			, ValueIdList{ resultCarryBorrowId, { 0u } } ) );

		m_module.putIntermediateResult( intermediateId );
	}

	void ExprVisitor::handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is msb.
		// Arg 4 is lsb.
		assert( expr->getArgList().size() == 4u );
		ValueIdList params;
		params.push_back( doSubmit( expr->getArgList()[0].get() ) );
		params.push_back( doSubmit( expr->getArgList()[1].get() ) );
		ValueId resultStructTypeId;
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

		auto resultMulExtendedId = ValueId{ m_module.getIntermediateResult(), resultStructTypeId.type };
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( resultStructTypeId
			, resultMulExtendedId
			, opCode
			, params ) );

		auto & msbArg = *expr->getArgList()[2];
		auto msbTypeId = m_module.registerType( msbArg.getType() );
		auto intermediateMsb = ValueId{ m_module.getIntermediateResult(), msbTypeId.type };
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( msbTypeId
			, intermediateMsb
			, ValueIdList{ resultMulExtendedId, { 1u } } ) );
		auto msbId = getVariablePointer( &msbArg );
		m_module.storeVariable( msbId
			, intermediateMsb
			, m_currentBlock );

		auto & lsbArg = *expr->getArgList()[3];
		auto lsbTypeId = m_module.registerType( lsbArg.getType() );
		auto intermediateLsb = ValueId{ m_module.getIntermediateResult(), lsbTypeId.type };
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( lsbTypeId
			, intermediateLsb
			, ValueIdList{ resultMulExtendedId, { 0u } } ) );
		auto lsbId = getVariablePointer( &lsbArg );
		m_module.storeVariable( lsbId
			, intermediateLsb
			, m_currentBlock );

		m_module.putIntermediateResult( intermediateMsb );
		m_module.putIntermediateResult( intermediateLsb );
		m_module.putIntermediateResult( resultMulExtendedId );
	}

	void ExprVisitor::handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		ValueIdList params;
		params.push_back( doSubmit( expr->getArgList()[0].get() ) );

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
			params.push_back( loadVariable( doSubmit( expr->getArgList()[i].get() ) ) );
		}

		auto typeId = m_module.registerType( expr->getType() );
		m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( typeId
			, m_result
			, opCode
			, params ) );
	}

	void ExprVisitor::handleExtensionIntrinsicCallExpr( spv::Id opCode, ast::expr::IntrinsicCall * expr )
	{
		auto intrinsic = expr->getIntrinsic();
		ValueIdList params;

		if ( ( intrinsic >= ast::expr::Intrinsic::eModf1F
				&& intrinsic <= ast::expr::Intrinsic::eModf4D )
			|| ( intrinsic >= ast::expr::Intrinsic::eFrexp1F
				&& intrinsic <= ast::expr::Intrinsic::eFrexp4D ) )
		{
			// For modf and frexp intrinsics, second parameter is an output parameter,
			// hence we need to pass it as a pointer to the call.
			assert( expr->getArgList().size() == 2u );
			params.push_back( loadVariable( doSubmit( expr->getArgList()[0].get() ) ) );
			params.push_back( doSubmit( expr->getArgList()[1].get() ) );
		}
		else
		{
			for ( auto & arg : expr->getArgList() )
			{
				params.push_back( loadVariable( doSubmit( arg.get() ) ) );
			}
		}

		auto typeId = m_module.registerType( expr->getType() );
		params.insert( params.begin(), { opCode } );
		params.insert( params.begin(), { 1u } );
		m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
		m_currentBlock.instructions.emplace_back( makeInstruction< ExtInstInstruction >( typeId
			, m_result
			, params ) );
	}

	void ExprVisitor::handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		ValueIdList params;

		for ( auto & arg : expr->getArgList() )
		{
			params.push_back( loadVariable( doSubmit( arg.get() ) ) );
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
			m_result = ValueId{ m_module.getIntermediateResult(), typeId.type };
			m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( typeId
				, m_result
				, opCode
				, params ) );
		}
	}

	ValueId ExprVisitor::getUnsignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_unsignedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeU" + std::to_string( count + 1u );
			m_unsignedExtendedTypes[count] = m_module.getCache().getStruct( ast::type::MemoryLayout::eC, name );

			if ( m_unsignedExtendedTypes[count]->empty() )
			{
				auto type = count == 3
					? m_module.getCache().getVec4U()
					: ( count == 2
						? m_module.getCache().getVec3U()
						: ( count == 1
							? m_module.getCache().getVec2U()
							: m_module.getCache().getUInt() ) );
				m_unsignedExtendedTypes[count]->declMember( "result", type );
				m_unsignedExtendedTypes[count]->declMember( "extended", type );
			}
		}

		return m_module.registerType( m_unsignedExtendedTypes[count] );
	}

	ValueId ExprVisitor::getSignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_signedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeS" + std::to_string( count + 1u );
			m_signedExtendedTypes[count] = m_module.getCache().getStruct( ast::type::MemoryLayout::eC, name );

			if ( m_signedExtendedTypes[count]->empty() )
			{
				auto type = count == 3
					? m_module.getCache().getVec4I()
					: ( count == 2
						? m_module.getCache().getVec3I()
						: ( count == 1
							? m_module.getCache().getVec2I()
							: m_module.getCache().getInt() ) );
				m_signedExtendedTypes[count]->declMember( "result", type );
				m_signedExtendedTypes[count]->declMember( "extended", type );
			}
		}

		return m_module.registerType( m_signedExtendedTypes[count] );
	}

	ValueId ExprVisitor::getVariablePointer( ast::expr::Expr * expr )
	{
		ValueId result{ 0u, expr->getType() };

		if ( isAccessChain( expr ) )
		{
			result = doSubmit( expr );
		}
		else
		{
			auto ident = ast::findIdentifier( expr );

			if ( ident )
			{
				auto var = ident->getVariable();
				VariableInfo sourceInfo;
				auto name = adaptName( var->getName() );
				auto varInfo = m_module.registerVariable( name
					, var->getBuiltin()
					, getStorageClass( var )
					, false
					, false
					, var->isOutputParam()
					, expr->getType()
					, sourceInfo );
				result = varInfo.id;
				assert( result.isPointer() );

				if ( result.getStorage() != sourceInfo.id.getStorage() )
				{
					auto id = loadVariable( sourceInfo.id );
					storeVariable( result, id );
				}
			}
			else
			{
				result = doSubmit( expr );

				if ( !result.isPointer() )
				{
					result = makeFunctionAlias( result );
				}
			}
		}

		assert( result.isPointer() );
		return result;
	}

	ValueId ExprVisitor::writeBinOpExpr( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId typeId
		, ValueId lhsId
		, ValueId rhsId
		, bool isLhsSpecConstant )
	{
		auto result = ValueId{ m_module.getIntermediateResult(), typeId.type };

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

	ValueId ExprVisitor::loadVariable( ValueId varId )
	{
		return m_module.loadVariable( varId, m_currentBlock );
	}

	void ExprVisitor::storeVariable( ValueId varId, ValueId valId )
	{
		m_module.storeVariable( varId, valId, m_currentBlock );
	}

	ValueId ExprVisitor::makeFunctionAlias( ValueId source )
	{
		return makeFunctionAlias( source, source.type );
	}

	ValueId ExprVisitor::makeFunctionAlias( ValueId source
		, ast::type::TypePtr type )
	{
		VariableInfo info;
		info.rvalue = true;
		auto result = m_module.registerVariable( "functmp_" + std::to_string( m_aliasId++ )
			, ast::Builtin::eNone
			, spv::StorageClassFunction
			, false
			, false
			, false
			, type
			, info ).id;
		m_module.storeVariable( result
			, source
			, m_currentBlock );
		return result;
	}

	bool ExprVisitor::initialiseVariable( ValueId init
		, bool allLiterals
		, bool isFuncInit
		, ast::var::VariablePtr var
		, ast::type::TypePtr type )
	{
		bool result{};
		spv::StorageClass storageClass{ getStorageClass( var ) };

		if ( allLiterals
			&& !var->isLoopVar()
			&& !isFuncInit )
		{
			VariableInfo sourceInfo;
			m_result = m_module.registerVariable( adaptName( var->getName() )
				, var->getBuiltin()
				, storageClass
				, var->isAlias()
				, var->isParam()
				, var->isOutputParam()
				, type
				, sourceInfo
				, init ).id;
			result = sourceInfo.isAlias;
		}
		else if ( var->isAlias()
			&& !isFuncInit )
		{
			m_module.registerAlias( adaptName( var->getName() )
				, type
				, init );
			m_result = init;
		}
		else
		{
			VariableInfo sourceInfo;
			auto varInfo = m_module.registerVariable( adaptName( var->getName() )
				, var->getBuiltin()
				, storageClass
				, false
				, false
				, false
				, type
				, sourceInfo );
			m_result = varInfo.id;
			result = sourceInfo.isAlias;

			if ( init )
			{
				m_module.storeVariable( m_result
					, init
					, m_currentBlock );
			}
			else if ( sourceInfo.needsStoreOnPromote() )
			{
				m_module.storeVariable( m_result
					, sourceInfo.id
					, m_currentBlock );
			}
		}

		return result;
	}

	ValueId ExprVisitor::visitInitialisers( ast::expr::ExprList const & inits
		, ast::type::TypePtr type
		, bool & allLiterals
		, bool & hasFuncInit )
	{
		ValueIdList initialisers;

		for ( auto & init : inits )
		{
			initialisers.push_back( loadVariable( doSubmit( init.get(), allLiterals ) ) );
			hasFuncInit = hasFuncInit || HasFnCall::submit( init.get() );
		}

		ValueId result{ 0u, type };

		if ( allLiterals )
		{
			result = m_module.registerLiteral( initialisers, type );
		}
		else
		{
			auto typeId = m_module.registerType( type );
			result = ValueId{ m_module.getIntermediateResult(), typeId.type };
			m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( typeId
				, result
				, initialisers ) );
		}

		return result;
	}
}
