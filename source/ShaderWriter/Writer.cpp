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
#include <ASTGenerator/Stmt/StmtEmitPrimitive.hpp>
#include <ASTGenerator/Stmt/StmtEmitVertex.hpp>
#include <ASTGenerator/Stmt/StmtFor.hpp>
#include <ASTGenerator/Stmt/StmtIf.hpp>
#include <ASTGenerator/Stmt/StmtInputComputeLayout.hpp>
#include <ASTGenerator/Stmt/StmtInputGeometryLayout.hpp>
#include <ASTGenerator/Stmt/StmtOutputGeometryLayout.hpp>
#include <ASTGenerator/Stmt/StmtWhile.hpp>

namespace sdw
{
	ShaderWriter::ShaderWriter( bool writeInvertFuncs
		, Config config )
		: m_config{ std::move( config ) }
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

	void ShaderWriter::registerName( std::string const & name, type::Kind type )
	{
		m_shader.registerName( name, type );
	}

	void ShaderWriter::checkNameExists( std::string const & name
		, type::Kind type )
	{
		m_shader.checkNameExists( name, type );
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

	void ShaderWriter::emitVertex()
	{
		addStmt( stmt::makeEmitVertex() );
	}

	void ShaderWriter::endPrimitive()
	{
		addStmt( stmt::makeEmitPrimitive() );
	}

	void ShaderWriter::discard()
	{
		addStmt( stmt::makeDiscard() );
	}

	void ShaderWriter::inputComputeLayout( uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ )
	{
		addStmt( stmt::makeInputComputeLayout( localSizeX, localSizeY, localSizeZ ) );
	}

	void ShaderWriter::inputGeometryLayout( stmt::InputLayout layout )
	{
		addStmt( stmt::makeInputGeometryLayout( layout ) );
	}

	void ShaderWriter::outputGeometryLayout( stmt::OutputLayout layout, uint32_t count )
	{
		addStmt( stmt::makeOutputGeometryLayout( layout, count ) );
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
		m_shader.push( stmt.get() );
		function();
		m_shader.pop();
		addStmt( std::move( stmt ) );
		return *this;
	}

	ShaderWriter & ShaderWriter::elseIfStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeElseIf( std::move( condition ) );
		m_shader.push( stmt.get() );
		function();
		m_shader.pop();
		addStmt( std::move( stmt ) );
		return *this;
	}

	void ShaderWriter::elseStmt( std::function< void() > function )
	{
		auto stmt = stmt::makeElse();
		m_shader.push( stmt.get() );
		function();
		m_shader.pop();
		addStmt( std::move( stmt ) );
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

	void ShaderWriter::registerConstant( std::string const & name
		, type::Kind type )
	{
		m_shader.registerConstant( name, type );
	}

	void ShaderWriter::registerSampler( std::string const & name
		, type::Kind type
		, uint32_t binding
		, uint32_t set
		, uint32_t count
		, bool enabled )
	{
		m_shader.registerSampler( name, type, binding, set, count, enabled );
	}

	void ShaderWriter::registerInput( std::string const & name
		, uint32_t location
		, type::Kind type )
	{
		m_shader.registerInput( name, location, type );
	}

	void ShaderWriter::registerOutput( std::string const & name
		, uint32_t location
		, type::Kind type )
	{
		m_shader.registerOutput( name, location, type );
	}
}
