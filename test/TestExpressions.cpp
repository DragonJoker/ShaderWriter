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
			check( expr->getType() == ast::Type::eBoolean );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eBool );
			check( expr->getValue< ast::ExprLiteral::ValueType::eBool >() == false );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::makeLiteralExpr( 1.0f );

			check( expr->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getType() == ast::Type::eFloat );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eFloat );
			check( expr->getValue< ast::ExprLiteral::ValueType::eFloat >() == 1.0f );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::makeLiteralExpr( 10 );

			check( expr->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getType() == ast::Type::eInt );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( expr->getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto expr = ast::makeLiteralExpr( 10u );

			check( expr->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getType() == ast::Type::eUInt );
			check( expr->getValueType() == ast::ExprLiteral::ValueType::eUInt );
			check( expr->getValue< ast::ExprLiteral::ValueType::eUInt >() == 10u );
			std::cout << "ExprLiteral: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}
	
	void testExprIdentifier()
	{
		testBegin( "testExprIdentifier" );
		auto expr = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "var0" ) );

		check( expr->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getType() == ast::Type::eInt );
		check( expr->getVariable()->getName() == "var0" );
		check( expr->getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprIdentifier: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAdd()
	{
		testBegin( "testExprAdd" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAddExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAdd );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAdd: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinus()
	{
		testBegin( "testExprMinus" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeMinusExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eMinus );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprMinus: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimes()
	{
		testBegin( "testExprTimes" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeTimesExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eTimes );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprTimes: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivide()
	{
		testBegin( "testExprTimes" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr= ast::makeDivideExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eDivide );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprDivide: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitAnd()
	{
		testBegin( "testExprBitAnd" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeBitAndExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eBitAnd );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprBitAnd: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitNot()
	{
		testBegin( "testExprBitNot" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makeBitNotExpr( ast::Type::eInt, std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eBitNot );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprBitNot: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitOr()
	{
		testBegin( "testExprBitOr" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeBitOrExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eBitOr );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprBitOr: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprBitXor()
	{
		testBegin( "testExprBitXor" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeBitXorExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eBitXor );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprBitXor: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogAnd()
	{
		testBegin( "testExprLogAnd" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLogAndExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLogAnd );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLogAnd: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogNot()
	{
		testBegin( "testExprLogNot" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLogNotExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eLogNot );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprLogNot: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLogOr()
	{
		testBegin( "testExprLogOr" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLogOrExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLogOr );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLogOr: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModulo()
	{
		testBegin( "testExprModulo" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeModuloExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eModulo );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprModulo: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShift()
	{
		testBegin( "testExprLShift" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLShiftExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLShift );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLShift: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShift()
	{
		testBegin( "testExprRShift" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeRShiftExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eRShift );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprRShift: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprComma()
	{
		testBegin( "testExprComma" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeCommaExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eComma );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprComma: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAssign()
	{
		testBegin( "testExprAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAddAssign()
	{
		testBegin( "testExprAddAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAddAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAddAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAddAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprDivideAssign()
	{
		testBegin( "testExprDivideAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeDivideAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eDivideAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprDivideAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMinusAssign()
	{
		testBegin( "testExprMinusAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeMinusAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eMinusAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprMinusAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprTimesAssign()
	{
		testBegin( "testExprTimesAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeTimesAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eTimesAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprTimesAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprModuloAssign()
	{
		testBegin( "testExprModuloAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeModuloAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eModuloAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprModuloAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLShiftAssign()
	{
		testBegin( "testExprLShiftAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLShiftAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLShiftAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLShiftAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprRShiftAssign()
	{
		testBegin( "testExprRShiftAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeRShiftAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eRShiftAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprRShiftAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprAndAssign()
	{
		testBegin( "testExprAndAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeAndAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eAndAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprAndAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprOrAssign()
	{
		testBegin( "testExprOrAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeOrAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eOrAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprOrAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprXorAssign()
	{
		testBegin( "testExprXorAssign" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeXorAssignExpr( ast::Type::eInt, std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eXorAssign );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprXorAssign: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprEqual()
	{
		testBegin( "testExprEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eEqual );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreater()
	{
		testBegin( "testExprGreater" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeGreaterExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eGreater );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprGreater: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprGreaterEqual()
	{
		testBegin( "testExprGreaterEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeGreaterEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eGreaterEqual );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprGreaterEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLess()
	{
		testBegin( "testExprLess" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLessExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLess );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLess: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprLessEqual()
	{
		testBegin( "testExprLessEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeLessEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eLessEqual );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprLessEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprNotEqual()
	{
		testBegin( "testExprNotEqual" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeNotEqualExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eNotEqual );
		check( expr->getType() == ast::Type::eBoolean );

		check( expr->getLHS()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getLHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr->getRHS()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getRHS()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprNotEqual: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostDecrement()
	{
		testBegin( "testExprPostDecrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makePostDecrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePostDecrement );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprPostDecrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPostIncrement()
	{
		testBegin( "testExprPostIncrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makePostIncrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePostIncrement );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprPostIncrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreDecrement()
	{
		testBegin( "testExprPreDecrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makePreDecrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePreDecrement );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprPreDecrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprPreIncrement()
	{
		testBegin( "testExprPreIncrement" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makePreIncrementExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::ePreIncrement );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprPreIncrement: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryMinus()
	{
		testBegin( "testExprUnaryMinus" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makeUnaryMinusExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eUnaryMinus );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprUnaryMinus: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprUnaryPlus()
	{
		testBegin( "testExprUnaryPlus" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makeUnaryPlusExpr( std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eUnaryPlus );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprUnaryPlus: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprCast()
	{
		testBegin( "testExprCast" );
		auto op = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "op" ) );
		auto expr = ast::makeCastExpr( ast::Type::eFloat, std::move( op ) );

		check( expr->getKind() == ast::Expr::Kind::eCast );
		check( expr->getType() == ast::Type::eFloat );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		std::cout << "ExprCast: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprFnCall()
	{
		testBegin( "testExprFnCall" );
		{
			auto funcName = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eFunction, "func" ) );
			ast::ExprList argList;
			auto expr = ast::makeFnCallExpr( ast::Type::eInt, std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::Expr::Kind::eFnCall );
			check( expr->getType() == ast::Type::eInt );

			check( expr->getFn()->getType() == ast::Type::eFunction );
			check( expr->getFn()->getVariable()->getType() == ast::Type::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().empty() );
			std::cout << "ExprFnCall: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto funcName = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eFunction, "func" ) );
			ast::ExprList argList;
			argList.emplace_back( ast::makeLiteralExpr( 10 ) );
			auto expr = ast::makeFnCallExpr( ast::Type::eInt, std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::Expr::Kind::eFnCall );
			check( expr->getType() == ast::Type::eInt );

			check( expr->getFn()->getType() == ast::Type::eFunction );
			check( expr->getFn()->getVariable()->getType() == ast::Type::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 1u );

			check( expr->getArgList()[0]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType() == ast::Type::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
			std::cout << "ExprFnCall: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		{
			auto funcName = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eFunction, "func" ) );
			ast::ExprList argList;
			argList.emplace_back( ast::makeLiteralExpr( 10 ) );
			argList.emplace_back( ast::makeLiteralExpr( 1.0f ) );
			auto expr = ast::makeFnCallExpr( ast::Type::eInt, std::move( funcName ), std::move( argList ) );

			check( expr->getKind() == ast::Expr::Kind::eFnCall );
			check( expr->getType() == ast::Type::eInt );

			check( expr->getFn()->getType() == ast::Type::eFunction );
			check( expr->getFn()->getVariable()->getType() == ast::Type::eFunction );
			check( expr->getFn()->getVariable()->getName() == "func" );

			check( expr->getArgList().size() == 2u );

			check( expr->getArgList()[0]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getArgList()[0]->getType() == ast::Type::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[0] ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );

			check( expr->getArgList()[1]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr->getArgList()[1]->getType() == ast::Type::eFloat );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[1] ).getValueType() == ast::ExprLiteral::ValueType::eFloat );
			check( static_cast< ast::ExprLiteral const & >( *expr->getArgList()[1] ).getValue< ast::ExprLiteral::ValueType::eFloat >() == 1.0f );
			std::cout << "ExprFnCall: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		}
		testEnd();
	}

	void testExprInit()
	{
		testBegin( "testExprInit" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeInitExpr( std::move( lhs ), std::move( rhs ) );

		check( expr->getKind() == ast::Expr::Kind::eInit );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getIdentifier()->getType() == ast::Type::eInt );
		check( expr->getIdentifier()->getVariable()->getName() == "lhs" );
		check( expr->getIdentifier()->getVariable()->getType() == ast::Type::eInt );

		check( expr->getInitialiser()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getInitialiser()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getInitialiser() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getInitialiser() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprInit: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprMbrSelect()
	{
		testBegin( "testExprMbrSelect" );
		auto outerVar = ast::makeVariable( ast::Type::eInt, "outerVar" );
		auto member = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "innerVar" ) );
		auto expr = ast::makeMbrSelectExpr( outerVar, std::move( member ) );

		check( expr->getKind() == ast::Expr::Kind::eMbrSelect );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getOuterVar().getType() == ast::Type::eInt );
		check( expr->getOuterVar().getName() == "outerVar" );

		check( expr->getOperand()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getOperand()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getOperand() ).getVariable()->getName() == "innerVar" );
		std::cout << "ExprMbrSelect: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprQuestion()
	{
		testBegin( "testExprQuestion" );
		auto ctrlExpr = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eBoolean, "ctrl" ) );
		auto trueExpr = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto falseExpr = ast::makeLiteralExpr( 10 );
		auto expr = ast::makeQuestionExpr( ast::Type::eInt, std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) );

		check( expr->getKind() == ast::Expr::Kind::eQuestion );
		check( expr->getType() == ast::Type::eInt );

		check( expr->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getCtrlExpr()->getType() == ast::Type::eBoolean );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getCtrlExpr() ).getVariable()->getType() == ast::Type::eBoolean );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getCtrlExpr() ).getVariable()->getName() == "ctrl" );

		check( expr->getTrueExpr()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getTrueExpr()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getTrueExpr() ).getVariable()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getTrueExpr() ).getVariable()->getName() == "lhs" );

		check( expr->getFalseExpr()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getFalseExpr()->getType() == ast::Type::eInt );
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
		check( expr->getType() == ast::Type::eInt );

		check( expr->getLabel()->getKind() == ast::Expr::Kind::eLiteral );
		check( expr->getLabel()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getLabel() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( *expr->getLabel() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		std::cout << "ExprSwitchCase: " << ast::DebugExprVisitor::submit( expr.get() ) << std::endl;
		testEnd();
	}

	void testExprSwitchTest()
	{
		testBegin( "testExprSwitchTest" );
		auto value = ast::makeIdentifierExpr( ast::makeVariable( ast::Type::eInt, "lhs" ) );
		auto expr = ast::makeSwitchTestExpr( std::move( value ) );

		check( expr->getKind() == ast::Expr::Kind::eSwitchTest );
		check( expr->getType() == ast::Type::eUndefined );

		check( expr->getValue()->getKind() == ast::Expr::Kind::eIdentifier );
		check( expr->getValue()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( *expr->getValue() ).getVariable()->getType() == ast::Type::eInt );
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
