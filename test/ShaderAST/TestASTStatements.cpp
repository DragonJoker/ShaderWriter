#include "Common.hpp"

#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Visitors/CloneStmt.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/SpecialiseStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	std::string getStmtName( ast::stmt::Stmt const & stmt )
	{
		switch ( stmt.getKind() )
		{
		case ast::stmt::Kind::eSimple:
			return "Simple";
		case ast::stmt::Kind::eContainer:
			return "Container";
		case ast::stmt::Kind::eCompound:
			return "Compound";
		case ast::stmt::Kind::eComment:
			return "Comment";
		case ast::stmt::Kind::eVariableDecl:
			return "VariableDecl";
		case ast::stmt::Kind::ePerPrimitiveDecl:
			return "PerPrimitiveDecl";
		case ast::stmt::Kind::ePerVertexDecl:
			return "PerVertexDecl";
		case ast::stmt::Kind::eInOutVariableDecl:
			return "InOutVariableDecl";
		case ast::stmt::Kind::eSpecialisationConstantDecl:
			return "SpecialisationConstantDecl";
		case ast::stmt::Kind::eConstantBufferDecl:
			return "ConstantBufferDecl";
		case ast::stmt::Kind::ePushConstantsBufferDecl:
			return "PushConstantsBufferDecl";
		case ast::stmt::Kind::eShaderBufferDecl:
			return "ShaderBufferDecl";
		case ast::stmt::Kind::eShaderStructBufferDecl:
			return "ShaderStructBufferDecl";
		case ast::stmt::Kind::eSamplerDecl:
			return "SamplerDecl";
		case ast::stmt::Kind::eImageDecl:
			return "ImageDecl";
		case ast::stmt::Kind::eSampledImageDecl:
			return "SampledImageDecl";
		case ast::stmt::Kind::eCombinedImageDecl:
			return "CombinedImageDecl";
		case ast::stmt::Kind::eFunctionDecl:
			return "FunctionDecl";
		case ast::stmt::Kind::eStructureDecl:
			return "StructureDecl";
		case ast::stmt::Kind::eIf:
			return "If";
		case ast::stmt::Kind::eElse:
			return "Else";
		case ast::stmt::Kind::eElseIf:
			return "ElseIf";
		case ast::stmt::Kind::eWhile:
			return "While";
		case ast::stmt::Kind::eFor:
			return "For";
		case ast::stmt::Kind::eDoWhile:
			return "DoWhile";
		case ast::stmt::Kind::eSwitch:
			return "Switch";
		case ast::stmt::Kind::eSwitchCase:
			return "SwitchCase";
		case ast::stmt::Kind::eReturn:
			return "Return";
		case ast::stmt::Kind::eBreak:
			return "Break";
		case ast::stmt::Kind::eContinue:
			return "Continue";
		case ast::stmt::Kind::eDemote:
			return "Demote";
		case ast::stmt::Kind::eTerminateInvocation:
			return "TerminateInvocation";
		case ast::stmt::Kind::eInputGeometryLayout:
			return "InputGeometryLayout";
		case ast::stmt::Kind::eOutputGeometryLayout:
			return "OutputGeometryLayout";
		case ast::stmt::Kind::eInputComputeLayout:
			return "InputComputeLayout";
		case ast::stmt::Kind::eOutputMeshLayout:
			return "OutputMeshLayout";
		case ast::stmt::Kind::eFragmentLayout:
			return "FragmentLayout";
		case ast::stmt::Kind::eOutputTessellationControlLayout:
			return "OutputTessellationControlLayout";
		case ast::stmt::Kind::eInputTessellationEvaluationLayout:
			return "InputTessellationEvaluationLayout";
		case ast::stmt::Kind::eAccelerationStructureDecl:
			return "AccelerationStructureDecl";
		case ast::stmt::Kind::eInOutRayPayloadVariableDecl:
			return "InOutRayPayloadVariableDecl";
		case ast::stmt::Kind::eHitAttributeVariableDecl:
			return "HitAttributeVariableDecl";
		case ast::stmt::Kind::eInOutCallableDataVariableDecl:
			return "InOutCallableDataVariableDecl";
		case ast::stmt::Kind::eBufferReferenceDecl:
			return "BufferReferenceDecl";
		case ast::stmt::Kind::eTerminateRay:
			return "TerminateRay";
		case ast::stmt::Kind::eIgnoreIntersection:
			return "IgnoreIntersection";
		case ast::stmt::Kind::eDispatchMesh:
			return "DispatchMesh";
		case ast::stmt::Kind::ePreprocExtension:
			return "PreprocExtension";
		case ast::stmt::Kind::ePreprocVersion:
			return "PreprocVersion";
		default:
			return "Unknown";
		}
	}

	ast::stmt::ContainerPtr makeContainer( ast::expr::ExprCache & exprCache
		, ast::stmt::Stmt const & stmt )
	{
		auto & stmtCache = stmt.getStmtCache();
		if ( stmt.getKind() == ast::stmt::Kind::eContainer )
		{
			return ast::StmtCloner::submit( stmtCache, exprCache, static_cast< ast::stmt::Container const & >( stmt ) );
		}

		auto container = stmtCache.makeContainer();
		container->addStmt( ast::StmtCloner::submit( stmtCache, exprCache, &stmt ) );
		return container;
	}

	void checkStmtDependant( test::TestCounts & testCounts
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Stmt const & stmt )
	{
		auto & stmtCache = stmt.getStmtCache();
		testCounts << "Stmt" << getStmtName( stmt ) << ":\n" << ast::debug::displayStatements( stmt ) << test::endl;
		ast::SpecialisationInfo spec{};
		ast::SpecConstantData specData{};
		specData.info.location = 1u;
		specData.info.type = typesCache.getInt32();
		specData.data.resize( 4u, 0u );
		spec.data.push_back( specData );
		{
			auto container = makeContainer( exprCache, stmt );
			ast::SSAData data{ testCounts.nextVarId, 0u };
			container = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, false );
			container = ast::resolveConstants( stmtCache, exprCache, typesCache, *container );
			container = ast::simplify( stmtCache, exprCache, typesCache, *container );
			container = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, spec );
		}
		{
			auto container = makeContainer( exprCache, stmt );
			ast::SSAData data{ testCounts.nextVarId, 0u };
			container = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, true );
			container = ast::resolveConstants( stmtCache, exprCache, typesCache, *container );
			container = ast::simplify( stmtCache, exprCache, typesCache, *container );
			container = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, spec );
		}
	}

	void testSimple( test::TestCounts & testCounts )
	{
		testBegin( "testSimple" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto stmt = stmtCache.makeSimple( exprCache.makeInit( std::move( lhs ), std::move( rhs ) ) );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eSimple )
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eInit )
			
		stmt = stmtCache.makeSimple( nullptr );
		ast::StmtCloner::submit( stmtCache, exprCache, stmt.get() );
		testEnd()
	}

	void testContainer( test::TestCounts & testCounts )
	{
		testBegin( "testContainer" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeContainer();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eContainer )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeContainer();
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			ast::StmtCloner::submit( stmtCache, exprCache, stmt.get() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eContainer )
			check( stmt->size() == 2u )
			check( stmt->back() )
		}
		testEnd()
	}

	void testCompound( test::TestCounts & testCounts )
	{
		testBegin( "testCompound" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeCompound();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eCompound )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeCompound();
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eCompound )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testComment( test::TestCounts & testCounts )
	{
		testBegin( "testComment" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeComment( "Coin glop miaou !!" );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eComment )
		require( stmt->getText() == "Coin glop miaou !!" )
		testEnd()
	}

	void testVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs" ) );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eVariableDecl )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "lhs" )
		testEnd()
	}

	void testPerVertexDecl( test::TestCounts & testCounts )
	{
		testBegin( "testPerVertexDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;

		for ( uint32_t source = 0u; source <= uint32_t( ast::stmt::PerVertexDecl::Source::eMeshOutput ); ++source )
		{
			auto stmt = stmtCache.makePerVertexDecl( ast::stmt::PerVertexDecl::Source( source )
				, typesCache.getInt32() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::ePerVertexDecl )
			require( stmt->getSource() == ast::stmt::PerVertexDecl::Source( source ) )
			check( stmt->getType()->getKind() == ast::type::Kind::eInt32 )
		}
		testEnd()
	}

	void testInOutVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto stmt = stmtCache.makeInOutVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput ), 1u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl )
			check( stmt->getLocation() == 1u )
			check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
			check( stmt->getVariable()->getName() == "lhs" )
		}
		{
			auto stmt = stmtCache.makeInOutVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", ast::var::Flag::eShaderConstant ), 1u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl )
			check( stmt->getLocation() == 1u )
			check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
			check( stmt->getVariable()->getName() == "lhs" )
		}
		{
			auto stmt = stmtCache.makeInOutVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", ast::var::Flag::ePushConstant ), 1u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl )
			check( stmt->getLocation() == 1u )
			check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
			check( stmt->getVariable()->getName() == "lhs" )
		}
		testEnd()
	}

	void testInOutStreamVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutStreamVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInOutStreamVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eGeometryStream )
			, 1u
			, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl )
		check( stmt->getLocation() == 1u )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "lhs" )
		check( stmt->getVariable()->isGeometryStream() )
		check( stmt->getStreamIndex() == 2u )
		testEnd()
	}

	void testInOutBlendVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutBlendVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInOutBlendVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eBlendIndex )
			, 1u
			, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl )
		check( stmt->getLocation() == 1u )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "lhs" )
		check( stmt->getVariable()->isBlendIndex() )
		check( stmt->getBlendIndex() == 2u )
		testEnd()
	}

	void testSpecialisationConstantDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSpecialisationConstantDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeSpecialisationConstantDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eBlendIndex )
			, 1u
			, exprCache.makeLiteral( typesCache, 18 ) );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eSpecialisationConstantDecl )
		check( stmt->getLocation() == 1u )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "lhs" )
		check( stmt->getValue()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getValue()->getLiteralType() == ast::expr::LiteralType::eInt32 )
		check( stmt->getValue()->getValue< ast::expr::LiteralType::eInt32 >() == 18 )
		testEnd()
	}

	void testConstantBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testConstantBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl )
			check( stmt->getBindingPoint() == 1u )
			check( stmt->getDescriptorSet() == 2u )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl )
			check( stmt->getBindingPoint() == 1u )
			check( stmt->getDescriptorSet() == 2u )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testPushConstantsBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testPushConstantsBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makePushConstantsBufferDecl( "Buffer", ast::type::MemoryLayout::eC );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::ePushConstantsBufferDecl )
			check( stmt->getMemoryLayout() == ast::type::MemoryLayout::eC )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makePushConstantsBufferDecl( "Buffer", ast::type::MemoryLayout::eC );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::ePushConstantsBufferDecl )
			check( stmt->getMemoryLayout() == ast::type::MemoryLayout::eC )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testShaderBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testShaderBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeShaderBufferDecl( typesCache, "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u, testCounts.getNextVarId() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl )
			check( stmt->getBindingPoint() == 1u )
			check( stmt->getDescriptorSet() == 2u )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeShaderBufferDecl( typesCache, "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u, testCounts.getNextVarId() );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl )
			check( stmt->getBindingPoint() == 1u )
			check( stmt->getDescriptorSet() == 2u )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testShaderStructBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testShaderStructBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto baseType = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BaseType" );
			auto array = typesCache.getArray( baseType );
			auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( testCounts.getNextVarId(), type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( testCounts.getNextVarId(), type, "Inst", ast::var::Flag::eUniform );
			auto stmt = stmtCache.makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl )
			check( stmt->getBindingPoint() == 1u )
			check( stmt->getDescriptorSet() == 2u )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto baseType = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BaseType" );
			baseType->declMember( "i", typesCache.getInt32() );
			baseType->declMember( "j", typesCache.getInt32() );
			auto array = typesCache.getArray( baseType );
			auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( testCounts.getNextVarId(), type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( testCounts.getNextVarId(), type, "Inst", ast::var::Flag::eUniform );
			auto stmt = stmtCache.makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl )
			check( stmt->getBindingPoint() == 1u )
			check( stmt->getDescriptorSet() == 2u )
		}
		testEnd()
	}

	void testSamplerDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSamplerDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeSamplerDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getSampler(), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eSamplerDecl )
		check( stmt->getBindingPoint() == 1u )
		check( stmt->getDescriptorSet() == 2u )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eSampler )
		check( stmt->getVariable()->getName() == "lhs" )
		testEnd()
	}

	void testImageDecl( test::TestCounts & testCounts )
	{
		testBegin( "testImageDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		ast::type::ImageConfiguration config{};
		auto stmt = stmtCache.makeImageDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getImage( config ), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eImageDecl )
		check( stmt->getBindingPoint() == 1u )
		check( stmt->getDescriptorSet() == 2u )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eImage )
		check( stmt->getVariable()->getName() == "lhs" )
		testEnd()
	}

	void testSampledImageDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSampledImageDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		ast::type::ImageConfiguration config{};
		auto stmt = stmtCache.makeSampledImageDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getSampledImage( config ), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eSampledImageDecl )
		check( stmt->getBindingPoint() == 1u )
		check( stmt->getDescriptorSet() == 2u )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eSampledImage )
		check( stmt->getVariable()->getName() == "lhs" )
		testEnd()
	}

	void testCombinedImageDecl( test::TestCounts & testCounts )
	{
		testBegin( "testCombinedImageDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		ast::type::ImageConfiguration config{};
		auto stmt = stmtCache.makeCombinedImageDecl( ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getCombinedImage( config, true ), "lhs" ), 1u, 2u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eCombinedImageDecl )
		check( stmt->getBindingPoint() == 1u )
		check( stmt->getDescriptorSet() == 2u )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eCombinedImage )
		check( stmt->getVariable()->getName() == "lhs" )
		testEnd()
	}

	void testFunctionDecl( test::TestCounts & testCounts )
	{
		testBegin( "testFunctionDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), {} ), "foo" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "foo" )
			check( stmt->getType()->empty() )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) } ), "foo" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "foo" )
			check( stmt->getType()->size() == 1u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ), ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) } ), "foo" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "foo" )
			check( stmt->getType()->size() == 2u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), {} ), "foo" ) );
			stmt->addStmt( stmtCache.makeReturn( exprCache.makeLiteral( typesCache, 10 ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "foo" )
			check( stmt->getType()->empty() )
			check( stmt->size() == 1u )
			check( !stmt->isPatchRoutine() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) } ), "foo" ) );
			stmt->addStmt( stmtCache.makeReturn(
				exprCache.makeAdd( typesCache.getInt32(),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 0u ) ),
					exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "foo" )
			check( stmt->getType()->size() == 1u )
			check( stmt->size() == 1u )
			check( !stmt->isPatchRoutine() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ), ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) } ), "foo" ) );
			stmt->addStmt( stmtCache.makeReturn(
				exprCache.makeAdd( typesCache.getInt32(),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 0u ) ),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 1u ) ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "foo" )
			check( stmt->getType()->size() == 2u )
			check( stmt->size() == 1u )
			check( !stmt->isPatchRoutine() )
		}
		testEnd()
	}

	void testEntryPointDecl( test::TestCounts & testCounts )
	{
		testBegin( "testEntryPointDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto inType = ast::type::makeGeometryInputType( typesCache.getVoid(), ast::type::InputLayout::eTriangleList );
			auto outType = ast::type::makeGeometryOutputType( typesCache.getVoid(), ast::type::OutputLayout::eTriangleStrip, 3u );
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { ast::var::makeVariable( testCounts.getNextVarId(), inType, "in" )
					, ast::var::makeVariable( testCounts.getNextVarId(), outType, "out" ) } )
				, "mainGeom" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "mainGeom" )
			check( stmt->getType()->size() == 2u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			auto inType = ast::type::makeTessellationControlInputType( typesCache.getVoid(), 3u );
			auto outType = ast::type::makeTessellationControlOutputType( typesCache.getVoid(), ast::type::PatchDomain::eTriangles, ast::type::Partitioning::eEqual, ast::type::OutputTopology::eTriangle, ast::type::PrimitiveOrdering::eCCW, 3u );
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { ast::var::makeVariable( testCounts.getNextVarId(), inType, "in" )
					, ast::var::makeVariable( testCounts.getNextVarId(), outType, "out" ) } )
				, "mainTesc" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "mainTesc" )
			check( stmt->getType()->size() == 2u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			auto inType = ast::type::makeTessellationEvaluationInputType( typesCache.getVoid(), ast::type::PatchDomain::eTriangles, ast::type::Partitioning::eEqual, ast::type::PrimitiveOrdering::eCCW, 3u );
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { ast::var::makeVariable( testCounts.getNextVarId(), inType, "in" ) } )
				, "mainTese" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "mainTese" )
			check( stmt->getType()->size() == 1u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			auto inType = ast::type::makeFragmentInputType( typesCache.getVoid(), ast::FragmentOrigin::eLowerLeft, ast::FragmentCenter::eHalfPixel );
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { ast::var::makeVariable( testCounts.getNextVarId(), inType, "in" ) } )
				, "mainFrag" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "mainFrag" )
			check( stmt->getType()->size() == 1u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			auto inType = ast::type::makeComputeInputType( typesCache.getVoid(), 4u, 8u, 16u );
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { ast::var::makeVariable( testCounts.getNextVarId(), inType, "in" ) } )
				, "mainComp" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "mainComp" )
			check( stmt->getType()->size() == 1u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		{
			auto outVertType = ast::type::makeMeshVertexOutputType( typesCache.getVoid(), 4u );
			auto outPrimType = ast::type::makeMeshPrimitiveOutputType( typesCache.getVoid(), ast::type::OutputTopology::eTriangle, 2u );
			auto stmt = stmtCache.makeFunctionDecl( ast::var::makeFunction( testCounts.getNextVarId(), typesCache.getFunction( typesCache.getInt32()
				, { ast::var::makeVariable( testCounts.getNextVarId(), outVertType, "vert" )
					, ast::var::makeVariable( testCounts.getNextVarId(), outPrimType, "prim" ) } )
				, "mainMesh" ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl )
			check( stmt->getName() == "mainMesh" )
			check( stmt->getType()->size() == 2u )
			check( stmt->empty() )
			check( !stmt->isPatchRoutine() )
		}
		testEnd()
	}

	void testStructureDecl( test::TestCounts & testCounts )
	{
		testBegin( "testStructureDecl" );
		for ( auto layout = 0u; layout <= uint32_t( ast::type::MemoryLayout::eShaderRecord ); ++layout )
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto type = typesCache.getStruct( ast::type::MemoryLayout( layout ), "MyStruct" );
			auto stmt = stmtCache.makeStructureDecl( type );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl )
			check( stmt->getType()->getName() == "MyStruct" )
			check( stmt->getType()->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd140, "MyStruct" );
			type->declMember( "i", typesCache.getInt32() );
			type->declMember( "j", typesCache.getInt32() );
			auto stmt = stmtCache.makeStructureDecl( type );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl )
			check( stmt->getType()->getName() == "MyStruct" )
			check( stmt->getType()->size() == 2u )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto type = typesCache.getIOStruct( "MyStruct", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput );
			type->declMember( "i", typesCache.getInt32(), 0u );
			type->declMember( "j", typesCache.getInt32(), 1u );
			type->declMember( ast::Builtin::eGlobalInvocationID, ast::type::Kind::eInt32, ast::type::NotArray );
			auto stmt = stmtCache.makeStructureDecl( type );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl )
			check( stmt->getType()->getName() == "MyStructCompInput" )
			check( stmt->getType()->size() == 3u )
		}
		testEnd()
	}

	void testIf( test::TestCounts & testCounts )
	{
		testBegin( "testIf" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eIf )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eIf )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testElse( test::TestCounts & testCounts )
	{
		testBegin( "testElse" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			auto elseStmt = stmt->createElse();
			checkThrow( stmt->createElse() );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( elseStmt->getKind() == ast::stmt::Kind::eElse )
			check( elseStmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseStmt = stmt->createElse();
			checkThrow( stmt->createElse() );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( elseStmt->getKind() == ast::stmt::Kind::eElse )
			check( elseStmt->size() == 2u )
		}
		testEnd()
	}

	void testElseIf( test::TestCounts & testCounts )
	{
		testBegin( "testElseIf" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf )
			check( elseIfStmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf )
			check( elseIfStmt->size() == 2u )
		}
		testEnd()
	}

	void testElseIfElse( test::TestCounts & testCounts )
	{
		testBegin( "testElseIf" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			stmt->createElse();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );
		}
		testEnd()
	}

	void testWhile( test::TestCounts & testCounts )
	{
		testBegin( "testWhile" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eWhile )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eWhile )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testFor( test::TestCounts & testCounts )
	{
		testBegin( "testFor" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto k = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeFor( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 0 ) )
				, exprCache.makeLessEqual( typesCache, exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) )
				, exprCache.makePreIncrement( exprCache.makeIdentifier( typesCache, k ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFor )
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit )
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt32 )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement )
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt32 )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto k = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeFor( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 0 ) )
				, exprCache.makeLessEqual( typesCache, exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) )
				, exprCache.makePreIncrement( exprCache.makeIdentifier( typesCache, k ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eFor )
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit )
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt32 )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement )
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt32 )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testDoWhile( test::TestCounts & testCounts )
	{
		testBegin( "testDoWhile" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeDoWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eDoWhile )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeDoWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eDoWhile )
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier )
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testSwitch( test::TestCounts & testCounts )
	{
		testBegin( "testSwitch" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eSwitch )
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest )
			check( stmt->empty() )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			stmt->createDefault();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eSwitch )
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest )
			check( stmt->size() == 2u )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "j" );
			auto k = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			auto caseStmt = stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto defaultStmt = stmt->createDefault();
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eSwitch )
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest )
			check( stmt->size() == 2u )
		}
		testEnd()
	}

	void testReturn( test::TestCounts & testCounts )
	{
		testBegin( "testReturn" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeReturn();
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eReturn )
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeReturn( exprCache.makeLiteral( typesCache, 10 ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eReturn )
			check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral )
		}
		testEnd()
	}

	void testDemote( test::TestCounts & testCounts )
	{
		testBegin( "testDemote" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeDemote();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eDemote )
		testEnd()
	}

	void testTerminateInvocation( test::TestCounts & testCounts )
	{
		testBegin( "testTerminateInvocation" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeTerminateInvocation();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eTerminateInvocation )
		testEnd()
	}

	void testInputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputGeometryLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputGeometryLayout( typesCache.getVoid()
			, ast::type::InputLayout::eLineStripWithAdjacency );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eInputGeometryLayout )
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid )
		check( stmt->getLayout() == ast::type::InputLayout::eLineStripWithAdjacency )
		testEnd()
	}

	void testOutputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputGeometryLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputGeometryLayout( typesCache.getVoid()
			, ast::type::OutputLayout::eTriangleStrip
			, 15u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eOutputGeometryLayout )
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid )
		check( stmt->getLayout() == ast::type::OutputLayout::eTriangleStrip )
		check( stmt->getPrimCount() == 15u )
		testEnd()
	}

	void testOutputMeshLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputMeshLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputMeshLayout( typesCache.getVoid()
			, ast::type::OutputTopology::eTriangle
			, 64u
			, 126u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eOutputMeshLayout )
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid )
		check( stmt->getTopology() == ast::type::OutputTopology::eTriangle )
		check( stmt->getMaxVertices() == 64u )
		check( stmt->getMaxPrimitives() == 126u )
		testEnd()
	}

	void testInputComputeLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputComputeLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputComputeLayout( typesCache.getVoid(), 16, 32, 64 );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eInputComputeLayout )
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid )
		check( stmt->getWorkGroupsX() == 16u )
		check( stmt->getWorkGroupsY() == 32u )
		check( stmt->getWorkGroupsZ() == 64u )
		testEnd()
	}

	void testPreprocExtension( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocExtension" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;

		for ( uint32_t status = 0u; status <= uint32_t( ast::stmt::PreprocExtension::ExtStatus::eRequired ); ++status )
		{
			auto stmt = stmtCache.makePreprocExtension( "GL_arb_coin", ast::stmt::PreprocExtension::ExtStatus( status ) );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::ePreprocExtension )
			check( stmt->getName() == "GL_arb_coin" )
			check( stmt->getStatus() == ast::stmt::PreprocExtension::ExtStatus( status ) )
		}
		testEnd()
	}

	void testPreprocVersion( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocVersion" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocVersion( "430 core" );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::ePreprocVersion )
		check( stmt->getName() == "430 core" )
		testEnd()
	}

	void testFragmentLayout( test::TestCounts & testCounts )
	{
		testBegin( "testFragmentLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeFragmentLayout( typesCache.getVoid()
				, ast::FragmentOrigin::eLowerLeft
			, ast::FragmentCenter::eCenterInteger );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eFragmentLayout )
		check( stmt->getFragmentCenter() == ast::FragmentCenter::eCenterInteger )
		check( stmt->getFragmentOrigin() == ast::FragmentOrigin::eLowerLeft )
		testEnd()
	}

	void testOutputTessellationControlLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputTessellationControlLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputTessellationControlLayout( typesCache.getVoid()
			, ast::type::PatchDomain::eQuads
			, ast::type::Partitioning::eFractionalEven
			, ast::type::OutputTopology::eQuad
			, ast::type::PrimitiveOrdering::eCCW
			, 4u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eOutputTessellationControlLayout )
		check( stmt->getDomain() == ast::type::PatchDomain::eQuads )
		check( stmt->getPartitioning() == ast::type::Partitioning::eFractionalEven )
		check( stmt->getTopology() == ast::type::OutputTopology::eQuad )
		check( stmt->getPrimitiveOrdering() == ast::type::PrimitiveOrdering::eCCW )
		check( stmt->getOutputVertices() == 4u )
		testEnd()
	}

	void testInputTessellationEvaluationLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputTessellationEvaluationLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputTessellationEvaluationLayout( typesCache.getVoid()
			, ast::type::PatchDomain::eQuads
			, ast::type::Partitioning::eFractionalEven
			, ast::type::PrimitiveOrdering::eCCW );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eInputTessellationEvaluationLayout )
		check( stmt->getDomain() == ast::type::PatchDomain::eQuads )
		check( stmt->getPartitioning() == ast::type::Partitioning::eFractionalEven )
		check( stmt->getPrimitiveOrdering() == ast::type::PrimitiveOrdering::eCCW )
		testEnd()
	}

	void testAccelerationStructureDecl( test::TestCounts & testCounts )
	{
		testBegin( "testAccelerationStructureDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeAccelerationStructureDecl( i
			, 18u
			, 52u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eAccelerationStructureDecl )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "i" )
		check( stmt->getBindingPoint() == 18u )
		check( stmt->getDescriptorSet() == 52u )
		testEnd()
	}

	void testInOutRayPayloadVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutRayPayloadVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeInOutRayPayloadVariableDecl( i
			, 18u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eInOutRayPayloadVariableDecl )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "i" )
		check( stmt->getLocation() == 18u )
		testEnd()
	}

	void testHitAttributeVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testHitAttributeVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeHitAttributeVariableDecl( i );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eHitAttributeVariableDecl )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "i" )
		testEnd()
	}

	void testInOutCallableDataVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutCallableDataVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeInOutCallableDataVariableDecl( i
			, 18u );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eInOutCallableDataVariableDecl )
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 )
		check( stmt->getVariable()->getName() == "i" )
		check( stmt->getLocation() == 18u )
		testEnd()
	}

	void testBufferReferenceDecl( test::TestCounts & testCounts )
	{
		testBegin( "testBufferReferenceDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeBufferReferenceDecl( typesCache.getInt32() );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eBufferReferenceDecl )
		check( stmt->getType()->getKind() == ast::type::Kind::eInt32 )
		testEnd()
	}

	void testTerminateRay( test::TestCounts & testCounts )
	{
		testBegin( "testTerminateRay" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeTerminateRay();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eTerminateRay )
		testEnd()
	}

	void testIgnoreIntersection( test::TestCounts & testCounts )
	{
		testBegin( "testIgnoreIntersection" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeIgnoreIntersection();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eIgnoreIntersection )
		testEnd()
	}

	void testBreak( test::TestCounts & testCounts )
	{
		testBegin( "testBreak" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto stmt = stmtCache.makeBreak( true );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eBreak );
			require( stmt->isSwitchCaseBreak() );
		}
		{
			auto stmt = stmtCache.makeBreak( false );
			checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

			require( stmt->getKind() == ast::stmt::Kind::eBreak )
			require( !stmt->isSwitchCaseBreak() );
		}
		testEnd()
	}

	void testContinue( test::TestCounts & testCounts )
	{
		testBegin( "testContinue" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeContinue();
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eContinue )
		testEnd()
	}

	void testDispatchMesh( test::TestCounts & testCounts )
	{
		testBegin( "testDispatchMesh" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto numGroupsX = exprCache.makeLiteral( typesCache, 16u );
		auto numGroupsY = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getBool(), "numGroupsY" ) );
		auto numGroupsZ = exprCache.makeLiteral( typesCache, 32u );
		auto payload = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( testCounts.getNextVarId(), typesCache.getTaskPayload( typesCache.getUInt32() ), "payload" ) );
		auto stmt = stmtCache.makeDispatchMesh( std::move( numGroupsX ), std::move( numGroupsY ), std::move( numGroupsZ ), std::move( payload ) );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::eDispatchMesh )
		require( stmt->getNumGroupsX()->getKind() == ast::expr::Kind::eLiteral )
		require( stmt->getNumGroupsY()->getKind() == ast::expr::Kind::eIdentifier )
		require( static_cast< ast::expr::Identifier const & >( *stmt->getNumGroupsY() ).getVariable()->getName() == "numGroupsY" )
		require( stmt->getNumGroupsZ()->getKind() == ast::expr::Kind::eLiteral )
		require( stmt->getPayload()->getKind() == ast::expr::Kind::eIdentifier )
		require( static_cast< ast::expr::Identifier const & >( *stmt->getPayload() ).getVariable()->getName() == "payload" )
		testEnd()
	}

	void testPerPrimitiveDecl( test::TestCounts & testCounts )
	{
		testBegin( "testPerPrimitiveDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePerPrimitiveDecl( typesCache.getInt32() );
		checkStmtDependant( testCounts, exprCache, typesCache, *stmt );

		require( stmt->getKind() == ast::stmt::Kind::ePerPrimitiveDecl )
		check( stmt->getType()->getKind() == ast::type::Kind::eInt32 )
		testEnd()
	}
}

testSuiteMain( TestASTStatements )
{
	testSuiteBegin()
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
	testSuiteEnd()
}

testSuiteLaunch( TestASTStatements )
