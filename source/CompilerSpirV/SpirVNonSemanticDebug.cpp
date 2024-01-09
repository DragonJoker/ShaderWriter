/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVNonSemanticDebug.hpp"

#include "CompilerSpirV/SpirVDebugHelpers.hpp"
#include "CompilerSpirV/SpirVModule.hpp"
#include "CompilerSpirV/SpirVModuleTypes.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>

#include <ShaderAST/Stmt/StmtVisitor.hpp>

namespace spirv::debug
{
	namespace helpers
	{
		static std::string printVersion( uint32_t major = MAIN_VERSION_MAJOR
			, uint32_t minor = MAIN_VERSION_MINOR
			, uint32_t build = MAIN_VERSION_BUILD
			, uint32_t year = MAIN_VERSION_YEAR )
		{
			std::stringstream stream;
			stream.imbue( std::locale{ "C" } );
			stream << major << "." << minor << "." << build << "-" << year;
			return stream.str();
		}
	}

	NonSemanticDebug::NonSemanticDebug( ast::ShaderAllocatorBlock * allocator
		, Module & shaderModule
		, glsl::StmtConfig const * config )
		: m_allocator{ allocator }
		, m_module{ shaderModule }
		, m_types{ shaderModule.getTypes() }
		, m_config{ config }
		, m_declarations{ allocator }
	{
	}

	void NonSemanticDebug::initialise( InstructionList & imports
		, glsl::Statements const & debugStatements )
	{
		m_enabled = true;
		m_extDebugInfo = ValueId{ m_module.getIntermediateResult() };
		imports.emplace_back( makeInstruction< ExtInstImportInstruction >( m_module.getNameCache()
			, m_extDebugInfo
			, "NonSemantic.Shader.DebugInfo.100" ) );

		m_voidType = m_types.doRegisterBaseType( ast::type::Kind::eVoid, nullptr );

		m_debugInfoNone = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::InfoNone
			, m_declarations
			, ValueIdList{ m_allocator } );

