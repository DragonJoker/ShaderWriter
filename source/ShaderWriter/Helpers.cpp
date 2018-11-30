/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Helpers.hpp"

#include "ShaderWriter/Shader.hpp"
#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Expr/ExprAdd.hpp>
#include <ShaderAST/Expr/ExprAddAssign.hpp>
#include <ShaderAST/Expr/ExprAggrInit.hpp>
#include <ShaderAST/Expr/ExprAndAssign.hpp>
#include <ShaderAST/Expr/ExprArrayAccess.hpp>
#include <ShaderAST/Expr/ExprAssign.hpp>
#include <ShaderAST/Expr/ExprBitAnd.hpp>
#include <ShaderAST/Expr/ExprBitNot.hpp>
#include <ShaderAST/Expr/ExprBitOr.hpp>
#include <ShaderAST/Expr/ExprCast.hpp>
#include <ShaderAST/Expr/ExprCompositeConstruct.hpp>
#include <ShaderAST/Expr/ExprDivide.hpp>
#include <ShaderAST/Expr/ExprDivideAssign.hpp>
#include <ShaderAST/Expr/ExprEqual.hpp>
#include <ShaderAST/Expr/ExprFnCall.hpp>
#include <ShaderAST/Expr/ExprGreater.hpp>
#include <ShaderAST/Expr/ExprGreaterEqual.hpp>
#include <ShaderAST/Expr/ExprIdentifier.hpp>
#include <ShaderAST/Expr/ExprInit.hpp>
#include <ShaderAST/Expr/ExprLess.hpp>
#include <ShaderAST/Expr/ExprLessEqual.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Expr/ExprLogAnd.hpp>
#include <ShaderAST/Expr/ExprLogNot.hpp>
#include <ShaderAST/Expr/ExprLogOr.hpp>
#include <ShaderAST/Expr/ExprLShift.hpp>
#include <ShaderAST/Expr/ExprLShiftAssign.hpp>
#include <ShaderAST/Expr/ExprMbrSelect.hpp>
#include <ShaderAST/Expr/ExprMinus.hpp>
#include <ShaderAST/Expr/ExprMinusAssign.hpp>
#include <ShaderAST/Expr/ExprModulo.hpp>
#include <ShaderAST/Expr/ExprModuloAssign.hpp>
#include <ShaderAST/Expr/ExprNotEqual.hpp>
#include <ShaderAST/Expr/ExprOrAssign.hpp>
#include <ShaderAST/Expr/ExprPostDecrement.hpp>
#include <ShaderAST/Expr/ExprPostIncrement.hpp>
#include <ShaderAST/Expr/ExprPreDecrement.hpp>
#include <ShaderAST/Expr/ExprPreIncrement.hpp>
#include <ShaderAST/Expr/ExprQuestion.hpp>
#include <ShaderAST/Expr/ExprRShift.hpp>
#include <ShaderAST/Expr/ExprRShiftAssign.hpp>
#include <ShaderAST/Expr/ExprTimes.hpp>
#include <ShaderAST/Expr/ExprTimesAssign.hpp>
#include <ShaderAST/Expr/ExprUnaryMinus.hpp>
#include <ShaderAST/Expr/ExprUnaryPlus.hpp>

