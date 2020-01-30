/*
See LICENSE file in root folder
*/
#include "GlslStmtVisitor.hpp"

#include "GlslExprVisitor.hpp"
#include "GlslHelpers.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

#include <sstream>

namespace glsl
{
	//*************************************************************************

	namespace
	{
		std::string getDimension( ast::type::ImageDim value )
		{
			switch ( value )
			{
			case ast::type::ImageDim::e1D:
				return "1D";
			case ast::type::ImageDim::e2D:
				return "2D";
			case ast::type::ImageDim::e3D:
				return "3D";
			case ast::type::ImageDim::eCube:
				return "Cube";
			case ast::type::ImageDim::eRect:
				return "2DRect";
			case ast::type::ImageDim::eBuffer:
				return "Buffer";
			default:
				assert( false && "Unsupported ast::type::ImageDim" );
				return "Undefined";
			}
		}
		
		std::string getPrefix( ast::type::Kind value )
		{
			switch ( value )
			{
			case ast::type::Kind::eInt:
				return "i";

			case ast::type::Kind::eUInt:
				return "u";

			case ast::type::Kind::eFloat:
				return std::string{};

			default:
				assert( false && "Unsupported ast::type::Kind" );
				return std::string{};
			}
		}

		std::string getArray( bool value )
		{
			return value
				? "Array"
				: std::string{};
		}

		std::string getMS( bool value )
		{
			return value
				? "MS"
				: std::string{};
		}

		std::string getShadow( ast::type::Trinary value )
		{
			return value == ast::type::Trinary::eTrue
				? "Shadow"
				: std::string{};
		}

		std::string getType( ast::type::Kind kind
			, ast::type::ImageConfiguration const & config )
		{
			return ( kind == ast::type::Kind::eSampledImage )
				? "sampler"
				: "image";
		}

		std::string getQualifiedName( ast::type::Kind kind
			, ast::type::ImageConfiguration const & config )
		{
			return getPrefix( config.sampledType )
				+ getType( kind, config )
				+ getDimension( config.dimension )
				+ getMS( config.isMS )
				+ getArray( config.isArrayed )
				+ getShadow( config.isDepth );
		}

		std::string getFormatName( ast::type::ImageFormat format )
		{
			switch ( format )
			{
			case ast::type::ImageFormat::eUnknown:
				return "rgba32f";
			case ast::type::ImageFormat::eRgba32f:
				return "rgba32f";
			case ast::type::ImageFormat::eRgba16f:
				return "rgba16f";
			case ast::type::ImageFormat::eRg32f:
				return "rg32f";
			case ast::type::ImageFormat::eRg16f:
				return "rg16f";
			case ast::type::ImageFormat::eR32f:
				return "r32f";
			case ast::type::ImageFormat::eR16f:
				return "r16f";
			case ast::type::ImageFormat::eRgba32i:
				return "rgba32i";
			case ast::type::ImageFormat::eRgba16i:
				return "rgba16i";
			case ast::type::ImageFormat::eRgba8i:
				return "rgba8i";
			case ast::type::ImageFormat::eRg32i:
				return "rg32i";
			case ast::type::ImageFormat::eRg16i:
				return "rg16i";
			case ast::type::ImageFormat::eRg8i:
				return "rg8i";
			case ast::type::ImageFormat::eR32i:
				return "r32i";
			case ast::type::ImageFormat::eR16i:
				return "r16i";
			case ast::type::ImageFormat::eR8i:
				return "r8i";
			case ast::type::ImageFormat::eRgba32u:
				return "rgba32ui";
			case ast::type::ImageFormat::eRgba16u:
				return "rgba16ui";
			case ast::type::ImageFormat::eRgba8u:
				return "rgba8ui";
			case ast::type::ImageFormat::eRg32u:
				return "rg32ui";
			case ast::type::ImageFormat::eRg16u:
				return "rg16ui";
			case ast::type::ImageFormat::eRg8u:
				return "rg8ui";
			case ast::type::ImageFormat::eR32u:
				return "r32ui";
			case ast::type::ImageFormat::eR16u:
				return "r16ui";
			case ast::type::ImageFormat::eR8u:
				return "r8ui";
			default:
				assert( false && "Unsupported ast::type::ImageFormat" );
				return "rgba32f";
			}
		}

