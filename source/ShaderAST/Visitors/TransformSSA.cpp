/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/TransformSSA.hpp"

#include "ShaderAST/ShaderStlTypes.hpp"
#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"
#include "ShaderAST/Visitors/CloneStmt.hpp"
#include "ShaderAST/Visitors/GetExprName.hpp"
#include "ShaderAST/Visitors/SimplifyStatements.hpp"

namespace ast
{
	namespace ssa
	{
		namespace helpers
		{
			static bool hasRuntimeArray( type::StructPtr type )
			{
				return type->end() != std::find_if( type->begin()
					, type->end()
					, []( type::Struct::Member const & lookup )
					{
						return lookup.type->getKind() == type::Kind::eArray
							&& getArraySize( lookup.type ) == type::UnknownArraySize;
					} );
			}

			static bool needsAlias( expr::Kind kind
				, bool uniform
				, bool param )
			{
				using expr::Kind;
				return ( uniform || kind != Kind::eIdentifier )
					&& ( param || kind != Kind::eMbrSelect )
					&& ( param || kind != Kind::eLiteral )
					&& ( param || kind != Kind::eSwizzle );
			}

			static bool isShaderVariable( expr::Expr const & expr )
			{
				return expr.getKind() == expr::Kind::eIdentifier
					&& ( static_cast< expr::Identifier const & >( expr ).getVariable()->isUniform()
						|| static_cast< expr::Identifier const & >( expr ).getVariable()->isShaderInput()
						|| static_cast< expr::Identifier const & >( expr ).getVariable()->isShaderOutput() );
			}
		}

		class StmtSSAiser;

		void declareStruct( type::StructPtr structType
			, StmtSSAiser & stmtVisitor );

