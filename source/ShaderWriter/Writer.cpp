/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Writer.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"
#include "ShaderWriter/VecTypes/Vec2.hpp"

#include <ShaderAST/Stmt/PreprocExtension.hpp>
#include <ShaderAST/Stmt/PreprocVersion.hpp>
#include <ShaderAST/Stmt/StmtBreak.hpp>
#include <ShaderAST/Stmt/StmtContinue.hpp>
#include <ShaderAST/Stmt/StmtDiscard.hpp>
#include <ShaderAST/Stmt/StmtDoWhile.hpp>
#include <ShaderAST/Stmt/StmtElse.hpp>
#include <ShaderAST/Stmt/StmtElseIf.hpp>
#include <ShaderAST/Stmt/StmtFor.hpp>
#include <ShaderAST/Stmt/StmtFragmentLayout.hpp>
#include <ShaderAST/Stmt/StmtIf.hpp>
#include <ShaderAST/Stmt/StmtInputComputeLayout.hpp>
#include <ShaderAST/Stmt/StmtInputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtOutputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtReturn.hpp>
#include <ShaderAST/Stmt/StmtWhile.hpp>

#include "WriterInt.hpp"

namespace sdw
{
	//*************************************************************************

	ShaderWriter::ShaderWriter( ast::ShaderStage type )
		: m_shader{ std::make_unique< Shader >( type ) }
	{
		if ( doGetCurrentWriter() )
		{
			assert( false );
			throw std::logic_error{ "Can't have more than one ShaderWriter instantiated at once" };
		}

		doGetCurrentWriter() = this;
		assert( doGetCurrentWriter() );
	}

	ShaderWriter::~ShaderWriter()
	{
		assert( doGetCurrentWriter() && "Ooops... 0xDDDDDDDD" );
		doGetCurrentWriter() = nullptr;
	}

	bool ShaderWriter::hasVariable( std::string const & name )const
	{
		return m_shader->hasVariable( name );
	}

	var::VariablePtr ShaderWriter::registerName( std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		return m_shader->registerName( name, type, flags );
	}

	var::VariablePtr ShaderWriter::registerLocale( std::string const & name
		, type::TypePtr type )
	{
		return m_shader->registerLocale( name, type );
	}

	var::VariablePtr ShaderWriter::registerLoopVar( std::string const & name
		, type::TypePtr type )
	{
		return m_shader->registerLoopVar( name, type );
	}

	var::VariablePtr ShaderWriter::registerInParam( std::string const & name
		, type::TypePtr type )
	{
		return m_shader->registerInParam( name, type );
	}

	var::VariablePtr ShaderWriter::registerOutParam( std::string const & name
		, type::TypePtr type )
	{
		return m_shader->registerOutParam( name, type );
	}

	var::VariablePtr ShaderWriter::registerInOutParam( std::string const & name
		, type::TypePtr type )
	{
		return m_shader->registerInOutParam( name, type );
	}

	var::VariablePtr ShaderWriter::getVar( std::string const & name )
	{
		return m_shader->getVar( name );
	}

	void ShaderWriter::registerSsbo( std::string const & name
		, SsboInfo const & info )
	{
		m_shader->registerSsbo( name, info );
	}

	void ShaderWriter::registerUbo( std::string const & name
		, UboInfo const & info )
	{
		m_shader->registerUbo( name, info );
	}

	void ShaderWriter::addStmt( stmt::StmtPtr stmt )
	{
		m_shader->addStmt( std::move( stmt ) );
	}

	void ShaderWriter::addFuncStmt( stmt::StmtPtr stmt )
	{
		m_shader->addFuncStmt( std::move( stmt ) );
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
		doPushScope( stmt::makeContainer() );
	}

	void ShaderWriter::popScope()
	{
		doPopScope();
		addStmt( std::move( m_currentStmts.back() ) );
		m_currentStmts.erase( m_currentStmts.begin() + ptrdiff_t( m_currentStmts.size() - 1u ) );
	}

	void ShaderWriter::saveNextExpr()
	{
		m_shader->saveNextExpr();
	}

	ast::expr::ExprPtr ShaderWriter::loadExpr( Value const & value )
	{
		return m_shader->loadExpr( makeExpr( *this, value ) );
	}

	void ShaderWriter::forStmt( expr::ExprPtr init
		, expr::ExprPtr cond
		, expr::ExprPtr incr
		, std::function< void() > function )
	{
		doPushScope( stmt::makeFor( makeExpr( *this, init )
			, makeExpr( *this, cond )
			, makeExpr( *this, incr ) ) );
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
		doPushScope( m_ifStmt.back()->createElseIf( std::move( condition ) )
			, ast::var::VariableList{} );
		function();
		doPopScope();
		return *this;
	}

