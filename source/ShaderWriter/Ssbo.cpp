#include "ShaderWriter/Ssbo.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Ssbo::Ssbo( Shader & shader
		, std::string const & name
		, uint32_t bind
		, uint32_t set
		, Ssbo::Layout layout )
		: m_shader{ shader }
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
