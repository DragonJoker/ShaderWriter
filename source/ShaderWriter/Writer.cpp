/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Writer.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"
#include "ShaderWriter/VecTypes/Vec2.hpp"

#include <ShaderAST/Stmt/PreprocExtension.hpp>
#include <ShaderAST/Stmt/PreprocVersion.hpp>
#include <ShaderAST/Stmt/StmtDiscard.hpp>
#include <ShaderAST/Stmt/StmtDoWhile.hpp>
#include <ShaderAST/Stmt/StmtElse.hpp>
#include <ShaderAST/Stmt/StmtElseIf.hpp>
#include <ShaderAST/Stmt/StmtFor.hpp>
#include <ShaderAST/Stmt/StmtIf.hpp>
#include <ShaderAST/Stmt/StmtInputComputeLayout.hpp>
#include <ShaderAST/Stmt/StmtInputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtOutputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtWhile.hpp>

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
		, SsboInfo const & info )
	{
		m_shader.registerSsbo( name, info );
	}

	void ShaderWriter::registerUbo( std::string const & name
		, UboInfo const & info )
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

	void ShaderWriter::pushScope()
	{
		m_currentStmts.emplace_back( stmt::makeContainer() );
		doPushScope( m_currentStmts.back().get() );
	}

	void ShaderWriter::popScope()
	{
		doPopScope();
		addStmt( std::move( m_currentStmts.back() ) );
		m_currentStmts.erase( m_currentStmts.begin() + m_currentStmts.size() - 1u );
	}

	void ShaderWriter::saveNextExpr()
	{
		m_shader.saveNextExpr();
	}

	ast::expr::ExprPtr ShaderWriter::loadExpr( Value const & value )
	{
		return m_shader.loadExpr( makeExpr( value ) );
	}

	void ShaderWriter::forStmt( expr::ExprPtr init
		, expr::ExprPtr cond
		, expr::ExprPtr incr
		, std::function< void() > function )
	{
		doPushScope( stmt::makeFor( makeExpr( init )
			, makeExpr( cond )
			, makeExpr( incr ) ) );
		function();
		popScope();
	}

	void ShaderWriter::doWhileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		doPushScope( stmt::makeDoWhile( std::move( condition ) ) );
		function();
		popScope();
	}

	void ShaderWriter::whileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		doPushScope( stmt::makeWhile( std::move( condition ) ) );
		function();
		popScope();
	}

	ShaderWriter & ShaderWriter::ifStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = stmt::makeIf( std::move( condition ) );
		m_ifStmt.push_back( stmt.get() );
		doPushScope( std::move( stmt ) );
		function();
		popScope();
		return *this;
	}

	ShaderWriter & ShaderWriter::elseIfStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		doPushScope( m_ifStmt.back()->createElseIf( std::move( condition ) ) );
		function();
		doPopScope();
		return *this;
	}

	ShaderWriter & ShaderWriter::elseStmt( std::function< void() > function )
	{
		doPushScope( m_ifStmt.back()->createElse() );
		function();
		doPopScope();
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
		auto type = Boolean::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		return Boolean{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Boolean > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, bool rhs
		, bool enabled )
	{
		auto type = Boolean::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Optional< Boolean >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	Int ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, int32_t rhs )
	{
		auto type = Int::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		return Int{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Int > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, int32_t rhs
		, bool enabled )
	{
		auto type = Int::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Optional< Int >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	UInt ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, uint32_t rhs )
	{
		auto type = UInt::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		return UInt{ &m_shader
			, makeExpr( var ) };
	}

	Optional< UInt > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, uint32_t rhs
		, bool enabled )
	{
		auto type = UInt::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Optional< UInt >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	Float ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, float rhs )
	{
		auto type = Float::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		return Float{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Float > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, float rhs
		, bool enabled )
	{
		auto type = Float::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Optional< Float >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	Double ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, double rhs )
	{
		auto type = Double::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeSpecConstantDecl( var
			, location
			, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		return Double{ &m_shader
			, makeExpr( var ) };
	}

	Optional< Double > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, double rhs
		, bool enabled )
	{
		auto type = Double::makeType( getTypesCache() );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSpecConstantDecl( var
				, location
				, ast::expr::makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Optional< Double >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	void ShaderWriter::doPushScope( ast::stmt::ContainerPtr && container )
	{
		m_currentStmts.emplace_back( std::move( container ) );
		doPushScope( m_currentStmts.back().get() );
	}

	void ShaderWriter::doPushScope( ast::stmt::Container * container )
	{
		m_shader.push( container );
	}

	void ShaderWriter::doPopScope()
	{
		m_shader.pop();
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
