/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Helpers_H___
#define ___SDW_Helpers_H___

#include "ShaderWriterPrerequisites.hpp"

#include <ShaderAST/Expr/ExprIdentifier.hpp>
#include <ShaderAST/Expr/ExprList.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Expr/SwizzleKind.hpp>
#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Stmt/Stmt.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtFunctionDecl.hpp>
#include <ShaderAST/Stmt/StmtInputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtOutputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtPerVertexDecl.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeStruct.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	using namespace ::ast;
	
	struct LocationHelper
	{
		uint32_t binding;
		uint32_t set;
	};

	template< typename ValueT >
	ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	template< typename ValueT >
	expr::ExprPtr makeCondition( ValueT value );
	template< typename ValueT >
	ast::type::ImageConfiguration makeConfig();
	SDW_API ast::stmt::Container * getContainer( ShaderWriter & shader );
	SDW_API ShaderWriter & getCurrentWriter();
	SDW_API uint32_t getNextVarId( ShaderWriter & writer );
	SDW_API uint32_t getNextVarId( Shader & shader );
	SDW_API ast::type::TypesCache & getTypesCache( ShaderWriter & writer );
	SDW_API ast::type::TypesCache & getTypesCache( ShaderWriter const & writer );
	SDW_API ast::type::TypesCache & getTypesCache( Shader const & shader );
	SDW_API Shader & getShader( ShaderWriter & writer );
	SDW_API Shader & getShader( ShaderWriter const & writer );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, bool value );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, int32_t value );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, int64_t value );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, uint32_t value );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, uint64_t value );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, float value );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, double value );
	SDW_API expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, long double value );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, var::VariablePtr const & var
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, bool value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, int32_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, int64_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, uint32_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, uint64_t value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, float value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, double value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, long double value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, ast::expr::Expr * expr
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, ast::expr::ExprPtr const & expr
		, bool force = true );

	template< typename T >
	expr::ExprPtr makeConstExpr( ShaderWriter const & writer
		, T const & value
		, bool force = true );

	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, bool value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, int32_t value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, int64_t value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, uint32_t value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, uint64_t value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, float value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, double value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, long double value );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, ast::expr::Expr * expr );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
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
	SDW_API expr::ExprPtr makeCopy( expr::ExprPtr operand );
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
	SDW_API expr::ExprPtr makeCompositeCtor( expr::ExprPtr image
		, expr::ExprPtr sampler );
	SDW_API expr::ExprPtr makeMbrSelect( expr::ExprPtr outer
		, uint32_t memberIndex
		, uint64_t flags );
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
	SDW_API stmt::StmtPtr makeShaderStructBufferDecl( std::string ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeBufferReferenceDecl( type::TypePtr type );
	SDW_API stmt::StmtPtr makeReturn( expr::ExprPtr expr );
	SDW_API stmt::StmtPtr makePreprocDefine( Shader & shader
		, std::string name
		, expr::ExprPtr expr );
	SDW_API stmt::StmtPtr makeVariableDecl( var::VariablePtr var );
	SDW_API stmt::StmtPtr makeHitAttributeVariableDecl( var::VariablePtr var );
	SDW_API stmt::StmtPtr makeInOutCallableDataVariableDecl( var::VariablePtr var
		, uint32_t location );
	SDW_API stmt::StmtPtr makeInOutRayPayloadVariableDecl( var::VariablePtr var
		, uint32_t location );
	SDW_API stmt::StmtPtr makeInOutVariableDecl( var::VariablePtr var
		, uint32_t location );
	SDW_API stmt::StmtPtr makeInOutVariableDecl( var::VariablePtr var
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t blendIndex );
	SDW_API stmt::StmtPtr makeInOutStreamVariableDecl( var::VariablePtr var
		, uint32_t location
		, uint32_t streamIndex );
	SDW_API stmt::StmtPtr makeInOutBlendVariableDecl( var::VariablePtr var
		, uint32_t location
		, uint32_t blendIndex );
	SDW_API stmt::StmtPtr makeSpecConstantDecl( var::VariablePtr var
		, uint32_t location
		, expr::LiteralPtr literal );
	SDW_API stmt::StmtPtr makeSampledImgDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeCombinedImageDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeImageDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeAccelerationStructureDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeSamplerDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::ContainerPtr makeFuncDecl( type::FunctionPtr type
		, std::string name );

	template< typename T >
	expr::ExprList makeExpr( ShaderWriter const & writer
		, std::vector< T > const & values
		, bool force = true );
	template< typename T >
	expr::ExprList makeConstExpr( ShaderWriter const & writer
		, std::vector< T > const & value
		, bool force = true );

	SDW_API void addStmt( Shader & shader
		, stmt::StmtPtr stmt );
	SDW_API void addStmt( ShaderWriter & writer
		, stmt::StmtPtr stmt );
	SDW_API void addGlobalStmt( Shader & shader
		, stmt::StmtPtr stmt );
	SDW_API void addGlobalStmt( ShaderWriter & writer
		, stmt::StmtPtr stmt );
	SDW_API void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt );
	SDW_API var::VariablePtr registerName( ShaderWriter & writer
		, std::string name
		, type::TypePtr type );
	SDW_API var::VariablePtr registerName( ShaderWriter & writer
		, std::string name
		, type::TypePtr type
		, uint64_t flags );
	SDW_API var::VariablePtr registerMember( ShaderWriter & writer
		, var::VariablePtr outer
		, std::string name
		, type::TypePtr type );
	SDW_API var::VariablePtr registerBlockVariable( ShaderWriter & writer
		, std::string name
		, type::TypePtr type );
	SDW_API var::VariablePtr getVar( ShaderWriter & writer
		, std::string_view name );
	SDW_API var::VariablePtr getMemberVar( ShaderWriter & writer
		, ast::var::VariablePtr outer
		, std::string_view name );
}

#include "Helpers.inl"

#endif
