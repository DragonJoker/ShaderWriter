/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/compileSpirV.hpp"

#include "SpirvCountActions.hpp"
#include "SpirvStmtAdapter.hpp"
#include "SpirvStmtConfigFiller.hpp"
#include "SpirvStmtVisitor.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/StmtSimplifier.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

#include <iostream>

namespace spirv
{
	namespace
	{
		spirv::Module compileSpirV( ast::Shader const & shader
			, SpirVConfig config )
		{
			ast::SSAData ssaData;
			ssaData.nextVarId = shader.getData().nextVarId;
			auto ssaStatements = ast::transformSSA( shader.getTypesCache()
				, shader.getStatements()
				, ssaData );
			auto simplified = ast::StmtSimplifier::submit( shader.getTypesCache()
				, ssaStatements.get() );
			ModuleConfig moduleConfig = spirv::StmtConfigFiller::submit( simplified.get() );
			moduleConfig.aliasId = ssaData.aliasId;
			moduleConfig.nextVarId = ssaData.nextVarId;
			spirv::PreprocContext context{};
			AdaptationData adaptationData{ context, moduleConfig };
			auto spirvStatements = spirv::StmtAdapter::submit( simplified.get(), adaptationData );
			auto actions = listActions( simplified.get() );
			return spirv::StmtVisitor::submit( shader.getTypesCache()
				, spirvStatements.get()
				, shader.getType()
				, moduleConfig
				, std::move( context )
				, config
				, std::move( actions ) );
		}
	}

	std::string writeSpirv( ast::Shader const & shader
		, SpirVConfig config
		, bool writeHeader )
	{
		std::string result;

		try
		{
			auto module = compileSpirV( shader, std::move( config ) );
			result = Module::write( module, writeHeader );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, SpirVConfig config )
	{
		std::vector< uint32_t > result;

		try
		{
			auto module = compileSpirV( shader, std::move( config ) );
			result = Module::serialize( module );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::string displaySpirv( std::vector< uint32_t > const & spirv )
	{
		auto module = spirv::Module::deserialize( spirv );
		return spirv::Module::write( module, true );
	}

	ast::Shader parseSpirv( ast::ShaderStage stage
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
			ast::expr::ExprPtr expr;
		};

		auto module = spirv::Module::deserialize( spirv );
		ast::Shader result{ stage };
		std::map< uint32_t, std::string > names;
		std::map< uint32_t, std::map< uint32_t, std::string > > mbrNames;

		// Gather names
		for ( auto & instruction : module.debug )
		{
			switch ( instruction->op.op )
			{
			case spv::OpSource:
				break;
			case spv::OpName:
				names.emplace( *instruction->resultId, *instruction->name );
				break;
			case spv::OpMemberName:
				{
					auto it = mbrNames.emplace( *instruction->returnTypeId, std::map< uint32_t, std::string >{} ).first;
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
