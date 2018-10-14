/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugStmtVisitor.hpp"

#include "ASTGenerator/Debug/DebugCommon.hpp"
#include "ASTGenerator/Debug/DebugExprVisitor.hpp"

namespace ast::debug
{
	StmtVisitor::StmtVisitor( std::string & result
		, std::string indent )
		: m_result{ result }
		, m_indent{ std::move( indent ) }
	{
	}

	std::string StmtVisitor::submit( stmt::Stmt * stmt
		, std::string indent )
	{
		std::string result;
		StmtVisitor vis{ result, std::move( indent ) };
		stmt->accept( &vis );
		return result;
	}

	void StmtVisitor::visitContainerStmt( stmt::Container * stmt )
	{
		for ( auto & stmt : stmt->getStatements() )
		{
			m_result += submit( stmt.get(), m_indent );
		}
	}

	void StmtVisitor::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
		m_result += "uniform " + stmt->getTypeName();
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitCompoundStmt( stmt::Compound * stmt )
	{
		if ( stmt->getStatements().empty() )
		{
			m_result += ";\n";
		}
		else
		{
			m_result += "\n" + m_indent + "{\n";
			auto save = m_indent;
			m_indent += "\t";
			visitContainerStmt( stmt );
			m_indent = save;

			if ( m_appendSemiColon )
			{
				m_result += m_indent + "};\n";
			}
			else
			{
				m_result += m_indent + "}\n";
			}
		}
	}

	void StmtVisitor::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		m_result += m_indent + "do";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ");\n";
	}

	void StmtVisitor::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		m_result += m_indent + "else if (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitElseStmt( stmt::Else * stmt )
	{
		m_result += m_indent + "else";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitForStmt( stmt::For * stmt )
	{
		m_result += m_indent + "for (" + ExprVisitor::submit( stmt->getInitExpr() ) + ";";
		m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + ";";
		m_result += ExprVisitor::submit( stmt->getIncrExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		m_result += m_indent + getTypeName( stmt->getRet() ) + " ";
		m_result += stmt->getTypeName() + "(";
		std::string sep;

		for ( auto & param : stmt->getParameters() )
		{
			m_result += sep + getTypeName( param->getType() ) + " " + param->getTypeName();
			sep = ", ";
		}

		m_result += ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitIfStmt( stmt::If * stmt )
	{
		m_result += m_indent + "if (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );

		for ( auto & elseIf : stmt->getElseIfList() )
		{
			elseIf->accept( this );
		}

		if ( stmt->getElse() )
		{
			stmt->getElse()->accept( this );
		}
	}

	void StmtVisitor::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		m_result += m_indent;
		m_result += "layout(" + getLocationName( stmt->getVariable() ) + "=" + std::to_string( stmt->getLocation() ) + ") ";
		m_result += getDirectionName( stmt->getVariable() ) + " ";
		m_result += getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getTypeName();
		auto arraySize = stmt->getVariable().getType()->getArraySize();

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				m_result += "[]";
			}
			else
			{
				m_result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		m_result += ";\n";
	}

	void StmtVisitor::visitReturnStmt( stmt::Return * stmt )
	{
		m_result += m_indent + "return " + ExprVisitor::submit( stmt->getExpr() ) + ";\n";
	}

	void StmtVisitor::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
		m_result += getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getTypeName();
		auto arraySize = stmt->getVariable().getType()->getArraySize();

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				m_result += "[]";
			}
			else
			{
				m_result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		m_result += ";\n";
	}

	void StmtVisitor::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
		m_result += "buffer " + stmt->getTypeName();
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitSimpleStmt( stmt::Simple * stmt )
	{
		m_result += m_indent + ExprVisitor::submit( stmt->getExpr() ) + ";\n";
	}

	void StmtVisitor::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		m_result += m_indent + "struct " + stmt->getType().getTypeName();

		if ( !stmt->getType().empty() )
		{
			m_result += "\n" + m_indent + "{\n";
			auto save = m_indent;
			m_indent += "\t";

			for ( auto & member : stmt->getType() )
			{
				m_result += m_indent + getTypeName( member.type ) + " " + member.name + ";\n";
			}

			m_indent = save;
			m_result += m_indent + "};\n";
		}
		else
		{
			m_result += ";\n";
		}
	}

	void StmtVisitor::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		if ( stmt->getCaseExpr() )
		{
			m_result += m_indent + "case " + ExprVisitor::submit( stmt->getCaseExpr() ) + ":";
		}
		else
		{
			m_result += m_indent + "default:";
		}

		m_appendSemiColon = false;

		if ( !stmt->getStatements().empty() )
		{
			visitCompoundStmt( stmt );
		}
		else
		{
			m_result += "\n";
		}

		m_result += m_indent + "break;\n";
	}

	void StmtVisitor::visitSwitchStmt( stmt::Switch * stmt )
	{
		m_result += m_indent + "switch (" + ExprVisitor::submit( stmt->getTestExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		m_result += m_indent + getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getTypeName();
		auto arraySize = stmt->getVariable().getType()->getArraySize();

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				m_result += "[]";
			}
			else
			{
				m_result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		m_result += ";\n";
	}

	void StmtVisitor::visitWhileStmt( stmt::While * stmt )
	{
		m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		m_result += "#define " + preproc->getTypeName() + " " + ExprVisitor::submit( preproc->getExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		m_result += "#elif " + ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		m_result += "#else\n";
	}

	void StmtVisitor::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
		m_result += "#endif\n";
	}

	void StmtVisitor::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		m_result += "#extension " + preproc->getTypeName() + ": " + getStatusName( preproc->getStatus() ) + "\n";
	}

	void StmtVisitor::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		m_result += "#if " + ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		m_result += "#ifdef " + ExprVisitor::submit( preproc->getIdentExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		m_result += "#version " + preproc->getTypeName() + "\n";
	}
}
