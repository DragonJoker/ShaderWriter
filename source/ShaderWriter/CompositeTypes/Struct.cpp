/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Struct.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	Struct::Struct( ShaderWriter & writer
		, std::string name
		, type::MemoryLayout layout )
		: m_shader{ &writer.getShader() }
		, m_type{ type::makeStructType( layout, std::move( name ) ) }
	{
	}

	Struct::Struct( ShaderWriter & writer
		, ast::type::StructPtr type )
		: m_shader{ &writer.getShader() }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_shader, sdw::makeStructDecl( m_type ) );
	}

	void Struct::end()
	{
		addStmt( *m_shader, sdw::makeStructDecl( m_type ) );
	}

	StructInstance Struct::getInstance( std::string const & name )const
	{
		return StructInstance{ m_shader
			, makeExpr( m_shader->registerLocale( name, m_type ) ) };
	}

	void Struct::declMember( std::string name
		, Struct const & type )
	{
		m_type->declMember( name, type.getType() );
	}
}
