#include "Common.hpp"

#include <ShaderAST/Expr/GetIntrinsicName.hpp>
#include <ShaderAST/Expr/GetCombinedImageAccessName.hpp>
#include <ShaderAST/Expr/GetStorageImageAccessName.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

namespace
{
	void testExprLiteral( test::TestCounts & testCounts )
	{
		testBegin( "testExprLiteral" );
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto expr = exprCache.makeLiteral( typesCache, false );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );
			require( expr->getLiteralType() == ast::expr::LiteralType::eBool );
			check( expr->getValue< ast::expr::LiteralType::eBool >() == false );
			testCounts << "ExprLiteral: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto expr = exprCache.makeLiteral( typesCache, 1.0f );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eFloat );
			require( expr->getLiteralType() == ast::expr::LiteralType::eFloat );
			check( expr->getValue< ast::expr::LiteralType::eFloat >() == 1.0f );
			testCounts << "ExprLiteral: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto expr = exprCache.makeLiteral( typesCache, 10 );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );
			require( expr->getLiteralType() == ast::expr::LiteralType::eInt32 );
			check( expr->getValue< ast::expr::LiteralType::eInt32 >() == 10 );
			testCounts << "ExprLiteral: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto expr = exprCache.makeLiteral( typesCache, 10u );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eUInt32 );
			require( expr->getLiteralType() == ast::expr::LiteralType::eUInt32 );
			check( expr->getValue< ast::expr::LiteralType::eUInt32 >() == 10u );
			testCounts << "ExprLiteral: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		testEnd();
	}
	
	void testExprIdentifier( test::TestCounts & testCounts )
	{
		testBegin( "testExprIdentifier" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto expr = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "var0" ) );

		require( expr->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );
		check( expr->getVariable()->getName() == "var0" );
		check( expr->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprIdentifier: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprAdd( test::TestCounts & testCounts )
	{
		testBegin( "testExprAdd" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAdd( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAdd );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprAdd: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprMinus( test::TestCounts & testCounts )
	{
		testBegin( "testExprMinus" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeMinus( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eMinus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprMinus: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprTimes( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimes" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeTimes( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eTimes );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprTimes: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprDivide( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimes" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr= exprCache.makeDivide( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eDivide );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprDivide: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprBitAnd( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitAnd" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeBitAnd( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitAnd );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprBitAnd: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprBitNot( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitNot" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeBitNot( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eBitNot );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprBitNot: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprBitOr( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitOr" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeBitOr( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitOr );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprBitOr: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprBitXor( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitXor" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeBitXor( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitXor );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprBitXor: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprLogAnd( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogAnd" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLogAnd( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLogAnd );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprLogAnd: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprLogNot( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogNot" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeLogNot( typesCache, std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eLogNot );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprLogNot: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprLogOr( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogOr" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLogOr( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLogOr );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprLogOr: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprModulo( test::TestCounts & testCounts )
	{
		testBegin( "testExprModulo" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeModulo( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eModulo );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprModulo: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprLShift( test::TestCounts & testCounts )
	{
		testBegin( "testExprLShift" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLShift( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLShift );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprLShift: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprRShift( test::TestCounts & testCounts )
	{
		testBegin( "testExprRShift" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeRShift( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eRShift );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprRShift: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprComma( test::TestCounts & testCounts )
	{
		testBegin( "testExprComma" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeComma( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eComma );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprComma: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprArrayAccess( test::TestCounts & testCounts )
	{
		testBegin( "testExprArrayAccess" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getArray( typesCache.getInt32() ), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeArrayAccess( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eArrayAccess );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eArray );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eArray );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprArrayAccess: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprAddAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAddAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAddAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAddAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprAddAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprDivideAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprDivideAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeDivideAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eDivideAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprDivideAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprMinusAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprMinusAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeMinusAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eMinusAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprMinusAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprTimesAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimesAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeTimesAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eTimesAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprTimesAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprModuloAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprModuloAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeModuloAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eModuloAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprModuloAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprLShiftAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprLShiftAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLShiftAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprLShiftAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprRShiftAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprRShiftAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeRShiftAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eRShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprRShiftAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprAndAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAndAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeAndAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAndAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprAndAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprOrAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprOrAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeOrAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eOrAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprOrAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprXorAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprXorAssign" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeXorAssign( typesCache.getInt32(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eXorAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprXorAssign: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprEqual" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeEqual( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprEqual: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprGreater( test::TestCounts & testCounts )
	{
		testBegin( "testExprGreater" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeGreater( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eGreater );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprGreater: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprGreaterEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprGreaterEqual" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeGreaterEqual( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eGreaterEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprGreaterEqual: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprLess( test::TestCounts & testCounts )
	{
		testBegin( "testExprLess" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLess( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLess );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprLess: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprLessEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprLessEqual" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeLessEqual( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLessEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprLessEqual: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprNotEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprNotEqual" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeNotEqual( typesCache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eNotEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt32 );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprNotEqual: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprPostDecrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPostDecrement" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePostDecrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePostDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprPostDecrement: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprPostIncrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPostIncrement" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePostIncrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePostIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprPostIncrement: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprPreDecrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPreDecrement" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePreDecrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePreDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprPreDecrement: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprPreIncrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPreIncrement" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makePreIncrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePreIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprPreIncrement: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprUnaryMinus( test::TestCounts & testCounts )
	{
		testBegin( "testExprUnaryMinus" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeUnaryMinus( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eUnaryMinus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprUnaryMinus: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprUnaryPlus( test::TestCounts & testCounts )
	{
		testBegin( "testExprUnaryPlus" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeUnaryPlus( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eUnaryPlus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprUnaryPlus: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprCast( test::TestCounts & testCounts )
	{
		testBegin( "testExprCast" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto op = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "op" ) );
		auto expr = exprCache.makeCast( typesCache.getFloat(), std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eCast );
		check( expr->getType()->getKind() == ast::type::Kind::eFloat );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		testCounts << "ExprCast: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprCompositeConstruct( test::TestCounts & testCounts )
	{
		testBegin( "testExprCompositeConstruct" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		ast::expr::ExprList args;
		args.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getVec4F(), "c1" ) ) );
		args.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getVec4F(), "c2" ) ) );
		auto expr = exprCache.makeCompositeConstruct( ast::expr::CompositeType::eMat2x4
			, ast::type::Kind::eFloat
			, std::move( args ) );

		check( expr->getKind() == ast::expr::Kind::eCompositeConstruct );
		check( expr->getType()->getKind() == ast::type::Kind::eMat2x4F );
		check( expr->getComposite() == ast::expr::CompositeType::eMat2x4 );
		check( expr->getComponent() == ast::type::Kind::eFloat );

		check( expr->getArgList().size() == 2u );
		testCounts << "ExprCompositeConstruct: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprFnCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprFnCall" );
		{
			ast::expr::ExprList argList;
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto functionType = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().empty() );
			testCounts << "ExprFnCall: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ast::expr::ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "p" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 1u );

			require( expr->getArgList()[0]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == ast::expr::LiteralType::eInt32 );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
			testCounts << "ExprFnCall: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ast::expr::ExprList argList;
			argList.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			argList.emplace_back( exprCache.makeLiteral( typesCache, 1.0f ) );
			auto functionType = typesCache.getFunction( typesCache.getInt32()
				, {
					ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "p0" ),
					ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getFloat(), "p1" ),
				} );
			auto funcName = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, functionType, "func" ) );
			auto expr = exprCache.makeFnCall( typesCache.getInt32(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 2u );

			require( expr->getArgList()[0]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt32 );
			require( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == ast::expr::LiteralType::eInt32 );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );

			require( expr->getArgList()[1]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[1]->getType()->getKind() == ast::type::Kind::eFloat );
			require( static_cast< ast::expr::Literal const & >( *expr->getArgList()[1] ).getLiteralType() == ast::expr::LiteralType::eFloat );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[1] ).getValue< ast::expr::LiteralType::eFloat >() == 1.0f );
			testCounts << "ExprFnCall: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		testEnd();
	}

	void testExprIntrinsicCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprIntrinsicCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( ast::expr::Intrinsic::eCount ); ++intr )
		{
			ast::expr::getName( ast::expr::Intrinsic( intr ) );
		}
		ast::expr::getName( ast::expr::Intrinsic::eCount );
		ast::expr::getName( ast::expr::Intrinsic::eInvalid );
		checkThrow( ast::expr::getName( ast::expr::Intrinsic( uint32_t( ast::expr::Intrinsic::eCount ) + 1u ) ) );
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ast::expr::ExprList argList;
			argList.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "x" ) ) );
			auto expr = exprCache.makeIntrinsicCall( typesCache.getInt32(), ast::expr::Intrinsic::eAbs1I, std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eIntrinsicCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getIntrinsic() == ast::expr::Intrinsic::eAbs1I );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType()->getKind() == ast::type::Kind::eInt32 );
			testCounts << "ExprIntrinsicCall: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		testEnd();
	}

	void testExprStorageImageAccessCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprStorageImageAccessCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( ast::expr::StorageImageAccess::eCount ); ++intr )
		{
			ast::expr::getName( ast::expr::StorageImageAccess( intr ) );
		}
		ast::expr::getName( ast::expr::StorageImageAccess::eCount );
		ast::expr::getName( ast::expr::StorageImageAccess::eInvalid );
		checkThrow( ast::expr::getName( ast::expr::StorageImageAccess( uint32_t( ast::expr::StorageImageAccess::eCount ) + 1u ) ) );
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ast::expr::ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getImage( config ), "x" ) ) );
			auto expr = exprCache.makeStorageImageAccessCall( typesCache.getInt32(), ast::expr::StorageImageAccess::eImageSize1DI, std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eImageAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getImageAccess() == ast::expr::StorageImageAccess::eImageSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == typesCache.getImage( config ) );
			testCounts << "ExprImageAccessCall: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		testEnd();
	}

	void testExprCombinedImageAccessCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprCombinedImageAccessCall" );
		for ( uint32_t intr = 0u; intr < uint32_t( ast::expr::CombinedImageAccess::eCount ); ++intr )
		{
			ast::expr::getName( ast::expr::CombinedImageAccess( intr ) );
			ast::expr::isBiasAndOffset( ast::expr::CombinedImageAccess( intr ) );
			ast::expr::isProj( ast::expr::CombinedImageAccess( intr ) );
			ast::expr::isShadow( ast::expr::CombinedImageAccess( intr ) );
			ast::expr::isShadowLodOffset( ast::expr::CombinedImageAccess( intr ) );
		}
		ast::expr::getName( ast::expr::CombinedImageAccess::eCount );
		ast::expr::getName( ast::expr::CombinedImageAccess::eInvalid );
		checkThrow( ast::expr::getName( ast::expr::CombinedImageAccess( uint32_t( ast::expr::CombinedImageAccess::eCount ) + 1u ) ) );
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			ast::expr::ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getCombinedImage( config ), "x" ) ) );
			auto expr = exprCache.makeCombinedImageAccessCall( typesCache.getInt32(), ast::expr::CombinedImageAccess::eTextureSize1DI, std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eCombinedImageAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

			check( expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == typesCache.getCombinedImage( config ) );
			testCounts << "ExprCombinedImageAccessCall: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		testEnd();
	}

	void testExprAggrInit( test::TestCounts & testCounts )
	{
		testBegin( "testExprAggrInit" );
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getArray( typesCache.getInt32(), 4u ), "lhs" ) );
			ast::expr::ExprList rhs;
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			require( expr->getKind() == ast::expr::Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt32 );

			require( expr->hasIdentifier() );
			check( expr->getIdentifier().getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getType() ) == ast::type::Kind::eInt32 );
			check( expr->getIdentifier().getVariable()->getName() == "lhs" );
			check( expr->getIdentifier().getVariable()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier().getVariable()->getType() ) == ast::type::Kind::eInt32 );

			check( expr->getInitialisers().empty() );
			testCounts << "ExprAggrInit (empty): " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		{
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getArray( typesCache.getInt32(), 4u ), "lhs" ) );
			ast::expr::ExprList rhs;
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 10 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 20 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 30 ) );
			rhs.emplace_back( exprCache.makeLiteral( typesCache, 40 ) );
			auto expr = exprCache.makeAggrInit( std::move( lhs ), std::move( rhs ) );

			require( expr->getKind() == ast::expr::Kind::eAggrInit );
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
				check( init->getKind() == ast::expr::Kind::eLiteral );
				check( init->getType()->getKind() == ast::type::Kind::eInt32 );
				check( static_cast< ast::expr::Literal const & >( *init ).getLiteralType() == ast::expr::LiteralType::eInt32 );
				check( static_cast< ast::expr::Literal const & >( *init ).getValue< ast::expr::LiteralType::eInt32 >() == v );
				v += 10;
			}

			testCounts << "ExprAggrInit: " << ast::debug::displayExpression( *expr ) << test::endl;
		}
		testEnd();
	}

	void testExprInit( test::TestCounts & testCounts )
	{
		testBegin( "testExprInit" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeInit( std::move( lhs ), std::move( rhs ) );

		require( expr->getKind() == ast::expr::Kind::eInit );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->hasIdentifier() );
		check( expr->getIdentifier().getType()->getKind() == ast::type::Kind::eInt32 );
		check( expr->getIdentifier().getVariable()->getName() == "lhs" );
		check( expr->getIdentifier().getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getInitialiser()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getInitialiser()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getInitialiser() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getInitialiser() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprInit: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprMbrSelect( test::TestCounts & testCounts )
	{
		testBegin( "testExprMbrSelect" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd140, "outer" );
		type->declMember( "inner", typesCache.getInt32() );
		auto outerVar = ast::var::makeVariable( ++testCounts.nextVarId, type, "outerVar" );
		auto expr = exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, outerVar ), 0u, uint64_t( ast::var::Flag::eShaderInput ) );

		require( expr->getKind() == ast::expr::Kind::eMbrSelect );
		check( expr->getOuterExpr()->getType()->getKind() == ast::type::Kind::eStruct );

		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );
		check( expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getName() == "outerVar" );

		check( expr->getMemberIndex() == 0u );
		check( expr->getMemberFlags() == uint64_t( ast::var::Flag::eShaderInput ) );
		testCounts << "ExprMbrSelect: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprQuestion( test::TestCounts & testCounts )
	{
		testBegin( "testExprQuestion" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto ctrlExpr = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "ctrl" ) );
		auto trueExpr = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( 2u, typesCache.getInt32(), "lhs" ) );
		auto falseExpr = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeQuestion( typesCache.getInt32(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

		require( expr->getKind() == ast::expr::Kind::eQuestion );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< ast::expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< ast::expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getName() == "ctrl" );

		require( expr->getTrueExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getTrueExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

		require( expr->getFalseExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getFalseExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getFalseExpr() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getFalseExpr() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprQuestion: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprSwitchCase( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwitchCase" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto label = exprCache.makeLiteral( typesCache, 10 );
		auto expr = exprCache.makeSwitchCase( std::move( label ) );

		require( expr->getKind() == ast::expr::Kind::eSwitchCase );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getLabel()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getLabel()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getLabel() ).getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( static_cast< ast::expr::Literal const & >( *expr->getLabel() ).getValue< ast::expr::LiteralType::eInt32 >() == 10 );
		testCounts << "ExprSwitchCase: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprSwitchTest( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwitchTest" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto expr = exprCache.makeSwitchTest( std::move( value ) );

		require( expr->getKind() == ast::expr::Kind::eSwitchTest );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		require( expr->getValue()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getValue()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getValue() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( static_cast< ast::expr::Identifier const & >( *expr->getValue() ).getVariable()->getName() == "lhs" );
		testCounts << "ExprSwitchTest: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprCopy( test::TestCounts & testCounts )
	{
		testBegin( "testExprCopy" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "operand" ) );
		auto expr = exprCache.makeCopy( std::move( value ) );

		require( expr->getKind() == ast::expr::Kind::eCopy );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		testCounts << "ExprCopyTest: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprAlias( test::TestCounts & testCounts )
	{
		testBegin( "testExprAlias" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto ident = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "operand" ) );
		auto lit = exprCache.makeLiteral( typesCache, 1 );
		auto expr = exprCache.makeAlias( typesCache.getInt32(), std::move( ident ), std::move( lit ) );

		require( expr->getKind() == ast::expr::Kind::eAlias );
		require( expr->hasIdentifier() );
		check( expr->getIdentifier().getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getAliasedExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		testCounts << "ExprAliasTest: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprStreamAppend( test::TestCounts & testCounts )
	{
		testBegin( "testExprStreamAppend" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "operand" ) );
		auto expr = exprCache.makeStreamAppend( std::move( value ) );

		require( expr->getKind() == ast::expr::Kind::eStreamAppend );
		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getType()->getKind() == ast::type::Kind::eInt32 );

		testCounts << "ExprStramAppendTest: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}

	void testExprSwizzle( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwizzle" );
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto value = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getVec4F(), "operand" ) );
		auto expr = exprCache.makeSwizzle( std::move( value ), ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e03 } );

		require( expr->getKind() == ast::expr::Kind::eSwizzle );
		require( expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier );
		require( expr->getOuterExpr()->getType()->getKind() == ast::type::Kind::eVec4F );
		check( expr->getType()->getKind() == ast::type::Kind::eVec2F );
		check( expr->getSwizzle() == ast::expr::SwizzleKind::e03 );

		testCounts << "ExprSwizzleTest: " << ast::debug::displayExpression( *expr ) << test::endl;
		testEnd();
	}
}

