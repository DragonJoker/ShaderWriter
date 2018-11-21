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
		Shader( ShaderType type );
		void push( stmt::Container * container );
		void pop();
#pragma region Variables registration
		/**
		*name
		*	Control statements.
		*/
		/**@{*/
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
		var::VariablePtr registerLocale( std::string const & name
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
			, Ssbo::Info const & info );
		void registerUbo( std::string const & name
			, Ubo::Info const & info );
		/**@}*/
#pragma endregion

		inline Ssbo::Info const & getSsboInfo( std::string const & name )const
		{
			return m_ssbos.at( name );
		}

		inline Ubo::Info const & getUboInfo( std::string const & name )const
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

		inline std::map< std::string, Ubo::Info > const & getUbos()const
		{
			return m_ubos;
		}

		inline std::map< std::string, Ssbo::Info > const & getSsbos()const
		{
			return m_ssbos;
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

		inline ShaderType getType()const
		{
			return m_type;
		}

	private:
		struct Block
		{
			std::map< std::string, var::VariablePtr > registered;
			stmt::Container * container;
		};
		ShaderType m_type;
		std::vector< Block > m_blocks;
		stmt::ContainerPtr m_container;
		std::map< std::string, Ssbo::Info > m_ssbos;
		std::map< std::string, Ubo::Info > m_ubos;
		std::map< std::string, type::TypePtr > m_constants;
		std::map< std::string, SpecConstantInfo > m_specConstants;
		std::map< std::string, SamplerInfo > m_samplers;
		std::map< std::string, ImageInfo > m_images;
		std::map< std::string, InputInfo > m_inputs;
		std::map< std::string, OutputInfo > m_outputs;
	};
}

#endif
