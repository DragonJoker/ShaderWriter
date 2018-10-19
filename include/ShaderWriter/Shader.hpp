/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Shader_H___
#define ___Writer_Shader_H___
#pragma once

#include "Function.hpp"
#include "Struct.hpp"
#include "Ssbo.hpp"
#include "Ubo.hpp"
#include "Pcb.hpp"
#include "Optional.hpp"

#include <vector>

namespace sdw
{
	struct UniformInfo
	{
		type::TypePtr m_type;
		uint32_t m_location;
		uint32_t m_count;
	};

	struct InputInfo
	{
		type::TypePtr m_type;
		uint32_t m_location;
	};

	struct OutputInfo
	{
		type::TypePtr m_type;
		uint32_t m_location;
	};

	struct SamplerInfo
	{
		type::TypePtr m_type;
		uint32_t m_binding;
		uint32_t m_set;
	};

	struct ImageInfo
	{
		type::TypePtr m_type;
		uint32_t m_binding;
		uint32_t m_set;
	};

	class Shader
	{
	public:
		Shader();
		void push( stmt::Container * container );
		void pop();
#pragma region Variables registration
		/**
		*name
		*	Control statements.
		*/
		/**@{*/
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, var::Flag flag );
		var::VariablePtr registerConstant( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerSampler( std::string const & name
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
			, type::TypePtr type );
		var::VariablePtr registerLocale( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerInParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerOutParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerInOutParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr getVar( std::string const & name
			, type::TypePtr type );
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
			return m_inputs.at( name ).m_type;
		}

		inline type::TypePtr getOutput( std::string const & name )const
		{
			return m_outputs.at( name ).m_type;
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

		inline stmt::Container * getStatements()
		{
			return &m_container;
		}

		inline stmt::Container * getContainer()
		{
			return m_blocks.back().container;
		}

	private:
		struct Block
		{
			std::map< std::string, var::VariablePtr > registered;
			stmt::Container * container;
		};
		std::vector< Block > m_blocks;
		stmt::Container m_container;
		std::map< std::string, Ssbo::Info > m_ssbos;
		std::map< std::string, Ubo::Info > m_ubos;
		std::map< std::string, type::TypePtr > m_constants;
		std::map< std::string, SamplerInfo > m_samplers;
		std::map< std::string, ImageInfo > m_images;
		std::map< std::string, InputInfo > m_inputs;
		std::map< std::string, OutputInfo > m_outputs;
	};
}

#include "Shader.inl"

#endif
