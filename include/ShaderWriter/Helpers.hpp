/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Helpers_H___
#define ___Writer_Helpers_H___

#include "ShaderWriterPrerequisites.hpp"

#include "CloneExpr.hpp"
#include "GetExprName.hpp"

#include <ASTGenerator/Expr/ExprList.hpp>
#include <ASTGenerator/Type/Type.hpp>
#include <ASTGenerator/Stmt/Stmt.hpp>
#include <ASTGenerator/Stmt/StmtContainer.hpp>
#include <ASTGenerator/Var/Variable.hpp>

namespace sdw
{
	using namespace ::ast;

	stmt::Container * getContainer( Shader & shader );
	expr::ExprPtr makeExpr( var::VariablePtr const & var );
	expr::ExprPtr makeExpr( bool value );
	expr::ExprPtr makeExpr( int32_t value );
	expr::ExprPtr makeExpr( int64_t value );
	expr::ExprPtr makeExpr( uint32_t value );
	expr::ExprPtr makeExpr( uint64_t value );
	expr::ExprPtr makeExpr( float value );
	expr::ExprPtr makeExpr( double value );
	expr::ExprPtr makeExpr( long double value );
	expr::ExprPtr makeInit( type::Kind type
		, std::string name
		, expr::ExprPtr init );
	template< typename T >
	expr::ExprList makeExpr( std::vector< T > const & values );
	void addStmt( Shader & shader
		, stmt::StmtPtr stmt );
	void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt );
	void registerName( Shader & shader
		, std::string const & name
		, type::Kind type );
	void checkNameExists( Shader & shader
		, std::string const & name
		, type::Kind type );
}

#include "Helpers.inl"

#endif
