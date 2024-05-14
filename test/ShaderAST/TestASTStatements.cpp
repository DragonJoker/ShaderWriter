#include "Common.hpp"

#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Visitors/CloneStmt.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SelectEntryPoint.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;

	expr::ExprList makeList( expr::ExprPtr arg0 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		return result;
	}

	expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		result.push_back( std::move( arg1 ) );
		return result;
	}

	expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1
		, expr::ExprPtr arg2
		, expr::ExprPtr arg3 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		result.push_back( std::move( arg1 ) );
		result.push_back( std::move( arg2 ) );
		result.push_back( std::move( arg3 ) );
		return result;
	}

	stmt::ContainerPtr makeContainer( expr::ExprCache & exprCache
		, stmt::Stmt const & stmt )
	{
		auto & stmtCache = stmt.getStmtCache();

		if ( stmt.getKind() == stmt::Kind::eContainer )
		{
			return StmtCloner::submit( stmtCache, exprCache, static_cast< stmt::Container const & >( stmt ) );
		}

		auto container = stmtCache.makeContainer();
		container->addStmt( StmtCloner::submit( stmtCache, exprCache, &stmt ) );
		return container;
	}

	stmt::ContainerPtr makeEntryPoint( test::TestCounts & testCounts
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Stmt const & stmt
		, ShaderStage stage )
	{
		auto entryPoint = getEntryPointType( stage );
		auto & stmtCache = stmt.getStmtCache();
		auto funcType = typesCache.getFunction( typesCache.getVoid(), {} );
		auto funcVar = var::makeFunction( { testCounts.getNextVarId(), "main" }, funcType );
		auto container = stmtCache.makeContainer();
		auto funcDecl = stmtCache.makeFunctionDecl( funcVar, stmt::FunctionFlag( 1u << uint32_t( entryPoint ) ) );

		if ( stmt.getKind() == stmt::Kind::eContainer )
		{
			funcDecl->addStmt( StmtCloner::submit( stmtCache, exprCache, static_cast< stmt::Container const & >( stmt ) ) );
		}
		else
		{
			funcDecl->addStmt( StmtCloner::submit( stmtCache, exprCache, &stmt ) );
		}

		container->addStmt( std::move( funcDecl ) );
		return container;
	}

	void checkStmtDependant( test::TestCounts & testCounts
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Stmt const & stmt
		, ShaderStage stage = ShaderStage::eCompute )
	{
		auto & stmtCache = stmt.getStmtCache();
		if ( astOn( debug::displayStatements( stmt ) ) )
		{
			EntryPointConfig config{ stage, "main" };
			SpecialisationInfo spec{};
			SpecConstantData specData{};
			specData.info.location = 1u;
			specData.info.type = typesCache.getInt32();
			specData.data.resize( 4u, 0u );
			spec.data.push_back( specData );
			if ( astWhen( "SSA transform without normalised structs" ) )
			{
				auto container = makeContainer( exprCache, stmt );
				astCheckNoThrow( listEntryPoints( *container ) )
				astCheckNoThrow( selectEntryPoint( stmtCache, exprCache, config, *container ) )
				SSAData data{ testCounts.nextVarId, 0u };
				astCheckNoThrow( container = transformSSA( stmtCache, exprCache, typesCache, *container, data, false ) )
				astCheckNoThrow( container = simplify( stmtCache, exprCache, typesCache, *container ) )
				astCheckNoThrow( container = resolveConstants( stmtCache, exprCache, *container ) )
				astCheckNoThrow( container = specialiseStatements( stmtCache, exprCache, typesCache, *container, spec ) )
			}
			if ( astWhen( "SSA transform with normalised structs" ) )
			{
				auto container = makeContainer( exprCache, stmt );
				astCheckNoThrow( listEntryPoints( *container ) )
				astCheckNoThrow( selectEntryPoint( stmtCache, exprCache, config, *container ) )
				SSAData data{ testCounts.nextVarId, 0u };
				astCheckNoThrow( container = transformSSA( stmtCache, exprCache, typesCache, *container, data, true ) )
				astCheckNoThrow( container = simplify( stmtCache, exprCache, typesCache, *container ) )
				astCheckNoThrow( container = resolveConstants( stmtCache, exprCache, *container ) )
				astCheckNoThrow( container = specialiseStatements( stmtCache, exprCache, typesCache, *container, spec ) )
			}
			if ( astWhen( "SSA transform without normalised structs" ) )
			{
				auto container = makeEntryPoint( testCounts, exprCache, typesCache, stmt, stage );
				astCheckNoThrow( listEntryPoints( *container ) )
				astCheckNoThrow( selectEntryPoint( stmtCache, exprCache, config, *container ) )
				SSAData data{ testCounts.nextVarId, 0u };
				astCheckNoThrow( container = transformSSA( stmtCache, exprCache, typesCache, *container, data, false ) )
				astCheckNoThrow( container = simplify( stmtCache, exprCache, typesCache, *container ) )
				astCheckNoThrow( container = resolveConstants( stmtCache, exprCache, *container ) )
				astCheckNoThrow( container = specialiseStatements( stmtCache, exprCache, typesCache, *container, spec ) )
			}
			if ( astWhen( "SSA transform with normalised structs" ) )
			{
				auto container = makeEntryPoint( testCounts, exprCache, typesCache, stmt, stage );
				astCheckNoThrow( listEntryPoints( *container ) )
				astCheckNoThrow( selectEntryPoint( stmtCache, exprCache, config, *container ) )
				SSAData data{ testCounts.nextVarId, 0u };
				astCheckNoThrow( container = transformSSA( stmtCache, exprCache, typesCache, *container, data, true ) )
				astCheckNoThrow( container = simplify( stmtCache, exprCache, typesCache, *container ) )
				astCheckNoThrow( container = resolveConstants( stmtCache, exprCache, *container ) )
				astCheckNoThrow( container = specialiseStatements( stmtCache, exprCache, typesCache, *container, spec ) )
			}
			if ( astOn( "SimpleVisitor check" ) )
			{
				struct Visitor
					: public stmt::SimpleVisitor
				{
				};
				Visitor vis;
				astCheckNoThrow( stmt.accept( &vis ) )
			}
		}
	}

	void testSimple( test::TestCounts & testCounts )
	{
		astTestBegin( "testSimple" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		if ( astOn( "Variable initialisation" ) )
		{
			auto lhs = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto stmt = stmtCache.makeSimple( exprCache.makeInit( std::move( lhs ), std::move( rhs ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSimple )
			astCheck( stmt->getExpr()->getKind() == expr::Kind::eInit )
		}
		{
			auto lhs = exprCache.makeIdentifier( typesCache
				, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" ) );
			auto stmt = stmtCache.makeSimple( exprCache.makeAggrInit( std::move( lhs )
					, makeList( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "a" ) )
						, exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "b" ) ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSimple )
			astCheck( stmt->getExpr()->getKind() == expr::Kind::eAggrInit )
		}
		{
			auto lhs = exprCache.makeIdentifier( typesCache
				, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" ) );
			auto rhs = exprCache.makeLiteral( typesCache, 10 );
			auto stmt = stmtCache.makeSimple( exprCache.makeAggrInit( std::move( lhs )
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSimple )
			astCheck( stmt->getExpr()->getKind() == expr::Kind::eAggrInit )
		}
		{
			auto lhs = exprCache.makeIdentifier( typesCache
				, var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" ) );
			auto stmt = stmtCache.makeSimple( exprCache.makeInit( std::move( lhs )
				, exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
					, type::Kind::eInt32
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSimple )
			astCheck( stmt->getExpr()->getKind() == expr::Kind::eInit )
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeLiteral( typesCache, 10 ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, lhs ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAggrInit( exprCache.makeIdentifier( typesCache, lhs )
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, lhs ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
					, type::Kind::eInt32
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, lhs ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" );
			auto rhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "rhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeLiteral( typesCache, 10 ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAssign( typesCache.getInt32()
				, exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeIdentifier( typesCache, rhs ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" );
			auto rhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "rhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAggrInit( exprCache.makeIdentifier( typesCache, lhs )
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAssign( typesCache.getVec2I32()
				, exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeIdentifier( typesCache, rhs ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" );
			auto rhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "rhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
					, type::Kind::eInt32
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAssign( typesCache.getVec2I32()
				, exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeIdentifier( typesCache, rhs ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( typesCache.getInt32(), 2u ), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAggrInit( exprCache.makeIdentifier( typesCache, lhs )
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeArrayAccess( typesCache.getInt32()
				, exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeLiteral( typesCache, 1 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec2I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeCompositeConstruct( expr::CompositeType::eVec2, type::Kind::eInt32
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 ) ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeArrayAccess( typesCache.getInt32()
				, exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeLiteral( typesCache, 1 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = exprCache.makeAggrInit( typesCache.getVec4I32()
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
					, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) );
			auto stmt = stmtCache.makeSimple( exprCache.makeSwizzle( std::move( lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e0 } ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = exprCache.makeAggrInit( typesCache.getVec4I32()
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
					, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) );
			auto stmt = stmtCache.makeSimple( exprCache.makeSwizzle( std::move( lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e01 } ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4, type::Kind::eInt32
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
					, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) );
			auto stmt = stmtCache.makeSimple( exprCache.makeSwizzle( std::move( lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e0 } ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4, type::Kind::eInt32
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
					, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) );
			auto stmt = stmtCache.makeSimple( exprCache.makeSwizzle( std::move( lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e01 } ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAggrInit( exprCache.makeIdentifier( typesCache, lhs )
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
					, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeSwizzle( exprCache.makeIdentifier( typesCache, lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e0 } ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeAggrInit( exprCache.makeIdentifier( typesCache, lhs )
				, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
					, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeSwizzle( exprCache.makeIdentifier( typesCache, lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e01 } ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeCompositeConstruct( expr::CompositeType::eVec4, type::Kind::eInt32
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
						, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeSwizzle( exprCache.makeIdentifier( typesCache, lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e0 } ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeCompositeConstruct( expr::CompositeType::eVec4, type::Kind::eInt32
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
						, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeSwizzle( exprCache.makeIdentifier( typesCache, lhs )
				, expr::SwizzleKind{ expr::SwizzleKind::e01 } ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto container = stmtCache.makeContainer();
			auto lhs = var::makeVariable( testCounts.getNextVarId(), typesCache.getVec4I32(), "lhs" );
			container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
				, exprCache.makeCompositeConstruct( expr::CompositeType::eVec4, type::Kind::eInt32
					, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
						, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) ) ) ) );
			container->addStmt( stmtCache.makeSimple( exprCache.makeArrayAccess( typesCache.getInt32()
				, exprCache.makeSwizzle( exprCache.makeIdentifier( typesCache, lhs ), expr::SwizzleKind{ expr::SwizzleKind::e01 } )
				, exprCache.makeLiteral( typesCache, 1 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *container );
		}
		{
			auto structType = typesCache.getStruct( type::MemoryLayout::eC, "Test" );
			structType->declMember( "a", type::Kind::eVec4I32, type::NotArray );
			{
				auto container = stmtCache.makeContainer();
				auto lhs = var::makeVariable( testCounts.getNextVarId(), structType, "lhs" );
				container->addStmt( stmtCache.makeSimple( exprCache.makeAggrInit( exprCache.makeIdentifier( typesCache, lhs )
					, makeList( exprCache.makeAggrInit( typesCache.getVec4I32()
						, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
							, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) ) ) ) ) );
				container->addStmt( stmtCache.makeSimple( exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, lhs ), 0u, 0u ) ) );
				checkStmtDependant( testCounts, exprCache, typesCache, *container );
			}
			{
				auto container = stmtCache.makeContainer();
				auto lhs = var::makeVariable( testCounts.getNextVarId(), structType, "lhs" );
				container->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, lhs )
					, exprCache.makeCompositeConstruct( expr::CompositeType::eVec4, type::Kind::eInt32
						, makeList( exprCache.makeLiteral( typesCache, 10 ), exprCache.makeLiteral( typesCache, 20 )
							, exprCache.makeLiteral( typesCache, 30 ), exprCache.makeLiteral( typesCache, 40 ) ) ) ) ) );
				container->addStmt( stmtCache.makeSimple( exprCache.makeMbrSelect( exprCache.makeIdentifier( typesCache, lhs ), 0u, 0u ) ) );
				checkStmtDependant( testCounts, exprCache, typesCache, *container );
			}
		}
		auto stmt = stmtCache.makeSimple( nullptr );
		StmtCloner::submit( stmtCache, exprCache, stmt.get() );

		astTestEnd()
	}

	void testContainer( test::TestCounts & testCounts )
	{
		astTestBegin( "testContainer" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeContainer();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eContainer )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeContainer();
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			StmtCloner::submit( stmtCache, exprCache, stmt.get() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eContainer )
			astCheck( stmt->size() == 2u )
			astCheck( stmt->back() )
		}
		astTestEnd()
	}

	void testCompound( test::TestCounts & testCounts )
	{
		astTestBegin( "testCompound" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeCompound();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eCompound )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeCompound();
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eCompound )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testComment( test::TestCounts & testCounts )
	{
		astTestBegin( "testComment" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeComment( "Coin glop miaou !!" );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eComment )
		astRequire( stmt->getText() == "Coin glop miaou !!" )
		astTestEnd()
	}

	void testVariableDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testVariableDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto stmt = stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eVariableDecl )
			astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getVariable()->getName() == "lhs" )
		}
		{
			auto stmt = stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::eLocale ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eVariableDecl )
			astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getVariable()->getName() == "lhs" )
		}
		astTestEnd()
	}

	void testPerVertexDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testPerVertexDecl" );
		std::map< stmt::PerVertexDecl::Source, ShaderStage > stages{ { stmt::PerVertexDecl::eVertexOutput, ShaderStage::eVertex }
			, { stmt::PerVertexDecl::eTessellationControlInput, ShaderStage::eTessellationControl }
			, { stmt::PerVertexDecl::eTessellationControlOutput, ShaderStage::eTessellationControl }
			, { stmt::PerVertexDecl::eTessellationEvaluationInput, ShaderStage::eTessellationEvaluation }
			, { stmt::PerVertexDecl::eTessellationEvaluationOutput, ShaderStage::eTessellationEvaluation }
			, { stmt::PerVertexDecl::eGeometryInput, ShaderStage::eGeometry }
			, { stmt::PerVertexDecl::eGeometryOutput, ShaderStage::eGeometry }
			, { stmt::PerVertexDecl::eMeshOutput, ShaderStage::eMesh } };
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;

		for ( uint32_t source = 0u; source <= uint32_t( stmt::PerVertexDecl::Source::eMeshOutput ); ++source )
		{
			auto stmt = stmtCache.makePerVertexDecl( stmt::PerVertexDecl::Source( source )
				, typesCache.getInt32() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, stages[stmt::PerVertexDecl::Source( source )] );

			astRequire( stmt->getKind() == stmt::Kind::ePerVertexDecl )
			astRequire( stmt->getSource() == stmt::PerVertexDecl::Source( source ) )
			astCheck( stmt->getType()->getKind() == type::Kind::eInt32 )
		}
		astTestEnd()
	}

	void testInOutVariableDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testInOutVariableDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto stmt = stmtCache.makeInOutVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::eShaderInput ), 1u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eCallable );

			astRequire( stmt->getKind() == stmt::Kind::eInOutVariableDecl )
			astCheck( stmt->getLocation() == 1u )
			astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getVariable()->getName() == "lhs" )
		}
		{
			auto stmt = stmtCache.makeInOutVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::eShaderConstant ), 1u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayAnyHit );

			astRequire( stmt->getKind() == stmt::Kind::eInOutVariableDecl )
			astCheck( stmt->getLocation() == 1u )
			astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getVariable()->getName() == "lhs" )
		}
		{
			auto stmt = stmtCache.makeInOutVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::ePushConstant ), 1u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayClosestHit );

			astRequire( stmt->getKind() == stmt::Kind::eInOutVariableDecl )
			astCheck( stmt->getLocation() == 1u )
			astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getVariable()->getName() == "lhs" )
		}
		astTestEnd()
	}

	void testInOutStreamVariableDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testInOutStreamVariableDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeInOutStreamVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::eShaderInput | var::Flag::eGeometryStream )
			, 1u
			, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eGeometry );

		astRequire( stmt->getKind() == stmt::Kind::eInOutVariableDecl )
		astCheck( stmt->getLocation() == 1u )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
		astCheck( stmt->getVariable()->getName() == "lhs" )
		astCheck( stmt->getVariable()->isGeometryStream() )
		astCheck( stmt->getStreamIndex() == 2u )
		astTestEnd()
	}

	void testInOutBlendVariableDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testInOutBlendVariableDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeInOutBlendVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::eShaderInput | var::Flag::eBlendIndex )
			, 1u
			, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eFragment );

		astRequire( stmt->getKind() == stmt::Kind::eInOutVariableDecl )
		astCheck( stmt->getLocation() == 1u )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
		astCheck( stmt->getVariable()->getName() == "lhs" )
		astCheck( stmt->getVariable()->isBlendIndex() )
		astCheck( stmt->getBlendIndex() == 2u )
		astTestEnd()
	}

	void testSpecialisationConstantDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testSpecialisationConstantDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		if ( astOn( "Base test" ) )
		{
			auto stmt = stmtCache.makeSpecialisationConstantDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", var::Flag::eShaderInput | var::Flag::eBlendIndex )
				, 1u
				, exprCache.makeLiteral( typesCache, 18 ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayMiss );

			astRequire( stmt->getKind() == stmt::Kind::eSpecialisationConstantDecl )
			astCheck( stmt->getLocation() == 1u )
			astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getVariable()->getName() == "lhs" )
			astCheck( stmt->getValue()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getValue()->getLiteralType() == expr::LiteralType::eInt32 )
			astCheck( stmt->getValue()->getValue< expr::LiteralType::eInt32 >() == 18 )
		}
		for ( uint8_t i = uint8_t( type::Kind::eBoolean ); i <= uint8_t( type::Kind::eVec2B ); ++i )
		{
			if ( auto kind = type::Kind( i );
				kind != type::Kind::eHalf )
			{
				if ( astOn( "Constant of type " + debug::getTypeName( kind ) ) )
				{
					auto var = var::makeVariable( testCounts.getNextVarId(), typesCache.getBasicType( kind )
						, "var"
						, var::Flag::eShaderInput | var::Flag::eBlendIndex );
					SpecialisationInfo spec{};
					SpecConstantData specData{};
					specData.info.location = 1u;
					specData.info.type = typesCache.getBasicType( kind );
					auto container = stmtCache.makeContainer();

					switch ( kind )
					{
					case type::Kind::eBoolean:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, true ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, true ) ) ) );
						specData.data.resize( 1u, 0u );
						break;
					case type::Kind::eInt8:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, int8_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, int8_t( 18 ) ) ) ) );
						specData.data.resize( 1u, 0u );
						break;
					case type::Kind::eInt16:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, int16_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, int16_t( 18 ) ) ) ) );
						specData.data.resize( 2u, 0u );
						break;
					case type::Kind::eInt32:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, int32_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, int32_t( 18 ) ) ) ) );
						specData.data.resize( 4u, 0u );
						break;
					case type::Kind::eInt64:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, int64_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, int64_t( 18 ) ) ) ) );
						specData.data.resize( 8u, 0u );
						break;
					case type::Kind::eUInt8:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, uint8_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, uint8_t( 18 ) ) ) ) );
						specData.data.resize( 1u, 0u );
						break;
					case type::Kind::eUInt16:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, uint16_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, uint16_t( 18 ) ) ) ) );
						specData.data.resize( 2u, 0u );
						break;
					case type::Kind::eUInt32:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, uint32_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, uint32_t( 18 ) ) ) ) );
						specData.data.resize( 4u, 0u );
						break;
					case type::Kind::eUInt64:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, uint64_t( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, uint64_t( 18 ) ) ) ) );
						specData.data.resize( 8u, 0u );
						break;
					case type::Kind::eFloat:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, float( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, float( 18 ) ) ) ) );
						specData.data.resize( 4u, 0u );
						break;
					case type::Kind::eDouble:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, double( 18 ) ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, double( 18 ) ) ) ) );
						specData.data.resize( 8u, 0u );
						break;
					default:
						container->addStmt( stmtCache.makeSpecialisationConstantDecl( var, 1u
							, exprCache.makeLiteral( typesCache, true ) ) );
						container->addStmt( stmtCache.makeSimple( exprCache.makeAdd( typesCache.getBasicType( kind )
							, exprCache.makeIdentifier( typesCache, var )
							, exprCache.makeLiteral( typesCache, true ) ) ) );
						specData.data.resize( 2u, 0u );
						break;
					}

					spec.data.push_back( specData );

