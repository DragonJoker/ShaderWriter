#include "ShaderWriter/Int.hpp"

#include "ShaderWriter/UInt.hpp"

#include <ASTGenerator/Expr/ExprAddAssign.hpp>
#include <ASTGenerator/Expr/ExprAndAssign.hpp>
#include <ASTGenerator/Expr/ExprBitAnd.hpp>
#include <ASTGenerator/Expr/ExprBitNot.hpp>
#include <ASTGenerator/Expr/ExprBitOr.hpp>
#include <ASTGenerator/Expr/ExprDivideAssign.hpp>
#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprLiteral.hpp>
#include <ASTGenerator/Expr/ExprLShift.hpp>
#include <ASTGenerator/Expr/ExprLShiftAssign.hpp>
#include <ASTGenerator/Expr/ExprMinusAssign.hpp>
#include <ASTGenerator/Expr/ExprModulo.hpp>
#include <ASTGenerator/Expr/ExprModuloAssign.hpp>
#include <ASTGenerator/Expr/ExprOrAssign.hpp>
#include <ASTGenerator/Expr/ExprPostDecrement.hpp>
#include <ASTGenerator/Expr/ExprPostIncrement.hpp>
#include <ASTGenerator/Expr/ExprPreDecrement.hpp>
#include <ASTGenerator/Expr/ExprPreIncrement.hpp>
#include <ASTGenerator/Expr/ExprRShift.hpp>
#include <ASTGenerator/Expr/ExprRShiftAssign.hpp>
#include <ASTGenerator/Expr/ExprTimesAssign.hpp>

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
				, stmt::makeSimple( expr::makeAssign( type::getInt()
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
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator=( int64_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( int32_t( rhs ) ) ) ) );
		return *this;
	}

	Int & Int::operator=( uint64_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( int64_t( rhs ) ) ) ) );
		return *this;
	}

	Int::operator uint32_t()
	{
		return 0u;
	}

	Int & Int::operator++()
	{
		updateExpr( expr::makePreIncrement( makeExpr( *this ) ) );
		return *this;
	}

	Int Int::operator++( int )
	{
		return Int{ findShader( *this ), expr::makePostIncrement( makeExpr( *this ) ) };
	}

	Int & Int::operator--()
	{
		updateExpr( expr::makePreDecrement( makeExpr( *this ) ) );
		return *this;
	}

	Int Int::operator--( int )
	{
		return Int{ findShader( *this ), expr::makePostDecrement( makeExpr( *this ) ) };
	}

	Int & Int::operator+=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator+=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator-=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator*=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator/=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeDivideAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator+=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator+=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( type::getInt()
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
				, stmt::makeSimple( expr::makeMinusAssign( type::getInt()
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
				, stmt::makeSimple( expr::makeTimesAssign( type::getInt()
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
				, stmt::makeSimple( expr::makeDivideAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator+=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator+=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator-=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator*=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator/=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeModuloAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeModuloAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeModuloAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeModuloAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator%=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeModuloAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator%=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeModuloAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator<<=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
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
				, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator<<=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator>>=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator<<=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	Int & Int::operator>>=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	Int & Int::operator&=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAndAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( int32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeOrAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAndAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeOrAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAndAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( Int const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeOrAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( Optional< Int > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAndAssign( type::getInt()
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
				, stmt::makeSimple( expr::makeOrAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator&=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAndAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator|=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeOrAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator&=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAndAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Int & Int::operator|=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeOrAssign( type::getInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	Int operator+( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( int32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator+( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator-( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator*( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator/( uint32_t const & lhs, Int const & rhs )
	{
		return Int{ findShader( rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator%( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator<<( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator>>( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, int32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, uint32_t const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, Int const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator&( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator|( Int const & lhs, UInt const & rhs )
	{
		return Int{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Int operator~( Int const & expr )
	{
		return Int{ findShader( expr )
			, expr::makeBitNot( type::getInt()
				, makeExpr( expr ) ) };
	}

	//*************************************************************************

	Optional< Int > operator+( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( int32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator+( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeAdd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator-( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeMinus( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator*( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeTimes( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator/( uint32_t const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( rhs )
			, expr::makeDivide( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator%( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeModulo( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator<<( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator>>( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, int32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, uint32_t const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, Int const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Int const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, Optional< Int > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, UInt const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Int const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator&( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator|( Optional< Int > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< Int >{ findShader( lhs, rhs )
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Int > operator~( Optional< Int > const & expr )
	{
		return Optional< Int >{ findShader( expr )
			, expr::makeBitNot( type::getInt()
				, makeExpr( expr ) )
			, areOptionalEnabled( expr ) };
	}

	//*************************************************************************
}
