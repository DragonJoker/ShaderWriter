#include "ShaderWriter/Pcb.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Pcb::Pcb( Shader & shader
		, std::string const & name )
		: m_shader{ shader }
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
