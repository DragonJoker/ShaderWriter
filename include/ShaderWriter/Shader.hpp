/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Shader_H___
#define ___SDW_Shader_H___
#pragma once

#include "ShaderWriter/CompositeTypes/Function.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/Ssbo.hpp"
#include "ShaderWriter/CompositeTypes/StructuredSsbo.hpp"
#include "ShaderWriter/CompositeTypes/Ubo.hpp"
#include "ShaderWriter/CompositeTypes/Pcb.hpp"
#include "ShaderWriter/Optional/Optional.hpp"

#include <vector>

namespace sdw
{
	struct InputInfo
	{
		type::TypePtr type;
		uint32_t location;
	};

	struct OutputInfo
	{
		type::TypePtr type;
		uint32_t location;
	};

	struct SamplerInfo
	{
		type::TypePtr type;
		uint32_t binding;
		uint32_t set;
	};

	struct ImageInfo
	{
		type::TypePtr type;
		uint32_t binding;
		uint32_t set;
	};

	class Shader
	{
	public:
		SDW_API Shader( ast::ShaderStage type );
		SDW_API void push( stmt::Container * container );
		SDW_API void pop();
		SDW_API void saveNextExpr();
		SDW_API ast::expr::ExprPtr loadExpr( ast::expr::ExprPtr expr );
#pragma region Variables registration
		/**
		*name
		*	Control statements.
		*/
		/**@{*/
		SDW_API void registerVariable( var::VariablePtr var );
		SDW_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		SDW_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		SDW_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		SDW_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		SDW_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerConstant( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerSpecConstant( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		SDW_API var::VariablePtr registerSampledImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerInput( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutput( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		SDW_API var::VariablePtr registerBuiltin( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		SDW_API var::VariablePtr registerBlockVariable( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerLocale( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInOutParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr getVar( std::string const & name )const;
		SDW_API void addStmt( stmt::StmtPtr stmt );
		SDW_API void registerSsbo( std::string const & name
			, SsboInfo const & info );
		SDW_API void registerUbo( std::string const & name
			, UboInfo const & info );
		/**@}*/
#pragma endregion

		inline SsboInfo const & getSsboInfo( std::string const & name )const
		{
			return m_ssbos.at( name );
		}

		inline UboInfo const & getUboInfo( std::string const & name )const
		{
			return m_ubos.at( name );
		}

		inline type::TypePtr getInput( std::string const & name )const
		{
			return m_inputs.at( name ).type;
		}

		inline type::TypePtr getOutput( std::string const & name )const
		{
			return m_outputs.at( name ).type;
		}

		inline std::map< std::string, SpecConstantInfo > const & getSpecConstants()const
		{
			return m_specConstants;
		}

		inline std::map< std::string, UboInfo > const & getUbos()const
		{
			return m_ubos;
		}

		inline std::map< std::string, SsboInfo > const & getSsbos()const
		{
			return m_ssbos;
		}

		inline std::map< std::string, PcbInfo > const & getPcbs()const
		{
			return m_pcbs;
		}

		inline std::map< std::string, SamplerInfo > const & getSamplers()const
		{
			return m_samplers;
		}

		inline std::map< std::string, InputInfo > const & getInputs()const
		{
			return m_inputs;
		}

		inline std::map< std::string, OutputInfo > const & getOutputs()const
		{
			return m_outputs;
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
		std::map< std::string, SsboInfo > m_ssbos;
		std::map< std::string, UboInfo > m_ubos;
		std::map< std::string, PcbInfo > m_pcbs;
		std::map< std::string, type::TypePtr > m_constants;
		std::map< std::string, SpecConstantInfo > m_specConstants;
		std::map< std::string, SamplerInfo > m_samplers;
		std::map< std::string, ImageInfo > m_images;
		std::map< std::string, InputInfo > m_inputs;
		std::map< std::string, OutputInfo > m_outputs;
		bool m_ignore{ false };
		ast::stmt::StmtPtr m_savedStmt;
	};
}

#endif
