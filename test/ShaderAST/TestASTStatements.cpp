#include "Common.hpp"

#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	void testSimple( test::TestCounts & testCounts )
	{
		testBegin( "testSimple" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto lhs = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		auto rhs = exprCache.makeLiteral( typesCache, 10 );
		auto stmt = stmtCache.makeSimple( exprCache.makeInit( std::move( lhs ), std::move( rhs ) ) );
		testCounts << "StmtSimple:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSimple );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eInit );
		testEnd();
	}

	void testContainer( test::TestCounts & testCounts )
	{
		testBegin( "testContainer" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeContainer();
			testCounts << "StmtContainer (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeContainer();
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			testCounts << "StmtContainer:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testCompound( test::TestCounts & testCounts )
	{
		testBegin( "testCompound" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeCompound();
			testCounts << "StmtCompound (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeCompound();
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			testCounts << "StmtCompound:" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testComment( test::TestCounts & testCounts )
	{
		testBegin( "testComment" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeComment( "Coin glop miaou !!" );
		testCounts << "StmtComment:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eComment );
		require( stmt->getText() == "Coin glop miaou !!" );
		testEnd();
	}

	void testVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs" ) );
		testCounts << "StmtVariableDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testPerVertexDecl( test::TestCounts & testCounts )
	{
		testBegin( "testPerVertexDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePerVertexDecl( ast::stmt::PerVertexDecl::Source::eTessellationControlInput
			, typesCache.getInt32() );
		testCounts << "StmtPerVertexDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePerVertexDecl );
		require( stmt->getSource() == ast::stmt::PerVertexDecl::Source::eTessellationControlInput );
		check( stmt->getType()->getKind() == ast::type::Kind::eInt32 );
		testEnd();
	}

	void testInOutVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInOutVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput ), 1u );
		testCounts << "StmtInOutVariableDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testInOutStreamVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutStreamVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInOutStreamVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eGeometryStream )
			, 1u
			, 2u );
		testCounts << "makeInOutStreamVariableDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "lhs" );
		check( stmt->getVariable()->isGeometryStream() );
		check( stmt->getStreamIndex() == 2u );
		testEnd();
	}

	void testInOutBlendVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutBlendVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInOutBlendVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eBlendIndex )
			, 1u
			, 2u );
		testCounts << "StmtInOutBlendVariableDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "lhs" );
		check( stmt->getVariable()->isBlendIndex() );
		check( stmt->getBlendIndex() == 2u );
		testEnd();
	}

	void testSpecialisationConstantDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSpecialisationConstantDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeSpecialisationConstantDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eBlendIndex )
			, 1u
			, exprCache.makeLiteral( typesCache, 18 ) );
		testCounts << "StmtSpecialisationConstantDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSpecialisationConstantDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "lhs" );
		check( stmt->getValue()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getValue()->getLiteralType() == ast::expr::LiteralType::eInt32 );
		check( stmt->getValue()->getValue< ast::expr::LiteralType::eInt32 >() == 18 );
		testEnd();
	}

	void testConstantBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testConstantBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			testCounts << "StmtConstantBufferDecl (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) ) );
			testCounts << "StmtConstantBufferDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testPushConstantsBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testPushConstantsBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makePushConstantsBufferDecl( "Buffer", ast::type::MemoryLayout::eC );
			testCounts << "StmtPushConstantsBufferDecl (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::ePushConstantsBufferDecl );
			check( stmt->getMemoryLayout() == ast::type::MemoryLayout::eC );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makePushConstantsBufferDecl( "Buffer", ast::type::MemoryLayout::eC );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) ) );
			testCounts << "StmtPushConstantsBufferDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::ePushConstantsBufferDecl );
			check( stmt->getMemoryLayout() == ast::type::MemoryLayout::eC );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testShaderBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testShaderBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeShaderBufferDecl( typesCache, "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u, ++testCounts.nextVarId );
			testCounts << "StmtShaderBufferDecl (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeShaderBufferDecl( typesCache, "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u, ++testCounts.nextVarId );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) ) );
			stmt->add( stmtCache.makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) ) );
			testCounts << "StmtShaderBufferDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testShaderStructBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testShaderStructBufferDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto baseType = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BaseType" );
			auto array = typesCache.getArray( baseType );
			auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( ++testCounts.nextVarId, type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( ++testCounts.nextVarId, type, "Inst", ast::var::Flag::eUniform );
			auto stmt = stmtCache.makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			testCounts << "StmtShaderStructBufferDecl (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto baseType = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BaseType" );
			baseType->declMember( "i", typesCache.getInt32() );
			baseType->declMember( "j", typesCache.getInt32() );
			auto array = typesCache.getArray( baseType );
			auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( ++testCounts.nextVarId, type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( ++testCounts.nextVarId, type, "Inst", ast::var::Flag::eUniform );
			auto stmt = stmtCache.makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			testCounts << "StmtShaderStructBufferDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
		}
		testEnd();
	}

	void testSamplerDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSamplerDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeSamplerDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getSampler(), "lhs" ), 1u, 2u );
		testCounts << "StmtSamplerDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSamplerDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eSampler );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testImageDecl( test::TestCounts & testCounts )
	{
		testBegin( "testImageDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		ast::type::ImageConfiguration config{};
		auto stmt = stmtCache.makeImageDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getImage( config ), "lhs" ), 1u, 2u );
		testCounts << "StmtImageDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eImageDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eImage );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testSampledImageDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSampledImageDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		ast::type::ImageConfiguration config{};
		auto stmt = stmtCache.makeSampledImageDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getSampledImage( config ), "lhs" ), 1u, 2u );
		testCounts << "StmtSampledImageDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSampledImageDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eSampledImage );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testCombinedImageDecl( test::TestCounts & testCounts )
	{
		testBegin( "testCombinedImageDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		ast::type::ImageConfiguration config{};
		auto stmt = stmtCache.makeCombinedImageDecl( ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getCombinedImage( config, true ), "lhs" ), 1u, 2u );
		testCounts << "StmtTextureDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eCombinedImageDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eCombinedImage );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testFunctionDecl( test::TestCounts & testCounts )
	{
		testBegin( "testFunctionDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( typesCache.getFunction( typesCache.getInt32(), {} ), "foo" );
			testCounts << "StmtFunctionDecl (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->empty() );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) } ), "foo" );
			testCounts << "StmtFunctionDecl (empty body):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->size() == 1u );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ), ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) } ), "foo" );
			testCounts << "StmtFunctionDecl (empty body):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->size() == 2u );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( typesCache.getFunction( typesCache.getInt32(), {} ), "foo" );
			stmt->addStmt( stmtCache.makeReturn( exprCache.makeLiteral( typesCache, 10 ) ) );
			testCounts << "StmtFunctionDecl (empty parameters list):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->empty() );
			check( stmt->size() == 1u );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) } ), "foo" );
			stmt->addStmt( stmtCache.makeReturn(
				exprCache.makeAdd( typesCache.getInt32(),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 0u ) ),
					exprCache.makeLiteral( typesCache, 10 ) ) ) );
			testCounts << "StmtFunctionDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->size() == 1u );
			check( stmt->size() == 1u );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeFunctionDecl( typesCache.getFunction( typesCache.getInt32(), { ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ), ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) } ), "foo" );
			stmt->addStmt( stmtCache.makeReturn(
				exprCache.makeAdd( typesCache.getInt32(),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 0u ) ),
					exprCache.makeIdentifier( typesCache, *( stmt->getType()->begin() + 1u ) ) ) ) );
			testCounts << "StmtFunctionDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->size() == 2u );
			check( stmt->size() == 1u );
		}
		testEnd();
	}

	void testStructureDecl( test::TestCounts & testCounts )
	{
		testBegin( "testStructureDecl" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd140, "MyStruct" );
			auto stmt = stmtCache.makeStructureDecl( type );
			testCounts << "StmtStructureDecl (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl );
			check( stmt->getType()->getName() == "MyStruct" );
			check( stmt->getType()->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto type = typesCache.getStruct( ast::type::MemoryLayout::eStd140, "MyStruct" );
			type->declMember( "i", typesCache.getInt32() );
			type->declMember( "j", typesCache.getInt32() );
			auto stmt = stmtCache.makeStructureDecl( type );
			testCounts << "StmtStructureDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl );
			check( stmt->getType()->getName() == "MyStruct" );
			check( stmt->getType()->size() == 2u );
		}
		testEnd();
	}

	void testIf( test::TestCounts & testCounts )
	{
		testBegin( "testIf" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			testCounts << "StmtIf (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			testCounts << "StmtIf:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testElse( test::TestCounts & testCounts )
	{
		testBegin( "testElse" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			auto elseStmt = stmt->createElse();
			testCounts << "StmtElse (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			testCounts << "StmtElse:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->size() == 2u );
		}
		testEnd();
	}

	void testElseIf( test::TestCounts & testCounts )
	{
		testBegin( "testElseIf" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "l" ) ) );
			testCounts << "StmtElseIf (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			testCounts << "StmtElseIf:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->size() == 2u );
		}
		testEnd();
	}

	void testElseIfElse( test::TestCounts & testCounts )
	{
		testBegin( "testElseIf" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "l" ) ) );
			stmt->createElse();
			testCounts << "StmtElse (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" );
			auto stmt = stmtCache.makeIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseIfStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, i ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			elseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			testCounts << "StmtElse:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;
		}
		testEnd();
	}

	void testWhile( test::TestCounts & testCounts )
	{
		testBegin( "testWhile" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			testCounts << "StmtWhile (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			testCounts << "StmtWhile:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testFor( test::TestCounts & testCounts )
	{
		testBegin( "testFor" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto k = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeFor( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 0 ) )
				, exprCache.makeLessEqual( typesCache, exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) )
				, exprCache.makePreIncrement( exprCache.makeIdentifier( typesCache, k ) ) );
			testCounts << "StmtFor (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) );
			auto k = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeFor( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 0 ) )
				, exprCache.makeLessEqual( typesCache, exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) )
				, exprCache.makePreIncrement( exprCache.makeIdentifier( typesCache, k ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			testCounts << "StmtFor:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testDoWhile( test::TestCounts & testCounts )
	{
		testBegin( "testDoWhile" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeDoWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			testCounts << "StmtDoWhile (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" ) );
			auto j = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" ) );
			auto stmt = stmtCache.makeDoWhile( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "k" ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( i ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			stmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( std::move( j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			testCounts << "StmtDoWhile:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testSwitch( test::TestCounts & testCounts )
	{
		testBegin( "testSwitch" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			testCounts << "StmtSwitch (empty):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->empty() );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			stmt->createDefault();
			testCounts << "StmtSwitch (empty cases):\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->size() == 2u );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "j" );
			auto k = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "k" );
			auto stmt = stmtCache.makeSwitch( exprCache.makeSwitchTest( exprCache.makeIdentifier( typesCache, i ) ) );
			auto caseStmt = stmt->createCase( exprCache.makeSwitchCase( exprCache.makeLiteral( typesCache, 10 ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			caseStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			auto defaultStmt = stmt->createDefault();
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, k ), exprCache.makeLiteral( typesCache, 10 ) ) ) );
			defaultStmt->addStmt( stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( typesCache, j ), exprCache.makeLiteral( typesCache, 20 ) ) ) );
			testCounts << "StmtSwitch:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testReturn( test::TestCounts & testCounts )
	{
		testBegin( "testReturn" );
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeReturn();
			testCounts << "StmtReturn:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eReturn );
		}
		{
			ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
			ast::type::TypesCache typesCache;
			auto stmt = stmtCache.makeReturn( exprCache.makeLiteral( typesCache, 10 ) );
			testCounts << "StmtReturn:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eReturn );
			check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		}
		testEnd();
	}

	void testDemote( test::TestCounts & testCounts )
	{
		testBegin( "testDemote" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeDemote();
		testCounts << "StmtDemote:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eDemote );
		testEnd();
	}

	void testTerminateInvocation( test::TestCounts & testCounts )
	{
		testBegin( "testTerminateInvocation" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeTerminateInvocation();
		testCounts << "StmtTerminateInvocation:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eTerminateInvocation );
		testEnd();
	}

	void testInputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputGeometryLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputGeometryLayout( typesCache.getVoid()
			, ast::type::InputLayout::eLineStripWithAdjacency );
		testCounts << "StmtInputGeometryLayout:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInputGeometryLayout );
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid );
		check( stmt->getLayout() == ast::type::InputLayout::eLineStripWithAdjacency );
		testEnd();
	}

	void testOutputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputGeometryLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputGeometryLayout( typesCache.getVoid()
			, ast::type::OutputLayout::eTriangleStrip
			, 15u );
		testCounts << "StmtOutputGeometryLayout:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eOutputGeometryLayout );
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid );
		check( stmt->getLayout() == ast::type::OutputLayout::eTriangleStrip );
		check( stmt->getPrimCount() == 15u );
		testEnd();
	}

	void testOutputMeshLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputMeshLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputMeshLayout( typesCache.getVoid()
			, ast::type::OutputTopology::eTriangle
			, 64u
			, 126u );
		testCounts << "StmtOutputGeometryLayout:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eOutputMeshLayout );
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid );
		check( stmt->getTopology() == ast::type::OutputTopology::eTriangle );
		check( stmt->getMaxVertices() == 64u );
		check( stmt->getMaxPrimitives() == 126u );
		testEnd();
	}

	void testInputComputeLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputComputeLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputComputeLayout( typesCache.getVoid(), 16, 32, 64 );
		testCounts << "StmtInputComputeLayout:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInputComputeLayout );
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid );
		check( stmt->getWorkGroupsX() == 16u );
		check( stmt->getWorkGroupsY() == 32u );
		check( stmt->getWorkGroupsZ() == 64u );
		testEnd();
	}

	void testPreprocDefine( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocDefine" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocDefine( 1u, "DefineIt", exprCache.makeLiteral( typesCache, 1 ) );
		testCounts << "PreprocDefine:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocDefine );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( stmt->getExpr()->getType()->getKind() == ast::type::Kind::eInt32 );
		testEnd();
	}

	void testPreprocIf( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocIf" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "ItIsDefined" ) ) );
		testCounts << "PreprocIf:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocIf );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElif( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocElif" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto ifStmt = stmtCache.makePreprocIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "ItIsNotDefined" ) ) );
		auto stmt = ifStmt->createElif( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "ItIsDefined" ) ) );
		testCounts << "PreprocElif:\n" << ast::debug::displayStatements( stmt ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocElif );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElse( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocElse" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto ifStmt = stmtCache.makePreprocIf( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "ItIsDefined" ) ) );
		auto stmt = ifStmt->createElse();
		testCounts << "PreprocElse:\n" << ast::debug::displayStatements( stmt ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocElse );
		testEnd();
	}
	
	void testPreprocIfDef( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocIfDef" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocIfDef( exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "IsItDefined" ) ) );
		testCounts << "PreprocIfDef:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocIfDef );
		check( stmt->getIdentExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getIdentExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocEndif( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocEndif" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocEndif();
		testCounts << "PreprocEndif:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocEndif );
		testEnd();
	}

	void testPreprocExtension( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocExtension" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocExtension( "GL_arb_coin", ast::stmt::PreprocExtension::ExtStatus::eEnabled );
		testCounts << "PreprocExtension:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocExtension );
		check( stmt->getName() == "GL_arb_coin" );
		check( stmt->getStatus() == ast::stmt::PreprocExtension::ExtStatus::eEnabled );
		testEnd();
	}

	void testPreprocVersion( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocVersion" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePreprocVersion( "430 core" );
		testCounts << "PreprocVersion:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocVersion );
		check( stmt->getName() == "430 core" );
		testEnd();
	}

	void testFragmentLayout( test::TestCounts & testCounts )
	{
		testBegin( "testFragmentLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeFragmentLayout( typesCache.getVoid()
				, ast::FragmentOrigin::eLowerLeft
			, ast::FragmentCenter::eCenterInteger );
		testCounts << "StmtFragmentLayout:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eFragmentLayout );
		check( stmt->getFragmentCenter() == ast::FragmentCenter::eCenterInteger );
		check( stmt->getFragmentOrigin() == ast::FragmentOrigin::eLowerLeft );
		testEnd();
	}

	void testOutputTessellationControlLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputTessellationControlLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeOutputTessellationControlLayout( typesCache.getVoid()
			, ast::type::PatchDomain::eQuads
			, ast::type::Partitioning::eFractionalEven
			, ast::type::OutputTopology::eQuad
			, ast::type::PrimitiveOrdering::eCCW
			, 4u );
		testCounts << "StmtOutputTessellationControlLayout:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eOutputTessellationControlLayout );
		check( stmt->getDomain() == ast::type::PatchDomain::eQuads );
		check( stmt->getPartitioning() == ast::type::Partitioning::eFractionalEven );
		check( stmt->getTopology() == ast::type::OutputTopology::eQuad );
		check( stmt->getPrimitiveOrdering() == ast::type::PrimitiveOrdering::eCCW );
		check( stmt->getOutputVertices() == 4u );
		testEnd();
	}

	void testInputTessellationEvaluationLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputTessellationEvaluationLayout" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeInputTessellationEvaluationLayout( typesCache.getVoid()
			, ast::type::PatchDomain::eQuads
			, ast::type::Partitioning::eFractionalEven
			, ast::type::PrimitiveOrdering::eCCW );
		testCounts << "StmtInputTessellationEvaluationLayout:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInputTessellationEvaluationLayout );
		check( stmt->getDomain() == ast::type::PatchDomain::eQuads );
		check( stmt->getPartitioning() == ast::type::Partitioning::eFractionalEven );
		check( stmt->getPrimitiveOrdering() == ast::type::PrimitiveOrdering::eCCW );
		testEnd();
	}

	void testAccelerationStructureDecl( test::TestCounts & testCounts )
	{
		testBegin( "testAccelerationStructureDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeAccelerationStructureDecl( i
			, 18u
			, 52u );
		testCounts << "StmtAccelerationStructureDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eAccelerationStructureDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "i" );
		check( stmt->getBindingPoint() == 18u );
		check( stmt->getDescriptorSet() == 52u );
		testEnd();
	}

	void testInOutRayPayloadVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutRayPayloadVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeInOutRayPayloadVariableDecl( i
			, 18u );
		testCounts << "StmtInOutRayPayloadVariableDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutRayPayloadVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "i" );
		check( stmt->getLocation() == 18u );
		testEnd();
	}

	void testHitAttributeVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testHitAttributeVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeHitAttributeVariableDecl( i );
		testCounts << "StmtHitAttributeVariableDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eHitAttributeVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "i" );
		testEnd();
	}

	void testInOutCallableDataVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutCallableDataVariableDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getInt32(), "i" );
		auto stmt = stmtCache.makeInOutCallableDataVariableDecl( i
			, 18u );
		testCounts << "StmtInOutCallableDataVariableDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutCallableDataVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt32 );
		check( stmt->getVariable()->getName() == "i" );
		check( stmt->getLocation() == 18u );
		testEnd();
	}

	void testBufferReferenceDecl( test::TestCounts & testCounts )
	{
		testBegin( "testBufferReferenceDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeBufferReferenceDecl( typesCache.getInt32() );
		testCounts << "StmtBufferReferenceDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eBufferReferenceDecl );
		check( stmt->getType()->getKind() == ast::type::Kind::eInt32 );
		testEnd();
	}

	void testTerminateRay( test::TestCounts & testCounts )
	{
		testBegin( "testTerminateRay" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeTerminateRay();
		testCounts << "StmtTerminateRay:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eTerminateRay );
		testEnd();
	}

	void testIgnoreIntersection( test::TestCounts & testCounts )
	{
		testBegin( "testIgnoreIntersection" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeIgnoreIntersection();
		testCounts << "StmtIgnoreIntersection:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eIgnoreIntersection );
		testEnd();
	}

	void testBreak( test::TestCounts & testCounts )
	{
		testBegin( "testBreak" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		{
			auto stmt = stmtCache.makeBreak( true );
			testCounts << "StmtBreak:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eBreak );
			require( stmt->isSwitchCaseBreak() );
		}
		{
			auto stmt = stmtCache.makeBreak( false );
			testCounts << "StmtBreak:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eBreak );
			require( !stmt->isSwitchCaseBreak() );
		}
		testEnd();
	}

	void testContinue( test::TestCounts & testCounts )
	{
		testBegin( "testContinue" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makeContinue();
		testCounts << "StmtContinue:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eContinue );
		testEnd();
	}

	void testDispatchMesh( test::TestCounts & testCounts )
	{
		testBegin( "testDispatchMesh" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::expr::ExprCache exprCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto numGroupsX = exprCache.makeLiteral( typesCache, 16u );
		auto numGroupsY = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getBool(), "numGroupsY" ) );
		auto numGroupsZ = exprCache.makeLiteral( typesCache, 32u );
		auto payload = exprCache.makeIdentifier( typesCache, ast::var::makeVariable( ++testCounts.nextVarId, typesCache.getTaskPayload( typesCache.getUInt32() ), "payload" ) );
		auto stmt = stmtCache.makeDispatchMesh( std::move( numGroupsX ), std::move( numGroupsY ), std::move( numGroupsZ ), std::move( payload ) );
		testCounts << "StmtDispatchMesh:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eDispatchMesh );
		require( stmt->getNumGroupsX()->getKind() == ast::expr::Kind::eLiteral );
		require( stmt->getNumGroupsY()->getKind() == ast::expr::Kind::eIdentifier );
		require( static_cast< ast::expr::Identifier const & >( *stmt->getNumGroupsY() ).getVariable()->getName() == "numGroupsY" );
		require( stmt->getNumGroupsZ()->getKind() == ast::expr::Kind::eLiteral );
		require( stmt->getPayload()->getKind() == ast::expr::Kind::eIdentifier );
		require( static_cast< ast::expr::Identifier const & >( *stmt->getPayload() ).getVariable()->getName() == "payload" );
		testEnd();
	}

	void testPerPrimitiveDecl( test::TestCounts & testCounts )
	{
		testBegin( "testPerPrimitiveDecl" );
		ast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };
		ast::type::TypesCache typesCache;
		auto stmt = stmtCache.makePerPrimitiveDecl( typesCache.getInt32() );
		testCounts << "StmtPerPrimitiveDecl:\n" << ast::debug::displayStatements( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePerPrimitiveDecl );
		check( stmt->getType()->getKind() == ast::type::Kind::eInt32 );
		testEnd();
	}
}

testSuiteMain( TestASTStatements )
{
	testSuiteBegin();
	testPreprocDefine( testCounts );
	testPreprocElif( testCounts );
	testPreprocElse( testCounts );
	testPreprocEndif( testCounts );
	testPreprocExtension( testCounts );
	testPreprocIf( testCounts );
	testPreprocIfDef( testCounts );
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
	testSuiteEnd();
}

testSuiteLaunch( TestASTStatements )