#if SDAST_ExceptAssert
					if ( kind == type::Kind::eVec2B )
					{
						astCheckThrow( container = specialiseStatements( stmtCache, exprCache, typesCache, *container, spec ) )
					}
					else
					{
						astCheckNoThrow( container = specialiseStatements( stmtCache, exprCache, typesCache, *container, spec ) )
					}
#endif
				}
			}
		}
		astTestEnd()
	}

	void testConstantBufferDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testConstantBufferDecl" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeConstantBufferDecl( "Buffer", type::MemoryLayout::eStd140, 1u, 2u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eMeshNV );

			astRequire( stmt->getKind() == stmt::Kind::eConstantBufferDecl )
			astCheck( stmt->getBindingPoint() == 1u )
			astCheck( stmt->getDescriptorSet() == 2u )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeConstantBufferDecl( "Buffer", type::MemoryLayout::eStd140, 1u, 2u );
			stmt->add( stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eTask );

			astRequire( stmt->getKind() == stmt::Kind::eConstantBufferDecl )
			astCheck( stmt->getBindingPoint() == 1u )
			astCheck( stmt->getDescriptorSet() == 2u )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testPushConstantsBufferDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testPushConstantsBufferDecl" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makePushConstantsBufferDecl( "Buffer", type::MemoryLayout::eC );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eTaskNV );

			astRequire( stmt->getKind() == stmt::Kind::ePushConstantsBufferDecl )
			astCheck( stmt->getMemoryLayout() == type::MemoryLayout::eC )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makePushConstantsBufferDecl( "Buffer", type::MemoryLayout::eC );
			stmt->add( stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::ePushConstantsBufferDecl )
			astCheck( stmt->getMemoryLayout() == type::MemoryLayout::eC )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testShaderBufferDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testShaderBufferDecl" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeShaderBufferDecl( typesCache, "Buffer", type::MemoryLayout::eStd430, 1u, 2u, testCounts.getNextVarId() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eShaderBufferDecl )
			astCheck( stmt->getBindingPoint() == 1u )
			astCheck( stmt->getDescriptorSet() == 2u )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeShaderBufferDecl( typesCache, "Buffer", type::MemoryLayout::eStd430, 1u, 2u, testCounts.getNextVarId() );
			stmt->add( stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eShaderBufferDecl )
			astCheck( stmt->getBindingPoint() == 1u )
			astCheck( stmt->getDescriptorSet() == 2u )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testShaderStructBufferDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testShaderStructBufferDecl" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto baseType = typesCache.getStruct( type::MemoryLayout::eStd430, "BaseType" );
			auto array = typesCache.getArray( baseType );
			auto type = typesCache.getStruct( type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = var::makeVariable( testCounts.getNextVarId(), type->getMember( "Data" ).type, "Data", var::Flag::eUniform );
			auto instance = var::makeVariable( testCounts.getNextVarId(), type, "Inst", var::Flag::eUniform );
			auto stmt = stmtCache.makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eShaderStructBufferDecl )
			astCheck( stmt->getBindingPoint() == 1u )
			astCheck( stmt->getDescriptorSet() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto baseType = typesCache.getIOStruct( "BaseType", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput );
			baseType->declMember( Builtin::eGlobalInvocationID, type::Kind::eInt32, type::NotArray );
			baseType->declMember( "mbr", type::Kind::eInt32, type::NotArray, 1u );
			auto array = typesCache.getArray( baseType );
			auto type = typesCache.getStruct( type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = var::makeVariable( testCounts.getNextVarId(), type->getMember( "Data" ).type, "Data", var::Flag::eUniform );
			auto instance = var::makeVariable( testCounts.getNextVarId(), type, "Inst", var::Flag::eUniform );
			auto stmt = stmtCache.makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eShaderStructBufferDecl )
			astCheck( stmt->getBindingPoint() == 1u )
			astCheck( stmt->getDescriptorSet() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto baseType = typesCache.getStruct( type::MemoryLayout::eStd430, "BaseType" );
			baseType->declMember( "i", typesCache.getInt32() );
			baseType->declMember( "j", typesCache.getInt32() );
			auto array = typesCache.getArray( baseType );
			auto type = typesCache.getStruct( type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = var::makeVariable( testCounts.getNextVarId(), type->getMember( "Data" ).type, "Data", var::Flag::eUniform );
			auto instance = var::makeVariable( testCounts.getNextVarId(), type, "Inst", var::Flag::eUniform );
			auto stmt = stmtCache.makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eShaderStructBufferDecl )
			astCheck( stmt->getBindingPoint() == 1u )
			astCheck( stmt->getDescriptorSet() == 2u )
		}
		astTestEnd()
	}

	void testSamplerDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testSamplerDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeSamplerDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getSampler(), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eSamplerDecl )
		astCheck( stmt->getBindingPoint() == 1u )
		astCheck( stmt->getDescriptorSet() == 2u )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eSampler )
		astCheck( stmt->getVariable()->getName() == "lhs" )
		astTestEnd()
	}

	void testImageDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testImageDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		type::ImageConfiguration config{};
		auto stmt = stmtCache.makeImageDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getImage( config ), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eImageDecl )
		astCheck( stmt->getBindingPoint() == 1u )
		astCheck( stmt->getDescriptorSet() == 2u )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eImage )
		astCheck( stmt->getVariable()->getName() == "lhs" )
		astTestEnd()
	}

	void testSampledImageDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testSampledImageDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		type::ImageConfiguration config{};
		auto stmt = stmtCache.makeSampledImageDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getSampledImage( config ), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eSampledImageDecl )
		astCheck( stmt->getBindingPoint() == 1u )
		astCheck( stmt->getDescriptorSet() == 2u )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eSampledImage )
		astCheck( stmt->getVariable()->getName() == "lhs" )
		astTestEnd()
	}

	void testCombinedImageDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testCombinedImageDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		type::ImageConfiguration config{};
		auto stmt = stmtCache.makeCombinedImageDecl( var::makeVariable( testCounts.getNextVarId(), typesCache.getCombinedImage( config, true ), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eCombinedImageDecl )
		astCheck( stmt->getBindingPoint() == 1u )
		astCheck( stmt->getDescriptorSet() == 2u )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eCombinedImage )
		astCheck( stmt->getVariable()->getName() == "lhs" )
		astTestEnd()
	}

	void testFunctionDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testFunctionDecl" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), {} ), "foo" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eVertex );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "foo" )
			astCheck( stmt->getType()->empty() )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) } ), "foo" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "foo" )
			astCheck( stmt->getType()->size() == 1u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ), var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) } ), "foo" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "foo" )
			astCheck( stmt->getType()->size() == 2u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), {} ), "foo" ) );
			stmt->addStmt( stmtCache.makeReturn( exprCache.makeLiteral( typesCache, 10 ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "foo" )
			astCheck( stmt->getType()->empty() )
			astCheck( stmt->size() == 1u )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) } ), "foo" ) );
			stmt->addStmt( stmtCache.makeReturn(
				exprCache.makeAdd( typesCache.getInt32(),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 0u ) ),
					exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "foo" )
			astCheck( stmt->getType()->size() == 1u )
			astCheck( stmt->size() == 1u )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ), var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) } ), "foo" ) );
			stmt->addStmt( stmtCache.makeReturn(
				exprCache.makeAdd( typesCache.getInt32(),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 0u ) ),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 1u ) ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "foo" )
			astCheck( stmt->getType()->size() == 2u )
			astCheck( stmt->size() == 1u )
			astCheck( !stmt->isPatchRoutine() )
		}
		astTestEnd()
	}

	void testEntryPointDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testEntryPointDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto inType = type::makeGeometryInputType( typesCache.getVoid(), type::InputLayout::eTriangleList );
			auto outType = type::makeGeometryOutputType( typesCache.getVoid(), type::OutputLayout::eTriangleStrip, 3u );
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
					, { var::makeVariable( testCounts.getNextVarId(), inType, "in" )
						, var::makeVariable( testCounts.getNextVarId(), outType, "out" ) } )
					, "mainGeom" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eGeometry );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "mainGeom" )
			astCheck( stmt->getType()->size() == 2u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			auto inType = type::makeTessellationControlInputType( typesCache.getVoid(), 3u );
			auto outType = type::makeTessellationControlOutputType( typesCache.getVoid(), type::PatchDomain::eTriangles, type::Partitioning::eEqual, type::OutputTopology::eTriangle, type::PrimitiveOrdering::eCCW, 3u );
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { var::makeVariable( testCounts.getNextVarId(), inType, "in" )
					, var::makeVariable( testCounts.getNextVarId(), outType, "out" ) } )
				, "mainTesc" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eTessellationControl );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "mainTesc" )
			astCheck( stmt->getType()->size() == 2u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			auto inType = type::makeTessellationEvaluationInputType( typesCache.getVoid(), type::PatchDomain::eTriangles, type::Partitioning::eEqual, type::PrimitiveOrdering::eCCW, 3u );
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { var::makeVariable( testCounts.getNextVarId(), inType, "in" ) } )
				, "mainTese" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eTessellationEvaluation );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "mainTese" )
			astCheck( stmt->getType()->size() == 1u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			auto inType = type::makeFragmentInputType( typesCache.getVoid(), FragmentOrigin::eLowerLeft, FragmentCenter::eHalfPixel, InvocationOrdering::ePixelInterlockOrdered );
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { var::makeVariable( testCounts.getNextVarId(), inType, "in" ) } )
				, "mainFrag" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eFragment );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "mainFrag" )
			astCheck( stmt->getType()->size() == 1u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			auto inType = type::makeComputeInputType( typesCache.getVoid(), 4u, 8u, 16u );
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { var::makeVariable( testCounts.getNextVarId(), inType, "in" ) } )
				, "mainComp" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eCompute );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "mainComp" )
			astCheck( stmt->getType()->size() == 1u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		{
			auto outVertType = type::makeMeshVertexOutputType( typesCache.getVoid(), 4u );
			auto outPrimType = type::makeMeshPrimitiveOutputType( typesCache.getVoid(), type::OutputTopology::eTriangle, 2u );
			auto stmt = stmtCache.makeFunctionDecl( var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { var::makeVariable( testCounts.getNextVarId(), outVertType, "vert" )
					, var::makeVariable( testCounts.getNextVarId(), outPrimType, "prim" ) } )
				, "mainMesh" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eMesh );

			astRequire( stmt->getKind() == stmt::Kind::eFunctionDecl )
			astCheck( stmt->getName() == "mainMesh" )
			astCheck( stmt->getType()->size() == 2u )
			astCheck( stmt->empty() )
			astCheck( !stmt->isPatchRoutine() )
		}
		astTestEnd()
	}

	void testStructureDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testStructureDecl" );
		for ( auto layout = 0u; layout <= uint32_t( type::MemoryLayout::eShaderRecord ); ++layout )
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto type = typesCache.getStruct( type::MemoryLayout( layout ), "MyStruct" );
			auto stmt = stmtCache.makeStructureDecl( type );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eStructureDecl )
			astCheck( stmt->getType()->getName() == "MyStruct" )
			astCheck( stmt->getType()->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto type = typesCache.getStruct( type::MemoryLayout::eStd140, "MyStruct" );
			type->declMember( "i", typesCache.getInt32() );
			type->declMember( "j", typesCache.getInt32() );
			auto stmt = stmtCache.makeStructureDecl( type );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eStructureDecl )
			astCheck( stmt->getType()->getName() == "MyStruct" )
			astCheck( stmt->getType()->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto type = typesCache.getIOStruct( "MyStruct", EntryPoint::eCompute, var::Flag::eShaderInput );
			type->declMember( "i", typesCache.getInt32(), 0u );
			type->declMember( "j", typesCache.getInt32(), 1u );
			type->declMember( Builtin::eGlobalInvocationID, type::Kind::eInt32, type::NotArray );
			auto stmt = stmtCache.makeStructureDecl( type );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eStructureDecl )
			astCheck( stmt->getType()->getName() == "MyStructCompInput" )
			astCheck( stmt->getType()->size() == 3u )
		}
		astTestEnd()
	}

	void testIf( test::TestCounts & testCounts )
	{
		astTestBegin( "testIf" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eIf )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eIdentifier )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eIf )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eIdentifier )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeIf( exprCache.makeLiteral( typesCache, false ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eIf )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eLiteral )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeIf( exprCache.makeLiteral( typesCache, true ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eIf )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eLiteral )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testElse( test::TestCounts & testCounts )
	{
		astTestBegin( "testElse" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			auto elseStmt = stmt->createElse();
			astCheckThrow( stmt->createElse() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( elseStmt->getKind() == stmt::Kind::eElse )
			astCheck( elseStmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseStmt = stmt->createElse();
			astCheckThrow( stmt->createElse() );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( elseStmt->getKind() == stmt::Kind::eElse )
			astCheck( elseStmt->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeLiteral( typesCache, true ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			{
				auto subStmt = stmtCache.makeIf( exprCache.makeLiteral( typesCache, false ) );
				subStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
				subStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
				auto subElseStmt = subStmt->createElse();
				astCheckThrow( subStmt->createElse() );
				subElseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
				subElseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
				stmt->addStmt( std::move( subStmt ) );
			}
			auto elseStmt = stmt->createElse();
			astCheckThrow( stmt->createElse() );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( elseStmt->getKind() == stmt::Kind::eElse )
			astCheck( elseStmt->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeLiteral( typesCache, false ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseStmt = stmt->createElse();
			astCheckThrow( stmt->createElse() );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			{
				auto subStmt = stmtCache.makeIf( exprCache.makeLiteral( typesCache, true ) );
				subStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
				subStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
				auto subElseStmt = subStmt->createElse();
				astCheckThrow( subStmt->createElse() );
				subElseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
				subElseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
				stmt->addStmt( std::move( subStmt ) );
			}
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( elseStmt->getKind() == stmt::Kind::eElse )
			astCheck( elseStmt->size() == 2u )
		}
		astTestEnd()
	}

	void testElseIf( test::TestCounts & testCounts )
	{
		astTestBegin( "testElseIf" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( elseIfStmt->getKind() == stmt::Kind::eElseIf )
			astCheck( elseIfStmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( elseIfStmt->getKind() == stmt::Kind::eElseIf )
			astCheck( elseIfStmt->size() == 2u )
		}
		astTestEnd()
	}

	void testElseIfElse( test::TestCounts & testCounts )
	{
		astTestBegin( "testElseIf" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->createElseIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			stmt->createElse();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		astTestEnd()
	}

	void testWhile( test::TestCounts & testCounts )
	{
		astTestBegin( "testWhile" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeWhile( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eWhile )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eIdentifier )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeWhile( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eWhile )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eIdentifier )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testFor( test::TestCounts & testCounts )
	{
		astTestBegin( "testFor" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto k = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeFor( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 0 ) )
				, exprCache.makeLessEqual( typesCache, exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) )
				, exprCache.makePreIncrement( exprCache.makeIdentifier( typesCache, k ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eFor )
			astCheck( stmt->getInitExpr()->getKind() == expr::Kind::eInit )
			astCheck( stmt->getInitExpr()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eLessEqual )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->getIncrExpr()->getKind() == expr::Kind::ePreIncrement )
			astCheck( stmt->getIncrExpr()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto k = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeFor( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 0 ) )
				, exprCache.makeLessEqual( typesCache, exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) )
				, exprCache.makePreIncrement( exprCache.makeIdentifier( typesCache, k ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eFor )
			astCheck( stmt->getInitExpr()->getKind() == expr::Kind::eInit )
			astCheck( stmt->getInitExpr()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eLessEqual )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->getIncrExpr()->getKind() == expr::Kind::ePreIncrement )
			astCheck( stmt->getIncrExpr()->getType()->getKind() == type::Kind::eInt32 )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testDoWhile( test::TestCounts & testCounts )
	{
		astTestBegin( "testDoWhile" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeDoWhile( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eDoWhile )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eIdentifier )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeDoWhile( exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eDoWhile )
			astCheck( stmt->getCtrlExpr()->getKind() == expr::Kind::eIdentifier )
			astCheck( stmt->getCtrlExpr()->getType()->getKind() == type::Kind::eBoolean )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testSwitch( test::TestCounts & testCounts )
	{
		astTestBegin( "testSwitch" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSwitch )
			astCheck( stmt->getTestExpr()->getKind() == expr::Kind::eSwitchTest )
			astCheck( stmt->empty() )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			stmt->createDefault();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSwitch )
			astCheck( stmt->getTestExpr()->getKind() == expr::Kind::eSwitchTest )
			astCheck( stmt->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto k = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			auto caseStmt = stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto defaultStmt = stmt->createDefault();
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSwitch )
			astCheck( stmt->getTestExpr()->getKind() == expr::Kind::eSwitchTest )
			astCheck( stmt->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto k = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeLiteral( typesCache, 10 ) ) );
			auto caseStmt = stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto defaultStmt = stmt->createDefault();
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSwitch )
			astCheck( stmt->getTestExpr()->getKind() == expr::Kind::eSwitchTest )
			astCheck( stmt->size() == 2u )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto j = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto k = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeLiteral( typesCache, 20 ) ) );
			auto caseStmt = stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto defaultStmt = stmt->createDefault();
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eSwitch )
			astCheck( stmt->getTestExpr()->getKind() == expr::Kind::eSwitchTest )
			astCheck( stmt->size() == 2u )
		}
		astTestEnd()
	}

	void testReturn( test::TestCounts & testCounts )
	{
		astTestBegin( "testReturn" );
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeReturn();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eReturn )
		}
		{
			stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			type::TypesCache typesCache;
			auto stmt = stmtCache.makeReturn( exprCache.makeLiteral( typesCache, 10 ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eReturn )
			astCheck( stmt->getExpr()->getKind() == expr::Kind::eLiteral )
		}
		astTestEnd()
	}

	void testDemote( test::TestCounts & testCounts )
	{
		astTestBegin( "testDemote" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeDemote();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eDemote )
		astTestEnd()
	}

	void testTerminateInvocation( test::TestCounts & testCounts )
	{
		astTestBegin( "testTerminateInvocation" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeTerminateInvocation();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eTerminateInvocation )
		astTestEnd()
	}

	void testInputGeometryLayout( test::TestCounts & testCounts )
	{
		astTestBegin( "testInputGeometryLayout" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputGeometryLayout( typesCache.getVoid()
			, type::InputLayout::eLineStripWithAdjacency );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eGeometry );

		astRequire( stmt->getKind() == stmt::Kind::eInputGeometryLayout )
		astCheck( stmt->getType()->getKind() == type::Kind::eVoid )
		astCheck( stmt->getLayout() == type::InputLayout::eLineStripWithAdjacency )
		astTestEnd()
	}

	void testOutputGeometryLayout( test::TestCounts & testCounts )
	{
		astTestBegin( "testOutputGeometryLayout" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputGeometryLayout( typesCache.getVoid()
			, type::OutputLayout::eTriangleStrip
			, 15u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eGeometry );

		astRequire( stmt->getKind() == stmt::Kind::eOutputGeometryLayout )
		astCheck( stmt->getType()->getKind() == type::Kind::eVoid )
		astCheck( stmt->getLayout() == type::OutputLayout::eTriangleStrip )
		astCheck( stmt->getPrimCount() == 15u )
		astTestEnd()
	}

	void testOutputMeshLayout( test::TestCounts & testCounts )
	{
		astTestBegin( "testOutputMeshLayout" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputMeshLayout( typesCache.getVoid()
			, type::OutputTopology::eTriangle
			, 64u
			, 126u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eMesh );

		astRequire( stmt->getKind() == stmt::Kind::eOutputMeshLayout )
		astCheck( stmt->getType()->getKind() == type::Kind::eVoid )
		astCheck( stmt->getTopology() == type::OutputTopology::eTriangle )
		astCheck( stmt->getMaxVertices() == 64u )
		astCheck( stmt->getMaxPrimitives() == 126u )
		astTestEnd()
	}

	void testInputComputeLayout( test::TestCounts & testCounts )
	{
		astTestBegin( "testInputComputeLayout" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputComputeLayout( typesCache.getVoid(), 16, 32, 64 );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eInputComputeLayout )
		astCheck( stmt->getType()->getKind() == type::Kind::eVoid )
		astCheck( stmt->getWorkGroupsX() == 16u )
		astCheck( stmt->getWorkGroupsY() == 32u )
		astCheck( stmt->getWorkGroupsZ() == 64u )
		astTestEnd()
	}

	void testPreprocExtension( test::TestCounts & testCounts )
	{
		astTestBegin( "testPreprocExtension" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;

		for ( uint32_t status = 0u; status <= uint32_t( stmt::PreprocExtension::ExtStatus::eRequired ); ++status )
		{
			auto stmt = stmtCache.makePreprocExtension( "GL_arb_coin", stmt::PreprocExtension::ExtStatus( status ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::ePreprocExtension )
			astCheck( stmt->getName() == "GL_arb_coin" )
			astCheck( stmt->getStatus() == stmt::PreprocExtension::ExtStatus( status ) )
		}
		astTestEnd()
	}

	void testPreprocVersion( test::TestCounts & testCounts )
	{
		astTestBegin( "testPreprocVersion" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocVersion( "430 core" );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::ePreprocVersion )
		astCheck( stmt->getName() == "430 core" )
		astTestEnd()
	}

	void testFragmentLayout( test::TestCounts & testCounts )
	{
		astTestBegin( "testFragmentLayout" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeFragmentLayout( typesCache.getVoid()
			, FragmentOrigin::eLowerLeft
			, FragmentCenter::eCenterInteger
			, InvocationOrdering::ePixelInterlockOrdered );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eFragment );

		astRequire( stmt->getKind() == stmt::Kind::eFragmentLayout )
		astCheck( stmt->getFragmentCenter() == FragmentCenter::eCenterInteger )
		astCheck( stmt->getFragmentOrigin() == FragmentOrigin::eLowerLeft )
		astTestEnd()
	}

	void testOutputTessellationControlLayout( test::TestCounts & testCounts )
	{
		astTestBegin( "testOutputTessellationControlLayout" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputTessellationControlLayout( typesCache.getVoid()
			, type::PatchDomain::eQuads
			, type::Partitioning::eFractionalEven
			, type::OutputTopology::eQuad
			, type::PrimitiveOrdering::eCCW
			, 4u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eTessellationControl );

		astRequire( stmt->getKind() == stmt::Kind::eOutputTessellationControlLayout )
		astCheck( stmt->getDomain() == type::PatchDomain::eQuads )
		astCheck( stmt->getPartitioning() == type::Partitioning::eFractionalEven )
		astCheck( stmt->getTopology() == type::OutputTopology::eQuad )
		astCheck( stmt->getPrimitiveOrdering() == type::PrimitiveOrdering::eCCW )
		astCheck( stmt->getOutputVertices() == 4u )
		astTestEnd()
	}

	void testInputTessellationEvaluationLayout( test::TestCounts & testCounts )
	{
		astTestBegin( "testInputTessellationEvaluationLayout" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputTessellationEvaluationLayout( typesCache.getVoid()
			, type::PatchDomain::eQuads
			, type::Partitioning::eFractionalEven
			, type::PrimitiveOrdering::eCCW );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eTessellationEvaluation );

		astRequire( stmt->getKind() == stmt::Kind::eInputTessellationEvaluationLayout )
		astCheck( stmt->getDomain() == type::PatchDomain::eQuads )
		astCheck( stmt->getPartitioning() == type::Partitioning::eFractionalEven )
		astCheck( stmt->getPrimitiveOrdering() == type::PrimitiveOrdering::eCCW )
		astTestEnd()
	}

	void testAccelerationStructureDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testAccelerationStructureDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeAccelerationStructureDecl( i
			, 18u
			, 52u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayGeneration );

		astRequire( stmt->getKind() == stmt::Kind::eAccelerationStructureDecl )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
		astCheck( stmt->getVariable()->getName() == "i" )
		astCheck( stmt->getBindingPoint() == 18u )
		astCheck( stmt->getDescriptorSet() == 52u )
		astTestEnd()
	}

	void testInOutRayPayloadVariableDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testInOutRayPayloadVariableDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeInOutRayPayloadVariableDecl( i
			, 18u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayIntersection );

		astRequire( stmt->getKind() == stmt::Kind::eInOutRayPayloadVariableDecl )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
		astCheck( stmt->getVariable()->getName() == "i" )
		astCheck( stmt->getLocation() == 18u )
		astTestEnd()
	}

	void testHitAttributeVariableDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testHitAttributeVariableDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeHitAttributeVariableDecl( i );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayAnyHit );

		astRequire( stmt->getKind() == stmt::Kind::eHitAttributeVariableDecl )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
		astCheck( stmt->getVariable()->getName() == "i" )
		astTestEnd()
	}

	void testInOutCallableDataVariableDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testInOutCallableDataVariableDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto i = var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeInOutCallableDataVariableDecl( i
			, 18u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eCallable );

		astRequire( stmt->getKind() == stmt::Kind::eInOutCallableDataVariableDecl )
		astCheck( stmt->getVariable()->getType()->getKind() == type::Kind::eInt32 )
		astCheck( stmt->getVariable()->getName() == "i" )
		astCheck( stmt->getLocation() == 18u )
		astTestEnd()
	}

	void testBufferReferenceDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testBufferReferenceDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeBufferReferenceDecl( typesCache.getInt32() );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eBufferReferenceDecl )
		astCheck( stmt->getType()->getKind() == type::Kind::eInt32 )
		astTestEnd()
	}

	void testTerminateRay( test::TestCounts & testCounts )
	{
		astTestBegin( "testTerminateRay" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeTerminateRay();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayClosestHit );

		astRequire( stmt->getKind() == stmt::Kind::eTerminateRay )
		astTestEnd()
	}

	void testIgnoreIntersection( test::TestCounts & testCounts )
	{
		astTestBegin( "testIgnoreIntersection" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeIgnoreIntersection();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eRayIntersection );

		astRequire( stmt->getKind() == stmt::Kind::eIgnoreIntersection )
		astTestEnd()
	}

	void testBreak( test::TestCounts & testCounts )
	{
		astTestBegin( "testBreak" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		{
			auto stmt = stmtCache.makeBreak( true );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eBreak );
			astRequire( stmt->isSwitchCaseBreak() );
		}
		{
			auto stmt = stmtCache.makeBreak( false );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			astRequire( stmt->getKind() == stmt::Kind::eBreak )
			astRequire( !stmt->isSwitchCaseBreak() );
		}
		astTestEnd()
	}

	void testContinue( test::TestCounts & testCounts )
	{
		astTestBegin( "testContinue" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makeContinue();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		astRequire( stmt->getKind() == stmt::Kind::eContinue )
		astTestEnd()
	}

	void testDispatchMesh( test::TestCounts & testCounts )
	{
		astTestBegin( "testDispatchMesh" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto numGroupsX = exprCache.makeLiteral( typesCache, 16u );
		auto numGroupsY = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "numGroupsY" ) );
		auto numGroupsZ = exprCache.makeLiteral( typesCache, 32u );
		auto payload = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getTaskPayload( typesCache.getUInt32() ), "payload" ) );
		auto stmt = stmtCache.makeDispatchMesh( std::move( numGroupsX ), std::move( numGroupsY ), std::move( numGroupsZ ), std::move( payload ) );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eTask );

		astRequire( stmt->getKind() == stmt::Kind::eDispatchMesh )
		astRequire( stmt->getNumGroupsX()->getKind() == expr::Kind::eLiteral )
		astRequire( stmt->getNumGroupsY()->getKind() == expr::Kind::eIdentifier )
		astRequire( static_cast< expr::Identifier const & >( *stmt->getNumGroupsY() ).getVariable()->getName() == "numGroupsY" )
		astRequire( stmt->getNumGroupsZ()->getKind() == expr::Kind::eLiteral )
		astRequire( stmt->getPayload()->getKind() == expr::Kind::eIdentifier )
		astRequire( static_cast< expr::Identifier const & >( *stmt->getPayload() ).getVariable()->getName() == "payload" )
		astTestEnd()
	}

	void testPerPrimitiveDecl( test::TestCounts & testCounts )
	{
		astTestBegin( "testPerPrimitiveDecl" );
		stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		type::TypesCache typesCache;
		auto stmt = stmtCache.makePerPrimitiveDecl( typesCache.getInt32() );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt, ShaderStage::eVertex );

		astRequire( stmt->getKind() == stmt::Kind::ePerPrimitiveDecl )
		astCheck( stmt->getType()->getKind() == type::Kind::eInt32 )
		astTestEnd()
	}
}

