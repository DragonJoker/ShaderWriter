/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeUniformBuffer.hpp"
#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	UniformBuffer::UniformBuffer( TypesCache & typesCache
		, std::string const & name
		, MemoryLayout layout )
		: Type{ typesCache, Kind::eUniformBuffer, true }
		, m_interface{ typesCache, layout, name }
	{
	}
}
