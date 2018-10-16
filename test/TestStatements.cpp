#include "Common.hpp"

#include <ASTGenerator/Var/Variable.hpp>
#include <ASTGenerator/Debug/DebugExprVisitor.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>

namespace
{
	void testPreprocIf()
	{
		testBegin( "testPreprocIf" );
		auto stmt = ast::stmt::makePreprocIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "ItIsDefined" ) ) );
		std::cout << "PreprocIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocIf );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}
	
	void testPreprocIfDef()
	{
		testBegin( "testPreprocIfDef" );
		auto stmt = ast::stmt::makePreprocIfDef( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "IsItDefined" ) ) );
		std::cout << "PreprocIfDef:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocIfDef );
		check( stmt->getIdentExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getIdentExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElif()
	{
		testBegin( "testPreprocElif" );
		auto stmt = ast::stmt::makePreprocElif( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "ItIsDefined" ) ) );
		std::cout << "PreprocElif:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocElif );
		check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElse()
	{
		testBegin( "testPreprocElse" );
		auto stmt = ast::stmt::makePreprocElse();
		std::cout << "PreprocElse:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocElse );
		testEnd();
	}

	void testPreprocEndif()
	{
		testBegin( "testPreprocEndif" );
		auto stmt = ast::stmt::makePreprocEndif();
		std::cout << "PreprocEndif:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocEndif );
		testEnd();
	}

	void testPreprocDefine()
	{
		testBegin( "testPreprocDefine" );
		auto stmt = ast::stmt::makePreprocDefine( "DefineIt", ast::expr::makeLiteral( 1 ) );
		std::cout << "PreprocDefine:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocDefine );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		check( stmt->getExpr()->getType()->getKind() == ast::type::Kind::eInt );
		testEnd();
	}

	void testPreprocExtension()
	{
		testBegin( "testPreprocExtension" );
		auto stmt = ast::stmt::makePreprocExtension( "GL_arb_coin", ast::stmt::PreprocExtension::Status::eEnabled );
		std::cout << "PreprocExtension:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocExtension );
		check( stmt->getName() == "GL_arb_coin" );
		check( stmt->getStatus() == ast::stmt::PreprocExtension::Status::eEnabled );
		testEnd();
	}

	void testPreprocVersion()
	{
		testBegin( "testPreprocVersion" );
		auto stmt = ast::stmt::makePreprocVersion( "430 core" );
		std::cout << "PreprocVersion:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::ePreprocVersion );
		check( stmt->getName() == "430 core" );
		testEnd();
	}

	void testSimpleStatement()
	{
		testBegin( "testSimpleStatement" );
		auto lhs = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		auto rhs = ast::expr::makeLiteral( 10 );
		auto stmt = ast::stmt::makeSimple( ast::expr::makeInit( std::move( lhs ), std::move( rhs ) ) );
		std::cout << "StmtSimple:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::eSimple );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eInit );
		testEnd();
	}
	
	void testVariableDeclStatement()
	{
		testBegin( "testVariableDeclStatement" );
		auto stmt = ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "lhs" ) );
		std::cout << "StmtVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::eVariableDecl );
		check( stmt->getVariable().getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable().getName() == "lhs" );
		testEnd();
	}

	void testSamplerDeclStatement()
	{
		testBegin( "testSamplerDeclStatement" );
		auto stmt = ast::stmt::makeSamplerDecl( ast::var::makeVariable( ast::type::getSampler2D(), "lhs" ), 1u, 2u );
		std::cout << "StmtSamplerDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::eSamplerDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getBindingSet() == 2u );
		check( stmt->getVariable().getType()->getKind() == ast::type::Kind::eSampler2D );
		check( stmt->getVariable().getName() == "lhs" );
		testEnd();
	}

	void testConstantBufferDeclStatement()
	{
		testBegin( "testConstantBufferDeclStatement" );
		{
			auto stmt = ast::stmt::makeConstantBufferDecl( "Buffer", 1u, 2u );
			std::cout << "StmtConstantBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getBindingSet() == 2u );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::stmt::makeConstantBufferDecl( "Buffer", 1u, 2u );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "i" ) ) );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "j" ) ) );
			std::cout << "StmtConstantBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eConstantBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getBindingSet() == 2u );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testShaderBufferDeclStatement()
	{
		testBegin( "testShaderBufferDeclStatement" );
		{
			auto stmt = ast::stmt::makeShaderBufferDecl( "Buffer", 1u, 2u );
			std::cout << "StmtShaderBufferDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getBindingSet() == 2u );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::stmt::makeShaderBufferDecl( "Buffer", 1u, 2u );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "i" ) ) );
			stmt->add( ast::stmt::makeVariableDecl( ast::var::makeVariable( ast::type::getInt(), "j" ) ) );
			std::cout << "StmtShaderBufferDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eShaderBufferDecl );
			check( stmt->getBindingPoint() == 1u );
			check( stmt->getBindingSet() == 2u );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}
	
	void testInOutVariableDeclStatement()
	{
		testBegin( "testInOutVariableDeclStatement" );
		auto stmt = ast::stmt::makeInOutVariableDecl( ast::var::makeVariable( ast::type::getInt(), "lhs", ast::var::Flag::eShaderInput ), 1u );
		std::cout << "StmtInOutVariableDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getVariable().getType()->getKind() == ast::type::Kind::eInt );
		check( stmt->getVariable().getName() == "lhs" );
		testEnd();
	}

	void testContainerStatement()
	{
		testBegin( "testContainerStatement" );
		{
			auto stmt = ast::stmt::makeContainer();
			std::cout << "StmtContainer (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeContainer();
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtContainer:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eContainer );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testCompoundStatement()
	{
		testBegin( "testCompoundStatement" );
		{
			auto stmt = ast::stmt::makeCompound();
			std::cout << "StmtCompound (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeCompound();
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtCompound:" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eCompound );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testIfStatement()
	{
		testBegin( "testIfStatement" );
		{
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			std::cout << "StmtIf (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtIf:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testElseStatement()
	{
		testBegin( "testElseStatement" );
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			auto elseStmt = stmt->createElse();
			std::cout << "StmtElse (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->getStatements().empty() );
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

			check( elseStmt->getKind() == ast::stmt::Kind::eElse );
			check( elseStmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testElseIfStatement()
	{
		testBegin( "testElseIfStatement" );
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "l" ) ) );
			std::cout << "StmtElseIf (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->getStatements().empty() );
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

			check( elseIfStmt->getKind() == ast::stmt::Kind::eElseIf );
			check( elseIfStmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testElseIfElseStatement()
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

	void testWhileStatement()
	{
		testBegin( "testWhileStatement" );
		{
			auto stmt = ast::stmt::makeWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			std::cout << "StmtWhile (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtWhile:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testDoWhileStatement()
	{
		testBegin( "testDoWhileStatement" );
		{
			auto stmt = ast::stmt::makeDoWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			std::cout << "StmtDoWhile (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeDoWhile( ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getBool(), "k" ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtDoWhile:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testForStatement()
	{
		testBegin( "testForStatement" );
		{
			auto k = ast::var::makeVariable( ast::type::getInt(), "k" );
			auto stmt = ast::stmt::makeFor( ast::expr::makeInit( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 0 ) )
				, ast::expr::makeLessEqual( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 10 ) )
				, ast::expr::makePreIncrement( ast::expr::makeIdentifier( k ) ) );
			std::cout << "StmtFor (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->getStatements().empty() );
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

			check( stmt->getKind() == ast::stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->getCtrlExpr()->getKind() == ast::expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::type::Kind::eInt );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testStructureDeclStatement()
	{
		testBegin( "testStructureDeclStatement" );
		{
			auto type = ast::type::makeStructType( "MyStruct" );
			auto stmt = ast::stmt::makeStructureDecl( type );
			std::cout << "StmtStructureDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eStructureDecl );
			check( stmt->getType().getName() == "MyStruct" );
			check( stmt->getType().empty() );
		}
		{
			auto type = ast::type::makeStructType( "MyStruct" );
			type->addMember( ast::type::getInt(), "i" );
			type->addMember( ast::type::getInt(), "j" );
			auto stmt = ast::stmt::makeStructureDecl( type );
			std::cout << "StmtStructureDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eStructureDecl );
			check( stmt->getType().getName() == "MyStruct" );
			check( stmt->getType().size() == 2u );
		}
		testEnd();
	}

	void testSwitchCaseStatement()
	{
		testBegin( "testSwitchCaseStatement" );
		{
			auto stmt = ast::stmt::makeSwitchCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( 10 ) ) );
			std::cout << "StmtSwitchCase (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr()->getLabel()->getLiteralType() == ast::expr::LiteralType::eInt );
			check( stmt->getCaseExpr()->getLabel()->getValue< ast::expr::LiteralType::eInt >() == 10 );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeSwitchCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( 10 ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtSwitchCase:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr()->getLabel()->getLiteralType() == ast::expr::LiteralType::eInt );
			check( stmt->getCaseExpr()->getLabel()->getValue< ast::expr::LiteralType::eInt >() == 10 );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testSwitchDefaultStatement()
	{
		testBegin( "testSwitchDefaultStatement" );
		{
			auto stmt = ast::stmt::makeSwitchDefault();
			std::cout << "StmtSwitchCase (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr() == nullptr );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "i" ) );
			auto j = ast::expr::makeIdentifier( ast::var::makeVariable( ast::type::getInt(), "j" ) );
			auto stmt = ast::stmt::makeSwitchDefault();
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( i ), ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( std::move( j ), ast::expr::makeLiteral( 20 ) ) ) );
			std::cout << "StmtSwitchCase:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr() == nullptr );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testSwitchStatement()
	{
		testBegin( "testSwitchStatement" );
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( i ) ) );
			std::cout << "StmtSwitch (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( i ) ) );
			stmt->addCase( ast::stmt::makeSwitchCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( 10 ) ) ) );
			stmt->addDefault( ast::stmt::makeSwitchDefault() );
			std::cout << "StmtSwitch (empty cases):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->getStatements().size() == 2u );
		}
		{
			auto i = ast::var::makeVariable( ast::type::getInt(), "i" );
			auto j = ast::var::makeVariable( ast::type::getInt(), "j" );
			auto k = ast::var::makeVariable( ast::type::getInt(), "k" );
			auto stmt = ast::stmt::makeSwitch( ast::expr::makeSwitchTest( ast::expr::makeIdentifier( i ) ) );
			auto caseStmt = ast::stmt::makeSwitchCase( ast::expr::makeSwitchCase( ast::expr::makeLiteral( 10 ) ) );
			caseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 10 ) ) ) );
			caseStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 20 ) ) ) );
			stmt->addCase( std::move( caseStmt ) );
			auto defaultStmt = ast::stmt::makeSwitchDefault();
			defaultStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( k ), ast::expr::makeLiteral( 10 ) ) ) );
			defaultStmt->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( j ), ast::expr::makeLiteral( 20 ) ) ) );
			stmt->addDefault( std::move( defaultStmt ) );
			std::cout << "StmtSwitch:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::expr::Kind::eSwitchTest );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testReturnStatement()
	{
		testBegin( "testReturnStatement" );
		auto stmt = ast::stmt::makeReturn( ast::expr::makeLiteral( 10 ) );
		std::cout << "StmtReturn:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::stmt::Kind::eReturn );
		check( stmt->getExpr()->getKind() == ast::expr::Kind::eLiteral );
		testEnd();
	}

	void testFunctionDeclStatement()
	{
		testBegin( "testFunctionDeclStatement" );
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", {} );
			std::cout << "StmtFunctionDecl (empty):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().empty() );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ) } );
			std::cout << "StmtFunctionDecl (empty body):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 1u );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ), ast::var::makeVariable( ast::type::getInt(), "j" ) } );
			std::cout << "StmtFunctionDecl (empty body):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 2u );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", {} );
			stmt->addStmt( ast::stmt::makeReturn( ast::expr::makeLiteral( 10 ) ) );
			std::cout << "StmtFunctionDecl (empty parameters list):\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().empty() );
			check( stmt->getStatements().size() == 1u );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ) } );
			stmt->addStmt( ast::stmt::makeReturn(
				ast::expr::makeAdd( ast::type::getInt(),
					ast::expr::makeIdentifier( stmt->getParameters()[0] ),
					ast::expr::makeLiteral( 10 ) ) ) );
			std::cout << "StmtFunctionDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 1u );
			check( stmt->getStatements().size() == 1u );
		}
		{
			auto stmt = ast::stmt::makeFunctionDecl( ast::type::getInt(), "foo", { ast::var::makeVariable( ast::type::getInt(), "i" ), ast::var::makeVariable( ast::type::getInt(), "j" ) } );
			stmt->addStmt( ast::stmt::makeReturn( 
				ast::expr::makeAdd( ast::type::getInt(), 
					ast::expr::makeIdentifier( stmt->getParameters()[0] ),
					ast::expr::makeIdentifier( stmt->getParameters()[1] ) ) ) );
			std::cout << "StmtFunctionDecl:\n" << ast::debug::StmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 2u );
			check( stmt->getStatements().size() == 1u );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestStatements" );
	testPreprocIf();
	testPreprocIfDef();
	testPreprocElif();
	testPreprocElse();
	testPreprocEndif();
	testPreprocDefine();
	testPreprocExtension();
	testPreprocVersion();
	testSimpleStatement();
	testVariableDeclStatement();
	testSamplerDeclStatement();
	testConstantBufferDeclStatement();
	testShaderBufferDeclStatement();
	testInOutVariableDeclStatement();
	testContainerStatement();
	testCompoundStatement();
	testIfStatement();
	testElseStatement();
	testElseIfStatement();
	testElseIfElseStatement();
	testWhileStatement();
	testDoWhileStatement();
	testForStatement();
	testStructureDeclStatement();
	testSwitchCaseStatement();
	testSwitchDefaultStatement();
	testSwitchStatement();
	testReturnStatement();
	testFunctionDeclStatement();
	testSuiteEnd();
}
