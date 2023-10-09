/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/compileSpirV.hpp"

#include "SpirvAdaptStatements.hpp"
#include "SpirvCountActions.hpp"
#include "SpirvFillConfig.hpp"
#include "SpirvGenerateStatements.hpp"
#include "SpirvModule.hpp"

#include <GlslCommon/GenerateGlslStatements.hpp>

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
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
		, SpirVConfig & config )
	{
		ast::stmt::StmtCache compileStmtCache{ allocator };
		ast::expr::ExprCache compileExprCache{ allocator };
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto statements = ast::transformSSA( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, shader.getStatements()
			, ssaData );
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get() );
		ModuleConfig moduleConfig{ &allocator
			, config
			, shader.getTypesCache()
			, shader.getType()
			, ssaData.nextVarId
			, ssaData.aliasId };
		spirv::fillConfig( statements.get()
			, moduleConfig );
		spirv::PreprocContext context{ &allocator };
		AdaptationData adaptationData{ context, std::move( moduleConfig ) };
		statements = spirv::adaptStatements( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get()
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::simplify( compileStmtCache
			, compileExprCache
			, shader.getTypesCache()
			, statements.get() );
		auto actions = listActions( statements.get() );
		glsl::Statements debug;

		if ( config.debug )
		{
			glsl::StmtConfig stmtConfig{ shader.getType()
				, glsl::v4_6
				, glsl::GlslExtensionSet{ glsl::ARB_shader_stencil_export
					, glsl::KHR_vulkan_glsl
					, glsl::EXT_multiview
					, glsl::EXT_shader_explicit_arithmetic_types_int8
					, glsl::EXT_shader_explicit_arithmetic_types_int16
					, glsl::EXT_shader_explicit_arithmetic_types_int64
					, glsl::NV_gpu_shader5
					, glsl::ARB_viewport_array
					, glsl::ARB_texture_cube_map_array
					, glsl::ARB_texture_gather
					, glsl::ARB_gpu_shader_int64
					, glsl::ARB_compute_shader
					, glsl::NV_shader_atomic_float
					, glsl::NV_viewport_array2
					, glsl::NV_shader_atomic_fp16_vector
					, glsl::ARB_shader_ballot
					, glsl::ARB_shader_viewport_layer_array
					, glsl::NV_stereo_view_rendering
					, glsl::NVX_multiview_per_view_attributes
					, glsl::EXT_nonuniform_qualifier
					, glsl::NV_mesh_shader
					, glsl::EXT_mesh_shader
					, glsl::EXT_buffer_reference2
					, glsl::EXT_shader_atomic_float
					, glsl::EXT_ray_tracing
					, glsl::EXT_ray_query
					, glsl::EXT_scalar_block_layout
					, glsl::ARB_shader_draw_parameters
					, glsl::KHR_shader_subgroup
					, glsl::KHR_shader_subgroup_basic
					, glsl::KHR_shader_subgroup_vote
					, glsl::KHR_shader_subgroup_arithmetic
					, glsl::KHR_shader_subgroup_ballot
					, glsl::KHR_shader_subgroup_shuffle
					, glsl::KHR_shader_subgroup_shuffle_relative
					, glsl::KHR_shader_subgroup_clustered
					, glsl::KHR_shader_subgroup_quad
					, glsl::EXT_separate_samplers
					, glsl::ARB_shading_language_420pack
					, glsl::ARB_explicit_attrib_location
					, glsl::ARB_separate_shader_objects }
				, true
				, false
				, false
				, true
				, true
				, true
				, true
				, config.allocator };
			debug = glsl::generateGlslStatements( stmtConfig, statements.get() );
		}

		return generateModule( compileExprCache
			, shader.getTypesCache()
			, statements.get()
			, shader.getType()
			, adaptationData.config
			, std::move( context )
			, config
			, std::move( actions )
			, std::move( debug ) );
	}

	std::string writeModule( Module const & module
		, bool writeHeader )
	{
		std::string result;

		try
		{
			result = Module::write( module, writeHeader );
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
		, SpirVConfig & config
		, bool writeHeader )
	{
		auto ownAllocator = config.allocator ? nullptr : std::make_unique< ast::ShaderAllocator >();
		auto allocator = config.allocator ? config.allocator->getBlock() : ownAllocator->getBlock();
		std::string result;

		try
		{
			auto module = compileSpirV( *allocator, shader, config );
			result = Module::write( *module, writeHeader );
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
		auto ownAllocator = config.allocator ? nullptr : std::make_unique< ast::ShaderAllocator >();
		auto allocator = config.allocator ? config.allocator->getBlock() : ownAllocator->getBlock();
		std::vector< uint32_t > result;

		try
		{
			auto module = compileSpirV( *allocator, shader, config );
			auto spirv = Module::serialize( *module );
			result.insert( result.end(), spirv.begin(), spirv.end() );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::string displaySpirv( ast::ShaderAllocatorBlock & allocator
		, std::vector< uint32_t > const & spirv )
	{
		auto module = spirv::Module::deserialize( &allocator, spirv );
		return spirv::Module::write( module, true );
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

		auto module = spirv::Module::deserialize( &allocator, spirv );
		ast::Shader result{ stage };
		Map< uint32_t, std::string > names{ module.allocator };
		Map< uint32_t, Map< uint32_t, std::string > > mbrNames{ module.allocator };

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
					auto it = mbrNames.emplace( *instruction->returnTypeId, Map< uint32_t, std::string >{ module.allocator } ).first;
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
