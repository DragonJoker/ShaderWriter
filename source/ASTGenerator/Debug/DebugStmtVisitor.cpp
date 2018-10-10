/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugStmtVisitor.hpp"

#include "ASTGenerator/Debug/DebugExprVisitor.hpp"

namespace ast
{
	namespace
	{
		std::string getTypeName( Type type )
		{
			std::string result;

			switch ( type )
			{
			case Type::eUndefined:
				result = "undefined";
				break;
			case Type::eFunction:
				result = "function";
				break;
			case Type::eBoolean:
				result = "bool";
				break;
			case Type::eInt:
				result = "int";
				break;
			case Type::eUInt:
				result = "uint";
				break;
			case Type::eFloat:
				result = "float";
				break;
			case Type::eVec2B:
				result = "bvec2";
				break;
			case Type::eVec3B:
				result = "bvec3";
				break;
			case Type::eVec4B:
				result = "bvec4";
				break;
			case Type::eVec2I:
				result = "ivec2";
				break;
			case Type::eVec3I:
				result = "ivec3";
				break;
			case Type::eVec4I:
				result = "ivec4";
				break;
			case Type::eVec2UI:
				result = "uivec2";
				break;
			case Type::eVec3UI:
				result = "uivec3";
				break;
			case Type::eVec4UI:
				result = "uivec4";
				break;
			case Type::eVec2F:
				result = "vec2";
				break;
			case Type::eVec3F:
				result = "vec3";
				break;
			case Type::eVec4F:
				result = "vec4";
				break;
			case Type::eMat2x2B:
				result = "bmat2";
				break;
			case Type::eMat3x3B:
				result = "bmat3";
				break;
			case Type::eMat4x4B:
				result = "bmat4";
				break;
			case Type::eMat2x2I:
				result = "imat2";
				break;
			case Type::eMat3x3I:
				result = "imat3";
				break;
			case Type::eMat4x4I:
				result = "imat4";
				break;
			case Type::eMat2x2UI:
				result = "uimat2";
				break;
			case Type::eMat3x3UI:
				result = "uimat3";
				break;
			case Type::eMat4x4UI:
				result = "uimat4";
				break;
			case Type::eMat2x2F:
				result = "mat2";
				break;
			case Type::eMat3x3F:
				result = "mat3";
				break;
			case Type::eMat4x4F:
				result = "mat4";
				break;
			case Type::eConstantsBuffer:
				result = "uniform";
				break;
			case Type::eShaderBuffer:
				result = "buffer";
				break;
			case Type::eSamplerBuffer:
				result = "samplerBuffer";
				break;
			case Type::eSampler1D:
				result = "sampler1D";
				break;
			case Type::eSampler2D:
				result = "sampler2D";
				break;
			case Type::eSampler3D:
				result = "sampler3D";
				break;
			case Type::eSamplerCube:
				result = "samplerCube";
				break;
			case Type::eSampler2DRect:
				result = "sampler2DRect";
				break;
			case Type::eSampler1DArray:
				result = "sampler1DArray";
				break;
			case Type::eSampler2DArray:
				result = "sampler2DArray";
				break;
			case Type::eSamplerCubeArray:
				result = "samplerCubeArray";
				break;
			case Type::eSampler1DShadow:
				result = "sampler1DShadow";
				break;
			case Type::eSampler2DShadow:
				result = "sampler2DShadow";
				break;
			case Type::eSamplerCubeShadow:
				result = "samplerCubeShadow";
				break;
			case Type::eSampler2DRectShadow:
				result = "sampler2DRectArrayShadow";
				break;
			case Type::eSampler1DArrayShadow:
				result = "sampler1DArrayShadow";
				break;
			case Type::eSampler2DArrayShadow:
				result = "sampler2DArrayShadow";
				break;
			case Type::eSamplerCubeArrayShadow:
				result = "samplerCubeArrayShadow";
				break;
			}

			return result;
		}
	}

	DebugStmtVisitor::DebugStmtVisitor( std::string & result
		, std::string indent )
		: m_result{ result }
		, m_indent{ std::move( indent ) }
	{
	}

	std::string DebugStmtVisitor::submit( Stmt * stmt
		, std::string indent )
	{
		std::string result;
		DebugStmtVisitor vis{ result, std::move( indent ) };
		stmt->accept( &vis );
		return result;
	}

	void DebugStmtVisitor::visitCompoundStmt( StmtCompound * stmt )
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

			for ( auto & stmt : stmt->getStatements() )
			{
				m_result += submit( stmt.get(), m_indent );
			}

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

	void DebugStmtVisitor::visitDoWhileStmt( StmtDoWhile * stmt )
	{
		m_result += m_indent + "do";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += m_indent + "while (" + DebugExprVisitor::submit( stmt->getCtrlExpr() ) + ");\n";
	}

	void DebugStmtVisitor::visitElseIfStmt( StmtElseIf * stmt )
	{
		m_result += m_indent + "else if (" + DebugExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void DebugStmtVisitor::visitElseStmt( StmtElse * stmt )
	{
		m_result += m_indent + "else";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void DebugStmtVisitor::visitForStmt( StmtFor * stmt )
	{
		m_result += m_indent + "for (" + DebugExprVisitor::submit( stmt->getInitExpr() ) + ";";
		m_result += DebugExprVisitor::submit( stmt->getCtrlExpr() ) + ";";
		m_result += DebugExprVisitor::submit( stmt->getIncrExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void DebugStmtVisitor::visitFunctionDeclStmt( StmtFunctionDecl * stmt )
	{
		m_result += m_indent + getTypeName( stmt->getRetType() ) + " ";
		m_result += stmt->getName() + "(";
		std::string sep;

		for ( auto & param : stmt->getParameters() )
		{
			m_result += sep + getTypeName( param->getType() ) + " " + param->getName();
			sep = ", ";
		}

		m_result += ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void DebugStmtVisitor::visitIfStmt( StmtIf * stmt )
	{
		m_result += m_indent + "if (" + DebugExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
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

	void DebugStmtVisitor::visitReturnStmt( StmtReturn * stmt )
	{
		m_result += m_indent + "return " + DebugExprVisitor::submit( stmt->getExpr() ) + ";\n";
	}

	void DebugStmtVisitor::visitSimpleStmt( StmtSimple * stmt )
	{
		m_result += m_indent + DebugExprVisitor::submit( stmt->getExpr() ) + ";\n";
	}

	void DebugStmtVisitor::visitStructureDeclStmt( StmtStructureDecl * stmt )
	{
		m_result += m_indent + "struct " + stmt->getName();
		m_appendSemiColon = true;
		visitCompoundStmt( stmt );
	}

	void DebugStmtVisitor::visitSwitchCaseStmt( StmtSwitchCase * stmt )
	{
		if ( stmt->getCaseExpr() )
		{
			m_result += m_indent + "case " + DebugExprVisitor::submit( stmt->getCaseExpr() ) + ":";
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

	void DebugStmtVisitor::visitSwitchStmt( StmtSwitch * stmt )
	{
		m_result += m_indent + "switch (" + DebugExprVisitor::submit( stmt->getTestExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void DebugStmtVisitor::visitVariableDeclStmt( StmtVariableDecl * stmt )
	{
		m_result += m_indent + getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getName() + ";\n";
	}

	void DebugStmtVisitor::visitWhileStmt( StmtWhile * stmt )
	{
		m_result += m_indent + "while (" + DebugExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}
}
