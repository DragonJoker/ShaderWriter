#include "Common.hpp"

#include <ShaderAST/Expr/GetIntrinsicName.hpp>
#include <ShaderAST/Expr/GetCombinedImageAccessName.hpp>
#include <ShaderAST/Expr/GetStorageImageAccessName.hpp>
#include <ShaderAST/Expr/ExprBinary.hpp>
#include <ShaderAST/Expr/ExprUnary.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>
#include <ShaderAST/Visitors/GetOutermostExpr.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

#pragma warning( disable:4146 )

namespace checks
{
	using namespace ast;

	static std::string getExprName( expr::Expr const & expr )
	{
		return toString( expr.getKind() );
	}

	static expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		result.push_back( std::move( arg1 ) );
		return result;
	}

	static bool isBinary( expr::Expr const & expr )
	{
		return expr.getKind() == expr::Kind::eAdd
			|| expr.getKind() == expr::Kind::eAlias
			|| expr.getKind() == expr::Kind::eArrayAccess
			|| expr.getKind() == expr::Kind::eAssign
			|| expr.getKind() == expr::Kind::eBitAnd
			|| expr.getKind() == expr::Kind::eBitOr
			|| expr.getKind() == expr::Kind::eBitXor
			|| expr.getKind() == expr::Kind::eComma
			|| expr.getKind() == expr::Kind::eDivide
			|| expr.getKind() == expr::Kind::eEqual
			|| expr.getKind() == expr::Kind::eGreater
			|| expr.getKind() == expr::Kind::eGreaterEqual
			|| expr.getKind() == expr::Kind::eLess
			|| expr.getKind() == expr::Kind::eLessEqual
			|| expr.getKind() == expr::Kind::eLogAnd
			|| expr.getKind() == expr::Kind::eLogOr
			|| expr.getKind() == expr::Kind::eLShift
			|| expr.getKind() == expr::Kind::eMinus
			|| expr.getKind() == expr::Kind::eModulo
			|| expr.getKind() == expr::Kind::eNotEqual
			|| expr.getKind() == expr::Kind::eRShift
			|| expr.getKind() == expr::Kind::eTimes
			|| expr.getKind() == expr::Kind::eAddAssign
			|| expr.getKind() == expr::Kind::eMinusAssign
			|| expr.getKind() == expr::Kind::eTimesAssign
			|| expr.getKind() == expr::Kind::eDivideAssign
			|| expr.getKind() == expr::Kind::eModuloAssign
			|| expr.getKind() == expr::Kind::eLShiftAssign
			|| expr.getKind() == expr::Kind::eRShiftAssign
			|| expr.getKind() == expr::Kind::eAndAssign
			|| expr.getKind() == expr::Kind::eOrAssign
			|| expr.getKind() == expr::Kind::eXorAssign;
	}

	static bool isUnary( expr::Expr const & expr )
	{
		return expr.getKind() == expr::Kind::eBitNot
			|| expr.getKind() == expr::Kind::eCast
			|| expr.getKind() == expr::Kind::eCopy
			|| expr.getKind() == expr::Kind::eLogNot
			|| expr.getKind() == expr::Kind::ePreIncrement
			|| expr.getKind() == expr::Kind::ePreDecrement
			|| expr.getKind() == expr::Kind::ePostIncrement
			|| expr.getKind() == expr::Kind::ePostDecrement
			|| expr.getKind() == expr::Kind::eStreamAppend
			|| expr.getKind() == expr::Kind::eUnaryMinus
			|| expr.getKind() == expr::Kind::eUnaryPlus;
	}

	static bool isPostSsaValid( expr::Expr const & expr )
	{
		return expr.getKind() != expr::Kind::eInit
			&& expr.getKind() != expr::Kind::ePreIncrement
			&& expr.getKind() != expr::Kind::ePreDecrement
			&& expr.getKind() != expr::Kind::ePostIncrement
			&& expr.getKind() != expr::Kind::ePostDecrement
			&& expr.getKind() != expr::Kind::eAddAssign
			&& expr.getKind() != expr::Kind::eMinusAssign
			&& expr.getKind() != expr::Kind::eTimesAssign
			&& expr.getKind() != expr::Kind::eDivideAssign
			&& expr.getKind() != expr::Kind::eModuloAssign
			&& expr.getKind() != expr::Kind::eLShiftAssign
			&& expr.getKind() != expr::Kind::eRShiftAssign
			&& expr.getKind() != expr::Kind::eAndAssign
			&& expr.getKind() != expr::Kind::eOrAssign
			&& expr.getKind() != expr::Kind::eXorAssign;
	}

	static stmt::ContainerPtr makeContainer( stmt::StmtCache & stmtCache
		, expr::Expr const & expr )
	{
		auto container = stmtCache.makeContainer();
		container->addStmt( stmtCache.makeSimple( expr.clone() ) );
		return container;
	}

	static void checkExprDependant( test::TestCounts & testCounts
		, expr::Expr const & expr
		, std::string const & function
		, int line )
	{
		auto & exprCache = expr.getExprCache();
		auto & typesCache = expr.getTypesCache();

		if ( astOn( debug::displayExpression( expr ) ) )
		{
			if ( isPostSsaValid( expr ) )
			{
				astSubCheckNoThrow( function, line, resolveConstants( exprCache, expr ) )
			}
			else
			{
				astSubCheckThrow( function, line, resolveConstants( exprCache, expr ) )
			}

			auto clone = expr.clone();
			clone->updateFlag( expr::Flag::eNonUniform );

			if ( isUnary( *clone ) )
			{
				if ( auto operand = static_cast< expr::Unary & >( *clone ).getOperand() )
				{
					const_cast< expr::Expr * >( operand )->updateFlag( expr::Flag::eNonUniform );
				}
			}
			else if ( isBinary( *clone ) )
			{
				auto & binary = static_cast< expr::Binary & >( *clone );

				if ( auto lhs = binary.getLHS() )
				{
					const_cast< expr::Expr * >( lhs )->updateFlag( expr::Flag::eNonUniform );
				}
				if ( auto rhs = binary.getRHS() )
				{
					const_cast< expr::Expr * >( rhs )->updateFlag( expr::Flag::eNonUniform );
				}
			}

			astSubCheckNoThrow( function, line, debug::displayExpression( *clone ) )

			if ( isPostSsaValid( expr ) )
			{
				astSubCheckNoThrow( function, line, resolveConstants( exprCache, *clone ) )
			}
			else
			{
				astSubCheckThrow( function, line, resolveConstants( exprCache, *clone ) )
			}

			if ( expr.getKind() == expr::Kind::eSwitchCase )
			{
				astSubCheckThrow( function, line, getOutermostExpr( expr ) )
				astSubCheckThrow( function, line, getOutermostExpr( *clone ) )
			}
			else
			{
				astSubCheckNoThrow( function, line, getOutermostExpr( expr ) )
				astSubCheckNoThrow( function, line, getOutermostExpr( *clone ) )
			}

			astSubCheckNoThrow( function, line, listCommaIdentifiers( expr ) )
			astSubCheckNoThrow( function, line, listIdentifiers( expr ) )
			astSubCheckNoThrow( function, line, listIdentifiers( expr, type::Kind::eInt32 ) )
			astSubCheckNoThrow( function, line, listIdentifiers( expr, type::Kind::eUndefined, var::Flag::eAlias ) )
			astSubCheckNoThrow( function, line, listIdentifiers( expr, type::Kind::eInt32, var::Flag::eAlias ) )
			astSubCheckNoThrow( function, line, findIdentifier( expr ) )
			astSubCheckNoThrow( function, line, findIdentifier( expr, type::Kind::eInt32 ) )
			astSubCheckNoThrow( function, line, findIdentifier( expr, type::Kind::eUndefined, var::Flag::eAlias ) )
			astSubCheckNoThrow( function, line, findIdentifier( expr, type::Kind::eInt32, var::Flag::eAlias ) )
			astSubCheckNoThrow( function, line, findName( expr ) )
			astSubCheckNoThrow( function, line, findName( expr, type::Kind::eInt32 ) )
			astSubCheckNoThrow( function, line, findName( expr, type::Kind::eUndefined, var::Flag::eAlias ) )
			astSubCheckNoThrow( function, line, findName( expr, type::Kind::eInt32, var::Flag::eAlias ) )

			if ( expr.getKind() != expr::Kind::eAlias )
			{
				stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
				if ( astWhen( "SSA transform expr without normalised structs" ) )
				{
					SSAData data{ testCounts.nextVarId, 0u };
					auto container = makeContainer( stmtCache, expr );
					astSubCheckNoThrow( function, line, container = transformSSA( stmtCache, exprCache, typesCache, *container, data, false ) )
					astSubCheckNoThrow( function, line, container = resolveConstants( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = simplify( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) )
				}
				if ( astWhen( "SSA transform expr with normalised structs" ) )
				{
					SSAData data{ testCounts.nextVarId, 0u };
					auto container = makeContainer( stmtCache, expr );
					astSubCheckNoThrow( function, line, container = transformSSA( stmtCache, exprCache, typesCache, *container, data, true ) )
					astSubCheckNoThrow( function, line, container = resolveConstants( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = simplify( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) )
				}
				if ( astWhen( "SSA transform clone without normalised structs" ) )
				{
					SSAData data{ testCounts.nextVarId, 0u };
					auto container = makeContainer( stmtCache, *clone );
					astSubCheckNoThrow( function, line, container = transformSSA( stmtCache, exprCache, typesCache, *container, data, false ) )
					astSubCheckNoThrow( function, line, container = resolveConstants( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = simplify( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) )
				}
				if ( astWhen( "SSA transform clone with normalised structs" ) )
				{
					SSAData data{ testCounts.nextVarId, 0u };
					auto container = makeContainer( stmtCache, *clone );
					astSubCheckNoThrow( function, line, container = transformSSA( stmtCache, exprCache, typesCache, *container, data, true ) )
					astSubCheckNoThrow( function, line, container = resolveConstants( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = simplify( stmtCache, exprCache, typesCache, *container ) )
					astSubCheckNoThrow( function, line, container = specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) )
				}
			}
			if ( astOn( "SimpleVisitor check" ) )
			{
				struct Visitor
					: public expr::SimpleVisitor
				{
					void visitUnaryExpr( expr::Unary const * expr )override
					{
						if ( auto operand = expr->getOperand() )
						{
							operand->accept( this );
						}
					}
					void visitBinaryExpr( expr::Binary const * expr )override
					{
						if ( auto lhs = expr->getLHS() )
						{
							lhs->accept( this );
						}
						if ( auto rhs = expr->getRHS() )
						{
							rhs->accept( this );
						}
					}
					void visitAggrInitExpr( expr::AggrInit const * expr )override
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
					void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}
					void visitFnCallExpr( expr::FnCall const * expr )override
					{
						if ( auto ident = expr->getFn() )
						{
							ident->accept( this );
						}
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}
					void visitIdentifierExpr( expr::Identifier const * expr )override
					{
					}
					void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}
					void visitInitExpr( expr::Init const * expr )override
					{
						if ( expr->hasIdentifier() )
						{
							expr->getIdentifier().accept( this );
						}
						if ( auto init = expr->getInitialiser() )
						{
							init->accept( this );
						}
					}
					void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}
					void visitLiteralExpr( expr::Literal const * expr )override
					{
					}
					void visitMbrSelectExpr( expr::MbrSelect const * expr )override
					{
						if ( auto outer = expr->getOuterExpr() )
						{
							outer->accept( this );
						}
					}
					void visitQuestionExpr( expr::Question const * expr )override
					{
						if ( auto ctrl = expr->getCtrlExpr() )
						{
							ctrl->accept( this );
						}
						if ( auto inner = expr->getTrueExpr() )
						{
							inner->accept( this );
						}
						if ( auto inner = expr->getFalseExpr() )
						{
							inner->accept( this );
						}
					}
					void visitStreamAppendExpr( expr::StreamAppend const * expr )override
					{
						visitUnaryExpr( expr );
					}
					void visitSwitchCaseExpr( expr::SwitchCase const * expr )override
					{
						if ( auto label = expr->getLabel() )
						{
							label->accept( this );
						}
					}
					void visitSwitchTestExpr( expr::SwitchTest const * expr )override
					{
						if ( auto value = expr->getValue() )
						{
							value->accept( this );
						}
					}
					void visitSwizzleExpr( expr::Swizzle const * expr )override
					{
						if ( auto outer = expr->getOuterExpr() )
						{
							outer->accept( this );
						}
					}
					void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}
				};
				Visitor vis;
				astSubCheckNoThrow( function, line, expr.accept( &vis ) )
			}
		}
	}

	template< expr::LiteralType LiteralT
		, expr::LiteralType LiteralU
		, typename ValueT >
	static void testLiteral( test::TestCounts & testCounts
		, expr::Literal const & expr
		, ValueT value
		, char const * const function
		, int line )
	{
		static type::Kind constexpr TypeT = expr::literalValueKind< LiteralT >;
		static type::Kind constexpr TypeU = expr::literalValueKind< LiteralU >;
		using ValueU = expr::LiteralValueType< LiteralU >;

		astSubRequire( function, line, expr.getKind() == expr::Kind::eLiteral )
		astSubCheckEqual( function, line, expr.getType()->getKind(), TypeT )
		astSubCheckEqual( function, line, expr.getLiteralType(), LiteralT )
		astSubCheckEqual( function, line, getLiteralValue< LiteralT >( expr ), value )
		astSubCheckEqual( function, line, expr.getValue< LiteralT >(), value )
		checkExprDependant( testCounts, expr, function, line );
		if ( astOn( "Basic conversions" ) )
		{
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eBool >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eInt8 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eInt16 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eInt32 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eInt64 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eUInt8 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eUInt16 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eUInt32 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eUInt64 >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eFloat >( getLiteralValue< LiteralT >( expr ) ) )
			astSubCheckNoThrow( function, line, expr::details::convert< expr::LiteralType::eDouble >( getLiteralValue< LiteralT >( expr ) ) )
		}
		if ( astOn( "Construction from other literal" ) )
		{
			expr::Literal result{ expr.getExprCache(), expr };
			astSubRequire( function, line, result.getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result.getType()->getKind(), TypeT )
			astSubCheckEqual( function, line, result.getLiteralType(), LiteralT )
			astSubCheckEqual( function, line, result.getValue< LiteralT >(), value )
			astSubCheckEqual( function, line, getLiteralValue< LiteralT >( result ), value )
		}
		if ( astOn( "Cast to other literal type" ) )
		{
			auto result = expr.castTo( LiteralU );
			astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result->getType()->getKind(), TypeU )
			astSubCheckEqual( function, line, result->getLiteralType(), LiteralU )
			astSubCheckEqual( function, line, result->getValue< LiteralU >(), ValueU( value ) )
			astSubCheckEqual( function, line, getLiteralValue< LiteralU >( *result ), ValueU( value ) )
		}
		if ( astOn( "Logical not" ) )
		{
			auto result = !expr;
			astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
			astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
			astSubCheckEqual( function, line, result->getValue< expr::LiteralType::eBool >(), false )
			astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), false )
		}
		if ( astOn( "Pre increment" ) )
		{
			auto result = preInc( expr );
			astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
			astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
			astSubCheckEqual( function, line, result->getValue< LiteralT >(), ValueT( value + 1 ) )
			astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value + 1 ) )
		}
		if ( astOn( "Post increment" ) )
		{
			auto result = preDec( expr );
			astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
			astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
			astSubCheckEqual( function, line, result->getValue< LiteralT >(), ValueT( value - 1 ) )
			astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value - 1 ) )
		}
		if ( auto prhs = expr.getExprCache().makeLiteral( expr.getTypesCache(), value ) )
		{
			auto & rhs = *prhs;
			if ( astOn( "Addition" ) )
			{
				auto result = expr + rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), value + value )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), value + value )
			}
			if ( astOn( "Subtraction" ) )
			{
				auto result = expr - rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT{} )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT{} )
			}
			if ( astOn( "Multiplication" ) )
			{
				auto result = expr * rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), value * value )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), value * value )
			}
			if ( astOn( "Division" ) )
			{
				auto result = expr / rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT{ 1 } )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT{ 1 } )
			}
			if ( astOn( "Less than" ) )
			{
				auto result = expr < rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), false )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), false )
			}
			if ( astOn( "Greater than" ) )
			{
				auto result = expr > rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), false )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), false )
			}
			if ( astOn( "Less than or equal to" ) )
			{
				auto result = expr <= rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), true )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), true )
			}
			if ( astOn( "Greater than or equal to" ) )
			{
				auto result = expr >= rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), true )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), true )
			}
			if ( astOn( "Equal to" ) )
			{
				auto result = expr == rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), true )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), true )
			}
			if ( astOn( "Different from" ) )
			{
				auto result = expr != rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), false )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), false )
			}
			if ( astOn( "Logical and" ) )
			{
				auto result = expr && rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), true )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), true )
			}
			if ( astOn( "Logical or" ) )
			{
				auto result = expr || rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), type::Kind::eBoolean )
				astSubCheckEqual( function, line, result->getLiteralType(), expr::LiteralType::eBool )
				astSubCheckEqual( function, line, result->template getValue< expr::LiteralType::eBool >(), true )
				astSubCheckEqual( function, line, getLiteralValue< expr::LiteralType::eBool >( *result ), true )
			}
		}
	}

	template< expr::LiteralType LiteralT
		, expr::LiteralType LiteralU
		, typename ValueT >
	static void testExprIntegerLiteral( test::TestCounts & testCounts
		, expr::Literal const & expr
		, ValueT value
		, char const * const function
		, int line )
	{
		static type::Kind constexpr TypeT = expr::literalValueKind< LiteralT >;

		testLiteral< LiteralT, LiteralU >( testCounts, expr, value, function, line );
		if ( astOn( "Binary not" ) )
		{
			auto result = ~expr;
			astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
			astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
			astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( ~value ) )
			astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( ~value ) )
		}
		if ( auto prhs = expr.getExprCache().makeLiteral( expr.getTypesCache(), ValueT{ 1 } ) )
		{
			auto & rhs = *prhs;
			if ( astOn( "Left shift" ) )
			{
				auto result = expr << rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value << 1 ) )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value << 1 ) )
			}
			if ( astOn( "Right shift" ) )
			{
				auto result = expr >> rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value >> 1 ) )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value >> 1 ) )
			}
		}
		if ( auto prhs = expr.getExprCache().makeLiteral( expr.getTypesCache(), value ) )
		{
			auto & rhs = *prhs;
			if ( astOn( "Modulo" ) )
			{
				auto result = expr % rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT{} )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT{} )
			}
			if ( astOn( "Binary or" ) )
			{
				auto result = expr | rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), value )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), value )
			}
			if ( astOn( "Binary xor" ) )
			{
				auto result = expr ^ rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value ^ value ) )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value ^ value ) )
			}
			if ( astOn( "Binary and" ) )
			{
				auto result = expr & rhs;
				astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
				astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
				astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
				astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value & value ) )
				astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value & value ) )
			}
		}
	}

	template< expr::LiteralType LiteralT
		, expr::LiteralType LiteralU >
	static void testExprFloatLiteral( test::TestCounts & testCounts
		, char const * const function
		, int line )
	{
		static type::Kind constexpr TypeT = expr::literalValueKind< LiteralT >;
		using ValueT = expr::LiteralValueType< LiteralT >;

		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto expr = exprCache.makeLiteral( typesCache, ValueT{ 10.0 } );
		testLiteral< LiteralT, LiteralU >( testCounts, *expr, ValueT{ 10.0 }, function, line );
		if ( astOn( "Unary minus" ) )
		{
			auto result = -( *expr );
			astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
			astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
			astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( -10.0 ) )
			astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( -10.0 ) )
		}
		if ( auto prhs = exprCache.makeLiteral( typesCache, ValueT( 1.0 ) ) )
		{
			auto & rhs = *prhs;
			astSubCheckThrow( function, line, ( *expr ) << rhs )
			astSubCheckThrow( function, line, ( *expr ) >> rhs )
		}
		if ( auto prhs = exprCache.makeLiteral( typesCache, ValueT{ 10.0 } ) )
		{
			auto & rhs = *prhs;
			astSubCheckThrow( function, line, ( *expr ) % rhs )
			astSubCheckThrow( function, line, ( *expr ) | rhs )
			astSubCheckThrow( function, line, ( *expr ) ^ rhs )
			astSubCheckThrow( function, line, ( *expr ) & rhs )
		}
		astSubCheckThrow( function, line, ~( *expr ) )
	}

	template< expr::LiteralType LiteralT
		, expr::LiteralType LiteralU >
	static void testExprSignedIntegerLiteral( test::TestCounts & testCounts
		, char const * const function
		, int line )
	{
		static type::Kind constexpr TypeT = expr::literalValueKind< LiteralT >;
		using ValueT = expr::LiteralValueType< LiteralT >;

		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto expr = exprCache.makeLiteral( typesCache, ValueT{ 10LL } );
		testExprIntegerLiteral< LiteralT, LiteralU >( testCounts, *expr, ValueT{ 10LL }, function, line );
		if ( astOn( "Unary minus" ) )
		{
			auto result = -( *expr );
			astSubRequire( function, line, result->getKind() == expr::Kind::eLiteral )
			astSubCheckEqual( function, line, result->getType()->getKind(), TypeT )
			astSubCheckEqual( function, line, result->getLiteralType(), LiteralT )
			astSubCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( -10LL ) )
			astSubCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( -10LL ) )
		}
	}

	template< expr::LiteralType LiteralT
		, expr::LiteralType LiteralU >
	static void testExprUnsignedIntegerLiteral( test::TestCounts & testCounts
		, char const * const function
		, int line )
	{
		using ValueT = expr::LiteralValueType< LiteralT >;

		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto expr = exprCache.makeLiteral( typesCache, ValueT{ 10ULL } );
		testExprIntegerLiteral< LiteralT, LiteralU >( testCounts, *expr, ValueT{ 10ULL }, function, line );
		astSubCheckThrow( function, line, -( *expr ) )
	}

	static void testExprLiteral( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLiteral" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pexpr = exprCache.makeLiteral( typesCache, false );

		if ( astOn( debug::displayExpression( *pexpr ) ) )
		{
			auto expr = pexpr.get();
			astRequire( expr->getKind() == expr::Kind::eLiteral )
			astCheckEqual( expr->getType()->getKind(), type::Kind::eBoolean )
			astCheckEqual( expr->getLiteralType(), expr::LiteralType::eBool )
			astCheckEqual( expr->getValue< expr::LiteralType::eBool >(), false )
			astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *expr ), false )
			checkExprDependant( testCounts, *expr, "testExprLiteral", __LINE__ );
			if ( astOn( "Basic conversions" ) )
			{
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eBool >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eInt8 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eInt16 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eInt32 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eInt64 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eUInt8 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eUInt16 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eUInt32 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eUInt64 >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eFloat >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
				astCheckNoThrow( expr::details::convert< expr::LiteralType::eDouble >( getLiteralValue< expr::LiteralType::eBool >( *expr ) ) )
			}
			if ( astOn( "Cast to unsigned type" ) )
			{
				auto result = expr->castTo( expr::LiteralType::eUInt8 );
				astRequire( result->getKind() == expr::Kind::eLiteral )
				astCheckEqual( result->getType()->getKind(), type::Kind::eUInt8 )
				astCheckEqual( result->getLiteralType(), expr::LiteralType::eUInt8 )
				astCheckEqual( result->getValue< expr::LiteralType::eUInt8 >(), uint8_t{} )
				astCheckEqual( getLiteralValue< expr::LiteralType::eUInt8 >( *result ), uint8_t{} )

				result = result->castTo( expr::LiteralType::eBool );
				astRequire( result->getKind() == expr::Kind::eLiteral )
				astCheckEqual( result->getType()->getKind(), type::Kind::eBoolean )
				astCheckEqual( result->getLiteralType(), expr::LiteralType::eBool )
				astCheckEqual( result->getValue< expr::LiteralType::eBool >(), false )
				astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *result ), false )
			}
			if ( astOn( "Binary not" ) )
			{
				auto result = ~( *expr );
				astRequire( result->getKind() == expr::Kind::eLiteral )
				astCheckEqual( result->getType()->getKind(), type::Kind::eBoolean )
				astCheckEqual( result->getLiteralType(), expr::LiteralType::eBool )
				astCheckEqual( result->getValue< expr::LiteralType::eBool >(), true )
				astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *result ), true )
			}
			if ( astOn( "Logical not" ) )
			{
				auto result = !( *expr );
				astRequire( result->getKind() == expr::Kind::eLiteral )
				astCheckEqual( result->getType()->getKind(), type::Kind::eBoolean )
				astCheckEqual( result->getLiteralType(), expr::LiteralType::eBool )
				astCheckEqual( result->getValue< expr::LiteralType::eBool >(), true )
				astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *result ), true )
			}
			if ( auto prhs = exprCache.makeLiteral( typesCache, true ) )
			{
				auto & rhs = *prhs;
				astCheckThrow( ( *expr ) << rhs )
				astCheckThrow( ( *expr ) >> rhs )
			}
			if ( auto prhs = exprCache.makeLiteral( typesCache, false ) )
			{
				auto & rhs = *prhs;
				if ( astOn( "Equal to" ) )
				{
					auto result = ( *expr ) == rhs;
					astRequire( result->getKind() == expr::Kind::eLiteral )
					astCheckEqual( result->getType()->getKind(), type::Kind::eBoolean )
					astCheckEqual( result->getLiteralType(), expr::LiteralType::eBool )
					astCheckEqual( result->getValue< expr::LiteralType::eBool >(), true )
					astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *result ), true )
				}
				if ( astOn( "Different from" ) )
				{
					auto result = ( *expr ) != rhs;
					astRequire( result->getKind() == expr::Kind::eLiteral )
					astCheckEqual( result->getType()->getKind(), type::Kind::eBoolean )
					astCheckEqual( result->getLiteralType(), expr::LiteralType::eBool )
					astCheckEqual( result->getValue< expr::LiteralType::eBool >(), false )
					astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *result ), false )
				}
				if ( astOn( "Logical and" ) )
				{
					auto result = ( *expr ) && rhs;
					astRequire( result->getKind() == expr::Kind::eLiteral )
					astCheckEqual( result->getType()->getKind(), type::Kind::eBoolean )
					astCheckEqual( result->getLiteralType(), expr::LiteralType::eBool )
					astCheckEqual( result->getValue< expr::LiteralType::eBool >(), false )
					astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *result ), false )
				}
				if ( astOn( "Logical or" ) )
				{
					auto result = ( *expr ) || rhs;
					astRequire( result->getKind() == expr::Kind::eLiteral )
					astCheckEqual( result->getType()->getKind(), type::Kind::eBoolean )
					astCheckEqual( result->getLiteralType(), expr::LiteralType::eBool )
					astCheckEqual( result->getValue< expr::LiteralType::eBool >(), false )
					astCheckEqual( getLiteralValue< expr::LiteralType::eBool >( *result ), false )
				}
				astCheckThrow( ( *expr ) + rhs )
				astCheckThrow( ( *expr ) - rhs )
				astCheckThrow( ( *expr ) * rhs )
				astCheckThrow( ( *expr ) / rhs )
				astCheckThrow( ( *expr ) % rhs )
			}
			astCheckThrow( -( *expr ) )
			astCheckThrow( preDec( *expr ) )
			astCheckThrow( preInc( *expr ) )
		}
		if ( astOn( "Initialisation from signed long" ) )
		{
			auto expr = exprCache.makeLiteral( typesCache, 1L );
			checkExprDependant( testCounts, *expr, "testExprLiteral", __LINE__ );
		}
		if ( astOn( "Initialisation from signed int" ) )
		{
			auto expr = exprCache.makeLiteral( typesCache, int( 1 ) );
			checkExprDependant( testCounts, *expr, "testExprLiteral", __LINE__ );
		}
		if ( astOn( "Initialisation from unsigned long" ) )
		{
			auto expr = exprCache.makeLiteral( typesCache, 1UL );
			checkExprDependant( testCounts, *expr, "testExprLiteral", __LINE__ );
		}
		if ( astOn( "Initialisation from unsigned int" ) )
		{
			auto expr = exprCache.makeLiteral( typesCache, unsigned( 1 ) );
			checkExprDependant( testCounts, *expr, "testExprLiteral", __LINE__ );
		}
		testExprFloatLiteral< expr::LiteralType::eFloat, expr::LiteralType::eDouble >( testCounts, "testExprLiteral", __LINE__ );
		testExprFloatLiteral< expr::LiteralType::eDouble, expr::LiteralType::eFloat >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< expr::LiteralType::eInt8, expr::LiteralType::eUInt8 >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< expr::LiteralType::eInt16, expr::LiteralType::eUInt16 >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< expr::LiteralType::eInt32, expr::LiteralType::eUInt32 >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< expr::LiteralType::eInt64, expr::LiteralType::eUInt64 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< expr::LiteralType::eUInt8, expr::LiteralType::eInt8 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< expr::LiteralType::eUInt16, expr::LiteralType::eInt16 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< expr::LiteralType::eUInt32, expr::LiteralType::eInt32 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< expr::LiteralType::eUInt64, expr::LiteralType::eInt64 >( testCounts, "testExprLiteral", __LINE__ );
		astTestEnd()
	}
	
	static void testExprIdentifier( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprIdentifier" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto expr = exprCache.makeIdentifier( typesCache
				, var::makeVariable( testCounts.getNextVarId()
					, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var0" )
					, typesCache.getInt32()
					, "var1" ) );

			astRequire( expr->getKind() == expr::Kind::eIdentifier )
			astRequire( expr->getFlags() == 0u )
			astCheck( !expr->isDummy() )
			expr->updateFlag( expr::Flag::eDummy );
			astCheck( expr->isDummy() )
			astCheckNoThrow( expr->clone() )
			expr->updateFlag( expr::Flag::eDummy, false );
			astCheck( !expr->isDummy() )
			astCheck( !expr->isSpecialisationConstant() )
			expr->updateFlag( expr::Flag::eSpecialisationConstant );
			astCheck( expr->isSpecialisationConstant() )
			astCheck( !expr->isConstant() )
			expr->updateFlag( expr::Flag::eConstant );
			astCheck( expr->isConstant() )
			astCheck( !expr->isImplicit() )
			expr->updateFlag( expr::Flag::eImplicit );
			astCheck( expr->isImplicit() )
			astCheck( !expr->isNonUniform() )
			expr->updateFlag( expr::Flag::eNonUniform );
			astCheck( expr->isNonUniform() )
			expr->updateFlag( expr::Flag::eNonUniform, false );
			astCheck( !expr->isNonUniform() )
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 )
			astCheck( expr->getVariable()->getName() == "var1" )
			astCheck( expr->getVariable()->getType()->getKind() == type::Kind::eInt32 )
			checkExprDependant( testCounts, *expr, "testExprIdentifier", __LINE__ );
			astCheckThrow( getLiteralValue< expr::LiteralType::eInt32 >( *expr ) )
		}
		if ( astOn( "Expression flags checks" ) )
		{
			uint32_t flags{};
			flags = flags | expr::Flag::eDummy;
			astCheck( ( flags & uint32_t( expr::Flag::eDummy ) ) == uint32_t( expr::Flag::eDummy ) )
			flags = expr::Flag::eConstant | flags;
			astCheck( ( flags & uint32_t( expr::Flag::eConstant ) ) == uint32_t( expr::Flag::eConstant ) )
			flags = expr::Flag::eSpecialisationConstant | expr::Flag::eImplicit;
			astCheck( ( flags & uint32_t( expr::Flag::eSpecialisationConstant ) ) == uint32_t( expr::Flag::eSpecialisationConstant ) )
			astCheck( ( flags & uint32_t( expr::Flag::eImplicit ) ) == uint32_t( expr::Flag::eImplicit ) )
		}
		if ( astOn( "Dummy expr cheks" ) )
		{
			expr::Expr dummy{ exprCache, 0u, typesCache, typesCache.getVoid(), expr::Kind::eAlias };
			dummy.accept( nullptr );
		}
		astTestEnd()
	}

	static void testExprAdd( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprAdd" );
		{
			Vector< uint32_t > a{ StlAllocatorT< uint32_t >{ testCounts.allocatorBlock.get() } };
			auto lhs = a.get_allocator();
			Vector< uint32_t > b{ StlAllocatorT< uint32_t >{ testCounts.allocatorBlock.get() } };
			auto rhs = b.get_allocator();
			astCheck( lhs == rhs );
			astCheck( !( lhs != rhs ) );
			astCheck( lhs.getAllocator() == rhs.getAllocator() );
		}
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeAdd( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eAdd );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprAdd", __LINE__ );
			auto subExpr = exprCache.makeAdd( typesCache.getInt32(), expr->clone(), exprCache.makeLiteral( typesCache, 10 ) );
			checkExprDependant( testCounts, *subExpr, "testExprAdd", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20 );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeAdd( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprAdd", __LINE__ );
		}
		{
			auto lhs = exprCache.makeAggrInit( typesCache.getVec2I32()
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) );
			auto rhs = exprCache.makeAggrInit( typesCache.getVec2I32()
				, makeList( exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) );
			auto expr = exprCache.makeAdd( typesCache.getVec2I32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eAdd );
			astCheck( expr->getType()->getKind() == type::Kind::eVec2I32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eAggrInit );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eVec2I32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eAggrInit );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eVec2I32 );
			checkExprDependant( testCounts, *expr, "testExprAdd", __LINE__ );
		}
		{
			auto lhs = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt32
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) );
			auto rhs = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt32
				, makeList( exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) );
			auto expr = exprCache.makeAdd( typesCache.getVec2I32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eAdd );
			astCheck( expr->getType()->getKind() == type::Kind::eVec2I32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eCompositeConstruct );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eVec2I32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eCompositeConstruct );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eVec2I32 );
			checkExprDependant( testCounts, *expr, "testExprAdd", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprMinus( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprMinus" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeMinus( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eMinus );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprMinus", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20 );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeMinus( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprMinus", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprTimes( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprTimes" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeTimes( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eTimes );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20 );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeTimes( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprDivide( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprTimes" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeDivide( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eDivide );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20 );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeDivide( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprBitAnd( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprBitAnd" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeBitAnd( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eBitAnd );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprBitAnd", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeBitAnd( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprBitAnd", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprBitNot( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprBitNot" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
			auto expr = exprCache.makeBitNot( std::move( op ) );

			astCheck( expr->getKind() == expr::Kind::eBitNot );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprBitNot", __LINE__ );
		}
		{
			auto op = exprCache.makeLiteral( typesCache, 20u );
			auto expr = exprCache.makeBitNot( std::move( op ) );
			checkExprDependant( testCounts, *expr, "testExprBitNot", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprBitOr( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprBitOr" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeBitOr( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eBitOr );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprBitOr", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeBitOr( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprBitOr", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprBitXor( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprBitXor" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeBitXor( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eBitXor );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprBitXor", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeBitXor( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprBitXor", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprLogAnd( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLogAnd" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLogAnd( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eLogAnd );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLogAnd", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeLogAnd( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLogAnd", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprLogNot( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLogNot" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
			auto expr = exprCache.makeLogNot( typesCache, std::move( op ) );

			astCheck( expr->getKind() == expr::Kind::eLogNot );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprLogNot", __LINE__ );
		}
		{
			auto op = exprCache.makeLiteral( typesCache, 20u );
			auto expr = exprCache.makeLogNot( typesCache, std::move( op ) );
			checkExprDependant( testCounts, *expr, "testExprLogNot", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprLogOr( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLogOr" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLogOr( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eLogOr );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLogOr", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeLogOr( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLogOr", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprModulo( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprModulo" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeModulo( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eModulo );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprModulo", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeModulo( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprModulo", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprLShift( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLShift" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLShift( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eLShift );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLShift", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeLShift( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLShift", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprRShift( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprRShift" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeRShift( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eRShift );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprRShift", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeRShift( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprRShift", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprComma( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprComma" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeComma( std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eComma );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprComma", __LINE__ );

		astCheckThrow( exprCache.makeComma( nullptr, nullptr ) )
		rhs = exprCache.makeLiteral( typesCache, 10 );
		expr = exprCache.makeComma( nullptr, std::move( rhs ) );
		checkExprDependant( testCounts, *expr, "testExprComma", __LINE__ );
		lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		expr = exprCache.makeComma( std::move( lhs ), nullptr );
		checkExprDependant( testCounts, *expr, "testExprComma", __LINE__ );
		astTestEnd()
	}

	static void testExprArrayAccess( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprArrayAccess" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32() ), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeArrayAccess( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eArrayAccess )
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 )

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier )
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eArray )
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" )
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eArray )

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral )
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 )
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 )
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 )
			checkExprDependant( testCounts, *expr, "testExprArrayAccess", __LINE__ );
		}
		{
			auto lhs = exprCache.makeAggrInit( typesCache.getArray( typesCache.getInt32(), 2u )
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) );
			auto rhs = exprCache.makeLiteral( typesCache, 1 );
			auto expr = exprCache.makeArrayAccess( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eArrayAccess )
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 )

			astRequire( expr->getLHS()->getKind() == expr::Kind::eAggrInit )
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eArray )

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral )
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 )
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 )
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 1 )
			checkExprDependant( testCounts, *expr, "testExprArrayAccess", __LINE__ );
		}
		{
			auto lhs = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt32
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) );
			auto rhs = exprCache.makeLiteral( typesCache, 1 );
			auto expr = exprCache.makeArrayAccess( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eArrayAccess )
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 )

			astRequire( expr->getLHS()->getKind() == expr::Kind::eCompositeConstruct )
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eVec2I32 )

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral )
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 )
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 )
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 1 )
			checkExprDependant( testCounts, *expr, "testExprArrayAccess", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprAddAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprAddAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAddAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eAddAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprAddAssign", __LINE__ );
		astCheckThrow( exprCache.makeAddAssign( typesCache.getInt32(), nullptr, nullptr ) );
		astTestEnd()
	}

	static void testExprDivideAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprDivideAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeDivideAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eDivideAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprDivideAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprMinusAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprMinusAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeMinusAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eMinusAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprMinusAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprTimesAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprTimesAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeTimesAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eTimesAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprTimesAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprModuloAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprModuloAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeModuloAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eModuloAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprModuloAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprLShiftAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLShiftAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLShiftAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eLShiftAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprLShiftAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprRShiftAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprRShiftAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeRShiftAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eRShiftAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprRShiftAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprAndAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprAndAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAndAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eAndAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprAndAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprOrAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprOrAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeOrAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eOrAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprOrAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprXorAssign( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprXorAssign" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeXorAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		astCheck( expr->getKind() == expr::Kind::eXorAssign );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
		astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprXorAssign", __LINE__ );
		astTestEnd()
	}

	static void testExprEqual( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprEqual" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eEqual );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprEqual", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprGreater( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprGreater" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeGreater( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eGreater );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprGreater", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeGreater( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprGreater", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprGreaterEqual( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprGreaterEqual" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeGreaterEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eGreaterEqual );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprGreaterEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeGreaterEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprGreaterEqual", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprLess( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLess" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLess( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eLess );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLess", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeLess( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLess", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprLessEqual( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprLessEqual" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLessEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eLessEqual );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLessEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeLessEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLessEqual", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprNotEqual( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprNotEqual" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeNotEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eNotEqual );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprNotEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeNotEqual( typesCache.getBool(), std::move( lhs ), std::move( rhs ) );

			astCheck( expr->getKind() == expr::Kind::eNotEqual );
			astCheck( expr->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getLHS()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getLHS()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getRHS()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getRHS()->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getRHS() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getRHS() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprNotEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeNotEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprNotEqual", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprPostDecrement( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprPostDecrement" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePostDecrement( std::move( op ) );

		astCheck( expr->getKind() == expr::Kind::ePostDecrement );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPostDecrement", __LINE__ );
		astTestEnd()
	}

	static void testExprPostIncrement( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprPostIncrement" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePostIncrement( std::move( op ) );

		astCheck( expr->getKind() == expr::Kind::ePostIncrement );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPostIncrement", __LINE__ );
		astTestEnd()
	}

	static void testExprPreDecrement( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprPreDecrement" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePreDecrement( std::move( op ) );

		astCheck( expr->getKind() == expr::Kind::ePreDecrement );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPreDecrement", __LINE__ );
		astTestEnd()
	}

	static void testExprPreIncrement( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprPreIncrement" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePreIncrement( std::move( op ) );

		astCheck( expr->getKind() == expr::Kind::ePreIncrement );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPreIncrement", __LINE__ );
		astTestEnd()
	}

	static void testExprUnaryMinus( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprUnaryMinus" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
			auto expr = exprCache.makeUnaryMinus( std::move( op ) );

			astCheck( expr->getKind() == expr::Kind::eUnaryMinus );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprUnaryMinus", __LINE__ );
		}
		{
			auto expr = exprCache.makeUnaryMinus( exprCache.makeLiteral( typesCache, 10 ) );

			astCheck( expr->getKind() == expr::Kind::eUnaryMinus );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprUnaryMinus", __LINE__ );
		}
		astCheckThrow( expr::UnaryMinus( exprCache, typesCache.getInt32(), nullptr ) )
		astTestEnd()
	}

	static void testExprUnaryPlus( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprUnaryPlus" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
			auto expr = exprCache.makeUnaryPlus( std::move( op ) );

			astCheck( expr->getKind() == expr::Kind::eUnaryPlus );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprUnaryPlus", __LINE__ );
		}
		{
			auto expr = exprCache.makeUnaryPlus( exprCache.makeLiteral( typesCache, 10 ) );

			astCheck( expr->getKind() == expr::Kind::eUnaryPlus );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprUnaryMinus", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprCast( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprCast" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto op = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
			auto expr = exprCache.makeCast( typesCache.getFloat(), std::move( op ) );

			astCheck( expr->getKind() == expr::Kind::eCast );
			astCheck( expr->getType()->getKind() == type::Kind::eFloat );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprCast", __LINE__ );
		}
		{
			auto op = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeCast( typesCache.getFloat(), std::move( op ) );

			astCheck( expr->getKind() == expr::Kind::eCast );
			astCheck( expr->getType()->getKind() == type::Kind::eFloat );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getOperand() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getOperand() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprCast", __LINE__ );
		}
		{
			auto op = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeCast( typesCache.getHalf(), std::move( op ) );

			astCheck( expr->getKind() == expr::Kind::eCast );
			astCheck( expr->getType()->getKind() == type::Kind::eHalf );

			astRequire( expr->getOperand()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getOperand()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getOperand() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getOperand() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprCast", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprCompositeConstruct( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprCompositeConstruct" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		for ( uint32_t type = 0u; type < uint32_t( expr::CompositeType::eCombine ); ++type )
		{
			expr::ExprList args;
			args.emplace_back( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c1" ) ) );
			args.emplace_back( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c2" ) ) );
			args.emplace_back( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c2" ) ) );
			args.emplace_back( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c2" ) ) );
			auto expr = exprCache.makeCompositeConstruct( expr::CompositeType( type )
				, type::Kind::eFloat
				, std::move( args ) );

			astCheck( expr->getKind() == expr::Kind::eCompositeConstruct )
			astCheck( expr->getComposite() == expr::CompositeType( type ) )
			astCheck( expr->getComponent() == type::Kind::eFloat )

			astCheck( expr->getArgList().size() == 4u )
			checkExprDependant( testCounts, *expr, "testExprCompositeConstruct", __LINE__ );
		}
		{
			auto expr = exprCache.makeCompositeConstruct( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getSampledImage( type::ImageConfiguration{} ), "img" ) )
				, exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getSampler(), "spl" ) ) );

			astCheck( expr->getKind() == expr::Kind::eCompositeConstruct )
			astCheck( expr->getType()->getKind() == type::Kind::eCombinedImage )
			astCheck( expr->getComposite() == expr::CompositeType::eCombine )
			astCheck( expr->getComponent() == type::Kind::eCombinedImage )

			astCheck( expr->getArgList().size() == 2u )
			checkExprDependant( testCounts, *expr, "testExprCompositeConstruct", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprFnCall( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprFnCall" );
		{
			expr::ExprList argList;
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto functionType = typesCache.getFunction( typesCache.getInt32(), var::VariableList{} );
			auto funcName = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eFnCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getFn()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getName() == "func" );
			astCheck( expr->getInstance() == nullptr );

			astCheck( expr->getArgList().empty() );
			checkExprDependant( testCounts, *expr, "testExprFnCall", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eFnCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getFn()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getName() == "func" );
			astCheck( expr->getInstance() == nullptr );

			astCheck( expr->getArgList().size() == 1u );

			astRequire( expr->getArgList()[0]->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getArgList()[0]->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprFnCall", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			argList.emplace_back( exprCache.makeLiteral( typesCache, 1.0f ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p0" ),
					var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p1" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eFnCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getFn()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getName() == "func" );
			astCheck( expr->getInstance() == nullptr );

			astCheck( expr->getArgList().size() == 2u );

			astRequire( expr->getArgList()[0]->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getArgList()[0]->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getValue< expr::LiteralType::eInt32 >() == 10 );

			astRequire( expr->getArgList()[1]->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getArgList()[1]->getType()->getKind() == type::Kind::eFloat );
			astRequire( static_cast< expr::Literal const & >( *expr->getArgList()[1] ).getLiteralType() == expr::LiteralType::eFloat );
			astCheck( static_cast< expr::Literal const & >( *expr->getArgList()[1] ).getValue< expr::LiteralType::eFloat >() == 1.0f );
			checkExprDependant( testCounts, *expr, "testExprFnCall", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprMemberFnCall( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprMemberFnCall" );
		{
			expr::ExprList argList;
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto functionType = typesCache.getFunction( typesCache.getInt32(), var::VariableList{} );
			auto funcName = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto funcOwner = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var" ) );
			auto expr = exprCache.makeMemberFnCall( typesCache.getInt32(), std::move( funcName ), std::move( funcOwner ), std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eFnCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getFn()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getName() == "func" );
			astCheck( expr->getInstance() != nullptr );
			astCheck( expr->getInstance()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( expr->getInstance()->getKind() == expr::Kind::eIdentifier );

			astCheck( expr->getArgList().empty() );
			checkExprDependant( testCounts, *expr, "testExprMemberFnCall", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto funcOwner = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var" ) );
			auto expr = exprCache.makeMemberFnCall( typesCache.getInt32(), std::move( funcName ), std::move( funcOwner ), std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eFnCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getFn()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getName() == "func" );
			astCheck( expr->getInstance() != nullptr );
			astCheck( expr->getInstance()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( expr->getInstance()->getKind() == expr::Kind::eIdentifier );

			astCheck( expr->getArgList().size() == 1u );

			astRequire( expr->getArgList()[0]->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getArgList()[0]->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprMemberFnCall", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			argList.emplace_back( exprCache.makeLiteral( typesCache, 1.0f ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p0" ),
					var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p1" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto funcOwner = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var" ) );
			auto expr = exprCache.makeMemberFnCall( typesCache.getInt32(), std::move( funcName ), std::move( funcOwner ), std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eFnCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getFn()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getType()->getKind() == type::Kind::eFunction );
			astCheck( expr->getFn()->getVariable()->getName() == "func" );
			astCheck( expr->getInstance() != nullptr );
			astCheck( expr->getInstance()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( expr->getInstance()->getKind() == expr::Kind::eIdentifier );

			astCheck( expr->getArgList().size() == 2u );

			astRequire( expr->getArgList()[0]->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getArgList()[0]->getType()->getKind() == type::Kind::eInt32 );
			astRequire( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getArgList()[0] ).getValue< expr::LiteralType::eInt32 >() == 10 );

			astRequire( expr->getArgList()[1]->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getArgList()[1]->getType()->getKind() == type::Kind::eFloat );
			astRequire( static_cast< expr::Literal const & >( *expr->getArgList()[1] ).getLiteralType() == expr::LiteralType::eFloat );
			astCheck( static_cast< expr::Literal const & >( *expr->getArgList()[1] ).getValue< expr::LiteralType::eFloat >() == 1.0f );
			checkExprDependant( testCounts, *expr, "testExprMemberFnCall", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprIntrinsicCall( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprIntrinsicCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( expr::Intrinsic::eCount ); ++intr )
		{
			getName( expr::Intrinsic( intr ) );
		}
		getName( expr::Intrinsic::eCount );
		getName( expr::Intrinsic::eInvalid );
		astCheckThrow( getName( expr::Intrinsic( uint32_t( expr::Intrinsic::eCount ) + 1u ) ) );
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList argList;
			argList.emplace_back( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" ) ) );
			auto expr = exprCache.makeIntrinsicCall( typesCache.getInt32(), expr::Intrinsic::eAbs1I, std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eIntrinsicCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getIntrinsic() == expr::Intrinsic::eAbs1I );

			astCheck( expr->getArgList().size() == 1 );
			astCheck( expr->getArgList().back()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getArgList().back()->getType()->getKind() == type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprIntrinsicCall", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprStorageImageAccessCall( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprStorageImageAccessCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( expr::StorageImageAccess::eCount ); ++intr )
		{
			getName( expr::StorageImageAccess( intr ) );
		}
		getName( expr::StorageImageAccess::eCount );
		getName( expr::StorageImageAccess::eInvalid );
		astCheckThrow( getName( expr::StorageImageAccess( uint32_t( expr::StorageImageAccess::eCount ) + 1u ) ) );
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList argList;
			type::ImageConfiguration config{};
			argList.emplace_back( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getImage( config ), "x" ) ) );
			auto expr = exprCache.makeStorageImageAccessCall( typesCache.getInt32(), expr::StorageImageAccess::eImageSize1DI, std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eImageAccessCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getImageAccess() == expr::StorageImageAccess::eImageSize1DI );

			astCheck( expr->getArgList().size() == 1 );
			astCheck( expr->getArgList().back()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getArgList().back()->getType() == typesCache.getImage( config ) );
			checkExprDependant( testCounts, *expr, "testExprStorageImageAccessCall", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprCombinedImageAccessCall( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprCombinedImageAccessCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( expr::CombinedImageAccess::eCount ); ++intr )
		{
			getName( expr::CombinedImageAccess( intr ) );
			isBiasAndOffset( expr::CombinedImageAccess( intr ) );
			isProj( expr::CombinedImageAccess( intr ) );
			isShadow( expr::CombinedImageAccess( intr ) );
			isShadowLodOffset( expr::CombinedImageAccess( intr ) );
		}
		getName( expr::CombinedImageAccess::eCount );
		getName( expr::CombinedImageAccess::eInvalid );
		astCheckThrow( getName( expr::CombinedImageAccess( uint32_t( expr::CombinedImageAccess::eCount ) + 1u ) ) );
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList argList;
			type::ImageConfiguration config{};
			argList.emplace_back( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getCombinedImage( config ), "x" ) ) );
			auto expr = exprCache.makeCombinedImageAccessCall( typesCache.getInt32(), expr::CombinedImageAccess::eTextureSize1DI, std::move( argList ) );

			astRequire( expr->getKind() == expr::Kind::eCombinedImageAccessCall );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astCheck( expr->getCombinedImageAccess() == expr::CombinedImageAccess::eTextureSize1DI );

			astCheck( expr->getArgList().size() == 1 );
			astCheck( expr->getArgList().back()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getArgList().back()->getType() == typesCache.getCombinedImage( config ) );
			checkExprDependant( testCounts, *expr, "testExprCombinedImageAccessCall", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprAggrInit( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprAggrInit" );
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32(), 4u ), "lhs" ) );
			expr::ExprList rhs;
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			astRequire( expr->getKind() == expr::Kind::eAggrInit );
			astCheck( expr->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getType() ) == type::Kind::eInt32 );

			astRequire( expr->hasIdentifier() );
			astCheck( expr->getIdentifier().getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getIdentifier().getType() ) == type::Kind::eInt32 );
			astCheck( expr->getIdentifier().getVariable()->getName() == "lhs" );
			astCheck( expr->getIdentifier().getVariable()->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getIdentifier().getVariable()->getType() ) == type::Kind::eInt32 );

			astCheck( expr->getInitialisers().empty() );
			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32(), 4u ), "lhs", var::Flag::eStatic ) );
			expr::ExprList rhs;
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			astRequire( expr->getKind() == expr::Kind::eAggrInit );
			astCheck( expr->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getType() ) == type::Kind::eInt32 );

			astRequire( expr->hasIdentifier() );
			astCheck( expr->getIdentifier().getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getIdentifier().getType() ) == type::Kind::eInt32 );
			astCheck( expr->getIdentifier().getVariable()->isStatic() );
			astCheck( expr->getIdentifier().getVariable()->getName() == "lhs" );
			astCheck( expr->getIdentifier().getVariable()->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getIdentifier().getVariable()->getType() ) == type::Kind::eInt32 );

			astCheck( expr->getInitialisers().empty() );
			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32(), 4u ), "lhs" ) );
			expr::ExprList rhs;
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 20 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 30 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 40 ) );
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			astRequire( expr->getKind() == expr::Kind::eAggrInit );
			astCheck( expr->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getType() ) == type::Kind::eInt32 );

			astRequire( expr->hasIdentifier() );
			astCheck( expr->getIdentifier().getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getIdentifier().getType() ) == type::Kind::eInt32 );
			astCheck( expr->getIdentifier().getVariable()->getName() == "lhs" );
			astCheck( expr->getIdentifier().getVariable()->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getIdentifier().getVariable()->getType() ) == type::Kind::eInt32 );

			astCheck( expr->getInitialisers().size() == 4u );
			int v = 10;

			for ( auto & init : expr->getInitialisers() )
			{
				astCheck( init->getKind() == expr::Kind::eLiteral );
				astCheck( init->getType()->getKind() == type::Kind::eInt32 );
				astCheck( static_cast< expr::Literal const & >( *init ).getLiteralType() == expr::LiteralType::eInt32 );
				astCheck( static_cast< expr::Literal const & >( *init ).getValue< expr::LiteralType::eInt32 >() == v );
				v += 10;
			}

			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList rhs;
			auto expr = exprCache.makeAggrInit( typesCache.getArray( typesCache.getInt32(), 4u ), std::move( rhs ) );

			astRequire( expr->getKind() == expr::Kind::eAggrInit );
			astCheck( expr->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getType() ) == type::Kind::eInt32 );

			astRequire( !expr->hasIdentifier() );

			astCheck( expr->getInitialisers().empty() );
			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			expr::ExprList rhs;
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 20 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 30 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 40 ) );
			auto expr = exprCache.makeAggrInit( typesCache.getArray( typesCache.getInt32(), 4u ), std::move( rhs ) );

			astRequire( expr->getKind() == expr::Kind::eAggrInit );
			astCheck( expr->getType()->getKind() == type::Kind::eArray );
			astCheck( getNonArrayKind( expr->getType() ) == type::Kind::eInt32 );

			astRequire( !expr->hasIdentifier() );

			astCheck( expr->getInitialisers().size() == 4u );
			int v = 10;

			for ( auto & init : expr->getInitialisers() )
			{
				astCheck( init->getKind() == expr::Kind::eLiteral );
				astCheck( init->getType()->getKind() == type::Kind::eInt32 );
				astCheck( static_cast< expr::Literal const & >( *init ).getLiteralType() == expr::LiteralType::eInt32 );
				astCheck( static_cast< expr::Literal const & >( *init ).getValue< expr::LiteralType::eInt32 >() == v );
				v += 10;
			}

			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprInit( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprInit" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::eConstant | var::Flag::eStatic ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeInit( std::move( lhs ), std::move( rhs ) );

		astRequire( expr->getKind() == expr::Kind::eInit );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->hasIdentifier() );
		astCheck( expr->getIdentifier().getType()->getKind() == type::Kind::eInt32 );
		astCheck( expr->getIdentifier().getVariable()->getName() == "lhs" );
		astCheck( expr->getIdentifier().getVariable()->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getInitialiser()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getInitialiser()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getInitialiser() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getInitialiser() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprInit", __LINE__ );
		astTestEnd()
	}

	static void testExprMbrSelect( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprMbrSelect" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto type = typesCache.getStruct( type::MemoryLayout::eStd140, "outer" );
		type->declMember( "inner", typesCache.getInt32() );
		{
			auto outerVar = var::makeVariable( testCounts.getNextVarId(), type, "outerVar" );
			auto expr = exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, outerVar ), 0u, uint64_t( var::Flag::eShaderInput ) );

			astRequire( expr->getKind() == expr::Kind::eMbrSelect );
			astCheck( expr->getOuterExpr()->getType()->getKind() == type::Kind::eStruct );

			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );
			astCheck( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getName() == "outerVar" );

			astCheck( expr->getMemberIndex() == 0u );
			astCheck( expr->getMemberFlags() == uint64_t( var::Flag::eShaderInput ) );
			checkExprDependant( testCounts, *expr, "testExprMbrSelect", __LINE__ );
		}
		{
			auto pointer = typesCache.getPointerType( type, type::Storage::eFunction );
			auto outerVar = var::makeVariable( testCounts.getNextVarId(), pointer, "outerVar" );
			auto expr = exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, outerVar ), 0u, uint64_t( var::Flag::eShaderInput ) );

			astRequire( expr->getKind() == expr::Kind::eMbrSelect );
			astCheck( expr->getOuterExpr()->getType()->getKind() == type::Kind::ePointer );

			astCheck( expr->getType()->getKind() == type::Kind::ePointer );
			astCheck( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier );
			astCheck( static_cast< expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getName() == "outerVar" );

			astCheck( expr->getMemberIndex() == 0u );
			astCheck( expr->getMemberFlags() == uint64_t( var::Flag::eShaderInput ) );
			checkExprDependant( testCounts, *expr, "testExprMbrSelect", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprQuestion( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprQuestion" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto ctrlExpr = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "ctrl" ) );
			auto trueExpr = exprCache.makeIdentifier( typesCache, var::makeVariable( 2u, typesCache.getInt32(), "lhs" ) );
			auto falseExpr = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeQuestion( typesCache.getInt32(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

			astRequire( expr->getKind() == expr::Kind::eQuestion );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getCtrlExpr()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean );
			astCheck( static_cast< expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getType()->getKind() == type::Kind::eBoolean );
			astCheck( static_cast< expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getName() == "ctrl" );

			astRequire( expr->getTrueExpr()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getTrueExpr()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

			astRequire( expr->getFalseExpr()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getFalseExpr()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getFalseExpr() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getFalseExpr() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprQuestion", __LINE__ );
		}
		{
			auto ctrlExpr = exprCache.makeLiteral( typesCache, false );
			auto trueExpr = exprCache.makeIdentifier( typesCache, var::makeVariable( 2u, typesCache.getInt32(), "lhs" ) );
			auto falseExpr = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeQuestion( typesCache.getInt32(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

			astRequire( expr->getKind() == expr::Kind::eQuestion );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			astRequire( expr->getCtrlExpr()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean );

			astRequire( expr->getTrueExpr()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getTrueExpr()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

			astRequire( expr->getFalseExpr()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getFalseExpr()->getType()->getKind() == type::Kind::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getFalseExpr() ).getLiteralType() == expr::LiteralType::eInt32 );
			astCheck( static_cast< expr::Literal const & >( *expr->getFalseExpr() ).getValue< expr::LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprQuestion", __LINE__ );
		}
		{
			auto ctrlExpr = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2, type::Kind::eBoolean
				, makeList( exprCache.makeLiteral( typesCache, false ), exprCache.makeLiteral( typesCache, true ) ) );
			auto trueExpr = exprCache.makeIdentifier( typesCache, var::makeVariable( 2u, typesCache.getVec2I32(), "lhs" ) );
			auto falseExpr = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2, type::Kind::eInt32
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) );
			auto expr = exprCache.makeQuestion( typesCache.getVec2I32(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

			astRequire( expr->getKind() == expr::Kind::eQuestion );
			astCheck( expr->getType()->getKind() == type::Kind::eVec2I32 );

			astRequire( expr->getCtrlExpr()->getKind() == expr::Kind::eCompositeConstruct );
			astCheck( expr->getCtrlExpr()->getType()->getKind() == type::Kind::eVec2B );

			astRequire( expr->getTrueExpr()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getTrueExpr()->getType()->getKind() == type::Kind::eVec2I32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == type::Kind::eVec2I32 );
			astCheck( static_cast< expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

			astRequire( expr->getFalseExpr()->getKind() == expr::Kind::eCompositeConstruct );
			astCheck( expr->getFalseExpr()->getType()->getKind() == type::Kind::eVec2I32 );
			checkExprDependant( testCounts, *expr, "testExprQuestion", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprSwitchCase( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprSwitchCase" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto label = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeSwitchCase( std::move( label ) );

		astRequire( expr->getKind() == expr::Kind::eSwitchCase );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getLabel()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getLabel()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getLabel() ).getLiteralType() == expr::LiteralType::eInt32 );
		astCheck( static_cast< expr::Literal const & >( *expr->getLabel() ).getValue< expr::LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprSwitchCase", __LINE__ );
		astTestEnd()
	}

	static void testExprSwitchTest( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprSwitchTest" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto expr = exprCache.makeSwitchTest( std::move( value ) );

		astRequire( expr->getKind() == expr::Kind::eSwitchTest );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		astRequire( expr->getValue()->getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getValue()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getValue() ).getVariable()->getType()->getKind() == type::Kind::eInt32 );
		astCheck( static_cast< expr::Identifier const & >( *expr->getValue() ).getVariable()->getName() == "lhs" );
		checkExprDependant( testCounts, *expr, "testExprSwitchTest", __LINE__ );
		astTestEnd()
	}

	static void testExprCopy( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprCopy" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto value = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "operand" ) );
			auto expr = exprCache.makeCopy( std::move( value ) );

			astRequire( expr->getKind() == expr::Kind::eCopy );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			checkExprDependant( testCounts, *expr, "testExprCopy", __LINE__ );
		}
		{
			auto expr = exprCache.makeCopy( exprCache.makeLiteral( typesCache, 10 ) );

			astRequire( expr->getKind() == expr::Kind::eCopy );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			checkExprDependant( testCounts, *expr, "testExprCopy", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprAlias( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprAlias" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto ident = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "operand" ) );
		auto lit = exprCache.makeLiteral( typesCache, 1 );
		auto expr = exprCache.makeAlias( typesCache.getInt32(), std::move( ident ), std::move( lit ) );

		astRequire( expr->getKind() == expr::Kind::eAlias );
		astRequire( expr->hasIdentifier() );
		astCheck( expr->getIdentifier().getKind() == expr::Kind::eIdentifier );
		astCheck( expr->getAliasedExpr()->getKind() == expr::Kind::eLiteral );
		astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

		checkExprDependant( testCounts, *expr, "testExprAlias", __LINE__ );
		astTestEnd()
	}

	static void testExprStreamAppend( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprStreamAppend" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto value = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "operand" ) );
			auto expr = exprCache.makeStreamAppend( std::move( value ) );

			astRequire( expr->getKind() == expr::Kind::eStreamAppend );
			astRequire( expr->getOperand()->getKind() == expr::Kind::eIdentifier );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			checkExprDependant( testCounts, *expr, "testExprStreamAppend", __LINE__ );
		}
		{
			auto expr = exprCache.makeStreamAppend( exprCache.makeLiteral( typesCache, 10 ) );

			astRequire( expr->getKind() == expr::Kind::eStreamAppend );
			astRequire( expr->getOperand()->getKind() == expr::Kind::eLiteral );
			astCheck( expr->getType()->getKind() == type::Kind::eInt32 );

			checkExprDependant( testCounts, *expr, "testExprStreamAppend", __LINE__ );
		}
		astTestEnd()
	}

	static void testExprSwizzle( test::TestCounts & testCounts )
	{
		astTestBegin( "testExprSwizzle" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "operand" ) );
		auto expr = exprCache.makeSwizzle( std::move( value ), expr::SwizzleKind{ expr::SwizzleKind::e03 } );

		astRequire( expr->getKind() == expr::Kind::eSwizzle )
		astRequire( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier )
		astRequire( expr->getOuterExpr()->getType()->getKind() == type::Kind::eVec4F )
		astCheck( expr->getType()->getKind() == type::Kind::eVec2F )
		astCheck( expr->getSwizzle() == expr::SwizzleKind::e03 )
		checkExprDependant( testCounts, *expr, "testExprSwizzle", __LINE__ );

		expr::SwizzleKind kind{};
		kind = expr::SwizzleKind::Value::e0;
		kind = expr::SwizzleKind::fromOffset( 0u );
		kind.toIndex();
		astCheck( !kind.isFourComponents() );
		astCheck( !kind.isThreeComponents() );
		astCheck( !kind.isTwoComponents() );
		astCheck( kind.isOneComponent() );
		auto kind2 = kind[0];
		kind |= kind2;

#define checkSwizzle( value )\
	getName( expr::SwizzleKind{ value } );\
	exprCache.makeSwizzle( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "operand" ) ), expr::SwizzleKind{ value } )

		checkSwizzle( expr::SwizzleKind::e0 );
		checkSwizzle( expr::SwizzleKind::e1 );
		checkSwizzle( expr::SwizzleKind::e2 );
		checkSwizzle( expr::SwizzleKind::e3 );
		checkSwizzle( expr::SwizzleKind::e00 );
		checkSwizzle( expr::SwizzleKind::e01 );
		checkSwizzle( expr::SwizzleKind::e02 );
		checkSwizzle( expr::SwizzleKind::e03 );
		checkSwizzle( expr::SwizzleKind::e10 );
		checkSwizzle( expr::SwizzleKind::e11 );
		checkSwizzle( expr::SwizzleKind::e12 );
		checkSwizzle( expr::SwizzleKind::e13 );
		checkSwizzle( expr::SwizzleKind::e20 );
		checkSwizzle( expr::SwizzleKind::e21 );
		checkSwizzle( expr::SwizzleKind::e22 );
		checkSwizzle( expr::SwizzleKind::e23 );
		checkSwizzle( expr::SwizzleKind::e30 );
		checkSwizzle( expr::SwizzleKind::e31 );
		checkSwizzle( expr::SwizzleKind::e32 );
		checkSwizzle( expr::SwizzleKind::e33 );
		checkSwizzle( expr::SwizzleKind::e000 );
		checkSwizzle( expr::SwizzleKind::e001 );
		checkSwizzle( expr::SwizzleKind::e002 );
		checkSwizzle( expr::SwizzleKind::e003 );
		checkSwizzle( expr::SwizzleKind::e010 );
		checkSwizzle( expr::SwizzleKind::e011 );
		checkSwizzle( expr::SwizzleKind::e012 );
		checkSwizzle( expr::SwizzleKind::e013 );
		checkSwizzle( expr::SwizzleKind::e020 );
		checkSwizzle( expr::SwizzleKind::e021 );
		checkSwizzle( expr::SwizzleKind::e022 );
		checkSwizzle( expr::SwizzleKind::e023 );
		checkSwizzle( expr::SwizzleKind::e030 );
		checkSwizzle( expr::SwizzleKind::e031 );
		checkSwizzle( expr::SwizzleKind::e032 );
		checkSwizzle( expr::SwizzleKind::e033 );
		checkSwizzle( expr::SwizzleKind::e100 );
		checkSwizzle( expr::SwizzleKind::e101 );
		checkSwizzle( expr::SwizzleKind::e102 );
		checkSwizzle( expr::SwizzleKind::e103 );
		checkSwizzle( expr::SwizzleKind::e110 );
		checkSwizzle( expr::SwizzleKind::e111 );
		checkSwizzle( expr::SwizzleKind::e112 );
		checkSwizzle( expr::SwizzleKind::e113 );
		checkSwizzle( expr::SwizzleKind::e120 );
		checkSwizzle( expr::SwizzleKind::e121 );
		checkSwizzle( expr::SwizzleKind::e122 );
		checkSwizzle( expr::SwizzleKind::e123 );
		checkSwizzle( expr::SwizzleKind::e130 );
		checkSwizzle( expr::SwizzleKind::e131 );
		checkSwizzle( expr::SwizzleKind::e132 );
		checkSwizzle( expr::SwizzleKind::e133 );
		checkSwizzle( expr::SwizzleKind::e200 );
		checkSwizzle( expr::SwizzleKind::e201 );
		checkSwizzle( expr::SwizzleKind::e202 );
		checkSwizzle( expr::SwizzleKind::e203 );
		checkSwizzle( expr::SwizzleKind::e210 );
		checkSwizzle( expr::SwizzleKind::e211 );
		checkSwizzle( expr::SwizzleKind::e212 );
		checkSwizzle( expr::SwizzleKind::e213 );
		checkSwizzle( expr::SwizzleKind::e220 );
		checkSwizzle( expr::SwizzleKind::e221 );
		checkSwizzle( expr::SwizzleKind::e222 );
		checkSwizzle( expr::SwizzleKind::e223 );
		checkSwizzle( expr::SwizzleKind::e230 );
		checkSwizzle( expr::SwizzleKind::e231 );
		checkSwizzle( expr::SwizzleKind::e232 );
		checkSwizzle( expr::SwizzleKind::e233 );
		checkSwizzle( expr::SwizzleKind::e300 );
		checkSwizzle( expr::SwizzleKind::e301 );
		checkSwizzle( expr::SwizzleKind::e302 );
		checkSwizzle( expr::SwizzleKind::e303 );
		checkSwizzle( expr::SwizzleKind::e310 );
		checkSwizzle( expr::SwizzleKind::e311 );
		checkSwizzle( expr::SwizzleKind::e312 );
		checkSwizzle( expr::SwizzleKind::e313 );
		checkSwizzle( expr::SwizzleKind::e320 );
		checkSwizzle( expr::SwizzleKind::e321 );
		checkSwizzle( expr::SwizzleKind::e322 );
		checkSwizzle( expr::SwizzleKind::e323 );
		checkSwizzle( expr::SwizzleKind::e330 );
		checkSwizzle( expr::SwizzleKind::e331 );
		checkSwizzle( expr::SwizzleKind::e332 );
		checkSwizzle( expr::SwizzleKind::e333 );
		checkSwizzle( expr::SwizzleKind::e0000 );
		checkSwizzle( expr::SwizzleKind::e0001 );
		checkSwizzle( expr::SwizzleKind::e0002 );
		checkSwizzle( expr::SwizzleKind::e0003 );
		checkSwizzle( expr::SwizzleKind::e0010 );
		checkSwizzle( expr::SwizzleKind::e0011 );
		checkSwizzle( expr::SwizzleKind::e0012 );
		checkSwizzle( expr::SwizzleKind::e0013 );
		checkSwizzle( expr::SwizzleKind::e0020 );
		checkSwizzle( expr::SwizzleKind::e0021 );
		checkSwizzle( expr::SwizzleKind::e0022 );
		checkSwizzle( expr::SwizzleKind::e0023 );
		checkSwizzle( expr::SwizzleKind::e0030 );
		checkSwizzle( expr::SwizzleKind::e0031 );
		checkSwizzle( expr::SwizzleKind::e0032 );
		checkSwizzle( expr::SwizzleKind::e0033 );
		checkSwizzle( expr::SwizzleKind::e0100 );
		checkSwizzle( expr::SwizzleKind::e0101 );
		checkSwizzle( expr::SwizzleKind::e0102 );
		checkSwizzle( expr::SwizzleKind::e0103 );
		checkSwizzle( expr::SwizzleKind::e0110 );
		checkSwizzle( expr::SwizzleKind::e0111 );
		checkSwizzle( expr::SwizzleKind::e0112 );
		checkSwizzle( expr::SwizzleKind::e0113 );
		checkSwizzle( expr::SwizzleKind::e0120 );
		checkSwizzle( expr::SwizzleKind::e0121 );
		checkSwizzle( expr::SwizzleKind::e0122 );
		checkSwizzle( expr::SwizzleKind::e0123 );
		checkSwizzle( expr::SwizzleKind::e0130 );
		checkSwizzle( expr::SwizzleKind::e0131 );
		checkSwizzle( expr::SwizzleKind::e0132 );
		checkSwizzle( expr::SwizzleKind::e0133 );
		checkSwizzle( expr::SwizzleKind::e0200 );
		checkSwizzle( expr::SwizzleKind::e0201 );
		checkSwizzle( expr::SwizzleKind::e0202 );
		checkSwizzle( expr::SwizzleKind::e0203 );
		checkSwizzle( expr::SwizzleKind::e0210 );
		checkSwizzle( expr::SwizzleKind::e0211 );
		checkSwizzle( expr::SwizzleKind::e0212 );
		checkSwizzle( expr::SwizzleKind::e0213 );
		checkSwizzle( expr::SwizzleKind::e0220 );
		checkSwizzle( expr::SwizzleKind::e0221 );
		checkSwizzle( expr::SwizzleKind::e0222 );
		checkSwizzle( expr::SwizzleKind::e0223 );
		checkSwizzle( expr::SwizzleKind::e0230 );
		checkSwizzle( expr::SwizzleKind::e0231 );
		checkSwizzle( expr::SwizzleKind::e0232 );
		checkSwizzle( expr::SwizzleKind::e0233 );
		checkSwizzle( expr::SwizzleKind::e0300 );
		checkSwizzle( expr::SwizzleKind::e0301 );
		checkSwizzle( expr::SwizzleKind::e0302 );
		checkSwizzle( expr::SwizzleKind::e0303 );
		checkSwizzle( expr::SwizzleKind::e0310 );
		checkSwizzle( expr::SwizzleKind::e0311 );
		checkSwizzle( expr::SwizzleKind::e0312 );
		checkSwizzle( expr::SwizzleKind::e0313 );
		checkSwizzle( expr::SwizzleKind::e0320 );
		checkSwizzle( expr::SwizzleKind::e0321 );
		checkSwizzle( expr::SwizzleKind::e0322 );
		checkSwizzle( expr::SwizzleKind::e0323 );
		checkSwizzle( expr::SwizzleKind::e0330 );
		checkSwizzle( expr::SwizzleKind::e0331 );
		checkSwizzle( expr::SwizzleKind::e0332 );
		checkSwizzle( expr::SwizzleKind::e0333 );
		checkSwizzle( expr::SwizzleKind::e1000 );
		checkSwizzle( expr::SwizzleKind::e1001 );
		checkSwizzle( expr::SwizzleKind::e1002 );
		checkSwizzle( expr::SwizzleKind::e1003 );
		checkSwizzle( expr::SwizzleKind::e1010 );
		checkSwizzle( expr::SwizzleKind::e1011 );
		checkSwizzle( expr::SwizzleKind::e1012 );
		checkSwizzle( expr::SwizzleKind::e1013 );
		checkSwizzle( expr::SwizzleKind::e1020 );
		checkSwizzle( expr::SwizzleKind::e1021 );
		checkSwizzle( expr::SwizzleKind::e1022 );
		checkSwizzle( expr::SwizzleKind::e1023 );
		checkSwizzle( expr::SwizzleKind::e1030 );
		checkSwizzle( expr::SwizzleKind::e1031 );
		checkSwizzle( expr::SwizzleKind::e1032 );
		checkSwizzle( expr::SwizzleKind::e1033 );
		checkSwizzle( expr::SwizzleKind::e1100 );
		checkSwizzle( expr::SwizzleKind::e1101 );
		checkSwizzle( expr::SwizzleKind::e1102 );
		checkSwizzle( expr::SwizzleKind::e1103 );
		checkSwizzle( expr::SwizzleKind::e1110 );
		checkSwizzle( expr::SwizzleKind::e1111 );
		checkSwizzle( expr::SwizzleKind::e1112 );
		checkSwizzle( expr::SwizzleKind::e1113 );
		checkSwizzle( expr::SwizzleKind::e1120 );
		checkSwizzle( expr::SwizzleKind::e1121 );
		checkSwizzle( expr::SwizzleKind::e1122 );
		checkSwizzle( expr::SwizzleKind::e1123 );
		checkSwizzle( expr::SwizzleKind::e1130 );
		checkSwizzle( expr::SwizzleKind::e1131 );
		checkSwizzle( expr::SwizzleKind::e1132 );
		checkSwizzle( expr::SwizzleKind::e1133 );
		checkSwizzle( expr::SwizzleKind::e1200 );
		checkSwizzle( expr::SwizzleKind::e1201 );
		checkSwizzle( expr::SwizzleKind::e1202 );
		checkSwizzle( expr::SwizzleKind::e1203 );
		checkSwizzle( expr::SwizzleKind::e1210 );
		checkSwizzle( expr::SwizzleKind::e1211 );
		checkSwizzle( expr::SwizzleKind::e1212 );
		checkSwizzle( expr::SwizzleKind::e1213 );
		checkSwizzle( expr::SwizzleKind::e1220 );
		checkSwizzle( expr::SwizzleKind::e1221 );
		checkSwizzle( expr::SwizzleKind::e1222 );
		checkSwizzle( expr::SwizzleKind::e1223 );
		checkSwizzle( expr::SwizzleKind::e1230 );
		checkSwizzle( expr::SwizzleKind::e1231 );
		checkSwizzle( expr::SwizzleKind::e1232 );
		checkSwizzle( expr::SwizzleKind::e1233 );
		checkSwizzle( expr::SwizzleKind::e1300 );
		checkSwizzle( expr::SwizzleKind::e1301 );
		checkSwizzle( expr::SwizzleKind::e1302 );
		checkSwizzle( expr::SwizzleKind::e1303 );
		checkSwizzle( expr::SwizzleKind::e1310 );
		checkSwizzle( expr::SwizzleKind::e1311 );
		checkSwizzle( expr::SwizzleKind::e1312 );
		checkSwizzle( expr::SwizzleKind::e1313 );
		checkSwizzle( expr::SwizzleKind::e1320 );
		checkSwizzle( expr::SwizzleKind::e1321 );
		checkSwizzle( expr::SwizzleKind::e1322 );
		checkSwizzle( expr::SwizzleKind::e1323 );
		checkSwizzle( expr::SwizzleKind::e1330 );
		checkSwizzle( expr::SwizzleKind::e1331 );
		checkSwizzle( expr::SwizzleKind::e1332 );
		checkSwizzle( expr::SwizzleKind::e1333 );
		checkSwizzle( expr::SwizzleKind::e2000 );
		checkSwizzle( expr::SwizzleKind::e2001 );
		checkSwizzle( expr::SwizzleKind::e2002 );
		checkSwizzle( expr::SwizzleKind::e2003 );
		checkSwizzle( expr::SwizzleKind::e2010 );
		checkSwizzle( expr::SwizzleKind::e2011 );
		checkSwizzle( expr::SwizzleKind::e2012 );
		checkSwizzle( expr::SwizzleKind::e2013 );
		checkSwizzle( expr::SwizzleKind::e2020 );
		checkSwizzle( expr::SwizzleKind::e2021 );
		checkSwizzle( expr::SwizzleKind::e2022 );
		checkSwizzle( expr::SwizzleKind::e2023 );
		checkSwizzle( expr::SwizzleKind::e2030 );
		checkSwizzle( expr::SwizzleKind::e2031 );
		checkSwizzle( expr::SwizzleKind::e2032 );
		checkSwizzle( expr::SwizzleKind::e2033 );
		checkSwizzle( expr::SwizzleKind::e2100 );
		checkSwizzle( expr::SwizzleKind::e2101 );
		checkSwizzle( expr::SwizzleKind::e2102 );
		checkSwizzle( expr::SwizzleKind::e2103 );
		checkSwizzle( expr::SwizzleKind::e2110 );
		checkSwizzle( expr::SwizzleKind::e2111 );
		checkSwizzle( expr::SwizzleKind::e2112 );
		checkSwizzle( expr::SwizzleKind::e2113 );
		checkSwizzle( expr::SwizzleKind::e2120 );
		checkSwizzle( expr::SwizzleKind::e2121 );
		checkSwizzle( expr::SwizzleKind::e2122 );
		checkSwizzle( expr::SwizzleKind::e2123 );
		checkSwizzle( expr::SwizzleKind::e2130 );
		checkSwizzle( expr::SwizzleKind::e2131 );
		checkSwizzle( expr::SwizzleKind::e2132 );
		checkSwizzle( expr::SwizzleKind::e2133 );
		checkSwizzle( expr::SwizzleKind::e2200 );
		checkSwizzle( expr::SwizzleKind::e2201 );
		checkSwizzle( expr::SwizzleKind::e2202 );
		checkSwizzle( expr::SwizzleKind::e2203 );
		checkSwizzle( expr::SwizzleKind::e2210 );
		checkSwizzle( expr::SwizzleKind::e2211 );
		checkSwizzle( expr::SwizzleKind::e2212 );
		checkSwizzle( expr::SwizzleKind::e2213 );
		checkSwizzle( expr::SwizzleKind::e2220 );
		checkSwizzle( expr::SwizzleKind::e2221 );
		checkSwizzle( expr::SwizzleKind::e2222 );
		checkSwizzle( expr::SwizzleKind::e2223 );
		checkSwizzle( expr::SwizzleKind::e2230 );
		checkSwizzle( expr::SwizzleKind::e2231 );
		checkSwizzle( expr::SwizzleKind::e2232 );
		checkSwizzle( expr::SwizzleKind::e2233 );
		checkSwizzle( expr::SwizzleKind::e2300 );
		checkSwizzle( expr::SwizzleKind::e2301 );
		checkSwizzle( expr::SwizzleKind::e2302 );
		checkSwizzle( expr::SwizzleKind::e2303 );
		checkSwizzle( expr::SwizzleKind::e2310 );
		checkSwizzle( expr::SwizzleKind::e2311 );
		checkSwizzle( expr::SwizzleKind::e2312 );
		checkSwizzle( expr::SwizzleKind::e2313 );
		checkSwizzle( expr::SwizzleKind::e2320 );
		checkSwizzle( expr::SwizzleKind::e2321 );
		checkSwizzle( expr::SwizzleKind::e2322 );
		checkSwizzle( expr::SwizzleKind::e2323 );
		checkSwizzle( expr::SwizzleKind::e2330 );
		checkSwizzle( expr::SwizzleKind::e2331 );
		checkSwizzle( expr::SwizzleKind::e2332 );
		checkSwizzle( expr::SwizzleKind::e2333 );
		checkSwizzle( expr::SwizzleKind::e3000 );
		checkSwizzle( expr::SwizzleKind::e3001 );
		checkSwizzle( expr::SwizzleKind::e3002 );
		checkSwizzle( expr::SwizzleKind::e3003 );
		checkSwizzle( expr::SwizzleKind::e3010 );
		checkSwizzle( expr::SwizzleKind::e3011 );
		checkSwizzle( expr::SwizzleKind::e3012 );
		checkSwizzle( expr::SwizzleKind::e3013 );
		checkSwizzle( expr::SwizzleKind::e3020 );
		checkSwizzle( expr::SwizzleKind::e3021 );
		checkSwizzle( expr::SwizzleKind::e3022 );
		checkSwizzle( expr::SwizzleKind::e3023 );
		checkSwizzle( expr::SwizzleKind::e3030 );
		checkSwizzle( expr::SwizzleKind::e3031 );
		checkSwizzle( expr::SwizzleKind::e3032 );
		checkSwizzle( expr::SwizzleKind::e3033 );
		checkSwizzle( expr::SwizzleKind::e3100 );
		checkSwizzle( expr::SwizzleKind::e3101 );
		checkSwizzle( expr::SwizzleKind::e3102 );
		checkSwizzle( expr::SwizzleKind::e3103 );
		checkSwizzle( expr::SwizzleKind::e3110 );
		checkSwizzle( expr::SwizzleKind::e3111 );
		checkSwizzle( expr::SwizzleKind::e3112 );
		checkSwizzle( expr::SwizzleKind::e3113 );
		checkSwizzle( expr::SwizzleKind::e3120 );
		checkSwizzle( expr::SwizzleKind::e3121 );
		checkSwizzle( expr::SwizzleKind::e3122 );
		checkSwizzle( expr::SwizzleKind::e3123 );
		checkSwizzle( expr::SwizzleKind::e3130 );
		checkSwizzle( expr::SwizzleKind::e3131 );
		checkSwizzle( expr::SwizzleKind::e3132 );
		checkSwizzle( expr::SwizzleKind::e3133 );
		checkSwizzle( expr::SwizzleKind::e3200 );
		checkSwizzle( expr::SwizzleKind::e3201 );
		checkSwizzle( expr::SwizzleKind::e3202 );
		checkSwizzle( expr::SwizzleKind::e3203 );
		checkSwizzle( expr::SwizzleKind::e3210 );
		checkSwizzle( expr::SwizzleKind::e3211 );
		checkSwizzle( expr::SwizzleKind::e3212 );
		checkSwizzle( expr::SwizzleKind::e3213 );
		checkSwizzle( expr::SwizzleKind::e3220 );
		checkSwizzle( expr::SwizzleKind::e3221 );
		checkSwizzle( expr::SwizzleKind::e3222 );
		checkSwizzle( expr::SwizzleKind::e3223 );
		checkSwizzle( expr::SwizzleKind::e3230 );
		checkSwizzle( expr::SwizzleKind::e3231 );
		checkSwizzle( expr::SwizzleKind::e3232 );
		checkSwizzle( expr::SwizzleKind::e3233 );
		checkSwizzle( expr::SwizzleKind::e3300 );
		checkSwizzle( expr::SwizzleKind::e3301 );
		checkSwizzle( expr::SwizzleKind::e3302 );
		checkSwizzle( expr::SwizzleKind::e3303 );
		checkSwizzle( expr::SwizzleKind::e3310 );
		checkSwizzle( expr::SwizzleKind::e3311 );
		checkSwizzle( expr::SwizzleKind::e3312 );
		checkSwizzle( expr::SwizzleKind::e3313 );
		checkSwizzle( expr::SwizzleKind::e3320 );
		checkSwizzle( expr::SwizzleKind::e3321 );
		checkSwizzle( expr::SwizzleKind::e3322 );
		checkSwizzle( expr::SwizzleKind::e3323 );
		checkSwizzle( expr::SwizzleKind::e3330 );
		checkSwizzle( expr::SwizzleKind::e3331 );
		checkSwizzle( expr::SwizzleKind::e3332 );
		checkSwizzle( expr::SwizzleKind::e3333 );

#undef checkSwizzle

		auto szvalue = expr::SwizzleKind::Value::e1 | expr::SwizzleKind::Value::e0;
		astCheck( szvalue == ( expr::SwizzleKind::Value::e1 | expr::SwizzleKind::Value::e0 ) )

		astCheck( ExprCloner::submit( exprCache, nullptr ) == nullptr )
		astCheck( ExprCloner::submit( exprCache, expr.get() ) != nullptr )
		expr->updateFlag( expr::Flag::eNonUniform );
		astCheck( ExprCloner::submit( exprCache, expr.get() ) != nullptr )
		astTestEnd()
	}
}

astTestSuiteMain( TestASTExpressions )
{
	astTestSuiteBegin()
	testCounts << "sizeof( bool ) = " << sizeof( bool ) << test::endl;
	testCounts << "sizeof( signed char ) = " << sizeof( signed char ) << test::endl;
	testCounts << "sizeof( signed short ) = " << sizeof( signed short ) << test::endl;
	testCounts << "sizeof( signed int ) = " << sizeof( signed int ) << test::endl;
	testCounts << "sizeof( signed long ) = " << sizeof( signed long ) << test::endl;
	testCounts << "sizeof( signed long long ) = " << sizeof( signed long long ) << test::endl;
	testCounts << "sizeof( unsigned char ) = " << sizeof( unsigned char ) << test::endl;
	testCounts << "sizeof( unsigned short ) = " << sizeof( unsigned short ) << test::endl;
	testCounts << "sizeof( unsigned int ) = " << sizeof( unsigned int ) << test::endl;
	testCounts << "sizeof( unsigned long ) = " << sizeof( unsigned long ) << test::endl;
	testCounts << "sizeof( unsigned long long ) = " << sizeof( unsigned long long ) << test::endl;
	checks::testExprAdd( testCounts );
	checks::testExprAddAssign( testCounts );
	checks::testExprAggrInit( testCounts );
	checks::testExprAlias( testCounts );
	checks::testExprAndAssign( testCounts );
	checks::testExprArrayAccess( testCounts );
	checks::testExprAssign( testCounts );
	checks::testExprBitAnd( testCounts );
	checks::testExprBitNot( testCounts );
	checks::testExprBitOr( testCounts );
	checks::testExprBitXor( testCounts );
	checks::testExprCast( testCounts );
	checks::testExprCombinedImageAccessCall( testCounts );
	checks::testExprComma( testCounts );
	checks::testExprCompositeConstruct( testCounts );
	checks::testExprCopy( testCounts );
	checks::testExprDivide( testCounts );
	checks::testExprDivideAssign( testCounts );
	checks::testExprEqual( testCounts );
	checks::testExprFnCall( testCounts );
	checks::testExprMemberFnCall( testCounts );
	checks::testExprGreater( testCounts );
	checks::testExprGreaterEqual( testCounts );
	checks::testExprIdentifier( testCounts );
	checks::testExprInit( testCounts );
	checks::testExprIntrinsicCall( testCounts );
	checks::testExprLess( testCounts );
	checks::testExprLessEqual( testCounts );
	checks::testExprLiteral( testCounts );
	checks::testExprLogAnd( testCounts );
	checks::testExprLogNot( testCounts );
	checks::testExprLogOr( testCounts );
	checks::testExprLShift( testCounts );
	checks::testExprLShiftAssign( testCounts );
	checks::testExprMbrSelect( testCounts );
	checks::testExprMinus( testCounts );
	checks::testExprMinusAssign( testCounts );
	checks::testExprModulo( testCounts );
	checks::testExprModuloAssign( testCounts );
	checks::testExprNotEqual( testCounts );
	checks::testExprOrAssign( testCounts );
	checks::testExprPostDecrement( testCounts );
	checks::testExprPostIncrement( testCounts );
	checks::testExprPreDecrement( testCounts );
	checks::testExprPreIncrement( testCounts );
	checks::testExprQuestion( testCounts );
	checks::testExprRShift( testCounts );
	checks::testExprRShiftAssign( testCounts );
	checks::testExprStorageImageAccessCall( testCounts );
	checks::testExprStreamAppend( testCounts );
	checks::testExprSwitchCase( testCounts );
	checks::testExprSwitchTest( testCounts );
	checks::testExprSwizzle( testCounts );
	checks::testExprTimes( testCounts );
	checks::testExprTimesAssign( testCounts );
	checks::testExprUnaryMinus( testCounts );
	checks::testExprUnaryPlus( testCounts );
	checks::testExprXorAssign( testCounts );
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTExpressions )
