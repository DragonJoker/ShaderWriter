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
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

#pragma warning( disable:4146 )

namespace checks
{
	using namespace ast::expr;

	static std::string getExprName( Expr const & expr )
	{
		return toString( expr.getKind() );
	}

	static bool isBinary( Expr const & expr )
	{
		return expr.getKind() == ast::expr::Kind::eAdd
			|| expr.getKind() == ast::expr::Kind::eAlias
			|| expr.getKind() == ast::expr::Kind::eArrayAccess
			|| expr.getKind() == ast::expr::Kind::eAssign
			|| expr.getKind() == ast::expr::Kind::eBitAnd
			|| expr.getKind() == ast::expr::Kind::eBitOr
			|| expr.getKind() == ast::expr::Kind::eBitXor
			|| expr.getKind() == ast::expr::Kind::eComma
			|| expr.getKind() == ast::expr::Kind::eDivide
			|| expr.getKind() == ast::expr::Kind::eEqual
			|| expr.getKind() == ast::expr::Kind::eGreater
			|| expr.getKind() == ast::expr::Kind::eGreaterEqual
			|| expr.getKind() == ast::expr::Kind::eLess
			|| expr.getKind() == ast::expr::Kind::eLessEqual
			|| expr.getKind() == ast::expr::Kind::eLogAnd
			|| expr.getKind() == ast::expr::Kind::eLogOr
			|| expr.getKind() == ast::expr::Kind::eLShift
			|| expr.getKind() == ast::expr::Kind::eMinus
			|| expr.getKind() == ast::expr::Kind::eModulo
			|| expr.getKind() == ast::expr::Kind::eNotEqual
			|| expr.getKind() == ast::expr::Kind::eRShift
			|| expr.getKind() == ast::expr::Kind::eTimes
			|| expr.getKind() == ast::expr::Kind::eAddAssign
			|| expr.getKind() == ast::expr::Kind::eMinusAssign
			|| expr.getKind() == ast::expr::Kind::eTimesAssign
			|| expr.getKind() == ast::expr::Kind::eDivideAssign
			|| expr.getKind() == ast::expr::Kind::eModuloAssign
			|| expr.getKind() == ast::expr::Kind::eLShiftAssign
			|| expr.getKind() == ast::expr::Kind::eRShiftAssign
			|| expr.getKind() == ast::expr::Kind::eAndAssign
			|| expr.getKind() == ast::expr::Kind::eOrAssign
			|| expr.getKind() == ast::expr::Kind::eXorAssign;
	}

	static bool isUnary( Expr const & expr )
	{
		return expr.getKind() == ast::expr::Kind::eBitNot
			|| expr.getKind() == ast::expr::Kind::eCast
			|| expr.getKind() == ast::expr::Kind::eCopy
			|| expr.getKind() == ast::expr::Kind::eLogNot
			|| expr.getKind() == ast::expr::Kind::ePreIncrement
			|| expr.getKind() == ast::expr::Kind::ePreDecrement
			|| expr.getKind() == ast::expr::Kind::ePostIncrement
			|| expr.getKind() == ast::expr::Kind::ePostDecrement
			|| expr.getKind() == ast::expr::Kind::eStreamAppend
			|| expr.getKind() == ast::expr::Kind::eUnaryMinus
			|| expr.getKind() == ast::expr::Kind::eUnaryPlus;
	}

	static bool isPostSsaValid( Expr const & expr )
	{
		return expr.getKind() != ast::expr::Kind::eInit
			&& expr.getKind() != ast::expr::Kind::ePreIncrement
			&& expr.getKind() != ast::expr::Kind::ePreDecrement
			&& expr.getKind() != ast::expr::Kind::ePostIncrement
			&& expr.getKind() != ast::expr::Kind::ePostDecrement
			&& expr.getKind() != ast::expr::Kind::eAddAssign
			&& expr.getKind() != ast::expr::Kind::eMinusAssign
			&& expr.getKind() != ast::expr::Kind::eTimesAssign
			&& expr.getKind() != ast::expr::Kind::eDivideAssign
			&& expr.getKind() != ast::expr::Kind::eModuloAssign
			&& expr.getKind() != ast::expr::Kind::eLShiftAssign
			&& expr.getKind() != ast::expr::Kind::eRShiftAssign
			&& expr.getKind() != ast::expr::Kind::eAndAssign
			&& expr.getKind() != ast::expr::Kind::eOrAssign
			&& expr.getKind() != ast::expr::Kind::eXorAssign;
	}

	static ast::stmt::ContainerPtr makeContainer( ast::stmt::StmtCache & stmtCache
		, Expr const & expr )
	{
		auto container = stmtCache.makeContainer();
		container->addStmt( stmtCache.makeSimple( expr.clone() ) );
		return container;
	}

