/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Shader.hpp"

#include <ASTGenerator/Stmt/StmtDoWhile.hpp>
#include <ASTGenerator/Stmt/StmtElse.hpp>
#include <ASTGenerator/Stmt/StmtElseIf.hpp>
#include <ASTGenerator/Stmt/StmtFor.hpp>
#include <ASTGenerator/Stmt/StmtIf.hpp>
#include <ASTGenerator/Stmt/StmtWhile.hpp>

namespace sdw
{
	Shader::Shader()
	{
		m_blocks.push( { {}, &m_container } );
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

	void Shader::returnStmt()
	{
		addStmt( stmt::makeReturn() );
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
}
