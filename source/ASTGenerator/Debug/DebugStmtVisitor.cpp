/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugStmtVisitor.hpp"

#include "ASTGenerator/Debug/DebugExprVisitor.hpp"

namespace ast
{
	namespace
	{
		std::string getTypeName( TypePtr type )
		{
			std::string result;

			switch ( type->getKind() )
			{
			case Type::Kind::eUndefined:
				result = "undefined";
				break;
			case Type::Kind::eFunction:
				result = "function";
				break;
			case Type::Kind::eBoolean:
				result = "bool";
				break;
			case Type::Kind::eInt:
				result = "int";
				break;
			case Type::Kind::eUInt:
				result = "uint";
				break;
			case Type::Kind::eFloat:
				result = "float";
				break;
			case Type::Kind::eVec2B:
				result = "bvec2";
				break;
			case Type::Kind::eVec3B:
				result = "bvec3";
				break;
			case Type::Kind::eVec4B:
				result = "bvec4";
				break;
			case Type::Kind::eVec2I:
				result = "ivec2";
				break;
			case Type::Kind::eVec3I:
				result = "ivec3";
				break;
			case Type::Kind::eVec4I:
				result = "ivec4";
				break;
			case Type::Kind::eVec2UI:
				result = "uivec2";
				break;
			case Type::Kind::eVec3UI:
				result = "uivec3";
				break;
			case Type::Kind::eVec4UI:
				result = "uivec4";
				break;
			case Type::Kind::eVec2F:
				result = "vec2";
				break;
			case Type::Kind::eVec3F:
				result = "vec3";
				break;
			case Type::Kind::eVec4F:
				result = "vec4";
				break;
			case Type::Kind::eMat2x2B:
				result = "bmat2";
				break;
			case Type::Kind::eMat3x3B:
				result = "bmat3";
				break;
			case Type::Kind::eMat4x4B:
				result = "bmat4";
				break;
			case Type::Kind::eMat2x2I:
				result = "imat2";
				break;
			case Type::Kind::eMat3x3I:
				result = "imat3";
				break;
			case Type::Kind::eMat4x4I:
				result = "imat4";
				break;
			case Type::Kind::eMat2x2UI:
				result = "uimat2";
				break;
			case Type::Kind::eMat3x3UI:
				result = "uimat3";
				break;
			case Type::Kind::eMat4x4UI:
				result = "uimat4";
				break;
			case Type::Kind::eMat2x2F:
				result = "mat2";
				break;
			case Type::Kind::eMat3x3F:
				result = "mat3";
				break;
			case Type::Kind::eMat4x4F:
				result = "mat4";
				break;
			case Type::Kind::eConstantsBuffer:
				result = "uniform";
				break;
			case Type::Kind::eShaderBuffer:
				result = "buffer";
				break;
			case Type::Kind::eSamplerBuffer:
				result = "samplerBuffer";
				break;
			case Type::Kind::eSampler1D:
				result = "sampler1D";
				break;
			case Type::Kind::eSampler2D:
				result = "sampler2D";
				break;
			case Type::Kind::eSampler3D:
				result = "sampler3D";
				break;
			case Type::Kind::eSamplerCube:
				result = "samplerCube";
				break;
			case Type::Kind::eSampler2DRect:
				result = "sampler2DRect";
				break;
			case Type::Kind::eSampler1DArray:
				result = "sampler1DArray";
				break;
			case Type::Kind::eSampler2DArray:
				result = "sampler2DArray";
				break;
			case Type::Kind::eSamplerCubeArray:
				result = "samplerCubeArray";
				break;
			case Type::Kind::eSampler1DShadow:
				result = "sampler1DShadow";
				break;
			case Type::Kind::eSampler2DShadow:
				result = "sampler2DShadow";
				break;
			case Type::Kind::eSamplerCubeShadow:
				result = "samplerCubeShadow";
				break;
			case Type::Kind::eSampler2DRectShadow:
				result = "sampler2DRectArrayShadow";
				break;
			case Type::Kind::eSampler1DArrayShadow:
				result = "sampler1DArrayShadow";
				break;
			case Type::Kind::eSampler2DArrayShadow:
				result = "sampler2DArrayShadow";
				break;
			case Type::Kind::eSamplerCubeArrayShadow:
				result = "samplerCubeArrayShadow";
				break;
			}

			return result;
		}

