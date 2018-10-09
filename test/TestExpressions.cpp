#include "Common.hpp"

#include <ASTGenerator/Variable.hpp>
#include <ASTGenerator/Expr/ExprAdd.hpp>
#include <ASTGenerator/Expr/ExprAddAssign.hpp>
#include <ASTGenerator/Expr/ExprAndAssign.hpp>
#include <ASTGenerator/Expr/ExprAssign.hpp>
#include <ASTGenerator/Expr/ExprBitAnd.hpp>
#include <ASTGenerator/Expr/ExprBitNot.hpp>
#include <ASTGenerator/Expr/ExprBitOr.hpp>
#include <ASTGenerator/Expr/ExprBitXor.hpp>
#include <ASTGenerator/Expr/ExprCast.hpp>
#include <ASTGenerator/Expr/ExprComma.hpp>
#include <ASTGenerator/Expr/ExprDivide.hpp>
#include <ASTGenerator/Expr/ExprDivideAssign.hpp>
#include <ASTGenerator/Expr/ExprEqual.hpp>
#include <ASTGenerator/Expr/ExprFnCall.hpp>
#include <ASTGenerator/Expr/ExprGreater.hpp>
#include <ASTGenerator/Expr/ExprGreaterEqual.hpp>
#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprInit.hpp>
#include <ASTGenerator/Expr/ExprLess.hpp>
#include <ASTGenerator/Expr/ExprLessEqual.hpp>
#include <ASTGenerator/Expr/ExprLiteral.hpp>
#include <ASTGenerator/Expr/ExprLogAnd.hpp>
#include <ASTGenerator/Expr/ExprLogNot.hpp>
#include <ASTGenerator/Expr/ExprLogOr.hpp>
#include <ASTGenerator/Expr/ExprLogXor.hpp>
#include <ASTGenerator/Expr/ExprLShift.hpp>
#include <ASTGenerator/Expr/ExprLShiftAssign.hpp>
#include <ASTGenerator/Expr/ExprMbrSelect.hpp>
#include <ASTGenerator/Expr/ExprMinus.hpp>
#include <ASTGenerator/Expr/ExprMinusAssign.hpp>
#include <ASTGenerator/Expr/ExprModulo.hpp>
#include <ASTGenerator/Expr/ExprModuloAssign.hpp>
#include <ASTGenerator/Expr/ExprNotEqual.hpp>
#include <ASTGenerator/Expr/ExprOrAssign.hpp>
#include <ASTGenerator/Expr/ExprPostDecrement.hpp>
#include <ASTGenerator/Expr/ExprPostIncrement.hpp>
#include <ASTGenerator/Expr/ExprPreDecrement.hpp>
#include <ASTGenerator/Expr/ExprPreIncrement.hpp>
#include <ASTGenerator/Expr/ExprQuestion.hpp>
#include <ASTGenerator/Expr/ExprRShift.hpp>
#include <ASTGenerator/Expr/ExprRShiftAssign.hpp>
#include <ASTGenerator/Expr/ExprSwitchCase.hpp>
#include <ASTGenerator/Expr/ExprSwitchTest.hpp>
#include <ASTGenerator/Expr/ExprTimes.hpp>
#include <ASTGenerator/Expr/ExprTimesAssign.hpp>
#include <ASTGenerator/Expr/ExprUnaryMinus.hpp>
#include <ASTGenerator/Expr/ExprUnaryPlus.hpp>
#include <ASTGenerator/Expr/ExprXorAssign.hpp>

