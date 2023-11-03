/*
See LICENSE file in root folder
*/
#ifndef ___SDW_EntryPointWriter_H___
#define ___SDW_EntryPointWriter_H___

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	class EntryPointWriter
		: public ShaderWriter
	{
	protected:
		SDW_API explicit EntryPointWriter( ast::ShaderStage type
			, ShaderAllocator * allocator = nullptr );
		SDW_API explicit EntryPointWriter( ast::ShaderStage type
			, ShaderBuilder & builder );
		SDW_API ~EntryPointWriter()override = default;

	public:
#pragma region Input declaration
		/**
		*name
		*	Input declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declInput( std::string name
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		inline T declInput( std::string name
			, uint32_t location
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, uint32_t location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, uint32_t location
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline T declInput( std::string name
			, uint32_t location
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		inline T declInput( std::string name
			, uint32_t location
			, uint64_t attributes
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, uint32_t location
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled
			, std::vector< T > const & defaultValue );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, uint32_t location
			, uint32_t dimension
			, bool enabled
			, std::vector< T > const & defaultValue );
		/**@}*/
#pragma endregion
#pragma region Output declaration
		/**
		*name
		*	Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declOutput( std::string name
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		inline T declOutput( std::string name
			, uint32_t location
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declOutputArray( std::string name
			, uint32_t location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declOutputArray( std::string name
			, uint32_t location
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled = true );
		/**@}*/
#pragma endregion

	protected:
		SDW_API var::VariablePtr registerInput( std::string name
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutput( std::string name
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );

	private:
		ast::EntryPoint m_entryPoint;
	};
}

#include "EntryPointWriter.inl"

#endif
