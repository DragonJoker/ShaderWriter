/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/compileSpirV.hpp"

#include "SpirVAdaptStatements.hpp"
#include "SpirVCountActions.hpp"
#include "SpirVFillConfig.hpp"
#include "SpirVGenerateStatements.hpp"
#include "SpirVModule.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>
#include <GlslCommon/GlslFillConfig.hpp>

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

#include <iostream>

namespace spirv
{
	void ModuleDeleter::operator()( Module * module )
	{
		delete module;
	}

	ModulePtr compileSpirV( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container * stmt
		, ast::ShaderStage stage
		, SpirVConfig & spirvConfig )
	{
		ast::SSAData ssaData;
		auto & typesCache = shader.getTypesCache();
		ssaData.nextVarId = shader.getData().nextVarId;
		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
		auto statements = ast::transformSSA( compileStmtCache
			, compileExprCache
			, typesCache
			, stmt
			, ssaData
			, true );
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, typesCache
			, statements.get() );
		statements = ast::resolveConstants( compileStmtCache
			, compileExprCache
			, typesCache
			, statements.get() );
		ModuleConfig moduleConfig{ &allocator
			, spirvConfig
			, typesCache
			, stage
			, ssaData.nextVarId
			, ssaData.aliasId };
		spirv::fillConfig( statements.get()
			, moduleConfig );
		spirv::PreprocContext context;
		AdaptationData adaptationData{ &allocator, context, std::move( moduleConfig ) };
		statements = spirv::adaptStatements( compileStmtCache
			, compileExprCache
			, typesCache
			, statements.get()
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, typesCache
			, statements.get() );
		auto actions = listActions( statements.get() );
		glsl::Statements debug;
		glsl::StmtConfig stmtConfig;

		if ( spirvConfig.debugLevel == DebugLevel::eDebugInfo )
		{
			auto intrinsicsConfig = glsl::fillConfig( stage
				, statements.get() );

			if ( intrinsicsConfig.requiresInt8 )
			{
				intrinsicsConfig.requiredExtensions.insert( glsl::EXT_shader_explicit_arithmetic_types_int8 );
			}

			if ( intrinsicsConfig.requiresInt16 )
			{
				intrinsicsConfig.requiredExtensions.insert( glsl::EXT_shader_explicit_arithmetic_types_int16 );
			}

			if ( intrinsicsConfig.requiresInt64 )
			{
				intrinsicsConfig.requiredExtensions.insert( glsl::ARB_gpu_shader_int64 );
			}

			stmtConfig = glsl::StmtConfig{ stage
				, glsl::v4_6
				, intrinsicsConfig.requiredExtensions
				, true
				, false
				, false
				, true
				, true
				, true
				, true
				, spirvConfig.allocator };
			glsl::checkConfig( stmtConfig, intrinsicsConfig );
			debug = glsl::generateGlslStatements( stmtConfig, intrinsicsConfig, statements.get(), true );
		}

