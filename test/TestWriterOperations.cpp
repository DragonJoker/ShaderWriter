#include "Common.hpp"
#include "TestWriterCommon.hpp"

namespace
{
	template< typename RET, typename RHS >
	void testBaseAssignOperators( sdw::Shader & shader
		, RET & ret
		, RHS const & rhs )
	{
		auto & statements = shader.getStatements()->getStatements();
		sdw::expr::Expr * expr;
		ret += rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret -= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret *= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret /= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
		}
	}

	template< typename RET, typename RHS >
	void testIntAssignOperators( sdw::Shader & shader
		, RET & ret
		, RHS const & rhs )
	{
		testBaseAssignOperators( shader, ret, rhs );
		auto & statements = shader.getStatements()->getStatements();
		sdw::expr::Expr * expr;
		ret %= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eModuloAssign );
		}
		ret <<= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eLShiftAssign );
		}
		ret >>= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eRShiftAssign );
		}
		ret |= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eOrAssign );
		}
		ret &= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAndAssign );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testBaseOperators( sdw::Shader & shader
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		auto & statements = shader.getStatements()->getStatements();
		sdw::expr::Expr * expr;
		ret = lhs + rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs - rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs * rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs / rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testIntOperators( sdw::Shader & shader
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		testBaseOperators( shader, ret, lhs, rhs );
		auto & statements = shader.getStatements()->getStatements();
		sdw::expr::Expr * expr;
		ret = lhs % rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eModulo );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs << rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLShift );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs >> rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eRShift );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs | rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitOr );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs & rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitAnd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = ~lhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitNot );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
	}

	template< typename RET, typename RHS >
	void testVecAssignOperators( sdw::Shader & shader
		, RET & ret
		, RHS const & rhs )
	{
		auto & statements = shader.getStatements()->getStatements();
		sdw::expr::Expr * expr;
		ret += rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret += rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret -= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret -= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret *= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret *= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret /= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
		}
		ret /= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testVecOperators( sdw::Shader & shader
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		auto & statements = shader.getStatements()->getStatements();
		sdw::expr::Expr * expr;
		ret = lhs + rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs + rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs - rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs - rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs * rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs * rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs / rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
		ret = lhs / rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnum< RET > );
		}
	}

	void testBool()
	{
		sdw::expr::Expr * expr;
		{
			testBegin( "testBool" );
			sdw::Shader shader;
			auto & statements = shader.getStatements()->getStatements();
			auto a = shader.declLocale< sdw::Boolean >( "a" );
			auto b = shader.declLocale< sdw::Boolean >( "b" );
			auto c = shader.declLocale< sdw::Boolean >( "c" );
			a = b == c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			a = b != c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			a = b || c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogOr );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			a = b && c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogAnd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testBoolOptEnabled" );
			sdw::Shader shader;
			auto & statements = shader.getStatements()->getStatements();
			auto a = shader.declLocale< sdw::Boolean >( "a", true );
			auto b = shader.declLocale< sdw::Boolean >( "b", true );
			auto c = shader.declLocale< sdw::Boolean >( "c", true );
			a = b == c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			a = b != c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			a = b || c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogOr );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			a = b && c;
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogAnd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testBoolOptDisabled" );
			sdw::Shader shader;
			auto & statements = shader.getStatements()->getStatements();
			auto a = shader.declLocale< sdw::Boolean >( "a", false );
			auto b = shader.declLocale< sdw::Boolean >( "b", false );
			auto c = shader.declLocale< sdw::Boolean >( "c", false );
			a = b == c;
			a = b != c;
			a = b || c;
			a = b && c;
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
	}

	void testFloat()
	{
		{
			testBegin( "testFloat" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Float >( "a" );
			auto b = shader.declLocale< sdw::Float >( "b" );
			auto c = shader.declLocale< sdw::Float >( "c" );
			testBaseAssignOperators( shader, c, 2.0f );
			testBaseAssignOperators( shader, c, 2.0_f );
			testBaseAssignOperators( shader, c, b );
			testBaseOperators( shader, c, a, 2.0f );
			testBaseOperators( shader, c, a, 2.0_f );
			testBaseOperators( shader, c, 2.0f, a );
			testBaseOperators( shader, c, 2.0_f, a );
			testBaseOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testFloatOptEnabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Float >( "a", true );
			auto b = shader.declLocale< sdw::Float >( "b", true );
			auto c = shader.declLocale< sdw::Float >( "c", true );
			testBaseAssignOperators( shader, c, b );
			testBaseOperators( shader, c, a, 2.0f );
			testBaseOperators( shader, c, a, 2.0_f );
			testBaseOperators( shader, c, 2.0f, a );
			testBaseOperators( shader, c, 2.0_f, a );
			testBaseOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testFloatOptDisabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Float >( "a", false );
			auto b = shader.declLocale< sdw::Float >( "b", false );
			auto c = shader.declLocale< sdw::Float >( "c", false );
			testBaseAssignOperators( shader, c, b );
			testBaseOperators( shader, c, a, 2.0f );
			testBaseOperators( shader, c, a, 2.0_f );
			testBaseOperators( shader, c, 2.0f, a );
			testBaseOperators( shader, c, 2.0_f, a );
			testBaseOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
	}

	void testInt()
	{
		{
			testBegin( "testInt" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Int >( "a" );
			auto b = shader.declLocale< sdw::Int >( "b" );
			auto c = shader.declLocale< sdw::Int >( "c" );
			testIntAssignOperators( shader, c, 2 );
			testIntAssignOperators( shader, c, 2u );
			testIntAssignOperators( shader, c, 2_i );
			testIntAssignOperators( shader, c, 2_u );
			testIntAssignOperators( shader, c, b );
			testIntOperators( shader, c, a, 2 );
			testIntOperators( shader, c, a, 2u );
			testIntOperators( shader, c, a, 2_i );
			testIntOperators( shader, c, a, 2_u );
			testBaseOperators( shader, c, 2, a );
			testBaseOperators( shader, c, 2u, a );
			testIntOperators( shader, c, 2_i, a );
			testIntOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testIntOptEnabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Int >( "a", true );
			auto b = shader.declLocale< sdw::Int >( "b", true );
			auto c = shader.declLocale< sdw::Int >( "c", true );
			testIntAssignOperators( shader, c, b );
			testIntOperators( shader, c, a, 2 );
			testIntOperators( shader, c, a, 2u );
			testIntOperators( shader, c, a, 2_i );
			testIntOperators( shader, c, a, 2_u );
			testBaseOperators( shader, c, 2, a );
			testBaseOperators( shader, c, 2u, a );
			testIntOperators( shader, c, 2_i, a );
			testIntOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testIntOptDisabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Int >( "a", false );
			auto b = shader.declLocale< sdw::Int >( "b", false );
			auto c = shader.declLocale< sdw::Int >( "c", false );
			testIntAssignOperators( shader, c, b );
			testIntOperators( shader, c, a, 2 );
			testIntOperators( shader, c, a, 2u );
			testIntOperators( shader, c, a, 2_i );
			testIntOperators( shader, c, a, 2_u );
			testBaseOperators( shader, c, 2, a );
			testBaseOperators( shader, c, 2u, a );
			testIntOperators( shader, c, 2_i, a );
			testIntOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
	}

	void testUInt()
	{
		{
			testBegin( "testUInt" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::UInt >( "a" );
			auto b = shader.declLocale< sdw::UInt >( "b" );
			auto c = shader.declLocale< sdw::UInt >( "c" );
			testIntAssignOperators( shader, c, 2 );
			testIntAssignOperators( shader, c, 2u );
			testIntAssignOperators( shader, c, 2_i );
			testIntAssignOperators( shader, c, 2_u );
			testIntAssignOperators( shader, c, b );
			testIntOperators( shader, c, a, 2 );
			testIntOperators( shader, c, a, 2u );
			testIntOperators( shader, c, a, 2_i );
			testIntOperators( shader, c, a, 2_u );
			testBaseOperators( shader, c, 2, a );
			testBaseOperators( shader, c, 2u, a );
			testIntOperators( shader, c, 2_u, a );
			testIntOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testUIntOptEnabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::UInt >( "a", true );
			auto b = shader.declLocale< sdw::UInt >( "b", true );
			auto c = shader.declLocale< sdw::UInt >( "c", true );
			testIntAssignOperators( shader, c, b );
			testIntOperators( shader, c, a, 2 );
			testIntOperators( shader, c, a, 2u );
			testIntOperators( shader, c, a, 2_i );
			testIntOperators( shader, c, a, 2_u );
			testBaseOperators( shader, c, 2, a );
			testBaseOperators( shader, c, 2u, a );
			testIntOperators( shader, c, 2_u, a );
			testIntOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testUIntOptDisabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::UInt >( "a", false );
			auto b = shader.declLocale< sdw::UInt >( "b", false );
			auto c = shader.declLocale< sdw::UInt >( "c", false );
			testIntAssignOperators( shader, c, b );
			testIntOperators( shader, c, a, 2 );
			testIntOperators( shader, c, a, 2u );
			testIntOperators( shader, c, a, 2_i );
			testIntOperators( shader, c, a, 2_u );
			testBaseOperators( shader, c, 2, a );
			testBaseOperators( shader, c, 2u, a );
			testIntOperators( shader, c, 2_u, a );
			testIntOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
	}

	void testVec2()
	{
		{
			testBegin( "testVec2" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec2 >( "a" );
			auto b = shader.declLocale< sdw::Vec2 >( "b" );
			auto c = shader.declLocale< sdw::Vec2 >( "c" );
			testVecAssignOperators( shader, c, sdw::vec2( 2.0_f ) );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec2( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec2( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec2OptEnabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec2 >( "a", true );
			auto b = shader.declLocale< sdw::Vec2 >( "b", true );
			auto c = shader.declLocale< sdw::Vec2 >( "c", true );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec2( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec2( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec2OptDisabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec2 >( "a", false );
			auto b = shader.declLocale< sdw::Vec2 >( "b", false );
			auto c = shader.declLocale< sdw::Vec2 >( "c", false );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec2( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec2( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
	}

	void testVec3()
	{
		{
			testBegin( "testVec3" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec3 >( "a" );
			auto b = shader.declLocale< sdw::Vec3 >( "b" );
			auto c = shader.declLocale< sdw::Vec3 >( "c" );
			testVecAssignOperators( shader, c, sdw::vec3( 2.0_f ) );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec3( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec3( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec3OptEnabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec3 >( "a", true );
			auto b = shader.declLocale< sdw::Vec3 >( "b", true );
			auto c = shader.declLocale< sdw::Vec3 >( "c", true );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec3( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec3( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec3OptDisabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec3 >( "a", false );
			auto b = shader.declLocale< sdw::Vec3 >( "b", false );
			auto c = shader.declLocale< sdw::Vec3 >( "c", false );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec3( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec3( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
	}

	void testVec4()
	{
		{
			testBegin( "testVec4" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec4 >( "a" );
			auto b = shader.declLocale< sdw::Vec4 >( "b" );
			auto c = shader.declLocale< sdw::Vec4 >( "c" );
			testVecAssignOperators( shader, c, sdw::vec4( 2.0_f ) );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec4( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec4( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec4OptEnabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec4 >( "a", true );
			auto b = shader.declLocale< sdw::Vec4 >( "b", true );
			auto c = shader.declLocale< sdw::Vec4 >( "c", true );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec4( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec4( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec4OptDisabled" );
			sdw::Shader shader;
			auto a = shader.declLocale< sdw::Vec4 >( "a", false );
			auto b = shader.declLocale< sdw::Vec4 >( "b", false );
			auto c = shader.declLocale< sdw::Vec4 >( "c", false );
			testVecAssignOperators( shader, c, b );
			testVecOperators( shader, c, a, sdw::vec4( 2.0_f ) );
			testVecOperators( shader, c, sdw::vec4( 2.0_f ), a );
			testVecOperators( shader, c, a, b );
			std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
			testEnd();
		}
	}
}

int main( int argc, char ** argv )	
{
	testSuiteBegin( "TestWriterOperations" );
	testBool();
	testFloat();
	testInt();
	testUInt();
	testVec2();
	testVec3();
	testVec4();
	testSuiteEnd();
}
