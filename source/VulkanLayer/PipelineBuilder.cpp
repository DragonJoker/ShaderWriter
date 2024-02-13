/*
See LICENSE file in root folder
*/
#include "VulkanLayer/PipelineBuilder.hpp"

#include "VulkanLayer/ProgramPipeline.hpp"

#include <ShaderAST/Shader.hpp>

#include <CompilerSpirV/compileSpirV.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <iostream>
#include <sstream>
#pragma warning( pop )
#include <optional>

#if defined( _WIN32 )
#	include <Windows.h>
#elif defined( __linux__ )
#	include <unistd.h>
#	include <dirent.h>
#	include <pwd.h>
#elif defined( __APPLE__ )
#	include <mach-o/dyld.h>
#	include <sys/sysctl.h>
#endif

namespace ast::vk
{
	namespace piperr
	{
#if defined( _WIN32 )
		static char constexpr PathSeparator = '\\';
#else
		static char constexpr PathSeparator = '/';
#endif

		static std::string getPath( std::string const & path )
		{
			return path.substr( 0, path.find_last_of( PathSeparator ) );
		}

#if defined( _WIN32 )

		static std::string getExecutableDirectory()
		{
			std::string result;
			char path[FILENAME_MAX];
			DWORD res = ::GetModuleFileNameA( nullptr
				, path
				, sizeof( path ) );

			if ( res != 0 )
			{
				result = path;
			}

			result = getPath( result ) + PathSeparator;
			return result;
		}

#elif defined( __linux__ )

		static std::string getExecutableDirectory()
		{
			std::string result;
			char path[FILENAME_MAX];
			char buffer[32];
			sprintf( buffer, "/proc/%d/exe", getpid() );
			auto bytes = std::min< std::size_t >( readlink( buffer
				, path
				, sizeof( path ) )
				, sizeof( path ) - 1 );

			if ( bytes > 0 )
			{
				path[bytes] = '\0';
				result = path;
			}

			result = getPath( result ) + PathSeparator;
			return result;
		}

#elif defined( __APPLE__ )

		static std::string getExecutableDirectory()
		{
			std::string result;
			char path[FILENAME_MAX]{};
			uint32_t size = FILENAME_MAX;

			if ( _NSGetExecutablePath( &path[0], &size ) == 0 )
			{
				char realPath[FILENAME_MAX]{};
				result = realpath( path, realPath );
			}

			result = getPath( result );
			return result;
		}

#endif
	}

	//*********************************************************************************************

	PipelineBuilder::PipelineBuilder( BuilderContext context
		, ProgramPipeline program )
		: m_context{ std::move( context ) }
		, m_program{ std::move( program ) }
	{
	}

	VkDescriptorSetLayoutArray PipelineBuilder::createDescriptorSetLayouts()
	{
		VkDescriptorSetLayoutArray result;

		for ( auto const & createInfo : m_program.getDescriptorLayouts() )
		{
			VkDescriptorSetLayout layout;

			if ( auto res = m_context.vkCreateDescriptorSetLayout( m_context.device
					, &createInfo.data
					, m_context.allocator
					, &layout );
				!checkError( res ) )
			{
				throw ast::Exception{ "VkDescriptorSetLayout creation failed." };
			}

			result.push_back( layout );
		}

		return result;
	}

	VkPipelineLayout PipelineBuilder::createPipelineLayout( VkDescriptorSetLayoutArray const & layouts )
	{
		VkPipelineLayout result{ nullptr };
		auto createInfo = m_program.getPipelineLayout( layouts );

		if ( auto res = m_context.vkCreatePipelineLayout( m_context.device
				, &createInfo
				, m_context.allocator
				, &result );
			!checkError( res ) )
		{
			throw ast::Exception{ "VkPipelineLayout creation failed." };
		}

		return result;
	}

	VkShaderModuleArray PipelineBuilder::createShaderModules()
	{
		VkShaderModuleArray result;

		for ( auto const & createInfo : m_program.getShaderModules() )
		{
			VkShaderModule mod{ nullptr };

			if ( auto res = m_context.vkCreateModule( m_context.device
					, &createInfo
					, m_context.allocator
					, &mod );
				!checkError( res ) )
			{
				throw ast::Exception{ "VkShaderModule creation failed." };
			}

			result.push_back( mod );
		}

		return result;
	}

	PipelineShaderStageArray PipelineBuilder::createShaderStages( VkShaderModuleArray modules
		, std::vector< VkSpecializationInfoOpt > const & specializationInfo )const
	{
		return m_program.getShaderStages( std::move( modules ), specializationInfo );
	}

	VkResult PipelineBuilder::createGraphicsPipeline( VkGraphicsPipelineCreateInfo const & createInfos
		, VkPipeline * result )const
	{
		if ( !m_program.checkGraphicsPipeline( createInfos ) )
		{
			return VK_ERROR_VALIDATION_FAILED_EXT;
		}

		VkResult err{};
			err = m_context.vkCreateGraphicsPipeline( m_context.device
				, m_context.cache
				, 1u
				, &createInfos
				, m_context.allocator
				, result );
			checkError( err );

		if ( err != VK_SUCCESS )
		{
			uint32_t i{};
			for ( auto const & shaderModule : m_program.getShaderModules() )
			{
				auto fileName = piperr::getExecutableDirectory() + "FailedGraphicsPipelineShader_" + std::to_string( i ) + ".spv";

				if ( FILE * fileOut = fopen( fileName.c_str(), "wb" ) )
				{
					fwrite( shaderModule.pCode
						, sizeof( uint32_t )
						, shaderModule.codeSize / sizeof( uint32_t )
						, fileOut );
					fclose( fileOut );
				}

				++i;
			}
		}

		return err;
	}

	VkResult PipelineBuilder::createComputePipeline( VkComputePipelineCreateInfo const & createInfos
		, VkPipeline * result )const
	{
		if ( !m_program.checkComputePipeline() )
		{
			return VK_ERROR_VALIDATION_FAILED_EXT;
		}

#	if defined( WIN32 )
		__try
		{
#	endif
			auto err = m_context.vkCreateComputePipeline( m_context.device
				, m_context.cache
				, 1u
				, &createInfos
				, m_context.allocator
				, result );
			checkError( err );
			return err;
#	if defined( WIN32 )
		}
		__except ( GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION )
		{
			return VK_ERROR_INITIALIZATION_FAILED;
		}
#	endif
	}

	//*********************************************************************************************
}
