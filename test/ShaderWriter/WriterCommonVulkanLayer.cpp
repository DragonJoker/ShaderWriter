#include "WriterCommonVulkanLayer.hpp"

#if SDW_Test_HasVulkan && SDW_HasVulkanLayer

#	include "CompileGLSL.hpp"
#	include "CompileSPIRV.hpp"
#	include "GlslToSpv.hpp"
#	include "WriterCommonSpirV.hpp"

#	if SDW_HasCompilerSpirV
#		include <CompilerSpirV/compileSpirV.hpp>
#	endif

#	include <VulkanLayer/PipelineBuilder.hpp>
#	include <VulkanLayer/ProgramPipeline.hpp>
#	include <VulkanLayer/MakeVkType.hpp>

#	include <ostream>
#	include <string>
#	include <sstream>
#	include <variant>

namespace test::sdw_test
{
	static std::ostream & operator<<( std::ostream & stream, VkSpecializationMapEntry const & rhs )
	{
		stream << rhs.constantID << ", " << rhs.offset << ", " << rhs.size;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, ast::vk::PipelineShaderStageCreateInfo const & rhs )
	{
		stream << rhs->flags << ", " << rhs->stage << ", " << rhs->module << ", " << rhs->pName;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkWriteDescriptorSet const & rhs )
	{
		stream << rhs.dstSet << ", " << rhs.dstBinding << ", " << rhs.dstArrayElement << ", " << rhs.descriptorType;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorImageInfo const & rhs )
	{
		stream << rhs.sampler << ", " << rhs.imageView << ", " << rhs.imageLayout;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorBufferInfo const & rhs )
	{
		stream << rhs.buffer << ", " << rhs.offset << ", " << rhs.range;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkSpecializationInfo const & rhs )
	{
		stream << rhs.dataSize;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkVertexInputAttributeDescription const & rhs )
	{
		stream << rhs.location << ", " << rhs.binding << ", " << rhs.format << ", " << rhs.offset;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkAttachmentDescription const & rhs )
	{
		stream << rhs.flags << ", " << rhs.format << ", " << rhs.samples << ", " << rhs.loadOp << ", " << rhs.storeOp << ", " << rhs.stencilLoadOp << ", " << rhs.stencilStoreOp << ", " << rhs.initialLayout << ", " << rhs.finalLayout;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkShaderModuleCreateInfo const & rhs )
	{
		stream << rhs.flags << ", " << rhs.codeSize;

		return stream;
	}

	std::ostream & operator<<( std::ostream & stream, VkDescriptorSetLayoutBinding const & rhs )
	{
		stream << rhs.binding << ", " << rhs.descriptorType << ", " << rhs.stageFlags << ", " << rhs.pImmutableSamplers;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorSetLayoutCreateInfo const & rhs )
	{
		stream << rhs.flags;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorPoolSize const & rhs )
	{
		stream << rhs.type << ", " << rhs.descriptorCount;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkPushConstantRange const & rhs )
	{
		stream << rhs.stageFlags << ", " << rhs.offset << ", " << rhs.size;

		return stream;
	}

	template< typename DataT, typename ValueT, typename CountT, size_t DataOffsetT, size_t CountOffsetT, size_t DivisorT >
	static std::ostream & operator<<( std::ostream & stream, ast::vk::ArrayHolder< DataT, ValueT, CountT, DataOffsetT, CountOffsetT, DivisorT > const & rhs )
	{
		stream << "  Base Values: " << rhs.data;

		if ( !rhs.values.empty() )
		{
			stream << std::endl << "  Entries:" << std::endl;

			for ( auto const & value : rhs.values )
			{
				stream << value << std::endl;
			}
		}

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, ast::vk::WriteDescriptorSet const & rhs )
	{
		std::visit( [&stream]( auto && arg )
		{
		stream << arg << std::endl;
		}, rhs );

		return stream;
	}

	template< typename DataT >
	static std::ostream & operator<<( std::ostream & stream, std::optional< DataT > const & rhs )
	{
		if ( rhs )
		{
			stream << *rhs << std::endl;
		}

		return stream;
	}

