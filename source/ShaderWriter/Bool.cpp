/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Bool.hpp"

namespace sdw
{
	Boolean::Boolean( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Boolean::Boolean( Boolean && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Boolean::Boolean( Boolean const & rhs )
		: Value{ rhs }
	{
	}

	Boolean::Boolean( Value const & rhs )
		: Value{ rhs }
	{
	}

	Boolean & Boolean::operator=( Boolean const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( type::getBool()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	Boolean & Boolean::operator=( bool rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getBool()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Boolean::operator bool()
	{
		return false;
	}

	Boolean operator==( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator!=( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator||( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator&&( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Optional< Boolean > operator||( Optional< Boolean > const & lhs, Boolean const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator&&( Optional< Boolean > const & lhs, Boolean const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator||( Boolean const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator&&( Boolean const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator||( Optional< Boolean > const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator&&( Optional< Boolean > const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

#define Writer_ImplementComparisonLHS( Operator, FuncName, LhsTypeT, RhsTypeT )\
	Boolean operator Operator( LhsTypeT const & lhs, RhsTypeT const & rhs )\
	{\
		return Boolean{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) ) };\
	}\
	Optional< Boolean > operator Operator( Optional< LhsTypeT > const & lhs, RhsTypeT const & rhs )\
	{\
		return Optional< Boolean >{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) )\
			, areOptionalEnabled( lhs, rhs ) };\
	}

#define Writer_ImplementComparisonRHS( Operator, FuncName, LhsTypeT, RhsTypeT )\
	Boolean operator Operator( LhsTypeT const & lhs, RhsTypeT const & rhs )\
	{\
		return Boolean{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) ) };\
	}\
	Optional< Boolean > operator Operator( LhsTypeT const & lhs, Optional< RhsTypeT > const & rhs )\
	{\
		return Optional< Boolean >{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) )\
			, areOptionalEnabled( lhs, rhs ) };\
	}

#define Writer_ImplementComparison( Operator, FuncName, LhsTypeT, RhsTypeT )\
	Boolean operator Operator( LhsTypeT const & lhs, RhsTypeT const & rhs )\
	{\
		return Boolean{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) ) };\
	}\
	Optional< Boolean > operator Operator( Optional< LhsTypeT > const & lhs, RhsTypeT const & rhs )\
	{\
		return Optional< Boolean >{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) )\
			, areOptionalEnabled( lhs, rhs ) };\
	}\
	Optional< Boolean > operator Operator( LhsTypeT const & lhs, Optional< RhsTypeT > const & rhs )\
	{\
		return Optional< Boolean >{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) )\
			, areOptionalEnabled( lhs, rhs ) };\
	}\
	Optional< Boolean > operator Operator( Optional< LhsTypeT > const & lhs, Optional< RhsTypeT > const & rhs )\
	{\
		return Optional< Boolean >{ findShader( lhs, rhs )\
			, sdw::FuncName( makeExpr( lhs ), makeExpr( rhs ) )\
			, areOptionalEnabled( lhs, rhs ) };\
	}

#define Writer_ImplementComparisonTypes( Operator, FuncName, TypeT )\
	Writer_ImplementComparison( Operator, FuncName, TypeT, Int )\
	Writer_ImplementComparison( Operator, FuncName, TypeT, UInt )\
	Writer_ImplementComparison( Operator, FuncName, TypeT, Float )\
	Writer_ImplementComparisonLHS( Operator, FuncName, TypeT, int32_t )\
	Writer_ImplementComparisonLHS( Operator, FuncName, TypeT, uint32_t )\
	Writer_ImplementComparisonLHS( Operator, FuncName, TypeT, float )\
	Writer_ImplementComparisonLHS( Operator, FuncName, TypeT, double )\
	Writer_ImplementComparisonRHS( Operator, FuncName, int32_t, TypeT )\
	Writer_ImplementComparisonRHS( Operator, FuncName, uint32_t, TypeT )\
	Writer_ImplementComparisonRHS( Operator, FuncName, float, TypeT )\
	Writer_ImplementComparisonRHS( Operator, FuncName, double, TypeT )

#define Writer_ImplementComparisons( TypeT )\
	Writer_ImplementComparisonTypes( ==, makeEqual, TypeT )\
	Writer_ImplementComparisonTypes( !=, makeNEqual, TypeT )\
	Writer_ImplementComparisonTypes( <, makeLess, TypeT )\
	Writer_ImplementComparisonTypes( <=, makeLEqual, TypeT )\
	Writer_ImplementComparisonTypes( >, makeGreater, TypeT )\
	Writer_ImplementComparisonTypes( >=, makeGEqual, TypeT )

	Writer_ImplementComparisons( Int )
	Writer_ImplementComparisons( UInt )
	Writer_ImplementComparisons( Float )

#undef Writer_ImplementComparisons
#undef Writer_ImplementComparisonTypes
#undef Writer_ImplementComparison
#undef Writer_ImplementComparisonLHS
}
