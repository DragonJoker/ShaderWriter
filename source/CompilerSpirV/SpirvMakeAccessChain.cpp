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
					, idents );
			}

		private:
			AccessChainLineariser( ast::type::TypesCache & cache
				, ast::expr::Kind kind
				, AccessChainExprArray & result
				, ast::expr::ExprList & idents )
				: m_cache{ cache }
				, m_result{ result }
				, m_idents{ idents }
				, m_kind{ kind }
			{
			}

			static AccessChainExprArray submit( ast::type::TypesCache & cache
				, ast::expr::Kind kind
				, ast::expr::Expr * expr
				, ast::expr::ExprList & idents )
			{
				AccessChainExprArray result;
				AccessChainLineariser vis
				{
					cache,
					kind,
					result,
					idents
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
				assert( false && "Unexpected ast::expr::Unary ?" );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				assert( false && "Unexpected ast::expr::Binary ?" );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				auto outer = submit( m_cache, m_kind, expr->getOuterExpr(), m_idents );
				auto inner = submit( m_cache, expr->getKind(), expr->getOperand(), m_idents );
				m_result = outer;
				m_result.insert( m_result.end(), inner.begin(), inner.end() );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				auto lhs = submit( m_cache, m_kind, expr->getLHS(), m_idents );
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
					&& expr->getType()->isMember() )
				{
					m_idents.emplace_back( ast::expr::makeIdentifier( m_cache, expr->getVariable()->getOuter() ) );
					auto ident = m_idents.back().get();
					m_result = submit( m_cache, m_kind, ident, m_idents );
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
					m_result = submit( m_cache, m_kind, expr->getOuterExpr(), m_idents );
				}

				doAddExpr( m_kind, expr );
			}

			void visitAggrInitExpr( ast::expr::AggrInit * )override
			{
				assert( false && "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				assert( false && "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall * )override
			{
				assert( false && "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::ImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init * )override
			{
				assert( false && "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * )override
			{
				assert( false && "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question * )override
			{
				assert( false && "Unexpected ast::expr::Question ?" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * )override
			{
				assert( false && "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * )override
			{
				assert( false && "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::TextureAccessCall ?" );
			}

		private:
			ast::type::TypesCache & m_cache;
			AccessChainExprArray & m_result;
			ast::expr::ExprList & m_idents;
			ast::expr::Kind m_kind{ ast::expr::Kind::eIdentifier };
		};

		class AccessChainCreator
			: public ast::expr::SimpleVisitor
		{
		public:
			static IdList submit( AccessChainExprArray const & exprs
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables )
			{
				IdList result;
				assert( exprs.size() >= 2u );
				VariableInfo info;
				result.push_back( submit( exprs[0].expr
					, module
					, currentBlock
					, loadedVariables ) );

				for ( size_t i = 1u; i < exprs.size(); ++i )
				{
					auto & expr = exprs[i];
					result.push_back( submit( result.back()
						, expr
						, module
						, currentBlock
						, loadedVariables
						, info ) );
				}

				return result;
			}

		private:
			AccessChainCreator( spv::Id & result
				, ast::expr::Kind parentKind
				, spv::Id parentId
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables
				, VariableInfo & info )
				: m_result{ result }
				, m_module{ module }
				, m_currentBlock{ currentBlock }
				, m_loadedVariables{ loadedVariables }
				, m_parentId{ parentId }
				, m_parentKind{ parentKind }
				, m_info{ info }
			{
			}

			static spv::Id submit( ast::expr::Expr * expr
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables )
			{
				spv::Id result;
				VariableInfo info;
				AccessChainCreator vis
				{
					result,
					expr->getKind(),
					0u,
					module,
					currentBlock,
					loadedVariables,
					info
				};
				expr->accept( &vis );
				return result;
			}

			static spv::Id submit( spv::Id parentId
				, ast::expr::Expr * expr
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables )
			{
				spv::Id result;
				VariableInfo info;
				AccessChainCreator vis
				{
					result,
					expr->getKind(),
					parentId,
					module,
					currentBlock,
					loadedVariables,
					info
				};
				expr->accept( &vis );
				return result;
			}

			static spv::Id submit( spv::Id parentId
				, AccessChainExpr expr
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables
				, VariableInfo & info )
			{
				spv::Id result;
				AccessChainCreator vis
				{
					result,
					expr.kind,
					parentId,
					module,
					currentBlock,
					loadedVariables,
					info
				};
				expr.expr->accept( &vis );
				return result;
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				m_result = ExprVisitor::submit( expr, m_currentBlock, m_module, true, m_loadedVariables );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				m_result = ExprVisitor::submit( expr, m_currentBlock, m_module, true, m_loadedVariables );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				assert( m_parentId != 0u );
				m_result = submit( expr->getOperand(), m_module, m_currentBlock, m_loadedVariables );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				assert( m_parentId != 0u );

				if ( isAccessChain( expr->getRHS() ) )
				{
					auto accessChain = makeAccessChain( expr->getRHS(), m_module, m_currentBlock, m_loadedVariables );
					m_result = m_module.loadVariable( accessChain, expr->getRHS()->getType(), m_currentBlock );
				}
				else
				{
					m_result = submit( m_parentId, expr->getRHS(), m_module, m_currentBlock, m_loadedVariables );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				auto var = expr->getVariable();

				if ( m_parentId != 0u
					&& m_parentKind != ast::expr::Kind::eArrayAccess )
				{
					// Leaf or Intermediate identifier.
					// Store member only (parent has already be added).
					m_result = m_module.registerMemberVariableIndex( expr->getType() );
				}
				else
				{
					// Head identifier, or array access index.
					m_result = m_module.registerVariable( var->getName()
						, getStorageClass( var )
						, expr->getType()
						, m_info ).id;

					if ( m_parentKind == ast::expr::Kind::eArrayAccess )
					{
						m_result = m_module.loadVariable( m_result
							, expr->getType()
							, m_currentBlock );
					}
				}
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				assert( m_parentId != 0u );

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

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				assert( m_parentId != 0u );

				if ( expr->getSwizzle().isOneComponent() )
				{
					m_result = m_module.registerLiteral( expr->getSwizzle().toIndex() );
				}
				else
				{
					spv::Id parentId;

					if ( isAccessChain( expr->getOuterExpr() ) )
					{
						parentId = makeAccessChain( expr->getOuterExpr()
							, m_module
							, m_currentBlock
							, m_loadedVariables );

						if ( isPtrAccessChain( expr->getOuterExpr() ) )
						{
							parentId = m_module.loadVariable( parentId
								, expr->getOuterExpr()->getType()
								, m_currentBlock );
						}
					}
					else
					{
						parentId = ExprVisitor::submit( expr->getOuterExpr()
							, m_currentBlock
							, m_module );
					}

					auto typeId = m_module.registerType( expr->getType() );
					m_result = writeShuffle( m_module
						, m_currentBlock
						, typeId
						, parentId
						, expr->getSwizzle() );
				}
			}

			void visitAggrInitExpr( ast::expr::AggrInit * )override
			{
				assert( false && "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				assert( false && "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall * )override
			{
				assert( false && "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::ImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init * )override
			{
				assert( false && "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * )override
			{
				assert( false && "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question * )override
			{
				assert( false && "Unexpected ast::expr::Question ?" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * )override
			{
				assert( false && "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * )override
			{
				assert( false && "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::TextureAccessCall ?" );
			}

		private:
			spv::Id & m_result;
			Module & m_module;
			Block & m_currentBlock;
			LoadedVariableArray & m_loadedVariables;
			spv::Id m_parentId;
			ast::expr::Kind m_parentKind;
			VariableInfo & m_info;
		};

#define SPIRV_CacheAccessChains 0

		spv::Id writeAccessChain( Block & currentBlock
			, IdList const & accessChain
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
				auto resultId = module.getIntermediateResult();
				// Write access chain => resultId = pointerTypeId( outer.members + index ).
				currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( pointerTypeId
					, resultId
					, accessChain ) );
				it = currentBlock.accessChains.emplace( accessChain, resultId ).first;
			}

			return it->second;

#else

			// Register the type pointed to.
			auto rawTypeId = module.registerType( expr->getType() );
			// Register the pointer to the type.
			auto storageClass = getStorageClass( ast::findIdentifier( expr )->getVariable() );
			//auto rawKind = ast::type::getNonArrayKind( expr->getType() );

			//if ( ast::type::isSampledImageType( rawKind )
			//	|| ast::type::isImageType( rawKind ) 
			//	|| ast::type::isSamplerType( rawKind ) )
			//{
			//	storageClass = spv::StorageClassUniform;
			//}

			auto pointerTypeId = module.registerPointerType( rawTypeId
				, storageClass );
			// Reserve the ID for the result.
			auto resultId = module.getIntermediateResult();
			// Write access chain => resultId = pointerTypeId( outer.members + index ).
			currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( pointerTypeId
				, resultId
				, accessChain ) );
			return resultId;

#endif
		}
	}

	spv::Id writeShuffle( Module & module
		, Block & currentBlock
		, spv::Id typeId
		, spv::Id outerId
		, ast::expr::SwizzleKind swizzle )
	{
		spv::Id result;
		auto swizzleComponents = getSwizzleComponents( swizzle );
		spirv::IdList shuffle;

		if ( swizzleComponents.size() == 1u )
		{
			shuffle.push_back( outerId );
			shuffle.push_back( swizzleComponents.front() );
			auto it = currentBlock.vectorShuffles.find( shuffle );

			if ( it == currentBlock.vectorShuffles.end() )
			{
				auto intermediateId = module.getIntermediateResult();
				currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( typeId
					, intermediateId
					, shuffle ) );
				it = currentBlock.vectorShuffles.emplace( shuffle, intermediateId ).first;
			}

			result = it->second;
		}
		else
		{
			shuffle.push_back( outerId );
			shuffle.push_back( outerId );
			shuffle.insert( shuffle.end(), swizzleComponents.begin(), swizzleComponents.end() );
			auto it = currentBlock.vectorShuffles.find( shuffle );

			if ( it == currentBlock.vectorShuffles.end() )
			{
				auto intermediateId = module.getIntermediateResult();
				currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( typeId
					, intermediateId
					, shuffle ) );
				it = currentBlock.vectorShuffles.emplace( shuffle, intermediateId ).first;
			}

			result = it->second;
		}

		return result;
	}

	bool isAccessChain( ast::expr::Expr * expr )
	{
		return expr->getKind() == ast::expr::Kind::eArrayAccess
			|| expr->getKind() == ast::expr::Kind::eMbrSelect
			|| ( expr->getKind() == ast::expr::Kind::eSwizzle
				&& !isScalarType( expr->getType()->getKind() ) )
			|| ( expr->getKind() == ast::expr::Kind::eIdentifier
				&& static_cast< ast::expr::Identifier const & >( *expr ).getVariable()->isMember() );
	}

	bool isPtrAccessChain( ast::expr::Expr * expr )
	{
		return isAccessChain( expr )
			&& ( expr->getKind() == ast::expr::Kind::eArrayAccess
				|| expr->getKind() == ast::expr::Kind::eMbrSelect
				|| ( expr->getKind() == ast::expr::Kind::eSwizzle
					&& !isScalarType( expr->getType()->getKind() ) )
				|| ( expr->getKind() == ast::expr::Kind::eIdentifier
					&& static_cast< ast::expr::Identifier const & >( *expr ).getVariable()->isMember() ) );
	}

	spv::Id makeAccessChain( ast::expr::Expr * expr
		, Module & module
		, Block & currentBlock
		, LoadedVariableArray & loadedVariables )
	{
		// Create Access Chain.
		ast::expr::ExprList idents;
		auto accessChainExprs = AccessChainLineariser::submit( expr->getCache(), expr, idents );
		auto accessChain = AccessChainCreator::submit( accessChainExprs
			, module
			, currentBlock
			, loadedVariables );
		return writeAccessChain( currentBlock
			, accessChain
			, expr
			, module );
	}
}