astTestSuiteMain( TestASTStatements )
{
	astTestSuiteBegin()
	testPreprocExtension( testCounts );
	testPreprocVersion( testCounts );
	testAccelerationStructureDecl( testCounts );
	testBreak( testCounts );
	testBufferReferenceDecl( testCounts );
	testCombinedImageDecl( testCounts );
	testComment( testCounts );
	testCompound( testCounts );
	testConstantBufferDecl( testCounts );
	testContainer( testCounts );
	testContinue( testCounts );
	testDemote( testCounts );
	testDispatchMesh( testCounts );
	testDoWhile( testCounts );
	testElse( testCounts );
	testElseIf( testCounts );
	testElseIfElse( testCounts );
	testFor( testCounts );
	testFragmentLayout( testCounts );
	testFunctionDecl( testCounts );
	testEntryPointDecl( testCounts );
	testHitAttributeVariableDecl( testCounts );
	testIf( testCounts );
	testIgnoreIntersection( testCounts );
	testImageDecl( testCounts );
	testInOutBlendVariableDecl( testCounts );
	testInOutCallableDataVariableDecl( testCounts );
	testInOutRayPayloadVariableDecl( testCounts );
	testInOutStreamVariableDecl( testCounts );
	testInOutVariableDecl( testCounts );
	testInputComputeLayout( testCounts );
	testInputGeometryLayout( testCounts );
	testInputTessellationEvaluationLayout( testCounts );
	testOutputGeometryLayout( testCounts );
	testOutputMeshLayout( testCounts );
	testOutputTessellationControlLayout( testCounts );
	testPerPrimitiveDecl( testCounts );
	testPerVertexDecl( testCounts );
	testPushConstantsBufferDecl( testCounts );
	testReturn( testCounts );
	testSampledImageDecl( testCounts );
	testSamplerDecl( testCounts );
	testShaderBufferDecl( testCounts );
	testShaderStructBufferDecl( testCounts );
	testSimple( testCounts );
	testSpecialisationConstantDecl( testCounts );
	testStructureDecl( testCounts );
	testSwitch( testCounts );
	testTerminateInvocation( testCounts );
	testTerminateRay( testCounts );
	testVariableDecl( testCounts );
	testWhile( testCounts );
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTStatements )
