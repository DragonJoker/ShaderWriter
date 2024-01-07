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
		using SsboMap = std::map< std::string, SsboInfo, std::less<> >;
		using UboMap = std::map< std::string, UboInfo, std::less<> >;
		using PcbMap = std::map< std::string, PcbInfo, std::less<> >;
		using ShaderRecordMap = std::map< std::string, ShaderRecordInfo, std::less<> >;
		using ConstantsMap = std::map< std::string, type::TypePtr, std::less<> >;
		using SpecConstantsMap = std::map< std::string, SpecConstantInfo, std::less<> >;
		using SamplerMap = std::map< std::string, SamplerInfo, std::less<> >;
		using TextureMap = std::map< std::string, TextureInfo, std::less<> >;
		using ImageMap = std::map< std::string, ImageInfo, std::less<> >;
		using InputMap = std::map< std::string, InputInfo, std::less<> >;
		using OutputMap = std::map< std::string, OutputInfo, std::less<> >;
		using InOutMap = std::map< std::string, InOutInfo, std::less<> >;

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
		std::map< EntryPoint, InputMap, std::less<> > inputs;
		std::map< EntryPoint, OutputMap, std::less<> > outputs;
		InOutMap inOuts;
		AccStructInfo accelerationStruct;
		uint32_t tessellationControlPoints{};
		mutable uint32_t nextVarId{};
	};

	class Shader
	{
		friend class ShaderBuilder;

	public:
		SDAST_API Shader( Shader const & ) = delete;
		SDAST_API Shader & operator=( Shader const & ) = delete;
		SDAST_API Shader( Shader && )noexcept = default;
		SDAST_API Shader & operator=( Shader && )noexcept = default;

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

		std::map< std::string, SpecConstantInfo, std::less<> > const & getSpecConstants()const
		{
			return m_data.specConstants;
		}

		std::map< std::string, UboInfo, std::less<> > const & getUbos()const
		{
			return m_data.ubos;
		}

		std::map< std::string, SsboInfo, std::less<> > const & getSsbos()const
		{
			return m_data.ssbos;
		}

		std::map< std::string, PcbInfo, std::less<> > const & getPcbs()const
		{
			return m_data.pcbs;
		}

		std::map< std::string, ShaderRecordInfo, std::less<> > const & getShaderRecords()const
		{
			return m_data.shaderRecords;
		}

		std::map< std::string, SamplerInfo, std::less<> > const & getSamplers()const
		{
			return m_data.samplers;
		}

		std::map< std::string, TextureInfo, std::less<> > const & getSampled()const
		{
			return m_data.sampled;
		}

		std::map< std::string, TextureInfo, std::less<> > const & getCombinedImages()const
		{
			return m_data.textures;
		}

		std::map< std::string, TextureInfo, std::less<> > const & getUniformTexelBuffers()const
		{
			return m_data.uniformTexels;
		}

		std::map< std::string, ImageInfo, std::less<> > const & getStorageTexelBuffers()const
		{
			return m_data.storageTexels;
		}

		std::map< std::string, InputInfo, std::less<> > const & getInputs( EntryPoint entryPoint )const
		{
			auto sit = m_data.inputs.find( entryPoint );

			if ( sit == m_data.inputs.end() )
			{
				static std::map< std::string, InputInfo, std::less<> > const dummy;
				return dummy;
			}

			return sit->second;
		}

		std::map< std::string, OutputInfo, std::less<> > const & getOutputs( EntryPoint entryPoint )const
		{
			auto sit = m_data.outputs.find( entryPoint );

			if ( sit == m_data.outputs.end() )
			{
				static std::map< std::string, OutputInfo, std::less<> > const dummy;
				return dummy;
			}

			return sit->second;
		}

		std::map< std::string, InOutInfo, std::less<> > const & getInOuts()const
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
