/*
See LICENSE file in root folder
*/
#include "ShaderWriter/EntryPointWriter.hpp"

namespace sdw
{
	EntryPointWriter::EntryPointWriter( ast::ShaderStage type
		, uint32_t flags
		, ShaderAllocator * allocator )
		: ShaderWriter{ type, allocator }
		, m_entryPoint{ getEntryPointType( type ) }
		, m_flags{ flags }
	{
	}

	EntryPointWriter::EntryPointWriter( ast::ShaderStage type
		, ShaderBuilder & builder
		, uint32_t flags )
		: ShaderWriter{ builder }
		, m_entryPoint{ getEntryPointType( type ) }
		, m_flags{ flags }
	{
	}

	var::VariablePtr EntryPointWriter::registerInput( std::string name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		return getBuilder().registerInput( m_entryPoint
			, std::move( name )
			, location
			, attributes
			, type );
	}

	var::VariablePtr EntryPointWriter::registerOutput( std::string name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		return getBuilder().registerOutput( m_entryPoint
			, std::move( name )
			, location
			, attributes
			, type );
	}
}
