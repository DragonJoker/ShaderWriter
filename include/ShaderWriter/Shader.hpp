/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Shader_H___
#define ___Writer_Shader_H___

#include "Function.hpp"
#include "Struct.hpp"
#include "Ssbo.hpp"
#include "Ubo.hpp"
#include "Pcb.hpp"
#include "Optional.hpp"

#include <ASTGenerator/Stmt/StmtContainer.hpp>

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
		void registerName( std::string const & name
			, type::Kind type );
		void checkNameExists( std::string const & name
			, type::Kind type );
		void addStmt( stmt::StmtPtr stmt );
		void registerSsbo( std::string const & name
			, Ssbo::Info const & info );
		void registerUbo( std::string const & name
			, Ubo::Info const & info );
		/**
		*name
		*	Constant declaration (#define name value).
		*/
		/**@{*/
		template< typename T >
		inline T declConstant( std::string const & name
			, T const & rhs );
		template< typename T >
		inline Optional< T > declConstant( std::string const & name
			, T const & rhs, bool enabled );
		/**
		*name
		*	Specialisation constant declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declSpecConstant( std::string const & name
			, uint32_t location
			, T const & rhs );
		template< typename T >
		inline Optional< T > declSpecConstant( std::string const & name
			, uint32_t location
			, T const & rhs
			, bool enabled );
		/**@}*/
		/**
		*name
		*	Sampler declaration.
		*/
		/**@{*/
		template< SamplerType SamplerT >
		inline typename SamplerTypeTraits< SamplerT >::Type declSampler( std::string const & name
			, uint32_t binding
			, uint32_t set );
		template< SamplerType SamplerT >
		inline Optional< typename SamplerTypeTraits< SamplerT >::Type > declSampler( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled );
		template< SamplerType SamplerT >
		inline Array< typename SamplerTypeTraits< SamplerT >::Type > declSamplerArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension );
		template< SamplerType SamplerT >
		inline Optional< Array< typename SamplerTypeTraits< SamplerT >::Type > > declSamplerArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled );
		/**@}*/
		/**
		*name
		*	Input declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declInput( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< T > declInput( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< Array< T > > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declInputArray( std::string const & name
			, uint32_t location
			, bool enabled );
		/**@}*/
		/**
		*name
		*	Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declOutput( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Array< T > declOutputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declOutputArray( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< T > declOutput( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declOutputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declOutputArray( std::string const & name
			, uint32_t location
			, bool enabled );
		/**@}*/
		/**
		*name
		*	Locale variable declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declLocale( std::string const & name );
		template< typename T >
		inline T declLocale( std::string const & name
			, T const & rhs );
		template< typename T >
		inline Optional< T > declLocale( std::string const & name
			, bool enabled );
		template< typename T >
		inline Optional< T > declLocale( std::string const & name
			, Optional< T > const & rhs );
		template< typename T >
		inline Optional< T > declLocale( std::string const & name
			, bool enabled
			, T const & rhs );
		template< typename T >
		inline Array< T > declLocaleArray( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declLocaleArray( std::string const & name
			, uint32_t dimension
			, std::vector< T > const & rhs );
		template< typename T >
		inline Optional< Array< T > > declLocaleArray( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declLocaleArray( std::string const & name
			, uint32_t dimension
			, bool enabled
			, std::vector< T > const & rhs );
		/**@}*/
		/**
		*name
		*	Built-in variable declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declBuiltin( std::string const & name );
		template< typename T >
		inline Optional< T > declBuiltin( std::string const & name
			, bool enabled );
		template< typename T >
		inline Array< T > declBuiltinArray( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declBuiltinArray( std::string const & name );
		template< typename T >
		inline Optional< Array< T > > declBuiltinArray( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declBuiltinArray( std::string const & name
			, bool enabled );

		template< typename T >
		inline T getBuiltin( std::string const & name );
		template< typename T >
		inline Optional< T > getBuiltin( std::string const & name
			, bool enabled );
		template< typename T >
		inline Array< T > getBuiltinArray( std::string const & name );
		template< typename T >
		inline Optional< Array< T > > getBuiltinArray( std::string const & name
			, bool enabled );
		template< typename T >
		inline Array< T > getBuiltinArray( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Optional< Array< T > > getBuiltinArray( std::string const & name
			, uint32_t dimension
			, bool enabled );
		/**@}*/

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

	private:
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

	private:
		stmt::Container m_container;
		std::map< std::string, type::Kind > m_registered;
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
