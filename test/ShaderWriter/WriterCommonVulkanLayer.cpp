#include "WriterCommonVulkanLayer.hpp"

#if SDW_Test_HasVulkan

#	include "CompileGLSL.hpp"
#	include "CompileSPIRV.hpp"
#	include "GlslToSpv.hpp"
#	include "WriterCommonSpirV.hpp"

#	if SDW_HasCompilerSpirV
#		include <CompilerSpirV/compileSpirV.hpp>
#	endif

#	include "PipelineBuilder.hpp"
#	include "ProgramPipeline.hpp"
#	include "MakeVkType.hpp"

#	include <ostream>
#	include <string>
#	include <sstream>
#	include <variant>

namespace test::sdw_test
{
	static std::string indent;

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorType const & rhs )
	{
		switch ( rhs )
		{
		case VK_DESCRIPTOR_TYPE_SAMPLER:
			stream << "VK_DESCRIPTOR_TYPE_SAMPLER";
			break;
		case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
			stream << "VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER";
			break;
		case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
			stream << "VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE";
			break;
		case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
			stream << "VK_DESCRIPTOR_TYPE_STORAGE_IMAGE";
			break;
		case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
			stream << "VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER";
			break;
		case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
			stream << "VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER";
			break;
		case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
			stream << "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER";
			break;
		case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
			stream << "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER";
			break;
		case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
			stream << "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC";
			break;
		case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
			stream << "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC";
			break;
		case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
			stream << "VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT";
			break;
		case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
			stream << "VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK";
			break;
		case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
			stream << "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR";
			break;
		case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
			stream << "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV";
			break;
		case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM:
			stream << "VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM";
			break;
		case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM:
			stream << "VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM";
			break;
		case VK_DESCRIPTOR_TYPE_TENSOR_ARM:
			stream << "VK_DESCRIPTOR_TYPE_TENSOR_ARM";
			break;
		case VK_DESCRIPTOR_TYPE_MUTABLE_EXT:
			stream << "VK_DESCRIPTOR_TYPE_MUTABLE_EXT";
			break;
		case VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV:
			stream << "VK_DESCRIPTOR_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_NV";
			break;
		case VK_DESCRIPTOR_TYPE_MAX_ENUM:
			stream << "VK_DESCRIPTOR_TYPE_MAX_ENUM";
			break;
		}

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkSpecializationMapEntry const & rhs )
	{
		stream << "VkSpecializationMapEntry: " << rhs.constantID << ", " << rhs.offset << ", " << rhs.size;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, vk::PipelineShaderStageCreateInfo const & rhs )
	{
		stream << "VkPipelineShaderStageCreateInfo: " << rhs->flags << ", " << rhs->stage << ", 0x" << rhs->module << ", " << rhs->pName;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorImageInfo const & rhs )
	{
		stream << "VkDescriptorImageInfo: 0x" << rhs.sampler << ", 0x" << rhs.imageView << ", " << rhs.imageLayout;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorBufferInfo const & rhs )
	{
		stream << "VkDescriptorBufferInfo: 0x" << rhs.buffer << ", " << rhs.offset << ", " << rhs.range;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkWriteDescriptorSet const & rhs )
	{
		stream << "VkWriteDescriptorSet: 0x" << rhs.dstSet << ", " << rhs.dstBinding << ", " << rhs.dstArrayElement << ", " << rhs.descriptorType;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkSpecializationInfo const & rhs )
	{
		stream << "VkSpecializationInfo: " << rhs.dataSize;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkVertexInputAttributeDescription const & rhs )
	{
		stream << "VkVertexInputAttributeDescription: " << rhs.location << ", " << rhs.binding << ", " << rhs.format << ", " << rhs.offset;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkAttachmentDescription const & rhs )
	{
		stream << "VkAttachmentDescription: " << rhs.flags << ", " << rhs.format << ", " << rhs.samples << ", " << rhs.loadOp << ", " << rhs.storeOp << ", " << rhs.stencilLoadOp << ", " << rhs.stencilStoreOp << ", " << rhs.initialLayout << ", " << rhs.finalLayout;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkShaderModuleCreateInfo const & rhs )
	{
		stream << "VkShaderModuleCreateInfo: " << rhs.flags << ", " << rhs.codeSize;

		return stream;
	}

	std::ostream & operator<<( std::ostream & stream, VkDescriptorSetLayoutBinding const & rhs )
	{
		stream << "VkDescriptorSetLayoutBinding: " << rhs.binding << ", " << rhs.descriptorType << ", " << rhs.stageFlags << ", 0x" << rhs.pImmutableSamplers;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorSetLayoutCreateInfo const & rhs )
	{
		stream << "VkDescriptorSetLayoutCreateInfo: " << rhs.flags;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkDescriptorPoolSize const & rhs )
	{
		stream << "VkDescriptorPoolSize: " << rhs.type << ", " << rhs.descriptorCount;

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, VkPushConstantRange const & rhs )
	{
		stream << "VkPushConstantRange: " << rhs.stageFlags << ", " << rhs.offset << ", " << rhs.size;

		return stream;
	}

	template< typename DataT, typename ValueT, typename CountT, size_t DataOffsetT, size_t CountOffsetT, size_t DivisorT >
	static std::ostream & operator<<( std::ostream & stream, vk::ArrayHolder< DataT, ValueT, CountT, DataOffsetT, CountOffsetT, DivisorT > const & rhs )
	{
		stream << rhs.data;

		if ( !rhs.values.empty() )
		{
			auto save = indent;
			indent += "  ";
			stream << std::endl << indent;

			for ( size_t i = 0u; i < rhs.values.size(); ++i )
			{
				stream << rhs.values[i];
				if ( i < rhs.values.size() - 1u )
					stream << std::endl << indent;
			}

			indent = save;
			stream << std::endl << indent;
		}

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, vk::AccelerationStructureWriteDescriptorSet const & rhs )
	{
		stream << rhs.data;

		if ( !rhs.values.empty() )
		{
			auto save = indent;
			indent += "  ";
			stream << std::endl << indent;

			for ( size_t i = 0u; i < rhs.values.size(); ++i )
			{
				stream << "0x" << rhs.values[i];
				if ( i < rhs.values.size() - 1u )
					stream << std::endl << indent;
			}

			indent = save;
			stream << std::endl << indent;
		}

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, vk::WriteDescriptorSet const & rhs )
	{
		std::visit( [&stream]( auto && arg )
			{
				stream << arg << std::endl << indent;
			}, rhs );

		return stream;
	}

	template< typename DataT >
	static std::ostream & operator<<( std::ostream & stream, std::optional< DataT > const & rhs )
	{
		if ( rhs )
		{
			stream << *rhs << std::endl << indent;
		}

		return stream;
	}

	template< typename DataT >
	static std::ostream & operator<<( std::ostream & stream, std::vector< DataT > const & rhs )
	{
		if ( !rhs.empty() )
		{
			stream << std::endl << indent << "Entries: " << uint32_t( rhs.size() );
			auto save = indent;
			indent += "  ";
			stream << std::endl << indent;

			for ( size_t i = 0u; i < rhs.size(); ++i )
			{
				stream << rhs[i];
				if ( i < rhs.size() - 1u )
					stream << std::endl << indent;
			}

			indent = save;
			stream << std::endl << indent;
		}

		return stream;
	}

	template< typename KeyT, typename DataT >
	static std::ostream & operator<<( std::ostream & stream, std::map< KeyT, DataT > const & rhs )
	{
		if ( !rhs.empty() )
		{
			stream << std::endl << indent << "Entries: " << uint32_t( rhs.size() );
			auto save = indent;
			indent += "  ";
			stream << std::endl << indent;
			auto it = rhs.begin();

			for ( size_t i = 0u; i < rhs.size(); ++i )
			{
				stream << it->first << ": " << it->second;
				if ( i < rhs.size() - 1u )
					stream << std::endl << indent;
				++it;
			}

			indent = save;
			stream << std::endl << indent;
		}

		return stream;
	}

	static std::ostream & operator<<( std::ostream & stream, vk::ProgramPipeline const & rhs )
	{
		stream << "Shader Stages: ";
		stream << rhs.getShaderStages() << std::endl;
		stream << "Specialization Infos: ";
		stream << rhs.getSpecializationInfos() << std::endl;
		stream << "DescriptorSet Writes: ";
		stream << rhs.getDescriptorSetWrites() << std::endl;
		stream << "Vertex Attributes: ";
		stream << rhs.getVertexAttributes() << std::endl;
		stream << "AttachmentDescriptions: ";
		stream << rhs.getAttachmentDescriptions() << std::endl;
		stream << "ShaderModules: ";
		stream << rhs.getShaderModules() << std::endl;
		stream << "DescriptorLayouts: ";
		stream << rhs.getDescriptorLayouts() << std::endl;
		stream << "DescriptorPoolSizes: ";
		stream << rhs.getDescriptorPoolSizes( 1u ) << std::endl;
		stream << "PushConstantRanges: ";
		stream << rhs.getPushConstantRanges() << std::endl;
		return stream;
	}

	static std::string toString( vk::ProgramPipeline const & rhs )
	{
		indent = std::string{};
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
			if ( auto glslangSpirv = compileGlslToSpv( entryPoint.stage
				, glsl::compileGlsl( *testCounts.allocatorBlock
					, shader
					, statements.get()
					, entryPoint.stage
					, ast::SpecialisationInfo{}
					, cfg )
				, config.specVersion );
				!glslangSpirv.empty() )
			{
				displayShader( "glslang SPIR-V"
					, spirv::displaySpirv( *testCounts.allocatorBlock, glslangSpirv )
					, testCounts
					, true
					, false );
			}
		}
