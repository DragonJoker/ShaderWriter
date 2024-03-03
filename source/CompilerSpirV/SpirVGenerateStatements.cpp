/*
See LICENSE file in root folder
*/
#include "SpirVGenerateStatements.hpp"

#include "SpirVGetSwizzleComponents.hpp"
#include "SpirVDebugHelpers.hpp"
#include "SpirVHelpers.hpp"
#include "SpirVIntrinsicConfig.hpp"
#include "SpirVIntrinsicNames.hpp"
#include "SpirVMakeAccessChain.hpp"
#include "SpirVStorageImageAccessConfig.hpp"
#include "SpirVStorageImageAccessNames.hpp"
#include "SpirVCombinedImageAccessConfig.hpp"
#include "SpirVCombinedImageAccessNames.hpp"

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
	namespace vis
	{
		namespace helpers
		{
			class HasFnCall
				: public ast::expr::SimpleVisitor
			{
			public:
				static bool submit( ast::expr::Expr const & expr )
				{
					bool result{ false };
					HasFnCall vis{ result };
					expr.accept( &vis );
					return result;
				}

			private:
				explicit HasFnCall( bool & result )
					: m_result{ result }
				{
				}

			private:
				void visitUnaryExpr( ast::expr::Unary const * expr )override
				{
					expr->getOperand()->accept( this );
				}

				void visitBinaryExpr( ast::expr::Binary const * expr )override
				{
					expr->getLHS()->accept( this );
					expr->getRHS()->accept( this );
				}

				void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
				{
					if ( expr->hasIdentifier() )
					{
						expr->getIdentifier().accept( this );
					}

					for ( auto & arg : expr->getInitialisers() )
					{
						arg->accept( this );
					}
				}

				void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}

				void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
				{
					expr->getOuterExpr()->accept( this );
				}

				void visitFnCallExpr( ast::expr::FnCall const * expr )override
				{
					expr->getFn()->accept( this );

					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}

					m_result = true;
				}

				void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}

					m_result = true;
				}

				void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}

					m_result = true;
				}

				void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}

					m_result = true;
				}

				void visitIdentifierExpr( ast::expr::Identifier const * expr )override
				{
				}

				void visitInitExpr( ast::expr::Init const * expr )override
				{
					if ( expr->hasIdentifier() )
					{
						expr->getIdentifier().accept( this );
					}

					expr->getInitialiser()->accept( this );
				}

				void visitLiteralExpr( ast::expr::Literal const * expr )override
				{
				}

				void visitQuestionExpr( ast::expr::Question const * expr )override
				{
					expr->getCtrlExpr()->accept( this );
					expr->getTrueExpr()->accept( this );
					expr->getFalseExpr()->accept( this );
				}

				void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
				{
					expr->getOperand()->accept( this );
				}

				void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
				{
					expr->getLabel()->accept( this );
				}

				void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
				{
					expr->getValue()->accept( this );
				}

				void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
				{
					expr->getOuterExpr()->accept( this );
				}

			private:
				bool & m_result;
			};

			static std::string adaptName( std::string const & name )
			{
				static std::map< std::string, std::string, std::less<> > const names
				{
					{ "gl_InstanceID", "gl_InstanceIndex" },
					{ "gl_VertexID", "gl_VertexIndex" },
				};

				if ( auto it = names.find( name );
					it != names.end() )
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
					result = int32_t( lit.getValue< ast::expr::LiteralType::eInt8 >() );
					break;
				case ast::expr::LiteralType::eInt16:
					result = int32_t( lit.getValue< ast::expr::LiteralType::eInt16 >() );
					break;
				case ast::expr::LiteralType::eInt32:
					result = int32_t( lit.getValue< ast::expr::LiteralType::eInt32 >() );
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
		}

		class ExprVisitor
			: public ast::expr::SimpleVisitor
		{
		public:
			static DebugId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr const & expr
				, PreprocContext const & context
				, Block & currentBlock
				, Module & shaderModule
				, glsl::Statement * currentDebugStatement )
			{
				bool allLiterals{ false };
				return submit( exprCache
					, expr
					, context
					, currentBlock
					, shaderModule
					, allLiterals
					, currentDebugStatement );
			}

			static DebugId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr const & expr
				, PreprocContext const & context
				, Block & currentBlock
				, Module & shaderModule
				, DebugId initialiser
				, bool hasFuncInit
				, glsl::Statement * currentDebugStatement )
			{
				bool allLiterals{ false };
				return submit( exprCache
					, expr
					, context
					, currentBlock
					, shaderModule
					, allLiterals
					, std::move( initialiser )
					, hasFuncInit
					, currentDebugStatement );
			}

			static DebugId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr const & expr
				, PreprocContext const & context
				, Block & currentBlock
				, Module & shaderModule
				, bool & allLiterals
				, glsl::Statement * currentDebugStatement )
			{
				DebugId result{ 0u, expr.getType() };
				ExprVisitor vis{ result
					, exprCache
					, context
					, currentBlock
					, shaderModule
					, allLiterals
					, currentDebugStatement };
				expr.accept( &vis );

				if ( expr.isNonUniform() )
				{
					shaderModule.decorate( result, spv::DecorationNonUniform );
				}

				return result;
			}

			static DebugId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr const & expr
				, PreprocContext const & context
				, Block & currentBlock
				, Module & shaderModule
				, bool & allLiterals
				, DebugId initialiser
				, bool hasFuncInit
				, glsl::Statement * currentDebugStatement )
			{
				DebugId result{ 0u, expr.getType() };
				ExprVisitor vis{ result
					, exprCache
					, context
					, currentBlock
					, shaderModule
					, allLiterals
					, std::move( initialiser )
					, hasFuncInit
					, currentDebugStatement };
				expr.accept( &vis );
				return result;
			}

		private:
			ExprVisitor( DebugId & result
				, ast::expr::ExprCache & exprCache
				, PreprocContext const & context
				, Block & currentBlock
				, Module & shaderModule
				, bool & allLiterals
				, glsl::Statement * currentDebugStatement )
				: m_exprCache{ exprCache }
				, m_context{ context }
				, m_typesCache{ shaderModule.getTypesCache() }
				, m_currentDebugStatement{ currentDebugStatement }
				, m_result{ result }
				, m_currentBlock{ currentBlock }
				, m_module{ shaderModule }
				, m_allLiterals{ allLiterals }
				, m_allocator{ shaderModule.allocator }
				, m_initialiser{ 0u }
			{
			}

			ExprVisitor( DebugId & result
				, ast::expr::ExprCache & exprCache
				, PreprocContext const & context
				, Block & currentBlock
				, Module & shaderModule
				, bool & allLiterals
				, DebugId initialiser
				, bool hasFuncInit
				, glsl::Statement * currentDebugStatement )
				: m_exprCache{ exprCache }
				, m_context{ context }
				, m_typesCache{ shaderModule.getTypesCache() }
				, m_currentDebugStatement{ currentDebugStatement }
				, m_result{ result }
				, m_currentBlock{ currentBlock }
				, m_module{ shaderModule }
				, m_allLiterals{ allLiterals }
				, m_allocator{ shaderModule.allocator }
				, m_initialiser{ std::move( initialiser ) }
				, m_hasFuncInit{ hasFuncInit }
			{
			}

			DebugId doSubmit( ast::expr::Expr const & expr )
			{
				return submit( m_exprCache, expr, m_context, m_currentBlock, m_module, m_currentDebugStatement );
			}

			DebugId doSubmit( ast::expr::Expr const & expr
				, DebugId initialiser
				, bool hasFuncInit )
			{
				return submit( m_exprCache, expr, m_context, m_currentBlock, m_module, std::move( initialiser ), hasFuncInit, m_currentDebugStatement );
			}

			DebugId doSubmit( ast::expr::Expr const & expr
				, bool & allLiterals )
			{
				return submit( m_exprCache, expr, m_context, m_currentBlock, m_module, allLiterals, m_currentDebugStatement );
			}

			glsl::RangeInfo getColumnData( ast::expr::Expr const & expr )const
			{
				return glsl::getColumnData( m_currentDebugStatement, expr );
			}

			template< typename ValueT >
			DebugId registerLiteral( ValueT value )
			{
				return m_module.registerLiteral( value );
			}

			DebugId registerLiteral( DebugIdList const & value, ast::type::TypePtr type )
			{
				return m_module.registerLiteral( value, type );
			}

			TypeId registerPointerType( TypeId type
				, spv::StorageClass storage
				, bool isForward = false )
			{
				return m_module.registerPointerType( std::move( type ), storage, isForward );
			}

			TypeId registerType( ast::type::TypePtr type
				, glsl::Statement const * debugStatement )
			{
				return m_module.registerType( type, debugStatement );
			}

			TypeId registerImageType( ast::type::CombinedImagePtr textureType )
			{
				return m_module.registerImageType( textureType->getImageType(), textureType->isComparison() );
			}

			DebugId mergeSamplerImage( DebugId const & imageId
				, DebugId const & samplerId )
			{
				return m_module.mergeSamplerImage( imageId
					, samplerId
					, m_currentBlock );
			}

			NamesCache & getNameCache()
			{
				return m_module.getNameCache();
			}

			DebugId registerVariable( std::string const & name
				, ast::Builtin builtin
				, spv::StorageClass storage
				, bool isAlias
				, bool isParam
				, bool isOutParam
				, ast::type::TypePtr type
				, VariableInfo & sourceInfo
				, DebugId const & initialiser = DebugId{} )
			{
				return m_module.registerVariable( m_currentBlock
					, name
					, builtin
					, storage
					, isAlias
					, isParam
					, isOutParam
					, std::move( type )
					, sourceInfo
					, initialiser
					, m_currentDebugStatement ).id;
			}

			DebugId getVariablePointer( DebugId varId
				, std::string name
				, spv::StorageClass storage
				, ast::expr::Expr const & expr )
			{
				return m_module.getVariablePointer( m_currentBlock
					, std::move( varId )
					, std::move( name )
					, storage
					, m_currentBlock
					, m_currentDebugStatement
					, getColumnData( expr ) );
			}

			void decorate( DebugId const & id
				, spv::Decoration decoration )
			{
				m_module.decorate( id, decoration );
			}

			VariableInfo registerAlias( std::string name
				, ast::type::TypePtr type
				, DebugId result )
			{
				return m_module.registerAlias( std::move( name )
					, type
					, std::move( result ) );
			}

			DebugId getIntermediateResult( ast::type::TypePtr type )
			{
				return DebugId{ m_module.getIntermediateResult(), type };
			}

			uint32_t getVersion()const
			{
				return m_module.getVersion();
			}

			DebugId loadVariable( DebugId const & variableId
				, ast::expr::Expr const & expr )
			{
				TraceFunc;
				return m_module.loadVariable( variableId
					, m_currentBlock
					, m_currentDebugStatement
					, getColumnData( expr ) );
			}

			void storeVariable( DebugId const & variableId
				, DebugId const & valueId
				, ast::expr::Expr const & expr )
			{
				TraceFunc;
				m_module.storeVariable( variableId
					, valueId
					, m_currentBlock
					, m_currentDebugStatement
					, getColumnData( expr ) );
			}

			void storePromoted( DebugId const & variableId
				, VariableInfo const & sourceInfo
				, ast::expr::Expr const & expr )
			{
				TraceFunc;
				m_module.storePromoted( variableId
					, sourceInfo
					, m_currentBlock
					, m_currentDebugStatement
					, getColumnData( expr ) );
			}

			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto operandId = loadVariable( doSubmit( *expr->getOperand() ), *expr->getOperand() );
				auto typeId = registerType( expr->getType(), nullptr );
				m_result = getIntermediateResult( typeId->type );

				if ( expr->isSpecialisationConstant() )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( getNameCache()
						, typeId.id
						, m_result.id
						, makeOperands( m_allocator
							, ValueId{ spv::Id( getUnOpCode( expr->getKind(), expr->getType()->getKind() ) ) }
							, operandId ) ) );
				}
				else
				{
					m_currentBlock.instructions.emplace_back( makeUnInstruction( getNameCache()
						, typeId.id
						, m_result.id
						, expr->getKind()
						, expr->getType()->getKind()
						, operandId.id ) );
				}
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto lhsId = loadVariable( doSubmit( *expr->getLHS() ), *expr->getLHS() );
				auto rhsId = loadVariable( doSubmit( *expr->getRHS() ), *expr->getRHS() );
				auto typeId = registerType( expr->getType(), nullptr );
				m_result = getIntermediateResult( typeId->type );

				if ( expr->isSpecialisationConstant() )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( getNameCache()
						, typeId.id
						, m_result.id
						, makeBinOpOperands( m_allocator
							, expr->getKind()
							, expr->getLHS()->getType()->getKind()
							, expr->getRHS()->getType()->getKind()
							, lhsId.id
							, rhsId.id ) ) );
				}
				else
				{
					m_currentBlock.instructions.emplace_back( makeBinInstruction( getNameCache()
						, typeId.id
						, m_result.id
						, expr->getKind()
						, expr->getLHS()->getType()->getKind()
						, expr->getRHS()->getType()->getKind()
						, lhsId.id
						, rhsId.id ) );
				}
			}

			void visitCastExpr( ast::expr::Cast const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto operandId = loadVariable( doSubmit( *expr->getOperand() ), *expr->getOperand() );
				auto dstTypeId = registerType( expr->getType(), nullptr );
				auto op = helpers::getCastOp( expr->getOperand()->getType()->getKind()
					, expr->getType()->getKind() );

				if ( op == spv::OpNop )
				{
					m_result = operandId;
				}
				else
				{
					m_result = getIntermediateResult( dstTypeId->type );

					if ( expr->isSpecialisationConstant() )
					{
						m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( getNameCache()
							, dstTypeId.id
							, m_result.id
							, makeOperands( m_allocator
								, ValueId{ spv::Id( op ) }
								, operandId ) ) );
					}
					else
					{
						m_currentBlock.instructions.emplace_back( makeCastInstruction( getNameCache()
							, dstTypeId.id
							, m_result.id
							, op
							, operandId.id ) );
					}
				}
			}

			void visitCommaExpr( ast::expr::Comma const * expr )override
			{
				TraceFunc;
				registerType( expr->getType(), nullptr );
				doSubmit( *expr->getLHS() );
				m_result = doSubmit( *expr->getRHS() );
			}

			void visitCopyExpr( ast::expr::Copy const * expr )override
			{
				auto operandId = loadVariable( doSubmit( *expr->getOperand() ), *expr->getOperand() );
				auto dstTypeId = registerType( expr->getType(), nullptr );
				m_result = getIntermediateResult( dstTypeId->type );
				m_currentBlock.instructions.emplace_back( makeInstruction< CopyObjectInstruction >( getNameCache()
					, dstTypeId.id
					, m_result.id
					, operandId.id ) );
			}

			void visitAssignExpr( ast::expr::Assign const * expr )override
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
					auto rhsId = loadVariable( doSubmit( *expr->getRHS() ), *expr->getRHS() );

					auto lhsOuter = lhsSwizzle.getOuterExpr();
					assert( lhsOuter->getKind() == ast::expr::Kind::eIdentifier
						|| isAccessChain( *lhsOuter ) );

					if ( lhsSwizzleKind.isOneComponent() )
					{
						// One component swizzles must be processed separately:
						// - Create an access chain to the selected component.
						//   No load to retrieve the variable ID.
						auto lhsId = getVariablePointer( *lhsOuter );
						//   Register component selection as a literal.
						auto componentId = registerLiteral( lhsSwizzleKind.toIndex() );
						//   Register pointer type.
						auto typeId = registerType( lhsSwizzle.getType(), nullptr );
						//   Retrieve outermost identifier, to be able to retrieve its variable's storage class.
						auto lhsOutermost = ast::getOutermostExpr( *lhsOuter );
						assert( lhsOutermost->getKind() == ast::expr::Kind::eIdentifier );
						auto pointerTypeId = registerPointerType( typeId
							, getStorageClass( getVersion(), static_cast< ast::expr::Identifier const & >( *lhsOutermost ).getVariable() ) );
						//   Create the access chain.
						auto intermediateId = getIntermediateResult( pointerTypeId->type );
						m_currentBlock.writeAccessChain( intermediateId
							, pointerTypeId
							, makeOperands( m_allocator, lhsId, componentId )
							, m_module );
						// - Store the RHS into this access chain.
						storeVariable( intermediateId, rhsId, *expr );
						m_result = intermediateId;
					}
					else
					{
						// - No load to retrieve the variable ID.
						auto lhsId = getVariablePointer( *lhsOuter );
						// - Load the variable manually.
						auto loadedLhsId = loadVariable( lhsId, *lhsOuter );
						// - The resulting shuffle indices will contain the RHS values for wanted LHS components,
						//   and LHS values for the remaining ones.
						auto typeId = registerType( lhsOuter->getType(), nullptr );
						DebugIdList shuffle{ m_allocator };
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

						for ( auto & swizzleComponent : convert( getSwizzleComponents( m_allocator
							, lhsSwizzleKind
							, rhsSwizzleKind
							, getComponentCount( lhsOuter->getType()->getKind() ) ) ) )
						{
							shuffle.emplace_back( swizzleComponent );
						}

						auto intermediateId = getIntermediateResult( typeId->type );
						m_currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( getNameCache()
							, typeId.id
							, intermediateId.id
							, convert( shuffle ) ) );
						storeVariable( lhsId, intermediateId, *expr );
						m_result = lhsId;
					}
				}
				else
				{
					// No load to retrieve the variable ID.
					auto lhsId = getVariablePointer( *expr->getLHS() );
					// Ask for the needed variables to be loaded.
					auto rhsId = loadVariable( doSubmit( *expr->getRHS() ), *expr->getRHS() );
					storeVariable( lhsId, rhsId, *expr );
					m_result = lhsId;
				}
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
			{
				TraceFunc;
				bool allLiterals = true;
				bool hasFuncInit = false;
				auto init = visitInitialisers( expr->getInitialisers()
					, expr->getType()
					, allLiterals
					, hasFuncInit );

				if ( expr->hasIdentifier() )
				{
					auto var = expr->getIdentifier().getVariable();
					initialiseVariable( init
						, allLiterals
						, hasFuncInit
						, expr->getIdentifier().getVariable()
						, expr->getType()
						, *expr );
				}
				else
				{
					m_result = init;
				}

				m_allLiterals = false;
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				m_result = makeAccessChain( m_exprCache
					, *expr
					, m_context
					, m_module
					, m_currentBlock
					, m_currentDebugStatement );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				m_result = makeAccessChain( m_exprCache
					, *expr
					, m_context
					, m_module
					, m_currentBlock
					, m_currentDebugStatement );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
			{
				TraceFunc;
				bool allLiterals = true;

				if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
				{
					auto it = expr->getArgList().begin();
					auto imageId = loadVariable( doSubmit( **it, allLiterals ), **it );
					++it;

					bool allLitsInit = true;
					auto samplerId = loadVariable( doSubmit( **it, allLitsInit ), **it );
					allLiterals = allLiterals && allLitsInit;

					m_result = mergeSamplerImage( imageId, samplerId );
				}
				else
				{
					DebugIdList params{ m_allocator };
					auto paramsCount = 0u;

					for ( auto & arg : expr->getArgList() )
					{
						bool allLitsInit = true;
						params.push_back( loadVariable( doSubmit( *arg, allLitsInit ), *arg ) );
						allLiterals = allLiterals && allLitsInit;
						paramsCount += ast::type::getComponentCount( arg->getType()->getKind() );
					}

					auto retCount = ast::type::getComponentCount( expr->getType()->getKind() )
						* ast::type::getComponentCount( ast::type::getComponentType( expr->getType()->getKind() ) );
					auto typeId = registerType( expr->getType(), nullptr );

					if ( paramsCount == 1u && retCount != 1u )
					{
						params.resize( retCount, params.back() );
						paramsCount = retCount;
					}

					if ( allLiterals )
					{
						assert( paramsCount == retCount );
						m_result = registerLiteral( params, expr->getType() );
					}
					else
					{
						m_result = getIntermediateResult( typeId->type );
						m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( getNameCache()
							, typeId.id
							, m_result.id
							, convert( params ) ) );
					}
				}

				m_allLiterals = m_allLiterals && allLiterals;
			}

			void visitFnCallExpr( ast::expr::FnCall const * expr )override
			{
				TraceFunc;
				DebugIdList params{ m_allocator };
				bool allLiterals = true;
				auto type = expr->getFn()->getType();
				assert( type->getKind() == ast::type::Kind::eFunction );
				auto fnType = std::static_pointer_cast< ast::type::Function >( type );
				assert( expr->getArgList().size() == fnType->size() );
				auto it = fnType->begin();

				struct OutputParam
				{
					OutputParam( DebugId psrc
						, DebugId pdst
						, ast::type::TypePtr ptype )
						: src{ std::move( psrc ) }
						, dst{ std::move( pdst ) }
						, type{ std::move( ptype ) }
					{
					}

					DebugId src;
					DebugId dst;
					ast::type::TypePtr type;
				};
				ast::Vector< OutputParam > outputParams{ m_allocator };

				for ( auto & arg : expr->getArgList() )
				{
					auto & param = *it;
					DebugId id;

					if ( isPointerParam( *param ) )
					{
						// Opaque and Output function parameters are pointers, hence their variables must not be loaded.
						id = getVariablePointer( *arg );
						assert( !isOpaqueType( param->getType()->getKind() )
							|| id.getStorage() == ast::type::Storage::eUniformConstant );

						if ( param->isOutputParam()
							&& id.getStorage() != ast::type::Storage::eFunction )
						{
							// We must have a variable with function storage class.
							// Hence we create a temporary variable with this storage class,
							// and load the original variable into it.
							auto srcId = id;
							id = makeFunctionAlias( srcId, arg->getType(), *arg );
							outputParams.emplace_back( srcId, id, arg->getType() );
						}
						else
						{
							m_currentBlock.modifyVariable( id );
						}
					}
					else
					{
						id = loadVariable( doSubmit( *arg ), *arg );
					}

					allLiterals = allLiterals
						&& ( arg->getKind() == ast::expr::Kind::eLiteral );
					params.push_back( id );
					++it;
				}

				auto typeId = registerType( expr->getType(), nullptr );
				auto fnId = doSubmit( *expr->getFn() );
				params.insert( params.begin(), fnId );
				m_result = getIntermediateResult( typeId->type );
				m_currentBlock.instructions.emplace_back( makeInstruction< FunctionCallInstruction >( getNameCache()
					, typeId.id
					, m_result.id
					, convert( params ) ) );

				for ( auto const & param : outputParams )
				{
					auto loadedId = loadVariable( param.dst, *expr );
					storeVariable( param.src, loadedId, *expr );
				}

				m_allLiterals = m_allLiterals && allLiterals;
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto var = expr->getVariable();

				if ( var->getBuiltin() == ast::Builtin::eWorkGroupSize )
				{
					m_result = DebugId{ m_context.workGroupSizeExpr };
				}
				else if ( var->isMemberVar() )
				{
					m_result = makeAccessChain( m_exprCache
						, *expr
						, m_context
						, m_module
						, m_currentBlock
						, m_currentDebugStatement );
				}
				else
				{
					initialiseVariable( m_initialiser
						, true
						, m_hasFuncInit
						, var
						, expr->getType()
						, *expr );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto isStore = expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageStore1DF
					&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageStore2DMSArrayU;
				auto paramType = expr->getArgList()[0]->getType();
				assert( paramType->getKind() == ast::type::Kind::eImage );
				auto imageVarId = doSubmit( *expr->getArgList()[0].get() );
				auto imageType = std::static_pointer_cast< ast::type::Image >( paramType );
				auto intermediateId = loadVariable( imageVarId, *expr->getArgList()[0].get() );
				DebugIdList params{ m_allocator };
				params.push_back( intermediateId );

				for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
				{
					auto & arg = ( *it );
					params.push_back( loadVariable( doSubmit( *arg ), *arg ) );
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
					params.emplace_back( spv::ImageOperandsSampleMask );
					params.push_back( sample );
				}

				IntrinsicConfig config;
				getSpirVConfig( expr->getImageAccess(), config );
				auto op = getSpirVName( expr->getImageAccess() );

				if ( isStore )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< ImageStoreInstruction >( getNameCache()
						, convert( params ) ) );
				}
				else if ( !config.needsTexelPointer )
				{
					auto typeId = registerType( expr->getType(), nullptr );
					m_result = getIntermediateResult( typeId->type );
					m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( getNameCache()
						, typeId.id
						, m_result.id
						, op
						, convert( params ) ) );
				}
				else
				{
					DebugIdList texelPointerParams{ m_allocator };
					uint32_t index = 0u;
					assert( imageVarId.isPointer() );
					texelPointerParams.push_back( imageVarId );
					++index;
					texelPointerParams.push_back( params[index] );
					++index;

					if ( imageType->getConfig().isMS )
					{
						texelPointerParams.push_back( params[index] );
						++index;
					}
					else
					{
						texelPointerParams.push_back( registerLiteral( 0u ) );
					}

					assert( expr->getArgList()[0]->getKind() == ast::expr::Kind::eIdentifier );
					auto imgParam = static_cast< ast::expr::Identifier const & >( *expr->getArgList()[0] ).getType();
					assert( imgParam->getKind() == ast::type::Kind::eImage );
					auto image = std::static_pointer_cast< ast::type::Image >( imgParam );
					auto sampledType = m_typesCache.getBasicType( image->getConfig().sampledType );
					auto sampledId = registerType( sampledType, nullptr );
					auto pointerTypeId = registerPointerType( sampledId
						, spv::StorageClassImage );
					auto pointerId = getIntermediateResult( pointerTypeId->type );
					m_currentBlock.instructions.emplace_back( makeInstruction< ImageTexelPointerInstruction >( getNameCache()
						, pointerTypeId.id
						, pointerId.id
						, convert( texelPointerParams ) ) );

					auto scopeId = registerLiteral( uint32_t( spv::ScopeDevice ) );
					DebugIdList accessParams{ m_allocator };
					accessParams.push_back( pointerId );
					accessParams.push_back( scopeId );

					if ( op == spv::OpAtomicCompareExchange )
					{
						auto equalMemorySemanticsId = registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
						auto unequalMemorySemanticsId = registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
						accessParams.push_back( equalMemorySemanticsId );
						accessParams.push_back( unequalMemorySemanticsId );
					}
					else
					{
						auto memorySemanticsId = registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
						accessParams.push_back( memorySemanticsId );
					}

					if ( params.size() > index )
					{
						accessParams.insert( accessParams.end()
							, params.begin() + index
							, params.end() );
					}


					auto typeId = registerType( expr->getType(), nullptr );
					m_result = getIntermediateResult( typeId->type );
					m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( getNameCache()
						, typeId.id
						, m_result.id
						, op
						, convert( accessParams ) ) );
				}
			}

			void visitInitExpr( ast::expr::Init const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				registerType( expr->getType(), nullptr );
				bool allLiterals = true;
				auto init = loadVariable( doSubmit( *expr->getInitialiser(), allLiterals ), *expr->getInitialiser() );
				bool hasFuncInit = helpers::HasFnCall::submit( *expr );

				if ( expr->hasIdentifier() )
				{
					initialiseVariable( init
						, allLiterals
						, hasFuncInit
						, expr->getIdentifier().getVariable()
						, expr->getType()
						, *expr );
				}
				else
				{
					m_result = init;
				}
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
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

			void visitLiteralExpr( ast::expr::Literal const * expr )override
			{
				TraceFunc;
				switch ( expr->getLiteralType() )
				{
				case ast::expr::LiteralType::eBool:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eBool >() );
					break;
				case ast::expr::LiteralType::eInt8:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eInt8 >() );
					break;
				case ast::expr::LiteralType::eInt16:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eInt16 >() );
					break;
				case ast::expr::LiteralType::eInt32:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eInt32 >() );
					break;
				case ast::expr::LiteralType::eInt64:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eInt64 >() );
					break;
				case ast::expr::LiteralType::eUInt8:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt8 >() );
					break;
				case ast::expr::LiteralType::eUInt16:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt16 >() );
					break;
				case ast::expr::LiteralType::eUInt32:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt32 >() );
					break;
				case ast::expr::LiteralType::eUInt64:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt64 >() );
					break;
				case ast::expr::LiteralType::eFloat:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eFloat >() );
					break;
				case ast::expr::LiteralType::eDouble:
					m_result = registerLiteral( expr->getValue< ast::expr::LiteralType::eDouble >() );
					break;
				default:
					AST_Failure( "Unsupported literal type" );
					break;
				}
			}

			void visitQuestionExpr( ast::expr::Question const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				auto ctrlId = loadVariable( doSubmit( *expr->getCtrlExpr() ), *expr->getCtrlExpr() );
				auto trueId = loadVariable( doSubmit( *expr->getTrueExpr() ), *expr->getTrueExpr() );
				auto falseId = loadVariable( doSubmit( *expr->getFalseExpr() ), *expr->getFalseExpr() );
				auto type = registerType( expr->getType(), nullptr );
				m_result = getIntermediateResult( type->type );
				auto branches = makeOperands( m_allocator, ctrlId, trueId, falseId );

				if ( expr->getCtrlExpr()->isSpecialisationConstant() )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( getNameCache()
						, type.id
						, m_result.id
						, makeOperands( m_allocator, ValueId{ spv::Id( spv::OpSelect ) }, branches ) ) );
				}
				else
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< SelectInstruction >( getNameCache()
						, type.id
						, m_result.id
						, branches ) );
				}
			}

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;

				if ( expr->getSwizzle().isOneComponent()
					&& expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier
					&& !static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->isTempVar()
					&& static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getBuiltin() != ast::Builtin::eWorkGroupSize )
				{
					m_result = loadVariable( makeAccessChain( m_exprCache
							, *expr
							, m_context
							, m_module
							, m_currentBlock
							, m_currentDebugStatement )
						, *expr );
				}
				else
				{
					m_result = loadVariable( makeVectorShuffle( m_exprCache
							, *expr
							, m_context
							, m_module
							, m_currentBlock
							, m_currentDebugStatement )
						, *expr );
				}
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				DebugIdList args{ m_allocator };
				bool first = true;

				for ( auto & arg : expr->getArgList() )
				{
					auto argId = doSubmit( *arg );
					args.emplace_back( argId );

					if ( !first )
					{
						args.back() = loadVariable( argId, *arg );
					}

					first = false;
				}

				auto typeId = registerType( expr->getType(), nullptr );
				auto kind = expr->getCombinedImageAccess();
				IntrinsicConfig config;
				getSpirVConfig( kind, config );
				auto op = getSpirVName( kind );

				// Load the sampled image variable
				auto sampledImageType = expr->getArgList()[0]->getType();
				assert( sampledImageType->getKind() == ast::type::Kind::eCombinedImage );
				args[0] = loadVariable( args[0], *expr->getArgList()[0] );

				if ( expr->getArgList().front()->isNonUniform() )
				{
					decorate( args[0], spv::DecorationNonUniform );
				}

				if ( config.needsImage )
				{
					// We need to extract the image from the sampled image, to give it to the final instruction.
					auto textureType = std::static_pointer_cast< ast::type::CombinedImage >( sampledImageType );
					auto imageTypeId = registerImageType( textureType );
					auto imageId = getIntermediateResult( imageTypeId->type );
					m_currentBlock.instructions.emplace_back( makeInstruction< ImageInstruction >( getNameCache()
						, imageTypeId.id
						, imageId.id
						, args[0].id ) );
					args[0] = imageId;
				}

				if ( config.imageOperandsIndex )
				{
					assert( args.size() >= config.imageOperandsIndex );
					bool constOffset = false;

					if ( config.offsetIndex )
					{
						assert( expr->getArgList().size() >= config.offsetIndex );
						constOffset = expr->getArgList()[config.offsetIndex - 1ULL]->isConstant();
					}

					auto mask = getMask( kind, constOffset );
					auto it = args.begin() + config.imageOperandsIndex;
					it = args.emplace( it, spv::Id( mask ) );
					++it;
				}

				m_result = getIntermediateResult( typeId->type );
				m_currentBlock.instructions.emplace_back( makeTextureAccessInstruction( getNameCache()
					, typeId.id
					, m_result.id
					, op
					, convert( args ) ) );
			}

			void visitAliasExpr( ast::expr::Alias const * expr )override
			{
				TraceFunc;
				m_result = submit( m_exprCache
					, *expr->getAliasedExpr()
					, m_context
					, m_currentBlock
					, m_module
					, m_currentDebugStatement );

				if ( expr->hasIdentifier() )
				{
					auto var = expr->getIdentifier().getVariable();
					registerAlias( var->getName()
						, var->getType()
						, m_result );
				}
			}

			void visitPreDecrementExpr( ast::expr::PreDecrement const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreDecrement expression." );
			}

			void visitPreIncrementExpr( ast::expr::PreIncrement const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PreIncrement expression." );
			}

			void visitPostDecrementExpr( ast::expr::PostDecrement const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PostDecrement expression." );
			}

			void visitPostIncrementExpr( ast::expr::PostIncrement const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::PostIncrement expression." );
			}

			void visitUnaryPlusExpr( ast::expr::UnaryPlus const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::UnaryPlus expression." );
			}

			void visitAddAssignExpr( ast::expr::AddAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::AddAssign expression." );
			}

			void visitAndAssignExpr( ast::expr::AndAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::AndAssign expression." );
			}

			void visitDivideAssignExpr( ast::expr::DivideAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::DivideAssign expression." );
			}

			void visitLShiftAssignExpr( ast::expr::LShiftAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::LShiftAssign expression." );
			}

			void visitMinusAssignExpr( ast::expr::MinusAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::MinusAssign expression." );
			}

			void visitModuloAssignExpr( ast::expr::ModuloAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::ModuloAssign expression." );
			}

			void visitOrAssignExpr( ast::expr::OrAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::OrAssign expression." );
			}

			void visitRShiftAssignExpr( ast::expr::RShiftAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::RShiftAssign expression." );
			}

			void visitTimesAssignExpr( ast::expr::TimesAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::TimesAssign expression." );
			}

			void visitXorAssignExpr( ast::expr::XorAssign const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::XorAssign expression." );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend expression." );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchCase expression." );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchTest expression." );
			}

		private:
			void handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall const * expr )
			{
				TraceFunc;
				// Arg 1 is lhs.
				// Arg 2 is rhs.
				// Arg 3 is carry or borrow.
				assert( expr->getArgList().size() == 3u );
				DebugIdList params{ m_allocator };
				params.push_back( loadVariable( doSubmit( *expr->getArgList()[0].get() ), *expr->getArgList()[0].get() ) );
				params.push_back( loadVariable( doSubmit( *expr->getArgList()[1].get() ), *expr->getArgList()[1].get() ) );

				auto resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( expr->getType()->getKind() )
					? getComponentCount( expr->getType()->getKind() )
					: 1 );
				auto resultCarryBorrowId = getIntermediateResult( resultStructTypeId->type );
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( getNameCache()
					, resultStructTypeId.id
					, resultCarryBorrowId.id
					, opCode
					, convert( params ) ) );

				auto const & carryBorrowArg = *expr->getArgList()[2];
				auto carryBorrowTypeId = registerType( carryBorrowArg.getType(), nullptr );
				auto intermediateId = getIntermediateResult( carryBorrowTypeId->type );
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( getNameCache()
					, carryBorrowTypeId.id
					, intermediateId.id
					, makeOperands( m_allocator, resultCarryBorrowId, ValueId{ 1u } ) ) );
				auto carryBorrowId = getVariablePointer( carryBorrowArg );
				storeVariable( carryBorrowId, intermediateId, *expr );

				auto resultTypeId = registerType( expr->getType(), nullptr );
				m_result = getIntermediateResult( resultTypeId->type );
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( getNameCache()
					, resultTypeId.id
					, m_result.id
					, makeOperands( m_allocator, resultCarryBorrowId, ValueId{ 0u } ) ) );
			}

			void handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall const * expr )
			{
				TraceFunc;
				// Arg 1 is lhs.
				// Arg 2 is rhs.
				// Arg 3 is msb.
				// Arg 4 is lsb.
				assert( expr->getArgList().size() == 4u );
				DebugIdList params{ m_allocator };
				params.push_back( loadVariable( doSubmit( *expr->getArgList()[0].get() ), *expr->getArgList()[0].get() ) );
				params.push_back( loadVariable( doSubmit( *expr->getArgList()[1].get() ), *expr->getArgList()[1].get() ) );
				TypeId resultStructTypeId;

				if ( auto paramType = expr->getArgList()[0]->getType()->getKind();
					isSignedIntType( paramType ) )
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

				auto resultMulExtendedId = getIntermediateResult( resultStructTypeId->type );
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( getNameCache()
					, resultStructTypeId.id
					, resultMulExtendedId.id
					, opCode
					, convert( params ) ) );

				auto const & msbArg = *expr->getArgList()[2];
				auto msbTypeId = registerType( msbArg.getType(), nullptr );
				auto intermediateMsb = getIntermediateResult( msbTypeId->type );
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( getNameCache()
					, msbTypeId.id
					, intermediateMsb.id
					, makeOperands( m_allocator, resultMulExtendedId, ValueId{ 1u } ) ) );
				auto msbId = getVariablePointer( msbArg );
				storeVariable( msbId, intermediateMsb, *expr );

				auto const & lsbArg = *expr->getArgList()[3];
				auto lsbTypeId = registerType( lsbArg.getType(), nullptr );
				auto intermediateLsb = getIntermediateResult( lsbTypeId->type );
				m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( getNameCache()
					, lsbTypeId.id
					, intermediateLsb.id
					, makeOperands( m_allocator, resultMulExtendedId, ValueId{ 0u } ) ) );
				auto lsbId = getVariablePointer( lsbArg );
				storeVariable( lsbId, intermediateLsb, *expr );
			}

			void handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall const * expr )
			{
				TraceFunc;
				DebugIdList params{ m_allocator };
				params.push_back( doSubmit( *expr->getArgList()[0].get() ) );

				auto scopeId = registerLiteral( uint32_t( spv::ScopeDevice ) );
				auto memorySemanticsId = registerLiteral( uint32_t( spv::MemorySemanticsAcquireReleaseMask ) );
				params.push_back( scopeId );
				params.push_back( memorySemanticsId );

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eAtomicCompSwapI
					|| expr->getIntrinsic() == ast::expr::Intrinsic::eAtomicCompSwapU )
				{
					auto memorySemanticsUnequalId = registerLiteral( uint32_t( spv::MemorySemanticsAcquireMask ) );
					params.push_back( memorySemanticsUnequalId );
				}

				for ( auto i = 1u; i < expr->getArgList().size(); ++i )
				{
					params.push_back( loadVariable( doSubmit( *expr->getArgList()[i] ), *expr->getArgList()[i] ) );
				}

				auto typeId = registerType( expr->getType(), nullptr );
				m_result = getIntermediateResult( typeId->type );
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( getNameCache()
					, typeId.id
					, m_result.id
					, opCode
					, convert( params ) ) );
			}

			void handleExtensionIntrinsicCallExpr( spv::Id opCode, ast::expr::IntrinsicCall const * expr )
			{
				TraceFunc;
				auto intrinsic = expr->getIntrinsic();
				DebugIdList params{ m_allocator };

				if ( ( intrinsic >= ast::expr::Intrinsic::eModf1F
						&& intrinsic <= ast::expr::Intrinsic::eModf4D )
					|| ( intrinsic >= ast::expr::Intrinsic::eFrexp1F
						&& intrinsic <= ast::expr::Intrinsic::eFrexp4D ) )
				{
					// For modf and frexp intrinsics, second parameter is an output parameter,
					// hence we need to pass it as a pointer to the call.
					assert( expr->getArgList().size() == 2u );
					params.push_back( loadVariable( doSubmit( *expr->getArgList()[0] ), *expr->getArgList()[0] ) );
					params.push_back( doSubmit( *expr->getArgList()[1] ) );
				}
				else if ( intrinsic >= ast::expr::Intrinsic::eInterpolateAtCentroid1
					&& intrinsic <= ast::expr::Intrinsic::eInterpolateAtCentroid4 )
				{
					for ( auto & arg : expr->getArgList() )
					{
						params.push_back( getVariablePointer( doSubmit( *arg )
							, "interpolant_" + std::to_string( m_aliasId )
							, spv::StorageClassInput
							, *arg ) );
						++m_aliasId;
					}
				}
				else if ( intrinsic >= ast::expr::Intrinsic::eInterpolateAtSample1
					&& intrinsic <= ast::expr::Intrinsic::eInterpolateAtOffset4 )
				{
					auto & args = expr->getArgList();
					params.push_back( getVariablePointer( doSubmit( *args[0] )
						, "interpolant_" + std::to_string( m_aliasId )
						, spv::StorageClassInput
						, *args[0] ) );
						++m_aliasId;
					params.push_back( loadVariable( doSubmit( *args[1] ), *args[1] ) );
				}
				else
				{
					for ( auto & arg : expr->getArgList() )
					{
						params.push_back( loadVariable( doSubmit( *arg ), *arg ) );
					}
				}

				auto typeId = registerType( expr->getType(), nullptr );
				params.emplace( params.begin(), opCode );
				params.emplace( params.begin(), m_module.extGlslStd450 );
				m_result = getIntermediateResult( typeId->type );
				m_currentBlock.instructions.emplace_back( makeInstruction< ExtInstInstruction >( getNameCache()
					, typeId.id
					, m_result.id
					, convert( params ) ) );
			}

			void handleBarrierIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall const * expr )
			{
				TraceFunc;
				DebugIdList params{ m_allocator };

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier )
				{
					if ( expr->getArgList().size() < 3u )
					{
						throw ast::Exception{ "Wrong number of parameters for a control barrier" };
					}

					params.push_back( registerLiteral( spv::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[0] ) ) ) );
					params.push_back( registerLiteral( spv::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[1] ) ) ) );
					params.push_back( registerLiteral( spv::MemorySemanticsMask( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[2] ) ) ) );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
				{
					if ( expr->getArgList().size() < 2u )
					{
						throw ast::Exception{ "Wrong number of parameters for a memory barrier" };
					}

					params.push_back( registerLiteral( spv::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[0] ) ) ) );
					params.push_back( registerLiteral( spv::MemorySemanticsMask( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[1] ) ) ) );
				}

				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( getNameCache()
					, opCode
					, convert( params ) ) );
			}

			void handleSubgroupIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall const * expr )
			{
				TraceFunc;
				DebugIdList params{ m_allocator };
				params.push_back( registerLiteral( spv::ScopeSubgroup ) );

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupBallotBitCount
					|| ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupAdd1F
						&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupXor4B ) )
				{
					params.emplace_back( spv::GroupOperationReduce );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupBallotInclusiveBitCount
					|| ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupInclusiveAdd1F
						&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupInclusiveXor4B ) )
				{
					params.emplace_back( spv::GroupOperationInclusiveScan );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupBallotExclusiveBitCount
					|| ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupExclusiveAdd1F
						&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupExclusiveXor4B ) )
				{
					params.emplace_back( spv::GroupOperationExclusiveScan );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupClusterAdd1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupClusterXor4B )
				{
					params.emplace_back( spv::GroupOperationClusteredReduce );
				}

				for ( auto & arg : expr->getArgList() )
				{
					params.push_back( loadVariable( doSubmit( *arg ), *arg ) );
				}

				if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4D )
				{
					params.push_back( registerLiteral( 0u ) );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadSwapVertical1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapVertical4D )
				{
					params.push_back( registerLiteral( 1u ) );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D )
				{
					params.push_back( registerLiteral( 2u ) );
				}

				auto typeId = registerType( expr->getType(), nullptr );
				m_result = getIntermediateResult( typeId->type );
				m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( getNameCache()
					, typeId.id
					, m_result.id
					, opCode
					, convert( params ) ) );
			}

			void handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall const * expr )
			{
				TraceFunc;
				DebugIdList params{ m_allocator };

				for ( auto & arg : expr->getArgList() )
				{
					auto id = doSubmit( *arg );

					if ( arg->getType()->getRawKind() != ast::type::Kind::eRayPayload
						&& arg->getType()->getRawKind() != ast::type::Kind::eCallableData )
					{
						id = loadVariable( id, *arg );
					}

					params.push_back( id );
				}

				if ( ( opCode >= spv::OpEmitVertex && opCode <= spv::OpEndStreamPrimitive )
					|| opCode == spv::OpExecuteCallableKHR
					|| opCode == spv::OpTraceRayKHR
					|| opCode == spv::OpWritePackedPrimitiveIndices4x8NV
					|| opCode == spv::OpSetMeshOutputsEXT )
				{
					m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( getNameCache()
						, opCode
						, convert( params ) ) );
				}
				else
				{
					auto typeId = registerType( expr->getType(), nullptr );
					m_result = getIntermediateResult( typeId->type );
					m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( getNameCache()
						, typeId.id
						, m_result.id
						, opCode
						, convert( params ) ) );
				}
			}

			TypeId getUnsignedExtendedResultTypeId( uint32_t count )
			{
				TraceFunc;
				--count;

				if ( !m_unsignedExtendedTypes[count] )
				{
					std::string name = "SDW_ExtendedResultTypeU" + std::to_string( count + 1u );
					m_unsignedExtendedTypes[count] = m_typesCache.getStruct( ast::type::MemoryLayout::eC, name );

					if ( m_unsignedExtendedTypes[count]->empty() )
					{
						auto type = count == 3
							? m_typesCache.getVec4U32()
							: ( count == 2
								? m_typesCache.getVec3U32()
								: ( count == 1
									? m_typesCache.getVec2U32()
									: m_typesCache.getUInt32() ) );
						m_unsignedExtendedTypes[count]->declMember( "result", type );
						m_unsignedExtendedTypes[count]->declMember( "extended", type );
					}
				}

				return registerType( m_unsignedExtendedTypes[count], nullptr );
			}

			TypeId getSignedExtendedResultTypeId( uint32_t count )
			{
				TraceFunc;
				--count;

				if ( !m_signedExtendedTypes[count] )
				{
					std::string name = "SDW_ExtendedResultTypeS" + std::to_string( count + 1u );
					m_signedExtendedTypes[count] = m_typesCache.getStruct( ast::type::MemoryLayout::eC, name );

					if ( m_signedExtendedTypes[count]->empty() )
					{
						auto type = count == 3
							? m_typesCache.getVec4I32()
							: ( count == 2
								? m_typesCache.getVec3I32()
								: ( count == 1
									? m_typesCache.getVec2I32()
									: m_typesCache.getInt32() ) );
						m_signedExtendedTypes[count]->declMember( "result", type );
						m_signedExtendedTypes[count]->declMember( "extended", type );
					}
				}

				return registerType( m_signedExtendedTypes[count], nullptr );
			}

			DebugId getVariablePointer( ast::expr::Expr const & expr )
			{
				TraceFunc;
				DebugId result{ 0u, expr.getType() };

				if ( isAccessChain( expr ) )
				{
					result = doSubmit( expr );
				}
				else if ( auto ident = ast::findIdentifier( expr ) )
				{
					auto var = ident->getVariable();
					VariableInfo sourceInfo;
					auto name = helpers::adaptName( var->getName() );
					auto varInfo = registerVariable( name
						, var->getBuiltin()
						, getStorageClass( getVersion(), var )
						, false
						, false
						, var->isOutputParam()
						, expr.getType()
						, sourceInfo );
					result = varInfo;
					assert( result.isPointer() );

					if ( result.getStorage() != sourceInfo.id.getStorage() )
					{
						auto id = loadVariable( DebugId{ sourceInfo.id }, *ident );
						storeVariable( result, id, *ident );
					}
				}
				else
				{
					result = doSubmit( expr );

					if ( !result.isPointer() )
					{
						result = makeFunctionAlias( result, expr );
					}
				}

				assert( result.isPointer() );
				return result;
			}

			DebugId makeFunctionAlias( DebugId const & source
				, ast::type::TypePtr type
				, ast::expr::Expr const & expr )
			{
				TraceFunc;
				VariableInfo info;
				info.rvalue = true;
				auto result = registerVariable( "functmp_" + std::to_string( uintptr_t( type.get() ) ) + std::to_string( m_aliasId )
					, ast::Builtin::eNone
					, spv::StorageClassFunction
					, false
					, false
					, false
					, type
					, info );
				++m_aliasId;
				storeVariable( result, source, expr );
				return result;
			}

			DebugId makeFunctionAlias( DebugId const & source
				, ast::expr::Expr const & expr )
			{
				TraceFunc;
				return makeFunctionAlias( source, source->type, expr );
			}

			bool initialiseVariable( DebugId const & init
				, bool allLiterals
				, bool isFuncInit
				, ast::var::VariablePtr var
				, ast::type::TypePtr type
				, ast::expr::Expr const & expr )
			{
				TraceFunc;
				bool result{};
				spv::StorageClass storageClass{ getStorageClass( getVersion(), var ) };

				if ( allLiterals
					&& !var->isLoopVar()
					&& !isFuncInit )
				{
					VariableInfo sourceInfo;
					m_result = registerVariable( helpers::adaptName( var->getName() )
						, var->getBuiltin()
						, storageClass
						, var->isAlias()
						, var->isParam()
						, var->isOutputParam()
						, type
						, sourceInfo
						, init );
					result = sourceInfo.isAlias;
				}
				else if ( var->isAlias()
					&& !isFuncInit )
				{
					registerAlias( helpers::adaptName( var->getName() )
						, type
						, init );
					m_result = init;
				}
				else
				{
					VariableInfo sourceInfo;
					auto varInfo = registerVariable( helpers::adaptName( var->getName() )
						, var->getBuiltin()
						, storageClass
						, false
						, false
						, false
						, type
						, sourceInfo
						, DebugId{} );

					if ( varInfo )
					{
						m_result = varInfo;
						result = sourceInfo.isAlias;

						if ( init )
						{
							storeVariable( m_result, init, expr );
						}
						else if ( sourceInfo.needsStoreOnPromote() )
						{
							storePromoted( m_result, sourceInfo, expr );
						}
					}
				}

				return result;
			}

			DebugId visitInitialisers( ast::expr::ExprList const & inits
				, ast::type::TypePtr type
				, bool & allLiterals
				, bool & hasFuncInit )
			{
				TraceFunc;
				DebugIdList initialisers{ m_allocator };

				for ( auto & init : inits )
				{
					initialisers.push_back( loadVariable( doSubmit( *init, allLiterals ), *init ) );
					hasFuncInit = hasFuncInit || helpers::HasFnCall::submit( *init );
				}

				DebugId result{ 0u, type };

				if ( allLiterals )
				{
					result = registerLiteral( initialisers, type );
				}
				else
				{
					auto typeId = registerType( type, nullptr );
					result = getIntermediateResult( typeId->type );
					m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( getNameCache()
						, typeId.id
						, result.id
						, convert( initialisers ) ) );
				}

				return result;
			}

		private:
			ast::expr::ExprCache & m_exprCache;
			spirv::PreprocContext const & m_context;
			ast::type::TypesCache & m_typesCache;
			glsl::Statement * m_currentDebugStatement;
			DebugId & m_result;
			Block & m_currentBlock;
			Module & m_module;
			bool & m_allLiterals;
			ast::ShaderAllocatorBlock * m_allocator;
			DebugId m_initialiser;
			bool m_hasFuncInit{ false };
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
				, ast::stmt::Stmt const & stmt
				, ast::ShaderStage type
				, ModuleConfig const & moduleConfig
				, spirv::PreprocContext context
				, SpirVConfig const & spirvConfig
				, glsl::StmtConfig const & stmtConfig
				, ShaderActions actions
				, glsl::Statements debugStatements )
			{
				auto result = ModulePtr{ new Module{ &exprCache.getAllocator()
					, typesCache
					, spirvConfig
					, stmtConfig
					, moduleConfig.addressingModel
					, getMemoryModel()
					, getExecutionModel( type )
					, debugStatements } };
				StmtVisitor vis{ exprCache
					, *result
					, moduleConfig
					, std::move( context )
					, std::move( actions )
					, std::move( debugStatements ) };
				stmt.accept( &vis );
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
				, Module & result
				, ModuleConfig const & moduleConfig
				, spirv::PreprocContext context
				, ShaderActions actions
				, glsl::Statements debugStatements )
				: m_exprCache{ exprCache }
				, m_allocator{ &m_exprCache.getAllocator() }
				, m_moduleConfig{ moduleConfig }
				, m_context{ std::move( context ) }
				, m_actions{ std::move( actions ) }
				, m_result{ result }
				, m_debug{ m_result.getNonSemanticDebug() }
				, m_debugStatements{ std::move( debugStatements ) }
				, m_currentBlock{ m_allocator }
				, m_controlBlocks{ m_allocator }
				, m_inputs{ m_allocator }
				, m_outputs{ m_allocator }
			{
				moduleConfig.fillModule( m_result );
				VariableInfo info;

				m_currentDebugStatement = m_debugStatements.statements.begin();

				for ( auto & input : moduleConfig.getInputs() )
				{
					if ( input->getBuiltin() != ast::Builtin::eWorkGroupSize )
					{
						m_inputs.push_back( m_result.registerVariable( m_currentBlock
							, helpers::adaptName( input->getName() )
							, input->getBuiltin()
							, getStorageClass( m_result.getVersion(), input, spv::StorageClassInput )
							, input->isAlias()
							, input->isParam()
							, input->isOutputParam()
							, input->getType()
							, info
							, DebugId{}
							, getCurrentDebugStatement() ).id );
					}
				}

				for ( auto & output : moduleConfig.getOutputs() )
				{
					m_outputs.push_back( m_result.registerVariable( m_currentBlock
						, helpers::adaptName( output->getName() )
						, output->getBuiltin()
						, getStorageClass( m_result.getVersion(), output, spv::StorageClassOutput )
						, output->isAlias()
						, output->isParam()
						, output->isOutputParam()
						, output->getType()
						, info
						, DebugId{}
						, getCurrentDebugStatement() ).id );
				}

				for ( auto & mode : moduleConfig.executionModes )
				{
					m_result.registerExecutionMode( mode );
				}
			}

			DebugId doSubmit( ast::expr::Expr const & expr
				, Block & block )
			{
				return ExprVisitor::submit( m_exprCache
					, expr
					, m_context
					, block
					, m_result
					, getCurrentDebugStatement() );
			}

			DebugId doSubmit( ast::expr::Expr const & expr )
			{
				return doSubmit( expr, m_currentBlock );
			}

			bool isDebugEnabled()const noexcept
			{
				return !m_debugStatements.statements.empty();
			}

			glsl::RangeInfo getColumnData( ast::expr::Expr const & expr )
			{
				return glsl::getColumnData( getCurrentDebugStatement(), expr );
			}

			glsl::RangeInfo getColumnData()
			{
				return glsl::getColumnData( getCurrentDebugStatement() );
			}

			void writeLine( InstructionList & instructions
				, glsl::Statement const * statement
				, ast::expr::Expr const & expr )
			{
				m_debug.makeLineExtension( instructions, statement, expr );
			}

			void writeLine( Block & block
				, glsl::Statement const * statement
				, ast::expr::Expr const & expr )
			{
				writeLine( block.instructions, statement, expr );
			}

			void writeLine( InstructionList & instructions
				, glsl::Statement const * statement )
			{
				m_debug.makeLineExtension( instructions, statement, statement->source.columns );
			}

			void writeLine( Block & block
				, glsl::Statement const * statement )
			{
				writeLine( block.instructions, statement );
			}

			DebugId loadVariable( DebugId const & variableId
				, ast::expr::Expr const & expr )
			{
				return m_result.loadVariable( variableId
					, m_currentBlock
					, getCurrentDebugStatement()
					, getColumnData( expr ) );
			}

			void consumeDebugStatement( [[maybe_unused]] glsl::StatementType type )
			{
				if ( isDebugEnabled() )
				{
					assert( type == getCurrentDebugStatement()->type );

					if ( type == glsl::StatementType::eScopeLine )
					{
						writeLine( m_currentBlock, getCurrentDebugStatement() );
					}

					++m_currentDebugStatement;
				}
			}

			void consumeSimpleDebugStatement()
			{
				consumeDebugStatement( m_scopeLines.back() );
			}

			void beginControl( Block & block )
			{
				if ( isDebugEnabled() )
				{
					auto ctrlBeginStmt = getCurrentDebugStatement();
					consumeDebugStatement( glsl::StatementType::eControlBegin );
					writeLine( block, ctrlBeginStmt );
				}
			}

			void beginScope( InstructionList & instructions )
			{
				m_debug.makeScopeInstruction( instructions );
				writeLine( instructions, getCurrentDebugStatement() );
			}

			void beginScope( Block & block )
			{
				beginScope( block.instructions );
			}

			glsl::Statement * parseScope( ast::stmt::Compound const * stmt
				, glsl::StatementType scopeBegin
				, glsl::StatementType scopeLine
				, glsl::StatementType scopeEnd )
			{
				glsl::Statement * result{};

				if ( isDebugEnabled() )
				{
					auto scopeBeginStmt = getCurrentDebugStatement();
					consumeDebugStatement( scopeBegin );

					if ( scopeBegin == glsl::StatementType::eLexicalScopeBegin )
					{
						m_debug.makeLexicalBlockInstruction( scopeBeginStmt );
						beginScope( m_currentBlock );
					}

					m_scopeLines.push_back( scopeLine );
					visitContainerStmt( stmt );
					m_scopeLines.pop_back();
					result = getCurrentDebugStatement();
					consumeDebugStatement( scopeEnd );
				}
				else
				{
					visitContainerStmt( stmt );
				}

				return result;
			}

			glsl::Statement * getCurrentDebugStatement()
			{
				return m_currentDebugStatement == m_debugStatements.statements.end()
					? nullptr
					: std::to_address( m_currentDebugStatement );
			}

			void interruptBlock( InstructionPtr interruptInstruction
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
					block.blockEnd = makeInstruction< BranchInstruction >( m_result.getNameCache(), ValueId{ nextBlockLabel } );
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
					block.blockEnd = makeInstruction< BranchConditionalInstruction >( m_result.getNameCache()
						, makeOperands( m_allocator
							, ValueId{ trueBlockLabel }
							, ValueId{ falseBlockLabel }
					, ValueId{ mergeBlockLabel } ) );
				}

				m_function->cfg.blocks.emplace_back( std::move( block ) );
			}

			void visitContainerStmt( ast::stmt::Container const * cont )override
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

			void visitBreakStmt( ast::stmt::Break const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( makeInstruction< BranchInstruction >( m_result.getNameCache(), ValueId{ m_controlBlocks.back().breakLabel } )
					, !stmt->isSwitchCaseBreak() );
			}

			void visitContinueStmt( ast::stmt::Continue const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( makeInstruction< BranchInstruction >( m_result.getNameCache(), ValueId{ m_controlBlocks.back().continueLabel } )
					, true );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl const * stmt )override
			{
				TraceFunc;

				if ( !stmt->empty() )
				{
					consumeDebugStatement( glsl::StatementType::eVariableBlockDecl );
					parseScope( stmt
						, glsl::StatementType::eStructureScopeBegin
						, glsl::StatementType::eStructureMemberDecl
						, glsl::StatementType::eStructureScopeEnd );
					auto variableId = m_result.bindBufferVariable( stmt->getName()
						, stmt->getBindingPoint()
						, stmt->getDescriptorSet()
						, spv::DecorationBlock );
				}
			}

			void visitDemoteStmt( ast::stmt::Demote const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();

				if ( m_moduleConfig.hasExtension( EXT_demote_to_helper_invocation ) )
				{
					m_currentBlock.instructions.emplace_back( makeInstruction< DemoteInstruction >( m_result.getNameCache() ) );
				}
				else
				{
					interruptBlock( makeInstruction< KillInstruction >( m_result.getNameCache() )
						, true );
				}
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh const * stmt )override
			{
				TraceFunc;
				DebugIdList operands{ m_allocator };
				operands.push_back( submitAndLoad( *stmt->getNumGroupsX() ) );
				operands.push_back( submitAndLoad( *stmt->getNumGroupsY() ) );
				operands.push_back( submitAndLoad( *stmt->getNumGroupsZ() ) );

				if ( stmt->getPayload() )
				{
					operands.push_back( doSubmit( *stmt->getPayload() ) );
				}

				consumeSimpleDebugStatement();
				interruptBlock( makeInstruction< EmitMeshTasksInstruction >( m_result.getNameCache(), convert( operands ) )
					, false );
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();

				if ( m_moduleConfig.hasExtension( KHR_terminate_invocation ) )
				{
					interruptBlock( makeInstruction< TerminateInvocationInstruction >( m_result.getNameCache() )
						, true );
				}
				else
				{
					interruptBlock( makeInstruction< KillInstruction >( m_result.getNameCache() )
						, true );
				}
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl const * stmt )override
			{
				TraceFunc;

				if ( !stmt->empty() )
				{
					consumeDebugStatement( glsl::StatementType::eVariableBlockDecl );
					parseScope( stmt
						, glsl::StatementType::eStructureScopeBegin
						, glsl::StatementType::eStructureMemberDecl
						, glsl::StatementType::eStructureScopeEnd );
				}
			}

			void visitCommentStmt( ast::stmt::Comment const * stmt )override
			{
				TraceFunc;
			}

			void visitCompoundStmt( ast::stmt::Compound const * stmt )override
			{
				TraceFunc;
				parseScope( stmt
					, glsl::StatementType::eLexicalScopeBegin
					, glsl::StatementType::eScopeLine
					, glsl::StatementType::eLexicalScopeEnd );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile const * stmt )override
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
				auto loopBlockLabel = loopBlock.label;
				beginControl( loopBlock );

				loopBlock.instructions.emplace_back( makeInstruction< LoopMergeInstruction >( m_result.getNameCache()
					, makeOperands( m_allocator
						, ValueId{ mergeBlock.label }
						, ValueId{ ifBlock.label }
						, ValueId{ 0u } ) ) );
				endBlock( loopBlock, contentBlock.label );

				// The current block becomes the loop content block.
				m_currentBlock = std::move( contentBlock );

				// Instructions go to loop content block.
				parseScope( stmt
					, glsl::StatementType::eLexicalScopeBegin
					, glsl::StatementType::eScopeLine
					, glsl::StatementType::eLexicalScopeEnd );

				// Branch current block to the continue target block.
				endBlock( m_currentBlock, ifBlock.label );

				// The if block, branches either back to the loop header block (true) or to the loop merge block (false).
				writeLine( ifBlock, getCurrentDebugStatement(), *stmt->getCtrlExpr() );
				auto intermediateIfId = loadVariable( doSubmit( *stmt->getCtrlExpr(), ifBlock ), *stmt->getCtrlExpr() );
				endBlock( ifBlock, intermediateIfId->id, loopBlockLabel, mergeBlock.label );

				// Current block becomes the merge block.
				m_controlBlocks.pop_back();
				m_currentBlock = std::move( mergeBlock );
				consumeDebugStatement( glsl::StatementType::eControlEnd );
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				TraceFunc;
				beginControl( m_currentBlock );
				parseScope( stmt
					, glsl::StatementType::eLexicalScopeBegin
					, glsl::StatementType::eScopeLine
					, glsl::StatementType::eLexicalScopeEnd );
			}

			void visitForStmt( ast::stmt::For const * stmt )override
			{
				AST_Failure( "Unexpected For statement." );
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout const * stmt )override
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

				consumeDebugStatement( glsl::StatementType::eVariableDecl );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
			{
				TraceFunc;
				auto type = stmt->getType();
				auto declStmt = getCurrentDebugStatement();
				consumeDebugStatement( glsl::StatementType::eFunctionDecl );
				auto previousScopeId = m_currentScopeId;
				auto scopeBeginStmt = getCurrentDebugStatement();
				consumeDebugStatement( glsl::StatementType::eFunctionScopeBegin );
				m_currentBlock = m_result.newBlock();

				auto retType = m_result.registerType( type->getReturnType(), declStmt );
				m_function = m_result.beginFunction( stmt->getName()
					, retType
					, ast::var::VariableList{ type->begin(), type->end() }
					, declStmt
					, scopeBeginStmt
					, getCurrentDebugStatement() );

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
						auto varInfo = m_result.registerVariable( m_currentBlock
							, param->getName()
							, ast::Builtin::eNone
							, spv::StorageClassFunction
							, false
							, false
							, param->isOutputParam()
							, param->getType()
							, sourceInfo
							, DebugId{}
							, declStmt );

						if ( !sourceInfo.id.isPointer() )
						{
							m_result.storeVariable( varInfo.id
								, sourceInfo.id
								, m_currentBlock
								, getCurrentDebugStatement()
								, getColumnData() );
						}
					}
				}

				glsl::Statement const * funcEndStmt{};

				if ( isDebugEnabled() )
				{
					m_currentScopeId = m_function->id.debug;
					beginScope( m_function->debugStart );
					m_scopeLines.push_back( glsl::StatementType::eScopeLine );
					visitContainerStmt( stmt );
					m_scopeLines.pop_back();
					funcEndStmt = getCurrentDebugStatement();
					consumeDebugStatement( glsl::StatementType::eFunctionScopeEnd );
				}
				else
				{
					visitContainerStmt( stmt );
				}

				if ( stmt->isEntryPoint() )
				{
					m_result.registerEntryPoint( m_function->id
						, stmt->getName()
						, convert( m_inputs )
						, convert( m_outputs ) );
				}

				if ( !m_currentBlock.blockEnd )
				{
					if ( type->getReturnType()->getKind() == ast::type::Kind::eVoid )
					{
						writeLine( m_currentBlock, funcEndStmt );
						m_currentBlock.blockEnd = makeInstruction< ReturnInstruction >( m_result.getNameCache() );
					}
					else
					{
						auto retId = ValueId{ m_result.getIntermediateResult(), retType->type };
						m_currentBlock.instructions.emplace_back( makeInstruction< UndefInstruction >( m_result.getNameCache(), retType.id, retId ) );
						writeLine( m_currentBlock, funcEndStmt );
						m_currentBlock.blockEnd = makeInstruction< ReturnValueInstruction >( m_result.getNameCache(), retId );
					}
				}

				m_currentBlock.instructions.emplace_back( std::move( m_currentBlock.blockEnd ) );
				m_currentBlock.blockEnd = makeInstruction< FunctionEndInstruction >( m_result.getNameCache() );
				m_function->cfg.blocks.emplace_back( std::move( m_currentBlock ) );
				m_result.endFunction();
				m_function = nullptr;
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );
				visitDebugVariableDecl();
			}

			void visitIfStmt( ast::stmt::If const * stmt )override
			{
				TraceFunc;
				++m_ifStmts;
				auto contentBlock = m_result.newBlock();
				auto mergeBlock = m_result.newBlock();

				// Retrieve the if false branch block label.
				// It will be the else block if it exists, or the merge block.
				Block elseBlock{ m_allocator };
				auto falseBlockLabel = mergeBlock.label;
				assert( stmt->getElseIfList().empty() && "ElseIf list is supposed to have been converted." );

				if ( stmt->getElse() )
				{
					elseBlock = m_result.newBlock();
					falseBlockLabel = elseBlock.label;
				}

				// End current block, to branch to the if content block (true) or to the false branch block (false).
				beginControl( m_currentBlock );
				auto intermediateIfId = loadVariable( doSubmit( *stmt->getCtrlExpr() ), *stmt->getCtrlExpr() );
				m_debug.makeNoScopeInstruction( m_currentBlock.instructions );

				m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( m_result.getNameCache(), ValueId{ mergeBlock.label }, ValueId{ 0u } ) );
				endBlock( m_currentBlock, intermediateIfId->id, contentBlock.label, falseBlockLabel );

				// The current block becomes the if content block.
				m_currentBlock = std::move( contentBlock );
				parseScope( stmt
					, glsl::StatementType::eLexicalScopeBegin
					, glsl::StatementType::eScopeLine
					, glsl::StatementType::eLexicalScopeEnd );
				endBlock( m_currentBlock, mergeBlock.label );

				if ( stmt->getElse() )
				{
					m_currentBlock = std::move( elseBlock );
					stmt->getElse()->accept( this );
					endBlock( m_currentBlock, mergeBlock.label );
				}

				beginScope( mergeBlock );

				// Current block becomes the merge block.
				m_currentBlock = std::move( mergeBlock );
				--m_ifStmts;
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl const * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl();
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( makeInstruction< IgnoreIntersectionInstruction >( m_result.getNameCache() )
					, false );
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl const * stmt )override
			{
				TraceFunc;
				m_result.registerType( stmt->getType(), getCurrentDebugStatement() );
				consumeDebugStatement( glsl::StatementType::eVariableDecl );
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl const * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl();
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );

				if ( stmt->getLocation() != ast::type::Struct::InvalidLocation )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationLocation ), stmt->getLocation() ) );
				}

				visitDebugVariableDecl();
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
				TraceFunc;
				auto variable = stmt->getVariable();
				auto variableId = visitVariable( variable );

				if ( stmt->getLocation() != ast::type::Struct::InvalidLocation )
				{
					m_result.decorate( variableId, makeIdList( m_allocator, spv::Id( spv::DecorationLocation ), stmt->getLocation() ) );
				}

				visitDebugVariableDecl();
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
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

				visitDebugVariableDecl();
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl const * stmt )override
			{
				TraceFunc;
				auto var = stmt->getVariable();
				m_result.registerSpecConstant( var->getName()
					, stmt->getLocation()
					, var->getType()
					, *stmt->getValue() );
				consumeDebugStatement( glsl::StatementType::eVariableDecl );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( spv::ExecutionModeLocalSize
					, makeOperands( m_allocator, ValueId{ stmt->getWorkGroupsX() }, ValueId{ stmt->getWorkGroupsY() }, ValueId{ stmt->getWorkGroupsZ() } ) );
				DebugIdList ids{ m_allocator };
				ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsX() ) );
				ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsY() ) );
				ids.push_back( m_result.registerLiteral( stmt->getWorkGroupsZ() ) );

				if ( m_moduleConfig.stage == ast::ShaderStage::eCompute )
				{
					m_context.workGroupSizeExpr = m_result.registerLiteral( ids, m_result.getTypesCache().getVec3U32() ).id;
					m_result.decorate( DebugId{ m_context.workGroupSizeExpr }, makeIdList( m_allocator, spv::Id( spv::DecorationBuiltIn ), spv::Id( spv::BuiltInWorkgroupSize ) ) );
				}
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getLayout() );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getLayout(), stmt->getPrimCount() );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement(); // topology
				consumeSimpleDebugStatement(); // max_primitives, max_vertices

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

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getDomain()
					, stmt->getPartitioning()
					, stmt->getTopology()
					, stmt->getPrimitiveOrdering()
					, stmt->getOutputVertices() );
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				m_result.registerExecutionMode( stmt->getDomain()
					, stmt->getPartitioning()
					, stmt->getPrimitiveOrdering() );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl const * stmt )override
			{
				TraceFunc;
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl const * stmt )override
			{
				TraceFunc;
				consumeDebugStatement( glsl::StatementType::eVariableDecl );
			}

			void visitReturnStmt( ast::stmt::Return const * stmt )override
			{
				TraceFunc;

				if ( isDebugEnabled() )
				{
					auto scopeLineStmt = getCurrentDebugStatement();
					consumeSimpleDebugStatement();
					writeLine( m_currentBlock, scopeLineStmt );
				}

				if ( auto expr = stmt->getExpr() )
				{
					auto result = loadVariable( doSubmit( *expr ), *expr );
					interruptBlock( makeInstruction< ReturnValueInstruction >( m_result.getNameCache(), result.id )
						, false );
				}
				else
				{
					interruptBlock( makeInstruction< ReturnInstruction >( m_result.getNameCache() )
						, false );
				}
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl const * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getVariable() );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl();
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getVariable() );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl();
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl const * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getVariable() );
				m_result.bindVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() );
				visitDebugVariableDecl();
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getVariable() );
				m_result.bindBufferVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet()
					, ( m_result.getVersion() > v1_3
						? spv::DecorationBlock
						: spv::DecorationBufferBlock ) );
				visitDebugVariableBlockDecl( stmt );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
				TraceFunc;
				auto variableId = visitVariable( stmt->getSsboInstance() );
				m_result.bindBufferVariable( variableId
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet()
					, ( m_result.getVersion() > v1_3
						? spv::DecorationBlock
						: spv::DecorationBufferBlock ) );
				visitDebugVariableDecl();
				consumeDebugStatement( glsl::StatementType::eStructureScopeBegin );
				consumeDebugStatement( glsl::StatementType::eStructureMemberDecl );
				consumeDebugStatement( glsl::StatementType::eStructureScopeEnd );
			}

			void visitSimpleStmt( ast::stmt::Simple const * stmt )override
			{
				TraceFunc;
				ExprVisitor::submit( m_exprCache, *stmt->getExpr(), m_context, m_currentBlock, m_result, getCurrentDebugStatement() );

				if ( stmt->getExpr()->getKind() != ast::expr::Kind::eAlias
					&& stmt->getExpr()->getKind() != ast::expr::Kind::eIdentifier )
				{
					consumeSimpleDebugStatement();
				}
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
				TraceFunc;
				auto structType = stmt->getType();

				if ( !stmt->getType()->isShaderInput()
					&& !stmt->getType()->isShaderOutput() )
				{
					auto declStatement = getCurrentDebugStatement();

					if ( isDebugEnabled() )
					{
						consumeDebugStatement( glsl::StatementType::eStructureDecl );
						consumeDebugStatement( glsl::StatementType::eStructureScopeBegin );

						for ( auto it = structType->begin(); it != structType->end(); ++it )
						{
							consumeDebugStatement( glsl::StatementType::eStructureMemberDecl );
						}

						consumeDebugStatement( glsl::StatementType::eStructureScopeEnd );
					}

					m_result.registerType( stmt->getType(), declStatement );
				}
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase const * stmt )override
			{
			}

			void visitSwitchStmt( ast::stmt::Switch const * stmt )override
			{
				TraceFunc;
				ast::Vector< Block > caseBlocks{ m_allocator };
				ast::Map< int32_t, spv::Id > caseBlocksIds{ m_allocator };
				auto mergeBlock = m_result.newBlock();
				m_controlBlocks.push_back( Control{ mergeBlock.label, 0u } );
				ast::stmt::SwitchCase const * defaultStmt{ nullptr };
				Block defaultBlock{ m_result.newBlock() };

				for ( auto & it : *stmt )
				{
					assert( it->getKind() == ast::stmt::Kind::eSwitchCase );
					auto & caseStmt = static_cast< ast::stmt::SwitchCase const & >( *it );

					if ( caseStmt.getCaseExpr() )
					{
						auto block = m_result.newBlock();
						caseBlocksIds.emplace( helpers::getInt32Value( *caseStmt.getCaseExpr()->getLabel() ), block.label );
						caseBlocks.emplace_back( std::move( block ) );
					}
					else
					{
						// Default
						defaultStmt = static_cast< ast::stmt::SwitchCase * >( it.get() );
					}
				}

				beginControl( m_currentBlock );
				auto selector = loadVariable( doSubmit( *stmt->getTestExpr()->getValue() ), *stmt->getTestExpr() );
				m_currentBlock.instructions.emplace_back( makeInstruction< SelectionMergeInstruction >( m_result.getNameCache(), ValueId{ mergeBlock.label }, ValueId{ 0u } ) );
				m_currentBlock.blockEnd = makeInstruction< SwitchInstruction >( m_result.getNameCache(), makeOperands( m_allocator, selector, ValueId{ defaultBlock.label } ), caseBlocksIds );
				m_currentBlock.isInterrupted = true;
				consumeDebugStatement( glsl::StatementType::eLexicalScopeBegin );

				if ( !caseBlocks.empty() )
				{
					endBlock( m_currentBlock, caseBlocks.front().label );
					uint32_t index = 0u;

					for ( auto & it : *stmt )
					{
						assert( it->getKind() == ast::stmt::Kind::eSwitchCase );

						if ( auto & caseStmt = static_cast< ast::stmt::SwitchCase const & >( *it );
							caseStmt.getCaseExpr() )
						{
							m_currentBlock = std::move( caseBlocks[index] );
							beginControl( m_currentBlock );
							parseScope( &caseStmt
								, glsl::StatementType::eLexicalScopeBegin
								, glsl::StatementType::eScopeLine
								, glsl::StatementType::eLexicalScopeEnd );

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
									endBlock( m_currentBlock, caseBlocks[index + 1ULL].label );
								}
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
					beginControl( m_currentBlock );
					parseScope( defaultStmt
						, glsl::StatementType::eLexicalScopeBegin
						, glsl::StatementType::eScopeLine
						, glsl::StatementType::eLexicalScopeEnd );
				}

				consumeDebugStatement( glsl::StatementType::eLexicalScopeEnd );
				endBlock( m_currentBlock, mergeBlock.label );

				m_controlBlocks.pop_back();
				m_currentBlock = std::move( mergeBlock );
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay const * stmt )override
			{
				TraceFunc;
				consumeSimpleDebugStatement();
				interruptBlock( makeInstruction< TerminateRayInstruction >( m_result.getNameCache() )
					, false );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
				TraceFunc;
				auto var = stmt->getVariable();
				auto variableId = visitVariable( var );

				if ( isDebugEnabled()
					&& !stmt->getVariable()->isBuiltin() )
				{
					if ( var->isPerTaskNV() )
					{
						auto structType = getStructType( var->getType() );

						if ( structType && !structType->empty() )
						{
							visitDebugVariableDecl();
							consumeDebugStatement( glsl::StatementType::eStructureScopeBegin );
							consumeDebugStatement( glsl::StatementType::eStructureMemberDecl );
							consumeDebugStatement( glsl::StatementType::eStructureScopeEnd );
						}
					}
					else if ( var->isPerTask() )
					{
						auto structType = getStructType( var->getType() );

						if ( !structType || !structType->empty() )
						{
							visitDebugVariableDecl();
						}
					}
					else
					{
						visitDebugVariableDecl();
					}
				}
			}

			void visitWhileStmt( ast::stmt::While const * stmt )override
			{
				AST_Failure( "Unexpected While statement." );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension const * preproc )override
			{
				TraceFunc;
				consumeDebugStatement( glsl::StatementType::eScopeLine );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
				TraceFunc;
				consumeDebugStatement( glsl::StatementType::eScopeLine );
			}

			DebugId visitVariable( ast::var::VariablePtr var )
			{
				TraceFunc;
				VariableInfo info;
				DebugId result;

				if ( var->isMemberVar() )
				{
					auto outer = m_result.registerVariable( m_currentBlock
						, var->getOuter()->getName()
						, var->getOuter()->getBuiltin()
						, getStorageClass( m_result.getVersion(), var )
						, var->isAlias()
						, var->isParam()
						, var->isOutputParam()
						, var->getOuter()->getType()
						, info
						, DebugId{}
						, getCurrentDebugStatement() ).id;
					result = m_result.registerMemberVariable( outer
						, var->getName()
						, var->getType() );
				}
				else
				{
					result = m_result.registerVariable( m_currentBlock
						, var->getName()
						, var->getBuiltin()
						, getStorageClass( m_result.getVersion(), var )
						, var->isAlias()
						, var->isParam()
						, var->isOutputParam()
						, var->getType()
						, info
						, DebugId{}
						, getCurrentDebugStatement() ).id;
				}

				decorateVar( *var, result, m_result );
				return result;
			}

			void visitDebugVariableDecl()
			{
				if ( !isDebugEnabled() )
				{
					return;
				}

				auto dbgStmt = getCurrentDebugStatement();
				consumeDebugStatement( dbgStmt->type );
			}

			void visitDebugVariableBlockDecl( ast::stmt::Compound const * stmt )
			{
				if ( isDebugEnabled() )
				{
					visitDebugVariableDecl();
				}

				parseScope( stmt
					, glsl::StatementType::eStructureScopeBegin
					, glsl::StatementType::eStructureMemberDecl
					, glsl::StatementType::eStructureScopeEnd );
			}

			DebugId submitAndLoad( ast::expr::Expr const & expr )
			{
				TraceFunc;
				auto result = doSubmit( expr );

				if ( expr.getKind() == ast::expr::Kind::eIdentifier )
				{
					result = loadVariable( result, expr );
				}

				return result;
			}

		private:
			ast::expr::ExprCache & m_exprCache;
			ast::ShaderAllocatorBlock * m_allocator;
			ModuleConfig const & m_moduleConfig;
			spirv::PreprocContext m_context;
			ShaderActions m_actions;
			Module & m_result;
			debug::NonSemanticDebug & m_debug;
			glsl::Statements m_debugStatements;
			Block m_currentBlock;
			Function * m_function{ nullptr };
			ast::Vector< Control > m_controlBlocks;
			uint32_t m_ifStmts{ 0u };
			DebugIdList m_inputs;
			DebugIdList m_outputs;
			glsl::StatementsList::iterator m_currentDebugStatement{};
			std::vector< glsl::StatementType > m_scopeLines{ glsl::StatementType::eScopeLine };
			ValueId m_currentScopeId{};
		};
	}

	ModulePtr generateModule( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Stmt const & stmt
		, ast::ShaderStage type
		, ModuleConfig const & moduleConfig
		, spirv::PreprocContext context
		, SpirVConfig const & spirvConfig
		, glsl::StmtConfig const & stmtConfig
		, ShaderActions actions
		, glsl::Statements debugStatements )
	{
		return vis::StmtVisitor::submit( exprCache
			, typesCache
			, stmt
			, type
			, moduleConfig
			, std::move( context )
			, spirvConfig
			, stmtConfig
			, std::move( actions )
			, std::move( debugStatements ) );
	}

	DebugId generateModuleExpr( ast::expr::ExprCache & exprCache
		, ast::expr::Expr const & expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & shaderModule )
	{
		return vis::ExprVisitor::submit( exprCache
			, expr
			, context
			, currentBlock
			, shaderModule
			, nullptr );
	}
}
