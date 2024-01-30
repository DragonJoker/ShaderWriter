/*
See LICENSE file in root folder
*/
#include "SpirVMakeAccessChain.hpp"

#include "SpirVDebugHelpers.hpp"
#include "SpirVGenerateStatements.hpp"
#include "SpirVGetSwizzleComponents.hpp"
#include "SpirVHelpers.hpp"
#include "SpirVIntrinsicConfig.hpp"
#include "SpirVIntrinsicNames.hpp"
#include "SpirVNonSemanticDebug.hpp"
#include "SpirVStorageImageAccessConfig.hpp"
#include "SpirVStorageImageAccessNames.hpp"
#include "SpirVCombinedImageAccessConfig.hpp"
#include "SpirVCombinedImageAccessNames.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <numeric>
#include <sstream>

namespace spirv
{
	namespace acnhlp
	{
		static bool isBuiltIn( ast::expr::Expr const & expr )
		{
			return expr.getKind() == ast::expr::Kind::eIdentifier
				&& static_cast< ast::expr::Identifier const & >( expr ).getVariable()->isBuiltin();
		}

		static bool isAccessChain( ast::expr::Expr const & expr
			, bool isFromArray )
		{
			return expr.getKind() == ast::expr::Kind::eArrayAccess
				|| expr.getKind() == ast::expr::Kind::eMbrSelect
				|| ( expr.getKind() == ast::expr::Kind::eSwizzle
					&& ( isFromArray
						|| !isScalarType( expr.getType()->getKind() )
						|| isBuiltIn( *static_cast< ast::expr::Swizzle const & >( expr ).getOuterExpr() ) ) )
				|| ( expr.getKind() == ast::expr::Kind::eIdentifier
					&& static_cast< ast::expr::Identifier const & >( expr ).getVariable()->isMemberVar() );
		}

		struct AccessChainExpr
		{
			ast::expr::Kind kind;
			ast::expr::Expr const * expr{};
		};
		using AccessChainExprArray = ast::Vector< AccessChainExpr >;

		class AccessChainLineariser
			: public ast::expr::SimpleVisitor
		{
		public:
			static AccessChainExprArray submit( ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::expr::Expr const & expr
				, ast::expr::ExprList & idents )
			{
				return submit( exprCache
					, typesCache
					, ast::expr::Kind::eIdentifier
					, expr
					, idents
					, false );
			}

		private:
			AccessChainLineariser( ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::expr::Kind kind
				, AccessChainExprArray & result
				, ast::expr::ExprList & idents
				, bool parsingMbrSelect )
				: m_exprCache{ exprCache }
				, m_typesCache{ typesCache }
				, m_result{ result }
				, m_idents{ idents }
				, m_kind{ kind }
				, m_parsingMbrSelect{ parsingMbrSelect }
			{
			}

			static AccessChainExprArray submit( ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::expr::Kind kind
				, ast::expr::Expr const & expr
				, ast::expr::ExprList & idents
				, bool parsingMbrSelect )
			{
				AccessChainExprArray result{ &exprCache.getAllocator() };
				AccessChainLineariser vis{ exprCache
					, typesCache
					, kind
					, result
					, idents
					, parsingMbrSelect };
				expr.accept( &vis );
				return result;
			}

			void doAddExpr( ast::expr::Kind kind
				, ast::expr::Expr const & expr )
			{
				m_kind = kind;
				m_result.push_back( { m_kind, &expr } );
			}

			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::Unary ?" );
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::Binary ?" );
			}

