/*
See LICENSE file in root folder
*/
#ifndef ___SDW_PipelineWriter_H___
#define ___SDW_PipelineWriter_H___

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	class PipelineWriter
		: public ShaderWriter
	{
	protected:
		SDW_API explicit PipelineWriter( ast::ShaderStage type
			, ShaderAllocator * allocator = nullptr );
		SDW_API explicit PipelineWriter( ShaderBuilder & builder );
		SDW_API ~PipelineWriter()override = default;

	public:
#pragma region Input declaration
		/**
		*name
		*	Input declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declInput( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		inline T declInput( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline T declInput( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		inline T declInput( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint64_t attributes
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled
			, std::vector< T > const & defaultValue );
		template< typename T >
		inline Array< T > declInputArray( std::string name
			, EntryPoint entryPoint
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
			, EntryPoint entryPoint
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		inline T declOutput( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declOutputArray( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declOutputArray( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled = true );
		/**@}*/
#pragma endregion

	protected:
		SDW_API var::VariablePtr registerInput( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutput( std::string name
			, EntryPoint entryPoint
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );
	};
}

#include "PipelineWriter.inl"

#endif
