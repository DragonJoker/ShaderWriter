/*
See LICENSE file in root folder
*/
#include "Common.hpp"

#include <ShaderAST/Expr/ExprIntrinsicCall.hpp>
#include <ShaderAST/Expr/MakeIntrinsic.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace checks
{
	using namespace ast;

	static stmt::ContainerPtr makeContainer( stmt::StmtCache & stmtCache
		, expr::Expr const & expr )
	{
		auto container = stmtCache.makeContainer();
		container->addStmt( stmtCache.makeSimple( expr.clone() ) );
		return container;
	}

	static void checkExprDependant( test::TestCounts & testCounts
		, expr::IntrinsicCall const & expr )
	{
		auto & exprCache = expr.getExprCache();
		auto & typesCache = expr.getTypesCache();

		testCounts << "Expr: " << ast::debug::displayExpression( expr ) << test::endl;
		checkNoThrow( ast::resolveConstants( exprCache, expr ) )

		auto clone = expr.clone();
		clone->updateFlag( ast::expr::Flag::eNonUniform );
		testCounts << "NonUniform Clone: " << ast::debug::displayExpression( *clone ) << test::endl;
		checkNoThrow( ast::resolveConstants( exprCache, *clone ) )

		checkNoThrow( ast::listCommaIdentifiers( expr ) )
		checkNoThrow( ast::listIdentifiers( expr ) )
		checkNoThrow( ast::listIdentifiers( expr, ast::type::Kind::eInt32 ) )
		checkNoThrow( ast::listIdentifiers( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) )
		checkNoThrow( ast::listIdentifiers( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) )
		checkNoThrow( ast::findIdentifier( expr ) )
		checkNoThrow( ast::findIdentifier( expr, ast::type::Kind::eInt32 ) )
		checkNoThrow( ast::findIdentifier( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) )
		checkNoThrow( ast::findIdentifier( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) )
		testCounts << "Find default params: [" << ast::findName( expr ) << "]" << test::endl;
		testCounts << "Find typed: [" << ast::findName( expr, ast::type::Kind::eInt32 ) << "]" << test::endl;
		testCounts << "Find flagged: [" << ast::findName( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) << "]" << test::endl;
		testCounts << "Find typed and flagged: [" << ast::findName( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) << "]" << test::endl;

		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		{
			ast::SSAData data{ testCounts.nextVarId, 0u };
			auto container = makeContainer( stmtCache, expr );
			container = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, false );
			container = ast::resolveConstants( stmtCache, exprCache, typesCache, *container );
			container = ast::simplify( stmtCache, exprCache, typesCache, *container );
			container = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, {} );
		}
		{
			ast::SSAData data{ testCounts.nextVarId, 0u };
			auto container = makeContainer( stmtCache, expr );
			container = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, true );
			container = ast::resolveConstants( stmtCache, exprCache, typesCache, *container );
			container = ast::simplify( stmtCache, exprCache, typesCache, *container );
			container = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, {} );
		}
	}
	// Angle and Trigonometry Functions

	static void testDegrees1(test::TestCounts & testCounts )
	{
		testBegin( "testDegrees1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto radiansVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "radians" );
		auto radians = exprCache.makeIdentifier( typesCache, radiansVar );
		auto result = expr::makeDegrees1( exprCache
			, typesCache
			, std::move( radians ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDegrees2(test::TestCounts & testCounts )
	{
		testBegin( "testDegrees2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto radiansVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "radians" );
		auto radians = exprCache.makeIdentifier( typesCache, radiansVar );
		auto result = expr::makeDegrees2( exprCache
			, typesCache
			, std::move( radians ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDegrees3(test::TestCounts & testCounts )
	{
		testBegin( "testDegrees3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto radiansVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "radians" );
		auto radians = exprCache.makeIdentifier( typesCache, radiansVar );
		auto result = expr::makeDegrees3( exprCache
			, typesCache
			, std::move( radians ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDegrees4(test::TestCounts & testCounts )
	{
		testBegin( "testDegrees4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto radiansVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "radians" );
		auto radians = exprCache.makeIdentifier( typesCache, radiansVar );
		auto result = expr::makeDegrees4( exprCache
			, typesCache
			, std::move( radians ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRadians1F(test::TestCounts & testCounts )
	{
		testBegin( "testRadians1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto degreesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "degrees" );
		auto degrees = exprCache.makeIdentifier( typesCache, degreesVar );
		auto result = expr::makeRadians1F( exprCache
			, typesCache
			, std::move( degrees ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRadians2F(test::TestCounts & testCounts )
	{
		testBegin( "testRadians2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto degreesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "degrees" );
		auto degrees = exprCache.makeIdentifier( typesCache, degreesVar );
		auto result = expr::makeRadians2F( exprCache
			, typesCache
			, std::move( degrees ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRadians3F(test::TestCounts & testCounts )
	{
		testBegin( "testRadians3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto degreesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "degrees" );
		auto degrees = exprCache.makeIdentifier( typesCache, degreesVar );
		auto result = expr::makeRadians3F( exprCache
			, typesCache
			, std::move( degrees ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRadians4F(test::TestCounts & testCounts )
	{
		testBegin( "testRadians4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto degreesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "degrees" );
		auto degrees = exprCache.makeIdentifier( typesCache, degreesVar );
		auto result = expr::makeRadians4F( exprCache
			, typesCache
			, std::move( degrees ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCos1(test::TestCounts & testCounts )
	{
		testBegin( "testCos1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCos1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCos2(test::TestCounts & testCounts )
	{
		testBegin( "testCos2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCos2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCos3(test::TestCounts & testCounts )
	{
		testBegin( "testCos3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCos3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCos4(test::TestCounts & testCounts )
	{
		testBegin( "testCos4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCos4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSin1(test::TestCounts & testCounts )
	{
		testBegin( "testSin1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSin1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSin2(test::TestCounts & testCounts )
	{
		testBegin( "testSin2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSin2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSin3(test::TestCounts & testCounts )
	{
		testBegin( "testSin3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSin3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSin4(test::TestCounts & testCounts )
	{
		testBegin( "testSin4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSin4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTan1(test::TestCounts & testCounts )
	{
		testBegin( "testTan1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTan1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTan2(test::TestCounts & testCounts )
	{
		testBegin( "testTan2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTan2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTan3(test::TestCounts & testCounts )
	{
		testBegin( "testTan3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTan3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTan4(test::TestCounts & testCounts )
	{
		testBegin( "testTan4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTan4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCosh1(test::TestCounts & testCounts )
	{
		testBegin( "testCosh1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCosh1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCosh2(test::TestCounts & testCounts )
	{
		testBegin( "testCosh2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCosh2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCosh3(test::TestCounts & testCounts )
	{
		testBegin( "testCosh3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCosh3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCosh4(test::TestCounts & testCounts )
	{
		testBegin( "testCosh4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCosh4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSinh1(test::TestCounts & testCounts )
	{
		testBegin( "testSinh1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSinh1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSinh2(test::TestCounts & testCounts )
	{
		testBegin( "testSinh2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSinh2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSinh3(test::TestCounts & testCounts )
	{
		testBegin( "testSinh3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSinh3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSinh4(test::TestCounts & testCounts )
	{
		testBegin( "testSinh4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSinh4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTanh1(test::TestCounts & testCounts )
	{
		testBegin( "testTanh1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTanh1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTanh2(test::TestCounts & testCounts )
	{
		testBegin( "testTanh2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTanh2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTanh3(test::TestCounts & testCounts )
	{
		testBegin( "testTanh3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTanh3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTanh4(test::TestCounts & testCounts )
	{
		testBegin( "testTanh4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTanh4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcos1(test::TestCounts & testCounts )
	{
		testBegin( "testAcos1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcos1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcos2(test::TestCounts & testCounts )
	{
		testBegin( "testAcos2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcos2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcos3(test::TestCounts & testCounts )
	{
		testBegin( "testAcos3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcos3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcos4(test::TestCounts & testCounts )
	{
		testBegin( "testAcos4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcos4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsin1(test::TestCounts & testCounts )
	{
		testBegin( "testAsin1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsin1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsin2(test::TestCounts & testCounts )
	{
		testBegin( "testAsin2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsin2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsin3(test::TestCounts & testCounts )
	{
		testBegin( "testAsin3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsin3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsin4(test::TestCounts & testCounts )
	{
		testBegin( "testAsin4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsin4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan1(test::TestCounts & testCounts )
	{
		testBegin( "testAtan1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto y_over_xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y_over_x" );
		auto y_over_x = exprCache.makeIdentifier( typesCache, y_over_xVar );
		auto result = expr::makeAtan1( exprCache
			, typesCache
			, std::move( y_over_x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan2(test::TestCounts & testCounts )
	{
		testBegin( "testAtan2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto y_over_xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y_over_x" );
		auto y_over_x = exprCache.makeIdentifier( typesCache, y_over_xVar );
		auto result = expr::makeAtan2( exprCache
			, typesCache
			, std::move( y_over_x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan3(test::TestCounts & testCounts )
	{
		testBegin( "testAtan3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto y_over_xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y_over_x" );
		auto y_over_x = exprCache.makeIdentifier( typesCache, y_over_xVar );
		auto result = expr::makeAtan3( exprCache
			, typesCache
			, std::move( y_over_x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan4(test::TestCounts & testCounts )
	{
		testBegin( "testAtan4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto y_over_xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y_over_x" );
		auto y_over_x = exprCache.makeIdentifier( typesCache, y_over_xVar );
		auto result = expr::makeAtan4( exprCache
			, typesCache
			, std::move( y_over_x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan21(test::TestCounts & testCounts )
	{
		testBegin( "testAtan21" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtan21( exprCache
			, typesCache
			, std::move( y )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan22(test::TestCounts & testCounts )
	{
		testBegin( "testAtan22" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtan22( exprCache
			, typesCache
			, std::move( y )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan23(test::TestCounts & testCounts )
	{
		testBegin( "testAtan23" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtan23( exprCache
			, typesCache
			, std::move( y )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtan24(test::TestCounts & testCounts )
	{
		testBegin( "testAtan24" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtan24( exprCache
			, typesCache
			, std::move( y )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcosh1(test::TestCounts & testCounts )
	{
		testBegin( "testAcosh1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcosh1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcosh2(test::TestCounts & testCounts )
	{
		testBegin( "testAcosh2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcosh2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcosh3(test::TestCounts & testCounts )
	{
		testBegin( "testAcosh3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcosh3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAcosh4(test::TestCounts & testCounts )
	{
		testBegin( "testAcosh4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAcosh4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsinh1(test::TestCounts & testCounts )
	{
		testBegin( "testAsinh1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsinh1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsinh2(test::TestCounts & testCounts )
	{
		testBegin( "testAsinh2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsinh2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsinh3(test::TestCounts & testCounts )
	{
		testBegin( "testAsinh3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsinh3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAsinh4(test::TestCounts & testCounts )
	{
		testBegin( "testAsinh4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAsinh4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtanh1(test::TestCounts & testCounts )
	{
		testBegin( "testAtanh1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtanh1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtanh2(test::TestCounts & testCounts )
	{
		testBegin( "testAtanh2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtanh2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtanh3(test::TestCounts & testCounts )
	{
		testBegin( "testAtanh3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtanh3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtanh4(test::TestCounts & testCounts )
	{
		testBegin( "testAtanh4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAtanh4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Exponential Functions

	static void testPow1(test::TestCounts & testCounts )
	{
		testBegin( "testPow1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makePow1( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPow2(test::TestCounts & testCounts )
	{
		testBegin( "testPow2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makePow2( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPow3(test::TestCounts & testCounts )
	{
		testBegin( "testPow3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makePow3( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPow4(test::TestCounts & testCounts )
	{
		testBegin( "testPow4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makePow4( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp1(test::TestCounts & testCounts )
	{
		testBegin( "testExp1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp2(test::TestCounts & testCounts )
	{
		testBegin( "testExp2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp3(test::TestCounts & testCounts )
	{
		testBegin( "testExp3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp4(test::TestCounts & testCounts )
	{
		testBegin( "testExp4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog1(test::TestCounts & testCounts )
	{
		testBegin( "testLog1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog2(test::TestCounts & testCounts )
	{
		testBegin( "testLog2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog3(test::TestCounts & testCounts )
	{
		testBegin( "testLog3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog4(test::TestCounts & testCounts )
	{
		testBegin( "testLog4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp21(test::TestCounts & testCounts )
	{
		testBegin( "testExp21" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp21( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp22(test::TestCounts & testCounts )
	{
		testBegin( "testExp22" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp22( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp23(test::TestCounts & testCounts )
	{
		testBegin( "testExp23" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp23( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExp24(test::TestCounts & testCounts )
	{
		testBegin( "testExp24" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeExp24( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog21(test::TestCounts & testCounts )
	{
		testBegin( "testLog21" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog21( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog22(test::TestCounts & testCounts )
	{
		testBegin( "testLog22" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog22( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog23(test::TestCounts & testCounts )
	{
		testBegin( "testLog23" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog23( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLog24(test::TestCounts & testCounts )
	{
		testBegin( "testLog24" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLog24( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt1F(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt2F(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt3F(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt4F(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt1D(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt2D(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt3D(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSqrt4D(test::TestCounts & testCounts )
	{
		testBegin( "testSqrt4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSqrt4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt1F(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt2F(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt3F(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt4F(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt1D(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt2D(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt3D(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverseSqrt4D(test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInverseSqrt4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Common Functions

	static void testAbs1F(test::TestCounts & testCounts )
	{
		testBegin( "testAbs1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs2F(test::TestCounts & testCounts )
	{
		testBegin( "testAbs2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs3F(test::TestCounts & testCounts )
	{
		testBegin( "testAbs3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs4F(test::TestCounts & testCounts )
	{
		testBegin( "testAbs4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs1I(test::TestCounts & testCounts )
	{
		testBegin( "testAbs1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs1I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs2I(test::TestCounts & testCounts )
	{
		testBegin( "testAbs2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs2I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs3I(test::TestCounts & testCounts )
	{
		testBegin( "testAbs3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs3I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs4I(test::TestCounts & testCounts )
	{
		testBegin( "testAbs4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs4I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs1D(test::TestCounts & testCounts )
	{
		testBegin( "testAbs1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs2D(test::TestCounts & testCounts )
	{
		testBegin( "testAbs2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs3D(test::TestCounts & testCounts )
	{
		testBegin( "testAbs3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAbs4D(test::TestCounts & testCounts )
	{
		testBegin( "testAbs4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAbs4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign1F(test::TestCounts & testCounts )
	{
		testBegin( "testSign1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign2F(test::TestCounts & testCounts )
	{
		testBegin( "testSign2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign3F(test::TestCounts & testCounts )
	{
		testBegin( "testSign3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign4F(test::TestCounts & testCounts )
	{
		testBegin( "testSign4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign1I(test::TestCounts & testCounts )
	{
		testBegin( "testSign1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign1I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign2I(test::TestCounts & testCounts )
	{
		testBegin( "testSign2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign2I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign3I(test::TestCounts & testCounts )
	{
		testBegin( "testSign3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign3I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign4I(test::TestCounts & testCounts )
	{
		testBegin( "testSign4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign4I( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign1D(test::TestCounts & testCounts )
	{
		testBegin( "testSign1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign2D(test::TestCounts & testCounts )
	{
		testBegin( "testSign2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign3D(test::TestCounts & testCounts )
	{
		testBegin( "testSign3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSign4D(test::TestCounts & testCounts )
	{
		testBegin( "testSign4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSign4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor1F(test::TestCounts & testCounts )
	{
		testBegin( "testFloor1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor2F(test::TestCounts & testCounts )
	{
		testBegin( "testFloor2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor3F(test::TestCounts & testCounts )
	{
		testBegin( "testFloor3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor4F(test::TestCounts & testCounts )
	{
		testBegin( "testFloor4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor1D(test::TestCounts & testCounts )
	{
		testBegin( "testFloor1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor2D(test::TestCounts & testCounts )
	{
		testBegin( "testFloor2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor3D(test::TestCounts & testCounts )
	{
		testBegin( "testFloor3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloor4D(test::TestCounts & testCounts )
	{
		testBegin( "testFloor4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFloor4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc1F(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc2F(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc3F(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc4F(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc1D(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc2D(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc3D(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTrunc4D(test::TestCounts & testCounts )
	{
		testBegin( "testTrunc4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTrunc4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound1F(test::TestCounts & testCounts )
	{
		testBegin( "testRound1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound2F(test::TestCounts & testCounts )
	{
		testBegin( "testRound2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound3F(test::TestCounts & testCounts )
	{
		testBegin( "testRound3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound4F(test::TestCounts & testCounts )
	{
		testBegin( "testRound4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound1D(test::TestCounts & testCounts )
	{
		testBegin( "testRound1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound2D(test::TestCounts & testCounts )
	{
		testBegin( "testRound2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound3D(test::TestCounts & testCounts )
	{
		testBegin( "testRound3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRound4D(test::TestCounts & testCounts )
	{
		testBegin( "testRound4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRound4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven1F(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven2F(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven3F(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven4F(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven1D(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven2D(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven3D(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRoundEven4D(test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeRoundEven4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil1F(test::TestCounts & testCounts )
	{
		testBegin( "testCeil1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil2F(test::TestCounts & testCounts )
	{
		testBegin( "testCeil2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil3F(test::TestCounts & testCounts )
	{
		testBegin( "testCeil3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil4F(test::TestCounts & testCounts )
	{
		testBegin( "testCeil4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil1D(test::TestCounts & testCounts )
	{
		testBegin( "testCeil1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil2D(test::TestCounts & testCounts )
	{
		testBegin( "testCeil2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil3D(test::TestCounts & testCounts )
	{
		testBegin( "testCeil3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCeil4D(test::TestCounts & testCounts )
	{
		testBegin( "testCeil4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeCeil4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract1F(test::TestCounts & testCounts )
	{
		testBegin( "testFract1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract2F(test::TestCounts & testCounts )
	{
		testBegin( "testFract2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract3F(test::TestCounts & testCounts )
	{
		testBegin( "testFract3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract4F(test::TestCounts & testCounts )
	{
		testBegin( "testFract4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract1D(test::TestCounts & testCounts )
	{
		testBegin( "testFract1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract2D(test::TestCounts & testCounts )
	{
		testBegin( "testFract2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract3D(test::TestCounts & testCounts )
	{
		testBegin( "testFract3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFract4D(test::TestCounts & testCounts )
	{
		testBegin( "testFract4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeFract4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod1F(test::TestCounts & testCounts )
	{
		testBegin( "testMod1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod2F(test::TestCounts & testCounts )
	{
		testBegin( "testMod2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod3F(test::TestCounts & testCounts )
	{
		testBegin( "testMod3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod4F(test::TestCounts & testCounts )
	{
		testBegin( "testMod4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod1D(test::TestCounts & testCounts )
	{
		testBegin( "testMod1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod2D(test::TestCounts & testCounts )
	{
		testBegin( "testMod2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod3D(test::TestCounts & testCounts )
	{
		testBegin( "testMod3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMod4D(test::TestCounts & testCounts )
	{
		testBegin( "testMod4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMod4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf1F(test::TestCounts & testCounts )
	{
		testBegin( "testModf1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf2F(test::TestCounts & testCounts )
	{
		testBegin( "testModf2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf3F(test::TestCounts & testCounts )
	{
		testBegin( "testModf3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf4F(test::TestCounts & testCounts )
	{
		testBegin( "testModf4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf1D(test::TestCounts & testCounts )
	{
		testBegin( "testModf1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf2D(test::TestCounts & testCounts )
	{
		testBegin( "testModf2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf3D(test::TestCounts & testCounts )
	{
		testBegin( "testModf3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testModf4D(test::TestCounts & testCounts )
	{
		testBegin( "testModf4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto iVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "i" );
		auto i = exprCache.makeIdentifier( typesCache, iVar );
		auto result = expr::makeModf4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( i ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin1F(test::TestCounts & testCounts )
	{
		testBegin( "testMin1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin2F(test::TestCounts & testCounts )
	{
		testBegin( "testMin2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin3F(test::TestCounts & testCounts )
	{
		testBegin( "testMin3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin4F(test::TestCounts & testCounts )
	{
		testBegin( "testMin4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin1D(test::TestCounts & testCounts )
	{
		testBegin( "testMin1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin2D(test::TestCounts & testCounts )
	{
		testBegin( "testMin2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin3D(test::TestCounts & testCounts )
	{
		testBegin( "testMin3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin4D(test::TestCounts & testCounts )
	{
		testBegin( "testMin4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin1I(test::TestCounts & testCounts )
	{
		testBegin( "testMin1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin1I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin2I(test::TestCounts & testCounts )
	{
		testBegin( "testMin2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin3I(test::TestCounts & testCounts )
	{
		testBegin( "testMin3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin4I(test::TestCounts & testCounts )
	{
		testBegin( "testMin4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin1U(test::TestCounts & testCounts )
	{
		testBegin( "testMin1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin1U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin2U(test::TestCounts & testCounts )
	{
		testBegin( "testMin2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin3U(test::TestCounts & testCounts )
	{
		testBegin( "testMin3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMin4U(test::TestCounts & testCounts )
	{
		testBegin( "testMin4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMin4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax1F(test::TestCounts & testCounts )
	{
		testBegin( "testMax1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax2F(test::TestCounts & testCounts )
	{
		testBegin( "testMax2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax3F(test::TestCounts & testCounts )
	{
		testBegin( "testMax3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax4F(test::TestCounts & testCounts )
	{
		testBegin( "testMax4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax1D(test::TestCounts & testCounts )
	{
		testBegin( "testMax1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax2D(test::TestCounts & testCounts )
	{
		testBegin( "testMax2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax3D(test::TestCounts & testCounts )
	{
		testBegin( "testMax3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax4D(test::TestCounts & testCounts )
	{
		testBegin( "testMax4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax1I(test::TestCounts & testCounts )
	{
		testBegin( "testMax1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax1I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax2I(test::TestCounts & testCounts )
	{
		testBegin( "testMax2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax3I(test::TestCounts & testCounts )
	{
		testBegin( "testMax3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax4I(test::TestCounts & testCounts )
	{
		testBegin( "testMax4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax1U(test::TestCounts & testCounts )
	{
		testBegin( "testMax1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax1U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax2U(test::TestCounts & testCounts )
	{
		testBegin( "testMax2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax3U(test::TestCounts & testCounts )
	{
		testBegin( "testMax3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMax4U(test::TestCounts & testCounts )
	{
		testBegin( "testMax4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMax4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp1F(test::TestCounts & testCounts )
	{
		testBegin( "testClamp1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp2F(test::TestCounts & testCounts )
	{
		testBegin( "testClamp2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp3F(test::TestCounts & testCounts )
	{
		testBegin( "testClamp3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp4F(test::TestCounts & testCounts )
	{
		testBegin( "testClamp4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp1D(test::TestCounts & testCounts )
	{
		testBegin( "testClamp1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp2D(test::TestCounts & testCounts )
	{
		testBegin( "testClamp2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp3D(test::TestCounts & testCounts )
	{
		testBegin( "testClamp3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp4D(test::TestCounts & testCounts )
	{
		testBegin( "testClamp4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp1I(test::TestCounts & testCounts )
	{
		testBegin( "testClamp1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp1I( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp2I(test::TestCounts & testCounts )
	{
		testBegin( "testClamp2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp3I(test::TestCounts & testCounts )
	{
		testBegin( "testClamp3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp4I(test::TestCounts & testCounts )
	{
		testBegin( "testClamp4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp1U(test::TestCounts & testCounts )
	{
		testBegin( "testClamp1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp1U( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp2U(test::TestCounts & testCounts )
	{
		testBegin( "testClamp2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp3U(test::TestCounts & testCounts )
	{
		testBegin( "testClamp3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testClamp4U(test::TestCounts & testCounts )
	{
		testBegin( "testClamp4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto minValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "minVal" );
		auto minVal = exprCache.makeIdentifier( typesCache, minValVar );
		auto maxValVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "maxVal" );
		auto maxVal = exprCache.makeIdentifier( typesCache, maxValVar );
		auto result = expr::makeClamp4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix1F(test::TestCounts & testCounts )
	{
		testBegin( "testMix1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix2F(test::TestCounts & testCounts )
	{
		testBegin( "testMix2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix3F(test::TestCounts & testCounts )
	{
		testBegin( "testMix3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix4F(test::TestCounts & testCounts )
	{
		testBegin( "testMix4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix1D(test::TestCounts & testCounts )
	{
		testBegin( "testMix1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix2D(test::TestCounts & testCounts )
	{
		testBegin( "testMix2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix3D(test::TestCounts & testCounts )
	{
		testBegin( "testMix3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMix4D(test::TestCounts & testCounts )
	{
		testBegin( "testMix4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto result = expr::makeMix4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep1F(test::TestCounts & testCounts )
	{
		testBegin( "testStep1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep1F( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep2F(test::TestCounts & testCounts )
	{
		testBegin( "testStep2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep2F( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep3F(test::TestCounts & testCounts )
	{
		testBegin( "testStep3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep3F( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep4F(test::TestCounts & testCounts )
	{
		testBegin( "testStep4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep4F( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep1D(test::TestCounts & testCounts )
	{
		testBegin( "testStep1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep1D( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep2D(test::TestCounts & testCounts )
	{
		testBegin( "testStep2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep2D( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep3D(test::TestCounts & testCounts )
	{
		testBegin( "testStep3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep3D( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testStep4D(test::TestCounts & testCounts )
	{
		testBegin( "testStep4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edgeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "edge" );
		auto edge = exprCache.makeIdentifier( typesCache, edgeVar );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeStep4D( exprCache
			, typesCache
			, std::move( edge )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep1F(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep1F( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep2F(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep2F( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep3F(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep3F( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep4F(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep4F( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep1D(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep1D( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep2D(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep2D( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep3D(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep3D( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSmoothStep4D(test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto edge0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "edge0" );
		auto edge0 = exprCache.makeIdentifier( typesCache, edge0Var );
		auto edge1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "edge1" );
		auto edge1 = exprCache.makeIdentifier( typesCache, edge1Var );
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeSmoothStep4D( exprCache
			, typesCache
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan1F(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan2F(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan3F(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan4F(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan1D(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan2D(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan3D(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsnan4D(test::TestCounts & testCounts )
	{
		testBegin( "testIsnan4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsnan4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf1F(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf2F(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf3F(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf4F(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf1D(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf2D(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf3D(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIsinf4D(test::TestCounts & testCounts )
	{
		testBegin( "testIsinf4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIsinf4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToInt1(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToInt1( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToInt2(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToInt2( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToInt3(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToInt3( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToInt4(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToInt4( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToUInt1(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToUInt1( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToUInt2(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToUInt2( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToUInt3(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToUInt3( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFloatBitsToUInt4(test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFloatBitsToUInt4( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIntBitsToFloat1(test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIntBitsToFloat1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIntBitsToFloat2(test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIntBitsToFloat2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIntBitsToFloat3(test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIntBitsToFloat3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testIntBitsToFloat4(test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeIntBitsToFloat4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUintBitsToFloat1(test::TestCounts & testCounts )
	{
		testBegin( "testUintBitsToFloat1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeUintBitsToFloat1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUintBitsToFloat2(test::TestCounts & testCounts )
	{
		testBegin( "testUintBitsToFloat2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeUintBitsToFloat2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUintBitsToFloat3(test::TestCounts & testCounts )
	{
		testBegin( "testUintBitsToFloat3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeUintBitsToFloat3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUintBitsToFloat4(test::TestCounts & testCounts )
	{
		testBegin( "testUintBitsToFloat4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeUintBitsToFloat4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma1F(test::TestCounts & testCounts )
	{
		testBegin( "testFma1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma1F( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma2F(test::TestCounts & testCounts )
	{
		testBegin( "testFma2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma2F( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma3F(test::TestCounts & testCounts )
	{
		testBegin( "testFma3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma3F( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma4F(test::TestCounts & testCounts )
	{
		testBegin( "testFma4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma4F( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma1D(test::TestCounts & testCounts )
	{
		testBegin( "testFma1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma1D( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma2D(test::TestCounts & testCounts )
	{
		testBegin( "testFma2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma2D( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma3D(test::TestCounts & testCounts )
	{
		testBegin( "testFma3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma3D( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFma4D(test::TestCounts & testCounts )
	{
		testBegin( "testFma4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto aVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "a" );
		auto a = exprCache.makeIdentifier( typesCache, aVar );
		auto bVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "b" );
		auto b = exprCache.makeIdentifier( typesCache, bVar );
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto result = expr::makeFma4D( exprCache
			, typesCache
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp1F(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp2F(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp3F(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp4F(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp1D(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp2D(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp3D(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFrexp4D(test::TestCounts & testCounts )
	{
		testBegin( "testFrexp4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeFrexp4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp1F(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp2F(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp3F(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp4F(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp1D(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp2D(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp3D(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLdexp4D(test::TestCounts & testCounts )
	{
		testBegin( "testLdexp4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto expVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "exp" );
		auto exp = exprCache.makeIdentifier( typesCache, expVar );
		auto result = expr::makeLdexp4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( exp ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Floating-point Pack and Unpack Functions

	static void testPackDouble2x32(test::TestCounts & testCounts )
	{
		testBegin( "testPackDouble2x32" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto vVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "v" );
		auto v = exprCache.makeIdentifier( typesCache, vVar );
		auto result = expr::makePackDouble2x32( exprCache
			, typesCache
			, std::move( v ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPackHalf2x16(test::TestCounts & testCounts )
	{
		testBegin( "testPackHalf2x16" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto vVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "v" );
		auto v = exprCache.makeIdentifier( typesCache, vVar );
		auto result = expr::makePackHalf2x16( exprCache
			, typesCache
			, std::move( v ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPackSnorm2x16(test::TestCounts & testCounts )
	{
		testBegin( "testPackSnorm2x16" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto vVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "v" );
		auto v = exprCache.makeIdentifier( typesCache, vVar );
		auto result = expr::makePackSnorm2x16( exprCache
			, typesCache
			, std::move( v ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPackSnorm4x8(test::TestCounts & testCounts )
	{
		testBegin( "testPackSnorm4x8" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto vVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "v" );
		auto v = exprCache.makeIdentifier( typesCache, vVar );
		auto result = expr::makePackSnorm4x8( exprCache
			, typesCache
			, std::move( v ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPackUnorm2x16(test::TestCounts & testCounts )
	{
		testBegin( "testPackUnorm2x16" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto vVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "v" );
		auto v = exprCache.makeIdentifier( typesCache, vVar );
		auto result = expr::makePackUnorm2x16( exprCache
			, typesCache
			, std::move( v ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testPackUnorm4x8(test::TestCounts & testCounts )
	{
		testBegin( "testPackUnorm4x8" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto vVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "v" );
		auto v = exprCache.makeIdentifier( typesCache, vVar );
		auto result = expr::makePackUnorm4x8( exprCache
			, typesCache
			, std::move( v ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUnpackDouble2x32(test::TestCounts & testCounts )
	{
		testBegin( "testUnpackDouble2x32" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto dVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "d" );
		auto d = exprCache.makeIdentifier( typesCache, dVar );
		auto result = expr::makeUnpackDouble2x32( exprCache
			, typesCache
			, std::move( d ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUnpackHalf2x16(test::TestCounts & testCounts )
	{
		testBegin( "testUnpackHalf2x16" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto vVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "v" );
		auto v = exprCache.makeIdentifier( typesCache, vVar );
		auto result = expr::makeUnpackHalf2x16( exprCache
			, typesCache
			, std::move( v ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUnpackSnorm2x16(test::TestCounts & testCounts )
	{
		testBegin( "testUnpackSnorm2x16" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeUnpackSnorm2x16( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUnpackSnorm4x8(test::TestCounts & testCounts )
	{
		testBegin( "testUnpackSnorm4x8" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeUnpackSnorm4x8( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUnpackUnorm2x16(test::TestCounts & testCounts )
	{
		testBegin( "testUnpackUnorm2x16" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeUnpackUnorm2x16( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUnpackUnorm4x8(test::TestCounts & testCounts )
	{
		testBegin( "testUnpackUnorm4x8" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeUnpackUnorm4x8( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Geometric Functions

	static void testLength1F(test::TestCounts & testCounts )
	{
		testBegin( "testLength1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLength2F(test::TestCounts & testCounts )
	{
		testBegin( "testLength2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLength3F(test::TestCounts & testCounts )
	{
		testBegin( "testLength3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLength4F(test::TestCounts & testCounts )
	{
		testBegin( "testLength4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLength1D(test::TestCounts & testCounts )
	{
		testBegin( "testLength1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLength2D(test::TestCounts & testCounts )
	{
		testBegin( "testLength2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLength3D(test::TestCounts & testCounts )
	{
		testBegin( "testLength3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLength4D(test::TestCounts & testCounts )
	{
		testBegin( "testLength4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeLength4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance1F(test::TestCounts & testCounts )
	{
		testBegin( "testDistance1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance1F( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance2F(test::TestCounts & testCounts )
	{
		testBegin( "testDistance2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance2F( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance3F(test::TestCounts & testCounts )
	{
		testBegin( "testDistance3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance3F( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance4F(test::TestCounts & testCounts )
	{
		testBegin( "testDistance4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance4F( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance1D(test::TestCounts & testCounts )
	{
		testBegin( "testDistance1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance1D( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance2D(test::TestCounts & testCounts )
	{
		testBegin( "testDistance2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance2D( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance3D(test::TestCounts & testCounts )
	{
		testBegin( "testDistance3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance3D( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDistance4D(test::TestCounts & testCounts )
	{
		testBegin( "testDistance4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto p0Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "p0" );
		auto p0 = exprCache.makeIdentifier( typesCache, p0Var );
		auto p1Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "p1" );
		auto p1 = exprCache.makeIdentifier( typesCache, p1Var );
		auto result = expr::makeDistance4D( exprCache
			, typesCache
			, std::move( p0 )
			, std::move( p1 ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot1F(test::TestCounts & testCounts )
	{
		testBegin( "testDot1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot1F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot2F(test::TestCounts & testCounts )
	{
		testBegin( "testDot2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot3F(test::TestCounts & testCounts )
	{
		testBegin( "testDot3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot4F(test::TestCounts & testCounts )
	{
		testBegin( "testDot4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot1D(test::TestCounts & testCounts )
	{
		testBegin( "testDot1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot1D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot2D(test::TestCounts & testCounts )
	{
		testBegin( "testDot2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot3D(test::TestCounts & testCounts )
	{
		testBegin( "testDot3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDot4D(test::TestCounts & testCounts )
	{
		testBegin( "testDot4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeDot4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCrossF(test::TestCounts & testCounts )
	{
		testBegin( "testCrossF" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeCrossF( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testCrossD(test::TestCounts & testCounts )
	{
		testBegin( "testCrossD" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeCrossD( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize1F(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize1F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize2F(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize3F(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize4F(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize1D(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize1D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize2D(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize3D(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNormalize4D(test::TestCounts & testCounts )
	{
		testBegin( "testNormalize4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNormalize4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward1F(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward1F( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward2F(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward2F( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward3F(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward3F( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward4F(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward4F( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward1D(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward1D( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward2D(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward2D( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward3D(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward3D( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFaceForward4D(test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NrefVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "Nref" );
		auto Nref = exprCache.makeIdentifier( typesCache, NrefVar );
		auto result = expr::makeFaceForward4D( exprCache
			, typesCache
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect1F(test::TestCounts & testCounts )
	{
		testBegin( "testReflect1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect1F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect2F(test::TestCounts & testCounts )
	{
		testBegin( "testReflect2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect2F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect3F(test::TestCounts & testCounts )
	{
		testBegin( "testReflect3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect3F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect4F(test::TestCounts & testCounts )
	{
		testBegin( "testReflect4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect4F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect1D(test::TestCounts & testCounts )
	{
		testBegin( "testReflect1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect1D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect2D(test::TestCounts & testCounts )
	{
		testBegin( "testReflect2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect2D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect3D(test::TestCounts & testCounts )
	{
		testBegin( "testReflect3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect3D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReflect4D(test::TestCounts & testCounts )
	{
		testBegin( "testReflect4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto result = expr::makeReflect4D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract1F(test::TestCounts & testCounts )
	{
		testBegin( "testRefract1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract1F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract2F(test::TestCounts & testCounts )
	{
		testBegin( "testRefract2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract2F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract3F(test::TestCounts & testCounts )
	{
		testBegin( "testRefract3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract3F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract4F(test::TestCounts & testCounts )
	{
		testBegin( "testRefract4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract4F( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract1D(test::TestCounts & testCounts )
	{
		testBegin( "testRefract1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract1D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract2D(test::TestCounts & testCounts )
	{
		testBegin( "testRefract2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract2D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract3D(test::TestCounts & testCounts )
	{
		testBegin( "testRefract3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract3D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testRefract4D(test::TestCounts & testCounts )
	{
		testBegin( "testRefract4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto IVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "I" );
		auto I = exprCache.makeIdentifier( typesCache, IVar );
		auto NVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "N" );
		auto N = exprCache.makeIdentifier( typesCache, NVar );
		auto etaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "eta" );
		auto eta = exprCache.makeIdentifier( typesCache, etaVar );
		auto result = expr::makeRefract4D( exprCache
			, typesCache
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Matrix Functions

	static void testMatrixCompMult2x2F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult2x2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult2x3F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult2x3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult2x4F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult2x4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult3x2F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult3x2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult3x3F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult3x3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult3x4F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult3x4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult4x2F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult4x2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult4x3F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult4x3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult4x4F(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult4x4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult2x2D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult2x2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult2x3D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult2x3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult2x4D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult2x4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult3x2D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult3x2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult3x3D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult3x3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult3x4D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult3x4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult4x2D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult4x2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult4x3D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult4x3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testMatrixCompMult4x4D(test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeMatrixCompMult4x4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct2x2F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct2x2F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct3x3F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct3x3F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct4x4F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct4x4F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct3x2F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct3x2F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct2x3F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct2x3F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct4x2F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct4x2F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct2x4F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct2x4F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct4x3F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct4x3F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct3x4F(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct3x4F( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct2x2D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct2x2D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct3x3D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct3x3D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct4x4D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct4x4D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct3x2D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct3x2D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct2x3D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct2x3D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct4x2D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct4x2D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct2x4D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct2x4D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct4x3D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct4x3D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testOuterProduct3x4D(test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto cVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "c" );
		auto c = exprCache.makeIdentifier( typesCache, cVar );
		auto rVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "r" );
		auto r = exprCache.makeIdentifier( typesCache, rVar );
		auto result = expr::makeOuterProduct3x4D( exprCache
			, typesCache
			, std::move( c )
			, std::move( r ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose2x2F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose2x2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose2x3F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose2x3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose2x4F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose2x4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose3x2F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose3x2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose3x3F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose3x3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose3x4F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose3x4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose4x2F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose4x2F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose4x3F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose4x3F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose4x4F(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose4x4F( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose2x2D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose2x2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose2x3D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose2x3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose2x4D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose2x4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose3x2D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose3x2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose3x3D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose3x3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose3x4D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose3x4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose4x2D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose4x2D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose4x3D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose4x3D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testTranspose4x4D(test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeTranspose4x4D( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDeterminant2x2F(test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant2x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2F(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeDeterminant2x2F( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDeterminant3x3F(test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant3x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3F(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeDeterminant3x3F( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDeterminant4x4F(test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant4x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4F(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeDeterminant4x4F( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDeterminant2x2D(test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant2x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2D(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeDeterminant2x2D( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDeterminant3x3D(test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant3x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3D(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeDeterminant3x3D( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDeterminant4x4D(test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant4x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4D(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeDeterminant4x4D( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverse2x2F(test::TestCounts & testCounts )
	{
		testBegin( "testInverse2x2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2F(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeInverse2x2F( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverse3x3F(test::TestCounts & testCounts )
	{
		testBegin( "testInverse3x3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3F(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeInverse3x3F( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverse4x4F(test::TestCounts & testCounts )
	{
		testBegin( "testInverse4x4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4F(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeInverse4x4F( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverse2x2D(test::TestCounts & testCounts )
	{
		testBegin( "testInverse2x2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat2x2D(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeInverse2x2D( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverse3x3D(test::TestCounts & testCounts )
	{
		testBegin( "testInverse3x3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat3x3D(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeInverse3x3D( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInverse4x4D(test::TestCounts & testCounts )
	{
		testBegin( "testInverse4x4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto mVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getMat4x4D(), "m" );
		auto m = exprCache.makeIdentifier( typesCache, mVar );
		auto result = expr::makeInverse4x4D( exprCache
			, typesCache
			, std::move( m ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Vector Relational Functions

	static void testLessThan2F(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan3F(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan4F(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan2D(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan3D(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan4D(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan2I(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan3I(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan4I(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan2U(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan3U(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThan4U(test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThan4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual2F(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual3F(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual4F(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual2D(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual3D(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual4D(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual2I(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual3I(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual4I(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual2U(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual3U(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testLessThanEqual4U(test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeLessThanEqual4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan2F(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan3F(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan4F(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan2D(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan3D(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan4D(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan2I(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan3I(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan4I(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan2U(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan3U(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThan4U(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThan4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual2F(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual3F(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual4F(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual2D(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual3D(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual4D(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual2I(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual3I(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual4I(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual2U(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual3U(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testGreaterThanEqual4U(test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeGreaterThanEqual4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual2F(test::TestCounts & testCounts )
	{
		testBegin( "testEqual2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual3F(test::TestCounts & testCounts )
	{
		testBegin( "testEqual3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual4F(test::TestCounts & testCounts )
	{
		testBegin( "testEqual4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual2D(test::TestCounts & testCounts )
	{
		testBegin( "testEqual2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual3D(test::TestCounts & testCounts )
	{
		testBegin( "testEqual3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual4D(test::TestCounts & testCounts )
	{
		testBegin( "testEqual4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual2I(test::TestCounts & testCounts )
	{
		testBegin( "testEqual2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual3I(test::TestCounts & testCounts )
	{
		testBegin( "testEqual3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual4I(test::TestCounts & testCounts )
	{
		testBegin( "testEqual4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual2U(test::TestCounts & testCounts )
	{
		testBegin( "testEqual2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual3U(test::TestCounts & testCounts )
	{
		testBegin( "testEqual3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEqual4U(test::TestCounts & testCounts )
	{
		testBegin( "testEqual4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeEqual4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual2F(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual2F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual3F(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual3F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual4F(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual4F( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual2D(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual2D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual3D(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual3D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual4D(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual4D( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual2I(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual2I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual3I(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual3I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual4I(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual4I( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual2U(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual2U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual3U(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual3U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNotEqual4U(test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto result = expr::makeNotEqual4U( exprCache
			, typesCache
			, std::move( x )
			, std::move( y ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAll2(test::TestCounts & testCounts )
	{
		testBegin( "testAll2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAll2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAll3(test::TestCounts & testCounts )
	{
		testBegin( "testAll3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAll3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAll4(test::TestCounts & testCounts )
	{
		testBegin( "testAll4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAll4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAny2(test::TestCounts & testCounts )
	{
		testBegin( "testAny2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAny2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAny3(test::TestCounts & testCounts )
	{
		testBegin( "testAny3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAny3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAny4(test::TestCounts & testCounts )
	{
		testBegin( "testAny4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeAny4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNot2(test::TestCounts & testCounts )
	{
		testBegin( "testNot2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNot2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNot3(test::TestCounts & testCounts )
	{
		testBegin( "testNot3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNot3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testNot4(test::TestCounts & testCounts )
	{
		testBegin( "testNot4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeNot4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Integer Functions

	static void testUaddCarry1(test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto carryVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "carry" );
		auto carry = exprCache.makeIdentifier( typesCache, carryVar );
		auto result = expr::makeUaddCarry1( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUaddCarry2(test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto carryVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "carry" );
		auto carry = exprCache.makeIdentifier( typesCache, carryVar );
		auto result = expr::makeUaddCarry2( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUaddCarry3(test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto carryVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "carry" );
		auto carry = exprCache.makeIdentifier( typesCache, carryVar );
		auto result = expr::makeUaddCarry3( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUaddCarry4(test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto carryVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "carry" );
		auto carry = exprCache.makeIdentifier( typesCache, carryVar );
		auto result = expr::makeUaddCarry4( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUsubBorrow1(test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto borrowVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "borrow" );
		auto borrow = exprCache.makeIdentifier( typesCache, borrowVar );
		auto result = expr::makeUsubBorrow1( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUsubBorrow2(test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto borrowVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "borrow" );
		auto borrow = exprCache.makeIdentifier( typesCache, borrowVar );
		auto result = expr::makeUsubBorrow2( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUsubBorrow3(test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto borrowVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "borrow" );
		auto borrow = exprCache.makeIdentifier( typesCache, borrowVar );
		auto result = expr::makeUsubBorrow3( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUsubBorrow4(test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto borrowVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "borrow" );
		auto borrow = exprCache.makeIdentifier( typesCache, borrowVar );
		auto result = expr::makeUsubBorrow4( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUmulExtended1(test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeUmulExtended1( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUmulExtended2(test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeUmulExtended2( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUmulExtended3(test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeUmulExtended3( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testUmulExtended4(test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeUmulExtended4( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testImulExtended1(test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeImulExtended1( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testImulExtended2(test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeImulExtended2( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testImulExtended3(test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeImulExtended3( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testImulExtended4(test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto yVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "y" );
		auto y = exprCache.makeIdentifier( typesCache, yVar );
		auto msbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "msb" );
		auto msb = exprCache.makeIdentifier( typesCache, msbVar );
		auto lsbVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "lsb" );
		auto lsb = exprCache.makeIdentifier( typesCache, lsbVar );
		auto result = expr::makeImulExtended4( exprCache
			, typesCache
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract1I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract2I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract3I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract4I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract1U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract2U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract3U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldExtract4U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldExtract4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert1I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert1I( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert2I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert2I( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert3I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert3I( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert4I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert4I( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert1U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert1U( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert2U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert2U( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert3U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert3U( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldInsert4U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto baseVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "base" );
		auto base = exprCache.makeIdentifier( typesCache, baseVar );
		auto insertVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "insert" );
		auto insert = exprCache.makeIdentifier( typesCache, insertVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto bitsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "bits" );
		auto bits = exprCache.makeIdentifier( typesCache, bitsVar );
		auto result = expr::makeBitfieldInsert4U( exprCache
			, typesCache
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse1I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse2I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse3I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse4I(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse1U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse2U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse3U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitfieldReverse4U(test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitfieldReverse4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount1I(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount2I(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount3I(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount4I(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount1U(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount2U(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount3U(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testBitCount4U(test::TestCounts & testCounts )
	{
		testBegin( "testBitCount4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeBitCount4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB1I(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB2I(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB3I(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB4I(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB1U(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB2U(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB3U(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindLSB4U(test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindLSB4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB1I(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB2I(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB3I(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB4I(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB1U(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB2U(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB3U(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFindMSB4U(test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeFindMSB4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Atomic Memory Functions

	static void testAtomicAddI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAddI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicAddI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicAddU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAddU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicAddU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicAddF(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAddF" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicAddF( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicAdd2H(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAdd2H" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2H(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2H(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicAdd2H( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicAdd4H(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAdd4H" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4H(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4H(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicAdd4H( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicMinI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMinI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicMinI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicMinU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMinU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicMinU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicMaxI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMaxI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicMaxI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicMaxU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMaxU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicMaxU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicAndI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAndI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicAndI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicAndU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAndU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicAndU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicOrI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicOrI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicOrI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicOrU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicOrU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicOrU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicXorI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicXorI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicXorI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicXorU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicXorU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicXorU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicExchangeI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicExchangeI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicExchangeI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicExchangeU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicExchangeU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicExchangeU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicExchangeF(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicExchangeF" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicExchangeF( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicExchange2H(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicExchange2H" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2H(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2H(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicExchange2H( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicExchange4H(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicExchange4H" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4H(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4H(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicExchange4H( exprCache
			, typesCache
			, std::move( mem )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicCompSwapI(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicCompSwapI" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto compareVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "compare" );
		auto compare = exprCache.makeIdentifier( typesCache, compareVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicCompSwapI( exprCache
			, typesCache
			, std::move( mem )
			, std::move( compare )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testAtomicCompSwapU(test::TestCounts & testCounts )
	{
		testBegin( "testAtomicCompSwapU" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto memVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mem" );
		auto mem = exprCache.makeIdentifier( typesCache, memVar );
		auto compareVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "compare" );
		auto compare = exprCache.makeIdentifier( typesCache, compareVar );
		auto dataVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "data" );
		auto data = exprCache.makeIdentifier( typesCache, dataVar );
		auto result = expr::makeAtomicCompSwapU( exprCache
			, typesCache
			, std::move( mem )
			, std::move( compare )
			, std::move( data ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Derivative Functions

	static void testDFdx1(test::TestCounts & testCounts )
	{
		testBegin( "testDFdx1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdx1( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdx2(test::TestCounts & testCounts )
	{
		testBegin( "testDFdx2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdx2( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdx3(test::TestCounts & testCounts )
	{
		testBegin( "testDFdx3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdx3( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdx4(test::TestCounts & testCounts )
	{
		testBegin( "testDFdx4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdx4( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxCoarse1(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxCoarse1( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxCoarse2(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxCoarse2( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxCoarse3(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxCoarse3( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxCoarse4(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxCoarse4( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxFine1(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxFine1( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxFine2(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxFine2( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxFine3(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxFine3( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdxFine4(test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdxFine4( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdy1(test::TestCounts & testCounts )
	{
		testBegin( "testDFdy1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdy1( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdy2(test::TestCounts & testCounts )
	{
		testBegin( "testDFdy2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdy2( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdy3(test::TestCounts & testCounts )
	{
		testBegin( "testDFdy3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdy3( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdy4(test::TestCounts & testCounts )
	{
		testBegin( "testDFdy4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdy4( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyCoarse1(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyCoarse1( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyCoarse2(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyCoarse2( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyCoarse3(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyCoarse3( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyCoarse4(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyCoarse4( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyFine1(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyFine1( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyFine2(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyFine2( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyFine3(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyFine3( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDFdyFine4(test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeDFdyFine4( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFwidth1(test::TestCounts & testCounts )
	{
		testBegin( "testFwidth1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeFwidth1( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFwidth2(test::TestCounts & testCounts )
	{
		testBegin( "testFwidth2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeFwidth2( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFwidth3(test::TestCounts & testCounts )
	{
		testBegin( "testFwidth3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeFwidth3( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testFwidth4(test::TestCounts & testCounts )
	{
		testBegin( "testFwidth4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto pVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "p" );
		auto p = exprCache.makeIdentifier( typesCache, pVar );
		auto result = expr::makeFwidth4( exprCache
			, typesCache
			, std::move( p ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Interpolation Functions

	static void testInterpolateAtCentroid1(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInterpolateAtCentroid1( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtCentroid2(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInterpolateAtCentroid2( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtCentroid3(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInterpolateAtCentroid3( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtCentroid4(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto xVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "x" );
		auto x = exprCache.makeIdentifier( typesCache, xVar );
		auto result = expr::makeInterpolateAtCentroid4( exprCache
			, typesCache
			, std::move( x ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtSample1(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto sampleVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "sample" );
		auto sample = exprCache.makeIdentifier( typesCache, sampleVar );
		auto result = expr::makeInterpolateAtSample1( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( sample ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtSample2(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto sampleVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "sample" );
		auto sample = exprCache.makeIdentifier( typesCache, sampleVar );
		auto result = expr::makeInterpolateAtSample2( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( sample ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtSample3(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto sampleVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "sample" );
		auto sample = exprCache.makeIdentifier( typesCache, sampleVar );
		auto result = expr::makeInterpolateAtSample3( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( sample ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtSample4(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto sampleVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "sample" );
		auto sample = exprCache.makeIdentifier( typesCache, sampleVar );
		auto result = expr::makeInterpolateAtSample4( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( sample ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtOffset1(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset1" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto result = expr::makeInterpolateAtOffset1( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( offset ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtOffset2(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset2" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto result = expr::makeInterpolateAtOffset2( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( offset ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtOffset3(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset3" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto result = expr::makeInterpolateAtOffset3( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( offset ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testInterpolateAtOffset4(test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset4" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto interpolantVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "interpolant" );
		auto interpolant = exprCache.makeIdentifier( typesCache, interpolantVar );
		auto offsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "offset" );
		auto offset = exprCache.makeIdentifier( typesCache, offsetVar );
		auto result = expr::makeInterpolateAtOffset4( exprCache
			, typesCache
			, std::move( interpolant )
			, std::move( offset ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Geometry Shader Functions

	static void testEmitStreamVertex(test::TestCounts & testCounts )
	{
		testBegin( "testEmitStreamVertex" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto streamVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "stream" );
		auto stream = exprCache.makeIdentifier( typesCache, streamVar );
		auto result = expr::makeEmitStreamVertex( exprCache
			, typesCache
			, std::move( stream ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEndStreamPrimitive(test::TestCounts & testCounts )
	{
		testBegin( "testEndStreamPrimitive" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto streamVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "stream" );
		auto stream = exprCache.makeIdentifier( typesCache, streamVar );
		auto result = expr::makeEndStreamPrimitive( exprCache
			, typesCache
			, std::move( stream ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEmitVertex(test::TestCounts & testCounts )
	{
		testBegin( "testEmitVertex" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto result = expr::makeEmitVertex( exprCache
			, typesCache );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testEndPrimitive(test::TestCounts & testCounts )
	{
		testBegin( "testEndPrimitive" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto result = expr::makeEndPrimitive( exprCache
			, typesCache );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Miscellaneous Functions

	static void testHelperInvocation(test::TestCounts & testCounts )
	{
		testBegin( "testHelperInvocation" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto result = expr::makeHelperInvocation( exprCache
			, typesCache );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	// Shader Invocation and Memory Control Functions

	// Ray tracing Shader Functions

	static void testTraceRay(test::TestCounts & testCounts )
	{
		testBegin( "testTraceRay" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto topLevelVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getAccelerationStructure(), "topLevel" );
		auto topLevel = exprCache.makeIdentifier( typesCache, topLevelVar );
		auto rayFlagsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "rayFlags" );
		auto rayFlags = exprCache.makeIdentifier( typesCache, rayFlagsVar );
		auto cullMaskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "cullMask" );
		auto cullMask = exprCache.makeIdentifier( typesCache, cullMaskVar );
		auto sbtRecordOffsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "sbtRecordOffset" );
		auto sbtRecordOffset = exprCache.makeIdentifier( typesCache, sbtRecordOffsetVar );
		auto sbtRecordStrideVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "sbtRecordStride" );
		auto sbtRecordStride = exprCache.makeIdentifier( typesCache, sbtRecordStrideVar );
		auto missIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "missIndex" );
		auto missIndex = exprCache.makeIdentifier( typesCache, missIndexVar );
		auto rayDescVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getRayDesc(), "rayDesc" );
		auto rayDesc = exprCache.makeIdentifier( typesCache, rayDescVar );
		auto payloadVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getRayPayload( typesCache.getVoid(), 0u ), "payload" );
		auto payload = exprCache.makeIdentifier( typesCache, payloadVar );
		auto result = expr::makeTraceRay( exprCache
			, typesCache
			, std::move( topLevel )
			, std::move( rayFlags )
			, std::move( cullMask )
			, std::move( sbtRecordOffset )
			, std::move( sbtRecordStride )
			, std::move( missIndex )
			, std::move( rayDesc )
			, std::move( payload ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReportIntersection(test::TestCounts & testCounts )
	{
		testBegin( "testReportIntersection" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto hitTVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "hitT" );
		auto hitT = exprCache.makeIdentifier( typesCache, hitTVar );
		auto hitKindVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "hitKind" );
		auto hitKind = exprCache.makeIdentifier( typesCache, hitKindVar );
		auto attribsVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getHitAttribute( typesCache.getVoid() ), "attribs" );
		auto attribs = exprCache.makeIdentifier( typesCache, attribsVar );
		auto result = expr::makeReportIntersection( exprCache
			, typesCache
			, std::move( hitT )
			, std::move( hitKind )
			, std::move( attribs ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testExecuteCallable(test::TestCounts & testCounts )
	{
		testBegin( "testExecuteCallable" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto sbtRecordIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "sbtRecordIndex" );
		auto sbtRecordIndex = exprCache.makeIdentifier( typesCache, sbtRecordIndexVar );
		auto callableVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getCallableData( typesCache.getVoid(), 0u ), "callable" );
		auto callable = exprCache.makeIdentifier( typesCache, callableVar );
		auto result = expr::makeExecuteCallable( exprCache
			, typesCache
			, std::move( sbtRecordIndex )
			, std::move( callable ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	//Mesh Shader NV Functions

	static void testSetMeshOutputCountsNV(test::TestCounts & testCounts )
	{
		testBegin( "testSetMeshOutputCountsNV" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto numVerticesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "numVertices" );
		auto numVertices = exprCache.makeIdentifier( typesCache, numVerticesVar );
		auto numPrimitivesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "numPrimitives" );
		auto numPrimitives = exprCache.makeIdentifier( typesCache, numPrimitivesVar );
		auto result = expr::makeSetMeshOutputCountsNV( exprCache
			, typesCache
			, std::move( numVertices )
			, std::move( numPrimitives ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testDispatchMeshNV(test::TestCounts & testCounts )
	{
		testBegin( "testDispatchMeshNV" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto payloadVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getTaskPayloadNV( typesCache.getVoid() ), "payload" );
		auto payload = exprCache.makeIdentifier( typesCache, payloadVar );
		auto numTasksVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "numTasks" );
		auto numTasks = exprCache.makeIdentifier( typesCache, numTasksVar );
		auto result = expr::makeDispatchMeshNV( exprCache
			, typesCache
			, std::move( payload )
			, std::move( numTasks ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testWritePackedPrimitiveIndices4x8NV(test::TestCounts & testCounts )
	{
		testBegin( "testWritePackedPrimitiveIndices4x8NV" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto indexOffsetVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "indexOffset" );
		auto indexOffset = exprCache.makeIdentifier( typesCache, indexOffsetVar );
		auto packedIndicesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "packedIndices" );
		auto packedIndices = exprCache.makeIdentifier( typesCache, packedIndicesVar );
		auto result = expr::makeWritePackedPrimitiveIndices4x8NV( exprCache
			, typesCache
			, std::move( indexOffset )
			, std::move( packedIndices ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	//Mesh Shader Functions

	static void testSetMeshOutputCounts(test::TestCounts & testCounts )
	{
		testBegin( "testSetMeshOutputCounts" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto numVerticesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "numVertices" );
		auto numVertices = exprCache.makeIdentifier( typesCache, numVerticesVar );
		auto numPrimitivesVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "numPrimitives" );
		auto numPrimitives = exprCache.makeIdentifier( typesCache, numPrimitivesVar );
		auto result = expr::makeSetMeshOutputCounts( exprCache
			, typesCache
			, std::move( numVertices )
			, std::move( numPrimitives ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	//Shader Subgroup Functions

	static void testSubgroupElect(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupElect" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto result = expr::makeSubgroupElect( exprCache
			, typesCache );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAll(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAll" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAll( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAny(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAny" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAny( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAllEqual4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAllEqual4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAllEqual4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcast4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcast4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupBroadcast4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBroadcastFirst4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBroadcastFirst4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBroadcastFirst4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBallot(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBallot" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBallot( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInverseBallot(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInverseBallot" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInverseBallot( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBallotBitExtract(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBallotBitExtract" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto indexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "index" );
		auto index = exprCache.makeIdentifier( typesCache, indexVar );
		auto result = expr::makeSubgroupBallotBitExtract( exprCache
			, typesCache
			, std::move( value )
			, std::move( index ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBallotBitCount(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBallotBitCount" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBallotBitCount( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBallotInclusiveBitCount(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBallotInclusiveBitCount" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBallotInclusiveBitCount( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBallotExclusiveBitCount(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBallotExclusiveBitCount" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBallotExclusiveBitCount( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBallotFindLSB(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBallotFindLSB" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBallotFindLSB( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupBallotFindMSB(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBallotFindMSB" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupBallotFindMSB( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffle4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffle4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupShuffle4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleXor4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleXor4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto maskVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "mask" );
		auto mask = exprCache.makeIdentifier( typesCache, maskVar );
		auto result = expr::makeSubgroupShuffleXor4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( mask ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleUp4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleUp4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleUp4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupShuffleDown4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupShuffleDown4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto deltaVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "delta" );
		auto delta = exprCache.makeIdentifier( typesCache, deltaVar );
		auto result = expr::makeSubgroupShuffleDown4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( delta ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAdd4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAdd4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAdd4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMul4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMul4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMul4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMin4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMin4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMin4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupMax4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMax4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupMax4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupAnd4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAnd4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupAnd4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupOr4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupOr4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupOr4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupXor4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupXor4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupXor4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAdd4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAdd4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAdd4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMul4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMul4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMul4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMin4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMin4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMin4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveMax4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveMax4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveMax4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveAnd4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveAnd4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveAnd4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveOr4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveOr4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveOr4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupInclusiveXor4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupInclusiveXor4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupInclusiveXor4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAdd4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAdd4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAdd4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMul4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMul4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMul4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMin4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMin4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMin4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveMax4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveMax4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveMax4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveAnd4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveAnd4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveAnd4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveOr4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveOr4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveOr4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupExclusiveXor4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupExclusiveXor4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupExclusiveXor4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAdd4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAdd4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAdd4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMul4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMul4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMul4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMin4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMin4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMin4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterMax4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterMax4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterMax4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterAnd4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterAnd4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterAnd4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterOr4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterOr4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterOr4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupClusterXor4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupClusterXor4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto clusterSizeVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "clusterSize" );
		auto clusterSize = exprCache.makeIdentifier( typesCache, clusterSizeVar );
		auto result = expr::makeSubgroupClusterXor4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( clusterSize ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast1B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast2B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast3B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast4B( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadBroadcast4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadBroadcast4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto idVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "id" );
		auto id = exprCache.makeIdentifier( typesCache, idVar );
		auto result = expr::makeSubgroupQuadBroadcast4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( id ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapHorizontal4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapHorizontal4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapHorizontal4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapVertical4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapVertical4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapVertical4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal1F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal2F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal3F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal4F(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal1I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal2I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal3I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal4I(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal1U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal2U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal3U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal4U(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal1B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal1B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getBoolean(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal1B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal2B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal2B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal2B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal3B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal3B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal3B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal4B(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal4B" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4B(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal4B( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal1D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal2D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal3D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testSubgroupQuadSwapDiagonal4D(test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupQuadSwapDiagonal4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeSubgroupQuadSwapDiagonal4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	//Shader Invocation Group Functions

	static void testReadInvocation1F(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation1F( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation2F(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation2F( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation3F(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation3F( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation4F(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation4F( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation1I(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation1I( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation2I(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation2I( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation3I(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation3I( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation4I(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation4I( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation1U(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation1U( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation2U(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation2U( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation3U(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation3U( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation4U(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation4U( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation1D(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation1D( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation2D(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation2D( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation3D(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation3D( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadInvocation4D(test::TestCounts & testCounts )
	{
		testBegin( "testReadInvocation4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto invocationIndexVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "invocationIndex" );
		auto invocationIndex = exprCache.makeIdentifier( typesCache, invocationIndexVar );
		auto result = expr::makeReadInvocation4D( exprCache
			, typesCache
			, std::move( value )
			, std::move( invocationIndex ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation1F(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation1F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getFloat(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation1F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation2F(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation2F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation2F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation3F(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation3F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation3F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation4F(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation4F" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4F(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation4F( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation1I(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation1I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation1I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation2I(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation2I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation2I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation3I(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation3I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation3I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation4I(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation4I" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation4I( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation1U(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation1U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getUInt32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation1U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation2U(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation2U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation2U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation3U(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation3U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation3U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation4U(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation4U" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4U32(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation4U( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation1D(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation1D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getDouble(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation1D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation2D(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation2D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation2D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation3D(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation3D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec3D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation3D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
	static void testReadFirstInvocation4D(test::TestCounts & testCounts )
	{
		testBegin( "testReadFirstInvocation4D" );
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto valueVar = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4D(), "value" );
		auto value = exprCache.makeIdentifier( typesCache, valueVar );
		auto result = expr::makeReadFirstInvocation4D( exprCache
			, typesCache
			, std::move( value ) );
		checkExprDependant( testCounts, *result );
		testEnd()
	}
}

testSuiteMain( TestASTIntrinsics )
{
	testSuiteBegin()
	checks::testDegrees1( testCounts );
	checks::testDegrees2( testCounts );
	checks::testDegrees3( testCounts );
	checks::testDegrees4( testCounts );
	checks::testRadians1F( testCounts );
	checks::testRadians2F( testCounts );
	checks::testRadians3F( testCounts );
	checks::testRadians4F( testCounts );
	checks::testCos1( testCounts );
	checks::testCos2( testCounts );
	checks::testCos3( testCounts );
	checks::testCos4( testCounts );
	checks::testSin1( testCounts );
	checks::testSin2( testCounts );
	checks::testSin3( testCounts );
	checks::testSin4( testCounts );
	checks::testTan1( testCounts );
	checks::testTan2( testCounts );
	checks::testTan3( testCounts );
	checks::testTan4( testCounts );
	checks::testCosh1( testCounts );
	checks::testCosh2( testCounts );
	checks::testCosh3( testCounts );
	checks::testCosh4( testCounts );
	checks::testSinh1( testCounts );
	checks::testSinh2( testCounts );
	checks::testSinh3( testCounts );
	checks::testSinh4( testCounts );
	checks::testTanh1( testCounts );
	checks::testTanh2( testCounts );
	checks::testTanh3( testCounts );
	checks::testTanh4( testCounts );
	checks::testAcos1( testCounts );
	checks::testAcos2( testCounts );
	checks::testAcos3( testCounts );
	checks::testAcos4( testCounts );
	checks::testAsin1( testCounts );
	checks::testAsin2( testCounts );
	checks::testAsin3( testCounts );
	checks::testAsin4( testCounts );
	checks::testAtan1( testCounts );
	checks::testAtan2( testCounts );
	checks::testAtan3( testCounts );
	checks::testAtan4( testCounts );
	checks::testAtan21( testCounts );
	checks::testAtan22( testCounts );
	checks::testAtan23( testCounts );
	checks::testAtan24( testCounts );
	checks::testAcosh1( testCounts );
	checks::testAcosh2( testCounts );
	checks::testAcosh3( testCounts );
	checks::testAcosh4( testCounts );
	checks::testAsinh1( testCounts );
	checks::testAsinh2( testCounts );
	checks::testAsinh3( testCounts );
	checks::testAsinh4( testCounts );
	checks::testAtanh1( testCounts );
	checks::testAtanh2( testCounts );
	checks::testAtanh3( testCounts );
	checks::testAtanh4( testCounts );
	checks::testPow1( testCounts );
	checks::testPow2( testCounts );
	checks::testPow3( testCounts );
	checks::testPow4( testCounts );
	checks::testExp1( testCounts );
	checks::testExp2( testCounts );
	checks::testExp3( testCounts );
	checks::testExp4( testCounts );
	checks::testLog1( testCounts );
	checks::testLog2( testCounts );
	checks::testLog3( testCounts );
	checks::testLog4( testCounts );
	checks::testExp21( testCounts );
	checks::testExp22( testCounts );
	checks::testExp23( testCounts );
	checks::testExp24( testCounts );
	checks::testLog21( testCounts );
	checks::testLog22( testCounts );
	checks::testLog23( testCounts );
	checks::testLog24( testCounts );
	checks::testSqrt1F( testCounts );
	checks::testSqrt2F( testCounts );
	checks::testSqrt3F( testCounts );
	checks::testSqrt4F( testCounts );
	checks::testSqrt1D( testCounts );
	checks::testSqrt2D( testCounts );
	checks::testSqrt3D( testCounts );
	checks::testSqrt4D( testCounts );
	checks::testInverseSqrt1F( testCounts );
	checks::testInverseSqrt2F( testCounts );
	checks::testInverseSqrt3F( testCounts );
	checks::testInverseSqrt4F( testCounts );
	checks::testInverseSqrt1D( testCounts );
	checks::testInverseSqrt2D( testCounts );
	checks::testInverseSqrt3D( testCounts );
	checks::testInverseSqrt4D( testCounts );
	checks::testAbs1F( testCounts );
	checks::testAbs2F( testCounts );
	checks::testAbs3F( testCounts );
	checks::testAbs4F( testCounts );
	checks::testAbs1I( testCounts );
	checks::testAbs2I( testCounts );
	checks::testAbs3I( testCounts );
	checks::testAbs4I( testCounts );
	checks::testAbs1D( testCounts );
	checks::testAbs2D( testCounts );
	checks::testAbs3D( testCounts );
	checks::testAbs4D( testCounts );
	checks::testSign1F( testCounts );
	checks::testSign2F( testCounts );
	checks::testSign3F( testCounts );
	checks::testSign4F( testCounts );
	checks::testSign1I( testCounts );
	checks::testSign2I( testCounts );
	checks::testSign3I( testCounts );
	checks::testSign4I( testCounts );
	checks::testSign1D( testCounts );
	checks::testSign2D( testCounts );
	checks::testSign3D( testCounts );
	checks::testSign4D( testCounts );
	checks::testFloor1F( testCounts );
	checks::testFloor2F( testCounts );
	checks::testFloor3F( testCounts );
	checks::testFloor4F( testCounts );
	checks::testFloor1D( testCounts );
	checks::testFloor2D( testCounts );
	checks::testFloor3D( testCounts );
	checks::testFloor4D( testCounts );
	checks::testTrunc1F( testCounts );
	checks::testTrunc2F( testCounts );
	checks::testTrunc3F( testCounts );
	checks::testTrunc4F( testCounts );
	checks::testTrunc1D( testCounts );
	checks::testTrunc2D( testCounts );
	checks::testTrunc3D( testCounts );
	checks::testTrunc4D( testCounts );
	checks::testRound1F( testCounts );
	checks::testRound2F( testCounts );
	checks::testRound3F( testCounts );
	checks::testRound4F( testCounts );
	checks::testRound1D( testCounts );
	checks::testRound2D( testCounts );
	checks::testRound3D( testCounts );
	checks::testRound4D( testCounts );
	checks::testRoundEven1F( testCounts );
	checks::testRoundEven2F( testCounts );
	checks::testRoundEven3F( testCounts );
	checks::testRoundEven4F( testCounts );
	checks::testRoundEven1D( testCounts );
	checks::testRoundEven2D( testCounts );
	checks::testRoundEven3D( testCounts );
	checks::testRoundEven4D( testCounts );
	checks::testCeil1F( testCounts );
	checks::testCeil2F( testCounts );
	checks::testCeil3F( testCounts );
	checks::testCeil4F( testCounts );
	checks::testCeil1D( testCounts );
	checks::testCeil2D( testCounts );
	checks::testCeil3D( testCounts );
	checks::testCeil4D( testCounts );
	checks::testFract1F( testCounts );
	checks::testFract2F( testCounts );
	checks::testFract3F( testCounts );
	checks::testFract4F( testCounts );
	checks::testFract1D( testCounts );
	checks::testFract2D( testCounts );
	checks::testFract3D( testCounts );
	checks::testFract4D( testCounts );
	checks::testMod1F( testCounts );
	checks::testMod2F( testCounts );
	checks::testMod3F( testCounts );
	checks::testMod4F( testCounts );
	checks::testMod1D( testCounts );
	checks::testMod2D( testCounts );
	checks::testMod3D( testCounts );
	checks::testMod4D( testCounts );
	checks::testModf1F( testCounts );
	checks::testModf2F( testCounts );
	checks::testModf3F( testCounts );
	checks::testModf4F( testCounts );
	checks::testModf1D( testCounts );
	checks::testModf2D( testCounts );
	checks::testModf3D( testCounts );
	checks::testModf4D( testCounts );
	checks::testMin1F( testCounts );
	checks::testMin2F( testCounts );
	checks::testMin3F( testCounts );
	checks::testMin4F( testCounts );
	checks::testMin1D( testCounts );
	checks::testMin2D( testCounts );
	checks::testMin3D( testCounts );
	checks::testMin4D( testCounts );
	checks::testMin1I( testCounts );
	checks::testMin2I( testCounts );
	checks::testMin3I( testCounts );
	checks::testMin4I( testCounts );
	checks::testMin1U( testCounts );
	checks::testMin2U( testCounts );
	checks::testMin3U( testCounts );
	checks::testMin4U( testCounts );
	checks::testMax1F( testCounts );
	checks::testMax2F( testCounts );
	checks::testMax3F( testCounts );
	checks::testMax4F( testCounts );
	checks::testMax1D( testCounts );
	checks::testMax2D( testCounts );
	checks::testMax3D( testCounts );
	checks::testMax4D( testCounts );
	checks::testMax1I( testCounts );
	checks::testMax2I( testCounts );
	checks::testMax3I( testCounts );
	checks::testMax4I( testCounts );
	checks::testMax1U( testCounts );
	checks::testMax2U( testCounts );
	checks::testMax3U( testCounts );
	checks::testMax4U( testCounts );
	checks::testClamp1F( testCounts );
	checks::testClamp2F( testCounts );
	checks::testClamp3F( testCounts );
	checks::testClamp4F( testCounts );
	checks::testClamp1D( testCounts );
	checks::testClamp2D( testCounts );
	checks::testClamp3D( testCounts );
	checks::testClamp4D( testCounts );
	checks::testClamp1I( testCounts );
	checks::testClamp2I( testCounts );
	checks::testClamp3I( testCounts );
	checks::testClamp4I( testCounts );
	checks::testClamp1U( testCounts );
	checks::testClamp2U( testCounts );
	checks::testClamp3U( testCounts );
	checks::testClamp4U( testCounts );
	checks::testMix1F( testCounts );
	checks::testMix2F( testCounts );
	checks::testMix3F( testCounts );
	checks::testMix4F( testCounts );
	checks::testMix1D( testCounts );
	checks::testMix2D( testCounts );
	checks::testMix3D( testCounts );
	checks::testMix4D( testCounts );
	checks::testStep1F( testCounts );
	checks::testStep2F( testCounts );
	checks::testStep3F( testCounts );
	checks::testStep4F( testCounts );
	checks::testStep1D( testCounts );
	checks::testStep2D( testCounts );
	checks::testStep3D( testCounts );
	checks::testStep4D( testCounts );
	checks::testSmoothStep1F( testCounts );
	checks::testSmoothStep2F( testCounts );
	checks::testSmoothStep3F( testCounts );
	checks::testSmoothStep4F( testCounts );
	checks::testSmoothStep1D( testCounts );
	checks::testSmoothStep2D( testCounts );
	checks::testSmoothStep3D( testCounts );
	checks::testSmoothStep4D( testCounts );
	checks::testIsnan1F( testCounts );
	checks::testIsnan2F( testCounts );
	checks::testIsnan3F( testCounts );
	checks::testIsnan4F( testCounts );
	checks::testIsnan1D( testCounts );
	checks::testIsnan2D( testCounts );
	checks::testIsnan3D( testCounts );
	checks::testIsnan4D( testCounts );
	checks::testIsinf1F( testCounts );
	checks::testIsinf2F( testCounts );
	checks::testIsinf3F( testCounts );
	checks::testIsinf4F( testCounts );
	checks::testIsinf1D( testCounts );
	checks::testIsinf2D( testCounts );
	checks::testIsinf3D( testCounts );
	checks::testIsinf4D( testCounts );
	checks::testFloatBitsToInt1( testCounts );
	checks::testFloatBitsToInt2( testCounts );
	checks::testFloatBitsToInt3( testCounts );
	checks::testFloatBitsToInt4( testCounts );
	checks::testFloatBitsToUInt1( testCounts );
	checks::testFloatBitsToUInt2( testCounts );
	checks::testFloatBitsToUInt3( testCounts );
	checks::testFloatBitsToUInt4( testCounts );
	checks::testIntBitsToFloat1( testCounts );
	checks::testIntBitsToFloat2( testCounts );
	checks::testIntBitsToFloat3( testCounts );
	checks::testIntBitsToFloat4( testCounts );
	checks::testUintBitsToFloat1( testCounts );
	checks::testUintBitsToFloat2( testCounts );
	checks::testUintBitsToFloat3( testCounts );
	checks::testUintBitsToFloat4( testCounts );
	checks::testFma1F( testCounts );
	checks::testFma2F( testCounts );
	checks::testFma3F( testCounts );
	checks::testFma4F( testCounts );
	checks::testFma1D( testCounts );
	checks::testFma2D( testCounts );
	checks::testFma3D( testCounts );
	checks::testFma4D( testCounts );
	checks::testFrexp1F( testCounts );
	checks::testFrexp2F( testCounts );
	checks::testFrexp3F( testCounts );
	checks::testFrexp4F( testCounts );
	checks::testFrexp1D( testCounts );
	checks::testFrexp2D( testCounts );
	checks::testFrexp3D( testCounts );
	checks::testFrexp4D( testCounts );
	checks::testLdexp1F( testCounts );
	checks::testLdexp2F( testCounts );
	checks::testLdexp3F( testCounts );
	checks::testLdexp4F( testCounts );
	checks::testLdexp1D( testCounts );
	checks::testLdexp2D( testCounts );
	checks::testLdexp3D( testCounts );
	checks::testLdexp4D( testCounts );
	checks::testPackDouble2x32( testCounts );
	checks::testPackHalf2x16( testCounts );
	checks::testPackSnorm2x16( testCounts );
	checks::testPackSnorm4x8( testCounts );
	checks::testPackUnorm2x16( testCounts );
	checks::testPackUnorm4x8( testCounts );
	checks::testUnpackDouble2x32( testCounts );
	checks::testUnpackHalf2x16( testCounts );
	checks::testUnpackSnorm2x16( testCounts );
	checks::testUnpackSnorm4x8( testCounts );
	checks::testUnpackUnorm2x16( testCounts );
	checks::testUnpackUnorm4x8( testCounts );
	checks::testLength1F( testCounts );
	checks::testLength2F( testCounts );
	checks::testLength3F( testCounts );
	checks::testLength4F( testCounts );
	checks::testLength1D( testCounts );
	checks::testLength2D( testCounts );
	checks::testLength3D( testCounts );
	checks::testLength4D( testCounts );
	checks::testDistance1F( testCounts );
	checks::testDistance2F( testCounts );
	checks::testDistance3F( testCounts );
	checks::testDistance4F( testCounts );
	checks::testDistance1D( testCounts );
	checks::testDistance2D( testCounts );
	checks::testDistance3D( testCounts );
	checks::testDistance4D( testCounts );
	checks::testDot1F( testCounts );
	checks::testDot2F( testCounts );
	checks::testDot3F( testCounts );
	checks::testDot4F( testCounts );
	checks::testDot1D( testCounts );
	checks::testDot2D( testCounts );
	checks::testDot3D( testCounts );
	checks::testDot4D( testCounts );
	checks::testCrossF( testCounts );
	checks::testCrossD( testCounts );
	checks::testNormalize1F( testCounts );
	checks::testNormalize2F( testCounts );
	checks::testNormalize3F( testCounts );
	checks::testNormalize4F( testCounts );
	checks::testNormalize1D( testCounts );
	checks::testNormalize2D( testCounts );
	checks::testNormalize3D( testCounts );
	checks::testNormalize4D( testCounts );
	checks::testFaceForward1F( testCounts );
	checks::testFaceForward2F( testCounts );
	checks::testFaceForward3F( testCounts );
	checks::testFaceForward4F( testCounts );
	checks::testFaceForward1D( testCounts );
	checks::testFaceForward2D( testCounts );
	checks::testFaceForward3D( testCounts );
	checks::testFaceForward4D( testCounts );
	checks::testReflect1F( testCounts );
	checks::testReflect2F( testCounts );
	checks::testReflect3F( testCounts );
	checks::testReflect4F( testCounts );
	checks::testReflect1D( testCounts );
	checks::testReflect2D( testCounts );
	checks::testReflect3D( testCounts );
	checks::testReflect4D( testCounts );
	checks::testRefract1F( testCounts );
	checks::testRefract2F( testCounts );
	checks::testRefract3F( testCounts );
	checks::testRefract4F( testCounts );
	checks::testRefract1D( testCounts );
	checks::testRefract2D( testCounts );
	checks::testRefract3D( testCounts );
	checks::testRefract4D( testCounts );
	checks::testMatrixCompMult2x2F( testCounts );
	checks::testMatrixCompMult2x3F( testCounts );
	checks::testMatrixCompMult2x4F( testCounts );
	checks::testMatrixCompMult3x2F( testCounts );
	checks::testMatrixCompMult3x3F( testCounts );
	checks::testMatrixCompMult3x4F( testCounts );
	checks::testMatrixCompMult4x2F( testCounts );
	checks::testMatrixCompMult4x3F( testCounts );
	checks::testMatrixCompMult4x4F( testCounts );
	checks::testMatrixCompMult2x2D( testCounts );
	checks::testMatrixCompMult2x3D( testCounts );
	checks::testMatrixCompMult2x4D( testCounts );
	checks::testMatrixCompMult3x2D( testCounts );
	checks::testMatrixCompMult3x3D( testCounts );
	checks::testMatrixCompMult3x4D( testCounts );
	checks::testMatrixCompMult4x2D( testCounts );
	checks::testMatrixCompMult4x3D( testCounts );
	checks::testMatrixCompMult4x4D( testCounts );
	checks::testOuterProduct2x2F( testCounts );
	checks::testOuterProduct3x3F( testCounts );
	checks::testOuterProduct4x4F( testCounts );
	checks::testOuterProduct3x2F( testCounts );
	checks::testOuterProduct2x3F( testCounts );
	checks::testOuterProduct4x2F( testCounts );
	checks::testOuterProduct2x4F( testCounts );
	checks::testOuterProduct4x3F( testCounts );
	checks::testOuterProduct3x4F( testCounts );
	checks::testOuterProduct2x2D( testCounts );
	checks::testOuterProduct3x3D( testCounts );
	checks::testOuterProduct4x4D( testCounts );
	checks::testOuterProduct3x2D( testCounts );
	checks::testOuterProduct2x3D( testCounts );
	checks::testOuterProduct4x2D( testCounts );
	checks::testOuterProduct2x4D( testCounts );
	checks::testOuterProduct4x3D( testCounts );
	checks::testOuterProduct3x4D( testCounts );
	checks::testTranspose2x2F( testCounts );
	checks::testTranspose2x3F( testCounts );
	checks::testTranspose2x4F( testCounts );
	checks::testTranspose3x2F( testCounts );
	checks::testTranspose3x3F( testCounts );
	checks::testTranspose3x4F( testCounts );
	checks::testTranspose4x2F( testCounts );
	checks::testTranspose4x3F( testCounts );
	checks::testTranspose4x4F( testCounts );
	checks::testTranspose2x2D( testCounts );
	checks::testTranspose2x3D( testCounts );
	checks::testTranspose2x4D( testCounts );
	checks::testTranspose3x2D( testCounts );
	checks::testTranspose3x3D( testCounts );
	checks::testTranspose3x4D( testCounts );
	checks::testTranspose4x2D( testCounts );
	checks::testTranspose4x3D( testCounts );
	checks::testTranspose4x4D( testCounts );
	checks::testDeterminant2x2F( testCounts );
	checks::testDeterminant3x3F( testCounts );
	checks::testDeterminant4x4F( testCounts );
	checks::testDeterminant2x2D( testCounts );
	checks::testDeterminant3x3D( testCounts );
	checks::testDeterminant4x4D( testCounts );
	checks::testInverse2x2F( testCounts );
	checks::testInverse3x3F( testCounts );
	checks::testInverse4x4F( testCounts );
	checks::testInverse2x2D( testCounts );
	checks::testInverse3x3D( testCounts );
	checks::testInverse4x4D( testCounts );
	checks::testLessThan2F( testCounts );
	checks::testLessThan3F( testCounts );
	checks::testLessThan4F( testCounts );
	checks::testLessThan2D( testCounts );
	checks::testLessThan3D( testCounts );
	checks::testLessThan4D( testCounts );
	checks::testLessThan2I( testCounts );
	checks::testLessThan3I( testCounts );
	checks::testLessThan4I( testCounts );
	checks::testLessThan2U( testCounts );
	checks::testLessThan3U( testCounts );
	checks::testLessThan4U( testCounts );
	checks::testLessThanEqual2F( testCounts );
	checks::testLessThanEqual3F( testCounts );
	checks::testLessThanEqual4F( testCounts );
	checks::testLessThanEqual2D( testCounts );
	checks::testLessThanEqual3D( testCounts );
	checks::testLessThanEqual4D( testCounts );
	checks::testLessThanEqual2I( testCounts );
	checks::testLessThanEqual3I( testCounts );
	checks::testLessThanEqual4I( testCounts );
	checks::testLessThanEqual2U( testCounts );
	checks::testLessThanEqual3U( testCounts );
	checks::testLessThanEqual4U( testCounts );
	checks::testGreaterThan2F( testCounts );
	checks::testGreaterThan3F( testCounts );
	checks::testGreaterThan4F( testCounts );
	checks::testGreaterThan2D( testCounts );
	checks::testGreaterThan3D( testCounts );
	checks::testGreaterThan4D( testCounts );
	checks::testGreaterThan2I( testCounts );
	checks::testGreaterThan3I( testCounts );
	checks::testGreaterThan4I( testCounts );
	checks::testGreaterThan2U( testCounts );
	checks::testGreaterThan3U( testCounts );
	checks::testGreaterThan4U( testCounts );
	checks::testGreaterThanEqual2F( testCounts );
	checks::testGreaterThanEqual3F( testCounts );
	checks::testGreaterThanEqual4F( testCounts );
	checks::testGreaterThanEqual2D( testCounts );
	checks::testGreaterThanEqual3D( testCounts );
	checks::testGreaterThanEqual4D( testCounts );
	checks::testGreaterThanEqual2I( testCounts );
	checks::testGreaterThanEqual3I( testCounts );
	checks::testGreaterThanEqual4I( testCounts );
	checks::testGreaterThanEqual2U( testCounts );
	checks::testGreaterThanEqual3U( testCounts );
	checks::testGreaterThanEqual4U( testCounts );
	checks::testEqual2F( testCounts );
	checks::testEqual3F( testCounts );
	checks::testEqual4F( testCounts );
	checks::testEqual2D( testCounts );
	checks::testEqual3D( testCounts );
	checks::testEqual4D( testCounts );
	checks::testEqual2I( testCounts );
	checks::testEqual3I( testCounts );
	checks::testEqual4I( testCounts );
	checks::testEqual2U( testCounts );
	checks::testEqual3U( testCounts );
	checks::testEqual4U( testCounts );
	checks::testNotEqual2F( testCounts );
	checks::testNotEqual3F( testCounts );
	checks::testNotEqual4F( testCounts );
	checks::testNotEqual2D( testCounts );
	checks::testNotEqual3D( testCounts );
	checks::testNotEqual4D( testCounts );
	checks::testNotEqual2I( testCounts );
	checks::testNotEqual3I( testCounts );
	checks::testNotEqual4I( testCounts );
	checks::testNotEqual2U( testCounts );
	checks::testNotEqual3U( testCounts );
	checks::testNotEqual4U( testCounts );
	checks::testAll2( testCounts );
	checks::testAll3( testCounts );
	checks::testAll4( testCounts );
	checks::testAny2( testCounts );
	checks::testAny3( testCounts );
	checks::testAny4( testCounts );
	checks::testNot2( testCounts );
	checks::testNot3( testCounts );
	checks::testNot4( testCounts );
	checks::testUaddCarry1( testCounts );
	checks::testUaddCarry2( testCounts );
	checks::testUaddCarry3( testCounts );
	checks::testUaddCarry4( testCounts );
	checks::testUsubBorrow1( testCounts );
	checks::testUsubBorrow2( testCounts );
	checks::testUsubBorrow3( testCounts );
	checks::testUsubBorrow4( testCounts );
	checks::testUmulExtended1( testCounts );
	checks::testUmulExtended2( testCounts );
	checks::testUmulExtended3( testCounts );
	checks::testUmulExtended4( testCounts );
	checks::testImulExtended1( testCounts );
	checks::testImulExtended2( testCounts );
	checks::testImulExtended3( testCounts );
	checks::testImulExtended4( testCounts );
	checks::testBitfieldExtract1I( testCounts );
	checks::testBitfieldExtract2I( testCounts );
	checks::testBitfieldExtract3I( testCounts );
	checks::testBitfieldExtract4I( testCounts );
	checks::testBitfieldExtract1U( testCounts );
	checks::testBitfieldExtract2U( testCounts );
	checks::testBitfieldExtract3U( testCounts );
	checks::testBitfieldExtract4U( testCounts );
	checks::testBitfieldInsert1I( testCounts );
	checks::testBitfieldInsert2I( testCounts );
	checks::testBitfieldInsert3I( testCounts );
	checks::testBitfieldInsert4I( testCounts );
	checks::testBitfieldInsert1U( testCounts );
	checks::testBitfieldInsert2U( testCounts );
	checks::testBitfieldInsert3U( testCounts );
	checks::testBitfieldInsert4U( testCounts );
	checks::testBitfieldReverse1I( testCounts );
	checks::testBitfieldReverse2I( testCounts );
	checks::testBitfieldReverse3I( testCounts );
	checks::testBitfieldReverse4I( testCounts );
	checks::testBitfieldReverse1U( testCounts );
	checks::testBitfieldReverse2U( testCounts );
	checks::testBitfieldReverse3U( testCounts );
	checks::testBitfieldReverse4U( testCounts );
	checks::testBitCount1I( testCounts );
	checks::testBitCount2I( testCounts );
	checks::testBitCount3I( testCounts );
	checks::testBitCount4I( testCounts );
	checks::testBitCount1U( testCounts );
	checks::testBitCount2U( testCounts );
	checks::testBitCount3U( testCounts );
	checks::testBitCount4U( testCounts );
	checks::testFindLSB1I( testCounts );
	checks::testFindLSB2I( testCounts );
	checks::testFindLSB3I( testCounts );
	checks::testFindLSB4I( testCounts );
	checks::testFindLSB1U( testCounts );
	checks::testFindLSB2U( testCounts );
	checks::testFindLSB3U( testCounts );
	checks::testFindLSB4U( testCounts );
	checks::testFindMSB1I( testCounts );
	checks::testFindMSB2I( testCounts );
	checks::testFindMSB3I( testCounts );
	checks::testFindMSB4I( testCounts );
	checks::testFindMSB1U( testCounts );
	checks::testFindMSB2U( testCounts );
	checks::testFindMSB3U( testCounts );
	checks::testFindMSB4U( testCounts );
	checks::testAtomicAddI( testCounts );
	checks::testAtomicAddU( testCounts );
	checks::testAtomicAddF( testCounts );
	checks::testAtomicAdd2H( testCounts );
	checks::testAtomicAdd4H( testCounts );
	checks::testAtomicMinI( testCounts );
	checks::testAtomicMinU( testCounts );
	checks::testAtomicMaxI( testCounts );
	checks::testAtomicMaxU( testCounts );
	checks::testAtomicAndI( testCounts );
	checks::testAtomicAndU( testCounts );
	checks::testAtomicOrI( testCounts );
	checks::testAtomicOrU( testCounts );
	checks::testAtomicXorI( testCounts );
	checks::testAtomicXorU( testCounts );
	checks::testAtomicExchangeI( testCounts );
	checks::testAtomicExchangeU( testCounts );
	checks::testAtomicExchangeF( testCounts );
	checks::testAtomicExchange2H( testCounts );
	checks::testAtomicExchange4H( testCounts );
	checks::testAtomicCompSwapI( testCounts );
	checks::testAtomicCompSwapU( testCounts );
	checks::testDFdx1( testCounts );
	checks::testDFdx2( testCounts );
	checks::testDFdx3( testCounts );
	checks::testDFdx4( testCounts );
	checks::testDFdxCoarse1( testCounts );
	checks::testDFdxCoarse2( testCounts );
	checks::testDFdxCoarse3( testCounts );
	checks::testDFdxCoarse4( testCounts );
	checks::testDFdxFine1( testCounts );
	checks::testDFdxFine2( testCounts );
	checks::testDFdxFine3( testCounts );
	checks::testDFdxFine4( testCounts );
	checks::testDFdy1( testCounts );
	checks::testDFdy2( testCounts );
	checks::testDFdy3( testCounts );
	checks::testDFdy4( testCounts );
	checks::testDFdyCoarse1( testCounts );
	checks::testDFdyCoarse2( testCounts );
	checks::testDFdyCoarse3( testCounts );
	checks::testDFdyCoarse4( testCounts );
	checks::testDFdyFine1( testCounts );
	checks::testDFdyFine2( testCounts );
	checks::testDFdyFine3( testCounts );
	checks::testDFdyFine4( testCounts );
	checks::testFwidth1( testCounts );
	checks::testFwidth2( testCounts );
	checks::testFwidth3( testCounts );
	checks::testFwidth4( testCounts );
	checks::testInterpolateAtCentroid1( testCounts );
	checks::testInterpolateAtCentroid2( testCounts );
	checks::testInterpolateAtCentroid3( testCounts );
	checks::testInterpolateAtCentroid4( testCounts );
	checks::testInterpolateAtSample1( testCounts );
	checks::testInterpolateAtSample2( testCounts );
	checks::testInterpolateAtSample3( testCounts );
	checks::testInterpolateAtSample4( testCounts );
	checks::testInterpolateAtOffset1( testCounts );
	checks::testInterpolateAtOffset2( testCounts );
	checks::testInterpolateAtOffset3( testCounts );
	checks::testInterpolateAtOffset4( testCounts );
	checks::testEmitStreamVertex( testCounts );
	checks::testEndStreamPrimitive( testCounts );
	checks::testEmitVertex( testCounts );
	checks::testEndPrimitive( testCounts );
	checks::testHelperInvocation( testCounts );
	checks::testTraceRay( testCounts );
	checks::testReportIntersection( testCounts );
	checks::testExecuteCallable( testCounts );
	checks::testSetMeshOutputCountsNV( testCounts );
	checks::testDispatchMeshNV( testCounts );
	checks::testWritePackedPrimitiveIndices4x8NV( testCounts );
	checks::testSetMeshOutputCounts( testCounts );
	checks::testSubgroupElect( testCounts );
	checks::testSubgroupAll( testCounts );
	checks::testSubgroupAny( testCounts );
	checks::testSubgroupAllEqual1F( testCounts );
	checks::testSubgroupAllEqual2F( testCounts );
	checks::testSubgroupAllEqual3F( testCounts );
	checks::testSubgroupAllEqual4F( testCounts );
	checks::testSubgroupAllEqual1I( testCounts );
	checks::testSubgroupAllEqual2I( testCounts );
	checks::testSubgroupAllEqual3I( testCounts );
	checks::testSubgroupAllEqual4I( testCounts );
	checks::testSubgroupAllEqual1U( testCounts );
	checks::testSubgroupAllEqual2U( testCounts );
	checks::testSubgroupAllEqual3U( testCounts );
	checks::testSubgroupAllEqual4U( testCounts );
	checks::testSubgroupAllEqual1B( testCounts );
	checks::testSubgroupAllEqual2B( testCounts );
	checks::testSubgroupAllEqual3B( testCounts );
	checks::testSubgroupAllEqual4B( testCounts );
	checks::testSubgroupAllEqual1D( testCounts );
	checks::testSubgroupAllEqual2D( testCounts );
	checks::testSubgroupAllEqual3D( testCounts );
	checks::testSubgroupAllEqual4D( testCounts );
	checks::testSubgroupBroadcast1F( testCounts );
	checks::testSubgroupBroadcast2F( testCounts );
	checks::testSubgroupBroadcast3F( testCounts );
	checks::testSubgroupBroadcast4F( testCounts );
	checks::testSubgroupBroadcast1I( testCounts );
	checks::testSubgroupBroadcast2I( testCounts );
	checks::testSubgroupBroadcast3I( testCounts );
	checks::testSubgroupBroadcast4I( testCounts );
	checks::testSubgroupBroadcast1U( testCounts );
	checks::testSubgroupBroadcast2U( testCounts );
	checks::testSubgroupBroadcast3U( testCounts );
	checks::testSubgroupBroadcast4U( testCounts );
	checks::testSubgroupBroadcast1B( testCounts );
	checks::testSubgroupBroadcast2B( testCounts );
	checks::testSubgroupBroadcast3B( testCounts );
	checks::testSubgroupBroadcast4B( testCounts );
	checks::testSubgroupBroadcast1D( testCounts );
	checks::testSubgroupBroadcast2D( testCounts );
	checks::testSubgroupBroadcast3D( testCounts );
	checks::testSubgroupBroadcast4D( testCounts );
	checks::testSubgroupBroadcastFirst1F( testCounts );
	checks::testSubgroupBroadcastFirst2F( testCounts );
	checks::testSubgroupBroadcastFirst3F( testCounts );
	checks::testSubgroupBroadcastFirst4F( testCounts );
	checks::testSubgroupBroadcastFirst1I( testCounts );
	checks::testSubgroupBroadcastFirst2I( testCounts );
	checks::testSubgroupBroadcastFirst3I( testCounts );
	checks::testSubgroupBroadcastFirst4I( testCounts );
	checks::testSubgroupBroadcastFirst1U( testCounts );
	checks::testSubgroupBroadcastFirst2U( testCounts );
	checks::testSubgroupBroadcastFirst3U( testCounts );
	checks::testSubgroupBroadcastFirst4U( testCounts );
	checks::testSubgroupBroadcastFirst1B( testCounts );
	checks::testSubgroupBroadcastFirst2B( testCounts );
	checks::testSubgroupBroadcastFirst3B( testCounts );
	checks::testSubgroupBroadcastFirst4B( testCounts );
	checks::testSubgroupBroadcastFirst1D( testCounts );
	checks::testSubgroupBroadcastFirst2D( testCounts );
	checks::testSubgroupBroadcastFirst3D( testCounts );
	checks::testSubgroupBroadcastFirst4D( testCounts );
	checks::testSubgroupBallot( testCounts );
	checks::testSubgroupInverseBallot( testCounts );
	checks::testSubgroupBallotBitExtract( testCounts );
	checks::testSubgroupBallotBitCount( testCounts );
	checks::testSubgroupBallotInclusiveBitCount( testCounts );
	checks::testSubgroupBallotExclusiveBitCount( testCounts );
	checks::testSubgroupBallotFindLSB( testCounts );
	checks::testSubgroupBallotFindMSB( testCounts );
	checks::testSubgroupShuffle1F( testCounts );
	checks::testSubgroupShuffle2F( testCounts );
	checks::testSubgroupShuffle3F( testCounts );
	checks::testSubgroupShuffle4F( testCounts );
	checks::testSubgroupShuffle1I( testCounts );
	checks::testSubgroupShuffle2I( testCounts );
	checks::testSubgroupShuffle3I( testCounts );
	checks::testSubgroupShuffle4I( testCounts );
	checks::testSubgroupShuffle1U( testCounts );
	checks::testSubgroupShuffle2U( testCounts );
	checks::testSubgroupShuffle3U( testCounts );
	checks::testSubgroupShuffle4U( testCounts );
	checks::testSubgroupShuffle1B( testCounts );
	checks::testSubgroupShuffle2B( testCounts );
	checks::testSubgroupShuffle3B( testCounts );
	checks::testSubgroupShuffle4B( testCounts );
	checks::testSubgroupShuffle1D( testCounts );
	checks::testSubgroupShuffle2D( testCounts );
	checks::testSubgroupShuffle3D( testCounts );
	checks::testSubgroupShuffle4D( testCounts );
	checks::testSubgroupShuffleXor1F( testCounts );
	checks::testSubgroupShuffleXor2F( testCounts );
	checks::testSubgroupShuffleXor3F( testCounts );
	checks::testSubgroupShuffleXor4F( testCounts );
	checks::testSubgroupShuffleXor1I( testCounts );
	checks::testSubgroupShuffleXor2I( testCounts );
	checks::testSubgroupShuffleXor3I( testCounts );
	checks::testSubgroupShuffleXor4I( testCounts );
	checks::testSubgroupShuffleXor1U( testCounts );
	checks::testSubgroupShuffleXor2U( testCounts );
	checks::testSubgroupShuffleXor3U( testCounts );
	checks::testSubgroupShuffleXor4U( testCounts );
	checks::testSubgroupShuffleXor1B( testCounts );
	checks::testSubgroupShuffleXor2B( testCounts );
	checks::testSubgroupShuffleXor3B( testCounts );
	checks::testSubgroupShuffleXor4B( testCounts );
	checks::testSubgroupShuffleXor1D( testCounts );
	checks::testSubgroupShuffleXor2D( testCounts );
	checks::testSubgroupShuffleXor3D( testCounts );
	checks::testSubgroupShuffleXor4D( testCounts );
	checks::testSubgroupShuffleUp1F( testCounts );
	checks::testSubgroupShuffleUp2F( testCounts );
	checks::testSubgroupShuffleUp3F( testCounts );
	checks::testSubgroupShuffleUp4F( testCounts );
	checks::testSubgroupShuffleUp1I( testCounts );
	checks::testSubgroupShuffleUp2I( testCounts );
	checks::testSubgroupShuffleUp3I( testCounts );
	checks::testSubgroupShuffleUp4I( testCounts );
	checks::testSubgroupShuffleUp1U( testCounts );
	checks::testSubgroupShuffleUp2U( testCounts );
	checks::testSubgroupShuffleUp3U( testCounts );
	checks::testSubgroupShuffleUp4U( testCounts );
	checks::testSubgroupShuffleUp1B( testCounts );
	checks::testSubgroupShuffleUp2B( testCounts );
	checks::testSubgroupShuffleUp3B( testCounts );
	checks::testSubgroupShuffleUp4B( testCounts );
	checks::testSubgroupShuffleUp1D( testCounts );
	checks::testSubgroupShuffleUp2D( testCounts );
	checks::testSubgroupShuffleUp3D( testCounts );
	checks::testSubgroupShuffleUp4D( testCounts );
	checks::testSubgroupShuffleDown1F( testCounts );
	checks::testSubgroupShuffleDown2F( testCounts );
	checks::testSubgroupShuffleDown3F( testCounts );
	checks::testSubgroupShuffleDown4F( testCounts );
	checks::testSubgroupShuffleDown1I( testCounts );
	checks::testSubgroupShuffleDown2I( testCounts );
	checks::testSubgroupShuffleDown3I( testCounts );
	checks::testSubgroupShuffleDown4I( testCounts );
	checks::testSubgroupShuffleDown1U( testCounts );
	checks::testSubgroupShuffleDown2U( testCounts );
	checks::testSubgroupShuffleDown3U( testCounts );
	checks::testSubgroupShuffleDown4U( testCounts );
	checks::testSubgroupShuffleDown1B( testCounts );
	checks::testSubgroupShuffleDown2B( testCounts );
	checks::testSubgroupShuffleDown3B( testCounts );
	checks::testSubgroupShuffleDown4B( testCounts );
	checks::testSubgroupShuffleDown1D( testCounts );
	checks::testSubgroupShuffleDown2D( testCounts );
	checks::testSubgroupShuffleDown3D( testCounts );
	checks::testSubgroupShuffleDown4D( testCounts );
	checks::testSubgroupAdd1F( testCounts );
	checks::testSubgroupAdd2F( testCounts );
	checks::testSubgroupAdd3F( testCounts );
	checks::testSubgroupAdd4F( testCounts );
	checks::testSubgroupAdd1I( testCounts );
	checks::testSubgroupAdd2I( testCounts );
	checks::testSubgroupAdd3I( testCounts );
	checks::testSubgroupAdd4I( testCounts );
	checks::testSubgroupAdd1U( testCounts );
	checks::testSubgroupAdd2U( testCounts );
	checks::testSubgroupAdd3U( testCounts );
	checks::testSubgroupAdd4U( testCounts );
	checks::testSubgroupAdd1D( testCounts );
	checks::testSubgroupAdd2D( testCounts );
	checks::testSubgroupAdd3D( testCounts );
	checks::testSubgroupAdd4D( testCounts );
	checks::testSubgroupMul1F( testCounts );
	checks::testSubgroupMul2F( testCounts );
	checks::testSubgroupMul3F( testCounts );
	checks::testSubgroupMul4F( testCounts );
	checks::testSubgroupMul1I( testCounts );
	checks::testSubgroupMul2I( testCounts );
	checks::testSubgroupMul3I( testCounts );
	checks::testSubgroupMul4I( testCounts );
	checks::testSubgroupMul1U( testCounts );
	checks::testSubgroupMul2U( testCounts );
	checks::testSubgroupMul3U( testCounts );
	checks::testSubgroupMul4U( testCounts );
	checks::testSubgroupMul1D( testCounts );
	checks::testSubgroupMul2D( testCounts );
	checks::testSubgroupMul3D( testCounts );
	checks::testSubgroupMul4D( testCounts );
	checks::testSubgroupMin1F( testCounts );
	checks::testSubgroupMin2F( testCounts );
	checks::testSubgroupMin3F( testCounts );
	checks::testSubgroupMin4F( testCounts );
	checks::testSubgroupMin1I( testCounts );
	checks::testSubgroupMin2I( testCounts );
	checks::testSubgroupMin3I( testCounts );
	checks::testSubgroupMin4I( testCounts );
	checks::testSubgroupMin1U( testCounts );
	checks::testSubgroupMin2U( testCounts );
	checks::testSubgroupMin3U( testCounts );
	checks::testSubgroupMin4U( testCounts );
	checks::testSubgroupMin1D( testCounts );
	checks::testSubgroupMin2D( testCounts );
	checks::testSubgroupMin3D( testCounts );
	checks::testSubgroupMin4D( testCounts );
	checks::testSubgroupMax1F( testCounts );
	checks::testSubgroupMax2F( testCounts );
	checks::testSubgroupMax3F( testCounts );
	checks::testSubgroupMax4F( testCounts );
	checks::testSubgroupMax1I( testCounts );
	checks::testSubgroupMax2I( testCounts );
	checks::testSubgroupMax3I( testCounts );
	checks::testSubgroupMax4I( testCounts );
	checks::testSubgroupMax1U( testCounts );
	checks::testSubgroupMax2U( testCounts );
	checks::testSubgroupMax3U( testCounts );
	checks::testSubgroupMax4U( testCounts );
	checks::testSubgroupMax1D( testCounts );
	checks::testSubgroupMax2D( testCounts );
	checks::testSubgroupMax3D( testCounts );
	checks::testSubgroupMax4D( testCounts );
	checks::testSubgroupAnd1I( testCounts );
	checks::testSubgroupAnd2I( testCounts );
	checks::testSubgroupAnd3I( testCounts );
	checks::testSubgroupAnd4I( testCounts );
	checks::testSubgroupAnd1U( testCounts );
	checks::testSubgroupAnd2U( testCounts );
	checks::testSubgroupAnd3U( testCounts );
	checks::testSubgroupAnd4U( testCounts );
	checks::testSubgroupAnd1B( testCounts );
	checks::testSubgroupAnd2B( testCounts );
	checks::testSubgroupAnd3B( testCounts );
	checks::testSubgroupAnd4B( testCounts );
	checks::testSubgroupOr1I( testCounts );
	checks::testSubgroupOr2I( testCounts );
	checks::testSubgroupOr3I( testCounts );
	checks::testSubgroupOr4I( testCounts );
	checks::testSubgroupOr1U( testCounts );
	checks::testSubgroupOr2U( testCounts );
	checks::testSubgroupOr3U( testCounts );
	checks::testSubgroupOr4U( testCounts );
	checks::testSubgroupOr1B( testCounts );
	checks::testSubgroupOr2B( testCounts );
	checks::testSubgroupOr3B( testCounts );
	checks::testSubgroupOr4B( testCounts );
	checks::testSubgroupXor1I( testCounts );
	checks::testSubgroupXor2I( testCounts );
	checks::testSubgroupXor3I( testCounts );
	checks::testSubgroupXor4I( testCounts );
	checks::testSubgroupXor1U( testCounts );
	checks::testSubgroupXor2U( testCounts );
	checks::testSubgroupXor3U( testCounts );
	checks::testSubgroupXor4U( testCounts );
	checks::testSubgroupXor1B( testCounts );
	checks::testSubgroupXor2B( testCounts );
	checks::testSubgroupXor3B( testCounts );
	checks::testSubgroupXor4B( testCounts );
	checks::testSubgroupInclusiveAdd1F( testCounts );
	checks::testSubgroupInclusiveAdd2F( testCounts );
	checks::testSubgroupInclusiveAdd3F( testCounts );
	checks::testSubgroupInclusiveAdd4F( testCounts );
	checks::testSubgroupInclusiveAdd1I( testCounts );
	checks::testSubgroupInclusiveAdd2I( testCounts );
	checks::testSubgroupInclusiveAdd3I( testCounts );
	checks::testSubgroupInclusiveAdd4I( testCounts );
	checks::testSubgroupInclusiveAdd1U( testCounts );
	checks::testSubgroupInclusiveAdd2U( testCounts );
	checks::testSubgroupInclusiveAdd3U( testCounts );
	checks::testSubgroupInclusiveAdd4U( testCounts );
	checks::testSubgroupInclusiveAdd1D( testCounts );
	checks::testSubgroupInclusiveAdd2D( testCounts );
	checks::testSubgroupInclusiveAdd3D( testCounts );
	checks::testSubgroupInclusiveAdd4D( testCounts );
	checks::testSubgroupInclusiveMul1F( testCounts );
	checks::testSubgroupInclusiveMul2F( testCounts );
	checks::testSubgroupInclusiveMul3F( testCounts );
	checks::testSubgroupInclusiveMul4F( testCounts );
	checks::testSubgroupInclusiveMul1I( testCounts );
	checks::testSubgroupInclusiveMul2I( testCounts );
	checks::testSubgroupInclusiveMul3I( testCounts );
	checks::testSubgroupInclusiveMul4I( testCounts );
	checks::testSubgroupInclusiveMul1U( testCounts );
	checks::testSubgroupInclusiveMul2U( testCounts );
	checks::testSubgroupInclusiveMul3U( testCounts );
	checks::testSubgroupInclusiveMul4U( testCounts );
	checks::testSubgroupInclusiveMul1D( testCounts );
	checks::testSubgroupInclusiveMul2D( testCounts );
	checks::testSubgroupInclusiveMul3D( testCounts );
	checks::testSubgroupInclusiveMul4D( testCounts );
	checks::testSubgroupInclusiveMin1F( testCounts );
	checks::testSubgroupInclusiveMin2F( testCounts );
	checks::testSubgroupInclusiveMin3F( testCounts );
	checks::testSubgroupInclusiveMin4F( testCounts );
	checks::testSubgroupInclusiveMin1I( testCounts );
	checks::testSubgroupInclusiveMin2I( testCounts );
	checks::testSubgroupInclusiveMin3I( testCounts );
	checks::testSubgroupInclusiveMin4I( testCounts );
	checks::testSubgroupInclusiveMin1U( testCounts );
	checks::testSubgroupInclusiveMin2U( testCounts );
	checks::testSubgroupInclusiveMin3U( testCounts );
	checks::testSubgroupInclusiveMin4U( testCounts );
	checks::testSubgroupInclusiveMin1D( testCounts );
	checks::testSubgroupInclusiveMin2D( testCounts );
	checks::testSubgroupInclusiveMin3D( testCounts );
	checks::testSubgroupInclusiveMin4D( testCounts );
	checks::testSubgroupInclusiveMax1F( testCounts );
	checks::testSubgroupInclusiveMax2F( testCounts );
	checks::testSubgroupInclusiveMax3F( testCounts );
	checks::testSubgroupInclusiveMax4F( testCounts );
	checks::testSubgroupInclusiveMax1I( testCounts );
	checks::testSubgroupInclusiveMax2I( testCounts );
	checks::testSubgroupInclusiveMax3I( testCounts );
	checks::testSubgroupInclusiveMax4I( testCounts );
	checks::testSubgroupInclusiveMax1U( testCounts );
	checks::testSubgroupInclusiveMax2U( testCounts );
	checks::testSubgroupInclusiveMax3U( testCounts );
	checks::testSubgroupInclusiveMax4U( testCounts );
	checks::testSubgroupInclusiveMax1D( testCounts );
	checks::testSubgroupInclusiveMax2D( testCounts );
	checks::testSubgroupInclusiveMax3D( testCounts );
	checks::testSubgroupInclusiveMax4D( testCounts );
	checks::testSubgroupInclusiveAnd1I( testCounts );
	checks::testSubgroupInclusiveAnd2I( testCounts );
	checks::testSubgroupInclusiveAnd3I( testCounts );
	checks::testSubgroupInclusiveAnd4I( testCounts );
	checks::testSubgroupInclusiveAnd1U( testCounts );
	checks::testSubgroupInclusiveAnd2U( testCounts );
	checks::testSubgroupInclusiveAnd3U( testCounts );
	checks::testSubgroupInclusiveAnd4U( testCounts );
	checks::testSubgroupInclusiveAnd1B( testCounts );
	checks::testSubgroupInclusiveAnd2B( testCounts );
	checks::testSubgroupInclusiveAnd3B( testCounts );
	checks::testSubgroupInclusiveAnd4B( testCounts );
	checks::testSubgroupInclusiveOr1I( testCounts );
	checks::testSubgroupInclusiveOr2I( testCounts );
	checks::testSubgroupInclusiveOr3I( testCounts );
	checks::testSubgroupInclusiveOr4I( testCounts );
	checks::testSubgroupInclusiveOr1U( testCounts );
	checks::testSubgroupInclusiveOr2U( testCounts );
	checks::testSubgroupInclusiveOr3U( testCounts );
	checks::testSubgroupInclusiveOr4U( testCounts );
	checks::testSubgroupInclusiveOr1B( testCounts );
	checks::testSubgroupInclusiveOr2B( testCounts );
	checks::testSubgroupInclusiveOr3B( testCounts );
	checks::testSubgroupInclusiveOr4B( testCounts );
	checks::testSubgroupInclusiveXor1I( testCounts );
	checks::testSubgroupInclusiveXor2I( testCounts );
	checks::testSubgroupInclusiveXor3I( testCounts );
	checks::testSubgroupInclusiveXor4I( testCounts );
	checks::testSubgroupInclusiveXor1U( testCounts );
	checks::testSubgroupInclusiveXor2U( testCounts );
	checks::testSubgroupInclusiveXor3U( testCounts );
	checks::testSubgroupInclusiveXor4U( testCounts );
	checks::testSubgroupInclusiveXor1B( testCounts );
	checks::testSubgroupInclusiveXor2B( testCounts );
	checks::testSubgroupInclusiveXor3B( testCounts );
	checks::testSubgroupInclusiveXor4B( testCounts );
	checks::testSubgroupExclusiveAdd1F( testCounts );
	checks::testSubgroupExclusiveAdd2F( testCounts );
	checks::testSubgroupExclusiveAdd3F( testCounts );
	checks::testSubgroupExclusiveAdd4F( testCounts );
	checks::testSubgroupExclusiveAdd1I( testCounts );
	checks::testSubgroupExclusiveAdd2I( testCounts );
	checks::testSubgroupExclusiveAdd3I( testCounts );
	checks::testSubgroupExclusiveAdd4I( testCounts );
	checks::testSubgroupExclusiveAdd1U( testCounts );
	checks::testSubgroupExclusiveAdd2U( testCounts );
	checks::testSubgroupExclusiveAdd3U( testCounts );
	checks::testSubgroupExclusiveAdd4U( testCounts );
	checks::testSubgroupExclusiveAdd1D( testCounts );
	checks::testSubgroupExclusiveAdd2D( testCounts );
	checks::testSubgroupExclusiveAdd3D( testCounts );
	checks::testSubgroupExclusiveAdd4D( testCounts );
	checks::testSubgroupExclusiveMul1F( testCounts );
	checks::testSubgroupExclusiveMul2F( testCounts );
	checks::testSubgroupExclusiveMul3F( testCounts );
	checks::testSubgroupExclusiveMul4F( testCounts );
	checks::testSubgroupExclusiveMul1I( testCounts );
	checks::testSubgroupExclusiveMul2I( testCounts );
	checks::testSubgroupExclusiveMul3I( testCounts );
	checks::testSubgroupExclusiveMul4I( testCounts );
	checks::testSubgroupExclusiveMul1U( testCounts );
	checks::testSubgroupExclusiveMul2U( testCounts );
	checks::testSubgroupExclusiveMul3U( testCounts );
	checks::testSubgroupExclusiveMul4U( testCounts );
	checks::testSubgroupExclusiveMul1D( testCounts );
	checks::testSubgroupExclusiveMul2D( testCounts );
	checks::testSubgroupExclusiveMul3D( testCounts );
	checks::testSubgroupExclusiveMul4D( testCounts );
	checks::testSubgroupExclusiveMin1F( testCounts );
	checks::testSubgroupExclusiveMin2F( testCounts );
	checks::testSubgroupExclusiveMin3F( testCounts );
	checks::testSubgroupExclusiveMin4F( testCounts );
	checks::testSubgroupExclusiveMin1I( testCounts );
	checks::testSubgroupExclusiveMin2I( testCounts );
	checks::testSubgroupExclusiveMin3I( testCounts );
	checks::testSubgroupExclusiveMin4I( testCounts );
	checks::testSubgroupExclusiveMin1U( testCounts );
	checks::testSubgroupExclusiveMin2U( testCounts );
	checks::testSubgroupExclusiveMin3U( testCounts );
	checks::testSubgroupExclusiveMin4U( testCounts );
	checks::testSubgroupExclusiveMin1D( testCounts );
	checks::testSubgroupExclusiveMin2D( testCounts );
	checks::testSubgroupExclusiveMin3D( testCounts );
	checks::testSubgroupExclusiveMin4D( testCounts );
	checks::testSubgroupExclusiveMax1F( testCounts );
	checks::testSubgroupExclusiveMax2F( testCounts );
	checks::testSubgroupExclusiveMax3F( testCounts );
	checks::testSubgroupExclusiveMax4F( testCounts );
	checks::testSubgroupExclusiveMax1I( testCounts );
	checks::testSubgroupExclusiveMax2I( testCounts );
	checks::testSubgroupExclusiveMax3I( testCounts );
	checks::testSubgroupExclusiveMax4I( testCounts );
	checks::testSubgroupExclusiveMax1U( testCounts );
	checks::testSubgroupExclusiveMax2U( testCounts );
	checks::testSubgroupExclusiveMax3U( testCounts );
	checks::testSubgroupExclusiveMax4U( testCounts );
	checks::testSubgroupExclusiveMax1D( testCounts );
	checks::testSubgroupExclusiveMax2D( testCounts );
	checks::testSubgroupExclusiveMax3D( testCounts );
	checks::testSubgroupExclusiveMax4D( testCounts );
	checks::testSubgroupExclusiveAnd1I( testCounts );
	checks::testSubgroupExclusiveAnd2I( testCounts );
	checks::testSubgroupExclusiveAnd3I( testCounts );
	checks::testSubgroupExclusiveAnd4I( testCounts );
	checks::testSubgroupExclusiveAnd1U( testCounts );
	checks::testSubgroupExclusiveAnd2U( testCounts );
	checks::testSubgroupExclusiveAnd3U( testCounts );
	checks::testSubgroupExclusiveAnd4U( testCounts );
	checks::testSubgroupExclusiveAnd1B( testCounts );
	checks::testSubgroupExclusiveAnd2B( testCounts );
	checks::testSubgroupExclusiveAnd3B( testCounts );
	checks::testSubgroupExclusiveAnd4B( testCounts );
	checks::testSubgroupExclusiveOr1I( testCounts );
	checks::testSubgroupExclusiveOr2I( testCounts );
	checks::testSubgroupExclusiveOr3I( testCounts );
	checks::testSubgroupExclusiveOr4I( testCounts );
	checks::testSubgroupExclusiveOr1U( testCounts );
	checks::testSubgroupExclusiveOr2U( testCounts );
	checks::testSubgroupExclusiveOr3U( testCounts );
	checks::testSubgroupExclusiveOr4U( testCounts );
	checks::testSubgroupExclusiveOr1B( testCounts );
	checks::testSubgroupExclusiveOr2B( testCounts );
	checks::testSubgroupExclusiveOr3B( testCounts );
	checks::testSubgroupExclusiveOr4B( testCounts );
	checks::testSubgroupExclusiveXor1I( testCounts );
	checks::testSubgroupExclusiveXor2I( testCounts );
	checks::testSubgroupExclusiveXor3I( testCounts );
	checks::testSubgroupExclusiveXor4I( testCounts );
	checks::testSubgroupExclusiveXor1U( testCounts );
	checks::testSubgroupExclusiveXor2U( testCounts );
	checks::testSubgroupExclusiveXor3U( testCounts );
	checks::testSubgroupExclusiveXor4U( testCounts );
	checks::testSubgroupExclusiveXor1B( testCounts );
	checks::testSubgroupExclusiveXor2B( testCounts );
	checks::testSubgroupExclusiveXor3B( testCounts );
	checks::testSubgroupExclusiveXor4B( testCounts );
	checks::testSubgroupClusterAdd1F( testCounts );
	checks::testSubgroupClusterAdd2F( testCounts );
	checks::testSubgroupClusterAdd3F( testCounts );
	checks::testSubgroupClusterAdd4F( testCounts );
	checks::testSubgroupClusterAdd1I( testCounts );
	checks::testSubgroupClusterAdd2I( testCounts );
	checks::testSubgroupClusterAdd3I( testCounts );
	checks::testSubgroupClusterAdd4I( testCounts );
	checks::testSubgroupClusterAdd1U( testCounts );
	checks::testSubgroupClusterAdd2U( testCounts );
	checks::testSubgroupClusterAdd3U( testCounts );
	checks::testSubgroupClusterAdd4U( testCounts );
	checks::testSubgroupClusterAdd1D( testCounts );
	checks::testSubgroupClusterAdd2D( testCounts );
	checks::testSubgroupClusterAdd3D( testCounts );
	checks::testSubgroupClusterAdd4D( testCounts );
	checks::testSubgroupClusterMul1F( testCounts );
	checks::testSubgroupClusterMul2F( testCounts );
	checks::testSubgroupClusterMul3F( testCounts );
	checks::testSubgroupClusterMul4F( testCounts );
	checks::testSubgroupClusterMul1I( testCounts );
	checks::testSubgroupClusterMul2I( testCounts );
	checks::testSubgroupClusterMul3I( testCounts );
	checks::testSubgroupClusterMul4I( testCounts );
	checks::testSubgroupClusterMul1U( testCounts );
	checks::testSubgroupClusterMul2U( testCounts );
	checks::testSubgroupClusterMul3U( testCounts );
	checks::testSubgroupClusterMul4U( testCounts );
	checks::testSubgroupClusterMul1D( testCounts );
	checks::testSubgroupClusterMul2D( testCounts );
	checks::testSubgroupClusterMul3D( testCounts );
	checks::testSubgroupClusterMul4D( testCounts );
	checks::testSubgroupClusterMin1F( testCounts );
	checks::testSubgroupClusterMin2F( testCounts );
	checks::testSubgroupClusterMin3F( testCounts );
	checks::testSubgroupClusterMin4F( testCounts );
	checks::testSubgroupClusterMin1I( testCounts );
	checks::testSubgroupClusterMin2I( testCounts );
	checks::testSubgroupClusterMin3I( testCounts );
	checks::testSubgroupClusterMin4I( testCounts );
	checks::testSubgroupClusterMin1U( testCounts );
	checks::testSubgroupClusterMin2U( testCounts );
	checks::testSubgroupClusterMin3U( testCounts );
	checks::testSubgroupClusterMin4U( testCounts );
	checks::testSubgroupClusterMin1D( testCounts );
	checks::testSubgroupClusterMin2D( testCounts );
	checks::testSubgroupClusterMin3D( testCounts );
	checks::testSubgroupClusterMin4D( testCounts );
	checks::testSubgroupClusterMax1F( testCounts );
	checks::testSubgroupClusterMax2F( testCounts );
	checks::testSubgroupClusterMax3F( testCounts );
	checks::testSubgroupClusterMax4F( testCounts );
	checks::testSubgroupClusterMax1I( testCounts );
	checks::testSubgroupClusterMax2I( testCounts );
	checks::testSubgroupClusterMax3I( testCounts );
	checks::testSubgroupClusterMax4I( testCounts );
	checks::testSubgroupClusterMax1U( testCounts );
	checks::testSubgroupClusterMax2U( testCounts );
	checks::testSubgroupClusterMax3U( testCounts );
	checks::testSubgroupClusterMax4U( testCounts );
	checks::testSubgroupClusterMax1D( testCounts );
	checks::testSubgroupClusterMax2D( testCounts );
	checks::testSubgroupClusterMax3D( testCounts );
	checks::testSubgroupClusterMax4D( testCounts );
	checks::testSubgroupClusterAnd1I( testCounts );
	checks::testSubgroupClusterAnd2I( testCounts );
	checks::testSubgroupClusterAnd3I( testCounts );
	checks::testSubgroupClusterAnd4I( testCounts );
	checks::testSubgroupClusterAnd1U( testCounts );
	checks::testSubgroupClusterAnd2U( testCounts );
	checks::testSubgroupClusterAnd3U( testCounts );
	checks::testSubgroupClusterAnd4U( testCounts );
	checks::testSubgroupClusterAnd1B( testCounts );
	checks::testSubgroupClusterAnd2B( testCounts );
	checks::testSubgroupClusterAnd3B( testCounts );
	checks::testSubgroupClusterAnd4B( testCounts );
	checks::testSubgroupClusterOr1I( testCounts );
	checks::testSubgroupClusterOr2I( testCounts );
	checks::testSubgroupClusterOr3I( testCounts );
	checks::testSubgroupClusterOr4I( testCounts );
	checks::testSubgroupClusterOr1U( testCounts );
	checks::testSubgroupClusterOr2U( testCounts );
	checks::testSubgroupClusterOr3U( testCounts );
	checks::testSubgroupClusterOr4U( testCounts );
	checks::testSubgroupClusterOr1B( testCounts );
	checks::testSubgroupClusterOr2B( testCounts );
	checks::testSubgroupClusterOr3B( testCounts );
	checks::testSubgroupClusterOr4B( testCounts );
	checks::testSubgroupClusterXor1I( testCounts );
	checks::testSubgroupClusterXor2I( testCounts );
	checks::testSubgroupClusterXor3I( testCounts );
	checks::testSubgroupClusterXor4I( testCounts );
	checks::testSubgroupClusterXor1U( testCounts );
	checks::testSubgroupClusterXor2U( testCounts );
	checks::testSubgroupClusterXor3U( testCounts );
	checks::testSubgroupClusterXor4U( testCounts );
	checks::testSubgroupClusterXor1B( testCounts );
	checks::testSubgroupClusterXor2B( testCounts );
	checks::testSubgroupClusterXor3B( testCounts );
	checks::testSubgroupClusterXor4B( testCounts );
	checks::testSubgroupQuadBroadcast1F( testCounts );
	checks::testSubgroupQuadBroadcast2F( testCounts );
	checks::testSubgroupQuadBroadcast3F( testCounts );
	checks::testSubgroupQuadBroadcast4F( testCounts );
	checks::testSubgroupQuadBroadcast1I( testCounts );
	checks::testSubgroupQuadBroadcast2I( testCounts );
	checks::testSubgroupQuadBroadcast3I( testCounts );
	checks::testSubgroupQuadBroadcast4I( testCounts );
	checks::testSubgroupQuadBroadcast1U( testCounts );
	checks::testSubgroupQuadBroadcast2U( testCounts );
	checks::testSubgroupQuadBroadcast3U( testCounts );
	checks::testSubgroupQuadBroadcast4U( testCounts );
	checks::testSubgroupQuadBroadcast1B( testCounts );
	checks::testSubgroupQuadBroadcast2B( testCounts );
	checks::testSubgroupQuadBroadcast3B( testCounts );
	checks::testSubgroupQuadBroadcast4B( testCounts );
	checks::testSubgroupQuadBroadcast1D( testCounts );
	checks::testSubgroupQuadBroadcast2D( testCounts );
	checks::testSubgroupQuadBroadcast3D( testCounts );
	checks::testSubgroupQuadBroadcast4D( testCounts );
	checks::testSubgroupQuadSwapHorizontal1F( testCounts );
	checks::testSubgroupQuadSwapHorizontal2F( testCounts );
	checks::testSubgroupQuadSwapHorizontal3F( testCounts );
	checks::testSubgroupQuadSwapHorizontal4F( testCounts );
	checks::testSubgroupQuadSwapHorizontal1I( testCounts );
	checks::testSubgroupQuadSwapHorizontal2I( testCounts );
	checks::testSubgroupQuadSwapHorizontal3I( testCounts );
	checks::testSubgroupQuadSwapHorizontal4I( testCounts );
	checks::testSubgroupQuadSwapHorizontal1U( testCounts );
	checks::testSubgroupQuadSwapHorizontal2U( testCounts );
	checks::testSubgroupQuadSwapHorizontal3U( testCounts );
	checks::testSubgroupQuadSwapHorizontal4U( testCounts );
	checks::testSubgroupQuadSwapHorizontal1B( testCounts );
	checks::testSubgroupQuadSwapHorizontal2B( testCounts );
	checks::testSubgroupQuadSwapHorizontal3B( testCounts );
	checks::testSubgroupQuadSwapHorizontal4B( testCounts );
	checks::testSubgroupQuadSwapHorizontal1D( testCounts );
	checks::testSubgroupQuadSwapHorizontal2D( testCounts );
	checks::testSubgroupQuadSwapHorizontal3D( testCounts );
	checks::testSubgroupQuadSwapHorizontal4D( testCounts );
	checks::testSubgroupQuadSwapVertical1F( testCounts );
	checks::testSubgroupQuadSwapVertical2F( testCounts );
	checks::testSubgroupQuadSwapVertical3F( testCounts );
	checks::testSubgroupQuadSwapVertical4F( testCounts );
	checks::testSubgroupQuadSwapVertical1I( testCounts );
	checks::testSubgroupQuadSwapVertical2I( testCounts );
	checks::testSubgroupQuadSwapVertical3I( testCounts );
	checks::testSubgroupQuadSwapVertical4I( testCounts );
	checks::testSubgroupQuadSwapVertical1U( testCounts );
	checks::testSubgroupQuadSwapVertical2U( testCounts );
	checks::testSubgroupQuadSwapVertical3U( testCounts );
	checks::testSubgroupQuadSwapVertical4U( testCounts );
	checks::testSubgroupQuadSwapVertical1B( testCounts );
	checks::testSubgroupQuadSwapVertical2B( testCounts );
	checks::testSubgroupQuadSwapVertical3B( testCounts );
	checks::testSubgroupQuadSwapVertical4B( testCounts );
	checks::testSubgroupQuadSwapVertical1D( testCounts );
	checks::testSubgroupQuadSwapVertical2D( testCounts );
	checks::testSubgroupQuadSwapVertical3D( testCounts );
	checks::testSubgroupQuadSwapVertical4D( testCounts );
	checks::testSubgroupQuadSwapDiagonal1F( testCounts );
	checks::testSubgroupQuadSwapDiagonal2F( testCounts );
	checks::testSubgroupQuadSwapDiagonal3F( testCounts );
	checks::testSubgroupQuadSwapDiagonal4F( testCounts );
	checks::testSubgroupQuadSwapDiagonal1I( testCounts );
	checks::testSubgroupQuadSwapDiagonal2I( testCounts );
	checks::testSubgroupQuadSwapDiagonal3I( testCounts );
	checks::testSubgroupQuadSwapDiagonal4I( testCounts );
	checks::testSubgroupQuadSwapDiagonal1U( testCounts );
	checks::testSubgroupQuadSwapDiagonal2U( testCounts );
	checks::testSubgroupQuadSwapDiagonal3U( testCounts );
	checks::testSubgroupQuadSwapDiagonal4U( testCounts );
	checks::testSubgroupQuadSwapDiagonal1B( testCounts );
	checks::testSubgroupQuadSwapDiagonal2B( testCounts );
	checks::testSubgroupQuadSwapDiagonal3B( testCounts );
	checks::testSubgroupQuadSwapDiagonal4B( testCounts );
	checks::testSubgroupQuadSwapDiagonal1D( testCounts );
	checks::testSubgroupQuadSwapDiagonal2D( testCounts );
	checks::testSubgroupQuadSwapDiagonal3D( testCounts );
	checks::testSubgroupQuadSwapDiagonal4D( testCounts );
	checks::testReadInvocation1F( testCounts );
	checks::testReadInvocation2F( testCounts );
	checks::testReadInvocation3F( testCounts );
	checks::testReadInvocation4F( testCounts );
	checks::testReadInvocation1I( testCounts );
	checks::testReadInvocation2I( testCounts );
	checks::testReadInvocation3I( testCounts );
	checks::testReadInvocation4I( testCounts );
	checks::testReadInvocation1U( testCounts );
	checks::testReadInvocation2U( testCounts );
	checks::testReadInvocation3U( testCounts );
	checks::testReadInvocation4U( testCounts );
	checks::testReadInvocation1D( testCounts );
	checks::testReadInvocation2D( testCounts );
	checks::testReadInvocation3D( testCounts );
	checks::testReadInvocation4D( testCounts );
	checks::testReadFirstInvocation1F( testCounts );
	checks::testReadFirstInvocation2F( testCounts );
	checks::testReadFirstInvocation3F( testCounts );
	checks::testReadFirstInvocation4F( testCounts );
	checks::testReadFirstInvocation1I( testCounts );
	checks::testReadFirstInvocation2I( testCounts );
	checks::testReadFirstInvocation3I( testCounts );
	checks::testReadFirstInvocation4I( testCounts );
	checks::testReadFirstInvocation1U( testCounts );
	checks::testReadFirstInvocation2U( testCounts );
	checks::testReadFirstInvocation3U( testCounts );
	checks::testReadFirstInvocation4U( testCounts );
	checks::testReadFirstInvocation1D( testCounts );
	checks::testReadFirstInvocation2D( testCounts );
	checks::testReadFirstInvocation3D( testCounts );
	checks::testReadFirstInvocation4D( testCounts );
	testSuiteEnd()
}

testSuiteLaunch( TestASTIntrinsics )