	static void checkExprDependant( test::TestCounts & testCounts
		, Expr const & expr
		, std::string const & function
		, int line )
	{
		auto & exprCache = expr.getExprCache();
		auto & typesCache = expr.getTypesCache();

		testCounts << "Expr" << getExprName( expr ) << ": " << ast::debug::displayExpression( expr ) << test::endl;

		if ( isPostSsaValid( expr ) )
		{
			subCheckNoThrow( function, line, ast::resolveConstants( exprCache, expr ) );
		}

		auto clone = expr.clone();
		clone->updateFlag( ast::expr::Flag::eNonUniform );

		if ( isUnary( *clone ) )
		{
			if ( auto operand = static_cast< ast::expr::Unary & >( *clone ).getOperand() )
			{
				const_cast< ast::expr::Expr * >( operand )->updateFlag( ast::expr::Flag::eNonUniform );
			}
		}
		else if ( isBinary( *clone ) )
		{
			auto & binary = static_cast< ast::expr::Binary & >( *clone );

			if ( auto lhs = binary.getLHS() )
			{
				const_cast< ast::expr::Expr * >( lhs )->updateFlag( ast::expr::Flag::eNonUniform );
			}
			if ( auto rhs = binary.getRHS() )
			{
				const_cast< ast::expr::Expr * >( rhs )->updateFlag( ast::expr::Flag::eNonUniform );
			}
		}

		testCounts << "NonUniform Clone: " << ast::debug::displayExpression( *clone ) << test::endl;

		if ( isPostSsaValid( expr ) )
		{
			subCheckNoThrow( function, line, ast::resolveConstants( exprCache, *clone ) );
		}

		subCheckNoThrow( function, line, ast::listCommaIdentifiers( expr ) );
		subCheckNoThrow( function, line, ast::listIdentifiers( expr ) );
		subCheckNoThrow( function, line, ast::listIdentifiers( expr, ast::type::Kind::eInt32 ) );
		subCheckNoThrow( function, line, ast::listIdentifiers( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) );
		subCheckNoThrow( function, line, ast::listIdentifiers( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) );
		subCheckNoThrow( function, line, ast::findIdentifier( expr ) );
		subCheckNoThrow( function, line, ast::findIdentifier( expr, ast::type::Kind::eInt32 ) );
		subCheckNoThrow( function, line, ast::findIdentifier( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) );
		subCheckNoThrow( function, line, ast::findIdentifier( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) );
		testCounts << "Find default params: [" << ast::findName( expr ) << "]" << test::endl;
		testCounts << "Find typed: [" << ast::findName( expr, ast::type::Kind::eInt32 ) << "]" << test::endl;
		testCounts << "Find flagged: [" << ast::findName( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) << "]" << test::endl;
		testCounts << "Find typed and flagged: [" << ast::findName( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) << "]" << test::endl;

		if ( expr.getKind() != ast::expr::Kind::eAlias )
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			{
				ast::SSAData data{ testCounts.nextVarId, 0u };
				auto container = makeContainer( stmtCache, expr );
				subCheckNoThrow( function, line, container = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, false ) );
				subCheckNoThrow( function, line, container = ast::resolveConstants( stmtCache, exprCache, typesCache, *container ) );
				subCheckNoThrow( function, line, container = ast::simplify( stmtCache, exprCache, typesCache, *container ) );
				subCheckNoThrow( function, line, container = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) );
			}
			{
				ast::SSAData data{ testCounts.nextVarId, 0u };
				auto container = makeContainer( stmtCache, expr );
				subCheckNoThrow( function, line, container = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, true ) );
				subCheckNoThrow( function, line, container = ast::resolveConstants( stmtCache, exprCache, typesCache, *container ) );
				subCheckNoThrow( function, line, container = ast::simplify( stmtCache, exprCache, typesCache, *container ) );
				subCheckNoThrow( function, line, container = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) );
			}
		}
	}

	template< ast::expr::LiteralType LiteralT
		, ast::expr::LiteralType LiteralU
		, typename ValueT >
	static void testLiteral( test::TestCounts & testCounts
		, Literal const & expr
		, ValueT value
		, char const * const function
		, int line )
	{
		static ast::type::Kind constexpr TypeT = ast::expr::literalValueKind< LiteralT >;
		static ast::type::Kind constexpr TypeU = ast::expr::literalValueKind< LiteralU >;
		using ValueU = LiteralValueType< LiteralU >;

		subRequire( function, line, expr.getKind() == Kind::eLiteral )
		subCheckEqual( function, line, expr.getType()->getKind(), TypeT )
		subCheckEqual( function, line, expr.getLiteralType(), LiteralT )
		subCheckEqual( function, line, getLiteralValue< LiteralT >( expr ), value )
		subCheckEqual( function, line, expr.getValue< LiteralT >(), value )
		checkExprDependant( testCounts, expr, function, line );
		{
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eBool >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eInt8 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eInt16 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eInt32 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eInt64 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eUInt8 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eUInt16 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eUInt32 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eUInt64 >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eFloat >( getLiteralValue< LiteralT >( expr ) ) )
			subCheckNoThrow( function, line, ast::expr::details::convert< LiteralType::eDouble >( getLiteralValue< LiteralT >( expr ) ) )
		}
		{
			Literal result{ expr.getExprCache(), expr };
			subRequire( function, line, result.getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result.getType()->getKind(), TypeT )
			subCheckEqual( function, line, result.getLiteralType(), LiteralT )
			subCheckEqual( function, line, result.getValue< LiteralT >(), value )
			subCheckEqual( function, line, getLiteralValue< LiteralT >( result ), value )
		}
		{
			auto result = expr.castTo( LiteralU );
			subRequire( function, line, result->getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result->getType()->getKind(), TypeU )
			subCheckEqual( function, line, result->getLiteralType(), LiteralU )
			subCheckEqual( function, line, result->getValue< LiteralU >(), ValueU( value ) )
			subCheckEqual( function, line, getLiteralValue< LiteralU >( *result ), ValueU( value ) )
		}
		{
			auto result = !expr;
			subRequire( function, line, result->getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
			subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
			subCheckEqual( function, line, result->getValue< LiteralType::eBool >(), false )
			subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), false )
		}
		{
			auto result = preInc( expr );
			subRequire( function, line, result->getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result->getType()->getKind(), TypeT )
			subCheckEqual( function, line, result->getLiteralType(), LiteralT )
			subCheckEqual( function, line, result->getValue< LiteralT >(), ValueT( value + 1 ) )
			subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value + 1 ) )
		}
		{
			auto result = preDec( expr );
			subRequire( function, line, result->getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result->getType()->getKind(), TypeT )
			subCheckEqual( function, line, result->getLiteralType(), LiteralT )
			subCheckEqual( function, line, result->getValue< LiteralT >(), ValueT( value - 1 ) )
			subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value - 1 ) )
		}
		if ( auto prhs = expr.getExprCache().makeLiteral( expr.getTypesCache(), value ) )
		{
			auto & rhs = *prhs;
			{
				auto result = expr + rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), value + value )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), value + value )
			}
			{
				auto result = expr - rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT{} )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT{} )
			}
			{
				auto result = expr * rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), value * value )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), value * value )
			}
			{
				auto result = expr / rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT{ 1 } )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT{ 1 } )
			}
			{
				auto result = expr < rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), false )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), false )
			}
			{
				auto result = expr > rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), false )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), false )
			}
			{
				auto result = expr <= rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), true )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), true )
			}
			{
				auto result = expr >= rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), true )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), true )
			}
			{
				auto result = expr == rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), true )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), true )
			}
			{
				auto result = expr != rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), false )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), false )
			}
			{
				auto result = expr && rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), true )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), true )
			}
			{
				auto result = expr || rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), ast::type::Kind::eBoolean )
				subCheckEqual( function, line, result->getLiteralType(), LiteralType::eBool )
				subCheckEqual( function, line, result->template getValue< LiteralType::eBool >(), true )
				subCheckEqual( function, line, getLiteralValue< LiteralType::eBool >( *result ), true )
			}
		}
	}

	template< ast::expr::LiteralType LiteralT
		, ast::expr::LiteralType LiteralU
		, typename ValueT >
	static void testExprIntegerLiteral( test::TestCounts & testCounts
		, Literal const & expr
		, ValueT value
		, char const * const function
		, int line )
	{
		static ast::type::Kind constexpr TypeT = ast::expr::literalValueKind< LiteralT >;

		testLiteral< LiteralT, LiteralU >( testCounts, expr, value, function, line );
		{
			auto result = ~expr;
			subRequire( function, line, result->getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result->getType()->getKind(), TypeT )
			subCheckEqual( function, line, result->getLiteralType(), LiteralT )
			subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( ~value ) )
			subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( ~value ) )
		}
		if ( auto prhs = expr.getExprCache().makeLiteral( expr.getTypesCache(), ValueT{ 1 } ) )
		{
			auto & rhs = *prhs;
			{
				auto result = expr << rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value << 1 ) )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value << 1 ) )
			}
			{
				auto result = expr >> rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value >> 1 ) )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value >> 1 ) )
			}
		}
		if ( auto prhs = expr.getExprCache().makeLiteral( expr.getTypesCache(), value ) )
		{
			auto & rhs = *prhs;
			{
				auto result = expr % rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT{} )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT{} )
			}
			{
				auto result = expr | rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), value )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), value )
			}
			{
				auto result = expr ^ rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value ^ value ) )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value ^ value ) )
			}
			{
				auto result = expr & rhs;
				subRequire( function, line, result->getKind() == Kind::eLiteral )
				subCheckEqual( function, line, result->getType()->getKind(), TypeT )
				subCheckEqual( function, line, result->getLiteralType(), LiteralT )
				subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( value & value ) )
				subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( value & value ) )
			}
		}
	}

	template< ast::expr::LiteralType LiteralT
		, ast::expr::LiteralType LiteralU >
	static void testExprFloatLiteral( test::TestCounts & testCounts
		, char const * const function
		, int line )
	{
		static ast::type::Kind constexpr TypeT = ast::expr::literalValueKind< LiteralT >;
		using ValueT = LiteralValueType< LiteralT >;

		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto expr = exprCache.makeLiteral( typesCache, ValueT{ 10.0 } );
		testLiteral< LiteralT, LiteralU >( testCounts, *expr, ValueT{ 10.0 }, function, line );
		{
			auto result = -( *expr );
			subRequire( function, line, result->getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result->getType()->getKind(), TypeT )
			subCheckEqual( function, line, result->getLiteralType(), LiteralT )
			subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( -10.0 ) )
			subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( -10.0 ) )
		}
		if ( auto prhs = exprCache.makeLiteral( typesCache, ValueT( 1.0 ) ) )
		{
			auto & rhs = *prhs;
			subCheckThrow( function, line, ( *expr ) << rhs )
			subCheckThrow( function, line, ( *expr ) >> rhs )
		}
		if ( auto prhs = exprCache.makeLiteral( typesCache, ValueT{ 10.0 } ) )
		{
			auto & rhs = *prhs;
			subCheckThrow( function, line, ( *expr ) % rhs )
			subCheckThrow( function, line, ( *expr ) | rhs )
			subCheckThrow( function, line, ( *expr ) ^ rhs )
			subCheckThrow( function, line, ( *expr ) & rhs )
		}
		subCheckThrow( function, line, ~( *expr ) )
	}

	template< ast::expr::LiteralType LiteralT
		, ast::expr::LiteralType LiteralU >
	static void testExprSignedIntegerLiteral( test::TestCounts & testCounts
		, char const * const function
		, int line )
	{
		static ast::type::Kind constexpr TypeT = ast::expr::literalValueKind< LiteralT >;
		using ValueT = LiteralValueType< LiteralT >;

		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto expr = exprCache.makeLiteral( typesCache, ValueT{ 10LL } );
		testExprIntegerLiteral< LiteralT, LiteralU >( testCounts, *expr, ValueT{ 10LL }, function, line );
		{
			auto result = -( *expr );
			subRequire( function, line, result->getKind() == Kind::eLiteral )
			subCheckEqual( function, line, result->getType()->getKind(), TypeT )
			subCheckEqual( function, line, result->getLiteralType(), LiteralT )
			subCheckEqual( function, line, result->template getValue< LiteralT >(), ValueT( -10LL ) )
			subCheckEqual( function, line, getLiteralValue< LiteralT >( *result ), ValueT( -10LL ) )
		}
	}

	template< ast::expr::LiteralType LiteralT
		, ast::expr::LiteralType LiteralU >
	static void testExprUnsignedIntegerLiteral( test::TestCounts & testCounts
		, char const * const function
		, int line )
	{
		using ValueT = LiteralValueType< LiteralT >;

		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto expr = exprCache.makeLiteral( typesCache, ValueT{ 10ULL } );
		testExprIntegerLiteral< LiteralT, LiteralU >( testCounts, *expr, ValueT{ 10ULL }, function, line );
		subCheckThrow( function, line, -( *expr ) )
	}

	static void testExprLiteral( test::TestCounts & testCounts )
	{
		testBegin( "testExprLiteral" );
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
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto expr = exprCache.makeLiteral( typesCache, false );

			require( expr->getKind() == Kind::eLiteral )
			checkEqual( expr->getType()->getKind(), ast::type::Kind::eBoolean )
			checkEqual( expr->getLiteralType(), LiteralType::eBool )
			checkEqual( expr->getValue< LiteralType::eBool >(), false )
			checkEqual( getLiteralValue< LiteralType::eBool >( *expr ), false )
			checkExprDependant( testCounts, *expr, "testExprLiteral", __LINE__ );
			{
				checkNoThrow( ast::expr::details::convert< LiteralType::eBool >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eInt8 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eInt16 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eInt32 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eInt64 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eUInt8 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eUInt16 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eUInt32 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eUInt64 >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eFloat >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
				checkNoThrow( ast::expr::details::convert< LiteralType::eDouble >( getLiteralValue< LiteralType::eBool >( *expr ) ) )
			}
			{
				auto result = expr->castTo( LiteralType::eUInt8 );
				require( result->getKind() == Kind::eLiteral )
				checkEqual( result->getType()->getKind(), ast::type::Kind::eUInt8 )
				checkEqual( result->getLiteralType(), LiteralType::eUInt8 )
				checkEqual( result->getValue< LiteralType::eUInt8 >(), uint8_t{} )
				checkEqual( getLiteralValue< LiteralType::eUInt8 >( *result ), uint8_t{} )

				result = result->castTo( LiteralType::eBool );
				require( result->getKind() == Kind::eLiteral )
				checkEqual( result->getType()->getKind(), ast::type::Kind::eBoolean )
				checkEqual( result->getLiteralType(), LiteralType::eBool )
				checkEqual( result->getValue< LiteralType::eBool >(), false )
				checkEqual( getLiteralValue< LiteralType::eBool >( *result ), false )
			}
			{
				auto result = ~( *expr );
				require( result->getKind() == Kind::eLiteral )
				checkEqual( result->getType()->getKind(), ast::type::Kind::eBoolean )
				checkEqual( result->getLiteralType(), LiteralType::eBool )
				checkEqual( result->getValue< LiteralType::eBool >(), true )
				checkEqual( getLiteralValue< LiteralType::eBool >( *result ), true )
			}
			{
				auto result = !( *expr );
				require( result->getKind() == Kind::eLiteral )
				checkEqual( result->getType()->getKind(), ast::type::Kind::eBoolean )
				checkEqual( result->getLiteralType(), LiteralType::eBool )
				checkEqual( result->getValue< LiteralType::eBool >(), true )
				checkEqual( getLiteralValue< LiteralType::eBool >( *result ), true )
			}
			if ( auto prhs = exprCache.makeLiteral( typesCache, true ) )
			{
				auto & rhs = *prhs;
				checkThrow( ( *expr ) << rhs )
				checkThrow( ( *expr ) >> rhs )
			}
			if ( auto prhs = exprCache.makeLiteral( typesCache, false ) )
			{
				auto & rhs = *prhs;
				{
					auto result = ( *expr ) == rhs;
					require( result->getKind() == Kind::eLiteral )
					checkEqual( result->getType()->getKind(), ast::type::Kind::eBoolean )
					checkEqual( result->getLiteralType(), LiteralType::eBool )
					checkEqual( result->getValue< LiteralType::eBool >(), true )
					checkEqual( getLiteralValue< LiteralType::eBool >( *result ), true )
				}
				{
					auto result = ( *expr ) != rhs;
					require( result->getKind() == Kind::eLiteral )
					checkEqual( result->getType()->getKind(), ast::type::Kind::eBoolean )
					checkEqual( result->getLiteralType(), LiteralType::eBool )
					checkEqual( result->getValue< LiteralType::eBool >(), false )
					checkEqual( getLiteralValue< LiteralType::eBool >( *result ), false )
				}
				{
					auto result = ( *expr ) && rhs;
					require( result->getKind() == Kind::eLiteral )
					checkEqual( result->getType()->getKind(), ast::type::Kind::eBoolean )
					checkEqual( result->getLiteralType(), LiteralType::eBool )
					checkEqual( result->getValue< LiteralType::eBool >(), false )
					checkEqual( getLiteralValue< LiteralType::eBool >( *result ), false )
				}
				{
					auto result = ( *expr ) || rhs;
					require( result->getKind() == Kind::eLiteral )
					checkEqual( result->getType()->getKind(), ast::type::Kind::eBoolean )
					checkEqual( result->getLiteralType(), LiteralType::eBool )
					checkEqual( result->getValue< LiteralType::eBool >(), false )
					checkEqual( getLiteralValue< LiteralType::eBool >( *result ), false )
				}
				checkThrow( ( *expr ) + rhs )
				checkThrow( ( *expr ) - rhs )
				checkThrow( ( *expr ) * rhs )
				checkThrow( ( *expr ) / rhs )
				checkThrow( ( *expr ) % rhs )
			}
			checkThrow( -( *expr ) )
			checkThrow( preDec( *expr ) )
			checkThrow( preInc( *expr ) )
		}
		testExprFloatLiteral< LiteralType::eFloat, LiteralType::eDouble >( testCounts, "testExprLiteral", __LINE__ );
		testExprFloatLiteral< LiteralType::eDouble, LiteralType::eFloat >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< LiteralType::eInt8, LiteralType::eUInt8 >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< LiteralType::eInt16, LiteralType::eUInt16 >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< LiteralType::eInt32, LiteralType::eUInt32 >( testCounts, "testExprLiteral", __LINE__ );
		testExprSignedIntegerLiteral< LiteralType::eInt64, LiteralType::eUInt64 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< LiteralType::eUInt8, LiteralType::eInt8 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< LiteralType::eUInt16, LiteralType::eInt16 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< LiteralType::eUInt32, LiteralType::eInt32 >( testCounts, "testExprLiteral", __LINE__ );
		testExprUnsignedIntegerLiteral< LiteralType::eUInt64, LiteralType::eInt64 >( testCounts, "testExprLiteral", __LINE__ );
		testEnd()
	}
	
	static void testExprIdentifier( test::TestCounts & testCounts )
	{
		testBegin( "testExprIdentifier" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto expr = exprCache.makeIdentifier( typesCache
			, ast::var::makeVariable( testCounts.getNextVarId()
				, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var0" )
				, typesCache.getInt32()
				, "var1" ) );

		require( expr->getKind() == Kind::eIdentifier )
		require( expr->getFlags() == 0u )
		check( !expr->isDummy() )
		expr->updateFlag( ast::expr::Flag::eDummy );
		check( expr->isDummy() )
		expr->updateFlag( ast::expr::Flag::eDummy, false );
		check( !expr->isDummy() )
		check( !expr->isSpecialisationConstant() )
		expr->updateFlag( ast::expr::Flag::eSpecialisationConstant );
		check( expr->isSpecialisationConstant() )
		check( !expr->isConstant() )
		expr->updateFlag( ast::expr::Flag::eConstant );
		check( expr->isConstant() )
		check( !expr->isImplicit() )
		expr->updateFlag( ast::expr::Flag::eImplicit );
		check( expr->isImplicit() )
		check( !expr->isNonUniform() )
		expr->updateFlag( ast::expr::Flag::eNonUniform );
		check( expr->isNonUniform() )
		expr->updateFlag( ast::expr::Flag::eNonUniform, false );
		check( !expr->isNonUniform() )
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 )
		check( expr->getVariable()->getName() == "var1" )
		check( expr->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		checkExprDependant( testCounts, *expr, "testExprIdentifier", __LINE__ );
		checkThrow( getLiteralValue< ast::expr::LiteralType::eInt32 >( *expr ) )
		{
			uint32_t flags{};
			flags = flags | ast::expr::Flag::eDummy;
			check( ( flags & uint32_t( ast::expr::Flag::eDummy ) ) == uint32_t( ast::expr::Flag::eDummy ) )
			flags = ast::expr::Flag::eConstant | flags;
			check( ( flags & uint32_t( ast::expr::Flag::eConstant ) ) == uint32_t( ast::expr::Flag::eConstant ) )
			flags = ast::expr::Flag::eSpecialisationConstant | ast::expr::Flag::eImplicit;
			check( ( flags & uint32_t( ast::expr::Flag::eSpecialisationConstant ) ) == uint32_t( ast::expr::Flag::eSpecialisationConstant ) )
			check( ( flags & uint32_t( ast::expr::Flag::eImplicit ) ) == uint32_t( ast::expr::Flag::eImplicit ) )
		}
		{
			ast::expr::Expr dummy{ exprCache, 0u, typesCache, typesCache.getVoid(), ast::expr::Kind::eAlias };
			dummy.accept( nullptr );
		}
		testEnd()
	}

	static void testExprAdd( test::TestCounts & testCounts )
	{
		testBegin( "testExprAdd" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeAdd( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eAdd );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
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
		testEnd()
	}

	static void testExprMinus( test::TestCounts & testCounts )
	{
		testBegin( "testExprMinus" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeMinus( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eMinus );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprMinus", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20 );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeMinus( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprMinus", __LINE__ );
		}
		testEnd()
	}

	static void testExprTimes( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimes" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeTimes( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eTimes );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20 );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeTimes( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		testEnd()
	}

	static void testExprDivide( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimes" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeDivide( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eDivide );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20 );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeDivide( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprTimes", __LINE__ );
		}
		testEnd()
	}

	static void testExprBitAnd( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitAnd" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeBitAnd( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eBitAnd );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprBitAnd", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeBitAnd( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprBitAnd", __LINE__ );
		}
		testEnd()
	}

	static void testExprBitNot( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitNot" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
			auto expr = exprCache.makeBitNot( std::move( op ) );

			check( expr->getKind() == Kind::eBitNot );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getOperand()->getKind() == Kind::eIdentifier );
			check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
			check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprBitNot", __LINE__ );
		}
		{
			auto op = exprCache.makeLiteral( typesCache, 20u );
			auto expr = exprCache.makeBitNot( std::move( op ) );
			checkExprDependant( testCounts, *expr, "testExprBitNot", __LINE__ );
		}
		testEnd()
	}

	static void testExprBitOr( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitOr" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeBitOr( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eBitOr );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprBitOr", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeBitOr( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprBitOr", __LINE__ );
		}
		testEnd()
	}

	static void testExprBitXor( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitXor" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeBitXor( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eBitXor );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprBitXor", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeBitXor( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprBitXor", __LINE__ );
		}
		testEnd()
	}

	static void testExprLogAnd( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogAnd" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLogAnd( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eLogAnd );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLogAnd", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeLogAnd( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLogAnd", __LINE__ );
		}
		testEnd()
	}

	static void testExprLogNot( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogNot" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
			auto expr = exprCache.makeLogNot( typesCache, std::move( op ) );

			check( expr->getKind() == Kind::eLogNot );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getOperand()->getKind() == Kind::eIdentifier );
			check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
			check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprLogNot", __LINE__ );
		}
		{
			auto op = exprCache.makeLiteral( typesCache, 20u );
			auto expr = exprCache.makeLogNot( typesCache, std::move( op ) );
			checkExprDependant( testCounts, *expr, "testExprLogNot", __LINE__ );
		}
		testEnd()
	}

	static void testExprLogOr( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogOr" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLogOr( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eLogOr );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLogOr", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeLogOr( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLogOr", __LINE__ );
		}
		testEnd()
	}

	static void testExprModulo( test::TestCounts & testCounts )
	{
		testBegin( "testExprModulo" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeModulo( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eModulo );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprModulo", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 10u );
			auto expr = exprCache.makeModulo( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprModulo", __LINE__ );
		}
		testEnd()
	}

	static void testExprLShift( test::TestCounts & testCounts )
	{
		testBegin( "testExprLShift" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLShift( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eLShift );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLShift", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeLShift( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLShift", __LINE__ );
		}
		testEnd()
	}

	static void testExprRShift( test::TestCounts & testCounts )
	{
		testBegin( "testExprRShift" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeRShift( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eRShift );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprRShift", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeRShift( typesCache.getUInt32(), std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprRShift", __LINE__ );
		}
		testEnd()
	}

	static void testExprComma( test::TestCounts & testCounts )
	{
		testBegin( "testExprComma" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeComma( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eComma );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprComma", __LINE__ );

		checkThrow( exprCache.makeComma( nullptr, nullptr ) )
		rhs = exprCache.makeLiteral( typesCache, 10 );
		expr = exprCache.makeComma( nullptr, std::move( rhs ) );
		checkExprDependant( testCounts, *expr, "testExprComma", __LINE__ );
		lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		expr = exprCache.makeComma( std::move( lhs ), nullptr );
		checkExprDependant( testCounts, *expr, "testExprComma", __LINE__ );
		testEnd()
	}

	static void testExprArrayAccess( test::TestCounts & testCounts )
	{
		testBegin( "testExprArrayAccess" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32() ), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeArrayAccess( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eArrayAccess );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eArray );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eArray );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprArrayAccess", __LINE__ );
		testEnd()
	}

	static void testExprAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprAssign", __LINE__ );
		testEnd()
	}

	static void testExprAddAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAddAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAddAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eAddAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprAddAssign", __LINE__ );
		checkThrow( exprCache.makeAddAssign( typesCache.getInt32(), nullptr, nullptr ) );
		testEnd()
	}

	static void testExprDivideAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprDivideAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeDivideAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eDivideAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprDivideAssign", __LINE__ );
		testEnd()
	}

	static void testExprMinusAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprMinusAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeMinusAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eMinusAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprMinusAssign", __LINE__ );
		testEnd()
	}

	static void testExprTimesAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimesAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeTimesAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eTimesAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprTimesAssign", __LINE__ );
		testEnd()
	}

	static void testExprModuloAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprModuloAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeModuloAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eModuloAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprModuloAssign", __LINE__ );
		testEnd()
	}

	static void testExprLShiftAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprLShiftAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLShiftAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eLShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprLShiftAssign", __LINE__ );
		testEnd()
	}

	static void testExprRShiftAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprRShiftAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeRShiftAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eRShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprRShiftAssign", __LINE__ );
		testEnd()
	}

	static void testExprAndAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAndAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAndAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eAndAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprAndAssign", __LINE__ );
		testEnd()
	}

	static void testExprOrAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprOrAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeOrAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eOrAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprOrAssign", __LINE__ );
		testEnd()
	}

	static void testExprXorAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprXorAssign" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeXorAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == Kind::eXorAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprXorAssign", __LINE__ );
		testEnd()
	}

	static void testExprEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprEqual" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eEqual );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprEqual", __LINE__ );
		}
		testEnd()
	}

	static void testExprGreater( test::TestCounts & testCounts )
	{
		testBegin( "testExprGreater" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeGreater( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eGreater );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprGreater", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeGreater( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprGreater", __LINE__ );
		}
		testEnd()
	}

	static void testExprGreaterEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprGreaterEqual" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeGreaterEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eGreaterEqual );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprGreaterEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeGreaterEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprGreaterEqual", __LINE__ );
		}
		testEnd()
	}

	static void testExprLess( test::TestCounts & testCounts )
	{
		testBegin( "testExprLess" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLess( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eLess );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLess", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeLess( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLess", __LINE__ );
		}
		testEnd()
	}

	static void testExprLessEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprLessEqual" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeLessEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eLessEqual );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprLessEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeLessEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprLessEqual", __LINE__ );
		}
		testEnd()
	}

	static void testExprNotEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprNotEqual" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeNotEqual( typesCache, std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eNotEqual );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprNotEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto expr = exprCache.makeNotEqual( typesCache.getBool(), std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == Kind::eNotEqual );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

			require( expr->getLHS()->getKind() == Kind::eIdentifier );
			check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
			check( static_cast< Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

			require( expr->getRHS()->getKind() == Kind::eLiteral );
			check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getRHS() ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getRHS() ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprNotEqual", __LINE__ );
		}
		{
			auto lhs = exprCache.makeLiteral( typesCache, 20u );
			auto rhs = exprCache.makeLiteral( typesCache, 3u );
			auto expr = exprCache.makeNotEqual( typesCache, std::move( lhs ), std::move( rhs ) );
			checkExprDependant( testCounts, *expr, "testExprNotEqual", __LINE__ );
		}
		testEnd()
	}

	static void testExprPostDecrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPostDecrement" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePostDecrement( std::move( op ) );

		check( expr->getKind() == Kind::ePostDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPostDecrement", __LINE__ );
		testEnd()
	}

	static void testExprPostIncrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPostIncrement" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePostIncrement( std::move( op ) );

		check( expr->getKind() == Kind::ePostIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPostIncrement", __LINE__ );
		testEnd()
	}

	static void testExprPreDecrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPreDecrement" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePreDecrement( std::move( op ) );

		check( expr->getKind() == Kind::ePreDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPreDecrement", __LINE__ );
		testEnd()
	}

	static void testExprPreIncrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPreIncrement" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePreIncrement( std::move( op ) );

		check( expr->getKind() == Kind::ePreIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprPreIncrement", __LINE__ );
		testEnd()
	}

	static void testExprUnaryMinus( test::TestCounts & testCounts )
	{
		testBegin( "testExprUnaryMinus" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeUnaryMinus( std::move( op ) );

		check( expr->getKind() == Kind::eUnaryMinus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprUnaryMinus", __LINE__ );

		checkThrow( ast::expr::UnaryMinus( exprCache, typesCache.getInt32(), nullptr ) )
		testEnd()
	}

	static void testExprUnaryPlus( test::TestCounts & testCounts )
	{
		testBegin( "testExprUnaryPlus" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeUnaryPlus( std::move( op ) );

		check( expr->getKind() == Kind::eUnaryPlus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprUnaryPlus", __LINE__ );
		testEnd()
	}

	static void testExprCast( test::TestCounts & testCounts )
	{
		testBegin( "testExprCast" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeCast( typesCache.getFloat(), std::move( op ) );

		check( expr->getKind() == Kind::eCast );
		check( expr->getType()->getKind() == ast::type::Kind::eFloat );

		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		checkExprDependant( testCounts, *expr, "testExprCast", __LINE__ );
		testEnd()
	}

	static void testExprCompositeConstruct( test::TestCounts & testCounts )
	{
		testBegin( "testExprCompositeConstruct" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		for ( uint32_t type = 0u; type < uint32_t( CompositeType::eCombine ); ++type )
		{
			ExprList args;
			args.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c1" ) ) );
			args.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c2" ) ) );
			args.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c2" ) ) );
			args.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c2" ) ) );
			auto expr = exprCache.makeCompositeConstruct( CompositeType( type )
				, ast::type::Kind::eFloat
				, std::move( args ) );

			check( expr->getKind() == Kind::eCompositeConstruct )
			check( expr->getComposite() == CompositeType( type ) )
			check( expr->getComponent() == ast::type::Kind::eFloat )

			check( expr->getArgList().size() == 4u )
			checkExprDependant( testCounts, *expr, "testExprCompositeConstruct", __LINE__ );
		}
		{
			auto expr = exprCache.makeCompositeConstruct( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getSampledImage( ast::type::ImageConfiguration{} ), "img" ) )
				, exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getSampler(), "spl" ) ) );

			check( expr->getKind() == Kind::eCompositeConstruct )
			check( expr->getType()->getKind() == ast::type::Kind::eCombinedImage )
			check( expr->getComposite() == CompositeType::eCombine )
			check( expr->getComponent() == ast::type::Kind::eCombinedImage )

			check( expr->getArgList().size() == 2u )
			checkExprDependant( testCounts, *expr, "testExprCompositeConstruct", __LINE__ );
		}
		testEnd()
	}

	static void testExprFnCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprFnCall" );
		{
			ExprList argList;
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto functionType = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );
			check( expr->getInstance() == nullptr );

			check( expr->getArgList().empty() );
			checkExprDependant( testCounts, *expr, "testExprFnCall", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );
			check( expr->getInstance() == nullptr );

			check( expr->getArgList().size() == 1u );

			require( expr->getArgList()[0]->getKind() == Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getArgList()[0] ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getArgList()[0] ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprFnCall", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			argList.emplace_back( exprCache.makeLiteral( typesCache, 1.0f ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p0" ),
					ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p1" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );
			check( expr->getInstance() == nullptr );

			check( expr->getArgList().size() == 2u );

			require( expr->getArgList()[0]->getKind() == Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getArgList()[0] ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getArgList()[0] ).getValue< LiteralType::eInt32 >() == 10 );

			require( expr->getArgList()[1]->getKind() == Kind::eLiteral );
			check( expr->getArgList()[1]->getType()->getKind() == ast::type::Kind::eFloat );
			require( static_cast< Literal const & >( *expr->getArgList()[1] ).getLiteralType() == LiteralType::eFloat );
			check( static_cast< Literal const & >( *expr->getArgList()[1] ).getValue< LiteralType::eFloat >() == 1.0f );
			checkExprDependant( testCounts, *expr, "testExprFnCall", __LINE__ );
		}
		testEnd()
	}

	static void testExprMemberFnCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprMemberFnCall" );
		{
			ExprList argList;
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto functionType = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto funcOwner = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var" ) );
			auto expr = exprCache.makeMemberFnCall( typesCache.getInt32(), std::move( funcName ), std::move( funcOwner ), std::move( argList ) );

			require( expr->getKind() == Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );
			check( expr->getInstance() != nullptr );
			check( expr->getInstance()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( expr->getInstance()->getKind() == ast::expr::Kind::eIdentifier );

			check( expr->getArgList().empty() );
			checkExprDependant( testCounts, *expr, "testExprMemberFnCall", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto funcOwner = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var" ) );
			auto expr = exprCache.makeMemberFnCall( typesCache.getInt32(), std::move( funcName ), std::move( funcOwner ), std::move( argList ) );

			require( expr->getKind() == Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );
			check( expr->getInstance() != nullptr );
			check( expr->getInstance()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( expr->getInstance()->getKind() == ast::expr::Kind::eIdentifier );

			check( expr->getArgList().size() == 1u );

			require( expr->getArgList()[0]->getKind() == Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getArgList()[0] ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getArgList()[0] ).getValue< LiteralType::eInt32 >() == 10 );
			checkExprDependant( testCounts, *expr, "testExprMemberFnCall", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			argList.emplace_back( exprCache.makeLiteral( typesCache, 1.0f ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "p0" ),
					ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p1" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), functionType, "func" ) );
			auto funcOwner = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "var" ) );
			auto expr = exprCache.makeMemberFnCall( typesCache.getInt32(), std::move( funcName ), std::move( funcOwner ), std::move( argList ) );

			require( expr->getKind() == Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );
			check( expr->getInstance() != nullptr );
			check( expr->getInstance()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( expr->getInstance()->getKind() == ast::expr::Kind::eIdentifier );

			check( expr->getArgList().size() == 2u );

			require( expr->getArgList()[0]->getKind() == Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< Literal const & >( *expr->getArgList()[0] ).getLiteralType() == LiteralType::eInt32 );
			check( static_cast< Literal const & >( *expr->getArgList()[0] ).getValue< LiteralType::eInt32 >() == 10 );

			require( expr->getArgList()[1]->getKind() == Kind::eLiteral );
			check( expr->getArgList()[1]->getType()->getKind() == ast::type::Kind::eFloat );
			require( static_cast< Literal const & >( *expr->getArgList()[1] ).getLiteralType() == LiteralType::eFloat );
			check( static_cast< Literal const & >( *expr->getArgList()[1] ).getValue< LiteralType::eFloat >() == 1.0f );
			checkExprDependant( testCounts, *expr, "testExprMemberFnCall", __LINE__ );
		}
		testEnd()
	}

	static void testExprIntrinsicCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprIntrinsicCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( Intrinsic::eCount ); ++intr )
		{
			getName( Intrinsic( intr ) );
		}
		getName( Intrinsic::eCount );
		getName( Intrinsic::eInvalid );
		checkThrow( getName( Intrinsic( uint32_t( Intrinsic::eCount ) + 1u ) ) );
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList argList;
			argList.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" ) ) );
			auto expr = exprCache.makeIntrinsicCall( typesCache.getInt32(), Intrinsic::eAbs1I, std::move( argList ) );

			require( expr->getKind() == Kind::eIntrinsicCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getIntrinsic() == Intrinsic::eAbs1I );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == Kind::eIdentifier );
			check( expr->getArgList().back()->getType()->getKind() == ast::type::Kind::eInt32 );
			checkExprDependant( testCounts, *expr, "testExprIntrinsicCall", __LINE__ );
		}
		testEnd()
	}

	static void testExprStorageImageAccessCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprStorageImageAccessCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( StorageImageAccess::eCount ); ++intr )
		{
			getName( StorageImageAccess( intr ) );
		}
		getName( StorageImageAccess::eCount );
		getName( StorageImageAccess::eInvalid );
		checkThrow( getName( StorageImageAccess( uint32_t( StorageImageAccess::eCount ) + 1u ) ) );
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getImage( config ), "x" ) ) );
			auto expr = exprCache.makeStorageImageAccessCall( typesCache.getInt32(), StorageImageAccess::eImageSize1DI, std::move( argList ) );

			require( expr->getKind() == Kind::eImageAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getImageAccess() == StorageImageAccess::eImageSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == typesCache.getImage( config ) );
			checkExprDependant( testCounts, *expr, "testExprStorageImageAccessCall", __LINE__ );
		}
		testEnd()
	}

	static void testExprCombinedImageAccessCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprCombinedImageAccessCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( CombinedImageAccess::eCount ); ++intr )
		{
			getName( CombinedImageAccess( intr ) );
			isBiasAndOffset( CombinedImageAccess( intr ) );
			isProj( CombinedImageAccess( intr ) );
			isShadow( CombinedImageAccess( intr ) );
			isShadowLodOffset( CombinedImageAccess( intr ) );
		}
		getName( CombinedImageAccess::eCount );
		getName( CombinedImageAccess::eInvalid );
		checkThrow( getName( CombinedImageAccess( uint32_t( CombinedImageAccess::eCount ) + 1u ) ) );
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getCombinedImage( config ), "x" ) ) );
			auto expr = exprCache.makeCombinedImageAccessCall( typesCache.getInt32(), CombinedImageAccess::eTextureSize1DI, std::move( argList ) );

			require( expr->getKind() == Kind::eCombinedImageAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getCombinedImageAccess() == CombinedImageAccess::eTextureSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == typesCache.getCombinedImage( config ) );
			checkExprDependant( testCounts, *expr, "testExprCombinedImageAccessCall", __LINE__ );
		}
		testEnd()
	}

	static void testExprAggrInit( test::TestCounts & testCounts )
	{
		testBegin( "testExprAggrInit" );
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32(), 4u ), "lhs" ) );
			ExprList rhs;
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			require( expr->getKind() == Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt32 );

			require( expr->hasIdentifier() );
			check( expr->getIdentifier().getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getType() ) == ast::type::Kind::eInt32 );
			check( expr->getIdentifier().getVariable()->getName() == "lhs" );
			check( expr->getIdentifier().getVariable()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getVariable()->getType() ) == ast::type::Kind::eInt32 );

			check( expr->getInitialisers().empty() );
			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32(), 4u ), "lhs", ast::var::Flag::eStatic ) );
			ExprList rhs;
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			require( expr->getKind() == Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt32 );

			require( expr->hasIdentifier() );
			check( expr->getIdentifier().getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getType() ) == ast::type::Kind::eInt32 );
			check( expr->getIdentifier().getVariable()->isStatic() );
			check( expr->getIdentifier().getVariable()->getName() == "lhs" );
			check( expr->getIdentifier().getVariable()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getVariable()->getType() ) == ast::type::Kind::eInt32 );

			check( expr->getInitialisers().empty() );
			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32(), 4u ), "lhs" ) );
			ExprList rhs;
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 20 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 30 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 40 ) );
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			require( expr->getKind() == Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt32 );

			require( expr->hasIdentifier() );
			check( expr->getIdentifier().getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getType() ) == ast::type::Kind::eInt32 );
			check( expr->getIdentifier().getVariable()->getName() == "lhs" );
			check( expr->getIdentifier().getVariable()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getVariable()->getType() ) == ast::type::Kind::eInt32 );

			check( expr->getInitialisers().size() == 4u );
			int v = 10;

			for ( auto & init : expr->getInitialisers() )
			{
				check( init->getKind() == Kind::eLiteral );
				check( init->getType()->getKind() == ast::type::Kind::eInt32 );
				check( static_cast< Literal const & >( *init ).getLiteralType() == LiteralType::eInt32 );
				check( static_cast< Literal const & >( *init ).getValue< LiteralType::eInt32 >() == v );
				v += 10;
			}

			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList rhs;
			auto expr = exprCache.makeAggrInit( typesCache.getArray( typesCache.getInt32(), 4u ), std::move( rhs ) );

			require( expr->getKind() == Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt32 );

			require( !expr->hasIdentifier() );

			check( expr->getInitialisers().empty() );
			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		{
			ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ExprList rhs;
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 20 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 30 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 40 ) );
			auto expr = exprCache.makeAggrInit( typesCache.getArray( typesCache.getInt32(), 4u ), std::move( rhs ) );

			require( expr->getKind() == Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt32 );

			require( !expr->hasIdentifier() );

			check( expr->getInitialisers().size() == 4u );
			int v = 10;

			for ( auto & init : expr->getInitialisers() )
			{
				check( init->getKind() == Kind::eLiteral );
				check( init->getType()->getKind() == ast::type::Kind::eInt32 );
				check( static_cast< Literal const & >( *init ).getLiteralType() == LiteralType::eInt32 );
				check( static_cast< Literal const & >( *init ).getValue< LiteralType::eInt32 >() == v );
				v += 10;
			}

			checkExprDependant( testCounts, *expr, "testExprAggrInit", __LINE__ );
		}
		testEnd()
	}

	static void testExprInit( test::TestCounts & testCounts )
	{
		testBegin( "testExprInit" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", ast::var::Flag::eConstant | ast::var::Flag::eStatic ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeInit( std::move( lhs ), std::move( rhs ) );

		require( expr->getKind() == Kind::eInit );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->hasIdentifier() );
		check( expr->getIdentifier().getType()->getKind() == ast::type::Kind::eInt32 );
		check( expr->getIdentifier().getVariable()->getName() == "lhs" );
		check( expr->getIdentifier().getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getInitialiser()->getKind() == Kind::eLiteral );
		check( expr->getInitialiser()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Literal const & >( *expr->getInitialiser() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getInitialiser() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprInit", __LINE__ );
		testEnd()
	}

	static void testExprMbrSelect( test::TestCounts & testCounts )
	{
		testBegin( "testExprMbrSelect" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd140, "outer" );
		type->declMember( "inner", typesCache.getInt32() );
		{
			auto outerVar = ast::var::makeVariable( testCounts.getNextVarId(), type, "outerVar" );
			auto expr = exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, outerVar ), 0u, uint64_t( ast::var::Flag::eShaderInput ) );

			require( expr->getKind() == Kind::eMbrSelect );
			check( expr->getOuterExpr()->getType()->getKind() == ast::type::Kind::eStruct );

			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );
			check( expr->getOuterExpr()->getKind() == Kind::eIdentifier );
			check( static_cast< Identifier const & >( *expr->getOuterExpr() ).getVariable()->getName() == "outerVar" );

			check( expr->getMemberIndex() == 0u );
			check( expr->getMemberFlags() == uint64_t( ast::var::Flag::eShaderInput ) );
			checkExprDependant( testCounts, *expr, "testExprMbrSelect", __LINE__ );
		}
		{
			auto pointer = typesCache.getPointerType( type, ast::type::Storage::eFunction );
			auto outerVar = ast::var::makeVariable( testCounts.getNextVarId(), pointer, "outerVar" );
			auto expr = exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, outerVar ), 0u, uint64_t( ast::var::Flag::eShaderInput ) );

			require( expr->getKind() == Kind::eMbrSelect );
			check( expr->getOuterExpr()->getType()->getKind() == ast::type::Kind::ePointer );

			check( expr->getType()->getKind() == ast::type::Kind::ePointer );
			check( expr->getOuterExpr()->getKind() == Kind::eIdentifier );
			check( static_cast< Identifier const & >( *expr->getOuterExpr() ).getVariable()->getName() == "outerVar" );

			check( expr->getMemberIndex() == 0u );
			check( expr->getMemberFlags() == uint64_t( ast::var::Flag::eShaderInput ) );
			checkExprDependant( testCounts, *expr, "testExprMbrSelect", __LINE__ );
		}
		testEnd()
	}

	static void testExprQuestion( test::TestCounts & testCounts )
	{
		testBegin( "testExprQuestion" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto ctrlExpr = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "ctrl" ) );
		auto trueExpr = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( 2u, typesCache.getInt32(), "lhs" ) );
		auto falseExpr = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeQuestion( typesCache.getInt32(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

		require( expr->getKind() == Kind::eQuestion );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getCtrlExpr()->getKind() == Kind::eIdentifier );
		check( expr->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getName() == "ctrl" );

		require( expr->getTrueExpr()->getKind() == Kind::eIdentifier );
		check( expr->getTrueExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

		require( expr->getFalseExpr()->getKind() == Kind::eLiteral );
		check( expr->getFalseExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Literal const & >( *expr->getFalseExpr() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getFalseExpr() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprQuestion", __LINE__ );
		testEnd()
	}

	static void testExprSwitchCase( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwitchCase" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto label = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeSwitchCase( std::move( label ) );

		require( expr->getKind() == Kind::eSwitchCase );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLabel()->getKind() == Kind::eLiteral );
		check( expr->getLabel()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Literal const & >( *expr->getLabel() ).getLiteralType() == LiteralType::eInt32 );
		check( static_cast< Literal const & >( *expr->getLabel() ).getValue< LiteralType::eInt32 >() == 10 );
		checkExprDependant( testCounts, *expr, "testExprSwitchCase", __LINE__ );
		testEnd()
	}

	static void testExprSwitchTest( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwitchTest" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto expr = exprCache.makeSwitchTest( std::move( value ) );

		require( expr->getKind() == Kind::eSwitchTest );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getValue()->getKind() == Kind::eIdentifier );
		check( expr->getValue()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getValue() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< Identifier const & >( *expr->getValue() ).getVariable()->getName() == "lhs" );
		checkExprDependant( testCounts, *expr, "testExprSwitchTest", __LINE__ );
		testEnd()
	}

	static void testExprCopy( test::TestCounts & testCounts )
	{
		testBegin( "testExprCopy" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "operand" ) );
		auto expr = exprCache.makeCopy( std::move( value ) );

		require( expr->getKind() == Kind::eCopy );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		checkExprDependant( testCounts, *expr, "testExprCopy", __LINE__ );
		testEnd()
	}

	static void testExprAlias( test::TestCounts & testCounts )
	{
		testBegin( "testExprAlias" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto ident = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "operand" ) );
		auto lit = exprCache.makeLiteral( typesCache, 1 );
		auto expr = exprCache.makeAlias( typesCache.getInt32(), std::move( ident ), std::move( lit ) );

		require( expr->getKind() == Kind::eAlias );
		require( expr->hasIdentifier() );
		check( expr->getIdentifier().getKind() == Kind::eIdentifier );
		check( expr->getAliasedExpr()->getKind() == Kind::eLiteral );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		checkExprDependant( testCounts, *expr, "testExprAlias", __LINE__ );
		testEnd()
	}

	static void testExprStreamAppend( test::TestCounts & testCounts )
	{
		testBegin( "testExprStreamAppend" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "operand" ) );
		auto expr = exprCache.makeStreamAppend( std::move( value ) );

		require( expr->getKind() == Kind::eStreamAppend );
		require( expr->getOperand()->getKind() == Kind::eIdentifier );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		checkExprDependant( testCounts, *expr, "testExprStreamAppend", __LINE__ );
		testEnd()
	}

	static void testExprSwizzle( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwizzle" );
		ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "operand" ) );
		auto expr = exprCache.makeSwizzle( std::move( value ), SwizzleKind{ SwizzleKind::e03 } );

		require( expr->getKind() == Kind::eSwizzle )
		require( expr->getOuterExpr()->getKind() == Kind::eIdentifier )
		require( expr->getOuterExpr()->getType()->getKind() == ast::type::Kind::eVec4F )
		check( expr->getType()->getKind() == ast::type::Kind::eVec2F )
		check( expr->getSwizzle() == SwizzleKind::e03 )
		checkExprDependant( testCounts, *expr, "testExprSwizzle", __LINE__ );

		SwizzleKind kind{};
		kind = SwizzleKind::Value::e0;
		kind = SwizzleKind::fromOffset( 0u );
		kind.toIndex();
		check( !kind.isFourComponents() );
		check( !kind.isThreeComponents() );
		check( !kind.isTwoComponents() );
		check( kind.isOneComponent() );
		auto kind2 = kind[0];
		kind |= kind2;

