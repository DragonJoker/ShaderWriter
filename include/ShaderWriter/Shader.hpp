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

#include <stack>

namespace sdw
{
	struct UniformInfo
	{
		type::Kind m_type;
		uint32_t m_location;
		uint32_t m_count;
	};

	struct InputInfo
	{
		type::Kind m_type;
		uint32_t m_location;
	};

	struct OutputInfo
	{
		type::Kind m_type;
		uint32_t m_location;
	};

	struct SamplerInfo
	{
		type::Kind m_type;
		uint32_t m_binding;
		uint32_t m_set;
		uint32_t m_count;
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
		void registerName( std::string const & name
			, type::Kind type );
		void checkNameExists( std::string const & name
			, type::Kind type );
		void addStmt( stmt::StmtPtr stmt );
		void registerSsbo( std::string const & name
			, Ssbo::Info const & info );
		void registerUbo( std::string const & name
			, Ubo::Info const & info );
		void registerConstant( std::string const & name
			, type::Kind type );
		void registerSampler( std::string const & name
			, type::Kind type
			, uint32_t binding
			, uint32_t set
			, uint32_t count
			, bool enabled = true );
		void registerInput( std::string const & name
			, uint32_t location
			, type::Kind type );
		void registerOutput( std::string const & name
			, uint32_t location
			, type::Kind type );
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

		inline type::Kind getInput( std::string const & name )const
		{
			return m_inputs.at( name ).m_type;
		}

		inline type::Kind getOutput( std::string const & name )const
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
			return m_blocks.top().container;
		}

	private:
		struct Block
		{
			std::map< std::string, type::Kind > registered;
			stmt::Container * container;
		};
		std::stack< Block > m_blocks;
		stmt::Container m_container;
		std::map< std::string, Ssbo::Info > m_ssbos;
		std::map< std::string, Ubo::Info > m_ubos;
		std::map< std::string, type::Kind > m_constants;
		std::map< std::string, SamplerInfo > m_samplers;
		std::map< std::string, InputInfo > m_inputs;
		std::map< std::string, OutputInfo > m_outputs;
	};
}

#include "Shader.inl"

#endif
