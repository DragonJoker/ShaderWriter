/*
See LICENSE file in root folder
*/
#include "GlslStmtVisitor.hpp"

#include "GlslExprVisitor.hpp"
#include "GlslHelpers.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <sstream>
#pragma warning( pop )

namespace glsl
{
	//*************************************************************************

	namespace GlslStmtVisitorInternal
	{
		static std::string getFormatName( ast::type::ImageFormat format )
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
				AST_Failure( "Unsupported ast::type::ImageFormat" );
				return "rgba32f";
			}
		}

		static std::string getName( ast::type::MemoryLayout layout )
		{
			switch ( layout )
			{
			case ast::type::MemoryLayout::eStd140:
			case ast::type::MemoryLayout::eC:
				return "std140";
			case ast::type::MemoryLayout::eStd430:
				return "std430";
			case ast::type::MemoryLayout::eScalar:
				return "scalar";
			default:
				AST_Failure( "Unsupported ast::type::MemoryLayout" );
				return "std140";
			}
		}

		static bool hasExtension( GlslConfig const & writerConfig
			, GlslExtension const & extension )
		{
			return writerConfig.availableExtensions.end() != writerConfig.availableExtensions.find( extension );
		}

		static std::string getInOutLayout( GlslConfig const & writerConfig
			, ast::stmt::InOutVariableDecl const & stmt )
		{
			std::string result = "layout(";
			std::string sep;

			if ( hasExtension( writerConfig, ARB_explicit_attrib_location )
				&& hasExtension( writerConfig, ARB_separate_shader_objects ) )
			{
				result += getLocationName( *stmt.getVariable() ) + "=" + writeValue( stmt.getLocation() );
				sep = ", ";
			}

			if ( writerConfig.shaderStage == ast::ShaderStage::eGeometry
				&& stmt.getVariable()->isGeometryStream() )
			{
				result += sep + "stream=" + writeValue( stmt.getStreamIndex() );
				sep = ", ";
			}

			if ( writerConfig.shaderStage == ast::ShaderStage::eFragment
				&& stmt.getVariable()->isBlendIndex() )
			{
				result += sep + "index=" + writeValue( stmt.getBlendIndex() );
			}

			result += ")";

			if ( result == "layout()" )
			{
				result.clear();
			}

			return result;
		}

		static std::string getName( ast::FragmentOrigin value )
		{
			switch ( value )
			{
			case ast::FragmentOrigin::eLowerLeft:
				return std::string{};
			case ast::FragmentOrigin::eUpperLeft:
				return "origin_upper_left";
			default:
				AST_Failure( "Unsupported FragmentOrigin" );
				return std::string{};
			}
		}

		static std::string getName( ast::FragmentCenter value )
		{
			switch ( value )
			{
			case ast::FragmentCenter::eHalfPixel:
				return std::string{};
			case ast::FragmentCenter::eCenterInteger:
				return "pixel_center_integer";
			default:
				AST_Failure( "Unsupported FragmentCenter" );
				return std::string{};
			}
		}

		static void join( std::string & lhs
			, std::string const & rhs
			, std::string const & sep )
		{
			if ( lhs.empty() )
			{
				lhs = rhs;
				return;
			}

			if ( rhs.empty() )
			{
				return;
			}

			lhs = lhs + sep + rhs;
		}

		static std::string printVersion( uint32_t major = MAIN_VERSION_MAJOR
			, uint32_t minor = MAIN_VERSION_MINOR
			, uint32_t build = MAIN_VERSION_BUILD
			, uint32_t year = MAIN_VERSION_YEAR )
		{
			std::stringstream stream;
			stream.imbue( std::locale{ "C" } );
			stream << major << "." << minor << "." << build << "-" << year;
			return stream.str();
		}

		static std::string writeBlock( std::string indent
			, ast::type::Struct const & structType )
		{
			std::string result;
			result += structType.getName();

			if ( !structType.empty() )
			{
				result += "\n" + indent + "{\n";
				auto save = indent;
				indent += "\t";

				for ( auto & mbr : structType )
				{
					result += indent;

					if ( mbr.location != ast::type::Struct::InvalidLocation
						&& !hasFlag( structType.getFlag(), ast::var::Flag::ePatchOutput )
						&& !hasFlag( structType.getFlag(), ast::var::Flag::ePatchInput ) )
					{
						result += "layout( location=" + writeValue( mbr.location ) + " ) ";
						result += ( structType.isShaderInput()
							? std::string{ "in" }
						: std::string{ "out" } ) + " ";
					}

					result += getTypeName( mbr.type ) + " " + mbr.name;
					result += getTypeArraySize( mbr.type );
					result += ";\n";
				}

				indent = save;
				result += indent + "}";
			}

			return result;
		}

		static std::string writeStruct( std::string const & indent
			, ast::type::Struct const & structType
			, std::string const & instanceName )
		{
			std::string result;
			result += indent + "struct ";
			result += writeBlock( indent, structType );

			if ( !instanceName.empty() )
			{
				result += " " + instanceName;
			}

			result += ";\n";
			return result;
		}
	}

	//*************************************************************************

	std::string StmtVisitor::submit( GlslConfig const & writerConfig
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, ast::stmt::Stmt * stmt
		, std::string indent )
	{
		std::string result;
		result += "// This shader was generated using ShaderWriter version " + GlslStmtVisitorInternal::printVersion() + "\n";
		StmtVisitor vis{ writerConfig, aliases, result, std::move( indent ) };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( GlslConfig const & writerConfig
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, std::string & result
		, std::string indent )
		: m_writerConfig{ writerConfig }
		, m_aliases{ aliases }
		, m_indent{ std::move( indent ) }
		, m_result{ result }
	{
	}

	std::string StmtVisitor::doSubmit( ast::expr::Expr * expr )
	{
		return ExprVisitor::submit( expr, m_writerConfig, m_aliases );
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
			m_result += m_indent;
			m_result += "layout(";
			m_result += GlslStmtVisitorInternal::getName( stmt->getMemoryLayout() );
			doWriteBinding( stmt->getBindingPoint()
				, stmt->getDescriptorSet()
				, ", " );

			m_result += ") uniform " + stmt->getName();
			m_appendSemiColon = true;
			visitCompoundStmt( stmt );
			m_appendLineEnd = true;
		}
	}

	void StmtVisitor::visitDemoteStmt( ast::stmt::Demote * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "discard;\n";
	}

	void StmtVisitor::visitDispatchMeshStmt( ast::stmt::DispatchMesh * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "EmitMeshTasksEXT";
		m_result += "(" + doSubmit( stmt->getNumGroupsX() );
		m_result += ", " + doSubmit( stmt->getNumGroupsY() );
		m_result += ", " + doSubmit( stmt->getNumGroupsZ() );
		m_result += ");\n";
	}

	void StmtVisitor::visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )
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
		m_result += m_indent + "//" + stmt->getText() + "\n";
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
			m_result += m_indent + "while (bool(" + doSubmit( stmt->getCtrlExpr() ) + "));\n";
		}
		else
		{
			m_result += m_indent + "while (" + doSubmit( stmt->getCtrlExpr() ) + ");\n";
		}

		m_appendLineEnd = true;
	}

	void StmtVisitor::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += m_indent + "else if (bool(" + doSubmit( stmt->getCtrlExpr() ) + "))";
		}
		else
		{
			m_result += m_indent + "else if (" + doSubmit( stmt->getCtrlExpr() ) + ")";
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
		m_result += m_indent + "for (" + doSubmit( stmt->getInitExpr() ) + "; ";

		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += "bool(" + doSubmit( stmt->getCtrlExpr() ) + "); ";
		}
		else
		{
			m_result += doSubmit( stmt->getCtrlExpr() ) + "; ";
		}

		m_result += doSubmit( stmt->getIncrExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )
	{
		std::string origin = GlslStmtVisitorInternal::getName( stmt->getFragmentOrigin() );
		std::string center = GlslStmtVisitorInternal::getName( stmt->getFragmentCenter() );

		if ( !origin.empty() || !center.empty() )
		{
			m_result += "layout(";
			m_result += origin;
			m_result += ( ( origin.empty() || center.empty() )
				? std::string{}
				: std::string{ ", " } );
			m_result += center;
			m_result += ") in vec4 gl_FragCoord;\n";
		}
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
			m_result = m_result
				+ sep + getDirectionName( *param )
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

		if ( stmt->isEntryPoint()
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

	void StmtVisitor::visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(";
		doWriteBinding( stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, "" );
		m_result += ") uniform accelerationStructureEXT";
		GlslStmtVisitorInternal::join( m_result, stmt->getVariable()->getName(), " " );
		m_result += ";\n";
	}

	void StmtVisitor::visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(buffer_reference";

		if ( auto structType = getStructType( stmt->getType() ) )
		{
			m_result += ", " + GlslStmtVisitorInternal::getName( structType->getMemoryLayout() );
			m_result += ") buffer " + getTypeName( stmt->getType() ) + " { ";
			m_result += getTypeName( structType->front().type ) + " " + structType->front().name + getTypeArraySize( structType->front().type ) + "; }";
		}
		else
		{
			m_result += ") buffer " + getTypeName( stmt->getType() ) + "s { ";
			m_result += getTypeName( stmt->getType() ) + getTypeArraySize( stmt->getType() ) + "; }";
		}

		m_result += ";\n";
	}

	void StmtVisitor::visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "hitAttributeEXT";
		GlslStmtVisitorInternal::join( m_result, getTypeName( stmt->getVariable()->getType() ), " " );
		GlslStmtVisitorInternal::join( m_result, stmt->getVariable()->getName(), " " );
		m_result += ";\n";
	}

	void StmtVisitor::visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )
	{
		doAppendLineEnd();
		auto var = stmt->getVariable();
		std::string name = "callableDataEXT";

		if ( var->isIncomingCallableData() )
		{
			name = "callableDataInEXT";
		}

		m_result += m_indent + "layout(" + getLocationName( *var ) + "=" + writeValue( stmt->getLocation() ) + ")";
		GlslStmtVisitorInternal::join( m_result, name, " " );
		GlslStmtVisitorInternal::join( m_result, getTypeName( var->getType() ), " " );
		GlslStmtVisitorInternal::join( m_result, var->getName(), " " );
		m_result += ";\n";
	}

	void StmtVisitor::visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )
	{
		doAppendLineEnd();
		auto var = stmt->getVariable();
		std::string name = "rayPayloadEXT";

		if ( var->isIncomingRayPayload() )
		{
			name = "rayPayloadInEXT";
		}

		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLocationName( *var ) + "=" + writeValue( stmt->getLocation() ) + ")";
		GlslStmtVisitorInternal::join( m_result, name, " " );
		GlslStmtVisitorInternal::join( m_result, getTypeName( stmt->getVariable()->getType() ), " " );
		GlslStmtVisitorInternal::join( m_result, stmt->getVariable()->getName(), " " );
		m_result += ";\n";
	}

	void StmtVisitor::visitIfStmt( ast::stmt::If * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();

		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += m_indent + "if (bool(" + doSubmit( stmt->getCtrlExpr() ) + "))";
		}
		else
		{
			m_result += m_indent + "if (" + doSubmit( stmt->getCtrlExpr() ) + ")";
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
		m_result += GlslStmtVisitorInternal::getFormatName( image->getConfig().format );

		if ( GlslStmtVisitorInternal::hasExtension( m_writerConfig, ARB_shading_language_420pack ) )
		{
			doWriteBinding( stmt->getBindingPoint()
				, stmt->getDescriptorSet()
				, ", " );
		}

		m_result += ") ";
		m_result += "uniform ";
		//m_result += getAccessQualifierName( image->getConfig() ) + " ";
		m_result += getQualifiedName( ast::type::Kind::eImage, image->getConfig() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "ignoreIntersectionEXT;\n";
	}

	void StmtVisitor::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + GlslStmtVisitorInternal::getInOutLayout( m_writerConfig, *stmt );
		GlslStmtVisitorInternal::join( m_result, getInterpolationQualifier( *stmt->getVariable() ), " " );
		GlslStmtVisitorInternal::join( m_result, getDirectionName( *stmt->getVariable() ), " " );
		GlslStmtVisitorInternal::join( m_result, getTypeName( stmt->getVariable()->getType() ), " " );
		GlslStmtVisitorInternal::join( m_result, stmt->getVariable()->getName(), " " );

		if ( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eArray
			&& ( m_writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
				|| m_writerConfig.shaderStage == ast::ShaderStage::eTessellationEvaluation ) )
		{
			m_result += "[]";
		}
		else
		{
			m_result += getTypeArraySize( stmt->getVariable()->getType() );
		}

		m_result += ";\n";
	}

	void StmtVisitor::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		AST_Failure( "No specialisation constant should remain at this stage" );
	}

	void StmtVisitor::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		doAppendLineEnd();

		if ( stmt->getWorkGroupsZ() == 1 )
		{
			if ( stmt->getWorkGroupsY() == 1 )
			{
				m_result += m_indent + "layout(local_size_x=" + writeValue( stmt->getWorkGroupsX() ) + ") in;\n";
			}
			else
			{
				m_result += m_indent + "layout(local_size_x=" + writeValue( stmt->getWorkGroupsX() )
					+ ", local_size_y=" + writeValue( stmt->getWorkGroupsY() ) + ") in;\n";
			}
		}
		else
		{
			m_result += m_indent + "layout(local_size_x=" + writeValue( stmt->getWorkGroupsX() )
				+ ", local_size_y=" + writeValue( stmt->getWorkGroupsY() )
				+ ", local_size_z=" + writeValue( stmt->getWorkGroupsZ() ) + ") in;\n";
		}
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ") in;\n";
	}

	void StmtVisitor::visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getDomain() );
		m_result += ", " + getLayoutName( stmt->getPartitioning() );
		m_result += ", " + getLayoutName( stmt->getPrimitiveOrdering() );
		m_result += ") in;\n";
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ", max_vertices = " + writeValue( stmt->getPrimCount() ) + ") out;\n";
	}

	void StmtVisitor::visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(" + getLayoutName( stmt->getTopology() ) + ") out;\n";
		m_result += m_indent + "layout(max_vertices = " + writeValue( stmt->getMaxVertices() ) + ", max_primitives = " + writeValue( stmt->getMaxPrimitives() ) + ") out;\n";
	}

	void StmtVisitor::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "layout(vertices=" + writeValue( stmt->getOutputVertices() ) + ") out;\n";
	}

	void StmtVisitor::visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )
	{
	}

	void StmtVisitor::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
		if ( stmt->getSource() != ast::stmt::PerVertexDecl::Source::eMeshOutput )
		{
			m_appendLineEnd = true;
			doAppendLineEnd();
			std::string decl;
			decl += "gl_PerVertex\n";

			decl += m_indent + "{\n";
			decl += m_indent + "	vec4 gl_Position;\n";
			decl += m_indent + "	float gl_PointSize;\n";
			decl += m_indent + "	float gl_ClipDistance[];\n";
			decl += m_indent + "	float gl_CullDistance[];\n";
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
			case ast::stmt::PerVertexDecl::Source::eMeshOutput:
				m_result += m_indent + "out " + decl + " gl_MeshVerticesNV[];\n";
				break;
			}

			m_appendLineEnd = true;
		}
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
		doAppendLineEnd();
		auto type = stmt->getVariable()->getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		m_result += m_indent;

		if ( GlslStmtVisitorInternal::hasExtension( m_writerConfig, ARB_shading_language_420pack ) )
		{
			m_result += "layout(";

			doWriteBinding( stmt->getBindingPoint()
				, stmt->getDescriptorSet()
				, "" );

			m_result += ") ";
		}

		assert( type->getKind() == ast::type::Kind::eSampledImage );
		auto sampledImage = std::static_pointer_cast< ast::type::SampledImage >( type );
		m_result += "uniform " + getQualifiedName( ast::type::Kind::eSampledImage, sampledImage->getConfig() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )
	{
		doAppendLineEnd();
		auto type = stmt->getVariable()->getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		m_result += m_indent;

		if ( GlslStmtVisitorInternal::hasExtension( m_writerConfig, ARB_shading_language_420pack ) )
		{
			m_result += "layout(";

			doWriteBinding( stmt->getBindingPoint()
				, stmt->getDescriptorSet()
				, "" );

			m_result += ") ";
		}

		assert( type->getKind() == ast::type::Kind::eCombinedImage );
		auto sampledImage = std::static_pointer_cast< ast::type::CombinedImage >( type );
		m_result += "uniform " + getQualifiedName( ast::type::Kind::eCombinedImage, sampledImage->getConfig(), sampledImage->isComparison() ) + " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(";
		doWriteBinding( stmt->getBindingPoint()
			, stmt->getDescriptorSet()
			, "" );
		m_result += ") uniform sampler";
		
		if ( static_cast< ast::type::Sampler const & >( *getNonArrayType( stmt->getVariable()->getType() ) ).isComparison() )
		{
			m_result += "Shadow";
		}

		m_result += " " + stmt->getVariable()->getName();
		m_result += getTypeArraySize( stmt->getVariable()->getType() );
		m_result += ";\n";
	}

	void StmtVisitor::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent;
		m_result += "layout(";
		m_result += GlslStmtVisitorInternal::getName( stmt->getMemoryLayout() );
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
		m_result += GlslStmtVisitorInternal::getName( stmt->getMemoryLayout() );
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
		if ( stmt->getExpr()->getKind() == ast::expr::Kind::eAlias )
		{
			doSubmit( stmt->getExpr() );
		}
		else if ( stmt->getExpr()->getKind() != ast::expr::Kind::eIdentifier )
		{
			auto result = doSubmit( stmt->getExpr() );

			if ( !result.empty() )
			{
				doAppendLineEnd();
				m_result += m_indent + result + ";\n";
			}
		}
	}

	void StmtVisitor::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += GlslStmtVisitorInternal::writeStruct( m_indent, *stmt->getType(), std::string{} );
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

		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		m_result += m_indent + "switch (" + doSubmit( stmt->getTestExpr() ) + ")";
		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
		m_appendLineEnd = true;
	}

	void StmtVisitor::visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )
	{
		m_result += m_indent + "terminateRayEXT;\n";
	}

	void StmtVisitor::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		if ( !stmt->getVariable()->isBuiltin() )
		{
			doAppendLineEnd();
			auto var = stmt->getVariable();

			if ( var->isPerTaskNV() )
			{
				auto structType = getStructType( var->getType() );

				if ( structType && !structType->empty() )
				{
					m_result += m_indent + "taskNV";
					GlslStmtVisitorInternal::join( m_result, getDirectionName( *var ), " " );
					m_result += " " + GlslStmtVisitorInternal::writeBlock( m_indent, *structType );
					GlslStmtVisitorInternal::join( m_result, var->getName(), " " );
					m_result += ";\n";
				}
			}
			else if ( var->isPerTask() )
			{
				auto structType = getStructType( var->getType() );

				if ( structType && !structType->empty() )
				{
					m_appendLineEnd = true;
					doAppendLineEnd();
					m_result += GlslStmtVisitorInternal::writeStruct( m_indent, *structType, std::string{} );
				}

				if ( !structType || !structType->empty() )
				{
					m_result += m_indent + "taskPayloadSharedEXT";
					GlslStmtVisitorInternal::join( m_result, getTypeName( var->getType() ), " " );
					GlslStmtVisitorInternal::join( m_result, var->getName(), " " );
					m_result += ";\n";
				}
			}
			else
			{
				m_result += m_indent;
				GlslStmtVisitorInternal::join( m_result, getDirectionName( *var ), " " );
				GlslStmtVisitorInternal::join( m_result, getInterpolationQualifier( *var ), " " );
				GlslStmtVisitorInternal::join( m_result, getTypeName( var->getType() ), " " );
				GlslStmtVisitorInternal::join( m_result, var->getName(), " " );
				m_result += getTypeArraySize( var->getType() );
				m_result += ";\n";
			}
		}
	}

	void StmtVisitor::visitWhileStmt( ast::stmt::While * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();

		if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
		{
			m_result += m_indent + "while (bool(" + doSubmit( stmt->getCtrlExpr() ) + "))";
		}
		else
		{
			m_result += m_indent + "while (" + doSubmit( stmt->getCtrlExpr() ) + ")";
		}

		m_appendSemiColon = false;
		visitCompoundStmt( stmt );
		m_result += "\n";
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
		doAppendLineEnd();
		m_result += "#extension " + preproc->getName() + ": " + getStatusName( preproc->getStatus() ) + "\n";
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
		doAppendLineEnd();
		m_result += "#version " + preproc->getName() + "\n";
	}

	void StmtVisitor::doWriteBinding( uint32_t binding
		, uint32_t set
		, std::string sep )
	{
		if ( binding != InvalidIndex
			&& GlslStmtVisitorInternal::hasExtension( m_writerConfig, ARB_shading_language_420pack ) )
		{
			m_result += sep + "binding=" + writeValue( binding );
			sep = ", ";

			if ( set != InvalidIndex && m_writerConfig.wantedVersion >= v4_6 )
			{
				m_result += sep + "set=" + writeValue( set );
			}
		}
	}

	//*************************************************************************
}