#include <ShaderAST/Stmt/PreprocDefine.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtImageDecl.hpp>
#include <ShaderAST/Stmt/StmtInOutVariableDecl.hpp>
#include <ShaderAST/Stmt/StmtReturn.hpp>
#include <ShaderAST/Stmt/StmtSampledImageDecl.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Stmt/StmtStructureDecl.hpp>
#include <ShaderAST/Stmt/StmtVariableDecl.hpp>

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeStruct.hpp>

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace sdw
{
	ast::type::TypePtr getNonArrayType( ast::type::TypePtr type )
	{
		switch ( type->getKind() )
		{
		case type::Kind::eArray:
			return std::static_pointer_cast< type::Array >( type )->getType();
		default:
			return type;
		}
	}

	stmt::Container * getContainer( Shader & shader )
	{
		return shader.getContainer();
	}

	Shader & getShader( ShaderWriter & writer )
	{
		return writer.getShader();
	}

	Shader const & getShader( ShaderWriter const & writer )
	{
		return writer.getShader();
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
		return expr::makeLiteral( value );
	}

	expr::ExprPtr makeExpr( long double value )
	{
		return expr::makeLiteral( double( value ) );
	}

	expr::ExprPtr makeExpr( expr::ExprPtr const & expr )
	{
		return ExprCloner::submit( expr );
	}

	expr::ExprPtr makeExpr( expr::Expr * expr )
	{
		return ExprCloner::submit( expr );
	}

	expr::ExprPtr makeInit( var::VariablePtr var
		, expr::ExprPtr init )
	{
		return expr::makeInit( makeIdent( std::move( var ) )
			, std::move( init ) );
	}

	expr::ExprPtr makeAggrInit( var::VariablePtr var
		, expr::ExprList && init )
	{
		return expr::makeAggrInit( makeIdent( std::move( var ) )
			, std::move( init ) );
	}

	expr::ExprPtr makeAggrInit( type::TypePtr type
		, expr::ExprList && init )
	{
		return expr::makeAggrInit( std::move( type )
			, std::move( init ) );
	}

	expr::ExprPtr makeAdd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeAdd( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeMinus( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeMinus( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeTimes( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeTimes( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeDivide( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeDivide( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeModulo( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeModulo( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeLShift( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeRShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeRShift( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeBitAnd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeBitAnd( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeBitOr( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeBitOr( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeBitNot( type::TypePtr type
		, expr::ExprPtr operand )
	{
		return expr::makeBitNot( std::move( type )
			, std::move( operand ) );
	}

	expr::ExprPtr makeLogAnd( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeLogAnd( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLogOr( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeLogOr( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLogNot( expr::ExprPtr operand )
	{
		return expr::makeLogNot( std::move( operand ) );
	}

	expr::ExprPtr makeAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeAddAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeAddAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeMinusAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeMinusAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeTimesAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeTimesAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeDivideAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeDivideAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeModuloAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeModuloAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeLShiftAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeRShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeRShiftAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeAndAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeAndAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeOrAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeOrAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeArrayAccess( type::TypePtr type
		, expr::ExprPtr array
		, expr::ExprPtr index )
	{
		return expr::makeArrayAccess( std::move( type )
			, std::move( array )
			, std::move( index ) );
	}

	expr::ExprPtr makeUnMinus( expr::ExprPtr operand )
	{
		return expr::makeUnaryMinus( std::move( operand ) );
	}

	expr::ExprPtr makeUnPlus( expr::ExprPtr operand )
	{
		return expr::makeUnaryPlus( std::move( operand ) );
	}

	expr::ExprPtr makePostInc( expr::ExprPtr operand )
	{
		return expr::makePostIncrement( std::move( operand ) );
	}

	expr::ExprPtr makePostDec( expr::ExprPtr operand )
	{
		return expr::makePostDecrement( std::move( operand ) );
	}

	expr::ExprPtr makePreInc( expr::ExprPtr operand )
	{
		return expr::makePreIncrement( std::move( operand ) );
	}

	expr::ExprPtr makePreDec( expr::ExprPtr operand )
	{
		return expr::makePreDecrement( std::move( operand ) );
	}

	expr::ExprPtr makeEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeEqual( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeNEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeNotEqual( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLess( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeLess( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeLessEqual( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeGreater( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeGreater( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeGEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		return expr::makeGreaterEqual( std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeFnCall( type::TypePtr type
		, expr::IdentifierPtr name
		, expr::ExprList && args )
	{
		return expr::makeFnCall( std::move( type )
			, std::move( name )
			, std::move( args ) );
	}

	expr::ExprPtr makeFnCall( type::TypePtr type
		, expr::IdentifierPtr name
		, expr::IdentifierPtr instance
		, expr::ExprList && args )
	{
		return expr::makeMemberFnCall( std::move( type )
			, std::move( name )
			, std::move( instance )
			, std::move( args ) );
	}

	expr::ExprPtr makeCompositeCtor( expr::CompositeType composite
		, type::Kind component
		, expr::ExprList && args )
	{
		return expr::makeCompositeConstruct( composite
			, component
			, std::move( args ) );
	}

	expr::ExprPtr makeMbrSelect( expr::ExprPtr outer
		, uint32_t memberIndex
		, expr::IdentifierPtr inner )
	{
		return expr::makeMbrSelect( std::move( outer )
			, memberIndex
			, std::move( inner ) );
	}

	expr::ExprPtr makeSwizzle( expr::ExprPtr outer
		, expr::SwizzleKind swizzle )
	{
		return expr::makeSwizzle( std::move( outer )
			, swizzle );
	}

	expr::ExprPtr makeQuestion( type::TypePtr type
		, expr::ExprPtr ctrlExpr
		, expr::ExprPtr trueExpr
		, expr::ExprPtr falseExpr )
	{
		return expr::makeQuestion( std::move( type )
			, std::move( ctrlExpr )
			, std::move( trueExpr )
			, std::move( falseExpr ) );
	}

	expr::ExprPtr makeCast( type::TypePtr destType
		, expr::ExprPtr operand )
	{
		return expr::makeCast( std::move( destType )
			, std::move( operand ) );
	}

	expr::IdentifierPtr makeIdent( var::VariablePtr var )
	{
		return expr::makeIdentifier( std::move( var ) );
	}

	stmt::StmtPtr makeSimple( expr::ExprPtr expr )
	{
		return stmt::makeSimple( std::move( expr ) );
	}

	stmt::StmtPtr makePerVertexDecl( stmt::PerVertexDecl::Source source
		, type::TypePtr type )
	{
		return stmt::makePerVertexDecl( source, std::static_pointer_cast< type::Struct >( type ) );
	}

	stmt::StmtPtr makeStructDecl( type::StructPtr type )
	{
		return stmt::makeStructureDecl( std::move( type ) );
	}

	stmt::StmtPtr makeShaderStructBufferDecl( std::string const & ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmt::makeShaderStructBufferDecl( ssboName
			, ssboInstance
			, data
			, bindingPoint
			, bindingSet );
	}

	stmt::StmtPtr makeReturn( expr::ExprPtr expr )
	{
		return stmt::makeReturn( std::move( expr ) );
	}

	stmt::StmtPtr makePreprocDefine( std::string name
		, expr::ExprPtr expr )
	{
		return stmt::makePreprocDefine( std::move( name )
			, std::move( expr ) );
	}

	stmt::StmtPtr makeVariableDecl( var::VariablePtr var )
	{
		return stmt::makeVariableDecl( std::move( var ) );
	}

	stmt::StmtPtr makeInOutVariableDecl( var::VariablePtr var
		, uint32_t location )
	{
		return stmt::makeInOutVariableDecl( std::move( var )
			, location );
	}

	stmt::StmtPtr makeSpecConstantDecl( var::VariablePtr var
		, uint32_t location
		, expr::LiteralPtr literal )
	{
		return stmt::makeSpecialisationConstantDecl( std::move( var )
			, location
			, std::move( literal ) );
	}

	stmt::StmtPtr makeSampledImgDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmt::makeSampledImageDecl( std::move( var )
			, bindingPoint
			, bindingSet );
	}

	stmt::StmtPtr makeImageDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmt::makeImageDecl( std::move( var )
			, bindingPoint
			, bindingSet );
	}

	stmt::ContainerPtr makeFuncDecl( type::TypePtr type
		, std::string name
		, var::VariableList args )
	{
		return stmt::makeFunctionDecl( std::move( type )
			, std::move( name )
			, std::move( args ) );
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

	var::VariablePtr registerName( Shader & shader
		, std::string const & name
		, type::TypePtr type )
	{
		return shader.registerName( name
			, type );
	}

	var::VariablePtr registerMember( Shader & shader
		, var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type )
	{
		return shader.registerMember( outer
			, name
			, type );
	}

	var::VariablePtr getVar( Shader & shader
		, std::string const & name )
	{
		return shader.getVar( name );
	}
}