		class ExprSSAiser
			: public expr::SimpleVisitor
		{
		public:
			static expr::ExprPtr submit( expr::Expr const & expr
				, stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, Map< uint32_t, var::VariablePtr > const & funcVarReplacements
				, stmt::Container * container
				, bool isParam
				, SSAData & data
				, StmtSSAiser & stmtVisitor )
			{
				expr::ExprPtr result{};
				ExprSSAiser vis{ data, stmtVisitor, stmtCache, exprCache, typesCache, funcVarReplacements, container, isParam, result };
				expr.accept( &vis );

				if ( expr.isNonUniform() )
				{
					result->updateFlag( ast::expr::Flag::eNonUniform );
				}

				return result;
			}

		private:
			ExprSSAiser( SSAData & data
				, StmtSSAiser & stmtVisitor
				, stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, Map< uint32_t, var::VariablePtr > const & funcVarReplacements
				, stmt::Container * container
				, bool isParam
				, expr::ExprPtr & result )
				: m_data{ data }
				, m_stmtVisitor{ stmtVisitor }
				, m_stmtCache{ stmtCache }
				, m_exprCache{ exprCache }
				, m_typesCache{ typesCache }
				, m_funcVarReplacements{ funcVarReplacements }
				, m_container{ container }
				, m_isParam{ isParam }
				, m_result{ result }
			{
			}

		protected:
			struct OutputParam
			{
				OutputParam( ast::expr::ExprPtr pparam
					, ast::var::VariablePtr palias )
					: param{ std::move( pparam ) }
					, alias{ std::move( palias ) }
				{
				}

				ast::expr::ExprPtr param{};
				ast::var::VariablePtr alias;
			};

			void doProcessOpaqueFnCallArg( var::Variable & param
				, expr::Expr const & arg
				, type::Kind kind
				, ast::expr::ExprList & args
				, std::vector< OutputParam > & outputParams )
			{
				if ( arg.getKind() == ast::expr::Kind::eArrayAccess )
				{
					ast::var::VariablePtr alias;
					auto newExpr = doSubmit( arg );
					ast::expr::ExprPtr aliasExpr{};

					if ( doMakeAlias( std::move( newExpr ), true, aliasExpr, alias ) )
					{
						if ( auto argIdent = findIdentifier( arg, kind, ast::var::Flag::eUniform );
							argIdent )
						{
							// For samplers and imges, the eUniform flag from the function parameter must be removed,
							// since the alias can't have it.
							param.updateFlag( ast::var::Flag::eUniform, false );
						}
					}

					args.emplace_back( std::move( aliasExpr ) );

					if ( param.isOutputParam()
						&& alias )
					{
						outputParams.emplace_back( doSubmit( arg ), alias );
					}
				}
				else
				{
					// Images/Samplers/Textures are uniform constant pointers.
					args.emplace_back( doSubmit( arg ) );
				}
			}

			void doProcessNonOpaqueFnCallArg( var::Variable const & param
				, expr::Expr const & arg
				, ast::expr::ExprList & args
				, std::vector< OutputParam > & outputParams )
			{
				ast::expr::ExprPtr aliasExpr{};
				ast::var::VariablePtr alias;
				doMakeAlias( doSubmit( arg ), true, aliasExpr, alias );
				args.emplace_back( std::move( aliasExpr ) );

				if ( param.isOutputParam()
					&& alias )
				{
					outputParams.emplace_back( doSubmit( arg ), alias );
				}
			}

			void doProcessFnCallArg( var::Variable & param
				, expr::Expr const & arg
				, ast::expr::ExprList & args
				, std::vector< OutputParam > & outputParams )
			{
				visitType( arg.getType() );
				auto kind = getNonArrayKind( arg.getType() );

				if ( isOpaqueType( kind ) )
				{
					doProcessOpaqueFnCallArg( param, arg, kind, args, outputParams );
				}
				else
				{
					doProcessNonOpaqueFnCallArg( param, arg, args, outputParams );
				}
			}

			void visitType( type::TypePtr type )
			{
				if ( auto structType = getStructType( type ) )
				{
					declareStruct( structType, m_stmtVisitor );
				}
			}

			void visitUnaryExpr( expr::Unary const * expr )override
			{
				TraceFunc;
				visitType( expr->getType() );
				visitType( expr->getOperand()->getType() );

				switch ( expr->getKind() )
				{
				case expr::Kind::eCopy:
					m_result = m_exprCache.makeCopy( doSubmit( *expr->getOperand() ) );
					break;
				case expr::Kind::eBitNot:
					doProcessUnExprT< expr::BitNot >( *expr );
					break;
				case expr::Kind::eLogNot:
					doProcessUnExprT< expr::LogNot >( *expr );
					break;
				case expr::Kind::ePostDecrement:
					doProcessPrePostIncDecExprT< expr::Minus >( *expr, false );
					break;
				case expr::Kind::ePostIncrement:
					doProcessPrePostIncDecExprT< expr::Add >( *expr, false );
					break;
				case expr::Kind::ePreDecrement:
					doProcessPrePostIncDecExprT< expr::Minus >( *expr, true );
					break;
				case expr::Kind::ePreIncrement:
					doProcessPrePostIncDecExprT< expr::Add >( *expr, true );
					break;
				case expr::Kind::eUnaryMinus:
					m_result = m_exprCache.makeUnaryMinus( doSubmit( *expr->getOperand() ) );
					break;
				case expr::Kind::eUnaryPlus:
					m_result = doSubmit( *expr->getOperand() );
					break;
				default:
					AST_Failure( "Unexpected unary expression type" );
					break;
				}

				if ( expr->getOperand()->isNonUniform() )
				{
					m_result->updateFlag( ast::expr::Flag::eNonUniform );
				}
			}

			void visitBinaryExpr( expr::Binary const * expr )override
			{
				TraceFunc;
				visitType( expr->getType() );
				visitType( expr->getLHS()->getType() );
				visitType( expr->getRHS()->getType() );

				switch ( expr->getKind() )
				{
				case expr::Kind::eArrayAccess:
					doProcessBinExprT< expr::ArrayAccess >( *expr );
					break;
				case expr::Kind::eAssign:
					doProcessBinExprT< expr::Assign >( *expr );
					break;
				case expr::Kind::eComma:
					doProcessBinExprT< expr::Assign >( *expr );
					break;
				case expr::Kind::eModulo:
					doProcessBinExprT< expr::Modulo >( *expr );
					break;
				case expr::Kind::eLShift:
					doProcessBinExprT< expr::LShift >( *expr );
					break;
				case expr::Kind::eRShift:
					doProcessBinExprT< expr::RShift >( *expr );
					break;
				case expr::Kind::eBitAnd:
					doProcessBinExprT< expr::BitAnd >( *expr );
					break;
				case expr::Kind::eBitOr:
					doProcessBinExprT< expr::BitOr >( *expr );
					break;
				case expr::Kind::eBitXor:
					doProcessBinExprT< expr::BitXor >( *expr );
					break;
				case expr::Kind::eLogAnd:
					doProcessBinExprT< expr::LogAnd >( *expr );
					break;
				case expr::Kind::eLogOr:
					doProcessBinExprT< expr::LogOr >( *expr );
					break;
				case expr::Kind::eEqual:
					doProcessBinExprT< expr::Equal >( *expr );
					break;
				case expr::Kind::eGreater:
					doProcessBinExprT< expr::Greater >( *expr );
					break;
				case expr::Kind::eGreaterEqual:
					doProcessBinExprT< expr::GreaterEqual >( *expr );
					break;
				case expr::Kind::eLess:
					doProcessBinExprT< expr::Less >( *expr );
					break;
				case expr::Kind::eLessEqual:
					doProcessBinExprT< expr::LessEqual >( *expr );
					break;
				case expr::Kind::eNotEqual:
					doProcessBinExprT< expr::NotEqual >( *expr );
					break;
				case expr::Kind::eModuloAssign:
					doProcessAssignBinExprT< expr::Modulo >( *expr );
					break;
				case expr::Kind::eLShiftAssign:
					doProcessAssignBinExprT< expr::LShift >( *expr );
					break;
				case expr::Kind::eRShiftAssign:
					doProcessAssignBinExprT< expr::RShift >( *expr );
					break;
				case expr::Kind::eAndAssign:
					doProcessAssignBinExprT< expr::BitAnd >( *expr );
					break;
				case expr::Kind::eOrAssign:
					doProcessAssignBinExprT< expr::BitOr >( *expr );
					break;
				case expr::Kind::eXorAssign:
					doProcessAssignBinExprT< expr::BitXor >( *expr );
					break;
				default:
					AST_Failure( "Unexpected binary expression type" );
					break;
				}

				if ( expr->getLHS()->isNonUniform()
					|| expr->getRHS()->isNonUniform() )
				{
					m_result->updateFlag( ast::expr::Flag::eNonUniform );
				}
			}

			void visitAddAssignExpr( expr::AddAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eAdd
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitAddExpr( expr::Add const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eAdd
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void visitCastExpr( ast::expr::Cast const * expr )override
			{
				TraceFunc;
				visitType( expr->getType() );
				visitType( expr->getOperand()->getType() );
				m_result = m_exprCache.makeCast( expr->getType()
					, doSubmit( *expr->getOperand() ) );
			}

			void visitDivideAssignExpr( expr::DivideAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eDivide
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitDivideExpr( expr::Divide const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eDivide
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void visitMinusAssignExpr( expr::MinusAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eMinus
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitMinusExpr( expr::Minus const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eMinus
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void visitTimesAssignExpr( expr::TimesAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eTimes
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitTimesExpr( expr::Times const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eTimes
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void visitAggrInitExpr( expr::AggrInit const * expr )override
			{
				TraceFunc;
				visitType( expr->getType() );
				expr::ExprList initialisers;

				for ( auto & init : expr->getInitialisers() )
				{
					initialisers.push_back( doSubmit( *init ) );
					assert( initialisers.back() );
				}

				if ( expr->hasIdentifier() )
				{
					m_result = m_exprCache.makeAggrInit( m_exprCache.makeIdentifier( m_typesCache, expr->getIdentifier().getVariable() )
						, std::move( initialisers ) );
				}
				else
				{
					m_result = m_exprCache.makeAggrInit( expr->getType()
						, std::move( initialisers ) );
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override
			{
				TraceFunc;
				visitType( expr->getType() );

				if ( expr->getArgList().size() == 1u
					&& !isScalarType( expr->getArgList().front()->getType()->getKind() ) )
				{
					auto const & arg = *expr->getArgList().front();
					auto argType = arg.getType();
					ast::var::VariablePtr alias;
					ast::expr::ExprPtr argAlias{};
					ast::expr::ExprList args;
					doMakeAlias( doSubmit( arg ), false, argAlias, alias );
					args.push_back( std::move( argAlias ) );
					m_result = m_exprCache.makeCompositeConstruct( expr->getComposite()
						, expr->getComponent()
						, std::move( args ) );
				}
				else
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.push_back( doSubmit( *arg ) );
					}

					if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
					{
						m_result = m_exprCache.makeCompositeConstruct( std::move( args.front() )
							, std::move( args.back() ) );
					}
					else
					{
						m_result = m_exprCache.makeCompositeConstruct( expr->getComposite()
							, expr->getComponent()
							, std::move( args ) );
					}
				}
			}

			void visitFnCallExpr( expr::FnCall const * expr )override
			{
				TraceFunc;
				ast::expr::ExprList args;
				std::vector< OutputParam > outputParams;
				auto funcVar = expr->getFn()->getVariable();

				if ( auto varIt = m_funcVarReplacements.find( funcVar->getId() );
					varIt != m_funcVarReplacements.end() )
				{
					funcVar = varIt->second;
				}

				auto fnType = std::static_pointer_cast< ast::type::Function >( funcVar->getType() );
				visitType( fnType->getReturnType() );
				auto it = fnType->begin();

				for ( auto & arg : expr->getArgList() )
				{
					auto const & param = *( it++ );
					doProcessFnCallArg( *param, *arg, args, outputParams );
				}

				if ( expr->isMember() )
				{
					m_result = m_exprCache.makeMemberFnCall( expr->getType()
						, m_exprCache.makeIdentifier( m_typesCache, funcVar )
						, doSubmit( *expr->getInstance() )
						, std::move( args ) );
				}
				else
				{
					m_result = m_exprCache.makeFnCall( expr->getType()
						, m_exprCache.makeIdentifier( m_typesCache, funcVar )
						, std::move( args ) );
				}

				if ( expr->getType()->getKind() != ast::type::Kind::eVoid )
				{
					// Store function result into a return alias, that will be the final result.
					auto var = doCreateAliasVar( expr->getType()
						, std::move( m_result ) );
					m_result = m_exprCache.makeIdentifier( m_typesCache, var );
				}
				else
				{
					doAddStmt( m_stmtCache.makeSimple( std::move( m_result ) ) );
				}

				for ( auto & var : outputParams )
				{
					doAddStmt( m_stmtCache.makeSimple( m_exprCache.makeAssign( var.alias->getType()
						, std::move( var.param )
						, m_exprCache.makeIdentifier( m_typesCache, var.alias ) ) ) );
				}
			}

			void visitIdentifierExpr( expr::Identifier const * expr )override
			{
				TraceFunc;
				visitType( expr->getType() );
				m_result = m_exprCache.makeIdentifier( expr->getTypesCache()
					, expr->getVariable() );
			}

			void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
			{
				TraceFunc;
				ast::expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				auto dstType = expr->getType();
				m_result = m_exprCache.makeStorageImageAccessCall( dstType
					, expr->getImageAccess()
					, std::move( args ) );

				if ( dstType->getKind() != ast::type::Kind::eVoid )
				{
					auto type = m_result->getType();
					auto alias = doCreateAliasVar( type
						, std::move( m_result ) );
					m_result = m_exprCache.makeIdentifier( m_typesCache, alias );
				}
			}

			void visitInitExpr( expr::Init const * expr )override
			{
				TraceFunc;
				if ( expr->getInitialiser()->isConstant() )
				{
					m_result = doSubmit( *expr->getInitialiser() );

					if ( expr->hasIdentifier() )
					{
						m_result = m_exprCache.makeInit( m_exprCache.makeIdentifier( m_typesCache, expr->getIdentifier().getVariable() )
							, std::move( m_result ) );
					}
				}
				else
				{
					expr::ExprPtr aliasExpr{};
					var::VariablePtr alias;
					doMakeAlias( doSubmit( *expr->getInitialiser() )
						, m_isParam
						, aliasExpr
						, alias );

					if ( expr->hasIdentifier() )
					{
						m_result = m_exprCache.makeInit( m_exprCache.makeIdentifier( m_typesCache, expr->getIdentifier().getVariable() )
							, std::move( aliasExpr ) );
					}
					else
					{
						m_result = std::move( aliasExpr );
					}
				}
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override
			{
				TraceFunc;
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				m_result = m_exprCache.makeIntrinsicCall( expr->getType()
					, expr->getIntrinsic()
					, std::move( args ) );
			}

			void visitLiteralExpr( expr::Literal const * expr )override
			{
				TraceFunc;
				m_result = m_exprCache.makeLiteral( *expr );
			}

			void visitMbrSelectExpr( expr::MbrSelect const * expr )override
			{
				TraceFunc;
				m_result = m_exprCache.makeMbrSelect( doSubmit( *expr->getOuterExpr() )
					, expr->getMemberIndex()
					, expr->getMemberFlags() );
			}

			void visitQuestionExpr( expr::Question const * expr )override
			{
				visitType( expr->getType() );
				auto condComponents = getComponentCount( expr->getCtrlExpr()->getType()->getKind() );
				auto opsComponents = getComponentCount( expr->getTrueExpr()->getType()->getKind() );

				if ( condComponents == opsComponents )
				{
					m_result = m_exprCache.makeQuestion( expr->getType()
						, doSubmit( *expr->getCtrlExpr() )
						, doSubmit( *expr->getTrueExpr() )
						, doSubmit( *expr->getFalseExpr() ) );
				}
				else
				{
					assert( condComponents == 1u );
					expr::ExprPtr argAlias{};
					ast::var::VariablePtr alias;
					doMakeAlias( doSubmit( *expr->getCtrlExpr() )
						, false
						, argAlias
						, alias );
					m_result = m_exprCache.makeQuestion( expr->getType()
						, std::move( argAlias )
						, doSubmit( *expr->getTrueExpr() )
						, doSubmit( *expr->getFalseExpr() ) );
				}
			}

			void visitStreamAppendExpr( expr::StreamAppend const * expr )override
			{
				TraceFunc;
				visitType( expr->getType() );
				visitType( expr->getOperand()->getType() );
				m_result = m_exprCache.makeStreamAppend( doSubmit( *expr->getOperand() ) );
			}

			void visitSwitchCaseExpr( expr::SwitchCase const * expr )override
			{
				TraceFunc;
				m_result = m_exprCache.makeSwitchCase( m_exprCache.makeLiteral( *expr->getLabel() ) );
			}

			void visitSwitchTestExpr( expr::SwitchTest const * expr )override
			{
				TraceFunc;
				m_result = m_exprCache.makeSwitchTest( doSubmit( *expr->getValue() ) );
			}

			void visitSwizzleExpr( expr::Swizzle const * expr )override
			{
				TraceFunc;
				m_result = m_exprCache.makeSwizzle( doSubmit( *expr->getOuterExpr() )
					, expr->getSwizzle() );
			}

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
			{
				TraceFunc;
				auto kind = expr->getCombinedImageAccess();
				auto returnType = expr->getType();
				ast::expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				m_result = m_exprCache.makeCombinedImageAccessCall( returnType
					, kind
					, std::move( args ) );
				auto type = m_result->getType();
				auto alias = doCreateAliasVar( type
					, std::move( m_result ) );
				m_result = m_exprCache.makeIdentifier( m_typesCache, alias );
			}

		private:
			var::VariablePtr doCreateVar( type::TypePtr type
				, expr::ExprPtr aliasedExpr
				, uint64_t flags )
			{
				TraceFunc;
				auto kind = getNonArrayKind( type );
				++m_data.nextVarId;
				++m_data.aliasId;
				auto result = var::makeVariable( m_data.nextVarId
					, type
					, "tmp_" + std::to_string( m_data.aliasId )
					, ( var::Flag::eImplicit
						| var::Flag::eLocale
						| flags ) );

				if ( isOpaqueType( kind ) )
				{
					result->updateFlag( var::Flag::eConstant );
					result->updateFlag( var::Flag::eUniform );
				}

				if ( flags & uint64_t( var::Flag::eAlias ) )
				{
					doAddStmt( m_stmtCache.makeSimple( m_exprCache.makeAlias( result->getType()
						, m_exprCache.makeIdentifier( m_typesCache, result )
						, std::move( aliasedExpr ) ) ) );
				}
				else
				{
					doAddStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( m_typesCache, result )
						, std::move( aliasedExpr ) ) ) );
				}

				return result;
			}

			var::VariablePtr doCreateAliasVar( type::TypePtr type
				, expr::ExprPtr aliasedExpr )
			{
				TraceFunc;
				return doCreateVar( type
					, std::move( aliasedExpr )
					, ( var::Flag::eTemp | var::Flag::eAlias ) );
			}

			bool doMakeAlias( expr::ExprPtr expr
				, bool param
				, expr::ExprPtr & aliasExpr
				, var::VariablePtr & alias
				, bool force = false )
			{
				TraceFunc;
				if ( expr->getKind() == ast::expr::Kind::eIdentifier
					&& static_cast< ast::expr::Identifier const & >( *expr ).getVariable()->isAlias() )
				{
					aliasExpr = std::move( expr );
					return false;
				}

				if ( !force
					&& ( isOpaqueType( getNonArrayKind( expr->getType() ) )
						|| !helpers::needsAlias( expr->getKind()
							, helpers::isShaderVariable( *expr )
							, param ) ) )
				{
					aliasExpr = std::move( expr );
					return false;
				}

				auto type = expr->getType();
				alias = doCreateAliasVar( type
					, std::move( expr ) );
				aliasExpr = m_exprCache.makeIdentifier( m_typesCache, alias );
				return true;
			}

			expr::ExprPtr doSubmit( expr::Expr const & expr )
			{
				return submit( expr
					, m_stmtCache
					, m_exprCache
					, m_typesCache
					, m_funcVarReplacements
					, m_container
					, m_isParam
					, m_data
					, m_stmtVisitor );
			}

			template< typename ExprT >
			void doProcessAssignBinExprT( expr::Binary const & expr )
			{
				TraceFunc;
				expr::ExprPtr aliasExpr{};
				var::VariablePtr alias;
				auto lhs = doSubmit( *expr.getLHS() );
				doMakeAlias( m_exprCache.makeExpr< ExprT >( expr.getType()
					, doSubmit( *lhs )
					, doSubmit( *expr.getRHS() ) )
					, false
					, aliasExpr
					, alias
					, true );
				doAddStmt( m_stmtCache.makeSimple( m_exprCache.makeAssign( lhs->getType()
					, doSubmit( *lhs )
					, std::move( aliasExpr ) ) ) );
				m_result = std::move( lhs );
			}

			template< typename ExprT >
			void doProcessAssignUnExprT( expr::Binary const & expr )
			{
				TraceFunc;
				expr::ExprPtr aliasExpr{};
				var::VariablePtr alias;
				auto lhs = doSubmit( *expr.getLHS() );
				doMakeAlias( m_exprCache.makeExpr< ExprT >( expr.getType()
					, doSubmit( *expr.getLHS() ) )
					, false
					, aliasExpr
					, alias
					, true );
				doAddStmt( m_stmtCache.makeSimple( m_exprCache.makeAssign( lhs->getType()
					, doSubmit( *lhs )
					, std::move( aliasExpr ) ) ) );
				m_result = std::move( lhs );
			}

			template< typename ExprT >
			void doProcessBinExprT( expr::Binary const & expr )
			{
				TraceFunc;
				m_result = m_exprCache.makeExpr< ExprT >( expr.getType()
					, doSubmit( *expr.getLHS() )
					, doSubmit( *expr.getRHS() ) );
			}

			template< typename ExprT >
			void doProcessUnExprT( expr::Unary const & expr )
			{
				TraceFunc;
				m_result = m_exprCache.makeExpr< ExprT >( expr.getType()
					, doSubmit( *expr.getOperand() ) );
			}

			template< typename ExprT >
			void doProcessPrePostIncDecExprT( expr::Unary const & expr
				, bool isPre )
			{
				TraceFunc;
				var::VariablePtr opAlias;
				auto lhs = doSubmit( *expr.getOperand() );

				if ( !isPre )
				{
					opAlias = doCreateVar( expr.getType()
						, doSubmit( *lhs )
						, uint32_t( var::Flag::eTemp ) );
				}

				expr::ExprPtr aliasExpr{};
				var::VariablePtr alias;
				doMakeAlias( m_exprCache.makeExpr< ExprT >( expr.getType()
					, doSubmit( *lhs )
					, makeOne( m_exprCache, expr.getType() ) )
					, false
					, aliasExpr
					, alias
					, true );
				doAddStmt( m_stmtCache.makeSimple( m_exprCache.makeAssign( lhs->getType()
					, doSubmit( *lhs )
					, std::move( aliasExpr ) ) ) );

				if ( isPre )
				{
					m_result = std::move( lhs );
				}
				else
				{
					m_result = m_exprCache.makeIdentifier( m_typesCache, opAlias );
				}
			}

			type::TypePtr doPromoteScalar( expr::ExprPtr & lhs
				, expr::ExprPtr & rhs )
			{
				TraceFunc;
				auto lhsScalar = isScalarType( lhs->getType()->getKind() );
				auto rhsScalar = isScalarType( rhs->getType()->getKind() );
				auto result = lhs->getType();

				if ( !lhsScalar || !rhsScalar )
				{
					if ( !lhsScalar && !rhsScalar )
					{
						assert( lhs->getType()->getKind() == rhs->getType()->getKind()
							&& "TODO" );
					}
					else if ( lhsScalar )
					{
						result = rhs->getType();
						expr::ExprPtr alias{};
						var::VariablePtr aliasVar;
						doMakeAlias( doSubmit( *lhs ), false, alias, aliasVar );
						lhs = doSubmit( *alias );
					}
					else if ( rhsScalar )
					{
						result = lhs->getType();
						expr::ExprPtr alias{};
						var::VariablePtr aliasVar;
						doMakeAlias( doSubmit( *rhs ), false, alias, aliasVar );
						rhs = doSubmit( *alias );
					}
				}

				return result;
			}

			expr::ExprPtr doWriteBinaryOperation( expr::Kind operation
				, type::TypePtr resType
				, expr::Expr const & rlhs
				, expr::Expr const & rrhs )
			{
				TraceFunc;
				auto lhs = &rlhs;
				auto rhs = &rrhs;
				visitType( resType );
				visitType( lhs->getType() );
				visitType( rhs->getType() );
				bool needMatchingVectors;
				bool switchParams;
				auto forceRhsType = isMatrixTimesVector( operation
					, lhs->getType()->getKind()
					, rhs->getType()->getKind()
					, switchParams
					, needMatchingVectors );

				if ( switchParams )
				{
					std::swap( lhs, rhs );
				}

				auto lhsType = lhs->getType();
				auto rhsType = rhs->getType();
				bool lhsMat = isMatrixType( lhsType->getKind() );
				bool rhsMat = isMatrixType( rhsType->getKind() );
				auto lhsExpr = doSubmit( *lhs );
				auto rhsExpr = doSubmit( *rhs );
				auto type = lhsExpr->getType();
				expr::ExprPtr result{};

				if ( lhsMat || rhsMat )
				{
					if ( forceRhsType )
					{
						type = resType;
					}

					expr::ExprList args;
					var::VariablePtr lhsAlias;
					var::VariablePtr rhsAlias;
					expr::ExprPtr lhsResExpr;
					expr::ExprPtr rhsResExpr;
					doMakeAlias( std::move( lhsExpr ), false, lhsResExpr, lhsAlias );
					doMakeAlias( std::move( rhsExpr ), false, rhsResExpr, rhsAlias );

					switch ( operation )
					{
					case expr::Kind::eAdd:
						result = m_exprCache.makeAdd( type
							, std::move( lhsResExpr )
							, std::move( rhsResExpr ) );
						break;
					case expr::Kind::eDivide:
						result = m_exprCache.makeDivide( type
							, std::move( lhsResExpr )
							, std::move( rhsResExpr ) );
						break;
					case expr::Kind::eMinus:
						result = m_exprCache.makeMinus( type
							, std::move( lhsResExpr )
							, std::move( rhsResExpr ) );
						break;
					case expr::Kind::eTimes:
						result = m_exprCache.makeTimes( type
							, std::move( lhsResExpr )
							, std::move( rhsResExpr ) );
						break;
					default:
						AST_Failure( "Unsupported binary operation" );
						break;
					}
				}
				else
				{
					if ( needMatchingVectors )
					{
						type = doPromoteScalar( lhsExpr, rhsExpr );
					}

					expr::ExprList args;

					switch ( operation )
					{
					case expr::Kind::eAdd:
						result = m_exprCache.makeAdd( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eDivide:
						result = m_exprCache.makeDivide( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eMinus:
						result = m_exprCache.makeMinus( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eTimes:
						result = m_exprCache.makeTimes( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					default:
						AST_Failure( "Unsupported binary operation" );
						break;
					}
				}

				return result;
			}

			void doAddStmt( stmt::StmtPtr stmt )
			{
				TraceFunc;
				if ( stmt->getKind() == stmt::Kind::eSimple )
				{
					auto expr = static_cast< stmt::Simple const & >( *stmt ).getExpr();

					if ( expr->getKind() == expr::Kind::eIdentifier )
					{
						return;
					}
				}

				m_container->addStmt( std::move( stmt ) );
			}

		private:
			SSAData & m_data;
			StmtSSAiser & m_stmtVisitor;
			stmt::StmtCache & m_stmtCache;
			expr::ExprCache & m_exprCache;
			type::TypesCache & m_typesCache;
			Map< uint32_t, var::VariablePtr > const & m_funcVarReplacements;
			stmt::Container * m_container;
			bool m_isParam;
			expr::ExprPtr & m_result;
		};

		class StmtSSAiser
			: public StmtCloner
		{
		public:
			static stmt::ContainerPtr submit( stmt::Container const & stmt
				, stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, SSAData & data
				, bool normaliseStructs )
			{
				stmt::ContainerPtr result = stmtCache.makeContainer();
				StmtSSAiser vis{ data, stmtCache, exprCache, typesCache, result, normaliseStructs };
				stmt.accept( &vis );
				return result;
			}

			void declareStruct( type::StructPtr structType )
			{
				if ( !m_normaliseStructs )
				{
					return;
				}

				if ( structType->getName() != "SDW_VoidInput"
					&& structType->getName() != "SDW_VoidOutput"
					&& m_declaredStructs.insert( structType->getName() ).second )
				{
					for ( auto & member : *structType )
					{
						if ( auto subStructType = getStructType( getNonArrayType( member.type ) ) )
						{
							declareStruct( subStructType );
						}
					}

					if ( !helpers::hasRuntimeArray( structType ) )
					{
						m_typeDeclarations->addStmt( m_stmtCache.makeStructureDecl( structType ) );
					}
				}
			}

			void declareStruct( type::TypePtr type )
			{
				if ( auto structType = getStructType( type ) )
				{
					declareStruct( structType );
				}
			}

		private:
			StmtSSAiser( SSAData & data
				, stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::ContainerPtr & result
				, bool normaliseStructs )
				: StmtCloner{ stmtCache, exprCache, result }
				, m_data{ data }
				, m_normaliseStructs{ normaliseStructs }
				, m_typesCache{ typesCache }
				, m_funcVarReplacements{ &m_stmtCache.getAllocator() }
			{
				auto cont = m_stmtCache.makeContainer();
				m_typeDeclarations = cont.get();
				m_current->addStmt( std::move( cont ) );
			}

		protected:
			using ast::StmtCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				return ExprSSAiser::submit( expr
					, m_stmtCache
					, m_exprCache
					, m_typesCache
					, m_funcVarReplacements
					, m_current
					, false
					, m_data
					, *this );
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				AST_Failure( "Unexpected Else statement." );
			}

			void visitIfStmt( ast::stmt::If const * stmt )override
			{
				TraceFunc;
				auto save = m_current;
				auto cont = m_stmtCache.makeIf( doSubmit( stmt->getCtrlExpr() ) );
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;
				auto currentIf = cont.get();
				m_current->addStmt( std::move( cont ) );

				// Replace all else ifs by the following :
				// Origin:
				// if (condA){}
				// else if (condB){}
				// else{}
				//
				// Result:
				// if (condA){}
				// else
				// {
				//   if (condB){}
				//   else{}
				// }
				if ( stmt->getElse()
					|| !stmt->getElseIfList().empty() )
				{
					auto & elseIfs = stmt->getElseIfList();
					auto it = elseIfs.begin();

					while ( it != elseIfs.end() )
					{
						auto elseStmt = currentIf->createElse();
						m_current = elseStmt;
						auto & elseIf = *it;
						cont = m_stmtCache.makeIf( doSubmit( elseIf->getCtrlExpr() ) );
						m_current = cont.get();
						visitContainerStmt( elseIf.get() );
						m_current = save;
						currentIf = cont.get();
						elseStmt->addStmt( std::move( cont ) );
						++it;
					}

					if ( stmt->getElse() )
					{
						auto elseStmt = currentIf->createElse();
						m_current = elseStmt;
						visitContainerStmt( stmt->getElse() );
						m_current = save;
					}
				}
			}

			void visitForStmt( stmt::For const * stmt )override
			{
				TraceFunc;
				auto block = m_stmtCache.makeCompound();
				auto save = m_current;
				m_current = block.get();
				m_current->addStmt( m_stmtCache.makeSimple( doSubmit( stmt->getInitExpr() ) ) );
				auto ifStmt = m_stmtCache.makeIf( doSubmit( stmt->getCtrlExpr() ) );
				{
					// Do ... while content
					auto doWhileContent = m_stmtCache.makeDoWhile( doSubmit( stmt->getCtrlExpr() ) );
					auto save2 = m_current;
					m_current = doWhileContent.get();
					visitContainerStmt( stmt );
					doAddStmt( m_stmtCache.makeSimple( doSubmit( stmt->getIncrExpr() ) ) );
					m_current = save2;
					ifStmt->addStmt( std::move( doWhileContent ) );
				}
				m_current->addStmt( std::move( ifStmt ) );
				m_current = save;
				m_current->addStmt( std::move( block ) );
			}

			void visitWhileStmt( stmt::While const * stmt )override
			{
				TraceFunc;
				auto ifStmt = m_stmtCache.makeIf( doSubmit( stmt->getCtrlExpr() ) );
				{
					// Do ... while content
					auto doWhileContent = m_stmtCache.makeDoWhile( doSubmit( stmt->getCtrlExpr() ) );
					auto save = m_current;
					m_current = doWhileContent.get();
					visitContainerStmt( stmt );
					m_current = save;
					ifStmt->addStmt( std::move( doWhileContent ) );
				}
				m_current->addStmt( std::move( ifStmt ) );
			}

			void visitFragmentLayoutStmt( stmt::FragmentLayout const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				m_fragmentLayoutStmt = stmt;
			}

			void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				m_outputGeometryLayoutStmt = stmt;
			}

			void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				m_inputGeometryLayoutStmt = stmt;
			}

			void visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				m_outputTessCtrlLayoutStmt = stmt;
			}

			void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				m_intputTessEvalLayoutStmt = stmt;
			}

			void visitFunctionDeclStmt( stmt::FunctionDecl const * stmt )override
			{
				TraceFunc;
				auto fnType = &static_cast< type::Function const & >( *stmt->getType() );
				declareStruct( fnType->getReturnType() );

				for ( auto & param : *fnType )
				{
					declareStruct( param->getType() );
				}

				if ( stmt->isEntryPoint() )
				{
					if ( stmt->getType()->size() < 2u
						&& m_outputGeometryLayoutStmt
						&& m_inputGeometryLayoutStmt )
					{
						auto funcVar = stmt->getFuncVar();
						auto funcType = stmt->getType();
						auto inType = type::makeGeometryInputType( m_inputGeometryLayoutStmt->getType()
							, m_inputGeometryLayoutStmt->getLayout() );
						auto outType = type::makeGeometryOutputType( m_outputGeometryLayoutStmt->getType()
							, m_outputGeometryLayoutStmt->getLayout()
							, m_outputGeometryLayoutStmt->getPrimCount() );
						var::VariableList parameters;
						parameters.push_back( var::makeVariable( EntityName{ ++m_data.nextVarId, "geomData" }
							, inType
							, var::Flag::eInputParam | var::Flag::eShaderInput ) );
						parameters.push_back( var::makeVariable( EntityName{ ++m_data.nextVarId, "geomStream" }
							, outType
							, var::Flag::eInputParam | var::Flag::eOutputParam | var::Flag::eShaderOutput ) );

						auto & typesCache = funcType->getTypesCache();
						funcType = typesCache.getFunction( funcType->getReturnType()
							, std::move( parameters ) );
						auto save = m_current;
						funcVar = ast::var::makeVariable( funcVar->getId()
							, funcType
							, stmt->getName()
							, funcVar->getFlags() );
						m_funcVarReplacements.try_emplace( funcVar->getId(), funcVar );
						auto cont = m_stmtCache.makeFunctionDecl( std::move( funcVar )
							, stmt->getFlags() );
						m_current = cont.get();
						visitContainerStmt( stmt );
						m_current = save;
						m_current->addStmt( std::move( cont ) );
					}
					else
					{
						StmtCloner::visitFunctionDeclStmt( stmt );
					}
				}
				else
				{
					StmtCloner::visitFunctionDeclStmt( stmt );
				}
			}

			void visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getVariable()->getType() );
				StmtCloner::visitAccelerationStructureDeclStmt( stmt );
			}

			void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				StmtCloner::visitBufferReferenceDeclStmt( stmt );
			}

			void visitDispatchMeshStmt( stmt::DispatchMesh const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getPayload()->getType() );
				StmtCloner::visitDispatchMeshStmt( stmt );
			}

			void visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getVariable()->getType() );
				StmtCloner::visitHitAttributeVariableDeclStmt( stmt );
			}

