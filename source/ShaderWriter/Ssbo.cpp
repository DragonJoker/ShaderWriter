/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Ssbo.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	Ssbo::Ssbo( ShaderWriter & writer
		, std::string const & name
		, uint32_t bind
		, uint32_t set
		, Ssbo::Layout layout )
		: m_shader{ writer.getShader() }
		, m_stmt{ stmt::makeShaderBufferDecl( name, bind, set ) }
		, m_name{ name }
		, m_info{ bind, set }
	{
	}

	void Ssbo::end()
	{
		addStmt( m_shader, std::move( m_stmt ) );
		m_shader.registerSsbo( m_name, m_info );
	}
}
