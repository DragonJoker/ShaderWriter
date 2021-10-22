/*
See LICENSE file in root folder
*/
#include "HlslStmtVisitor.hpp"

#include "HlslExprVisitor.hpp"

namespace hlsl
{
	namespace
	{
		std::string getName( ast::type::OutputDomain value )
		{
			switch ( value )
			{
			case ast::type::OutputDomain::eIsolines:
				return "isoline";
			case ast::type::OutputDomain::eTriangles:
				return "tri";
			case ast::type::OutputDomain::eQuads:
				return "quad";
			default:
				AST_Failure( "Unsupported type::OutputDomain." );
				return "undefined";
			}
		}

		std::string getName( ast::type::OutputPartitioning value )
		{
			switch ( value )
			{
			case ast::type::OutputPartitioning::eEqual:
				return "integer";
			case ast::type::OutputPartitioning::eFractionalEven:
				return "fractionaleven";
			case ast::type::OutputPartitioning::eFractionalOdd:
				return "fractionalodd";
			default:
				AST_Failure( "Unsupported type::OutputPartitioning." );
				return "undefined";
			}
		}

		std::string getName( ast::type::OutputTopology domain
			, ast::type::OutputVertexOrder order )
		{
			switch ( domain )
			{
			case ast::type::OutputTopology::ePoint:
				return "point";
			case ast::type::OutputTopology::eLine:
				return "line";
			case ast::type::OutputTopology::eTriangle:
				switch ( order )
				{
				case ast::type::OutputVertexOrder::eCW:
					return "triangle_cw";
				case ast::type::OutputVertexOrder::eCCW:
					return "triangle_ccw";
				default:
					AST_Failure( "Unsupported type::OutputVertexOrder." );
					return "UNDEFINED";
				}
			default:
				AST_Failure( "Unsupported type::OutputDomain." );
				return "UNDEFINED";
			}
		}
	}

	std::string StmtVisitor::submit( HlslConfig const & writerConfig
		, std::set< std::string > const & patchRoutines
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, ast::stmt::Stmt * stmt
		, std::string indent )
	{
		std::string result;
		StmtVisitor vis{ writerConfig, patchRoutines, aliases, std::move( indent ), result };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( HlslConfig const & writerConfig
		, std::set< std::string > const & patchRoutines
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, std::string indent
		, std::string & result )
		: m_writerConfig{ writerConfig }
		, m_patchRoutines{ patchRoutines }
		, m_aliases{ aliases }
		, m_indent{ std::move( indent ) }
		, m_result{ result }
	{
	}

	std::string StmtVisitor::doSubmit( ast::expr::Expr * expr )
	{
		return ExprVisitor::submit( expr, m_aliases );
	}

	void StmtVisitor::doAppendLineEnd()
	{
		if ( m_appendLineEnd && !m_result.empty() )
		{
			m_result += "\n";
		}

		m_appendLineEnd = false;
	}

	void StmtVisitor::visitContainerStmt( ast::stmt::Container * stmt )
	{
		for ( auto & curStmt : *stmt )
		{
			curStmt->accept( this );
		}
	}

	void StmtVisitor::visitBreakStmt( ast::stmt::Break * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "break;\n";
	}

	void StmtVisitor::visitContinueStmt( ast::stmt::Continue * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "continue;\n";
	}

	void StmtVisitor::visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )
	{
		if ( !stmt->empty() )
		{
			m_appendLineEnd = true;
			doAppendLineEnd();
			m_result += m_indent + "cbuffer " + stmt->getName() + ": register(b" + std::to_string( stmt->getBindingPoint() ) + ")";
			m_appendSemiColon = true;
			visitCompoundStmt( stmt );
			m_appendLineEnd = true;
		}
	}

	void StmtVisitor::visitDiscardStmt( ast::stmt::Discard * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "discard;\n";
	}

