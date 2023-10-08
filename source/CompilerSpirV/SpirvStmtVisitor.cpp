/*
See LICENSE file in root folder
*/
#include "SpirvStmtVisitor.hpp"

#include "SpirvGetSwizzleComponents.hpp"
#include "SpirvHelpers.hpp"
#include "SpirvIntrinsicConfig.hpp"
#include "SpirvIntrinsicNames.hpp"
#include "SpirvMakeAccessChain.hpp"
#include "SpirvStorageImageAccessConfig.hpp"
#include "SpirvStorageImageAccessNames.hpp"
#include "SpirvCombinedImageAccessConfig.hpp"
#include "SpirvCombinedImageAccessNames.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>
#include <ShaderAST/Visitors/GetOutermostExpr.hpp>

#include <algorithm>
#include <array>
#include <numeric>
#include <sstream>
#include <stdexcept>

namespace spirv
{
	namespace vishlp
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
			explicit HasFnCall( bool & result )
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

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override
			{
				for ( auto & arg : expr->getArgList() )
				{
					arg->accept( this );
				}

				m_result = true;
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override
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

		static std::string adaptName( std::string const & name )
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

		static spv::Op getCastOp( ast::type::Kind src, ast::type::Kind dst )
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
				else if ( !isDoubleType( dst ) )
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
				else if ( !isFloatType( dst ) )
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
				else if ( !isHalfType( dst ) )
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
					if ( dst != src )
					{
						result = spv::OpSConvert;
					}
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::OpBitcast;
				}
				else if ( !isSignedIntType( dst ) )
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
					if ( dst != src )
					{
						result = spv::OpUConvert;
					}
				}
				else if ( isAccelerationStructureType( dst ) )
				{
					result = spv::OpConvertUToAccelerationStructureKHR;
				}
				else if ( isPointerType( dst ) )
				{
					result = spv::OpConvertUToPtr;
				}
				else if ( !isUnsignedIntType( dst ) )
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

		static int32_t getInt32Value( ast::expr::Literal const & lit )
		{
			int32_t result{};

			switch ( lit.getLiteralType() )
			{
			case ast::expr::LiteralType::eBool:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eBool >() );
				break;
			case ast::expr::LiteralType::eInt8:
				result = lit.getValue< ast::expr::LiteralType::eInt8 >();
				break;
			case ast::expr::LiteralType::eInt16:
				result = lit.getValue< ast::expr::LiteralType::eInt16 >();
				break;
			case ast::expr::LiteralType::eInt32:
				result = lit.getValue< ast::expr::LiteralType::eInt32 >();
				break;
			case ast::expr::LiteralType::eInt64:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eInt64 >() );
				break;
			case ast::expr::LiteralType::eUInt8:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eUInt8 >() );
				break;
			case ast::expr::LiteralType::eUInt16:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eUInt16 >() );
				break;
			case ast::expr::LiteralType::eUInt32:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eUInt32 >() );
				break;
			case ast::expr::LiteralType::eUInt64:
				result = int32_t( lit.getValue< ast::expr::LiteralType::eUInt64 >() );
				break;
			default:
				break;
			}

			return result;
		}

		class ExprVisitor
			: public ast::expr::SimpleVisitor
		{
		public:
			static ValueId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr * expr
				, PreprocContext const & context
				, Block & currentBlock
				, Module & module
				, bool isAlias = false )
			{
				bool allLiterals{ false };
				return submit( exprCache
					, expr
					, context
					, currentBlock
					, module
					, allLiterals
					, isAlias );
			}

			static ValueId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr * expr
				, PreprocContext const & context
				, Block & currentBlock
				, Module & module
				, ValueId initialiser
				, bool hasFuncInit
				, bool isAlias = false )
			{
				bool allLiterals{ false };
				return submit( exprCache
					, expr
					, context
					, currentBlock
					, module
					, allLiterals
					, initialiser
					, hasFuncInit
					, isAlias );
			}

			static ValueId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr * expr
				, PreprocContext const & context
				, Block & currentBlock
				, Module & module
				, bool & allLiterals
				, bool isAlias )
			{
				ValueId result{ 0u, expr->getType() };
				ExprVisitor vis{ result
					, exprCache
					, context
					, currentBlock
					, module
					, allLiterals
					, isAlias };
				expr->accept( &vis );

				if ( expr->isNonUniform() )
				{
					module.decorate( result, spv::DecorationNonUniform );
				}

				return result;
			}

			static ValueId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr * expr
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
					, exprCache
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

		private:
			ExprVisitor( ValueId & result
				, ast::expr::ExprCache & exprCache
				, PreprocContext const & context
				, Block & currentBlock
				, Module & module
				, bool & allLiterals
				, bool isAlias )
				: m_exprCache{ exprCache }
				, m_context{ context }
				, m_result{ result }
				, m_currentBlock{ currentBlock }
				, m_module{ module }
				, m_allLiterals{ allLiterals }
				, m_allocator{ module.allocator }
				, m_initialiser{ 0u }
				, m_hasFuncInit{ false }
				, m_isAlias{ isAlias }
			{
			}

			ExprVisitor( ValueId & result
				, ast::expr::ExprCache & exprCache
				, PreprocContext const & context
				, Block & currentBlock
				, Module & module
				, bool & allLiterals
				, ValueId initialiser
				, bool hasFuncInit
				, bool isAlias )
				: m_exprCache{ exprCache }
				, m_context{ context }
				, m_result{ result }
				, m_currentBlock{ currentBlock }
				, m_module{ module }
				, m_allLiterals{ allLiterals }
				, m_initialiser{ initialiser }
				, m_hasFuncInit{ hasFuncInit }
				, m_isAlias{ isAlias }
			{
			}

			ValueId doSubmit( ast::expr::Expr * expr )
			{
				return submit( m_exprCache, expr, m_context, m_currentBlock, m_module, false );
			}

			ValueId doSubmit( ast::expr::Expr * expr
				, ValueId initialiser
				, bool hasFuncInit )
			{
				return submit( m_exprCache, expr, m_context, m_currentBlock, m_module, initialiser, hasFuncInit, false );
			}

			ValueId doSubmit( ast::expr::Expr * expr
				, bool & allLiterals )
			{
				return submit( m_exprCache, expr, m_context, m_currentBlock, m_module, allLiterals, false );
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto operandId = loadVariable( doSubmit( expr->getOperand() ) );
				auto typeId = m_module.registerType( expr->getType() );
				m_result = { m_module.getIntermediateResult(), typeId->type };

				if ( expr->isSpecialisationConstant() )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( m_module.nameCache
						, typeId.id
						, m_result
						, makeOperands( m_allocator
							, ValueId{ spv::Id( getUnOpCode( expr->getKind(), expr->getType()->getKind() ) ) }
							, operandId ) ) );
				}
				else
				{
					m_currentBlock.instructions.emplace_back( makeUnInstruction( m_module.nameCache
						, typeId.id
						, m_result
						, expr->getKind()
						, expr->getType()->getKind()
						, operandId ) );
				}
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto lhsId = loadVariable( doSubmit( expr->getLHS() ) );
				auto rhsId = loadVariable( doSubmit( expr->getRHS() ) );
				auto typeId = m_module.registerType( expr->getType() );
				m_result = writeBinOpExpr( expr->getKind()
					, expr->getLHS()->getType()->getKind()
					, expr->getRHS()->getType()->getKind()
					, { typeId.id }
					, lhsId
					, rhsId
					, expr->isSpecialisationConstant() );
			}

			void visitCastExpr( ast::expr::Cast * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto operandId = loadVariable( doSubmit( expr->getOperand() ) );
				auto dstTypeId = m_module.registerType( expr->getType() );
				auto op = vishlp::getCastOp( expr->getOperand()->getType()->getKind()
					, expr->getType()->getKind() );

				if ( op == spv::OpNop )
				{
					m_result = operandId;
				}
				else
				{
					m_result = { m_module.getIntermediateResult(), dstTypeId->type };

					if ( expr->isSpecialisationConstant() )
					{
						m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( m_module.nameCache
							, dstTypeId.id
							, m_result
							, makeOperands( m_allocator
								, ValueId{ spv::Id( op ) }
								, operandId ) ) );
					}
					else
					{
						m_currentBlock.instructions.emplace_back( makeCastInstruction( m_module.nameCache
							, dstTypeId.id
							, m_result
							, op
							, operandId ) );
					}
				}
			}

			void visitCommaExpr( ast::expr::Comma * expr )override
			{
				TraceFunc;
				m_module.registerType( expr->getType() );
				doSubmit( expr->getLHS() );
				m_result = doSubmit( expr->getRHS() );
			}

			void visitCopyExpr( ast::expr::Copy * expr )override
			{
				auto operandId = loadVariable( doSubmit( expr->getOperand() ) );
				auto dstTypeId = m_module.registerType( expr->getType() );
				m_result = { m_module.getIntermediateResult(), dstTypeId->type };
				m_currentBlock.instructions.emplace_back( makeInstruction< CopyObjectInstruction >( m_module.nameCache
					, dstTypeId.id
					, m_result
					, operandId ) );
			}

			void visitAssignExpr( ast::expr::Assign * expr )override
			{
				TraceFunc;
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
							, getStorageClass( m_module.getVersion(), static_cast< ast::expr::Identifier const & >( *lhsOutermost ).getVariable() ) );
						//   Create the access chain.
						auto intermediateId = ValueId{ m_module.getIntermediateResult(), pointerTypeId->type };
						m_currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( m_module.nameCache
							, pointerTypeId.id
							, intermediateId
							, makeOperands( m_allocator, lhsId, componentId ) ) );
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
						ValueIdList shuffle{ m_allocator };
						shuffle.emplace_back( loadedLhsId );
						shuffle.emplace_back( rhsId );
						ast::expr::SwizzleKind rhsSwizzleKind;
						auto rhsCount = getComponentCount( expr->getRHS()->getType()->getKind() );
						assert( rhsCount <= 4u );

						switch ( rhsCount )
						{
						case 1u:
							rhsSwizzleKind = ast::expr::SwizzleKind::e0;
							break;
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

						auto swizzleComponents = convert( getSwizzleComponents( m_allocator
							, lhsSwizzleKind
							, rhsSwizzleKind
							, getComponentCount( lhsOuter->getType()->getKind() ) ) );
						shuffle.insert( shuffle.end()
							, swizzleComponents.begin()
							, swizzleComponents.end() );
						auto intermediateId = ValueId{ m_module.getIntermediateResult(), typeId->type };
						m_currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( m_module.nameCache
							, typeId.id
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

			void visitAggrInitExpr( ast::expr::AggrInit * expr )override
			{
				TraceFunc;
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
					m_result = init;
				}

				m_allLiterals = false;
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				m_result = makeAccessChain( m_exprCache
					, expr
					, m_context
					, m_module
					, m_currentBlock );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				m_result = makeAccessChain( m_exprCache
					, expr
					, m_context
					, m_module
					, m_currentBlock );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				TraceFunc;
				bool allLiterals = true;

				if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
				{
					auto it = expr->getArgList().begin();
					auto imageId = loadVariable( doSubmit( ( it++ )->get(), allLiterals ) );

					bool allLitsInit = true;
					auto samplerId = loadVariable( doSubmit( it->get(), allLitsInit ) );
					allLiterals = allLiterals && allLitsInit;

					m_result = m_module.mergeSamplerImage( imageId, samplerId, m_currentBlock );
				}
				else
				{
					ValueIdList params{ m_allocator };
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
						m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
						m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( m_module.nameCache
							, typeId.id
							, m_result
							, params ) );
					}
				}

				m_allLiterals = m_allLiterals && allLiterals;
			}

			void visitFnCallExpr( ast::expr::FnCall * expr )override
			{
				TraceFunc;
				ValueIdList params{ m_allocator };
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
				Vector< OutputParam > outputParams{ m_allocator };

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
				m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
				m_currentBlock.instructions.emplace_back( makeInstruction< FunctionCallInstruction >( m_module.nameCache
					, typeId.id
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

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				TraceFunc;
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
					m_result = makeAccessChain( m_exprCache
						, expr
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

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto isStore = expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageStore1DF
					&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageStore2DMSArrayU;
				auto paramType = expr->getArgList()[0]->getType();
				assert( paramType->getKind() == ast::type::Kind::eImage );
				auto imageVarId = doSubmit( expr->getArgList()[0].get() );
				auto imageType = std::static_pointer_cast< ast::type::Image >( paramType );
				auto intermediateId = loadVariable( imageVarId );
				ValueIdList params{ m_allocator };
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
					m_currentBlock.instructions.emplace_back( makeInstruction< ImageStoreInstruction >( m_module.nameCache
						, params ) );
				}
				else if ( !config.needsTexelPointer )
				{
					auto typeId = m_module.registerType( expr->getType() );
					m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
					m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( m_module.nameCache
						, typeId.id
						, m_result
						, op
						, params ) );
				}
				else
				{
					ValueIdList texelPointerParams{ m_allocator };
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
					auto sampledType = m_module.getTypesCache().getBasicType( image->getConfig().sampledType );
					auto sampledId = m_module.registerType( sampledType );
					auto pointerTypeId = m_module.registerPointerType( sampledId
						, spv::StorageClassImage );
					auto pointerId = ValueId{ m_module.getIntermediateResult(), pointerTypeId->type };
					m_currentBlock.instructions.emplace_back( makeInstruction< ImageTexelPointerInstruction >( m_module.nameCache
						, pointerTypeId.id
						, pointerId
						, texelPointerParams ) );

					auto scopeId = m_module.registerLiteral( uint32_t( spv::ScopeDevice ) );
					ValueIdList accessParams{ m_allocator };
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
					m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
					m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( m_module.nameCache
						, typeId.id
						, m_result
						, op
						, accessParams ) );
					m_module.putIntermediateResult( pointerId );
				}
			}

			void visitInitExpr( ast::expr::Init * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				m_module.registerType( expr->getType() );
				bool allLiterals = true;
				auto init = loadVariable( doSubmit( expr->getInitialiser(), allLiterals ) );
				bool hasFuncInit = vishlp::HasFnCall::submit( expr );
				initialiseVariable( init
					, allLiterals
					, hasFuncInit
					, expr->getIdentifier()->getVariable()
					, expr->getType() );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
			{
				TraceFunc;
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
					else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eControlBarrier
						&& expr->getIntrinsic() <= ast::expr::Intrinsic::eMemoryBarrier )
					{
						handleBarrierIntrinsicCallExpr( opCode, expr );
					}
					else if ( opCode >= spv::OpGroupNonUniformElect
						&& opCode <= spv::OpGroupNonUniformQuadSwap )
					{
						handleSubgroupIntrinsicCallExpr( opCode, expr );
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

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				TraceFunc;
				switch ( expr->getLiteralType() )
				{
				case ast::expr::LiteralType::eBool:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eBool >() );
					break;
				case ast::expr::LiteralType::eInt8:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eInt8 >() );
					break;
				case ast::expr::LiteralType::eInt16:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eInt16 >() );
					break;
				case ast::expr::LiteralType::eInt32:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eInt32 >() );
					break;
				case ast::expr::LiteralType::eInt64:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eInt64 >() );
					break;
				case ast::expr::LiteralType::eUInt8:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt8 >() );
					break;
				case ast::expr::LiteralType::eUInt16:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt16 >() );
					break;
				case ast::expr::LiteralType::eUInt32:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt32 >() );
					break;
				case ast::expr::LiteralType::eUInt64:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt64 >() );
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

			void visitQuestionExpr( ast::expr::Question * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto ctrlId = loadVariable( doSubmit( expr->getCtrlExpr() ) );
				auto trueId = loadVariable( doSubmit( expr->getTrueExpr() ) );
				auto falseId = loadVariable( doSubmit( expr->getFalseExpr() ) );
				auto type = m_module.registerType( expr->getType() );
				m_result = ValueId{ m_module.getIntermediateResult(), type->type };
				auto branches = makeOperands( m_allocator, ctrlId, trueId, falseId );

				if ( expr->getCtrlExpr()->isSpecialisationConstant() )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( m_module.nameCache
						, type.id
						, m_result
						, makeOperands( m_allocator, ValueId{ spv::Id( spv::OpSelect ) }, branches ) ) );
				}
				else
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SelectInstruction >( m_module.nameCache
						, type.id
						, m_result
						, branches ) );
				}
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				TraceFunc;
				m_allLiterals = false;

				if ( expr->getSwizzle().isOneComponent()
					&& expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier
					&& !static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->isTempVar()
					&& static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getBuiltin() != ast::Builtin::eWorkGroupSize )
				{
					m_result = loadVariable( makeAccessChain( m_exprCache
						, expr
						, m_context
						, m_module
						, m_currentBlock ) );
				}
				else
				{
					m_result = loadVariable( makeVectorShuffle( m_exprCache
						, expr
						, m_context
						, m_module
						, m_currentBlock ) );
				}
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ValueIdList args{ m_allocator };
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
				auto kind = expr->getCombinedImageAccess();
				IntrinsicConfig config;
				getSpirVConfig( kind, config );
				auto op = getSpirVName( kind );

				// Load the sampled image variable
				auto sampledImageType = expr->getArgList()[0]->getType();
				assert( sampledImageType->getKind() == ast::type::Kind::eCombinedImage );
				args[0] = loadVariable( args[0] );

				if ( expr->getArgList().front()->isNonUniform() )
				{
					m_module.decorate( args[0], spv::DecorationNonUniform );
				}

				if ( config.needsImage )
				{
					// We need to extract the image from the sampled image, to give it to the final instruction.
					auto textureType = std::static_pointer_cast< ast::type::CombinedImage >( sampledImageType );
					auto imageTypeId = m_module.registerImageType( textureType->getImageType(), textureType->isComparison() );
					auto imageId = ValueId{ m_module.getIntermediateResult(), imageTypeId->type };
					m_currentBlock.instructions.emplace_back( makeInstruction< ImageInstruction >( m_module.nameCache
						, imageTypeId.id
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

				m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
				m_currentBlock.instructions.emplace_back( makeTextureAccessInstruction( m_module.nameCache
					, typeId.id
					, m_result
					, op
					, args ) );
			}

			void visitAliasExpr( ast::expr::Alias * expr )override
			{
				TraceFunc;
				m_result = submit( m_exprCache
					, expr->getRHS()
					, m_context
					, m_currentBlock
					, m_module
					, true );
				auto var = expr->getLHS()->getVariable();
				m_module.registerAlias( var->getName()
					, var->getType()
					, m_result );
			}

			void visitPreDecrementExpr( ast::expr::PreDecrement * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitPreIncrementExpr( ast::expr::PreIncrement * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitPostDecrementExpr( ast::expr::PostDecrement * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitPostIncrementExpr( ast::expr::PostIncrement * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitUnaryPlusExpr( ast::expr::UnaryPlus * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitAddAssignExpr( ast::expr::AddAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitAndAssignExpr( ast::expr::AndAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitOrAssignExpr( ast::expr::OrAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitXorAssignExpr( ast::expr::XorAssign * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend expression." );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchCase expression." );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchTest expression." );
			}

		private:
			void handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
			{
				TraceFunc;
				// Arg 1 is lhs.
				// Arg 2 is rhs.
				// Arg 3 is carry or borrow.
				assert( expr->getArgList().size() == 3u );
				ValueIdList params{ m_allocator };
				params.push_back( loadVariable( doSubmit( expr->getArgList()[0].get() ) ) );
				params.push_back( loadVariable( doSubmit( expr->getArgList()[1].get() ) ) );

				auto resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( expr->getType()->getKind() )
					? getComponentCount( expr->getType()->getKind() )
					: 1 );
				auto resultCarryBorrowId = ValueId{ m_module.getIntermediateResult(), resultStructTypeId->type };
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( m_module.nameCache
					, resultStructTypeId.id
					, resultCarryBorrowId
					, opCode
					, params ) );

				auto & carryBorrowArg = *expr->getArgList()[2];
				auto carryBorrowTypeId = m_module.registerType( carryBorrowArg.getType() );
				auto intermediateId = ValueId{ m_module.getIntermediateResult(), carryBorrowTypeId->type };
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( m_module.nameCache
					, carryBorrowTypeId.id
					, intermediateId
					, makeOperands( m_allocator, resultCarryBorrowId, ValueId{ 1u } ) ) );
				auto carryBorrowId = getVariablePointer( &carryBorrowArg );
				m_module.storeVariable( carryBorrowId
					, intermediateId
					, m_currentBlock );

				auto resultTypeId = m_module.registerType( expr->getType() );
				m_result = ValueId{ m_module.getIntermediateResult(), resultTypeId->type };
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( m_module.nameCache
					, resultTypeId.id
					, m_result
					, makeOperands( m_allocator, resultCarryBorrowId, ValueId{ 0u } ) ) );

				m_module.putIntermediateResult( intermediateId );
			}

			void handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
			{
				TraceFunc;
				// Arg 1 is lhs.
				// Arg 2 is rhs.
				// Arg 3 is msb.
				// Arg 4 is lsb.
				assert( expr->getArgList().size() == 4u );
				ValueIdList params{ m_allocator };
				params.push_back( loadVariable( doSubmit( expr->getArgList()[0].get() ) ) );
				params.push_back( loadVariable( doSubmit( expr->getArgList()[1].get() ) ) );
				TypeId resultStructTypeId;
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

				auto resultMulExtendedId = ValueId{ m_module.getIntermediateResult(), resultStructTypeId->type };
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( m_module.nameCache
					, resultStructTypeId.id
					, resultMulExtendedId
					, opCode
					, params ) );

				auto & msbArg = *expr->getArgList()[2];
				auto msbTypeId = m_module.registerType( msbArg.getType() );
				auto intermediateMsb = ValueId{ m_module.getIntermediateResult(), msbTypeId->type };
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( m_module.nameCache
					, msbTypeId.id
					, intermediateMsb
					, makeOperands( m_allocator, resultMulExtendedId, ValueId{ 1u } ) ) );
				auto msbId = getVariablePointer( &msbArg );
				m_module.storeVariable( msbId
					, intermediateMsb
					, m_currentBlock );

				auto & lsbArg = *expr->getArgList()[3];
				auto lsbTypeId = m_module.registerType( lsbArg.getType() );
				auto intermediateLsb = ValueId{ m_module.getIntermediateResult(), lsbTypeId->type };
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( m_module.nameCache
					, lsbTypeId.id
					, intermediateLsb
					, makeOperands( m_allocator, resultMulExtendedId, ValueId{ 0u } ) ) );
				auto lsbId = getVariablePointer( &lsbArg );
				m_module.storeVariable( lsbId
					, intermediateLsb
					, m_currentBlock );

				m_module.putIntermediateResult( intermediateMsb );
				m_module.putIntermediateResult( intermediateLsb );
				m_module.putIntermediateResult( resultMulExtendedId );
			}

			void handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
			{
				TraceFunc;
				ValueIdList params{ m_allocator };
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
				m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( m_module.nameCache
					, typeId.id
					, m_result
					, opCode
					, params ) );
			}

			void handleExtensionIntrinsicCallExpr( spv::Id opCode, ast::expr::IntrinsicCall * expr )
			{
				TraceFunc;
				auto intrinsic = expr->getIntrinsic();
				ValueIdList params{ m_allocator };

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
				else if ( intrinsic >= ast::expr::Intrinsic::eInterpolateAtCentroid1
					&& intrinsic <= ast::expr::Intrinsic::eInterpolateAtCentroid4 )
				{
					for ( auto & arg : expr->getArgList() )
					{
						params.push_back( m_module.getVariablePointer( doSubmit( arg.get() )
							, "interpolant_" + std::to_string( m_aliasId++ )
							, spv::StorageClassInput
							, m_currentBlock ) );
					}
				}
				else if ( intrinsic >= ast::expr::Intrinsic::eInterpolateAtSample1
					&& intrinsic <= ast::expr::Intrinsic::eInterpolateAtOffset4 )
				{
					auto & args = expr->getArgList();
					params.push_back( m_module.getVariablePointer( doSubmit( args[0].get() )
						, "interpolant_" + std::to_string( m_aliasId++ )
						, spv::StorageClassInput
						, m_currentBlock ) );
					params.push_back( loadVariable( doSubmit( args[1].get() ) ) );
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
				params.insert( params.begin(), { m_module.extGlslStd450 } );
				m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
				m_currentBlock.instructions.emplace_back( makeInstruction< ExtInstInstruction >( m_module.nameCache
					, typeId.id
					, m_result
					, params ) );
			}

			void handleBarrierIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
			{
				TraceFunc;
				ValueIdList params{ m_allocator };

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier )
				{
					if ( expr->getArgList().size() < 3u )
					{
						throw std::runtime_error{ "Wrong number of parameters for a control barrier" };
					}

					params.push_back( m_module.registerLiteral( spv::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[0] ) ) ) );
					params.push_back( m_module.registerLiteral( spv::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) ) ) );
					params.push_back( m_module.registerLiteral( spv::MemorySemanticsMask( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[2] ) ) ) );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
				{
					if ( expr->getArgList().size() < 2u )
					{
						throw std::runtime_error{ "Wrong number of parameters for a memory barrier" };
					}

					params.push_back( m_module.registerLiteral( spv::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[0] ) ) ) );
					params.push_back( m_module.registerLiteral( spv::MemorySemanticsMask( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) ) ) );
				}

				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( m_module.nameCache
					, opCode
					, params ) );
			}

			void handleSubgroupIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
			{
				TraceFunc;
				ValueIdList params{ m_allocator };
				params.push_back( m_module.registerLiteral( spv::ScopeSubgroup ) );

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupBallotBitCount
					|| ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupAdd1F
						&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupXor4B ) )
				{
					params.push_back( { spv::GroupOperationReduce } );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupBallotInclusiveBitCount
					|| ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupInclusiveAdd1F
						&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupInclusiveXor4B ) )
				{
					params.push_back( { spv::GroupOperationInclusiveScan } );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupBallotExclusiveBitCount
					|| ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupExclusiveAdd1F
						&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupExclusiveXor4B ) )
				{
					params.push_back( { spv::GroupOperationExclusiveScan } );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupClusterAdd1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupClusterXor4B )
				{
					params.push_back( { spv::GroupOperationClusteredReduce } );
				}

				for ( auto & arg : expr->getArgList() )
				{
					params.push_back( loadVariable( doSubmit( arg.get() ) ) );
				}

				if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4D )
				{
					params.push_back( m_module.registerLiteral( 0 ) );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadSwapVertical1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapVertical4D )
				{
					params.push_back( m_module.registerLiteral( 1 ) );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D )
				{
					params.push_back( m_module.registerLiteral( 2 ) );
				}

				auto typeId = m_module.registerType( expr->getType() );
				m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( m_module.nameCache
					, typeId.id
					, m_result
					, opCode
					, params ) );
			}

			void handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
			{
				TraceFunc;
				ValueIdList params{ m_allocator };

				for ( auto & arg : expr->getArgList() )
				{
					auto id = doSubmit( arg.get() );

					if ( arg->getType()->getRawKind() != ast::type::Kind::eRayPayload
						&& arg->getType()->getRawKind() != ast::type::Kind::eCallableData )
					{
						id = loadVariable( id );
					}

					params.push_back( id );
				}

				if ( ( opCode >= spv::OpEmitVertex && opCode <= spv::OpEndStreamPrimitive )
					|| opCode == spv::OpExecuteCallableKHR
					|| opCode == spv::OpTraceRayKHR
					|| opCode == spv::OpWritePackedPrimitiveIndices4x8NV
					|| opCode == spv::OpSetMeshOutputsEXT )
				{
					m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( m_module.nameCache
						, opCode
						, params ) );
				}
				else
				{
					auto typeId = m_module.registerType( expr->getType() );
					m_result = ValueId{ m_module.getIntermediateResult(), typeId->type };
					m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( m_module.nameCache
						, typeId.id
						, m_result
						, opCode
						, params ) );
				}
			}

			TypeId getUnsignedExtendedResultTypeId( uint32_t count )
			{
				TraceFunc;
				--count;

				if ( !m_unsignedExtendedTypes[count] )
				{
					std::string name = "SDW_ExtendedResultTypeU" + std::to_string( count + 1u );
					m_unsignedExtendedTypes[count] = m_module.getTypesCache().getStruct( ast::type::MemoryLayout::eC, name );

					if ( m_unsignedExtendedTypes[count]->empty() )
					{
						auto type = count == 3
							? m_module.getTypesCache().getVec4U32()
							: ( count == 2
								? m_module.getTypesCache().getVec3U32()
								: ( count == 1
									? m_module.getTypesCache().getVec2U32()
									: m_module.getTypesCache().getUInt32() ) );
						m_unsignedExtendedTypes[count]->declMember( "result", type );
						m_unsignedExtendedTypes[count]->declMember( "extended", type );
					}
				}

				return m_module.registerType( m_unsignedExtendedTypes[count] );
			}

			TypeId getSignedExtendedResultTypeId( uint32_t count )
			{
				TraceFunc;
				--count;

				if ( !m_signedExtendedTypes[count] )
				{
					std::string name = "SDW_ExtendedResultTypeS" + std::to_string( count + 1u );
					m_signedExtendedTypes[count] = m_module.getTypesCache().getStruct( ast::type::MemoryLayout::eC, name );

					if ( m_signedExtendedTypes[count]->empty() )
					{
						auto type = count == 3
							? m_module.getTypesCache().getVec4I32()
							: ( count == 2
								? m_module.getTypesCache().getVec3I32()
								: ( count == 1
									? m_module.getTypesCache().getVec2I32()
									: m_module.getTypesCache().getInt32() ) );
						m_signedExtendedTypes[count]->declMember( "result", type );
						m_signedExtendedTypes[count]->declMember( "extended", type );
					}
				}

				return m_module.registerType( m_signedExtendedTypes[count] );
			}

			ValueId getVariablePointer( ast::expr::Expr * expr )
			{
				TraceFunc;
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
						auto name = vishlp::adaptName( var->getName() );
						auto varInfo = m_module.registerVariable( name
							, var->getBuiltin()
							, getStorageClass( m_module.getVersion(), var )
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

			ValueId writeBinOpExpr( ast::expr::Kind exprKind
				, ast::type::Kind lhsTypeKind
				, ast::type::Kind rhsTypeKind
				, ValueId typeId
				, ValueId lhsId
				, ValueId rhsId
				, bool isLhsSpecConstant )
			{
				TraceFunc;
				auto result = ValueId{ m_module.getIntermediateResult(), typeId.type };

				if ( isLhsSpecConstant )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( m_module.nameCache
						, typeId
						, result
						, makeBinOpOperands( m_allocator
							, exprKind
							, lhsTypeKind
							, rhsTypeKind
							, lhsId
							, rhsId ) ) );
				}
				else
				{
					m_currentBlock.instructions.emplace_back( makeBinInstruction( m_module.nameCache
						, typeId
						, result
						, exprKind
						, lhsTypeKind
						, rhsTypeKind
						, lhsId
						, rhsId ) );
				}

				return result;
			}

			ValueId loadVariable( ValueId varId )
			{
				TraceFunc;
				return m_module.loadVariable( varId, m_currentBlock );
			}

			void storeVariable( ValueId varId, ValueId valId )
			{
				TraceFunc;
				m_module.storeVariable( varId, valId, m_currentBlock );
			}

			ValueId makeFunctionAlias( ValueId source )
			{
				TraceFunc;
				return makeFunctionAlias( source, source.type );
			}

			ValueId makeFunctionAlias( ValueId source
				, ast::type::TypePtr type )
			{
				TraceFunc;
				VariableInfo info;
				info.rvalue = true;
				auto result = m_module.registerVariable( "functmp_" + std::to_string( uintptr_t( type.get() ) ) + std::to_string( m_aliasId++ )
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

			bool initialiseVariable( ValueId init
				, bool allLiterals
				, bool isFuncInit
				, ast::var::VariablePtr var
				, ast::type::TypePtr type )
			{
				TraceFunc;
				bool result{};
				spv::StorageClass storageClass{ getStorageClass( m_module.getVersion(), var ) };

				if ( allLiterals
					&& !var->isLoopVar()
					&& !isFuncInit )
				{
					VariableInfo sourceInfo;
					m_result = m_module.registerVariable( vishlp::adaptName( var->getName() )
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
					m_module.registerAlias( vishlp::adaptName( var->getName() )
						, type
						, init );
					m_result = init;
				}
				else
				{
					VariableInfo sourceInfo;
					auto varInfo = m_module.registerVariable( vishlp::adaptName( var->getName() )
						, var->getBuiltin()
						, storageClass
						, false
						, false
						, false
						, type
						, sourceInfo );

					if ( varInfo.id.id != 0u )
					{
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
							m_module.storePromoted( m_result
								, sourceInfo
								, m_currentBlock );
						}
					}
				}

				return result;
			}

			ValueId visitInitialisers( ast::expr::ExprList const & inits
				, ast::type::TypePtr type
				, bool & allLiterals
				, bool & hasFuncInit )
			{
				TraceFunc;
				ValueIdList initialisers{ m_allocator };

				for ( auto & init : inits )
				{
					initialisers.push_back( loadVariable( doSubmit( init.get(), allLiterals ) ) );
					hasFuncInit = hasFuncInit || vishlp::HasFnCall::submit( init.get() );
				}

				ValueId result{ 0u, type };

				if ( allLiterals )
				{
					result = m_module.registerLiteral( initialisers, type );
				}
				else
				{
					auto typeId = m_module.registerType( type );
					result = ValueId{ m_module.getIntermediateResult(), typeId->type };
					m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( m_module.nameCache
						, typeId.id
						, result
						, initialisers ) );
				}

				return result;
			}

		private:
			ast::expr::ExprCache & m_exprCache;
			spirv::PreprocContext const & m_context;
			ValueId & m_result;
			Block & m_currentBlock;
			Module & m_module;
			bool & m_allLiterals;
			ast::ShaderAllocatorBlock * m_allocator;
			ValueId m_initialiser;
			bool m_hasFuncInit{ false };
			bool m_isAlias;
			std::array< ast::type::BaseStructPtr, 4u > m_unsignedExtendedTypes;
			std::array< ast::type::BaseStructPtr, 4u > m_signedExtendedTypes;
			uint32_t m_aliasId{ 1u };
		};

		class StmtVisitor
			: public ast::stmt::Visitor
		{
		public:
			static ModulePtr submit( ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::stmt::Stmt * stmt
				, ast::ShaderStage type
				, ModuleConfig const & moduleConfig
				, spirv::PreprocContext context
				, SpirVConfig & spirvConfig
				, ShaderActions actions
				, debug::DebugStatements debugStatements )
			{
				auto result = ModulePtr{ new Module{ &exprCache.getAllocator()
					, typesCache
					, spirvConfig
					, moduleConfig.addressingModel
					, getMemoryModel()
					, getExecutionModel( type )
					, debugStatements } };
				StmtVisitor vis{ exprCache
					, typesCache
					, *result
					, type
					, moduleConfig
					, std::move( context )
					, spirvConfig
					, std::move( actions )
					, std::move( debugStatements ) };
				stmt->accept( &vis );
				return result;
			}

		private:
			struct Control
			{
				spv::Id breakLabel;
				spv::Id continueLabel;
			};

		private:
			StmtVisitor( ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, Module & result
				, ast::ShaderStage type
				, ModuleConfig const & moduleConfig
				, spirv::PreprocContext context
				, SpirVConfig & spirvConfig
				, ShaderActions actions
				, debug::DebugStatements debugStatements )
				: m_exprCache{ exprCache }
				, m_typesCache{ typesCache }
				, m_allocator{ &m_exprCache.getAllocator() }
				, m_moduleConfig{ moduleConfig }
				, m_context{ std::move( context ) }
				, m_actions{ std::move( actions ) }
				, m_result{ result }
				, m_debugStatements{ std::move( debugStatements ) }
				, m_currentBlock{ m_allocator }
				, m_controlBlocks{ m_allocator }
				, m_inputs{ m_allocator }
				, m_outputs{ m_allocator }
			{
				moduleConfig.fillModule( m_result );
				VariableInfo info;

				for ( auto & input : moduleConfig.getInputs() )
				{
					if ( input->getBuiltin() != ast::Builtin::eWorkGroupSize )
					{
						m_inputs.push_back( m_result.registerVariable( vishlp::adaptName( input->getName() )
							, input->getBuiltin()
							, getStorageClass( m_result.getVersion(), input, spv::StorageClassInput )
							, input->isAlias()
							, input->isParam()
							, input->isOutputParam()
							, input->getType()
							, info ).id );
					}
				}

				for ( auto & output : moduleConfig.getOutputs() )
				{
					m_outputs.push_back( m_result.registerVariable( vishlp::adaptName( output->getName() )
						, output->getBuiltin()
						, getStorageClass( m_result.getVersion(), output, spv::StorageClassOutput )
						, output->isAlias()
						, output->isParam()
						, output->isOutputParam()
						, output->getType()
						, info ).id );
				}

				for ( auto & mode : moduleConfig.executionModes )
				{
					m_result.registerExecutionMode( mode );
				}

				m_currentDebugStatement = m_debugStatements.statements.begin();
				m_currentScopeId = m_result.globalScopeId;
			}

			bool isDebugEnabled()const noexcept
			{
				return !m_debugStatements.statements.empty();
			}

			void consumeDebugStatement( [[maybe_unused]] debug::DebugStatementType type )
			{
				if ( isDebugEnabled() )
				{
					assert( type == m_currentDebugStatement->type );

					if ( type == debug::DebugStatementType::eScopeLine
						&& m_currentScopeId != m_result.globalScopeId )
					{
						auto scopeLineStmt = getCurrentDebugStatement();
						auto lineId = m_result.registerLiteral( scopeLineStmt->source.lineStart );
						auto columnStartId = m_result.registerLiteral( scopeLineStmt->source.columnStart );
						auto columnEndId = m_result.registerLiteral( scopeLineStmt->source.columnEnd );
						m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Line
							, m_currentBlock
							, debug::makeValueIdList( m_allocator, m_result.debugSourceId, lineId, lineId, columnStartId, columnEndId ) );
					}

					++m_currentDebugStatement;
				}
			}

			void consumeSimpleDebugStatement()
			{
				consumeDebugStatement( m_scopeLines.back() );
			}

			void parseScope( ast::stmt::Compound * stmt
				, debug::DebugStatementType scopeBegin
				, debug::DebugStatementType scopeLine
				, debug::DebugStatementType scopeEnd )
			{
				if ( isDebugEnabled() )
				{
					auto previousScopeId = m_currentScopeId;
					auto scopeBeginStmt = getCurrentDebugStatement();
					consumeDebugStatement( scopeBegin );
					auto scopeLineId = m_result.registerLiteral( scopeBeginStmt->source.lineStart );

					if ( scopeBegin == debug::DebugStatementType::eFunctionScopeBegin )
					{
						m_currentScopeId = m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Function
							, debug::makeValueIdList( m_allocator, m_function->debugNameId, m_function->debugTypeId, m_result.debugSourceId, m_function->debugLineId, m_function->debugColumnId, previousScopeId, m_function->debugNameId, m_function->debugFlagId, scopeLineId, m_functionDebugId ) );

						m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::FunctionDefinition
							, m_currentBlock
							, debug::makeValueIdList( m_allocator, m_currentScopeId, m_function->id ) );
					}
					else if ( scopeBegin == debug::DebugStatementType::eLexicalScopeBegin )
					{
						auto lineId = m_result.registerLiteral( scopeBeginStmt->source.lineStart );
						auto columnId = m_result.registerLiteral( scopeBeginStmt->source.columnStart );
						m_currentScopeId = m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::LexicalBlock
							, debug::makeValueIdList( m_allocator, m_result.debugSourceId, lineId, columnId, previousScopeId ) );

						m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Scope
							, m_currentBlock
							, debug::makeValueIdList( m_allocator, m_currentScopeId ) );
					}

					m_scopeLines.push_back( scopeLine );
					visitCompoundStmt( stmt );
					m_scopeLines.pop_back();
					consumeDebugStatement( scopeEnd );
				}
				else
				{
					visitCompoundStmt( stmt );
				}
			}

			debug::DebugStatement * getCurrentDebugStatement()
			{
				return m_currentDebugStatement == m_debugStatements.statements.end()
					? nullptr
					: &( *m_currentDebugStatement );
			}

			void interruptBlock( Block & block
				, InstructionPtr interruptInstruction
				, bool pushBlock )
			{
				TraceFunc;
				m_currentBlock.blockEnd = std::move( interruptInstruction );
				m_currentBlock.isInterrupted = true;

				if ( pushBlock && !m_ifStmts )
				{
					m_function->cfg.blocks.emplace_back( std::move( m_currentBlock ) );
					m_currentBlock = m_result.newBlock();
				}
			}

			void endBlock( Block & block
				, spv::Id nextBlockLabel )
			{
				TraceFunc;
				if ( !block.isInterrupted )
				{
					block.blockEnd = makeInstruction< BranchInstruction >( m_result.nameCache, ValueId{ nextBlockLabel } );
				}

				m_function->cfg.blocks.emplace_back( std::move( block ) );
			}

			void endBlock( Block & block
				, spv::Id trueBlockLabel
				, spv::Id falseBlockLabel
				, spv::Id mergeBlockLabel )
			{
				TraceFunc;
				if ( !block.isInterrupted )
				{
					block.blockEnd = makeInstruction< BranchConditionalInstruction >( m_result.nameCache
						, makeOperands( m_allocator
							, ValueId{ trueBlockLabel }
							, ValueId{ falseBlockLabel }
					, ValueId{ mergeBlockLabel } ) );
				}

				m_function->cfg.blocks.emplace_back( std::move( block ) );
			}

			void visitContainerStmt( ast::stmt::Container * cont )override
			{
				TraceFunc;
				for ( auto & stmt : *cont )
				{
					if ( !m_currentBlock.isInterrupted )
					{
						stmt->accept( this );
					}
				}
			}

			void visitBreakStmt( ast::stmt::Break * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( m_currentBlock
					, makeInstruction< BranchInstruction >( m_result.nameCache, ValueId{ m_controlBlocks.back().breakLabel } )
					, !stmt->isSwitchCaseBreak() );
			}

			void visitContinueStmt( ast::stmt::Continue * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( m_currentBlock
					, makeInstruction< BranchInstruction >( m_result.nameCache, ValueId{ m_controlBlocks.back().continueLabel } )
					, true );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override
			{
				TraceFunc;
				consumeDebugStatement( debug::DebugStatementType::eStructureDecl );
				parseScope( stmt
					, debug::DebugStatementType::eStructureScopeBegin
					, debug::DebugStatementType::eStructureMemberDecl
					, debug::DebugStatementType::eStructureScopeEnd );
				auto variableId = m_result.bindBufferVariable( stmt->getName()
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet()
					, spv::DecorationBlock );
				consumeDebugStatement( debug::DebugStatementType::eVariableDecl );
			}

			void visitDemoteStmt( ast::stmt::Demote * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();

				if ( m_moduleConfig.hasExtension( EXT_demote_to_helper_invocation ) )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< DemoteInstruction >( m_result.nameCache ) );
				}
				else
				{
					interruptBlock( m_currentBlock
						, makeInstruction< KillInstruction >( m_result.nameCache )
						, true );
				}
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh * stmt )override
			{
				TraceFunc;
				ValueIdList operands{ m_allocator };
				operands.push_back( submitAndLoad( stmt->getNumGroupsX() ) );
				operands.push_back( submitAndLoad( stmt->getNumGroupsY() ) );
				operands.push_back( submitAndLoad( stmt->getNumGroupsZ() ) );

				if ( stmt->getPayload() )
				{
					operands.push_back( ExprVisitor::submit( m_exprCache, stmt->getPayload(), m_context, m_currentBlock, m_result ) );
				}

				consumeSimpleDebugStatement();
				interruptBlock( m_currentBlock
					, makeInstruction< EmitMeshTasksInstruction >( m_result.nameCache, operands )
					, false );
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();

				if ( m_moduleConfig.hasExtension( KHR_terminate_invocation ) )
				{
					interruptBlock( m_currentBlock
						, makeInstruction< TerminateInvocationInstruction >( m_result.nameCache )
						, true );
				}
				else
				{
					interruptBlock( m_currentBlock
						, makeInstruction< KillInstruction >( m_result.nameCache )
						, true );
				}
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override
			{
				TraceFunc;
				consumeDebugStatement( debug::DebugStatementType::eStructureDecl );
				parseScope( stmt
					, debug::DebugStatementType::eStructureScopeBegin
					, debug::DebugStatementType::eStructureMemberDecl
					, debug::DebugStatementType::eStructureScopeEnd );
				consumeDebugStatement( debug::DebugStatementType::eVariableDecl );
			}

			void visitCommentStmt( ast::stmt::Comment * stmt )override
			{
				TraceFunc;
			}

			void visitCompoundStmt( ast::stmt::Compound * stmt )override
			{
				TraceFunc;
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile * stmt )override
			{
				TraceFunc;
				auto loopBlock = m_result.newBlock();
				auto ifBlock = m_result.newBlock();
				auto mergeBlock = m_result.newBlock();
				auto contentBlock = m_result.newBlock();
				m_controlBlocks.push_back( Control{ mergeBlock.label, ifBlock.label } );

				// End current block, to branch to the loop header block.
				endBlock( m_currentBlock, loopBlock.label );

				// The loop header block, to which continue target will branch, branches to the loop content block.
				consumeDebugStatement( debug::DebugStatementType::eControlBegin );
				auto loopBlockLabel = loopBlock.label;
				loopBlock.instructions.emplace_back( makeInstruction< LoopMergeInstruction >( m_result.nameCache
					, makeOperands( m_allocator
						, ValueId{ mergeBlock.label }
						, ValueId{ ifBlock.label }
						, ValueId{ 0u } ) ) );
				endBlock( loopBlock, contentBlock.label );

				// The current block becomes the loop content block.
				m_currentBlock = std::move( contentBlock );

				// Instructions go to loop content block.
				parseScope( stmt
					, debug::DebugStatementType::eLexicalScopeBegin
					, debug::DebugStatementType::eScopeLine
					, debug::DebugStatementType::eLexicalScopeEnd );

				// Branch current block to the continue target block.
				endBlock( m_currentBlock, ifBlock.label );

				// The if block, branches either back to the loop header block (true) or to the loop merge block (false).
				auto intermediateIfId = m_result.loadVariable( ExprVisitor::submit( m_exprCache, stmt->getCtrlExpr(), m_context, ifBlock, m_result ), m_currentBlock );
				endBlock( ifBlock, intermediateIfId.id, loopBlockLabel, mergeBlock.label );

				// Current block becomes the merge block.
				m_controlBlocks.pop_back();
				m_currentBlock = std::move( mergeBlock );
				consumeDebugStatement( debug::DebugStatementType::eControlEnd );
			}

			void visitElseIfStmt( ast::stmt::ElseIf * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else * stmt )override
			{
				TraceFunc;
				consumeDebugStatement( debug::DebugStatementType::eControlBegin );
				parseScope( stmt
					, debug::DebugStatementType::eLexicalScopeBegin
					, debug::DebugStatementType::eScopeLine
					, debug::DebugStatementType::eLexicalScopeEnd );
			}

			void visitForStmt( ast::stmt::For * stmt )override
			{
				AST_Failure( "Unexpected For statement." );
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )override
			{
				TraceFunc;
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

				consumeDebugStatement( debug::DebugStatementType::eVariableDecl );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override
			{
				TraceFunc;
				auto type = stmt->getType();
				auto retType = m_result.registerType( type->getReturnType() );
				m_function = m_result.beginFunction( stmt->getName()
					, retType
					, ast::var::VariableList{ type->begin(), type->end() } );
				m_currentBlock = m_result.newBlock();

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

				if ( isDebugEnabled() )
				{
					auto declStmt = getCurrentDebugStatement();
					consumeDebugStatement( debug::DebugStatementType::eFunctionDecl );
					m_functionDebugId.id = m_result.getNextId();
					m_function->debugNameId = m_result.registerString( stmt->getName() );
					m_function->debugLineId = m_result.registerLiteral( declStmt->source.lineStart );
					m_function->debugColumnId = m_result.registerLiteral( declStmt->source.columnStart );
					m_function->debugFlagId = m_result.registerLiteral( 0u );
					m_functionDebugId = m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::FunctionDeclaration
						, debug::makeValueIdList( m_allocator, m_function->debugNameId, m_function->debugTypeId, m_result.debugSourceId, m_function->debugLineId, m_function->debugColumnId, m_result.globalScopeId, m_function->debugNameId, m_function->debugFlagId ) );
				}

				parseScope( stmt
					, debug::DebugStatementType::eFunctionScopeBegin
					, debug::DebugStatementType::eScopeLine
					, debug::DebugStatementType::eFunctionScopeEnd );

				if ( stmt->isEntryPoint() )
				{
					m_result.registerEntryPoint( ValueId{ m_function->declaration.front()->resultId.value() }
						, stmt->getName()
						, m_inputs
						, m_outputs );
				}

				if ( !m_currentBlock.blockEnd )
				{
					if ( type->getReturnType()->getKind() == ast::type::Kind::eVoid )
					{
						m_currentBlock.blockEnd = makeInstruction< ReturnInstruction >( m_result.nameCache );
					}
					else
					{
						auto retId = ValueId{ m_result.getIntermediateResult(), retType->type };
						m_currentBlock.instructions.emplace_back( makeInstruction< UndefInstruction >( m_result.nameCache, retType.id, retId ) );
						m_currentBlock.blockEnd = makeInstruction< ReturnValueInstruction >( m_result.nameCache, retId );
					}
				}

				m_currentBlock.instructions.emplace_back( std::move( m_currentBlock.blockEnd ) );
				m_currentBlock.blockEnd = makeInstruction< FunctionEndInstruction >( m_result.nameCache );
				m_function->cfg.blocks.emplace_back( std::move( m_currentBlock ) );
				m_result.endFunction();
				m_function = nullptr;
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );
				visitDebugVariableDecl( variable, variableId );
			}

			void visitIfStmt( ast::stmt::If * stmt )override
			{
				TraceFunc;
				++m_ifStmts;
				auto contentBlock = m_result.newBlock();
				auto mergeBlock = m_result.newBlock();

				// Retrieve the if false branch block label.
				// It will be the else block if it exists, or the merge block.
				BlockList elseIfBlocks{ m_allocator };
				Block elseBlock{ m_allocator };
				auto falseBlockLabel = mergeBlock.label;
				assert( stmt->getElseIfList().empty() && "ElseIf list is supposed to have been converted." );

				if ( stmt->getElse() )
				{
					elseBlock = m_result.newBlock();
					falseBlockLabel = elseBlock.label;
				}

				// End current block, to branch to the if content block (true) or to the false branch block (false).
				auto intermediateIfId = m_result.loadVariable( ExprVisitor::submit( m_exprCache, stmt->getCtrlExpr(), m_context, m_currentBlock, m_result ), m_currentBlock );
				m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( m_result.nameCache, ValueId{ mergeBlock.label }, ValueId{ 0u } ) );
				endBlock( m_currentBlock, intermediateIfId.id, contentBlock.label, falseBlockLabel );

				// The current block becomes the if content block.
				m_currentBlock = std::move( contentBlock );
				consumeDebugStatement( debug::DebugStatementType::eControlBegin );
				parseScope( stmt
					, debug::DebugStatementType::eLexicalScopeBegin
					, debug::DebugStatementType::eScopeLine
					, debug::DebugStatementType::eLexicalScopeEnd );
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

			void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl( variable, variableId );
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( m_currentBlock
					, makeInstruction< IgnoreIntersectionInstruction >( m_result.nameCache )
					, false );
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )override
			{
				TraceFunc;
				m_result.registerType( stmt->getType() );
				consumeDebugStatement( debug::DebugStatementType::eVariableDecl );
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl( variable, variableId );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );

				if ( stmt->getLocation() != ast::type::Struct::InvalidLocation )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationLocation ), stmt->getLocation() ) );
				}

				visitDebugVariableDecl( variable, variableId );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );

				if ( stmt->getLocation() != ast::type::Struct::InvalidLocation )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationLocation ), stmt->getLocation() ) );
				}

				visitDebugVariableDecl( variable, variableId );
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );

				if ( variable->isShaderConstant() )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationSpecId ), stmt->getLocation() ) );
				}
				else if ( !variable->isBuiltin()
					&& stmt->getLocation() != ast::type::Struct::InvalidLocation )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationLocation ), stmt->getLocation() ) );
				}

				if ( variable->isBlendIndex() )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationIndex ), stmt->getBlendIndex() ) );
				}

				if ( variable->isGeometryStream() )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationStream ), stmt->getStreamIndex() ) );
				}

				visitDebugVariableDecl( variable, variableId );
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override
			{
				TraceFunc;
				auto var = stmt->getVariable();
				m_result.registerSpecConstant( var->getName()
					, stmt->getLocation()
					, var->getType()
					, *stmt->getValue() );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( spv::ExecutionModeLocalSize
					, makeOperands( m_allocator, ValueId{ stmt->getWorkGroupsX() }, ValueId{ stmt->getWorkGroupsY() }, ValueId{ stmt->getWorkGroupsZ() } ) );
				ValueIdList ids{ m_allocator };
				ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsX() ) );
				ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsY() ) );
				ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsZ() ) );

				if ( m_moduleConfig.stage == ast::ShaderStage::eCompute )
				{
					m_context.workGroupSizeExpr = m_result.registerLiteral( ids, m_result.getTypesCache().getVec3U32() );
					m_result.decorate( m_context.workGroupSizeExpr, makeIdList( m_allocator, spv::Id( spv::DecorationBuiltIn ), spv::Id( spv::BuiltInWorkgroupSize ) ) );
				}
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getLayout() );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getLayout(), stmt->getPrimCount() );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();

				if ( m_moduleConfig.stage == ast::ShaderStage::eMeshNV )
				{
					m_result.registerExecutionModeNV( stmt->getTopology()
						, stmt->getMaxVertices()
						, stmt->getMaxPrimitives() );
				}
				else
				{
					m_result.registerExecutionMode( stmt->getTopology()
						, stmt->getMaxVertices()
						, stmt->getMaxPrimitives() );
				}
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getDomain()
					, stmt->getPartitioning()
					, stmt->getTopology()
					, stmt->getPrimitiveOrdering()
					, stmt->getOutputVertices() );
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getDomain()
					, stmt->getPartitioning()
					, stmt->getPrimitiveOrdering() );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )override
			{
				TraceFunc;
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override
			{
				TraceFunc;
			}

			void visitReturnStmt( ast::stmt::Return * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();

				if ( stmt->getExpr() )
				{
					auto result = m_result.loadVariable( ExprVisitor::submit( m_exprCache
							, stmt->getExpr()
							, m_context
							, m_currentBlock
							, m_result )
						, m_currentBlock );
					interruptBlock( m_currentBlock
						, makeInstruction< ReturnValueInstruction >( m_result.nameCache, result )
						, false );
				}
				else
				{
					interruptBlock( m_currentBlock
						, makeInstruction< ReturnInstruction >( m_result.nameCache )
						, false );
				}
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getVariable() );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl( stmt->getVariable(), variableId );
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getVariable() );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl( stmt->getVariable(), variableId );
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getVariable() );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl( stmt->getVariable(), variableId );
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override
			{
				TraceFunc;
				consumeDebugStatement( debug::DebugStatementType::eStructureDecl );
				parseScope( stmt
					, debug::DebugStatementType::eStructureScopeBegin
					, debug::DebugStatementType::eStructureMemberDecl
					, debug::DebugStatementType::eStructureScopeEnd );
				auto variableId = m_result.bindBufferVariable( stmt->getSsboName()
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet()
					, ( m_result.getVersion() > v1_3
						? spv::DecorationBlock
						: spv::DecorationBufferBlock ) );
				visitDebugVariableDecl( stmt->getVariable(), variableId );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override
			{
				TraceFunc;
				consumeDebugStatement( debug::DebugStatementType::eStructureDecl );
				consumeDebugStatement( debug::DebugStatementType::eStructureScopeBegin );
				visitVariable( stmt->getSsboInstance() );
				consumeDebugStatement( debug::DebugStatementType::eStructureMemberDecl );
				consumeDebugStatement( debug::DebugStatementType::eStructureScopeEnd );
				auto variableId = m_result.bindBufferVariable( stmt->getSsboInstance()->getName()
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet()
					, ( m_result.getVersion() > v1_3
						? spv::DecorationBlock
						: spv::DecorationBufferBlock ) );
				visitDebugVariableDecl( stmt->getSsboInstance(), variableId );
			}

			void visitSimpleStmt( ast::stmt::Simple * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				ExprVisitor::submit( m_exprCache, stmt->getExpr(), m_context, m_currentBlock, m_result );
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override
			{
				TraceFunc;

				if ( isDebugEnabled() )
				{
					auto declStatement = getCurrentDebugStatement();
					consumeDebugStatement( debug::DebugStatementType::eStructureDecl );
					consumeDebugStatement( debug::DebugStatementType::eStructureScopeBegin );
					auto structType = stmt->getType();
					auto typeId = m_result.registerType( structType );
					ValueIdList subTypes{ m_allocator };

					for ( auto it = structType->begin(); it != structType->end(); ++it )
					{
						auto & member = *it;
						auto subTypeId = m_result.registerType( member.type, member.type->getIndex(), typeId );

						auto dbgStmt = getCurrentDebugStatement();
						auto lineId = m_result.registerLiteral( dbgStmt->source.lineStart );
						auto columnId = m_result.registerLiteral( dbgStmt->source.columnStart );
						auto nameId = m_result.registerString( member.name );
						auto offsetId = m_result.registerLiteral( member.offset );
						auto sizeId = m_result.registerLiteral( member.size );
						auto flagId = m_result.registerLiteral( 0u );
						auto resultId = m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeMember
							, debug::makeValueIdList( m_allocator, nameId, subTypeId, m_result.debugSourceId, lineId, columnId, offsetId, sizeId, flagId ) );
						subTypes.push_back( resultId );
						consumeDebugStatement( debug::DebugStatementType::eStructureMemberDecl );
					}

					auto nameId = m_result.registerString( structType->getName() );
					auto tagId = m_result.registerLiteral( uint32_t( spv::NonSemanticShaderDebugInfo100DebugCompositeType::Struct ) );
					auto lineId = m_result.registerLiteral( declStatement->source.lineStart );
					auto columnId = m_result.registerLiteral( declStatement->source.columnStart );
					auto sizeId = m_result.registerLiteral( getSize( structType, structType->getMemoryLayout() ) );
					auto flagId = m_result.registerLiteral( 0u );
					m_result.makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
						, typeId.debug
						, debug::makeValueIdList( m_allocator, nameId, tagId, m_result.debugSourceId, lineId, columnId, m_result.globalScopeId, nameId, sizeId, flagId, subTypes ) );
					consumeDebugStatement( debug::DebugStatementType::eStructureScopeEnd );
				}

				m_result.registerType( stmt->getType() );
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override
			{
			}

			void visitSwitchStmt( ast::stmt::Switch * stmt )override
			{
				TraceFunc;
				Vector< Block > caseBlocks{ m_allocator };
				Map< int32_t, spv::Id > caseBlocksIds{ m_allocator };
				auto mergeBlock = m_result.newBlock();
				m_controlBlocks.push_back( Control{ mergeBlock.label, 0u } );
				ast::stmt::SwitchCase * defaultStmt{ nullptr };
				Block defaultBlock{ m_result.newBlock() };

				for ( auto & it : *stmt )
				{
					assert( it->getKind() == ast::stmt::Kind::eSwitchCase );
					auto & caseStmt = static_cast< ast::stmt::SwitchCase const & >( *it );

					if ( caseStmt.getCaseExpr() )
					{
						auto block = m_result.newBlock();
						caseBlocksIds.emplace( vishlp::getInt32Value( *caseStmt.getCaseExpr()->getLabel() ), block.label );
						caseBlocks.emplace_back( std::move( block ) );
					}
					else
					{
						// Default
						defaultStmt = static_cast< ast::stmt::SwitchCase * >( it.get() );
					}
				}

				auto selector = m_result.loadVariable( ExprVisitor::submit( m_exprCache, stmt->getTestExpr()->getValue(), m_context, m_currentBlock, m_result ), m_currentBlock );
				m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( m_result.nameCache, ValueId{ mergeBlock.label }, ValueId{ 0u } ) );
				m_currentBlock.blockEnd = makeInstruction< SwitchInstruction >( m_result.nameCache, makeOperands( m_allocator, selector, ValueId{ defaultBlock.label } ), caseBlocksIds );
				m_currentBlock.isInterrupted = true;

				consumeDebugStatement( debug::DebugStatementType::eControlBegin );
				consumeDebugStatement( debug::DebugStatementType::eLexicalScopeBegin );

				if ( !caseBlocks.empty() )
				{
					endBlock( m_currentBlock, caseBlocks.front().label );
					uint32_t index = 0u;

					for ( auto & it : *stmt )
					{
						assert( it->getKind() == ast::stmt::Kind::eSwitchCase );
						auto & caseStmt = static_cast< ast::stmt::SwitchCase & >( *it );
						m_currentBlock = std::move( caseBlocks[index] );

						consumeDebugStatement( debug::DebugStatementType::eControlBegin );
						parseScope( &caseStmt
							, debug::DebugStatementType::eLexicalScopeBegin
							, debug::DebugStatementType::eScopeLine
							, debug::DebugStatementType::eLexicalScopeEnd );

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
					consumeDebugStatement( debug::DebugStatementType::eControlBegin );
					parseScope( defaultStmt
						, debug::DebugStatementType::eLexicalScopeBegin
						, debug::DebugStatementType::eScopeLine
						, debug::DebugStatementType::eLexicalScopeEnd );
				}

				consumeDebugStatement( debug::DebugStatementType::eLexicalScopeEnd );
				endBlock( m_currentBlock, mergeBlock.label );

				m_controlBlocks.pop_back();
				m_currentBlock = std::move( mergeBlock );
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( m_currentBlock
					, makeInstruction< TerminateRayInstruction >( m_result.nameCache )
					, false );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override
			{
				TraceFunc;
				auto var = stmt->getVariable();
				auto variableId = visitVariable( var );
				visitDebugVariableDecl( var, variableId );
			}

			void visitWhileStmt( ast::stmt::While * stmt )override
			{
				AST_Failure( "Unexpected While statement." );
			}

			void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override
			{
				AST_Failure( "Unexpected PreprocDefine statement." );
			}

			void visitPreprocElif( ast::stmt::PreprocElif * preproc )override
			{
				AST_Failure( "Unexpected PreprocElif statement." );
			}

			void visitPreprocElse( ast::stmt::PreprocElse * preproc )override
			{
				AST_Failure( "Unexpected PreprocElse statement." );
			}

			void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override
			{
				AST_Failure( "Unexpected PreprocEndif statement." );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override
			{
				TraceFunc;
				m_result.registerExtension( preproc->getName() );
			}

			void visitPreprocIf( ast::stmt::PreprocIf * preproc )override
			{
				AST_Failure( "Unexpected PreprocIf statement." );
			}

			void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override
			{
				AST_Failure( "Unexpected PreprocIfDef statement." );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override
			{
				TraceFunc;
				//TODO m_result->addStmt( ast::stmt::makePreprocVersion( preproc->getName() ) );
			}

			ValueId visitVariable( ast::var::VariablePtr var )
			{
				TraceFunc;
				VariableInfo info;
				ValueId result;

				if ( var->isMember() )
				{
					auto outer = m_result.registerVariable( var->getOuter()->getName()
						, var->getOuter()->getBuiltin()
						, getStorageClass( m_result.getVersion(), var )
						, var->isAlias()
						, var->isParam()
						, var->isOutputParam()
						, var->getOuter()->getType()
						, info ).id;
					result = m_result.registerMemberVariable( outer
						, var->getName()
						, var->getType() );
				}
				else
				{
					result = m_result.registerVariable( var->getName()
						, var->getBuiltin()
						, getStorageClass( m_result.getVersion(), var )
						, var->isAlias()
						, var->isParam()
						, var->isOutputParam()
						, var->getType()
						, info ).id;
				}

				decorateVar( *var, result, m_result );
				return result;
			}

			void visitDebugVariableDecl( std::string const & name
				, ast::type::TypePtr type
				, uint64_t varFlags
				, ValueId variableId )
			{
				if ( ( varFlags & uint64_t( ast::var::Flag::eMember ) ) )
				{
					m_result.registerDebugMemberVariable( name
						, type
						, varFlags
						, getCurrentDebugStatement() );
					consumeDebugStatement( debug::DebugStatementType::eVariableDecl );
				}
				else
				{
					m_result.registerDebugVariable( name
						, type
						, varFlags
						, variableId
						, getCurrentDebugStatement() );
					consumeDebugStatement( debug::DebugStatementType::eVariableDecl );
				}
			}

			void visitDebugVariableDecl( ast::var::VariablePtr variable
				, ValueId variableId )
			{
				visitDebugVariableDecl( variable->getName()
					, variable->getType()
					, variable->getFlags()
					, variableId );
			}

			ValueId submitAndLoad( ast::expr::Expr * expr )
			{
				TraceFunc;
				auto result = ExprVisitor::submit( m_exprCache, expr, m_context, m_currentBlock, m_result );

				if ( expr->getKind() == ast::expr::Kind::eIdentifier )
				{
					result = m_result.loadVariable( result, m_currentBlock );
				}

				return result;
			}

		private:
			ast::expr::ExprCache & m_exprCache;
			ast::type::TypesCache & m_typesCache;
			ast::ShaderAllocatorBlock * m_allocator;
			ModuleConfig const & m_moduleConfig;
			spirv::PreprocContext m_context;
			ShaderActions m_actions;
			Module & m_result;
			debug::DebugStatements m_debugStatements;
			Block m_currentBlock;
			Function * m_function{ nullptr };
			Vector< Control > m_controlBlocks;
			uint32_t m_ifStmts{ 0u };
			ValueIdList m_inputs;
			ValueIdList m_outputs;
			debug::DebugStatementsList::iterator m_currentDebugStatement{};
			std::vector< debug::DebugStatementType > m_scopeLines{ debug::DebugStatementType::eScopeLine };
			ValueId m_functionDebugId{};
			ValueId m_currentScopeId{};
		};
	}

	ModulePtr generateModule( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Stmt * stmt
		, ast::ShaderStage type
		, ModuleConfig const & moduleConfig
		, spirv::PreprocContext context
		, SpirVConfig & spirvConfig
		, ShaderActions actions
		, debug::DebugStatements debugStatements )
	{
		return vishlp::StmtVisitor::submit( exprCache
			, typesCache
			, stmt
			, type
			, moduleConfig
			, std::move( context )
			, spirvConfig
			, std::move( actions )
			, std::move( debugStatements ) );
	}

	ValueId generateModuleExpr( ast::expr::ExprCache & exprCache
		, ast::expr::Expr * expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module )
	{
		return vishlp::ExprVisitor::submit( exprCache
			, expr
			, context
			, currentBlock
			, module );
	}
}
