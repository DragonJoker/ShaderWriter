/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Struct.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	Struct::Struct( ShaderWriter & writer
		, std::string name )
		: m_shader{ &writer.getShader() }
		, m_type{ type::makeStructType( type::MemoryLayout::eStd140, std::move( name ) ) }
	{
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
}