			void visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getVariable()->getType() );
				StmtCloner::visitInOutCallableDataVariableDeclStmt( stmt );
			}

			void visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getVariable()->getType() );
				StmtCloner::visitInOutRayPayloadVariableDeclStmt( stmt );
			}

			void visitInOutVariableDeclStmt( stmt::InOutVariableDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getVariable()->getType() );
				StmtCloner::visitInOutVariableDeclStmt( stmt );
			}

			void visitInputComputeLayoutStmt( stmt::InputComputeLayout const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				StmtCloner::visitInputComputeLayoutStmt( stmt );
			}

			void visitOutputMeshLayoutStmt( stmt::OutputMeshLayout const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				StmtCloner::visitOutputMeshLayoutStmt( stmt );
			}

			void visitReturnStmt( stmt::Return const * stmt )override
			{
				TraceFunc;

				if ( auto expr = stmt->getExpr() )
				{
					declareStruct( expr->getType() );
				}

				StmtCloner::visitReturnStmt( stmt );
			}

			void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
				StmtCloner::visitShaderBufferDeclStmt( stmt );
			}

			void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getSsboInstance()->getType() );
				declareStruct( stmt->getData()->getType() );
				StmtCloner::visitShaderStructBufferDeclStmt( stmt );
			}

			void visitStructureDeclStmt( stmt::StructureDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getType() );
			}

			void visitVariableDeclStmt( stmt::VariableDecl const * stmt )override
			{
				TraceFunc;
				declareStruct( stmt->getVariable()->getType() );
				StmtCloner::visitVariableDeclStmt( stmt );
			}

		private:
			void doAddStmt( stmt::StmtPtr stmt )
			{
				TraceFunc;
				if ( stmt->getKind() == stmt::Kind::eSimple )
				{
					auto expr = static_cast< stmt::Simple const & >( *stmt ).getExpr();

					if ( expr->getKind() == expr::Kind::eIdentifier )
					{
						return;
					}
				}

				m_current->addStmt( std::move( stmt ) );
			}

		private:
			SSAData & m_data;
			bool m_normaliseStructs;
			ast::UnorderedStringSet m_declaredStructs;
			stmt::Container * m_typeDeclarations;
			type::TypesCache & m_typesCache;
			stmt::FragmentLayout const * m_fragmentLayoutStmt{};
			stmt::OutputGeometryLayout const * m_outputGeometryLayoutStmt{};
			stmt::InputGeometryLayout const * m_inputGeometryLayoutStmt{};
			stmt::OutputTessellationControlLayout const * m_outputTessCtrlLayoutStmt{};
			stmt::InputTessellationEvaluationLayout const * m_intputTessEvalLayoutStmt{};
			Map< uint32_t, var::VariablePtr > m_funcVarReplacements;
		};

		void declareStruct( type::StructPtr structType
			, StmtSSAiser & stmtVisitor )
		{
			stmtVisitor.declareStruct( structType );
		}
	}

	stmt::ContainerPtr transformSSA( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container const & container
		, SSAData & ssaData
		, bool normaliseStructs )
	{
		return ssa::StmtSSAiser::submit( container, stmtCache, exprCache, typesCache, ssaData, normaliseStructs );
	}
}
