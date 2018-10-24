/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Helpers_H___
#define ___SDW_Helpers_H___

#include "ShaderWriterPrerequisites.hpp"

#include "GetExprName.hpp"
#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprList.hpp>
#include <ASTGenerator/Type/Type.hpp>
#include <ASTGenerator/Stmt/Stmt.hpp>
#include <ASTGenerator/Stmt/StmtContainer.hpp>
#include <ASTGenerator/Stmt/StmtFunctionDecl.hpp>
#include <ASTGenerator/Stmt/StmtInputGeometryLayout.hpp>
#include <ASTGenerator/Stmt/StmtOutputGeometryLayout.hpp>
#include <ASTGenerator/Stmt/StmtPerVertexDecl.hpp>
#include <ASTGenerator/Type/TypeStruct.hpp>
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
	ast::expr::ExprPtr makeExpr( ast::expr::Expr * expr );
	ast::expr::ExprPtr makeExpr( ast::expr::ExprPtr const & expr );

	expr::ExprPtr makeInit( var::VariablePtr var
		, expr::ExprPtr init );
	expr::ExprPtr makeAggrInit( var::VariablePtr var
		, expr::ExprList && init );
	expr::ExprPtr makeAdd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeMinus( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeTimes( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeDivide( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeModulo( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeLShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeRShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeBitAnd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeBitOr( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeBitNot( type::TypePtr type
		, expr::ExprPtr operand );
	expr::ExprPtr makeLogAnd( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeLogOr( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeLogNot( expr::ExprPtr operand );
	expr::ExprPtr makeAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeAddAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeMinusAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeTimesAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeDivideAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeModuloAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeLShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeRShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeAndAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeOrAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeArrayAccess( type::TypePtr type
		, expr::ExprPtr array
		, expr::ExprPtr index );
	expr::ExprPtr makeUnMinus( expr::ExprPtr operand );
	expr::ExprPtr makeUnPlus( expr::ExprPtr operand );
	expr::ExprPtr makePostInc( expr::ExprPtr operand );
	expr::ExprPtr makePostDec( expr::ExprPtr operand );
	expr::ExprPtr makePreInc( expr::ExprPtr operand );
	expr::ExprPtr makePreDec( expr::ExprPtr operand );
	expr::ExprPtr makeEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeNEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeLess( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeLEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeGreater( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeGEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	expr::ExprPtr makeFnCall( type::TypePtr type
		, expr::IdentifierPtr name
		, expr::ExprList && args );
	expr::ExprPtr makeMbrSelect( expr::ExprPtr outer
		, expr::IdentifierPtr inner );
	expr::ExprPtr makeQuestion( type::TypePtr type
		, expr::ExprPtr ctrlExpr
		, expr::ExprPtr trueExpr
		, expr::ExprPtr falseExpr );
	expr::ExprPtr makeCast( type::TypePtr destType
		, expr::ExprPtr operand );
	expr::IdentifierPtr makeIdent( var::VariablePtr var );

	stmt::StmtPtr makeSimple( expr::ExprPtr expr );
	stmt::StmtPtr makePerVertexDecl( stmt::PerVertexDecl::Source source
		, type::TypePtr type );
	stmt::StmtPtr makeStructDecl( type::StructPtr type );
	stmt::StmtPtr makeReturn( expr::ExprPtr expr );
	stmt::StmtPtr makePreprocDefine( std::string name
		, expr::ExprPtr expr );
	stmt::StmtPtr makeVariableDecl( var::VariablePtr var );
	stmt::StmtPtr makeInOutVariableDecl( var::VariablePtr var
		, uint32_t location );
	stmt::StmtPtr makeSamplerDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	stmt::StmtPtr makeImageDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	stmt::ContainerPtr makeFuncDecl( type::TypePtr type
		, std::string name
		, var::VariableList args );

	template< typename T >
	expr::ExprList makeExpr( std::vector< T > const & values );
	void addStmt( Shader & shader
		, stmt::StmtPtr stmt );
	void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt );
	var::VariablePtr registerName( Shader & shader
		, std::string const & name
		, type::TypePtr type );
	var::VariablePtr getVar( Shader & shader
		, std::string const & name
		, type::TypePtr type );
}

#include "Helpers.inl"

#endif
