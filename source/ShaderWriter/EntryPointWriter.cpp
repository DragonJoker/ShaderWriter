/*
See LICENSE file in root folder
*/
#include "ShaderWriter/EntryPointWriter.hpp"

namespace sdw
{
	EntryPointWriter::EntryPointWriter( ast::ShaderStage type
		, ShaderAllocator * allocator )
		: ShaderWriter{ type, allocator }
		, m_entryPoint{ getEntryPointType( type ) }
	{
	}

	EntryPointWriter::EntryPointWriter( ast::ShaderStage type
		, ShaderBuilder & builder )
		: ShaderWriter{ builder }
		, m_entryPoint{ getEntryPointType( type ) }
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