		m_debugExpressionDummy = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Expression
			, m_declarations
			, ValueIdList{ m_allocator } );

		auto sourceNameId = m_module.registerString( "main.glsl" );
		auto sourceTextId = m_module.registerString( debugStatements.source );
		m_debugSourceId = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Source
			, m_declarations
			, debug::makeValueIdList( m_allocator, sourceNameId, sourceTextId ) );

		auto spvVersionId = m_module.registerLiteral( 1u );
		auto dwarfVersionId = m_module.registerLiteral( 4u );
		auto languageId = m_module.registerLiteral( 2u );
		m_globalScopeId = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::CompilationUnit
			, m_declarations
			, debug::makeValueIdList( m_allocator, spvVersionId, dwarfVersionId, m_debugSourceId, languageId ) );

		m_currentScopeId = m_globalScopeId;
	}

	spv::Id NonSemanticDebug::getNextId()const
	{
		return m_enabled ? m_module.getNextId() : 0u;
	}

	bool NonSemanticDebug::isExtNonSemanticDebugInfo( spv::Id id )const
	{
		return id == m_extDebugInfo.id;
	}

	void NonSemanticDebug::setExtID( spv::Id id )
	{
		m_extDebugInfo.id = id;
	}

	void NonSemanticDebug::registerBaseType( ast::type::Kind kind
		, DebugId & resultId )
	{
		if ( !m_enabled )
		{
			return;
		}

		if ( kind == ast::type::Kind::eVoid )
		{
			m_voidType = resultId;
		}

		auto nameId = m_module.registerString( glsl::getTypeName( kind ) );
		auto sizeId = m_module.registerLiteral( debug::getSize( kind ) );
		auto encodingId = m_module.registerLiteral( debug::getEncoding( kind ) );
		auto flagId = m_module.registerLiteral( 0u );
		resultId.debug = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeBasic
			, m_declarations
			, debug::makeValueIdList( m_allocator, nameId, sizeId, encodingId, flagId ) );
	}

	void NonSemanticDebug::registerArrayType( TypeId const & elementTypeId
		, uint32_t arraySize
		, DebugId & resultId )
	{
		if ( !m_enabled || !elementTypeId.debug )
		{
			return;
		}

		auto lengthId = m_module.registerLiteral( arraySize );
		resultId.debug = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeArray
			, m_declarations
			, debug::makeValueIdList( m_allocator, elementTypeId, lengthId ) );
	}

	void NonSemanticDebug::registerRuntimeArrayType( TypeId const & elementTypeId
		, DebugId & resultId )
	{
		registerArrayType( elementTypeId, 1024u, resultId );
	}

	void NonSemanticDebug::registerVectorType( TypeId const & componentTypeId
		, uint32_t componentCount
		, DebugId & resultId )
	{
		if ( !m_enabled || !componentTypeId.debug )
		{
			return;
		}

		auto countId = m_module.registerLiteral( componentCount );
		resultId.debug = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeVector
			, m_declarations
			, debug::makeValueIdList( m_allocator, componentTypeId, countId ) );
	}

	void NonSemanticDebug::registerMatrixType( TypeId const & componentTypeId
		, uint32_t componentCount
		, DebugId & resultId )
	{
		if ( !m_enabled || !componentTypeId.debug )
		{
			return;
		}

		auto countId = m_module.registerLiteral( componentCount );
		auto majornessId = m_module.registerLiteral( true );
		resultId.debug = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeMatrix
			, m_declarations
			, debug::makeValueIdList( m_allocator, componentTypeId, countId, majornessId ) );
	}

	void NonSemanticDebug::registerSamplerType( ast::type::SamplerPtr type
		, DebugId & resultId )
	{
		if ( !m_enabled )
		{
			return;
		}

		registerOpaqueType( glsl::getTypeName( type ), resultId );
	}

	void NonSemanticDebug::registerCombinedImageType( ast::type::CombinedImagePtr type
		, DebugId & resultId )
	{
		if ( !m_enabled )
		{
			return;
		}

		registerOpaqueType( glsl::getTypeName( type ), resultId );
	}

	void NonSemanticDebug::registerImageType( ast::type::ImagePtr type
		, DebugId & resultId )
	{
		if ( !m_enabled )
		{
			return;
		}

		registerOpaqueType( glsl::getTypeName( type ), resultId );
	}

	void NonSemanticDebug::registerAccelerationStructureType( DebugId & resultId )
	{
		if ( !m_enabled )
		{
			return;
		}

		registerOpaqueType( "accelerationStructure", resultId );
	}

	void NonSemanticDebug::registerMemberType( ast::type::Struct::Member const & member
		, DebugId const & subTypeId
		, glsl::Statement const * debugStatement
		, ValueIdList & subTypes )
	{
		if ( !m_enabled || !debugStatement )
		{
			return;
		}

		auto nameId = m_module.registerString( member.name );
		auto lineId = m_module.registerLiteral( debugStatement ? debugStatement->source.lines.start : 0u );
		auto columnId = m_module.registerLiteral( debugStatement ? debugStatement->source.columns.start : 0u );
		auto flagId = m_module.registerLiteral( 0u );
		auto offsetId = m_module.registerLiteral( member.offset * 8u );
		auto sizeId = m_module.registerLiteral( member.size * 8u );
		subTypes.push_back( makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeMember
			, m_declarations
			, debug::makeValueIdList( m_allocator, nameId, subTypeId, m_debugSourceId, lineId, columnId, offsetId, sizeId, flagId ) ) );
	}

	void NonSemanticDebug::registerStructType( ast::type::StructPtr structType
		, ValueIdList const & subTypes
		, glsl::Statement const * debugStatement
		, DebugId & resultId )
	{
		if ( !m_enabled || !debugStatement )
		{
			return;
		}

		auto tagId = m_module.registerLiteral( 1u );
		auto nameId = m_module.registerString( glsl::getTypeName( structType ) );
		auto lineId = m_module.registerLiteral( debugStatement ? debugStatement->source.lines.start : 0u );
		auto columnId = m_module.registerLiteral( debugStatement ? debugStatement->source.columns.start : 0u );
		auto flagId = m_module.registerLiteral( 0u );
		auto sizeId = m_module.registerLiteral( structType->empty() ? 0u : getSize( structType, structType->getMemoryLayout() ) * 8u );
		resultId.debug = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
			, m_declarations
			, debug::makeValueIdList( m_allocator, nameId, tagId, m_debugSourceId, lineId, columnId, m_globalScopeId, nameId, sizeId, flagId, subTypes ) );
	}

	void NonSemanticDebug::registerFunctionType( TypeIdList const & funcTypes
		, DebugId & resultId )
	{
		if ( !m_enabled )
		{
			return;
		}

		auto flagsId = m_module.registerLiteral( uint32_t( spv::NonSemanticShaderDebugInfo100DebugInfoFlags::IsPublic ) );
		resultId.debug = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeFunction
			, m_declarations
			, debug::makeValueIdList( m_allocator, flagsId, funcTypes ) );
	}

	void NonSemanticDebug::declareVariable( InstructionList & instructions
		, std::string const & name
		, ast::type::TypePtr type
		, DebugId variableId
		, DebugId initialiserId
		, glsl::Statement const * debugStatement
		, bool isAccessChain )
	{
		if ( !m_enabled || !debugStatement )
		{
			return;
		}

		auto nameId = m_module.registerString( name );
		auto typeId = m_module.registerType( type, debugStatement );
		auto lineId = m_module.registerLiteral( debugStatement->source.lines.start );
		auto columnId = m_module.registerLiteral( debugStatement->source.columns.start );
		auto flagsId = m_module.registerLiteral( 0u );
		assert( variableId.debug );

		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::LocalVariable
			, m_declarations
			, variableId.debug
			, debug::makeValueIdList( m_allocator, nameId, typeId, m_debugSourceId, lineId, columnId, m_globalScopeId, flagsId ) );

		if ( !isAccessChain )
		{
			// Access chains are not declared like traditional variables.
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Declare
				, instructions
				, debug::makeValueIdList( m_allocator, variableId.debug, variableId.id, m_debugExpressionDummy ) );
		}

		if ( initialiserId )
		{
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Value
				, instructions
				, debug::makeValueIdList( m_allocator, variableId.debug, initialiserId.id, m_debugExpressionDummy ) );
		}
	}

	void NonSemanticDebug::declarePointerParam( InstructionList & instructions
		, std::string const & name
		, ast::type::TypePtr type
		, DebugId variableId
		, DebugId initialiser
		, glsl::Statement const * debugStatement )
	{
		if ( !m_enabled )
		{
			return;
		}

		// if debugStatement exists, the variable will be declared prior to this call
		if ( !debugStatement )
		{
			declareVariable( instructions
				, name
				, std::move( type )
				, std::move( variableId )
				, std::move( initialiser )
				, m_currentFunctionFirstLineStatement );
		}
	}

	void NonSemanticDebug::declareAccessChain( InstructionList & instructions
		, ast::expr::Expr const & expr
		, glsl::Statement const * debugStatement
		, DebugId & resultId )
	{
		if ( !m_enabled || !debugStatement || !m_config )
		{
			return;
		}

		resultId.debug = ValueId{ getNextId(), expr.getType() };
		declareVariable( instructions
			, glsl::getExprName( *m_config, expr )
			, expr.getType()
			, resultId
			, DebugId{}
			, debugStatement
			, true );
	}

	void NonSemanticDebug::declareFunction( Function & function
		, std::string const & name
		, ast::var::VariableList const & params
		, DebugIdList const & funcParams
		, glsl::Statement const * declDebugStatement
		, glsl::Statement const * scopeBeginDebugStatement
		, glsl::Statement const * firstLineStatement )
	{
		if ( !m_enabled || !declDebugStatement || !scopeBeginDebugStatement || !firstLineStatement )
		{
			return;
		}

		m_currentFunctionFirstLineStatement = firstLineStatement;
		m_currentScopeId = function.id.debug;

		auto scopeLineId = m_module.registerLiteral( scopeBeginDebugStatement->source.lines.start );
		auto nameId = m_module.registerString( name );
		auto lineId = m_module.registerLiteral( declDebugStatement->source.lines.start ).id;
		auto columnId = m_module.registerLiteral( declDebugStatement->source.columns.start ).id;
		auto flagId = m_module.registerLiteral( 0u ).id;
		auto declId = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::FunctionDeclaration
			, m_declarations
			, debug::makeValueIdList( m_allocator
				, nameId, function.debugTypeId, m_debugSourceId, lineId, columnId, m_globalScopeId, nameId, flagId ) );
		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Function
			, m_declarations
			, function.id.debug
			, debug::makeValueIdList( m_allocator
				, nameId, function.debugTypeId, m_debugSourceId, lineId, columnId, m_globalScopeId, nameId, flagId, scopeLineId, declId ) );
		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::FunctionDefinition
			, function.debugStart
			, debug::makeValueIdList( m_allocator, function.id.debug, function.id.id ) );
		auto itParam = funcParams.begin();

		for ( auto & param : params )
		{
			auto paramNameId = m_module.registerString( param->getName() );
			auto paramTypeId = m_module.registerType( param->getType(), scopeBeginDebugStatement );
			auto paramColumnId = m_module.registerLiteral( 0u );
			auto paramFlagsId = m_module.registerLiteral( 0u );
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::LocalVariable
				, m_declarations
				, itParam->debug
				, debug::makeValueIdList( m_allocator
					, paramNameId, paramTypeId, m_debugSourceId, scopeLineId, paramColumnId, function.id.debug, paramFlagsId ) );

			++itParam;
		}
	}

	void NonSemanticDebug::makeEntryPointInstruction( DebugId functionId )
	{
		if ( !m_enabled )
		{
			return;
		}

		assert( functionId.debug );
		auto compilerSignatureId = m_module.registerString( "ShaderWriter-v" + helpers::printVersion() );
		auto cliArgumentsId = m_module.registerString( "-fullDebugInfo" );
		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::EntryPoint
			, m_declarations
			, debug::makeValueIdList( m_allocator
				, functionId.debug, m_globalScopeId, compilerSignatureId, cliArgumentsId ) );
	}

	void NonSemanticDebug::makeLexicalBlockInstruction( glsl::Statement const * scopeBeginStatement )
	{
		if ( !m_enabled || !scopeBeginStatement )
		{
			return;
		}

		auto lineId = m_module.registerLiteral( scopeBeginStatement->source.lines.start );
		auto columnId = m_module.registerLiteral( scopeBeginStatement->source.columns.start );
		m_currentScopeId = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::LexicalBlock
			, m_declarations
			, debug::makeValueIdList( m_allocator
				, m_debugSourceId, lineId, columnId, m_currentScopeId ) );
	}
	
	void NonSemanticDebug::makeValueInstruction( InstructionList & instructions
		, DebugId variableId
		, DebugId valueId )
	{
		if ( !m_enabled || !variableId.debug )
		{
			return;
		}

		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Value
			, instructions
			, debug::makeValueIdList( m_allocator, variableId.debug, valueId.id, m_debugExpressionDummy ) );
	}

	void NonSemanticDebug::makeScopeInstruction( InstructionList & instructions )
	{
		if ( !m_enabled )
		{
			return;
		}

		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Scope
			, instructions
			, debug::makeValueIdList( m_allocator, m_currentScopeId ) );
	}

	void NonSemanticDebug::makeNoScopeInstruction( InstructionList & instructions )
	{
		if ( !m_enabled )
		{
			return;
		}

		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::NoScope
			, instructions
			, ValueIdList{ m_allocator } );
	}

	void NonSemanticDebug::makeLineExtension( InstructionList & instructions
		, glsl::Statement const * debugStatement
		, glsl::RangeInfo const & columns )
	{
		if ( !m_enabled || !debugStatement || m_currentScopeId == m_globalScopeId )
		{
			return;
		}

		auto lineId = m_module.registerLiteral( debugStatement->source.lines.start );
		auto columnStartId = m_module.registerLiteral( columns.start );
		auto columnEndId = m_module.registerLiteral( columns.end );
		makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Line
			, instructions
			, debug::makeValueIdList( m_allocator
				, m_debugSourceId, lineId, lineId, columnStartId, columnEndId ) );
	}

	void NonSemanticDebug::makeLineExtension( InstructionList & instructions
		, glsl::Statement const * debugStatement
		, ast::expr::Expr const & expr )
	{
		if ( !debugStatement )
		{
			return;
		}

		auto columns = debugStatement->source.columns;

		if ( auto it = debugStatement->exprs.find( &expr );
			it != debugStatement->exprs.end() )
		{
			columns = it->second;
		}

		makeLineExtension( instructions, debugStatement, columns );
	}

	ValueId NonSemanticDebug::makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
		, InstructionList & instructions
		, ValueIdList operands )
	{
		ValueId resultId{ m_module.getNextId() };
		makeDebugInstruction( instruction, instructions, resultId, std::move( operands ) );
		return resultId;
	}

	void NonSemanticDebug::makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
		, InstructionList & instructions
		, ValueId resultId
		, ValueIdList operands )
	{
		instructions.emplace_back( makeInstruction< ExtInstInstruction >( m_module.getNameCache()
			, m_voidType.id
			, resultId
			, debug::makeValueIdList( m_allocator, m_extDebugInfo, ValueId{ spv::Id( instruction ) }, operands ) ) );
	}

	void NonSemanticDebug::registerOpaqueType( std::string const & name
		, DebugId & resultId )
	{
		auto tagId = m_module.registerLiteral( 0u );
		auto nameId = m_module.registerString( "@" + name );
		auto lineId = m_module.registerLiteral( 0u );
		auto columnId = m_module.registerLiteral( 0u );
		auto flagId = m_module.registerLiteral( 0u );
		resultId.debug = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
			, m_declarations
			, debug::makeValueIdList( m_allocator
				, nameId, tagId, m_debugSourceId, lineId, columnId, m_globalScopeId, nameId, m_debugInfoNone, flagId ) );
	}
}
