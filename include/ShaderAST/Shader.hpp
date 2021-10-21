/*
See LICENSE file in root folder
*/
#ifndef ___AST_Shader_H___
#define ___AST_Shader_H___
#pragma once

#include "BoInfo.hpp"
#include "shader.h"

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
		eCombinedSamplerImage,
		eStorageImage,
		eCount,
	};

	struct ShaderData
	{
		using SsboMap = std::map< std::string, SsboInfo >;
		using UboMap = std::map< std::string, UboInfo >;
		using PcbMap = std::map< std::string, PcbInfo >;
		using ConstantsMap = std::map< std::string, type::TypePtr >;
		using SpecConstantsMap = std::map< std::string, SpecConstantInfo >;
		using SamplerMap = std::map< std::string, SamplerInfo >;
		using ImageMap = std::map< std::string, ImageInfo >;
		using InputMap = std::map< std::string, InputInfo >;
		using OutputMap = std::map< std::string, OutputInfo >;

		SsboMap ssbos;
		UboMap ubos;
		PcbMap pcbs;
		ConstantsMap constants;
		SpecConstantsMap specConstants;
		SamplerMap samplers;
		ImageMap images;
		InputMap inputs;
		OutputMap outputs;
		mutable uint32_t nextVarId{};
	};

	class Shader
	{
	public:
		SDAST_API Shader( ast::ShaderStage type );
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
		SDAST_API bool hasVariable( std::string const & name )const;
		SDAST_API void registerVariable( var::VariablePtr var );
		SDAST_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		SDAST_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerStaticConstant( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerConstant( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerSpecConstant( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerSampledImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerInput( std::string const & name
			, uint32_t location
			, uint32_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerOutput( std::string const & name
			, uint32_t location
			, uint32_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerBuiltin( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerBlockVariable( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerLocale( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerLoopVar( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerParam( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInParam( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerOutParam( std::string const & name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInOutParam( std::string const & name
			, type::TypePtr type );
		SDAST_API bool hasVar( std::string const & name )const;
		SDAST_API var::VariablePtr getVar( std::string const & name )const;
		SDAST_API void addStmt( stmt::StmtPtr stmt );
		SDAST_API void addFuncStmt( stmt::StmtPtr stmt );
		SDAST_API void registerSsbo( std::string const & name
			, SsboInfo const & info );
		SDAST_API void registerUbo( std::string const & name
			, UboInfo const & info );
		SDAST_API expr::ExprPtr getDummyExpr( type::TypePtr type )const;
		/**@}*/

		inline SsboInfo const & getSsboInfo( std::string const & name )const
		{
			return m_data.ssbos.at( name );
		}

		inline UboInfo const & getUboInfo( std::string const & name )const
		{
			return m_data.ubos.at( name );
		}

		inline type::TypePtr getInput( std::string const & name )const
		{
			return m_data.inputs.at( name ).type;
		}

		inline type::TypePtr getOutput( std::string const & name )const
		{
			return m_data.outputs.at( name ).type;
		}

		inline std::map< std::string, SpecConstantInfo > const & getSpecConstants()const
		{
			return m_data.specConstants;
		}

		inline std::map< std::string, UboInfo > const & getUbos()const
		{
			return m_data.ubos;
		}

		inline std::map< std::string, SsboInfo > const & getSsbos()const
		{
			return m_data.ssbos;
		}

		inline std::map< std::string, PcbInfo > const & getPcbs()const
		{
			return m_data.pcbs;
		}

		inline std::map< std::string, SamplerInfo > const & getSamplers()const
		{
			return m_data.samplers;
		}

		inline std::map< std::string, InputInfo > const & getInputs()const
		{
			return m_data.inputs;
		}

		inline std::map< std::string, OutputInfo > const & getOutputs()const
		{
			return m_data.outputs;
		}

		inline stmt::Container * getStatements()const
		{
			return m_container.get();
		}

		inline stmt::Container * getContainer()
		{
			return m_blocks.back().container;
		}

		inline stmt::Container * getFuncContainer()
		{
			return m_blocks.front().container;
		}

		inline ast::ShaderStage getType()const
		{
			return m_type;
		}

		inline ast::type::TypesCache & getTypesCache()const
		{
			return *m_typesCache;
		}

		inline ShaderData const & getData()const
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
		std::vector< Block > m_blocks;
		stmt::ContainerPtr m_container;
		ShaderData m_data;
		bool m_ignore{ false };
		ast::stmt::StmtPtr m_savedStmt;
	};
}

#endif
