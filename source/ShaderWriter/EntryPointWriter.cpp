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

	EntryPointWriter::EntryPointWriter( ShaderBuilder & builder )
		: ShaderWriter{ builder }
	{
	}

	var::VariablePtr EntryPointWriter::registerInput( std::string name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		return getBuilder().registerInput( getEntryPointType( getShader().getType() )
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
		return getBuilder().registerOutput( getEntryPointType( getShader().getType() )
			, std::move( name )
			, location
			, attributes
			, type );
	}
}
