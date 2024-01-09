#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	template< typename T >
	struct IsSdwValue
	{
		static bool constexpr Value = true;
	};

	template<>
	struct IsSdwValue< int32_t >
	{
		static bool constexpr Value = false;
	};

	template<>
	struct IsSdwValue< uint32_t >
	{
		static bool constexpr Value = false;
	};

	template<>
	struct IsSdwValue< float >
	{
		static bool constexpr Value = false;
	};

	template< typename T >
	static constexpr bool isSdwValue = IsSdwValue< T >::Value;

	template< typename LHS
		, typename RHS
		, typename Enable = void >
	struct ValueTypeGetter;

	template< typename LHS, typename RHS >
	struct ValueTypeGetter< LHS, RHS
		, std::enable_if_t< isSdwValue< LHS > && isSdwValue< RHS > > >
	{
		using Type = LHS;
	};

	template< typename LHS, typename RHS >
	struct ValueTypeGetter< LHS, RHS
		, std::enable_if_t< isSdwValue< LHS > && !isSdwValue< RHS > > >
	{
		using Type = LHS;
	};

	template< typename LHS, typename RHS >
	struct ValueTypeGetter< LHS, RHS
		, std::enable_if_t< !isSdwValue< LHS > && isSdwValue< RHS > > >
	{
		using Type = RHS;
	};

	template< typename LHS, typename RHS >
	using ValueTypeT = typename ValueTypeGetter< LHS, RHS >::Type;

	template< typename RET, typename RHS >
	void testBaseAssignOperators( sdw::ShaderWriter & writer
		, test::sdw_test::TestCounts & testCounts
		, RET & ret
		, RHS const & rhs )
	{
		auto & statements = *writer.getBuilder().getContainer();
		sdw::expr::Expr const * expr{};
		ret += writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret -= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret *= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret /= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
		}
	}

	template< typename RET, typename RHS >
	void testIntAssignOperators( sdw::ShaderWriter & writer
		, test::sdw_test::TestCounts & testCounts
		, RET & ret
		, RHS const & rhs )
	{
		testBaseAssignOperators( writer, testCounts, ret, rhs );
		auto & statements = *writer.getBuilder().getContainer();
		sdw::expr::Expr const * expr{};
		ret %= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eModuloAssign );
		}
		ret <<= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eLShiftAssign );
		}
		ret >>= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eRShiftAssign );
		}
		ret |= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eOrAssign );
		}
		ret &= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAndAssign );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testComparators( sdw::ShaderWriter & writer
		, test::sdw_test::TestCounts & testCounts
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		using CompType = sdw::RealTypeT< ValueTypeT< LHS, RHS > >;
		auto & statements = *writer.getBuilder().getContainer();
		sdw::expr::Expr const * expr{};
		ret = writer.cast< CompType >( lhs ) == writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
		}
		ret = writer.cast< CompType >( lhs ) != writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
		}
		ret = writer.cast< CompType >( lhs ) < writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLess );
		}
		ret = writer.cast< CompType >( lhs ) <= writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLessEqual );
		}
		ret = writer.cast< CompType >( lhs ) > writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eGreater );
		}
		ret = writer.cast< CompType >( lhs ) >= writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eGreaterEqual );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testBaseOperators( sdw::ShaderWriter & writer
		, test::sdw_test::TestCounts & testCounts
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		auto & statements = *writer.getBuilder().getContainer();
		sdw::expr::Expr const * expr{};
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) + writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) - writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) * writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) / writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testIntOperators( sdw::ShaderWriter & writer
		, test::sdw_test::TestCounts & testCounts
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		testBaseOperators( writer, testCounts, ret, lhs, rhs );
		auto & statements = *writer.getBuilder().getContainer();
		sdw::expr::Expr const * expr{};
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) % writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eModulo );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) << writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLShift );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) >> writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eRShift );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) | writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitOr );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) & writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitAnd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = ~writer.cast< sdw::RealTypeT< RET > >( lhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitNot );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
	}

	template< typename RET, typename RHS >
	void testVecAssignOperators( sdw::ShaderWriter & writer
		, test::sdw_test::TestCounts & testCounts
		, RET & ret
		, RHS const & rhs )
	{
		auto & statements = *writer.getBuilder().getContainer();
		sdw::expr::Expr const * expr{};
		ret += rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret += rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret -= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret -= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret *= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret *= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret /= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
		}
		ret /= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			check( expr->getKind() == sdw::expr::Kind::eDivideAssign );
		}
	}

	template< typename RET, typename LHS, typename RHS >
	void testVecOperators( sdw::ShaderWriter & writer
		, test::sdw_test::TestCounts & testCounts
		, RET & ret
		, LHS const & lhs
		, RHS const & rhs )
	{
		auto & statements = *writer.getBuilder().getContainer();
		sdw::expr::Expr const * expr{};
		ret = lhs + rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs + rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs - rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs - rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs * rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs * rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs / rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs / rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			require( expr->getKind() == sdw::expr::Kind::eAssign );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
	}

	void testBool( test::sdw_test::TestCounts & testCounts )
	{
		sdw::expr::Expr const * expr{};
		{
			testBegin( "testBool" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto & statements = *writer.getBuilder().getContainer();
					auto a = writer.declLocale< sdw::Boolean >( "a" );
					auto b = writer.declLocale< sdw::Boolean >( "b" );
					auto c = writer.declLocale< sdw::Boolean >( "c" );
					a = b == c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b != c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b || c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogOr );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b && c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogAnd );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testBoolOptEnabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto & statements = *writer.getBuilder().getContainer();
					auto a = writer.declLocale< sdw::Boolean >( "a", true );
					auto b = writer.declLocale< sdw::Boolean >( "b", true );
					auto c = writer.declLocale< sdw::Boolean >( "c", true );
					a = b == c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b != c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b || c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogOr );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b && c;
					require( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					require( expr->getKind() == sdw::expr::Kind::eAssign );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogAnd );
					check( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testBoolOptDisabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< sdw::Boolean >( "a", false );
					auto b = writer.declLocale< sdw::Boolean >( "b", false );
					auto c = writer.declLocale< sdw::Boolean >( "c", false );
					a = b == c;
					a = b != c;
					a = b || c;
					a = b && c;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
	}

	template< typename FloatT >
	void testFloat( test::sdw_test::TestCounts & testCounts )
	{
		{
			testBegin( "testFloat" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< FloatT >( "a" );
					auto b = writer.declLocale< FloatT >( "b" );
					auto c = writer.declLocale< FloatT >( "c" );
					testBaseAssignOperators( writer, testCounts, c, 2.0 );
					testBaseOperators( writer, testCounts, c, a, 2.0 );
					testBaseOperators( writer, testCounts, c, 2.0, a );
					testBaseAssignOperators( writer, testCounts, c, 2.0f );
					testBaseAssignOperators( writer, testCounts, c, 2.0_f );
					testBaseAssignOperators( writer, testCounts, c, b );
					testBaseOperators( writer, testCounts, c, a, 2.0f );
					testBaseOperators( writer, testCounts, c, a, 2.0_f );
					testBaseOperators( writer, testCounts, c, 2.0f, a );
					testBaseOperators( writer, testCounts, c, 2.0_f, a );
					testBaseOperators( writer, testCounts, c, a, b );
					auto d = writer.declLocale< sdw::Boolean >( "d" );
					testComparators( writer, testCounts, d, c, 2.0f );
					testComparators( writer, testCounts, d, c, 2.0_f );
					testComparators( writer, testCounts, d, c, 2 );
					testComparators( writer, testCounts, d, c, 2_i );
					testComparators( writer, testCounts, d, c, 2u );
					testComparators( writer, testCounts, d, c, 2_u );
					testComparators( writer, testCounts, d, 2.0f, c );
					testComparators( writer, testCounts, d, 2.0_f, c );
					testComparators( writer, testCounts, d, 2, c );
					testComparators( writer, testCounts, d, 2_i, c );
					testComparators( writer, testCounts, d, 2u, c );
					testComparators( writer, testCounts, d, 2_u, c );
					testComparators( writer, testCounts, d, c, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testFloatOptEnabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< FloatT >( "a", true );
					auto b = writer.declLocale< FloatT >( "b", true );
					auto c = writer.declLocale< FloatT >( "c", true );
					testBaseAssignOperators( writer, testCounts, c, 2.0 );
					testBaseOperators( writer, testCounts, c, a, 2.0 );
					testBaseOperators( writer, testCounts, c, 2.0, a );
					testBaseAssignOperators( writer, testCounts, c, b );
					testBaseOperators( writer, testCounts, c, a, 2.0f );
					testBaseOperators( writer, testCounts, c, a, 2.0_f );
					testBaseOperators( writer, testCounts, c, 2.0f, a );
					testBaseOperators( writer, testCounts, c, 2.0_f, a );
					testBaseOperators( writer, testCounts, c, a, b );
					auto d = writer.declLocale< sdw::Boolean >( "d", true );
					testComparators( writer, testCounts, d, c, 2.0f );
					testComparators( writer, testCounts, d, c, 2.0_f );
					testComparators( writer, testCounts, d, c, 2 );
					testComparators( writer, testCounts, d, c, 2_i );
					testComparators( writer, testCounts, d, c, 2u );
					testComparators( writer, testCounts, d, c, 2_u );
					testComparators( writer, testCounts, d, 2.0f, c );
					testComparators( writer, testCounts, d, 2.0_f, c );
					testComparators( writer, testCounts, d, 2, c );
					testComparators( writer, testCounts, d, 2_i, c );
					testComparators( writer, testCounts, d, 2u, c );
					testComparators( writer, testCounts, d, 2_u, c );
					testComparators( writer, testCounts, d, c, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testFloatOptDisabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< FloatT >( "a", false );
					auto b = writer.declLocale< FloatT >( "b", false );
					auto c = writer.declLocale< FloatT >( "c", false );
					testBaseAssignOperators( writer, testCounts, c, 2.0 );
					testBaseOperators( writer, testCounts, c, a, 2.0 );
					testBaseOperators( writer, testCounts, c, 2.0, a );
					testBaseAssignOperators( writer, testCounts, c, b );
					testBaseOperators( writer, testCounts, c, a, 2.0f );
					testBaseOperators( writer, testCounts, c, a, 2.0_f );
					testBaseOperators( writer, testCounts, c, 2.0f, a );
					testBaseOperators( writer, testCounts, c, 2.0_f, a );
					testBaseOperators( writer, testCounts, c, a, b );
					auto d = writer.declLocale< sdw::Boolean >( "d", false );
					testComparators( writer, testCounts, d, c, 2.0f );
					testComparators( writer, testCounts, d, c, 2.0_f );
					testComparators( writer, testCounts, d, c, 2 );
					testComparators( writer, testCounts, d, c, 2_i );
					testComparators( writer, testCounts, d, c, 2u );
					testComparators( writer, testCounts, d, c, 2_u );
					testComparators( writer, testCounts, d, 2.0f, c );
					testComparators( writer, testCounts, d, 2.0_f, c );
					testComparators( writer, testCounts, d, 2, c );
					testComparators( writer, testCounts, d, 2_i, c );
					testComparators( writer, testCounts, d, 2u, c );
					testComparators( writer, testCounts, d, 2_u, c );
					testComparators( writer, testCounts, d, c, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
	}

	template< typename IntT >
	void testInt( test::sdw_test::TestCounts & testCounts )
	{
		{
			testBegin( "testInt" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< IntT >( "a" );
					auto b = writer.declLocale< IntT >( "b" );
					auto c = writer.declLocale< IntT >( "c" );
					testIntAssignOperators( writer, testCounts, c, 2 );
					testIntAssignOperators( writer, testCounts, c, 2u );
					testIntAssignOperators( writer, testCounts, c, 2_i );
					testIntAssignOperators( writer, testCounts, c, 2_u );
					testIntAssignOperators( writer, testCounts, c, b );
					testIntOperators( writer, testCounts, c, a, 2 );
					testIntOperators( writer, testCounts, c, a, 2u );
					testIntOperators( writer, testCounts, c, a, 2_i );
					testIntOperators( writer, testCounts, c, a, 2_u );
					testBaseOperators( writer, testCounts, c, 2, a );
					testBaseOperators( writer, testCounts, c, 2u, a );
					testIntOperators( writer, testCounts, c, 2_i, a );
					testIntOperators( writer, testCounts, c, a, b );
					auto d = writer.declLocale< sdw::Boolean >( "d" );
					testComparators( writer, testCounts, d, c, 2.0f );
					testComparators( writer, testCounts, d, c, 2.0_f );
					testComparators( writer, testCounts, d, c, 2 );
					testComparators( writer, testCounts, d, c, 2_i );
					testComparators( writer, testCounts, d, c, 2u );
					testComparators( writer, testCounts, d, c, 2_u );
					testComparators( writer, testCounts, d, 2.0f, c );
					testComparators( writer, testCounts, d, 2.0_f, c );
					testComparators( writer, testCounts, d, 2, c );
					testComparators( writer, testCounts, d, 2_i, c );
					testComparators( writer, testCounts, d, 2u, c );
					testComparators( writer, testCounts, d, 2_u, c );
					testComparators( writer, testCounts, d, c, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testIntOptEnabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< IntT >( "a", true );
					auto b = writer.declLocale< IntT >( "b", true );
					auto c = writer.declLocale< IntT >( "c", true );
					testIntAssignOperators( writer, testCounts, c, b );
					testIntOperators( writer, testCounts, c, a, 2 );
					testIntOperators( writer, testCounts, c, a, 2u );
					testIntOperators( writer, testCounts, c, a, 2_i );
					testIntOperators( writer, testCounts, c, a, 2_u );
					testBaseOperators( writer, testCounts, c, 2, a );
					testBaseOperators( writer, testCounts, c, 2u, a );
					testIntOperators( writer, testCounts, c, 2_i, a );
					testIntOperators( writer, testCounts, c, a, b );
					auto d = writer.declLocale< sdw::Boolean >( "d", true );
					testComparators( writer, testCounts, d, c, 2.0f );
					testComparators( writer, testCounts, d, c, 2.0_f );
					testComparators( writer, testCounts, d, c, 2 );
					testComparators( writer, testCounts, d, c, 2_i );
					testComparators( writer, testCounts, d, c, 2u );
					testComparators( writer, testCounts, d, c, 2_u );
					testComparators( writer, testCounts, d, 2.0f, c );
					testComparators( writer, testCounts, d, 2.0_f, c );
					testComparators( writer, testCounts, d, 2, c );
					testComparators( writer, testCounts, d, 2_i, c );
					testComparators( writer, testCounts, d, 2u, c );
					testComparators( writer, testCounts, d, 2_u, c );
					testComparators( writer, testCounts, d, c, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testIntOptDisabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< IntT >( "a", false );
					auto b = writer.declLocale< IntT >( "b", false );
					auto c = writer.declLocale< IntT >( "c", false );
					testIntAssignOperators( writer, testCounts, c, b );
					testIntOperators( writer, testCounts, c, a, 2 );
					testIntOperators( writer, testCounts, c, a, 2u );
					testIntOperators( writer, testCounts, c, a, 2_i );
					testIntOperators( writer, testCounts, c, a, 2_u );
					testBaseOperators( writer, testCounts, c, 2, a );
					testBaseOperators( writer, testCounts, c, 2u, a );
					testIntOperators( writer, testCounts, c, 2_i, a );
					testIntOperators( writer, testCounts, c, a, b );
					auto d = writer.declLocale< sdw::Boolean >( "d", false );
					testComparators( writer, testCounts, d, c, 2.0f );
					testComparators( writer, testCounts, d, c, 2.0_f );
					testComparators( writer, testCounts, d, c, 2 );
					testComparators( writer, testCounts, d, c, 2_i );
					testComparators( writer, testCounts, d, c, 2u );
					testComparators( writer, testCounts, d, c, 2_u );
					testComparators( writer, testCounts, d, 2.0f, c );
					testComparators( writer, testCounts, d, 2.0_f, c );
					testComparators( writer, testCounts, d, 2, c );
					testComparators( writer, testCounts, d, 2_i, c );
					testComparators( writer, testCounts, d, 2u, c );
					testComparators( writer, testCounts, d, 2_u, c );
					testComparators( writer, testCounts, d, c, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
	}

	template< template< typename ComponentT > typename VecT, typename ComponentT >
	void testVec( test::sdw_test::TestCounts & testCounts )
	{
		using VecType = VecT< ComponentT >;
		{
			testBegin( "testVec" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< VecType >( "a" );
					auto b = writer.declLocale< VecType >( "b" );
					auto c = writer.declLocale< VecType >( "c" );
					testVecAssignOperators( writer, testCounts, c, test::getDefault< VecType >( writer ) );
					testVecAssignOperators( writer, testCounts, c, b );
					testVecOperators( writer, testCounts, c, a, test::getDefault< VecType >( writer ) );
					testVecOperators( writer, testCounts, c, test::getDefault< VecType >( writer ), a );
					testVecOperators( writer, testCounts, c, a, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testVecOptEnabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< VecType >( "a", true );
					auto b = writer.declLocale< VecType >( "b", true );
					auto c = writer.declLocale< VecType >( "c", true );
					testVecAssignOperators( writer, testCounts, c, b );
					testVecOperators( writer, testCounts, c, a, test::getDefault< VecType >( writer ) );
					testVecOperators( writer, testCounts, c, test::getDefault< VecType >( writer ), a );
					testVecOperators( writer, testCounts, c, a, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
		{
			testBegin( "testVecOptDisabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< VecType >( "a", false );
					auto b = writer.declLocale< VecType >( "b", false );
					auto c = writer.declLocale< VecType >( "c", false );
					testVecAssignOperators( writer, testCounts, c, b );
					testVecOperators( writer, testCounts, c, a, test::getDefault< VecType >( writer ) );
					testVecOperators( writer, testCounts, c, test::getDefault< VecType >( writer ), a );
					testVecOperators( writer, testCounts, c, a, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			testEnd();
		}
	}

	void boolCast( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "boolCast" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			ComputeWriter writer;
			writer.implementMainT< VoidT >( 16u, [&]( ComputeInT< VoidT > in )
				{
					auto b = writer.declLocale(
						"b", 1_u );
					auto x = writer.declLocale( "x", 0x287a_u & b );
					auto xa = writer.declLocale( "xa", x != 0_u );
					auto xb = writer.declLocale( "xb", writer.cast<Float>( xa ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterOperations )
{
	sdwTestSuiteBegin();
	testBool( testCounts );
	testFloat< sdw::Float >( testCounts );
	testFloat< sdw::Double >( testCounts );
	testInt< sdw::Int >( testCounts );
	testInt< sdw::UInt >( testCounts );
	testVec< sdw::Vec2T, sdw::Half >( testCounts );
	testVec< sdw::Vec2T, sdw::Float >( testCounts );
	testVec< sdw::Vec2T, sdw::Double >( testCounts );
	testVec< sdw::Vec2T, sdw::Int >( testCounts );
	testVec< sdw::Vec2T, sdw::UInt >( testCounts );
	testVec< sdw::Vec3T, sdw::Float >( testCounts );
	testVec< sdw::Vec3T, sdw::Double >( testCounts );
	testVec< sdw::Vec3T, sdw::Int >( testCounts );
	testVec< sdw::Vec3T, sdw::UInt >( testCounts );
	testVec< sdw::Vec4T, sdw::Half >( testCounts );
	testVec< sdw::Vec4T, sdw::Float >( testCounts );
	testVec< sdw::Vec4T, sdw::Double >( testCounts );
	testVec< sdw::Vec4T, sdw::Int >( testCounts );
	testVec< sdw::Vec4T, sdw::UInt >( testCounts );
	boolCast( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterOperations )
