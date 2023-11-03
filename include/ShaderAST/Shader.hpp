/*
See LICENSE file in root folder
*/
#ifndef ___AST_Shader_H___
#define ___AST_Shader_H___
#pragma once

#include "BoInfo.hpp"
#include "shader.h"

#include "ShaderAST/ShaderStlTypes.hpp"
#include "ShaderAST/Expr/ExprCache.hpp"
#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Stmt/StmtContainer.hpp"

#include <vector>
#include <map>
#include <set>
#include <stdexcept>

namespace ast
{
	enum class DescriptorType
	{
		eUniformBuffer,
		eStorageBuffer,
		eSampler,
		eTexture,
		eStorageImage,
		eUniformTexelBuffer,
		eStorageTexelBuffer,
		eShaderRecordBuffer,
		eCount,
	};

	struct ShaderData
	{
		using SsboMap = std::map< std::string, SsboInfo >;
		using UboMap = std::map< std::string, UboInfo >;
		using PcbMap = std::map< std::string, PcbInfo >;
		using ShaderRecordMap = std::map< std::string, ShaderRecordInfo >;
		using ConstantsMap = std::map< std::string, type::TypePtr >;
		using SpecConstantsMap = std::map< std::string, SpecConstantInfo >;
		using SamplerMap = std::map< std::string, SamplerInfo >;
		using TextureMap = std::map< std::string, TextureInfo >;
		using ImageMap = std::map< std::string, ImageInfo >;
		using InputMap = std::map< std::string, InputInfo >;
		using OutputMap = std::map< std::string, OutputInfo >;
		using InOutMap = std::map< std::string, InOutInfo >;

		SsboMap ssbos;
		UboMap ubos;
		PcbMap pcbs;
		ShaderRecordMap shaderRecords;
		ConstantsMap constants;
		SpecConstantsMap specConstants;
		SamplerMap samplers;
		TextureMap sampled;
		TextureMap textures;
		TextureMap uniformTexels;
		ImageMap images;
		ImageMap storageTexels;
		std::map< EntryPoint, InputMap > inputs;
		std::map< EntryPoint, OutputMap > outputs;
		InOutMap inOuts;
		AccStructInfo accelerationStruct;
		uint32_t tessellationControlPoints{};
		mutable uint32_t nextVarId{};
	};

	class Shader
	{
		friend class ShaderBuilder;

	public:
		SDAST_API explicit Shader( ast::ShaderStage type
			, ShaderAllocator * allocator = nullptr );
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		SDAST_API bool hasGlobalVariable( std::string_view const & name )const;
		SDAST_API var::VariablePtr getGlobalVariable( std::string_view const & name )const;
		SDAST_API void registerGlobalVariable( var::VariablePtr var );
		/**@}*/

		SsboInfo const & getSsboInfo( std::string const & name )const
		{
			return m_data.ssbos.at( name );
		}

		UboInfo const & getUboInfo( std::string const & name )const
		{
			return m_data.ubos.at( name );
		}

		ShaderRecordInfo const & getShaderRecordInfo( std::string const & name )const
		{
			return m_data.shaderRecords.at( name );
		}

		type::TypePtr getInput( EntryPoint entryPoint
			, std::string const & name )const
		{
			auto sit = m_data.inputs.find( entryPoint );

			if ( sit == m_data.inputs.end() )
			{
				return nullptr;
			}

			return sit->second.at( name ).type;
		}

		type::TypePtr getOutput( EntryPoint entryPoint
			, std::string const & name )const
		{
			auto sit = m_data.outputs.find( entryPoint );

			if ( sit == m_data.outputs.end() )
			{
				return nullptr;
			}

			return sit->second.at( name ).type;
		}

		std::map< std::string, SpecConstantInfo > const & getSpecConstants()const
		{
			return m_data.specConstants;
		}

		std::map< std::string, UboInfo > const & getUbos()const
		{
			return m_data.ubos;
		}

		std::map< std::string, SsboInfo > const & getSsbos()const
		{
			return m_data.ssbos;
		}

		std::map< std::string, PcbInfo > const & getPcbs()const
		{
			return m_data.pcbs;
		}

		std::map< std::string, ShaderRecordInfo > const & getShaderRecords()const
		{
			return m_data.shaderRecords;
		}

		std::map< std::string, SamplerInfo > const & getSamplers()const
		{
			return m_data.samplers;
		}

		std::map< std::string, TextureInfo > const & getSampled()const
		{
			return m_data.sampled;
		}

		std::map< std::string, TextureInfo > const & getCombinedImages()const
		{
			return m_data.textures;
		}

		std::map< std::string, TextureInfo > const & getUniformTexelBuffers()const
		{
			return m_data.uniformTexels;
		}

		std::map< std::string, ImageInfo > const & getStorageTexelBuffers()const
		{
			return m_data.storageTexels;
		}

		std::map< std::string, InputInfo > const & getInputs( EntryPoint entryPoint )const
		{
			auto sit = m_data.inputs.find( entryPoint );

			if ( sit == m_data.inputs.end() )
			{
				static std::map< std::string, InputInfo > const dummy;
				return dummy;
			}

			return sit->second;
		}

		std::map< std::string, OutputInfo > const & getOutputs( EntryPoint entryPoint )const
		{
			auto sit = m_data.outputs.find( entryPoint );

			if ( sit == m_data.outputs.end() )
			{
				static std::map< std::string, OutputInfo > const dummy;
				return dummy;
			}

			return sit->second;
		}

		std::map< std::string, InOutInfo > const & getInOuts()const
		{
			return m_data.inOuts;
		}

		stmt::Container * getStatements()const
		{
			return m_container.get();
		}

		ast::ShaderStage getType()const
		{
			return m_type;
		}

		ast::type::TypesCache & getTypesCache()const
		{
			return *m_typesCache;
		}

		ast::expr::ExprCache & getExprCache()const
		{
			return *m_exprCache;
		}

		ast::stmt::StmtCache & getStmtCache()const
		{
			return *m_stmtCache;
		}

		ShaderAllocatorBlock & getAllocator()const
		{
			return *m_allocator;
		}

		ShaderData const & getData()const
		{
			return m_data;
		}

		SDAST_API SdwShader getOpaqueHandle()const;
		SDAST_API static Shader const & fromOpaqueHandle(SdwShader shader);

	private:
		ShaderData & getData()
		{
			return m_data;
		}

	private:
		ast::ShaderStage m_type;
		std::unique_ptr< ShaderAllocator > m_ownAllocator;
		ShaderAllocatorBlockPtr m_allocator;
		std::unique_ptr< ast::type::TypesCache > m_typesCache;
		std::unique_ptr< ast::stmt::StmtCache > m_stmtCache;
		std::unique_ptr< ast::expr::ExprCache > m_exprCache;
		stmt::ContainerPtr m_container;
		Set< var::VariablePtr > m_globalVariables;
		ShaderData m_data;
	};
}

#endif
