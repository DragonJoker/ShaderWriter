/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Helpers.hpp"

#include "ShaderWriter/Shader.hpp"

#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprLiteral.hpp>
#include <ASTGenerator/Stmt/StmtContainer.hpp>

namespace sdw
{
	stmt::Container * getContainer( Shader & shader )
	{
		return shader.getContainer();
	}

	expr::ExprPtr makeExpr( var::VariablePtr const & var )
	{
		return expr::makeIdentifier( var );
	}

	expr::ExprPtr makeExpr( bool value )
	{
		return expr::makeLiteral( value );
	}

	expr::ExprPtr makeExpr( int32_t value )
	{
		return expr::makeLiteral( value );
	}

	expr::ExprPtr makeExpr( int64_t value )
	{
		return expr::makeLiteral( int32_t( value ) );
	}

	expr::ExprPtr makeExpr( uint32_t value )
	{
		return expr::makeLiteral( value );
	}

	expr::ExprPtr makeExpr( uint64_t value )
	{
		return expr::makeLiteral( uint32_t( value ) );
	}

	expr::ExprPtr makeExpr( float value )
	{
		return expr::makeLiteral( value );
	}

	expr::ExprPtr makeExpr( double value )
	{
		return expr::makeLiteral( float( value ) );
	}

	expr::ExprPtr makeExpr( long double value )
	{
		return expr::makeLiteral( float( value ) );
	}

	expr::ExprPtr makeInit( type::Kind type
		, std::string name
		, expr::ExprPtr init )
	{
		return expr::makeInit( expr::makeIdentifier( var::makeVariable( type::makeType( type ), std::move( name ) ) )
			, std::move( init ) );
	}

	void addStmt( Shader & shader
		, stmt::StmtPtr stmt )
	{
		shader.addStmt( std::move( stmt ) );
	}

	void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt )
	{
		container.addStmt( std::move( stmt ) );
	}

	void registerName( Shader & shader
		, std::string const & name
		, type::Kind type )
	{
		shader.registerName( name, type );
	}

	void checkNameExists( Shader & shader
		, std::string const & name
		, type::Kind type )
	{
		shader.checkNameExists( name, type );
	}
}
