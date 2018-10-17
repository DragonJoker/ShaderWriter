/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Pcb.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	Pcb::Pcb( ShaderWriter & writer
		, std::string const & name )
		: m_shader{ writer.getShader() }
		, m_stmt{ stmt::makePushConstantsBufferDecl( name ) }
		, m_name{ name }
		, m_info{ 0u, 0u }
	{
	}

	void Pcb::end()
	{
		addStmt( m_shader, std::move( m_stmt ) );
	}
}
