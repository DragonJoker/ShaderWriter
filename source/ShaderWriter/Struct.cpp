/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Struct.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Struct::Struct( Shader & shader
		, std::string name )
		: m_shader{ &shader }
		, m_type{ type::makeStructType( std::move( name ) ) }
	{
	}

	void Struct::end()
	{
		addStmt( *m_shader, stmt::makeStructureDecl( m_type ) );
	}

	StructInstance Struct::getInstance( std::string const & name )
	{
		return StructInstance{ m_shader
			, makeExpr( var::makeVariable( m_type, name ) ) };
	}
}
