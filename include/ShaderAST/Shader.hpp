/*
See LICENSE file in root folder
*/
#ifndef ___AST_Shader_H___
#define ___AST_Shader_H___
#pragma once

#include "BoInfo.hpp"
#include "ast_shader.h"

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
		using AllInputsMap = std::map< EntryPoint, ShaderData::InputMap, std::less<> >;
		using AllOutputsMap = std::map< EntryPoint, ShaderData::OutputMap, std::less<> >;

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
		AllInputsMap inputs;
		AllOutputsMap outputs;
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
		SDAST_API Shader( Shader && rhs )noexcept;
		SDAST_API Shader & operator=( Shader && rhs )noexcept = delete;

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
		/**
		*name
		*	Data helpers.
		*/
		/**@{*/
		SDAST_API uint32_t getNextVarId();
		SDAST_API void setTessellationControlPoints( uint32_t v );
		SDAST_API void registerConstant( std::string name, type::TypePtr type );
		SDAST_API void registerSpecConstant( std::string name, type::TypePtr type, uint32_t location );
		SDAST_API void registerSampler( std::string name, type::TypePtr type, uint32_t binding, uint32_t set );
		SDAST_API void registerUniformTexelBuffer( std::string name, type::TypePtr type, uint32_t binding, uint32_t set );
		SDAST_API void registerStorageTexelBuffer( std::string name, type::TypePtr type, uint32_t binding, uint32_t set );
		SDAST_API void registerSampledImage( std::string name, type::TypePtr type, uint32_t binding, uint32_t set );
		SDAST_API void registerCombinedImage( std::string name, type::TypePtr type, uint32_t binding, uint32_t set );
		SDAST_API void registerStorageImage( std::string name, type::TypePtr type, uint32_t binding, uint32_t set );
		SDAST_API void setAccelerationStruct( type::TypePtr type, uint32_t binding, uint32_t set );
		SDAST_API void registerInput( EntryPoint entryPoint
			, std::string name
			, uint32_t location
			, type::TypePtr type );
		SDAST_API void registerOutput( EntryPoint entryPoint
			, std::string name
			, uint32_t location
			, type::TypePtr type );
		SDAST_API void registerInOut( std::string name, type::TypePtr type );
		SDAST_API void registerSsbo( std::string name, SsboInfo const & info );
		SDAST_API void registerUbo( std::string name, UboInfo const & info );
		SDAST_API void registerPcb( std::string name, InterfaceBlock const & info );
		SDAST_API void registerShaderRecord( std::string name, ShaderRecordInfo const & info );
		/**@}*/

		SsboInfo const & getSsboInfo( std::string const & name )const
		{
			return m_data.ssbos.at( name );
		}

		UboInfo const & getUboInfo( std::string const & name )const
		{
			return m_data.ubos.at( name );
		}

		InterfaceBlock const & getPcbInfo( std::string const & name )const
		{
			return m_data.pcbs.at( name );
		}

		ShaderRecordInfo const & getShaderRecordInfo( std::string const & name )const
		{
			return m_data.shaderRecords.at( name );
		}

		AccStructInfo const & getAccelerationStructureInfo()const
		{
			return m_data.accelerationStruct;
		}

		uint32_t getTessellationControlPoints()const
		{
			return m_data.tessellationControlPoints;
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

		ShaderData::ConstantsMap const & getConstants()const
		{
			return m_data.constants;
		}

		ShaderData::SpecConstantsMap const & getSpecConstants()const
		{
			return m_data.specConstants;
		}

		ShaderData::UboMap const & getUbos()const
		{
			return m_data.ubos;
		}

		ShaderData::SsboMap const & getSsbos()const
		{
			return m_data.ssbos;
		}

		ShaderData::PcbMap const & getPcbs()const
		{
			return m_data.pcbs;
		}

		ShaderData::ShaderRecordMap const & getShaderRecords()const
		{
			return m_data.shaderRecords;
		}

		ShaderData::SamplerMap const & getSamplers()const
		{
			return m_data.samplers;
		}

		ShaderData::TextureMap const & getSampledImages()const
		{
			return m_data.sampled;
		}

		ShaderData::TextureMap const & getCombinedImages()const
		{
			return m_data.textures;
		}

		ShaderData::ImageMap const & getStorageImages()const
		{
			return m_data.images;
		}

		ShaderData::TextureMap const & getUniformTexelBuffers()const
		{
			return m_data.uniformTexels;
		}

		ShaderData::ImageMap const & getStorageTexelBuffers()const
		{
			return m_data.storageTexels;
		}

		ShaderData::AllInputsMap const & getAllInputs()const
		{
			return m_data.inputs;
		}

		ShaderData::AllOutputsMap const & getAllOutputs()const
		{
			return m_data.outputs;
		}

		ShaderData::InputMap const & getInputs( EntryPoint entryPoint )const
		{
			auto sit = m_data.inputs.find( entryPoint );

			if ( sit == m_data.inputs.end() )
			{
				static std::map< std::string, InputInfo, std::less<> > const dummy;
				return dummy;
			}

			return sit->second;
		}

		ShaderData::OutputMap const & getOutputs( EntryPoint entryPoint )const
		{
			auto sit = m_data.outputs.find( entryPoint );

			if ( sit == m_data.outputs.end() )
			{
				static std::map< std::string, OutputInfo, std::less<> > const dummy;
				return dummy;
			}

			return sit->second;
		}

		ShaderData::InOutMap const & getInOuts()const
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

		uint32_t getVarId()const noexcept
		{
			return m_data.nextVarId;
		}

		SDAST_API AstShader getOpaqueHandle()const;
		SDAST_API static Shader const & fromOpaqueHandle( AstShader shader );

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
