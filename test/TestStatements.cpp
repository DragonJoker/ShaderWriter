#include "Common.hpp"

#include <ASTGenerator/Var/Variable.hpp>
#include <ASTGenerator/Debug/DebugExprVisitor.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>

namespace
{
	void testPreprocIf()
	{
		testBegin( "testPreprocIf" );
		auto stmt = ast::makePreprocIf( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "ItIsDefined" ) ) );
		std::cout << "PreprocIf:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocIf );
		check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
		testEnd();
	}
	
	void testPreprocIfDef()
	{
		testBegin( "testPreprocIfDef" );
		auto stmt = ast::makePreprocIfDef( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "IsItDefined" ) ) );
		std::cout << "PreprocIfDef:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocIfDef );
		check( stmt->getIdentExpr()->getKind() == ast::Expr::Kind::eIdentifier );
		check( stmt->getIdentExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElif()
	{
		testBegin( "testPreprocElif" );
		auto stmt = ast::makePreprocElif( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "ItIsDefined" ) ) );
		std::cout << "PreprocElif:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocElif );
		check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
		check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
		testEnd();
	}

	void testPreprocElse()
	{
		testBegin( "testPreprocElse" );
		auto stmt = ast::makePreprocElse();
		std::cout << "PreprocElse:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocElse );
		testEnd();
	}

	void testPreprocEndif()
	{
		testBegin( "testPreprocEndif" );
		auto stmt = ast::makePreprocEndif();
		std::cout << "PreprocEndif:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocEndif );
		testEnd();
	}

	void testPreprocDefine()
	{
		testBegin( "testPreprocDefine" );
		auto stmt = ast::makePreprocDefine( "DefineIt", ast::makeLiteralExpr( 1 ) );
		std::cout << "PreprocDefine:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocDefine );
		check( stmt->getExpr()->getKind() == ast::Expr::Kind::eLiteral );
		check( stmt->getExpr()->getType()->getKind() == ast::Type::Kind::eInt );
		testEnd();
	}

	void testPreprocExtension()
	{
		testBegin( "testPreprocExtension" );
		auto stmt = ast::makePreprocExtension( "GL_arb_coin", ast::PreprocExtension::Status::eEnabled );
		std::cout << "PreprocExtension:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocExtension );
		check( stmt->getName() == "GL_arb_coin" );
		check( stmt->getStatus() == ast::PreprocExtension::Status::eEnabled );
		testEnd();
	}

	void testPreprocVersion()
	{
		testBegin( "testPreprocVersion" );
		auto stmt = ast::makePreprocVersion( "430 core" );
		std::cout << "PreprocVersion:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::ePreprocVersion );
		check( stmt->getName() == "430 core" );
		testEnd();
	}

	void testSimpleStatement()
	{
		testBegin( "testSimpleStatement" );
		auto lhs = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "lhs" ) );
		auto rhs = ast::makeLiteralExpr( 10 );
		auto stmt = ast::makeSimpleStmt( ast::makeInitExpr( std::move( lhs ), std::move( rhs ) ) );
		std::cout << "StmtSimple:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::eSimple );
		check( stmt->getExpr()->getKind() == ast::Expr::Kind::eInit );
		testEnd();
	}
	
	void testVariableDeclStatement()
	{
		testBegin( "testVariableDeclStatement" );
		auto stmt = ast::makeVariableDeclStmt( ast::makeVariable( ast::getIntType(), "lhs" ) );
		std::cout << "StmtVariableDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::eVariableDecl );
		check( stmt->getVariable().getType()->getKind() == ast::Type::Kind::eInt );
		check( stmt->getVariable().getName() == "lhs" );
		testEnd();
	}
	
	void testBoundVariableDeclStatement()
	{
		testBegin( "testBoundVariableDeclStatement" );
		auto stmt = ast::makeBoundVariableDeclStmt( ast::makeVariable( ast::getSampler2DType(), "lhs" ), 1u, 2u );
		std::cout << "StmtBoundVariableDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::eBoundVariableDecl );
		check( stmt->getBindingPoint() == 1u );
		check( stmt->getBindingSet() == 2u );
		check( stmt->getVariable().getType()->getKind() == ast::Type::Kind::eSampler2D );
		check( stmt->getVariable().getName() == "lhs" );
		testEnd();
	}
	
	void testInOutVariableDeclStatement()
	{
		testBegin( "testInOutVariableDeclStatement" );
		auto stmt = ast::makeInOutVariableDeclStmt( ast::makeVariable( ast::getIntType(), "lhs" ), 1u, ast::StmtInOutVariableDecl::Direction::eIn );
		std::cout << "StmtInOutVariableDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::eInOutVariableDecl );
		check( stmt->getLocation() == 1u );
		check( stmt->getDirection() == ast::StmtInOutVariableDecl::Direction::eIn );
		check( stmt->getVariable().getType()->getKind() == ast::Type::Kind::eInt );
		check( stmt->getVariable().getName() == "lhs" );
		testEnd();
	}

	void testCompoundStatement()
	{
		testBegin( "testCompoundStatement" );
		{
			auto stmt = ast::makeCompoundStmt();
			std::cout << "StmtCompound:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eCompound );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "i" ) );
			auto j = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "j" ) );
			auto stmt = ast::makeCompoundStmt();
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( j ), ast::makeLiteralExpr( 20 ) ) ) );
			std::cout << "StmtCompound:" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eCompound );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testIfStatement()
	{
		testBegin( "testIfStatement" );
		{
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			std::cout << "StmtIf:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "i" ) );
			auto j = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "j" ) );
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( j ), ast::makeLiteralExpr( 20 ) ) ) );
			std::cout << "StmtIf:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eIf );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testElseStatement()
	{
		testBegin( "testElseStatement" );
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			auto elseStmt = stmt->createElse();
			std::cout << "StmtElse:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( elseStmt->getKind() == ast::Stmt::Kind::eElse );
			check( elseStmt->getStatements().empty() );
		}
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 20 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( i ), ast::makeLiteralExpr( 20 ) ) ) );
			elseStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 10 ) ) ) );
			std::cout << "StmtElse:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( elseStmt->getKind() == ast::Stmt::Kind::eElse );
			check( elseStmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testElseIfStatement()
	{
		testBegin( "testElseIfStatement" );
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "l" ) ) );
			std::cout << "StmtElseIf:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( elseIfStmt->getKind() == ast::Stmt::Kind::eElseIf );
			check( elseIfStmt->getStatements().empty() );
		}
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "l" ) ) );
			elseIfStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( i ), ast::makeLiteralExpr( 20 ) ) ) );
			elseIfStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 10 ) ) ) );
			std::cout << "StmtElseIf:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( elseIfStmt->getKind() == ast::Stmt::Kind::eElseIf );
			check( elseIfStmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testElseIfElseStatement()
	{
		testBegin( "testElseIfStatement" );
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "l" ) ) );
			auto elseStmt = stmt->createElse();
			std::cout << "StmtElse:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;
		}
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto stmt = ast::makeIfStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 20 ) ) ) );
			auto elseIfStmt = stmt->createElseIf( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "l" ) ) );
			elseIfStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( i ), ast::makeLiteralExpr( 20 ) ) ) );
			elseIfStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 10 ) ) ) );
			auto elseStmt = stmt->createElse();
			elseStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( i ), ast::makeLiteralExpr( 20 ) ) ) );
			elseStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 10 ) ) ) );
			std::cout << "StmtElse:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;
		}
		testEnd();
	}

	void testWhileStatement()
	{
		testBegin( "testWhileStatement" );
		{
			auto stmt = ast::makeWhileStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			std::cout << "StmtWhile:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "i" ) );
			auto j = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "j" ) );
			auto stmt = ast::makeWhileStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( j ), ast::makeLiteralExpr( 20 ) ) ) );
			std::cout << "StmtWhile:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testDoWhileStatement()
	{
		testBegin( "testDoWhileStatement" );
		{
			auto stmt = ast::makeDoWhileStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			std::cout << "StmtWhile:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "i" ) );
			auto j = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "j" ) );
			auto stmt = ast::makeDoWhileStmt( ast::makeIdentifierExpr( ast::makeVariable( ast::getBoolType(), "k" ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( j ), ast::makeLiteralExpr( 20 ) ) ) );
			std::cout << "StmtWhile:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eDoWhile );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eIdentifier );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testForStatement()
	{
		testBegin( "testForStatement" );
		{
			auto k = ast::makeVariable( ast::getIntType(), "k" );
			auto stmt = ast::makeForStmt( ast::makeInitExpr( ast::makeIdentifierExpr( k ), ast::makeLiteralExpr( 0 ) )
				, ast::makeLessEqualExpr( ast::makeIdentifierExpr( k ), ast::makeLiteralExpr( 10 ) )
				, ast::makePreIncrementExpr( ast::makeIdentifierExpr( k ) ) );
			std::cout << "StmtFor:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::Expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::Type::Kind::eInt );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::Expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::Type::Kind::eInt );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "i" ) );
			auto j = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "j" ) );
			auto k = ast::makeVariable( ast::getIntType(), "k" );
			auto stmt = ast::makeForStmt( ast::makeInitExpr( ast::makeIdentifierExpr( k ), ast::makeLiteralExpr( 0 ) )
				, ast::makeLessEqualExpr( ast::makeIdentifierExpr( k ), ast::makeLiteralExpr( 10 ) )
				, ast::makePreIncrementExpr( ast::makeIdentifierExpr( k ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( j ), ast::makeLiteralExpr( 20 ) ) ) );
			std::cout << "StmtFor:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFor );
			check( stmt->getInitExpr()->getKind() == ast::Expr::Kind::eInit );
			check( stmt->getInitExpr()->getType()->getKind() == ast::Type::Kind::eInt );
			check( stmt->getCtrlExpr()->getKind() == ast::Expr::Kind::eLessEqual );
			check( stmt->getCtrlExpr()->getType()->getKind() == ast::Type::Kind::eBoolean );
			check( stmt->getIncrExpr()->getKind() == ast::Expr::Kind::ePreIncrement );
			check( stmt->getIncrExpr()->getType()->getKind() == ast::Type::Kind::eInt );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testStructureDeclStatement()
	{
		testBegin( "testStructureDeclStatement" );
		{
			auto stmt = ast::makeStructureDeclStmt( "MyStruct" );
			std::cout << "StmtStructureDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eStructureDecl );
			check( stmt->getName() == "MyStruct" );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto stmt = ast::makeStructureDeclStmt( "MyStruct" );
			stmt->add( ast::makeVariableDeclStmt( i ) );
			stmt->add( ast::makeVariableDeclStmt( j ) );
			std::cout << "StmtStructureDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eStructureDecl );
			check( stmt->getName() == "MyStruct" );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testSwitchCaseStatement()
	{
		testBegin( "testSwitchCaseStatement" );
		{
			auto stmt = ast::makeSwitchCaseStmt( ast::makeSwitchCaseExpr( ast::makeLiteralExpr( 10 ) ) );
			std::cout << "StmtSwitchCase:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr()->getLabel()->getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( stmt->getCaseExpr()->getLabel()->getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "i" ) );
			auto j = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "j" ) );
			auto stmt = ast::makeSwitchCaseStmt( ast::makeSwitchCaseExpr( ast::makeLiteralExpr( 10 ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( j ), ast::makeLiteralExpr( 20 ) ) ) );
			std::cout << "StmtSwitchCase:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr()->getLabel()->getValueType() == ast::ExprLiteral::ValueType::eInt );
			check( stmt->getCaseExpr()->getLabel()->getValue< ast::ExprLiteral::ValueType::eInt >() == 10 );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testSwitchDefaultStatement()
	{
		testBegin( "testSwitchDefaultStatement" );
		{
			auto stmt = ast::makeSwitchDefaultStmt();
			std::cout << "StmtSwitchCase:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr() == nullptr );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "i" ) );
			auto j = ast::makeIdentifierExpr( ast::makeVariable( ast::getIntType(), "j" ) );
			auto stmt = ast::makeSwitchDefaultStmt();
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( i ), ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( std::move( j ), ast::makeLiteralExpr( 20 ) ) ) );
			std::cout << "StmtSwitchCase:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eSwitchCase );
			check( stmt->getCaseExpr() == nullptr );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testSwitchStatement()
	{
		testBegin( "testSwitchStatement" );
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto stmt = ast::makeSwitchStmt( ast::makeSwitchTestExpr( ast::makeIdentifierExpr( i ) ) );
			std::cout << "StmtSwitch:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::Expr::Kind::eSwitchTest );
			check( stmt->getStatements().empty() );
		}
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto stmt = ast::makeSwitchStmt( ast::makeSwitchTestExpr( ast::makeIdentifierExpr( i ) ) );
			stmt->addCase( ast::makeSwitchCaseStmt( ast::makeSwitchCaseExpr( ast::makeLiteralExpr( 10 ) ) ) );
			stmt->addDefault( ast::makeSwitchDefaultStmt() );
			std::cout << "StmtSwitch:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::Expr::Kind::eSwitchTest );
			check( stmt->getStatements().size() == 2u );
		}
		{
			auto i = ast::makeVariable( ast::getIntType(), "i" );
			auto j = ast::makeVariable( ast::getIntType(), "j" );
			auto k = ast::makeVariable( ast::getIntType(), "k" );
			auto stmt = ast::makeSwitchStmt( ast::makeSwitchTestExpr( ast::makeIdentifierExpr( i ) ) );
			auto caseStmt = ast::makeSwitchCaseStmt( ast::makeSwitchCaseExpr( ast::makeLiteralExpr( 10 ) ) );
			caseStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 10 ) ) ) );
			caseStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( k ), ast::makeLiteralExpr( 20 ) ) ) );
			stmt->addCase( std::move( caseStmt ) );
			auto defaultStmt = ast::makeSwitchDefaultStmt();
			defaultStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( k ), ast::makeLiteralExpr( 10 ) ) ) );
			defaultStmt->addStmt( ast::makeSimpleStmt( ast::makeInitExpr( ast::makeIdentifierExpr( j ), ast::makeLiteralExpr( 20 ) ) ) );
			stmt->addDefault( std::move( defaultStmt ) );
			std::cout << "StmtSwitch:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eSwitch );
			check( stmt->getTestExpr()->getKind() == ast::Expr::Kind::eSwitchTest );
			check( stmt->getStatements().size() == 2u );
		}
		testEnd();
	}

	void testReturnStatement()
	{
		testBegin( "testReturnStatement" );
		auto stmt = ast::makeReturnStmt( ast::makeLiteralExpr( 10 ) );
		std::cout << "StmtReturn:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

		check( stmt->getKind() == ast::Stmt::Kind::eReturn );
		check( stmt->getExpr()->getKind() == ast::Expr::Kind::eLiteral );
		testEnd();
	}

	void testFunctionDeclStatement()
	{
		testBegin( "testFunctionDeclStatement" );
		{
			auto stmt = ast::makeFunctionDeclStmt( ast::getIntType(), "foo", {} );
			std::cout << "StmtFunctionDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().empty() );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::makeFunctionDeclStmt( ast::getIntType(), "foo", { ast::makeVariable( ast::getIntType(), "i" ) } );
			std::cout << "StmtFunctionDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 1u );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::makeFunctionDeclStmt( ast::getIntType(), "foo", { ast::makeVariable( ast::getIntType(), "i" ), ast::makeVariable( ast::getIntType(), "j" ) } );
			std::cout << "StmtFunctionDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 2u );
			check( stmt->getStatements().empty() );
		}
		{
			auto stmt = ast::makeFunctionDeclStmt( ast::getIntType(), "foo", {} );
			stmt->addStmt( ast::makeReturnStmt( ast::makeLiteralExpr( 10 ) ) );
			std::cout << "StmtFunctionDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().empty() );
			check( stmt->getStatements().size() == 1u );
		}
		{
			auto stmt = ast::makeFunctionDeclStmt( ast::getIntType(), "foo", { ast::makeVariable( ast::getIntType(), "i" ) } );
			stmt->addStmt( ast::makeReturnStmt(
				ast::makeAddExpr( ast::getIntType(),
					ast::makeIdentifierExpr( stmt->getParameters()[0] ),
					ast::makeLiteralExpr( 10 ) ) ) );
			std::cout << "StmtFunctionDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFunctionDecl );
			check( stmt->getName() == "foo" );
			check( stmt->getParameters().size() == 1u );
			check( stmt->getStatements().size() == 1u );
		}
		{
			auto stmt = ast::makeFunctionDeclStmt( ast::getIntType(), "foo", { ast::makeVariable( ast::getIntType(), "i" ), ast::makeVariable( ast::getIntType(), "j" ) } );
			stmt->addStmt( ast::makeReturnStmt( 
				ast::makeAddExpr( ast::getIntType(), 
					ast::makeIdentifierExpr( stmt->getParameters()[0] ),
					ast::makeIdentifierExpr( stmt->getParameters()[1] ) ) ) );
			std::cout << "StmtFunctionDecl:\n" << ast::DebugStmtVisitor::submit( stmt.get() ) << std::endl;

			check( stmt->getKind() == ast::Stmt::Kind::eFunctionDecl );
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
	testBoundVariableDeclStatement();
	testInOutVariableDeclStatement();
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