		return generateModule( compileExprCache
			, typesCache
			, statements.get()
			, stage
			, adaptationData.config
			, std::move( context )
			, spirvConfig
			, stmtConfig
			, std::move( actions )
			, std::move( debug ) );
	}

	ModulePtr compileSpirV( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, SpirVConfig & spirvConfig )
	{
		return compileSpirV( allocator
			, shader
			, shader.getStatements()
			, shader.getType()
			, spirvConfig );
	}

	std::string writeModule( Module const & module
		, bool writeHeader )
	{
		std::string result;

		try
		{
			NameCache names{ module.allocator };
			result = Module::write( module, names, writeHeader );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::vector< uint32_t > serialiseModule( Module const & module )
	{
		std::vector< uint32_t > result{};

		try
		{
			auto spirv = Module::serialize( module );
			result.insert( result.end(), spirv.begin(), spirv.end() );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::string writeSpirv( ast::Shader const & shader
		, ast::stmt::Container * statements
		, ast::ShaderStage stage
		, SpirVConfig & config
		, bool writeHeader )
	{
		auto ownAllocator = config.allocator ? nullptr : std::make_unique< ast::ShaderAllocator >();
		auto allocator = config.allocator ? config.allocator->getBlock() : ownAllocator->getBlock();
		std::string result;

		try
		{
			auto module = compileSpirV( *allocator, shader, statements, stage, config );
			NameCache names{ allocator.get() };
			result = Module::write( *module, names, writeHeader );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::string writeSpirv( ast::Shader const & shader
		, SpirVConfig & config
		, bool writeHeader )
	{
		return writeSpirv( shader
			, shader.getStatements()
			, shader.getType()
			, config
			, writeHeader );
	}

	std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, ast::stmt::Container * statements
		, ast::ShaderStage stage
		, SpirVConfig & config )
	{
		auto ownAllocator = config.allocator ? nullptr : std::make_unique< ast::ShaderAllocator >();
		auto allocator = config.allocator ? config.allocator->getBlock() : ownAllocator->getBlock();
		std::vector< uint32_t > result;

		try
		{
			auto module = compileSpirV( *allocator, shader, statements, stage, config );
			auto spirv = Module::serialize( *module );
			result.insert( result.end(), spirv.begin(), spirv.end() );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, SpirVConfig & config )
	{
		return serialiseSpirv( shader
			, shader.getStatements()
			, shader.getType()
			, config );
	}

	std::string displaySpirv( ast::ShaderAllocatorBlock & allocator
		, std::vector< uint32_t > const & spirv )
	{
		ast::type::TypesCache typesCache{};
		NameCache names{ &allocator };
		auto module = spirv::Module::deserialize( &allocator, typesCache, names, spirv );
		return spirv::Module::write( module, names, true );
	}

	ast::Shader parseSpirv( ast::ShaderAllocatorBlock & allocator
		, ast::ShaderStage stage
		, std::vector< uint32_t > const & spirv )
	{
		struct Entity
		{
			enum Type
			{
				eType,
				eVar,
				eExpr,
			};

			uint32_t id;

		private:
			ast::type::TypePtr type;
			ast::var::VariablePtr var;
		};

		ast::type::TypesCache typesCache{};
		NameCache names{ &allocator };
		auto module = spirv::Module::deserialize( &allocator, typesCache, names, spirv );
		ast::Shader result{ stage };
		ast::Map< uint32_t, ast::Map< uint32_t, std::string > > mbrNames{ module.allocator };

		// Gather names
		for ( auto & instruction : module.getDebugStringsDeclarations() )
		{
			switch ( instruction->op.op )
			{
			case spv::OpString:
				names.add( *instruction->resultId, *instruction->name );
				break;
			default:
				break;
			}
		}
		for ( auto & instruction : module.getDebugNamesDeclarations() )
		{
			switch ( instruction->op.op )
			{
			case spv::OpSource:
				break;
			case spv::OpName:
				names.add( *instruction->resultId, *instruction->name );
				break;
			case spv::OpMemberName:
				{
					auto it = mbrNames.emplace( *instruction->returnTypeId, ast::Map< uint32_t, std::string >{ module.allocator } ).first;
					it->second.emplace( *instruction->resultId, *instruction->name );
				}
				break;
			default:
				break;
			}
		}

		for ( auto & instruction : module.extensions )
		{
			switch ( instruction->op.op )
			{
			case spv::OpExtInstImport:
				break;
			case spv::OpExtension:
				break;
			default:
				break;
			}
		}

		for ( auto & instruction : module.capabilities )
		{
			switch ( instruction->op.op )
			{
			case spv::OpCapability:
				break;
			default:
				break;
			}
		}

		for ( auto & instruction : module.executionModes )
		{
			switch ( instruction->op.op )
			{
			case spv::OpExecutionMode:
				break;
			default:
				break;
			}
		}

		for ( auto & instruction : module.executionModes )
		{
			switch ( instruction->op.op )
			{
			case spv::OpDecorate:
				break;
			case spv::OpMemberDecorate:
				break;
			default:
				break;
			}
		}

		for ( auto & instruction : module.globalDeclarations )
		{
			switch ( instruction->op.op )
			{
			case spv::OpTypeVoid:
			case spv::OpTypeBool:
			case spv::OpTypeInt:
			case spv::OpTypeFloat:
			case spv::OpTypeVector:
			case spv::OpTypeMatrix:
			case spv::OpTypeImage:
			case spv::OpTypeSampler:
			case spv::OpTypeSampledImage:
			case spv::OpTypeArray:
			case spv::OpTypeRuntimeArray:
			case spv::OpTypeStruct:
			case spv::OpTypeOpaque:
			case spv::OpTypePointer:
			case spv::OpTypeFunction:
			case spv::OpTypeEvent:
			case spv::OpTypeDeviceEvent:
			case spv::OpTypeReserveId:
			case spv::OpTypeQueue:
			case spv::OpTypePipe:
			case spv::OpTypeForwardPointer:
			case spv::OpVariable:
			case spv::OpConstant:
			case spv::OpConstantComposite:
			case spv::OpConstantFalse:
			case spv::OpConstantTrue:
			case spv::OpSpecConstant:
			case spv::OpSpecConstantComposite:
			case spv::OpSpecConstantFalse:
			case spv::OpSpecConstantTrue:
				break;
			default:
				break;
			}
		}

		return result;
	}
}
