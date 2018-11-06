#include "../Common.hpp"

#include <ASTGenerator/Var/Variable.hpp>
#include <ASTGenerator/Debug/DebugExprVisitor.hpp>

namespace
{
	void testExprLiteral()
	{
		testBegin( "testExprLiteral" );
		{
			auto expr = ast::expr::makeLiteral( false );

			check( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eBoolean );
			check( expr->getLiteralType() == ast::expr::LiteralType::eBool );
			check( expr->getValue< ast::expr::LiteralType::eBool >() == false );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::expr::makeLiteral( 1.0f );

			check( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eFloat );
			check( expr->getLiteralType() == ast::expr::LiteralType::eFloat );
			check( expr->getValue< ast::expr::LiteralType::eFloat >() == 1.0f );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::expr::makeLiteral( 10 );

			check( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );
			check( expr->getLiteralType() == ast::expr::LiteralType::eInt );
			check( expr->getValue< ast::expr::LiteralType::eInt >() == 10 );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::expr::makeLiteral( 10u );

			check( expr->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::type::Kind::eUInt );
			check( expr->getLiteralType() == ast::expr::LiteralType::eUInt );
			check( expr->getValue< ast::expr::LiteralType::eUInt >() == 10u );
			std::cout << "ExprLiteral: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}
	
	void testExprIdentifier()
	{
		testBegin( "testExprIdentifier" );
		auto expr = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "var0" ) );

		check( expr->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );
		check( expr->getVariable()->getName() == "var0" );
		check( expr->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprIdentifier: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAdd()
	{
		testBegin( "testExprAdd" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeAdd( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAdd );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAdd: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinus()
	{
		testBegin( "testExprMinus" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeMinus( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eMinus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprMinus: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimes()
	{
		testBegin( "testExprTimes" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeTimes( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eTimes );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprTimes: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivide()
	{
		testBegin( "testExprTimes" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr= ast::expr::makeDivide( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eDivide );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprDivide: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitAnd()
	{
		testBegin( "testExprBitAnd" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeBitAnd( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitAnd );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprBitAnd: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitNot()
	{
		testBegin( "testExprBitNot" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makeBitNot( ast::type::getInt(), std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eBitNot );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprBitNot: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitOr()
	{
		testBegin( "testExprBitOr" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeBitOr( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitOr );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprBitOr: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitXor()
	{
		testBegin( "testExprBitXor" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeBitXor( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eBitXor );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprBitXor: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogAnd()
	{
		testBegin( "testExprLogAnd" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeLogAnd( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLogAnd );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLogAnd: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogNot()
	{
		testBegin( "testExprLogNot" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeLogNot( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eLogNot );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprLogNot: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogOr()
	{
		testBegin( "testExprLogOr" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeLogOr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLogOr );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLogOr: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModulo()
	{
		testBegin( "testExprModulo" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeModulo( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eModulo );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprModulo: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShift()
	{
		testBegin( "testExprLShift" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeLShift( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLShift );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLShift: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShift()
	{
		testBegin( "testExprRShift" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeRShift( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eRShift );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprRShift: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprComma()
	{
		testBegin( "testExprComma" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeComma( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eComma );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprComma: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprArrayAccess()
	{
		testBegin( "testExprArrayAccess" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeArrayAccess( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eArrayAccess );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprArrayAccess: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAssign()
	{
		testBegin( "testExprAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAddAssign()
	{
		testBegin( "testExprAddAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeAddAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAddAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAddAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivideAssign()
	{
		testBegin( "testExprDivideAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeDivideAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eDivideAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprDivideAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinusAssign()
	{
		testBegin( "testExprMinusAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeMinusAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eMinusAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprMinusAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimesAssign()
	{
		testBegin( "testExprTimesAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeTimesAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eTimesAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprTimesAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModuloAssign()
	{
		testBegin( "testExprModuloAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeModuloAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eModuloAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprModuloAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShiftAssign()
	{
		testBegin( "testExprLShiftAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeLShiftAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLShiftAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShiftAssign()
	{
		testBegin( "testExprRShiftAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeRShiftAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eRShiftAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprRShiftAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAndAssign()
	{
		testBegin( "testExprAndAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeAndAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eAndAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprAndAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprOrAssign()
	{
		testBegin( "testExprOrAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeOrAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eOrAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprOrAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprXorAssign()
	{
		testBegin( "testExprXorAssign" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeXorAssign( ast::type::getInt(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eXorAssign );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprXorAssign: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprEqual()
	{
		testBegin( "testExprEqual" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeEqual( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreater()
	{
		testBegin( "testExprGreater" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeGreater( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eGreater );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprGreater: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreaterEqual()
	{
		testBegin( "testExprGreaterEqual" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeGreaterEqual( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eGreaterEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprGreaterEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLess()
	{
		testBegin( "testExprLess" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeLess( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLess );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLess: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLessEqual()
	{
		testBegin( "testExprLessEqual" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeLessEqual( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eLessEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprLessEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprNotEqual()
	{
		testBegin( "testExprNotEqual" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeNotEqual( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eNotEqual );
		check( expr->getType()->getKind() == ast::type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getRHS() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprNotEqual: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostDecrement()
	{
		testBegin( "testExprPostDecrement" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makePostDecrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePostDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPostDecrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostIncrement()
	{
		testBegin( "testExprPostIncrement" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makePostIncrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePostIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPostIncrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreDecrement()
	{
		testBegin( "testExprPreDecrement" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makePreDecrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePreDecrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPreDecrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreIncrement()
	{
		testBegin( "testExprPreIncrement" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makePreIncrement( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::ePreIncrement );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprPreIncrement: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryMinus()
	{
		testBegin( "testExprUnaryMinus" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makeUnaryMinus( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eUnaryMinus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprUnaryMinus: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryPlus()
	{
		testBegin( "testExprUnaryPlus" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makeUnaryPlus( std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eUnaryPlus );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprUnaryPlus: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprCast()
	{
		testBegin( "testExprCast" );
		auto op = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "op" ) );
		auto expr = ast::expr::makeCast( ast::type::getFloat(), std::move( op ) );

		check( expr->getKind() == ast::expr::Kind::eCast );
		check( expr->getType()->getKind() == ast::type::Kind::eFloat );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		std::cout << "ExprCast: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprFnCall()
	{
		testBegin( "testExprFnCall" );
		{
			auto funcName = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getFunction(), "func" ) );
			ast::expr::ExprList argList;
			auto expr = ast::expr::makeFnCall( ast::type::getInt(), std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().empty() );
			std::cout << "ExprFnCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto funcName = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getFunction(), "func" ) );
			ast::expr::ExprList argList;
			argList.emplace_back( ast::expr::makeLiteral( 10 ) );
			auto expr = ast::expr::makeFnCall( ast::type::getInt(), std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 1u );

			check( expr->getArgList()[0]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == ast::expr::LiteralType::eInt );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getValue< ast::expr::LiteralType::eInt >() == 10 );
			std::cout << "ExprFnCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto funcName = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getFunction(), "func" ) );
			ast::expr::ExprList argList;
			argList.emplace_back( ast::expr::makeLiteral( 10 ) );
			argList.emplace_back( ast::expr::makeLiteral( 1.0f ) );
			auto expr = ast::expr::makeFnCall( ast::type::getInt(), std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 2u );

			check( expr->getArgList()[0]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::type::Kind::eInt );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getLiteralType() == ast::expr::LiteralType::eInt );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[0] ).getValue< ast::expr::LiteralType::eInt >() == 10 );

			check( expr->getArgList()[1]->getKind() == ast::expr::Kind::eLiteral );
			check( expr->getArgList()[1]->getType()->getKind() == ast::type::Kind::eFloat );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[1] ).getLiteralType() == ast::expr::LiteralType::eFloat );
			check( static_cast< ast::expr::Literal const & >( *expr->getArgList()[1] ).getValue< ast::expr::LiteralType::eFloat >() == 1.0f );
			std::cout << "ExprFnCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprIntrinsicCall()
	{
		testBegin( "testExprIntrinsicCall" );
		{
			ast::expr::ExprList argList;
			argList.emplace_back( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "x" ) ) );
			auto expr = ast::expr::makeIntrinsicCall( ast::type::getInt(), ast::expr::Intrinsic::eAbs1I, std::move( argList ) );

			check( expr->getKind() == ast::expr::Kind::eIntrinsicCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getIntrinsic() == ast::expr::Intrinsic::eAbs1I );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == ast::type::getInt() );
			std::cout << "ExprIntrinsicCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprImageAccessCall()
	{
		testBegin( "testExprImageAccessCall" );
		{
			ast::expr::ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getImage( config ), "x" ) ) );
			auto expr = ast::expr::makeImageAccessCall( ast::type::getInt(), ast::expr::ImageAccess::eImageSize1DI, std::move( argList ) );

			check( expr->getKind() == ast::expr::Kind::eImageAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getImageAccess() == ast::expr::ImageAccess::eImageSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == ast::type::getImage( config ) );
			std::cout << "ExprImageAccessCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprTextureAccessCall()
	{
		testBegin( "testExprTextureAccessCall" );
		{
			ast::expr::ExprList argList;
			ast::type::ImageConfiguration config{};
			argList.emplace_back( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getSampledImage( config ), "x" ) ) );
			auto expr = ast::expr::makeTextureAccessCall( ast::type::getInt(), ast::expr::TextureAccess::eTextureSize1DI, std::move( argList ) );

			check( expr->getKind() == ast::expr::Kind::eTextureAccessCall );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getTextureAccess() == ast::expr::TextureAccess::eTextureSize1DI );

			check( expr->getArgList().size() == 1 );
			check( expr->getArgList().back()->getKind() == ast::expr::Kind::eIdentifier );
			check( expr->getArgList().back()->getType() == ast::type::getSampledImage( config ) );
			std::cout << "ExprTextureAccessCall: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprAggrInit()
	{
		testBegin( "testExprAggrInit" );
		{
			auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::makeType( ast::type::Kind::eInt, 4u ), "lhs" ) );
			ast::expr::ExprList rhs;
			auto expr = ast::expr::makeAggrInit( std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == ast::expr::Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getIdentifier()->getType()->getKind() == ast::type::Kind::eInt );
			check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
			check( expr->getIdentifier()->getVariable()->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getInitialisers().empty() );
			std::cout << "ExprAggrInit (empty): " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::makeType( ast::type::Kind::eInt, 4u ), "lhs" ) );
			ast::expr::ExprList rhs;
			rhs.emplace_back( ast::expr::makeLiteral( 10 ) );
			rhs.emplace_back( ast::expr::makeLiteral( 20 ) );
			rhs.emplace_back( ast::expr::makeLiteral( 30 ) );
			rhs.emplace_back( ast::expr::makeLiteral( 40 ) );
			auto expr = ast::expr::makeAggrInit( std::move( lhs ), std::move( rhs ) );

			check( expr->getKind() == ast::expr::Kind::eAggrInit );
			check( expr->getType()->getKind() == ast::type::Kind::eInt );

			check( expr->getIdentifier()->getType()->getKind() == ast::type::Kind::eInt );
			check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
			check( expr->getIdentifier()->getVariable()->getType()->getKind() == ast::type::Kind::eInt );

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

	void testExprInit()
	{
		testBegin( "testExprInit" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeInit( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::expr::Kind::eInit );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getIdentifier()->getType()->getKind() == ast::type::Kind::eInt );
		check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
		check( expr->getIdentifier()->getVariable()->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getInitialiser()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getInitialiser()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getInitialiser() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getInitialiser() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprInit: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMbrSelect()
	{
		testBegin( "testExprMbrSelect" );
		auto outerVar = ast::var::makeVariable( ast::type::getInt(), "outerVar" );
		auto member = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "innerVar" ) );
		auto expr = ast::expr::makeMbrSelect( ast::expr::makeIdentifier( outerVar ), 0u, std::move( member ) );

		check( expr->getKind() == ast::expr::Kind::eMbrSelect );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getOuterExpr()->getType()->getKind() == ast::type::Kind::eInt );
		check( expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOuterExpr() ).getVariable()->getName() == "outerVar" );

		check( expr->getOperand()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getOperand() ).getVariable()->getName() == "innerVar" );
		std::cout << "ExprMbrSelect: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprQuestion()
	{
		testBegin( "testExprQuestion" );
		auto ctrlExpr = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "ctrl" ) );
		auto trueExpr = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto falseExpr = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeQuestion( ast::type::getInt(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

		check( expr->getKind() == ast::expr::Kind::eQuestion );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< ast::expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eBoolean );
		check( static_cast< ast::expr::Identifier const & >( *expr->getCtrlExpr() ).getVariable()->getName() == "ctrl" );

		check( expr->getTrueExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getTrueExpr()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

		check( expr->getFalseExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getFalseExpr()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getFalseExpr() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getFalseExpr() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprQuestion: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprSwitchCase()
	{
		testBegin( "testExprSwitchCase" );
		auto label = ast::expr::makeLiteral( 10 );
		auto expr = ast::expr::makeSwitchCase( std::move( label ) );

		check( expr->getKind() == ast::expr::Kind::eSwitchCase );
		check( expr->getType()->getKind() == ast::type::Kind::eInt );

		check( expr->getLabel()->getKind() == ast::expr::Kind::eLiteral );
		check( expr->getLabel()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getLabel() ).getLiteralType() == ast::expr::LiteralType::eInt );
		check( static_cast< ast::expr::Literal const & >( *expr->getLabel() ).getValue< ast::expr::LiteralType::eInt >() == 10 );
		std::cout << "ExprSwitchCase: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprSwitchTest()
	{
		testBegin( "testExprSwitchTest" );
		auto value = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto expr = ast::expr::makeSwitchTest( std::move( value ) );

		check( expr->getKind() == ast::expr::Kind::eSwitchTest );
		check( expr->getType()->getKind() == ast::type::Kind::eUndefined );

		check( expr->getValue()->getKind() == ast::expr::Kind::eIdentifier );
		check( expr->getValue()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getValue() ).getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( static_cast< ast::expr::Identifier const & >( *expr->getValue() ).getVariable()->getName() == "lhs" );
		std::cout << "ExprSwitchTest: " << ast::debug::ExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestExpressions" );
	testExprLiteral();
	testExprIdentifier();
	testExprAdd();
	testExprMinus();
	testExprTimes();
	testExprDivide();
	testExprBitAnd();
	testExprBitNot();
	testExprBitOr();
	testExprBitXor();
	testExprLogAnd();
	testExprLogNot();
	testExprLogOr();
	testExprModulo();
	testExprLShift();
	testExprRShift();
	testExprComma();
	testExprArrayAccess();
	testExprAssign();
	testExprAddAssign();
	testExprDivideAssign();
	testExprMinusAssign();
	testExprTimesAssign();
	testExprModuloAssign();
	testExprLShiftAssign();
	testExprRShiftAssign();
	testExprAndAssign();
	testExprOrAssign();
	testExprXorAssign();
	testExprEqual();
	testExprGreater();
	testExprGreaterEqual();
	testExprLess();
	testExprLessEqual();
	testExprNotEqual();
	testExprPostDecrement();
	testExprPostIncrement();
	testExprPreDecrement();
	testExprPreIncrement();
	testExprUnaryMinus();
	testExprUnaryPlus();
	testExprCast();
	testExprFnCall();
	testExprIntrinsicCall();
	testExprTextureAccessCall();
	testExprImageAccessCall();
	testExprInit();
	testExprAggrInit();
	testExprMbrSelect();
	testExprQuestion();
	testExprSwitchCase();
	testExprSwitchTest();
	testSuiteEnd();
}