testSuiteMain( TestASTExpressions )
{
	testSuiteBegin();
	testExprAdd( testCounts );
	testExprAddAssign( testCounts );
	testExprAggrInit( testCounts );
	testExprAlias( testCounts );
	testExprAndAssign( testCounts );
	testExprArrayAccess( testCounts );
	testExprAssign( testCounts );
	testExprBitAnd( testCounts );
	testExprBitNot( testCounts );
	testExprBitOr( testCounts );
	testExprBitXor( testCounts );
	testExprCast( testCounts );
	testExprCombinedImageAccessCall( testCounts );
	testExprComma( testCounts );
	testExprCompositeConstruct( testCounts );
	testExprCopy( testCounts );
	testExprDivide( testCounts );
	testExprDivideAssign( testCounts );
	testExprEqual( testCounts );
	testExprFnCall( testCounts );
	testExprGreater( testCounts );
	testExprGreaterEqual( testCounts );
	testExprIdentifier( testCounts );
	testExprInit( testCounts );
	testExprIntrinsicCall( testCounts );
	testExprLess( testCounts );
	testExprLessEqual( testCounts );
	testExprLiteral( testCounts );
	testExprLogAnd( testCounts );
	testExprLogNot( testCounts );
	testExprLogOr( testCounts );
	testExprLShift( testCounts );
	testExprLShiftAssign( testCounts );
	testExprMbrSelect( testCounts );
	testExprMinus( testCounts );
	testExprMinusAssign( testCounts );
	testExprModulo( testCounts );
	testExprModuloAssign( testCounts );
	testExprNotEqual( testCounts );
	testExprOrAssign( testCounts );
	testExprPostDecrement( testCounts );
	testExprPostIncrement( testCounts );
	testExprPreDecrement( testCounts );
	testExprPreIncrement( testCounts );
	testExprQuestion( testCounts );
	testExprRShift( testCounts );
	testExprRShiftAssign( testCounts );
	testExprStorageImageAccessCall( testCounts );
	testExprStreamAppend( testCounts );
	testExprSwitchCase( testCounts );
	testExprSwitchTest( testCounts );
	testExprSwizzle( testCounts );
	testExprTimes( testCounts );
	testExprTimesAssign( testCounts );
	testExprUnaryMinus( testCounts );
	testExprUnaryPlus( testCounts );
	testExprXorAssign( testCounts );
	testSuiteEnd();
}

testSuiteLaunch( TestASTExpressions )
