/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Writer.hpp"

#include "ShaderWriter/Intrinsics.hpp"
#include "ShaderWriter/Vec2.hpp"

#include <ASTGenerator/Stmt/PreprocExtension.hpp>
#include <ASTGenerator/Stmt/PreprocVersion.hpp>
#include <ASTGenerator/Stmt/StmtDiscard.hpp>
#include <ASTGenerator/Stmt/StmtDoWhile.hpp>
#include <ASTGenerator/Stmt/StmtElse.hpp>
#include <ASTGenerator/Stmt/StmtElseIf.hpp>
#include <ASTGenerator/Stmt/StmtFor.hpp>
#include <ASTGenerator/Stmt/StmtIf.hpp>
#include <ASTGenerator/Stmt/StmtInputComputeLayout.hpp>
#include <ASTGenerator/Stmt/StmtInputGeometryLayout.hpp>
#include <ASTGenerator/Stmt/StmtOutputGeometryLayout.hpp>
#include <ASTGenerator/Stmt/StmtWhile.hpp>

namespace sdw
{
	//*************************************************************************

	ShaderWriter::ShaderWriter( ShaderType type
		, bool writeInvertFuncs
		, Config config )
		: m_type{ type }
		, m_config{ std::move( config ) }
	{
		addStmt( stmt::makePreprocVersion( std::to_string( config.shaderLanguageVersion ) ) );
		enableExtension( "GL_ARB_explicit_attrib_location", 330u );
		enableExtension( "GL_ARB_explicit_uniform_location", 430u );
		enableExtension( "GL_ARB_separate_shader_objects", 410u );
		enableExtension( "GL_ARB_shading_language_420pack", 420u );
		enableExtension( "GL_ARB_texture_cube_map_array", 400u );

		if ( writeInvertFuncs )
		{
			declareInvertVec2Y();
			declareInvertVec3Y();
		}
	}

	var::VariablePtr ShaderWriter::registerName( std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		return m_shader.registerName( name, type, flags );
	}

	var::VariablePtr ShaderWriter::registerLocale( std::string const & name
		, type::TypePtr type )
	{
		return m_shader.registerLocale( name, type );
	}

	var::VariablePtr ShaderWriter::registerInParam( std::string const & name
		, type::TypePtr type )
	{
		return m_shader.registerInParam( name, type );
	}

	var::VariablePtr ShaderWriter::registerOutParam( std::string const & name
		, type::TypePtr type )
	{
		return m_shader.registerOutParam( name, type );
	}

	var::VariablePtr ShaderWriter::registerInOutParam( std::string const & name
		, type::TypePtr type )
	{
		return m_shader.registerInOutParam( name, type );
	}

	var::VariablePtr ShaderWriter::getVar( std::string const & name )
	{
		return m_shader.getVar( name );
	}

	void ShaderWriter::registerSsbo( std::string const & name
		, Ssbo::Info const & info )
	{
		m_shader.registerSsbo( name, info );
	}

	void ShaderWriter::registerUbo( std::string const & name
		, Ubo::Info const & info )
	{
		m_shader.registerUbo( name, info );
	}

	void ShaderWriter::addStmt( stmt::StmtPtr stmt )
	{
		m_shader.addStmt( std::move( stmt ) );
	}

	void ShaderWriter::inlineComment( std::string const & comment )
	{
	}

	void ShaderWriter::multilineComment( std::string const & comment )
	{
	}

	void ShaderWriter::enableExtension( std::string const & name, uint32_t inCoreVersion )
	{
		if ( getShaderLanguageVersion() < inCoreVersion )
		{
			addStmt( stmt::makePreprocExtension( name, stmt::PreprocExtension::Status::eEnabled ) );
		}
	}

	void ShaderWriter::discard()
	{
		addStmt( stmt::makeDiscard() );
	}

	sdw::Vec2 ShaderWriter::bottomUpToTopDown( sdw::Vec2 const & texCoord )
	{
		if ( !isTopDown() )
		{
			return m_invertVec2Y( texCoord );
		}

		return texCoord;
	}

	sdw::Vec2 ShaderWriter::topDownToBottomUp( sdw::Vec2 const & texCoord )
	{
		if ( isTopDown() )
		{
			return m_invertVec2Y( texCoord );
		}

		return texCoord;
	}

	sdw::Vec3 ShaderWriter::bottomUpToTopDown( sdw::Vec3 const & texCoord )
	{
		if ( !isTopDown() )
		{
			return m_invertVec3Y( texCoord );
		}

		return texCoord;
	}

	sdw::Vec3 ShaderWriter::topDownToBottomUp( sdw::Vec3 const & texCoord )
	{
		if ( isTopDown() )
		{
			return m_invertVec3Y( texCoord );
		}

		return texCoord;
	}

	void ShaderWriter::returnStmt()
	{
		addStmt( stmt::makeReturn() );
	}

	void ShaderWriter::forStmt( expr::ExprPtr init
		, expr::ExprPtr cond
		, expr::ExprPtr incr
		, std::function< void() > function )
	{
		auto stmt = stmt::makeFor( makeExpr( init )
			, makeExpr( cond )
			, makeExpr( incr ) );
		m_shader.push( stmt.get() );
		function();
		m_shader.pop();
		addStmt( std::move( stmt ) );
	}