		std::string getName( ast::type::MemoryLayout layout )
		{
			switch ( layout )
			{
			case ast::type::MemoryLayout::eStd140:
				return "std140";
			case ast::type::MemoryLayout::eStd430:
				return "std430";
			default:
				assert( false && "Unsupported ast::type::MemoryLayout" );
				return "std140";
			}
		}
	}

	//*************************************************************************

	std::string StmtVisitor::submit( GlslConfig const & writerConfig
		, ast::stmt::Stmt * stmt
		, std::string indent )
	{
		std::string result;
		StmtVisitor vis{ writerConfig, result, std::move( indent ) };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( GlslConfig const & writerConfig
		, std::string & result
		, std::string indent )
		: m_writerConfig{ writerConfig }
		, m_result{ result }
		, m_indent{ std::move( indent ) }
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

	void StmtVisitor::visitContainerStmt( ast::stmt::Container * stmt )
	{
		for ( auto & stmt : *stmt )
		{
			stmt->accept( this );
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
			m_result += m_indent;
			m_result += "layout(";
			m_result += getName( stmt->getMemoryLayout() );
			doWriteBinding( stmt->getBindingPoint()
				, stmt->getDescriptorSet()
				, ", " );

			m_result += ") uniform " + stmt->getName();
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
			m_result += m_indent;
			m_result += "layout(push_constant) ";
			m_result += "uniform " + stmt->getName();
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
			m_result += m_indent + "}";
		}
	}

	void StmtVisitor::visitDoWhileStmt( ast::stmt::DoWhile * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "do";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";

		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += m_indent + "while (bool(" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + "));\n";
		}
		else
		{
			m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + ");\n";
		}

		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += m_indent + "else if (bool(" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + "))";
		}
		else
		{
			m_result += m_indent + "else if (" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + ")";
		}

		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseStmt( ast::stmt::Else * stmt )
	{
		m_result += m_indent + "else";
		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitForStmt( ast::stmt::For * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "for (" + ExprVisitor::submit( stmt->getInitExpr(), m_writerConfig ) + "; ";

		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += "bool(" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + "); ";
		}
		else
		{
			m_result += ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + "; ";
		}

		m_result += ExprVisitor::submit( stmt->getIncrExpr(), m_writerConfig ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		auto type = stmt->getType();
		m_result += m_indent + getTypeName( type->getReturnType() );
		m_result += " " + stmt->getName() + "(";
		std::string sep;

		for ( auto & param : *type )
		{
			m_result += sep + getDirectionName( *param )
				+ " " + getTypeName( param->getType() )
				+ " " + param->getName() + getTypeArraySize( param->getType() );
			sep = ", ";
		}

		m_result += ")";
		m_appendSemiColon = false;
		doAppendLineEnd();
		m_result += "\n" + m_indent + "{\n";
		auto save = m_indent;
		m_indent += "\t";
		visitContainerStmt( stmt );

		if ( stmt->getName() == "main"
			&& m_writerConfig.shaderStage == ast::ShaderStage::eVertex )
		{
			if ( m_writerConfig.flipVertY )
			{
				m_result += m_indent + "gl_Position.y = -gl_Position.y;\n";
			}

			if ( m_writerConfig.fixupClipDepth )
			{
				m_result += m_indent + "gl_Position.z = (gl_Position.z + gl_Position.w) * 0.5;\n";
			}
		}

		m_indent = save;

		if ( m_appendSemiColon )
		{
			m_result += m_indent + "};\n";
		}
		else
		{
			m_result += m_indent + "}";
		}

		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitIfStmt( ast::stmt::If * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();

		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += m_indent + "if (bool(" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + "))";
		}
		else
		{
			m_result += m_indent + "if (" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + ")";
		}

		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";

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
		auto type = stmt->getVariable()->getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		assert( type->getKind() == ast::type::Kind::eImage );
		auto image = std::static_pointer_cast< ast::type::Image >( type );
		m_result += m_indent;
		m_result += "layout(";

		if ( image->getConfig().accessKind == ast::type::AccessKind::eRead )
		{
			m_result += "readonly";
			m_result += ", " + getFormatName( image->getConfig().format );
		}
		else if ( image->getConfig().accessKind == ast::type::AccessKind::eWrite )
		{
			m_result += "writeonly";
		}
		else
		{
			m_result += getFormatName( image->getConfig().format );
		}

		doWriteBinding( stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, ", " );

		m_result += ") uniform ";
		m_result += getQualifiedName( ast::type::Kind::eImage, image->getConfig() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(" + getLocationName( *stmt->getVariable() ) + "=" + std::to_string( stmt->getLocation() ) + ") ";
		m_result += getFlatnessName( *stmt->getVariable() );
		m_result += getDirectionName( *stmt->getVariable() ) + " ";
		m_result += getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		assert( false && "No specialisation constant should remain at this stage" );
	}

	void StmtVisitor::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		doAppendLineEnd();

		if ( stmt->getWorkGroupsZ() == 1 )
		{
			if ( stmt->getWorkGroupsY() == 1 )
			{
				m_result += m_indent + "layout(local_size_x=" + std::to_string( stmt->getWorkGroupsX() ) + ") in;\n";
			}
			else
			{
				m_result += m_indent + "layout(local_size_x=" + std::to_string( stmt->getWorkGroupsX() )
					+ ", local_size_y=" + std::to_string( stmt->getWorkGroupsY() ) + ") in;\n";
			}
		}
		else
		{
			m_result += m_indent + "layout(local_size_x=" + std::to_string( stmt->getWorkGroupsX() )
				+ ", local_size_y=" + std::to_string( stmt->getWorkGroupsY() )
				+ ", local_size_z=" + std::to_string( stmt->getWorkGroupsZ() ) + ") in;\n";
		}
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ") in;\n";
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ", max_vertices = " + std::to_string( stmt->getPrimCount() ) + ") out;\n";
	}

	void StmtVisitor::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
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
		case ast::stmt::PerVertexDecl::Source::eVertexOutput:
			m_result += m_indent + "out " + decl + ";\n";
			break;
		case ast::stmt::PerVertexDecl::Source::eTessellationControlInput:
		case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
			m_result += m_indent + "in " + decl + " gl_in[gl_MaxPatchVertices];\n";
			break;
		case ast::stmt::PerVertexDecl::Source::eTessellationControlOutput:
			m_result += m_indent + "out " + decl + " gl_out[];\n";
			break;
		case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
			m_result += m_indent + "out " + decl + ";\n";
			break;
		case ast::stmt::PerVertexDecl::Source::eGeometryInput:
			m_result += m_indent + "in " + decl + " gl_in[];\n";
			break;
		case ast::stmt::PerVertexDecl::Source::eGeometryOutput:
			m_result += m_indent + "out " + decl + ";\n";
			break;
		}
	}

	void StmtVisitor::visitReturnStmt( ast::stmt::Return * stmt )
	{
		doAppendLineEnd();

		if ( stmt->getExpr() )
		{
			m_result += m_indent + "return " + ExprVisitor::submit( stmt->getExpr(), m_writerConfig ) + ";\n";
		}
		else
		{
			m_result += m_indent + "return;\n";
		}
	}

	void StmtVisitor::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		doAppendLineEnd();
		auto type = stmt->getVariable()->getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		m_result += m_indent;
		m_result += "layout(";

		doWriteBinding( stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, "" );

		m_result += ") ";
		assert( type->getKind() == ast::type::Kind::eSampledImage );
		auto sampledImage = std::static_pointer_cast< ast::type::SampledImage >( type );
		m_result += "uniform " + getQualifiedName( ast::type::Kind::eSampledImage, sampledImage->getConfig() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
	}

	void StmtVisitor::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(";
		m_result += getName( stmt->getMemoryLayout() );
		doWriteBinding( stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, ", " );
		m_result += ") buffer " + stmt->getSsboName();
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += ";\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(";
		m_result += getName( stmt->getMemoryLayout() );
		doWriteBinding( stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, ", " );
		m_result += ") buffer " + stmt->getSsboName();
		auto data = stmt->getData();
		auto arrayType = std::static_pointer_cast< ast::type::Array >( data->getType() );
		m_result += "\n{";
		m_result += "\n\t" + getTypeName( arrayType->getType() ) + " " + data->getName();
		m_result += getTypeArraySize( arrayType ) + ";";
		m_result += "\n} " + stmt->getSsboInstance()->getName() + ";\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + ExprVisitor::submit( stmt->getExpr(), m_writerConfig ) + ";\n";
	}

	void StmtVisitor::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "struct " + stmt->getType()->getName();

		if ( !stmt->getType()->empty() )
		{
			m_result += "\n" + m_indent + "{\n";
			auto save = m_indent;
			m_indent += "\t";

			for ( auto & member : *stmt->getType() )
			{
				m_result += m_indent + getTypeName( member.type ) + " " + member.name;
				m_result += getTypeArraySize( member.type );
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

	void StmtVisitor::visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )
	{
		doAppendLineEnd();

		if ( stmt->getCaseExpr() )
		{
			m_result += m_indent + "case " + ExprVisitor::submit( stmt->getCaseExpr(), m_writerConfig ) + ":";
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

		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "switch (" + ExprVisitor::submit( stmt->getTestExpr(), m_writerConfig ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		if ( !stmt->getVariable()->isBuiltin() )
		{
			doAppendLineEnd();
			m_result += m_indent + getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
			m_result += getTypeArraySize( stmt->getVariable()->getType() );
			m_result += ";\n";
		}
	}

	void StmtVisitor::visitWhileStmt( ast::stmt::While * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();

		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += m_indent + "while (bool(" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + "))";
		}
		else
		{
			m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr(), m_writerConfig ) + ")";
		}

		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		doAppendLineEnd();
		m_result += "#define " + preproc->getName() + " " + ExprVisitor::submit( preproc->getExpr(), m_writerConfig ) + "\n";
	}

	void StmtVisitor::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		doAppendLineEnd();
		m_result += "#elif " + ExprVisitor::submit( preproc->getCtrlExpr(), m_writerConfig ) + "\n";
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
		doAppendLineEnd();
		m_result += "#extension " + preproc->getName() + ": " + getStatusName( preproc->getStatus() ) + "\n";
	}

	void StmtVisitor::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
		doAppendLineEnd();
		m_result += "#if " + ExprVisitor::submit( preproc->getCtrlExpr(), m_writerConfig ) + "\n";
	}

	void StmtVisitor::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		doAppendLineEnd();
		m_result += "#ifdef " + ExprVisitor::submit( preproc->getIdentExpr(), m_writerConfig ) + "\n";
	}

	void StmtVisitor::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
		doAppendLineEnd();
		m_result += "#version " + preproc->getName() + "\n";
	}

	void StmtVisitor::doWriteBinding( uint32_t binding
		, uint32_t set
		, std::string sep )
	{
		if ( binding != InvalidIndex )
		{
			m_result += sep + "binding=" + std::to_string( binding );
			sep = ", ";
		}

		if ( set != InvalidIndex && m_writerConfig.shaderLanguageVersion >= 460 )
		{
			m_result += sep + "set=" + std::to_string( set );
		}
	}

	//*************************************************************************
}