	template< typename DataT >
	static std::ostream & operator<<( std::ostream & stream, std::vector< DataT > const & rhs )
	{
		if ( !rhs.empty() )
		{
			stream << "  Entries:" << std::endl;

			for ( auto const & data : rhs )
			{
				stream << "    " << data << std::endl;
			}
		}

		return stream;
	}

	template< typename KeyT, typename DataT >
	static std::ostream & operator<<( std::ostream & stream, std::map< KeyT, DataT > const & rhs )
	{
		if ( !rhs.empty() )
		{
			stream << "  Entries:" << std::endl;

			for ( auto const & [key, data] : rhs )
			{
				stream << "    " << key << ": " << data << std::endl;
			}
		}

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, ast::vk::ProgramPipeline const & rhs )
	{
		stream << "Shader Stages: " << std::endl;
		stream << rhs.getShaderStages() << std::endl;
		stream << "Specialization Infos: " << std::endl;
		stream << rhs.getSpecializationInfos() << std::endl;
		stream << "DescriptorSet Writes: " << std::endl;
		stream << rhs.getDescriptorSetWrites() << std::endl;
		stream << "Vertex Attributes: " << std::endl;
		stream << rhs.getVertexAttributes() << std::endl;
		stream << "AttachmentDescriptions: " << std::endl;
		stream << rhs.getAttachmentDescriptions() << std::endl;
		stream << "ShaderModules: " << std::endl;
		stream << rhs.getShaderModules() << std::endl;
		stream << "DescriptorLayouts: " << std::endl;
		stream << rhs.getDescriptorLayouts() << std::endl;
		stream << "DescriptorPoolSizes: " << std::endl;
		stream << rhs.getDescriptorPoolSizes( 1u ) << std::endl;
		stream << "PushConstantRanges: " << std::endl;
		stream << rhs.getPushConstantRanges() << std::endl;
		return stream;
	}

	static std::string toString( ast::vk::ProgramPipeline const & rhs )
	{
		std::stringstream stream;
		stream.imbue( std::locale{ "C" } );
		stream << rhs;
		return stream.str();
	}

	static auto spirvCrossValidate( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
#if SDW_Test_HasSpirVCross
		for ( auto const & entryPoint : entryPoints )
		{
			spirv::SpirVConfig config{};
			config.debugLevel = spirv::DebugLevel::eNames;
			ast::stmt::StmtCache compileStmtCache{ *testCounts.allocatorBlock };
			ast::expr::ExprCache compileExprCache{ *testCounts.allocatorBlock };
			auto statements = ::ast::selectEntryPoint( compileStmtCache
				, compileExprCache
				, entryPoint
				, *shader.getStatements() );
			config.specVersion = testCounts.getSpirVVersion( infoIndex );
			auto sdwSpirV = spirv::serialiseSpirv( *testCounts.allocatorBlock
				, shader
				, statements.get()
				, entryPoint.stage
				, config );
			auto crossGlsl = validateSpirVToGlsl( sdwSpirV
				, entryPoint.stage
				, testCounts
				, true );
			auto textSpirv = spirv::writeSpirv( *testCounts.allocatorBlock
				, shader
				, statements.get()
				, entryPoint.stage
				, config );
			displayShader( "SPIR-V"
				, textSpirv
				, testCounts
				, true
				, false );
			displayShader( "SpirV-Cross GLSL"
				, crossGlsl
				, testCounts
				, true
				, true );
			auto cfg = getGlslConfig( glsl::v4_6, testCounts );
			auto glslangSpirv = compileGlslToSpv( entryPoint.stage
				, glsl::compileGlsl( *testCounts.allocatorBlock
					, shader
					, statements.get()
					, entryPoint.stage
					, ast::SpecialisationInfo{}
					, cfg )
				, config.specVersion );
			displayShader( "glslang SPIR-V"
				, spirv::displaySpirv( *testCounts.allocatorBlock, glslangSpirv )
				, testCounts
				, true
				, false );
		}
#endif
	}

