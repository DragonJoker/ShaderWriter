#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Debug/DebugExprVisitor.hpp>
#include <ShaderAST/Debug/DebugStmtVisitor.hpp>

namespace
{
	void testSimple( test::TestCounts & testCounts )
	{
		testBegin( "testSimple" );
		ast::type::TypesCache cache;
		auto lhs = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( cache, 10 );
		auto stmt = ast::stmt::makeSimple( ast::expr::makeInit( std::move( lhs ), std::move( rhs ) ) );
		testCounts << "StmtSimple:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSimple );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eInit );
		testEnd();
	}

	void testContainer( test::TestCounts & testCounts )
	{
		testBegin( "testContainer" );
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeContainer();
			testCounts << "StmtContainer (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) );
			auto stmt = ast::stmt::makeContainer();
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			testCounts << "StmtContainer:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testCompound( test::TestCounts & testCounts )
	{
		testBegin( "testCompound" );
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeCompound();
			testCounts << "StmtCompound (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) );
			auto stmt = ast::stmt::makeCompound();
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			testCounts << "StmtCompound:" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testComment( test::TestCounts & testCounts )
	{
		testBegin( "testComment" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeComment( "Coin glop miaou !!" );
		testCounts << "StmtComment:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eComment );
		require( stmt->getText() == "Coin glop miaou !!" );
		testEnd();
	}

	void testVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testVariableDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "lhs" ) );
		testCounts << "StmtVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testPerVertexDecl( test::TestCounts & testCounts )
	{
		testBegin( "testPerVertexDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makePerVertexDecl( ast::stmt::PerVertexDecl::Source::eTessellationControlInput
			, cache.getInt() );
		testCounts << "StmtPerVertexDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePerVertexDecl );
		require( stmt->getSource() == ast::stmt::PerVertexDecl::Source::eTessellationControlInput );
		check( stmt->getType()->getKind() == ast::type::Kind::eInt );
		testEnd();
	}

	void testInOutVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutVariableDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeInOutVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "lhs", ast::var::Flag::eShaderInput ), 1u );
		testCounts << "StmtInOutVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testInOutStreamVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutStreamVariableDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeInOutStreamVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eGeometryStream )
			, 1u
			, 2u );
		testCounts << "makeInOutStreamVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "lhs" );
		check( stmt->getVariable()->isGeometryStream() );
		check( stmt->getStreamIndex() == 2u );
		testEnd();
	}

	void testInOutBlendVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutBlendVariableDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeInOutBlendVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eBlendIndex )
			, 1u
			, 2u );
		testCounts << "StmtInOutBlendVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "lhs" );
		check( stmt->getVariable()->isBlendIndex() );
		check( stmt->getBlendIndex() == 2u );
		testEnd();
	}

	void testSpecialisationConstantDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSpecialisationConstantDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeSpecialisationConstantDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "lhs", ast::var::Flag::eShaderInput | ast::var::Flag::eBlendIndex )
			, 1u
			, ast::expr::makeLiteral( cache, 18 ) );
		testCounts << "StmtSpecialisationConstantDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSpecialisationConstantDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "lhs" );
		check( stmt->getValue()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getValue()->getLiteralType() == ast::expr::LiteralType::eInt );
		check( stmt->getValue()->getValue< ast::expr::LiteralType::eInt >() == 18 );
		testEnd();
	}

	void testConstantBufferDecl( test::TestCounts & testCounts )
	{
		testBegin( "testConstantBufferDecl" );
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			testCounts << "StmtConstantBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) ) );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) ) );
			testCounts << "StmtConstantBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makePushConstantsBufferDecl( "Buffer", ast::type::MemoryLayout::eC );
			testCounts << "StmtPushConstantsBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::ePushConstantsBufferDecl );
			check( stmt->getMemoryLayout() == ast::type::MemoryLayout::eC );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makePushConstantsBufferDecl( "Buffer", ast::type::MemoryLayout::eC );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) ) );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) ) );
			testCounts << "StmtPushConstantsBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeShaderBufferDecl( cache, "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u, ++testCounts.nextVarId );
			testCounts << "StmtShaderBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeShaderBufferDecl( cache, "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u, ++testCounts.nextVarId );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) ) );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) ) );
			testCounts << "StmtShaderBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto baseType = cache.getStruct( ast::type::MemoryLayout::eStd430, "BaseType" );
			auto array = cache.getArray( baseType );
			auto type = cache.getStruct( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( ++testCounts.nextVarId, type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( ++testCounts.nextVarId, type, "Inst", ast::var::Flag::eUniform );
			auto stmt = ast::stmt::makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			testCounts << "StmtShaderStructBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
		}
		{
			ast::type::TypesCache cache;
			auto baseType = cache.getStruct( ast::type::MemoryLayout::eStd430, "BaseType" );
			baseType->declMember( "i", cache.getInt() );
			baseType->declMember( "j", cache.getInt() );
			auto array = cache.getArray( baseType );
			auto type = cache.getStruct( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( ++testCounts.nextVarId, type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( ++testCounts.nextVarId, type, "Inst", ast::var::Flag::eUniform );
			auto stmt = ast::stmt::makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			testCounts << "StmtShaderStructBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
		}
		testEnd();
	}

	void testSamplerDecl( test::TestCounts & testCounts )
	{
		testBegin( "testSamplerDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeSamplerDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getSampler(), "lhs" ), 1u, 2u );
		testCounts << "StmtSamplerDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
		ast::type::TypesCache cache;
		ast::type::ImageConfiguration config{};
		auto stmt = ast::stmt::makeImageDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getImage( config ), "lhs" ), 1u, 2u );
		testCounts << "StmtImageDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
		ast::type::TypesCache cache;
		ast::type::ImageConfiguration config{};
		auto stmt = ast::stmt::makeSampledImageDecl( ast::var::makeVariable( ++testCounts.nextVarId, cache.getSampledImage( config ), "lhs" ), 1u, 2u );
		testCounts << "StmtSamplerDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSampledImageDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eSampledImage );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testFunctionDecl( test::TestCounts & testCounts )
	{
		testBegin( "testFunctionDecl" );
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeFunctionDecl( cache.getFunction( cache.getInt(), {} ), "foo" );
			testCounts << "StmtFunctionDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->empty() );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeFunctionDecl( cache.getFunction( cache.getInt(), { ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) } ), "foo" );
			testCounts << "StmtFunctionDecl (empty body):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->size() == 1u );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeFunctionDecl( cache.getFunction( cache.getInt(), { ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ), ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) } ), "foo" );
			testCounts << "StmtFunctionDecl (empty body):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->size() == 2u );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeFunctionDecl( cache.getFunction( cache.getInt(), {} ), "foo" );
			stmt->addStmt( ast::stmt::makeReturn( ast::expr::makeLiteral( cache, 10 ) ) );
			testCounts << "StmtFunctionDecl (empty parameters list):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->empty() );
			check( stmt->size() == 1u );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeFunctionDecl( cache.getFunction( cache.getInt(), { ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) } ), "foo" );
			stmt->addStmt( ast::stmt::makeReturn(
				ast::expr::makeAdd( cache.getInt(),
					ast::expr::makeIdentifier( cache, *( stmt->getType()->begin() + 0u ) ),
					ast::expr::makeLiteral( cache, 10 ) ) ) );
			testCounts << "StmtFunctionDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getType()->size() == 1u );
			check( stmt->size() == 1u );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeFunctionDecl( cache.getFunction( cache.getInt(), { ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ), ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) } ), "foo" );
			stmt->addStmt( ast::stmt::makeReturn(
				ast::expr::makeAdd( cache.getInt(),
					ast::expr::makeIdentifier( cache, *( stmt->getType()->begin() + 0u ) ),
					ast::expr::makeIdentifier( cache, *( stmt->getType()->begin() + 1u ) ) ) ) );
			testCounts << "StmtFunctionDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto type = cache.getStruct( ast::type::MemoryLayout::eStd140, "MyStruct" );
			auto stmt = ast::stmt::makeStructureDecl( type );
			testCounts << "StmtStructureDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl );
			check( stmt->getType()->getName() == "MyStruct" );
			check( stmt->getType()->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto type = cache.getStruct( ast::type::MemoryLayout::eStd140, "MyStruct" );
			type->declMember( "i", cache.getInt() );
			type->declMember( "j", cache.getInt() );
			auto stmt = ast::stmt::makeStructureDecl( type );
			testCounts << "StmtStructureDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			testCounts << "StmtIf (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			testCounts << "StmtIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			auto elseStmt = stmt->createElse();
			testCounts << "StmtElse (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, i ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			testCounts << "StmtElse:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->size() == 2u );
		}
		testEnd();
	}

	void testElseIf( test::TestCounts & testCounts )
	{
		testBegin( "testElseIf" );
		{
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "l" ) ) );
			testCounts << "StmtElseIf (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, i ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			testCounts << "StmtElseIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->size() == 2u );
		}
		testEnd();
	}

	void testElseIfElse( test::TestCounts & testCounts )
	{
		testBegin( "testElseIf" );
		{
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			stmt->createElseIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "l" ) ) );
			stmt->createElse();
			testCounts << "StmtElse (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "l" ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, i ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, i ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			testCounts << "StmtElse:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;
		}
		testEnd();
	}

	void testWhile( test::TestCounts & testCounts )
	{
		testBegin( "testWhile" );
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeWhile( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			testCounts << "StmtWhile (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) );
			auto stmt = ast::stmt::makeWhile( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			testCounts << "StmtWhile:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto k = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "k" );
			auto stmt = ast::stmt::makeFor( ast::expr::makeInit( ast::expr::makeIdentifier( cache, k ), ast::expr::makeLiteral( cache, 0 ) )
				, ast::expr::makeLessEqual( cache, ast::expr::makeIdentifier( cache, k ), ast::expr::makeLiteral( cache, 10 ) )
				, ast::expr::makePreIncrement( ast::expr::makeIdentifier( cache, k ) ) );
			testCounts << "StmtFor (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) );
			auto k = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "k" );
			auto stmt = ast::stmt::makeFor( ast::expr::makeInit( ast::expr::makeIdentifier( cache, k ), ast::expr::makeLiteral( cache, 0 ) )
				, ast::expr::makeLessEqual( cache, ast::expr::makeIdentifier( cache, k ), ast::expr::makeLiteral( cache, 10 ) )
				, ast::expr::makePreIncrement( ast::expr::makeIdentifier( cache, k ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			testCounts << "StmtFor:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testDoWhile( test::TestCounts & testCounts )
	{
		testBegin( "testDoWhile" );
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeDoWhile( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			testCounts << "StmtDoWhile (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" ) );
			auto stmt = ast::stmt::makeDoWhile( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			testCounts << "StmtDoWhile:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( cache, i ) ) );
			testCounts << "StmtSwitch (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->empty() );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( cache, i ) ) );
			stmt->createCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( cache, 10 ) ) );
			stmt->createDefault();
			testCounts << "StmtSwitch (empty cases):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->size() == 2u );
		}
		{
			ast::type::TypesCache cache;
			auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
			auto j = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "j" );
			auto k = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "k" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( cache, i ) ) );
			auto caseStmt = stmt->createCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( cache, 10 ) ) );
			caseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			caseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, k ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			auto defaultStmt = stmt->createDefault();
			defaultStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, k ), ast::expr::makeLiteral( cache, 10 ) ) ) );
			defaultStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( cache, j ), ast::expr::makeLiteral( cache, 20 ) ) ) );
			testCounts << "StmtSwitch:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeReturn();
			testCounts << "StmtReturn:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eReturn );
		}
		{
			ast::type::TypesCache cache;
			auto stmt = ast::stmt::makeReturn( ast::expr::makeLiteral( cache, 10 ) );
			testCounts << "StmtReturn:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

			require( stmt->getKind() == ast::stmt::Kind::eReturn );
			check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		}
		testEnd();
	}

	void testDiscard( test::TestCounts & testCounts )
	{
		testBegin( "testDiscard" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeDiscard();
		testCounts << "StmtDiscard:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eDiscard );
		testEnd();
	}

	void testInputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputGeometryLayout" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeInputGeometryLayout( cache.getVoid()
			, ast::type::InputLayout::eLineStripWithAdjacency );
		testCounts << "StmtInputGeometryLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInputGeometryLayout );
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid );
		check( stmt->getLayout() == ast::type::InputLayout::eLineStripWithAdjacency );
		testEnd();
	}

	void testOutputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputGeometryLayout" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeOutputGeometryLayout( cache.getVoid()
			, ast::type::OutputLayout::eTriangleStrip
			, 15u );
		testCounts << "StmtOutputGeometryLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eOutputGeometryLayout );
		check( stmt->getType()->getKind() == ast::type::Kind::eVoid );
		check( stmt->getLayout() == ast::type::OutputLayout::eTriangleStrip );
		check( stmt->getPrimCount() == 15u );
		testEnd();
	}

	void testOutputMeshLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputMeshLayout" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeOutputMeshLayout( cache.getVoid()
			, ast::type::OutputTopology::eTriangle
			, 64u
			, 126u );
		testCounts << "StmtOutputGeometryLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeInputComputeLayout( cache.getVoid(), 16, 32, 64 );
		testCounts << "StmtInputComputeLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makePreprocDefine( 1u, "DefineIt", ast::expr::makeLiteral( cache, 1 ) );
		testCounts << "PreprocDefine:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocDefine );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( stmt->getExpr()->getType()->getKind() == ast::type::Kind::eInt );
		testEnd();
	}

	void testPreprocIf( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocIf" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makePreprocIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "ItIsDefined" ) ) );
		testCounts << "PreprocIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocIf );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElif( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocElif" );
		ast::type::TypesCache cache;
		auto ifStmt = ast::stmt::makePreprocIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "ItIsNotDefined" ) ) );
		auto stmt = ifStmt->createElif( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "ItIsDefined" ) ) );
		testCounts << "PreprocElif:\n" << ast::debug::StmtVisitor::submit( stmt ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocElif );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElse( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocElse" );
		ast::type::TypesCache cache;
		auto ifStmt = ast::stmt::makePreprocIf( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "ItIsDefined" ) ) );
		auto stmt = ifStmt->createElse();
		testCounts << "PreprocElse:\n" << ast::debug::StmtVisitor::submit( stmt ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocElse );
		testEnd();
	}
	
	void testPreprocIfDef( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocIfDef" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makePreprocIfDef( ast::expr::makeIdentifier( cache, ast::var::makeVariable( ++testCounts.nextVarId, cache.getBool(), "IsItDefined" ) ) );
		testCounts << "PreprocIfDef:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocIfDef );
		check( stmt->getIdentExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getIdentExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocEndif( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocEndif" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makePreprocEndif();
		testCounts << "PreprocEndif:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocEndif );
		testEnd();
	}

	void testPreprocExtension( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocExtension" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makePreprocExtension( "GL_arb_coin", ast::stmt::PreprocExtension::ExtStatus::eEnabled );
		testCounts << "PreprocExtension:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocExtension );
		check( stmt->getName() == "GL_arb_coin" );
		check( stmt->getStatus() == ast::stmt::PreprocExtension::ExtStatus::eEnabled );
		testEnd();
	}

	void testPreprocVersion( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocVersion" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makePreprocVersion( "430 core" );
		testCounts << "PreprocVersion:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocVersion );
		check( stmt->getName() == "430 core" );
		testEnd();
	}

	void testFragmentLayout( test::TestCounts & testCounts )
	{
		testBegin( "testFragmentLayout" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeFragmentLayout( cache.getVoid()
				, ast::FragmentOrigin::eLowerLeft
			, ast::FragmentCenter::eCenterInteger );
		testCounts << "StmtFragmentLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eFragmentLayout );
		check( stmt->getFragmentCenter() == ast::FragmentCenter::eCenterInteger );
		check( stmt->getFragmentOrigin() == ast::FragmentOrigin::eLowerLeft );
		testEnd();
	}

	void testOutputTessellationControlLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputTessellationControlLayout" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeOutputTessellationControlLayout( cache.getVoid()
			, ast::type::PatchDomain::eQuads
			, ast::type::Partitioning::eFractionalEven
			, ast::type::OutputTopology::eQuad
			, ast::type::PrimitiveOrdering::eCCW
			, 4u );
		testCounts << "StmtOutputTessellationControlLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

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
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeInputTessellationEvaluationLayout( cache.getVoid()
			, ast::type::PatchDomain::eQuads
			, ast::type::Partitioning::eFractionalEven
			, ast::type::PrimitiveOrdering::eCCW );
		testCounts << "StmtInputTessellationEvaluationLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInputTessellationEvaluationLayout );
		check( stmt->getDomain() == ast::type::PatchDomain::eQuads );
		check( stmt->getPartitioning() == ast::type::Partitioning::eFractionalEven );
		check( stmt->getPrimitiveOrdering() == ast::type::PrimitiveOrdering::eCCW );
		testEnd();
	}

	void testAccelerationStructureDecl( test::TestCounts & testCounts )
	{
		testBegin( "testAccelerationStructureDecl" );
		ast::type::TypesCache cache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
		auto stmt = ast::stmt::makeAccelerationStructureDecl( i
			, 18u
			, 52u );
		testCounts << "StmtAccelerationStructureDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eAccelerationStructureDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "i" );
		check( stmt->getBindingPoint() == 18u );
		check( stmt->getDescriptorSet() == 52u );
		testEnd();
	}

	void testInOutRayPayloadVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutRayPayloadVariableDecl" );
		ast::type::TypesCache cache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
		auto stmt = ast::stmt::makeInOutRayPayloadVariableDecl( i
			, 18u );
		testCounts << "StmtInOutRayPayloadVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutRayPayloadVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "i" );
		check( stmt->getLocation() == 18u );
		testEnd();
	}

	void testHitAttributeVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testHitAttributeVariableDecl" );
		ast::type::TypesCache cache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
		auto stmt = ast::stmt::makeHitAttributeVariableDecl( i );
		testCounts << "StmtHitAttributeVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eHitAttributeVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "i" );
		testEnd();
	}

	void testInOutCallableDataVariableDecl( test::TestCounts & testCounts )
	{
		testBegin( "testInOutCallableDataVariableDecl" );
		ast::type::TypesCache cache;
		auto i = ast::var::makeVariable( ++testCounts.nextVarId, cache.getInt(), "i" );
		auto stmt = ast::stmt::makeInOutCallableDataVariableDecl( i
			, 18u );
		testCounts << "StmtInOutCallableDataVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutCallableDataVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "i" );
		check( stmt->getLocation() == 18u );
		testEnd();
	}

	void testBufferReferenceDecl( test::TestCounts & testCounts )
	{
		testBegin( "testBufferReferenceDecl" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeBufferReferenceDecl( cache.getInt() );
		testCounts << "StmtBufferReferenceDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eBufferReferenceDecl );
		check( stmt->getType()->getKind() == ast::type::Kind::eInt );
		testEnd();
	}

	void testTerminateRay( test::TestCounts & testCounts )
	{
		testBegin( "testTerminateRay" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeTerminateRay();
		testCounts << "StmtTerminateRay:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eTerminateRay );
		testEnd();
	}

	void testIgnoreIntersection( test::TestCounts & testCounts )
	{
		testBegin( "testIgnoreIntersection" );
		ast::type::TypesCache cache;
		auto stmt = ast::stmt::makeIgnoreIntersection();
		testCounts << "StmtIgnoreIntersection:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << test::endl;

		require( stmt->getKind() == ast::stmt::Kind::eIgnoreIntersection );
		testEnd();
	}
}

testSuiteMain( TestASTStatements )
{
	testSuiteBegin();
	testSimple( testCounts );
	testContainer( testCounts );
	testCompound( testCounts );
	testComment( testCounts );
	testVariableDecl( testCounts );
	testPerVertexDecl( testCounts );
	testInOutVariableDecl( testCounts );
	testInOutStreamVariableDecl( testCounts );
	testInOutBlendVariableDecl( testCounts );
	testSpecialisationConstantDecl( testCounts );
	testConstantBufferDecl( testCounts );
	testPushConstantsBufferDecl( testCounts );
	testShaderBufferDecl( testCounts );
	testShaderStructBufferDecl( testCounts );
	testSamplerDecl( testCounts );
	testImageDecl( testCounts );
	testSampledImageDecl( testCounts );
	testFunctionDecl( testCounts );
	testStructureDecl( testCounts );
	testIf( testCounts );
	testElse( testCounts );
	testElseIf( testCounts );
	testElseIfElse( testCounts );
	testWhile( testCounts );
	testFor( testCounts );
	testDoWhile( testCounts );
	testSwitch( testCounts );
	testReturn( testCounts );
	testDiscard( testCounts );
	testInputGeometryLayout( testCounts );
	testOutputGeometryLayout( testCounts );
	testOutputMeshLayout( testCounts );
	testInputComputeLayout( testCounts );
	testPreprocDefine( testCounts );
	testPreprocIf( testCounts );
	testPreprocElif( testCounts );
	testPreprocElse( testCounts );
	testPreprocIfDef( testCounts );
	testPreprocEndif( testCounts );
	testPreprocExtension( testCounts );
	testPreprocVersion( testCounts );
	testFragmentLayout( testCounts );
	testOutputTessellationControlLayout( testCounts );
	testInputTessellationEvaluationLayout( testCounts );
	testAccelerationStructureDecl( testCounts );
	testInOutRayPayloadVariableDecl( testCounts );
	testHitAttributeVariableDecl( testCounts );
	testInOutCallableDataVariableDecl( testCounts );
	testBufferReferenceDecl( testCounts );
	testTerminateRay( testCounts );
	testIgnoreIntersection( testCounts );
	testSuiteEnd();
}

testSuiteLaunch( TestASTStatements )
