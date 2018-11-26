#include "../Common.hpp"

#include <ASTGenerator/Var/Variable.hpp>
#include <ASTGenerator/Debug/DebugExprVisitor.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>

namespace
{
	void testPreprocIf( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocIf" );
		auto stmt = ast::stmt::makePreprocIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "ItIsDefined" ) ) );
		std::cout << "PreprocIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocIf );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}
	
	void testPreprocIfDef( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocIfDef" );
		auto stmt = ast::stmt::makePreprocIfDef( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "IsItDefined" ) ) );
		std::cout << "PreprocIfDef:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocIfDef );
		check( stmt->getIdentExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getIdentExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElif( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocElif" );
		auto ifStmt = ast::stmt::makePreprocIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "ItIsNotDefined" ) ) );
		auto stmt = ifStmt->createElif( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "ItIsDefined" ) ) );
		std::cout << "PreprocElif:\n" << ast::debug::StmtVisitor::submit( stmt ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocElif );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElse( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocElse" );
		auto ifStmt = ast::stmt::makePreprocIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "ItIsDefined" ) ) );
		auto stmt = ifStmt->createElse();
		std::cout << "PreprocElse:\n" << ast::debug::StmtVisitor::submit( stmt ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocElse );
		testEnd();
	}

	void testPreprocEndif( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocEndif" );
		auto stmt = ast::stmt::makePreprocEndif();
		std::cout << "PreprocEndif:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocEndif );
		testEnd();
	}

	void testPreprocDefine( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocDefine" );
		auto stmt = ast::stmt::makePreprocDefine( "DefineIt", ast::expr::makeLiteral( 1 ) );
		std::cout << "PreprocDefine:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocDefine );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( stmt->getExpr()->getType()->getKind() == ast::type::Kind::eInt );
		testEnd();
	}

	void testPreprocExtension( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocExtension" );
		auto stmt = ast::stmt::makePreprocExtension( "GL_arb_coin", ast::stmt::PreprocExtension::Status::eEnabled );
		std::cout << "PreprocExtension:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocExtension );
		check( stmt->getName() == "GL_arb_coin" );
		check( stmt->getStatus() == ast::stmt::PreprocExtension::Status::eEnabled );
		testEnd();
	}

	void testPreprocVersion( test::TestCounts & testCounts )
	{
		testBegin( "testPreprocVersion" );
		auto stmt = ast::stmt::makePreprocVersion( "430 core" );
		std::cout << "PreprocVersion:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::ePreprocVersion );
		check( stmt->getName() == "430 core" );
		testEnd();
	}

	void testSimpleStatement( test::TestCounts & testCounts )
	{
		testBegin( "testSimpleStatement" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto stmt = ast::stmt::makeSimple( ast::expr::makeInit( std::move( lhs ), std::move( rhs ) ) );
		std::cout << "StmtSimple:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSimple );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eInit );
		testEnd();
	}
	
	void testVariableDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testVariableDeclStatement" );
		auto stmt = ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		std::cout << "StmtVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eVariableDecl );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testSampledImageDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testSampledImageDeclStatement" );
		ast::type::ImageConfiguration config{};
		auto stmt = ast::stmt::makeSampledImageDecl( ast::var::makeVariable( ast::type::getSampledImage( config ), "lhs" ), 1u, 2u );
		std::cout << "StmtSamplerDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSampledImageDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eSampledImage );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testSamplerDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testSamplerDeclStatement" );
		auto stmt = ast::stmt::makeSamplerDecl( ast::var::makeVariable( ast::type::getSampler(), "lhs" ), 1u, 2u );
		std::cout << "StmtSamplerDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eSamplerDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eSampler );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testImageDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testImageDeclStatement" );
		ast::type::ImageConfiguration config{};
		auto stmt = ast::stmt::makeImageDecl( ast::var::makeVariable( ast::type::getImage( config ), "lhs" ), 1u, 2u );
		std::cout << "StmtImageDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eImageDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getDescriptorSet() == 2u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eImage );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testConstantBufferDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testConstantBufferDeclStatement" );
		{
			auto stmt = ast::stmt::makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			std::cout << "StmtConstantBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->empty() );
		}
		{
			auto stmt = ast::stmt::makeConstantBufferDecl( "Buffer", ast::type::MemoryLayout::eStd140, 1u, 2u );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "i" ) ) );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "j" ) ) );
			std::cout << "StmtConstantBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testShaderBufferDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testShaderBufferDeclStatement" );
		{
			auto stmt = ast::stmt::makeShaderBufferDecl( "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u );
			std::cout << "StmtShaderBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->empty() );
		}
		{
			auto stmt = ast::stmt::makeShaderBufferDecl( "Buffer", ast::type::MemoryLayout::eStd430, 1u, 2u );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "i" ) ) );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "j" ) ) );
			std::cout << "StmtShaderBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testShaderStructBufferDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testShaderStructBufferDeclStatement" );
		{
			auto baseType = ast::type::makeStructType( ast::type::MemoryLayout::eStd430, "BaseType" );
			auto array = ast::type::makeArrayType( baseType );
			auto type = ast::type::makeStructType( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( type, "Inst", ast::var::Flag::eUniform );
			auto stmt = ast::stmt::makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			std::cout << "StmtShaderStructBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
		}
		{
			auto baseType = ast::type::makeStructType( ast::type::MemoryLayout::eStd430, "BaseType" );
			baseType->declMember( "i", ast::type::getInt() );
			baseType->declMember( "j", ast::type::getInt() );
			auto array = ast::type::makeArrayType( baseType );
			auto type = ast::type::makeStructType( ast::type::MemoryLayout::eStd430, "BufferType" );
			type->declMember( "Data", array );
			auto data = ast::var::makeVariable( type->getMember( "Data" ).type, "Data", ast::var::Flag::eUniform );
			auto instance = ast::var::makeVariable( type, "Inst", ast::var::Flag::eUniform );
			auto stmt = ast::stmt::makeShaderStructBufferDecl( "Buffer", instance, data, 1u, 2u );
			std::cout << "StmtShaderStructBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eShaderStructBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getDescriptorSet() == 2u );
		}
		testEnd();
	}
	
	void testInOutVariableDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testInOutVariableDeclStatement" );
		auto stmt = ast::stmt::makeInOutVariableDecl( ast::var::makeVariable( ast::type::getInt(), "lhs", ast::var::Flag::eShaderInput ), 1u );
		std::cout << "StmtInOutVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable()->getName() == "lhs" );
		testEnd();
	}

	void testContainerStatement( test::TestCounts & testCounts )
	{
		testBegin( "testContainerStatement" );
		{
			auto stmt = ast::stmt::makeContainer();
			std::cout << "StmtContainer (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeContainer();
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtContainer:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testCompoundStatement( test::TestCounts & testCounts )
	{
		testBegin( "testCompoundStatement" );
		{
			auto stmt = ast::stmt::makeCompound();
			std::cout << "StmtCompound (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeCompound();
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtCompound:" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testIfStatement( test::TestCounts & testCounts )
	{
		testBegin( "testIfStatement" );
		{
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			std::cout << "StmtIf (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testElseStatement( test::TestCounts & testCounts )
	{
		testBegin( "testElseStatement" );
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			auto elseStmt = stmt->createElse();
			std::cout << "StmtElse (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->empty() );
		}
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 20 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( i ), ast::expr::makeLiteral( 20 ) ) ) );
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 10 ) ) ) );
			std::cout << "StmtElse:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->size() == 2u );
		}
		testEnd();
	}

	void testElseIfStatement( test::TestCounts & testCounts )
	{
		testBegin( "testElseIfStatement" );
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "l" ) ) );
			std::cout << "StmtElseIf (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->empty() );
		}
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "l" ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( i ), ast::expr::makeLiteral( 20 ) ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 10 ) ) ) );
			std::cout << "StmtElseIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->size() == 2u );
		}
		testEnd();
	}

	void testElseIfElseStatement( test::TestCounts & testCounts )
	{
		testBegin( "testElseIfStatement" );
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "l" ) ) );
			auto elseStmt = stmt->createElse();
			std::cout << "StmtElse (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;
		}
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "l" ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( i ), ast::expr::makeLiteral( 20 ) ) ) );
			elseIfStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 10 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( i ), ast::expr::makeLiteral( 20 ) ) ) );
			elseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 10 ) ) ) );
			std::cout << "StmtElse:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;
		}
		testEnd();
	}

	void testWhileStatement( test::TestCounts & testCounts )
	{
		testBegin( "testWhileStatement" );
		{
			auto stmt = ast::stmt::makeWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			std::cout << "StmtWhile (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtWhile:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testDoWhileStatement( test::TestCounts & testCounts )
	{
		testBegin( "testDoWhileStatement" );
		{
			auto stmt = ast::stmt::makeDoWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			std::cout << "StmtDoWhile (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeDoWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtDoWhile:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testForStatement( test::TestCounts & testCounts )
	{
		testBegin( "testForStatement" );
		{
			auto k = ast::var::makeVariable( ast::type::getInt(), "k" );
			auto stmt = ast::stmt::makeFor( ast::expr::makeInit( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 0 ) )
				, ast::expr::makeLessEqual( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 10 ) )
				, ast::expr::makePreIncrement( ast::expr::makeIdentifier( k ) ) );
			std::cout << "StmtFor (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

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
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto k = ast::var::makeVariable( ast::type::getInt(), "k" );
			auto stmt = ast::stmt::makeFor( ast::expr::makeInit( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 0 ) )
				, ast::expr::makeLessEqual( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 10 ) )
				, ast::expr::makePreIncrement( ast::expr::makeIdentifier( k ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtFor:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

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

	void testStructureDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testStructureDeclStatement" );
		{
			auto type = ast::type::makeStructType( ast::type::MemoryLayout::eStd140, "MyStruct" );
			auto stmt = ast::stmt::makeStructureDecl( type );
			std::cout << "StmtStructureDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl );
			check( stmt->getType()->getName() == "MyStruct" );
			check( stmt->getType()->empty() );
		}
		{
			auto type = ast::type::makeStructType( ast::type::MemoryLayout::eStd140, "MyStruct" );
			type->declMember( "i", ast::type::getInt() );
			type->declMember( "j", ast::type::getInt() );
			auto stmt = ast::stmt::makeStructureDecl( type );
			std::cout << "StmtStructureDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eStructureDecl );
			check( stmt->getType()->getName() == "MyStruct" );
			check( stmt->getType()->size() == 2u );
		}
		testEnd();
	}

	void testSwitchStatement( test::TestCounts & testCounts )
	{
		testBegin( "testSwitchStatement" );
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( i ) ) );
			std::cout << "StmtSwitch (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->empty() );
		}
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( i ) ) );
			stmt->createCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( 10 ) ) );
			stmt->createDefault();
			std::cout << "StmtSwitch (empty cases):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->size() == 2u );
		}
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto k = ast::var::makeVariable( ast::type::getInt(), "k" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( i ) ) );
			auto caseStmt = stmt->createCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( 10 ) ) );
			caseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 10 ) ) ) );
			caseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 20 ) ) ) );
			auto defaultStmt = stmt->createDefault();
			defaultStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 10 ) ) ) );
			defaultStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtSwitch:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->size() == 2u );
		}
		testEnd();
	}

	void testReturnStatement( test::TestCounts & testCounts )
	{
		testBegin( "testReturnStatement" );
		{
			auto stmt = ast::stmt::makeReturn();
			std::cout << "StmtReturn:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eReturn );
		}
		{
			auto stmt = ast::stmt::makeReturn( ast::expr::makeLiteral( 10 ) );
			std::cout << "StmtReturn:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eReturn );
			check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		}
		testEnd();
	}

	void testDiscardStatement( test::TestCounts & testCounts )
	{
		testBegin( "testDiscardStatement" );
		auto stmt = ast::stmt::makeDiscard();
		std::cout << "StmtDiscard:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eDiscard );
		testEnd();
	}

	void testInputComputeLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputComputeLayout" );
		auto stmt = ast::stmt::makeInputComputeLayout( 16, 32, 64 );
		std::cout << "StmtInputComputeLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInputComputeLayout );
		check( stmt->getWorkGroupsX() == 16u );
		check( stmt->getWorkGroupsY() == 32u );
		check( stmt->getWorkGroupsZ() == 64u );
		testEnd();
	}

	void testInputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testInputGeometryLayout" );
		auto stmt = ast::stmt::makeInputGeometryLayout( ast::stmt::InputLayout::eLineStripWithAdjacency );
		std::cout << "StmtInputGeometryLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eInputGeometryLayout );
		check( stmt->getLayout() == ast::stmt::InputLayout::eLineStripWithAdjacency );
		testEnd();
	}

	void testOutputGeometryLayout( test::TestCounts & testCounts )
	{
		testBegin( "testOutputGeometryLayout" );
		auto stmt = ast::stmt::makeOutputGeometryLayout( ast::stmt::OutputLayout::eTriangleStrip, 15u );
		std::cout << "StmtOutputGeometryLayout:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		require( stmt->getKind() == ast::stmt::Kind::eOutputGeometryLayout );
		check( stmt->getLayout() == ast::stmt::OutputLayout::eTriangleStrip );
		check( stmt->getPrimCount() == 15u );
		testEnd();
	}

	void testFunctionDeclStatement( test::TestCounts & testCounts )
	{
		testBegin( "testFunctionDeclStatement" );
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", {} );
			std::cout << "StmtFunctionDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().empty() );
			check( stmt->empty() );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ) } );
			std::cout << "StmtFunctionDecl (empty body):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 1u );
			check( stmt->empty() );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ), ast::var::makeVariable( ast::type::getInt(), "j" ) } );
			std::cout << "StmtFunctionDecl (empty body):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 2u );
			check( stmt->empty() );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", {} );
			stmt->addStmt( ast::stmt::makeReturn( ast::expr::makeLiteral( 10 ) ) );
			std::cout << "StmtFunctionDecl (empty parameters list):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().empty() );
			check( stmt->size() == 1u );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ) } );
			stmt->addStmt( ast::stmt::makeReturn(
				ast::expr::makeAdd( ast::type::getInt(),
					ast::expr::makeIdentifier( stmt->getParameters()[0] ),
					ast::expr::makeLiteral( 10 ) ) ) );
			std::cout << "StmtFunctionDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 1u );
			check( stmt->size() == 1u );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ), ast::var::makeVariable( ast::type::getInt(), "j" ) } );
			stmt->addStmt( ast::stmt::makeReturn( 
				ast::expr::makeAdd( ast::type::getInt(), 
					ast::expr::makeIdentifier( stmt->getParameters()[0] ),
					ast::expr::makeIdentifier( stmt->getParameters()[1] ) ) ) );
			std::cout << "StmtFunctionDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			require( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 2u );
			check( stmt->size() == 1u );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestASTStatements" );
	testPreprocIf( testCounts );
	testPreprocIfDef( testCounts );
	testPreprocElif( testCounts );
	testPreprocElse( testCounts );
	testPreprocEndif( testCounts );
	testPreprocDefine( testCounts );
	testPreprocExtension( testCounts );
	testPreprocVersion( testCounts );
	testSimpleStatement( testCounts );
	testVariableDeclStatement( testCounts );
	testSampledImageDeclStatement( testCounts );
	testSamplerDeclStatement( testCounts );
	testImageDeclStatement( testCounts );
	testConstantBufferDeclStatement( testCounts );
	testShaderBufferDeclStatement( testCounts );
	testShaderStructBufferDeclStatement( testCounts );
	testInOutVariableDeclStatement( testCounts );
	testContainerStatement( testCounts );
	testCompoundStatement( testCounts );
	testIfStatement( testCounts );
	testElseStatement( testCounts );
	testElseIfStatement( testCounts );
	testElseIfElseStatement( testCounts );
	testWhileStatement( testCounts );
	testDoWhileStatement( testCounts );
	testForStatement( testCounts );
	testStructureDeclStatement( testCounts );
	testSwitchStatement( testCounts );
	testReturnStatement( testCounts );
	testDiscardStatement( testCounts );
	testInputComputeLayout( testCounts );
	testInputGeometryLayout( testCounts );
	testOutputGeometryLayout( testCounts );
	testFunctionDeclStatement( testCounts );
	testSuiteEnd();
}
