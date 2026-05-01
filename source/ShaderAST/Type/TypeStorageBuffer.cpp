/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeStorageBuffer.hpp"
#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	StorageBuffer::StorageBuffer( TypesCache & typesCache
		, std::string const & name
		, MemoryLayout layout
		, bool isArray )
		: Type{ typesCache, Kind::eStorageBuffer, true }
		, m_interface{ typesCache, layout, name }
		, m_isArray{ isArray }
	{
	}

	size_t getHash( MemoryLayout layout
		, std::string const & name
		, bool isArray
		, bool explicitLayout )
	{
		size_t result = std::hash< std::string >{}( name );
		result = hashCombine( result, layout );
		result = hashCombine( result, isArray );
		result = hashCombine( result, explicitLayout );
		return result;
	}
}
