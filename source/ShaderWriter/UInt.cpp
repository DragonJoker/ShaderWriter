/*
See LICENSE file in root folder
*/
#include "ShaderWriter/UInt.hpp"

#include "ShaderWriter/Bool.hpp"

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
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	UInt & UInt::operator=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator=( uint64_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getUInt()
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
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator-=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator*=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator/=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator+=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator-=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator*=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator/=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator+=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator-=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator*=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator/=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator%=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeModuloAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator%=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeModuloAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator<<=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator>>=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator<<=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeLShiftAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator>>=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeRShiftAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator<<=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeLShiftAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator>>=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeRShiftAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator&=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator|=( uint32_t const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator&=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAndAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator|=( UInt const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeOrAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator&=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAndAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	UInt & UInt::operator|=( Optional< UInt > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeOrAssign( type::getUInt()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	UInt operator+( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator-( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator*( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator/( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator+( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator-( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator*( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator/( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator+( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator-( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator*( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator/( uint32_t const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator%( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator%( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator<<( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator>>( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator<<( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator>>( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator&( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator|( UInt const & lhs, uint32_t const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator&( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator|( UInt const & lhs, UInt const & rhs )
	{
		return UInt{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	UInt operator~( UInt const & expr )
	{
		return UInt{ findShader( expr )
			, sdw::makeBitNot( type::getUInt()
				, makeExpr( expr ) ) };
	}

	//*************************************************************************

	Optional< UInt > operator+( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator+( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeAdd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator-( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeMinus( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator*( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeTimes( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator/( uint32_t const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( rhs )
			, sdw::makeDivide( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs )
			, sdw::makeModulo( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator%( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeModulo( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator<<( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeLShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator>>( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeRShift( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( Optional< UInt > const & lhs, uint32_t const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( Optional< UInt > const & lhs, UInt const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( UInt const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator&( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitAnd( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator|( Optional< UInt > const & lhs, Optional< UInt > const & rhs )
	{
		return Optional< UInt >{ findShader( lhs, rhs )
			, sdw::makeBitOr( type::getUInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< UInt > operator~( Optional< UInt > const & expr )
	{
		return Optional< UInt >{ findShader( expr )
			, sdw::makeBitNot( type::getUInt()
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