		std::string getDirectionName( StmtInOutVariableDecl::Direction direction )
		{
			std::string result;

			switch ( direction )
			{
			case StmtInOutVariableDecl::Direction::eIn:
				result = "in";
				break;

			case StmtInOutVariableDecl::Direction::eOut:
				result = "out";
				break;

			case StmtInOutVariableDecl::Direction::eInOut:
				result = "inout";
				break;

			}

			return result;
		}

		std::string getStatusName( PreprocExtension::Status status )
		{
			std::string result;

			switch ( status )
			{
			case ast::PreprocExtension::Status::eDisabled:
				result = "disable";
				break;

			case ast::PreprocExtension::Status::eEnabled:
				result = "enable";
				break;

			case ast::PreprocExtension::Status::eRequired:
				result = "required";
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

	void DebugStmtVisitor::visitBoundVariableDeclStmt( StmtBoundVariableDecl * stmt )
	{
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
		m_result += getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getName();
		auto arraySize = stmt->getVariable().getType()->getArraySize();

		if ( arraySize != ast::Type::NotArray )
		{
			if ( arraySize == ast::Type::UnknownArraySize )
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

	void DebugStmtVisitor::visitInOutVariableDeclStmt( StmtInOutVariableDecl * stmt )
	{
		m_result += m_indent;
		m_result += "layout(location=" + std::to_string( stmt->getLocation() ) + ") " + getDirectionName( stmt->getDirection() ) + " ";
		m_result += getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getName();
		auto arraySize = stmt->getVariable().getType()->getArraySize();

		if ( arraySize != ast::Type::NotArray )
		{
			if ( arraySize == ast::Type::UnknownArraySize )
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
		auto arraySize = stmt->getVariable().getType()->getArraySize();

		if ( arraySize != ast::Type::NotArray )
		{
			if ( arraySize == ast::Type::UnknownArraySize )
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

	void DebugStmtVisitor::visitWhileStmt( StmtWhile * stmt )
	{
		m_result += m_indent + "while (" + DebugExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
	}

	void DebugStmtVisitor::visitPreprocDefine( PreprocDefine * preproc )
	{
		m_result += "#define " + preproc->getName() + " " + DebugExprVisitor::submit( preproc->getExpr() ) + "\n";
	}

	void DebugStmtVisitor::visitPreprocElif( PreprocElif * preproc )
	{
		m_result += "#elif " + DebugExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void DebugStmtVisitor::visitPreprocElse( PreprocElse * preproc )
	{
		m_result += "#else\n";
	}

	void DebugStmtVisitor::visitPreprocEndif( PreprocEndif * preproc )
	{
		m_result += "#endif\n";
	}

	void DebugStmtVisitor::visitPreprocExtension( PreprocExtension * preproc )
	{
		m_result += "#extension " + preproc->getName() + ": " + getStatusName( preproc->getStatus() ) + "\n";
	}

	void DebugStmtVisitor::visitPreprocIf( PreprocIf * preproc )
	{
		m_result += "#if " + DebugExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void DebugStmtVisitor::visitPreprocIfDef( PreprocIfDef * preproc )
	{
		m_result += "#ifdef " + DebugExprVisitor::submit( preproc->getIdentExpr() ) + "\n";
	}

	void DebugStmtVisitor::visitPreprocVersion( PreprocVersion * preproc )
	{
		m_result += "#version " + preproc->getName() + "\n";
	}
}