	void ShaderWriter::doWhileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeDoWhile( std::move( condition ) );
		m_shader.push( stmt.get() );
		function();
		m_shader.pop();
		addStmt( std::move( stmt ) );
	}

	void ShaderWriter::whileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeWhile( std::move( condition ) );
		m_shader.push( stmt.get() );
		function();
		m_shader.pop();
		addStmt( std::move( stmt ) );
	}

	ShaderWriter & ShaderWriter::ifStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeIf( std::move( condition ) );
		m_ifStmt.push_back( stmt.get() );
		m_shader.push( stmt.get() );
		function();
		m_shader.pop();
		addStmt( std::move( stmt ) );
		return *this;
	}

	ShaderWriter & ShaderWriter::elseIfStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = m_ifStmt.back()->createElseIf( std::move( condition ) );
		m_shader.push( stmt );
		function();
		m_shader.pop();
		return *this;
	}

	ShaderWriter & ShaderWriter::elseStmt( std::function< void() > function )
	{
		auto stmt = m_ifStmt.back()->createElse();
		m_shader.push( stmt );
		function();
		m_shader.pop();
		return *this;
	}

	void ShaderWriter::endIf()
	{
		m_ifStmt.pop_back();
	}

	void ShaderWriter::declareInvertVec2Y()
	{
		m_invertVec2Y = implementFunction< Vec2 >( "invertVec2Y"
			, [this]( Vec2 const & v )
			{
				returnStmt( vec2( v.x(), 1.0_f - v.y() ) );
			}
			, InVec2{ *this, "v" } );
	}

	void ShaderWriter::declareInvertVec3Y()
	{
		m_invertVec3Y = implementFunction< Vec3 >( "invertVec3Y"
			, [this]( Vec3 const & v )
			{
				returnStmt( vec2( v.x(), 1.0_f - v.y(), v.z() ) );
			}
			, InVec3{ *this, "v" } );
	}

	var::VariablePtr ShaderWriter::registerConstant( std::string const & name
		, type::TypePtr type )
	{
		return m_shader.registerConstant( name, type );
	}

	var::VariablePtr ShaderWriter::registerSpecConstant( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		return m_shader.registerSpecConstant( name, location, type );
	}

	var::VariablePtr ShaderWriter::registerSampledImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader.registerSampledImage( name, type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader.registerImage( name, type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerInput( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		return m_shader.registerInput( name, location, type );
	}

	var::VariablePtr ShaderWriter::registerOutput( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		return m_shader.registerOutput( name, location, type );
	}

	var::VariablePtr ShaderWriter::registerBuiltin( std::string const & name
		, type::TypePtr type )
	{
		return m_shader.registerBuiltin( name, type );
	}

	//*************************************************************************

	VertexWriter::VertexWriter( bool writeInvertFuncs
		, Config config )
		: ShaderWriter{ ShaderType::eVertex, writeInvertFuncs, config }
	{
	}

	InVertex VertexWriter::getIn()
	{
		return InVertex{ *this };
	}

	OutVertex VertexWriter::getOut()
	{
		return OutVertex{ *this };
	}

	//*************************************************************************

	TessellationControlWriter::TessellationControlWriter( bool writeInvertFuncs
		, Config config )
		: ShaderWriter{ ShaderType::eTessellationControl, writeInvertFuncs, config }
	{
	}

	InTessellationControl TessellationControlWriter::getIn()
	{
		return InTessellationControl{ *this };
	}

	OutTessellationControl TessellationControlWriter::getOut()
	{
		return OutTessellationControl{ *this };
	}

	//*************************************************************************

	TessellationEvaluationWriter::TessellationEvaluationWriter( bool writeInvertFuncs
		, Config config )
		: ShaderWriter{ ShaderType::eTessellationControl, writeInvertFuncs, config }
	{
	}

	InTessellationEvaluation TessellationEvaluationWriter::getIn()
	{
		return InTessellationEvaluation{ *this };
	}

	OutTessellationEvaluation TessellationEvaluationWriter::getOut()
	{
		return OutTessellationEvaluation{ *this };
	}

	//*************************************************************************

	GeometryWriter::GeometryWriter( bool writeInvertFuncs
		, Config config )
		: ShaderWriter{ ShaderType::eGeometry, writeInvertFuncs, config }
	{
	}

	void GeometryWriter::inputLayout( stmt::InputLayout layout )
	{
		addStmt( stmt::makeInputGeometryLayout( layout ) );
	}

	void GeometryWriter::outputLayout( stmt::OutputLayout layout, uint32_t count )
	{
		addStmt( stmt::makeOutputGeometryLayout( layout, count ) );
	}

	InGeometry GeometryWriter::getIn()
	{
		return InGeometry{ *this };
	}

	OutGeometry GeometryWriter::getOut()
	{
		return OutGeometry{ *this };
	}

	//*************************************************************************

	FragmentWriter::FragmentWriter( bool writeInvertFuncs
		, Config config )
		: ShaderWriter{ ShaderType::eFragment, writeInvertFuncs, config }
	{
	}

	InFragment FragmentWriter::getIn()
	{
		return InFragment{ *this };
	}

	OutFragment FragmentWriter::getOut()
	{
		return OutFragment{ *this };
	}

	//*************************************************************************

	ComputeWriter::ComputeWriter( bool writeInvertFuncs
		, Config config )
		: ShaderWriter{ ShaderType::eCompute, writeInvertFuncs, config }
	{
	}

	InCompute ComputeWriter::getIn()
	{
		return InCompute{ *this };
	}

	void ComputeWriter::inputLayout( uint32_t localSizeX )
	{
		addStmt( stmt::makeInputComputeLayout( localSizeX, 1, 1 ) );
	}

	void ComputeWriter::inputLayout( uint32_t localSizeX
		, uint32_t localSizeY )
	{
		addStmt( stmt::makeInputComputeLayout( localSizeX
			, localSizeY, 1 ) );
	}

	void ComputeWriter::inputLayout( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
	{
		addStmt( stmt::makeInputComputeLayout( localSizeX
			, localSizeY
			, localSizeZ ) );
	}

	//*************************************************************************
}
