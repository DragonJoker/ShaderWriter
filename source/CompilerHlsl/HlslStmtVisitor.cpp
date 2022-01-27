/*
See LICENSE file in root folder
*/
#include "HlslStmtVisitor.hpp"

#include "HlslExprVisitor.hpp"

#pragma warning( disable:4365 )
#include <sstream>

namespace hlsl
{
	namespace
	{
		std::string getName( ast::type::PatchDomain value )
		{
			switch ( value )
			{
			case ast::type::PatchDomain::eIsolines:
				return "isoline";
			case ast::type::PatchDomain::eTriangles:
				return "tri";
			case ast::type::PatchDomain::eQuads:
				return "quad";
			default:
				AST_Failure( "Unsupported type::PatchDomain." );
				return "undefined";
			}
		}

		std::string getName( ast::type::Partitioning value )
		{
			switch ( value )
			{
			case ast::type::Partitioning::eEqual:
				return "integer";
			case ast::type::Partitioning::eFractionalEven:
				return "fractionaleven";
			case ast::type::Partitioning::eFractionalOdd:
				return "fractionalodd";
			default:
				AST_Failure( "Unsupported type::Partitioning." );
				return "undefined";
			}
		}

		std::string getName( ast::type::OutputTopology domain
			, ast::type::PrimitiveOrdering order )
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
				case ast::type::PrimitiveOrdering::eCW:
					return "triangle_cw";
				case ast::type::PrimitiveOrdering::eCCW:
					return "triangle_ccw";
				default:
					AST_Failure( "Unsupported type::PrimitiveOrdering." );
					return "UNDEFINED";
				}
			default:
				AST_Failure( "Unsupported type::OutputTopology." );
				return "UNDEFINED";
			}
		}

		std::string getName( ast::type::OutputTopology topology )
		{
			switch ( topology )
			{
			case ast::type::OutputTopology::ePoint:
				return "point";
			case ast::type::OutputTopology::eLine:
				return "line";
			case ast::type::OutputTopology::eTriangle:
				return "triangle";
			default:
				AST_Failure( "Unsupported type::OutputTopology." );
				return "UNDEFINED";
			}
		}

		std::string writeIOMember( ast::ShaderStage stage
			, ast::type::TypePtr type
			, std::string name
			, ast::Builtin builtin
			, bool isInput
			, uint32_t builtinIndex
			, uint32_t location
			, Semantic & intSem
			, Semantic & fltSem )
		{
			auto & cache = type->getCache();
			std::string semantic;

			if ( builtin == ast::Builtin::eClipDistance )
			{
				type = cache.getVec4F();
				semantic = ": SV_ClipDistance" + std::to_string( builtinIndex );
			}
			else if ( builtin == ast::Builtin::eCullDistance )
			{
				// Merged with SV_ClipDistance ?
			}
			else
			{
				if ( isSignedIntType( type->getKind() )
					|| isUnsignedIntType( type->getKind() ) )
				{
					semantic = ": " + getSemantic( stage, builtin, isInput, location, type, intSem );
				}
				else
				{
					semantic = ": " + getSemantic( stage, builtin, isInput, location, type, fltSem );
				}
			}

			if ( semantic.empty() )
			{
				return semantic;
			}

			std::string result;

			if ( isMeshStage( stage )
				&& builtin == ast::Builtin::ePrimitiveIndicesNV )
			{
				result += "indices ";
			}

			result += getTypeName( type ) + " ";
			result += adaptName( name );
			result += getTypeArraySize( type );

			if ( builtin != ast::Builtin::ePrimitiveIndicesNV )
			{
				result += semantic;
			}

			return result;
		}

		std::string writeIOMember( ast::ShaderStage stage
			, ast::type::Struct::Member const & member
			, bool isInput
			, Semantic & intSem
			, Semantic & fltSem )
		{
			return writeIOMember( stage
				, member.type
				, member.name
				, member.builtin
				, isInput
				, member.builtinIndex
				, member.location
				, intSem
				, fltSem ) + ";\n";
		}

		std::string writeIOMembers( ast::ShaderStage stage
			, std::string const & indent
			, ast::type::Struct const & structType )
		{
			Semantic rintSem = { "BLENDINDICES", 0u };
			Semantic rfltSem = { "TEXCOORD", 0u };
			Semantic * pintSem = &rintSem;
			Semantic * pfltSem = &rfltSem;
			std::string result;
			bool isInput = true;

			if ( structType.isShaderOutput() )
			{
				isInput = false;

				if ( stage == ast::ShaderStage::eFragment )
				{
					rintSem.name = "SV_Target";
					pfltSem = &rintSem;
				}
			}

			for ( auto & mbr : structType )
			{
				result += indent + writeIOMember( stage, mbr, isInput, *pintSem, *pfltSem );
			}

			return result;
		}

		std::string writeBaseMember( ast::type::Struct::Member const & member )
		{
			std::string result = getTypeName( member.type ) + " ";
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

			result += name + ";\n";
			return result;
		}

		std::string writeBaseMembers( std::string indent
			, ast::type::Struct const & structType )
		{
			std::string result;

			for ( auto & mbr : structType )
			{
				result += indent + writeBaseMember( mbr );
			}

			return result;
		}

		std::string writeMembers( ast::ShaderStage stage
			, std::string indent
			, ast::type::Struct const & structType )
		{
			if ( structType.isShaderInput()
				|| structType.isShaderOutput()
				|| structType.isPatchInput() )
			{
				return writeIOMembers( stage
					, indent
					, static_cast< ast::type::IOStruct const & >( structType ) );
			}

			return writeBaseMembers( indent, structType );
		}

		std::string writeTessEvalIn( ast::type::TessellationInputPatch const & tesscType
			, RoutineMap const & patchRoutines
			, std::string const & indent )
		{
			std::string result;
			result += indent + "[domain(\"" + getName( tesscType.getDomain() ) + "\")]\n";
			return result;
		}

		std::string writeTessCtrlOut( ast::type::TessellationControlOutput const & tesscType
			, RoutineMap const & patchRoutines
			, std::string const & indent )
		{
			std::string result;
			result += indent + "[domain(\"" + getName( tesscType.getDomain() ) + "\")]\n";
			result += indent + "[partitioning(\"" + getName( tesscType.getPartitioning() ) + "\")]\n";
			result += indent + "[outputtopology(\"" + getName( tesscType.getTopology(), tesscType.getOrder() ) + "\")]\n";
			result += indent + "[outputcontrolpoints(" + std::to_string( tesscType.getOutputVertices() ) + ")]\n";

			if ( !patchRoutines.empty() )
			{
				auto rit = std::find_if( patchRoutines.begin()
					, patchRoutines.end()
					, []( auto & lookup )
					{
						return !lookup.second->isMain;
					} );

				if ( rit != patchRoutines.end() )
				{
					result += indent + "[patchconstantfunc(\"" + ( rit->first ) + "\")]\n";
				}
				else
				{
				}
			}

			return result;
		}

		std::string writeMeshPrimOut( RoutineMap const & routines
			, std::string const & indent )
		{
			auto it = std::find_if( routines.begin()
				, routines.end()
				, []( auto & lookup )
				{
					return lookup.second->isMain;
				} );
			std::string result;

			if ( it != routines.end() )
			{
				result += indent + "[outputtopology(\"" + getName( it->second->getOutputTopology() ) + "\")]\n";
			}

			return result;
		}

		std::string printVersion( uint32_t major = MAIN_VERSION_MAJOR
			, uint32_t minor = MAIN_VERSION_MINOR
			, uint32_t build = MAIN_VERSION_BUILD
			, uint32_t year = MAIN_VERSION_YEAR )
		{
			std::stringstream stream;
			stream << major << "." << minor << "." << build << "-" << year;
			return stream.str();
		}
	}

	std::string StmtVisitor::submit( HlslConfig const & writerConfig
		, RoutineMap const & routines
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, ast::stmt::Stmt * stmt
		, std::string indent )
	{
		std::string result;
		result += "// This shader was generated using ShaderWriter version " + printVersion() + "\n";
		StmtVisitor vis{ writerConfig, routines, aliases, std::move( indent ), result };
		stmt->accept( &vis );
		return result;
	}

	StmtVisitor::StmtVisitor( HlslConfig const & writerConfig
		, RoutineMap const & routines
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, std::string indent
		, std::string & result )
		: m_writerConfig{ writerConfig }
		, m_routines{ routines }
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

	void StmtVisitor::visitDemoteStmt( ast::stmt::Demote * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent + "discard;\n";
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

	void StmtVisitor::visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )
	{
		AST_Failure( "ast::stmt::FragmentLayout unexpected at that point" );
	}

	void StmtVisitor::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		m_appendLineEnd = true;
		doAppendLineEnd();
		auto type = stmt->getType();
		ast::var::VariableList params;

		if ( stmt->isEntryPoint() )
		{
			for ( auto & mbr : *type )
			{
				auto argType = mbr->getType();

				if ( argType->getKind() == ast::type::Kind::eGeometryOutput )
				{
					auto maxVertexCount = static_cast< ast::type::GeometryOutput const & >( *argType ).getCount();
					m_result += m_indent + "[maxvertexcount(" + std::to_string( maxVertexCount ) + ")]\n";
					params.push_back( mbr );
				}
				else if ( argType->getKind() == ast::type::Kind::eComputeInput )
				{
					if ( !isMeshStage( m_writerConfig.shaderStage ) )
					{
						auto & compType = static_cast< ast::type::ComputeInput const & >( *argType );

						if ( compType.getLocalSizeX() == ast::stmt::InputComputeLayout::Uninit )
						{
							if ( compType.getLocalSizeY() == ast::stmt::InputComputeLayout::Uninit )
							{
								m_result += m_indent + "[numthreads( " + std::to_string( compType.getLocalSizeX() ) + " )]\n";
							}
							else
							{
								m_result += m_indent + "[numthreads( " + std::to_string( compType.getLocalSizeX() )
									+ ", " + std::to_string( compType.getLocalSizeY() ) + " )]\n";
							}
						}
						else
						{
							m_result += m_indent + "[numthreads( " + std::to_string( compType.getLocalSizeX() )
								+ ", " + std::to_string( compType.getLocalSizeY() )
								+ ", " + std::to_string( compType.getLocalSizeZ() ) + " )]\n";
						}
					}

					params.push_back( mbr );
				}
				else if ( argType->getKind() == ast::type::Kind::eFragmentInput )
				{
					// Fragment layouts unsupported in HLSL :/
					auto & fragType = static_cast< ast::type::FragmentInput const & >( *argType );
					argType = fragType.getType();

					if ( argType->getKind() != ast::type::Kind::eVoid
						&& ( argType->getKind() != ast::type::Kind::eStruct
							|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
					{
						params.push_back( mbr );
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
						params.push_back( mbr );
					}
				}
				else if ( argType->getKind() == ast::type::Kind::eTessellationControlOutput )
				{
					auto & tesscoType = static_cast< ast::type::TessellationControlOutput const & >( *argType );
					m_result += writeTessCtrlOut( tesscoType
						, m_routines
						, m_indent );
					argType = tesscoType.getType();

					if ( argType->getKind() != ast::type::Kind::eVoid
						&& ( argType->getKind() != ast::type::Kind::eStruct
							|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
					{
						params.push_back( mbr );
					}
				}
				else if ( argType->getKind() == ast::type::Kind::eTessellationInputPatch )
				{
					auto & tesseiType = static_cast< ast::type::TessellationInputPatch const & >( *argType );
					m_result += writeTessEvalIn( tesseiType
						, m_routines
						, m_indent );
					argType = tesseiType.getType();

					if ( argType->getKind() != ast::type::Kind::eVoid
						&& ( argType->getKind() != ast::type::Kind::eStruct
							|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
					{
						params.push_back( mbr );
					}
				}
				else if ( argType->getKind() == ast::type::Kind::eMeshVertexOutput )
				{
					auto & meshType = static_cast< ast::type::MeshVertexOutput const & >( *argType );
					argType = meshType.getType();

					if ( argType->getKind() != ast::type::Kind::eVoid
						&& ( argType->getKind() != ast::type::Kind::eStruct
							|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
					{
						params.push_back( mbr );
					}
				}
				else if ( argType->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
				{
					auto & meshType = static_cast< ast::type::MeshPrimitiveOutput const & >( *argType );
					argType = meshType.getType();

					if ( argType->getKind() != ast::type::Kind::eVoid
						&& ( argType->getKind() != ast::type::Kind::eStruct
							|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
					{
						params.push_back( mbr );
					}
				}
				else if ( argType->getKind() == ast::type::Kind::eTaskPayloadIn )
				{
					auto & taskType = static_cast< ast::type::TaskPayloadIn const & >( *argType );
					argType = taskType.getType();

					if ( argType->getKind() != ast::type::Kind::eVoid
						&& ( argType->getKind() != ast::type::Kind::eStruct
							|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
					{
						params.push_back( mbr );
					}
				}
				else
				{
					params.push_back( mbr );
				}
			}

			if ( m_writerConfig.shaderStage == ast::ShaderStage::eMesh )
			{
				m_result += writeMeshPrimOut( m_routines
					, m_indent );
			}

			if ( m_writerConfig.shaderStage == ast::ShaderStage::eCallable )
			{
				m_result += m_indent + "[shader(\"callable\")]\n";
			}
			else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayAnyHit )
			{
				m_result += m_indent + "[shader(\"anyhit\")]\n";
			}
			else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayClosestHit )
			{
				m_result += m_indent + "[shader(\"closesthit\")]\n";
			}
			else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayGeneration )
			{
				m_result += m_indent + "[shader(\"raygeneration\")]\n";
			}
			else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayIntersection )
			{
				m_result += m_indent + "[shader(\"intersection\")]\n";
			}
			else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayMiss )
			{
				m_result += m_indent + "[shader(\"miss\")]\n";
			}
		}
		else
		{
			params.insert( params.end(), type->begin(), type->end() );
		}

		auto retType = type->getReturnType();

		if ( retType->getKind() == ast::type::Kind::eTessellationControlOutput )
		{
			auto & tesscoType = static_cast< ast::type::TessellationControlOutput const & >( *retType );
			m_result += writeTessCtrlOut( tesscoType
				, m_routines
				, m_indent );
		}

		m_result += m_indent + getTypeName( retType );
		m_result += " " + stmt->getName() + "(";
		std::string sep;
		Semantic sem{ "", 0u };

		for ( auto & param : params )
		{
			if ( param->isBuiltin() )
			{
				m_result += sep + getDirectionName( *param )
					+ writeIOMember( m_writerConfig.shaderStage
						, param->getType()
						, param->getName()
						, param->getBuiltin()
						, true
						, ast::type::Struct::InvalidLocation
						, ast::type::Struct::InvalidLocation
						, sem
						, sem );
			}
			else
			{
				m_result += sep + getDirectionName( *param )
					+ getAttributeName( param->getType() )
					+ getTypeName( param->getType() ) + " "
					+ adaptName( param->getName() )
					+ getTypeArraySize( param->getType() );
			}

			sep = m_indent + "\n\t, ";
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

	void StmtVisitor::visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * stmt )
	{
		doAppendLineEnd();
		m_result += m_indent;
		auto & var = *stmt->getVariable();
		m_result += getTypeName( var.getType() ) + " ";
		m_result += var.getName();
		m_result += ": register(t" + std::to_string( stmt->getBindingPoint() ) + ")";
		m_result += ";\n";
	}

	void StmtVisitor::visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )
	{
	}

	void StmtVisitor::visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )
	{
		declareVariable( stmt->getVariable() );
	}

	void StmtVisitor::visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )
	{
		declareVariable( stmt->getVariable() );
	}

	void StmtVisitor::visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )
	{
		declareVariable( stmt->getVariable() );
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

	void StmtVisitor::visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )
	{
		m_result += m_indent + "IgnoreHit();\n";
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

	void StmtVisitor::visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )
	{
		AST_Failure( "ast::stmt::InputTessellationEvaluationLayout unexpected at that point" );
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		AST_Failure( "ast::stmt::OutputGeometryLayout unexpected at that point" );
	}

	void StmtVisitor::visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )
	{
		AST_Failure( "ast::stmt::OutputMeshLayout unexpected at that point" );
	}

	void StmtVisitor::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
		AST_Failure( "ast::stmt::visitOutputTessellationControlLayoutStmt unexpected at that point" );
	}

	void StmtVisitor::visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )
	{
		AST_Failure( "ast::stmt::PerPrimitiveDecl unexpected at that point" );
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

			m_result += writeMembers( m_writerConfig.shaderStage
				, m_indent
				, *stmt->getType() );

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

	void StmtVisitor::visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )
	{
		m_result += m_indent + "AcceptHitAndEndSearch();\n";
	}

	void StmtVisitor::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		declareVariable( stmt->getVariable() );
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

	void StmtVisitor::declareVariable( ast::var::VariablePtr pvar )
	{
		doAppendLineEnd();
		m_result += m_indent;
		auto & var = *pvar;

		if ( var.isStatic() )
		{
			m_result += "static ";
		}

		if ( var.isPerTask() )
		{
			m_result += "groupshared ";
		}

		m_result += getTypeName( var.getType() ) + " ";
		m_result += var.getName();
		m_result += getTypeArraySize( var.getType() );
		m_result += ";\n";
	}
}