namespace
{
	void testExprLiteral()
	{
		testBegin( "testExprLiteral" );
		{
			ast::ExprLiteral lit{ false };

			check( lit.getKind() == ast::Expr::Kind::eLiteral );
			check( lit.getType() == ast::Type::eBoolean );
			check( lit.getValueType() == ast::ExprLiteral::ValueType::eBool );
			check( lit.getValue< ast::ExprLiteral::ValueType::eBool >() == false );
		}
		{
			ast::ExprLiteral lit{ 1.0f };

			check( lit.getKind() == ast::Expr::Kind::eLiteral );
			check( lit.getType() == ast::Type::eFloat );
			check( lit.getValueType() == ast::ExprLiteral::ValueType::eFloat );
			check( lit.getValue< ast::ExprLiteral::ValueType::eFloat >() == 1.0f );
		}
		{
			ast::ExprLiteral lit{ 10 };

			check( lit.getKind() == ast::Expr::Kind::eLiteral );
			check( lit.getType() == ast::Type::eInt );
			check( lit.getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( lit.getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		}
		{
			ast::ExprLiteral lit{ 10u };

			check( lit.getKind() == ast::Expr::Kind::eLiteral );
			check( lit.getType() == ast::Type::eUInt );
			check( lit.getValueType() == ast::ExprLiteral::ValueType::eUInt );
			check( lit.getValue< ast::ExprLiteral::ValueType::eUInt >() == 10u );
		}
		testEnd();
	}
	
	void testExprIdentifier()
	{
		testBegin( "testExprIdentifier" );
		ast::ExprIdentifier ident{ std::make_shared< ast::Variable >( ast::Type::eInt, "var0" ) };

		check( ident.getKind() == ast::Expr::Kind::eIdentifier );
		check( ident.getType() == ast::Type::eInt );
		check( ident.getVariable()->getName() == "var0" );
		check( ident.getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprAdd()
	{
		testBegin( "testExprAdd" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprAdd expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eAdd );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprMinus()
	{
		testBegin( "testExprMinus" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprMinus expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eMinus );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprTimes()
	{
		testBegin( "testExprTimes" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprTimes expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eTimes );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprDivide()
	{
		testBegin( "testExprTimes" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprDivide expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eDivide );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprBitAnd()
	{
		testBegin( "testExprBitAnd" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprBitAnd expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eBitAnd );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprBitNot()
	{
		testBegin( "testExprBitNot" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprBitNot expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eBitNot );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprBitOr()
	{
		testBegin( "testExprBitOr" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprBitOr expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eBitOr );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprBitXor()
	{
		testBegin( "testExprBitXor" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprBitXor expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eBitXor );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLogAnd()
	{
		testBegin( "testExprLogAnd" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLogAnd expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLogAnd );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLogNot()
	{
		testBegin( "testExprLogNot" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLogNot expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLogNot );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLogOr()
	{
		testBegin( "testExprLogOr" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLogOr expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLogOr );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLogXor()
	{
		testBegin( "testExprLogXor" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLogXor expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLogXor );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprModulo()
	{
		testBegin( "testExprModulo" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprModulo expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eModulo );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLShift()
	{
		testBegin( "testExprLShift" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLShift expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLShift );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprRShift()
	{
		testBegin( "testExprRShift" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprRShift expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eRShift );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprComma()
	{
		testBegin( "testExprComma" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprComma expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eComma );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprAssign()
	{
		testBegin( "testExprAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprAddAssign()
	{
		testBegin( "testExprAddAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprAddAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eAddAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprDivideAssign()
	{
		testBegin( "testExprDivideAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprDivideAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eDivideAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprMinusAssign()
	{
		testBegin( "testExprMinusAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprMinusAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eMinusAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprTimesAssign()
	{
		testBegin( "testExprTimesAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprTimesAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eTimesAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprModuloAssign()
	{
		testBegin( "testExprModuloAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprModuloAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eModuloAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLShiftAssign()
	{
		testBegin( "testExprLShiftAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLShiftAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLShiftAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprRShiftAssign()
	{
		testBegin( "testExprRShiftAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprRShiftAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eRShiftAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprAndAssign()
	{
		testBegin( "testExprAndAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprAndAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eAndAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprOrAssign()
	{
		testBegin( "testExprOrAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprOrAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eOrAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprXorAssign()
	{
		testBegin( "testExprXorAssign" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprXorAssign expr{ ast::Type::eInt, std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eXorAssign );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprEqual()
	{
		testBegin( "testExprEqual" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprEqual expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eEqual );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprGreater()
	{
		testBegin( "testExprGreater" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprGreater expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eGreater );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprGreaterEqual()
	{
		testBegin( "testExprGreaterEqual" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprGreaterEqual expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eGreaterEqual );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLess()
	{
		testBegin( "testExprLess" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLess expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLess );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprLessEqual()
	{
		testBegin( "testExprLessEqual" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprLessEqual expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eLessEqual );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprNotEqual()
	{
		testBegin( "testExprNotEqual" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprNotEqual expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eNotEqual );
		check( expr.getType() == ast::Type::eBoolean );

		check( expr.getLHS().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getLHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getName() == "lhs" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getLHS() ).getVariable()->getType() == ast::Type::eInt );

		check( expr.getRHS().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getRHS().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getRHS() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprPostDecrement()
	{
		testBegin( "testExprPostDecrement" );
		auto op = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "op" ) );
		ast::ExprPostDecrement expr{ std::move( op ) };

		check( expr.getKind() == ast::Expr::Kind::ePostDecrement );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprPostIncrement()
	{
		testBegin( "testExprPostIncrement" );
		auto op = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "op" ) );
		ast::ExprPostIncrement expr{ std::move( op ) };

		check( expr.getKind() == ast::Expr::Kind::ePostIncrement );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprPreDecrement()
	{
		testBegin( "testExprPreDecrement" );
		auto op = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "op" ) );
		ast::ExprPreDecrement expr{ std::move( op ) };

		check( expr.getKind() == ast::Expr::Kind::ePreDecrement );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprPreIncrement()
	{
		testBegin( "testExprPreIncrement" );
		auto op = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "op" ) );
		ast::ExprPreIncrement expr{ std::move( op ) };

		check( expr.getKind() == ast::Expr::Kind::ePreIncrement );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprUnaryMinus()
	{
		testBegin( "testExprUnaryMinus" );
		auto op = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "op" ) );
		ast::ExprUnaryMinus expr{ std::move( op ) };

		check( expr.getKind() == ast::Expr::Kind::eUnaryMinus );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprUnaryPlus()
	{
		testBegin( "testExprUnaryPlus" );
		auto op = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "op" ) );
		ast::ExprUnaryPlus expr{ std::move( op ) };

		check( expr.getKind() == ast::Expr::Kind::eUnaryPlus );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprCast()
	{
		testBegin( "testExprCast" );
		auto op = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "op" ) );
		ast::ExprCast expr{ ast::Type::eFloat, std::move( op ) };

		check( expr.getKind() == ast::Expr::Kind::eCast );
		check( expr.getType() == ast::Type::eFloat );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "op" );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		testEnd();
	}

	void testExprFnCall()
	{
		testBegin( "testExprFnCall" );
		{
			auto funcName = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eFunction, "func" ) );
			ast::ExprList argList;
			ast::ExprFnCall expr{ ast::Type::eInt, std::move( funcName ), std::move( argList ) };

			check( expr.getKind() == ast::Expr::Kind::eFnCall );
			check( expr.getType() == ast::Type::eInt );

			check( expr.getFn().getType() == ast::Type::eFunction );
			check( expr.getFn().getVariable()->getType() == ast::Type::eFunction );
			check( expr.getFn().getVariable()->getName() == "func" );

			check( expr.getArgList().empty() );
		}
		{
			auto funcName = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eFunction, "func" ) );
			ast::ExprList argList;
			argList.emplace_back( std::make_unique< ast::ExprLiteral >( 10 ) );
			ast::ExprFnCall expr{ ast::Type::eInt, std::move( funcName ), std::move( argList ) };

			check( expr.getKind() == ast::Expr::Kind::eFnCall );
			check( expr.getType() == ast::Type::eInt );

			check( expr.getFn().getType() == ast::Type::eFunction );
			check( expr.getFn().getVariable()->getType() == ast::Type::eFunction );
			check( expr.getFn().getVariable()->getName() == "func" );

			check( expr.getArgList().size() == 1u );

			check( expr.getArgList()[0]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr.getArgList()[0]->getType() == ast::Type::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr.getArgList()[0] ).getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr.getArgList()[0] ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		}
		{
			auto funcName = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eFunction, "func" ) );
			ast::ExprList argList;
			argList.emplace_back( std::make_unique< ast::ExprLiteral >( 10 ) );
			argList.emplace_back( std::make_unique< ast::ExprLiteral >( 1.0f ) );
			ast::ExprFnCall expr{ ast::Type::eInt, std::move( funcName ), std::move( argList ) };

			check( expr.getKind() == ast::Expr::Kind::eFnCall );
			check( expr.getType() == ast::Type::eInt );

			check( expr.getFn().getType() == ast::Type::eFunction );
			check( expr.getFn().getVariable()->getType() == ast::Type::eFunction );
			check( expr.getFn().getVariable()->getName() == "func" );

			check( expr.getArgList().size() == 2u );

			check( expr.getArgList()[0]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr.getArgList()[0]->getType() == ast::Type::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr.getArgList()[0] ).getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( static_cast< ast::ExprLiteral const & >( *expr.getArgList()[0] ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );

			check( expr.getArgList()[1]->getKind() == ast::Expr::Kind::eLiteral );
			check( expr.getArgList()[1]->getType() == ast::Type::eFloat );
			check( static_cast< ast::ExprLiteral const & >( *expr.getArgList()[1] ).getValueType() == ast::ExprLiteral::ValueType::eFloat );
			check( static_cast< ast::ExprLiteral const & >( *expr.getArgList()[1] ).getValue< ast::ExprLiteral::ValueType::eFloat >() == 1.0f );
		}
		testEnd();
	}

	void testExprInit()
	{
		testBegin( "testExprInit" );
		auto lhs = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto rhs = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprInit expr{ std::move( lhs ), std::move( rhs ) };

		check( expr.getKind() == ast::Expr::Kind::eInit );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getIdentifier().getType() == ast::Type::eInt );
		check( expr.getIdentifier().getVariable()->getName() == "lhs" );
		check( expr.getIdentifier().getVariable()->getType() == ast::Type::eInt );

		check( expr.getInitialiser().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getInitialiser().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getInitialiser() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getInitialiser() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprMbrSelect()
	{
		testBegin( "testExprMbrSelect" );
		auto outerVar = std::make_shared< ast::Variable >( ast::Type::eInt, "outerVar" );
		auto member = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "innerVar" ) );
		ast::ExprMbrSelect expr{ outerVar, std::move( member ) };

		check( expr.getKind() == ast::Expr::Kind::eMbrSelect );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getOuterVar().getType() == ast::Type::eInt );
		check( expr.getOuterVar().getName() == "outerVar" );

		check( expr.getOperand().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getOperand().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getOperand() ).getVariable()->getName() == "innerVar" );
		testEnd();
	}

	void testExprQuestion()
	{
		testBegin( "testExprQuestion" );
		auto ctrlExpr = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eBoolean, "ctrl" ) );
		auto trueExpr = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		auto falseExpr = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprQuestion expr{ ast::Type::eInt, std::move( ctrlExpr ), std::move( trueExpr ), std::move( falseExpr ) };

		check( expr.getKind() == ast::Expr::Kind::eQuestion );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getCtrlExpr().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getCtrlExpr().getType() == ast::Type::eBoolean );
		check( static_cast< ast::ExprIdentifier const & >( expr.getCtrlExpr() ).getVariable()->getType() == ast::Type::eBoolean );
		check( static_cast< ast::ExprIdentifier const & >( expr.getCtrlExpr() ).getVariable()->getName() == "ctrl" );

		check( expr.getTrueExpr().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getTrueExpr().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getTrueExpr() ).getVariable()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getTrueExpr() ).getVariable()->getName() == "lhs" );

		check( expr.getFalseExpr().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getFalseExpr().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getFalseExpr() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getFalseExpr() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprSwitchCase()
	{
		testBegin( "testExprSwitchCase" );
		auto label = std::make_unique< ast::ExprLiteral >( 10 );
		ast::ExprSwitchCase expr{ std::move( label ) };

		check( expr.getKind() == ast::Expr::Kind::eSwitchCase );
		check( expr.getType() == ast::Type::eInt );

		check( expr.getLabel().getKind() == ast::Expr::Kind::eLiteral );
		check( expr.getLabel().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getLabel() ).getValueType() == ast::ExprLiteral::ValueType::eInt );
		check( static_cast< ast::ExprLiteral const & >( expr.getLabel() ).getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
		testEnd();
	}

	void testExprSwitchTest()
	{
		testBegin( "testExprSwitchTest" );
		auto value = std::make_unique< ast::ExprIdentifier >( std::make_shared< ast::Variable >( ast::Type::eInt, "lhs" ) );
		ast::ExprSwitchTest expr{ std::move( value ) };

		check( expr.getKind() == ast::Expr::Kind::eSwitchTest );
		check( expr.getType() == ast::Type::eUndefined );

		check( expr.getValue().getKind() == ast::Expr::Kind::eIdentifier );
		check( expr.getValue().getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getValue() ).getVariable()->getType() == ast::Type::eInt );
		check( static_cast< ast::ExprIdentifier const & >( expr.getValue() ).getVariable()->getName() == "lhs" );
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
	testExprLogXor();
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
