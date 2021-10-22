/*
See LICENSE file in root folder
*/
#include "SpirvStmtConfigFiller.hpp"

#include "SpirvExprConfigFiller.hpp"
#include "SpirvHelpers.hpp"
#include "SpirvImageAccessNames.hpp"
#include "SpirvIntrinsicNames.hpp"
#include "SpirvTextureAccessNames.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

#include <stdexcept>

namespace spirv
{
	ModuleConfig StmtConfigFiller::submit( ast::stmt::Container * cont )
	{
		ModuleConfig result;
		StmtConfigFiller vis{ result };
		cont->accept( &vis );
		return result;
	}

	StmtConfigFiller::StmtConfigFiller( ModuleConfig & result )
		: m_result{ result }
	{
	}

	void StmtConfigFiller::visitBreakStmt( ast::stmt::Break * cont )
	{
	}

	void StmtConfigFiller::visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitContainerStmt( ast::stmt::Container * cont )
	{
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtConfigFiller::visitContinueStmt( ast::stmt::Continue * cont )
	{
	}

	void StmtConfigFiller::visitDiscardStmt( ast::stmt::Discard * stmt )
	{
	}

	void StmtConfigFiller::visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitCommentStmt( ast::stmt::Comment * stmt )
	{
	}

	void StmtConfigFiller::visitCompoundStmt( ast::stmt::Compound * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitDoWhileStmt( ast::stmt::DoWhile * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseStmt( ast::stmt::Else * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitForStmt( ast::stmt::For * stmt )
	{
		ExprConfigFiller::submit( stmt->getInitExpr(), m_result );
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		ExprConfigFiller::submit( stmt->getIncrExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitFragmentLayout( ast::stmt::FragmentLayout * stmt )
	{
	}

	void StmtConfigFiller::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getFlags() )
		{
			bool isEntryPoint = stmt->isEntryPoint();
			auto funcType = stmt->getType();

			for ( auto & param : *funcType )
			{
				auto type = param->getType();

				if ( type->getKind() == ast::type::Kind::eGeometryOutput )
				{
					doProcessGeometryOutput( param
						, static_cast< ast::type::GeometryOutput const & >( *type )
						, stmt->getName() );
				}
				else if ( type->getKind() == ast::type::Kind::eGeometryInput )
				{
					doProcessGeometryInput( param
						, static_cast< ast::type::GeometryInput const & >( *type )
						, stmt->getName() );
				}
				else if ( type->getKind() == ast::type::Kind::eTessellationControlInput )
				{
					doProcessTessellationControlInput( param
						, static_cast< ast::type::TessellationControlInput const & >( *type )
						, stmt->getName()
						, isEntryPoint );
				}
				else if ( type->getKind() == ast::type::Kind::eTessellationControlOutput )
				{
					doProcessTessellationControlOutput( param
						, static_cast< ast::type::TessellationControlOutput const & >( *type )
						, stmt->getName()
						, isEntryPoint );
				}
				else if ( type->getKind() == ast::type::Kind::eTessellationOutputPatch )
				{
					doProcessOutputPatch( param
						, std::static_pointer_cast< ast::type::Struct >( type ) );
				}
				else
				{
					uint32_t arraySize = ast::type::NotArray;

					if ( type->getKind() == ast::type::Kind::eArray )
					{
						auto & arrayType = static_cast< ast::type::Array const & >( *type );
						type = arrayType.getType();
						arraySize = arrayType.getArraySize();
					}

					if ( type->getKind() == ast::type::Kind::eStruct )
					{
						auto structType = std::static_pointer_cast< ast::type::Struct >( type );

						if ( structType->isShaderInput() )
						{
							doProcessInput( param
								, static_cast< ast::type::IOStruct const & >( *structType )
								, arraySize
								, stmt->getName()
								, isEntryPoint );
						}
						else if ( structType->isShaderOutput() )
						{
							doProcessOutput( param
								, static_cast< ast::type::IOStruct const & >( *structType )
								, arraySize
								, stmt->getName()
								, isEntryPoint );
						}
						else if ( param->isPatchInput() )
						{
							doProcessInputPatch( param, structType );
						}
					}
				}
			}
		}

		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitIfStmt( ast::stmt::If * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );

		for ( auto & elseIf : stmt->getElseIfList() )
		{
			elseIf->accept( this );
		}

		if ( stmt->getElse() )
		{
			stmt->getElse()->accept( this );
		}
	}

	void StmtConfigFiller::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		auto imgType = std::static_pointer_cast< ast::type::Image >( ast::type::getNonArrayType( stmt->getVariable()->getType() ) );

		if ( imgType->getConfig().dimension == ast::type::ImageDim::e1D )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampled1D );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eRect )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledRect );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eBuffer )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledBuffer );
		}

		if ( imgType->getConfig().isMS )
		{
			m_result.requiredCapabilities.insert( spv::CapabilityStorageImageMultisample );
		}

		switch ( imgType->getConfig().format )
		{
		case ast::type::ImageFormat::eRg32f:
		case ast::type::ImageFormat::eRg16f:
		case ast::type::ImageFormat::eR32f:
		case ast::type::ImageFormat::eR16f:
		case ast::type::ImageFormat::eRg32i:
		case ast::type::ImageFormat::eRg16i:
		case ast::type::ImageFormat::eRg8i:
		case ast::type::ImageFormat::eR32i:
		case ast::type::ImageFormat::eR16i:
		case ast::type::ImageFormat::eR8i:
		case ast::type::ImageFormat::eRg32u:
		case ast::type::ImageFormat::eRg16u:
		case ast::type::ImageFormat::eRg8u:
		case ast::type::ImageFormat::eR32u:
		case ast::type::ImageFormat::eR16u:
		case ast::type::ImageFormat::eR8u:
			m_result.requiredCapabilities.insert( spv::CapabilityStorageImageExtendedFormats );
			break;
		default:
			break;
		}
	}

	void StmtConfigFiller::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		auto var = stmt->getVariable();

		if ( !var->isShaderConstant() )
		{
			if ( var->isShaderInput() )
			{
				m_result.inputs.insert( var );
			}

			if ( var->isShaderOutput() )
			{
				m_result.outputs.insert( var );
			}
		}

		if ( var->isPatch() )
		{
			m_result.requiredCapabilities.insert( spv::CapabilityTessellation );
		}

		if ( var->isPerSample() )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampleRateShading );
		}

		if ( var->isGeometryStream() )
		{
			m_result.requiredCapabilities.insert( spv::CapabilityGeometryStreams );
		}
	}

	void StmtConfigFiller::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
	}

	void StmtConfigFiller::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
	}

	void StmtConfigFiller::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
	}

	void StmtConfigFiller::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
	}

	void StmtConfigFiller::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
	}

	void StmtConfigFiller::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
	}

	void StmtConfigFiller::visitReturnStmt( ast::stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			ExprConfigFiller::submit( stmt->getExpr(), m_result );
		}
	}

	void StmtConfigFiller::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		auto imgType = std::static_pointer_cast< ast::type::SampledImage >( ast::type::getNonArrayType( stmt->getVariable()->getType() ) );

		if ( imgType->getConfig().dimension == ast::type::ImageDim::e1D )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampled1D );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eRect )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledRect );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eBuffer )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledBuffer );
		}

		switch ( imgType->getConfig().format )
		{
		case ast::type::ImageFormat::eRg32f:
		case ast::type::ImageFormat::eRg16f:
		case ast::type::ImageFormat::eR32f:
		case ast::type::ImageFormat::eR16f:
		case ast::type::ImageFormat::eRg32i:
		case ast::type::ImageFormat::eRg16i:
		case ast::type::ImageFormat::eRg8i:
		case ast::type::ImageFormat::eR32i:
		case ast::type::ImageFormat::eR16i:
		case ast::type::ImageFormat::eR8i:
		case ast::type::ImageFormat::eRg32u:
		case ast::type::ImageFormat::eRg16u:
		case ast::type::ImageFormat::eRg8u:
		case ast::type::ImageFormat::eR32u:
		case ast::type::ImageFormat::eR16u:
		case ast::type::ImageFormat::eR8u:
			m_result.requiredCapabilities.insert( spv::CapabilityStorageImageExtendedFormats );
			break;
		default:
			break;
		}
	}

	void StmtConfigFiller::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
	}

	void StmtConfigFiller::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		doTraverseType( stmt->getSsboInstance()->getType() );
	}

	void StmtConfigFiller::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		ExprConfigFiller::submit( stmt->getExpr(), m_result );
		doTraverseType( stmt->getExpr()->getType() );
	}

	void StmtConfigFiller::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		ExprConfigFiller::submit( stmt->getTestExpr()->getValue(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		doTraverseType( stmt->getVariable()->getType() );
	}

	void StmtConfigFiller::visitWhileStmt( ast::stmt::While * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		ExprConfigFiller::submit( preproc->getExpr(), m_result );
	}

	void StmtConfigFiller::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		ExprConfigFiller::submit( preproc->getCtrlExpr(), m_result );
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocElse( ast::stmt::PreprocElse * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
	}

	void StmtConfigFiller::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
	}

	void StmtConfigFiller::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
		ExprConfigFiller::submit( preproc->getCtrlExpr(), m_result );
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
	}

	void StmtConfigFiller::doTraverseType( ast::type::TypePtr type )
	{
		type = ast::type::getNonArrayType( type );
		auto kind = type->getKind();

		if ( kind == ast::type::Kind::eStruct )
		{
			doTraverseType( std::static_pointer_cast< ast::type::Struct >( type ) );
		}
		else
		{
			kind = getScalarType( kind );

			if ( kind == ast::type::Kind::eDouble )
			{
				m_result.requiredCapabilities.insert( spv::CapabilityFloat64 );
			}
		}
	}

	void StmtConfigFiller::doTraverseType( ast::type::StructPtr type )
	{
		for ( auto & member : *type )
		{
			doTraverseType( member.type );
		}
	}

	void StmtConfigFiller::doProcessGeometryOutput( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType
		, std::string const & name )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderOutput() );
			doProcessOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, ast::type::NotArray
				, name
				, true );
		}
	}

	void StmtConfigFiller::doProcessGeometryInput( ast::var::VariablePtr var
		, ast::type::GeometryInput const & geomType
		, std::string const & name )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderInput() );
			doProcessInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, getArraySize( geomType.layout )
				, name
				, true );
		}
	}

	void StmtConfigFiller::doProcessTessellationControlOutput( ast::var::VariablePtr var
		, ast::type::TessellationControlOutput const & tessType
		, std::string const & name
		, bool isEntryPoint )
	{
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderOutput() );
			doProcessOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, tessType.getOutputVertices()
				, name
				, isEntryPoint );
		}
	}

	void StmtConfigFiller::doProcessTessellationControlInput( ast::var::VariablePtr var
		, ast::type::TessellationControlInput const & geomType
		, std::string const & name
		, bool isEntryPoint )
	{
		auto type = geomType.getType();

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderInput() );
			doProcessInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, geomType.getInputVertices()
				, name
				, isEntryPoint );
		}
	}

	void StmtConfigFiller::doProcessOutput( ast::var::VariablePtr var
		, ast::type::IOStruct const & ioType
		, uint32_t arraySize
		, std::string const & name
		, bool isEntryPoint )
	{
		if ( isEntryPoint )
		{
			m_result.output = var;
		}
		else
		{
			m_result.outputMapping.emplace( var, name );
		}

		for ( auto & mbr : ioType )
		{
			m_result.addShaderOutput( "sdwOut_" + mbr.name
				, mbr.type
				, ioType.getFlag()
				, arraySize );
		}
	}

	void StmtConfigFiller::doProcessInput( ast::var::VariablePtr var
		, ast::type::IOStruct const & ioType
		, uint32_t arraySize
		, std::string const & name
		, bool isEntryPoint )
	{
		if ( isEntryPoint )
		{
			m_result.input = var;
		}
		else
		{
			m_result.inputMapping.emplace( var, name );
		}

		for ( auto & mbr : ioType )
		{
			m_result.addShaderInput( "sdwIn_" + mbr.name
				, mbr.type
				, ioType.getFlag()
				, arraySize );
		}
	}

	void StmtConfigFiller::doProcessOutputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType )
	{
		m_result.addPatchOutput( var->getName()
			, var->getType()
			, var->getFlags() );
	}

	void StmtConfigFiller::doProcessInputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType )
	{
		m_result.addPatchInput( var->getName()
			, var->getType()
			, var->getFlags() );
	}
}
