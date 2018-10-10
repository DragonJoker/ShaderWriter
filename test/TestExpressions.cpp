#include "Common.hpp"

#include <ASTGenerator/Var/Variable.hpp>
#include <ASTGenerator/Debug/DebugExprVisitor.hpp>

namespace
{
	void testExprLiteral()
	{
		testBegin( "testExprLiteral" );
		{
			auto expr = ast::makeLiteralExpr( false );

			check( expr->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eBool );
			check( expr->getValue< ast::ExprLiteral::ValueType::eBool >() == false );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::makeLiteralExpr( 1.0f );

			check( expr->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::Type::Kind::eFloat );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eFloat );
			check( expr->getValue< ast::ExprLiteral::ValueType::eFloat >() == 1.0f );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::makeLiteralExpr( 10 );

			check( expr->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::Type::Kind::eInt );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( expr->getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::makeLiteralExpr( 10u );

			check( expr->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getType()->getKind() == ast::Type::Kind::eUInt );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eUInt );
			check( expr->getValue< ast::ExprLiteral::ValueType::eUInt >() == 10u );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}
	
	void testExprIdentifier()
	{
		testBegin( "testExprIdentifier" );
		auto expr = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "var0" ) );

		check( expr->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );
		check( expr->getVariable()->getName() == "var0" );
		check( expr->getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprIdentifier: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAdd()
	{
		testBegin( "testExprAdd" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAddExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAdd );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAdd: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinus()
	{
		testBegin( "testExprMinus" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeMinusExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eMinus );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprMinus: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimes()
	{
		testBegin( "testExprTimes" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeTimesExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eTimes );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprTimes: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivide()
	{
		testBegin( "testExprTimes" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr= ast::makeDivideExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eDivide );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprDivide: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitAnd()
	{
		testBegin( "testExprBitAnd" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeBitAndExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eBitAnd );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprBitAnd: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitNot()
	{
		testBegin( "testExprBitNot" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makeBitNotExpr( ast::getIntType(), std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eBitNot );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprBitNot: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitOr()
	{
		testBegin( "testExprBitOr" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeBitOrExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eBitOr );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprBitOr: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitXor()
	{
		testBegin( "testExprBitXor" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeBitXorExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eBitXor );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprBitXor: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogAnd()
	{
		testBegin( "testExprLogAnd" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLogAndExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLogAnd );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLogAnd: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogNot()
	{
		testBegin( "testExprLogNot" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLogNotExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eLogNot );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprLogNot: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogOr()
	{
		testBegin( "testExprLogOr" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLogOrExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLogOr );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLogOr: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModulo()
	{
		testBegin( "testExprModulo" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeModuloExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eModulo );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprModulo: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShift()
	{
		testBegin( "testExprLShift" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLShiftExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLShift );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLShift: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShift()
	{
		testBegin( "testExprRShift" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeRShiftExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eRShift );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprRShift: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprComma()
	{
		testBegin( "testExprComma" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeCommaExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eComma );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprComma: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAssign()
	{
		testBegin( "testExprAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAddAssign()
	{
		testBegin( "testExprAddAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAddAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAddAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAddAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivideAssign()
	{
		testBegin( "testExprDivideAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeDivideAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eDivideAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprDivideAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinusAssign()
	{
		testBegin( "testExprMinusAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeMinusAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eMinusAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprMinusAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimesAssign()
	{
		testBegin( "testExprTimesAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeTimesAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eTimesAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprTimesAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModuloAssign()
	{
		testBegin( "testExprModuloAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeModuloAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eModuloAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprModuloAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShiftAssign()
	{
		testBegin( "testExprLShiftAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLShiftAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLShiftAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLShiftAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShiftAssign()
	{
		testBegin( "testExprRShiftAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeRShiftAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eRShiftAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprRShiftAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAndAssign()
	{
		testBegin( "testExprAndAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAndAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAndAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAndAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprOrAssign()
	{
		testBegin( "testExprOrAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeOrAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eOrAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprOrAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprXorAssign()
	{
		testBegin( "testExprXorAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeXorAssignExpr( ast::getIntType(), std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eXorAssign );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprXorAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprEqual()
	{
		testBegin( "testExprEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eEqual );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreater()
	{
		testBegin( "testExprGreater" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeGreaterExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eGreater );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprGreater: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreaterEqual()
	{
		testBegin( "testExprGreaterEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeGreaterEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eGreaterEqual );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprGreaterEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLess()
	{
		testBegin( "testExprLess" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLessExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLess );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLess: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLessEqual()
	{
		testBegin( "testExprLessEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLessEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLessEqual );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLessEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprNotEqual()
	{
		testBegin( "testExprNotEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeNotEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eNotEqual );
		check( expr->getType()->getKind() == ast::Type::Kind::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprNotEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostDecrement()
	{
		testBegin( "testExprPostDecrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makePostDecrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePostDecrement );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprPostDecrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostIncrement()
	{
		testBegin( "testExprPostIncrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makePostIncrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePostIncrement );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprPostIncrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreDecrement()
	{
		testBegin( "testExprPreDecrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makePreDecrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePreDecrement );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprPreDecrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreIncrement()
	{
		testBegin( "testExprPreIncrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makePreIncrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePreIncrement );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprPreIncrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryMinus()
	{
		testBegin( "testExprUnaryMinus" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makeUnaryMinusExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eUnaryMinus );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprUnaryMinus: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryPlus()
	{
		testBegin( "testExprUnaryPlus" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makeUnaryPlusExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eUnaryPlus );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprUnaryPlus: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprCast()
	{
		testBegin( "testExprCast" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "op" ) );
		auto expr = ast::makeCastExpr( ast::getFloatType(), std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eCast );
		check( expr->getType()->getKind() == ast::Type::Kind::eFloat );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		std::cout << "ExprCast: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprFnCall()
	{
		testBegin( "testExprFnCall" );
		{
			auto funcName = ast::makeIdentifierExpr( ast::makeVariable( ast::getFunctionType(), "func" ) );
			ast::ExprList argList;
			auto expr = ast::makeFnCallExpr( ast::getIntType(), std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::Expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::Type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::Type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::Type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().empty() );
			std::cout << "ExprFnCall: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto funcName = ast::makeIdentifierExpr( ast::makeVariable( ast::getFunctionType(), "func" ) );
			ast::ExprList argList;
			argList.emplace_back( ast::makeLiteralExpr( 10 ) );
			auto expr = ast::makeFnCallExpr( ast::getIntType(), std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::Expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::Type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::Type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::Type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 1u );

			check( expr->getArgList()[0]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::Type::Kind::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
			std::cout << "ExprFnCall: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto funcName = ast::makeIdentifierExpr( ast::makeVariable( ast::getFunctionType(), "func" ) );
			ast::ExprList argList;
			argList.emplace_back( ast::makeLiteralExpr( 10 ) );
			argList.emplace_back( ast::makeLiteralExpr( 1.0f ) );
			auto expr = ast::makeFnCallExpr( ast::getIntType(), std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::Expr::Kind::eFnCall );
			check( expr->getType()->getKind() == ast::Type::Kind::eInt );

			check( expr->getFn()->getType()->getKind() == ast::Type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getType()->getKind() == ast::Type::Kind::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 2u );

			check( expr->getArgList()[0]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType()->getKind() == ast::Type::Kind::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );

			check( expr->getArgList()[1]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getArgList()[1]->getType()->getKind() == ast::Type::Kind::eFloat );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[1] ).getValueType() == ast::ExprLiteral::ValueType::eFloat );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[1] ).getValue< ast::ExprLiteral::ValueType::eFloat >() == 1.0f );
			std::cout << "ExprFnCall: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprInit()
	{
		testBegin( "testExprInit" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeInitExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eInit );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getIdentifier()->getType()->getKind() == ast::Type::Kind::eInt );
		check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
		check( expr->getIdentifier()->getVariable()->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getInitialiser()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getInitialiser()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getInitialiser() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getInitialiser() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprInit: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMbrSelect()
	{
		testBegin( "testExprMbrSelect" );
		auto outerVar = ast::makeVariable( ast::getIntType(), "outerVar" );
		auto member = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "innerVar" ) );
		auto expr = ast::makeMbrSelectExpr( outerVar, std::move( member ) );

		check( expr->getKind() == ast::Expr::Kind::eMbrSelect );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getOuterVar().getType()->getKind() == ast::Type::Kind::eInt );
		check( expr->getOuterVar().getName() == "outerVar" );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "innerVar" );
		std::cout << "ExprMbrSelect: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprQuestion()
	{
		testBegin( "testExprQuestion" );
		auto ctrlExpr = ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "ctrl" ) );
		auto trueExpr = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto falseExpr = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeQuestionExpr( ast::getIntType(), std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

		check( expr->getKind() == ast::Expr::Kind::eQuestion );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getCtrlExpr() ).getVariable()->getType()->getKind() == ast::Type::Kind::eBoolean );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getCtrlExpr() ).getVariable()->getName() == "ctrl" );

		check( expr->getTrueExpr()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getTrueExpr()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getTrueExpr() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

		check( expr->getFalseExpr()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getFalseExpr()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getFalseExpr() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getFalseExpr() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprQuestion: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprSwitchCase()
	{
		testBegin( "testExprSwitchCase" );
		auto label = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeSwitchCaseExpr( std::move( label ) );

		check( expr->getKind() == ast::Expr::Kind::eSwitchCase );
		check( expr->getType()->getKind() == ast::Type::Kind::eInt );

		check( expr->getLabel()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getLabel()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getLabel() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getLabel() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprSwitchCase: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprSwitchTest()
	{
		testBegin( "testExprSwitchTest" );
		auto value = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto expr = ast::makeSwitchTestExpr( std::move( value ) );

		check( expr->getKind() == ast::Expr::Kind::eSwitchTest );
		check( expr->getType()->getKind() == ast::Type::Kind::eUndefined );

		check( expr->getValue()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getValue()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getValue() ).getVariable()->getType()->getKind() == ast::Type::Kind::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getValue() ).getVariable()->getName() == "lhs" );
		std::cout << "ExprSwitchTest: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
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
	testExprInit();
	testExprMbrSelect();
	testExprQuestion();
	testExprSwitchCase();
	testExprSwitchTest();
	testSuiteEnd();
}
