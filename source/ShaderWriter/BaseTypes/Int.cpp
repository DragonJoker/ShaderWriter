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
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	Int & Int::operator=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator=( int64_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getInt()
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
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator+=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator-=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator*=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator/=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator+=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeModuloAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeModuloAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeModuloAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator<<=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeLShiftAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator>>=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeRShiftAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator&=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAndAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator|=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeOrAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	Int operator+( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator~( Int const & expr )
	{
		return Int{ findShader( expr )
			, sdw::makeBitNot( type::getInt()
				, makeExpr( expr ) ) };
	}

	//*************************************************************************

	Optional< Int > operator+( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, sdw::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator~( Optional< Int > const & expr )
	{
		return Optional< Int >{ findShader( expr )
			, sdw::makeBitNot( type::getInt()
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
