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

	void StmtVisitor::doAppendLineEnd()
	{
		if ( m_appendLineEnd && !m_result.empty() )
		{
			m_result += "\n";
		}

		m_appendLineEnd = false;
	}

	void StmtVisitor::visitContainerStmt( stmt::Container * stmt )
	{
		for ( auto & stmt : stmt->getStatements() )
		{
			stmt->accept( this );
		}
	}

	void StmtVisitor::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
		m_result += "uniform " + stmt->getName();
		m_appendSemiColon = true;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitDiscardStmt( stmt::Discard * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "discard;\n";
	}

	void StmtVisitor::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(push_constant) ";
		m_result += "uniform " + stmt->getName();
		m_appendSemiColon = true;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitCompoundStmt( stmt::Compound * stmt )
	{
		doAppendLineEnd();

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
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "do";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ");\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		m_result += m_indent + "else if (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseStmt( stmt::Else * stmt )
	{
		m_result += m_indent + "else";
		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitEmitPrimitiveStmt( stmt::EmitPrimitive * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "EmitPrimitive();\n";
	}

	void StmtVisitor::visitEmitVertexStmt( stmt::EmitVertex * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "EmitVertex();\n";
	}

	void StmtVisitor::visitForStmt( stmt::For * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "for (" + ExprVisitor::submit( stmt->getInitExpr() ) + "; ";
		m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + "; ";
		m_result += ExprVisitor::submit( stmt->getIncrExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + getTypeName( stmt->getRet() );
		m_result += " " + stmt->getName() + "(";
		std::string sep;

		for ( auto & param : stmt->getParameters() )
		{
			m_result += sep + getDirectionName( *param )
				+ " " + getTypeName( param->getType() )
				+ " " + param->getName();
			sep = ", ";
		}

		m_result += ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitIfStmt( stmt::If * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
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

		m_appendLineEnd = true;
	}

	void StmtVisitor::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(" + getLocationName( stmt->getVariable() ) + "=" + std::to_string( stmt->getLocation() ) + ") ";
		m_result += getDirectionName( stmt->getVariable() ) + " ";
		m_result += getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getName();
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

	void StmtVisitor::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(local_size_x=" + std::to_string( stmt->getWorkGroupsX() )
			+ ", local_size_y=" + std::to_string( stmt->getWorkGroupsY() )
			+ ", local_size_z=" + std::to_string( stmt->getWorkGroupsZ() ) + ") in;\n";
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ") in;\n";
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ", max_vertices = " + std::to_string( stmt->getPrimCount() ) + ") out;\n";
	}

	void StmtVisitor::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		std::string decl;
		decl += "gl_PerVertex\n";
		decl += m_indent + "{\n";
		decl += m_indent + "	vec4 gl_Position;\n";
		decl += m_indent + "	float gl_PointSize;\n";
		decl += m_indent + "	float gl_ClipDistance[];\n";
		decl += m_indent + "}";
		switch ( stmt->getSource() )
		{
		case stmt::PerVertexDecl::Source::eVertexOutput:
			m_result += m_indent + "out " + decl + ";\n";
			break;
		case stmt::PerVertexDecl::Source::eTessellationControlInput:
		case stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
			m_result += m_indent + "in " + decl + " gl_in[gl_MaxPatchVertices];\n";
			break;
		case stmt::PerVertexDecl::Source::eTessellationControlOutput:
			m_result += m_indent + "out " + decl + " gl_out[];\n";
			break;
		case stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
			m_result += m_indent + "out " + decl + ";\n";
			break;
		case stmt::PerVertexDecl::Source::eGeometryInput:
			m_result += m_indent + "in " + decl + " gl_in[];\n";
			break;
		case stmt::PerVertexDecl::Source::eGeometryOutput:
			m_result += m_indent + "out " + decl + ";\n";
			break;
		}
	}

	void StmtVisitor::visitReturnStmt( stmt::Return * stmt )
	{
		doAppendLineEnd();

		if ( stmt->getExpr() )
		{
			m_result += m_indent + "return " + ExprVisitor::submit( stmt->getExpr() ) + ";\n";
		}
		else
		{
			m_result += m_indent + "return;\n";
		}
	}

	void StmtVisitor::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
		m_result += getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getName();
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
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
		m_result += "buffer " + stmt->getName();
		m_appendSemiColon = true;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitSimpleStmt( stmt::Simple * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + ExprVisitor::submit( stmt->getExpr() ) + ";\n";
	}

	void StmtVisitor::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "struct " + stmt->getType().getName();

		if ( !stmt->getType().empty() )
		{
			m_result += "\n" + m_indent + "{\n";
			auto save = m_indent;
			m_indent += "\t";

			for ( auto & member : stmt->getType() )
			{
				m_result += m_indent + getTypeName( member.type ) + " " + member.name;
				auto arraySize = member.type->getArraySize();

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
		doAppendLineEnd();

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
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitSwitchStmt( stmt::Switch * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "switch (" + ExprVisitor::submit( stmt->getTestExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + getTypeName( stmt->getVariable().getType() ) + " " + stmt->getVariable().getName();
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
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		doAppendLineEnd();
		m_result += "#define " + preproc->getName() + " " + ExprVisitor::submit( preproc->getExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		doAppendLineEnd();
		m_result += "#elif " + ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		doAppendLineEnd();
		m_result += "#else\n";
	}

	void StmtVisitor::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
		doAppendLineEnd();
		m_result += "#endif\n";
	}

	void StmtVisitor::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		doAppendLineEnd();
		m_result += "#extension " + preproc->getName() + ": " + getStatusName( preproc->getStatus() ) + "\n";
	}

	void StmtVisitor::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		doAppendLineEnd();
		m_result += "#if " + ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		doAppendLineEnd();
		m_result += "#ifdef " + ExprVisitor::submit( preproc->getIdentExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		doAppendLineEnd();
		m_result += "#version " + preproc->getName() + "\n";
	}
}
