/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Struct.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Struct::Struct( stmt::Container & container
		, std::string name )
		: m_container{ container }
		, m_type{ type::makeStructType( std::move( name ) ) }
	{
	}

	void Struct::end()
	{
		addStmt( m_container, stmt::makeStructureDecl( m_type ) );
	}
}
