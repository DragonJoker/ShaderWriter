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
#include <ShaderAST/Stmt/StmtVariableDecl.hpp>
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

	template< typename TypeT >
	concept U32Compatible = std::is_same_v< uint32_t, uint32_t >
		|| std::is_same_v< uint32_t, std::underlying_type_t< TypeT > >;

	template< U32Compatible BindingT, U32Compatible SetT >
	LocationHelper makeLocation( BindingT binding, SetT set )
	{
		return { .binding = uint32_t( binding ), .set = uint32_t( set ) };
	}

	template< typename ValueT >
	ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	template< typename ValueT >
	expr::ExprPtr makeCondition( ValueT value );
	template< typename ValueT >
	ast::type::ImageConfiguration makeConfig();
	SDW_API ast::stmt::Container * getContainer( ShaderWriter const & shader );
	SDW_API ShaderWriter & getCurrentWriter();
	SDW_API uint32_t getNextVarId( ShaderWriter & writer );
	SDW_API uint32_t getNextVarId( ShaderBuilder & builder );
	SDW_API ast::var::VariablePtr registerFunction( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string name
		, stmt::FunctionFlag flag );
	SDW_API ast::var::VariablePtr registerFunction( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string name
		, uint32_t flags );
	SDW_API ast::stmt::StmtCache & getStmtCache( ShaderWriter const & writer );
	SDW_API ast::stmt::StmtCache & getStmtCache( ShaderWriter const * writer );
	SDW_API ast::stmt::StmtCache & getStmtCache( Shader const & shader );
	SDW_API ast::stmt::StmtCache & getStmtCache( ShaderBuilder const & builder );
	SDW_API ast::expr::ExprCache & getExprCache( ShaderWriter const & writer );
	SDW_API ast::expr::ExprCache & getExprCache( Shader const & shader );
	SDW_API ast::expr::ExprCache & getExprCache( ShaderBuilder const & builder );
	SDW_API ast::type::TypesCache & getTypesCache( ShaderWriter const & writer );
	SDW_API ast::type::TypesCache & getTypesCache( Shader const & shader );
	SDW_API ast::type::TypesCache & getTypesCache( ShaderBuilder const & builder );
	SDW_API ShaderBuilder & getBuilder( ShaderWriter & writer );
	SDW_API ShaderBuilder const & getBuilder( ShaderWriter const & writer );
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
		, type::Scope value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, type::MemorySemantics value
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, ast::expr::Expr const * expr
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( ShaderWriter const & writer
		, ast::expr::Expr const & expr
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
		, ast::expr::Expr const * expr );
	SDW_API expr::ExprList makeFnArg( ShaderWriter const & writer
		, ast::expr::Expr const & expr );

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
	SDW_API expr::IdentifierPtr makeIdent( expr::ExprCache & exprCache
		, type::TypesCache & cache
		, var::VariablePtr var );
	SDW_API expr::ExprPtr makeDispatchMeshNV( type::TypesCache & cache
		, expr::ExprPtr payload
		, expr::ExprPtr numTasks );

	SDW_API stmt::StmtPtr makeSimple( stmt::StmtCache & stmtCache
		, expr::ExprPtr expr );
	SDW_API stmt::StmtPtr makePerVertexDecl( stmt::StmtCache & stmtCache
		, stmt::PerVertexDecl::Source source
		, type::TypePtr type );
	SDW_API stmt::StmtPtr makeStructureDecl( stmt::StmtCache & stmtCache
		, type::StructPtr type );
	SDW_API stmt::StmtPtr makeShaderStructBufferDecl( stmt::StmtCache & stmtCache
		, std::string ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeBufferReferenceDecl( stmt::StmtCache & stmtCache
		, type::TypePtr type );
	SDW_API stmt::StmtPtr makeReturn( stmt::StmtCache & stmtCache
		, expr::ExprPtr expr );
	SDW_API stmt::StmtPtr makeReturn( stmt::StmtCache & stmtCache );
	SDW_API stmt::VariableDeclPtr makeVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var );
	SDW_API stmt::StmtPtr makeHitAttributeVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var );
	SDW_API stmt::StmtPtr makeInOutCallableDataVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location );
	SDW_API stmt::StmtPtr makeInOutRayPayloadVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location );
	SDW_API stmt::StmtPtr makeInOutVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location );
	SDW_API stmt::StmtPtr makeInOutVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t blendIndex );
	SDW_API stmt::StmtPtr makeInOutStreamVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, uint32_t streamIndex );
	SDW_API stmt::StmtPtr makeInOutBlendVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, uint32_t blendIndex );
	SDW_API stmt::StmtPtr makeSpecialisationConstantDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, expr::LiteralPtr literal );
	SDW_API stmt::StmtPtr makeSampledImageDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeCombinedImageDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeImageDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeAccelerationStructureDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::StmtPtr makeSamplerDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet );
	SDW_API stmt::ContainerPtr makeFunctionDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr funcVar );
	SDW_API stmt::StmtPtr makeDispatchMesh( stmt::StmtCache & stmtCache
		, expr::ExprPtr numGroupsX
		, expr::ExprPtr numGroupsY
		, expr::ExprPtr numGroupsZ
		, expr::ExprPtr payload );

	template< typename T >
	expr::ExprList makeExpr( ShaderWriter const & writer
		, std::vector< T > const & values
		, bool force = true );
	template< typename T >
	expr::ExprList makeConstExpr( ShaderWriter const & writer
		, std::vector< T > const & value
		, bool force = true );

	SDW_API void addStmt( ShaderBuilder & builder
		, stmt::StmtPtr stmt );
	SDW_API void addStmt( ShaderWriter & writer
		, stmt::StmtPtr stmt );
	SDW_API void addGlobalStmt( ShaderBuilder & builder
		, stmt::StmtPtr stmt );
	SDW_API void addGlobalStmt( ShaderWriter & writer
		, stmt::StmtPtr stmt );
	SDW_API void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt );
	SDW_API var::VariablePtr registerName( ShaderBuilder & builder
		, std::string name
		, type::TypePtr type );
	SDW_API var::VariablePtr registerName( ShaderBuilder & builder
		, std::string name
		, type::TypePtr type
		, var::Flag flag );
	SDW_API var::VariablePtr registerName( ShaderBuilder & builder
		, std::string name
		, type::TypePtr type
		, uint64_t flags );
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
	SDW_API bool hasVariable( ShaderBuilder const & builder
		, std::string_view name
		, bool isLocale );
	SDW_API var::VariablePtr getVariable( ShaderBuilder const & builder
		, std::string_view name
		, bool isLocale );
	SDW_API bool hasVariable( ShaderWriter const & writer
		, std::string_view name
		, bool isLocale );
	SDW_API var::VariablePtr getVariable( ShaderWriter const & writer
		, std::string_view name
		, bool isLocale );
	SDW_API var::VariablePtr getMemberVariable( ShaderWriter const & writer
		, ast::var::VariablePtr outer
		, std::string_view name );

	template< typename StmtT >
	void addStmt( ShaderWriter & writer
		, stmt::StmtPtrT< StmtT > stmt )
	{
#pragma warning( push )
#pragma warning( disable: 4946 )
		addStmt( writer, stmt::StmtPtr{ reinterpret_cast< stmt::Stmt * >( stmt.release() ) } );
#pragma warning( pop )
	}
}

#include "Helpers.inl"

#endif
