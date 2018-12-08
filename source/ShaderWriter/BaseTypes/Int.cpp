/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"

#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	//*************************************************************************

	Int::Int( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Int::Int( Int && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Int::Int( Int const & rhs )
		: Value{ rhs }
	{
	}

	Int::Int( int16_t rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Int::Int( int32_t rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Int::Int( int64_t rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Int::Int( Value const & rhs )
		: Value{ rhs }
	{
	}

	Int & Int::operator=( Int const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( getType()->getCache().getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	expr::ExprPtr Int::makeCondition()const
	{
		return sdw::makeNEqual( makeExpr( *this )
			, makeExpr( 0 ) );
	}

	Int & Int::operator=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( getType()->getCache().getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator=( int64_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( getType()->getCache().getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator++()
	{
		updateExpr( sdw::makePreInc( makeExpr( *this ) ) );
		return *this;
	}

	Int Int::operator++( int )
	{
		return Int{ findShader( *this ), sdw::makePostInc( makeExpr( *this ) ) };
	}

	Int & Int::operator--()
	{
		updateExpr( sdw::makePreDec( makeExpr( *this ) ) );
		return *this;
	}

	Int Int::operator--( int )
	{
		return Int{ findShader( *this ), sdw::makePostDec( makeExpr( *this ) ) };
	}

	Int & Int::operator+=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator+=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator-=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator*=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator/=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator+=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeModuloAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeModuloAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeModuloAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator<<=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeLShiftAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator>>=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeRShiftAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator&=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator^=( int32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeXorAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator^=( Int const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeXorAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAndAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator|=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeOrAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator^=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeXorAssign( findTypesCache( *this, rhs ).getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	ast::type::TypePtr Int::makeType( ast::type::TypesCache & cache )
	{
		return cache.getInt();
	}

	//*************************************************************************

	Int operator+( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator^( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator^( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator^( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator~( Int const & expr )
	{
		return Int{ findShader( expr )
			, sdw::makeBitNot( findTypesCache( expr ).getInt()
				, makeExpr( expr ) ) };
	}

	//*************************************************************************

	Optional< Int > operator+( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator^( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator^( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator^( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator^( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator^( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator~( Optional< Int > const & expr )
	{
		return Optional< Int >{ findShader( expr )
			, sdw::makeBitNot( findTypesCache( expr ).getInt()
				, makeExpr( expr ) )
			, areOptionalEnabled( expr ) };
	}

	//*************************************************************************

	Boolean operator==( Int const & lhs, Int const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator!=( Int const & lhs, Int const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<( Int const & lhs, Int const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<=( Int const & lhs, Int const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>( Int const & lhs, Int const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>=( Int const & lhs, Int const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Optional< Boolean > operator==( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator==( Int const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator!=( Int const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<( Int const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<=( Int const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>( Int const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>=( Int const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
