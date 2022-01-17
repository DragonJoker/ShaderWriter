/*
See LICENSE file in root folder
*/
#include "SpirvMakeAccessChain.hpp"

#include "SpirvExprVisitor.hpp"

#include "SpirvGetSwizzleComponents.hpp"
#include "SpirvHelpers.hpp"
#include "SpirvImageAccessConfig.hpp"
#include "SpirvImageAccessNames.hpp"
#include "SpirvIntrinsicConfig.hpp"
#include "SpirvIntrinsicNames.hpp"
#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

#include <numeric>
#include <sstream>

namespace spirv
{
	namespace
	{
		struct AccessChainExpr
		{
			ast::expr::Kind kind;
			ast::expr::Expr * expr;
		};
		using AccessChainExprArray = std::vector< AccessChainExpr >;

		class AccessChainLineariser
			: public ast::expr::SimpleVisitor
		{
		public:
			static AccessChainExprArray submit( ast::type::TypesCache & cache
				, ast::expr::Expr * expr
				, ast::expr::ExprList & idents )
			{
				return submit( cache
					, ast::expr::Kind::eIdentifier
					, expr
					, idents
					, false );
			}

		private:
			AccessChainLineariser( ast::type::TypesCache & cache
				, ast::expr::Kind kind
				, AccessChainExprArray & result
				, ast::expr::ExprList & idents
				, bool parsingMbrSelect )
				: m_cache{ cache }
				, m_result{ result }
				, m_idents{ idents }
				, m_kind{ kind }
				, m_parsingMbrSelect{ parsingMbrSelect }
			{
			}

			static AccessChainExprArray submit( ast::type::TypesCache & cache
				, ast::expr::Kind kind
				, ast::expr::Expr * expr
				, ast::expr::ExprList & idents
				, bool parsingMbrSelect )
			{
				AccessChainExprArray result;
				AccessChainLineariser vis
				{
					cache,
					kind,
					result,
					idents,
					parsingMbrSelect,
				};
				expr->accept( &vis );
				return result;
			}

			void doAddExpr( ast::expr::Kind kind
				, ast::expr::Expr * expr )
			{
				m_kind = kind;
				m_result.push_back( { m_kind, expr } );
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				AST_Failure( "Unexpected ast::expr::Unary ?" );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				AST_Failure( "Unexpected ast::expr::Binary ?" );
			}

			AccessChainExprArray doSubmit( ast::expr::Kind kind
				, ast::expr::Expr * expr )
			{
				return submit( m_cache, kind, expr, m_idents, m_parsingMbrSelect );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				m_result = doSubmit( m_kind, expr->getOuterExpr() );
				m_result.push_back( { expr->getKind(), expr } );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				auto lhs = doSubmit( m_kind, expr->getLHS() );
				m_result = lhs;

				if ( isAccessChain( expr->getRHS() ) )
				{
					doAddExpr( expr->getKind(), expr );
				}
				else
				{
					doAddExpr( expr->getKind(), expr->getRHS() );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				if ( expr->getVariable()->isMember()
					&& expr->getType()->isMember()
					&& !m_parsingMbrSelect )
				{
					m_idents.emplace_back( ast::expr::makeIdentifier( m_cache, expr->getVariable()->getOuter() ) );
					auto ident = m_idents.back().get();
					m_result = doSubmit( m_kind, ident );
				}

				doAddExpr( m_kind, expr );
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				doAddExpr( m_kind, expr );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				if ( m_result.empty() )
				{
					m_result = doSubmit( m_kind, expr->getOuterExpr() );
				}

				doAddExpr( m_kind, expr );
			}

			void visitAggrInitExpr( ast::expr::AggrInit * )override
			{
				AST_Failure( "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				AST_Failure( "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall * )override
			{
				AST_Failure( "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * )override
			{
				AST_Failure( "Unexpected ast::expr::ImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init * )override
			{
				AST_Failure( "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * )override
			{
				AST_Failure( "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question * )override
			{
				AST_Failure( "Unexpected ast::expr::Question ?" );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend * )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * )override
			{
				AST_Failure( "Unexpected ast::expr::TextureAccessCall ?" );
			}

		private:
			ast::type::TypesCache & m_cache;
			AccessChainExprArray & m_result;
			ast::expr::ExprList & m_idents;
			ast::expr::Kind m_kind{ ast::expr::Kind::eIdentifier };
			bool m_parsingMbrSelect{ false };
		};

		class AccessChainCreator
			: public ast::expr::SimpleVisitor
		{
		public:
			static ValueIdList submit( AccessChainExprArray const & exprs
				, PreprocContext const & context
				, Module & module
				, Block & currentBlock )
			{
				ValueIdList result;
				assert( exprs.size() >= 2u );
				result.push_back( submit( exprs[0].expr
					, context
					, module
					, currentBlock ) );

				for ( size_t i = 1u; i < exprs.size(); ++i )
				{
					auto & expr = exprs[i];
					result.push_back( module.loadVariable( submit( result.back()
							, expr
							, context
							, module
							, currentBlock )
						, currentBlock ) );
				}

				return result;
			}

		private:
			AccessChainCreator( ValueId & result
				, ast::expr::Kind parentKind
				, ValueId parentId
				, PreprocContext const & context
				, Module & module
				, Block & currentBlock )
				: m_result{ result }
				, m_context{ context }
				, m_module{ module }
				, m_currentBlock{ currentBlock }
				, m_parentId{ parentId }
				, m_parentKind{ parentKind }
			{
			}

			static ValueId submit( ast::expr::Expr * expr
				, PreprocContext const & context
				, Module & module
				, Block & currentBlock )
			{
				ValueId result{ 0u, expr->getType() };
				AccessChainCreator vis{ result
					, expr->getKind()
					, {}
					, context
					, module
					, currentBlock };
				expr->accept( &vis );
				return result;
			}

			static ValueId submit( ValueId parentId
				, ast::expr::Expr * expr
				, PreprocContext const & context
				, Module & module
				, Block & currentBlock )
			{
				ValueId result{ 0u, expr->getType() };
				AccessChainCreator vis{ result
					, expr->getKind()
					, parentId
					, context
					, module
					, currentBlock };
				expr->accept( &vis );
				return result;
			}

			static ValueId submit( ValueId parentId
				, AccessChainExpr expr
				, PreprocContext const & context
				, Module & module
				, Block & currentBlock )
			{
				ValueId result{ 0u, parentId.type };
				AccessChainCreator vis{ result
					, expr.kind
					, parentId
					, context
					, module
					, currentBlock };
				expr.expr->accept( &vis );
				return result;
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				m_result = ExprVisitor::submit( expr, m_context, m_currentBlock, m_module );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				m_result = ExprVisitor::submit( expr, m_context, m_currentBlock, m_module );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				assert( m_parentId );
				m_result = m_module.registerLiteral( expr->getMemberIndex() );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				assert( m_parentId );

				if ( isAccessChain( expr->getRHS() ) )
				{
					m_result = makeAccessChain( expr->getRHS()
						, m_context
						, m_module
						, m_currentBlock );
				}
				else
				{
					m_result = submit( m_parentId
						, expr->getRHS()
						, m_context
						, m_module
						, m_currentBlock );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				auto var = expr->getVariable();

				if ( var->isAlias() )
				{
					assert( !m_parentId || m_parentKind == ast::expr::Kind::eArrayAccess );
					m_result = m_module.getVariablePointer( var->getName()
						, spv::StorageClassFunction
						, var->getType()
						, m_currentBlock );
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
					auto it = m_context.constAggrExprs.find( var->getId() );
					VariableInfo sourceInfo;

					if ( it != m_context.constAggrExprs.end() )
					{
						// Aggregated constants don't behave well with array access, instantiate the variable, with its initialisers.
						m_result = m_module.loadVariable( ExprVisitor::submit( expr, m_context, m_currentBlock, m_module ), m_currentBlock );
						m_result = m_module.registerVariable( var->getName()
							, var->getBuiltin()
							, getStorageClass( m_module.getVersion(), var )
							, false
							, false
							, false
							, expr->getType()
							, sourceInfo
							, m_result ).id;
					}
					else
					{
						m_result = m_module.registerVariable( var->getName()
							, var->getBuiltin()
							, getStorageClass( m_module.getVersion(), var )
							, false
							, false
							, var->isOutputParam()
							, expr->getType()
							, sourceInfo ).id;
					}

					if ( sourceInfo.needsStoreOnPromote() )
					{
						m_module.storePromoted( m_result
							, sourceInfo
							, m_currentBlock );
					}

					if ( m_parentKind == ast::expr::Kind::eArrayAccess )
					{
						m_result = m_module.loadVariable( m_result
							, m_currentBlock );
					}
				}
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				assert( m_parentId );

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

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				assert( m_parentId );

				if ( expr->getSwizzle().isOneComponent() )
				{
					m_result = m_module.registerLiteral( expr->getSwizzle().toIndex() );
				}
				else
				{
					m_result = makeVectorShuffle( expr
						, m_context
						, m_module
						, m_currentBlock );
				}
			}

			void visitAggrInitExpr( ast::expr::AggrInit * )override
			{
				AST_Failure( "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				AST_Failure( "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall * )override
			{
				AST_Failure( "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * )override
			{
				AST_Failure( "Unexpected ast::expr::ImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init * )override
			{
				AST_Failure( "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * )override
			{
				AST_Failure( "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question * )override
			{
				AST_Failure( "Unexpected ast::expr::Question ?" );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend * )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * )override
			{
				AST_Failure( "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * )override
			{
				AST_Failure( "Unexpected ast::expr::TextureAccessCall ?" );
			}

		private:
			ValueId & m_result;
			PreprocContext const & m_context;
			Module & m_module;
			Block & m_currentBlock;
			ValueId m_parentId;
			ast::expr::Kind m_parentKind;
		};

#define SPIRV_CacheAccessChains 0

		ValueId writeAccessChain( Block & currentBlock
			, ValueIdList const & accessChain
			, ast::expr::Expr * expr
			, Module & module )
		{
#if SPIRV_CacheAccessChains

			auto it = currentBlock.accessChains.find( accessChain );

			if ( it == currentBlock.accessChains.end() )
			{
				// Register the type pointed to.
				auto rawTypeId = module.registerType( expr->getType() );
				// Register the pointer to the type.
				auto pointerTypeId = module.registerPointerType( rawTypeId
					, getStorageClass( ast::findIdentifier( expr )->getVariable() ) );
				// Reserve the ID for the result.
				ValueId resultId{ module.getIntermediateResult(), pointerTypeId.type };
				// Write access chain => resultId = pointerTypeId( outer.members + index ).
				currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( pointerTypeId
					, resultId
					, accessChain ) );
				it = currentBlock.accessChains.emplace( accessChain, resultId ).first;
			}

			return it->second;

#else

			auto var = ast::findIdentifier( expr )->getVariable();
			// Register the type pointed to.
			auto rawTypeId = module.registerType( expr->getType() );
			// Register the pointer to the type.
			auto storageClass = getStorageClass( module.getVersion(), var );

			auto pointerTypeId = module.registerPointerType( rawTypeId
				, storageClass );
			// Reserve the ID for the result.
			ValueId result{ module.getIntermediateResult(), pointerTypeId.type };
			// Write access chain => resultId = pointerTypeId( outer.members + index ).
			currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( pointerTypeId
				, result
				, accessChain ) );
			return result;

#endif
		}

		bool isBuiltIn( ast::expr::Expr * expr )
		{
			return expr->getKind() == ast::expr::Kind::eIdentifier
				&& static_cast< ast::expr::Identifier const & >( *expr ).getVariable()->isBuiltin();
		}
	}

	bool isAccessChain( ast::expr::Expr * expr )
	{
		return expr->getKind() == ast::expr::Kind::eArrayAccess
			|| expr->getKind() == ast::expr::Kind::eMbrSelect
			|| ( expr->getKind() == ast::expr::Kind::eSwizzle
				&& ( !isScalarType( expr->getType()->getKind() )
					|| isBuiltIn( static_cast< ast::expr::Swizzle const & >( *expr ).getOuterExpr() ) ) )
			|| ( expr->getKind() == ast::expr::Kind::eIdentifier
				&& static_cast< ast::expr::Identifier const & >( *expr ).getVariable()->isMember() );
	}

	ValueId makeAccessChain( ast::expr::Expr * expr
		, PreprocContext const & context
		, Module & module
		, Block & currentBlock )
	{
		// Create Access Chain.
		ast::expr::ExprList idents;
		auto accessChainExprs = AccessChainLineariser::submit( expr->getCache(), expr, idents );
		auto accessChain = AccessChainCreator::submit( accessChainExprs
			, context
			, module
			, currentBlock );
		return writeAccessChain( currentBlock
			, accessChain
			, expr
			, module );
	}

	ValueId makeVectorShuffle( ast::expr::Swizzle * expr
		, PreprocContext const & context
		, Module & module
		, Block & currentBlock )
	{
		auto typeId = module.registerType( expr->getType() );
		auto outerId = module.loadVariable( ExprVisitor::submit( expr->getOuterExpr()
				, context
				, currentBlock
				, module )
			, currentBlock );
		ValueId result{ 0u, typeId.type };
		auto swizzleComponents = convert( getSwizzleComponents( expr->getSwizzle() ) );

		if ( swizzleComponents.size() == 1u )
		{
			ValueIdList extract;
			extract.push_back( outerId );
			extract.push_back( swizzleComponents.front() );
			auto intermediateId = ValueId{ module.getIntermediateResult(), typeId.type };
			currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( typeId
				, intermediateId
				, extract ) );
			result = intermediateId;
		}
		else
		{
			ValueIdList shuffle;
			shuffle.push_back( outerId );
			shuffle.push_back( outerId );
			shuffle.insert( shuffle.end(), swizzleComponents.begin(), swizzleComponents.end() );
			auto intermediateId = ValueId{ module.getIntermediateResult(), typeId.type };
			currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( typeId
				, intermediateId
				, shuffle ) );
			result = intermediateId;
		}

		assert( !result.isPointer() );
		return result;
	}
}
