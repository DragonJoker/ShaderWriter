/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Writer.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"
#include "ShaderWriter/VecTypes/Vec2.hpp"

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

	ShaderWriter::ShaderWriter( ShaderType type )
		: m_shader{ type }
	{
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

	void ShaderWriter::discard()
	{
		addStmt( stmt::makeDiscard() );
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

	Boolean ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, bool rhs )
	{
		auto type = type::makeType( typeEnum< Boolean > );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( rhs ) ) );
		return Boolean{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Boolean > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, bool rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< Boolean > );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( rhs ) ) );
		}

		return Optional< Boolean >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	Int ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, int32_t rhs )
	{
		auto type = type::makeType( typeEnum< Int > );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( rhs ) ) );
		return Int{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Int > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, int32_t rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< Int > );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( rhs ) ) );
		}

		return Optional< Int >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	UInt ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, uint32_t rhs )
	{
		auto type = type::makeType( typeEnum< UInt > );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( rhs ) ) );
		return UInt{ &m_shader
			, makeExpr( var ) };
	}

	Optional< UInt > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, uint32_t rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< UInt > );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( rhs ) ) );
		}

		return Optional< UInt >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	Float ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, float rhs )
	{
		auto type = type::makeType( typeEnum< Float > );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( rhs ) ) );
		return Float{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Float > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, float rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< Float > );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( rhs ) ) );
		}

		return Optional< Float >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	Double ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, double rhs )
	{
		auto type = type::makeType( typeEnum< Double > );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( rhs ) ) );
		return Double{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Double > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, double rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< Double > );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( rhs ) ) );
		}

		return Optional< Double >{ &m_shader
			, makeExpr( var )
			, enabled };
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
		, type::TypePtr type
		, var::Flag flag )
	{
		return m_shader.registerBuiltin( name, type, flag );
	}

	//*************************************************************************

	VertexWriter::VertexWriter()
		: ShaderWriter{ ShaderType::eVertex }
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

	TessellationControlWriter::TessellationControlWriter()
		: ShaderWriter{ ShaderType::eTessellationControl }
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

	TessellationEvaluationWriter::TessellationEvaluationWriter()
		: ShaderWriter{ ShaderType::eTessellationControl }
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

	GeometryWriter::GeometryWriter()
		: ShaderWriter{ ShaderType::eGeometry }
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

	FragmentWriter::FragmentWriter()
		: ShaderWriter{ ShaderType::eFragment }
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

	ComputeWriter::ComputeWriter()
		: ShaderWriter{ ShaderType::eCompute }
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
