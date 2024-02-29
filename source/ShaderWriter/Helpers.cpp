/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Helpers.hpp"

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
#include <ShaderAST/Expr/ExprBitXor.hpp>
#include <ShaderAST/Expr/ExprCast.hpp>
#include <ShaderAST/Expr/ExprCompositeConstruct.hpp>
#include <ShaderAST/Expr/ExprCopy.hpp>
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
#include <ShaderAST/Expr/ExprXorAssign.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtAccelerationStructureDecl.hpp>
#include <ShaderAST/Stmt/StmtBufferReferenceDecl.hpp>
#include <ShaderAST/Stmt/StmtCombinedImageDecl.hpp>
#include <ShaderAST/Stmt/StmtDispatchMesh.hpp>
#include <ShaderAST/Stmt/StmtFragmentLayout.hpp>
#include <ShaderAST/Stmt/StmtHitAttributeVariableDecl.hpp>
#include <ShaderAST/Stmt/StmtImageDecl.hpp>
#include <ShaderAST/Stmt/StmtInOutCallableDataVariableDecl.hpp>
#include <ShaderAST/Stmt/StmtInOutRayPayloadVariableDecl.hpp>
#include <ShaderAST/Stmt/StmtInOutVariableDecl.hpp>
#include <ShaderAST/Stmt/StmtReturn.hpp>
#include <ShaderAST/Stmt/StmtSampledImageDecl.hpp>
#include <ShaderAST/Stmt/StmtSamplerDecl.hpp>
#include <ShaderAST/Stmt/StmtShaderStructBufferDecl.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Stmt/StmtSpecialisationConstantDecl.hpp>
#include <ShaderAST/Stmt/StmtStructureDecl.hpp>
#include <ShaderAST/Stmt/StmtVariableDecl.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeStruct.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Shader.hpp>
#include <ShaderAST/ShaderBuilder.hpp>

