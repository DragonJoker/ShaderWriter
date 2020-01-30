#include "../Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Debug/DebugExprVisitor.hpp>

namespace
{
	void testExprLiteral( test::TestCounts & testCounts )
	{
		testBegin( "testExprLiteral" );
		{
			ast::type::TypesCache cache;
			auto expr = ast::expr::makeLiteral( cache, false );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );
			require( expr->getLiteralType() == ast::expr::LiteralType::eBool );
			check( expr->getValue< ast::expr::LiteralType::eBool >() == false );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			ast::type::TypesCache cache;
			auto expr = ast::expr::makeLiteral( cache, 1.0f );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eFloat );
			require( expr->getLiteralType() == ast::expr::LiteralType::eFloat );
			check( expr->getValue< ast::expr::LiteralType::eFloat >() == 1.0f );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			ast::type::TypesCache cache;
			auto expr = ast::expr::makeLiteral( cache, 10 );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );
			require( expr->getLiteralType() == ast::expr::LiteralType::eInt );
			check( expr->getValue< ast::expr::LiteralType::eInt >() == 10 );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			ast::type::TypesCache cache;
			auto expr = ast::expr::makeLiteral( cache, 10u );

			require( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eUInt );
			require( expr->getLiteralType() == ast::expr::LiteralType::eUInt );
			check( expr->getValue< ast::expr::LiteralType::eUInt >() == 10u );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}
	
	void testExprIdentifier( test::TestCounts & testCounts )
	{
		testBegin( "testExprIdentifier" );
		ast::type::TypesCache cache;
		auto expr = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "var0" ) );

		require( expr->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );
		check( expr->getVariable()->getName() == "var0" );
		check( expr->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprIdentifier: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAdd( test::TestCounts & testCounts )
	{
		testBegin( "testExprAdd" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeAdd( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAdd );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAdd: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinus( test::TestCounts & testCounts )
	{
		testBegin( "testExprMinus" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeMinus( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eMinus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprMinus: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimes( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimes" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeTimes( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eTimes );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprTimes: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivide( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimes" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr= ast::expr::makeDivide( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eDivide );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprDivide: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitAnd( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitAnd" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeBitAnd( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitAnd );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprBitAnd: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitNot( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitNot" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makeBitNot( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eBitNot );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprBitNot: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitOr( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitOr" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeBitOr( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitOr );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprBitOr: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitXor( test::TestCounts & testCounts )
	{
		testBegin( "testExprBitXor" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeBitXor( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitXor );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprBitXor: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogAnd( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogAnd" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeLogAnd( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLogAnd );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLogAnd: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogNot( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogNot" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeLogNot( cache, std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eLogNot );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprLogNot: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogOr( test::TestCounts & testCounts )
	{
		testBegin( "testExprLogOr" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeLogOr( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLogOr );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLogOr: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModulo( test::TestCounts & testCounts )
	{
		testBegin( "testExprModulo" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeModulo( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eModulo );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprModulo: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShift( test::TestCounts & testCounts )
	{
		testBegin( "testExprLShift" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeLShift( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLShift );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLShift: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShift( test::TestCounts & testCounts )
	{
		testBegin( "testExprRShift" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeRShift( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eRShift );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprRShift: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprComma( test::TestCounts & testCounts )
	{
		testBegin( "testExprComma" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeComma( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eComma );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprComma: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprArrayAccess( test::TestCounts & testCounts )
	{
		testBegin( "testExprArrayAccess" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getArray( cache.getInt() ), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeArrayAccess( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eArrayAccess );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eArray );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eArray );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprArrayAccess: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAddAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAddAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeAddAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAddAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAddAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivideAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprDivideAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeDivideAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eDivideAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprDivideAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinusAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprMinusAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeMinusAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eMinusAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprMinusAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimesAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprTimesAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeTimesAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eTimesAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprTimesAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModuloAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprModuloAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeModuloAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eModuloAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprModuloAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShiftAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprLShiftAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeLShiftAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLShiftAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShiftAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprRShiftAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeRShiftAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eRShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprRShiftAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAndAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprAndAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeAndAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAndAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAndAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprOrAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprOrAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeOrAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eOrAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprOrAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprXorAssign( test::TestCounts & testCounts )
	{
		testBegin( "testExprXorAssign" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeXorAssign( cache.getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eXorAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprXorAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprEqual" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeEqual( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreater( test::TestCounts & testCounts )
	{
		testBegin( "testExprGreater" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeGreater( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eGreater );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprGreater: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreaterEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprGreaterEqual" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeGreaterEqual( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eGreaterEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprGreaterEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLess( test::TestCounts & testCounts )
	{
		testBegin( "testExprLess" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeLess( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLess );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLess: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLessEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprLessEqual" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeLessEqual( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLessEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLessEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprNotEqual( test::TestCounts & testCounts )
	{
		testBegin( "testExprNotEqual" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeNotEqual( cache, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eNotEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		require( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		require( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprNotEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostDecrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPostDecrement" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makePostDecrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePostDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPostDecrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostIncrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPostIncrement" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makePostIncrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePostIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPostIncrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreDecrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPreDecrement" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makePreDecrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePreDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPreDecrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreIncrement( test::TestCounts & testCounts )
	{
		testBegin( "testExprPreIncrement" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makePreIncrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePreIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPreIncrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryMinus( test::TestCounts & testCounts )
	{
		testBegin( "testExprUnaryMinus" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makeUnaryMinus( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eUnaryMinus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprUnaryMinus: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryPlus( test::TestCounts & testCounts )
	{
		testBegin( "testExprUnaryPlus" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makeUnaryPlus( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eUnaryPlus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprUnaryPlus: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprCast( test::TestCounts & testCounts )
	{
		testBegin( "testExprCast" );
		ast::type::TypesCache cache;
		auto op = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "op" ) );
		auto expr = ast::expr::makeCast( cache.getFloat(), std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eCast );
		check( expr->getType()->getKind() == ast::type::Kind::eFloat );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprCast: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprCompositeConstruct( test::TestCounts & testCounts )
	{
		testBegin( "testExprCompositeConstruct" );
		ast::type::TypesCache cache;
		ast::expr::ExprList args;
		args.emplace_back( ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getVec4F(), "c1" ) ) );
		args.emplace_back( ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getVec4F(), "c2" ) ) );
		auto expr = ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eMat2x4
			, ast::type::Kind::eFloat
			, std::move( args ) );

		check( expr->getKind() == ast::expr::Kind::eCompositeConstruct );
		check( expr->getType()->getKind() == ast::type::Kind::eMat2x4F );
		check( expr->getComposite() == ast::expr::CompositeType::eMat2x4 );
		check( expr->getComponent() == ast::type::Kind::eFloat );

		check( expr->getArgList().size() == 2u );
		std::cout << "ExprCompositeConstruct: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprFnCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprFnCall" );
		{
			ast::expr::ExprList argList;
			ast::type::TypesCache cache;
			auto functionType = cache.getFunction( cache.getInt(), ast::var::VariableList{} );
			auto funcName = ast::expr::makeIdentifier( cache, ast::var::makeVariable( functionType, "func" ) );
			auto expr = ast::expr::makeFnCall( cache.getInt(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().empty() );
			std::cout << "ExprFnCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			ast::type::TypesCache cache;
			ast::expr::ExprList argList;
			argList.emplace_back( ast::expr::makeLiteral( cache, 10 ) );
			auto functionType = cache.getFunction( cache.getInt()
				, {
					ast::var::makeVariable( cache.getInt(), "p" ),
				} );
			auto funcName = ast::expr::makeIdentifier( cache, ast::var::makeVariable( functionType, "func" ) );
			auto expr = ast::expr::makeFnCall( cache.getInt(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 1u );

			require( expr->getArgList()[0]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt );
			require( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == ast::expr::LiteralType::eInt );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getValue< ast::expr::LiteralType::eInt >() == 10 );
			std::cout << "ExprFnCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			ast::type::TypesCache cache;
			ast::expr::ExprList argList;
			argList.emplace_back( ast::expr::makeLiteral( cache, 10 ) );
			argList.emplace_back( ast::expr::makeLiteral( cache, 1.0f ) );
			auto functionType = cache.getFunction( cache.getInt()
				, {
					ast::var::makeVariable( cache.getInt(), "p0" ),
					ast::var::makeVariable( cache.getFloat(), "p1" ),
				} );
			auto funcName = ast::expr::makeIdentifier( cache, ast::var::makeVariable( functionType, "func" ) );
			auto expr = ast::expr::makeFnCall( cache.getInt(), std::move( funcName ), std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 2u );

			require( expr->getArgList()[0]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt );
			require( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == ast::expr::LiteralType::eInt );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getValue< ast::expr::LiteralType::eInt >() == 10 );

			require( expr->getArgList()[1]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[1]->getType()->getKind() == ast::type::Kind::eFloat );
			require( static_cast< ast::expr::Literal const & >( *expr->getArgList()[1] ).getLiteralType() == ast::expr::LiteralType::eFloat );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[1] ).getValue< ast::expr::LiteralType::eFloat >() == 1.0f );
			std::cout << "ExprFnCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprIntrinsicCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprIntrinsicCall" );
		{
			ast::type::TypesCache cache;
			ast::expr::ExprList argList;
			argList.emplace_back( ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "x" ) ) );
			auto expr = ast::expr::makeIntrinsicCall( cache.getInt(), ast::expr::Intrinsic::eAbs1I, std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eIntrinsicCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getIntrinsic() == ast::expr::Intrinsic::eAbs1I );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType()->getKind() == ast::type::Kind::eInt );
			std::cout << "ExprIntrinsicCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprImageAccessCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprImageAccessCall" );
		{
			ast::type::TypesCache cache;
			ast::expr::ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getImage( config ), "x" ) ) );
			auto expr = ast::expr::makeImageAccessCall( cache.getInt(), ast::expr::ImageAccess::eImageSize1DI, std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eImageAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getImageAccess() == ast::expr::ImageAccess::eImageSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == cache.getImage( config ) );
			std::cout << "ExprImageAccessCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprTextureAccessCall( test::TestCounts & testCounts )
	{
		testBegin( "testExprTextureAccessCall" );
		{
			ast::type::TypesCache cache;
			ast::expr::ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getSampledImage( config ), "x" ) ) );
			auto expr = ast::expr::makeTextureAccessCall( cache.getInt(), ast::expr::TextureAccess::eTextureSize1DI, std::move( argList ) );

			require( expr->getKind() == ast::expr::Kind::eTextureAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getTextureAccess() == ast::expr::TextureAccess::eTextureSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == cache.getSampledImage( config ) );
			std::cout << "ExprTextureAccessCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprAggrInit( test::TestCounts & testCounts )
	{
		testBegin( "testExprAggrInit" );
		{
			ast::type::TypesCache cache;
			auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getArray( cache.getInt(), 4u ), "lhs" ) );
			ast::expr::ExprList rhs;
			auto expr = ast::expr::makeAggrInit( std::move( lhs ), std::move( rhs ) );

			require( expr->getKind() == ast::expr::Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt );

			check( expr->getIdentifier()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier()->getType() ) == ast::type::Kind::eInt );
			check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
			check( expr->getIdentifier()->getVariable()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier()->getVariable()->getType() ) == ast::type::Kind::eInt );

			check( expr->getInitialisers().empty() );
			std::cout << "ExprAggrInit (empty): " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			ast::type::TypesCache cache;
			auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getArray( cache.getInt(), 4u ), "lhs" ) );
			ast::expr::ExprList rhs;
			rhs.emplace_back( ast::expr::makeLiteral( cache, 10 ) );
			rhs.emplace_back( ast::expr::makeLiteral( cache, 20 ) );
			rhs.emplace_back( ast::expr::makeLiteral( cache, 30 ) );
			rhs.emplace_back( ast::expr::makeLiteral( cache, 40 ) );
			auto expr = ast::expr::makeAggrInit( std::move( lhs ), std::move( rhs ) );

			require( expr->getKind() == ast::expr::Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getType() ) == ast::type::Kind::eInt );

			check( expr->getIdentifier()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier()->getType() ) == ast::type::Kind::eInt );
			check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
			check( expr->getIdentifier()->getVariable()->getType()->getKind() == ast::type::Kind::eArray );
			check( getNonArrayKind( expr->getIdentifier()->getVariable()->getType() ) == ast::type::Kind::eInt );

			check( expr->getInitialisers().size() == 4u );
			int v = 10;

			for ( auto & init : expr->getInitialisers() )
			{
				check( init->getKind() == ast::expr::Kind::eLiteral );
				check( init->getType()->getKind() == ast::type::Kind::eInt );
				check( static_cast< ast::expr::Literal const & >( *init ).getLiteralType() == ast::expr::LiteralType::eInt );
				check( static_cast< ast::expr::Literal const & >( *init ).getValue< ast::expr::LiteralType::eInt >() == v );
				v += 10;
			}

			std::cout << "ExprAggrInit: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprInit( test::TestCounts & testCounts )
	{
		testBegin( "testExprInit" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeInit( std::move( lhs ), std::move( rhs ) );

		require( expr->getKind() == ast::expr::Kind::eInit );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getIdentifier()->getType()->getKind() == ast::type::Kind::eInt );
		check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
		check( expr->getIdentifier()->getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getInitialiser()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getInitialiser()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getInitialiser() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getInitialiser() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprInit: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMbrSelect( test::TestCounts & testCounts )
	{
		testBegin( "testExprMbrSelect" );
		ast::type::TypesCache cache;
		auto outerVar = ast::var::makeVariable( cache.getInt(), "outerVar" );
		auto member = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "innerVar" ) );
		auto expr = ast::expr::makeMbrSelect( ast::expr::makeIdentifier( cache, outerVar ), 0u, std::move( member ) );

		require( expr->getKind() == ast::expr::Kind::eMbrSelect );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOuterExpr()->getType()->getKind() == ast::type::Kind::eInt );
		check( expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getName() == "outerVar" );

		require( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "innerVar" );
		std::cout << "ExprMbrSelect: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprQuestion( test::TestCounts & testCounts )
	{
		testBegin( "testExprQuestion" );
		ast::type::TypesCache cache;
		auto ctrlExpr = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getBool(), "ctrl" ) );
		auto trueExpr = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto falseExpr = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeQuestion( cache.getInt(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

		require( expr->getKind() == ast::expr::Kind::eQuestion );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< ast::expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< ast::expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getName() == "ctrl" );

		require( expr->getTrueExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getTrueExpr()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

		require( expr->getFalseExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getFalseExpr()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getFalseExpr() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getFalseExpr() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprQuestion: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprSwitchCase( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwitchCase" );
		ast::type::TypesCache cache;
		auto label = ast::expr::makeLiteral( cache, 10 );
		auto expr = ast::expr::makeSwitchCase( std::move( label ) );

		require( expr->getKind() == ast::expr::Kind::eSwitchCase );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getLabel()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getLabel()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getLabel() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getLabel() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprSwitchCase: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprSwitchTest( test::TestCounts & testCounts )
	{
		testBegin( "testExprSwitchTest" );
		ast::type::TypesCache cache;
		auto value = ast::expr::makeIdentifier( cache, ast::var::makeVariable( cache.getInt(), "lhs" ) );
		auto expr = ast::expr::makeSwitchTest( std::move( value ) );

		require( expr->getKind() == ast::expr::Kind::eSwitchTest );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		require( expr->getValue()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getValue()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getValue() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getValue() ).getVariable()->getName() == "lhs" );
		std::cout << "ExprSwitchTest: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestASTExpressions" );
	testExprLiteral( testCounts );
	testExprIdentifier( testCounts );
	testExprAdd( testCounts );
	testExprMinus( testCounts );
	testExprTimes( testCounts );
	testExprDivide( testCounts );
	testExprBitAnd( testCounts );
	testExprBitNot( testCounts );
	testExprBitOr( testCounts );
	testExprBitXor( testCounts );
	testExprLogAnd( testCounts );
	testExprLogNot( testCounts );
	testExprLogOr( testCounts );
	testExprModulo( testCounts );
	testExprLShift( testCounts );
	testExprRShift( testCounts );
	testExprComma( testCounts );
	testExprArrayAccess( testCounts );
	testExprAssign( testCounts );
	testExprAddAssign( testCounts );
	testExprDivideAssign( testCounts );
	testExprMinusAssign( testCounts );
	testExprTimesAssign( testCounts );
	testExprModuloAssign( testCounts );
	testExprLShiftAssign( testCounts );
	testExprRShiftAssign( testCounts );
	testExprAndAssign( testCounts );
	testExprOrAssign( testCounts );
	testExprXorAssign( testCounts );
	testExprEqual( testCounts );
	testExprGreater( testCounts );
	testExprGreaterEqual( testCounts );
	testExprLess( testCounts );
	testExprLessEqual( testCounts );
	testExprNotEqual( testCounts );
	testExprPostDecrement( testCounts );
	testExprPostIncrement( testCounts );
	testExprPreDecrement( testCounts );
	testExprPreIncrement( testCounts );
	testExprUnaryMinus( testCounts );
	testExprUnaryPlus( testCounts );
	testExprCast( testCounts );
	testExprCompositeConstruct( testCounts );
	testExprFnCall( testCounts );
	testExprIntrinsicCall( testCounts );
	testExprTextureAccessCall( testCounts );
	testExprImageAccessCall( testCounts );
	testExprInit( testCounts );
	testExprAggrInit( testCounts );
	testExprMbrSelect( testCounts );
	testExprQuestion( testCounts );
	testExprSwitchCase( testCounts );
	testExprSwitchTest( testCounts );
	testSuiteEnd();
}
