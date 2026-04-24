/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	var::VariablePtr registerStorageBuffer( ShaderWriter & writer
		, std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, var::Flag flag
		, bool enabled )
	{
		return getBuilder( writer ).registerStorageBuffer( std::move( name )
			, type
			, binding
			, set
			, flag
			, enabled );
	}

	type::StorageBufferPtr makeArrayStorageBufferType( type::TypesCache & cache
		, std::string const & name
		, type::MemoryLayout layout
		, type::TypePtr dataType )
	{
		auto type = makeStorageBufferType( cache
			, name + "Type"
			, layout
			, true );
		if ( type->empty() )
			type->registerMember( "data", dataType, type::UnknownArraySize );
		return type;
	}

	type::StorageBufferPtr makeArrayStorageBufferType( type::TypesCache & cache
		, std::string const & name
		, type::MemoryLayout layout
		, Struct const & dataType )
	{
		return makeArrayStorageBufferType( cache, name, layout, dataType.getType() );
	}
}
