/*
See LICENSE file in root folder
*/
#ifndef ___AST_Shader_H___
#define ___AST_Shader_H___
#pragma once

#include "BoInfo.hpp"
#include "shader.h"

#include "ShaderAST/Expr/ExprCache.hpp"
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
		InputMap inputs;
		OutputMap outputs;
		InOutMap inOuts;
		AccStructInfo accelerationStruct;
		uint32_t tessellationControlPoints{};
		mutable uint32_t nextVarId{};
	};

	class Shader
	{
	public:
		SDAST_API explicit Shader( ast::ShaderStage type );
		SDAST_API void push( stmt::Container * container
			, ast::var::VariableList vars );
		SDAST_API void pop();
		SDAST_API void saveNextExpr();
		SDAST_API ast::expr::ExprPtr loadExpr( ast::expr::ExprPtr expr );
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		SDAST_API bool hasVariable( std::string_view name )const;
		SDAST_API void registerVariable( var::VariablePtr var );
		SDAST_API var::VariablePtr registerName( std::string name
			, type::TypePtr type
			, uint64_t flags );
		SDAST_API var::VariablePtr registerName( std::string name
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerName( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string name
			, type::TypePtr type
			, uint64_t flags );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string name
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerStaticConstant( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerConstant( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerSpecConstant( std::string name
			, uint32_t location
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerAccelerationStructure( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerSampler( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerSampledImage( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerTexture( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerImage( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerInput( std::string name
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerOutput( std::string name
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInOut( std::string name
			, uint64_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerBuiltin( ast::Builtin builtin
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerBlockVariable( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerLocale( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerLoopVar( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerParam( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInParam( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerOutParam( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInOutParam( std::string name
			, type::TypePtr type );
		SDAST_API bool hasVar( std::string_view name )const;
		SDAST_API var::VariablePtr getVar( std::string_view name )const;
		SDAST_API var::VariablePtr getMemberVar( var::VariablePtr outer
			, std::string_view name )const;
		SDAST_API void addStmt( stmt::StmtPtr stmt );
		SDAST_API void addGlobalStmt( stmt::StmtPtr stmt );
		SDAST_API void registerSsbo( std::string name
			, SsboInfo const & info );
		SDAST_API void registerUbo( std::string name
			, UboInfo const & info );
		SDAST_API void registerPcb( std::string name
			, InterfaceBlock const & info );
		SDAST_API void registerShaderRecord( std::string name
			, ShaderRecordInfo const & info );
		SDAST_API expr::ExprPtr getDummyExpr( type::TypePtr type )const;
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

		type::TypePtr getInput( std::string const & name )const
		{
			return m_data.inputs.at( name ).type;
		}

		type::TypePtr getOutput( std::string const & name )const
		{
			return m_data.outputs.at( name ).type;
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

		std::map< std::string, InputInfo > const & getInputs()const
		{
			return m_data.inputs;
		}

		std::map< std::string, OutputInfo > const & getOutputs()const
		{
			return m_data.outputs;
		}

		std::map< std::string, InOutInfo > const & getInOuts()const
		{
			return m_data.inOuts;
		}

		stmt::Container * getStatements()const
		{
			return m_container.get();
		}

		stmt::Container * getContainer()
		{
			return m_blocks.back().container;
		}

		stmt::Container * getGlobalContainer()
		{
			return m_blocks.front().container;
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

		ShaderData const & getData()const
		{
			return m_data;
		}

		SDAST_API SdwShader getOpaqueHandle()const;
		SDAST_API static Shader const & fromOpaqueHandle(SdwShader shader);

	private:
		struct Block
		{
			std::set< var::VariablePtr > registered;
			stmt::Container * container;
		};
		ast::ShaderStage m_type;
		std::unique_ptr< ast::type::TypesCache > m_typesCache;
		std::unique_ptr< ast::expr::ExprCache > m_exprCache;
		std::vector< Block > m_blocks;
		stmt::ContainerPtr m_container;
		ShaderData m_data;
		bool m_ignore{ false };
		ast::stmt::StmtPtr m_savedStmt;
	};
}

#endif
