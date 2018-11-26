/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslStmtVisitor.hpp"

#include "ShaderWriter/GLSL/GlslExprVisitor.hpp"
#include "ShaderWriter/GLSL/GlslHelpers.hpp"

#include <ASTGenerator/Type/TypeImage.hpp>
#include <ASTGenerator/Type/TypeSampledImage.hpp>

#include <sstream>

namespace sdw::glsl
{
	//*************************************************************************

	namespace
	{
		std::string getDimension( type::ImageDim value )
		{
			switch ( value )
			{
			case type::ImageDim::e1D:
				return "1D";
			case type::ImageDim::e2D:
				return "2D";
			case type::ImageDim::e3D:
				return "3D";
			case type::ImageDim::eCube:
				return "Cube";
			case type::ImageDim::eRect:
				return "2DRect";
			case type::ImageDim::eBuffer:
				return "Buffer";
			default:
				assert( false && "Unsupported type::ImageDim" );
				return "Undefined";
			}
		}
		
		std::string getPrefix( type::Kind value )
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
				assert( false && "Unsupported type::Kind" );
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

		std::string getShadow( type::Trinary value )
		{
			return value == type::Trinary::eTrue
				? "Shadow"
				: std::string{};
		}

		std::string getType( type::Kind kind
			, type::ImageConfiguration const & config )
		{
			return ( kind == type::Kind::eSampledImage )
				? "sampler"
				: "image";
		}

		std::string getQualifiedName( type::Kind kind
			, type::ImageConfiguration const & config )
		{
			return getPrefix( config.sampledType )
				+ getType( kind, config )
				+ getDimension( config.dimension )
				+ getMS( config.isMS )
				+ getArray( config.isArrayed )
				+ getShadow( config.isDepth );
		}

