/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/UInt.hpp"

#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	//*************************************************************************

	UInt::UInt( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	UInt::UInt( UInt && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	UInt::UInt( UInt const & rhs )
		: Value{ rhs }
	{
	}

	UInt::UInt( uint16_t rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	UInt::UInt( uint32_t rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	UInt::UInt( uint64_t rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	UInt::UInt( Value const & rhs )
		: Value{ rhs }
	{
	}

	UInt & UInt::operator=( UInt const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	expr::ExprPtr UInt::makeCondition()const
	{
		return sdw::makeNEqual( makeExpr( *this )
			, makeExpr( 0u ) );
	}

	UInt & UInt::operator=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator=( uint64_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator++()
	{
		updateExpr( sdw::makePreInc( makeExpr( *this ) ) );
		return *this;
	}

	UInt UInt::operator++( int )
	{
		return UInt{ findShader( *this ), sdw::makePostInc( makeExpr( *this ) ) };
	}

	UInt & UInt::operator--()
	{
		updateExpr( sdw::makePreDec( makeExpr( *this ) ) );
		return *this;
	}

	UInt UInt::operator--( int )
	{
		return UInt{ findShader( *this ), sdw::makePostDec( makeExpr( *this ) ) };
	}

	UInt & UInt::operator+=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator-=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator*=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator/=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator+=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator-=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator*=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator/=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator+=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator-=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator*=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator/=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator%=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeModuloAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator%=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeModuloAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator<<=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator>>=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator<<=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator>>=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator<<=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeLShiftAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator>>=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeRShiftAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator&=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator|=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator^=( uint32_t const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeXorAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator&=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator|=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator^=( UInt const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeXorAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator&=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAndAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator|=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeOrAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator^=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeXorAssign( findTypesCache( *this, rhs ).getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	ast::type::TypePtr UInt::makeType( ast::type::TypesCache & cache )
	{
		return cache.getUInt();
	}

	//*************************************************************************

	UInt operator+( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator-( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator*( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator/( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator+( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator-( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator*( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator/( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator+( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeAdd( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator-( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeMinus( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator*( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeTimes( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator/( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeDivide( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator%( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator%( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator<<( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator>>( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator<<( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator>>( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator&( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator|( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator^( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator&( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator|( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator^( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator~( UInt const & expr )
	{
		return UInt{ findShader( expr )
			, sdw::makeBitNot( expr.getType()->getCache().getUInt()
				, makeExpr( expr ) ) };
	}

	//*************************************************************************

	Optional< UInt > operator+( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeAdd( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeMinus( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeTimes( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeDivide( rhs.getType()->getCache().getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeModulo( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator^( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator^( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator^( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator^( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitXor( findTypesCache( lhs, rhs ).getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator~( Optional< UInt > const & expr )
	{
		return Optional< UInt >{ findShader( expr )
			, sdw::makeBitNot( expr.getType()->getCache().getUInt()
				, makeExpr( expr ) )
			, areOptionalEnabled( expr ) };
	}

	//*************************************************************************

	Boolean operator==( UInt const & lhs, UInt const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator!=( UInt const & lhs, UInt const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<( UInt const & lhs, UInt const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<=( UInt const & lhs, UInt const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>( UInt const & lhs, UInt const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>=( UInt const & lhs, UInt const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Optional< Boolean > operator==( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator==( UInt const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator!=( UInt const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<( UInt const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<=( UInt const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>( UInt const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>=( UInt const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
