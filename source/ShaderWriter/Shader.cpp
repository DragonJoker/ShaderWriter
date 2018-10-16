/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Shader.hpp"

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
	Shader::Shader( ShaderConfig config )
		: m_config{ std::move( config ) }
	{
		m_blocks.push( { {}, &m_container } );
		addStmt( stmt::makePreprocVersion( std::to_string( config.shaderLanguageVersion ) ) );
		enableExtension( "GL_ARB_explicit_attrib_location", 330u );
		enableExtension( "GL_ARB_explicit_uniform_location", 430u );
		enableExtension( "GL_ARB_separate_shader_objects", 410u );
		enableExtension( "GL_ARB_shading_language_420pack", 420u );
		enableExtension( "GL_ARB_texture_cube_map_array", 400u );
		declareInvertVec2Y();
		declareInvertVec3Y();
	}

	void Shader::registerName( std::string const & name, type::Kind type )
	{
		auto & block = m_blocks.top();
		auto it = block.registered.find( name );
		block.registered.emplace( name, type );
	}

	void Shader::checkNameExists( std::string const & name
		, type::Kind type )
	{
		auto & block = m_blocks.top();
		auto it = block.registered.find( name );

		if ( it == block.registered.end() )
		{
			std::string text;
			text += "No registered variable with the name [" + name + "].";
			throw std::runtime_error{ text };
		}
	}

	void Shader::addStmt( stmt::StmtPtr stmt )
	{
		getContainer()->addStmt( std::move( stmt ) );
	}

	void Shader::registerSsbo( std::string const & name
		, Ssbo::Info const & info )
	{
		m_ssbos.emplace( name, info );
	}

	void Shader::registerUbo( std::string const & name
		, Ubo::Info const & info )
	{
		m_ubos.emplace( name, info );
	}

	void Shader::inlineComment( std::string const & comment )
	{
	}

	void Shader::multilineComment( std::string const & comment )
	{
	}

	void Shader::enableExtension( std::string const & name, uint32_t inCoreVersion )
	{
		if ( getShaderLanguageVersion() < inCoreVersion )
		{
			addStmt( stmt::makePreprocExtension( name, stmt::PreprocExtension::Status::eEnabled ) );
		}
	}

	void Shader::emitVertex()
	{
		addStmt( stmt::makeEmitVertex() );
	}

	void Shader::endPrimitive()
	{
		addStmt( stmt::makeEmitPrimitive() );
	}

	void Shader::discard()
	{
		addStmt( stmt::makeDiscard() );
	}

	void Shader::inputComputeLayout( uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ )
	{
		addStmt( stmt::makeInputComputeLayout( localSizeX, localSizeY, localSizeZ ) );
	}

	void Shader::inputGeometryLayout( stmt::InputLayout layout )
	{
		addStmt( stmt::makeInputGeometryLayout( layout ) );
	}

	void Shader::outputGeometryLayout( stmt::OutputLayout layout, uint32_t count )
	{
		addStmt( stmt::makeOutputGeometryLayout( layout, count ) );
	}

	sdw::Vec2 Shader::bottomUpToTopDown( sdw::Vec2 const & texCoord )
	{
		if ( !isTopDown() )
		{
			return m_invertVec2Y( texCoord );
		}

		return texCoord;
	}

	sdw::Vec2 Shader::topDownToBottomUp( sdw::Vec2 const & texCoord )
	{
		if ( isTopDown() )
		{
			return m_invertVec2Y( texCoord );
		}

		return texCoord;
	}

	sdw::Vec3 Shader::bottomUpToTopDown( sdw::Vec3 const & texCoord )
	{
		if ( !isTopDown() )
		{
			return m_invertVec3Y( texCoord );
		}

		return texCoord;
	}

	sdw::Vec3 Shader::topDownToBottomUp( sdw::Vec3 const & texCoord )
	{
		if ( isTopDown() )
		{
			return m_invertVec3Y( texCoord );
		}

		return texCoord;
	}

	void Shader::returnStmt()
	{
		addStmt( stmt::makeReturn() );
	}

	void Shader::forStmt( expr::ExprPtr init
		, expr::ExprPtr cond
		, expr::ExprPtr incr
		, std::function< void() > function )
	{
		auto stmt = stmt::makeFor( makeExpr( init )
			, makeExpr( cond )
			, makeExpr( incr ) );
		m_blocks.push( { {}, stmt.get() } );
		function();
		m_blocks.pop();
		addStmt( std::move( stmt ) );
	}

	void Shader::doWhileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeDoWhile( std::move( condition ) );
		m_blocks.push( { {}, stmt.get() } );
		function();
		m_blocks.pop();
		addStmt( std::move( stmt ) );
	}

	void Shader::whileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeWhile( std::move( condition ) );
		m_blocks.push( { {}, stmt.get() } );
		function();
		m_blocks.pop();
		addStmt( std::move( stmt ) );
	}

	Shader & Shader::ifStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeIf( std::move( condition ) );
		m_blocks.push( { {}, stmt.get() } );
		function();
		m_blocks.pop();
		addStmt( std::move( stmt ) );
		return *this;
	}

	Shader & Shader::elseIfStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeElseIf( std::move( condition ) );
		m_blocks.push( { {}, stmt.get() } );
		function();
		m_blocks.pop();
		addStmt( std::move( stmt ) );
		return *this;
	}

	void Shader::elseStmt( std::function< void() > function )
	{
		auto stmt = stmt::makeElse();
		m_blocks.push( { {}, stmt.get() } );
		function();
		m_blocks.pop();
		addStmt( std::move( stmt ) );
	}

	void Shader::declareInvertVec2Y()
	{
		m_invertVec2Y = implementFunction< Vec2 >( "invertVec2Y"
			, [this]( Vec2 const & v )
			{
				returnStmt( vec2( v.x(), 1.0_f - v.y() ) );
			}
			, InVec2{ this, "v" } );
	}

	void Shader::declareInvertVec3Y()
	{
		m_invertVec3Y = implementFunction< Vec3 >( "invertVec3Y"
			, [this]( Vec3 const & v )
			{
				returnStmt( vec2( v.x(), 1.0_f - v.y(), v.z() ) );
			}
		, InVec3{ this, "v" } );
	}

	void Shader::registerConstant( std::string const & name
		, type::Kind type )
	{
		registerName( name, type );
		m_constants.emplace( name, type );
	}

	void Shader::registerSampler( std::string const & name
		, type::Kind type
		, uint32_t binding
		, uint32_t set
		, uint32_t count
		, bool enabled )
	{
		registerName( name, type );

		if ( enabled )
		{
			m_samplers.emplace( name, SamplerInfo{ type, binding, set, count } );
		}
	}

	void Shader::registerInput( std::string const & name
		, uint32_t location
		, type::Kind type )
	{
		registerName( name, type );
		m_inputs.emplace( name, InputInfo{ type, location } );
	}

	void Shader::registerOutput( std::string const & name
		, uint32_t location
		, type::Kind type )
	{
		registerName( name, type );
		m_outputs.emplace( name, OutputInfo{ type, location } );
	}
}
