#include "ShaderWriter/Float.hpp"

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

	Float::Float( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Float::Float( Float && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Float::Float( Float const & rhs )
		: Value{ rhs }
	{
	}

	Float::Float( Value const & rhs )
		: Value{ rhs }
	{
	}

	Float & Float::operator=( Float const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( type::getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	Float & Float::operator=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator=( double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator=( long double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float::operator float()
	{
		return 0.0f;
	}

	Float & Float::operator+=( Float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator-=( Float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator*=( Float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator/=( Float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator+=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator-=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator*=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator/=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator+=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( type::getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Float & Float::operator-=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( type::getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Float & Float::operator*=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( type::getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Float & Float::operator/=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeDivideAssign( type::getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	Float operator+( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator-( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator*( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator/( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator+( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator-( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator*( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator/( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator+( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator-( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator*( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator/( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	//*************************************************************************

	Optional< Float > operator+( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeAdd( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeMinus( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeTimes( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, expr::makeDivide( type::getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
