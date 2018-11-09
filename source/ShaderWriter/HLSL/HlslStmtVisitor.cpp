/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslStmtVisitor.hpp"

#include "ShaderWriter/HLSL/HlslExprVisitor.hpp"

namespace sdw::hlsl
{
	std::string StmtVisitor::submit( stmt::Stmt * stmt
		, ShaderType type
		, std::string indent )
	{
		std::string result;
		StmtVisitor vis{ result, type, std::move( indent ) };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( std::string & result
		, ShaderType type
		, std::string indent )
		: m_result{ result }
		, m_indent{ std::move( indent ) }
		, m_type{ type }
	{
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
		for ( auto & stmt : *stmt )
		{
			stmt->accept( this );
		}
	}

	void StmtVisitor::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "cbuffer " + stmt->getName() + ": register(b" + std::to_string( stmt->getBindingPoint() ) + ")";
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

	void StmtVisitor::visitCommentStmt( stmt::Comment * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + stmt->getText() + "\n";
	}

	void StmtVisitor::visitCompoundStmt( stmt::Compound * stmt )
	{
		doAppendLineEnd();
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
				+ getTypeName( param->getType() ) + " "
				+ param->getName();
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

	void StmtVisitor::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += getTypeName( stmt->getVariable()->getType() ) + " ";

		if ( stmt->getVariable()->isImplicit() )
		{
			m_result += stmt->getVariable()->getName() + ": register(t" + std::to_string( stmt->getBindingPoint() ) + ")";
		}
		else
		{
			m_result += stmt->getVariable()->getName() + ": register(u" + std::to_string( stmt->getBindingPoint() ) + ")";
		}

		auto arraySize = stmt->getVariable()->getType()->getArraySize();

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

	void StmtVisitor::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		assert( false && "stmt::InOutVariableDecl unexpected at that point" );
	}

	void StmtVisitor::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		doAppendLineEnd();
		m_result += "\n";

		if ( stmt->getWorkGroupsZ() == -1 )
		{
			if ( stmt->getWorkGroupsY() == -1 )
			{
				m_result += m_indent + "[numthreads( " + std::to_string( stmt->getWorkGroupsX() ) + " )]";
			}
			else
			{
				m_result += m_indent + "[numthreads( " + std::to_string( stmt->getWorkGroupsX() )
					+ ", " + std::to_string( stmt->getWorkGroupsY() ) + " )]";
			}
		}
		else
		{
			m_result += m_indent + "[numthreads( " + std::to_string( stmt->getWorkGroupsX() )
				+ ", " + std::to_string( stmt->getWorkGroupsY() )
				+ ", " + std::to_string( stmt->getWorkGroupsZ() ) + " )]";
		}
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		assert( false && "stmt::InputGeometryLayout unexpected at that point" );
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		assert( false && "stmt::OutputGeometryLayout unexpected at that point" );
	}

	void StmtVisitor::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		assert( false && "stmt::PerVertexDecl unexpected at that point" );
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

	void StmtVisitor::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		assert( false && "stmt::SampledImageDecl unexpected at that point" );
	}

	void StmtVisitor::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "SamplerState " + stmt->getVariable()->getName() + ": register(s" + std::to_string( stmt->getBindingPoint() ) + ");\n";
	}

	void StmtVisitor::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "struct " + stmt->getName() + "Struct";
		m_appendSemiColon = true;
		visitCompoundStmt( stmt );
		m_result += m_indent + "RWStructuredBuffer<" + stmt->getName() + "Struct> " + stmt->getName() + ": register(u" + std::to_string( stmt->getBindingPoint() ) + ");\n";
	}

	void StmtVisitor::visitSimpleStmt( stmt::Simple * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + ExprVisitor::submit( stmt->getExpr() ) + ";\n";
	}

	void StmtVisitor::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		if ( !stmt->getType()->empty() )
		{
			m_appendLineEnd = true;
			doAppendLineEnd();
			m_result += m_indent + "struct " + stmt->getType()->getName();

			m_result += "\n" + m_indent + "{\n";
			auto save = m_indent;
			m_indent += "\t";

			for ( auto & member : *stmt->getType() )
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

		if ( !stmt->empty() )
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
		m_result += m_indent + getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
		auto arraySize = stmt->getVariable()->getType()->getArraySize();

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
		assert( false && "stmt::PreprocExtension unexpected at that point" );
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
		assert( false && "stmt::PreprocVersion unexpected at that point" );
	}
}