#endif
	}

	static vk::ProgramPipeline generateProgram( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, uint32_t infoIndex
		, sdw_test::TestCounts & testCounts )
	{
		auto timerBlock = testCounts.beginTimer( "generateProgram" );
		return vk::ProgramPipeline{ testCounts.getSpirVVersion( infoIndex )
			, shader, entryPoints };
	}

	static vk::ProgramPipeline generateProgram( vk::ShaderPtrs const & shaders
		, uint32_t infoIndex
		, sdw_test::TestCounts & testCounts )
	{
		auto timerBlock = testCounts.beginTimer( "generateProgram" );
		return vk::ProgramPipeline{ testCounts.getSpirVVersion( infoIndex )
			, shaders };
	}

	void validateShaderOnIndex( ::ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers )
	{
#if SDW_HasCompilerSpirV
		if ( compilers.spirV.enable
			&& testCounts.isSpirVInitialised( infoIndex )
			&& !testCounts.isSpvIgnored( infoIndex, compilers.spirV.ignoredSpv )
			&& testCounts.isSpvRequested( infoIndex, compilers.spirV.requestedSpv )
			&& testCounts.isVulkanRequested( infoIndex, compilers.spirV.requestedVulkan ) )
		{
			astOn( "Vulkan " + printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
				+ " - SPIR-V " + printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) );
			try
			{
				vk::ProgramPipeline program{ generateProgram( shader, entryPoints, infoIndex, testCounts ) };

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
			catch ( spirv::UnsupportedExtensionException & exc )
			{
				testCounts.printBlock( testCounts.testName + " - Validate - " + exc.what() );
			}
			catch ( spirv::ExtensionNotFoundException & exc )
			{
				testCounts.printBlock( testCounts.testName + " - Validate - " + exc.what() );
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

	void validateShaderOnIndex( vk::ShaderPtrs const & shaders
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, Compilers const & compilers )
	{
#if SDW_HasCompilerSpirV
		if ( compilers.spirV.enable
			&& testCounts.isSpirVInitialised( infoIndex )
			&& !testCounts.isSpvIgnored( infoIndex, compilers.spirV.ignoredSpv )
			&& testCounts.isSpvRequested( infoIndex, compilers.spirV.requestedSpv )
			&& testCounts.isVulkanRequested( infoIndex, compilers.spirV.requestedVulkan ) )
		{
			astOn( "Vulkan " + printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
				+ " - SPIR-V " + printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) );
			try
			{
				vk::ProgramPipeline program{ generateProgram( shaders, infoIndex, testCounts ) };

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
			catch ( spirv::UnsupportedExtensionException & exc )
			{
				testCounts.printBlock( testCounts.testName + " - Validate - " + exc.what() );
			}
			catch ( spirv::ExtensionNotFoundException & exc )
			{
				testCounts.printBlock( testCounts.testName + " - Validate - " + exc.what() );
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