			AccessChainExprArray doSubmit( ast::expr::Kind kind
				, ast::expr::Expr const & expr )
			{
				return submit( m_exprCache, m_typesCache, kind, expr, m_idents, m_parsingMbrSelect );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				m_result = doSubmit( m_kind, *expr->getOuterExpr() );
				m_result.push_back( { expr->getKind(), expr } );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
			{
				auto lhs = doSubmit( m_kind, *expr->getLHS() );
				m_result = lhs;

				if ( isAccessChain( *expr->getRHS(), true ) )
				{
					doAddExpr( expr->getKind(), *expr );
				}
				else
				{
					doAddExpr( expr->getKind(), *expr->getRHS() );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				if ( expr->getVariable()->isMemberVar()
					&& expr->getType()->isMember()
					&& !m_parsingMbrSelect )
				{
					m_idents.emplace_back( m_exprCache.makeIdentifier( m_typesCache, expr->getVariable()->getOuter() ) );
					auto ident = m_idents.back().get();
					m_result = doSubmit( m_kind, *ident );
				}

				doAddExpr( m_kind, *expr );
			}

			void visitLiteralExpr( ast::expr::Literal const * expr )override
			{
				doAddExpr( m_kind, *expr );
			}

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				if ( m_result.empty() )
				{
					m_result = doSubmit( m_kind, *expr->getOuterExpr() );
				}

				doAddExpr( m_kind, *expr );
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * )override
			{
				AST_Failure( "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * )override
			{
				AST_Failure( "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::StorageImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init const * )override
			{
				AST_Failure( "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question const * )override
			{
				AST_Failure( "Unexpected ast::expr::Question ?" );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::CombinedImageAccessCall ?" );
			}

		private:
			ast::expr::ExprCache & m_exprCache;
			ast::type::TypesCache & m_typesCache;
			AccessChainExprArray & m_result;
			ast::expr::ExprList & m_idents;
			ast::expr::Kind m_kind{ ast::expr::Kind::eIdentifier };
			bool m_parsingMbrSelect{ false };
		};

		class AccessChainCreator
			: public ast::expr::SimpleVisitor
		{
		public:
			static DebugIdList submit( ast::expr::ExprCache & exprCache
				, AccessChainExprArray const & exprs
				, PreprocContext const & context
				, Module & shaderModule
				, Block & currentBlock
				, glsl::Statement * currentDebugStatement )
			{
				DebugIdList result{ &exprCache.getAllocator() };
				assert( exprs.size() >= 2u );
				auto it = exprs.begin();
				result.push_back( submit( exprCache
					, *it->expr
					, context
					, shaderModule
					, currentBlock
					, currentDebugStatement ) );

				while ( ++it != exprs.end())
				{
					result.push_back( shaderModule.loadVariable( submit( exprCache
							, result.back()
							, *it
							, context
							, shaderModule
							, currentBlock
							, currentDebugStatement )
						, currentBlock
						, currentDebugStatement
						, glsl::getColumnData( currentDebugStatement, *it->expr ) ) );
				}

				return result;
			}

		private:
			AccessChainCreator( DebugId & result
				, ast::expr::ExprCache & exprCache
				, ast::expr::Kind parentKind
				, DebugId parentId
				, PreprocContext const & context
				, Module & shaderModule
				, Block & currentBlock
				, glsl::Statement * currentDebugStatement )
				: m_exprCache{ exprCache }
				, m_result{ result }
				, m_context{ context }
				, m_module{ shaderModule }
				, m_currentBlock{ currentBlock }
				, m_parentId{ std::move( parentId ) }
				, m_parentKind{ parentKind }
				, m_currentDebugStatement{ currentDebugStatement }
			{
			}

			static DebugId submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr const & expr
				, PreprocContext const & context
				, Module & shaderModule
				, Block & currentBlock
				, glsl::Statement * currentDebugStatement )
			{
				DebugId result{ 0u, expr.getType() };
				AccessChainCreator vis{ result
					, exprCache
					, expr.getKind()
					, DebugId{}
					, context
					, shaderModule
					, currentBlock
					, currentDebugStatement };
				expr.accept( &vis );
				return result;
			}

			static DebugId submit( ast::expr::ExprCache & exprCache
				, DebugId parentId
				, ast::expr::Expr const & expr
				, PreprocContext const & context
				, Module & shaderModule
				, Block & currentBlock
				, glsl::Statement * currentDebugStatement )
			{
				DebugId result{ 0u, expr.getType() };
				AccessChainCreator vis{ result
					, exprCache
					, expr.getKind()
					, std::move( parentId )
					, context
					, shaderModule
					, currentBlock
					, currentDebugStatement };
				expr.accept( &vis );
				return result;
			}

			static DebugId submit( ast::expr::ExprCache & exprCache
				, DebugId parentId
				, AccessChainExpr expr
				, PreprocContext const & context
				, Module & shaderModule
				, Block & currentBlock
				, glsl::Statement * currentDebugStatement )
			{
				DebugId result{ 0u, parentId->type };
				AccessChainCreator vis{ result
					, exprCache
					, expr.kind
					, std::move( parentId )
					, context
					, shaderModule
					, currentBlock
					, currentDebugStatement };
				expr.expr->accept( &vis );
				return result;
			}

			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				m_result = generateModuleExpr( m_exprCache, *expr, m_context, m_currentBlock, m_module );
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				m_result = generateModuleExpr( m_exprCache, *expr, m_context, m_currentBlock, m_module );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				assert( m_parentId );
				m_result = m_module.registerLiteral( expr->getMemberIndex() );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
			{
				assert( m_parentId );

				if ( isAccessChain( *expr->getRHS(), true ) )
				{
					m_result = makeAccessChain( m_exprCache
						, *expr->getRHS()
						, m_context
						, m_module
						, m_currentBlock
						, m_currentDebugStatement );
				}
				else
				{
					m_result = submit( m_exprCache
						, m_parentId
						, *expr->getRHS()
						, m_context
						, m_module
						, m_currentBlock
						, m_currentDebugStatement );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				auto var = expr->getVariable();

				if ( var->isAlias() )
				{
					assert( !m_parentId || m_parentKind == ast::expr::Kind::eArrayAccess );
					m_result = m_module.getVariablePointer( m_currentBlock
						, var->getName()
						, spv::StorageClassFunction
						, m_currentBlock
						, m_currentDebugStatement
						, glsl::getColumnData( m_currentDebugStatement, *expr ) );
				}
				else if ( m_parentId
					&& m_parentKind != ast::expr::Kind::eArrayAccess )
				{
					// Leaf or Intermediate identifier.
					// Store member only (parent has already be added).
					m_result = m_module.registerMemberVariableIndex( expr->getType() );
				}
				else
				{
					// Head identifier, or array access index.
					VariableInfo sourceInfo;
					m_result = m_module.registerVariable( m_currentBlock
						, var->getName()
						, var->getBuiltin()
						, getStorageClass( m_module.getVersion(), var )
						, false
						, false
						, var->isOutputParam()
						, expr->getType()
						, sourceInfo ).id;

					decorateVar( *var, m_result, m_module );

					if ( sourceInfo.needsStoreOnPromote() )
					{
						m_module.storePromoted( m_result
							, sourceInfo
							, m_currentBlock
							, m_currentDebugStatement
							, glsl::getColumnData( m_currentDebugStatement, *expr ) );
					}

					if ( m_parentKind == ast::expr::Kind::eArrayAccess )
					{
						m_result = m_module.loadVariable( m_result
							, m_currentBlock
							, m_currentDebugStatement
							, glsl::getColumnData( m_currentDebugStatement, *expr ) );
					}
					else
					{
						auto type = m_result->type;

						while ( getPointerLevel( type ) > 1 )
						{
							m_result = m_module.loadVariable( m_result
								, m_currentBlock
								, m_currentDebugStatement
								, glsl::getColumnData( m_currentDebugStatement, *expr ) );
							type = m_result->type;
						}
					}
				}
			}

			void visitLiteralExpr( ast::expr::Literal const * expr )override
			{
				assert( m_parentId );

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

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				assert( m_parentId );

				if ( expr->getSwizzle().isOneComponent() )
				{
					m_result = m_module.registerLiteral( expr->getSwizzle().toIndex() );
				}
				else
				{
					m_result = makeVectorShuffle( m_exprCache
						, *expr
						, m_context
						, m_module
						, m_currentBlock
						, m_currentDebugStatement );
				}
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * )override
			{
				AST_Failure( "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::StorageImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init const * )override
			{
				AST_Failure( "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question const * )override
			{
				AST_Failure( "Unexpected ast::expr::Question ?" );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * )override
			{
				AST_Failure( "Unexpected ast::expr::CombinedImageAccessCall ?" );
			}

		private:
			ast::expr::ExprCache & m_exprCache;
			DebugId & m_result;
			PreprocContext const & m_context;
			Module & m_module;
			Block & m_currentBlock;
			DebugId m_parentId;
			ast::expr::Kind m_parentKind;
			glsl::Statement * m_currentDebugStatement;
		};
	}

	bool isAccessChain( ast::expr::Expr const & expr )
	{
		return acnhlp::isAccessChain( expr, false );
	}

	DebugId makeAccessChain( ast::expr::ExprCache & exprCache
		, ast::expr::Expr const & expr
		, PreprocContext const & context
		, Module & shaderModule
		, Block & currentBlock
		, glsl::Statement * debugStatement )
	{
		// Create Access Chain.
		ast::expr::ExprList idents;
		auto accessChain = acnhlp::AccessChainCreator::submit( exprCache
			, acnhlp::AccessChainLineariser::submit( exprCache, expr.getTypesCache(), expr, idents )
			, context
			, shaderModule
			, currentBlock
			, debugStatement );
		return currentBlock.writeAccessChain( convert( accessChain )
			, expr
			, shaderModule
			, debugStatement );
	}

	DebugId makeVectorShuffle( ast::expr::ExprCache & exprCache
		, ast::expr::Swizzle const & expr
		, PreprocContext const & context
		, Module & shaderModule
		, Block & currentBlock
		, glsl::Statement const * debugStatement )
	{
		auto typeId = shaderModule.registerType( expr.getType(), nullptr );
		auto outerId = shaderModule.loadVariable( generateModuleExpr( exprCache, *expr.getOuterExpr()
				, context
				, currentBlock
				, shaderModule )
			, currentBlock
			, debugStatement
			, glsl::getColumnData( debugStatement, *expr.getOuterExpr() ) );
		DebugId result{ 0u, typeId->type };

		if ( auto swizzleComponents = convert( getSwizzleComponents( shaderModule.allocator, expr.getSwizzle() ) );
			swizzleComponents.size() == 1u )
		{
			ValueIdList extract{ &exprCache.getAllocator() };
			extract.push_back( outerId.id );
			extract.push_back( swizzleComponents.front() );
			auto intermediateId = DebugId{ shaderModule.getIntermediateResult(), typeId->type };
			currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( shaderModule.getNameCache()
				, typeId.id
				, intermediateId.id
				, extract ) );
			result = intermediateId;
		}
		else
		{
			ValueIdList shuffle{ &exprCache.getAllocator() };
			shuffle.push_back( outerId.id );
			shuffle.push_back( outerId.id );
			shuffle.insert( shuffle.end(), swizzleComponents.begin(), swizzleComponents.end() );
			auto intermediateId = DebugId{ shaderModule.getIntermediateResult(), typeId->type };
			currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( shaderModule.getNameCache()
				, typeId.id
				, intermediateId.id
				, shuffle ) );
			result = intermediateId;
		}

		assert( !result.isPointer() );
		return result;
	}
}
