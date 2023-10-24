/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Writer.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"
#include "ShaderWriter/BaseTypes/AccelerationStructure.hpp"
#include "ShaderWriter/BaseTypes/Sampler.hpp"
#include "ShaderWriter/VecTypes/Vec2.hpp"

#include <ShaderAST/Stmt/PreprocExtension.hpp>
#include <ShaderAST/Stmt/PreprocVersion.hpp>
#include <ShaderAST/Stmt/StmtBreak.hpp>
#include <ShaderAST/Stmt/StmtContinue.hpp>
#include <ShaderAST/Stmt/StmtDemote.hpp>
#include <ShaderAST/Stmt/StmtTerminateInvocation.hpp>
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
	ShaderWriter::ShaderWriter( ast::ShaderStage type
		, ShaderAllocator * allocator )
		: m_shader{ std::make_unique< Shader >( type, allocator ) }
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

	bool ShaderWriter::hasVariable( std::string_view name )const
	{
		return m_shader->hasVariable( name );
	}

	var::VariablePtr ShaderWriter::registerName( std::string name
		, type::TypePtr type
		, uint64_t flags )
	{
		return m_shader->registerName( std::move( name ), type, flags );
	}

	var::VariablePtr ShaderWriter::registerLocale( std::string name
		, type::TypePtr type )
	{
		return m_shader->registerLocale( std::move( name ), type );
	}

	var::VariablePtr ShaderWriter::registerLoopVar( std::string name
		, type::TypePtr type )
	{
		return m_shader->registerLoopVar( std::move( name ), type );
	}

	var::VariablePtr ShaderWriter::registerInParam( std::string name
		, type::TypePtr type )
	{
		return m_shader->registerInParam( std::move( name ), type );
	}

	var::VariablePtr ShaderWriter::registerOutParam( std::string name
		, type::TypePtr type )
	{
		return m_shader->registerOutParam( std::move( name ), type );
	}

	var::VariablePtr ShaderWriter::registerInOutParam( std::string name
		, type::TypePtr type )
	{
		return m_shader->registerInOutParam( std::move( name ), type );
	}

	var::VariablePtr ShaderWriter::getVar( std::string_view name )
	{
		return m_shader->getVar( name );
	}

	void ShaderWriter::registerSsbo( std::string name
		, SsboInfo const & info )
	{
		m_shader->registerSsbo( std::move( name ), info );
	}

	void ShaderWriter::registerUbo( std::string name
		, UboInfo const & info )
	{
		m_shader->registerUbo( std::move( name ), info );
	}

	void ShaderWriter::addStmt( stmt::StmtPtr stmt )
	{
		m_shader->addStmt( std::move( stmt ) );
	}

	void ShaderWriter::addGlobalStmt( stmt::StmtPtr stmt )
	{
		m_shader->addGlobalStmt( std::move( stmt ) );
	}

	void ShaderWriter::inlineComment( std::string const & comment )
	{
	}

	void ShaderWriter::multilineComment( std::string const & comment )
	{
	}

	void ShaderWriter::demote()
	{
		assert( m_shader->getType() == ast::ShaderStage::eFragment
			|| m_shader->getType() == ast::ShaderStage::eTraditionalGraphics
			|| m_shader->getType() == ast::ShaderStage::eModernGraphicsNV
			|| m_shader->getType() == ast::ShaderStage::eModernGraphics );
		addStmt( getStmtCache().makeDemote() );
	}

	void ShaderWriter::terminate()
	{
		assert( m_shader->getType() == ast::ShaderStage::eFragment
			|| m_shader->getType() == ast::ShaderStage::eTraditionalGraphics
			|| m_shader->getType() == ast::ShaderStage::eModernGraphicsNV
			|| m_shader->getType() == ast::ShaderStage::eModernGraphics );
		addStmt( getStmtCache().makeTerminateInvocation() );
	}

	void ShaderWriter::returnStmt()
	{
		addStmt( makeReturn( getStmtCache() ) );
	}

	void ShaderWriter::pushScope()
	{
		doPushScope( getStmtCache().makeContainer() );
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
		doPushScope( getStmtCache().makeFor( makeExpr( *this, init )
			, makeExpr( *this, cond )
			, makeExpr( *this, incr ) ) );
		function();
		popScope();
	}

	void ShaderWriter::doWhileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		doPushScope( getStmtCache().makeDoWhile( std::move( condition ) ) );
		function();
		popScope();
	}

	void ShaderWriter::doWhileStmt( sdw::Boolean condition
		, std::function< void() > function )
	{
		return doWhileStmt( makeCondition( condition ), function );
	}

	void ShaderWriter::whileStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		doPushScope( getStmtCache().makeWhile( std::move( condition ) ) );
		function();
		popScope();
	}

	void ShaderWriter::whileStmt( sdw::Boolean condition
		, std::function< void() > function )
	{
		return whileStmt( makeCondition( condition ), function );
	}

	ShaderWriter & ShaderWriter::ifStmt( expr::ExprPtr condition
		, std::function< void() > function )
	{
		auto stmt = getStmtCache().makeIf( std::move( condition ) );
		m_ifStmt.push_back( stmt.get() );
		doPushScope( std::move( stmt ) );
		function();
		popScope();
		return *this;
	}

	ShaderWriter & ShaderWriter::ifStmt( sdw::Boolean condition
		, std::function< void() > function )
	{
		return ifStmt( makeCondition( condition ), function );
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

	ShaderWriter & ShaderWriter::elseIfStmt( sdw::Boolean condition
		, std::function< void() > function )
	{
		return ifStmt( makeCondition( condition ), function );
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
		auto stmt = getStmtCache().makeSwitch( getExprCache().makeSwitchTest( std::move( value ) ) );
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
		auto stmt = m_switchStmt.back()->createCase( getExprCache().makeSwitchCase( std::move( literal ) ) );
		doPushScope( stmt
			, ast::var::VariableList{} );
		function();
		doPopScope();
	}

	void ShaderWriter::defaultStmt( std::function< void() > function )
	{
		auto stmt = m_switchStmt.back()->createDefault();
		doPushScope( stmt
			, ast::var::VariableList{} );
		function();
		doPopScope();
	}

	void ShaderWriter::caseBreakStmt()
	{
		addStmt( getStmtCache().makeBreak( true ) );
	}

	void ShaderWriter::loopBreakStmt()
	{
		addStmt( getStmtCache().makeBreak( false ) );
	}

	void ShaderWriter::loopContinueStmt()
	{
		addStmt( getStmtCache().makeContinue() );
	}

#pragma region Constant declaration

	void ShaderWriter::controlBarrier( type::Scope executionScope
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		sdw::controlBarrier( *this, executionScope, memoryScope, semantics );
	}

	void ShaderWriter::memoryBarrier( type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		sdw::memoryBarrier( *this, memoryScope, semantics );
	}

	void ShaderWriter::memoryBarrier()
	{
		sdw::memoryBarrier( *this );
	}

	void ShaderWriter::memoryBarrierBuffer()
	{
		sdw::memoryBarrierBuffer( *this );
	}

	void ShaderWriter::memoryBarrierShared()
	{
		sdw::memoryBarrierShared( *this );
	}

	void ShaderWriter::memoryBarrierImage()
	{
		sdw::memoryBarrierImage( *this );
	}

	void ShaderWriter::groupMemoryBarrier()
	{
		sdw::groupMemoryBarrier( *this );
	}

	void ShaderWriter::subgroupBarrier()
	{
		sdw::subgroupBarrier( *this );
	}

	void ShaderWriter::subgroupMemoryBarrier()
	{
		sdw::subgroupMemoryBarrier( *this );
	}

	void ShaderWriter::subgroupMemoryBarrierBuffer()
	{
		sdw::subgroupMemoryBarrierBuffer( *this );
	}

	void ShaderWriter::subgroupMemoryBarrierShared()
	{
		sdw::subgroupMemoryBarrierShared( *this );
	}

	void ShaderWriter::subgroupMemoryBarrierImage()
	{
		sdw::subgroupMemoryBarrierImage( *this );
	}

#pragma endregion

	Boolean ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, bool rhs
		, bool enabled )
	{
		auto type = Boolean::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Boolean{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Int8 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, int8_t rhs
		, bool enabled )
	{
		auto type = Int8::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Int8{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Int16 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, int16_t rhs
		, bool enabled )
	{
		auto type = Int16::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Int16{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Int32 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, int32_t rhs
		, bool enabled )
	{
		auto type = Int32::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Int32{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Int64 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, int64_t rhs
		, bool enabled )
	{
		auto type = Int64::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Int64{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	UInt8 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, uint8_t rhs
		, bool enabled )
	{
		auto type = UInt8::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return UInt8{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	UInt16 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, uint16_t rhs
		, bool enabled )
	{
		auto type = UInt16::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return UInt16{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	UInt32 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, uint32_t rhs
		, bool enabled )
	{
		auto type = UInt32::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return UInt32{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	UInt64 ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, uint64_t rhs
		, bool enabled )
	{
		auto type = UInt64::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return UInt64{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Float ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, float rhs
		, bool enabled )
	{
		auto type = Float::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Float{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	Double ShaderWriter::declSpecConstant( std::string name
		, uint32_t location
		, double rhs
		, bool enabled )
	{
		auto type = Double::makeType( getTypesCache() );
		auto var = registerSpecConstant( std::move( name )
			, location
			, type );

		if ( enabled )
		{
			addStmt( makeSpecialisationConstantDecl( getStmtCache()
				, var
				, location
				, getExprCache().makeLiteral( getTypesCache(), rhs ) ) );
		}

		return Double{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	AccelerationStructure ShaderWriter::declAccelerationStructure( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto type = AccelerationStructure::makeType( getTypesCache() );
		auto var = registerAccelerationStructure( std::move( name )
			, type
			, binding
			, set );

		if ( enabled )
		{
			addStmt( makeAccelerationStructureDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return AccelerationStructure{ *this
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

	var::VariablePtr ShaderWriter::registerStaticConstant( std::string name
		, type::TypePtr type )
	{
		return m_shader->registerStaticConstant( std::move( name ), type );
	}

	var::VariablePtr ShaderWriter::registerSpecConstant( std::string name
		, uint32_t location
		, type::TypePtr type )
	{
		return m_shader->registerSpecConstant( std::move( name ), location, type );
	}

	var::VariablePtr ShaderWriter::registerAccelerationStructure( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader->registerAccelerationStructure( std::move( name ), type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerSampler( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader->registerSampler( std::move( name ), type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerSampledImage( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader->registerSampledImage( std::move( name ), type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerTexture( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader->registerTexture( std::move( name ), type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerImage( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return m_shader->registerImage( std::move( name ), type, binding, set, enabled );
	}

	var::VariablePtr ShaderWriter::registerInOut( std::string name
		, uint64_t attributes
		, type::TypePtr type )
	{
		return m_shader->registerInOut( std::move( name ), attributes, type );
	}

	var::VariablePtr ShaderWriter::registerBuiltin( ast::Builtin builtin
		, type::TypePtr type
		, var::Flag flag )
	{
		return m_shader->registerBuiltin( builtin, type, flag );
	}
}
