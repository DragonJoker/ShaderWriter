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
#include <ShaderAST/Visitors/PreprocessShader.hpp>
#include <ShaderAST/Visitors/SelectEntryPoint.hpp>
#include <ShaderAST/Visitors/SimplifyStatements.hpp>

#include <algorithm>
#include <iostream>

namespace spirv
{
	void ModuleDeleter::operator()( Module * shaderModule )
	{
		delete shaderModule;
	}

	ModulePtr compilePreprocessedSpirV( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::PreprocessResult & preprocessResult
		, ast::ShaderStage stage
		, SpirVConfig & spirvConfig )
	{
		auto & typesCache = shader.getTypesCache();
		ModuleConfig moduleConfig{ &allocator
			, spirvConfig
			, typesCache
			, stage
			, preprocessResult.ssaData.nextVarId
			, preprocessResult.ssaData.aliasId };
		spirv::fillConfig( *preprocessResult.statements
			, moduleConfig );
		spirv::PreprocContext context;
		AdaptationData adaptationData{ &allocator, context, std::move( moduleConfig ) };
		auto statements = spirv::adaptStatements( *preprocessResult.stmtCache
			, *preprocessResult.exprCache
			, typesCache
			, *preprocessResult.statements
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::simplify( *preprocessResult.stmtCache
			, *preprocessResult.exprCache
			, typesCache
			, *statements );
		auto actions = listActions( *statements );
		glsl::Statements debug;
		glsl::StmtConfig stmtConfig;

		if ( spirvConfig.debugLevel == DebugLevel::eDebugInfo )
		{
			auto intrinsicsConfig = glsl::fillConfig( stage
				, *statements );

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
				, true };
			glsl::checkConfig( stmtConfig, intrinsicsConfig );
			debug = glsl::generateGlslStatements( stmtConfig, intrinsicsConfig, *statements, true );
		}

		return generateModule( *preprocessResult.exprCache
			, typesCache
			, *statements
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
		, ast::stmt::Container const * stmt
		, ast::ShaderStage stage
		, SpirVConfig & spirvConfig )
	{
		auto preprocessResult = ast::preprocessShader( allocator, shader, *stmt );
		return compilePreprocessedSpirV( allocator, shader, preprocessResult, stage, spirvConfig );
	}

	ModulePtr compileSpirV( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, SpirVConfig & spirvConfig )
	{
		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
		auto entryPoints = ast::listEntryPoints( *shader.getStatements() );
		auto it = std::find_if( entryPoints.begin()
			, entryPoints.end()
			, [&shader]( ast::EntryPointConfig const & lookup )
			{
				return lookup.stage == shader.getType();
			} );
		if ( it == entryPoints.end() )
		{
			return {};
		}

		auto statements = ast::selectEntryPoint( compileStmtCache
			, compileExprCache
			, *it
			, *shader.getStatements() );
		return compileSpirV( allocator
			, shader
			, statements.get()
			, shader.getType()
			, spirvConfig );
	}

	std::string writeModule( Module const & shaderModule
		, bool writeHeader )
	{
		std::string result;

		try
		{
			NameCache names{ shaderModule.allocator };
			result = Module::write( shaderModule, names, writeHeader );
		}
		catch ( ast::Exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::vector< uint32_t > serialiseModule( Module const & shaderModule )
	{
		std::vector< uint32_t > result{};

		try
		{
			auto spirv = Module::serialize( shaderModule );
			result.insert( result.end(), spirv.begin(), spirv.end() );
		}
		catch ( ast::Exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::string writeSpirv( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const * statements
		, ast::ShaderStage stage
		, SpirVConfig & config
		, bool writeHeader )
	{
		std::string result;

		try
		{
			auto shaderModule = compileSpirV( allocator, shader, statements, stage, config );
			NameCache names{ &allocator };
			result = Module::write( *shaderModule, names, writeHeader );
		}
		catch ( ast::Exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::string writeSpirv( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, SpirVConfig & config
		, bool writeHeader )
	{
		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
		auto entryPoints = ast::listEntryPoints( *shader.getStatements() );
		auto it = std::find_if( entryPoints.begin()
			, entryPoints.end()
			, [&shader]( ast::EntryPointConfig const & lookup )
			{
				return lookup.stage == shader.getType();
			} );
		if ( it == entryPoints.end() )
		{
			return {};
		}

		auto statements = ast::selectEntryPoint( compileStmtCache
			, compileExprCache
			, *it
			, *shader.getStatements() );
		return writeSpirv( allocator
			, shader
			, statements.get()
			, shader.getType()
			, config
			, writeHeader );
	}

	std::vector< uint32_t > serialiseSpirv( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const * statements
		, ast::ShaderStage stage
		, SpirVConfig & config )
	{
		std::vector< uint32_t > result;

		try
		{
			auto shaderModule = compileSpirV( allocator, shader, statements, stage, config );
			auto spirv = Module::serialize( *shaderModule );
			result.insert( result.end(), spirv.begin(), spirv.end() );
		}
		catch ( ast::Exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::vector< uint32_t > serialiseSpirv( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, SpirVConfig & config )
	{
		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
		auto entryPoints = ast::listEntryPoints( *shader.getStatements() );
		auto it = std::find_if( entryPoints.begin()
			, entryPoints.end()
			, [&shader]( ast::EntryPointConfig const & lookup )
			{
				return lookup.stage == shader.getType();
			} );
		if ( it == entryPoints.end() )
		{
			return {};
		}

		auto statements = ast::selectEntryPoint( compileStmtCache
			, compileExprCache
			, *it
			, *shader.getStatements() );
		return serialiseSpirv( allocator
			, shader
			, statements.get()
			, shader.getType()
			, config );
	}

	std::string displaySpirv( ast::ShaderAllocatorBlock & allocator
		, std::vector< uint32_t > const & spirv )
	{
		ast::type::TypesCache typesCache{};
		NameCache names{ &allocator };
		auto shaderModule = spirv::Module::deserialize( &allocator, typesCache, names, spirv );
		return spirv::Module::write( shaderModule, names, true );
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
			ast::var::VariablePtr var;
		};

		ast::type::TypesCache typesCache{};
		NameCache names{ &allocator };
		auto shaderModule = spirv::Module::deserialize( &allocator, typesCache, names, spirv );
		ast::Shader result{ stage };
		ast::Map< uint32_t, ast::Map< uint32_t, std::string > > mbrNames{ shaderModule.allocator };

		// Gather names
		for ( auto & instruction : shaderModule.getDebugStringsDeclarations() )
		{
			switch ( instruction->op.getOp() )
			{
			case spv::OpString:
				names.add( *instruction->resultId, *instruction->name );
				break;
			default:
				break;
			}
		}
		for ( auto & instruction : shaderModule.getDebugNamesDeclarations() )
		{
			switch ( instruction->op.getOp() )
			{
			case spv::OpSource:
				break;
			case spv::OpName:
				names.add( *instruction->resultId, *instruction->name );
				break;
			case spv::OpMemberName:
				{
					auto it = mbrNames.try_emplace( *instruction->returnTypeId, shaderModule.allocator ).first;
					it->second.try_emplace( *instruction->resultId, *instruction->name );
				}
				break;
			default:
				break;
			}
		}

		for ( auto const & instruction : shaderModule.extensions )
		{
			switch ( instruction->op.getOp() )
			{
			case spv::OpExtInstImport:
				break;
			case spv::OpExtension:
				break;
			default:
				break;
			}
		}

		for ( auto const & instruction : shaderModule.capabilities )
		{
			switch ( instruction->op.getOp() )
			{
			case spv::OpCapability:
				break;
			default:
				break;
			}
		}

		for ( auto const & instruction : shaderModule.executionModes )
		{
			switch ( instruction->op.getOp() )
			{
			case spv::OpExecutionMode:
				break;
			default:
				break;
			}
		}

		for ( auto const & instruction : shaderModule.executionModes )
		{
			switch ( instruction->op.getOp() )
			{
			case spv::OpDecorate:
				break;
			case spv::OpMemberDecorate:
				break;
			default:
				break;
			}
		}

		for ( auto const & instruction : shaderModule.globalDeclarations )
		{
			switch ( instruction->op.getOp() )
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