#include "WriterInt.hpp"
#include "Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	stmt::Container * getContainer( ShaderWriter const & writer )
	{
		return writer.getBuilder().getContainer();
	}

	ShaderWriter & getCurrentWriter()
	{
		assert( doGetCurrentWriter() );
		return *doGetCurrentWriter();
	}

	uint32_t getNextVarId( ShaderWriter & writer )
	{
		return getNextVarId( writer.getBuilder() );
	}

	uint32_t getNextVarId( ShaderBuilder & shader )
	{
		return shader.getNextVarId();
	}

	ast::var::VariablePtr registerFunction( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string name
		, ast::stmt::FunctionFlag flag )
	{
		return writer.getBuilder().registerFunction( std::move( name ), std::move( type ), flag );
	}

	ast::var::VariablePtr registerFunction( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string name
		, uint32_t flags )
	{
		return writer.getBuilder().registerFunction( std::move( name ), std::move( type ), flags );
	}

	ast::stmt::StmtCache & getStmtCache( ShaderWriter const & writer )
	{
		return writer.getStmtCache();
	}

	ast::stmt::StmtCache & getStmtCache( ShaderWriter const * writer )
	{
		return writer->getStmtCache();
	}

	ast::stmt::StmtCache & getStmtCache( Shader const & shader )
	{
		return shader.getStmtCache();
	}

	ast::stmt::StmtCache & getStmtCache( ShaderBuilder const & builder )
	{
		return builder.getStmtCache();
	}

	expr::ExprCache & getExprCache( ShaderWriter const & writer )
	{
		return writer.getExprCache();
	}

	expr::ExprCache & getExprCache( Shader const & shader )
	{
		return shader.getExprCache();
	}

	expr::ExprCache & getExprCache( ShaderBuilder const & builder )
	{
		return builder.getExprCache();
	}

	type::TypesCache & getTypesCache( ShaderWriter const & writer )
	{
		return writer.getTypesCache();
	}

	type::TypesCache & getTypesCache( Shader const & shader )
	{
		return shader.getTypesCache();
	}

	type::TypesCache & getTypesCache( ShaderBuilder const & builder )
	{
		return builder.getTypesCache();
	}

	ShaderBuilder & getBuilder( ShaderWriter & writer )
	{
		return writer.getBuilder();
	}

	ShaderBuilder const & getBuilder( ShaderWriter const & writer )
	{
		return writer.getBuilder();
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, bool value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), value );
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, int32_t value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), value );
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, int64_t value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), int32_t( value ) );
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, uint32_t value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), value );
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, uint64_t value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), uint32_t( value ) );
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, float value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), value );
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, double value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), value );
	}

	expr::LiteralPtr makeLiteral( ShaderWriter const & writer
		, long double value )
	{
		return writer.getExprCache().makeLiteral( writer.getTypesCache(), double( value ) );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, var::VariablePtr const & var
		, [[maybe_unused]] bool force )
	{
		return writer.getExprCache().makeIdentifier( writer.getTypesCache(), var );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, bool value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, value );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, int32_t value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, value );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, int64_t value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, int32_t( value ) );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, uint32_t value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, value );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, uint64_t value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, uint32_t( value ) );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, float value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, value );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, double value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, value );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, long double value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, double( value ) );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, type::Scope value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, uint32_t( value ) );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, type::MemorySemantics value
		, [[maybe_unused]] bool force )
	{
		return makeLiteral( writer, uint32_t( value ) );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, expr::Expr const & expr
		, [[maybe_unused]] bool force )
	{
		return ExprCloner::submit( writer.getExprCache(), expr );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, expr::Expr const * expr
		, [[maybe_unused]] bool force )
	{
		return ExprCloner::submit( writer.getExprCache(), expr );
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, bool value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, int32_t value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, int64_t value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, uint32_t value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, uint64_t value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, float value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, double value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, long double value )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, value ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, expr::Expr const & expr )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, expr ) );
		return result;
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, expr::Expr const * expr )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer, expr ) );
		return result;
	}

	expr::ExprPtr makeInit( var::VariablePtr var
		, expr::ExprPtr init )
	{
		auto & exprCache = getExprExprCache( init );
		auto & typesCache = getExprTypesCache( init );
		return exprCache.makeInit( makeIdent( exprCache, typesCache, std::move( var ) )
			, std::move( init ) );
	}

	expr::ExprPtr makeAggrInit( var::VariablePtr var
		, expr::ExprList && init )
	{
		auto & exprCache = getExprExprCache( init );
		auto & typesCache = getExprTypesCache( init );
		return exprCache.makeAggrInit( makeIdent( exprCache, typesCache, std::move( var ) )
			, std::move( init ) );
	}

	expr::ExprPtr makeAggrInit( type::TypePtr type
		, expr::ExprList && init )
	{
		auto & exprCache = getExprExprCache( init );
		return exprCache.makeAggrInit( std::move( type )
			, std::move( init ) );
	}

	expr::ExprPtr makeAdd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeAdd( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeMinus( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeMinus( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeTimes( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeTimes( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeDivide( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeDivide( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeModulo( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeModulo( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeLShift( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeRShift( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeRShift( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeBitAnd( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeBitAnd( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeBitOr( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeBitOr( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeBitXor( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeBitXor( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeBitNot( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makeBitNot( std::move( operand ) );
	}

	expr::ExprPtr makeCopy( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makeCopy( std::move( operand ) );
	}

	expr::ExprPtr makeLogAnd( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeLogAnd( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLogOr( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeLogOr( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLogNot( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		auto & typesCache = getExprTypesCache( operand );
		return exprCache.makeLogNot( typesCache
			, std::move( operand ) );
	}

	expr::ExprPtr makeAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeAddAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeAddAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeMinusAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeMinusAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeTimesAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeTimesAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeDivideAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeDivideAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeModuloAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeModuloAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeLShiftAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeRShiftAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeRShiftAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeAndAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeAndAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeOrAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeOrAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeXorAssign( type::TypePtr type
		, expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		return exprCache.makeXorAssign( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeArrayAccess( type::TypePtr type
		, expr::ExprPtr array
		, expr::ExprPtr index )
	{
		auto & exprCache = getExprExprCache( array, index );
		return exprCache.makeArrayAccess( std::move( type )
			, std::move( array )
			, std::move( index ) );
	}

	expr::ExprPtr makeUnMinus( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makeUnaryMinus( std::move( operand ) );
	}

	expr::ExprPtr makeUnPlus( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makeUnaryPlus( std::move( operand ) );
	}

	expr::ExprPtr makePostInc( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makePostIncrement( std::move( operand ) );
	}

	expr::ExprPtr makePostDec( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makePostDecrement( std::move( operand ) );
	}

	expr::ExprPtr makePreInc( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makePreIncrement( std::move( operand ) );
	}

	expr::ExprPtr makePreDec( expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makePreDecrement( std::move( operand ) );
	}

	expr::ExprPtr makeEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeEqual( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeNEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeNotEqual( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLess( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeLess( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeLEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeLessEqual( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeGreater( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeGreater( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeGEqual( expr::ExprPtr lhs
		, expr::ExprPtr rhs )
	{
		auto & exprCache = getExprExprCache( lhs, rhs );
		auto & typesCache = getExprTypesCache( lhs, rhs );
		return exprCache.makeGreaterEqual( typesCache
			, std::move( lhs )
			, std::move( rhs ) );
	}

	expr::ExprPtr makeFnCall( type::TypePtr type
		, expr::IdentifierPtr name
		, expr::ExprList && args )
	{
		auto & exprCache = getExprExprCache( name, args );
		return exprCache.makeFnCall( std::move( type )
			, std::move( name )
			, std::move( args ) );
	}

	expr::ExprPtr makeFnCall( type::TypePtr type
		, expr::IdentifierPtr name
		, expr::IdentifierPtr instance
		, expr::ExprList && args )
	{
		auto & exprCache = getExprExprCache( name, instance, args );
		return exprCache.makeMemberFnCall( std::move( type )
			, std::move( name )
			, std::move( instance )
			, std::move( args ) );
	}

	expr::ExprPtr makeCompositeCtor( expr::CompositeType composite
		, type::Kind component
		, expr::ExprList && args )
	{
		auto & exprCache = getExprExprCache( args );
		return exprCache.makeCompositeConstruct( composite
			, component
			, std::move( args ) );
	}

	expr::ExprPtr makeCompositeCtor( expr::ExprPtr image
		, expr::ExprPtr sampler )
	{
		auto & exprCache = getExprExprCache( image, sampler );
		return exprCache.makeCompositeConstruct( std::move( image )
			, std::move( sampler ) );
	}

	expr::ExprPtr makeMbrSelect( expr::ExprPtr outer
		, uint32_t memberIndex
		, uint64_t flags )
	{
		auto & exprCache = getExprExprCache( outer );
		return exprCache.makeMbrSelect( std::move( outer )
			, memberIndex
			, flags );
	}

	expr::ExprPtr makeSwizzle( expr::ExprPtr outer
		, expr::SwizzleKind swizzle )
	{
		auto & exprCache = getExprExprCache( outer );
		return exprCache.makeSwizzle( std::move( outer )
			, swizzle );
	}

	expr::ExprPtr makeQuestion( type::TypePtr type
		, expr::ExprPtr ctrlExpr
		, expr::ExprPtr trueExpr
		, expr::ExprPtr falseExpr )
	{
		auto & exprCache = getExprExprCache( ctrlExpr, trueExpr, falseExpr );
		return exprCache.makeQuestion( std::move( type )
			, std::move( ctrlExpr )
			, std::move( trueExpr )
			, std::move( falseExpr ) );
	}

	expr::ExprPtr makeCast( type::TypePtr destType
		, expr::ExprPtr operand )
	{
		auto & exprCache = getExprExprCache( operand );
		return exprCache.makeCast( std::move( destType )
			, std::move( operand ) );
	}

	expr::IdentifierPtr makeIdent( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, var::VariablePtr var )
	{
		return exprCache.makeIdentifier( typesCache, std::move( var ) );
	}

	expr::ExprPtr makeDispatchMeshNV( type::TypesCache & typesCache
		, expr::ExprPtr payload
		, expr::ExprPtr numTasks )
	{
		auto & exprCache = getExprExprCache( payload, numTasks );
		return makeDispatchMeshNV( exprCache
			, typesCache
			, std::move( payload )
			, std::move( numTasks ) );
	}

	stmt::StmtPtr makeSimple( stmt::StmtCache & stmtCache
		, expr::ExprPtr expr )
	{
		return stmtCache.makeSimple( std::move( expr ) );
	}

	stmt::StmtPtr makePerVertexDecl( stmt::StmtCache & stmtCache
		, stmt::PerVertexDecl::Source source
		, type::TypePtr type )
	{
		return stmtCache.makePerVertexDecl( source, std::static_pointer_cast< type::Struct >( type ) );
	}

	stmt::StmtPtr makeStructureDecl( stmt::StmtCache & stmtCache
		, type::StructPtr type )
	{
		return stmtCache.makeStructureDecl( std::move( type ) );
	}

	stmt::StmtPtr makeShaderStructBufferDecl( stmt::StmtCache & stmtCache
		, std::string ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmtCache.makeShaderStructBufferDecl( std::move( ssboName )
			, ssboInstance
			, data
			, bindingPoint
			, bindingSet );
	}

	stmt::StmtPtr makeBufferReferenceDecl( stmt::StmtCache & stmtCache
		, type::TypePtr type )
	{
		return stmtCache.makeBufferReferenceDecl( type );
	}

	stmt::StmtPtr makeReturn( stmt::StmtCache & stmtCache
		, expr::ExprPtr expr )
	{
		return stmtCache.makeReturn( std::move( expr ) );
	}

	stmt::StmtPtr makeReturn( stmt::StmtCache & stmtCache )
	{
		return stmtCache.makeReturn();
	}

	stmt::VariableDeclPtr makeVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var )
	{
		return stmtCache.makeVariableDecl( std::move( var ) );
	}

	stmt::StmtPtr makeHitAttributeVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var )
	{
		return stmtCache.makeHitAttributeVariableDecl( std::move( var ) );
	}

	stmt::StmtPtr makeInOutCallableDataVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location )
	{
		return stmtCache.makeInOutCallableDataVariableDecl( std::move( var )
			, location );
	}

	stmt::StmtPtr makeInOutRayPayloadVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location )
	{
		return stmtCache.makeInOutRayPayloadVariableDecl( std::move( var )
			, location );
	}

	stmt::StmtPtr makeInOutVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location )
	{
		return stmtCache.makeInOutVariableDecl( std::move( var )
			, location );
	}

	stmt::StmtPtr makeInOutVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t blendIndex )
	{
		return stmtCache.makeInOutVariableDecl( std::move( var )
			, location
			, streamIndex
			, blendIndex );
	}

	stmt::StmtPtr makeInOutStreamVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, uint32_t streamIndex )
	{
		return stmtCache.makeInOutStreamVariableDecl( std::move( var )
			, location
			, streamIndex );
	}

	stmt::StmtPtr makeInOutBlendVariableDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, uint32_t blendIndex )
	{
		return stmtCache.makeInOutBlendVariableDecl( std::move( var )
			, location
			, blendIndex );
	}

	stmt::StmtPtr makeSpecialisationConstantDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t location
		, expr::LiteralPtr literal )
	{
		return stmtCache.makeSpecialisationConstantDecl( std::move( var )
			, location
			, std::move( literal ) );
	}

	stmt::StmtPtr makeSampledImageDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmtCache.makeSampledImageDecl( std::move( var )
			, bindingPoint
			, bindingSet );
	}

	stmt::StmtPtr makeCombinedImageDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmtCache.makeCombinedImageDecl( std::move( var )
			, bindingPoint
			, bindingSet );
	}

	stmt::StmtPtr makeImageDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmtCache.makeImageDecl( std::move( var )
			, bindingPoint
			, bindingSet );
	}

	stmt::StmtPtr makeAccelerationStructureDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmtCache.makeAccelerationStructureDecl( std::move( var )
			, bindingPoint
			, bindingSet );
	}

	stmt::StmtPtr makeSamplerDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return stmtCache.makeSamplerDecl( std::move( var )
			, bindingPoint
			, bindingSet );
	}

	stmt::ContainerPtr makeFunctionDecl( stmt::StmtCache & stmtCache
		, var::VariablePtr funcVar )
	{
		return stmtCache.makeFunctionDecl( std::move( funcVar ) );
	}

	stmt::StmtPtr makeDispatchMesh( stmt::StmtCache & stmtCache
		, expr::ExprPtr numGroupsX
		, expr::ExprPtr numGroupsY
		, expr::ExprPtr numGroupsZ
		, expr::ExprPtr payload )
	{
		return stmtCache.makeDispatchMesh( std::move( numGroupsX )
			, std::move( numGroupsY )
			, std::move( numGroupsZ )
			, std::move( payload ) );
	}

	void addStmt( ShaderBuilder & builder
		, stmt::StmtPtr stmt )
	{
		builder.addStmt( std::move( stmt ) );
	}

	void addStmt( ShaderWriter & writer
		, stmt::StmtPtr stmt )
	{
		addStmt( writer.getBuilder(), std::move( stmt ) );
	}

	void addGlobalStmt( ShaderBuilder & builder
		, stmt::StmtPtr stmt )
	{
		builder.addGlobalStmt( std::move( stmt ) );
	}

	void addGlobalStmt( ShaderWriter & writer
		, stmt::StmtPtr stmt )
	{
		addGlobalStmt( writer.getBuilder(), std::move( stmt ) );
	}

	void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt )
	{
		container.addStmt( std::move( stmt ) );
	}

	var::VariablePtr registerName( ShaderBuilder & builder
		, std::string name
		, type::TypePtr type )
	{
		return builder.registerName( std::move( name )
			, type );
	}

	var::VariablePtr registerName( ShaderBuilder & builder
		, std::string name
		, type::TypePtr type
		, var::Flag flag )
	{
		return builder.registerName( std::move( name )
			, type
			, flag );
	}

	var::VariablePtr registerName( ShaderBuilder & builder
		, std::string name
		, type::TypePtr type
		, uint64_t flags )
	{
		return builder.registerName( std::move( name )
			, type
			, flags );
	}

	var::VariablePtr registerName( ShaderWriter & writer
		, std::string name
		, type::TypePtr type )
	{
		return writer.getBuilder().registerName( std::move( name )
			, type );
	}

	var::VariablePtr registerName( ShaderWriter & writer
		, std::string name
		, type::TypePtr type
		, uint64_t flags )
	{
		return writer.getBuilder().registerName( std::move( name )
			, type
			, flags );
	}

	var::VariablePtr registerMember( ShaderWriter & writer
		, var::VariablePtr outer
		, std::string name
		, type::TypePtr type )
	{
		return writer.getBuilder().registerMember( outer
			, std::move( name )
			, type );
	}

	var::VariablePtr registerBlockVariable( ShaderWriter & writer
		, std::string name
		, type::TypePtr type )
	{
		return writer.getBuilder().registerBlockVariable( std::move( name )
			, type );
	}

	bool hasVariable( ShaderBuilder const & builder
		, std::string_view name
		, bool isLocale )
	{
		return builder.hasVariable( name, isLocale );
	}

	var::VariablePtr getVariable( ShaderBuilder const & builder
		, std::string_view name
		, bool isLocale )
	{
		return builder.getVariable( name, isLocale );
	}

	bool hasVariable( ShaderWriter const & writer
		, std::string_view name
		, bool isLocale )
	{
		return writer.getBuilder().hasVariable( name, isLocale );
	}

	var::VariablePtr getVariable( ShaderWriter const & writer
		, std::string_view name
		, bool isLocale )
	{
		return writer.getBuilder().getVariable( name, isLocale );
	}

	var::VariablePtr getMemberVariable( ShaderWriter const & writer
		, ast::var::VariablePtr outer
		, std::string_view name )
	{
		return writer.getBuilder().getMemberVariable( outer, name );
	}
}
