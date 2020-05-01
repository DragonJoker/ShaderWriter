/*
See LICENSE file in root folder
*/
#ifndef ___AST_Shader_H___
#define ___AST_Shader_H___
#pragma once

#include "BoInfo.hpp"

#include "ShaderAST/Stmt/StmtContainer.hpp"

#include <vector>
#include <map>

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
	};

	class Shader
	{
	public:
		Shader( ast::ShaderStage type );
		void push( stmt::Container * container
			, ast::var::VariableList vars );
		void pop();
		void saveNextExpr();
		ast::expr::ExprPtr loadExpr( ast::expr::ExprPtr expr );
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		bool hasVariable( std::string const & name )const;
		void registerVariable( var::VariablePtr var );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerStaticConstant( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerConstant( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerSpecConstant( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		var::VariablePtr registerSampledImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		var::VariablePtr registerImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		var::VariablePtr registerInput( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		var::VariablePtr registerOutput( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		var::VariablePtr registerBuiltin( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		var::VariablePtr registerBlockVariable( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerLocale( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerLoopVar( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerInParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerOutParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerInOutParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr getVar( std::string const & name )const;
		void addStmt( stmt::StmtPtr stmt );
		void registerSsbo( std::string const & name
			, SsboInfo const & info );
		void registerUbo( std::string const & name
			, UboInfo const & info );
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

	private:
		struct Block
		{
			std::map< std::string, var::VariablePtr > registered;
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