		std::string getFormatName( type::ImageFormat format )
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
				assert( false && "Unsupported type::ImageFormat" );
				return "rgba32f";
			}
		}

		std::string getName( type::MemoryLayout layout )
		{
			switch ( layout )
			{
			case ast::type::MemoryLayout::eStd140:
				return "std140";
			case ast::type::MemoryLayout::eStd430:
				return "std430";
			default:
				assert( false && "Unsupported type::MemoryLayout" );
				return "std140";
			}
		}
	}

	//*************************************************************************

	std::string StmtVisitor::submit( stmt::Stmt * stmt
		, std::string indent )
	{
		std::string result;
		StmtVisitor vis{ result, std::move( indent ) };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( std::string & result
		, std::string indent )
		: m_result{ result }
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

	void StmtVisitor::visitContainerStmt( stmt::Container * stmt )
	{
		for ( auto & stmt : *stmt )
		{
			stmt->accept( this );
		}
	}

	void StmtVisitor::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		if ( !stmt->empty() )
		{
			m_appendLineEnd = true;
			doAppendLineEnd();
			m_result += m_indent;
			m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() );

			if ( m_hasDescriptorSet )
			{
				m_result += ", set=" + std::to_string( stmt->getDescriptorSet() );
			}

			m_result += ", " + getName( stmt->getMemoryLayout() ) + ") ";
			m_result += "uniform " + stmt->getName();
			m_appendSemiColon = true;
			visitCompoundStmt( stmt );
			m_appendLineEnd = true;
		}
	}

	void StmtVisitor::visitDiscardStmt( stmt::Discard * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "discard;\n";
	}

	void StmtVisitor::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
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
			m_result += m_indent + "}";
		}
	}

	void StmtVisitor::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "do";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";

		if ( stmt->getCtrlExpr()->getType()->getKind() != type::Kind::eBoolean )
		{
			m_result += m_indent + "while (bool(" + ExprVisitor::submit( stmt->getCtrlExpr() ) + "));\n";
		}
		else
		{
			m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ");\n";
		}

		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		if ( stmt->getCtrlExpr()->getType()->getKind() != type::Kind::eBoolean )
		{
			m_result += m_indent + "else if (bool(" + ExprVisitor::submit( stmt->getCtrlExpr() ) + "))";
		}
		else
		{
			m_result += m_indent + "else if (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		}

		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseStmt( stmt::Else * stmt )
	{
		m_result += m_indent + "else";
		m_appendSemiColon = false;
		m_appendLineEnd = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitForStmt( stmt::For * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "for (" + ExprVisitor::submit( stmt->getInitExpr() ) + "; ";

		if ( stmt->getCtrlExpr()->getType()->getKind() != type::Kind::eBoolean )
		{
			m_result += "bool(" + ExprVisitor::submit( stmt->getCtrlExpr() ) + "); ";
		}
		else
		{
			m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + "; ";
		}

		m_result += ExprVisitor::submit( stmt->getIncrExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
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
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitIfStmt( stmt::If * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();

		if ( stmt->getCtrlExpr()->getType()->getKind() != type::Kind::eBoolean )
		{
			m_result += m_indent + "if (bool(" + ExprVisitor::submit( stmt->getCtrlExpr() ) + "))";
		}
		else
		{
			m_result += m_indent + "if (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
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

	void StmtVisitor::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		doAppendLineEnd();
		auto type = stmt->getVariable()->getType();

		if ( type->getKind() == type::Kind::eArray )
		{
			type = std::static_pointer_cast< type::Array >( type )->getType();
		}

		assert( type->getKind() == type::Kind::eImage );
		auto image = std::static_pointer_cast< type::Image >( type );
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() );

		if ( m_hasDescriptorSet )
		{
			m_result += ", set=" + std::to_string( stmt->getDescriptorSet() );
		}

		if ( image->getConfig().accessKind == type::AccessKind::eRead )
		{
			m_result += ", readonly";
			m_result += ", " + getFormatName( image->getConfig().format );
		}
		else if ( image->getConfig().accessKind == type::AccessKind::eWrite )
		{
			m_result += ", writeonly";
		}
		else
		{
			m_result += ", " + getFormatName( image->getConfig().format );
		}

		m_result += ") uniform ";
		m_result += getQualifiedName( type::Kind::eImage, image->getConfig() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(" + getLocationName( *stmt->getVariable() ) + "=" + std::to_string( stmt->getLocation() ) + ") ";
		m_result += getDirectionName( *stmt->getVariable() ) + " ";
		m_result += getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )
	{
		assert( false && "No specialisation constant should remain at this stage" );
	}

	void StmtVisitor::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
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

	void StmtVisitor::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		doAppendLineEnd();
		auto type = stmt->getVariable()->getType();

		if ( type->getKind() == type::Kind::eArray )
		{
			type = std::static_pointer_cast< type::Array >( type )->getType();
		}

		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() );

		if ( m_hasDescriptorSet )
		{
			m_result += ", set=" + std::to_string( stmt->getDescriptorSet() );
		}

		m_result += ") ";
		assert( type->getKind() == type::Kind::eSampledImage );
		auto sampledImage = std::static_pointer_cast< type::SampledImage >( type );
		m_result += "uniform " + getQualifiedName( type::Kind::eSampledImage, sampledImage->getConfig() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
	}

	void StmtVisitor::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() );

		if ( m_hasDescriptorSet )
		{
			+", set=" + std::to_string( stmt->getDescriptorSet() );
		}

		m_result += ", " + getName( stmt->getMemoryLayout() ) + ") ";
		m_result += "buffer " + stmt->getSsboName();
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += ";\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() );

		if ( m_hasDescriptorSet )
		{
			m_result += ", set=" + std::to_string( stmt->getDescriptorSet() );
		}

		m_result += ", " + getName( stmt->getMemoryLayout() ) + ") ";
		m_result += "buffer " + stmt->getSsboName();
		auto data = stmt->getData();
		auto arrayType = std::static_pointer_cast< type::Array >( data->getType() );
		auto structType = std::static_pointer_cast< type::Struct >( arrayType->getType() );
		m_result += "\n{";
		m_result += "\n\t" + structType->getName() + " " + data->getName() + "[];";
		m_result += "\n} " + stmt->getSsboInstance()->getName() + ";\n";
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

		m_result += "\n";
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
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		if ( !stmt->getVariable()->isBuiltin() )
		{
			doAppendLineEnd();
			m_result += m_indent + getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
			m_result += getTypeArraySize( stmt->getVariable()->getType() );
			m_result += ";\n";
		}
	}

	void StmtVisitor::visitWhileStmt( stmt::While * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();

		if ( stmt->getCtrlExpr()->getType()->getKind() != type::Kind::eBoolean )
		{
			m_result += m_indent + "while (bool(" + ExprVisitor::submit( stmt->getCtrlExpr() ) + "))";
		}
		else
		{
			m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
		}

		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
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
		m_hasDescriptorSet = std::stoi( preproc->getName() ) >= 450;

		if ( m_hasDescriptorSet )
		{
			m_result += "#extension GL_KHR_vulkan_glsl : enable\n";
		}
	}

	//*************************************************************************
}
