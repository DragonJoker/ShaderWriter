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
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		ret -= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		ret *= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		ret /= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
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
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eModuloAssign );
		ret <<= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eLShiftAssign );
		ret >>= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eRShiftAssign );
		ret |= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eOrAssign );
		ret &= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAndAssign );
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
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
		ret = lhs - rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
		ret = lhs * rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
		ret = lhs / rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
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
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eModulo );
		ret = lhs << rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLShift );
		ret = lhs >> rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eRShift );
		ret = lhs | rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitOr );
		ret = lhs & rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitAnd );
		ret = ~lhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitNot );
	}

	template< typename RET, typename RHS >
	void testVecAssignOperators( sdw::Shader & shader
		, RET & ret
		, RHS const & rhs )
	{
		auto & statements = shader.getStatements()->getStatements();
		sdw::expr::Expr * expr;
		ret += rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		ret -= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		ret *= rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		ret /= rhs.x();
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
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
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
		ret = lhs - rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
		ret = lhs * rhs;
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
		ret = lhs / rhs.x();
		check( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
		expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
		check( expr->getKind() == sdw::expr::Kind::eAssign );
		check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
	}

	void testBool()
	{
		sdw::Shader shader;
		auto a = shader.declLocale< sdw::Boolean >( "a" );
		auto b = shader.declLocale< sdw::Boolean >( "b" );
		auto c = shader.declLocale< sdw::Boolean >( "c" );

		a = b == c;
		a = b != c;
		a = b || c;
		a = b && c;

		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
	}

	void testFloat()
	{
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
	}

	void testInt()
	{
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
	}

	void testUInt()
	{
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
	}

	void testVec2()
	{
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
	}

	void testVec3()
	{
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
	}

	void testVec4()
	{
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