#define checkSwizzle( value )\
	getName( SwizzleKind{ value } );\
	exprCache.makeSwizzle( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "operand" ) ), SwizzleKind{ value } )

		checkSwizzle( SwizzleKind::e0 );
		checkSwizzle( SwizzleKind::e1 );
		checkSwizzle( SwizzleKind::e2 );
		checkSwizzle( SwizzleKind::e3 );
		checkSwizzle( SwizzleKind::e00 );
		checkSwizzle( SwizzleKind::e01 );
		checkSwizzle( SwizzleKind::e02 );
		checkSwizzle( SwizzleKind::e03 );
		checkSwizzle( SwizzleKind::e10 );
		checkSwizzle( SwizzleKind::e11 );
		checkSwizzle( SwizzleKind::e12 );
		checkSwizzle( SwizzleKind::e13 );
		checkSwizzle( SwizzleKind::e20 );
		checkSwizzle( SwizzleKind::e21 );
		checkSwizzle( SwizzleKind::e22 );
		checkSwizzle( SwizzleKind::e23 );
		checkSwizzle( SwizzleKind::e30 );
		checkSwizzle( SwizzleKind::e31 );
		checkSwizzle( SwizzleKind::e32 );
		checkSwizzle( SwizzleKind::e33 );
		checkSwizzle( SwizzleKind::e000 );
		checkSwizzle( SwizzleKind::e001 );
		checkSwizzle( SwizzleKind::e002 );
		checkSwizzle( SwizzleKind::e003 );
		checkSwizzle( SwizzleKind::e010 );
		checkSwizzle( SwizzleKind::e011 );
		checkSwizzle( SwizzleKind::e012 );
		checkSwizzle( SwizzleKind::e013 );
		checkSwizzle( SwizzleKind::e020 );
		checkSwizzle( SwizzleKind::e021 );
		checkSwizzle( SwizzleKind::e022 );
		checkSwizzle( SwizzleKind::e023 );
		checkSwizzle( SwizzleKind::e030 );
		checkSwizzle( SwizzleKind::e031 );
		checkSwizzle( SwizzleKind::e032 );
		checkSwizzle( SwizzleKind::e033 );
		checkSwizzle( SwizzleKind::e100 );
		checkSwizzle( SwizzleKind::e101 );
		checkSwizzle( SwizzleKind::e102 );
		checkSwizzle( SwizzleKind::e103 );
		checkSwizzle( SwizzleKind::e110 );
		checkSwizzle( SwizzleKind::e111 );
		checkSwizzle( SwizzleKind::e112 );
		checkSwizzle( SwizzleKind::e113 );
		checkSwizzle( SwizzleKind::e120 );
		checkSwizzle( SwizzleKind::e121 );
		checkSwizzle( SwizzleKind::e122 );
		checkSwizzle( SwizzleKind::e123 );
		checkSwizzle( SwizzleKind::e130 );
		checkSwizzle( SwizzleKind::e131 );
		checkSwizzle( SwizzleKind::e132 );
		checkSwizzle( SwizzleKind::e133 );
		checkSwizzle( SwizzleKind::e200 );
		checkSwizzle( SwizzleKind::e201 );
		checkSwizzle( SwizzleKind::e202 );
		checkSwizzle( SwizzleKind::e203 );
		checkSwizzle( SwizzleKind::e210 );
		checkSwizzle( SwizzleKind::e211 );
		checkSwizzle( SwizzleKind::e212 );
		checkSwizzle( SwizzleKind::e213 );
		checkSwizzle( SwizzleKind::e220 );
		checkSwizzle( SwizzleKind::e221 );
		checkSwizzle( SwizzleKind::e222 );
		checkSwizzle( SwizzleKind::e223 );
		checkSwizzle( SwizzleKind::e230 );
		checkSwizzle( SwizzleKind::e231 );
		checkSwizzle( SwizzleKind::e232 );
		checkSwizzle( SwizzleKind::e233 );
		checkSwizzle( SwizzleKind::e300 );
		checkSwizzle( SwizzleKind::e301 );
		checkSwizzle( SwizzleKind::e302 );
		checkSwizzle( SwizzleKind::e303 );
		checkSwizzle( SwizzleKind::e310 );
		checkSwizzle( SwizzleKind::e311 );
		checkSwizzle( SwizzleKind::e312 );
		checkSwizzle( SwizzleKind::e313 );
		checkSwizzle( SwizzleKind::e320 );
		checkSwizzle( SwizzleKind::e321 );
		checkSwizzle( SwizzleKind::e322 );
		checkSwizzle( SwizzleKind::e323 );
		checkSwizzle( SwizzleKind::e330 );
		checkSwizzle( SwizzleKind::e331 );
		checkSwizzle( SwizzleKind::e332 );
		checkSwizzle( SwizzleKind::e333 );
		checkSwizzle( SwizzleKind::e0000 );
		checkSwizzle( SwizzleKind::e0001 );
		checkSwizzle( SwizzleKind::e0002 );
		checkSwizzle( SwizzleKind::e0003 );
		checkSwizzle( SwizzleKind::e0010 );
		checkSwizzle( SwizzleKind::e0011 );
		checkSwizzle( SwizzleKind::e0012 );
		checkSwizzle( SwizzleKind::e0013 );
		checkSwizzle( SwizzleKind::e0020 );
		checkSwizzle( SwizzleKind::e0021 );
		checkSwizzle( SwizzleKind::e0022 );
		checkSwizzle( SwizzleKind::e0023 );
		checkSwizzle( SwizzleKind::e0030 );
		checkSwizzle( SwizzleKind::e0031 );
		checkSwizzle( SwizzleKind::e0032 );
		checkSwizzle( SwizzleKind::e0033 );
		checkSwizzle( SwizzleKind::e0100 );
		checkSwizzle( SwizzleKind::e0101 );
		checkSwizzle( SwizzleKind::e0102 );
		checkSwizzle( SwizzleKind::e0103 );
		checkSwizzle( SwizzleKind::e0110 );
		checkSwizzle( SwizzleKind::e0111 );
		checkSwizzle( SwizzleKind::e0112 );
		checkSwizzle( SwizzleKind::e0113 );
		checkSwizzle( SwizzleKind::e0120 );
		checkSwizzle( SwizzleKind::e0121 );
		checkSwizzle( SwizzleKind::e0122 );
		checkSwizzle( SwizzleKind::e0123 );
		checkSwizzle( SwizzleKind::e0130 );
		checkSwizzle( SwizzleKind::e0131 );
		checkSwizzle( SwizzleKind::e0132 );
		checkSwizzle( SwizzleKind::e0133 );
		checkSwizzle( SwizzleKind::e0200 );
		checkSwizzle( SwizzleKind::e0201 );
		checkSwizzle( SwizzleKind::e0202 );
		checkSwizzle( SwizzleKind::e0203 );
		checkSwizzle( SwizzleKind::e0210 );
		checkSwizzle( SwizzleKind::e0211 );
		checkSwizzle( SwizzleKind::e0212 );
		checkSwizzle( SwizzleKind::e0213 );
		checkSwizzle( SwizzleKind::e0220 );
		checkSwizzle( SwizzleKind::e0221 );
		checkSwizzle( SwizzleKind::e0222 );
		checkSwizzle( SwizzleKind::e0223 );
		checkSwizzle( SwizzleKind::e0230 );
		checkSwizzle( SwizzleKind::e0231 );
		checkSwizzle( SwizzleKind::e0232 );
		checkSwizzle( SwizzleKind::e0233 );
		checkSwizzle( SwizzleKind::e0300 );
		checkSwizzle( SwizzleKind::e0301 );
		checkSwizzle( SwizzleKind::e0302 );
		checkSwizzle( SwizzleKind::e0303 );
		checkSwizzle( SwizzleKind::e0310 );
		checkSwizzle( SwizzleKind::e0311 );
		checkSwizzle( SwizzleKind::e0312 );
		checkSwizzle( SwizzleKind::e0313 );
		checkSwizzle( SwizzleKind::e0320 );
		checkSwizzle( SwizzleKind::e0321 );
		checkSwizzle( SwizzleKind::e0322 );
		checkSwizzle( SwizzleKind::e0323 );
		checkSwizzle( SwizzleKind::e0330 );
		checkSwizzle( SwizzleKind::e0331 );
		checkSwizzle( SwizzleKind::e0332 );
		checkSwizzle( SwizzleKind::e0333 );
		checkSwizzle( SwizzleKind::e1000 );
		checkSwizzle( SwizzleKind::e1001 );
		checkSwizzle( SwizzleKind::e1002 );
		checkSwizzle( SwizzleKind::e1003 );
		checkSwizzle( SwizzleKind::e1010 );
		checkSwizzle( SwizzleKind::e1011 );
		checkSwizzle( SwizzleKind::e1012 );
		checkSwizzle( SwizzleKind::e1013 );
		checkSwizzle( SwizzleKind::e1020 );
		checkSwizzle( SwizzleKind::e1021 );
		checkSwizzle( SwizzleKind::e1022 );
		checkSwizzle( SwizzleKind::e1023 );
		checkSwizzle( SwizzleKind::e1030 );
		checkSwizzle( SwizzleKind::e1031 );
		checkSwizzle( SwizzleKind::e1032 );
		checkSwizzle( SwizzleKind::e1033 );
		checkSwizzle( SwizzleKind::e1100 );
		checkSwizzle( SwizzleKind::e1101 );
		checkSwizzle( SwizzleKind::e1102 );
		checkSwizzle( SwizzleKind::e1103 );
		checkSwizzle( SwizzleKind::e1110 );
		checkSwizzle( SwizzleKind::e1111 );
		checkSwizzle( SwizzleKind::e1112 );
		checkSwizzle( SwizzleKind::e1113 );
		checkSwizzle( SwizzleKind::e1120 );
		checkSwizzle( SwizzleKind::e1121 );
		checkSwizzle( SwizzleKind::e1122 );
		checkSwizzle( SwizzleKind::e1123 );
		checkSwizzle( SwizzleKind::e1130 );
		checkSwizzle( SwizzleKind::e1131 );
		checkSwizzle( SwizzleKind::e1132 );
		checkSwizzle( SwizzleKind::e1133 );
		checkSwizzle( SwizzleKind::e1200 );
		checkSwizzle( SwizzleKind::e1201 );
		checkSwizzle( SwizzleKind::e1202 );
		checkSwizzle( SwizzleKind::e1203 );
		checkSwizzle( SwizzleKind::e1210 );
		checkSwizzle( SwizzleKind::e1211 );
		checkSwizzle( SwizzleKind::e1212 );
		checkSwizzle( SwizzleKind::e1213 );
		checkSwizzle( SwizzleKind::e1220 );
		checkSwizzle( SwizzleKind::e1221 );
		checkSwizzle( SwizzleKind::e1222 );
		checkSwizzle( SwizzleKind::e1223 );
		checkSwizzle( SwizzleKind::e1230 );
		checkSwizzle( SwizzleKind::e1231 );
		checkSwizzle( SwizzleKind::e1232 );
		checkSwizzle( SwizzleKind::e1233 );
		checkSwizzle( SwizzleKind::e1300 );
		checkSwizzle( SwizzleKind::e1301 );
		checkSwizzle( SwizzleKind::e1302 );
		checkSwizzle( SwizzleKind::e1303 );
		checkSwizzle( SwizzleKind::e1310 );
		checkSwizzle( SwizzleKind::e1311 );
		checkSwizzle( SwizzleKind::e1312 );
		checkSwizzle( SwizzleKind::e1313 );
		checkSwizzle( SwizzleKind::e1320 );
		checkSwizzle( SwizzleKind::e1321 );
		checkSwizzle( SwizzleKind::e1322 );
		checkSwizzle( SwizzleKind::e1323 );
		checkSwizzle( SwizzleKind::e1330 );
		checkSwizzle( SwizzleKind::e1331 );
		checkSwizzle( SwizzleKind::e1332 );
		checkSwizzle( SwizzleKind::e1333 );
		checkSwizzle( SwizzleKind::e2000 );
		checkSwizzle( SwizzleKind::e2001 );
		checkSwizzle( SwizzleKind::e2002 );
		checkSwizzle( SwizzleKind::e2003 );
		checkSwizzle( SwizzleKind::e2010 );
		checkSwizzle( SwizzleKind::e2011 );
		checkSwizzle( SwizzleKind::e2012 );
		checkSwizzle( SwizzleKind::e2013 );
		checkSwizzle( SwizzleKind::e2020 );
		checkSwizzle( SwizzleKind::e2021 );
		checkSwizzle( SwizzleKind::e2022 );
		checkSwizzle( SwizzleKind::e2023 );
		checkSwizzle( SwizzleKind::e2030 );
		checkSwizzle( SwizzleKind::e2031 );
		checkSwizzle( SwizzleKind::e2032 );
		checkSwizzle( SwizzleKind::e2033 );
		checkSwizzle( SwizzleKind::e2100 );
		checkSwizzle( SwizzleKind::e2101 );
		checkSwizzle( SwizzleKind::e2102 );
		checkSwizzle( SwizzleKind::e2103 );
		checkSwizzle( SwizzleKind::e2110 );
		checkSwizzle( SwizzleKind::e2111 );
		checkSwizzle( SwizzleKind::e2112 );
		checkSwizzle( SwizzleKind::e2113 );
		checkSwizzle( SwizzleKind::e2120 );
		checkSwizzle( SwizzleKind::e2121 );
		checkSwizzle( SwizzleKind::e2122 );
		checkSwizzle( SwizzleKind::e2123 );
		checkSwizzle( SwizzleKind::e2130 );
		checkSwizzle( SwizzleKind::e2131 );
		checkSwizzle( SwizzleKind::e2132 );
		checkSwizzle( SwizzleKind::e2133 );
		checkSwizzle( SwizzleKind::e2200 );
		checkSwizzle( SwizzleKind::e2201 );
		checkSwizzle( SwizzleKind::e2202 );
		checkSwizzle( SwizzleKind::e2203 );
		checkSwizzle( SwizzleKind::e2210 );
		checkSwizzle( SwizzleKind::e2211 );
		checkSwizzle( SwizzleKind::e2212 );
		checkSwizzle( SwizzleKind::e2213 );
		checkSwizzle( SwizzleKind::e2220 );
		checkSwizzle( SwizzleKind::e2221 );
		checkSwizzle( SwizzleKind::e2222 );
		checkSwizzle( SwizzleKind::e2223 );
		checkSwizzle( SwizzleKind::e2230 );
		checkSwizzle( SwizzleKind::e2231 );
		checkSwizzle( SwizzleKind::e2232 );
		checkSwizzle( SwizzleKind::e2233 );
		checkSwizzle( SwizzleKind::e2300 );
		checkSwizzle( SwizzleKind::e2301 );
		checkSwizzle( SwizzleKind::e2302 );
		checkSwizzle( SwizzleKind::e2303 );
		checkSwizzle( SwizzleKind::e2310 );
		checkSwizzle( SwizzleKind::e2311 );
		checkSwizzle( SwizzleKind::e2312 );
		checkSwizzle( SwizzleKind::e2313 );
		checkSwizzle( SwizzleKind::e2320 );
		checkSwizzle( SwizzleKind::e2321 );
		checkSwizzle( SwizzleKind::e2322 );
		checkSwizzle( SwizzleKind::e2323 );
		checkSwizzle( SwizzleKind::e2330 );
		checkSwizzle( SwizzleKind::e2331 );
		checkSwizzle( SwizzleKind::e2332 );
		checkSwizzle( SwizzleKind::e2333 );
		checkSwizzle( SwizzleKind::e3000 );
		checkSwizzle( SwizzleKind::e3001 );
		checkSwizzle( SwizzleKind::e3002 );
		checkSwizzle( SwizzleKind::e3003 );
		checkSwizzle( SwizzleKind::e3010 );
		checkSwizzle( SwizzleKind::e3011 );
		checkSwizzle( SwizzleKind::e3012 );
		checkSwizzle( SwizzleKind::e3013 );
		checkSwizzle( SwizzleKind::e3020 );
		checkSwizzle( SwizzleKind::e3021 );
		checkSwizzle( SwizzleKind::e3022 );
		checkSwizzle( SwizzleKind::e3023 );
		checkSwizzle( SwizzleKind::e3030 );
		checkSwizzle( SwizzleKind::e3031 );
		checkSwizzle( SwizzleKind::e3032 );
		checkSwizzle( SwizzleKind::e3033 );
		checkSwizzle( SwizzleKind::e3100 );
		checkSwizzle( SwizzleKind::e3101 );
		checkSwizzle( SwizzleKind::e3102 );
		checkSwizzle( SwizzleKind::e3103 );
		checkSwizzle( SwizzleKind::e3110 );
		checkSwizzle( SwizzleKind::e3111 );
		checkSwizzle( SwizzleKind::e3112 );
		checkSwizzle( SwizzleKind::e3113 );
		checkSwizzle( SwizzleKind::e3120 );
		checkSwizzle( SwizzleKind::e3121 );
		checkSwizzle( SwizzleKind::e3122 );
		checkSwizzle( SwizzleKind::e3123 );
		checkSwizzle( SwizzleKind::e3130 );
		checkSwizzle( SwizzleKind::e3131 );
		checkSwizzle( SwizzleKind::e3132 );
		checkSwizzle( SwizzleKind::e3133 );
		checkSwizzle( SwizzleKind::e3200 );
		checkSwizzle( SwizzleKind::e3201 );
		checkSwizzle( SwizzleKind::e3202 );
		checkSwizzle( SwizzleKind::e3203 );
		checkSwizzle( SwizzleKind::e3210 );
		checkSwizzle( SwizzleKind::e3211 );
		checkSwizzle( SwizzleKind::e3212 );
		checkSwizzle( SwizzleKind::e3213 );
		checkSwizzle( SwizzleKind::e3220 );
		checkSwizzle( SwizzleKind::e3221 );
		checkSwizzle( SwizzleKind::e3222 );
		checkSwizzle( SwizzleKind::e3223 );
		checkSwizzle( SwizzleKind::e3230 );
		checkSwizzle( SwizzleKind::e3231 );
		checkSwizzle( SwizzleKind::e3232 );
		checkSwizzle( SwizzleKind::e3233 );
		checkSwizzle( SwizzleKind::e3300 );
		checkSwizzle( SwizzleKind::e3301 );
		checkSwizzle( SwizzleKind::e3302 );
		checkSwizzle( SwizzleKind::e3303 );
		checkSwizzle( SwizzleKind::e3310 );
		checkSwizzle( SwizzleKind::e3311 );
		checkSwizzle( SwizzleKind::e3312 );
		checkSwizzle( SwizzleKind::e3313 );
		checkSwizzle( SwizzleKind::e3320 );
		checkSwizzle( SwizzleKind::e3321 );
		checkSwizzle( SwizzleKind::e3322 );
		checkSwizzle( SwizzleKind::e3323 );
		checkSwizzle( SwizzleKind::e3330 );
		checkSwizzle( SwizzleKind::e3331 );
		checkSwizzle( SwizzleKind::e3332 );
		checkSwizzle( SwizzleKind::e3333 );

#undef checkSwizzle

		auto szvalue = SwizzleKind::Value::e1 | SwizzleKind::Value::e0;
		check( szvalue == ( SwizzleKind::Value::e1 | SwizzleKind::Value::e0 ) )

		check( ast::ExprCloner::submit( exprCache, nullptr ) == nullptr )
		check( ast::ExprCloner::submit( exprCache, expr.get() ) != nullptr )
		expr->updateFlag( ast::expr::Flag::eNonUniform );
		check( ast::ExprCloner::submit( exprCache, expr.get() ) != nullptr )
		testEnd()
	}
}

testSuiteMain( TestASTExpressions )
{
	testSuiteBegin()
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
	testSuiteEnd()
}

testSuiteLaunch( TestASTExpressions )
