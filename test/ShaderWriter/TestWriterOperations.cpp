#include "../Common.hpp"
#include "TestWriterCommon.hpp"

namespace
{
	template< typename RET, typename RHS >
	void testBaseAssignOperators( sdw::Shader & shader
		, RET & ret
		, RHS const & rhs )
	{
		auto & statements = *shader.getStatements();
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
		auto & statements = *shader.getStatements();
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
	void testComparators( sdw::Shader & shader
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		auto & statements = *shader.getStatements();
		sdw::expr::Expr * expr;
		ret = lhs == rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
		}
		ret = lhs != rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
		}
		ret = lhs < rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLess );
		}
		ret = lhs <= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLessEqual );
		}
		ret = lhs > rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eGreater );
		}
		ret = lhs >= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eGreaterEqual );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testBaseOperators( sdw::Shader & shader
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		auto & statements = *shader.getStatements();
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
		auto & statements = *shader.getStatements();
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
		auto & statements = *shader.getStatements();
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
		auto & statements = *shader.getStatements();
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
			sdw::ShaderWriter writer{ false };
			auto & statements = *writer.getShader().getStatements();
			auto a = writer.declLocale< sdw::Boolean >( "a" );
			auto b = writer.declLocale< sdw::Boolean >( "b" );
			auto c = writer.declLocale< sdw::Boolean >( "c" );
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
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testBoolOptEnabled" );
			sdw::ShaderWriter writer{ false };
			auto & statements = *writer.getShader().getStatements();
			auto a = writer.declLocale< sdw::Boolean >( "a", true );
			auto b = writer.declLocale< sdw::Boolean >( "b", true );
			auto c = writer.declLocale< sdw::Boolean >( "c", true );
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
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testBoolOptDisabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Boolean >( "a", false );
			auto b = writer.declLocale< sdw::Boolean >( "b", false );
			auto c = writer.declLocale< sdw::Boolean >( "c", false );
			a = b == c;
			a = b != c;
			a = b || c;
			a = b && c;
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
	}

	void testFloat()
	{
		{
			testBegin( "testFloat" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Float >( "a" );
			auto b = writer.declLocale< sdw::Float >( "b" );
			auto c = writer.declLocale< sdw::Float >( "c" );
			testBaseAssignOperators( writer.getShader(), c, 2.0f );
			testBaseAssignOperators( writer.getShader(), c, 2.0_f );
			testBaseAssignOperators( writer.getShader(), c, b );
			testBaseOperators( writer.getShader(), c, a, 2.0f );
			testBaseOperators( writer.getShader(), c, a, 2.0_f );
			testBaseOperators( writer.getShader(), c, 2.0f, a );
			testBaseOperators( writer.getShader(), c, 2.0_f, a );
			testBaseOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d" );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testFloatOptEnabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Float >( "a", true );
			auto b = writer.declLocale< sdw::Float >( "b", true );
			auto c = writer.declLocale< sdw::Float >( "c", true );
			testBaseAssignOperators( writer.getShader(), c, b );
			testBaseOperators( writer.getShader(), c, a, 2.0f );
			testBaseOperators( writer.getShader(), c, a, 2.0_f );
			testBaseOperators( writer.getShader(), c, 2.0f, a );
			testBaseOperators( writer.getShader(), c, 2.0_f, a );
			testBaseOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d", true );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testFloatOptDisabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Float >( "a", false );
			auto b = writer.declLocale< sdw::Float >( "b", false );
			auto c = writer.declLocale< sdw::Float >( "c", false );
			testBaseAssignOperators( writer.getShader(), c, b );
			testBaseOperators( writer.getShader(), c, a, 2.0f );
			testBaseOperators( writer.getShader(), c, a, 2.0_f );
			testBaseOperators( writer.getShader(), c, 2.0f, a );
			testBaseOperators( writer.getShader(), c, 2.0_f, a );
			testBaseOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d", false );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
	}

	void testInt()
	{
		{
			testBegin( "testInt" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Int >( "a" );
			auto b = writer.declLocale< sdw::Int >( "b" );
			auto c = writer.declLocale< sdw::Int >( "c" );
			testIntAssignOperators( writer.getShader(), c, 2 );
			testIntAssignOperators( writer.getShader(), c, 2u );
			testIntAssignOperators( writer.getShader(), c, 2_i );
			testIntAssignOperators( writer.getShader(), c, 2_u );
			testIntAssignOperators( writer.getShader(), c, b );
			testIntOperators( writer.getShader(), c, a, 2 );
			testIntOperators( writer.getShader(), c, a, 2u );
			testIntOperators( writer.getShader(), c, a, 2_i );
			testIntOperators( writer.getShader(), c, a, 2_u );
			testBaseOperators( writer.getShader(), c, 2, a );
			testBaseOperators( writer.getShader(), c, 2u, a );
			testIntOperators( writer.getShader(), c, 2_i, a );
			testIntOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d" );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testIntOptEnabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Int >( "a", true );
			auto b = writer.declLocale< sdw::Int >( "b", true );
			auto c = writer.declLocale< sdw::Int >( "c", true );
			testIntAssignOperators( writer.getShader(), c, b );
			testIntOperators( writer.getShader(), c, a, 2 );
			testIntOperators( writer.getShader(), c, a, 2u );
			testIntOperators( writer.getShader(), c, a, 2_i );
			testIntOperators( writer.getShader(), c, a, 2_u );
			testBaseOperators( writer.getShader(), c, 2, a );
			testBaseOperators( writer.getShader(), c, 2u, a );
			testIntOperators( writer.getShader(), c, 2_i, a );
			testIntOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d", true );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testIntOptDisabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Int >( "a", false );
			auto b = writer.declLocale< sdw::Int >( "b", false );
			auto c = writer.declLocale< sdw::Int >( "c", false );
			testIntAssignOperators( writer.getShader(), c, b );
			testIntOperators( writer.getShader(), c, a, 2 );
			testIntOperators( writer.getShader(), c, a, 2u );
			testIntOperators( writer.getShader(), c, a, 2_i );
			testIntOperators( writer.getShader(), c, a, 2_u );
			testBaseOperators( writer.getShader(), c, 2, a );
			testBaseOperators( writer.getShader(), c, 2u, a );
			testIntOperators( writer.getShader(), c, 2_i, a );
			testIntOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d", false );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
	}

	void testUInt()
	{
		{
			testBegin( "testUInt" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::UInt >( "a" );
			auto b = writer.declLocale< sdw::UInt >( "b" );
			auto c = writer.declLocale< sdw::UInt >( "c" );
			testIntAssignOperators( writer.getShader(), c, 2 );
			testIntAssignOperators( writer.getShader(), c, 2u );
			testIntAssignOperators( writer.getShader(), c, 2_i );
			testIntAssignOperators( writer.getShader(), c, 2_u );
			testIntAssignOperators( writer.getShader(), c, b );
			testIntOperators( writer.getShader(), c, a, 2 );
			testIntOperators( writer.getShader(), c, a, 2u );
			testIntOperators( writer.getShader(), c, a, 2_i );
			testIntOperators( writer.getShader(), c, a, 2_u );
			testBaseOperators( writer.getShader(), c, 2, a );
			testBaseOperators( writer.getShader(), c, 2u, a );
			testIntOperators( writer.getShader(), c, 2_u, a );
			testIntOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d" );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testUIntOptEnabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::UInt >( "a", true );
			auto b = writer.declLocale< sdw::UInt >( "b", true );
			auto c = writer.declLocale< sdw::UInt >( "c", true );
			testIntAssignOperators( writer.getShader(), c, b );
			testIntOperators( writer.getShader(), c, a, 2 );
			testIntOperators( writer.getShader(), c, a, 2u );
			testIntOperators( writer.getShader(), c, a, 2_i );
			testIntOperators( writer.getShader(), c, a, 2_u );
			testBaseOperators( writer.getShader(), c, 2, a );
			testBaseOperators( writer.getShader(), c, 2u, a );
			testIntOperators( writer.getShader(), c, 2_u, a );
			testIntOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d", true );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testUIntOptDisabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::UInt >( "a", false );
			auto b = writer.declLocale< sdw::UInt >( "b", false );
			auto c = writer.declLocale< sdw::UInt >( "c", false );
			testIntAssignOperators( writer.getShader(), c, b );
			testIntOperators( writer.getShader(), c, a, 2 );
			testIntOperators( writer.getShader(), c, a, 2u );
			testIntOperators( writer.getShader(), c, a, 2_i );
			testIntOperators( writer.getShader(), c, a, 2_u );
			testBaseOperators( writer.getShader(), c, 2, a );
			testBaseOperators( writer.getShader(), c, 2u, a );
			testIntOperators( writer.getShader(), c, 2_u, a );
			testIntOperators( writer.getShader(), c, a, b );
			auto d = writer.declLocale< sdw::Boolean >( "d", false );
			testComparators( writer.getShader(), d, c, 2.0f );
			testComparators( writer.getShader(), d, c, 2.0_f );
			testComparators( writer.getShader(), d, c, 2 );
			testComparators( writer.getShader(), d, c, 2_i );
			testComparators( writer.getShader(), d, c, 2u );
			testComparators( writer.getShader(), d, c, 2_u );
			testComparators( writer.getShader(), d, 2.0f, c );
			testComparators( writer.getShader(), d, 2.0_f, c );
			testComparators( writer.getShader(), d, 2, c );
			testComparators( writer.getShader(), d, 2_i, c );
			testComparators( writer.getShader(), d, 2u, c );
			testComparators( writer.getShader(), d, 2_u, c );
			testComparators( writer.getShader(), d, c, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
	}

	void testVec2()
	{
		{
			testBegin( "testVec2" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec2 >( "a" );
			auto b = writer.declLocale< sdw::Vec2 >( "b" );
			auto c = writer.declLocale< sdw::Vec2 >( "c" );
			testVecAssignOperators( writer.getShader(), c, sdw::vec2( 2.0_f ) );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec2( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec2( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec2OptEnabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec2 >( "a", true );
			auto b = writer.declLocale< sdw::Vec2 >( "b", true );
			auto c = writer.declLocale< sdw::Vec2 >( "c", true );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec2( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec2( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec2OptDisabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec2 >( "a", false );
			auto b = writer.declLocale< sdw::Vec2 >( "b", false );
			auto c = writer.declLocale< sdw::Vec2 >( "c", false );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec2( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec2( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
	}

	void testVec3()
	{
		{
			testBegin( "testVec3" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec3 >( "a" );
			auto b = writer.declLocale< sdw::Vec3 >( "b" );
			auto c = writer.declLocale< sdw::Vec3 >( "c" );
			testVecAssignOperators( writer.getShader(), c, sdw::vec3( 2.0_f ) );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec3( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec3( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec3OptEnabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec3 >( "a", true );
			auto b = writer.declLocale< sdw::Vec3 >( "b", true );
			auto c = writer.declLocale< sdw::Vec3 >( "c", true );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec3( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec3( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec3OptDisabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec3 >( "a", false );
			auto b = writer.declLocale< sdw::Vec3 >( "b", false );
			auto c = writer.declLocale< sdw::Vec3 >( "c", false );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec3( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec3( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
	}

	void testVec4()
	{
		{
			testBegin( "testVec4" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec4 >( "a" );
			auto b = writer.declLocale< sdw::Vec4 >( "b" );
			auto c = writer.declLocale< sdw::Vec4 >( "c" );
			testVecAssignOperators( writer.getShader(), c, sdw::vec4( 2.0_f ) );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec4( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec4( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec4OptEnabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec4 >( "a", true );
			auto b = writer.declLocale< sdw::Vec4 >( "b", true );
			auto c = writer.declLocale< sdw::Vec4 >( "c", true );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec4( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec4( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			testEnd();
		}
		{
			testBegin( "testVec4OptDisabled" );
			sdw::ShaderWriter writer{ false };
			auto a = writer.declLocale< sdw::Vec4 >( "a", false );
			auto b = writer.declLocale< sdw::Vec4 >( "b", false );
			auto c = writer.declLocale< sdw::Vec4 >( "c", false );
			testVecAssignOperators( writer.getShader(), c, b );
			testVecOperators( writer.getShader(), c, a, sdw::vec4( 2.0_f ) );
			testVecOperators( writer.getShader(), c, sdw::vec4( 2.0_f ), a );
			testVecOperators( writer.getShader(), c, a, b );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
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
