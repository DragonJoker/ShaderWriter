/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Helpers_H___
#define ___SDW_Helpers_H___

#include "ShaderWriterPrerequisites.hpp"

#include <ShaderAST/Expr/ExprIdentifier.hpp>
#include <ShaderAST/Expr/ExprList.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Stmt/Stmt.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtFunctionDecl.hpp>
#include <ShaderAST/Stmt/StmtInputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtOutputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtPerVertexDecl.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeStruct.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	using namespace ::ast;

	template< typename ValueT >
	ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	template< typename ValueT >
	expr::ExprPtr makeCondition( ValueT const & value );
	template< typename ValueT >
	ast::type::ImageConfiguration makeConfig();
	SDW_API ast::stmt::Container * getContainer( Shader & shader );
	SDW_API ShaderWriter & getCurrentWriter();
	SDW_API ast::type::TypesCache & getTypesCache( ShaderWriter & writer );
	SDW_API ast::type::TypesCache & getTypesCache( Shader const & shader );
	SDW_API Shader & getShader( ShaderWriter & writer );
	SDW_API Shader const & getShader( ShaderWriter const & writer );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, var::VariablePtr const & var
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, bool value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, int32_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, int64_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, uint32_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, uint64_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, float value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, double value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, long double value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, ast::expr::Expr * expr
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, ast::expr::ExprPtr const & expr
		, bool force = true );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, bool value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, int32_t value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, int64_t value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, uint32_t value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, uint64_t value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, float value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, double value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, long double value );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, ast::expr::Expr * expr );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, ast::expr::ExprPtr const & expr );

	SDW_API expr::ExprPtr makeInit( var::VariablePtr var
		, expr::ExprPtr init );
	SDW_API expr::ExprPtr makeAggrInit( var::VariablePtr var
		, expr::ExprList && init );
	SDW_API expr::ExprPtr makeAggrInit( type::TypePtr type
		, expr::ExprList && init );
	SDW_API expr::ExprPtr makeAdd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeMinus( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeTimes( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeDivide( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeModulo( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeLShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeRShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeBitAnd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeBitOr( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeBitXor( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeBitNot( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makeLogAnd( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeLogOr( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeLogNot( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makeAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeAddAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeMinusAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeTimesAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeDivideAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeModuloAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeLShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeRShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeAndAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeOrAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeXorAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeArrayAccess( type::TypePtr type
		, expr::ExprPtr array
		, expr::ExprPtr index );
	SDW_API expr::ExprPtr makeUnMinus( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makeUnPlus( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makePostInc( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makePostDec( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makePreInc( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makePreDec( expr::ExprPtr operand );
	SDW_API expr::ExprPtr makeEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeNEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeLess( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeLEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeGreater( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeGEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs );
	SDW_API expr::ExprPtr makeFnCall( type::TypePtr type
		, expr::IdentifierPtr name
		, expr::ExprList && args );
	SDW_API expr::ExprPtr makeFnCall( type::TypePtr type
		, expr::IdentifierPtr name
		, expr::IdentifierPtr instance
		, expr::ExprList && args );
	SDW_API expr::ExprPtr makeCompositeCtor( expr::CompositeType composite
		, type::Kind component
		, expr::ExprList && args );
	SDW_API expr::ExprPtr makeMbrSelect( expr::ExprPtr outer
		, uint32_t memberIndex
		, expr::IdentifierPtr inner );
	SDW_API expr::ExprPtr makeSwizzle( expr::ExprPtr outer
		, expr::SwizzleKind swizzle );
	SDW_API expr::ExprPtr makeQuestion( type::TypePtr type
		, expr::ExprPtr ctrlExpr
		, expr::ExprPtr trueExpr
		, expr::ExprPtr falseExpr );
	SDW_API expr::ExprPtr makeCast( type::TypePtr destType
		, expr::ExprPtr operand );
	SDW_API expr::IdentifierPtr makeIdent( type::TypesCache & cache
		, var::VariablePtr var );

	SDW_API stmt::StmtPtr makeSimple( expr::ExprPtr expr );
	SDW_API stmt::StmtPtr makePerVertexDecl( stmt::PerVertexDecl::Source source
		, type::TypePtr type );
	SDW_API stmt::StmtPtr makeStructDecl( type::StructPtr type );
	SDW_API stmt::StmtPtr makeShaderStructBufferDecl( std::string const & ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeReturn( expr::ExprPtr expr );
	SDW_API stmt::StmtPtr makePreprocDefine( std::string name
		, expr::ExprPtr expr );
	SDW_API stmt::StmtPtr makeVariableDecl( var::VariablePtr var );
	SDW_API stmt::StmtPtr makeInOutVariableDecl( var::VariablePtr var
		, uint32_t location );
	SDW_API stmt::StmtPtr makeSpecConstantDecl( var::VariablePtr var
		, uint32_t location
		, expr::LiteralPtr literal );
	SDW_API stmt::StmtPtr makeSampledImgDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeImageDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::ContainerPtr makeFuncDecl( type::FunctionPtr type
		, std::string name );

	template< typename T >
	expr::ExprList makeExpr( Shader const & shader
		, std::vector< T > const & values
		, bool force = true );

	SDW_API void addStmt( Shader & shader
		, stmt::StmtPtr stmt );
	SDW_API void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt );
	SDW_API var::VariablePtr registerName( Shader & shader
		, std::string const & name
		, type::TypePtr type );
	SDW_API var::VariablePtr registerMember( Shader & shader
		, var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type );
	SDW_API var::VariablePtr registerBlockVariable( Shader & shader
		, std::string const & name
		, type::TypePtr type );
	SDW_API var::VariablePtr getVar( Shader & shader
		, std::string const & name );
}

#include "Helpers.inl"

#endif
