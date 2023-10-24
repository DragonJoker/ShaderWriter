/*
See LICENSE file in root folder
*/
#include "ShaderWriter/EntryPointWriter.hpp"

namespace sdw
{
	EntryPointWriter::EntryPointWriter( ast::ShaderStage type
		, ShaderAllocator * allocator )
		: ShaderWriter{ type, allocator }
	{
	}

	var::VariablePtr EntryPointWriter::registerInput( std::string name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		return getShader().registerInput( getEntryPointType( getShader().getType() )
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
		return getShader().registerOutput( getEntryPointType( getShader().getType() )
			, std::move( name )
			, location
			, attributes
			, type );
	}
}