	void StmtVisitor::visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )
	{
		if ( !stmt->empty() )
		{
			m_appendLineEnd = true;
			doAppendLineEnd();
			m_result += m_indent + "cbuffer " + stmt->getName();
			m_appendSemiColon = true;
			visitCompoundStmt( stmt );
			m_appendLineEnd = true;
		}
	}

	void StmtVisitor::visitCommentStmt( ast::stmt::Comment * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + stmt->getText() + "\n";
	}

	void StmtVisitor::visitCompoundStmt( ast::stmt::Compound * stmt )
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

	void StmtVisitor::visitDoWhileStmt( ast::stmt::DoWhile * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "do";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += m_indent + "while (" + doSubmit( stmt->getCtrlExpr() ) + ");\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		m_result += m_indent + "else if (" + doSubmit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseStmt( ast::stmt::Else * stmt )
	{
		m_result += m_indent + "else";
		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitForStmt( ast::stmt::For * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "for (" + doSubmit( stmt->getInitExpr() ) + "; ";
		m_result += doSubmit( stmt->getCtrlExpr() ) + "; ";
		m_result += doSubmit( stmt->getIncrExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitFragmentLayout( ast::stmt::FragmentLayout * stmt )
	{
		// Unsupported in HLSL :/
	}

	void StmtVisitor::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		auto type = stmt->getType();
		ast::var::VariableList params;

		if ( !type->empty() )
		{
			if ( stmt->isEntryPoint() )
			{
				auto it = type->begin();
				auto argType = ( *it )->getType();

				if ( argType->getKind() == ast::type::Kind::eGeometryInput )
				{
					params.push_back( *it );
					++it;
					params.push_back( *it );
					argType = ( *it )->getType();

					if ( argType->getKind() == ast::type::Kind::eGeometryOutput )
					{
						auto maxVertexCount = static_cast< ast::type::GeometryOutput const & >( *argType ).count;
						m_result += m_indent + "[maxvertexcount(" + std::to_string( maxVertexCount ) + ")]\n";
					}
				}
				else if ( argType->getKind() == ast::type::Kind::eTessellationControlInput )
				{
					auto & tessciType = static_cast< ast::type::TessellationControlInput const & >( *argType );
					argType = tessciType.getType();

					if ( argType->getKind() != ast::type::Kind::eVoid
						&& ( argType->getKind() != ast::type::Kind::eStruct
							|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
					{
						params.push_back( *it );
					}

					++it;
					argType = ( *it )->getType();

					if ( argType->getKind() == ast::type::Kind::eTessellationControlOutput )
					{
						auto & tesscoType = static_cast< ast::type::TessellationControlOutput const & >( *argType );
						m_result += m_indent + "[domain(\"" + getName( tesscoType.getDomain() ) + "\")]\n";
						m_result += m_indent + "[partitioning(\"" + getName( tesscoType.getPartitioning() ) + "\")]\n";
						m_result += m_indent + "[outputtopology(\"" + getName( tesscoType.getTopology(), tesscoType.getOrder() ) + "\")]\n";
						m_result += m_indent + "[outputcontrolpoints(" + std::to_string( tesscoType.getOutputVertices() ) + ")]\n";

						if ( !m_patchRoutines.empty() )
						{
							m_result += m_indent + "[patchconstantfunc(\"" + ( *m_patchRoutines.begin() ) + "\")]\n";
						}

						argType = tesscoType.getType();

						if ( argType->getKind() != ast::type::Kind::eVoid
							&& ( argType->getKind() != ast::type::Kind::eStruct
								|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
						{
							params.push_back( *it );
						}
					}
					else
					{
						params.push_back( *it );
					}
				}
				else
				{
					params.push_back( *it );
				}
			}
			else
			{
				params.insert( params.end(), type->begin(), type->end() );
			}
		}

		m_result += m_indent + getTypeName( type->getReturnType() );
		m_result += " " + stmt->getName() + "(";
		std::string sep;

		for ( auto & param : params )
		{
			m_result += sep + getDirectionName( *param )
				+ getTypeName( param->getType() ) + " "
				+ param->getName() + getTypeArraySize( param->getType() );
			sep = ", ";
		}

		m_result += ")";
		m_appendSemiColon = false;
		doAppendLineEnd();
		m_result += "\n" + m_indent + "{\n";
		auto save = m_indent;
		m_indent += "\t";
		visitContainerStmt( stmt );

		if ( stmt->getName() == "SDW_main"
			&& m_writerConfig.shaderStage == ast::ShaderStage::eVertex
			&& m_writerConfig.flipVertY )
		{
			m_result += m_indent + "sdwOutput.gl_Position.y = -sdwOutput.gl_Position.y;\n";
		}

		m_indent = save;
		m_result += m_indent + "}\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitIfStmt( ast::stmt::If * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "if (" + doSubmit( stmt->getCtrlExpr() ) + ")";
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

	void StmtVisitor::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += getTypeName( stmt->getVariable()->getType() ) + " ";
		m_result += stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );

		if ( stmt->getVariable()->isImplicit() )
		{
			m_result += ": register(t" + std::to_string( stmt->getBindingPoint() ) + ")";
		}
		else
		{
			m_result += ": register(u" + std::to_string( stmt->getBindingPoint() ) + ")";
		}

		m_result += ";\n";
	}

	void StmtVisitor::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		AST_Failure( "ast::stmt::InOutVariableDecl unexpected at that point" );
	}

	void StmtVisitor::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		AST_Failure( "ast::stmt::SpecialisationConstantDecl unexpected at that point" );
	}

	void StmtVisitor::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		doAppendLineEnd();
		m_result += "\n";

		if ( stmt->getWorkGroupsZ() == ast::stmt::InputComputeLayout::Uninit )
		{
			if ( stmt->getWorkGroupsY() == ast::stmt::InputComputeLayout::Uninit )
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

	void StmtVisitor::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		AST_Failure( "ast::stmt::InputGeometryLayout unexpected at that point" );
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		AST_Failure( "ast::stmt::OutputGeometryLayout unexpected at that point" );
	}

	void StmtVisitor::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
		AST_Failure( "ast::stmt::visitOutputTessellationControlLayoutStmt unexpected at that point" );
	}

	void StmtVisitor::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
		AST_Failure( "ast::stmt::PerVertexDecl unexpected at that point" );
	}

	void StmtVisitor::visitReturnStmt( ast::stmt::Return * stmt )
	{
		doAppendLineEnd();

		if ( stmt->getExpr() )
		{
			m_result += m_indent + "return " + doSubmit( stmt->getExpr() ) + ";\n";
		}
		else
		{
			m_result += m_indent + "return;\n";
		}
	}

	void StmtVisitor::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		AST_Failure( "ast::stmt::SampledImageDecl unexpected at that point" );
	}

	void StmtVisitor::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ": register(s" + std::to_string( stmt->getBindingPoint() ) + ");\n";
	}

	void StmtVisitor::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "RWByteAddressBuffer "
			+ stmt->getSsboName()
			+ ": register(u" + std::to_string( stmt->getBindingPoint() ) + ");\n";
	}

	void StmtVisitor::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "RWStructuredBuffer<" + getTypeName( stmt->getData()->getType() ) + "> "
			+ stmt->getData()->getName()
			+ ": register(u" + std::to_string( stmt->getBindingPoint() ) + ");\n";
	}

	void StmtVisitor::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		if ( stmt->getExpr()->getKind() == ast::expr::Kind::eAlias )
		{
			auto result = doSubmit( stmt->getExpr() );

			if ( !result.empty() )
			{
				m_result += m_indent + doSubmit( stmt->getExpr() ) + ";\n";
			}
		}
		else if ( stmt->getExpr()->getKind() != ast::expr::Kind::eIdentifier )
		{
			doAppendLineEnd();
			m_result += m_indent + doSubmit( stmt->getExpr() ) + ";\n";
		}
	}

	void StmtVisitor::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
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
				m_result += m_indent + getTypeName( member.type ) + " ";
				auto name = member.name;
				auto index = name.find( ":" );

				if ( index != std::string::npos )
				{
					// There are semantics for this variable.
					name = name.substr( 0, index )
						+ getTypeArraySize( member.type )
						+ name.substr( index );
				}
				else
				{
					name += getTypeArraySize( member.type );
				}

				m_result += name + ";\n";
			}

			m_indent = save;
			m_result += m_indent + "};\n";
		}
	}

	void StmtVisitor::visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )
	{
		doAppendLineEnd();

		if ( stmt->getCaseExpr() )
		{
			m_result += m_indent + "case " + doSubmit( stmt->getCaseExpr() ) + ":";
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

	void StmtVisitor::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "switch (" + doSubmit( stmt->getTestExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		auto & var = *stmt->getVariable();

		if ( var.isStatic() )
		{
			m_result += "static ";
		}

		m_result += getTypeName( var.getType() ) + " ";
		m_result += var.getName();
		m_result += getTypeArraySize( var.getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitWhileStmt( ast::stmt::While * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "while (" + doSubmit( stmt->getCtrlExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		doAppendLineEnd();
		m_result += "#define " + preproc->getName() + " " + doSubmit( preproc->getExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		doAppendLineEnd();
		m_result += "#elif " + doSubmit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElse( ast::stmt::PreprocElse * preproc )
	{
		doAppendLineEnd();
		m_result += "#else\n";
	}

	void StmtVisitor::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
		doAppendLineEnd();
		m_result += "#endif\n";
	}

	void StmtVisitor::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
		AST_Failure( "ast::stmt::PreprocExtension unexpected at that point" );
	}

	void StmtVisitor::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
		doAppendLineEnd();
		m_result += "#if " + doSubmit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		doAppendLineEnd();
		m_result += "#ifdef " + doSubmit( preproc->getIdentExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
		AST_Failure( "ast::stmt::PreprocVersion unexpected at that point" );
	}
}