	static ast::vk::ProgramPipeline generateProgram( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, uint32_t infoIndex
		, sdw_test::TestCounts & testCounts )
	{
		auto timerBlock = testCounts.beginTimer( "generateProgram" );
		return ast::vk::ProgramPipeline{ testCounts.getSpirVVersion( infoIndex )
			, shader, entryPoints };
	}

	static ast::vk::ProgramPipeline generateProgram( ast::vk::ShaderPtrs const & shaders
		, uint32_t infoIndex
		, sdw_test::TestCounts & testCounts )
	{
		auto timerBlock = testCounts.beginTimer( "generateProgram" );
		return ast::vk::ProgramPipeline{ testCounts.getSpirVVersion( infoIndex )
			, shaders };
	}

	void validateShaderOnIndex( ::ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers )
	{
#if SDW_HasCompilerSpirV
		if ( compilers.spirV
			&& testCounts.isSpirVInitialised( infoIndex ) )
		{
			astOn( "Vulkan " + printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
				+ " - SPIR-V " + printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) );
			try
			{
				ast::vk::ProgramPipeline program{ generateProgram( shader, entryPoints, infoIndex, testCounts ) };

				if ( compilers.forceDisplay )
				{
					testCounts.printBlock( toString( program ) );
				}

				std::string errors;

				if ( auto isValidated = validateProgram( program, errors, testCounts, infoIndex );
					errors.find( "failed to compile internal representation" ) == std::string::npos
						&& errors.find( "unexpected compilation failure" ) == std::string::npos )
				{
					astCheck( isValidated && errors.empty() )

					if ( !isValidated || !errors.empty() )
					{
						testCounts.printError( errors );
						astCheckNoThrow( spirvCrossValidate( shader, entryPoints, testCounts, infoIndex ) );
					}
				}
			}
			catch ( std::exception & exc )
			{
				if ( auto err = std::string{ exc.what() };
					err != std::string{ "Shader serialization failed." }
						&& err.find( "failed to compile internal representation" ) == std::string::npos
						&& err.find( "unexpected compilation failure" ) == std::string::npos )
				{
					testCounts.printError( "Shader validation:\n" + err );
				}
			}
		}
#endif
	}

	void validateShaderOnIndex( ast::vk::ShaderPtrs const & shaders
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers )
	{
#if SDW_HasCompilerSpirV
		if ( compilers.spirV
			&& testCounts.isSpirVInitialised( infoIndex ) )
		{
			astOn( "Vulkan " + printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
				+ " - SPIR-V " + printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) );
			try
			{
				ast::vk::ProgramPipeline program{ generateProgram( shaders, infoIndex, testCounts ) };

				if ( compilers.forceDisplay )
				{
					testCounts.printBlock( toString( program ) );
				}

				std::string errors;

				if ( auto isValidated = validateProgram( program, errors, testCounts, infoIndex );
					errors.find( "failed to compile internal representation" ) == std::string::npos
						&& errors.find( "unexpected compilation failure" ) == std::string::npos )
				{
					astCheck( isValidated && errors.empty() )

					if ( !isValidated || !errors.empty() )
					{
						testCounts.printError( errors );

						for ( auto const * shader : shaders )
						{
							ast::EntryPointConfigArray entryPoints{ ast::StlAllocatorT< ast::EntryPointConfig >{ &shader->getAllocator() } };
							entryPoints.emplace_back( shader->getType(), "main" );
							astCheckNoThrow( spirvCrossValidate( *shader
								, entryPoints
								, testCounts
								, infoIndex ) );
						}
					}
				}
			}
			catch ( std::exception & exc )
			{
				if ( auto err = std::string{ exc.what() };
					err != std::string{ "Shader serialization failed." }
						&& err.find( "failed to compile internal representation" ) == std::string::npos
						&& err.find( "unexpected compilation failure" ) == std::string::npos )
				{
					testCounts.printError( "Shader validation:\n" + err );
				}
			}
		}
#endif
	}
}

#endif