	ShaderWriter & ShaderWriter::elseStmt( std::function< void() > function )
	{
		doPushScope( m_ifStmt.back()->createElse()
			, ast::var::VariableList{} );
		function();
		doPopScope();
		return *this;
	}

	void ShaderWriter::endIf()
	{
		m_ifStmt.pop_back();
	}

	ShaderWriter & ShaderWriter::switchStmt( expr::ExprPtr value
		, std::function< void() > function )
	{
		auto stmt = stmt::makeSwitch( ast::expr::makeSwitchTest( std::move( value ) ) );
		m_switchStmt.push_back( stmt.get() );
		doPushScope( std::move( stmt ) );
		function();
		popScope();
		return *this;
	}

	void ShaderWriter::endSwitch()
	{
		m_switchStmt.pop_back();
	}

	void ShaderWriter::caseStmt( expr::LiteralPtr literal
		, std::function< void() > function )
	{
		auto stmt = m_switchStmt.back()->createCase( ast::expr::makeSwitchCase( std::move( literal ) ) );
		doPushScope( stmt
			, ast::var::VariableList{} );
		function();
		doPopScope();
	}

	void ShaderWriter::caseBreakStmt()
	{
		addStmt( ast::stmt::makeBreak( true ) );
	}

	void ShaderWriter::loopBreakStmt()
	{
		addStmt( ast::stmt::makeBreak( false ) );
	}

	void ShaderWriter::loopContinueStmt()
	{
		addStmt( ast::stmt::makeContinue() );
	}

	Boolean ShaderWriter::declSpecConstant( std::string const & name
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

		return Boolean{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Int ShaderWriter::declSpecConstant( std::string const & name
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

		return Int{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	UInt ShaderWriter::declSpecConstant( std::string const & name
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

		return UInt{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Float ShaderWriter::declSpecConstant( std::string const & name
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

		return Float{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Double ShaderWriter::declSpecConstant( std::string const & name
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

		return Double{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	void ShaderWriter::doPushScope( ast::stmt::ContainerPtr && container )
	{
		m_currentStmts.emplace_back( std::move( container ) );
		doPushScope( m_currentStmts.back().get()
			, ast::var::VariableList{} );
	}

	void ShaderWriter::doPushScope( ast::stmt::ContainerPtr && container
		, ast::var::VariableList vars )
	{
		m_currentStmts.emplace_back( std::move( container ) );
		doPushScope( m_currentStmts.back().get()
			, std::move( vars ) );
	}

	void ShaderWriter::doPushScope( ast::stmt::Container * container
		, ast::var::VariableList vars )
	{
		m_shader->push( container, vars );
	}

	void ShaderWriter::doPopScope()
	{
		m_shader->pop();
	}

	var::VariablePtr ShaderWriter::registerStaticConstant( std::string const & name
		, type::TypePtr type )
	{
		return m_shader->registerStaticConstant( name, type );
	}

	var::VariablePtr ShaderWriter::registerConstant( std::string const & name
		, type::TypePtr type )
	{
		return m_shader->registerConstant( name, type );
	}

	var::VariablePtr ShaderWriter::registerSpecConstant( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		return m_shader->registerSpecConstant( name, location, type );
	}

	var::VariablePtr ShaderWriter::registerSampledImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader->registerSampledImage( name, type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader->registerImage( name, type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerInput( std::string const & name
		, uint32_t location
		, uint32_t attributes
		, type::TypePtr type )
	{
		return m_shader->registerInput( name, location, attributes, type );
	}

	var::VariablePtr ShaderWriter::registerOutput( std::string const & name
		, uint32_t location
		, uint32_t attributes
		, type::TypePtr type )
	{
		return m_shader->registerOutput( name, location, attributes, type );
	}

	var::VariablePtr ShaderWriter::registerBuiltin( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return m_shader->registerBuiltin( name, type, flag );
	}

	//*************************************************************************

	VertexWriter::VertexWriter()
		: ShaderWriter{ ast::ShaderStage::eVertex }
	{
	}

	//*************************************************************************

	TessellationControlWriter::TessellationControlWriter()
		: ShaderWriter{ ast::ShaderStage::eTessellationControl }
	{
	}

	//*************************************************************************

	TessellationEvaluationWriter::TessellationEvaluationWriter()
		: ShaderWriter{ ast::ShaderStage::eTessellationControl }
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
		: ShaderWriter{ ast::ShaderStage::eGeometry }
	{
	}

	//*************************************************************************

	FragmentWriter::FragmentWriter()
		: ShaderWriter{ ast::ShaderStage::eFragment }
	{
	}

	void FragmentWriter::fragmentLayout( ast::FragmentOrigin origin
		, ast::FragmentCenter center )
	{
		addStmt( stmt::makeFragmentLayout( origin, center ) );
	}

	//*************************************************************************

	ComputeWriter::ComputeWriter()
		: ShaderWriter{ ast::ShaderStage::eCompute }
	{
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
