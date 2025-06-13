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

	class ParamTypeNames
	{
	public:
		template< typename T >
		static std::string GetName( int )
		{
			if constexpr ( std::is_same_v< T, sdw::Half > ) return "sdw::Half";
			if constexpr ( std::is_same_v< T, sdw::Float > ) return "sdw::Float";
			if constexpr ( std::is_same_v< T, sdw::Double > ) return "sdw::Double";
			if constexpr ( std::is_same_v< T, sdw::Int > ) return "sdw::Int";
			if constexpr ( std::is_same_v< T, sdw::UInt > ) return "sdw::UInt";
			if constexpr ( std::is_same_v< T, sdw::HVec2 > ) return "sdw::HVec2";
			if constexpr ( std::is_same_v< T, sdw::IVec2 > ) return "sdw::IVec2";
			if constexpr ( std::is_same_v< T, sdw::UVec2 > ) return "sdw::UVec2";
			if constexpr ( std::is_same_v< T, sdw::DVec2 > ) return "sdw::DVec2";
			if constexpr ( std::is_same_v< T, sdw::Vec2 > ) return "sdw::Vec2";
			if constexpr ( std::is_same_v< T, sdw::IVec3 > ) return "sdw::IVec3";
			if constexpr ( std::is_same_v< T, sdw::UVec3 > ) return "sdw::UVec3";
			if constexpr ( std::is_same_v< T, sdw::DVec3 > ) return "sdw::DVec3";
			if constexpr ( std::is_same_v< T, sdw::Vec3 > ) return "sdw::Vec3";
			if constexpr ( std::is_same_v< T, sdw::HVec4 > ) return "sdw::HVec4";
			if constexpr ( std::is_same_v< T, sdw::IVec4 > ) return "sdw::IVec4";
			if constexpr ( std::is_same_v< T, sdw::UVec4 > ) return "sdw::UVec4";
			if constexpr ( std::is_same_v< T, sdw::DVec4 > ) return "sdw::DVec4";
			if constexpr ( std::is_same_v< T, sdw::Vec4 > ) return "sdw::Vec4";
		}
	};

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
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret -= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret *= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret /= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eDivideAssign );
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
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eModuloAssign );
		}
		ret <<= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eLShiftAssign );
		}
		ret >>= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eRShiftAssign );
		}
		ret |= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eOrAssign );
		}
		ret &= writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eAndAssign );
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
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
		}
		ret = writer.cast< CompType >( lhs ) != writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
		}
		ret = writer.cast< CompType >( lhs ) < writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLess );
		}
		ret = writer.cast< CompType >( lhs ) <= writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLessEqual );
		}
		ret = writer.cast< CompType >( lhs ) > writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eGreater );
		}
		ret = writer.cast< CompType >( lhs ) >= writer.cast< CompType >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eGreaterEqual );
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
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) - writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) * writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) / writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
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
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eModulo );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) << writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLShift );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) >> writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eRShift );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) | writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitOr );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = writer.cast< sdw::RealTypeT< RET > >( lhs ) & writer.cast< sdw::RealTypeT< RET > >( rhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitAnd );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = ~writer.cast< sdw::RealTypeT< RET > >( lhs );
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eBitNot );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
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
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret += rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eAddAssign );
		}
		ret -= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret -= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eMinusAssign );
		}
		ret *= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret *= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eTimesAssign );
		}
		ret /= rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eDivideAssign );
		}
		ret /= rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astCheck( expr->getKind() == sdw::expr::Kind::eDivideAssign );
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
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs + rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eAdd );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs - rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs - rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eMinus );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs * rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs * rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eTimes );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs / rhs;
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
		ret = lhs / rhs.x();
		if ( sdw::isOptionalEnabled( ret ) )
		{
			astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
			expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
			astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eDivide );
			astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::typeEnumV< RET > );
		}
	}

	TEST_F( SDWTest, testBool )
	{
		sdw::expr::Expr const * expr{};
		sdwTestBegin( "testBool" );
		{
			astOn( "testBool" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto & statements = *writer.getBuilder().getContainer();
					auto a = writer.declLocale< sdw::Boolean >( "a" );
					auto b = writer.declLocale< sdw::Boolean >( "b" );
					auto c = writer.declLocale< sdw::Boolean >( "c" );
					a = b == c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b != c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b || c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogOr );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b && c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogAnd );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		{
			astOn( "testBoolOptEnabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto & statements = *writer.getBuilder().getContainer();
					auto a = writer.declLocale< sdw::Boolean >( "a", true );
					auto b = writer.declLocale< sdw::Boolean >( "b", true );
					auto c = writer.declLocale< sdw::Boolean >( "c", true );
					a = b == c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eEqual );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b != c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eNotEqual );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b || c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogOr );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
					a = b && c;
					astRequire( statements.back()->getKind() == sdw::stmt::Kind::eSimple );
					expr = static_cast< sdw::stmt::Simple const & >( *statements.back() ).getExpr();
					astRequire( expr->getKind() == sdw::expr::Kind::eAssign );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getKind() == sdw::expr::Kind::eLogAnd );
					astCheck( static_cast< sdw::expr::Assign const & >( *expr ).getRHS()->getType()->getKind() == sdw::type::Kind::eBoolean );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		{
			astOn( "testBoolOptDisabled" );
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
		}
		sdwTestEnd()
	}

	template< typename ParamT >
	struct TestFloatOperationsT : public SDWTest
	{
	};

	using FloatParamTypes = testing::Types< sdw::Float, sdw::Double >;

	TYPED_TEST_SUITE( TestFloatOperationsT, FloatParamTypes, ParamTypeNames );

	TYPED_TEST( TestFloatOperationsT, testFloat )
	{
		sdwTestBegin( "testFloat" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a" );
					auto b = writer.declLocale< TypeParam >( "b" );
					auto c = writer.declLocale< TypeParam >( "c" );
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
		}
		sdwTestEnd()
	}

	TYPED_TEST( TestFloatOperationsT, testFloatOptEnabled )
	{
		sdwTestBegin( "testFloatOptEnabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a", true );
					auto b = writer.declLocale< TypeParam >( "b", true );
					auto c = writer.declLocale< TypeParam >( "c", true );
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
		}
		sdwTestEnd()
	}

	TYPED_TEST( TestFloatOperationsT, testFloatOptDisabled )
	{
		sdwTestBegin( "testFloatOptDisabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a", false );
					auto b = writer.declLocale< TypeParam >( "b", false );
					auto c = writer.declLocale< TypeParam >( "c", false );
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
		}
		sdwTestEnd()
	}

	template< typename ParamT >
	struct TestIntOperationsT : public SDWTest
	{
	};

	using IntParamTypes = testing::Types< sdw::Int, sdw::UInt >;

	TYPED_TEST_SUITE( TestIntOperationsT, IntParamTypes, ParamTypeNames );

	TYPED_TEST( TestIntOperationsT, testInt )
	{
		sdwTestBegin( "testInt" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a" );
					auto b = writer.declLocale< TypeParam >( "b" );
					auto c = writer.declLocale< TypeParam >( "c" );
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
		}
		sdwTestEnd()
	}

	TYPED_TEST( TestIntOperationsT, testIntOptEnabled )
	{
		sdwTestBegin( "testIntOptEnabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a", true );
					auto b = writer.declLocale< TypeParam >( "b", true );
					auto c = writer.declLocale< TypeParam >( "c", true );
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
		}
		sdwTestEnd()
	}

	TYPED_TEST( TestIntOperationsT, testIntOptDisabled )
	{
		sdwTestBegin( "testIntOptDisabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a", false );
					auto b = writer.declLocale< TypeParam >( "b", false );
					auto c = writer.declLocale< TypeParam >( "c", false );
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
		}
		sdwTestEnd()
	}

	template< typename ParamT >
	struct TestVecOperationsT : public SDWTest
	{
	};

	using VecParamTypes = testing::Types
		< sdw::HVec2, sdw::Vec2, sdw::DVec2, sdw::IVec2, sdw::UVec2
		, sdw::Vec3, sdw::DVec3, sdw::IVec3, sdw::UVec3
		, sdw::HVec4, sdw::Vec4, sdw::DVec4, sdw::IVec4, sdw::UVec4 >;

	TYPED_TEST_SUITE( TestVecOperationsT, VecParamTypes, ParamTypeNames );

	TYPED_TEST( TestVecOperationsT, testVecT )
	{
		sdwTestBegin( "testVec" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a" );
					auto b = writer.declLocale< TypeParam >( "b" );
					auto c = writer.declLocale< TypeParam >( "c" );
					testVecAssignOperators( writer, testCounts, c, test::getDefault< TypeParam >( writer ) );
					testVecAssignOperators( writer, testCounts, c, b );
					testVecOperators( writer, testCounts, c, a, test::getDefault< TypeParam >( writer ) );
					testVecOperators( writer, testCounts, c, test::getDefault< TypeParam >( writer ), a );
					testVecOperators( writer, testCounts, c, a, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( TestVecOperationsT, testVecOptEnabled )
	{
		sdwTestBegin( "testVecOptEnabled" );
		{
			astOn( "testVecOptEnabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a", true );
					auto b = writer.declLocale< TypeParam >( "b", true );
					auto c = writer.declLocale< TypeParam >( "c", true );
					testVecAssignOperators( writer, testCounts, c, b );
					testVecOperators( writer, testCounts, c, a, test::getDefault< TypeParam >( writer ) );
					testVecOperators( writer, testCounts, c, test::getDefault< TypeParam >( writer ), a );
					testVecOperators( writer, testCounts, c, a, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( TestVecOperationsT, testVecOptDisabled )
	{
		sdwTestBegin( "testVecOptDisabled" );
		{
			astOn( "testVecOptDisabled" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto a = writer.declLocale< TypeParam >( "a", false );
					auto b = writer.declLocale< TypeParam >( "b", false );
					auto c = writer.declLocale< TypeParam >( "c", false );
					testVecAssignOperators( writer, testCounts, c, b );
					testVecOperators( writer, testCounts, c, a, test::getDefault< TypeParam >( writer ) );
					testVecOperators( writer, testCounts, c, test::getDefault< TypeParam >( writer ), a );
					testVecOperators( writer, testCounts, c, a, b );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, boolCast )
	{
		sdwTestBegin( "boolCast" );
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
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
